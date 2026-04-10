# Code Review — µTest++ (`micro-test-plus`)

**Date:** 10 April 2026  
**Reviewer:** GitHub Copilot  
**Scope:** All files under `src/` and `include/micro-os-plus/`  
**Exclusions:** Doxygen comments (by request)

---

## Summary

The codebase is well-structured, modular, and demonstrates a high level of
C++ craftsmanship. The use of CRTP for `runnable<Self_T>`, concept-constrained
templates, structured `std::unique_ptr` ownership, and careful suppression of
platform-specific warnings all reflect deliberate design. The findings below
range from a semantic correctness issue in the comparators to several minor
style and robustness observations.

---

## Findings

### 1. ~~Semantic error in `ne_` epsilon comparator~~ (HIGH) — **FIXED**

**File:** `include/micro-os-plus/micro-test-plus/detail.h`

The `eq_` comparator returns `true` when `|lhs - rhs| < epsilon`, and `ne_`
returns `true` when `|lhs - rhs| > epsilon`. When the difference is
_exactly_ equal to `epsilon`, both comparators return `false`. This means
the logical identity `!eq(a, b) ↔ ne(a, b)` does not hold, and two
consecutive calls can both report a failure.

```cpp
// eq_ uses strictly less than:
return math::abs (get (lhs) - get (rhs)) < lhs.epsilon;

// ne_ uses strictly greater than — dead zone when diff == epsilon:
return math::abs (get (lhs_) - get (rhs_)) > lhs_.epsilon;
```

**Recommendation:** Change `ne_`'s epsilon branches to use `>=` rather than
`>`, matching the half-open interval used by `eq_`:

```cpp
return math::abs (get (lhs_) - get (rhs_)) >= lhs_.epsilon;
```

---

### 2. ~~`deferred_reporter_base` destructor calls `::abort()` directly~~ (MEDIUM) — **FIXED**

**File:** `src/deferred-reporter.cpp`

When an assumption fails, the destructor calls `::abort()` directly rather
than through `runner::abort()`. The runner's method prints a formatted
diagnostic line (`"Test execution aborted at file:line"`) and is the
intended entry point. Calling `::abort()` directly silently bypasses that
diagnostic.

```cpp
// deferred-reporter.cpp — bypasses runner::abort()
if (abort_ && !value_) [[unlikely]]
  {
    printf ("\n");
    subtest_.reporter ().write_buffer_to_stdout ();
    abort ();   // This is ::abort(), not subtest_.runner().abort()
  }
```

**Recommendation:** Route through the runner's abort method to ensure the
source-location diagnostic is always printed, or at a minimum add a
`fflush(stdout)` call immediately before `::abort()` to prevent buffered
output from being lost on embedded targets.

---

### 3. ~~`reporter::flush()` does not flush the output file~~ (MEDIUM) — **FIXED**

**File:** `src/reporter.cpp`

`reporter::flush()` only calls `fflush(stdout)`. When an output file is
open (`output_file_ != nullptr`), its write buffer is never explicitly
flushed by this method; it is flushed only in the destructor.

If the process is terminated abnormally (e.g. via `::abort()`), the file
may contain incomplete output.

```cpp
void
reporter::flush (void)
{
  fflush (stdout); // output_file_ is not flushed here
}
```

**Recommendation:**

```cpp
void
reporter::flush (void)
{
  fflush (stdout);
  if (output_file_ != nullptr)
    fflush (output_file_);
}
```

---

### 4. ~~`deferred_reporter_base` does not delete copy operations~~ (MEDIUM) — **FIXED**

**File:** `include/micro-os-plus/micro-test-plus/deferred-reporter.h`

`deferred_reporter_base` stores a reference member (`subtest& subtest_`)
and a `const` member (`const reflection::source_location location_`). The
copy assignment operator is therefore implicitly deleted by the compiler,
but the copy constructor is implicitly _provided_. If an object were
accidentally copied (e.g. stored in a container), the increment of
`subtest_.increment_subtest_index()` in the constructor and the
pass/fail recording in the destructor would execute twice per expression,
silently corrupting check counts.

