# C++ API review

Date: 2026-11-05, on branch `xpack-development`, commit `aaadbe4b`.

Scope: the umbrella header `include/micro-os-plus/micro-test-plus.h`,
the public headers in `include/micro-os-plus/micro-test-plus/`, their
inline definitions in `inlines/`, and the definitions in `src/`. At the
request of the maintainer, only the defects are reported (section 1),
and the deprecated functionality is ignored. The Doxygen comments were
ignored.

Method: the 46 files (10709 lines of code, the comments stripped with
`strip-comments.mjs`, keeping the original line numbers) were read from
the entry points inwards. The suspected defects were reproduced with
probe programs built with Apple Clang 17 (`-std=c++20 -Wall -Wextra
-Wpedantic`), with and without `-fno-exceptions -fno-rtti`, and with
`-fsanitize=address,undefined`; the TAP outputs were validated with
`tests/scripts/validate-tap.mjs` at every verbosity, on the console and
in the output file. The library was also compiled with
`arm-none-eabi-g++` 15.2.1 for Cortex-M4 (`-fno-exceptions -fno-rtti
-Wconversion -Wsign-conversion -Wdouble-promotion
-Wframe-larger-than=512 -fstack-usage`), without warnings; the largest
stack frame is 384 bytes (`reporter_tap::end_suite`). All 18 public
headers compile on their own. The newcomer exercise was not done, since
the review is limited to the defects.

Independence: the earlier reports in `maintenance/docs/`, and the
commits and issues that refer to them, were deliberately not
consulted.

Summary: 5 problems (0 open, 5 fixed, 0 withdrawn). #1 is undefined
behaviour, and #2 gives wrong results without a diagnostic; they should
be fixed first, followed by #3 (the reports contradict the documented
contract for the application types), #4 (the report and the exit code
disagree), and #5 (a warning that breaks the builds with `-Werror`).
None of the suggested changes alters the public API.

Tags: **[breaking]** the suggested change alters the public API;
**[internal]** it does not; **[confirmed]** a probe reproduced the
problem.

## 1. Defects

