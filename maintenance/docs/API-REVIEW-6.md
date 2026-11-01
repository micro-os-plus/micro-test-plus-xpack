# C++ API review

Date: 2026-10-31, on branch `xpack-development`, commit `87e3c16b`.

Scope: the umbrella header `include/micro-os-plus/micro-test-plus.h`, the
public headers in `include/micro-os-plus/micro-test-plus/`, their
`inlines/`, and `src/`. As requested, the deprecated definitions
(`deprecated.h`, `inlines/deprecated-inlines.h`, `src/deprecated.cpp`, and
the members guarded by `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED`)
were not reviewed; they are mentioned only where they leak into the
configuration without the deprecated functionality (#21). The Doxygen
comments were ignored, except by the newcomer exercise.

Method: the comments were stripped with
`.github/skills/api-review/scripts/strip-comments.mjs` (48 files, 9370
lines of code, original line numbers kept), and every non-deprecated file
was read in full, in the order given by the skill. The headers were
checked for self-containment (`check-headers.mjs`, 19 headers, none
failed) and for formatting (`clang-format --dry-run --Werror`, no
differences; no line longer than 80 characters; all header guards follow
the rule). The probes were built with Apple clang 17.0.0
(`-std=c++20 -Wall -Wextra -Wpedantic`), also with
`-fsanitize=address,undefined`, and with `-fno-exceptions -fno-rtti`; the
TAP outputs were checked with `tests/scripts/validate-tap.mjs`. No native
GCC works on this host, so the GCC checks used `arm-none-eabi-g++` 15.2.1
(Cortex-M4, `-fno-exceptions -fno-rtti -Wdouble-promotion -Wconversion
-Wsign-conversion -Wframe-larger-than=512 -fstack-usage`), compiling
only. The newcomer exercise was done by a fresh sub-agent, which read only
the user manual and the public declarations; its programs are in the
session scratchpad (`newcomer/t1.cpp` to `t7-suites.cpp`, and
`newcomer/mistakes/`), and the probes of this review in `probe/p1.cpp` to
`p8.cpp`.

Independence: the earlier reports in `maintenance/docs/`, and the commits
and issues that refer to them, were deliberately not consulted.

Summary: 44 problems (0 open, 33 fixed, 11 withdrawn).

The most serious are the lifetime defects #1 (a comparison returned by a
helper reports freed memory) and #2 (a kept `expect()` result is used
after its destruction), the invalid TAP output of #5, the stale output
file of #6, which can make a CI job read the results of an earlier run,
and the misleading reports of #7 (application types) and #4 (`throws()`
hides a failed `require()`).

Suggested order of work:

1. the defects: #1, #2, #5, #6, #7, #4, #3, then #9 and #10 (#8 was
   withdrawn);