**Recommendation:** Explicitly `= delete` the copy and move operations,
consistent with the rule-of-five applied throughout the rest of the
codebase:

```cpp
deferred_reporter_base (const deferred_reporter_base&) = delete;
deferred_reporter_base (deferred_reporter_base&&) = delete;
deferred_reporter_base& operator= (const deferred_reporter_base&) = delete;
deferred_reporter_base& operator= (deferred_reporter_base&&) = delete;
```

---

### ~~5. `runner::initialise()` — brace-init for vector count (MEDIUM)~~ — **FIXED**

**File:** `src/runner.cpp`

The expression `std::vector<std::string_view> argvs{ static_cast<size_t>(argc) }`
uses brace-initialisation. Because `string_view` has no implicit constructor
from `size_t`, the `initializer_list` overload is eliminated and the
compiler falls back to the count constructor — but this is non-obvious
to a reader and could be confused with a one-element list. Using round
parentheses is unambiguous:

```cpp
// Current (unexpected brace syntax):
std::vector<std::string_view> argvs{ static_cast<size_t> (argc) };

// Recommended (unambiguous count constructor):
std::vector<std::string_view> argvs (static_cast<size_t> (argc));
```

---

### ~~6. `reporter_human` warning about unsupported file output goes to the file (LOW)~~ — **FIXED**

**File:** `src/reporter-human.cpp`

When a `--output-file` argument is supplied but the human reporter does
not support it, the warning is written to the output file itself, then
the file is closed. A user who does not inspect the file will see no
warning at all.

```cpp
if (output_file_ != nullptr)
  {
    fprintf (output_file_, "warning: output file specified but not "
                           "supported by human reporter\n");
    fclose (output_file_);
    output_file_ = nullptr;
  }
```

**Recommendation:** Write the warning to `stderr`:

```cpp
fprintf (stderr, "warning: --output-file is not supported by "
                 "the human reporter; ignoring\n");
```

---

### ~~7. `runner_totals::operator+=` should be `noexcept` (LOW)~~ — **FIXED**

**File:** `include/micro-os-plus/micro-test-plus/runner-totals.h`

The `operator+=` modifies only integral counters and calls nothing that
can throw. It should be declared `noexcept` to document this and to enable
compiler optimisations.

```cpp
runner_totals&
operator+= (const runner_totals& other) noexcept;
```

and correspondingly in `src/runner-totals.cpp`.

---

### 8. Duplicate `indent_size` constant (LOW) — **WON'T FIX** (each reporter may use a different indentation)

**Files:** `src/reporter-human.cpp` (line 90), `src/reporter-tap.cpp`
(line 80)

Both reporter implementations define `constexpr size_t indent_size = 4;`
independently. If the indentation is ever changed, both must be updated
in sync.

**Recommendation:** Define `indent_size` once — either in a shared private
header (e.g. `reporter-detail.h`) or as a protected constant in the base
`reporter` class.

---

### 9. `write_buffer_to_stdout()` is public (LOW) — **WON'T FIX** (added explanatory comment)

**File:** `include/micro-os-plus/micro-test-plus/reporter.h`

`write_buffer_to_stdout()` and `write_buffer_to_file()` are implementation
helpers used by derived reporter classes. Exposing them as `public` widens
the API surface unnecessarily; `deferred-reporter.cpp` calls
`write_buffer_to_stdout()` on an abort, which is the only legitimate
external caller.

**Recommendation:** Change `write_buffer_to_stdout()` to `protected`. The
abort call in `deferred-reporter.cpp` can be refactored either by adding
a dedicated `flush_and_abort()` method on the reporter, or by keeping the
method public with an explicit comment.

---

### ~~10. `verbosity_t` alias is redundant (LOW)~~ — **FIXED**

**File:** `include/micro-os-plus/micro-test-plus/reporter.h`

```cpp
using verbosity_t = verbosity;
```

The alias `verbosity_t` is introduced immediately after the `verbosity`
enum but is never used in the framework headers or sources; all code uses
`verbosity` directly. The alias adds noise without benefit.

**Recommendation:** Remove the alias unless it is intentionally part of
the public API for user code.

---

### ~~11. C compatibility headers used in C++ context (LOW)~~ — **FIXED**

