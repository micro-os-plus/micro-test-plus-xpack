# C++ API review

Date: 2026-11-05, on branch `xpack-development`, commit `bfb5c5e3`.

Scope: the umbrella header `include/micro-os-plus/micro-test-plus.h`, the
public headers in `include/micro-os-plus/micro-test-plus/`, their
`inlines/`, and the definitions in `src/`; the Doxygen comments were
ignored. As requested, the deprecated code was not reviewed, and the report
lists **only the defects** (section 1); the other sections of the checks
(usability, structure, naming, simplicity, modern C++, embedded suitability)
were not part of this review, and the newcomer exercise was not run.

Method: the comments were stripped with
`.github/skills/api-review/scripts/strip-comments.mjs` (46 files, 10830
lines of code), and every stripped file was read in full, in the order of
the skill. The suspected defects were reproduced with probe programs built
with Apple clang 17 (`-std=c++20 -Wall -Wextra -Wpedantic -g
-fsanitize=address,undefined`, with `detect_stack_use_after_return=1` for
the lifetime questions), once with `-fno-exceptions -fno-rtti`, and
cross-compiled with `arm-none-eabi-g++` 15 for Cortex-M4 (`-fno-exceptions
-fno-rtti -Wframe-larger-than=512 -fstack-usage`); no native GCC was
installed. The TAP outputs (console and file) were validated with
`tests/scripts/validate-tap.mjs` for every verbosity, with and without
filters. The 18 public headers compile on their own, and `clang-format`
reports no difference.

Independence: the earlier reports in `maintenance/docs/`, and the commits
and issues that refer to them, were deliberately not consulted.