2. the non-breaking improvements: the diagnostics (#11, #12, #13, #20),
   the reports (#14, #15), #25, #26, #21, #32, and the clean-ups #28 to
   #31;
3. for the next major release, the breaking changes: #2 (if not done
   earlier), #22, #23, #24, and #27;
4. the documentation items #35 to #44, through the `website-review` and
   `doxygen-review` skills.

Tags: **[breaking]** means that the suggested change alters the public
API; **[internal]** means that it does not; **[confirmed]** means that a
probe, or a newcomer program, reproduced the problem. Findings without
**[confirmed]** are derived from reading the code.

## 1. Defects

- **#1 — A comparison returned by a helper refers to the helper's
  locals.** [internal] **[confirmed]** (fixed)
  `detail.h` lines 225 to 229 (`stored_operand_t`), used by the deduction
  guides of `compare_op` (lines 889 to 893), `approx_op`, `and_op`,
  `or_op`, and `predicate_op`: an lvalue operand of class type is stored
  as a `const&`. The result is computed in the constructor, but the
  operands are read again later, when the check is formatted. A helper
  that builds the expected value locally and returns the comparison,
  the obvious way to reuse a check, returns references to destroyed
  objects:

  ```c++
  auto has_name (const std::string& actual)
  {
    std::string expected{ "a fairly long expected name, on the heap" };
    return mt::eq (actual, expected);
  }
  // t.expect (has_name (n));
  ```

  Probe `p1.cpp` (`P_HELPER`) prints freed heap memory as the right
  operand: `condition: "\"another fairly long ...\" ==
  \"\\x1f\\\\��\\x7f\\0\\0@\\x03..."`. The same happens with any
  stored expression whose operands go out of scope before the check.
  Possible changes, for the maintainer to choose:
  - store copies of all the operands (simple and safe; costs a copy of
    each container or string operand per check);
  - keep the references, but format the operands eagerly in the
    constructor when the result is `false`, so that the failure reports
    are always safe (the passing checks in verbose mode would still read
    the references);
  - keep the design, mark the parameters of the comparators with
    `[[clang::lifetimebound]]` where the compiler supports it, and
    document that the comparison objects must not outlive their
    operands.

  Fixed in `6fc1a779` (#229): the first option, with the classes that
  cannot be copied still stored as `const` references; the
  `[[clang::lifetimebound]]` option was not used, since only clang warns
  about it.

  Size of the first option, measured on `qemu-cortex-m33-cmake-gcc`
  (GCC 15.2.1, the `text` of the linked programs). With
  `compare-sizes.py` (v5.0.1 tests, `HEAD` compared with `HEAD` plus
  the change), all five programs are unchanged in both builds (a control
  run with no change gives the same zeros), since the v5.0.1 sources
  compare only scalars and temporaries. With the programs of the build
  folders (the same working-tree tests in both builds, only `include/`
  differing), `empty`, `minimal`, `sample`, and `suite` are unchanged,
  and `unit`, which compares named strings and containers, grows by 408
  bytes in the debug build (1151952 to 1152360, +0.04%) and by 1124
  bytes in the release build (563172 to 564296, +0.2%); `data` and
  `bss` do not change. The script needed changes to work at all (the
  deprecated macro, three more edits of the v5.0.1 test sources, the
  link of the `unit` program, and the display of the compiler errors),
  which are in `maintenance/scripts/size-comparison/`.

- **#2 — The result of `expect()` and `require()` dangles when it is
  kept.** [breaking] **[confirmed]** (fixed)
  `test.h` lines 1289 to 1295 and 1332 to 1338, `inlines/test-inlines.h`
  lines 478 to 512: the `check_result` is a defaulted argument
  (`detail::check_result&& result = detail::check_result{}`), and the
  function returns an rvalue reference to it. The temporary is destroyed
  at the end of the full expression, and no lifetime extension applies
  through the returned reference, so
  `auto&& r = t.expect (x); r << "message";` uses a destroyed object.
  Probe `p1.cpp` (`P_DANGLE`), with AddressSanitizer:
  `stack-use-after-scope ... in check_result::operator<<`. The check is
  also reported before the message is added. The suggested change was to
  return the result by value; it was not followed, since the guaranteed
  copy elision of C++17 would let `auto r = t.expect (...)` compile
  again, and the check would be reported at the end of the block, which
  the design of #222 prevents. The change made: `operator<<` and
  `value()` are rvalue-qualified, and `operator<<` returns an rvalue
  reference, so a bound result cannot be used.

  Fixed in `e9ad5539` (#230): as described above; the signatures of
  `expect()` and `require()` are unchanged, so the item is no longer
  [breaking] for code that does not use a bound result.

- **#3 — `approx()` fails for two equal infinities.** [internal]
  **[confirmed]** (fixed)
  `inlines/detail-inlines.h` lines 543 to 549: the floating-point branch
  of `differ_by_at_most()` computes `abs (lhs - rhs) <= epsilon`; for
  two infinities of the same sign the difference is NaN, so
  `approx (inf, inf, 0.1)` fails, while `eq (inf, inf)` passes. Probe
  `p1.cpp` (`P_INF`): `not ok 2 - approx inf`,
  `condition: "inf ~ (inf +/- 0.1)"`, and the same for `-inf`. Suggested
  change: return `true` when `lhs == rhs`, before computing the
  difference.

  Fixed in `78700952` (#235): the distance of two equal operands is taken as
  zero, and compared with the tolerance, so that a negative tolerance
  still fails, instead of returning `true` for equal operands.

- **#4 — `throws()` and `nothrow()` swallow a failed `require()`.**
  [internal] **[confirmed]** (fixed)
  `inlines/detail-inlines.h` lines 687 to 759: the callable is run
  inside `catch (...)`, which also catches `detail::failed_requirement`,
  the exception that stops the test case after a failed `require()`.
  Probe `p1.cpp` (`P_THROWS_REQ`):
  `✗ inner FAILED (p1.cpp:72) - test case stopped`, then
  `✓ outer throws`, and the test case continues; the report says the
  opposite of what happened, and `throws()` passes because of the
  framework's own exception. Suggested change: add
  `catch (const detail::failed_requirement&) { throw; }` before the
  other handlers of the three constructors.

  Fixed in `d0e3af3d` (#234): as suggested; the definition of
  `failed_requirement` moved to `detail.h`.

- **#5 — A check on an outer test case while a nested one runs produces
  invalid TAP.** [internal] **[confirmed]** (fixed)
  `inlines/test-inlines.h` lines 478 to 512 and `src/test.cpp` lines 244
  to 259: `expect()` and `require()` report to the test case object they
  are called on, even when another (nested) test case is running. A
  nested lambda that captures the outer `t` by reference, an easy
  mistake when the parameters have different names, writes a test point
  of the parent inside the subtest of the child. Probe `p3.cpp`: the
  validator reports `s > parent > child: no plan` and
  `s > parent > : incorrect number of tests`. The runner already knows
  the running test case (`running_test_case_`). Suggested change: when
  `this` is not the running test case, report a failure on the running
  one ("check on test case 'parent' while 'child' runs"), or attribute
  the check to the running one.

  Fixed in `a9e314a6` (#231): as suggested, the check is reported as a
  failure of the running test case, with a message that names the two
  test cases; the deprecated `expect()` and `require()` overloads were
  not changed.

- **#6 — After a command-line error, the output file of an earlier run
  is left in place.** [internal] **[confirmed]** (fixed)
  `src/runner.cpp` lines 273 to 319: with errors or `--help`, the
  reporter is created with `output_file_path` cleared (line 276), so the
  file named by `--output-file` is neither truncated nor written. Probe:
  a file containing `STALE CONTENT FROM AN EARLIER RUN`, then
  `p2 --output-file=stale.tap --bogus`; the exit code is 2, and the file
  still has the old content. A CI job that reads the file, and not the
  exit code, sees the results of the earlier run, possibly passing.
  Suggested change: open (and truncate) the file in this case as well,
  and write the error lines (`Bail out! ...`) to it, so that the file
  always describes the current run.

  Fixed in `f51ded85` (#232): as suggested, for the option errors; `--help`
  is unchanged.

- **#7 — An application type is reported with the operand decorations
  of its parts.** [internal] **[confirmed]** (fixed)
  `src/expression-formatter.cpp` lines 193 to 205, 413 to 513: the
  application's `operator<<` receives the same formatter as the
  operands, so the numbers it writes get C suffixes and the strings get
  quotes. Newcomer program `t4.cpp`, with
  `f << m.cents / 100 << "." << m.cents % 100 << " " << m.currency`:
  `119l.1l "EUR" == 119l.0l "EUR"`, and `(1, 0l.1l "RON")` in a pair;
  the same object streamed into a message reads `119.1 EUR`. The output
  is misleading (`119l.1l`), contradicts the manual ("shown as that
  function writes them"), and `formatter.str()`, which the manual
  suggests for testing such an operator, returns the decorated text.
  Possible changes: switch the formatter to plain mode around the call
  of an application `operator<<` (detected in `append_value()` and the
  operand paths as a type that none of the built-in overloads handles),
  or give the application a separate plain formatter.

  Fixed in `8ad82b6b` (#233): the second possibility of the item, but not by
  switching the formatter to the plain mode: the operands of the
  application types are written by `plain_text::append()`. A formatter
  that the application constructs keeps the decorations.

- **#8 — A lazy message is dropped from the reports of passing
  checks.** [internal] **[confirmed]** (withdrawn)
  `inlines/check-result-inlines.h` lines 182 to 188: a lazy message (a
  callable) is evaluated only when the check fails, while a plain
  message is written whenever the check is written (in verbose mode, or
  with an output file). Probe `p1.cpp` (`P_LAZY`) in verbose mode:
  `ok 1 - plain message`, but `ok 2 - true` for
  `t.expect (true) << [] { return "lazy message"; }`. Suggested change:
  evaluate the lazy message whenever `is_written_` is set; that already
  restricts the cost to the checks that are written.

  Withdrawn: the behaviour is intended and documented (the User's Guide
  and the comment of `operator<<`): a lazy message exists for the values
  that are valid only after a failure, such as the `error()` of a
  `std::expected` that holds a value, so evaluating it after a success,
  as suggested, would call `error()` on a value and be undefined
  behaviour.

- **#9 — Strings of the other character types are compared as
  addresses, or rejected.** [internal] **[confirmed]** (fixed)
  `inlines/detail-inlines.h` lines 1151 to 1163 (`as_operand()` handles
  only `char`), `expression-formatter.h` lines 632 to 635, and
  `extension.h` lines 469 to 474 (`has_npos` excludes the strings from
  the ranges): `eq (pa, pb)` with two `const wchar_t*` (or `char8_t*`)
  that point to equal contents fails, and reports two addresses
  (`0x7ff7bcbd106c == 0x7ff7bcbd1054`, probe `p5.cpp`);
  `eq (std::wstring, std::wstring)` and `eq (std::u8string, ...)` do not
  compile (`no matching function for call to 'eq'`); and a message
  `<< u8"text"` prints an address (`not ok 1 - 0x100c38520`, probe
  `p1.cpp`, `P_TYPES`). The formatter already prints the single
  characters of these types (`u8'a'`, `L'x'`). Suggested change: extend
  `c_string` to a template over the character type, and add the
  formatter overloads for `std::basic_string_view` of `wchar_t`,
  `char8_t`, `char16_t`, and `char32_t`, used for the pointers, the
  arrays, and the strings of these types.

  Fixed in `36a441c8` (#236): narrower than suggested. The strings and string
  views of the four types are accepted and written as UTF-8, and the
  pointers and arrays are written as text in the plain mode; as
  operands, the pointers remain addresses, as #183 decided and the
  User's Guide documents, so `c_string` was not made a template.

- **#10 — Control characters in messages and names are written
  raw.** [internal] **[confirmed]** (fixed)
  `src/expression-formatter.cpp` lines 193 to 230 (the plain mode of the
  check messages) and `src/reporter-tap.cpp` lines 103 to 133
  (`tap_text()` replaces only the line ends): the operands are escaped,
  but a `'\0'`, an escape character, or another control character in a
  message or a test name reaches the console and the file unchanged.
  Probe `p1.cpp` (`P_NUL`): `not ok 1 - before^@after` (a raw NUL byte
  in the TAP file and on the console). An escape sequence in a message
  can change the terminal state, and only the `ESC [ ... m` sequences
  are removed from the file. Suggested change: in the plain mode, and in
  `tap_text()`, write the control characters other than the line ends
  and the tab as `\0` and `\xHH`, as the operands are written.

  Fixed in `099d0d5c` (#237): the messages through the plain mode of the
  formatter, and the names in the `located_name` constructors, instead
  of in `tap_text()`, so that all the reporters are covered.

## 2. Usability

### The newcomer exercise

A fresh sub-agent wrote one program per task, reading only the user
manual and the public declarations. Each program was built and run with
clang, and compiled with `arm-none-eabi-g++` 15.2.1 (no native GCC works
on this host, so the programs were not run with GCC). All the programs
compiled without warnings with `-Wall -Wextra -Wpedantic`.

Overall, the library can be learnt and used from the manual and the
public headers alone; the weak points are the diagnostics of the common
mistakes, some failure reports, and the accuracy of the manual.

The code repeated by every program is about 8 lines: the include, the
namespace alias, the runner, the optional `initialise()` and
`add_top_suite()`, and `return tr.run_suites ();`. This is acceptable,
and lighter than in most frameworks.

The tasks:

- Task 1, a suite that checks a small class (`t1.cpp`): completed. The
  reports are clear without the source
  (`pop removes one FAILED (t1.cpp:68, 2ul == 1u)`). The type of the
  body parameter, `mt::test_case&`, had to be found in a comment of
  `test.h`, since the manual writes only `auto&`.
- Task 2, integers, floating-point values, strings, and containers
  (`t2.cpp`): completed from the manual alone; every failure shows what
  was compared (`0.33333334f ~ (0.3 +/- 0.01)`,
  `{1, 2, 3} == {1, 2, 4}`).
- Task 3, exceptions (`t3.cpp`): completed, but the manual gives only
  the signatures, without an example, and the failure reports do not
  tell why the check failed (#14).
- Task 4, an application type in messages and operands (`t4.cpp`):
  completed, but the parts of the type get the operand decorations in
  the comparisons (`119l.1l "EUR"`), not in the messages (#7).
- Task 5, an application comparator and predicate (`t5.cpp`):
  completed, but the contract of a tag (`symbol`, `apply()`) is only in
  the manual and `compare_op` is declared in `detail` (#13); the
  manual's example takes `const&` operands, which its text advises
  against (#39); `negate()` is reported without parentheses (#15); the
  forwarding of the caller's location is not documented (#37).
- Task 6, a run configured in code with the TAP reporter (`t6.cpp`):
  completed at the first attempt.
- Task 7, static suites in a separate translation unit (`t7.cpp`,
  `t7-suites.cpp`): completed at the first attempt; the ordering by
  name, `test_each`, the filters, and the listing behaved as documented.

The places where several forms are offered with nothing to tell which
one to choose: the four ways of initialising the runner (with
`argc`/`argv`, with `runner_options`, with `runner_options{ argc,
argv }`, or not at all), a top suite or none, `add_suite()` or
`static_suite`, `auto&` or `mt::test_case&` for the body (not
equivalent for the diagnostics, see #20), `"x"` or `"x"sv` in the
string examples, `const&` or forwarding references for the extension
operands, and `located_name` or `reflection::source_location` for the
location of a helper.

The diagnostics of the deliberate mistakes (the number of lines of the
whole compiler output; GCC compiled only):

| Mistake                                 | clang   | GCC     | Clear  |
| --------------------------------------- | ------- | ------- | ------ |
| operand without `operator<<`            | 13      | 24      | yes    |
| `expect()` with a struct or a string    | 34      | 78      | partly |
| incompatible operands (`eq (1, "abc")`) | 122-146 | 175-287 | no     |
| test body with the wrong parameters     | 23      | 32      | partly |
| suite body with the wrong parameters    | 35      | 81-93   | no     |
| tag without `symbol` or `apply()`       | 13-28   | 29-37   | partly |

The constrained parts (`printable`, `checkable`) give short errors at
the user's line. Nothing else is constrained, so the other mistakes fail
inside the framework: the incompatible operands in
`inlines/detail-inlines.h`, followed by 20 to 50 candidates from the
standard library, and the suite bodies inside `std::function`, where GCC
adds a misleading second error (#11, #12, #13, #17). The `auto& t` form
used by all the examples of the manual adds five framework frames to
every error in a body, which makes the GCC output two to three times
longer (#20, #43). With GCC, `expect()` with a non-boolean value says
only "no operand of the disjunction is satisfied".

The manual: the enable macro `MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED` is
not in the user manual, only on the install page; without it, the
header is silently empty, and the first error is
`use of undeclared identifier 'micro_os_plus'` (#35). About a dozen
places disagree with the code: stale sample outputs, the `expect()`
signature without its location parameter, and a Namespaces section
without `extension` and `reflection` (#36 to #42).

The findings follow.

- **#11 — Comparisons of incompatible operands are not constrained.**
  [internal] **[confirmed]** (fixed)
  `function-comparators.h` lines 126 to 212: `eq()` and the others
  require only that the operands are printable. `eq (1, "abc")`,
  `eq (std::string, 42)`, and `eq (std::vector<int>, std::array<int, 2>)`
  fail inside `inlines/detail-inlines.h` line 309, naming
  `detail::c_string` and `detail::equal_to::apply`, followed by 20 to 50
  unrelated candidates from the standard library: 122 to 146 lines with
  clang, 175 to 287 with GCC (newcomer, `mistakes/`). Suggested change:
  add a `detail` concept that checks that `Compare_T::apply()` is
  well-formed for the unwrapped operands, and require it in the six
  comparators, next to `printable`; the error then appears at the user's
  line, as for the non-printable operands (13 lines with clang).

  Fixed in `2bddb862` (#238): as suggested, with one concept for each
  relation that mirrors `apply()`; the pairs of pointers with a function
  pointer remain accepted. The diagnostic is 22 lines with clang.

- **#12 — The bodies of test cases and suites are not constrained.**
  [internal] **[confirmed]** (fixed)
  `test.h` lines 1186 to 1189, 1701 to 1704, 2151 to 2154, and
  `runner.h` lines 572 to 575: a body with the wrong parameters fails
  inside `detail::callable_ref::invoke_callable` (23 lines with clang,
  32 with GCC), or, for `add_suite()` and `static_suite`, inside the
  constructor of `std::function`, where GCC adds a second, misleading
  `enable_if<false>` error (35 to 93 lines; newcomer, `mistakes/`).
  Suggested change: a `requires std::invocable<Callable_T&, test_case&,
  std::decay_t<Args_T>&...>` (and `suite&` for the suites), or a
  `static_assert` with a message such as "the body of a test case must
  take a `test_case&` first parameter".

  Fixed in `bd1d33c4` (#239): as suggested, with the concepts `test_body`
  and `suite_body`; the diagnostic is 13 lines with clang. A move-only
  suite body is rejected as well.

  Adjusted in `5e6cc586` (#246): the check of the invocability instantiated
  the generic lambdas, which made the errors in their bodies worse (49
  lines against 19 with clang), so it applies only to the bodies with a
  non-generic call operator.

- **#13 — The extension tags have no concept.** [internal]
  **[confirmed]** (fixed)
  `detail.h` lines 1711 and 1712 export `compare_op` and `predicate_op`
  to the `extension` namespace, but nothing states what a tag must
  provide. A tag without `symbol` fails in
  `inlines/expression-formatter-inlines.h` line 410, and one without
  `apply()` in `inlines/detail-inlines.h` line 478, after 25 to 35 lines
  of instantiation context with GCC (newcomer, `mistakes/`). The contract
  (the type of `symbol`, the return type of `apply()`) can be found only
  in the manual. Suggested change: concepts `extension::compare_tag` and
  `extension::predicate_tag`, required by the constructors and the
  deduction guides, so that the contract is in a public header and the
  error is at the user's line.

  Fixed in `398787cf` (#240): as suggested, with the concepts required by
  the constructors of `compare_op` and `predicate_op`; the diagnostic
  is 19 lines with clang.

- **#14 — The exception checks do not say why they failed.** [internal]
  **[confirmed]** (fixed)
  `inlines/expression-formatter-inlines.h` lines 591 to 620 and
  `inlines/detail-inlines.h` lines 687 to 759: `throws<E>` reports
  `throws<std::invalid_argument>` both when nothing was thrown and when
  another exception was thrown, and `nothrow` reports `nothrow` without
  the `what()` of the exception (probe `p8.cpp`; newcomer `t3.cpp`).
  Suggested change: record, in `callable_op`, whether something was
  thrown and the `what()` of a `std::exception`, and append them to the
  report (`throws<std::invalid_argument>, but std::exception "other" was
  thrown`, `throws<...>, but nothing was thrown`, `nothrow, but "boom"
  was thrown`).

  Fixed in `f4873dc0` (#241): as suggested; the constructors and the
  factory functions are no longer `constexpr`.

- **#15 — `negate()` is reported without parentheses.** [internal]
  **[confirmed]** (fixed)
  `inlines/expression-formatter-inlines.h` lines 562 to 567:
  `negate (eq (1, 1))` is reported as `not 1 == 1`, and a negated
  predicate as `not "hello world" starts with "hello"`; both read as
  `(not x) == y` (probe `p8.cpp`; newcomer `t5.cpp`). Suggested change:
  write `not (...)` when the operand is a binary expression or a
  predicate.

  Fixed in `1011aad1` (#242): for the `compare_op` and the `approx_op`; the
  predicates, written as a prefix (`not even 4`), are not parenthesised.

- **#16 — The comparisons of application types require an
  `operator<<`.** [internal] **[confirmed]** (withdrawn)
  `function-comparators.h` lines 126 to 212: two application objects
  with an `operator==` cannot be compared with `eq()` unless the
  application also writes an `operator<<` for the formatter, even
  when only the result matters (newcomer, "operand without
  `operator<<`"). The diagnostic itself is good. This is a design
  choice; an alternative is to accept such operands and print a
  placeholder, for example the type name from
  `reflection::type_name<T>()` in braces, as other frameworks print
  `{?}`. Left to the maintainer.

  Withdrawn: a design decision, kept. The requirement gives a clear
  error at the call (13 lines with clang), and a failure report that
  shows the values, which is what the framework is for; a placeholder
  such as `{?}` would hide the cause of a failure, and an
  `operator<<` for the formatter takes a few lines (see the User's
  Guide, "Custom types").

- **#17 — The diagnostic of `expect()` with a non-boolean value is
  useless with GCC.** [internal] **[confirmed]** (fixed)
  `test.h` lines 1289 to 1295 and `extension.h` lines 270 to 274:
  `t.expect (std::string{})` gives, with GCC, 78 lines that say only
  "no operand of the disjunction is satisfied" and suggest
  `-fconcepts-diagnostics-depth=2`; with clang, the notes name the
  internal `op_type` and `detail::op` (newcomer, `mistakes/`).
  Suggested change: an additional overload, constrained with
  `not checkable<Expr_T>`, whose body is a `static_assert` with the
  message "expect() takes a boolean condition or a comparison such as
  eq()"; the user-facing text then replaces the concept trace.

  Fixed in `bf1aa796` (#243): as suggested; the diagnostic is 21 lines with
  GCC and 22 with clang. The overloads are accepted by a `requires`
  expression, so a helper constrains with `extension::checkable`.

- **#18 — The help text does not describe the filter levels.**
  [internal] **[confirmed]** (fixed)
  `src/runner.cpp` lines 78 to 85: the help shows `--filter=<pattern>`,
  but each repetition of the option applies to the next nesting level
  (suite, test case, nested test case), and a single `--filter` with a
  test case name selects nothing (probe: `p2 --list-tests
  --filter=three` lists 0 test cases). The levels and the `|`
  alternatives are explained only in the manual. Suggested change:
  `--filter=<suite> [--filter=<test case> ...]`, with one line on the
  `*`, `?`, and `|` syntax.

  Fixed in `3040e93a` (#244): a description under the option, in five
  lines, instead of the suggested change of the usage line; no test.

- **#19 — `--list-tests` succeeds when the filters select nothing.**
  [internal] **[confirmed]** (fixed)
  `src/runner.cpp` line 781: with `--list-tests`, filters that match no
  test case give the exit code 0 (probe `p2`), while a run with the same
  filters gives 2 (`the filters selected no test case`, lines 806 to
  823). A script that checks a filter with `--list-tests` before
  running is misled. Suggested change: the same exit code, and the same
  error line, in both modes.

  Fixed in `9b405683` (#245): as suggested; the User's Guide, which gave the
  exit code 0 for the listing, was updated.

- **#20 — Mistakes in a generic body are reported deep in the
  framework.** [internal] **[confirmed]** (withdrawn)
  `inlines/test-inlines.h` lines 264 to 281 and 375 to 420: every error
  inside an `auto& t` body, the form used by all the examples of the
  manual, is preceded by five framework frames (`callable_ref`,
  `create_test_case`, `suite::test`, `after_test_case_create`), which
  doubles or triples the GCC diagnostics (newcomer: 19 lines with
  `mt::test_case& t`, 34 with `auto& t`, for the same mistake). The
  frames are inherent to a generic lambda; the improvement is to show
  `mt::test_case&` in the manual (see #43) and to keep the call chain
  short: `create_test_case()` and `after_test_case_create()` could
  become one function.

## 3. Structure and layering

  Withdrawn: measured again after the fixes of #12 and #246, a mistake
  in a generic body is 19 lines with clang and 19 with GCC, against 4 and
  5 for a body with a `test_case&` parameter; the difference is the
  instantiation of the generic lambda, which is inherent, and the
  frames of the framework are not the cause. Showing `mt::test_case&` in
  the manual remains in #43.

- **#21 — The deprecated wrappers and literals are compiled without the
  deprecated functionality.** [internal] (fixed)
  `values.h` (all of it, except `detail::op`), `math.h` lines 169 to
  328, `expression-formatter.h` lines 443 to 457 and 655 to 658,
  `extension.h` lines 520 and 521 (`has_value`), and
  `inlines/detail-inlines.h` lines 458 to 462: `integral_constant`,
  `floating_point_constant`, `value<T>`, `named_bool`, the parsing of
  the literals, `decimal_epsilon()`, and their formatter overloads serve
  only the deprecated wrappers and literals, but are not guarded by
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED`; the
  non-deprecated build parses and keeps about 600 lines it never uses.
  Suggested change: move `detail::op` to `detail.h` (or keep it alone in
  `values.h`), and guard the rest, or move it to `deprecated.h`.

  Fixed in `7b084117` (#247): the wrappers and the parsing of the literals
  moved to `deprecated.h`, `values.h` was removed, and the remaining
  uses are guarded.

- **#22 — `detail` appears in the public signatures and base classes.**
  [breaking] (fixed in part)
  `test.h` lines 1083 and 1565 (`test_case` and `suite` derive from
  `detail::runnable_base`, which provides their public `name()` and
  `totals()`), lines 1289 to 1338 (`detail::check_result` in `expect()`
  and `require()`, see #2), `function-comparators.h` lines 250 to 254
  (`detail::approx_operand` in `approx()`), and `expression-formatter.h`
  line 1383 (the public `expression_formatter` is declared in `detail`,
  so the newcomer could not look up `str()` or its overloads). The users
  meet these names in every diagnostic. Suggested change: move
  `runnable_base` out of `detail` under a public name (or make it a
  private base, with using-declarations for `name()` and `totals()`),
  move `approx_operand` to `extension` (as `printable` and `checkable`
  are), and declare `expression_formatter` in the top namespace, with a
  `detail` alias for compatibility.

  Fixed in `e570bdf7` (#250), in part: `approx_operand` moved to
  `extension`, without a transition, since it is new since v5.0.1. The
  other points are kept: `runnable_base` stays the base of the public
  classes, since renaming a class of `detail` would only change the
  names in the diagnostics, and `detail::check_result` stays in the
  signatures of `expect()` and `require()`.

  The remaining points are deliberately kept: `expression_formatter` is
  already aliased in the top namespace, a private `runnable_base` would
  break the conversion of the public classes to it, and renaming it
  would only change the diagnostics.

- **#23 — The runner's counts are public, but used only by the tests
  and the reporters.** [breaking] (withdrawn)
  `runner.h` lines 703, 789, 852, 873, and 890
  (`total_suites_count()`, `added_suites_count()`,
  `static_suites_count()`, `skipped_suites_count()`, and `totals()`),
  and `test.h` line 1439 (`test_case::nesting_depth()`): none of them is
  mentioned in the manual, the library calls them only from the
  reporters (which are friends), and the tests call the first four.
  Four counts of suites make the runner's interface look larger than it
  is. Suggested change: keep `totals()` (an application may want the
  result without parsing the output) and document it; make the others
  private, with an access class for the tests, as `stopwatch` already
  has (`stopwatch_test_access`). Migration: `[[deprecated]]` for one
  major release.

  Withdrawn: the counts are new since v5.0.1 and none of them is a defect: the
  interface of the runner is larger by four names, and hiding them
  would need an access class for the tests, which is more code than it
  removes. They are not documented in the manual, and may be used by
  the applications that want the counts of the suites.

- **#24 — `utility::split()` is public, but unused.** [breaking] (withdrawn)
  `utility.h` lines 131 to 157, `inlines/utility-inlines.h` lines 89 to
  114, and `src/utility.cpp` lines 212 to 231: the library never calls
  `split()`; only `tests/sources/unit-checks/src/checks.cpp` (lines 302
  to 323) does. The template and the `std::string_view` overload
  implement the same loop twice. `extract_file_name()` and `is_match()`
  are used by the library, but by no example of the manual except one
  mention. Suggested change: deprecate `split()`; if it is kept, keep
  one implementation (the `std::string_view` overload covers
  `std::string` arguments). Migration: `[[deprecated]]` for one major
  release.

  Withdrawn: a decision of the maintainer: `utility::split()` is a public utility
  meant for the applications, listed with the other utility functions
  in the User's Guide, so it stays in `utility`; the two forms differ in
  the type that they return (`std::vector<T>` for the input type, and
  `std::vector<std::string_view>`), so they are not duplicates.

- **#25 — Without exceptions, a failed `require()` ends the process
  without the summary.** [internal] **[confirmed]** (withdrawn)
  `src/check-result.cpp` lines 178 to 188 and `src/runner.cpp` lines
  897 to 934: the build without exceptions calls `runner::abort()`,
  which writes `Bail out!`, calls the optional handler, and then
  `::abort()`. The remaining suites do not run (unavoidable without
  exceptions, and visible: `- test execution aborted`), but the totals
  are not written either, and the handler receives only the location,
  so it cannot end the program with a meaningful exit code; the process
  ends with `SIGABRT` (exit code 134, probe `p4.cpp`). Suggested change:
  write the session totals (and the TAP plan of the suites already
  reported) before calling the handler, and pass the exit code to it
  (a second handler type, keeping the current one).

  Withdrawn: a design decision, kept. The User's Guide documents the
  purpose of the handler: to signal the failure and reset the target,
  or, with exceptions, to throw and return control to the application,
  which then chooses its own result (its example uses `3`). An aborted
  session has no exit code of its own, since the runner never
  completes, and the handler is called only on a failure, so a code
  passed to it would carry no information. The totals are not written
  after the abort because, in TAP, `Bail out!` ends the stream, and a
  plan or totals after it would be wrong for the consumers; with the
  human reporter it would be a partial summary of a run that did not
  finish.

- **#26 — The configuration errors are written twice to the
  terminal.** [internal] **[confirmed]** (withdrawn)
  `src/runner.cpp` lines 288 to 294: each error is written to `stderr`
  (`error: unknown option '--bogus'`) and through the reporter to
  `stdout` (`Bail out! unknown option '--bogus'`), so an interactive
  user sees it twice (probe `p2`). Suggested change: write to `stderr`
  only when the reporter does not already write the line to the console
  (for example in silent mode), or only to `stderr` when no output file
  is used.

## 4. Naming and consistency

  Withdrawn: a design decision, kept. The `stderr` line and the
  reporter line serve different readers: the reporter line is the
  `Bail out!` that the TAP consumers read on `stdout`, and the `stderr`
  line is the only one that reaches the terminal when `stdout` is
  redirected (`prog > report.tap`) or when only `stderr` is captured.
  The program cannot tell these cases apart on the embedded targets,
  which have no `isatty()`, and writing to `stderr` only in the silent
  mode would lose exactly the redirected case.

- **#27 — The members of `runner_options` follow three naming
  patterns.** [breaking] (withdrawn)
  `runner-options.h` lines 345 to 467: `selected_reporter` (of type
  `reporter_kind`), `verbosity_level` (of type `verbosity`), and
  `colour` (of type `colour_mode`), next to `output_file_path`,
  `filter_patterns`, `list_tests`, and `help`. Nothing tells a user
  which spelling to expect for the next one. Suggested change: name the
  members after the command-line options (`reporter`, `verbosity`,
  `colour`, `output_file`, `filters`, `list_tests`, `help`), and keep
  the current names as `[[deprecated]]` references for one major
  release, if the change is considered worth the churn.

## 5. Simplicity and duplication

  Withdrawn: the proposed names are worse than the current ones: a member
  `verbosity` would have the type `verbosity` in the same class, which
  is why the member is `verbosity_level`; the members are all new since
  v5.0.1, and the inconsistency is cosmetic.

- **#28 — `test()` and `test_each()` are written twice.** [internal] (withdrawn)
  `inlines/test-inlines.h` lines 455 to 467, 733 to 752, and 832 to 881:
  `suite` and `test_case` each have a `test()` and two `test_each()`
  overloads; the four `test_each()` bodies are identical calls of
  `detail::test_each_value()`. Suggested change: define them once, as
  templates in the common base, parametrised by the parent suite and
  the nesting depth.

  Withdrawn: the logic is already written once, in `detail::test_each_value()`; the
  four `test_each()` members are one-line forwarders that carry the
  public documentation, and `suite::test()` differs from
  `test_case::test()` (the suite delegates to the running test case), so
  a shared base would need a CRTP mixin that adds more complexity than
  it removes.

- **#29 — The command-line parser matches the options in three
  ways.** [internal] (fixed)
  `src/runner-options.cpp` lines 152 to 232 and 292 to 326: the test
  "the option, or the option followed by `=`" is written in
  `get_value()`, again in `is_known_option()`, and twice more for
  `--colour` and `--color`; `is_known_option()` exists only to avoid a
  second error after `get_value()` has reported a missing value.
  Suggested change: one table of the options (name, takes a value,
  handler), and one matching function.

  Fixed in `30d379dc` (#248): as suggested, with a table of the options
  that take a value and one matching loop.

- **#30 — `runner_options` has a hand-written copy assignment.**
  [internal] (withdrawn)
  `inlines/runner-options-inlines.h` lines 59 to 65: the copy
  assignment copies and then move-assigns, while the copy constructor
  and the move assignment are defaulted; the defaulted copy assignment
  gives the same result for these members. Suggested change: `= default`.

## 6. Modern C++

  Withdrawn: the hand-written copy assignment is a deliberate workaround, documented
  in `src/runner.cpp`: the copy assignment of `std::vector` triggers
  `-Waggregate-return` in the standard library headers on some targets.
  `= default` compiles cleanly with GCC 15.2.1, but the older toolchains
  could not be tested, and removing 8 lines is not worth a risk for the
  builds with `-Werror`.

- **#31 — `[[gnu::always_inline]]` in the public headers.** [internal] (withdrawn)
  `test.h` lines 675, 849, 868, 949, and 1461, and `detail.h` lines 477
  to 773: the umbrella header accepts MSVC (`_MSVC_LANG`), which does
  not know the `gnu` attributes and warns about them (C5030) in every
  translation unit. Suggested change: a project macro that expands to
  the attribute only with `__GNUC__`, or no attribute (these functions
  are small templates, inlined anyway).

## 7. Suitability for embedded targets

  Withdrawn: MSVC is not a supported compiler (`reflection::type_name()` needs
  `__PRETTY_FUNCTION__`, which only GCC and Clang provide), and an
  unknown attribute of the `gnu` namespace is only a warning there.

- **#32 — The TAP reporter copies every test case name twice.**
  [internal] **[confirmed]** (fixed)
  `src/reporter-tap.cpp` lines 565 and 644, and `inlines/test-inlines.h`
  lines 101 to 141: the name of each test case is copied into a
  `std::string` by `located_name`, and twice more by `tap_text()`, in
  `begin_test_case()` and `end_test_case()`, at every verbosity,
  including `--silent`. Probe `p7.cpp`, counting `operator new`: a test
  case with a name longer than the small-string capacity (22 characters
  with libc++, 15 with libstdc++, as on the embedded targets) costs 3
  allocations with the TAP reporter, 1 with the human reporter, and 0
  with a short name; 100 passing checks cost none. Suggested change:
  escape only when the name contains a character that needs it (a
  search, without a copy), and write the name directly otherwise.

  Fixed in `d651fa6e` (#249): as suggested; 1 allocation for a long name,
  as with the human reporter.

## 8. Incidental observations

- **#33** `check-result.h` lines 397 to 399: the layout of
  `check_result` depends on `__cpp_exceptions`
  (`uncaught_exceptions_`), so translation units compiled with and
  without exceptions cannot be mixed with the library; worth one line in
  the build notes.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#34** `detail.h` lines 889 to 893 and 1270 to 1273: the deduction
  guides call `as_operand()` unqualified, so argument-dependent lookup
  could select an application function of the same name; the
  constructors and the comparators qualify it (`detail::as_operand`).
  (fixed)
  Fixed in `05ba6d48` (#251): the guides, `comparison_operand_t`, and
  the reporter calls of `append_pointer()` and `append_number()` are
  qualified with `detail::`; tested in `operands.cpp` with a type whose
  namespace has `as_operand()` overloads.
- **#35** (`website-review`) The user manual does not name
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED`, nor the sources to build; they
  are only in `website/docs/install/_project/_build-and-integration-info.mdx`
  (line 62). Without the macro, the umbrella header is empty, and the
  first error is `use of undeclared identifier 'micro_os_plus'`. A
  link from the manual would unblock a newcomer at the first step.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#36** (`website-review`) Several sample outputs of the manual are
  stale (newcomer, table rows 7 to 12): `# { test case passed, 1 check }`
  (the code writes `# { passed, 1 check }`), `expect: 43 == 42` (the code
  writes `condition: "43 == 42"`), `lineNumber: 69` for a 25-line
  program, totals that disagree with the suite line, and no `# Running:`
  and `# Built with` lines.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#37** (`website-review`) The manual gives `expect()` as
  `auto expect (const Expr_T& expr)` (line 543), without the
  `source_location` parameter that lets a check helper report the
  caller's line; this use is not documented.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#38** (`website-review`) The Namespaces section (lines 260 to 267)
  omits `extension` and `reflection`.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#39** (`website-review`) The extension example takes its operands as
  `const&` (from line 1157), while the text after it (from line 1215)
  recommends forwarding references.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#40** (`website-review`) Line 896 states that the containers "must be
  of the same type"; a C array against a `std::vector` is accepted.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#41** (`doxygen-review`) The comments of the non-deprecated
  `approx()` (`function-comparators.h` lines 222 and 234) and of
  `extension.h` (line 149) present the deprecated wrappers and literals
  as normal alternatives.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#42** (`website-review`) Line 1776 repeats `--output-file=<path>`;
  the second form is `--output-file <path>`.
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#43** (`website-review`) The manual never shows a body with an
  explicit `mt::test_case&` parameter, which gives diagnostics two to
  three times shorter than `auto&` (see #20).
  (fixed)
  Fixed in `c2a19d23`: as suggested.
- **#44** (`website-review`) The counts of an outer test case exclude
  the checks of its nested test cases, while the suite counts include
  them (newcomer `t1.cpp`: `Nested - FAILED (0 checks passed, 1
  failed)`); the behaviour is consistent, but not explained.
  (fixed)
  Fixed in `c2a19d23`: as suggested.

## 9. Reviewed and found sound

- The session state machine of `runner`: `initialise()` and
  `add_top_suite()` twice, out of order, or not at all, `run_suites()`
  twice, suites added during the run, and static suites constructed
  after the start are all handled, reported, and reflected in the exit
  code.
- The registration of the static suites: the `constinit` list heads
  (`suite::first_`, `runner::started_first_`) make the construction
  order across translation units irrelevant, and the suites are sorted
  by name; the newcomer's suites in a separate translation unit worked
  at the first attempt.
- Copy and move: the registered and referenced classes (`runner`,
  `suite`, `test_case`, `check_result`, `expression_formatter`, the
  reporters, `stopwatch`) are neither copyable nor movable; `counters`
  and `runner_options` are copyable.
- The counting of nested test cases, of skipped test cases, and of the
  failures of nested test cases in their parents, suites, and totals
  (probe `p1.cpp`, `P_NESTFAIL`).
- The comparisons of mixed signed and unsigned integers
  (`std::cmp_equal` and the others, with the character types and `bool`
  excluded), `-1 == 4294967295u` failing correctly; the C strings against
  `std::string` and `std::string_view`, null C strings, character arrays
  bounded by their size, arrays against containers, `std::optional`,
  `std::byte`, and the integer `approx()` without overflow at the limits.
- The formatting of the fundamental types: the suffixes, `-0.0`, NaN,
  the infinities, `long double` with the shortest exact precision, the
  escaped characters and strings in the operands, the scoped
  enumerations, and the pointers.
- The TAP output: valid TAP 14 at every verbosity, on the console and in
  the file (probe `p2.cpp`), with `#`, `\`, `:`, and newlines in the
  names and messages escaped or replaced; the quiet mode shows the path
  and the failed checks; the silent mode writes nothing.
- The nested `check_result` objects alive at the same time (the
  `pending_` list of the formatter), and the reports during stack
  unwinding (`std::uncaught_exceptions()`).
- The build without exceptions and RTTI; the cross build for Cortex-M4
  with no warning, including `-Wdouble-promotion` and `-Wconversion`;
  no stack frame over 328 bytes (`reporter_tap::end_suite`); no heap
  allocation for passing checks at the normal verbosity.
- The configuration entirely in code, through `runner_options`, without
  a command line (newcomer `t6.cpp`).
- The self-containment of all the headers, the header guards, the
  formatting, the line lengths, and the source lists of
  `xcdl-package.jsonc`, `CMakeLists.txt`, and `meson.build`, which
  match `src/`.
- The diagnostics of the `printable` and `checkable` constraints with
  clang: short, at the user's line, and naming the concept.