**Files:** `runner.h`, `deferred-reporter.h`, `reporter.h`,
`deferred-reporter-inlines.h`, `test-inlines.h`, and several `.cpp`
files include `<stdio.h>` and `<time.h>`.

In C++ code, the preferred headers are `<cstdio>` and `<ctime>`, which
place declarations in the `std` namespace and avoid polluting the global
namespace.

**Recommendation:** Replace all `#include <stdio.h>` with
`#include <cstdio>` and `#include <time.h>` with `#include <ctime>` in
`.cpp` files and, more importantly, in the public headers.

---

### 12. `timestamps::compute_elapsed_time()` precondition not enforced (LOW)

**File:** `src/timings.cpp`

The function requires `has_timestamps()` to be `true` before it is
called, and accessing a disengaged `std::optional` is undefined behaviour.
This precondition is documented only in a comment; there is no assertion
to guard against incorrect use.

```cpp
void
timestamps::compute_elapsed_time (uint32_t& milliseconds,
                                  uint32_t& microseconds) const
{
  // Precondition: has_timestamps() must be true before calling this method.
  // Invoking it with disengaged optionals is undefined behaviour.
```

**Recommendation:** Add an assertion at the start of the function:

```cpp
assert (has_timestamps ());
```

or, since `<cassert>` may not be available and the project targets
bare-metal, a static analysis attribute such as `[[expects: has_timestamps()]]`
(C++26) or a defensive early return.

---

### ~~13. `runner` hardcodes its internal name as `"-"` (LOW)~~ — **FIXED**

**File:** `src/runner.cpp`

```cpp
runner::runner (const char* top_suite_name)
    : test_node{ "-" }, top_suite_{ top_suite_name, *this }
```

The `test_node` base is initialised with the literal `"-"`, which becomes
the runner's own `name_`. This string appears in trace output
(`MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS`) and could be
confusing. Using a more descriptive string, or using `top_suite_name`,
would improve diagnostics.

---

### ~~14. `is_match` has exponential worst-case complexity (LOW)~~ — **FIXED**

**File:** `src/utility.cpp`

The wildcard-matching algorithm uses recursion with a linear loop for
`*` patterns. For inputs such as `is_match("aaaaaa", "a*a*a*b")`, the
complexity is $O(2^n)$ in the number of wildcards. For a test framework
this is unlikely to matter in practice, but it is worth documenting.

**Recommendation:** Add a comment warning about the exponential worst
case, or replace the algorithm with a standard dynamic-programming or
iterative solution if longer strings or complex patterns are expected.

---

### 15. Fixed-size `snprintf` buffers may silently truncate (LOW)

**Files:** `src/reporter-tap.cpp`, `src/reporter-human.cpp`

Several fixed-size stacks buffers (e.g. `char message_totals[120]`,
`char message_summary[40]`) are used to format lines that incorporate the
suite name. If a suite name is longer than the available space, `snprintf`
will silently truncate and the output will be incorrect.

**Recommendation:** Either replace fixed buffers with `std::string` and
`std::to_string`/`std::format`, or increase the buffer sizes and add a
run-time assertion:

```cpp
const int written = snprintf (message_totals, sizeof (message_totals), ...);
assert (written > 0 && static_cast<size_t> (written) < sizeof (message_totals));
```

---

### ~~16. `static_suite` stores a wasted no-op callable (LOW)~~ — **FIXED**

**File:** `include/micro-os-plus/micro-test-plus/inlines/test-inlines.h`

`static_suite` inherits from `runnable<suite>`, which stores
`std::function<void(suite&)> callable_`. The constructor sets this
callable to an empty lambda `[] (suite&) noexcept {}`, which is never
invoked (since `static_suite::run()` calls `static_callable_` instead).
Every `static_suite` instance therefore carries one unused `std::function`
object. On embedded targets, `std::function` allocates heap memory for
non-trivial callables (though the empty-lambda case is trivial and likely
optimised away).

This is an architectural consequence of `static_suite` inheriting from
`runnable<suite>` rather than `runnable<static_suite>`. If memory is a
concern on small targets, refactoring the inheritance to use `static_suite`
as the `Self_T` parameter would eliminate this overhead.