- **#1 — A character array streamed into a message is read past its
  end.** (fixed) [internal] **[confirmed]**
  `src/expression-formatter.cpp` lines 556 to 567 (and the plain-mode
  paths of the `const wchar_t*`, `const char8_t*`, `const char16_t*`,
  and `const char32_t*` overloads, lines 577 to 652): there is no
  overload of `expression_formatter::operator<<` for arrays, so a
  `char buf[N]` streamed after `expect()` (through
  `check_result::operator<<`, `inlines/check-result-inlines.h` line
  205), or written by an application `operator<<` (a fixed-size name
  field, common on embedded targets), decays to `const char*` and is
  measured with `strlen()`. When the array is full, without a
  terminator, the read continues into the adjacent memory. The same
  array used as an operand is bounded by its extent (`as_operand()`
  passes `std::extent_v` to `basic_c_string`), so the two paths
  disagree. Probe:

  ```c++
  char buf[4] = { 'a', 'b', 'c', 'd' };
  t.expect (mt::eq (buf, "abcd"));  // passes, bounded
  t.expect (false) << buf;          // prints "abcd\x10e..."
  ```

  AddressSanitizer reports `stack-buffer-overflow ... READ of size 7`
  in `expression_formatter::operator<<(char const*)`. The names have
  the same exposure: `located_name (const char*)`
  (`inlines/test-inlines.h` lines 101 to 106) also uses the length of
  the C string, so `ts.test (buf, ...)` with a full array overreads.
  Suggested change: add a member template
  `template <character Char_T, std::size_t N> operator<<
  (const Char_T (&s)[N])` that writes `basic_c_string<Char_T>{ s, N }`
  (which stops at the first terminator, so the string literals are
  unaffected), and a `located_name` constructor for the `char` arrays
  that bounds the name in the same way.

  Fixed in `abb8a98d` (#271): the character-pointer overloads of the
  formatter are now a template constrained by
  `detail::character_pointer`, with a more specialised template for the
  arrays (and the same pair of constructors for `located_name`), which
  stops at the first null character or at the end of the array. They are
  templates because a non-template pointer overload ties with the array
  template and wins. Tested in `miscellaneous.cpp` and under
  AddressSanitizer.

- **#2 — Comparisons of a character type with an integer of the other
  signedness give wrong results, silently.** (fixed) [internal]
  **[confirmed]** `inlines/detail-inlines.h` lines 278 to 292
  (`sign_mixed_integers`) and the `apply()` functions at lines 505 to
  625: the safe `std::cmp_*()` comparisons are used for the mixed
  signed and unsigned integers, but the character types are excluded
  from them (since `std::cmp_*()` rejects them), so they fall back to
  the built-in operators, with the usual arithmetic conversions; the
  `-Wsign-compare` warning, which would tell the user, is silenced by
  the pragma at line 258. Probe, on x86_64 (where `char` is signed):

  ```c++
  char c = '\x80';
  t.expect (mt::lt (c, 1u));     // fails: -128 < 1u is false
  t.expect (mt::gt (U'a', -1));  // fails: -1 becomes 4294967295u
  t.expect (mt::lt (-1, 1ul));   // passes: cmp_less() is used
  ```

  The affected types are those whose promoted type has the rank of
  `int` or more and the other signedness: `char` where it is signed,
  `char32_t` always, and `wchar_t` where it is 32 bits wide (unsigned
  on `arm-none-eabi`, signed on Linux and macOS). The report shows the
  operands correctly (`'\x80' < 1u`), which makes the failure harder
  to understand. Suggested change, one of:
  - convert each character operand to the integer type of the same
    size and signedness (`char` to `signed char` or `unsigned char`,
    `wchar_t` to `std::make_signed_t<wchar_t>` or
    `std::make_unsigned_t<wchar_t>`, `char8_t` to `unsigned char`,
    `char16_t` to `std::uint_least16_t`, and `char32_t` to
    `std::uint_least32_t`) and use `std::cmp_*()` on the results;
  - or reject the comparison of a character type with an integer of
    the other signedness, with a `static_assert` that asks for an
    explicit conversion.

  Fixed in `8637f7e9` (#272): the first option; the character operands
  are converted to the integer of the same size and signedness
  (`comparison_integer_t`) and compared with `std::cmp_*()`. Characters
  of different types are compared by value too; only `bool` remains
  excluded. Tested in `comparisons.cpp` with checks that do not depend
  on the signedness of `char`.

- **#3 — The application `operator<<` of an enumeration or of a type
  with `begin()` and `end()` is written with the decorations of the
  report.** (fixed) [internal] **[confirmed]**
  `inlines/expression-formatter-inlines.h` lines 447 to 459
  (`append_operand()`) and `expression-formatter.h` lines 1665 to 1669
  (`member_printable`): an operand is written directly on the report
  formatter when `formatter.operator<< (value)` is valid, and through
  `plain_text::append()` (the plain mode) otherwise. For a scoped
  enumeration, or for a type with `begin()` and `end()`, the member
  templates of lines 863 to 867 and 838 to 841 make
  `member_printable` true, but the overload resolution of
  `*this << value` then selects the application's own `operator<<`
  (a better match), which therefore writes on the decorating
  formatter: the strings are quoted, the characters are written as
  literals, and the integers receive their suffixes. Probe:

  ```c++
  enum class colour { red, green };
  mt::expression_formatter&
  operator<< (mt::expression_formatter& f, colour c)
  {
    return f << std::string_view{ c == colour::red ? "red" : "green" }
             << '/' << static_cast<unsigned> (c);
  }
  t.expect (mt::eq (colour::red, colour::green));
  // report: "red"'/'0u == "green"'/'1u   (expected: red/0 == green/1)
  t.expect (false) << colour::red;  // message: red/0 (correct)
  ```

  A `struct` without `begin()` and `end()`, with the same operator, is
  reported correctly (`plain/0 == plain/1`); a `struct` with
  `begin()`, `end()`, and an `operator<<` that writes `v.size ()` is
  reported as `bag#1ul`. This contradicts the documented contract
  (the values written by the application operators appear in the
  reports as in the messages, in the plain mode), and it hits exactly
  the case for which the manual recommends an `operator<<` (the names
  of the enumerators). The containers of such types are affected too
  (`{"red"'/'0u}`), since their elements go through `append_value()`
  and `append_operand()`. Suggested change: in `append_operand()`,
  test first whether the application provides a free operator, for
  example with a concept `application_printable<T> = requires
  (expression_formatter& f, const T& v) { operator<< (f, v); }`
  (found by argument-dependent lookup, after checking that no free
  `operator<<` of the framework is visible at that point), and use
  `plain_text::append()` when it is true.

  Fixed in `d577784b` (#273): as suggested, with the concept named
  `free_printable`; the framework defines no free `operator<<` for the
  formatter, so only the ones of the application are found. Tested in
  `operands.cpp` with an enumeration, a range, and a vector of
  enumerations.

- **#4 — A call rejected during or after the run sets the exit code
  to 1, but the report says that everything passed.** (fixed) [internal]
  **[confirmed]** `src/runner.cpp` lines 628 to 634
  (`reject_suite()`), 643 to 650 (`mark_rejected()`), and 877 to 880
  (the exit code); the same for the repeated `initialise()` (lines 284
  to 289) and `add_top_suite()` (lines 444 to 449): the error is
  written only on `stderr`, with `fprintf()`, and recorded in
  `has_rejected_calls_`, which changes only the exit code. The
  reporter is never told, so neither the console report nor the output
  file contains it. Probe: a suite body that calls `tr.add_suite()`,
  or that constructs a function-local `static_suite`, both rejected.
  The human report ends with `✓ Total: 2 checks passed, 0 failed`, the
  TAP stream and the output file contain only `ok` test points and a
  matching plan (valid TAP 14), and the process exits with 1; a TAP
  consumer that reads the file, or a user who reads the summary, sees
  a successful run that the CI marks as failed, with nothing to
  explain it. A test case started on a suite that is not running is
  handled better (`src/test.cpp` lines 265 to 272): it becomes a
  failed test point of the running suite. Suggested change: when a
  suite is running, record the rejection in the same way, as a failed
  test point of `running_suite_` (`fail_suite()`), so that the suite,
  the totals, and the summary fail; otherwise write it through the
  reporter (`write_line()` with `error_prefix()`, which reaches the
  output file), and count the rejected calls in the session summary,
  so that the `Total` line is not marked as passed when the exit code
  is 1.

  Fixed in `007a0d3d` (#274): `runner::reject_call()` keeps the message on
  `stderr` and the exit code, and also reports it: as a failed check of
  the running test case, as a failed test point of the running suite
  (the top suite included), and otherwise as a comment line after the
  summary. The `Late suites` test and the reference outputs were
  updated.

- **#5 — With Clang and `-fno-exceptions`, `src/test.cpp` warns about
  an unused private field.** (fixed) [internal] **[confirmed]**
  `test.h` line 1922 (`const located_name& located_name_` of
  `test_case`), initialised in `inlines/test-inlines.h` line 527: the
  member is read only by `fail_unexpected_exception()` (`src/test.cpp`
  line 523), which exists only with `__cpp_exceptions`. Compiling
  `src/test.cpp` with Clang, `-Wall -fno-exceptions` reports
  `private field 'located_name_' is not used
  [-Wunused-private-field]`, which fails the builds of the
  applications that compile the library with `-Werror` (the test
  platforms build without exceptions only with GCC, so the tests do
  not show it). Suggested change: guard the member and its initialiser
  with `#if defined(__cpp_exceptions)`, or declare it
  `[[maybe_unused]]`.

  Fixed in `007a0d3d` (#274) and `11f1366e` (#275): the field is now read
  by `runner::reject_call()` in every build, so the warning no longer
  appears (it is reproduced with the library sources of `8637f7e9`);
  the suggested guard was not needed. The native `unit-test-noexcept`
  program, which compiles the framework and the unit tests with
  `-fno-exceptions` and the strict warnings, was added, to catch such a
  warning. Note that the earlier statement that the test platforms build
  without exceptions only with GCC meant the embedded platforms; the
  native ones linked the static library, built with exceptions.
