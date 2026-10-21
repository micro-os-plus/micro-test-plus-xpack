# C++ API review

Date: 2026-10-12, on branch `xpack-development`, commit `38bb4962`.

Scope: the C++ source code of the library: the public headers in
`include/micro-os-plus/micro-test-plus.h` and
`include/micro-os-plus/micro-test-plus/`, the inline definitions in
`include/micro-os-plus/micro-test-plus/inlines/`, and the definitions in
`src/`. The Doxygen comments were deliberately ignored; the review judges
the API by its code alone (structure, consistency, elegance, readability,
and ease of understanding).

Method: the comments were stripped from all 46 source files, and the
remaining 5759 lines of code were read in full. Suspected defects were
confirmed with small probe programs, compiled with Apple clang 17
(`-std=c++20`, `-DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED`) and linked with
the library sources; one was confirmed with AddressSanitizer. Items marked
**[confirmed]** were reproduced; the others are derived from reading the
code. The sample programs in `tests/sources/` were consulted to see how
the API is used in practice.

The documentation review in `maintenance/docs/WEBSITE-API-REVIEW.md`
already contains some API design items (its #48 to #55 and #84 to #88).
Where an item below overlaps, it says so; the numbers in this document
are independent of the numbers there.

Summary: 66 problems (1 open, 64 fixed, 1 withdrawn).

The most serious problems are those that make tests behave wrongly:

- a nested test case that follows a check aborts the whole program
  (#1);
- a failed nested test case does not fail its parent (#2);
- calling `exit_code()` twice runs all suites again and counts
  everything twice (#3);
- a stored `expect()` reports the expression of another check (#4);
- a user function named `get()` silently changes the result of `eq()`
  (#5);
- integer literals do not follow C++ literal syntax: `010_i` is 10 and
  `300_u8` is 44 (#8);
- floating-point values can compare both equal and less than (#9);
- suite names are stored as non-owning pointers, and deferred suites
  read freed memory (#11).

Suggested order of work: fix the defects in section 1 (#1 to #14, #63,
and #66), each with a regression test in `tests/sources/unit/`; then the
non-breaking clean-ups (#28, #29, #41 deprecation attributes, #47, #48,
#49, and #54 to #62); then decide on the structural changes in section 2
and the renames in section 3, which are breaking changes and best grouped
in one major release.

Each item is tagged **[breaking]** when the suggested change alters the
public API, or **[internal]** when it does not.

## 1. Defects

- **#1 — A nested test case that follows a check aborts the program.**
  (fixed) Both reporters now write the outer test case's buffered results
  before a nested test case begins, in execution order, as node-tap
  does; covered by the unit test "Nested subtest after a check" (commit
  `d9b694e0`, issue #33).

  [internal] **[confirmed]** Every check writes its result into the
  reporter's line buffer (`src/reporter-human.cpp` lines 581 to 607,
  `src/reporter-tap.cpp` lines 570 to 596), and the buffer is emptied only
  at the end of the test case. A nested `t.test (...)` calls
  `begin_subtest()`, which requires an empty buffer and calls `abort()`
  otherwise (`src/reporter-human.cpp` lines 415 to 423,
  `src/reporter-tap.cpp` lines 405 to 411). Therefore:

  ```cpp
  ts.test ("parent", [] (auto& t) {
    t.expect (true);
    t.test ("child", [] (auto& c) { c.expect (true); });
  });
  ```

  prints "Buffer not empty at the beginning of a test case" and ends
  with SIGABRT, with both reporters and every verbosity. The existing
  test (`tests/sources/unit/src/main.cpp` line 288) passes only because
  the parent has no check before the nested test case. Before starting a
  nested test case, commit the parent's buffer (write it to the file, and
  to the console when the verbosity requires it), or keep one buffer per
  nesting level; add the case above to the unit tests.

- **#2 — A failed nested test case does not fail its parent.**
  (fixed) A new `failed_subtests` counter makes a test case fail when
  one of its nested test cases fails, at every level, with the same TAP
  structure as node-tap; the check counters still count only the test
  case's own checks. Covered by the unit test "Failed nested subtest"
  (commit `c0af8a17`, issue #34).

  [internal] **[confirmed]** `subtest::test()` passes `parent_suite_`, not `*this`,
  to `after_subtest_create_()` (`inlines/test-inlines.h` line 308), so the
  child's totals are added directly to the suite
  (`src/test.cpp` line 192), never to the parent test case. A parent
  whose only failure is in a child is reported as
  `✓ parent - passed (1 check)`, and the TAP reporter emits `ok` for a
  subtest that contains a `not ok`, which contradicts TAP 14 subtest
  semantics. Accumulate the child into its parent test case, and only
  the top-level test case into the suite (taking care not to count the
  child twice).

- **#3 — `exit_code()` runs the suites; calling it twice runs them
  again.**
  (fixed) Renamed to `run()`; `exit_code()` remains as a deprecated
  alias. The session is a state machine (`created`, `initialised`,
  `finished`): later calls of `run()` return the stored exit code
  without running anything, and a second `initialise()` is reported and
  ignored. Covered by the unit test (commit `b5139d83`, issue #35).

  [breaking] **[confirmed]** `runner::exit_code()`
  (`src/runner.cpp` lines 361 to 390) ends the top suite, runs all
  registered suites, ends the session, and adds the top suite's totals to
  the runner's. A second call repeats everything: the probe printed
  "3 checks passed, 1 failed, in 4 test cases" after the first call and
  "8 checks passed, 2 failed, in 10 test cases" after the second. The
  name promises a query and hides the most important step of the
  session. Rename it to `run()` (returning the exit code), or split it
  into `run()` and a `const` `exit_code()`; in either case make the
  session a state machine (`created`, `initialised`, `finished`) and
  ignore, or report, out-of-order calls.

- **#4 — A stored `expect()` reports the expression of another check.**
  (fixed) The expression formatter records which check owns its text,
  and moves the text aside only when a new check begins while the
  previous one is still pending; the check objects do not grow, since
  a per-check copy added 24 bytes per check to the test functions'
  stack frames and overflowed the 4 KB stack on Cortex-M33. The same
  scenario also numbered both checks `2` (the number was read when
  reporting, but incremented when constructing); the number is now
  assigned when the check is reported, so the TAP points follow the
  output order. Covered by the unit test "Stored check result" (commit
  `c4c3597c`, issue #36).

  [internal] **[confirmed]** All checks share one
  `expression_formatter`, owned by the reporter. The constructor of
  `deferred_reporter` clears it and formats its expression into it
  (`inlines/deferred-reporter-inlines.h` lines 176 to 178); the
  destructor reads it back (`src/deferred-reporter.cpp` line 106). When
  the result of `expect()` is kept in a variable:

  ```cpp
  auto e1 = t.expect (mt::eq (1, 2));
  t.expect (mt::eq (3, 3));
  ```

  the failure is reported as `FAILED (..., 3 == 3)`, after the success
  of the second check. `auto` makes this easy to write and the type
  cannot be named, so the compiler cannot help. Format into a string
  owned by the `deferred_reporter` (it already owns `deferred_output_`),
  or format only in the destructor from a copy of the operands.

- **#5 — A user function named `get()` changes the result of
  comparisons.**
  (fixed) The helper is now `detail::unwrap_()`, always called
  qualified, and it calls `get()` only on framework types; the same
  check found that a user type with a `get()` member function was also
  compared by `get()`, not by its `operator==`. Covered by the unit test
  "Application types with get()" (commit `2f29e6c8`, issue #37).

  [internal] **[confirmed]** The comparison operators call
  `get (lhs)` and `get (rhs)` unqualified (`inlines/detail-inlines.h`
  lines 82 to 90, and 216 to 245, 285 to 306, 343 to 350, and the
  others), so argument-dependent lookup also finds functions named `get`
  in the namespaces of the operands. With

  ```cpp
  namespace user {
    struct wrapped { int v; bool operator== (const wrapped&) const = default; };
    constexpr int get (const wrapped&) { return 999; }
  }
  ```

  `mt::eq (user::wrapped{ 1 }, user::wrapped{ 2 })` is true. Rename the
  helper (for example `detail::unwrap_()`), call it qualified, and
  restrict it to framework types (`type_traits::is_op`).

- **#6 — Streaming a `bool` into a check message does not compile.**
  (fixed) `bool` is appended as `true`/`false`; the other arithmetic
  types are converted by `detail::append_number_()`, shared with the
  expression formatter, which also handles `long double` on the
  platforms without `std::to_chars()` for it. Covered by the unit test
  "Message values" (commit `40d58127`, issue #38).

  [internal] **[confirmed]** `deferred_reporter_base::operator<<` accepts
  every arithmetic type (`type_traits::printable`), and sends all of them
  except `char` to `std::to_chars()` (`inlines/deferred-reporter-inlines.h`
  lines 115 to 134); `std::to_chars (char*, char*, bool)` is deleted, so
  `t.expect (x) << "flag " << flag;` fails with "call to deleted
  function 'to_chars'". Handle `bool` explicitly (`"true"`/`"false"`),
  as `expression_formatter` already does.

- **#7 — Two `reporter` stream operators are declared but never
  defined.**
  (fixed) Both are defined in `src/reporter.cpp`, writing `true`/`false`
  and `nullptr`, as the expression formatter does. The tests also found
  that a pointer to a `const` object could not be displayed, neither by
  the reporter nor by the expression formatter (so `mt::ne (&a, &b)` with
  `const` objects did not compile): the `reinterpret_cast<void*>` cast
  away the qualifiers; both now use `detail::to_printable_pointer_()`.
  Covered by the unit tests "Reporter stream operators" and "Pointers to
  const" (commit `0d280c51`, issue #40).

  [internal] **[confirmed]** `reporter::operator<< (bool)` and
  `reporter::operator<< (std::nullptr_t)` (`reporter.h` lines 258 and 266)
  have no definition; `t.reporter () << true;` fails at link time. Since
  the non-template `bool` overload hides the arithmetic template for
  `bool`, the error appears only when the code is linked. Define them (as
  in `src/expression-formatter.cpp` lines 101 to 117), or remove the
  declarations.

- **#8 — Integer literals do not follow C++ literal syntax.**
  (fixed) The integer literal operators now use `math::integer()`, which
  parses the hexadecimal, binary, and octal prefixes and the digit
  separators, and fails the compilation, with an explicit message, for a
  decimal point or an exponent, or for a value that does not fit in the
  type (`math::num()` remains for the floating-point literals). Covered
  by the static assertions in `static-asserts.cpp` (commit `19b02b56`,
  issue #39).

  [internal] **[confirmed]** `math::num()` (`inlines/math-inlines.h` lines 162 to
  183) reads decimal digits only, skips digit separators, stops at a
  decimal point, and never checks the range:

  | Literal | Result | C++ meaning |
  | --- | --- | --- |
  | `010_i` | 10 | 8 (octal) |
  | `1.5_i` | 1 | not an integer |
  | `300_u8` | 44 | out of range |
  | `0x10_i` | static assertion on `'x'` | 16 |

  A test that compares with `010_i` checks against a different value
  from the one the reader sees. Parse the `0x`, `0b`, and `0` prefixes
  (or reject them with a clear message), reject a decimal point in the
  integer literals, and accumulate in `unsigned long long` with a
  `static_assert` that the value fits the target type.

- **#9 — Floating-point values can compare both equal and less than.**
  (fixed) As decided, the implicit tolerance of the literals and wrappers
  is kept, but all six comparisons now apply it consistently, through
  `detail::within_tolerance_()`: values within the tolerance are equal,
  and neither less nor greater (`1.45 < 1.5_d` is now false). The new
  `mt::approx (value, epsilon)` sets the tolerance explicitly. The
  tolerance is documented in the user guide and the Literals topic, with
  a compatibility notice. Covered by the unit test "Floating-point
  tolerance" (commit `4dc047e4`, issue #41).

  [breaking] **[confirmed]** `eq_` and `ne_` apply a tolerance when an
  operand has an `epsilon` (`inlines/detail-inlines.h` lines 223 to 240
  and 290 to 303); `gt_`, `ge_`, `lt_`, and `le_` ignore it (lines 343 to
  350 and the following). The tolerance is derived from the number of
  decimals written (`type-traits.h` lines 685 and 844 to 849): `1.5_d`
  and `mt::to_d (1.5)` both carry an epsilon of 0.1. Consequently
  `1.45 == 1.5_d` and `1.45 < 1.5_d` are both true. An implicit
  tolerance that depends on how the number is spelt is surprising, and
  the relational operators are inconsistent with it. Make the tolerance
  explicit (for example `mt::approx (1.5, 0.01)`), applied consistently
  by all six relations, and let the plain wrappers compare exactly.

- **#10 — The `_f` and `_d` literals overflow on 32-bit targets.**
  (fixed) All three floating-point literals use `unsigned long long`;
  `math::num()` and `math::den()` fail the compilation, with an explicit
  message, if the digits do not fit (19 before and 18 after the decimal
  point in 64 bits), or if the literal has an exponent. The same check
  found that a digit separator after the decimal point produced a wrong
  value on all platforms (`1.000'5_d` was about 1.8e13); `den()` and
  `den_size()` now skip the separators. Covered by the static assertions
  in `static-asserts.cpp` (commit `7032feb4`, issue #42).

  [internal] `operator""_f` and `operator""_d` compute the numerator,
  the denominator, and the size in `unsigned long`
  (`inlines/literals-inlines.h` lines 450 to 479), while `operator""_ld`
  uses `unsigned long long` (lines 492 to 499). On Cortex-M, RISC-V 32,
  and AArch32, `unsigned long` has 32 bits, so a literal with ten or more
  decimals (`1.0123456789_d`) wraps silently in `math::den()`. Use
  `unsigned long long` for all three, and assert the number of digits.

- **#11 — Names are non-owning pointers; deferred suites read freed
  memory.**
  (fixed) The suites (those registered with `runner::suite()` and the
  static suites, which run later) copy their name into a `std::string`
  member, and the node name points to the copy; the test cases, which
  run immediately, keep the non-owning pointer, avoiding an allocation
  per test case. A `std::string_view` parameter was not chosen, since it
  would document the lifetime requirement without removing it. Covered
  by a dynamic suite with a temporary name in the unit test, checked by
  AddressSanitizer in the native debug builds (issue #43, commit
  `38c89353`).

  [breaking] **[confirmed]** `test_node` stores the name as
  `const char*` (`test.h` line 249). Test cases run immediately, but
  suites registered with `runner::suite()` run later, in `exit_code()`.
  `r.suite (std::string ("Suite ").append (id).c_str (), fn);` therefore
  keeps a dangling pointer; AddressSanitizer reports a
  heap-use-after-free in `reporter_human::begin_suite()`. Copy the names
  of deferred suites into a `std::string`, or take `std::string_view`
  and make the lifetime requirement visible in the signature.

- **#12 — String literals cannot be compared with strings, and character
  arrays compare as addresses.**
  (fixed) As decided, the comparators pass their operands through
  `detail::as_operand_()`, which converts the `char` arrays, string
  literals, and `char` pointers to `detail::c_string_`, compared by
  content (also with `std::string` and `std::string_view`) in all six
  comparators; a null pointer is equal only to another null pointer, and
  a `char` array is read only up to its size. The other arrays decay to
  pointers and the functions to function pointers, so they, and the
  other pointers, are still compared by address. The six pointer
  overloads were removed (they decayed the arrays, losing their size).
  The failure messages show the strings. Covered by the unit tests "C
  string comparisons" and "Failed C string comparisons" (commit
  `96da278a`, issue #44). This also resolves WEBSITE-API-REVIEW #33.

  [breaking] **[confirmed]** The
  comparison structures store operands by value (`detail.h` lines 296 and
  304), so an array type cannot be stored:
  `mt::eq ("abc", std::string{ "abc" })` fails to compile deep in
  `inlines/detail-inlines.h` line 140. Two `char` arrays select the
  pointer overloads (`inlines/function-comparators-inlines.h` lines 97 to
  102 and the other `*` overloads), so `mt::eq (a, b)` is false for two
  arrays holding `"abc"`. Store `std::decay_t` of the operands, compare
  character pointers and arrays as `std::string_view` (as the reader
  expects in a test), and keep the pointer overloads for non-character
  pointers only. See also WEBSITE-API-REVIEW #33.

- **#13 — `char*` is printed as an address, `const char*` as a string.**
  (fixed) The pointer templates of `expression_formatter` and `reporter`
  now exclude `char`, so the `char` pointers and arrays reach the
  `const char*` overloads and are printed as strings; the `signed char`
  and `unsigned char` pointers (byte buffers) are still printed as
  addresses. The `const char*` overloads, which now also receive the
  null `char*` values, write `"nullptr"` for a null pointer instead of
  passing it to `std::string::append()`. Covered by the unit tests
  "Reporter stream operators" and "Formatter character pointers"
  (commit `fd6220ab`, issue #45).

  [internal] **[confirmed]** `expression_formatter` has
  `operator<< (const char*)` and a template `operator<< (T*)`
  (`expression-formatter.h` lines 249 and 398); for a `char*` the
  template is the better match, so a mutable buffer prints as
  `0x7ff7b76bb2f4`. The same applies to `reporter` (`reporter.h` lines
  250 and 290). Add a `char*` overload, or constrain the template to
  non-character types.

- **#14 — An exception escaping a test case ends the whole run.**
  (fixed) As decided, `subtest::run()` catches, when `__cpp_exceptions`
  is defined, the exceptions that escape the test case body, and reports
  them as a failed check of the test case (`unexpected exception: ` and
  `what()` for a `std::exception`, `unexpected exception of unknown
  type` otherwise; the type is not shown, since it would need RTTI); the
  run continues with the next test case. The failure is reported at the
  location of the `test()` call, captured by the new `detail::test_name`,
  the first parameter of `suite::test()` and `subtest::test()`, converted
  implicitly from a string literal or a `const char*`. The exceptions
  escaping a suite body, outside its test cases, are still not caught.
  Covered by the unit tests "Unexpected std::exception", "Unexpected
  exception of unknown type", and "Unexpected exception in nested test
  case" (commit `56b99ca9`, issue #46).

  [internal] `subtest::run()`, `suite::run()`, and `static_suite::run()`
  (`src/test.cpp` lines 216 to 235, 257 to 275, and 331 to 347) call the
  user callable without a `try` block. On hosted builds with exceptions,
  one unexpected exception terminates the program, and the summary of
  the other test cases is lost. When `__cpp_exceptions` is defined,
  catch in `subtest::run()`, report a failed check with the type (and
  `what()`, if available), and continue with the next test case.

- **#63 — A null C string streamed into a check message crashes the
  program.**
  (fixed) `deferred_reporter_base::operator<<` writes `"nullptr"` for a
  null `char*` or `const char*`, as the `expression_formatter` and the
  `reporter` do. `nullptr` itself, which is convertible to
  `std::string_view` in C++20 and reached the same `append()`, is also
  written as `"nullptr"`; `type_traits::printable` lists
  `std::nullptr_t` explicitly, since C++23 deletes that conversion.
  Covered by the unit test "Message values" (commit `35ece3b5`,
  issue #48).

  [internal] **[confirmed]** `deferred_reporter_base::operator<<`
  (`inlines/deferred-reporter-inlines.h` line 128) passes every
  non-arithmetic message to `std::string::append()`, which must not be
  called with a null pointer; `t.expect (true) << message`, with a null
  `const char*` (or `char*`) `message`, ends with a segmentation fault
  in `strlen()` (confirmed with AddressSanitizer). Found while fixing
  #13, whose `expression_formatter` and `reporter` overloads now write
  `"nullptr"` for a null C string; append `"nullptr"` here too, for the
  types that are pointers to `char`. Added after the review; the number
  follows the last item, so that the existing references stay valid.

- **#66 — A user type with a member named `value` changes the result of
  comparisons.**
  [internal] **[confirmed]** `type_traits::has_value` accepts any type
  with a member named `value` (`type-traits.h` line 410), and the
  `compare_op` constructor then compares `Lhs_T::value` and
  `Rhs_T::value` (`inlines/detail-inlines.h` lines 360 to 364), instead
  of the operands. With

  ```cpp
  namespace user {
    struct tagged {
      static constexpr int value = 1;
      int v;
      constexpr bool operator== (const tagged& o) const { return v == o.v; }
    };
    struct named { int value; bool operator== (const named&) const = default; };
  }
  ```

  `mt::eq (user::tagged{ 1 }, user::tagged{ 2 })` is true, while the
  type's own `operator==` says false, and `mt::eq (user::named{ 1 },
  user::named{ 1 })` does not compile (`invalid use of non-static data
  member 'value'`). The standard types with a static `value`, such as
  `std::integral_constant`, take the same path, harmlessly. Restrict the
  shortcut to the framework types (`type_traits::is_op`), as for `get()`
  in #5. Found while fixing #53; the number follows the last item.

## 2. Structure and layering

- **#15 — Internal state of the public classes can be modified by
  users.**
  (fixed) `totals()` returns only a `const` reference; the framework
  updates the protected `totals_` directly. The `own_index (size_t)`
  setter and `increment_subtest_index()` are protected, and `runner`,
  `static_runner`, and `detail::deferred_reporter_base` are friends of
  `runnable_base`. Unlike the recommendation, the read-only getters
  (`own_index()`, `current_subtest_index()`,
  `children_subtests_count()`) remain public, since the reporters use
  them and friendship is not inherited by derived reporters; they do not
  modify the state. `run()` is still public; `runner()` was later
  renamed `test_runner()` and made protected (see #32);
  `suite::timings()` and `reporter()` were later made protected
  (see #17 and #18) (commit `3bd15439`, issue #49).

  [breaking] **[confirmed]** Every `subtest` and `suite` inherits
  public members that exist only for the framework:
  `own_index (size_t)`, `increment_subtest_index()`,
  `current_subtest_index()`, `children_subtests_count()`, and a mutable
  `totals()` (`test.h` lines 229, 351 to 398). Inside a test,
  `t.own_index (99); t.totals ().increment_failed_checks (0);` compiles.
  Make them protected or private and grant access to the runner and the
  reporters (friendship, or a passkey type); keep only `name()`,
  `test()`, `expect()`, `assume()`, and read-only totals public.

- **#16 — The constructors of `subtest`, `suite`, and `top_suite` are
  public.**
  (fixed) The `subtest` and `top_suite` constructors are private, with
  `suite` and `runner`, respectively, as friends. Unlike the
  recommendation, the `suite` constructor is protected, not private,
  since `top_suite` and `static_suite` derive from it; `runner` is a
  friend. `std::make_unique()` cannot access these constructors, so
  `runner::suite()` and `test()` allocate the nodes with `new`
  (commit `9253f119`, issue #50).

  [breaking] They take internal parameters: `own_index`,
  `nesting_depth`, and the parent suite (`test.h` lines 649 to 651, 844,
  and 987). A user who writes `mt::suite s{ "name", runner, fn };`
  obtains a suite that is never registered and never run, without any
  diagnostic. Make these constructors private (friend `runner` and
  `suite`), so that `runner::suite()`, `suite::test()`, and
  `static_suite` are the only entry points.

- **#17 — Public signatures expose `detail` types.**
  (fixed) `runner_totals` was moved to the public namespace, without a
  `detail` alias, since the tests read their own counters through
  `totals()`. `suite::timings()`, `runner::timings()`, and
  `reporter::expression()` are protected: `runner`, `reporter_human`,
  and `reporter_tap` are friends of `suite`; the two reporters are
  friends of `runner`; `subtest` and `detail::deferred_reporter_base`
  are friends of `reporter`. `timestamps` and `colours` remain in
  `detail`. The other exposures are deliberate and were not changed:
  the applications use the formatter only through the public
  `expression_formatter` alias and its `operator<<`, and never construct
  one, so its `detail::colours&` constructor parameter is not part of
  their interface; `expect()` and `assume()` return an unspecified type
  through `auto`, a common idiom for expression results; and the
  `detail` base classes only supply the inherited members
  (commit `4d893432`, issue #51).

  [breaking] `suite::timings()` and `runner::timings()` return
  `detail::timestamps&`, `totals()` returns `detail::runner_totals&`,
  `reporter::expression()` returns `detail::expression_formatter&`, the
  formatter constructor takes `detail::colours&`, `expect()` returns a
  `detail::deferred_reporter` through `auto`, and the public classes
  derive from `detail::test_node` and `detail::runnable<>`. Either
  promote the types that users need (the totals, the formatter for
  user-defined types) to the public namespace, or make the accessors
  non-public. Same as WEBSITE-API-REVIEW #48.

- **#18 — The reporter interface is public, but neither extensible nor
  meant for users.**
  (fixed) `reporter`, `reporter_human`, `reporter_tap`, and the `endl`
  and `indent()` manipulators were moved to `detail`; custom reporters
  are not supported, and the reporter is still selected with
  `--reporter`. The `verbosity` enumeration remains public, and the new
  `runner::verbosity()` replaces `runner.reporter ().verbosity ()`, the
  only use of the reporter by the applications. `runner::reporter()`
  and `runnable_base::reporter()` are protected, with
  `detail::runnable_base` a friend of `runner`. The protocol members of
  `detail::reporter` (`pass()`, `fail()`, the `begin_*()`/`end_*()`
  functions, and the output functions) remain public within `detail`
  (commit `aedc6117`, issue #52).

  [breaking] The runner creates one of two built-in
  reporters, selected by a string (`src/runner.cpp` lines 250 to 268).
  Meanwhile `reporter` publishes the protocol between the runner, the
  checks, and the reporter: `pass()`, `fail()`, `begin_session()` to
  `end_subtest()`, `write_buffer_to_console()`, `flush()`, `endline()`,
  and `expression()` (`reporter.h` lines 231 to 509). Either move the
  reporters to `detail` and keep only the selection public, or support
  custom reporters (a factory or an instance passed to `initialise()`)
  and separate the user-facing part from the internal protocol.
  Overlaps WEBSITE-API-REVIEW #49.

- **#19 — The command line is parsed in two places, with two error
  policies.**
  (fixed) All options are parsed once, by `runner::parse_options_()`,
  into a `detail::options` structure (the selected reporter, the
  verbosity, the output file path, and a `std::span` view of `argv`),
  which is passed to the reporter constructors; the reporter no longer
  parses the command line. Unlike the recommendation, unknown options
  are still silently ignored: the applications receive the same `argv`
  and may define their own options, and the test command lines place
  the application arguments before the µTest++ options, so a stricter
  policy would require reordering all of them. A missing option
  argument and an unknown reporter name still terminate the program
  (see #21). The structure was made public by #20 (commit `f9a962b5`,
  issue #53).

  [breaking] The runner parses `--reporter`
  (`src/runner.cpp` lines 223 to 247); the reporter constructor parses
  `--verbose`, `--quiet`, `--silent`, and `--output-file`
  (`src/reporter.cpp` lines 89 to 131). Unknown options, including
  misspelt ones such as `--verbos`, are silently ignored, while a
  missing option argument terminates the program. As a consequence, the
  reporter constructor takes the whole argument vector as a
  `std::unique_ptr<std::vector<std::string_view>>` (see #51). Parse all
  options once, in the runner, into an options structure, pass that
  structure to the reporter, and report unknown options consistently.

- **#20 — The runner cannot be configured without a command line.**
  (fixed) The options structure of #19 is public, as `runner_options`
  (with the `reporter_kind` enumeration, and `verbosity`, moved there),
  in the new `runner-options.h`. The new `initialise (const
  runner_options&, const char* top_suite_name)` creates the reporter
  and starts the session; `initialise (argc, argv, top_suite_name)`
  parses the command line with `parse_options_()` and calls it. Without
  arguments, the top suite is named "default suite". The reporter now
  keeps a copy of the output file path, and an empty path writes no
  file, so the strings referred to by the options need to live only
  until `initialise()` returns. Covered by the unit test "Runner
  options" (commit `badcf376`, issue #54).

  [internal] `initialise (int argc, char* argv[], ...)` is the only way
  to select the reporter, the verbosity, or the output file. Embedded
  targets without semihosting arguments must build a fake `argv`. Add
  an overload taking the options structure of #19; the `argv` overload
  becomes a parser in front of it.

- **#21 — The library terminates the process in many places.**
  (fixed) The option errors (an unknown reporter name, a missing option
  argument, and an output file that cannot be opened) are reported on
  `stderr` and the option is ignored; the tests are still run, and
  `run()` returns 2. The failed assumptions and the reporters' buffer
  check go through `runner::abort()`, which calls the handler set by the
  new `runner::set_abort_handler()` (it returns the previous one, as
  `std::set_terminate()` does), and `::abort()` only if there is no
  handler or it returns. `compute_elapsed_time()` returns zero without
  timestamps, instead of the `assert()`. Covered by the unit tests
  "Runner option errors" and "Abort handler" (commit `ad4a1a9c`, issue
  #55).

  [internal] `exit (1)` is called for option errors (`src/runner.cpp`
  lines 244 and 267, `src/reporter.cpp` lines 127 and 143), `::abort()`
  for failed assumptions and the buffer check of #1 (`src/runner.cpp`
  line 407, `src/reporter-human.cpp` line 422, `src/reporter-tap.cpp`
  line 410), and `assert()` in `timestamps::compute_elapsed_time()`
  (`src/timings.cpp` line 187). A test framework should report and let
  the application decide. Return an error from `initialise()` (or make
  `exit_code()` non-zero), and route the remaining fatal cases through
  one overridable hook, which is useful on embedded targets anyway.

- **#22 — `assume()` aborts the whole program, and its name means
  something else elsewhere.**
  (fixed) The operation is now `require()`, as `REQUIRE()` in Catch2
  and doctest and `BOOST_REQUIRE()` in Boost.Test; `assume()` remains
  as a deprecated alias. When exceptions are enabled, a failed
  `require()` stops only the current test case, as the fatal assertions
  of these frameworks and `ASSERT_*` in GoogleTest do: the destructor
  of the deferred reporter (now `noexcept (false)`) throws
  `detail::failed_requirement`, not derived from `std::exception`, and
  `subtest::run()` catches it; it does not throw during stack unwinding,
  for a result kept in a variable. Without exceptions, it still aborts
  the test execution with `runner::abort()`, as Catch2 does (it calls
  `std::terminate()`). The Doxygen group is renamed to Requirements,
  and the user guide compares the fatal checks of the other frameworks
  (including Boost.UT, whose `fatal` calls `std::exit()`). Covered by
  the unit tests "Failed require", "Failed deprecated assume", "Failed
  require in nested test case", and "Failed require during unwinding"
  (commit `3ee4a3f6`, issue #56).

  [breaking] A failed `assume()` calls
  `runner::abort()`, which calls `::abort()`
  (`src/deferred-reporter.cpp` lines 121 to 126, `src/runner.cpp` lines
  397 to 408): the remaining test cases and suites do not run, and no
  summary is printed. In JUnit, Hypothesis, and similar frameworks, an
  unmet assumption skips the current test, which is the opposite. Name
  the operation after its effect (`require()`, or
  `expect (...) << fatal` as in Boost.UT), and, when exceptions are
  available, stop only the current test case (throw a private exception,
  caught in `subtest::run()`); keep the abort for builds without
  exceptions.

- **#23 — The runner is a `test_node` without a meaningful name.**
  (fixed) `runner` no longer derives from `detail::test_node`; it owns a
  `runner_totals` member, with its own read-only `totals()` accessor,
  used by the reporters for the session summary and by the tests.
  `runner::name()` is removed; the name shown in the reports remains
  that of the top suite. `test_node` is now the base of the suites and
  the test cases only (commit `06a6783e`, issue #57).

  [breaking] `runner` derives from `detail::test_node` to reuse the name
  and the totals (`runner.h` line 146), but its name is the constant
  `"runner"` (`src/runner.cpp` lines 110 and 124), and the user-visible
  name belongs to the top suite. Use composition: the runner owns a
  totals object; `name()` disappears from the runner.

- **#24 — `runnable<Self_T>` is not CRTP, and `static_suite` bypasses
  it.** (fixed) The `detail::runnable` template is removed; `subtest` and
  `suite` derive directly from `detail::runnable_base`, which declares
  the pure virtual `run()`, and each stores its body in its own
  `std::function`, built by the `detail::bind_callable()` helper.
  `static_suite` stores its body in the callable inherited from `suite`,
  via a wrapper that converts the reference to `static_suite&`, so its
  callable signature is unchanged (see #25); its `run()` override and
  second callable are removed (commit `b55760e6`, issue #58).

  [internal] The template parameter only selects the type of the
  stored `std::function` (`test.h` line 598); nothing casts to `Self_T`.
  `static_suite` derives from `suite`, so it inherits
  `std::function<void (suite&)>`, passes `nullptr` to it
  (`inlines/test-inlines.h` line 476), and adds a second
  `std::function<void (static_suite&)>` (`test.h` line 1162), with a
  `run()` copied from `suite::run()`. Store the callable once in
  `runnable_base` (as `std::function<void (Self&)>` with a single `Self`
  per hierarchy), and remove the template layer and the duplicate
  `run()`.

- **#25 — The suite callables have different signatures.** (fixed)
  The `static_suite` constructor passes the callable and its arguments
  to the `suite` constructor unchanged, so the callable receives
  `suite&`, as for the suites registered with `runner::suite()`; the
  conversion wrapper and the second template parameter of
  `detail::bind_callable()` are removed. The sample programs and the
  user guide now use `suite&`, and the change is listed in the
  compatibility notices (issue #59).

  [breaking] A suite registered with `runner::suite()` receives `suite&`; a
  `static_suite` receives `static_suite&` (`test.h` lines 844 and 1093).
  The same function cannot serve both, which is why
  `tests/sources/suite/src/main.cpp` line 53 and
  `tests/sources/suite/src/suite.cpp` line 55 define two. Pass `suite&`
  in both cases.

- **#26 — Two runner classes and a workaround registry for static
  suites.** (fixed) The static suites are kept in an intrusive list,
  sorted by name, whose head is a `constinit` pointer
  (`static_suite::first_`), so the list does not depend on the runner
  object; a suite inserts itself in its constructor and removes itself
  in its destructor, with no allocation. `static_suite` takes a
  `runner&`, which it only refers to; any runner runs, after its
  registered suites, the static suites that refer to it, and counts
  them with `static_suites_count()`. The `static_runner` class, its
  `register_static_suite()`, and the `detail::to_runner()` and
  `detail::register_static_suite()` helpers are removed; `static_runner`
  remains as a deprecated alias of `runner`, so the existing code
  compiles unchanged (issue #60).

  [breaking] Static suites need `static_runner`; their
  registration writes through a raw owning pointer
  (`std::vector<static_suite*>*`, `runner.h` line 567, `new`/`delete` in
  `src/runner.cpp` lines 475 to 480 and 585) into an object whose
  constructor may not have run yet; and the incomplete type is worked
  around by two `detail` free functions (`detail::to_runner()`,
  `detail::register_static_suite()`) plus a public static
  `static_runner::register_static_suite()`. A registry independent of
  the runner object (a function-local static, or an intrusive list with
  a `constinit` head pointer) removes the undefined behaviour, the
  helpers, and the need for a second runner class. Overlaps
  WEBSITE-API-REVIEW #55 and #87.

- **#27 — Execution order and timing are implicit.** (fixed)
  `run()` merges the suites registered with `runner::suite()`, sorted
  by name with a stable sort, with the list of static suites, already
  sorted by name, so all the suites other than the top suite run in a
  single name order; for equal names, the registered suites run first,
  in the order of their registration. The test cases of the top suite
  still run immediately, since the top suite is open from
  `initialise()` to `run()`, and the static suites cannot run in
  registration order, which is unspecified across translation units.
  The name `runner::suite()` is kept; its documentation states that the
  suite only runs at `run()`. The expected outputs of the `unit` test
  are reordered (issue #61).

  [internal] **[confirmed]** Test cases added to the top suite run immediately;
  suites added with `runner::suite()` run later, sorted by name; static
  suites run after them, sorted separately (`src/runner.cpp` lines 321
  to 333 and 531 to 544). The registration order is lost (the probe
  registered "Zeta" and then "Alpha"; "Alpha" ran first), and
  `suite::test()` and `runner::suite()` look alike but differ in when
  the body runs. Choose one rule (registration order, or one name order
  across all suites), state it in the API names (for example
  `runner::add_suite()`), and keep the two kinds of suites in one list.

- **#28 — Two public headers do not compile on their own.** (fixed)
  `function-comparators.h` and `exceptions.h` include `detail.h`, so
  every public header now compiles on its own (issue #62).

  [internal] **[confirmed]** `function-comparators.h` (20 errors) and
  `exceptions.h` (8 errors) use `detail::eq_`, `detail::throws_`, and
  the others without including `detail.h`; they compile only after the
  umbrella header has included `detail.h`. All other headers compile on
  their own. Include `detail.h` in both.

- **#29 — `utility::is_match()` is used only by the tests.** (fixed)
  The runner accepts `--filter=<pattern>` and `--filter <pattern>`, and
  `runner_options::filter_patterns`, with the semantics of `--grep` in
  node-tap: the option may be repeated, one pattern per nesting level
  (the first for the suite names, the second for the test cases, and
  each further one for the nested test cases); within a pattern, `|`
  separates alternatives, each matched by `is_match()`. The suites and
  the test cases that do not match are not run, keep their index, and
  are reported by the new `reporter::skip_suite()` and
  `reporter::skip_subtest()` (`ok <n> - <name> # SKIP filtered` in TAP);
  they are counted by `runner::skipped_suites_count()` and the new
  `runner_totals::skipped_subtests()`, and the suite and totals lines
  show `, <n> skipped` after the respective counts only when not zero,
  so the output without a filter is unchanged. The top suite is never
  skipped as a whole, but its test cases are filtered, including by its
  name. `is_match()` is rewritten iteratively, with constant stack usage
  and `O(n * m)` time. Covered by the unit test "Runner filter" and new
  `is_match()` checks (issue #63).

  [internal] The wildcard matcher (`src/utility.cpp` line 130) is called only by
  `tests/sources/unit/src/utility.cpp`. Give it a purpose: a
  `--filter=<pattern>` option (also `--filter <pattern>`), parsed by
  `runner::parse_options_()`, that runs only the suites whose names
  match, tested in the single loop of `runner::run_suites_()` (both
  added after this review; `src/runner.cpp` lines 282 and 417 at
  commit `395c980d`). The option may be repeated, and a suite runs
  when it matches any of the patterns; this is an exception to the
  rule that the last occurrence of an option takes effect, and must be
  documented as such. Repetition is preferred to a comma-separated
  list: it needs no delimiter, so names containing commas remain
  selectable, and it does not need `utility::split()` (see #65). A
  suite that does not match is reported as skipped (in TAP,
  `ok <n> - <name> # SKIP filtered`), so that the plan and the
  numbering stay valid. The test cases of the top suite run in
  `main()`, outside the runner, and are not filtered; document this.
  Matching is case-sensitive and applies to the whole name. Before
  relying on it on embedded targets, rewrite `is_match()` iteratively:
  it recurses once per input character, with a backtracking loop for
  each `*`. Split from the original #29; the rest is now #65.

- **#65 — Unused or test-only helpers in public namespaces.** (fixed)
  `type_traits::list`, `type_traits::identity`,
  `type_traits::function_traits`, `detail::assertion`, `mut()`, and
  `detail::genuine_integral_value` (with its `expression_formatter`
  overload) are removed, with the static assertions of
  `function_traits`. As decided, `utility::split()` and
  `utility::is_match()` stay public in `utility`, as test helpers, and
  `is_match()` is not moved to `detail`. The compatibility notices list
  the removed public names (commit `f58dff49`, issue #95).

  [breaking] `utility::split()` is used only by
  `tests/sources/unit/src/utility.cpp`; `type_traits::list`,
  `type_traits::identity`, and `type_traits::function_traits` only by
  `tests/sources/unit/src/static-asserts.cpp`; `detail::assertion`
  (`detail.h` line 127) is unused; `mut()`, a public `const_cast`
  (`function-comparators.h` line 332), is unused; and
  `detail::genuine_integral_value` (in `type_traits` before #30) is
  never created, although `expression_formatter` has an overload for
  it. Remove them, with their tests; once #29 is implemented, move
  `is_match()` to `detail`. Split from #29. Overlaps WEBSITE-API-REVIEW #52.

- **#30 — `type_traits` holds value types, not traits.** (fixed)
  As decided, `op`, `value_base_`, `integral_constant`,
  `floating_point_constant`, `genuine_integral_value`, and `value` are
  moved to `detail`, in the new `values.h` (with
  `inlines/values-inlines.h`, the former `type-traits-inlines.h`), which
  depends only on `math.h`; `type-traits.h` includes it for the `is_op`
  concept, and keeps only the traits and the concepts. The floating
  point specialisation of `value` is constrained by
  `std::floating_point`, and the `type_traits::is_floating_point`
  concept, used only there, is removed. The `to_*` and `_*` aliases, the
  literals, and the `to_t` and `_t` templates are unchanged, except for
  the namespace of their base (issue #64).

  [breaking] Besides concepts and traits, the namespace holds the wrapper types that
  users actually create: `value`, `integral_constant`,
  `floating_point_constant`, and the tag `op` (`type-traits.h` lines 379
  to 851). A reader looking for `to_i`'s type does not expect it in
  `type_traits`. Move the value types to a namespace of their own (or to
  `detail`, since users name them only through `to_*` and the literals).

- **#31 — `math` exposes literal-parsing internals.** (fixed)
  The whole `math` namespace is moved to `detail::math`, including
  `integer()` and the helpers already marked internal by their trailing
  underscore (`count_literal_digits_()`, `parse_integer_literal_()`, and
  `integer_literal_t_`). The literal operators qualify their calls with
  `detail::math::`; the value wrappers and the comparisons, already in
  `detail`, are unchanged. No deprecated aliases are kept, as for #30.
  Covered by the static assertions in `static-asserts.cpp` (commit
  `d9767eff`, issue #66).

  [breaking] `math::abs()`, `math::min_value()`, `math::pow()` (integer exponents
  only), `math::num()`, `math::den()`, and two `math::den_size()` are
  implementation details of the literals and the comparisons
  (`math.h` lines 105 to 217), with names that suggest general
  mathematical functions. Move them to `detail`.

- **#64 — `test_node` has a single derived class.** (fixed)
  `detail::test_node` is removed; its `name_` and `totals_` members and
  their `name()` and `totals()` getters are moved to
  `detail::runnable_base`, which is now the single base of the suites
  and the test cases. The forward declaration in `detail.h` (the
  remaining part of #57) is removed, and `top_suite` exposes the getter
  with `using detail::runnable_base::name;` (commit `c53c45c8`,
  issue #68).

  [internal] Since #23, `runner` no longer derives from `detail::test_node`, and
  `detail::runnable_base` is its only derived class (`test.h` lines 231
  and 363). The split no longer separates anything: `test_node` holds
  the name and the totals, with their getters (`src/test.cpp` lines 82
  and 95, `inlines/test-inlines.h` lines 150 and 160), and
  `runnable_base` the rest of the state of the same nodes. Merge the
  two classes: move `name_`, `totals_`, `name()`, and `totals()` into
  `runnable_base`, remove `test_node` and its forward declaration in
  `detail.h` (line 85, the remaining part of #57), and update the
  `using detail::test_node::name;` declaration of `top_suite`
  (`test.h` line 1220). Together with #24, which removes the
  `runnable<Self_T>` layer, the suites and the test cases would derive
  from a single base class.

## 3. Naming and consistency

- **#32 — Member functions named after classes.** (fixed)
  `runnable_base::runner()` is renamed `test_runner()`, following the
  noun style of the other accessors rather than a `get_` prefix, and
  made protected, since only the derived suites and test cases, and the
  runner, a friend, call it. The constructor parameters named `runner`
  are renamed `test_runner` as well, since they also hid the class; the
  `class runner` specifiers are gone from `test.h`,
  `inlines/test-inlines.h`, and `src/test.cpp` (commit `59698efd`,
  issue #65). As decided, `runner::suite()` keeps its short name, since
  it is the call that users write most often, and the `class suite`
  specifiers in `runner` remain; `runner::reporter()`,
  `runnable_base::reporter()`, `reporter::verbosity()`, and
  `runner::verbosity()` keep their names as well.

  [breaking] `runner::suite()`, `runner::reporter()`,
  `runnable_base::reporter()`, `runnable_base::runner()`, and
  `reporter::verbosity()` hide the class and enumeration names inside
  these classes, so the code needs elaborated type specifiers
  throughout (`class suite& initialise (...)`,
  `class reporter& reporter (...)`, `enum verbosity verbosity_`). Rename
  them, for example `add_suite()`, `get_reporter()`, `get_runner()`,
  `get_verbosity()`. Same as WEBSITE-API-REVIEW #50. Note that the
  `runner::verbosity()` added by the fix of #18 follows the same
  pattern, and should be renamed together with `reporter::verbosity()`.

- **#33 — Three names for a test case.** (fixed) As decided, "test
  case" is the term of the API, and `test()` keeps its name. The
  `subtest` class is renamed `test_case`; the `runner_totals` counters
  are `executed_test_cases()`, `failed_test_cases()`, and
  `skipped_test_cases()`; `children_subtests_count()` is
  `child_test_cases_count()`; the reporter notifications are
  `begin_test_case()`, `end_test_case()`, and `skip_test_case()`; and
  the internal names (`child_test_cases_`, `after_test_case_create_()`,
  `open_test_cases_`) follow. No deprecated aliases are kept. The
  output of the reporters is unchanged, including the `# Subtest:`
  lines of TAP; the names of the existing tests, in string literals,
  are unchanged as well. The compatibility notices list the renames
  (commit `f28083ac`, issue #69).

  [breaking] The class is
  `subtest`, the function that creates one is `test()`, the counter is
  `executed_subtests()`, and the reporters print "test case"
  (`src/reporter-human.cpp` line 212). Choose one term for the API; if
  the class remains `subtest` (TAP's term), name the counter after it
  and use "test case" only in the text. Overlaps WEBSITE-API-REVIEW #56.

- **#34 — `subtest_index` counts TAP test points.** (fixed)
  `current_subtest_index()` is renamed `test_point_number()`,
  `increment_subtest_index()` `next_test_point_number()`, and the member
  `test_point_number_`. The side effect in the constructor of a check
  result had already been moved to the destructor of the deferred
  reporter, where the check is reported (see #4). Fixed together with
  #33 (commit `f28083ac`, issue #69).

  [internal] `increment_subtest_index()` is called by every check
  (`src/deferred-reporter.cpp` line 82) and by every nested test case
  (`inlines/test-inlines.h` line 302), and `current_subtest_index()` is
  printed as the TAP test point number (`src/reporter-tap.cpp` lines 575
  and 615). Rename both after what they count
  (`next_test_point_number()`, `test_point_number()`); the constructor
  of a check result should not have this side effect hidden in it.

- **#35 — `runner_totals` is not specific to the runner.** (fixed)
  As decided, the class is renamed `counters`, not `totals`, which would
  be hidden by the `totals()` accessor inside `runner` and
  `runnable_base` (the problem of #32); the accessor keeps its name.
  The files are renamed `counters.h`, `inlines/counters-inlines.h`, and
  `src/counters.cpp`, and `was_successful()` is renamed `passed()`. The
  counter is already `executed_test_cases()` (#33). No deprecated
  aliases are kept; the compatibility notices list the renames
  (commit `0fbf32a3`, issue #70).

  [breaking]
  Every test case, suite, and runner owns one (`test.h` line 259). Name
  it `totals` (or `counters`); also consider `passed()` instead of
  `was_successful()` (the only past-tense accessor) and
  `executed_test_cases()` (see #33).

- **#36 — The timing vocabulary is inconsistent.** (fixed) The
  `timestamp` and `timestamps` classes are replaced by one
  `detail::stopwatch` with `start()`, `stop()`, `has_elapsed()`, and
  `elapsed()`, which returns a `std::chrono::microseconds`; the
  reporters split it into milliseconds and microseconds for printing. A
  zero reading means both "not read" and "no clock", so the
  `std::optional` members, `has_begin()`, `has_end()`, `has_clock()`,
  and the `timespec` overloads of the operations are gone. The
  `timings()` accessors are renamed `stopwatch()`, and the files are
  renamed `stopwatch.h`, `inlines/stopwatch-inlines.h`, and
  `src/stopwatch.cpp`. The accessors were already protected and the
  class is in `detail`, so only the compatibility notices mention the
  rename (commit `0fbebfa8`, issue #71).

  [breaking] The header
  is `timings.h`, the classes are `timestamp` and `timestamps`, the
  accessors are `timings()`, the operations are `timestamp_begin()` and
  `timestamp_end()` (nouns used as verbs), `has_clock()` means "the value
  is not zero" (`src/timings.cpp` lines 86 to 90), and
  `compute_elapsed_time (uint32_t&, uint32_t&)` returns its result
  through two output parameters. A `stopwatch` with `start()`,
  `stop()`, `has_elapsed()`, and `elapsed()` returning a small structure
  (or `std::chrono::microseconds`) says the same in fewer concepts.

- **#37 — `deferred_reporter` is not a reporter.** (fixed) The
  `deferred_reporter_base` and `deferred_reporter` classes are merged
  into one `detail::check_result`. Its template constructor delegates to
  a private non-template constructor, so the code shared by all
  expression types (that constructor and the destructor, which does the
  reporting) is still compiled once, in `src/check-result.cpp`; the
  base class added nothing to this. The message member is renamed
  `message_`, and the files are renamed `check-result.h`,
  `inlines/check-result-inlines.h`, and `src/check-result.cpp`
  (commit `dc890c5b`, issue #72).

  [internal] It is the
  result of one check, which reports itself when destroyed
  (`deferred-reporter.h` lines 111 to 291). The split into
  `deferred_reporter_base` and `deferred_reporter`, whose only addition
  is a template constructor, has no purpose. Merge the two into one
  class named after its role (`check_result`, or `expectation`).

- **#38 — The name suffixes are used inconsistently.** (fixed) The
  expression types in `detail` are renamed `unary_op`, `binary_op`,
  `callable_op`, `eq_op`, `ne_op`, `gt_op`, `ge_op`, `lt_op`, `le_op`,
  `and_op`, `or_op`, `not_op`, `throws_op`, and `nothrow_op`; the other
  internal types and functions drop the suffix (`value_base`,
  `c_string`, `unwrap()`, `within_tolerance()`, `append_number()`,
  `to_printable_pointer()`, `as_operand()`, `count_literal_digits()`,
  `integer_literal`, and `parse_integer_literal()`), and the types with
  `_t` are renamed `session_state`, `open_test_case`, and
  `indentation`. `value_base::value_` is now private. The protected
  `test_runner_()`, `reporter_()`, and `next_test_point_number_()`
  take the suffix; the protected `own_index (size_t)` setter and the
  `suite::stopwatch()`, `runner::reporter()`, `runner::stopwatch()`,
  and `reporter::expression()` accessors are removed, and their callers,
  all friends or derived classes, use the data members directly
  (commit `fee79766`, issue #73).

  [internal] The trailing underscore marks non-public members, public members, and
  internal types and functions, and some types carry a `_t` suffix
  while most do not. The rules are:

  - The trailing underscore marks the non-public (private and
    protected) data members, static data members included, and member
    functions, and nothing else.
  - Types, type aliases, and enumerators do not take it, whatever their
    access; the access specifier at the declaration is enough, and a
    type named like a data member would clash with it.
  - Internal types and functions at namespace scope are marked by the
    `detail` namespace, not by the spelling.
  - Types and type aliases have plain names, without a `_t` suffix, as
    most of them already do (`stopwatch`, `counters`,
    `check_result`). The `_t` suffix used to keep a type apart from a
    data member of the same name, which the trailing underscore of the
    data member now does. The exceptions are the names required by
    the standard conventions (`value_type`, `result_type`, `type`) and
    the public `runner::abort_handler_t` (`runner.h` line 379), kept
    to avoid a breaking change.

  The non-conforming uses are:

  - Namespace-scope types and functions in `detail` with the suffix:
    `unary_op_`, `binary_op_`, `eq_`, `ne_`, `gt_`, `ge_`, `lt_`,
    `le_`, `and_`, `or_`, `not_`, `callable_op_`, `throws_`,
    `nothrow_`, `c_string_`, `unwrap_()`, `within_tolerance_()`,
    `append_number_()`, `to_printable_pointer_()`, and `as_operand_()`
    (`detail.h`), `value_base_` (`values.h` line 127), and
    `detail::math::count_literal_digits_()`, `integer_literal_t_`, and
    `parse_integer_literal_()` (`math.h` lines 174, 253, and 294).
    Dropping the suffix is not enough for `and_`, `or_`, and `not_`,
    since `and`, `or`, and `not` are alternative tokens; a common
    suffix for all the expression types (`eq_op`, `and_op`, and so on)
    keeps them uniform. `integer_literal_t_` carries both suffixes,
    and becomes `integer_literal`.
  - A public data member with the suffix: `value_base_::value_`
    (`values.h` line 169).
  - Protected member functions without the suffix:
    `runnable_base::test_runner()`, `own_index()` (both overloads),
    `reporter()`, and `next_test_point_number()` (`test.h` lines 389
    to 437), `suite::stopwatch()` (`test.h` lines 995 and 1008),
    `runner::reporter()` and `runner::stopwatch()` (`runner.h` lines
    529 to 557), and `reporter::expression()` (`reporter.h` line 570).
    The last five are accessors of members named `stopwatch_`,
    `reporter_`, and `expression_`, so adding the suffix clashes; the
    class and its friends can use the data members directly, and the
    accessors can be removed, unless a derived class needs them.
  - Types with the `_t` suffix: `runner::session_state_t` (`runner.h`
    line 709) and `reporter_human::open_test_case_t`
    (`reporter-human.h` line 366) become `session_state` and
    `open_test_case`, which no longer clash with the data members
    `session_state_` and `open_test_cases_`. `detail::indent_t`
    (`reporter.h` line 127) cannot become `indent`, since the
    manipulator function `indent (size_t)` that returns it would hide
    the type name; `indentation` avoids this.

  The private and protected data members, the other non-public member
  functions, and the nested types (apart from the `_t` suffix) already
  conform. `to_t` and `_t` (`literals.h`) are names of the `to_*` and
  `_*` families, not uses of the suffix; see #40.

- **#39 — `_not()`, `_and()`, and `_or()` stand apart from the other
  comparators.** (fixed) The logical functions are renamed `negate()`,
  `both()`, and `either()`; the old names are not kept, and the
  compatibility notices list the renames. The internal expression types
  keep their names (`not_op`, `and_op`, and `or_op`). The functions take
  only one or two operands, which the new names express. The trailing
  underscore suggested below is no longer possible, since #38 reserves
  it for the non-public members, and `not_op()`, `and_op()`, and
  `or_op()` would repeat the names of the internal types they return
  (commit `a04d37f8`, issue #74).

  [breaking] The six comparisons are `eq()`, `ne()`, and
  so on, while the logical functions use a leading underscore
  (`function-comparators.h` lines 285, 301, and 317). A leading
  underscore followed by a lowercase letter is reserved only in the
  global namespace, so the names are valid, but no other public name
  uses this spelling. Use a
  trailing underscore (`not_()`, `and_()`, `or_()`, as Boost.Hana does)
  or descriptive names, and rename the internal structures accordingly.

- **#40 — Three spellings for the same wrapper.** (fixed) The 23 `_*`
  type aliases and the generic `_t<T>` wrapper, deprecated since 3.2.0,
  are removed; the `to_*` forms and the literals remain. The unit tests
  use the `to_*` forms, and the compatibility notices list the removed
  names (commit `71f0d26f`, issue #75).

  [breaking] `_i` is a
  literal operator (`literals.h` line 133) and also a type alias in
  `micro_test_plus` (line 524), next to the newer `to_i` (line 816);
  `_t` and `to_t` are two identical structures (lines 723 and 1048). The
  old spellings are deprecated only in comments. Keep `to_*` and the
  literals, and remove the `_*` aliases and `_t` (see #41). Overlaps
  WEBSITE-API-REVIEW #54.

- **#41 — Deprecated entities carry no `[[deprecated]]` attribute.**
  (fixed) The `_*` aliases and `_t` were removed by #40. The
  `runner (const char*)` constructor (and thus `static_runner`), and
  the entities deprecated since, `exit_code()`, `assume()`, and the
  `static_runner` alias, now carry `[[deprecated]]`, with a message
  naming the replacement. The `empty` test passes the suite names to
  `initialise()`; the tests that check the deprecated entities on
  purpose silence `-Wdeprecated-declarations` locally. The
  compatibility notices mention the new warnings (commit `b0c6561a`,
  issue #76). Their removal remains for the next major release.

  [internal] The `_*` aliases, `_t`, and the `runner (const char*)` and
  `static_runner (const char*)` constructors (`runner.h` lines 170 and
  455) are deprecated in the comments only, so users get no warning;
  `tests/sources/sample/src/main.cpp` line 100 still uses the
  constructor. Add `[[deprecated ("use ...")]]`, then remove them in the
  next major release.

- **#42 — `get_comment_prefix()` is the only `get_` accessor.**
  (fixed) The pure virtual and its overrides in `reporter_human`,
  `reporter_tap`, and the unit test reporter are renamed
  `comment_prefix()`, and are `const`. The reporters are in `detail`, so
  no compatibility notice is needed (commit `66fd6880`, issue #77).

  [internal] All other accessors are bare nouns (`verbosity()`,
  `expression()`, `name()`). It is also a non-`const` virtual
  (`reporter.h` line 487). Rename it `comment_prefix()` and make it
  `const`.

- **#43 — `endl()`, `endline()`, and `flush()` do not do what their
  names say.** (fixed) `endl` and `indent()` were already in `detail`,
  moved with the reporters (commit `aedc6117`); they are not user API,
  since the users reach the reporter only through the message of
  `expect()`, which does not accept manipulators. The members are
  renamed `end_line()` and `flush_streams()`, and `end_line()` no longer
  flushes, so the callers, which flush at the end of each check, flush
  only once. The reporters are in `detail`, so no compatibility notice is
  needed (commit `420694bf`, issue #78).

  [internal] `endl` (a free function in the public
  namespace, `reporter.h` line 133) only appends a newline to the
  internal buffer and flushes the C streams; it does not output the
  line. `flush()` (`src/reporter.cpp` lines 412 to 420) flushes `stdout`
  and the file, but not the reporter's own buffer, which is written only
  at the end of a test case. The callers then flush twice
  (`src/reporter-human.cpp` lines 605 to 607). Move `endl` and `indent`
  to `detail`, and rename the members after their effect
  (`end_line()`, `flush_streams()`).

- **#44 — The type suffixes in failure messages do not match the
  literals.** (fixed) `signed char` values are written with the `sc`
  suffix, and `long double` values with `ld`, the names of the literals.
  As decided, `int` and `double` keep no suffix, but the floating-point
  values with an integral value are written with a decimal point
  (`42.0`, `42.0f`, `42.0ld`), so that they can be distinguished from
  the integers; the messages added with `<<` are unchanged. Covered by
  the unit test "Formatter number suffixes" (commit `55ba0be4`, issue
  #79).

  [internal] **[confirmed]** The formatter appends a suffix
  to most numbers (`src/expression-formatter.cpp` lines 124 to 284), but
  `signed char` prints as `5c`, while its literal is `_sc` and `c` means
  `char`; `long double` prints as `1.5l`, the same suffix as `long`;
  `int` and `double` print no suffix. Since `std::int8_t` is usually
  `signed char`, `_i8` values print with the `char` suffix. Use the
  literal names (`5sc`, `1.5ld`) consistently, or drop the suffixes.

- **#45 — Inconsistent declaration style.** (fixed) The empty
  parameter lists of the named functions and of the constructors are
  written `(void)`, as in the rest of µOS++; the destructors and the
  operators keep `()`. The overrides in the `final` reporter classes and
  in the test classes are written with `override` alone, without
  `virtual`. The `static_runner` part no longer applies, since
  `static_runner` is now an alias of `runner` (commit `96d63e7f`, issue
  #80).

  [internal] Empty parameter
  lists are written both ways in the same class (`name (void)` and
  `totals ()`, `test.h` lines 219 and 230); see also WEBSITE-API-REVIEW
  #67. In the `final` reporter classes, some overrides are
  `virtual ... override` and others only `override`
  (`reporter-human.h` lines 191 and 211), and
  `static_runner::total_suites_count()` is `virtual ... final override`
  in a `final` class (`runner.h` line 538). Use `override` alone.

- **#46 — Boolean parameters hide the meaning at the call site.**
  (fixed) `abort` is replaced by
  `detail::check_kind { expectation, requirement }`, in `check_result`
  and `output_fail_suffix_()`. The kind, the message, `has_expression`,
  and the location are grouped in `detail::failure_info`, held by
  `check_result` and passed to `fail()`;
  `fail_unexpected_exception_()` builds one with designated
  initialisers. The private `check_result` constructor initialises it
  positionally, since clang `-Weverything` rejects designated
  initialisers there (`-Wpre-c++20-compat-pedantic`). `fail()` takes a
  non-`const` reference until #47 makes the message `const`
  (commit `e37df158`, issue #81).

  [internal] `reporter::fail (bool abort, ..., bool has_expression, ...)`,
  `output_fail_suffix_ (..., bool abort, ...)`, and
  `check_result (expr, bool abort, ...)` are called with unlabelled
  flags: `expect()` and `require()` construct
  `check_result{ expr, false, ... }` and `check_result{ expr, true, ... }`
  (`test-inlines.h` lines 313 and 332), the destructor calls
  `fail (abort_, message_, expression_str, has_expression_, ...)`
  (`src/check-result.cpp` line 148), and
  `test_case::fail_unexpected_exception_()` calls
  `fail (false, message, expression, false, location_, *this)`
  (`src/test.cpp` line 311). Use an
  `enum class check_kind { expectation, requirement }` instead of
  `abort`, in `check_result`, `fail()`, and `output_fail_suffix_()`.
  Group the kind, the message, `has_expression`, and the location in a
  `detail::failure_info` struct, held by `check_result`, and pass it to
  `fail()` instead of the four separate parameters;
  `fail_unexpected_exception_()` then builds one with designated
  initialisers (`.kind = check_kind::expectation,
  .has_expression = false`).

- **#47 — Non-`const` references where `const` suffices.** (fixed)
  `reporter::pass()` and `fail()`, the four `output_*_` hooks, and the
  `begin_*`, `end_*`, and `skip_*` hooks take `const` references, in the
  base class and in both reporters, and the open test cases of
  `reporter_human` are kept as `const test_case*`. The expression
  formatter refers to the reporter's colours through a `const`
  reference. Since the reporters abort the program, from the test case
  they receive, when a top-level test case starts with a non-empty
  buffer, `abort()` is now `const`; it only delegates to the runner
  (commit `a84c9e75`, issue #82).

  [internal]
  `reporter::pass (std::string& message, ...)`, `fail (...,
  std::string& message, ...)`, the four `output_*_` hooks (which only
  read `message` and the test case), `expression_formatter (colours&)`,
  and the `begin_*`/`end_*` hooks (which only read their argument) take
  mutable references (`reporter.h` lines 362 to 660). Make them `const`.

## 4. Simplicity and duplication

- **#48 — Duplicated code.** (fixed) The selection sort and
  `static_suite::run()` had already gone with the merge of
  `static_runner` into `runner` and of the static suites into the
  runner's ordering; the remaining insertion sort is deliberate (it
  avoids `-Waggregate-return` from `std::stable_sort`), and the unused
  `<algorithm>` include is removed. `operator<< (indentation)` and
  `indent_size_` are defined once, in `reporter`; the elapsed-time
  message is built by `reporter::format_elapsed_time_()`; the pointers
  are formatted by `detail::append_pointer()`, which replaces
  `to_printable_pointer()`, and the unused `reporter::colour_()` is
  removed; the file name of a path is extracted only by
  `utility::extract_file_name()`, which `reflection::short_name()` now
  delegates to, so both separators are recognised everywhere (commit
  `9c61e33a`, issue #83).

  [internal] The same logic exists twice or
  more:
  - a hand-written selection sort, in `runner::run_suites_()` and
    `static_runner::run_suites_()` (`src/runner.cpp` lines 321 to 333
    and 531 to 544), while `<algorithm>` is included and unused;
    `std::ranges::stable_sort` with a projection replaces both;
  - `suite::run()` and `static_suite::run()` (`src/test.cpp` lines 257
    to 275 and 331 to 347);
  - `operator<< (detail::indent_t)` and `indent_size` in both reporters
    (`src/reporter-human.cpp` lines 123 to 136, `src/reporter-tap.cpp`
    lines 102 to 116); they belong in `reporter`;
  - the elapsed-time message, five times in the two reporters;
  - pointer formatting and `colour_()`, in `reporter` and
    `expression_formatter`;
  - the file name of a path, three times (`reflection::short_name()`,
    `utility::extract_file_name()`, and inline in
    `reporter::write_info_()`), with different handling of `\`; see
    WEBSITE-API-REVIEW #51.

- **#49 — The six comparison structures repeat the same pattern.**
  (fixed) `eq_op`, `ne_op`, `gt_op`, `ge_op`, `lt_op`, and `le_op` are
  replaced by one `detail::compare_op<Lhs_T, Rhs_T, Compare_T>`,
  parameterised by six tags (`equal_to`, `not_equal_to`, `greater`,
  `greater_equal`, `less`, and `less_equal`) that hold the operator,
  its symbol for the formatter, and the result within the tolerance;
  the formatter has one overload instead of six, and the unused default
  arguments and mismatched `using std::operator...` lists are gone.
  The tags are not the `std::ranges` comparators, whose constraints
  reject mixed-type comparisons that are valid today. The tag is passed
  as an empty constructor argument, so the call sites rely on deduction
  without a factory function; `apply()` is `[[gnu::always_inline]]`
  and the symbols are C strings, which keeps the debug builds within
  about 1% of the previous size and makes the release builds 1.3%
  smaller. As a side effect, a zero tolerance now compares exactly
  (`approx (1.5, 0.0)` was not equal to 1.5) (commit `ac6a2bb5`,
  issue #84).

- **#50 — The string and container operators are rarely selected.**
  (fixed) A probe showed that the premise for the string operators is
  inaccurate: they are selected whenever at least one operand is exactly
  a `std::string_view` (the other may be a `std::string`, a string
  literal, or a `char` pointer); only `std::string` with `std::string`
  or with a C string selects the standard operators. They are kept, and
  their documentation says when they apply. The container operators are
  removed: same-type containers always selected the standard operators
  (returning `bool`), and mixed containers failed to compile; `eq()` and
  `ne()` are recommended instead. The "Check containers with operators"
  sample, which silently used the standard operators, is removed, and
  the unit tests assert the selection at compile time. The Doxygen
  topic text claiming that `eq()` compares containers element by
  element is corrected; it uses the standard `==`, so `eq()` also
  rejects mixed container types (commit `9ab5f925`, issue #85).

  [breaking] `operators::operator== (std::string_view, std::string_view)`
  wins only when both operands are exactly `std::string_view`, and the
  container operators lose to the standard ones for same-type
  containers and fail to compile for mixed ones. Remove them and
  recommend `eq()`/`ne()`, or require a wrapped operand as for the
  other operators. Same as WEBSITE-API-REVIEW #53 and #84.

- **#51 — The reporter receives the arguments through a pointer to a
  vector.**
  (fixed) The reporter constructors take the `detail::options`
  structure of #19, which holds a `std::span<char* const>` view of
  `argv`, without allocations (commit `f9a962b5`, issue #53).

  [breaking] The constructors take
  `std::unique_ptr<std::vector<std::string_view>>` (`reporter.h` line
  214), which the runner builds from `argv` (`src/runner.cpp` lines 252
  to 260): two allocations and an ownership transfer for read-only data
  that `argv` already holds. Pass the options structure of #19, or a
  `std::span<const std::string_view>`.

- **#52 — Extra callable arguments are bound with `std::bind`.**
  (fixed) The variadic arguments are kept, since the samples and the
  user guide use them for parametrised suites; `bind_callable()` now
  stores them in a `mutable` lambda, with a C++20 pack init-capture,
  and calls the callable with `std::invoke`. The arguments are still
  copied, which the deferred suites need; the user guide now says so,
  and that a pointer or `std::ref()` refers to the caller's object.
  `std::ref()` is no longer unwrapped, so an `auto&` parameter receives
  the `std::reference_wrapper` (a compatibility notice says so). The
  GCC ARM `_Bind` workaround is no longer needed; the callable without
  arguments is still stored directly. The unit test "Callable
  arguments" covers copies, `std::ref()`, pointers, and a deferred
  suite (commit `7d846b8a`, issue #86).

  [breaking] `test (name, callable, args...)` and the suite constructors
  bind the extra arguments with `std::bind` (`inlines/test-inlines.h`
  lines 235 and 484). `std::bind` copies them (a reference parameter
  then refers to the copy, unless the caller writes `std::ref`), and it
  adds code size. A lambda capture says the same more clearly; consider
  removing the variadic arguments, or capture them into a lambda with
  `std::apply`.

- **#53 — Operands are copied several times per check.**
  (fixed) `detail::unwrap()`, `lhs()`, `rhs()`, and `operand()` return
  `decltype (auto)`, and `value_base::get()` returns a `const`
  reference, so the operands are no longer copied when compared or
  formatted; a check now makes two copies instead of six. As decided,
  the operands are still stored by value, so that a comparator may
  outlive the expressions it was built from; a comparator nested in a
  logical operator is still copied with its operands. Covered by the
  unit test "Operand copies" (commit `660b5121`, issue #87).

  [internal] `binary_op_` stores copies of the operands (`detail.h`
  lines 296 and 304), and `get()`, `lhs()`, and `rhs()` return by value
  (`inlines/detail-inlines.h` lines 82 to 90 and 162 to 180), so a
  vector or a string is copied once when stored and again for each
  comparison and each formatting. Return `const` references
  (`decltype (auto)`), and copy only where the operand is a temporary.

## 5. Suitability for embedded targets

- **#54 — Executed test cases are kept alive until the end.**
  (fixed) `suite::test()` and `test_case::test()` construct the test
  case as a local object, run it, and destroy it when they return,
  together with its `std::function` and bound arguments; the nodes
  keep only `child_test_cases_count_`, which the TAP plan needs. The
  heap no longer grows with the number of test cases; instead, the
  stack holds one test case (about 76 bytes on 32-bit targets) for
  each level of nesting being run. Covered by the unit test "Test case
  lifetime" (commit `20b23129`, issue #88).

  [internal] Each test case is allocated with `std::make_unique`, executed at
  once, and then kept in `children_subtests_`
  (`src/test.cpp` lines 171 to 175), together with its `std::function`
  and bound arguments, until its suite is destroyed. Only the count is
  read later (`children_subtests_count()`). Memory therefore grows with
  the number of test cases. Construct the test case on the stack inside
  `test()`, and keep a counter.

- **#55 — Every check is formatted, even when nothing will print it.**
  (withdrawn) The premise is wrong. With the default verbosity, a test
  case that fails prints its whole buffer, passed checks included, with
  their expressions (`end_test_case()` in `src/reporter-human.cpp` and
  `src/reporter-tap.cpp`), and an output file receives them as well.
  When a check passes, a later check of the same test case may still
  fail, so it is not known whether its expression will be printed; it
  cannot be formatted later either, since a kept result outlives its
  operands (#4). Neither is there a heap allocation per check: the
  expression formatter reuses one buffer, which keeps its capacity, and
  allocates only for a check kept while others run. The remaining cost
  is the formatting time, which only the quiet and silent verbosities,
  without an output file, could save; this was not considered worth a
  reporter query in every check.

  [internal] The `deferred_reporter` constructor formats the expression
  into a `std::string` for every check
  (`inlines/deferred-reporter-inlines.h` line 178). With the default
  verbosity, passing checks are never printed, so the formatting (and
  its heap use) is wasted for most checks. Format only when the result
  will be printed: on failure, or with `--verbose`. This also resolves
  #4.

- **#56 — Messages are built in fixed-size arrays and truncated
  silently.** (fixed) The reporters no longer format the suite and test
  case names, or their indentation, into arrays; they are passed as
  `%s` arguments to `write_file_()` and `write_console_()`. The arrays
  keep only the counts and the fixed words, whose lengths are bounded.
  In the TAP reporter, the console result lines common to all branches
  of `end_suite()` and `end_test_case()` are written once, after the
  branches. The `suite` test adds a static suite with names longer than
  the former arrays, and test cases nested ten levels deep; it showed
  that the human reporter also truncated the result line of a passed
  test case (`end_test_case()`), which is fixed the same way
  (commit `9316deee`, issue #90).

  [internal] The TAP reporter formats the suite and test case names,
  with their indentation, into `char[120]`, `char[160]`, and
  `char[300]` arrays with `snprintf()` (`src/reporter-tap.cpp` lines
  235, 293, 386, 449, 510, and 757), since each line is written twice,
  to the file and to the console. A long name, or a deep nesting,
  truncates the line silently; in `end_suite()` the `# { passed, ...`
  part is lost and the elapsed time and the closing `}`, appended
  later, leave a malformed TAP result line. The human reporter mostly
  avoids this, since it keeps only the bounded parts (counts and fixed
  words) in arrays and passes the name as a `%s` argument to
  `write_file_()` and `write_console_()`, which have no length limit.
  Do the same in the TAP reporter: remove the names and the indentation
  from the arrays and pass them to both writes; this avoids both the
  truncation and the use of the heap, at the cost of repeating each
  format string. Appending the lines to `buffer_` is not suitable, since
  it would change when the test case output is written and cleared.

## 6. Incidental observations

- **#57 — Stale forward declarations.** (fixed)
  The forward declaration of `runner_totals` in `test.h` is no longer
  stale, since #17 moved the class to the public namespace; the one of
  `test_node` in `detail.h` was removed with the class (#64).

  [internal] `test.h` line 97 declares `micro_test_plus::runner_totals` and `detail.h` line 81
  declares `micro_test_plus::test_node`; both classes live in `detail`.
  Remove both (the first is WEBSITE-API-REVIEW #86).

- **#58 — A trace macro leaks into user code.** (fixed)
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE` is now undefined at the end
  of `inlines/test-inlines.h`; the string literals are concatenated
  when the templates are parsed, so the trace messages are not
  affected. The macro is kept local to that header, and `src/` keeps
  `%zu`, since the reporter output already uses it with `snprintf()`
  on all platforms.

  [internal] `MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE` is defined in
  `inlines/test-inlines.h` (lines 77 and 79), and therefore in every
  user translation unit, yet `src/test.cpp` line 114 uses `%zu`
  directly. Define it in a private header, and use it everywhere.

- **#59 — The TAP test point number is printed through `int`.** (fixed)
  `output_pass_prefix_()` and `output_fail_prefix_()` now pass the
  `size_t` returned by `test_point_number()` (formerly
  `current_subtest_index()`) directly to the arithmetic `operator<<`
  of the reporter, as the other counts are printed.

  [internal] `src/reporter-tap.cpp` lines 575 and 615 cast
  `current_subtest_index()` to `int`; every other count uses `%zu` or
  the `size_t` stream operator. Remove the casts.

- **#60 — The decimal count of a run-time value is computed
  unsafely.** (fixed)
  `den_size (Value_T)` now works on the absolute value, stops when the
  distance to the nearest integer, not the fractional part, is at most
  `1e-7`, and stops before converting a value from which the type holds
  only integers (2^52 for `double`, at most 2^63). The probes confirmed
  more than the item stated: `to_d{ -1.5 }` was undefined behaviour,
  `to_d{ 1e20 }` looped forever, and 12387 of the 99999 values with
  three decimals between 0.001 and 99.999 (e.g. 0.011) got 17 or 18
  decimals, hence an almost zero tolerance; all give 3 now. #9 kept the
  implicit tolerance, so the function remains. Covered by static
  assertions in `static-asserts.cpp` and by checks of `to_d` in the
  "Floating-point tolerance" unit test (commit `aab11b2e`, issue #93).
  The changed tolerances are described in a compatibility notice.

  Remaining limitations: the threshold is absolute, so above about 1e12
  (for `double`) the rounding noise can exceed it, and the count may
  still be too high, up to the integral limit; the tolerance is then
  stricter than intended, but defined. A threshold relative to the
  magnitude was not chosen, since it would cut the count short for
  `float` values that use all their digits. A NaN cannot be passed in a
  constant expression (clang rejects the NaN arithmetic), so it is
  checked only at run time, by the probes, not by the unit test.

  [internal] `detail::math::den_size (Value_T)`
  (`inlines/math-inlines.h` lines 284 to 315), used by `to_f`, `to_d`,
  and `to_ld`, multiplies the value by ten until its fractional part is
  below `1e-7`, converting it to `unsigned long long` at every step;
  for a value above about 1.8e19 the conversion is undefined, and the
  binary representation of most decimals makes the result depend on
  rounding noise. This disappears if the tolerance becomes explicit
  (#9).

- **#61 — Constructors with side effects.** (fixed) Fixed by other
  items; no separate change was needed. #36 replaced `timestamp` with
  `detail::stopwatch`, whose default constructor only zero-initialises
  its members; the clock is read by the named operations `start()` and
  `stop()` (commit `0fbebfa8`, issue #71). The test point number is
  incremented in the destructor of `check_result`, where the check is
  reported, not in its constructor (#4, #34). `start()` and `stop()`
  still keep the first reading and ignore later calls, but each is
  called once per object (by the runner, the top suite, and the
  suites), so the guard is only defensive and was left as is.

  [internal] The default
  constructor of `timestamp` reads the clock (`src/timings.cpp` lines 71
  to 78), and `timestamp_begin()` silently ignores a second call (lines
  101 to 109); the constructor of a check result increments the test
  point number (#34). Prefer named operations (`timestamp::now()`).

- **#62 — `type_name()` depends on the compiler's function signature
  layout.** (fixed) The function was kept, since the exception type
  makes the `throws<E>` failure message more informative. It now
  searches for the whole marker (`"[T = "` for clang, `"[with T = "`
  for GCC), so a type name that contains brackets is parsed correctly;
  with clang, `type_name<int[3]>()` previously located the array
  bracket and read past the end of the string. If the marker is not
  found, or the compiler is not supported, it returns `"unknown"`
  instead of failing to compile. `static_assert` checks after the
  definition verify the layout for clang and GCC at compile time
  (commit `6265f4cb`, issue #94).

  [internal] `reflection::type_name()`
  (`inlines/reflection-inlines.h` lines 148 to 173) locates the type in
  `__PRETTY_FUNCTION__` with `rfind ('[') + 5` for clang and
  `find ("T = ")` for GCC, and fails to compile on other compilers. It
  is used only in the `throws<E>` failure message; consider printing
  "throws" there and removing the function, or adding a
  `static_assert`-based self-test for the supported compilers.

## 7. Reviewed and found sound

- The split into declarations (`include/.../*.h`), inline and template
  definitions (`inlines/*-inlines.h`), and non-inline definitions
  (`src/*.cpp`) is applied consistently, one file per concern.
- The expression-template design (operands wrapped in `op`-derived
  types, comparison results that remember their operands) gives
  informative failure messages without macros, and the requirement that
  at least one operand of an operator be a framework type
  (`type_traits::any_op`) keeps the operators from hijacking ordinary
  comparisons.
- Concepts (`checkable`, `is_op`, `container_like`) constrain the
  templates clearly, and the resulting error messages are mostly
  readable.
- Copy and move operations are consistently deleted for the
  identity-bearing classes (test nodes, runner, reporters, formatter).
- `[[nodiscard]]`, `noexcept`, and `constexpr` are applied widely and,
  as far as checked, correctly; `expect()` is rightly not
  `[[nodiscard]]`.
- `reflection::source_location` falls back cleanly when
  `<source_location>` is missing.
- The `expression_formatter` alias gives users a stable name for
  formatting their own types through `operator<<`.
- The library needs neither RTTI nor exceptions; the exception checks
  are compiled only when `__cpp_exceptions` is defined.