---

### ~~17. `reporter_tap::begin_subtest` and `reporter_human::begin_subtest` call `abort()` directly (LOW)~~ — **FIXED**

**Files:** `src/reporter-tap.cpp`, `src/reporter-human.cpp`

Both methods call `abort()` (i.e. `::abort()`) directly when an
unexpected non-empty buffer is found at the start of a subtest. This is
a defensive guard for an internal logic error — but it bypasses both the
runner's `abort()` diagnostic output and any `fflush()` calls, and it
does not print the source location.

**Recommendation:** Either use `runner_.abort(sl)` (if a reference to the
runner is available), or at minimum call `fflush(stdout)` before `::abort()`
to ensure the error context is visible.

---

## Positive Observations

- The CRTP `runnable<Self_T>` pattern cleanly separates callable storage
  from the class hierarchy without requiring virtual dispatch for the
  callable invocation.
- Consistent use of `[[nodiscard]]`, `noexcept`, and `[[likely]]`/
  `[[unlikely]]` throughout the API.
- The `std::bind`/direct-store conditional in `runnable<Self_T>::runnable`
  correctly works around the GCC ARM 15.2 `__is_nothrow_invocable` bug for
  zero-argument cases.
- `static_children_suites_` is deliberately not default-initialised in the
  class body (BSS-zero guarantee for static-duration objects) — this subtle
  detail is correctly documented in the header.
- Diagnostic `#pragma GCC diagnostic` push/pop pairs are used with
  discipline, at the smallest possible scope.
- The `reporter` buffer strategy (accumulate into `std::string`, write on
  `endline()`) avoids interleaved output on multi-threaded hosts and
  reduces system-call churn.

---

## Second Review — 10 April 2026

**Scope:** Full re-read of all `src/` and `include/` files after first-pass
fixes. Doxygen comments excluded.

---

### Summary of New Findings

