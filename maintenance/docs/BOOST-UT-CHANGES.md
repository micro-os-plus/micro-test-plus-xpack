# Boost UT API changes from v1.1.8 to v2.3.1

Date: 2026-10-21, on branch `xpack-development`, commit `dbe0c110`
(µTest++ `6.0.0-pre`).

Purpose: µTest++ was derived from v1.1.8 of Boost UT
(<https://github.com/boost-ext/ut>). This report lists the changes to the
UT API made between the tags `v1.1.8` (2020-08-02) and `v2.3.1`
(2025-04-02), checks each one against the current µTest++ code, and
recommends whether it is worth adding to µTest++. Section 11 then
compares the latest UT code (`master`, after `v2.3.1`) with the latest
µTest++ code, including the UT features older than v1.1.8 that µTest++
never took; section 12 records which µTest++ files derive from UT.

Scope: `include/boost/ut.hpp` (the whole library), the new
`include/boost/ut.cppm`, the `README.md`, and the `example/` folder of
UT; 195 commits, 61 files, about 1470 lines added and 640 removed in the
header when whitespace is ignored. The changes to the UT build files, CI
workflows, and tests were not reviewed, except where they reveal an API
change.

Method: the header was compared with `git diff -w v1.1.8 v2.3.1`, read
in full, and the commits behind the non-obvious changes were inspected
individually. Each change was then looked up in the µTest++ headers
(`include/micro-os-plus/micro-test-plus/`) and sources (`src/`). One
claim (that `expect()` rejects `std::optional`) was confirmed with a
probe program compiled with Apple clang (`-std=c++20`); the other
statements about µTest++ are based on reading the code.

## Summary

The two projects diverged structurally after v1.1.8. UT kept its
global runner (`cfg<override>`), free `expect()`, and macro-free
registration by assignment; µTest++ has an explicit `runner`, member
checks (`t.expect()`), a compiled library, and two internal reporters.
As a result, about half of the UT changes do not map onto µTest++ at
all, and most of the remaining ones were already made independently in
µTest++ (C++20 concepts, sized literals, robust `type_name()`, dynamic
test names, named suites, restricted `has_value`).

The changes worth adding are few and small:

| #   | Change                                                      | Recommendation | Cost   | Breaking |
| --- | ----------------------------------------------------------- | -------------- | ------ | -------- |
| 1   | `expect()` accepting types explicitly convertible to `bool` | **Adopt**      | Small  | No       |
| 2   | Lazily evaluated messages (`<< [&] { ... }`)                | **Adopt**      | Small  | No       |
| 3   | `approx()` for integral types                               | Consider       | Small  | No       |
| 4   | Range detection with `std::ranges::range` in the formatter  | Consider       | Small  | Unlikely |
| 5   | Data-driven test cases with generated names                 | Consider       | Medium | No       |
| 6   | `--list` command-line option                                | Consider       | Small  | No       |
| 7   | JUnit XML reporter                                          | Defer          | Large  | No       |
| 8   | C++20 module interface                                      | Defer          | Medium | No       |

One UT change should be explicitly **not** copied: the fatal assertion
exception now derives from `std::exception` (item 9.4), which lets the
code under test swallow a failed fatal check.

The rest of this report gives the details, grouped by area. Each item
states what changed in UT, what µTest++ has today, and the verdict:

- **Adopt**: worth doing, low risk;
- **Consider**: useful, but the benefit is moderate or the design needs
  a decision;
- **Defer**: useful for some users, but too costly now;
- **Covered**: µTest++ already has it, possibly in another form;
- **Not applicable**: depends on a UT design that µTest++ does not share;
- **Reject**: harmful, or contrary to the µTest++ goals.

## 1. Checks and expressions

### 1.1. `expect()` accepts types explicitly convertible to `bool`

UT: the constraint of `expect()` changed from
`is_convertible_v<TExpr, bool>` to the new concept

```c++
template <class From, class To>
concept explicitly_convertible_to =
    requires { static_cast<To>(std::declval<From>()); };
```

so `expect(opt)`, `expect(ptr)`, and `expect(fn)` compile for
`std::optional`, `std::unique_ptr`, `std::shared_ptr`, `std::function`,
`std::expected`, and the application types with an `explicit operator
bool`.

µTest++: `extension::checkable` is
`is_op<T> or std::convertible_to<T, bool>`, which requires an implicit
conversion. A probe confirmed that `checkable<std::optional<int>>` and
`checkable<std::unique_ptr<int>>` are false, so `t.expect (opt)` does not
compile and the user must write `t.expect (opt.has_value ())` or
`t.expect (ptr != nullptr)`.

Assessment: a common, harmless convenience. The `check_result`
constructor already evaluates the expression with `static_cast<bool>`,
so the decision logic needs no change. The formatter does: for a type
that is neither an expression nor printable (such as `std::optional`),
`expression << expr` must be replaced by writing the converted `bool`
value, so that the report shows `false` rather than failing to compile.

Verdict: **Adopt**. Change `checkable` to use an explicit conversion,
and format the non-printable operands through `static_cast<bool>`. Add
unit tests with `std::optional`, `std::unique_ptr`, and a class with an
`explicit operator bool`.

Status: fixed in #155, commit `2933857e`, on 2026-10-21. `checkable`
tests the contextual conversion (`t ? true : false`, on a `const`
value), which, unlike `static_cast<bool>`, rejects the scoped
enumerations. All the operands
that are only explicitly convertible are written as the converted
`bool`, not only the non-printable ones, since the value of a printable
one, such as the contents of a `std::optional<bool>`, could contradict
the outcome; the operands accepted before are written as before.

### 1.2. Lazily evaluated messages

UT (commit `c4680e9`): `expect_::operator<<` invokes the argument when
it is a callable with a non-`void` result, and only when the check
failed:

```c++
std::expected<bool, std::string> e = std::unexpected ("lazy evaluated");
expect (e.has_value ()) << [&] { return e.error (); } << fatal;
```

µTest++: `check_result::operator<<` already skips the _formatting_ of
the message when the outcome is not written, but the argument
expression itself is evaluated before the operator is called. For
`e.error ()` on an `expected` holding a value, or `*ptr` on a null
pointer, this is undefined behaviour in a passing check. A lambda is
not `printable`, so today it does not compile.

Assessment: the semantics fit µTest++ well, including `require()`: the
`check_result` destructor runs at the end of the full expression, after
the message operators. The only design point is the priority between
the two interpretations of a type that is both invocable and printable;
UT gives priority to invocation, which is the less surprising choice
for lambdas.

Verdict: **Adopt**. Add an overload constrained with
`std::invocable<T> and printable<std::invoke_result_t<T>>`, invoked only
when the outcome is written (which, in the quiet modes, is only on
failure).

Status: fixed in #156, commit `03af21b0`, on 2026-10-21. The concept is
`detail::lazy_message`, internal, limited to the class types: the
function pointers stay printable, written as addresses, and are not
called, unlike in UT. The callables are called only if the check
fails, not whenever the outcome is written, since at the normal
verbosity the passed checks are written too; after a success they
append nothing.

### 1.3. Fatal checks: `fatal(expr)` and `expect(expr) << fatal`

UT (commits `19a8042`, `e5491d9`): two new spellings of a fatal check
were added, and the documentation switched to the first:

```c++
expect (fatal (1 == 2_i)) << "message";   // new, preferred
expect (1 == 2_i) << fatal;               // new
expect ((1 == 2_i) >> fatal);             // v1.1.8, still supported
```

Both were motivated by a v1.1.8 limitation: a custom message could not
be attached to a fatal check.

µTest++: `t.require (expr) << "message"` has always allowed it.
`assume()` remains as a deprecated alias.

Verdict: **Covered**. Adding more spellings for the same operation would
only enlarge the API.

### 1.4. `approx()` with an explicit epsilon

UT (commits `6e24d43`, `adabb53`): a new function comparator
`approx (lhs, rhs, epsilon)`, first named `near` and renamed because of
a `<Windows.h>` macro. It accepts any arithmetic types, computes the
difference with a new `math::abs_diff()` that does not wrap around for
unsigned types, and is reported as `lhs ~ (rhs +/- epsilon)`.

µTest++: `approx (value, epsilon)` returns a value wrapper with an
explicit tolerance, used as `t.expect (x == mt::approx (1.0, 0.01))`. It
is restricted to floating-point types.

Assessment: the floating-point case is fully covered, with a syntax
that reads better in operator expressions. The missing case is an
integral tolerance, which is realistic on embedded targets (timer
ticks, ADC readings, and counts with a known jitter of one or two
units). If added, the difference must be computed as UT does, without
subtracting the larger unsigned value from the smaller one.

Verdict: **Consider**, low priority. If done, extend the existing
`approx()` to the integral types rather than adding a second form with
three arguments.

Status: fixed in #157, commit `23f1a2ce`, on 2026-10-21. Implemented
as in UT, at the request of the maintainer, rather than by extending
the wrapper, which is kept: `approx (lhs, rhs, epsilon)` is a function
comparator, reported as `lhs ~ (rhs +/- epsilon)`. Unlike in UT, the
distance of two integers is computed exactly, without wrap-around or
overflow, also for mixed signedness, and a negative tolerance fails.

### 1.5. Constraints on the function comparators

UT (commit `eba2c71`): `eq()`, `neq()`, `gt()`, `ge()`, `lt()`, `le()`,
and `approx()` now require both operands to be stream-insertable, so
that an operand that cannot be reported is diagnosed at the call site
rather than deep inside the printer.

µTest++: the comparators in `function-comparators.h` are not
constrained; an operand without a formatter `operator<<` is diagnosed
where the expression is formatted.

Assessment: a better compiler diagnostic, at no run-time cost. The
constraint would be `extension::printable` for both operands. Care is
needed for `container_like` operands and for the expression templates
themselves, which must remain accepted.

Verdict: **Consider**, as part of a diagnostics clean-up; it is not
listed in the summary table because it changes no behaviour.

Status: fixed in #158, commit `d3c3cdb8`, on 2026-10-21. The six
comparators require `extension::printable` for both operands; with an
operand that has no formatter, the diagnostic of Apple clang 17 is 13
lines long, at the check, instead of 148, in the formatter.

### 1.6. Ranges in the formatter and in the operators

UT: the container overloads changed from
`is_container_v<T> and not has_npos_v<T>` to
`std::ranges::range<T> and not ostreamable<T>`, both in the printer and
in the `operators` `==` and `!=`.

µTest++: the formatter uses `detail::container_like<T> and not
detail::has_npos<T>` (members `begin()` and `end()`). The container
operators were removed deliberately (see `API-COMPATIBILITY.md`,
item 20).

Assessment: `std::ranges::range` also covers the built-in arrays, the
types with non-member `begin()` and `end()`, and the views. The
exclusion of the printable types is the more important part: a type
that is both a range and printable (`std::filesystem::path`, which is a
range of `path` elements, or an application type with its own
`operator<<`) is printed by its own operator rather than element by
element, and cannot recurse indefinitely. Whether the current
`container_like` rule causes an ambiguity or a recursion for such
types in µTest++ was not verified.

Verdict: **Consider** for the formatter, after a probe with
`std::filesystem::path` and with a printable application container.
**Not applicable** for the operators.

Status: fixed in #159, commit `9f98e14f`, on 2026-10-21. The probe
confirmed the defect: formatting a `std::filesystem::path` overflowed
the stack. The ranges are detected as by a range-based `for` statement
(`detail::formattable_range`), without `<ranges>`, which would add 8%
to 14% to the compile time; the arrays, the strings, the ranges of
their own type, and the ranges of elements that are not printable are
excluded. UT's exclusion of the printable types was not needed.

### 1.7. `type<T>` comparisons

UT (commits `44bcbe4`, `36a8650`): `type<T> == expr` compares the type
of an expression, and a bug where `type<T> != type<T>` returned `true`
was fixed.

µTest++: there is no `type<T>`.

Verdict: **Reject**. Type checks belong in `static_assert()` with
`std::is_same_v`, which fails at compile time and costs nothing at run
time.

### 1.8. Named boolean literals

UT (commit `572f180`): `"name"_b` now prints its name on failure, and
two named booleans compare equal.

µTest++: `"name"_b` returns a `detail::named_bool`, which the formatter
prints by name.

Verdict: **Covered**.

### 1.9. Literals and value wrappers

UT (commits `3b05dca`, `ca6d4e1`): new literals `_sc`, `_ull`, `_i8`,
`_i16`, `_i32`, `_i64`, `_u8`, `_u16`, `_u32`, and `_u64`, with the
matching type aliases; `math::num()` was rewritten, and fixes were made
to the detection of the compile-time constants
(`has_static_member_object_value`, commit `916587a`).

µTest++: all these literals exist, with the wrappers `to_sc`, `to_ull`,
`to_i8` to `to_u64`; `detail::has_value` is restricted to the framework
expressions (`is_op<T> and requires { T::value; }`), which avoids the
v1.1.8 problem of treating any application type with a `value` member
as a constant.

Verdict: **Covered**.

### 1.10. Custom source location

UT: a new example passes a `source_location` explicitly to `expect()`,
for helper functions that report the location of their caller.

µTest++: `expect()` and `require()` take the location as a defaulted
parameter.

Verdict: **Covered**. A short example in the website guide might be
useful, since the feature is not obvious.

## 2. Test definition

### 2.1. Data-driven test cases with generated names

UT (commits `20f2c3f`, `4804ae6`, `644e29d`, `7151a32`): the `|`
operator now accepts any `std::ranges::range`, including views, and
each instance is given a distinct name, built from the value for the
arithmetic types and `bool`, and from the ordinal and the type name for
the others; applications may overload `format_test_parameter()` for
their own types:

```c++
"args"_test = [] (auto arg) { expect (arg > 0_i); }
    | std::views::iota (1, 4);
// "args (1)", "args (2)", "args (3)"

"types"_test = []<class T> (T arg) { /* ... */ }
    | std::tuple{ 42, true, std::complex{ 1.5, 2.0 } };
// "types (42, int)", "types (true, bool)",
// "types (3rd parameter, std::complex<double>)"
```

µTest++: `test (name, callable, arguments...)` passes one fixed set of
arguments to one test case. Since `test_case_name` accepts a
`std::string`, and the test case runs before the temporary string is
destroyed, a loop with generated names already works:

```c++
for (int v : { 1, 2, 3 })
  {
    ts.test ("args (" + std::to_string (v) + ")",
             [] (auto& t, int arg) { t.expect (mt::gt (arg, 0)); }, v);
  }
```

Assessment: the loop covers ranges; it does not cover a heterogeneous
`std::tuple`, which needs `std::apply` and a fold expression. A helper
(for example `ts.test_each (name, values, callable)`) would remove the
boilerplate and give consistent names, but it adds API surface, a
naming policy, and a customisation point to document. Generated names
also cost a `std::string` allocation per instance, which UT accepts;
in µTest++ the cost is the same, but the string is only a temporary,
since a test case runs within the call to `test()` and its name is
not copied.

Verdict: **Consider**. As a first step, document the loop idiom in the
website guide; decide on a helper only if users ask for it.

Status: fixed in #160, commit `1e21b785`, on 2026-10-21. Implemented
as a helper, at the request of the maintainer, instead of only
documenting the loop: `test_each (name, values, callable)`, on the
suites and the test cases, for braced lists, ranges, and tuples. The
names show the value written as in the messages, or the position for
the values that cannot be written; UT names only the arithmetic values
and `bool`, and the others by ordinal and type.

### 2.2. Dynamic test names

UT (commit `9873e7f`): the test name in `events::test` became a
`std::string`, to fix a dangling reference with names built at run time
(issue 569).

µTest++: `test_case_name` accepts a `std::string`; the name is not
copied, but this is safe, because the test case runs within the call
to `test()`, while the temporary string is still alive.

Verdict: **Covered**.

### 2.3. Named suites

UT (commit `788f6b4`): `suite<"name"> s = [] { ... };`, using a
`fixed_string` template parameter; the unnamed suites are reported as
`"unnamed suite"`, and the reporters receive new `suite_begin` and
`suite_end` events.

µTest++: every suite has a name, given to the constructor of `suite`
or `static_suite`; the reporters already handle the suite boundaries.

Verdict: **Covered**.

### 2.4. Examples without API changes

UT added examples for suites as `static inline` class members, for
free-standing BDD steps (`scenario ("..."); given ("...");`), for a
`main()` that sets the filter from `argv`, and for an `[[expect]]`
attribute trick; the Gherkin steps gained typed parameters
(`lexical_cast`). None of them changes the API that µTest++ shares.

Verdict: **Not applicable**.

## 3. Logging

### 3.1. `log()` with `std::format`

UT (commits `bf8388f`, `837807e`): when the library provides
`std::format`, `log ("pre {} == {}", 42, 43)` formats a message into the
output; the stream form `log << "msg"` remains.

µTest++: there is no log facility; messages are attached to checks,
and the application may write to `stdout` or use the trace channel.

Assessment: `std::format` is expensive in code size on the embedded
targets (it pulls in locale-aware and floating-point formatting), and
its availability in the Arm and RISC-V toolchains is uneven. An
unconditional log channel that is interleaved correctly with the
reporter output (and is valid TAP, as a comment line) may be useful,
but it is a separate design question, not a port of the UT feature.

Verdict: **Reject** the `std::format` form. A reporter-aware
informational message (for example `t.info (...)`, written as a TAP
comment) may be considered separately.

## 4. Runner and command line

### 4.1. Catch2-like command-line options

UT (commit `2f02b0c`): `detail::cfg` gained a parser for an option set
modelled after Catch2: `-h`, `-l` (`--list-tests`), `-t`
(`--list-tags`), `-s` (`--success`), `-o` (`--out`), `-r`
(`--reporter`), `-a` (`--abort`), `-x` (`--abortx`), `-d`
(`--durations`), `--use-colour`, `--libidentify`, and several others
that are parsed but not implemented (`--name`, `--input-file`,
`--min-duration`, `--order`, `--rng-seed`, `--wait-for-keypress`). An
unknown option after the first known one ends the program with
`std::exit (-1)`. Positional arguments form a glob query over the test
names and tags, with `!` for negation.

µTest++: `--reporter`, `--output-file`, `--filter`, and the verbosity
options `--silent`, `--quiet`, and `--verbose`; the other arguments are
ignored, because the applications may define their own; the colours are
enabled automatically when `stdout` is a terminal; durations are
already reported.

Assessment, per option:

- `--list`: prints the names of the suites and test cases without
  running them. Useful for CI scripts and for IDE test explorers; it
  needs a dry-run mode in which the bodies are walked but no checks are
  evaluated, which is not trivial, since the test cases are discovered
  only by running the suite bodies. Worth a design note.
- `--abort` and `--abortx`: stopping after the first or the N-th
  failure is of limited value for the µTest++ use cases (short runs,
  often on targets where restarting is the expensive part), and
  `require()` already stops a test case.
- `--use-colour`: forcing the colours on would help in the CI systems
  that render ANSI sequences but do not provide a terminal; small.
- `--success`: covered by `--verbose`.
- Exiting on unknown options: contrary to the µTest++ rule of ignoring
  them, and harmful on embedded targets.
- `!` negation in the filter: a possible extension of `--filter`, but
  no request for it is known.

Verdict: **Consider** `--list` (in the summary table) and, at lower
priority, a forced colour option; **Reject** the rest of the set and
the exit on unknown options.

Status: the colour option fixed in #162, commit `87e470fc`, on
2026-10-21; `--list` remains open. Unlike UT, the primary option
follows the GNU tools: `--color[=always|never|auto]`, with the GNU
synonyms, where `--color` alone means `always` and the value is
accepted only after `=`; the UT and Catch2 form, `--use-colour
<yes|no|auto>`, is accepted as an alternative. The default remains
`auto` (`isatty()`, on POSIX only); the TAP reporter and the output
file never receive colours, and `runner_options::colour` sets the mode
without a command line.

### 4.2. Implicit capture of `argc` and `argv`

UT (commits `4f260fd`, `9a8fd97`): the arguments are captured before
`main()` by a function marked `__attribute__((constructor(101)))` that
takes `(int argc, const char* argv[])`, and on MSVC from `__argc` and
`__argv`; `run()` also accepts them explicitly through `run_cfg`.

µTest++: `runner::initialise (argc, argv)`, or `initialise (options)`
without a command line.

Assessment: passing arguments to the constructor functions is a glibc
extension; with newlib and on bare-metal targets the parameters hold
whatever is in the registers.

Verdict: **Reject**.

### 4.3. Summary printed once

UT (commit `5c60610`): the reporter no longer guards the summary with a
`static` flag; the runner calls it once, through `report_summary()`.

µTest++: the session state of the runner guarantees a single summary.

Verdict: **Covered**.

## 5. Reporters

### 6.0. JUnit XML reporter

UT (commits `2f02b0c`, `e45ea7e`): a new `reporter_junit` class,
selected with `--reporter junit` and written to the file given with
`-o`; it also became the default reporter for the console output,
redirecting `std::cout` into a buffer while each test runs.

µTest++: two internal reporters, TAP version 14 (the default) and
human-readable; custom reporters are not supported.

Assessment: JUnit XML is what Jenkins, GitLab, and Azure Pipelines
display natively, so there is real demand. However, TAP output can be
converted with existing tools (for example the JUnit reporter of
node-tap, mentioned in `src/reporter-tap.cpp`, or `tap-junit`). The UT
implementation is not suitable for embedded targets: it builds an
`std::unordered_map` tree of `std::unique_ptr` nodes, uses
`std::stack`, `std::chrono::high_resolution_clock`, and `std::ofstream`,
and replaces the buffer of `std::cout`. A µTest++ version would need a
design of its own, and the whole report must be kept in memory until
the end, because the XML attributes of a suite include its totals.

Verdict: **Defer**. Document the TAP to JUnit conversion in the website
guide; reconsider if users of the native builds ask for it.

Status: deferred, recorded in #161 on 2026-10-21; not planned for
v6.0.0, and not implemented.

### 5.2. New reporter events

UT: new events `run_begin`, `suite_begin`, `suite_end`, and
`test_finish` (the end of a nested test, previously not reported); a
colour for the skipped tests.

µTest++: the reporters are internal and already receive the start and
end of the suites and of the nested test cases, and report the skipped
suites.

Verdict: **Covered**.

## 6. Reflection

### 6.1. `reflection::type_name()`

UT (commits `bd178db`, `c3ed7a2`, `c0319c7`): the fixed offsets into
`__PRETTY_FUNCTION__` were replaced by offsets computed at compile time
from a probe type, and a `decay_type_name()` variant was added.

µTest++: `type_name()` searches the signature for the `[T = ` (clang) or
`[with T = ` (GCC) marker, and returns `"unknown"` for other compilers.

Verdict: **Covered**. The decayed variant is trivial for the user
(`type_name<std::decay_t<T>> ()`) and is not needed.

### 6.2. `reflection::source_location`

UT (commit `90ba172`): an alias of `std::source_location` when the
library provides it (except with Apple libc++), otherwise the built-in
class.

µTest++: the problem of a type that depends on the headers included
before µTest++, and differs between translation units, was found and
fixed independently (`API-REVIEW.md`, item 1).

Verdict: **Covered**; nothing to take from the UT version.

## 7. Language and portability

### 7.1. C++20 only, concepts instead of SFINAE

UT (commits `255293e`, `093a915`, `1a07b02`, `2841097`): C++17 support
was dropped; `requires_t`, `is_valid()`, and the hand-written traits
were replaced by concepts and `std::` traits; `utility::string_view`
was replaced by `std::string_view`.

µTest++: already C++20, with concepts in `extension.h` and `detail`.

Verdict: **Covered**.

### 7.2. Removal of `BOOST_UT_FORWARD` and `BOOST_UT_IMPLEMENTATION`

UT (commit `4ac9033`): the split between a forward-declaring header and
a single implementation translation unit was removed.

µTest++: the non-template code is compiled once, in `src/*.cpp`.

Verdict: **Not applicable**.

### 7.3. `std::regex` removed

UT (commit `cce6120`): the filter no longer uses `std::regex`, to speed
up compilation; a minimal matcher supporting only `.` was added.

µTest++: never used `std::regex`; `utility::is_match()` handles `*` and
`?`.

Verdict: **Not applicable**.

### 7.4. MSVC and `<Windows.h>` compatibility

UT (commits `5fd8c5d`, `93cfddb`, `a9bcdbd`, `4309c9e`): the `min` and
`max` macros are saved and undefined around the header, and several
MSVC bugs are worked around.

µTest++: no use of `std::min` or `std::max` was found in the headers;
Windows is only a native test platform.

Verdict: **Not applicable** today; worth remembering if `std::min` or
`std::max` is ever used in a public header.

### 7.5. C++20 module interface

UT (commits `6bbd6ac`, `a0cd7c0`): the module declaration moved from the
header (guarded by `__cpp_modules`) to a separate `ut.cppm`; the header
uses `BOOST_UT_EXPORT` and skips the standard includes when built as a
module.

µTest++: no module interface.

Assessment: the module support of `arm-none-eabi-gcc` and of
`riscv-none-elf-gcc` is still immature, meson support is limited, and
CMake needs version 3.28 or later. µTest++ is also not header-only, so
the module would cover only the public headers.

Verdict: **Defer**.

### 7.6. Versioned inline namespace

UT: the inline namespace follows the version (`v1_1_8` to `v2_3_1`), to
prevent the mixing of objects built with different versions.

µTest++: no versioned namespace; the library is compiled from source
with each application.

Verdict: **Not applicable**.

## 8. Behaviour changes in UT without µTest++ counterpart

### 8.1. Default reporter

UT changed `cfg` from `runner<reporter<printer>>` to
`runner<reporter_junit<printer>>`, which changes the console output of
every UT program (buffering, indentation of the nested tests, and the
per-suite summaries).

Verdict: **Not applicable**; recorded only because examples taken from
recent UT documentation will not match the µTest++ output.

### 8.2. Fixes of unreachable code and warnings

UT moved the `return` statements of `throws_`, `nothrow_`, and `aborts_`
inside the `try` blocks (MSVC warning C4702), renamed shadowing
parameters, and added `noexcept` to the move constructor of
`utility::function`.

Verdict: **Not applicable**; µTest++ has its own implementation and
warning policy.

## 9. Changes that should not be copied

### 9.1. Exit on unknown command-line options

See item 4.1.

### 9.2. Implicit `argc` and `argv`

See item 4.2.

### 9.3. `std::format` in the core

See item 3.1.

### 9.4. Fatal assertion derived from `std::exception`

UT: `events::fatal_assertion` now derives from `std::exception`.

µTest++: the exception thrown by a failed `require()`
(`failed_requirement`, in `src/check-result.cpp`) is deliberately not
derived from `std::exception`, as documented in `test.h`.

Assessment: with the UT change, a test body, or the code under test
called from it, that contains `catch (const std::exception&)` catches
the fatal assertion and continues as if the check had passed its
fatal stage. This is a regression in UT, not an improvement.

Verdict: **Reject**; keep the current µTest++ design.

## 10. Suggested order of work

1. Items 1.1 and 1.2 (explicit `bool` conversion and lazy messages):
   small, non-breaking, and independent; each needs unit tests in
   `tests/sources/unit/` and a paragraph in the website guide.
2. Documentation only: the loop idiom for data-driven test cases
   (item 2.1), the custom source location (item 1.10), and the
   conversion of TAP to JUnit XML (item 6.0).
3. Probes for item 1.6 (printable ranges in the formatter), then a
   decision.
4. Design notes, if there is demand: `--list` (item 4.1), the integral
   `approx()` (item 1.4), and a `test_each()` helper (item 2.1).
5. Deferred: the JUnit reporter (item 6.0) and the module interface
   (item 7.5).

## 11. Comparison of the latest versions

Date: 2026-10-21. UT: `master` at commit `f6cf5f4` (2026-10-20),
58 commits after `v2.3.1`, not tagged; the inline namespace is still
`v2_3_1`. µTest++: branch `xpack-development` at commit `dbe0c110`.

Method: the UT header was compared with `git diff -w v2.3.1 f6cf5f4`
(about 470 changed lines, mostly in the JUnit reporter), and the whole
UT `master` header was then compared feature by feature with the
µTest++ public API, so that the UT features already present in v1.1.8,
which the sections above do not cover, are included.

Result: no new feature in UT `master` is worth adding. The one new
candidate comes from an old UT feature: skipping a test case from the
code (item 11.2.1).

| #      | Feature                                                  | Recommendation | Cost  | Breaking |
| ------ | -------------------------------------------------------- | -------------- | ----- | -------- |
| 11.2.1 | Skip a test case from the code, reported as TAP `# SKIP` | Consider       | Small | No       |

### 11.1. Changes after v2.3.1

#### 11.1.1. Hang in `den_size()` for large values

UT (commit `f6cf5f4`): the run-time count of the decimals of a
floating-point value looped forever when the value did not fit in
`unsigned long long`, because the conversion was undefined; the loop now
stops at half the range of the integer type.

µTest++: `math::count_decimals()` already stops at the magnitude from
which the type holds only integers (`integral_limit`, at most 2^63),
which also covers infinities and NaNs.

Verdict: **Covered**.

#### 11.1.2. Location of the fatal checks

UT (commits `1445a71`, `6dbe84f`): `fatal (expr)` now captures its own
`source_location`; before, a failed fatal check was reported at the
location of the previous check (`cfg::location`).

µTest++: `require()` takes the location as a defaulted parameter.

Verdict: **Covered**.

#### 11.1.3. A fatal check ends the program

UT (commits `9a4c8c7`, `af9b2a2`): a failed fatal check now prints
`terminated for the fatal issue` and calls `std::exit (-1)`; the runner
no longer catches the fatal assertion, so the remaining tests and
suites are not run, and no summary is printed.

µTest++: a failed `require()` stops only the current test case; the
other test cases and suites still run, and the summary is printed.

Verdict: **Reject**. Stopping the whole session hides all the results
after the first fatal failure, which on embedded targets means another
build and download cycle to see them.

#### 11.1.4. Rework of the JUnit and console reporter

UT (commits `024fcea` to `20bc09c`, `0f9adef`): the results became a
tree of nodes instead of maps keyed by name (so tests with equal names
are no longer merged), the per-suite summaries count the failed tests
rather than the failed checks, the skipped tests are counted and
coloured, the messages of the failed tests are shown, and the runner
prints `UT starts ===` and `Completed ===` banners, unconditionally,
from its constructor and destructor.

µTest++: the reporters are internal and already keep the suites and
test cases in order, with their own totals.

Verdict: **Not applicable**; the JUnit reporter itself remains
**Defer** (item 6.0).

#### 11.1.5. Dangling test names

UT (commits `f709ea9`, `59a9beb`): `detail::test` now keeps a temporary
`std::string` name alive in a `std::optional<std::string>` member.

µTest++: not needed, since a test case runs within the call to
`test()`, while the temporary is still alive (item 2.2).

Verdict: **Covered**.

#### 11.1.6. Other changes

- Tags kept on parameterised tests (commit `18690cf`): **Not
  applicable**, µTest++ has no tags (item 11.2.1).
- Colour of the parentheses of `and` and `or` (commit `b390c66`):
  cosmetic, **Not applicable**.
- Module interface (commits `e1260f1`, `e8d5269`): `import std` is no
  longer re-exported, the module file instantiates a few templates
  explicitly, and the CMake target `Boost::ut_module` is installed:
  see item 7.5, **Defer**.
- Implicit `argc` and `argv` disabled on Apple (commit `2f65579`):
  confirms that the mechanism is not portable (item 4.2, **Reject**).
- Bazel build (commit `53e17f2`): **Not applicable**.

### 11.2. UT features never taken into µTest++

These features were already present in v1.1.8 and are still in UT
`master`.

#### 11.2.1. Tags and skipped tests

UT: `tag ("name") / "test"_test = ...` attaches tags, which the runner
can select (`options.tag`, and the command-line query); the predefined
`skip` tag (`skip / "test"_test = ...`) reports the test as skipped
without running it.

µTest++: no tags; a test case or a suite is skipped only when
`--filter` does not select it, and the TAP reporter writes it as
`ok <n> - <name> # SKIP filtered`.

Assessment: tags need a vector of strings per test and a second
selection mechanism next to `--filter`, which is not justified for the
typical µTest++ programs. Skipping from the code, however, is useful on
its own: a test case for a feature that a board does not have, or that
is temporarily broken, can then be reported as skipped instead of being
removed or commented out. TAP 14 has the directive for it (`# SKIP
<reason>`), and the human reporter already counts the skipped test
cases.

Verdict: **Consider** a way to skip a test case from the code, with a
reason, for example a member function of the test case called at the
start of its body, or an overload of `test()`; **Reject** the tags.

#### 11.2.2. BDD and specification aliases

UT: `given`, `when`, `then`, `feature`, `scenario` (namespace `bdd`),
`describe` and `it` (namespace `spec`), and `should`, which create
nested tests labelled with their kind.

µTest++: nested test cases, created with `t.test (...)`.

Verdict: **Reject**. The aliases add only a label; a test case name such
as `"given an empty vector"` gives the same report without new API.

#### 11.2.3. Gherkin

UT: `bdd::gherkin::steps` parses a feature file at run time and binds
its steps to lambdas, with typed parameters.

Verdict: **Reject**. It needs text parsing and file access, and allocates
heavily, which is not suitable for the embedded targets.

#### 11.2.4. `that %` and `constant<>`

UT: `that % value` wraps a plain value so that the operators produce a
reportable expression; `constant<expr>` evaluates the expression at
compile time and reports it at run time.

µTest++: the value wrappers (`to_i()`, ..., `to_t<T>()`) and the
function comparators cover `that %`; compile-time checks belong in
`static_assert()`.

Verdict: **Covered** for `that %`, **Reject** for `constant<>`.

#### 11.2.5. Terse syntax

UT: with `using namespace boost::ut::operators::terse`, a statement such
as `42_i == sum (40, 2);` is a check, reported by the destructor of the
temporary expression through the global runner.

Verdict: **Not applicable**. The checks of µTest++ are member functions
of the test case, and there is no global runner to report to.

#### 11.2.6. `aborts()`

UT: `aborts (callable)` runs the callable in a child process created
with `fork()` and checks that it ended abnormally.

Verdict: **Reject**. It is limited to POSIX, and impossible on the
embedded targets, which are the main use of µTest++.

#### 11.2.7. Customisable runner, reporter, and printer

UT: the application may replace the runner, the reporter, or the
printer by specialising `cfg<override>`; the examples include a
parallel runner and a benchmark test type.

µTest++: custom reporters are deliberately not supported; the reporter
is selected with `--reporter` or `runner_options`.

Verdict: **Reject**, as a matter of design; the TAP output is the
supported integration point for other tools.

#### 11.2.8. `log`, `mut()`, dry run, and `type<T>`

Covered by earlier items: `log` (item 3.1, **Reject** the `std::format`
form), `mut()` (removed deliberately, `API-COMPATIBILITY.md`, item 19),
the dry run of `options.dry_run` (the `--list` option, item 4.1,
**Consider**), and `type<T>` (item 1.7, **Reject**).

### 11.3. µTest++ features with no UT counterpart

For context, the features of µTest++ that UT `master` does not have
(none of them needs to change):

- the TAP version 14 reporter, the default;
- the verbosity levels (`--silent`, `--quiet`, `--verbose`);
- the output file (`--output-file`), written in parallel with the
  console;
- `require()` stopping only the current test case, and the behaviour
  without exceptions;
- the function forms of the logical operators (`both()`, `either()`, and
  `negate()`);
- the static suites, run in the order of their names;
- `runner_options`, for the programs without a command line;
- the `extension` namespace, for application comparators and
  predicates reported like the built-in ones.

## 12. Provenance of the source files

Until 2026-10-21, every file in `include/` and `src/` stated that
"major parts of the code are inspired from v1.1.8 of the Boost UT
project" (except `stopwatch.h` and `inlines/stopwatch-inlines.h`). Each
file was compared, without comments, with the UT v1.1.8 header, and the
statement was kept only where the file declares or implements an entity
taken or adapted from UT, even if rewritten. It was removed where the
file holds a µTest++ design, even if the general idea is common to UT
and other frameworks. The package-level credit remains in `README.md`
and `LICENSE-Boost`.

Kept (26 files):

- `detail.h`, `inlines/detail-inlines.h`: the expression templates
  (UT `eq_`, `neq_`, `gt_`, ..., `and_`, `or_`, `not_`, `throws_`,
  `nothrow_`);
- `values.h`, `inlines/values-inlines.h`: the value wrappers and the
  compile-time constants (UT `value`, `integral_constant`,
  `floating_point_constant`);
- `literals.h`, `inlines/literals-inlines.h`: the user-defined literals
  and the wrapper aliases (UT `literals`, `_i`, ..., `_t`);
- `math.h`, `inlines/math-inlines.h`: UT `math` (`abs`, `pow`, `num`,
  `den`, `den_size`);
- `operators.h`, `inlines/operators-inlines.h`: UT `operators`;
- `function-comparators.h`, `inlines/function-comparators-inlines.h`: UT
  `eq()`, `neq()`, `gt()`, ...;
- `exceptions.h`, `inlines/exceptions-inlines.h`: UT `throws()` and
  `nothrow()`;
- `extension.h`: the concepts derived from UT `type_traits` (`is_op`,
  `has_epsilon`, `has_value`, `has_npos`, `container_like`);
- `expression-formatter.h`, `inlines/expression-formatter-inlines.h`,
  `src/expression-formatter.cpp`: UT `printer`;
- `reflection.h`, `inlines/reflection-inlines.h`, `src/reflection.cpp`:
  UT `reflection` (`source_location`, `type_name()`) and the
  `short_name` of the UT reporter;
- `utility.h`, `inlines/utility-inlines.h`, `src/utility.cpp`: UT
  `is_match()` and `split()` (`is_match()` was rewritten without
  recursion, with the same contract);
- `test.h`, `inlines/test-inlines.h`: `expect()` and `require()`, with
  the signature and the streamed message of UT `expect()`.

Removed (20 files):

- `micro-test-plus.h`: only includes the other headers;
- `check-result.h`, `inlines/check-result-inlines.h`,
  `src/check-result.cpp`: the result of a check, reported by its
  destructor, with the requirement kind; UT `expect_` shares only the
  idea of the streamed message;
- `counters.h`, `inlines/counters-inlines.h`, `src/counters.cpp`: a
  µTest++ class; UT counts the same quantities in two anonymous
  structures of its reporter, which is common to all frameworks;
- `reporter.h`, `inlines/reporter-inlines.h`, `src/reporter.cpp`,
  `reporter-human.h`, `src/reporter-human.cpp`, `reporter-tap.h`,
  `src/reporter-tap.cpp`: the µTest++ reporters (the expression
  printing derived from UT moved to the expression formatter);
- `runner-options.h`, `runner.h`, `inlines/runner-inlines.h`,
  `src/runner.cpp`: the explicit runner, its options, and the
  command-line parser; the level-wise `--filter` uses `is_match()`, but
  not the UT path syntax;
- `src/stopwatch.cpp`: UT v1.1.8 has no timing (the header already had
  no statement);
- `src/test.cpp`: the execution of the suites and test cases, the
  handling of unexpected exceptions, and the abort.

The borderline decisions are `check-result.*`, `counters.*`, and
`test.cpp` (removed), and `test.h`, `inlines/test-inlines.h`, and
`src/reflection.cpp` (kept).