Summary: 6 problems (0 open, 6 fixed, 0 withdrawn), all defects, all
confirmed, none breaking. The most serious was #1 (a wrong result: arrays of
integers of different signedness compare equal when they are not). #2 is
undefined behaviour only for an expression with an array operand that is
returned from a helper or kept after the array is destroyed, and is
resolved by documenting the rule, since copying the arrays costs stack or
heap for every check. #5 and #6 were found later, by the Doxygen review
of the fixes: the `volatile` operands did not compile (#5, fixed), and a
misdirected test case was missing from the listing (#6, fixed). All the
problems are fixed.

Tags: **[breaking]** the suggested change alters the public API;
**[internal]** it does not; **[confirmed]** a probe reproduced the problem.

## 1. Defects

- **#1 — Arrays compare integers of different signedness by
  conversion.** (fixed) [internal] **[confirmed]**
  Fixed in `1be46e35` (#276): the elements are compared with
  `equal_to::apply()` in the operator and in the search of the first
  difference, as suggested; the constraint was kept.
  `inlines/detail-inlines.h` lines 1587 to 1595, and
  `inlines/expression-formatter-inlines.h` lines 546 to 572: the
  `operator==` of `array_operand` compares the elements with `std::equal`,
  that is with the built-in `==`, and its constraint accepts any pair of
  types that is `std::equality_comparable_with`. For an `int` array against
  an `unsigned` array or container, `-1` is converted to `4294967295u`, so
  `mt::eq (a, b)` passes and `mt::ne (a, b)` fails, while the user manual
  (`website/docs/user/checks/index.mdx` lines 303 to 311) says that the
  arrays are compared element by element and that two integers of different
  signedness are compared by value; `mt::eq (-1, UINT_MAX)` does fail.
  The same comparison in `append_first_difference()` (line 557) emits
  `-Wsign-compare` from the library header in the application build, with
  both clang and GCC.

  Evidence (probe `p1`, `int a[] = { -1, 2 }`, `unsigned b[] = {
  UINT_MAX, 2u }`, `std::array<unsigned, 2> c{ UINT_MAX, 2u }`):

  ```text
  ✗ scalar int vs unsigned FAILED (p1.cpp:11, -1 == 4294967295u)
  ✓ C arrays int vs unsigned
  ✓ C array int vs std::array unsigned
  ✗ ne of the same FAILED (p1.cpp:19, {-1, 2} != {4294967295u, 2u})
  ```

  Suggested change: compare the elements with the rule of the scalars,
  `std::equal (lhs.begin (), lhs.end (), rhs.begin (), rhs.end (),
  [] (const auto& l, const auto& r) { return equal_to::apply (l, r); })`,
  use the same predicate in `append_first_difference()`, and constrain the
  operator with `comparable<comparison::equal, T, element>` instead of
  `std::equality_comparable_with`. The ordering (`<=>`) needs no change:
  `std::three_way_comparable_with<int, unsigned>` is false, so `lt()` and
  the others reject these operands at compile time. The `std::optional`,
  `std::pair`, and `std::tuple` operands keep the standard operators (for
  example `std::optional<int>{ -1 }` equals `UINT_MAX`), as the manual says
  for the containers; this is consistent with the documentation and is not
  part of the defect.

- **#2 — Array operands are referred to, not copied, so a returned
  expression dangles.** (fixed) [internal] **[confirmed]**
  `inlines/detail-inlines.h` lines 1623 to 1650: `as_operand()` turns a
  character array into a `basic_c_string` and any other array into an
  `array_operand`, both of which keep only a pointer to the array
  (`detail.h` lines 1656 to 1719 and 1820 to 1868). The manual
  (`website/docs/user/checks/index.mdx` lines 332 to 343) promises that the
  comparators copy the named operands, "so that an expression built in a
  helper function from its parameters and returned, or kept in a variable,
  stays valid after the operands are destroyed", and lists only the views
  and the non-copyable operands as exceptions. The comparison result is
  computed at construction, but the operands are read again when the
  expression is written in the report, after the array is gone.

  Evidence (probe `p2`, a `packet` structure with `int data[4]` and `char
  name[32]`, passed by value to helpers that return `mt::eq (p.data,
  expected)` and `mt::eq (p.name, expected)`):

  ```text
  ✗ FAILED (p2.cpp:27, {-1323858112, 32759, 0, 0} == {1, 2, 3, 5})
  ✗ FAILED (p2.cpp:30, "a name \0�\0\0\0\x10a\0\0gh for \0\0..." == "other")
  ==36084==ERROR: AddressSanitizer: stack-use-after-return
      #0 ... expression_formatter::append_operand<int>(int const&)
      #2 ... expression_formatter::operator<<(array_operand<int> const&)
  ```

  The same happens without a helper when the array is a member of a
  temporary: `auto e = mt::eq (make_packet ().data, v);` followed by
  `t.expect (e);`. A `const char*` operand is not affected: it is a
  pointer, and the pointer is what is copied.

  Suggested changes, for the maintainer to choose:

  1. store the arrays by value: an `std::array<T, N>` copy for the other
     arrays, and a bounded copy of the characters for the character arrays
     (an `std::array<Char_T, N>` with the length, which keeps the
     comparison by content and makes no allocation); the cost is a copy of
     the array for every check, which matters for large buffers on small
     stacks;
  2. keep the references, and add the arrays to the documented exceptions
     of the copy rule, next to the views.

  Fixed in `308bd4ac`: the arrays are documented as referred to (no issue
  number).

  Decision: the second option. The user manual and the comment of
  `function-comparators.h` now name the arrays as operands that are
  referred to, and give the remedy for a returned or stored expression
  (a copy of the array of the same type, such as `std::to_array
  (buffer)`, or `std::string{ name }`; both were probed with ASan). The
  developer manual and the comments of `detail.h` already stated the rule.

- **#3 — Wide and Unicode C strings are written as addresses outside the
  messages.** (fixed) [internal] **[confirmed]**
  Fixed in `4d4ed367` (#278): the text is written in both modes, but
  unquoted, as the `char` text is, and not quoted as suggested below,
  since a quoted `symbol` of a comparator tag would be reported as
  `1" near "5`; the operands are still quoted by the overload for
  `basic_c_string`.
  `src/expression-formatter.cpp` lines 599 to 679: the `append_c_string()`
  overloads for `wchar_t`, `char8_t`, `char16_t`, and `char32_t` write the
  address of the pointer unless the formatter is in the plain mode (the
  messages and the values of the application types). The comment gives the
  reason "the wide strings are not strings for the comparators", which no
  longer holds: they are compared by content and reported as text (manual,
  `checks/index.mdx` lines 298 to 322). Two paths reach these overloads:
  an `mt::expression_formatter` constructed by the application, which the
  manual says keeps the decorations of the reports, and the `symbol` of an
  application comparator or predicate tag, which
  `extension::compare_tag` accepts as any printable value and which is
  written with `*this << Compare_T::symbol`
  (`inlines/expression-formatter-inlines.h` lines 520 to 523 and 746 to
  749). The `char` overload writes the text in both modes.

  Evidence (probe `p3`): `f << "narrow" << ' ' << L"wide" << ' ' <<
  u"utf16"` gives `narrow' '0x105aee360' '0x105aee3a0`, and a tag with
  `static constexpr const wchar_t* symbol = L" near "` gives the failure
  report `(p3.cpp:18, 10x105aef4605)`.

  Suggested change: write the text in both modes, as the `char` overload
  does (`*this << bounded_view (s, capacity)` after the null check), and
  remove the `append_pointer()` branch and the stale reason.

- **#4 — Errors during `--list-tests` leave the exit code at 0 and do not
  reach the output file.** (fixed) [internal] **[confirmed]**
  Fixed in `576641d7` (#277): the rejected calls and the exception of a
  suite body are written in the list, as the other errors of the
  listing, and make the exit code 1, as suggested. The message of the
  exception is built in `runnable_base::reject_body_exception()`, not
  in `suite::run()`, since a larger frame of `suite::run()` overflowed
  the 8 KB stack of the Cortex-M33 tests.
  `src/runner.cpp` line 890 sets the exit code of the listing from
  `listed_nothing` and `has_option_errors()` only, ignoring
  `has_rejected_calls_`; `runner::reject_call()` (lines 664 to 668)
  returns before writing to the reporter when listing, so the error is
  written only on `stderr`; and the listing branch of `suite::run()`
  (`src/test.cpp` lines 607 to 629) catches an exception of the suite body,
  writes it on `stderr`, and marks nothing. The listing is then incomplete
  (the test cases after the exception, or the rejected suite, are
  missing), the output file does not say so, and a script that checks the
  exit status accepts it, while the same program exits with 1 when run.

  Evidence (probe `p5`, a suite body that throws after its first test
  case; probe `p7`, a suite added from a suite body):

  ```text
  $ ./p5 --list --output-file=list.txt; echo "exit=$?"
  error: unexpected exception in the body of suite '1 throws'
  exit=0                      (list.txt has no error; './p5' exits with 1)
  $ ./p7 --list > /dev/null; echo "exit=$?"
  error: suite 'late' added after run_suites() started, rejected
  exit=0                      ('./p7' exits with 1)
  ```

  Suggested change: in the listing, count the rejected calls in the exit
  code (`listed_nothing || has_option_errors () || has_rejected_calls_`),
  write the errors of `reject_call()` and of the suite bodies through the
  reporter (`write_line()` with `comment_prefix()`, as the other listing
  errors are), so that they reach the output file, and mark the runner from
  the `catch` of the listing branch of `suite::run()`.

- **#5 — The `volatile` operands do not compile, or are rejected with a
  wrong reason.** (fixed) [internal] **[confirmed]**
  Fixed in `ff363279` (#279): as suggested below, with tests for the
  arrays and the pointers in `operands.cpp` and in the static assertions.
  A `volatile char` array is compared as a range, not as a string.
  Found after this review, on commit `4c3468e9`, by the Doxygen review
  (`DOXYGEN-REVIEW.md` #91), and investigated with probes; part of it is a
  regression of `abb8a98d` (#271).
  `inlines/detail-inlines.h` lines 1690 to 1725, `as_operand()`: the type
  is `std::remove_cvref_t<T>`, which, for an array, also removes the
  qualifiers of the elements (the qualifiers of an array are those of its
  elements), so a `volatile int[3]` is seen as an `int[3]`, and the
  `static_cast` to `const int*` (line 1712) is ill-formed; the pointer
  branch (line 1702) accepts the `volatile` characters, which
  `basic_c_string` cannot refer to. The errors occur when the return type
  is deduced, inside the constraint of the comparator, so they are hard
  errors, followed by the rejection of the comparison. Separately,
  `expression-formatter.h` lines 555 and 556 (and
  `inlines/expression-formatter-inlines.h` lines 200 and 201): the
  overload for the character arrays, added by #271, accepts the `volatile`
  characters, and is then ambiguous with the overload for the pointers
  (line 767), which excludes only the non-`volatile` character pointers
  (`detail.h` line 1640, `character_pointer`); at `f6714bc5` a `volatile
  char` array in a message was written as an address. The `volatile`
  buffers are common on the embedded targets (for example a DMA buffer
  `volatile std::uint8_t rx[N]`), and cannot be compared at all.

  Evidence (probes `v` and `m`, Apple clang 17, `-std=c++20`):

  ```text
  volatile char* p;    eq (p, p)    no matching constructor for
                                    initialization of 'basic_c_string<char>';
                                    the operands of eq () cannot be compared
                                    with ==
  volatile int a[3];   eq (a, a)    static_cast from 'volatile int *' to
                                    'const int *' is not allowed; the
                                    operands of eq () cannot be compared
                                    with ==
  volatile char a[3];  eq (a, a)    an operand of the comparator cannot be
                                    written in the report; define an
                                    operator<< ...
  volatile char a[3];  << a         a message argument must be a value that
                                    can be written (compiles at f6714bc5)
  volatile int* p;     eq (p, p)    compiles, compared by address
  ```

  Suggested change (prototyped; the 18 unit test sources compile with it,
  with `-Weverything -Werror`): in `as_operand()`, take the element type
  as `std::remove_const_t<std::remove_extent_t<std::remove_reference_t<
  T>>>`, which keeps `volatile`, use it for the character test (excluding
  the `volatile` characters) and for `array_operand`, and use
  `character_pointer<type>` for the pointer branch; constrain the
  overload of the formatter for the character arrays with `not
  std::is_volatile_v<Char_T>`. The `volatile` arrays, including those of
  characters, are then compared element by element and written as ranges
  (`{1, 2, 3, 4} == {1, 2, 9, 4}`; `{-1, 2, 3} == {4294967295u, 2u, 3u}`
  fails, as for the other arrays), the `volatile` character pointers are
  compared by address, as the other pointers, and a `volatile` character
  array in a message is written as an address again. A `volatile char`
  array is not a string: `eq (volatile_text, "abc")` remains rejected,
  since reading it as text would need a copy; this is to be documented.

- **#6 — A test case started on a suite that is not running is missing
  from the listing and from the output file.** (fixed) [internal]
  **[confirmed]**
  Fixed in `67aa7242` (#280): as suggested below, with the check added to
  the test of the listing errors in `miscellaneous.cpp`; the branches for a
  running test case or suite were kept.
  Found after this review, on commit `4c3468e9`, by the Doxygen review
  (`DOXYGEN-REVIEW.md` #92); the same gap as #4, in a path that #277
  did not change.
  `src/test.cpp` lines 237 to 277, `runnable_base::accepts_test_case()`:
  when no test case or suite can take the failure (while the test cases
  are listed, before `run_suites()`, or after it returned), the message is
  written with `fprintf (stderr, ...)` and `runner_.mark_rejected()` (line
  275), not with `runner::reject_call()`, which also writes it, as a
  comment line, in the listing or in the report, and in the output file.
  The exit code is 1, but the list is incomplete without saying so, while
  a suite added too late, in the same listing, is reported in it. The
  unit tests cover this path only with the `silent` verbosity, after the
  session, and not while listing.

  Evidence (probe `p92`, a suite body that starts a test case on another
  suite, or adds a suite):

  ```text
  $ ./p92 --list --output-file=list.txt          (adds a suite)
  # error: suite 'late' added after run_suites() started, rejected
  exit=1                     (in the list, in list.txt, and on stderr)
  $ MISDIRECTED=1 ./p92 --list --output-file=list.txt
  error: test case 'misdirected' started on suite 'A', which is not running
  exit=1                     (on stderr only; the list and list.txt omit it)
  ```

  Suggested change (prototyped): replace the `fprintf()` and the
  `mark_rejected()` at the end of `accepts_test_case()` with
  `runner_.reject_call (message, &name.location ())`; the message is then
  written in the list, in the output file, and on `stderr`, and the
  branches for a running test case or suite are unchanged. Delegating
  them too would remove their duplication of `reject_call()`, but would
  add a `stderr` line and `mark_rejected()` to the failed checks, unlike
  `test_case::report_misdirected_test()`; the smaller change is
  recommended. Add a listing test in `unit-miscellaneous`.
