# C++ API review

Note: the private function `runner::run_suites()` (earlier `run_suites_()`)
was renamed `run_child_suites()`, to free the name for a public function;
this document uses the new name throughout.

Date: 2026-10-15, on branch `xpack-development`, commit `821ca8ab`.

Scope: the C++ source code of the library: the umbrella header
`include/micro-os-plus/micro-test-plus.h`, the public headers in
`include/micro-os-plus/micro-test-plus/`, the inline definitions in
`include/micro-os-plus/micro-test-plus/inlines/`, and the definitions in
`src/`. The Doxygen comments were deliberately ignored; the review judges
the API by its code alone. The history of the project (earlier reports,
commits, and issues) was deliberately not consulted.

Method: the comments were stripped from all 48 source files, and the
remaining 6258 lines of code were read in full. Every public header was
compiled on its own (20 headers, none failed). Suspected defects were
reproduced with probe programs linked with the library sources, compiled
with Apple clang 17.0.0 on x86_64 (`-std=c++20`,
`-DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED`), with AddressSanitizer and
UndefinedBehaviorSanitizer for the lifetime questions, and with
`-fno-exceptions` for the build without exceptions; two probes were
compiled with `arm-none-eabi-g++` 15.2.1 (libstdc++). The sample programs
in `tests/sources/` were read to see the intended use.

Overlap: `maintenance/docs/` contains no other review report, so no item
below overlaps another report.

Summary: 57 problems (1 open, 53 fixed, 3 withdrawn).

The most serious problems are those that make tests behave wrongly or
fail to build:

- the type of `reflection::source_location` depends on the headers
  included before µTest++, so with GCC two translation units disagree
  on it and the link fails (#1);
- the runner keeps the filter patterns as views of the caller's strings,
  which are read after they are freed (#3);
- suites registered while the tests run, or after, are silently never
  run, and the exit code says success (#4);
- an exception thrown in a suite body, or a test case started on the
  suite from inside another test case, ends the whole program (#5, #6);
- without exceptions, one failed `require()` aborts the whole program,
  with no summary (#7);
- the `_b` literal overflows the stack in any check (#8);
- run-time floating-point values without decimals, or smaller than
  `1e-7`, are compared with a tolerance of `0.1` (#9);
- a `char` with the value zero in an operand hides the rest of the test
  case output (#11);
- in quiet mode the TAP console output declares `1..0`, which a TAP
  consumer reads as success even when tests failed (#14).

Suggested order of work: fix the defects in section 1 first, each with a
regression test in `tests/sources/unit/` (#1 to #8 and #14 first, as
they crash, hang, or misreport); then the non-breaking clean-ups (#27,
#36 to #43, #45, #55, #57, and section 6); then decide on the breaking changes in
sections 2 and 3 (#20 to #24 with #54, #30, #31, and #32), best grouped
in one major release.

Tags: **[breaking]** marks a suggested change that alters the public API
so that existing user code may need changes; **[internal]** marks a
change that does not affect existing user code (including purely
additive changes); **[confirmed]** marks a problem reproduced by a probe;
the others are derived from reading the code.

## 1. Defects

- **#1 — The type of `source_location` depends on the include order.**
  [internal] **[confirmed]** (fixed)
  Fixed in `a8733dc2` (#96): `reflection.h` includes `<version>` before the test, and
  `runner::abort()` no longer assumes that `line()` returns
  `unsigned int`; regression test in
  `tests/sources/unit/src/static-asserts.cpp`.
  `reflection.h` lines 65 to 69 and 107 to 122,
  `inlines/reflection-inlines.h` lines 81 to 122: the header tests
  `__cpp_lib_source_location` before including any header that defines
  it. The macro is defined only by `<version>` and `<source_location>`,
  so the result depends on what the user included earlier. With
  `arm-none-eabi-g++` (libstdc++), a translation unit that includes
  only µTest++ gets the custom class, while one that includes
  `<version>` first gets `std::source_location`. A probe that includes
  `<version>` before `micro-test-plus.h` and calls `tr.abort ()`
  references `runner::abort(std::source_location const&)`, while
  `src/runner.cpp` defines
  `runner::abort(reflection::source_location const&)`: the link fails.
  The inline classes that hold a location (`test_name`, `check_result`,
  `failure_info`) also differ between translation units, which is an
  ODR violation even when the link succeeds. Include `<version>` before
  the test (or test `__has_include(<source_location>)`), so that the
  choice depends only on the toolchain.

- **#2 — `runner::verbosity()` dereferences a null pointer before
  `initialise()`.** [internal] **[confirmed]** (fixed)
  Fixed in `9de58bfd` (#97): the runner keeps the verbosity, set by
  `initialise()` from the options and `verbosity::normal` before it; the
  reporter keeps a constant copy, and `reporter::verbosity()` was
  removed; regression test in `tests/sources/unit/src/miscellaneous.cpp`.
  `inlines/runner-inlines.h` lines 78 to 82: the reporter is created by
  `initialise()` (`src/runner.cpp` lines 235 to 242), but
  `verbosity()` is public and `noexcept` and reads `reporter_->`
  unconditionally. A probe calling it before `initialise()` stops with
  "member call on null pointer" and a SEGV. Keep the verbosity in the
  runner (set by `initialise()`, with a default), or return
  `verbosity::normal` while no reporter exists.

- **#3 — The filter patterns are kept as views of the caller's
  strings.** [internal] **[confirmed]** (fixed)
  Fixed in `552ae9eb` (#98): the runner keeps the patterns as
  `std::string`, copied by `initialise()`, so the caller's strings need
  only remain valid until it returns, as for the other options;
  regression test in `tests/sources/unit/src/miscellaneous.cpp`.
  `runner.h` line 652, `src/runner.cpp` lines 253 to 257,
  `runner-options.h` line 224: `initialise (const runner_options&)`
  copies `std::string_view` objects, and `is_selected_()` reads them
  later, during `run()`. A probe that fills `filter_patterns` from a
  local `std::string` destroyed after `initialise()` ends with
  "heap-use-after-free" in `runner::is_selected_()`. The command-line
  path is safe only because `argv` lives until the end of the program.
  Store the patterns as `std::string` in the runner.

- **#4 — Suites registered during or after `run()` are silently never
  run.** [internal] **[confirmed]** (fixed)
  Fixed in `2ddf8780` (#99): `run()` moves the session to a new
  `running` state, and `register_suite_()` rejects a suite added while
  the session runs or after it ended: the error is reported on
  `stderr`, the suite is discarded, so it is not counted either, and
  the exit code is 1 (unless an option error requires 2), also for the
  later calls of `run()`; a call of `run()` from a suite body is
  rejected too; regression test in
  `tests/sources/unit/src/miscellaneous.cpp`.
  `inlines/runner-inlines.h` lines 104 to 119, `src/runner.cpp` lines
  433 to 441, 475, and 559 to 563: `run_child_suites()` takes the number of
  suites once (line 475), and `runner::suite()` accepts registrations in
  any state. In a probe, a suite registered from inside another suite's
  body, and one registered after `run()`, both containing a failing
  check, never ran; the summary counted three suites, only two ran, and
  the exit code was 0. Either reject a registration after `run()` has
  started (report it as a failure, so that the exit code is not 0), or
  keep running suites until no new ones remain.

- **#5 — An exception thrown in a suite body ends the program.**
  [internal] **[confirmed]** (fixed)
  Fixed in `d7cf21a1` (#100): `suite::run()` catches the exceptions, as
  `test_case::run()` does, and reports them as a failed check of the
  suite, numbered after the test cases already run (the TAP plan of the
  suite counts it), without a source location, via the new
  `reporter::fail_suite()`; the run continues with the next suite; a
  body declared `noexcept` still terminates the program; regression
  tests in `tests/sources/unit/src/exceptions.cpp`.
  `src/test.cpp` lines 337 to 355: `test_case::run()` catches
  everything, but `suite::run()` has no `try` block, so an exception
  thrown by the suite body outside a test case (for example by a set-up
  step) leaves `runner::run()` and calls `std::terminate()`. In a probe
  the program ended with "terminating due to uncaught exception", with
  no summary and none of the following suites run. Catch the exceptions
  in `suite::run()` as `test_case::run()` does, and count them as a
  failure of the suite.

- **#6 — A test case started on the suite from inside another test case
  aborts the program.** [internal] **[confirmed]** (fixed)
  Fixed in `6f7509a3` (#101): the runner keeps the innermost running
  test case (restored by a guard, also when an exception leaves
  `test_case::run()`), and `suite::test()`, called while a test case
  runs, forwards the call to it, so the new test case runs nested in it,
  as if started with `test_case::test()`; before any check, the report
  was also malformed (the test case was numbered as a sibling inside
  the outer one), which is fixed too; regression test in
  `tests/sources/unit/src/miscellaneous.cpp`.
  `src/reporter-human.cpp` lines 427 to 444 and 752 to 769,
  `src/reporter-tap.cpp` lines 422 to 436 and 729 to 743: when a test
  case begins and the reporter's buffer is not empty, both reporters
  accept it only at a nesting depth above 1; otherwise they print
  "Buffer not empty at the beginning of a test case" and call
  `abort()`. A user who captures the suite and calls `ts.test (...)`
  inside a test case, after a check, gets a depth of 1 and the whole
  program aborts. A library-internal invariant should not be enforced
  by terminating a user program. Either treat the call as a nested test
  case (commit the buffer, as for depth above 1), or report it as a
  failure of the outer test case and continue.

- **#7 — Without exceptions, one failed `require()` aborts the whole
  program.** [breaking] **[confirmed]** (fixed)
  Fixed in `2d89d03e` (#102): the abort is the intended behaviour,
  since without exceptions the test case cannot be stopped alone, so it
  is kept, and neither (a) nor (b) below was implemented; what was
  wrong was the report written before the abort, which the new
  `reporter::abort_test_case()` hook, called in place of the
  `end_test_case()` that is never reached, now completes. The human
  reporter displays the names of the open test cases not yet
  displayed (the failure previously appeared under the previous test
  case), then the buffered results; the TAP reporter adds a
  `Bail out! Requirement failed at <file>:<line>` line; both write the
  results to the output file too (it previously ended before them),
  display them also with quiet verbosity, since the totals are never
  reached, and no longer display them with silent verbosity. No
  regression test, since no test configuration is built without
  exceptions; verified with `-fno-exceptions` probes, for both
  reporters, all verbosity levels, the output file, and a nested test
  case. The placement of the `aborted...` marker in the TAP YAML block,
  found meanwhile, is a separate item (#49).
  `src/check-result.cpp` lines 158 to 170, `src/runner.cpp` lines 628
  to 647: with exceptions, a failed requirement stops only its test
  case; without, it calls `runner::abort()`, which ends in `::abort()`.
  A probe built with `-fno-exceptions` stopped with SIGABRT after the
  first failure: the following test cases did not run, no summary was
  printed, and the human reporter did not even print the name of the
  failing test case. The same source therefore behaves very differently
  on the targets most likely to disable exceptions. Possible changes:
  (a) give `check_result` an explicit `operator bool` and, without
  exceptions, let a failed requirement only mark the test case as
  failed, so that users write `if (!t.require (...)) return;`;
  (b) keep the abort, but name it (for example `require_or_abort()`),
  so that the cost is visible at the call site. The decision is the
  maintainer's.

- **#8 — The `_b` literal overflows the stack in any check.**
  [internal] **[confirmed]** (fixed)
  Fixed in `f6fa0d4f` (#103): the literal returns the new
  `detail::named_bool`, with an implicit conversion to `bool` (always
  `true`) and a `name()` accessor, but without `get()` or comparison
  operators, so that the comparators compare it as `true`, the generic
  operators are selected for it, and a new formatter overload prints its
  name (`"flag"_b == flag` fails as `flag == false`); it no longer
  derives from `std::string_view`, so two named literals still compare
  as equal, not by name; regression test in
  `tests/sources/unit/src/operators.cpp`.
  `inlines/literals-inlines.h` lines 523 to 592,
  `inlines/expression-formatter-inlines.h` lines 188 to 195: the local
  type `named` derives from `detail::op`, so the formatter selects the
  `is_op` overload, which calls `unwrap()`; `named` has no `get()`, so
  `unwrap()` returns the object itself, and the overload calls itself
  until the stack overflows. Both `t.expect ("flag"_b)` and
  `t.expect (mt::eq ("flag"_b, true))` crashed with exit status 139
  (AddressSanitizer: stack-overflow at line 193). The unit tests use
  `_b` only in `static_assert` (`tests/sources/unit/src/static-asserts.cpp`
  lines 135 to 137), so this was never exercised. Also, `named ==
  bool` returns the `bool` itself, so the name never appears in any
  output. Either give `named` a formatter overload that prints the name
  and a `get()`, or remove `_b`.

- **#9 — Small or whole run-time floating-point values get a tolerance
  of 0.1.** [internal] **[confirmed]** (fixed)
  Fixed in `3739ef5b` (#104): `math::den_size()` counts the leading
  zeros of a value below one as decimals (the distance is measured to
  the nearest non-zero integer), so `to_d{1e-12}` has an epsilon of
  `1e-12`; a zero has no decimals, and the new `math::decimal_epsilon()`
  gives it a zero epsilon, which compares exactly; whole values keep
  one decimal (`0.1`), as the literal `42.0_d`; regression tests in
  `tests/sources/unit/src/main.cpp` and
  `tests/sources/unit/src/static-asserts.cpp`.
  `values.h` lines 409 to 415, `inlines/math-inlines.h` lines 323 to
  356: the tolerance of `to_f`, `to_d`, and `to_ld` is `10^-n`, where
  `n` is the number of decimals counted by `den_size()`, which stops as
  soon as the fractional part is within the absolute value `1e-7`.
  Every value below `1e-7`, and every whole number, therefore counts as
  one decimal: in a probe, `to_d{1e-12}`, `to_d{1e-9}`, and `to_d{0.0}`
  all had an epsilon of `0.1`; `eq (to_d{1e-12}, 0.05)` and
  `eq (to_d{0.0}, 0.09)` passed, and `lt (to_d{0.0}, 0.09)` failed.
  Scale the precision to the magnitude of the value (or bound the
  epsilon by a fraction of `|value|` when the value is not zero), and
  add tests with values below `1e-7`. Also note that a tolerance of one
  full unit of the last decimal makes `1.0_d` equal to every value in
  `(0.9, 1.1)` (`eq (1.0_d, 1.09)` passed); half a unit would match the
  notation, but changes existing results.

- **#10 — The `has_value` and `has_epsilon` concepts match user
  types.** [internal] **[confirmed]** (fixed)
  Fixed in `0ba39b82` (#105): both concepts require `is_op<T>`, so they
  match only the framework constants and floating-point wrappers, and
  the application types with members named `value` or `epsilon` are
  compared with their own operators; regression tests in
  `tests/sources/unit/src/main.cpp` and
  `tests/sources/unit/src/static-asserts.cpp`.
  `type-traits.h` lines 159 to 174, `inlines/detail-inlines.h` lines
  194 to 230 and 360 to 372: `compare_op` treats any type with a member
  named `value` as a compile-time constant (it reads `Lhs_T::value`),
  and any type with a member named `epsilon` as a floating-point
  wrapper. `eq (sample{ 1 }, sample{ 2 })`, for a plain aggregate with
  a data member `value` and a defaulted `operator==`, does not compile
  ("invalid use of non-static data member 'value'", in
  `detail-inlines.h` line 363). Constrain both concepts to the
  framework's own types (`is_op<T> and ...`).

- **#11 — A zero `char` hides the rest of the output.**
  [internal] **[confirmed]** (fixed)
  Fixed in `977e9755` (#106): the console buffer is written with
  `fwrite()`, and the messages are streamed as strings, so a zero no
  longer ends the output; the `char` values are written as quoted,
  escaped literals (`'a'`, `' '`, `'\0'`, `'\x1b'`), and the formatter's
  own separators as strings; regression tests in
  `tests/sources/unit/src/main.cpp` and
  `tests/sources/unit/src/miscellaneous.cpp`.
  `src/expression-formatter.cpp` lines 77 to 82,
  `inlines/check-result-inlines.h` lines 153 to 156, `src/reporter.cpp`
  lines 173 to 177, `src/reporter-human.cpp` lines 640 and 693: a
  `char` is appended raw, and the buffer is written with `fputs()` and
  the message with `c_str()`, both of which stop at the first zero.
  In a probe, `eq ('\0', 'a')` printed "FAILED (p11.cpp:44, " and
  nothing else: the end of that line and the whole next failed check
  were lost, although both were counted. A zero in a message cut the
  message. Write the buffers with their sizes, and print characters as
  quoted, escaped literals (`'\0'`, `'a'`), which also makes `' '` and
  control characters visible.

- **#12 — `long double` values are printed with six digits.**
  [internal] **[confirmed]** (fixed)
  Fixed in `257d4962` (#107): where `long double` is wider than
  `double`, the value is printed with `"%.*Lg"`, with the smallest
  precision, from `LDBL_DIG` (1 for zero and the subnormal values) up
  to `LDBL_DECIMAL_DIG`, that reads back with `strtold()` as the same
  value, which gives the shortest exact form; `errno` is preserved;
  where no precision reads back exactly, because the C library handles
  `long double` with the precision of `double` (newlib on AArch64, where
  `0.1000001L` was printed as `0.100000099999999994548893766932451399`),
  the value is cast to `double` and printed with `std::to_chars`;
  regression tests in `tests/sources/unit/src/miscellaneous.cpp`, and
  the `to_ld` tests in `tests/sources/unit/src/comparisons.cpp` now
  use a `long double` literal, whose text is the same on all the
  platforms.
  `inlines/detail-inlines.h` lines 572 to 597: where `long double` is
  wider than `double`, the value is printed with `"%Lg"`, which gives
  six significant digits, while `float` and `double` use the shortest
  exact form. On x86_64, `eq (0.1L, 0.1000001L)` failed with the
  message "0.1ld == 0.1ld". Use `"%.*Lg"` with `LDBL_DECIMAL_DIG` (or
  `std::to_chars` where the library supports `long double`).

- **#13 — Negating a narrow typed literal changes its type.**
  [breaking] **[confirmed]** (fixed)
  Fixed in `5167fe2e` (#108): `integral_constant<N>::operator-`
  converts the result back to `decltype (N)`; the negation of an unsigned literal wraps around
  for all the widths (`-1_u8` is the `std::uint8_t` value 255, as `-1_u`
  is `UINT_MAX`), and the negation of the minimum of a signed type is
  rejected with a `static_assert`; `math::integer()` was replaced by
  `math::integer_magnitude()`, which accepts, for the signed types, the
  magnitude `max () + 1`, returned by the new
  `detail::integral_literal()` as a `detail::integral_min_magnitude<T>`,
  whose only operation is the negation, so `-128_i8` compiles and
  `128_i8` alone does not; regression tests in
  `tests/sources/unit/src/static-asserts.cpp`.
  `inlines/values-inlines.h` lines 120 to 125,
  `inlines/math-inlines.h` lines 460 to 478:
  `integral_constant<N>::operator-` returns `integral_constant<-N>`,
  and `-N` is promoted to `int` for every type narrower than `int`. In
  a probe, `-1_i8` and `-1_s` were `int`, and `-1_u8` was the `int`
  value `-1`, not the `std::uint8_t` value 255, while `-1_u` wraps to
  `UINT_MAX` as in C++. The most negative values (`-128_i8`,
  `-2147483648_i`) do not compile, because the magnitude is checked
  against the maximum before the sign is applied. Convert back to
  `decltype (N)`, reject the negation of unsigned literals with a clear
  `static_assert` (or define it as wrapping, consistently), and allow
  the magnitude `max () + 1` when it is negated.

- **#14 — In quiet mode, the TAP console output declares `1..0`.**
  [internal] **[confirmed]** (fixed)
  Fixed in `2b83ff31` (#109): with `--quiet`, the console receives one
  `ok`/`not ok` line per suite (and the `# SKIP filtered` lines of the
  skipped suites), followed by the real plan and the totals; checked
  with the node-tap parser (`tap-parser` 18, strict mode), which now
  reads a run with failed suites as failed; regression test on the
  console output of `sample-test-quiet` in
  `tests/platforms/synthetic-posix/cmake/artefacts.cmake`.
  `src/reporter-tap.cpp` lines 201 to 210: with `--quiet`, the console
  receives "TAP version 14", "1..0", and the totals comment. In TAP,
  `1..0` means that all tests were skipped, so a consumer reads a run
  with failures as successful (only the exit code says otherwise).
  Print the top-level test points (one line per suite, `ok` or
  `not ok`) with the real plan, which is still short, or print no plan
  and no TAP header at all.

- **#15 — The human report file depends on the console verbosity.**
  [internal] **[confirmed]** (fixed)
  Documented in `b5c7a6a6` (#110); the code is unchanged, by decision: the
  output file is intended for the integration with other tools, and the
  TAP reporter, which writes it completely at every verbosity, is the
  one to use for it, while the human reporter is intended for the
  console. The user guide (new "Output file" section), the FAQ,
  `runner-options.h`, and `reporter-human.h` now state that the human
  report file is complete only with normal or verbose verbosity.
  `src/reporter-human.cpp` lines 167 to 222, 242 to 256, 288 to 361,
  451, and 497 to 594: most writes to the output file are inside the
  verbosity conditions, but the test case names are written always. In
  a probe with `--quiet --output-file`, the file contained only the
  test case names and the totals; with `--silent`, only the names, not
  even the totals. The TAP reporter writes the same complete file at
  every verbosity, so the two reporters disagree. Write the file
  independently of the console verbosity, as the TAP reporter does.

- **#16 — Names and messages are not escaped in the TAP output.**
  [internal] **[confirmed]** (fixed)
  Fixed in `850957df` (#111): in the `ok`/`not ok` lines, the names of
  the suites and test cases, the messages, the expressions of the
  passed checks, and the `Bail out!` reason are written with each `\`
  as `\\` and each `#` as `\#`, as the TAP 14 specification recommends,
  and with the line breaks (`\n`, `\r`, and `\r\n`) replaced by spaces;
  the `# Subtest:` comments keep the names as they are, with only the
  line breaks replaced, since the specification defines no escapes in
  comments and the node-tap parser uses their text as it is; checked
  with the node-tap parser (`tap-parser` 18, strict mode), which reads
  a failed test case named "TAP escapes # TODO in names \ messages" as
  failed, not as TODO, and reports the names unescaped; regression test
  in `tests/sources/unit/src/miscellaneous.cpp`, with the updated
  reference outputs. The `condition:` values are unchanged (#51).
  `src/reporter-tap.cpp` lines 440, 531 to 533, 619 to 624, and 660 to
  665: names and messages are written as they are. A test case named
  "parser # TODO rework" produced
  `not ok 1 - parser # TODO rework # { FAILED, ... }`, which a TAP 14
  consumer reads as a TODO directive, so the failure is not counted; a
  message with a newline broke the test point line. Escape `#` and `\`
  in descriptions, and replace or indent line breaks.

- **#17 — The comparison operators lose the operands of standard
  types.** [breaking] **[confirmed]** (fixed)
  Fixed in `75e921f8` (#112): the `std::string_view` overloads were
  removed from `operators`, so the operators are selected only when an
  operand is a framework literal or wrapper, and the standard operators
  compare all the strings, also in the user code that follows the using
  directive; the documentation recommends `eq()` and `ne()` for strings
  and states that the other forms return a plain `bool`; static
  assertions in `tests/sources/unit/src/static-asserts.cpp`, the sample
  test case "Check strings with operators" removed, and the reference
  outputs updated.
  `operators.h` lines 140 to 161, `inlines/operators-inlines.h` lines
  76 to 107: the generic operators require one framework operand, and
  the `std::string_view` overloads are outranked by the standard ones
  whenever an operand is a `std::string`. With `using namespace
  operators`, `t.expect (s1 == s2)` and `t.expect (s1 == "abd")` (with
  `std::string s1`) evaluate to `bool`, and the failure message has no
  operands, while `eq (s1, s2)` prints "abc == abd". Conversely, two
  `std::string_view` operands select the framework's non-template
  overload, so after the using directive every `sv1 == sv2` in the
  user's code returns a `compare_op`. Either remove the string
  overloads from `operators` and recommend `eq()` for strings, or add
  overloads that take `const std::string&`, and document which forms
  print their operands.

- **#18 — Common types cannot be used in comparisons.**
  [internal] **[confirmed]** (fixed)
  Fixed in `287a15d9` (#113): the formatter writes the scoped
  enumerations, including `std::byte`, by their underlying value, with
  the suffix of its type (`0`, `1uc`), the pairs and the tuples as
  `(a, b)`, so the maps as `{(1, 2), (3, 4)}`, and the optionals by
  their value, or as `nullopt` (also `std::nullopt` itself); an
  `operator<<` of the application for an enumeration is still
  preferred. By decision, no fallback was added for the types that
  cannot be written: it would compete with the conversions to
  `std::string_view` and to the arithmetic types, and would hide a
  missing `operator<<`, so a user-defined type still needs one.
  Regression tests in `tests/sources/unit/src/miscellaneous.cpp` (a
  vector of pairs stands for the map, whose constructor, inlined by
  `arm-none-eabi-g++` at `-Os`, triggers `-Waggregate-return` in
  libstdc++), with the updated reference outputs.
  `expression-formatter.h` lines 233 to 555,
  `inlines/expression-formatter-inlines.h` lines 203 to 217: the
  formatter has no overload for scoped enumerations, `std::byte`,
  `std::pair` (so no map), `std::tuple`, or `std::optional`, so
  `eq (colour::red, colour::green)`, `eq (std::byte{ 1 },
  std::byte{ 2 })`, and `eq (map1, map2)` do not compile, with the error
  deep inside the formatter. Scoped enumerations are common in
  embedded code. Print scoped enumerations and `std::byte` by their
  underlying value, pairs and tuples as `(a, b)`, and consider a
  fallback for types that cannot be printed (for example `{?}`), so
  that a comparison always compiles.

- **#19 — "Test output written" is printed in silent mode.**
  [internal] **[confirmed]** (fixed)
  Fixed in `a309b387` (#114): the reporter destructor writes the
  confirmation message only when the verbosity is not `silent`, so
  `--silent` writes nothing to the console, as documented; the example
  output in the developer documentation updated. No regression test was
  added, since the console output is not compared with reference files.
  `src/reporter.cpp` lines 126 to 136: the reporter destructor always
  prints the message to the console. With `--silent --output-file`, it
  was the only line printed. Respect the verbosity.

- **#49 — The `aborted...` marker breaks the TAP YAML block.**
  [internal] **[confirmed]** (fixed)
  Fixed in `e7421411` (#144): the TAP reporter no longer adds a
  marker; a failed requirement is reported like any other failed check,
  as node-tap reports a failed assertion followed by a throw (its YAML
  block has no field for the stop). With exceptions, the stop is shown
  by the plan of the test case, which follows; without, by the
  `Bail out!` line added by #7. The human reporter now names the
  effect, ` - test case stopped`, or, without exceptions,
  ` - test execution aborted`. The reference outputs and the user
  documentation updated; the `tests/assets/tap/unit-test.tap` blocks
  of the four failed requirements, previously parsed by `tap-parser`
  21.8.0 as having no diagnostics, now give their `at:` fields.
  Verified for both builds with `-fno-exceptions` probes, with and
  without an expression, for both reporters.
  `src/reporter-tap.cpp` lines 692 to 699 and 709 to 718,
  `src/reporter-human.cpp` lines 740 to 750: for a failed requirement,
  both reporters append " aborted..." right after the failure. In TAP,
  this text lands inside the YAML diagnostics block: without an
  expression (for example `t.require (false)`), the block opens with
  `--- aborted...`, while TAP 14 starts it with a line holding only
  `---`, so a consumer does not recognise the block, and reads the
  `at:` fields and the closing `...` as unexpected lines; with an
  expression, the marker becomes part of the `condition:` value
  (`condition: 0 > 0 aborted...`). The reference outputs contain the
  broken form (`tests/assets/tap/unit-test.tap` lines 969, 978, 988,
  and 1000). In both reporters, the word is also misleading when
  exceptions are enabled, since only the test case is stopped and the
  run continues (`tests/assets/txt/unit-test.txt` lines 525, 528, 532,
  and 537); it is accurate only without exceptions, where the test
  execution is aborted (#7). In TAP, report the kind outside the
  scalar values, for example as a separate YAML field; in both
  reporters, name the effect that actually follows (the test case is
  stopped, or the test execution is aborted), and update the
  reference outputs.

- **#51 — The `condition:` values are not valid YAML.**
  [internal] **[confirmed]** (fixed)
  Fixed in `a3445ab3` (#147): the expression is written as a YAML
  double-quoted scalar, with each `\` as `\\`, each `"` as `\"`, and
  the control characters as YAML escapes (`\0`, `\t`, `\n`, `\e`,
  `\xHH`, and so on), whatever the operands; checked with the node-tap
  parser (`tap-parser` 18, strict mode), which now reads all the 336
  `condition:` values of `tests/assets/tap/unit-test.tap`, with no
  non-TAP data, and returns them unchanged (before the fix, 16 failed
  test points had no diagnostics); regression test in
  `tests/sources/unit/src/miscellaneous.cpp` (string operands with
  `: `, ` #`, `"`, `\`, a line break, and a tab), with the updated
  reference outputs; the user guide, the FAQ, and the compatibility
  notices updated. The `filename:` values of the `at:` field are still
  plain scalars.
  `src/reporter-tap.cpp` lines 698 to 704: the expression is written
  after `condition: ` as a plain YAML scalar, without quotes or
  escapes. Parsed with the node-tap parser (`tap-parser` 18, which uses
  the `yaml` package), 15 of the 332 `condition:` values in
  `tests/assets/tap/unit-test.tap` are rejected: the container
  operands (`{1, 2} != {1, 2}`, `{} != {}`, `{ 1, 2 } == { 1, 3 }`,
  lines 2813 to 2917) start a YAML flow mapping, and the character
  operands (`'\0' == 'a'`, `' ' == '\t'`, lines 134 and 141) start a
  single-quoted scalar followed by more text. The whole diagnostics
  block is then passed on as unparsed text, and the failed test point
  has no diagnostics at all, neither the condition nor the location
  (in strict mode, the block is also reported as non-TAP data). The
  string operands are also written
  unquoted (`abc == abx`, line 690), so a string that contains `: `
  makes the value invalid, and one that contains ` #` is silently
  truncated at the YAML comment (by the YAML rules; no test string
  contains them). Write the value as a YAML double-quoted scalar,
  escaping `\`, `"`, and the control characters, whatever the
  operands; fix it together with #16, which escapes the descriptions,
  and update the reference outputs.

- **#52 — The TAP location fields are not those of node-tap.**
  [internal] **[confirmed]** (fixed)
  Fixed in `620cfbcd` (#146): the `at:` field is written with
  `fileName:` and `lineNumber:`; verified with node-tap 21.8.0, whose
  JUnit report of a probe now gives the failed `<testcase>` the
  `file="probe.cpp" line="9"` attributes (none before), and with
  `tap-parser` 18.3.4, which reads both fields from all the 355 and
  344 location blocks of the reference outputs. No column was added.
  The reference outputs, the user guide examples, and the
  compatibility notices updated; `tests/scripts/compare-files.sh`
  (generated from the build-helper template, updated separately)
  normalises both `line:` and `lineNumber:`, so the other projects
  are not affected. No regression test was added, since the existing
  reference outputs cover the format.
  `src/reporter-tap.cpp` lines 921 to 924: the location of a failed
  check is written in the YAML diagnostics block as `at:` with the
  fields `filename:` and `line:`. TAP 14 does not standardise the
  diagnostics fields, so the block is valid TAP, but the names do not
  match those of node-tap, the most common TAP consumer, which writes
  `at:` with `fileName:`, `lineNumber:`, and `columnNumber:`, and whose
  reporters (`@tapjs/reporter` 21.8.0) read `at.fileName` (with
  `at.file` and `file` as fallbacks, but not `filename`), and
  `at.lineNumber` (with `at.line` and `line` as fallbacks). The location
  written by µTest++ is therefore lost: with the output of a probe
  passed through `tap --reporter=junit`, the `<testcase>` of the failed
  check has no `file` and `line` attributes, which the CI systems use to
  annotate the failure; with `fileName:` and `lineNumber:`, it has
  `file="probe.cpp" line="9"`. The default terminal reporter displays
  the file name only from `at.fileName`, and the line only when
  `columnNumber` is also present, which `reflection::source_location`
  does not provide. There is no TAP parser in µTest++, so no other
  consumer depends on the current names. Rename the fields to
  `fileName:` and `lineNumber:`, update the reference outputs
  (`tests/assets/tap/unit-test.tap` has 353 location blocks,
  `unit-test-noexcept.tap` 342) and the examples in the user guide
  (`website/docs/user/_project/_content.mdx` lines 175, 237, 248,
  255, 376, and 981), and add a compatibility notice; a column would require extending
  `reflection::source_location`, and is not needed by the other
  reporters.

- **#56 — The wide character types are reported as numbers.**
  [internal] **[confirmed]** (fixed)
  Fixed in `70660a6c` (#151): the formatter has overloads for the four
  types, which write the values as quoted literals with their prefix,
  through the `append_character()` helper shared with `char`; the
  values that are not characters by themselves are written with `\x`
  and all the hexadecimal digits of their type, and the messages write
  them as the expressions do, as proposed below.
  `expression-formatter.h` lines 340 to 421, `src/expression-formatter.cpp`
  lines 238 to 359, `inlines/check-result-inlines.h` lines 161 to 164:
  the formatter has overloads for `char` and for the integer types, but
  none for `char8_t`, `char16_t`, `char32_t`, and `wchar_t`, which are
  therefore promoted to `int` or `unsigned int`. In a probe (on
  2026-10-20, at `8fa29e9b`), `eq (u'x', u'y')` was reported as
  `120 == 121`, `eq (U'x', U'y')` as `120u == 121u`, and the `L'x'` and
  `u8'x'` comparisons as `120 == 121`; in a message, `u'x'` and `U'x'`
  were both written as `120`. Report them as character literals with
  their prefix (`u8'x'`, `u'x'`, `U'x'`, `L'x'`), with the escapes of
  `char` (#11) for the control characters, `\x` for the `char8_t` values
  above `0x7F` (UTF-8 code units) and for the `char16_t` surrogates, and
  `\u` or `\U` for the other values outside ASCII. Since #36 was fixed,
  the messages are written by the same formatter, in its plain mode;
  there, write these values as in the expressions too, since they
  cannot be appended unchanged, as `char` is, without converting them
  to UTF-8.

## 2. Structure and layering

- **#20 — The internal protocol of the test classes is public.**
  [breaking] **[confirmed]** (fixed)
  Fixed in `b200ea72` (#115): `run()` and `abort()` are private, renamed
  `run_()` and `abort_()`, as the other non-public functions; the
  overrides in `suite` and `test_case` are private too, with the runner
  (for the suites) and `runnable_base` (for the test cases) as friends.
  `own_index()`, `test_point_number()`, and `child_test_cases_count()`
  were removed rather than made private, since a private getter could
  not follow the naming convention without clashing with its data
  member; the TAP reporter, now a friend of `runnable_base` with the
  human reporter, reads the data members directly, as both already did
  for the suite stopwatch. The top suite setter and its `using`
  declaration were removed; the runner, a friend, sets the name
  directly. `nesting_depth()` stays public, as it was not part of the
  item. The unit test that read `child_test_cases_count()` now reads
  `totals().executed_test_cases()`; no regression test was added, since
  the calls are now compilation errors. Compatibility notices updated.
  `test.h` lines 289 to 370, 1104 to 1105,
  `inlines/test-inlines.h` lines 479 to 483: `run()`, `abort()`,
  `own_index()`, `test_point_number()`, and `child_test_cases_count()`
  are public members of `runnable_base`, and so of `suite`,
  `top_suite`, and `test_case`, but they exist for the runner and the
  reporters (none is used by the sample programs). A probe that called
  `ts.run ()` twice on the top suite printed three result lines for it.
  `top_suite::name (const char*)` is public but unreachable (since
  `initialise()` returns `suite&`), keeps a non-owning pointer, and
  forces the `using` declaration at line 1048. Make these members
  private, with the runner and the reporters as friends, and remove the
  setter.

- **#21 — The test name parameter is a `detail` type that accepts only
  C strings.** [breaking] **[confirmed]** (fixed)
  Fixed in `c51d8477` (#116): the type is public, renamed
  `test_case_name`, with a second implicit constructor from
  `const std::string&`; the name is still not copied, so a temporary
  string is valid while the test case runs. A `std::string_view` is not
  accepted, since it may not be null-terminated. Helpers that add test
  cases can take a `const test_case_name&` parameter, so that the
  reported location is that of their caller. The name parameter of
  `runner::suite()` and of the `suite` constructor is a
  `std::string_view`, since the name is copied. The change is additive,
  not breaking, since `detail::test_name` was new in the unreleased
  v5.1. The other `detail` return types (`approx()`, `expect()`, the
  `to_i` family) stay in `detail`, since users do not need to name
  them. Unit test, user guide, and compatibility notices updated.
  `test.h` lines 130 to 178, 666 to 669, and 956 to 959: `test()` takes
  `const detail::test_name&`, which is constructed only from
  `const char*`, so `ts.test (name, ...)` with a `std::string` does not
  compile. Since test cases run immediately, a `std::string` argument
  is safe. Other `detail` types in public signatures: `approx()`
  returns `detail::value<T>` (`literals.h` lines 797 to 801), the
  `to_i` family are aliases of `detail::value<>` (`literals.h` lines
  484 to 726), and `expect()` returns `detail::check_result`. Move
  `test_name` to the public namespace, with a constructor from
  `const std::string&` (and the same for `runner::suite()`).

- **#22 — The expression formatter exposes its internal protocol.**
  [breaking] (fixed)
  Fixed in `b43b0fcd` (#117): apart from the constructor, the public
  members are the `operator<<` overloads and `str()`, which returns a
  const reference, so it cannot alter the texts, and is needed to test
  an `operator<<` with a stand-alone formatter, as the unit tests do.
  `begin_check()`, `check_text()`, and `end_check()` are private, with
  `check_result`, their only caller, as a friend; the reporters need no
  friendship, since they do not call the formatter. `c_str()`,
  `clear()`, `empty()`, `append()`, and `reserve()` were removed rather
  than made private, since the library did not use them; the unit tests
  that called `clear()` between values now compare the text written
  since the previous value. The `protected` section became `private`
  too, which settles the formatter part of #30. No regression test was
  added, since the calls are now compilation errors. Compatibility
  notices updated.
  `expression-formatter.h` lines 569 to 664 and 780: the class is
  aliased into the public namespace, so that users can write
  `operator<<` for their own types, but its public members also include
  `begin_check()`, `end_check()`, `check_text()`, `clear()`,
  `append()`, `reserve()`, `str()`, and `c_str()`, which a user's
  operator can call and so corrupt the pending check texts. Keep only
  the stream operators public, and make the protocol private, with
  `check_result` and the reporters as friends.

- **#23 — The `type_traits` namespace mixes the implementation with the
  names meant for the applications.** [breaking] (fixed)
  Fixed in `0ee0278b` (#118): the namespace is now `extension`, and the
  header `extension.h`; `is_op`, `any_op`, `has_epsilon`, `checkable`,
  and `printable` stay public, documented for the custom comparators,
  operators, and helpers, and `has_value`, `container_like`, and
  `has_npos` moved to `detail`. The static asserts check the new
  locations; no other regression test was added, since the old names
  are now compilation errors. Compatibility notices updated.
  `type-traits.h` lines 111 to 263: the namespace holds seven concepts
  (no traits; the last ones were removed earlier, see the compatibility
  notices) and is public, but no user page documents any of them; the
  only uses outside the library headers are the checks in
  `tests/sources/unit/src/static-asserts.cpp` lines 77 to 120. The
  namespace is meant for the applications that write their own
  comparators, operators, and helpers (#54), and only some of the
  concepts serve them:
  - `is_op` tells whether an operand is a framework expression or
    wrapper, which a custom comparator or operator must know;
  - `any_op` limits a custom operator to the operands of which at least
    one is a framework type, as `operators.h` lines 138 to 264 do, so
    that it does not compete with other operators;
  - `has_epsilon` lets a custom comparator honour the tolerance of the
    floating-point wrappers, as `compare_op` does
    (`inlines/detail-inlines.h` lines 198 to 232);
  - `checkable` and `printable` constrain the helpers that forward to
    `expect()`/`require()` and to the message `operator<<`.

  The other two serve only the implementation: `has_value` is a
  shortcut in `compare_op` for two literals (`inlines/detail-inlines.h`
  lines 364 to 368), which `detail::unwrap()` makes unnecessary for a
  custom comparator, and `container_like` and `has_npos` only select
  the container overload of the formatter (`expression-formatter.h`
  lines 508 to 512); an application that needs such tests has
  `std::ranges::range` and the standard string types, which are more
  precise. Move `has_value`, `container_like`, and `has_npos` to
  `detail`, and keep the unit tests on them through `detail::`. The
  name `type_traits` no longer describes the content, and, with #54, the
  namespace would also hold the building blocks of the expressions,
  which are not concepts either; since this item is breaking anyway,
  rename it after its purpose, for example `extension` (singular, as
  `math`, `reflection`, and `utility`). Keep it a separate namespace,
  not the top one, since the applications write `using namespace` on
  the top namespace, and generic names like `is_op` and `unwrap` would
  leak into their code. Decide together with #54.

- **#54 — Custom comparators and operators cannot report their
  operands.** [internal] **[confirmed]** (fixed)
  Fixed in `47d987d4` (#149): `compare_op` is public, as
  `extension::compare_op`, with the tags of the application (an empty
  struct with a `symbol` and a static `apply()`, which receives the
  unwrapped operands; the tolerance applies only if the tag defines
  `within_tolerance_result`), and the new `extension::predicate_op`
  does the same for the unary predicates, reported as
  `symbol operand`; the formatter reports both as the built-in
  expressions, so no base class, `unwrap()`, or formatter hook had to
  be made public. The generic formatter overload accepts only the
  value wrappers, which have `get()`, so a type with only the marker
  is rejected at compile time. Static asserts and unit tests with a
  custom comparator, predicate, and operator written with public names
  only; User's Guide section and compatibility notices added.
  `values.h` lines 111 to 121, `detail.h` lines 177 and 251,
  `expression-formatter.h` lines 491 to 494 and 587 to 676,
  `inlines/expression-formatter-inlines.h` lines 133 to 140,
  `inlines/detail-inlines.h` lines 90 to 97: an application can write
  a comparator that returns `bool`, which `checkable` accepts, but a
  failure then shows no operands; or it can combine the existing
  comparators (`both (ge (x, lo), le (x, hi))`), which shows them, but
  cannot express a new relation. To write a new comparison that is
  reported as the built-in ones are, it must return a framework
  expression, and everything needed to build one is in `detail`: the
  `detail::op` marker that `is_op` tests, the `unary_op` and
  `binary_op` bases, and `detail::unwrap()`. The formatting cannot be
  extended either: each built-in expression has its own `operator<<`
  overload in `expression_formatter`, and any other type that
  satisfies `is_op` falls into the generic overload, which writes
  `detail::unwrap (t)`; for a type without `get()`, `unwrap()` returns
  the object itself, and the overload calls itself. A probe with a
  user type that declares `using op_type = detail::op;` and an
  explicit `operator bool` returning `false`, checked with
  `t.expect (my_op{})`, stops with a stack overflow in
  `detail::unwrap<my_op>` (AddressSanitizer). Define a public extension
  point, in the namespace of #23: a base for the binary (and unary)
  expressions, which stores the operands and the result, `unwrap()`,
  and a way for the derived type to write itself (for example an
  operator symbol, or a member `format()` that the formatter calls),
  so that the formatter needs no overload per type; and make the
  generic overload reject, at compile time, an `is_op` type that it
  cannot format. Add a unit test that defines a custom comparator and a
  custom operator using only public names; what it cannot compile
  without is what must be public. Decide together with #23.

- **#24 — Suites are deferred, test cases are immediate, and the calls
  look the same.** [breaking] **[confirmed]** (fixed)
  Fixed in `aa662c25` (#126), with #31, by the first option:
  `runner::add_suite()` replaces `runner::suite()`, which is
  deprecated; the dynamic suites are still deferred, and the name now
  shows it.
  `inlines/runner-inlines.h` lines 104 to 119,
  `inlines/test-inlines.h` lines 449 to 468: `ts.test (name, f)` runs
  `f` at once, while `tr.suite (name, f)` stores `f` and runs it from
  `run()`. In a probe, a helper function registered both with lambdas
  capturing a local by reference: the test case passed, the suite read
  a dead stack frame ("stack-use-after-return"). Either name the
  deferral (for example `add_suite()`), or run dynamic suites
  immediately, as test cases are, and keep the deferral only for static
  suites, which need it.

- **#25 — The execution order of the suites is implicit.** [internal]
  (fixed)
  Fixed in `81bce73b` (#120): the name order chosen by #61 is kept,
  since the static suites, constructed in an unspecified order, need
  it, and a single rule keeps the order independent of how a suite is
  declared. The FAQ, the User's Guide, and the runner documentation
  state that the names are compared byte by byte (case-sensitively,
  and without comparing the numbers by value), that the suites added
  with `suite()` do not run in the order of the calls, and that
  zero-padded numeric prefixes give an explicit order.
  `src/runner.cpp` lines 475 to 535, `src/test.cpp` lines 420 to 436:
  the top suite runs first (as its test cases are written in `main()`),
  then the dynamic and the static suites are merged and run sorted by
  `strcmp()`, so in byte order ("Z" before "a"), regardless of the
  order of registration. Nothing in the names reveals this. Document
  it, or keep the registration order for the dynamic suites, which is
  what a user writing them in sequence expects.

- **#26 — Quiet mode hides which checks failed.** [internal]
  **[confirmed]** (withdrawn)
  Withdrawn by decision in `f497d3ec` (#121); the code is unchanged,
  and the behaviour is documented. The observation is correct, but the proposal is not
  useful: the normal verbosity already displays the details of the
  failed test cases and only one line per passed test case, so a quiet
  level showing the failures would hardly differ from it. The levels
  keep distinct purposes: `quiet` tells whether the run failed (and,
  with TAP, which suites failed), `normal` tells what failed, and the
  TAP output file, complete at every verbosity (#15), keeps the full
  record when the console is quiet. The human reporter, intended for
  the console, has no such file (#15), so with it `--quiet` shows
  only the totals. The User's Guide (Verbosity section, with a table of
  the console and file contents per level), the FAQ, the Command Line
  Options page (whose quiet example still showed the `1..0` plan
  removed by #14), and the `verbosity` documentation in
  `runner-options.h` now state that `--quiet` does not show which
  checks failed, and how to find out.
  `src/reporter-human.cpp` lines 497, 575 to 581, and 829,
  `src/reporter-tap.cpp` lines 537 and 784 to 785: at `quiet`, both
  reporters print only the totals; the failed checks, their locations,
  and their test cases are not printed, so a user must run again to
  learn what failed. Quiet usually means "only the failures". Print the
  failures (with their test case names) at `quiet`, and keep `silent`
  for no output.

- **#27 — The library terminates the process and reports errors outside
  the reporter.** [internal] **[confirmed]** (fixed)
  Fixed in `c8295c08` (#122): what remained after #6 and #7 was
  done; the abort of a failed requirement without exceptions is kept,
  by the decision of #7, with the handler deciding how the process
  ends. (1) The reporters no longer abort when a top-level test case
  begins with results in the buffer (no longer reachable from valid user
  code since #6); they write the results, as for a nested test case,
  and continue; the human reporter wrote them to `stderr`, the TAP one
  to `stdout`. (2) `runner::abort()`, for a failed requirement and for
  an explicit call alike, now has the reporter complete the report,
  through the new `reporter::abort_session()` (replacing
  `abort_test_case()`), between `initialise()` and the end of `run()`:
  the results of the running test case, then
  `✗ Test execution aborted at <file>:<line>` (human) or
  `Bail out! Requirement failed|Test execution aborted at
  <file>:<line>` (TAP), on the console and in the output file; the
  `stderr` line is written only before `initialise()` or after `run()`.
  A probe confirmed that an explicit `runner::abort()` previously lost
  the buffered results of the running test case, and left the output
  file without a trace of the abort. A probe also showed that an
  exception thrown by the abort handler, which `abort_handler_t`
  allows, to return control to the application, was caught by the
  test case (or the suite) as unexpected, and the run continued; the
  runner now sets a final `aborted_` flag before calling the handler,
  the test cases and the suites pass the exception on, no test case
  runs afterwards, `initialise()` and `run()` refuse to start (`run()`
  returns 1), a repeated abort is not reported again, and the
  reporters clear the buffer after the abort, so that its results are
  not written twice. Verified with probes (both
  reporters, all verbosity levels, the output file, with and without
  exceptions, from a test case, a top suite test case, a suite body,
  and after `run()`); regression test in
  `tests/sources/unit/src/miscellaneous.cpp`. The configuration errors
  (options, output file, suites added too late) are still reported on
  `stderr`, as usage errors, mostly before the reporter exists; having
  the reporter repeat them in the output file is left to #28.
  `src/runner.cpp` lines 198, 321 to 323, 367 to 369, 567, and 635 to
  646, `src/reporter.cpp` lines 99 to 100,
  `src/reporter-human.cpp` lines 437 to 442 and 762 to 767,
  `src/check-result.cpp` lines 166 to 168: `::abort()` is called from
  `runner::abort()` (reached from #6 and #7), and the error messages go
  to `stderr` with `fprintf()`, so they are missing from the output
  file and may be lost on targets where `stderr` is not connected.
  The abort handler cannot prevent the abort, since `runner::abort()`
  is `[[noreturn]]`. Report errors through the reporter (and the
  file), and leave the termination to the application, apart from the
  explicit `runner::abort()`.

- **#28 — The configuration errors are missing from the output file.**
  [internal] (withdrawn)
  Withdrawn by decision on 2026-10-20; the code is unchanged. Of the
  four errors, an output file that cannot be opened cannot be written
  to it, and a suite added after `run()` finished is reported when the
  file is already closed; only the option errors could be repeated,
  and only by keeping them until the file is open, which adds state
  for little benefit, since the CI tools keep `stderr` in their logs.
  The User's Guide (Console output section) already states that these
  errors go only to `stderr` and are not written to the output file.
  Revised by decision on 2026-10-18. The original item also proposed
  an output sink in `runner_options` (a `void (*) (const char*,
  size_t)` defaulting to `stdout`) and, later, user-defined reporters;
  both parts are withdrawn, and the behaviour is documented in the
  Console output section of the User's Guide. The redirection of the
  output is the job of the C library, not of the framework: on the
  µOS++ platforms, which provide the C library back end, `stdout`,
  `stderr`, and `fopen()` already reach the host through Arm
  semihosting, so both the console output and the output file work
  without a hook; the other environments (for example the Pico SDK or
  STM32CubeMX projects) send the output to a UART or RTT by
  retargeting the C library (`_write()` with newlib), which a sink
  would only duplicate. A sink would not reduce the code size either,
  since the formatting still needs `vfprintf()`. The reporters remain
  a closed enumeration, selected with `--reporter` or
  `runner_options`.
  The remaining problem is in
  `src/runner.cpp` lines 332, 378, and 462, and `src/reporter.cpp`
  line 99: the configuration errors (a missing option argument, an
  unknown reporter, a suite added too late, an output file that cannot
  be opened) are written only to `stderr` (see #27). With semihosting
  they reach the host, but they are missing from the output file, so a
  run that returns 2 does not record why in the file read by the other
  tools. Have the reporter repeat them in the output file, once it is
  open (in TAP, as `#` diagnostic lines before the plan).

- **#29 — `counters` is a value type that cannot be copied.**
  [internal] (fixed)
  Fixed in `6dec41fb` (#124): the copy and move operations of
  `counters` are now defaulted (and documented), so
  `counters before = ts.totals ();` takes an independent snapshot; the
  class is trivially copyable. The change is additive, so the original
  [breaking] tag was wrong. The counters of the nodes are still
  protected: the runner, the suites, and the test cases remain neither
  copyable nor movable, and `totals()` returns only a `const`
  reference. Regression tests in
  `tests/sources/unit/src/static-asserts.cpp` (copy and move traits)
  and `tests/sources/unit/src/miscellaneous.cpp` (a snapshot taken
  before a test case keeps its values, and an assigned copy matches
  the live counters).
  `counters.h` lines 124 to 152: the class holds five `size_t` values,
  but its copy and move operations are deleted, so a user cannot take a
  snapshot (`auto before = tr.totals ();`) to compare later. Make it
  copyable (the default operations suffice).

- **#30 — `protected` is used for classes that are not designed for
  derivation.** [internal] (fixed)
  Fixed in `cee35ed9` (#125): the non-public members of `runner`,
  `counters`, `reporter_human`, and `reporter_tap` are `private`; no
  code derived from these classes, and the friends keep their access.
  The `expression_formatter` part was settled by #22. `stopwatch`
  keeps `protected`, since the unit tests derive from it to set known
  clock readings (`tests/sources/unit/src/stopwatch.cpp`), so the
  problem did not apply to it; its class comment now says so. No
  regression test was added, since an access to these members from
  outside is a compilation error.
  `runner.h` lines 517 to 710, `counters.h` lines 292 to 339,
  `stopwatch.h` lines 224 to 253, `expression-formatter.h` lines 666
  to 729, `reporter-human.h` lines 262 to 382, `reporter-tap.h` lines
  256 to 323: `runner`, `counters`, `stopwatch`, and
  `expression_formatter` have no virtual functions, and
  `reporter_human` and `reporter_tap` are `final`, yet their non-public
  members are `protected`, which suggests an extension point that does
  not exist. Use `private`.

## 3. Naming and consistency

- **#31 — Member functions named after types.** [breaking] (fixed)
  Fixed in `aa662c25` (#126): `runner::add_suite()` and
  `runner::verbosity_level()` replace `runner::suite()` and
  `runner::verbosity()`, which remain as `[[deprecated]]` aliases that
  forward to them; the new name also shows that the suite is only
  added to a list, to be run by `run()` (see #24).
  `reporter::verbosity()` no longer existed, so it needed no change.
  While the aliases exist, they still hide the types inside the
  runner, so `class suite` and `micro_test_plus::verbosity` stay in
  `runner.h` until the aliases are removed. The "Runner options" test
  case in `tests/sources/unit/src/miscellaneous.cpp` checks that the
  aliases still work.
  `runner.h` lines 266, 295, 361 to 363, 452 to 453, and 592,
  `reporter.h` lines 567 to 568 and 777, `test.h` lines 404 and 436,
  `runner-options.h` lines 170 to 172: `runner::suite()`,
  `runner::verbosity()`, and `reporter::verbosity()` hide the types of
  the same names inside the classes, which forces `class suite&`,
  `class top_suite`, `enum verbosity`, and `micro_test_plus::verbosity`
  throughout the code. Rename the functions (for example
  `add_suite()`, see #24, and `verbosity_level()`, matching the
  `runner_options` data member).

- **#32 — Two public counts are not named after what they count.**
  [breaking] (fixed)
  Fixed in `a46e6f17` (#127), as decided below: `added_suites_count()`
  and `passed_checks()`, with `increment_passed_checks()`, replace
  `suites_count()`, `successful_checks()`, and
  `increment_successful_checks()`, which remain as `[[deprecated]]`
  aliases. The reporters, the unit tests (including the test-local
  `local_counts` field), and the compatibility notices use the new
  names; the "Runner options" test case in
  `tests/sources/unit/src/miscellaneous.cpp` checks that the aliases
  still work, and that `suites_count()` still counts the top suite.
  Rewritten on 2026-10-19: the original table also listed names that
  were not inconsistent (`executed_checks()`, the sum of the passed and
  failed checks), not counts (`reporter::pass()`, an internal event
  handler; `counters::passed()`, a predicate), or no longer public
  (`own_index()` and `test_point_number()`, removed by #20; the
  remaining private names are covered by #34).

  - Suites. `runner::suites_count()` (`runner.h` lines 538 to 546,
    `src/runner.cpp` lines 745 to 753) returns the number of the
    suites added with `add_suite()`, plus one for the top suite, but
    not the `static_suite` objects; those are counted by
    `static_suites_count()`, and only `total_suites_count()`
    (`runner.h` lines 489 to 501) counts all the suites, which is the
    number both reporters print (`src/reporter-human.cpp` line 174,
    `src/reporter-tap.cpp` line 299). A user who wants the number of
    suites calls `suites_count()` and silently gets a subset. The
    comments share the confusion: `total_suites_count()` is described
    as the count of the "registered" suites, although it is the only
    one that includes the static suites. Either make `suites_count()`
    count all the suites and deprecate `total_suites_count()`, or
    rename `suites_count()` after what it counts (for example
    `registered_suites_count()`) and keep the old name as a
    `[[deprecated]]` alias. The first option silently changes the
    value returned by an existing call, so the second is safer.
  - Checks. `counters::successful_checks()` and
    `increment_successful_checks()` (`counters.h` lines 196 to 204 and
    248 to 256) call the checks "successful", while the opposite count
    is `failed_checks()`, the reporters print "checks passed"
    (`src/reporter-human.cpp` line 193), `counters::passed()` reports
    that nothing failed, and the comment of `successful_checks()`
    itself says "the number of checks that passed". Rename the pair
    `passed_checks()` and `increment_passed_checks()`, and keep the
    old names as `[[deprecated]]` aliases.

  The unit tests that check the current meaning of `suites_count()`
  (`tests/sources/unit/src/main.cpp` lines 722 to 762,
  `tests/sources/unit/src/miscellaneous.cpp` lines 1413 and 1433) must
  follow the chosen option.
  Decision (2026-10-19): `runner::added_suites_count()` replaces
  `suites_count()` and counts only the suites added with `add_suite()`,
  without the top suite; the callers that need the top suite add one
  themselves. `suites_count()` remains as a `[[deprecated]]` alias that
  returns `added_suites_count () + 1`, so its value does not change;
  `total_suites_count()` keeps its value, now computed as one (the top
  suite) plus `added_suites_count()` plus `static_suites_count()`.
  `counters::passed_checks()` and `increment_passed_checks()` replace
  `successful_checks()` and `increment_successful_checks()`, which
  remain as `[[deprecated]]` aliases; the data member
  `successful_checks_` becomes `passed_checks_`.

- **#33 — "aborted..." is printed for a requirement that stops only the
  test case.** [internal] (fixed)
  Fixed in `e7421411` (#144), together with #49; the GitHub issue of
  this item is #128. For a failed requirement, the human reporter
  appends `- test case stopped` with exceptions, and
  `- test execution aborted` without; the TAP reporter adds no marker,
  since the plan of the test case shows the stop, and the `Bail out!`
  line the abort.
  `src/reporter-human.cpp` lines 722 to 725, `src/reporter-tap.cpp`
  lines 690 to 693: with exceptions, a failed requirement stops its test
  case and the run continues, but both reporters say "aborted...".
  Say what happens (for example "test case stopped").

- **#34 — The trailing underscore marks both data members and member
  functions.** [internal] (fixed)
  Fixed in `01efcbac` (#129), as decided below: the trailing
  underscore was removed from all the member functions listed, and from
  `runnable_base::is_aborted()`, which the list omitted; `run()` and
  `abort()` have their names of before #20 again.
  `runnable_base::reporter_()` became `test_reporter()`, rather than
  `get_reporter()`, to match `test_runner()`, which keeps its name since
  `runner()` would hide the class `runner` in the same way; the comments
  of both functions say why. The derived reporter of the unit tests
  (`tests/sources/unit/src/miscellaneous.cpp`) overrides the renamed
  output functions. The local variables `link` in
  `static_suite::link()` and `unlink()` became `slot`, so they no
  longer share the name of their function. The private getters removed
  in #20 were not restored, since nothing needs them. No regression
  test was added, and no compatibility notice, since all the renamed
  functions are non-public.
  `test.h` lines 389 to 420 and 448 to 504, `runner.h` line 614:
  `runnable_base::reporter_()` is a function, `runner::reporter_` a
  data member; `test_runner_()` returns `runner_`. The same spelling
  for two kinds of entities, in friend classes that use both, makes the
  code harder to read. Reserve the trailing underscore for data members,
  or give the private functions verb names (for example
  `get_reporter_()`).
  Decision (2026-10-18): reserve the trailing underscore for the
  non-public data members; no member function has it, whatever its
  access. This reverses the renaming of `run()` and `abort()` to
  `run_()` and `abort_()` in #20. Functions to rename, by header:
  `test.h` (`abort_()`, `after_test_case_create_()`,
  `fail_unexpected_exception_()`, `link_()`, `next_test_point_number_()`,
  `reporter_()`, `run_()`, `running_test_case_()`, `test_runner_()`,
  `unlink_()`); `runner.h` (`is_selected_()`, `parse_options_()`,
  `register_suite_()`, `run_child_suites()`); `reporter.h`,
  `reporter-human.h`, and `reporter-tap.h` (`clear_buffer_()`,
  `commit_buffer_()`, `display_open_names_()`,
  `format_elapsed_time_()`, `output_pass_prefix_()` and its three
  siblings, `write_buffer_to_file_()`, `write_console_()`,
  `write_file_()`, `write_info_()`); `expression-formatter.h`
  (`append_decimal_point_()`, `append_elements_()`, `colour_()`);
  `stopwatch.h` (`is_recorded_()`). One name cannot simply drop the
  underscore: `runnable_base::reporter()` would hide the type
  `detail::reporter` in `suite` and `test_case` (the problem of #31),
  so it needs another name (for example `get_reporter()`). The private
  getters removed in #20 could now be private functions again, since
  they no longer clash with their data members. The function-pointer
  and `std::function` data members (`abort_handler_`, `callable_`)
  keep the underscore. The change is not breaking, since all the
  functions are non-public.

- **#35 — Minor inconsistencies of qualifiers and names.** [internal]
  (fixed)
  Fixed in `eca85089` (#130): `check_result::value()` and
  `reporter::comment_prefix()` (with its overrides), the only `const`
  accessors without `noexcept`, are now `noexcept`; `stopwatch::start()`
  now restarts the measurement, clearing both readings, and `stop()`
  replaces the stop reading. The line numbers below predate #125 to
  #129.
  `runner.h` lines 452 to 453 (`noexcept`) and `reporter.h` lines 567
  to 568 (not), `check-result.h` lines 303 to 304 (`value()` not
  `noexcept`), `src/stopwatch.cpp` lines 96 to 120: equivalent
  accessors differ in `noexcept`, and `stopwatch::start()` and `stop()`
  record only their first call, which their names do not say (`start()`
  after `stop()` is silently ignored). Align the qualifiers, and either
  rename the functions or make them restart.

- **#55 — The documentation says "method" and "field" for the class
  members.** [internal] (fixed)
  Fixed in `5d000eaf` (#150): the Doxygen comments in the headers and
  the sources, the website pages, the comment in
  `tests/sources/unit/include/unit-test.h` line 118, the
  `.github/skills/led/SKILL.md` line, and #31 now say _member
  functions_ and _data members_ (the `timespec` fields became
  _members_). The rule, and the terms in
  `.github/copilot-instructions.md`,
  `.github/skills/code-review/SKILL.md` (lines 50 and 126), and
  `.github/skills/doxygen-review/SKILL.md` (lines 31 and 125), are
  left to a separate change of the project instructions. The line
  numbers below predate the fix.
  `.github/copilot-instructions.md` (Code Style) now requires the C++
  terms: _member functions_ rather than _methods_, and _data members_
  rather than _fields_. The documentation predates the rule and uses
  the other terms throughout:
  - the Doxygen comments in the headers: `reporter.h` line 175,
    `reporter-human.h` line 102, `reporter-tap.h` line 90, `runner.h`
    lines 150 and 161 (the last three say "All members and methods",
    which also implies that the member functions are not members),
    `reflection.h` line 141, `inlines/counters-inlines.h` line 24,
    `inlines/expression-formatter-inlines.h` line 24,
    `inlines/runner-inlines.h` lines 25 and 27, `inlines/test-inlines.h`
    lines 27 and 188, `inlines/values-inlines.h` lines 25, 27, and 35;
  - the Doxygen comments in the sources: the file headers of
    `src/check-result.cpp`, `src/counters.cpp`, `src/reporter.cpp`,
    `src/reporter-human.cpp`, `src/reporter-tap.cpp`, `src/runner.cpp`,
    and `src/test.cpp` (line 21 in each), and `src/counters.cpp` line
    25, `src/reporter.cpp` lines 159, 172, and 370, `src/test.cpp` line
    26, `src/reporter-human.cpp` lines 229, 261, 374, 431, 483, 635,
    640 to 641, 662 to 663, 676, 724, and 805, `src/reporter-tap.cpp`
    lines 781, 788, 790 to 791, 816 to 817, 834, and 985;
  - the website: `website/docs/user/_project/_content.mdx` lines 321,
    337, 450, and 526, `website/docs/getting-started/glossary/index.mdx`
    lines 22 and 26;
  - the project instructions, which contradict the new rule:
    `.github/copilot-instructions.md` line 79 ("Document all classes,
    methods, properties"), `.github/skills/code-review/SKILL.md` line
    50, `.github/skills/doxygen-review/SKILL.md` lines 31 and 125, and
    `.github/skills/led/SKILL.md` line 63;
  - this report: #31 said "the `runner_options` field".

  Replace the terms in all these places. Keep them where they do not
  name a class member: "method" meaning a procedure (the install pages,
  the blog posts, and the "Method:" lines of the reports), the
  `-Wsuggest-final-methods` pragmas, and "field" for the TAP YAML
  diagnostics keys (`src/reporter-tap.cpp` lines 840, 877, and 881,
  `website/docs/getting-started/_project/_compatibility-notices.mdx`
  line 293, and #51 to #53 here). The `tv_sec` and `tv_nsec` fields of
  `struct timespec` (`stopwatch.h` lines 237 to 238,
  `inlines/stopwatch-inlines.h` line 68, `src/stopwatch.cpp` line 125)
  are members of a C structure; "members" fits them as well. Leave the
  published blog posts unchanged, as they record past releases, and
  leave the generated API pages in `website/docs/api/` to be
  regenerated from the corrected comments.

## 4. Simplicity and duplication

- **#36 — The messages accept fewer types than the expressions.**
  [internal] **[confirmed]** (fixed)
  Fixed in `6d33fa75` (#131): `check_result::operator<<` moves the message
  into a local `expression_formatter` in a private plain mode (no type
  suffixes, no added decimal point, `char` unquoted, no colours),
  appends the value with the formatter overloads, and moves the message
  back, so no buffer is allocated; `printable` is now satisfied by the
  types that the formatter writes. The values accepted before are
  written unchanged. Static asserts in
  `tests/sources/unit/src/static-asserts.cpp`, and the "Message types"
  test case in `tests/sources/unit/src/miscellaneous.cpp`; User's Guide
  and compatibility notices updated.
  `inlines/check-result-inlines.h` lines 148 to 178, `extension.h`
  lines 221 to 223, `src/expression-formatter.cpp` lines 66 to 517,
  `inlines/expression-formatter-inlines.h` lines 118 to 225: the check
  message (`expect (...) << value`) and the expression formatter
  implement the stream operators for the same values, with separate
  rules. A message accepts only the arithmetic types, `std::nullptr_t`,
  and the types convertible to `std::string_view` (`printable`), while
  an expression also accepts the pointers, the containers, `std::pair`,
  `std::tuple`, `std::optional`, the enumerations, and the application
  types with an `operator<<` for `expression_formatter`; the fixes of
  #11 and #18 widened the gap, since they changed only the formatter.
  In a probe (on 2026-10-20, at `8fa29e9b`), `eq (p, nullptr)`, with
  `int* p`, was reported, but `expect (false) << p` did not compile
  (`'int *' does not satisfy 'printable'`, followed by a misleading
  error about `std::function`, see #45). Let the message pass the values
  that are not strings to an `expression_formatter` in a plain mode,
  which writes the numbers without the type suffixes (`2u` as `2`) and
  `char` unquoted, as the messages do now, and widen `printable` to the
  types that the formatter accepts; the application `operator<<`
  functions then serve the messages too. The reporter also has its own
  stream operators (`src/reporter.cpp` lines 403 to 495,
  `inlines/reporter-inlines.h` lines 86 to 110), but they receive only
  the text and the numbers written by the library, and already share
  `detail::append_number()` and `detail::append_pointer()` with the
  formatter; merging them is not needed. The wide character types,
  reported as numbers in both paths, are #56. (Narrowed on 2026-10-20;
  the item first covered the reporter and the wide characters too.)

- **#37 — Two hand-written sorts and a merge.** [internal]
  (fixed)
  Fixed in `fdaa1f64` (#132): all the suites are kept in one list,
  sorted by `suite::link()`, as proposed below.
  `src/runner.cpp` lines 475 to 535, `src/test.cpp` lines 420 to 436:
  the dynamic suites are insertion-sorted, the static suites are kept
  sorted by insertion into a list, and the two sequences are then
  merged; the names are compared with `std::strcmp()` in three places,
  which must agree, or the merge silently produces a wrong order. Keep
  all the suites in the intrusive list, sorted by `link()`: move
  `next_`, `first_`, `link()`, and `unlink()` from `static_suite` to
  `suite`, link the registered suites in `register_suite()`, unlink in
  `~suite()`, and let `run_child_suites()` walk the list, skipping the suites
  of other runners; `static_suites_count()` subtracts the registered
  suites from the count of the list. The insertion sort and the merge
  are removed, nothing is allocated, and the names are compared in one
  place. For equal names, the suites run in the order of their
  creation, so the static suites constructed before `main()` run before
  the registered ones (the reverse of the merge). Collecting pointers
  into a vector and calling `std::stable_sort()` was considered and
  rejected: it allocates a temporary buffer, adds the merge code of the
  standard library on the embedded targets, and still needs raw
  pointers as iterators to avoid `-Waggregate-return`. The order by
  name is kept (see #25).

- **#38 — `suite::test()` and `test_case::test()` are duplicated.**
  [internal]
  (fixed)
  Fixed in `71f381a6` (#133): the common body is
  `runnable_base::create_test_case()`, as proposed below.
  `inlines/test-inlines.h` lines 299 to 318 and 449 to 468: the two
  bodies differ only in the parent suite and the nesting depth. Move
  the body to `runnable_base`, with these two values as parameters.

- **#39 — The reporters duplicate their common logic.** [internal]
  (fixed)
  Fixed in `48a2b3b8` (#134): the counts text of the session, suite,
  and test case lines is formatted by `reporter::format_session_totals()`,
  `format_suite_totals()`, and `format_test_case_totals()`, with the
  labels and markers left to each reporter; the check of the buffer is
  `reporter::commit_outer_results()`, with `commit_buffer()` a pure
  virtual of `reporter`. The skip lines were left in each reporter,
  since their formats differ by design. The lines written twice by the
  TAP reporter are #57.
  `src/reporter-human.cpp` lines 174 to 201, 427 to 444, and 752 to
  769, `src/reporter-tap.cpp` lines 155 to 186, 422 to 436, and 729 to
  743: the totals line, the check of the buffer at the beginning of a
  test case (twice in each reporter), and the "skipped" fragments are
  written out separately in each place. Move them to `reporter` as
  helpers.

- **#40 — `reflection::short_name()` duplicates
  `utility::extract_file_name()`.** [breaking]
  (fixed)
  Fixed in `efbebd50` (#135): `short_name()` was released in
  5.0.1, so it was deprecated, not removed; it remains as a
  `[[deprecated]]` alias of `utility::extract_file_name()`.
  `src/reflection.cpp` lines 70 to 74, `reflection.h` lines 217 to
  218, `src/utility.cpp` lines 87 to 97: `short_name()` only forwards,
  and the library does not use it. Remove it (or deprecate it).

- **#41 — The floating-point literal encoding compensates itself.**
  [internal]
  (fixed)
  Fixed in `dd9c8cbf` (#136): `den()` returns the plain decimals (25 for
  `1.25`), `den_size<Cs...>()` their count (2), and the epsilon of
  `floating_point_constant` is `1 / 10^Size`; the values and the
  tolerances of the literals are unchanged, and one more decimal is
  accepted (19 instead of 18). The run-time function is renamed
  `count_decimals()`.
  `inlines/math-inlines.h` lines 241 to 296 and 323 to 356, `values.h`
  lines 273 to 282 and 409 to 415: `den()` multiplies the decimals by
  10, `den_size<Cs...>()` returns the count plus one to compensate, and
  the epsilon subtracts the one again; the run-time `den_size (value)`
  has the same name but returns the count without the one. Pass the
  plain decimals and their count, and give the run-time function its
  own name (for example `count_decimals()`).

- **#42 — `throws_op` and `nothrow_op` are templates on the callable
  type.** [internal]
  (fixed)
  Fixed in `0bf23316` (#137): the callable is a parameter of the
  constructors only; `throws_op` is parameterised by the exception type
  alone, `nothrow_op` is a plain struct, and the two `throws_op`
  formatter overloads are merged into one.
  `detail.h` lines 859 to 926, `expression-formatter.h` lines 531 to
  555, `inlines/exceptions-inlines.h` lines 80 to 121: the callable is
  used only in the constructor; the objects keep a single `bool`. The
  parameter makes a new class, and new formatter instantiations, for
  every lambda. Return a `callable_op` (or a type parameterised only by
  the exception type) from `throws()` and `nothrow()`.

- **#57 — The TAP reporter formats most of its lines twice.**
  [internal]
  (fixed)
  Fixed in `a451f903` (#152): `reporter::write_line (bool to_console,
  const char* format, ...)` formats the text once and writes it to the
  output file, without the colour sequences, and, when requested, to
  `stdout`; it serves the 8 pairs of the TAP reporter, the 12 pairs of
  the human reporter (all of which match their console lines once the
  colours are removed), and the two lines of `write_info()`. In the TAP
  `end_test_case()`, the plan line stays split between the two streams
  with normal verbosity, since the console plan of a passed test case
  counts only the nested test cases. The removal of the colour
  sequences is shared with `write_buffer_to_file()`; as a side effect,
  a colour sequence in a test name no longer reaches the TAP output
  file, as was already the case for the check lines. The console and
  file outputs of the sample programs, for both reporters and all
  verbosity levels, were compared with those of the previous version
  and found identical.
  `src/reporter-tap.cpp` lines 266 and 270, 309 and 319, 346 and 355,
  409 and 442, 484 and 494, 553 and 562, 871 and 881, and 931 and 942:
  in `begin_session()`, `end_session()`, `begin_suite()`, `end_suite()`,
  `skip_suite()`, `begin_test_case()`, `skip_test_case()`, and
  `abort_session()`, the same line is written by `write_file()` and
  again by `write_console()`, with the same format and arguments, the
  second under a verbosity condition (in `end_suite()`, only with
  normal or verbose verbosity; the quiet line is shorter). Add to
  `reporter` a variadic helper, for example `write_line (bool
  to_console, const char* format, ...)`, which formats the line once
  and writes it to the output file and, when requested, to `stdout`.
  The empty line and the buffered output that precede the console line
  stay with the callers, since their conditions differ; they are
  written before the helper is called, so the file line is written
  after the console output of the buffer, rather than before it, but
  the content of each stream is unchanged.
  In the human reporter, the file and console lines differ by the
  colour sequences, which `write_buffer_to_file()` already removes; the
  same helper could serve it if it removed them from the file copy, but
  only if all its 12 `write_file()` calls match their console lines in
  this way, which is to be checked. Found while fixing #39.

## 5. Suitability for embedded targets

- **#43 — Every check formats its operands and flushes the output,
  even when nothing is printed.** [internal] **[confirmed]** (fixed)
  Fixed in `fdcab206` (#138): `reporter::writes_passed_checks()` tells
  whether the passed checks are written (the human reporter with normal
  or verbose verbosity, the TAP reporter also with an output file);
  when not, `check_result` formats neither the expression nor the
  messages of a passed check, decided in the constructor, while the
  operands are alive, and reports no pass line; a failed check is
  always formatted. The pass and fail suffixes no longer flush the
  streams, which are flushed when the test case ends. With `--quiet`,
  an aborted test execution now displays only the failed checks,
  unless the TAP reporter writes an output file; regression test in
  `tests/sources/unit/src/miscellaneous.cpp`.
  `inlines/check-result-inlines.h` lines 93 to 110,
  `src/reporter.cpp` lines 496 to 508, `src/reporter-human.cpp` lines
  630 to 658, `src/reporter-tap.cpp` lines 614 to 641: the expression is
  formatted into a string in the `check_result` constructor, the pass
  line is formatted into the reporter's buffer, and `fflush (stdout)`
  is called after every check. In a probe at `--quiet`, 100 passing
  checks on a user type called its formatter 200 times. On a target
  with semihosting, the per-check flush is a host round trip. Format
  the expression only when it will be printed (a failure, or
  `verbose`); the operands are still alive in the destructor of an
  unstored `check_result`, and a stored one could be formatted eagerly.
  Flush at the end of a test case.

- **#44 — The operands are copied into each comparison.** [internal]
  **[confirmed]** (fixed)
  Fixed in `8d3b836a` (#139): the function comparators, the operators,
  and the extension templates take forwarding references; the
  temporaries are moved into the expression, the named operands of
  class type and the nested expressions are referred to, and the
  scalars are kept by value (`detail::stored_operand_t`). `operator not`
  and `negate()` name the template argument of `not_op`, since the class
  template argument deduction copied an inner `not_op`, so `not not x`
  was evaluated as `not x`; regression tests in
  `tests/sources/unit/src/miscellaneous.cpp`, `operators.cpp`, and
  `static-asserts.cpp`.
  `detail.h` lines 310 to 320, `inlines/detail-inlines.h` lines 140 to
  145, `inlines/function-comparators-inlines.h` lines 85 to 91:
  `binary_op` stores the operands by value, so `eq (a, b)` copied both
  operands in a probe, and comparing two `std::vector` objects
  allocates two copies. Since the comparison result is consumed within
  the same full expression, storing `const&` is safe for checks;
  however, a user who keeps `auto op = eq (f (), 1);` would then hold a
  dangling reference, so this is a trade-off for the maintainer
  (references for class types, values for scalars, is one option).

- **#45 — Each test case allocates a `std::function`.** [internal]
  **[confirmed]** (fixed)
  Fixed in `3d7ec5fa` (#140): the body of a test case, with the copies
  of its arguments, is a local object of `create_test_case()`, and the
  test case refers to it with `detail::callable_ref`, which holds its
  address and a function pointer, without allocation; the suites still
  store their bodies in a `std::function`; regression test in
  `tests/sources/unit/src/miscellaneous.cpp`.
  `test.h` line 866, `inlines/test-inlines.h` lines 224 to 239 and 249
  to 262, `src/test.cpp` line 310: the callable of a test case, with
  the copies of its bound arguments, is stored in a `std::function`,
  which allocates when they do not fit its small buffer. In a probe (on
  2026-10-20, at `8fa29e9b`, Apple clang 17 with libc++, whose buffer
  holds three pointers), a nested test case whose lambda captured four
  references allocated once, while a lambda that captured one
  reference, and a lambda without captures with a bound `int`, did not.
  With `arm-none-eabi-g++` 15.2.1, the libstdc++ buffer is 8 bytes on
  Cortex-M, so a lambda that captures three references already
  allocates. Test cases run immediately, inside `test()`, and the
  callable and the arguments outlive `run()`, so they need no
  ownership: a non-owning reference (the address of the callable and a
  function pointer to a template thunk) is enough, without allocation
  (suites, which are deferred, still need `std::function`). A compile
  error in a test case body would then no longer be followed by a
  misleading error about the conversion to `std::function` (see #36).

- **#50 — The value wrappers trigger a GCC `-Wpsabi` note on
  AArch64.** [internal] **[confirmed]** (fixed)
  Fixed in `604b608e` (#145): `detail::op` defines an `op_type` marker,
  `type_traits::is_op` detects the marker instead of the derivation
  from `op`, and `value_base` declares it directly, without deriving
  from `op`; regression test in
  `tests/sources/unit/src/static-asserts.cpp`.
  `values.h` lines 102 to 104, 127, and 362, `type-traits.h` line 188,
  `inlines/literals-inlines.h` line 618: `value_base` derives from the
  empty `op` struct, so the floating point specialisation of
  `value<T>`, which holds only the value and the tolerance, is a
  homogeneous floating-point aggregate with an empty base. GCC 10.1
  changed how AArch64 passes such types in C++17, and GCC emits a
  `-Wpsabi` note for each function template instantiation that passes
  or returns one by value. In the `qemu-aarch64-a72-cmake-gcc-debug`
  build (`aarch64-none-elf-g++` 15.2.1), `approx()` produced two notes,
  for `float` and `double`, each followed by a long instantiation
  trace; any user test that calls `approx()` gets them too. The note
  is informative only, since all the code is compiled by the same
  compiler, but it cannot be silenced locally: neither
  `#pragma GCC diagnostic ignored "-Wpsabi"` nor
  `[[gnu::always_inline]]` on `approx()` remove it. Avoid the empty
  base.

## 6. Incidental observations

- **#46 — Two macros differ from those used elsewhere.** [internal]
  (fixed)
  Fixed in `3de2002b` (#141): the build information tests
  `__cpp_exceptions` and `_WIN32`; the sample and unit tests, which
  also tested `__EXCEPTIONS`, test `__cpp_exceptions` too.
  `src/reporter.cpp` lines 328 to 341: the build information tests
  `__EXCEPTIONS` (GCC and clang only), while the rest of the library
  tests `__cpp_exceptions`, and `WIN32`, which compilers do not
  predefine (they define `_WIN32`).

- **#47 — The size format macro is used in one file only.** [internal]
  (fixed)
  Fixed in `0f623d56` (#142): the macro is defined unconditionally in
  `detail.h`, all the `size_t` formats of the library use it, and it
  is undefined at the end of `micro-test-plus.h`, to keep it out of the
  application code.
  `inlines/test-inlines.h` lines 79 to 85 and 520, `src/test.cpp` line
  93, and the `%zu` formats in `src/reporter-human.cpp` and
  `src/reporter-tap.cpp`: `MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE`
  exists for a Windows toolchain without `%zu`, but all the reporters
  use `%zu` directly. Either use the macro everywhere or remove it.

- **#48 — `initialise (argc, argv)` handles a second call twice.**
  [internal] (withdrawn)
  Withdrawn in `2ae68d6b` (#143); the branch is kept, with a comment
  explaining it.
  The observation is not correct: the branch does not repeat the check,
  it skips `parse_options()`, which reports the option errors on
  `stderr` and sets `has_option_errors_`, so that `run()` returns 2.
  Without the branch, a second call with an invalid option would report
  the error and change the exit code of the session already running.
  `src/runner.cpp` lines 163 to 166: the branch only forwards to the
  other `initialise()`, which performs the same check (line 196).
  Remove it.

- **#53 — The TAP output is not validated against TAP 14.**
  [internal] **[confirmed]** (fixed)
  Fixed in `025a723d` (#148): `tests/scripts/validate-tap.mjs` is run
  as a `<name>-validate` ctest test for each of the 20 TAP files written
  by the CMake build of the synthetic-posix platform, next to its
  compare test; all pass, and a copy of `unit-test.tap` with a stray
  line is rejected. The meson build does not compare the outputs, so
  it does not validate them either.
  `tests/scripts/compare-files.sh`, `tests/cmake/common-functions.cmake`
  lines 226 to 249: the TAP files written by the tests are compared
  with the reference outputs in `tests/assets/tap/`, but nothing checks
  that either is valid TAP 14, so a structural mistake (a wrong plan, a
  mis-indented line, a malformed YAML block) is copied into the
  reference files when they are regenerated, and passes unnoticed. Perl
  `TAP::Parser` 3.43 (`prove`, installed with macOS) cannot be used: it
  stops with `TAP specified version 14 but we don't know about versions
  later than 13`, and does not understand the indented subtests. The
  `tap-parser` 18.3.4 command (the node-tap parser) cannot be used as
  it is either, since its exit code tells whether the tests passed, and
  `unit-test.tap` has 356 intentional failures. A short Node script
  using `tap-parser` in strict mode, which follows every subtest parser
  and fails only on the parser errors (`tapError`) and the non-TAP
  lines, accepts all the ten reference files, and rejects copies of
  `unit-test.tap` with a stray line, a wrong subtest plan, a
  mis-indented test point, a duplicate test number, no top-level plan,
  an invalid YAML value, an unterminated YAML block, and a mis-indented
  YAML key; it accepts `TAP version 15`, which a check of the `version`
  event rejects. Since TAP 14 does not standardise the diagnostics
  fields, such a validator cannot confirm the field names of #52, only
  that the structure stays valid. Add `tap-parser` to the npm
  `devDependencies` in `tests/package.json`, and the script as
  `tests/scripts/validate-tap.mjs`; run it either once over the
  reference files (sufficient, since `compare-files.sh` normalises only
  comment lines, hexadecimal values, timings, and line numbers, none of
  which affect the structure), or as a ctest test for each generated
  file, next to `add_compare_files_test()`; only the synthetic-posix
  platforms write TAP files. Handle it after #52.

## 7. Reviewed and found sound

- All 20 public headers compile on their own.
- Stored check results: a result kept in a variable reports its own
  expression, even when other checks run meanwhile (probe).
- Nesting: a failure in a nested test case fails its parent, the suite,
  and the totals, and checks after a nested test case are reported
  (probe).
- Name lookup: user functions named `get()` and `abs()` do not change
  the results of the comparisons (probe); the generic calls inside the
  templates are qualified.
- C strings and character arrays are compared by content, up to the
  terminator, with a defined order for null pointers (`detail.h` lines
  983 to 1125).
- Integer literals: the octal, hexadecimal, and binary prefixes, the
  digit separators, and the range of the target type are checked at
  compile time, also for the negated values (#13).
- Exceptions in test case bodies are reported as failures, with their
  `what()` text, and the run continues.
- `run()` runs the suites once; a second call returns the same exit
  code.
- The runner can be configured without a command line
  (`initialise (const runner_options&)`), and the command line is
  parsed in a single function.
- The deprecated entities (`runner (const char*)`, `exit_code()`,
  `assume()`, `static_runner`) carry `[[deprecated]]`.
- The static suites list has a `constinit` head, so static suites may be
  constructed before their runner.
- The fixed-size buffers in the reporters hold only numbers and
  constant text; names are written directly, so nothing is truncated.
- Copy and move operations are deleted consistently on the classes
  that hold references or identity.
