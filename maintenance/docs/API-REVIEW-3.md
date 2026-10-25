# C++ API review

Date: 2026-10-23, on branch `xpack-development`, commit `1e491028`.

Scope: the umbrella header `include/micro-os-plus/micro-test-plus.h`,
the 21 public headers in `include/micro-os-plus/micro-test-plus/`,
the 17 inline headers in `include/micro-os-plus/micro-test-plus/inlines/`,
and the 11 source files in `src/`. The Doxygen comments were ignored.

Method: the comments were stripped with
`.github/skills/api-review/scripts/strip-comments.mjs` (50 files, 7988
lines of code, original line numbers kept) and every stripped file was
read in full. The sample and unit test programs in `tests/sources/`
were read for the intended use. The headers were checked for
self-containment (`check-headers.mjs`, Apple Clang 17), the formatting
with `clang-format --dry-run --Werror`, and the generated `CMakeLists.txt`
and `meson.build` against `xpm run xcdl-export`. Sixteen probe programs
were built against the library sources with Apple Clang 17.0.0
(`-std=c++20 -Wall -Wextra -Wpedantic`), with
`-fsanitize=address,undefined`, with `-fno-exceptions -fno-rtti`, and
with `-Weverything`; the TAP outputs were validated with
`tests/scripts/validate-tap.mjs`. No native GCC is installed on the
review machine, so GCC was used only through the cross compiler
`arm-none-eabi-g++` 15.2.1 (Cortex-M4, `-Os -fno-exceptions -fno-rtti
-Wframe-larger-than=512 -fstack-usage`). No program size was measured,
and no claim about size is made.

Independence: the earlier reports in `maintenance/docs/`, and the
commits and issues that refer to them, were deliberately not
consulted.

Summary: 32 problems (32 open, 0 fixed, 0 withdrawn).

The most serious are the defects that make a check pass when it
should fail, or fail when it should pass:

- the default tolerance of the floating-point wrappers and literals
  (#1);
- the comparison of arrays by address (#2);
- `expect()` accepting a string literal or a function name (#3);
- the overloaded `and`/`or`, which evaluate both sides (#4);
- the mutable counters, through which a test case can erase its own
  failures (#6).

The output defects come next: the TAP console output is invalid at
the default verbosity (#7); quiet mode hides the failed checks (#8);
the human output file depends on the console verbosity (#9); and
command-line errors do not reach the outputs (#10, #11).

Suggested order of work:

1. The non-breaking defects: #5, #12, #14, and #15, which are local
   fixes, then #7, #8, #9, #10, #11, and #16, best done together with
   the refactoring of the output policy in #25.
2. The non-breaking clean-ups: #19, #26, #28, #29, #30, #31, and #32.
3. The breaking changes, grouped for one major release: #2, #3, #6,
   #17, #20, and #21.
4. The deprecated definitions, last, since they need no separate work:
   #1, #4, #13, #18, #22, #23, #27, and #24. The first seven concern
   the overloaded operators, the literals, and the type wrappers, which
   are deprecated since 5.1.0 (#166); their defects disappear when
   these are removed in a future major release, so none of them needs
   a fix of its own. #24 is the removal of the members that were
   deprecated earlier, in the same release.

Tags:

- **[breaking]**: the suggested change alters the public API or the
  observable behaviour of correct user code;
- **[internal]**: the suggested change does not alter the public API;
- **[confirmed]**: a probe program reproduced the problem; items
  without this tag are derived from reading the code.

## 1. Defects

- **#1 — The default floating-point tolerance is erratic and
  asymmetric.** [breaking] **[confirmed]**
  `values.h` lines 459 to 515, `inlines/math-inlines.h` lines 297 to
  377, `values.h` line 375, and `inlines/detail-inlines.h` lines 368
  to 403: `to_f`, `to_d`, and `to_ld` give the wrapped value a
  tolerance of one unit of its last decimal digit
  (`decimal_epsilon()`), and the `_f`, `_d`, and `_ld` literals one
  unit of their last written digit. All six relations then treat the
  operands as equal when they differ by less than that. The probe
  results:
  - `to_d (0.5) == 0.45` passes, but `to_d (0.45) == 0.5` fails: the
    result depends on which operand is wrapped;
  - `to_d (0.3) == 0.21` passes (a difference of 0.09);
  - every whole number gets a tolerance of 0.1, because
    `count_decimals()` always counts at least one decimal:
    `to_d (3.0) == 3.09` and `to_d (1000000.0) == 1000000.09` pass,
    while `to_d (0.0)` gets no tolerance at all;
  - `to_d (1.0 / 3)` gets a tolerance of `1e-17`, below one unit in
    the last place, so a value that differs by one rounding fails;
  - `1.5_d == 1.41` passes, `1.50_d == 1.41` fails, and
    `1.5_d == 1.41_d` fails (two literals are compared exactly through
    `has_value`); `5._d == 5.9` passes (a tolerance of 1);
  - `to_d (1.5) > 1.41` and `to_d (1.5) != 1.41` fail, with the
    messages `1.5 > 1.41` and `1.5 != 1.41`; the tolerance is not
    shown anywhere (`inlines/expression-formatter-inlines.h` lines
    267 to 274).

  Suggested change, with options for the maintainer:
  (a) compare the wrappers exactly by default, and apply a tolerance
  only when the user asks for it, with `approx()` or a two-argument
  wrapper; (b) keep an implicit tolerance, but make it a small
  relative one based on `std::numeric_limits<T>::epsilon()`, symmetric
  in the two operands; (c) keep the digit-based tolerance of the
  literals, but make it half a unit of the last written digit, so that
  only values that round to the literal compare equal. In all cases,
  print the tolerance in the failure message when one was applied
  (for example `1.5 == 1.41 (+/- 0.1)`). Migration: none is possible
  through deprecation, since the syntax does not change; the release
  notes should say that the floating-point wrappers and literals no
  longer compare equal to values that differ in the last decimal, and
  that `approx()` must be used where a tolerance is intended.

  Status: deprecated in `0b707ed6` (#166), not removed. The wrappers and
  literals that carry the tolerance are deprecated since 5.1.0; the
  digit-based tolerance itself is unchanged until they are removed.

- **#2 — `eq()` and the other comparators compare arrays by
  address.** [breaking] **[confirmed]**
  `inlines/detail-inlines.h` lines 983 to 1017: `as_operand()` turns
  `char` arrays and pointers into `c_string` and compares their
  content, but turns every other array into a pointer. The probe:
  `eq (a, b)` with two `std::uint8_t[3]` arrays of equal content
  fails with `0x7ff7b4cbb06c == 0x7ff7b4cbb068`; the same happens for
  `int` arrays, for `char8_t`, `char16_t`, `char32_t`, and `wchar_t`
  strings (`eq (u8, u8"abc")`, `eq (w, L"abc")`), and for the pointers
  to these character types. Comparing byte buffers is a common check
  on embedded targets, and the comparison of arrays with `==` is
  deprecated in C++20. Suggested change: compare two arrays element by
  element (`std::ranges::equal()` for `eq`/`ne`,
  `std::lexicographical_compare_three_way()` for the orderings) and
  print them as ranges; treat arrays and pointers of all character
  types as strings, through `std::basic_string_view` of the right
  character type; alternatively, reject arrays other than `char`
  arrays with a `static_assert` that names the alternative
  (`std::span`). Migration: the code that compiles today and compares
  addresses is almost certainly wrong; the release notes should say
  that arrays are now compared by content.

- **#3 — `expect()` and `require()` accept a string literal or a
  function name, and pass.** [breaking] **[confirmed]**
  `extension.h` lines 219 to 221: `checkable` accepts any type usable
  in `t ? true : false`, which includes arrays, pointers, and
  functions. The probe: `t.expect ("answer () == 42")`,
  `t.require ("must hold")`, and `t.expect (answer)` (a function name
  without the call) all pass, with no warning at
  `-Wall -Wextra -Wpedantic`. Writing the description instead of the
  condition is a plausible mistake, and it silently disables the
  check. Suggested change: exclude from `checkable` the arrays, the
  pointers to the character types, the functions, and the pointers to
  functions and members; keep the pointers to objects, or require an
  explicit `ne (p, nullptr)` for them (the maintainer decides).
  Migration: a constrained overload of `expect()` and `require()` for
  the excluded types, marked `[[deprecated]]` for one release, with a
  message that explains the mistake; the release notes should say that
  these arguments are no longer accepted.

- **#4 — The overloaded `and` and `or` evaluate both operands.**
  [breaking] **[confirmed]**
  `operators.h` lines 257 to 280, `inlines/detail-inlines.h` lines
  511 to 537: once `using namespace mt::operators` is in effect, an
  expression such as `p != nullptr and p->x == 1_i` calls the
  overloaded `operator and`, whose arguments are both evaluated before
  the call. The probe crashes with a null pointer dereference
  (AddressSanitizer: `SEGV ... detail-inlines.h:400`). The idiom is
  correct C++ without the library, so the user has no reason to
  suspect it. Suggested change, with options: (a) remove the `and`,
  `or`, and `not` operators and keep `both()`, `either()`, and
  `negate()`, whose function-call syntax makes the eager evaluation
  visible; (b) keep them, and state the limitation prominently in the
  user manual. Migration for (a): mark the three operators
  `[[deprecated ("use both()/either()/negate()")]]` for one release.

  Status: deprecated in `0b707ed6` (#166), not removed. The overloaded `and`,
  `or`, and `not` operators are deprecated since 5.1.0 (they are removed
  together with the operators). The definitions moved to `deprecated.h` in
  `1b55e954` (#169). The functions `both()` and `either()`, recommended
  above, were renamed `all_of()` and `any_of()`, and made variadic, in
  `e7f7d5f7` (#168).

- **#5 — A `static_suite` constructed during or after `run()` is
  silently skipped, and still counted.** [internal] **[confirmed]**
  `inlines/test-inlines.h` lines 820 and 851, `src/runner.cpp` lines
  554 to 577, 604 to 637, and 865 to 878: the `static_suite`
  constructors call `link()` directly, so they bypass the check in
  `register_suite()` that rejects `add_suite()` after `run()` has
  started. The probes:
  - constructed inside a suite body during `run()`, a suite whose name
    sorts after the running suite is run, but one whose name sorts
    before it is never run; it is still counted by
    `static_suites_count()`, so the human total says "5 test suites"
    while four ran, and the TAP plan is `1..5` with four test points;
  - constructed after `run()` has returned, the suite is ignored
    without a message, a second `run()` still returns 0, and
    `total_suites_count()` reports 2.

  Suggested change: route the registration of `static_suite` through
  the same check as `add_suite()`, keyed on the state of its runner
  (reject, report on `stderr` and through the reporter, and make the
  exit code non-zero), and compute the plan from the suites actually
  reported.

  Status: fixed. The `static_suite` constructors call
  `runner::link_static_suite()`, which rejects the suite (as
  `add_suite()` does, with `runner::reject_suite()`) if the runner has
  started. A static suite may be constructed before its runner, so the
  runner is not accessed; the started runners are kept in a
  constant-initialised list, searched by address. The plan then follows
  from the suites actually linked.

- **#6 — A test case or a suite can overwrite its own counters.**
  [breaking] **[confirmed]**
  `test.h` lines 391 to 411, `inlines/test-inlines.h` lines 160 to
  174, `counters.h` lines 190 to 277: `runnable_base` is a public
  base of `test_case` and `suite`, and its non-const `totals()` is
  public, so `t.totals ()` returns a mutable `counters&` whose
  `increment_*()` functions and assignment operators are public. The
  probe: `t.expect (false); t.totals () = mt::counters{};` reports the
  test case as "passed (0 checks)", and the failure disappears from
  all the totals. Suggested change: make the non-const `totals()`
  private, reachable by the framework through the existing friends;
  `counters` can then stay a public value type, since the user only
  sees copies or const references. Migration: mark the non-const
  overload `[[deprecated]]` for one release; reading code then selects
  the const overload and keeps compiling.

- **#7 — The TAP output on the console is invalid at the normal
  verbosity.** [internal] **[confirmed]**
  `src/reporter-tap.cpp` lines 666 to 678 and 745 to 756,
  `inlines/test-inlines.h` line 221: the checks and the nested test
  cases of a test case share one test point counter. At the normal
  verbosity (the default), the console omits the passed checks and
  prints a plan that counts only the nested test cases, but keeps the
  shared numbers. A test case with two checks before a nested test
  case prints `ok 3 - inner` under the plan `1..1`, which the
  validator rejects ("id greater than plan end"). In addition, every
  passed test case without nested test cases gets the plan `1..0`,
  which is how TAP marks a skipped set of tests. The output file is
  valid at every verbosity. Suggested change: at the normal
  verbosity, either print a passed test case as a single test point
  without its `# Subtest` block, or print its block complete (as in
  the file); do not renumber.

  Status: fixed (#174). At the normal verbosity, a passed test case with
  nothing displayed under it is a single `ok` test point, and a failed
  test case, or one with a nested test case, is a complete block: its
  heading is displayed lazily, with those of its outer test cases, and
  its buffered checks are displayed, so that the plan counts the
  displayed test points, with their original numbers. The console
  output of all the test programs, at the three verbosity levels, is
  accepted by `validate-tap.mjs`. The output file is unchanged.

- **#8 — Quiet mode does not show which checks failed.** [internal]
  **[confirmed]**
  `src/reporter-tap.cpp` lines 456 to 463 and 633 to 664,
  `src/reporter-human.cpp` lines 254 and 432: with `--quiet`, the TAP
  console shows only `not ok 1 - p04 # { FAILED, ... }` for the whole
  suite, and the human console shows only the final total; neither
  shows the failed check, its location, or its expression. Quiet mode
  is useful precisely when the failures are what the user wants to
  see. Suggested change: in quiet mode, omit the passed checks and the
  passed test cases, but print the failed checks with the names of the
  enclosing test cases (the human reporter already has
  `display_open_names()` for this).

  Status: fixed (#174). With `--quiet`, the console displays the failed checks
  and the totals. The human reporter writes the headings of the suite
  and of the enclosing test cases, then the failed checks. The TAP
  reporter keeps the console a valid document, with the suites as single
  test points, and writes the failed checks as comments, after a comment
  line with the names of the suite and of the test cases. The lines of
  the failed checks are kept apart from the buffer, which also holds the
  passed checks for the output file.

- **#9 — The human output file depends on the console verbosity.**
  [internal] **[confirmed]**
  `src/reporter-human.cpp` lines 165, 254 to 295, 432 to 491, 526 to
  530, and 794 to 797: the human reporter writes to the file only
  under the same conditions as to the console, and
  `writes_passed_checks()` ignores the output file (the TAP reporter
  considers it, `src/reporter-tap.cpp` lines 722 to 727). The probes:
  with `--silent --output-file=...`, the file contains the test case
  names and nothing else, with no results and no totals; with
  `--quiet`, it contains the names and the total, but not the failed
  check. Suggested change: decide the content of the file
  independently of the console (all the results, as in normal or
  verbose mode), as the TAP reporter does.

  Status: fixed (#174). The human reporter writes all the records to the file,
  as the TAP reporter does, whatever the console verbosity; the file of
  a quiet or silent run is the same as that of the default run, so the
  tests compare them with the same reference file, and the references
  of the quiet and silent runs were removed.

- **#10 — Command-line errors do not reach the outputs.** [internal]
  **[confirmed]**
  `src/runner.cpp` lines 353 to 402 and 437 to 440, and lines 248 to
  260: `parse_options()` reports errors only on `stderr`, before the
  reporter exists, and the run continues. The probe:
  `--reporter=junit --output-file=p07.tap` prints the error on
  `stderr`, then writes a complete, valid, all-passing TAP file, and
  exits with 2. A tool that reads the file, or the TAP console output,
  sees success. Suggested change: keep the errors in the runner and
  emit them through the reporter in `begin_session()` (a TAP
  `Bail out!` or a comment line, and a human error line), so that
  they reach the console and the file alike.

  Status: fixed. An unknown reporter name stops the session in
  `initialise()`: no output file is created, nothing is reported, no
  test is run, and `run()` returns 2. The other command-line errors are
  kept by the runner and written by `begin_session()` as comment lines
  (`# error: ...` in TAP), to the console and to the output file, as
  well as on `stderr`.

- **#11 — Mistyped options, and filters that match nothing, end in
  success.** [internal] **[confirmed]**
  `src/runner.cpp` lines 404 to 470 and 725 to 732: the option loop
  has no final `else`, so an unknown option is ignored; and the exit
  code does not consider the number of executed test cases. The
  probes: `--verbos --filtr=x` runs everything and exits with 0;
  `--filter=nothing` runs no test case and exits with 0. A typing
  mistake in a CI script then disables the tests without a trace.
  Suggested change: report the unknown options that start with `--`
  as errors (exit code 2, as for the other option errors), leaving
  the other arguments to the application; and report a run in which
  the filters selected no test case as an error.

  Status: fixed. The unknown options that start with `--` are reported
  as errors (exit code 2); the other arguments are left to the
  application. A run with filters that executed no test case is
  reported as an error, with exit code 2. The unit tests were updated.

- **#12 — `range_element` fails hard on types with non-iterator
  `begin()` and `end()`.** [internal] **[confirmed]**
  `extension.h` lines 273 to 276, 332 to 345, and 393 to 398:
  `container_like` accepts any type with `begin()` and `end()`
  members, and the specialisation of `range_element` then forms
  `*begin()` in its body, outside the immediate context, so a void
  return is a hard error, not a failed constraint. The probe: a user
  type with `void begin() const` and `void end() const` (a
  transaction) and its own `operator<<` cannot be used in `eq()`; the
  error starts at `extension.h:344:21`, reached from `printable` and
  `formattable_range`. Suggested change: require
  `std::input_or_output_iterator` (or a dereferenceable result) in
  `container_like`, or check the element type inside the concept
  (`requires { typename range_element<T>::type; }` with a SFINAE-safe
  `range_element`).

  Status: fixed. `container_like` and `free_range` require
  `begin()` to return a `std::input_or_output_iterator` and `end()` a
  `std::sentinel_for` it, so such a type is not a range and the
  `range_element` specialisations are not selected. Static asserts for
  a type with `void` `begin()` and `end()` were added to
  `unit-static-asserts`.

- **#13 — Mixing a `float` and a `double` tolerance does not
  compile.** [internal] **[confirmed]**
  `inlines/detail-inlines.h` lines 223 to 228, `math.h` lines 133 to
  135: when both operands have an epsilon, `within_tolerance()` calls
  `math::min_value (lhs.epsilon, rhs.epsilon)`, which takes two
  arguments of the same type. `to_f (1.0f) == to_d (1.0)` and
  `1.5_f == to_d (1.5)` fail with "no matching function for call to
  'min_value'". Suggested change: convert both epsilons to their
  common type before taking the minimum.

  Status: deprecated in `0b707ed6` (#166), not removed. The `to_f`/`to_d`
  wrappers are deprecated since 5.1.0; the defect remains until they are
  removed.

- **#14 — A null test case or suite name crashes.** [internal]
  **[confirmed]**
  `inlines/test-inlines.h` lines 100 to 104 and 576 to 591,
  `src/test.cpp` lines 499 to 515: the names are stored as given and
  later passed to `strlen()`, `strcmp()`, `std::string_view`, and
  `printf ("%s")`. The probe `ts.test (name, ...)` with a null `name`
  stops with a SEGV in `strlen`. The operands of the checks handle
  null C strings (`c_string`), so the names are the exception.
  Suggested change: store `""` (or a fixed placeholder) for a null
  name in `test_case_name`, `suite`, and `static_suite`.

  Status: fixed. `test_case_name` and the two `static_suite`
  constructors store or pass `""` for a null `const char*`. The
  `suite` and `runner::add_suite()` parameters are `std::string_view`,
  so a null `const char*` is converted at the call, before the library
  is entered; it cannot be intercepted there.

- **#15 — Strings in failure messages are not quoted, and NUL and
  newline characters reach the console raw.** [internal]
  **[confirmed]**
  `src/expression-formatter.cpp` lines 117 to 122 and 210 to 241,
  compared with lines 136 to 147: characters are quoted and escaped
  (`'a'`, `'\n'`), but strings are appended as they are. The probes:
  `eq (std::string (""), std::string (" "))` fails with `( ==  )`,
  which does not show the operands; a string with an embedded `'\0'`
  writes a NUL byte to the console; and a newline in an operand breaks
  the human report across lines. The TAP YAML block escapes them
  correctly. Suggested change: print the string operands in double
  quotes, with the same escapes as the characters, in the expression
  (not in the user messages, which stay plain).

  Status: fixed. The `std::string_view` and `c_string` overloads of
  `expression_formatter` write the string between double quotes, with
  the escapes of the character literals (`\0`, `\n`, `\"`, `\\`, and
  `\xNN` for the other control characters); the bytes above `0x7F` are
  kept, so that UTF-8 text stays readable. The plain mode of the
  messages and the null pointers (`nullptr`) are unchanged. The type
  name in `throws<T>` is appended directly, so it is not quoted. The
  reference files in `tests/assets` were updated.

- **#16 — At the normal verbosity, a passed nested test case is
  printed without its parent.** [internal] **[confirmed]**
  `src/reporter-human.cpp` lines 446 to 463: the probe prints
  `✓ inner - passed (1 check)` indented under the suite heading,
  before any line that names its parent test case `outer`, whose
  result line comes next. A reader sees an indented result under an
  unseen heading. Suggested change: at the normal verbosity, either
  omit the passed nested test cases (they are already counted in the
  parent), or print the open parent names first, as
  `display_open_names()` does for failures.

  Status: fixed (#174). At the normal verbosity, the names of the outer test
  cases that were not displayed yet are written before the line of a
  passed nested test case (and of a skipped one).

## 2. Structure and layering

- **#17 — Suites run in alphabetical order, not in the order in
  which they are added.** [breaking] **[confirmed]**
  `src/test.cpp` lines 499 to 515, `src/runner.cpp` lines 554 to 577
  and 604 to 637: `add_suite()` links the new suite into the same
  name-sorted list as the `static_suite` objects, and `run()` follows
  that list. The probe adds "Zeta (added first)" and then
  "Alpha (added second)"; Alpha runs first. Sorting is a reasonable
  way to make the static initialisation order deterministic, but for
  `add_suite()` the user already chose the order explicitly, and
  nothing in the name says that it is ignored. Suggested change: run
  the added suites in insertion order (they are already kept in
  `children_suites_`), and keep the sorting for the `static_suite`
  objects only; or keep the current policy and make it visible in the
  user manual. Migration: the release notes should say that the
  suites added with `add_suite()` now run in the order of the calls.

- **#18 — The comparators and the operators constrain their operands
  differently.** [internal] **[confirmed]**
  `function-comparators.h` lines 120 to 206, `operators.h` lines 143
  to 296: `eq()` and the other comparators require both operands to
  be `printable`, so an unsupported type is rejected at the call;
  the operators require only `any_op`, so the same type is accepted
  and fails inside the formatter
  (`inlines/expression-formatter-inlines.h:272`, "invalid operands to
  binary expression ('expression_formatter' and 'const measurement')").
  The operators also skip `as_operand()`, so they treat C strings and
  arrays differently from the comparators. Suggested change: give the
  operators the same `printable` constraint, and pass their operands
  through `as_operand()`, so that both forms accept the same types and
  compare them the same way.

  Status: deprecated in `0b707ed6` (#166), not removed. The operators are
  deprecated since 5.1.0; the difference disappears when they are removed.
  The definitions moved to `deprecated.h` in `1b55e954` (#169).

- **#19 — `std::chrono` durations can be neither printed nor
  compared.** [internal] **[confirmed]**
  `expression-formatter.h` lines 287 to 829: there is no overload for
  `std::chrono::duration`, so `eq (5ms, 6ms)` is rejected, and
  `to_t<std::chrono::milliseconds> (5ms) == 5ms` fails inside the
  formatter. Durations are common in embedded tests (timeouts,
  periods). Suggested change: add a formatter overload that prints the
  count followed by the unit (`5ms`, `250us`, `2s`, or the ratio for
  the other periods).

  Status: fixed in #176, commit `a2b16cc5`, on 2026-10-25. A new
  `expression_formatter::operator<<` overload
  writes the count, without a type suffix, followed by `ns`, `us`,
  `ms`, `s`, `min`, or `h`, or, for the other periods, `[N/D]s`. The
  comparators and `expect()` accept durations; the checks added to
  `unit-checks` and the reference outputs updated.

- **#20 — Classes that are not designed for derivation are not
  `final`.** [breaking]
  `test.h` lines 1007 to 1364 (`test_case`, which has a private
  constructor and protected members), 1783 to 1855 (`top_suite`), and
  1921 to 2037 (`static_suite`), `stopwatch.h` lines 140 to 423
  (`stopwatch`, with protected members): nothing derives from these
  classes, and a user class derived from `static_suite` would be
  registered with the base's behaviour only. Suggested change: mark
  `test_case`, `top_suite`, `static_suite`, and `detail::stopwatch`
  `final`, and make their protected members private. Migration: none
  is needed for `test_case` and `top_suite` (they cannot be
  constructed by a derived class); for `static_suite`, the release
  notes should say that it is now `final`.

- **#21 — `utility::split()` is not used by the library, and does not
  deduce its arguments.** [breaking] **[confirmed]**
  `utility.h` lines 121 to 123, `inlines/utility-inlines.h` lines 89
  to 109: the declaration has no default for `T`, the definition adds
  `T = std::string_view`, but `T` is always deduced from the first
  argument, so the default never applies; `split ("a.b", ".")` does
  not compile (`std::size` and `find_first_of` on `const char*`). Only
  the unit tests call it, with an explicit `<std::string_view>`, and
  it returns a `std::vector` (heap). Suggested change: remove it from
  the public `utility` namespace, or give it the signature
  `split (std::string_view input, std::string_view delimiters)
  -> std::vector<std::string_view>`. Migration: `[[deprecated]]` for
  one release.

## 3. Naming and consistency

- **#22 — `approx()` has two unrelated meanings.** [breaking]
  `literals.h` lines 808 to 812, `function-comparators.h` lines 243
  to 247: the two-argument `approx (value, epsilon)` returns a
  wrapper (`detail::value<T>`, a `detail` type in a public signature)
  to be compared with an operator, while the three-argument
  `approx (lhs, rhs, epsilon)` is itself a comparison. The first is
  declared with the literals, the second with the comparators. The
  same name for a value and for a check is confusing in the reports
  and in the documentation. Suggested change: keep `approx (lhs, rhs,
  epsilon)` as the comparator and rename the wrapper (for example
  `to_d (value, epsilon)`, overloads of the existing wrappers, or
  `within (value, epsilon)`). Migration: keep the two-argument
  `approx()` as a `[[deprecated]]` alias for one release.

  Status: deprecated in `0b707ed6` (#166), not removed. The two-argument
  `approx (value, epsilon)` is deprecated since 5.1.0, in favour of `approx
  (lhs, rhs, epsilon)`. The definitions moved to `deprecated.h` in `1b55e954`
  (#169).

- **#23 — The `_b` literal does not match `to_b`.** [breaking]
  `literals.h` lines 437 to 438 and 488: every other literal has a
  wrapper of the same type, but `"..."_b` is a named condition that is
  always true (`detail::named_bool`), while `to_b` wraps a `bool`
  value. The consistency table:

  | type              | literal          | wrapper               |
  | ----------------- | ---------------- | --------------------- |
  | `bool`            | (none)           | `to_b`                |
  | named condition   | `"..."_b`        | (none)                |
  | `char`            | `_c`             | `to_c`                |
  | `signed char`     | `_sc`            | `to_sc`               |
  | `short`           | `_s`             | `to_s`                |
  | `int`             | `_i`             | `to_i`                |
  | `long`            | `_l`             | `to_l`                |
  | `long long`       | `_ll`            | `to_ll`               |
  | unsigned types    | `_u` ... `_ull`  | `to_u` ... `to_ull`   |
  | fixed-width types | `_i8` ... `_u64` | `to_i8` ... `to_u64`  |
  | floating types    | `_f` `_d` `_ld`  | `to_f` `to_d` `to_ld` |
  | any type          | (none)           | `to_t<T>`             |

  The `_s` suffix is also read as "string" by many users, where it
  means `short` here. Suggested change: rename the named condition to
  a suffix that does not suggest `bool` (for example `_name` or
  `_cond`), keeping `_b` as a deprecated alias for one release; the
  `_s` suffix can stay, since it matches `to_s`.

  Status: deprecated in `0b707ed6` (#166), not removed. The `_b` literal and
  `to_b` are deprecated since 5.1.0. The definitions moved to `deprecated.h`
  in `1b55e954` (#169).

- **#24 — Deprecated members named after types force qualified names
  in the declarations.** [breaking]
  `runner.h` lines 288, 316, 426 to 429, 539 to 540, 575 to 576, 722
  to 724, and 846: the deprecated `runner::suite()`,
  `runner::verbosity()`, and `runner::reporter()` hide the types of
  the same names, so the declarations need `class suite&`,
  `class top_suite`, `micro_test_plus::verbosity`, and trailing return
  types. Suggested change: remove these members in the next major
  release, then drop the elaborated and qualified names.

## 4. Simplicity and duplication

- **#25 — The output policy is repeated in every reporter callback.**
  [internal]
  `src/reporter-tap.cpp` and `src/reporter-human.cpp` test the
  verbosity 25 and 21 times; each callback computes `to_console`
  itself, decides separately whether the buffer goes to the file, and
  manages `add_empty_line_`. The defects #7, #8, #9, and #16 are all
  inconsistencies between these copies. Suggested change: decide, in
  one function of the base class, what each kind of record (passed
  check, failed check, test case result, suite result, total) writes
  to the console and to the file at each verbosity, and let the
  callbacks only format the records. Fix #7, #8, #9, and #16 on top of
  it.

  Status: fixed (#174). The base class decides where each kind of record goes
  (`reporter::route()` with `record_kind`, and `console_lines()` for the
  buffered lines), and the callbacks of the two reporters only format
  the records and ask. The defects #7, #8, #9, and #16 were fixed on top
  of it. The open test cases are tracked by the base class, for both
  reporters. The console output with the normal and quiet verbosity is
  covered by four new tests of `unit-checks-test`, which compare the
  captured console with reference files.

- **#26 — `test_each()` copies each value and the callable.**
  [internal] **[confirmed]**
  `inlines/test-inlines.h` lines 675 to 717 and 248 to 264: each
  element is passed to `test()` as an extra argument, which
  `bind_callable()` decays and stores by value, together with a copy
  of the callable. The probe counts three value copies and three
  callable copies for three values, and a `std::vector` of
  `std::unique_ptr` does not compile. Suggested change: bind the
  element by reference (`std::cref`, or a dedicated bound callable
  that stores a pointer), and the callable by reference, since both
  outlive the synchronous call.

## 5. Modern C++

- **#27 — A positive integer literal one past the maximum gives an
  unclear error.** [internal] **[confirmed]**
  `values.h` lines 280 to 294, `inlines/values-inlines.h` lines 173
  to 189: `2147483648_i` returns `integral_min_magnitude<int>`, which
  only supports unary minus, so `2147483648_i == 0` fails with
  `invalid operands to binary expression
  ('integral_min_magnitude<int>' and 'int')`. The other out-of-range
  literals get a clear `static_assert`. Suggested change: give
  `integral_min_magnitude` a constrained conversion or comparison that
  fails with a `static_assert` stating that the value does not fit in
  the type of the literal.

  Status: deprecated in `0b707ed6` (#166), not removed. The literals are
  deprecated since 5.1.0; the error message is unchanged until they are
  removed.

## 6. Suitability for embedded targets

- **#28 — The passed checks are formatted at the normal verbosity,
  and usually discarded.** [internal]
  `src/reporter-tap.cpp` lines 722 to 727, `src/reporter-human.cpp`
  lines 526 to 530, `inlines/check-result-inlines.h` lines 126 to
  137, `src/reporter-tap.cpp` lines 776 to 778: at the normal
  verbosity (the default), `writes_passed_checks()` is true, so every
  passed check formats its expression and is written to the buffer
  (and, in TAP, copied once more by `tap_text()`); the buffer is shown
  only when the test case fails. This keeps the context of a failure,
  which is useful, but costs formatting time and heap growth on every
  passed check. Derived from reading; not measured. Suggested
  change, for the maintainer to weigh: format the passed checks only
  in verbose mode or with an output file, and show only the failed
  checks (with the names of the open test cases) at the normal
  verbosity; or keep the current behaviour and state the trade-off.

## 7. Incidental observations

- **#29 — `uncaught_exceptions_` is unused without exceptions.**
  [internal] **[confirmed]**
  `check-result.h` line 370: with `-fno-exceptions`, Clang warns
  `private field 'uncaught_exceptions_' is not used`
  (`-Wunused-private-field`, part of `-Wall`), and every
  `check_result` carries the unused member. Suggested change: declare
  it under `#if defined(__cpp_exceptions)`.

- **#30 — Three lines exceed 80 characters.** [internal]
  `micro-test-plus.h` line 61 (85), `inlines/detail-inlines.h` line
  790 (109), and `src/reporter.cpp` line 448 (93): all are comments
  after `#endif` that repeat a long condition. Suggested change:
  shorten the comments (for example `// long double formatting`).

- **#31 — Comments on concepts produce `-Wdocumentation` warnings in
  user code.** [internal] **[confirmed]**
  With `-Weverything`, a user translation unit that includes the
  umbrella header gets warnings such as `'@tparam' command used in a
  comment that is not attached to a template declaration` from
  `extension.h` lines 181 to 431 and `test.h` lines 142, 919, 936,
  1875, and 1876 (Clang does not attach these comments to concepts).
  Apart from these and #29, `-Weverything` reports nothing in the
  library. Suggested change: refer to the `doxygen-review` skill, or
  wrap the concept declarations in a `-Wdocumentation` pragma.

- **#32 — Non-finite values get the type suffix.** [internal]
  **[confirmed]**
  `src/expression-formatter.cpp` lines 427 to 467: `INFINITY` and a
  `float` NaN print as `inff` and `nanf`, and `long double` ones as
  `infld` and `nanld`, which read as misspellings. Suggested change:
  append the suffix only when the text is a number.

## 8. Reviewed and found sound

- All 21 public headers compile on their own; the formatting matches
  `maintenance/config/.clang-format`; the header guards follow the
  rule and are unique; the 11 source files are registered in
  `xcdl-package.jsonc`, and the generated `CMakeLists.txt` and
  `meson.build` list the same files (the committed `CMakeLists.txt`
  differs from the raw export only in its formatting).
- Two `check_result` objects alive at once (kept in variables, with
  messages added later) report the right expression and message each,
  through the pending list of the formatter.
- Lifetimes: test case names built from temporary strings, nested
  test cases, and stored check results run clean under AddressSanitizer
  and UndefinedBehaviorSanitizer.
- Exceptions: an exception in a test case body or in a suite body is
  reported as a failure, and the run continues; `throws<T>()` fails
  for other exception types and prints the type name without RTTI; a
  failed `require()` stops only its test case.
- Without exceptions, a failed `require()` aborts the run, with a
  visible "test execution aborted" message and the abort handler
  hook; given that C++ cannot unwind without exceptions, this is a
  deliberate and visible difference.
- The session functions handle the wrong call orders: `run()` before
  `initialise()`, `initialise()` twice, and `run()` twice report an
  error or return the stable exit code; `add_suite()` after `run()`
  is rejected and makes the exit code non-zero.
- Nesting: failures in nested test cases reach the parent, the suite,
  and the totals; checks before and after a nested test case are
  counted correctly; the file TAP output is valid at every verbosity.
- TAP escaping: `#`, `\`, newlines, and colons in suite names, test
  case names, and messages are escaped or replaced, and the YAML
  `condition` is a valid double-quoted scalar, including NUL and
  control characters.
- Every fundamental type (`bool`, all the character types, the
  integer types with their extreme values, the three floating-point
  types with full precision, `-0.0`, enumerations, `std::byte`,
  `std::nullptr_t`, `std::optional`, cv-qualified and function
  pointers) prints correctly in the expressions and in the messages.
- Integer literals: decimal, octal, hexadecimal, and binary prefixes,
  digit separators, the minimum values (`-2147483648_i`), and the
  rejection of decimal points, exponents, and out-of-range values.
  Unary minus keeps the type of the literal (`-5_u8` is 251), which
  differs from the built-in promotion to `int` but is consistent and
  arguably what the user of a typed literal means.
- `approx()` on integers computes the distance without overflow for
  any combination of signed and unsigned operands.
- The concepts `has_epsilon`, `has_value`, and the wrapper `get()`
  dispatch are gated by `is_op`, so user types with members named
  `value`, `epsilon`, `npos`, or `get()` are not affected (probe with
  such a type and its own `operator<<`).
- Name lookup: the generic names (`abs`, `pow`, `min_value`, `unwrap`,
  `get`) are qualified; the unqualified `begin()` and `end()` in
  `free_range` rely on argument-dependent lookup deliberately.
- Copy and move: all registered and referenced classes are neither
  copyable nor movable; `counters` is a copyable value type.
- Configuration without a command line: `runner_options` covers every
  command-line setting, so embedded targets need no `argv`.
- Include order and configuration: no type, default, or layout depends
  on the configuration macros; only `__cpp_exceptions` adds member
  function declarations. Derived from reading; not probed with two
  translation units.
- Cross build (GCC 15.2.1, Cortex-M4, `-Os -fno-exceptions -fno-rtti
  -Wdouble-promotion -Wframe-larger-than=512`): no warnings; the
  largest frame is 320 bytes (`reporter_tap::end_suite()`); there is
  no recursion, including in the literal parsing.
