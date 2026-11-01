# C++ API review

Date: 2026-11-01, on branch `xpack-development`, commit `691bfaf7`.

Scope: the umbrella header `include/micro-os-plus/micro-test-plus.h`, the
public headers in `include/micro-os-plus/micro-test-plus/`, their
`inlines/`, and `src/`. The Doxygen comments were ignored. As requested,
the review concentrates on the remaining defects and on the ways to
simplify the code; the deprecated functionality is not reviewed for
defects, and is mentioned only once, as a simplification (#30).

Method: the comments were stripped with
`.github/skills/api-review/scripts/strip-comments.mjs` (46 files, 10,084
lines of code, of which 1,289 are in `deprecated.h`,
`inlines/deprecated-inlines.h`, and `src/deprecated.cpp`), and every
stripped file was read. The probes were built with Apple clang 17
(`-std=c++20 -Wall -Wextra -Wpedantic`), with
`-fsanitize=address,undefined` for the lifetime questions, and checked
with `arm-none-eabi-g++` 15.2.1 (the native xPack GCC does not work with
the current macOS SDK); the TAP outputs were checked with
`tests/scripts/validate-tap.mjs`. The library was cross-compiled for
Cortex-M4F (`-Os -fno-exceptions -fno-rtti -fstack-usage`). The newcomer
programs were written by a sub-agent, from the manual and the public
declarations only, before and independently of the code reading; its
programs and diagnostics are in the session scratchpad
(`newcomer/t*.cpp`, `newcomer/m*.cpp`).

Independence: the earlier reports in `maintenance/docs/`, and the
commits and issues that refer to them, were deliberately not consulted.

Summary: 31 problems (8 open, 7 fixed, 2 partly fixed, 14 withdrawn).

The most serious defect is #1 (a test case started on a suite that is
not running is executed and reported, but its failures are lost: the
exit code is 0, and the TAP output is invalid); it is fixed. #2 and #6
were withdrawn, since the requirement that a check is reported right
after its statement excludes the suggested change. #3 to #5 are smaller
output and overload defects.

On the question of the complexity: the code is complicated mostly in
four places, by size of stripped code:

- the reporters, 2,110 lines: two output mechanisms (#13), and a
  lazy-heading and blank-line state machine written twice (#14);
- the test tree, 1,331 lines: three callable wrappers (#16), duplicated
  `expect()`/`require()` overloads (#18), and irregular totals (#19);
- the expression formatting, 1,379 lines: a shared buffer with owner
  bookkeeping (#15), and two rendering modes in one class (#4);
- the comparisons in `detail`, 1,139 lines: six tags and twelve
  concepts that differ only in the operator (#17).

The runner itself (880 lines) is complicated mainly by the error
handling of the call order, which is justified. The deprecated
functionality adds 1,289 lines plus 120 conditional blocks in 21 other
files (#30); its removal at the next major release is the largest single
simplification.

Suggested order of work:

1. defects: #1 (done), #3 (done), #4 (withdrawn), #5 (done);
2. internal simplifications, without visible changes: #15, #16 (with
   #26), #17 (with #9), #18, #21, #24, #25, then #13;
3. simplifications that change the output, with the expected files
   updated in the same commits: #14, #19;
4. breaking changes, for the next major release: #20, #22, #23, #30.

Tags: **[breaking]** means that the suggested change alters the public
API; **[internal]** means that it does not. **[confirmed]** means that a
probe reproduced the problem; findings without it are derived from
reading the code.

## 1. Defects

- **#1 — A test case started on a suite that is not running is
  executed, but its results are lost.** [internal] **[confirmed]**
  (fixed)
  `inlines/test-inlines.h` lines 800 to 820 (`suite::test()`) and
  `src/test.cpp` lines 245 to 326 (`after_test_case_create()`):
  `suite::test()` redirects to the running test case when there is one,
  but, from a suite body or after the run, it creates the test case on
  `this` suite, whatever its state. Probe `p1.cpp`:

  - variant A: the body of a suite added with `add_suite()` captures with
    `[&]` and calls `top.test (...)` on the top suite (a natural slip,
    the outer `top` instead of the parameter `s`). The top suite has
    already been closed and added to the totals, so the failed test case
    is printed inside the other suite, numbered `not ok 2` in a suite
    whose plan is `1..1`, and lost from the totals:
    `Total: 2 checks passed, 0 failed`, exit code **0**. The TAP
    validator reports `child: id greater than plan end`;
  - variant B: `top.test (...)` after `run_suites()`: the test case runs
    and prints a failure after the final totals, the exit code is **0**,
    and the TAP output has a test point without a plan.

  The same happens with a static suite object named from another
  suite's body. Adding a suite after the run is rejected with an error
  and exit code 1; adding a test case is not.

  Suggested change: the runner already knows which suite is running
  (the top suite between `add_top_suite()` and `run_suites()`, then each
  suite in `run_child_suites()`); keep a `running_suite_` pointer, and
  in `suite::test()`/`test_each()`, when there is no running test case
  and `this` is not the running suite, treat the call as the misdirected
  checks are treated (`report_misdirected()`): report a failed check in
  the running suite (or an error and `mark_rejected()` when nothing
  runs), and do not run the body. Add both variants to the unit tests.

  Fixed in `e8246e85` (#252): the runner remembers the running suite,
  and `suite::test()` rejects a test case started on any other suite,
  as suggested; the rejection is a failure of the running suite, or,
  when none runs, an error on `stderr` and exit code 1 from the later
  calls of `run_suites()`. Tests added in `miscellaneous.cpp`.
  Follow-up in `868f7efa` (#252): the checks moved to their own test case,
  "Misplaced test cases", since they overflowed the 8 KB stack of the
  Cortex-M QEMU platforms in "Optional top suite"; the `-noexcept`
  reference outputs were updated.

- **#2 — Keeping the result of `expect()` or `require()` is a use after
  scope.** [internal] **[confirmed]** (withdrawn)
  `test.h` lines 1394 to 1491, `inlines/test-inlines.h` lines 495 to
  579, `check-result.h` lines 196 to 402: the checks return
  `detail::check_result&&`, a reference to the temporary created by the
  defaulted third parameter, which is destroyed at the end of the full
  expression. `auto&& result = t.expect (eq (1, 2));` followed by
  `std::move (result) << message;` is a stack use after scope (probe
  `p4.cpp`, AddressSanitizer:
  `stack-use-after-scope check-result-inlines.h:191`), with no warning
  from clang or GCC. Writing the result to a variable, to look at
  `value()` later, is an ordinary thing to try.

  Suggested change: return `detail::check_result` by value, constructed
  in the `return` statement by a constructor that does what `init()`
  does now. Guaranteed copy elision makes this work for a type that is
  neither copyable nor movable (prototype `p5.cpp`, accepted by clang 17
  and GCC 15): `t.expect (x) << "..."` behaves exactly as now, and
  `auto&& r = t.expect (x)` extends the lifetime, so the check is
  reported when `r` goes out of scope, instead of being undefined. This
  also removes the third parameter and `init()`, and lets `value()` be
  `const&` instead of `const&&` (see also #6). A smaller fix, which
  only warns, is `[[clang::lifetimebound]]` on the parameter.

  Withdrawn: the requirement is that the result of a check is reported
  immediately after its statement, so the result must not be usable
  after the statement. Returning the check result by value (prototyped
  and tested, with no problem found) allows `auto r = t.expect (...)`,
  and then the check is reported at the end of the scope, not after the
  statement. The current design (a reference to the temporary, with the
  members callable only on an rvalue) reports the check at the end of
  the statement in all cases, also when the reference is bound to a name,
  and a use of the named reference is possible only with an explicit
  `std::move (r)`, which is a misuse. The residual undefined behaviour of
  that misuse is accepted.

- **#3 — A container that declares `npos` cannot be compared.**
  [internal] **[confirmed]** (fixed)
  `extension.h` lines 444 and 445 (`has_npos`) and 548 to 553
  (`formattable_range`): to keep the strings from being printed as
  ranges, every type with a member `npos` is excluded from the range
  formatting. A user container with a `static constexpr npos` (common in
  fixed-capacity buffers and string classes) and `begin()`/`end()` is
  then not `printable` at all, so `eq (a, b)` does not compile (probe
  `p3.cpp`, `-DP_NPOS`: `'my_buf &' does not satisfy 'printable'`).
  Suggested change: exclude the types convertible to a
  `std::basic_string_view` of a character type (the ones that have an
  overload of their own), instead of the types that have `npos`; then
  `has_npos` can be removed.
  Fixed in `60af1266` (#253): `formattable_range` uses the new
  `detail::string_like`; `has_npos` remains only in the deprecated
  `type_traits`.

- **#4 — An application type is printed with different rules inside a
  report and alone.** [internal] **[confirmed]** (withdrawn)
  Withdrawn: the plain rules are deliberate (#233, commit `8ad82b6b`):
  the application writes its type as it wants, so `money` is reported
  as `119.10 EUR`. With the expression rules it became
  `119l.10l "EUR"` (tried, then reverted). The standalone formatter
  keeps the decorated rules by design.
  `inlines/expression-formatter-inlines.h` lines 399 to 411 and 733 to
  741: an operand whose `operator<<` is not a member of the formatter
  (that is, every application type) goes through `plain_text::append()`,
  which formats it in the message mode, so its `std::string` members are
  printed without quotes and escapes. Probe `p6.cpp`:
  `eq (rec{ "a " }, rec{ "a" })` prints `rec{a } == rec{a}` (the
  trailing space is invisible), while the same strings as direct
  operands print `"a " == "a"`, and the same `operator<<` applied to a
  standalone `expression_formatter`, as the manual suggests for testing
  it, prints `rec{"a "}` (newcomer `t4.cpp`). Suggested change: format
  the application operands in the expression mode, like the built-in
  operands; keep the plain mode for the messages only. With one rule per
  context, the `plain_` flag tested in eight functions
  (`src/expression-formatter.cpp` lines 383 to 968) can become two
  small sets of helpers, one per mode.

- **#5 — `long double` values are printed with an invalid suffix.**
  [internal] **[confirmed]** (fixed)
  Fixed in `bddd782e` (#254): the suffix is `L`.
  `src/expression-formatter.cpp` lines 892 to 903 append `ld`; C++ has
  no such suffix (`L` is the long double suffix). Probe `p3.cpp`:
  `0.1ld == 0.2ld`. Suggested change: append `L`, as the other suffixes
  follow the C++ literal syntax (`u`, `l`, `ul`, `ll`, `ull`, `f`).

## 2. Usability

- **#6 — The public signatures of the checks show an internal type and
  a parameter that the users must not pass.** [breaking] (withdrawn)
  `test.h` lines 1394 to 1491: `expect()` and `require()` return
  `detail::check_result&&` and take a third parameter,
  `detail::check_result&& result = detail::check_result{}`. The manual
  declares `auto expect (const Expr_T&, const source_location& = ...)`
  (newcomer report). The change suggested in #2 makes the signatures
  `detail::check_result expect (const Expr_T&, const source_location& =
  ...)`; only a call that passes the third argument breaks, and no user
  has a reason to. Release notes: "the third, internal, parameter of
  `expect()` and `require()` was removed".

  Withdrawn, with #2: the third parameter is the temporary that the
  design of #2 relies on. The defaulted parameter remains an
  implementation detail of the signatures; the manual describes the
  checks with `auto` as the return type.

- **#7 — The diagnostic of an unsupported condition points into the
  library.** [internal] **[confirmed]** (withdrawn)
  Withdrawn: it depended on #18, which was withdrawn; the message cannot
  name the type in a `static_assert` before C++26.
  `inlines/test-inlines.h` lines 519 to 530 and 568 to 579: the
  `static_assert` of the `unsupported_condition` overloads is reported
  at `test-inlines.h:526`, not at the user's line, and does not name the
  type (newcomer `m1.cpp`: 34 lines with clang, 38 with GCC; 22 and 21
  with a `test_case&` parameter). The user line appears only in the
  "required from" notes. Suggested change: see #18, which reduces the
  overloads to one; the message could add "(see the line of the call
  below)", since the type cannot be named in a `static_assert` before
  C++26.

- **#8 — The test body constraint exempts the generic lambdas, and its
  first note misleads.** [internal] **[confirmed]** (withdrawn)
  Withdrawn: the exemption is deliberate (#246, commit `5e6cc586`): to
  check a generic lambda the compiler instantiates its body, and an
  error in the body becomes an error of the check, with a longer trace.
  `test.h` lines 1057 to 1103 (`generic_callable`, `test_body`,
  `suite_body`): a class without a non-template `operator()` (a generic
  lambda) satisfies the constraint without any check, so
  `[] (auto& t, int x)` with no argument fails inside
  `detail::callable_ref::invoke_callable` (`test-inlines.h:422`,
  newcomer `m4b.cpp`). For a non-generic lambda with wrong parameters
  (`m4.cpp`, `m6.cpp`), clang first explains that the lambda does not
  satisfy `generic_callable`, and the real reason (`is_invocable_v`)
  comes last; GCC stops at "no operand of the disjunction is
  satisfied". Suggested change: check `std::is_invocable_v` for the
  generic lambdas too (`auto&` parameters deduce without instantiating
  the body, unless the return type is deduced); if a probe shows hard
  errors for some bodies, keep the exemption but order the disjunction
  so that `is_invocable_v` is reported first.

- **#9 — The diagnostics of an invalid comparison name only the
  internals.** [internal] **[confirmed]** (partly fixed)
  Partly fixed in `45139a09` (#256): the comparison is now checked first, so
  Clang reports the invalid operator and the two types first; GCC still
  reports only the disjunction, and the size is unchanged.
  `inlines/detail-inlines.h` lines 278 to 450: `eq (1, "abc")` and
  `eq (std::string, std::vector<int>)` explain the failure through
  `detail::equal_operands`, `sign_mixed_integers`,
  `function_pointer_pair`, `comparison_lookup::can_equal`, and
  `detail::c_string` instead of `const char*` (newcomer `m2a.cpp`,
  `m2b.cpp`: 28 lines with clang, 34 with GCC, which never says that
  `==` is missing). Suggested change: #17, which replaces the six
  disjunctions with one concept whose last, and therefore reported,
  requirement is the comparison itself.

- **#10 — Characters in a check message are printed in two styles.**
  [internal] **[confirmed]** (withdrawn)
  Withdrawn: the prefixed form is deliberate (see the Doxygen comments
  of the `operator<<` overloads, "also in the plain mode"): a
  `char16_t`, `char32_t`, or `wchar_t` value is not necessarily text, and
  printing it as UTF-8 needs a transcoder, which the small targets do not
  carry.
  `src/expression-formatter.cpp` lines 459 to 530: in a message,
  `'x'` prints as `x`, but `u8'x'` and `L'x'` print as `u8'x'` and
  `L'x'`, while the strings of the same types (`u"ab"`, `std::wstring`)
  print raw (probe `p3.cpp`). Suggested change: in the plain mode,
  print every character type as its UTF-8 text, as the strings are.

- **#11 — Programs with static suites only must still write the whole
  `main()`.** [internal]
  Newcomer `t7-main.cpp`: every program repeats
  `mt::runner tr; tr.initialise (argc, argv); ...
  return tr.run_suites ();`, and the static suites in other files need
  `extern mt::runner tr;`. Suggested change (optional, additive): an
  optional source file with a default `main()` and a default runner,
  which the build includes only on request. This adds a feature, so it
  is listed only for completeness; the maintainer may prefer to keep
  the explicit `main()`.

## 3. Structure and layering

- **#12 — The internal classes share their state through friendships
  instead of interfaces.** [internal]
  48 `friend` declarations in the public headers: `runner` befriends
  both reporters, `runnable_base`, and `static_suite`;
  `runnable_base` befriends `runner`, `check_result`, and both
  reporters; `suite` befriends five classes; `counters` five. The
  reporters read `runner::options_`, `runner::stopwatch_`,
  `suite::stopwatch_`, `test_point_number_`, `own_index_`, and
  `child_test_cases_count_` directly (`src/reporter-tap.cpp` lines 347,
  386, 460 to 530, 600, 827, 1000), and `check_result` reaches into the
  reporter's `expression_` (`inlines/test-inlines.h` lines 507 to 509).
  Every change of a private member therefore touches the reporters.
  Suggested change: give the reporters a small set of `const` accessors
  in `runnable_base` (`test_point_number()`, `own_index()`,
  `child_test_cases_count()`, `elapsed()`), pass the arguments and the
  elapsed time to `begin_session()`/`end_session()`, and remove the
  friendships that only serve reading; #15 removes the access to
  `expression_`.

## 4. Naming and consistency

No findings beyond #5 and #10, and the option spellings (#20).

## 5. Simplicity and duplication

- **#13 — The reporters write through two mechanisms and fixed-size
  buffers.** [internal] (withdrawn)
  Withdrawn: the `char` arrays of the totals and of the elapsed time keep
  those lines off the heap; with `std::string` each test case and suite
  end would allocate, on targets with small heaps. The gain is
  readability only, and the effect on the code size was not measured.
  `reporter.h` lines 328 to 420 and 902 to 1116, `src/reporter.cpp`
  lines 441 to 530 and 806 to 1000: the per-check lines are composed
  with stream operators into `buffer_` (ten `operator<<` overloads,
  `endl`, `indent()`), the other lines with three printf-style
  functions (`write_console()`, `write_file()`, `write_line()`, with
  `va_copy` and a 128-byte local buffer), and the totals with
  `snprintf()` into `char` arrays whose sizes are computed by hand
  (`totals_size_ = 94 + 6 * (digits10 + 1)`, `fragment_size`,
  `elapsed_time_size_`, with a `static_assert`). Since `std::string` is
  already used for every buffer, suggested change: compose every line
  in a `std::string` with `append()` and `detail::append_number()`, and
  write it through one function that takes the text and the route
  (console, file, or both). The stream operators of `reporter`, the
  variadic functions, the format attributes, the
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE` macro, and the size
  arithmetic all go. The cross build shows that the current frames are
  small (at most 336 bytes, `reporter_tap::end_suite()`), so the change
  is about readability, not stack.

- **#14 — The rules for what is shown, and for the blank lines, are
  written twice, as a state machine spread over both reporters.**
  [internal]
  `src/reporter-human.cpp` and `src/reporter-tap.cpp` (together 1,066
  lines): each reporter implements, separately, the deferred display of
  the suite and test case headings (`open_test_cases_` with
  `name_displayed`, `current_suite_`, `suite_displayed_`,
  `display_open_names()`, `display_open_test_cases()`,
  `display_open_heading()`), the commit of the buffered checks
  (`commit_buffer()`, `commit_outer_results()`, `console_lines()`,
  `write_quiet_failures()`), and the blank lines (`add_empty_line_` is
  read or assigned in 29 places in the human reporter and 26 in the TAP
  reporter). The decisions depend on the verbosity, the output file,
  `route (record_kind)`, and `writes_passed_checks()`, which overlap.
  This is the part of the code that is hardest to change without
  breaking the expected outputs. Suggested change, in two steps:

  1. move the policy to the base class: one function decides, for each
     event (heading, check, result, skip, abort), whether it goes to the
     console, the file, or the deferred buffer, and which pending
     headings must be shown first; the derived classes only format a
     heading, a check line, and a result line;
  2. replace the blank-line tracking by a fixed rule (for example, one
     blank line before each suite heading and before the totals, none
     elsewhere), and update the expected files once.

- **#15 — The expression text is kept in a shared buffer with owner
  bookkeeping.** [internal] (withdrawn)
  Withdrawn: a second `std::string` in every `check_result` adds 32
  bytes to the frame of each check; in unoptimised builds the checks of
  a test body do not share their slots, which is what overflowed the
  8 KB stack of the QEMU targets (see the stack note in
  `miscellaneous.cpp`). The shared buffer exists to avoid this cost.
  `expression-formatter.h` lines 1140 to 1182 and 1510 to 1525,
  `src/expression-formatter.cpp` lines 1055 to 1123,
  `inlines/check-result-inlines.h` line 120, `src/check-result.cpp`
  lines 157 to 176: one `expression_formatter`, owned by the reporter,
  formats the expressions of all checks; to support two check results
  alive at once, it keeps an `owner_` pointer and a `pending_` vector of
  (owner, text) pairs, searched by `check_text()` and `end_check()`. The
  only saving is the reuse of one heap buffer, and only when the passed
  checks are written (verbose mode or output file), because nothing is
  formatted otherwise. Suggested change: let `check_result` own its
  expression text, next to the message it already owns, and format into
  it with a local formatter; `begin_check()`, `check_text()`,
  `end_check()`, `owner_`, `pending_`, the reporter's `expression_`
  member, and the corresponding friendships go.

- **#16 — Three callable wrappers, and three special cases for member
  pointers, where two lambdas would do.** [internal] (withdrawn)
  Withdrawn: `bound_callable` and `callable_ref` exist so that, without
  optimisations, the call chain of each nested test case has no frames
  for a lambda call operator (which cannot be always inlined portably)
  nor for `std::invoke()` (three frames), which matters on the 8 KB
  stacks of the QEMU targets; two lambdas would lengthen the chain.
  `test.h` lines 797 to 1004, `inlines/test-inlines.h` lines 268 to 424
  and 865 to 876: `bind_callable()` produces either the callable itself
  or a `bound_callable` (a callable plus a `std::tuple` of the
  arguments, invoked through an `index_sequence`), which a test case
  wraps in a `callable_ref` (a hand-written function reference) and a
  suite in a `std::function`; `bound_callable::invoke()`,
  `callable_ref::invoke_callable()`, and `test_each_value()` each
  repeat `if constexpr (std::is_member_pointer_v<...>)`, which
  `std::invoke()` already handles. Suggested change:

  - test cases run synchronously, so `create_test_case()` can wrap
    `[&] (test_case& t) { std::invoke (callable, t, arguments...); }`
    in the existing `callable_ref`, with no copy of the arguments (see
    #26);
  - suites are deferred, so the suite constructor can store
    `[c = std::forward<C> (callable), ...a = std::forward<A>
    (arguments)] (suite& s) mutable { std::invoke (c, s, a...); }` (a
    C++20 pack init-capture) in its `std::function`;
  - `bind_callable()`, `bound_callable`, and the member pointer special
    cases go.

- **#17 — Six comparison tags and twelve concepts differ only in the
  operator.** [internal] (partly fixed)
  Partly fixed in `eb68e27d` (#255): the twelve concepts became `comparable`
  and `can_compare`, selected by an enumerator; the standard functors
  were rejected (`-Wnoexcept`), and the six tags remain, since they are
  named in the reports and the extension interface.
  `detail.h` lines 435 to 777 and `inlines/detail-inlines.h` lines 278
  to 576: each of `equal_to`, ..., `less_equal` has the same `apply()`
  (`std::cmp_*` for mixed signedness, otherwise the operator, with a
  `using std::operator...`), and each has its own `*_operands` concept
  and its own `comparison_lookup::can_*` concept, all written as the
  same three-way disjunction. Suggested change: one template, for
  example `template <class Op_T, auto Cmp_F, fixed_string Symbol>
  struct comparison`, where `Op_T` is the transparent standard functor
  (`std::equal_to<>`, `std::less<>`, ...; their `operator()` is
  constrained, and `std::less<>` also gives the total order of the
  pointers), `Cmp_F` the matching `std::cmp_*`, and one concept
  `comparable<Op_T, L, R>` whose last requirement is the comparison
  itself, which also shortens the diagnostics (#9). The reason for
  `function_pointer_pair` is not evident from the code; a probe should
  establish whether the standard functors make it unnecessary.

- **#18 — `expect()` and `require()` have four overloads that differ
  only in the kind of check.** [internal] (withdrawn)
  Withdrawn: the gain is about 90 lines; an unconstrained overload still
  instantiates its body for a type that is not a condition, so it needs
  an `if constexpr` guard to avoid a cascade of errors after the
  `static_assert`; and a shared private `check()` adds a frame to every
  check in unoptimised builds, which matters on the 8 KB stacks (see
  #16).
  `test.h` lines 1119 to 1125 and 1394 to 1491,
  `inlines/test-inlines.h` lines 495 to 579: each check has a
  constrained overload and an `unsupported_condition` overload that
  only fires a `static_assert`, and the bodies of `expect()` and
  `require()` are identical except for `check_kind`. Suggested change:
  one unconstrained overload of each, starting with the `static_assert`,
  both calling one private `check (kind, expr, location)`. The
  deprecated `legacy_checkable` overloads remain more constrained, so
  overload resolution still prefers them. The concept
  `unsupported_condition` goes.

- **#19 — The totals are aggregated irregularly.** [internal] (withdrawn)
  Withdrawn: the aggregation is deliberate (see the Doxygen comment of
  `after_test_case_create()`): a test case reports only its own checks,
  as in node-tap, while its failure and its count reach the parent.
  Changing it would alter the printed totals of the parent test cases.
  `src/test.cpp` lines 245 to 326: when a nested test case ends, its
  parent test case receives the test case counts (executed, failed,
  skipped), but the suite receives the nested checks directly; so a
  parent's `totals()` counts its nested test cases but not their
  checks, and the suite receives the counts through two paths. The
  result is correct, but hard to verify. Suggested change: aggregate as
  a tree (each node adds its totals to its parent, the suite to the
  runner); if the reporters must keep showing the parent's own checks
  only, keep a separate "own checks" pair of counters. This changes the
  totals printed for the parent test cases, so the expected files must
  be updated in the same commit.

- **#20 — The command line accepts many spellings for the same
  options.** [breaking]
  `src/runner-options.cpp` lines 170 to 217 and 286 to 349: `--colour`,
  `--color`, `--use-colour`, and `--use-color`; the values `always`,
  `yes`, `force`, `never`, `no`, `none`, `auto`, `tty`, and `if-tty`;
  `--list` and `--list-tests`; and a special error for `--colour`
  followed by a word that is a colour mode (`is_colour_mode()`), needed
  because `--colour` alone means `always`. Suggested change: keep
  `--colour[=always|never|auto]` (and `--color` if American spelling is
  wanted) and `--list-tests`; accept the others for one major release
  with a warning on the console, then remove them. Release notes: "the
  option aliases `--use-colour`, `--use-color`, `--list`, and the colour
  values `yes`, `force`, `no`, `none`, `tty`, and `if-tty` are
  deprecated".

- **#21 — A public header and its inlines file hold one non-deprecated
  function.** [internal]
  `math.h` and `inlines/math-inlines.h`: `detail::math::abs()` is used
  once (`inlines/detail-inlines.h` line 719); `min_value()` serves the
  deprecated code only. Suggested change: move `abs()` next to its only
  caller and remove the two files at the next major release (after
  #30); until then, they can stay as they are.

- **#22 — `utility::split()` exists twice and is not used by the
  library.** [breaking]
  `utility.h` lines 131 to 157, `inlines/utility-inlines.h` lines 89 to
  113, `src/utility.cpp` lines 212 to 230: a template and a
  `std::string_view` overload with the same body; no file in `include/`
  or `src/` calls either. Suggested change: mark the template
  `[[deprecated]]` (the `std::string_view` overload covers every
  argument the template accepts that has `find_first_of()`), and
  consider whether `split()` belongs in a testing framework at all.

- **#23 — `located_name` has a redundant constructor.** [breaking]
  `test.h` lines 194 to 232: the `const std::string&` constructor does
  what the `std::string_view` one does for an lvalue string (the copy
  into `name_` is the same). Suggested change: remove it; every current
  call still compiles, so only code that takes its address breaks.

- **#24 — `runner_options` defines its copy assignment by hand.**
  [internal] (withdrawn)
  Withdrawn: it is not defaulted on purpose; the defaulted copy
  assignment of the vectors of strings uses `std::copy`, which triggers
  `-Waggregate-return` in the standard library headers of GCC on some
  targets (see the Doxygen comment of the operator).
  `inlines/runner-options-inlines.h` lines 59 to 65: the copy assignment
  copies into a temporary and moves it, which is what `= default` does,
  except for the strong exception guarantee, which nothing needs here.
  Suggested change: `= default`, as for the other special members.

## 6. Modern C++

No separate findings: the variadic `printf`-style functions are covered
by #13, the hand-written member pointer dispatch by #16, and the
`const&&` qualifier of `check_result::value()` by #2.

## 7. Suitability for embedded targets

- **#25 — Comparing two lvalue containers copies both.** [internal]
  **[confirmed]** (withdrawn)
  Withdrawn: the copy is deliberate (`stored_operand_t`): an expression
  that an application function builds from its parameters, and returns,
  must not refer to the destroyed locals of that function. The cost is
  the two allocations of the probe, for the containers only.
  `detail.h` lines 228 to 232: `stored_operand_t` stores by reference
  only the lvalues of non-copyable types; every copyable lvalue is
  copied into the expression template. Probe `p2.cpp` (counting
  `operator new`): a passing `t.expect (eq (v1, v2))` on two
  `std::vector<int>` of 100 elements makes 2 heap allocations in the
  normal mode (7 in the verbose mode), and so does `eq (s1, s2)` on two
  long `std::string`; `t.expect (v1 == v2)` makes none. Suggested
  change: store the lvalues as `const&` and only the rvalues by value;
  an lvalue outlives the expression template in every use the API
  allows (`auto e = eq (a, f ())` still owns the result of `f ()`).

- **#26 — The arguments of a test case are copied for each test
  case.** [internal] (withdrawn)
  Withdrawn, with #16: storing references would change the documented
  semantics (a reference parameter refers to the copy, not to the
  caller's object); an application that does not want the copy passes a
  pointer or `std::ref()`.
  `inlines/test-inlines.h` lines 268 to 318: `bind_callable()` stores
  `std::decay_t` copies of the extra arguments of `test()` in a tuple,
  although the test case runs before `test()` returns; a container
  passed as an argument is therefore allocated and copied for every
  test case. Suggested change: the by-reference lambda of #16. The
  suites, which are deferred, must keep their copies.

## 8. Incidental observations

- **#27 — A comment line exceeds 80 characters.** [internal] (fixed)
  Fixed in `e5e5fbd4`: the comment is re-wrapped.
  `inlines/test-inlines.h` line 98 (119 characters, in the comment of
  the `located_name` constructor).

- **#28 — Header comments that the newcomer could not rely on.**
  [internal] (fixed)
  Fixed in `e5e5fbd4`: the comments of the `extension` namespace, `is_op`, `throws()`, `nothrow()`, and the `runner_options` constructor were corrected.
  To be handled with the `doxygen-review` skill: the `extension`
  namespace comment points to `detail.h` for the constructor form
  `compare_op{ lhs, rhs, tag{} }`, and does not list `compare_tag`,
  `predicate_tag`, and `approx_operand`; the comment of `is_op` explains
  it through the deprecated `to_i` and `_i` and through `detail::op`;
  the comments of `throws()` and `nothrow()` name `detail::throws_op`;
  the comment of `runner_options (argc, argv)` omits `--list`; nothing
  says that `throws<Base>()` passes for a derived exception.

- **#29 — The manual shows a different signature of `expect()`.**
  [internal] (fixed)
  Fixed in `e5e5fbd4`: the manual says that the return type is internal and the object cannot be kept; the strings example uses a plain literal.
  To be handled with the `website-review` skill, after #2 and #6: the
  manual declares `auto expect (const Expr_T&, const source_location&)`;
  it also uses `"fortytwo"sv` in the strings example without saying why
  a plain literal would not do.

- **#31 — `throws<std::exception>()` makes the compilers warn.**
  [internal] **[confirmed]** (fixed)
  `inlines/detail-inlines.h`, `throws_op<Exception_T>::throws_op`: the
  handler of `std::exception` is unreachable when `Exception_T` is
  `std::exception` or a base of it, and Clang and GCC report
  `-Wexceptions` in the code of the application. Found while checking
  the claim in the documentation of `throws()`. Fixed in `3e7f46ac`:
  the warning is ignored around the constructor, and the unit test
  checks `throws<std::exception>`.

## 9. Reviewed and found sound

- All 18 public headers compile on their own; `clang-format --dry-run
  --Werror` reports no difference.
- On Cortex-M4F (`-Os`, no exceptions, no RTTI), no function of the
  library has a frame above 336 bytes.
- The comparisons of mixed signedness use `std::cmp_*`; the integer
  branch of `approx()` (`differ_by_at_most()`) handles the full range
  without overflow; the floating-point branch handles the infinities
  and NaN.
- The null C strings compare and print consistently (`c_string`), and
  character arrays stop at their terminator, or at their size.
- A failed `require()` inside a nested test case stops only that test
  case; a `require()` that fails inside the callable of `throws()` is
  propagated, not counted as the expected exception.
- A check on a test case that is not running is reported as a failure
  of the running test case (`report_misdirected()`); #1 is the missing
  counterpart for the test cases.
- The names are escaped once, in `located_name`; the TAP descriptions
  and YAML values are escaped; the TAP output of the ordinary runs
  validates.
- The command line errors, the output file errors, `--help`, and
  `--list-tests` decline the session consistently, with exit codes 2,
  2, 0, and 0 or 2.
- The call order of the session functions (`initialise()` twice,
  `add_top_suite()` twice, `run_suites()` twice, suites added during or
  after the run) is checked and reported, except for #1.
- The static suites constructed before the runner, in other translation
  units, are registered without touching the runner object.

## Deprecated

- **#30 — The deprecated functionality is spread through the
  non-deprecated code.** [breaking] [deprecated]
  Besides the 1,289 lines of `deprecated.h`,
  `inlines/deprecated-inlines.h`, and `src/deprecated.cpp`, there are
  120 `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED` blocks in 21
  other files, and several mechanisms exist only for them: `unwrap()`,
  `within_tolerance()` and `within_tolerance_result`, `has_value`,
  `has_epsilon`, `legacy_checkable`, `named_bool`, `math::min_value()`,
  and the deprecated members of `runner`, `test_case`, `suite`,
  `counters`, `stopwatch`, and `reporter`. Removing them at the next
  major release, as planned by the `[[deprecated]]` messages, is the
  largest single simplification, and also makes #21 possible. Release
  notes: the list of the deprecated entities, each with its
  replacement, as given in its `[[deprecated]]` message.
