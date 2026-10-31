# API review 5

Date: 2026-10-31, on `xpack-development` at `bc0c39ce`.

## Scope

The public API of µTest++, as reached through
`micro-os-plus/micro-test-plus.h`: the runner and its options, the test
hierarchy, the checks and their results, the function comparators, the
exception checks, the `extension` namespace, the `utility` and
`reflection` namespaces, the expression formatter, and the observable
behaviour of the reporters and of the command line.

The deprecated functionality (everything under
`MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED`, `deprecated.h`, and
its inlines) was deliberately excluded. The previous reviews were not
consulted, so some findings may repeat decisions already taken; those
can be closed by reference.

The findings marked _Confirmed_ were reproduced with the native
`synthetic-posix-cmake-clang-debug` build (clang 21.1.8, macOS), either
with the existing test programs or with a small probe program linked
against `top-bin/libmicro-test-plus.a`.

## Summary

| ID | Severity | Topic |
| --- | --- | --- |
| [H1](#h1) | High | `--help` and option errors reject the suites added after `initialise()` (fixed, #216) |
| [M1](#m1) | Medium | `all_of()`, `any_of()`, and `negate()` bypass the check guard (fixed, #217) |
| [M2](#m2) | Medium | `application_arguments()` contradicts its contract for unparsed options (fixed, #218) |
| [M3](#m3) | Medium | String quoting depends on the static type of the operand (fixed, #219) |
| [M4](#m4) | Medium | `--colour never` silently enables colours and ends the parsing (fixed, #220) |
| [L1](#l1) | Low | Integer suffixes collide with the duration units (fixed, #221) |
| [L2](#l2) | Low | A named check result reports out of order (fixed, #222) |
| [L3](#l3) | Low | The `runner_options` constructor writes to `stderr` (fixed, #223) |
| [L4](#l4) | Low | The extension operators lack the operand normalisation (fixed, #219, #224) |
| [L5](#l5) | Low | No way to construct a formatter without `detail` (fixed, #225) |
| [L6](#l6) | Low | Public mutators on `counters` (fixed, #226) |
| [L7](#l7) | Low | Suite names reject `std::string_view` for a reason that does not apply (fixed, #227) |
| [L8](#l8) | Low | Documentation drift (fixed; remainder withdrawn) |

---

## High

<a id="h1"></a>

### H1. `--help` and option errors reject the suites added after `initialise()`

**Fixed in** `c826cd6a` (#216), on 2026-10-31: a new
`session_state::declined`, set by the help, option error, and output
file error paths of `initialise()`; `register_suite()` discards the
suites of a declined session silently, and `run_suites()` returns the
stored exit code. The unit test "Runner option errors" now checks the
unknown option and the output file error cases; `--help` follows the
same path and is not tested, since its usage text would be recorded in
the expected output.

_Confirmed._

**Location:** `src/runner.cpp:314-315`, `src/runner.cpp:339-340`,
`src/runner.cpp:566-571`, `src/runner.cpp:583-589`.

When the options request `--help`, have errors, or name an output file
that cannot be opened, `runner::initialise()` writes its message and
sets `session_state_` to `finished`. The usual `main()` then continues
with `add_suite()`, as `tests/sources/suite/src/main.cpp` does.
`register_suite()` treats `finished` as "after `run_suites()`", so it
rejects each suite with a false message and calls `mark_rejected()`,
which raises the exit code from 0 to 1.

```console
$ suite-test --help
Usage: suite-test [options] [--] [arguments]
...
error: suite 'Local suite 1' added after run_suites() started, rejected
...
error: suite 'Local suite 2' added after run_suites() started, rejected
$ echo $?
2
```

(Two runners, each returning 1, summed by the test program.) With
`--bogus`, the exit code stays 2, but the same false rejection messages
are written.

This contradicts the documentation of `runner_options::help`
(`runner-options.h:462-473`), which states that `run_suites()` returns
0, and it makes `program --help` fail in scripts. The message itself is
wrong: `run_suites()` was never called. `add_top_suite()` and
`after_test_case_create()` already handle this case by returning
silently when `options_.help || has_option_errors()`; `register_suite()`
is the only entry point that does not.

**Recommendation:** Use a distinct state for a session that was declined
during `initialise()` (for example `session_state::declined`), or test
`options_.help || has_option_errors()` in `register_suite()` before the
state test, and discard the suite silently, without `mark_rejected()`.
Add a test that runs a program with `add_suite()` after `initialise()`
with `--help` and with an unknown option, and checks both the output and
the exit code.

---

## Medium

<a id="m1"></a>

### M1. `all_of()`, `any_of()`, and `negate()` bypass the check guard

**Fixed in** `e6e58964` (#217), on 2026-10-31: each operand of the
three functions is now constrained with `extension::checkable`, as for
`expect()`. Static assertions in `unit-static-asserts` check that the
always true operands are rejected and the valid ones still accepted.
The comments, the `checkable` description, and the User's Guide were
updated.

_Confirmed._

**Location:** `function-comparators.h:265-304`,
`inlines/function-comparators-inlines.h:217-292`,
`inlines/detail-inlines.h:592-600`.

`expect()` and `require()` are constrained with `extension::checkable`,
which rejects the `suspicious_condition` types (C strings, arrays,
function pointers, member pointers), since they are always `true`. The
logical combinators have no constraint at all, and their operators
convert each operand with `static_cast<bool>`, so the guard is bypassed
as soon as the condition is wrapped:

```cpp
const char* p = "abc";
t.expect (mt::all_of ("x", p));         // compiles, always passes
t.expect (mt::negate (mt::negate ("x"))); // compiles, always passes
```

Both checks passed silently in the probe, whilst `t.expect ("x")` is
rejected (or deprecated). The typical mistake this guard exists for,
writing `all_of (name, "expected")` instead of `all_of (eq (name,
"expected"), ...)`, is exactly the one that goes undetected.

**Recommendation:** Constrain each operand of `all_of()`, `any_of()`,
and `negate()` with `extension::checkable`, as for `expect()`. This is
a source-level breaking change only for code that is already wrong.

<a id="m2"></a>

### M2. `application_arguments()` contradicts its contract for unparsed options

**Fixed in** `a3d6d3d6` (#218), on 2026-10-31, as recommended for the
long term: `arguments` is private (`arguments_`) and read with the
`const` accessor `arguments()`, so the position where the application
arguments start cannot go stale; the options of a default-constructed
object have no application arguments, as documented.

_Confirmed._

**Location:** `runner-options.h:397`, `runner-options.h:528-545`,
`runner-options.h:592`, `inlines/runner-options-inlines.h:102-112`.

The documentation states that the span is empty "if the options were not
parsed from a command line". `application_begin_` is initialised to 0,
and only the parsing constructor changes it, so for options built in
code, with the public `arguments` member assigned, the span returns all
the arguments, including `arguments[0]`:

```cpp
mt::runner_options o;
o.arguments = { "prog", "--verbose" };
o.application_arguments ().size (); // 2, documented as 0
```

The underlying issue is that `runner_options` mixes public input fields
with private state derived from parsing them (`errors_`,
`unknown_option_`, `application_begin_`); changing a public field after
parsing leaves the derived state stale, and nothing in the type tells
the user which fields are inputs and which are records of the parse.

**Recommendation:** At minimum, initialise `application_begin_` to a
sentinel that means "not parsed" and return an empty span for it. In the
longer term, consider making `arguments` read-only (a private member
with an accessor), since the runner uses it only as the record of the
command line (for the `Running:` line, the help text, and the default
top suite name).

<a id="m3"></a>

### M3. String quoting depends on the static type of the operand

**Fixed in** `1123a982` (#219), on 2026-10-31, with the lower-impact
option: the stored operands of `extension::compare_op` and
`extension::predicate_op` are prepared by `as_operand()`, and the
`const char*` elements of ranges, pairs, tuples, and optionals are
written quoted. The `const char*` overload stays unquoted, so the text
written by the application `operator<<` functions is unchanged; the
User's Guide explains how to quote a value there. The larger change
(quoting all and adding a raw text API) was not made.

_Confirmed._

**Location:** `expression-formatter.h:293-294`,
`expression-formatter.h:396-406`, `src/expression-formatter.cpp:193-205`,
`src/expression-formatter.cpp:293-305`,
`inlines/detail-inlines.h:1143-1179`.

In the expressions, `std::string` and `std::string_view` values are
written quoted and escaped, whilst `const char*` values are written
unchanged, since the `const char*` overload doubles as the way to write
punctuation from the application `operator<<` functions. Only the
built-in comparators turn their C string operands into `c_string`
(through `as_operand()`), which is quoted; everywhere else a C string
value appears raw:

```text
✗ opt const char* FAILED (x == nullopt)
✗ opt string FAILED ("x" == nullopt)
✗ extension with char array FAILED (hello starts with help)
✗ extension with string FAILED ("hello" starts with help)
```

The same applies to the elements of containers, pairs, tuples, and
optionals of `const char*`, and to the fields that an application
`operator<<` writes. An empty C string is then invisible, and a value
with spaces cannot be told apart from the surrounding text. Conversely,
an application that writes a separator as a `std::string_view` (for
example `", "sv`) gets it quoted.

The rule is documented, but it is a trap: the quoting of a value depends
on whether it was stored as a pointer or as a string, which the reader
of a failed report cannot know.

**Recommendation:** Separate the two roles explicitly: quote all string
values, `const char*` included, in the expression mode, and give the
application functions an explicit way to append raw text (for example a
member `text (std::string_view)`, or an `extension::raw` wrapper). If
this is too disruptive, at least apply `as_operand()` to the operands of
`extension::compare_op` and `extension::predicate_op` (see
[L4](#l4)), and quote the `const char*` elements of ranges, optionals,
pairs, and tuples.

<a id="m4"></a>

### M4. `--colour never` silently enables colours and ends the parsing

**Fixed in** `c824ff2d` (#220), on 2026-10-31, with the first
recommendation: the GNU rule is kept, and a bare `--colour` or `--color`
followed by a mode word is now an option error that suggests the `=`
form and the `--` separator. The space form is still not accepted,
since the value is optional and would be ambiguous with an application
argument.

_Confirmed._

**Location:** `src/runner-options.cpp:280-295`.

`--colour` alone means `always`, and its value is accepted only after
`=`. The space-separated form is therefore read as `--colour` followed
by an application argument, which ends the option parsing:

```console
$ sample-test --reporter human --colour never --verbose
        ✗ ... FAILED (main.cpp:183, "never" == "one")
        ✗ ... FAILED (main.cpp:185, "--verbose" == "two")
```

The colours were on (escape sequences in the piped output), and both
`never` and `--verbose` were passed to the application, so `--verbose`
was silently ignored. The behaviour is documented and follows GNU `ls`,
but it differs from all the other options with values (`--reporter`,
`--output-file`, `--filter`, and `--use-colour`), which accept both the
`=` and the space forms; GNU `ls` at least fails on the stray word,
whilst here it is silently accepted.

**Recommendation:** When `--colour` or `--color` is followed by one of
the recognised mode words, report an error that suggests the `=` form
(keeping the GNU semantics, but without the silent misrouting), or
accept the space form as for `--use-colour`.

---

## Low

<a id="l1"></a>

### L1. Integer suffixes collide with the duration units

**Fixed in** `ab67099c` (#221), on 2026-10-31, as recommended: the
`signed char`, `unsigned char`, `short`, and `unsigned short` values are
written as casts, for example `(unsigned short)3`; the other suffixes
and `ld` are unchanged. This replaces the `sc` and `uc` suffixes chosen
by #79.

_Confirmed._

**Location:** `src/expression-formatter.cpp:408-427`,
`inlines/expression-formatter-inlines.h:302-339`.

The suffixes of `short` (`s`) and `unsigned short` (`us`) are the same
as the units written for `std::chrono::seconds` and
`std::chrono::microseconds`:

```text
✗ ushort FAILED (3us == 4us)
✗ us FAILED (3us == 4us)
```

The duration units match the standard C++ literals (`3us` is valid
C++), whilst `us` for `unsigned short` is not a C++ suffix; the integer
suffixes are named after the µTest++ literals, which are now deprecated.

**Recommendation:** Write the types that have no standard literal
suffix (`signed char`, `unsigned char`, `short`, `unsigned short`) in a
form that cannot be confused, for example as a functional cast
(`(unsigned short)3`), and keep the standard suffixes (`u`, `l`, `ul`,
`ll`, `ull`, `f`, `l` for `long double`) for the others.

<a id="l2"></a>

### L2. A named check result reports out of order

_Confirmed._

**Location:** `check-result.h:245-254`, `src/check-result.cpp:127-170`.

The copy and move constructors of `check_result` are deleted, but this
does not prevent `auto r = t.expect (...);`, since the initialisation
from a prvalue is guaranteed to be elided. The check is then reported
when `r` goes out of scope, after the checks that follow it, and a
failed `require()` throws at that point instead of at its statement. In
the probe, the check of line 48 was reported after that of line 50.

**Recommendation:** Document that the result must not be named. If a
runtime diagnostic is wanted, `expression_formatter::begin_check()`
already detects a pending owner; a pending owner of the same test case
at the next check is a reliable sign of a named result.

**Fixed in** `e0fcb270` (#222), on 2026-10-31, with a compile-time
prevention instead of the recommendation: the result is a defaulted
temporary argument of `expect()` and `require()`, which return a
reference to it, so `auto r = ...` and `auto& r = ...` do not compile.
`auto&&` remains possible and dangles. Sizes on the Cortex-M33:
`sample-test` -296 bytes (debug) and -56 bytes (release).

<a id="l3"></a>

### L3. The `runner_options` constructor writes to `stderr`

**Location:** `src/runner-options.cpp:318-328`.

`add_error()` writes each error on `stderr` while the constructor parses
the command line, and `runner::initialise()` then writes the same
errors again on the console (and in the output file). A value type
whose constructor has an output side effect cannot be used to parse
silently, for example to inspect or adjust the options before deciding
how to run, or in a unit test of the parser; the TAP output also shows
each error twice (`error: ...` on `stderr`, `Bail out! ...` on
`stdout`).

**Recommendation:** Only record the errors in the constructor, and let
`runner::initialise()` write them on `stderr` together with the console
copy.

**Fixed in** `a5904145` (#223), on 2026-10-31, as recommended:
`add_error()` only records the errors, and `runner::initialise()` writes
them on `stderr` before the console copy.

<a id="l4"></a>

### L4. The extension operators lack the operand normalisation

**Fixed in** `1123a982` (#219) and `6ecbc779` (#224), on 2026-10-31:
the operands are now prepared by `as_operand()` in
`extension::compare_op` and `extension::predicate_op`, so their reports
match those of `eq()`; `as_operand()` is not exported, since it is no
longer needed. The tags remain static, which is now documented, with the
way around it (#224).

**Location:** `detail.h:853-856`, `detail.h:1230-1232`,
`detail.h:1685-1699`, `inlines/detail-inlines.h:1143-1179`.

The built-in comparators pass their operands through
`detail::as_operand()`, which turns the C strings into `c_string`
(compared and printed as strings) and the arrays into `array_operand`
(compared and printed as ranges). The applications that build their own
operators with `extension::compare_op` or `extension::predicate_op`
cannot do the same without naming `detail`, so their reports differ
from those of `eq()` for the same operands (see [M3](#m3)).

The tags are also limited to a static `apply()` and a static `symbol`,
so an application comparator cannot carry a parameter, such as a
tolerance, and report it as `approx()` reports its epsilon.

**Recommendation:** Export `as_operand()` in `extension`, or apply it in
the deduction guides of `compare_op` and `predicate_op`. Document the
static nature of the tags, and the way around it (passing the parameter
as the right operand).

<a id="l5"></a>

### L5. No way to construct a formatter without `detail`

**Location:** `expression-formatter.h:233`.

The only public constructor of `expression_formatter` takes a
`const detail::colours&`, so an application that wants to unit-test its
own `operator<<` for the formatter has to name `detail::colours_none`,
which the guidelines forbid.

**Recommendation:** Add a public default constructor (no colours,
expression mode), or a function such as
`extension::to_string (const T&)`, constrained with
`extension::printable`, that returns the text of a value as the
expressions write it.

**Fixed in** `a5458f6c` (#225), on 2026-10-31, with the first option of
the recommendation: a public default constructor, without colours. The
`to_string()` function was not added.

<a id="l6"></a>

### L6. Public mutators on `counters`

**Location:** `counters.h:190-299`.

The applications receive the counters only as `const counters&`
(`runner::totals()`, `totals()` of the suites and test cases), yet
`operator+=` and the `increment_*()` functions are public, so they are
part of the stable API although only the framework uses them.

**Recommendation:** Consider making them private, with the framework
classes as friends, at the next major release; they would need a
deprecation period first.

**Fixed in** `557d765b` (#226), on 2026-10-31: the mutators are private
now, in 6.0.0, without a deprecation period, since the non-`const`
`totals()` was already removed. The deprecated
`increment_successful_checks()` and `increment_executed_subtests()` were
removed.

<a id="l7"></a>

### L7. Suite names reject `std::string_view` for a reason that does not apply

**Location:** `runner.h:556-562`, `test.h:2086-2119`,
`inlines/test-inlines.h:643-652`.

The documentation of `add_suite()` explains that a `std::string_view`
name is not accepted since it is not guaranteed to be null-terminated,
"as for the test cases". For the test cases this is a real constraint,
since `test_case_name` keeps only a pointer; the suites, however, copy
their name into `owned_name_`, and the private `suite` constructor
already takes a `std::string_view`. The restriction only costs a
`std::string` temporary at the call site.

**Recommendation:** Either accept `std::string_view` for `add_suite()`
and `static_suite`, or state uniformity with the test cases as the
reason, instead of null-termination.

**Fixed in** `bcb876fe` (#227), on 2026-10-31, with the second option of
the recommendation: the comments state the real reasons. A
`std::string_view` was not accepted for the suites only, to keep the
uniformity of #203; an owning test case was prototyped and not adopted,
since it increases the size of every program.

<a id="l8"></a>

### L8. Documentation drift

**Fixed:** `CLAUDE.md` was brought up to date (the first two items
below, and the layout of the tests, the reference outputs, and the
skills), without an issue.

**Withdrawn:** the third item. The `@details` of `extract_file_name()`
and `is_match()` are in the definitions, in `src/utility.cpp`, and
Doxygen merges them with the declarations, so the generated
documentation has them; `@since` is used only for the items new in 6.0.0
or deprecated, and the utility functions, in 3.0.0, are neither.

- `CLAUDE.md` (Repository Layout) does not list `runner-options.h`
  (`runner_options`, `verbosity`, `reporter_kind`, and `colour_mode`)
  and `values.h`, and states that `runner_options`, `verbosity`, and
  `reporter_kind` are in `runner.h`; `colour_mode` is not mentioned in
  the Architecture section.
- `CLAUDE.md` lists only `is_match()` and `split()` in `utility`;
  `extract_file_name()` is also public there, and used by the tests.
- The public functions in `utility.h` (`extract_file_name()`,
  `is_match()`) have no `@details` section and no `@since` tag, unlike
  the rest of the public API, and contrary to the documentation rules in
  `.github/copilot-instructions.md`.

---

## Checked without findings

- The default TAP stream at the `normal` verbosity is well formed: each
  subtest has its test points and a matching plan.
- The sign-mixed integer comparisons use `std::cmp_*`, and `approx()`
  with integers computes the distance without overflow.
- `expression_formatter` handles coexisting check results (nested or
  named) through its pending list, without corrupting the texts.
- The run order of the suites (sorted by name, stable for equal names)
  is deliberate and documented in `runner.h` and `test.h`.
- `--list-tests` not listing nested test cases is documented.