| #   | Severity | File(s)                                  | Topic                                                                                |
| --- | -------- | ---------------------------------------- | ------------------------------------------------------------------------------------ |
| 18  | MEDIUM   | `reporter.h`                             | `verbosity_t` alias and usages not fully removed (fix #10 incomplete)                |
| 19  | MEDIUM   | `reporter-human.cpp`, `reporter-tap.cpp` | `end_session()` parameter named `runner_` — trailing underscore reserved for members |
| 20  | MEDIUM   | `src/runner.cpp`                         | Local variable `exit_code` shadows method name                                       |
| 21  | LOW      | `runner.h`                               | `suite_index_` member declared but never used                                        |
| 22  | LOW      | `reporter.h`                             | Private `append_number` method lacks trailing underscore                             |
| 23  | LOW      | `runner.h`                               | Protected `suites_count()` method lacks trailing underscore                          |
| 24  | LOW      | Multiple `.cpp` files                    | Stale commented-out `#include` lines                                                 |
| 25  | LOW      | `inlines/runner-inlines.h`               | Local variable `suite` shadows class name `suite`                                    |

---

### ~~18. `verbosity_t` alias and usages not fully removed (MEDIUM)~~ — **WON'T FIX** (alias kept; lines 753 and 836 already use `verbosity_t`)

**File:** `include/micro-os-plus/micro-test-plus/reporter.h`

Fix #10 was intended to remove the `verbosity_t` type alias, but three
occurrences remain:

- **Line 146**: `using verbosity_t = verbosity;` — the alias itself.
- **Line 753**: `verbosity_t verbosity () const` — the getter return type.
- **Line 836**: `verbosity_t verbosity_{};` — the protected data member type.

All three should use `verbosity` directly:

```cpp
// Remove:
using verbosity_t = verbosity;

// Line 753:
verbosity
verbosity () const
{
  return verbosity_;
}

// Line 836:
verbosity verbosity_{};
```

---

### 19. `end_session()` parameter named `runner_` (MEDIUM)

**Files:** `src/reporter-human.cpp` (line 135),
`src/reporter-tap.cpp` (line 136)

Both implementations declare:

```cpp
void reporter_human::end_session (runner& runner_)
void reporter_tap::end_session   (runner& runner_)
```

The convention in this codebase is that names ending with `_` are member
variables. Using a trailing underscore on a parameter is misleading and
inconsistent. Rename the parameter to `runner` (or `runner_ref` if
shadowing the class type is a concern):

```cpp
void reporter_human::end_session (runner& runner)
void reporter_tap::end_session   (runner& runner)
```

The same should be applied to the corresponding virtual declarations in
the header.

---

### 20. Local variable `exit_code` shadows method name (MEDIUM)

**File:** `src/runner.cpp` (line 247)

```cpp
int
runner::exit_code (void)
{
  ...
  int exit_code = totals_.was_successful () ? 0 : 1;
  return exit_code;
}
```

The local variable `exit_code` shadows the enclosing method `exit_code()`.
Rename the variable to make the code unambiguous:

```cpp
const int result = totals_.was_successful () ? 0 : 1;
return result;
```

---

### 21. `suite_index_` member declared but never used (LOW)

**File:** `include/micro-os-plus/micro-test-plus/runner.h` (line 276)

```cpp
size_t suite_index_ = 0;
```

This data member is not read or written anywhere in the codebase. Remove
it.

---

### 22. Private `append_number` method lacks trailing underscore (LOW)

**File:** `include/micro-os-plus/micro-test-plus/reporter.h` (line 887)

The private static helper:

```cpp
template <class T>
static void append_number (std::string& buffer, T v);
```

should be named `append_number_` to follow the convention that
private/protected members use a trailing underscore.

---

### 23. Protected `suites_count()` method lacks trailing underscore (LOW) — **WON'T FIX** (`suites_count()` is `public:`, not `protected:`; trailing underscore not required)

**File:** `include/micro-os-plus/micro-test-plus/runner.h` (line 247)

The `protected:` method:

```cpp
[[nodiscard]] size_t
suites_count (void) const noexcept;
```

should be named `suites_count_()` to follow the naming convention. All
callers (`runner_inlines.h` `suite()` method and `static_runner::run_suites_()`)
must also be updated.

---

### 24. Stale commented-out `#include` lines (LOW)

**Files:** `src/runner.cpp`, `src/test.cpp`, `src/runner-totals.cpp`,
`src/deferred-reporter.cpp`, `src/utility.cpp`,
`include/.../inlines/runner-inlines.h`

Multiple files contain commented-out include directives that were never
removed, e.g.:

```cpp
// #include <stdio.h>
// #include <stdlib.h>
// #include <vector>
// #include <cstring>
```

These lines serve no purpose and add noise to the source. Remove them.

---

### 25. Local variable `suite` shadows class name in `runner_inlines.h` (LOW)

**File:**
`include/micro-os-plus/micro-test-plus/inlines/runner-inlines.h`

```cpp
template <typename Callable_T, typename... Args_T>
void
runner::suite (const char* name, Callable_T&& callable,
               Args_T&&... arguments)
{
  auto suite = std::make_unique<class suite> (
      name, *this, suites_count () + 1, ...);
  register_suite_ (std::move (suite));
}
```

The local variable `suite` has the same name as the enclosing method
`runner::suite` and the class `suite`. The `class suite` qualification is
a workaround forced by this ambiguity. Rename the local variable to
`child_suite` or `s`:

```cpp
auto child_suite = std::make_unique<class suite> (
    name, *this, suites_count () + 1,
    std::forward<Callable_T> (callable),
    std::forward<Args_T> (arguments)...);
register_suite_ (std::move (child_suite));
```

---

## Positive Observations (Second Review)

- Buffer clearing in `begin_subtest()` / `end_subtest()` is handled
  correctly in both reporter implementations, ensuring clean state for
  each subtest.
- The `static_children_suites_` raw-pointer deletion in
  `static_runner::~static_runner()` correctly avoids deleting the
  `static_suite` objects themselves (which have static storage duration),
  deleting only the vector of pointers.
- The `timestamp` class correctly defaults all five special member
  functions because `timespec` is trivially copyable; this is documented.

---

## Third Review — 10 April 2026

**Scope:** Full re-read of all `src/` and `include/` files after
second-pass fixes. Doxygen comments excluded.

---

### Summary of New Findings

| #   | Severity | File(s)                      | Topic                                                                                                                            |
| --- | -------- | ---------------------------- | -------------------------------------------------------------------------------------------------------------------------------- |
| 26  | LOW      | `src/runner.cpp`             | ~~`puts("]")` should use `trace::printf("]\n")` for consistency~~ **FIXED**                                                      |
| 27  | LOW      | `src/reporter.cpp`           | `verbosity_` double-initialisation (default `silent`, then `normal`)                                                             |
| 28  | LOW      | `src/test.cpp`               | ~~Commented-out timing and accumulation lines in `run()` and `after_subtest_create_()`~~ **FIXED**                               |
| 29  | LOW      | `src/runner.cpp`             | American spelling "Initialize" in inline comment                                                                                 |
| 30  | LOW      | `inlines/reporter-inlines.h` | Misleading comment about null-pointer rendering platform                                                                         |
| 31  | LOW      | `src/runner.cpp`             | ~~`runner::suites_count()` lacks trailing underscore (finding 23, still pending)~~ **WON'T FIX** (`suites_count()` is `public:`) |
| 32  | LOW      | `runner.h`                   | ~~`static_children_suites_` raw pointer could be `std::unique_ptr`~~ **WON'T FIX** (raw pointer is architecturally required)     |

---

### ~~26. `puts("]")` inconsistency in debug trace (LOW)~~ — **FIXED**

**File:** `src/runner.cpp`

Inside the `MICRO_OS_PLUS_DEBUG` diagnostic block in `runner::initialise()`,
surrounding output uses `trace::printf()` but the closing bracket is printed
with `puts("]")`:

```cpp
trace::printf ("argv[");
for (int i = 0; i < argc; ++i)
  {
    ...
    trace::printf ("'%s'", argv[i]);
  }
puts ("]");   // writes to stdout, not the trace stream
```

`puts` always writes to `stdout` and appends a newline. On embedded targets
it may not route through the configured trace backend (e.g. semihosting,
SWO). For consistency, this should be `trace::printf ("]\n")`.

---

### ~~27. `verbosity_` double-initialisation (LOW)~~ — **FIXED**

**File:** `src/reporter.cpp`

The protected data member is declared as:

```cpp
verbosity_t verbosity_{};   // zero-initialised → verbosity::silent
```

and then the very first statement of the constructor body assigns it again:

```cpp
reporter::reporter (...)
{
  verbosity_ = verbosity::normal;
  ...
}
```

This results in two initialisations: one to `verbosity::silent` (the
in-class default) and immediately one to `verbosity::normal` (the
constructor body). The intent is that `normal` is the real default, with
command-line flags able to override it. The in-class default should
reflect that:

```cpp
verbosity_t verbosity_{ verbosity::normal };
```

With this change, the redundant assignment in the constructor body can be
removed.

---

### ~~28. Commented-out dead code in `test.cpp` (LOW)~~ — **FIXED**

**File:** `src/test.cpp`

Two locations contain commented-out lines that should be removed:

1. In `subtest::run()` and `suite::run()`:

```cpp
// this->timings.timestamp_begin ();
reporter.begin_subtest (*this);
// ...
// this->timings.timestamp_end ();
reporter.end_subtest (*this);
```

2. In `runnable_base::after_subtest_create_()`:

```cpp
// Do not accumulate the totals from the child test into the current test
// totals. totals () += subtest.totals ();
```

The explanatory comment in item 2 is valuable; only the commented-out
code line `totals () += subtest.totals ();` should be removed, leaving
the explanatory sentence as a plain comment.

---

### ~~29. American spelling in inline comment (LOW)~~ — **FIXED**

**File:** `src/runner.cpp`

The comment:

```cpp
// Initialize and configure the reporter.
```

uses American spelling. Per the project's British English convention, it
should be:

```cpp
// Initialise and configure the reporter.
```

---

### ~~30. Misleading platform note in null-pointer rendering (LOW)~~ — **FIXED**

**File:**
`include/micro-os-plus/micro-test-plus/inlines/reporter-inlines.h`

The comment reads:

```cpp
// Explicitly render null pointers as "0x0" to avoid platform-specific
// pointer representations like "(nil)" on macOS.
```

This is reversed: `(nil)` is the Linux/glibc rendering of a null pointer
via `%p`; macOS already renders it as `0x0`. The comment should read:

```cpp
// Explicitly render null pointers as "0x0" to avoid platform-specific
// representations such as "(nil)" on Linux/glibc.
```

---

### 31. `runner::suites_count()` lacks trailing underscore (LOW) — **WON'T FIX** (`suites_count()` is `public:`, not `protected:`; trailing underscore not required)

**File:** `include/micro-os-plus/micro-test-plus/runner.h` (line 247),
`src/runner.cpp`

This is finding #23 from the second review, which was recorded but not
yet addressed. Re-inspection of `runner.h` confirms that `suites_count()`
is declared in the `public:` section of the class, not `protected:`. The
naming convention (trailing underscore) applies only to `protected:` and
`private:` members. No rename is required.

---

### 32. `static_children_suites_` raw pointer (LOW) — **WON'T FIX** (raw pointer is architecturally required)

**File:** `include/micro-os-plus/micro-test-plus/runner.h`

The `static_runner` class manages `static_children_suites_` as a raw
`std::vector<static_suite*>*`. It was initially suggested that a
`std::unique_ptr` could replace the manual `delete` in the destructor.

However, the raw pointer is **architecturally required** and cannot be
replaced by `std::unique_ptr`. The reason is the static initialisation
order problem: `static_suite` objects in other translation units may call
`register_static_suite()` before `static_runner`'s constructor has run,
relying on BSS zero-initialisation to guarantee the field reads as
`nullptr`. If the field were a `std::unique_ptr`, its own default
constructor (running when `static_runner` is constructed) would
**overwrite** any pointer value already written by an earlier
`register_static_suite()` call, silently discarding every suite
registered before the runner's constructor executed.

The current design — raw pointer in BSS, lazily allocated with `new`,
deleted in the destructor — is the correct and only safe approach for
this use case. No code change is required.

---

## Positive Observations (Third Review)

- The `assert(has_timestamps())` precondition guard in
  `timestamps::compute_elapsed_time()` is now in place with the correct
  `<cassert>` include.
- `runner::exit_code()` uses `const int result` (renamed from
  `exit_code`) eliminating the variable-shadows-method issue.
- All stale commented-out `#include` directives have been removed from
  `src/` and `include/` files.
- `auto child_suite` (formerly `auto suite`) in `runner_inlines.h`
  cleanly eliminates the three-way name ambiguity.
- `append_number_()` is correctly private with a trailing underscore,
  consistent with the naming convention.

---

## Fourth Review — 11 April 2026

**Scope:** Full re-read of all `src/` and `include/` files after
third-pass fixes. Doxygen comments excluded.

---

### Summary of New Findings

| #   | Severity | File(s)                               | Topic                                                                                                        |
| --- | -------- | ------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| 33  | LOW      | `src/reporter-tap.cpp`                | ~~Trace blocks in `end_suite()` and `end_subtest()` call `printf()` instead of `trace::printf()`~~ **FIXED** |
| 34  | LOW      | `src/reporter-human.cpp`              | ~~Dead commented-out fragment `/* add_empty_line_ && */` inside live `if` condition~~ **FIXED**              |
| 35  | LOW      | `inlines/test-inlines.h`              | ~~`static_suite` passes `nullptr` as callable to `suite` base class~~ **FIXED**                              |
| 36  | LOW      | `inlines/deferred-reporter-inlines.h` | ~~`#include <cstring>` is not used in that file (stale include)~~ **FIXED**                                  |
| 37  | LOW      | `runner.h`                            | ~~`#include <ctime>` is redundant — already provided by `timings.h`~~ **FIXED**                              |

---

### ~~33. Trace blocks call `printf()` instead of `trace::printf()` (LOW)~~ — **FIXED**

**File:** `src/reporter-tap.cpp`

In `reporter_tap::end_suite()` and `reporter_tap::end_subtest()`, the
diagnostic trace blocks guarded by
`MICRO_OS_PLUS_TRACE && MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS` call bare
`printf()` rather than `trace::printf()`:

```cpp
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s '%s' +%zu -%zu ...", __PRETTY_FUNCTION__,
            suite.name (), ...);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
```

On embedded targets, `printf` writes to `stdout`, which may bypass the
configured trace backend (semihosting, SWO, etc.). All trace-guarded
diagnostics elsewhere in the file use `trace::printf()` correctly. These
two calls should be changed to `trace::printf()`.

---

### ~~34. Dead commented-out fragment inside live `if` condition (LOW)~~ — **FIXED**

**File:** `src/reporter-human.cpp`

In `reporter_human::end_suite()`, the condition reads:

```cpp
if (/* add_empty_line_ && */ suite.totals ().executed_subtests () > 0)
```

The fragment `/* add_empty_line_ && */` is a surviving remnant of a
previous refactoring. It has no effect on behaviour but reduces
readability and may mislead a future reader into thinking the condition
is intentionally partial. It should be removed, leaving:

```cpp
if (suite.totals ().executed_subtests () > 0)
```

---

### ~~35. `static_suite` passes `nullptr` as callable to `suite` base (LOW)~~ — **FIXED**

**File:**
`include/micro-os-plus/micro-test-plus/inlines/test-inlines.h`

The `static_suite` constructor initialises the `suite` base with
`nullptr` as the callable argument:

```cpp
static_suite::static_suite (const char* name, static_runner& runner,
                             Callable_T&& callable)
    : suite{ name, runner, runner.static_suites_count () + 1, nullptr }
```

This causes `runnable::callable_` (a `std::function<void(suite&)>`) to
be left in an empty (null) state. At runtime this is safe because
`static_suite::run()` overrides `suite::run()` and always invokes
`static_callable_` instead, so `callable_` is never called. However, if
`suite::run()` were ever invoked on a `static_suite` via a base-class
pointer — for instance during refactoring — the invocation of an empty
`std::function` would throw `std::bad_function_call` on hosted targets,
or produce undefined behaviour on bare-metal (where exceptions are
typically disabled).

Passing a no-op lambda is no more expensive at compile time and removes
the latent trap:

```cpp
: suite{ name, runner, runner.static_suites_count () + 1,
         [] (suite&) noexcept {} }
```

---

### ~~36. Stale `#include <cstring>` in `deferred-reporter-inlines.h` (LOW)~~ — **FIXED**

**File:**
`include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines.h`

The file includes `<cstring>`:

```cpp
#include <charconv>
#include <cstring>
#include <cstdio>
```

None of the C string functions declared in `<cstring>` (`strlen`,
`strcpy`, `memcpy`, `strrchr`, etc.) are used anywhere in that file.
The only string processing performed is via `std::to_chars` (from
`<charconv>`) and `std::string::append`/`push_back`. The `<cstring>`
include is stale and should be removed.

---

### ~~37. Redundant `#include <ctime>` in `runner.h` (LOW)~~ — **FIXED**

**File:** `include/micro-os-plus/micro-test-plus/runner.h`

`runner.h` includes `<ctime>` directly:

```cpp
#include <functional>
#include <memory>
#include <ctime>
```

However, `runner.h` does not use any declaration from `<ctime>` in its
own body (`time_t`, `struct tm`, `clock_t`, `mktime`, etc. are absent).
`runner.h` already includes `timings.h`, which itself includes `<ctime>`
for the `timespec` type used by `timestamps`. The `<ctime>` include in
`runner.h` is therefore redundant and should be removed.

---

## Positive Observations (Fourth Review)

- All trace blocks in the remainder of `reporter-tap.cpp` and
  `reporter-human.cpp` correctly use `trace::printf()` — the two
  defective calls in `end_suite()` and `end_subtest()` are isolated
  anomalies.
- Fixed-size `snprintf` buffers in the TAP reporter use `sizeof(buffer)`
  correctly, preventing overflows.
- `deferred_reporter_base::operator<<` uses `std::to_chars` with a
  fixed-size stack buffer, correctly avoiding dynamic allocation.
- `timings::compute_elapsed_time` is guarded by `assert(has_timestamps())`
  as required.
