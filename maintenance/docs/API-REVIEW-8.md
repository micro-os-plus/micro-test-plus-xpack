# C++ API review

Date: 2026-11-04, on branch `xpack-development`, commit `35a688d0`.

Scope: the umbrella header `include/micro-os-plus/micro-test-plus.h`,
the public headers in `include/micro-os-plus/micro-test-plus/`, their
inline definitions in `inlines/`, and the definitions in `src/`. The
deprecated functionality (`deprecated.h`, `inlines/deprecated-inlines.h`,
`src/deprecated.cpp`, and the members marked `[[deprecated]]`) was
excluded at the request of the maintainer, so this report has no
`[deprecated]` items. The Doxygen comments were ignored, except by the
newcomer exercise of section 2.

Method: the comments were stripped with
`.github/skills/api-review/scripts/strip-comments.mjs` (46 files,
10183 lines of code), and every stripped file outside the deprecated
set was read in full, from the umbrella header inwards. All 18 public
headers compile on their own (`check-headers.mjs`), and
`clang-format --dry-run --Werror` reports no difference. The probes
were built natively with Apple clang 17.0.0 (`-std=c++20 -Wall -Wextra
-Wpedantic`; with `-fsanitize=address,undefined` for the lifetime
questions; once with `-fno-exceptions -fno-rtti`), and compiled with
`arm-none-eabi-g++` 15.2.1 (`-mcpu=cortex-m4 -mfloat-abi=hard
-fno-exceptions -fno-rtti -Os -Wframe-larger-than=512 -fstack-usage`)
for the GCC diagnostics and the stack frames; no working native GCC is
installed on the review host. Every TAP output was checked with
`tests/scripts/validate-tap.mjs`. The newcomer programs of section 2
were written by a separate sub-agent, which read only the user manual
and the public declarations, and used Clang 17 and `arm-none-eabi-g++`
14.2.1. No program size was measured, so no item claims a size
difference.

Independence: the earlier reports in `maintenance/docs/`, and the
commits and issues that refer to them, were deliberately not
consulted.

Summary: 41 problems (0 open, 22 fixed, 19 withdrawn). The defects of
section 1 are fixed (#1 to #3, #5 to #7) or withdrawn (#4), the
diagnostics of the common mistakes are fixed (#8 to #11), the other
findings of the code are fixed (#20, #23, #30) or withdrawn, and the
documentation items (#32 to #41) are fixed (#33 to #41) or withdrawn (#32).
The withdrawn items are #4, #12 to #19, #21, #22, #24 to #29, #31, and #32:
#4 needed `std::move()` to defeat the guards of #222 and #230, and the
others are deliberate design decisions or judgements (see the notes in the
API review skill).

Tags: **[breaking]** means that the suggested change alters the public
API; **[internal]** means that it does not; **[confirmed]** means that
a probe reproduced the problem (the others are derived from reading the
code).

## 1. Defects

- **#1 — `test()` on a static suite before the runner is initialised
  dereferences a null pointer.** [internal] **[confirmed]** (fixed)
  `src/test.cpp` lines 220 to 252, `inlines/runner-inlines.h` line 100:
  `accepts_test_case()` calls `runner::has_option_errors()`, which
  calls `reporter_->has_output_file_error()`; `reporter_` is created by
  `initialise()`, so it is null until then. A `static_suite` is a
  `suite`, and its `test()` member is reachable from `main()`:

  ```c++
  static mt::runner r;
  static mt::static_suite s{ "static", r, [] (mt::suite&) {} };
  int main () { s.test ("t", [] (mt::test_case& t) { t.expect (true); }); ... }
  ```

  UBSan reports `member call on null pointer of type 'detail::reporter'`
  at `runner-inlines.h:100`, followed by a SEGV in
  `reporter::has_output_file_error()`. Make `has_option_errors()`
  null-safe (`reporter_ != nullptr && ...`), and, in
  `accepts_test_case()`, treat `session_state::created` as "not
  running": print the error and call `mark_rejected()`, as for a suite
  that is not running.

  Fixed in `5ec9632e` (#259): `has_option_errors()` tolerates the
  missing reporter, so the call is rejected with the existing "not
  running" error and `run_suites()` returns 1; the cause, not the
  message, was changed, as the existing path already printed the error
  and called `mark_rejected()`. Tested in `miscellaneous.cpp`.

- **#2 — Wide and Unicode string literals and pointers are compared as
  arrays or as addresses.** [internal] **[confirmed]** (fixed)
  `inlines/detail-inlines.h` lines 1376 to 1410 (`as_operand()`)
  converts only the arrays of and the pointers to `char` into
  `c_string`. A `wchar_t`, `char8_t`, `char16_t`, or `char32_t`
  literal becomes an `array_operand` whose element count includes the
  terminator, so it never equals the string with the same text, and a
  pointer is compared and printed as an address:

  ```text
  ✗ wchar_t literal vs wstring FAILED (p2.cpp:12, {L'a', L'b', L'c', L'\0'} == "abc")
  ✗ char8_t literal vs u8string FAILED (p2.cpp:13, {u8'a', u8'b', u8'c', u8'\0'} == "abc")
  ✗ char16_t literal vs u16string FAILED (p2.cpp:14, {u'a', u'b', u'c', u'\0'} == "abc")
  ✗ wstring vs literal FAILED (p2.cpp:15, "abc" == {L'a', L'b', L'c', L'\0'})
  ✗ wchar_t pointer vs wstring FAILED (p2.cpp:17, 0x10ef6ec30 == "abd")
  ```

  The same values compare equal with `char`. Make `c_string` a template
  on the character type (`basic_c_string<Char_T>`), and route all five
  character types through it in `as_operand()`, so that the arrays are
  trimmed at the first terminator, the pointers are compared by
  content (with `nullptr` handled as now), and the formatter prints
  them as strings.

  Fixed in `d85947d0` (#260): `basic_c_string<Char_T>` replaces
  `c_string` (which remains as an alias for `char`), and the arrays and
  pointers of the five character types are converted to it, also as
  the elements of ranges, pairs, and tuples. The messages and the
  expression syntax of #22 were not changed.

- **#3 — A test case started on a test case or a suite that is not
  running is silently nested in the running test case.** [internal]
  **[confirmed]** (fixed) `inlines/test-inlines.h` lines 810 to 835 and 459 to
  472: `suite::test()` forwards to the running test case, whatever its
  suite, before `accepts_test_case()` can detect that the target suite
  is not running; `test_case::test()` has no check at all, unlike
  `expect()` and `require()`, which report a misdirected check
  (`is_misdirected()`, lines 479 to 484). In the probe, `outer.test()`
  called from within the nested `inner`, and `other->test()` called on
  the suite of another `add_suite()`, both run, the second one
  displayed inside `inner`, in the wrong suite; the TAP output is
  invalid at every verbosity except `--quiet`:

  ```text
  p13.tap > B > outer > inner: test point id 1 appears multiple times
  ```

  In `suite::test()`, forward only when the running test case belongs
  to this suite (`&running->parent_suite_ == this`); otherwise fall
  through to `accepts_test_case()`. In `test_case::test()`, when
  `is_misdirected()`, report a failed check on the running test case,
  as `report_misdirected()` does, and do not run the body.

  Fixed in `5a14844e` (#261): as proposed; both rejections are reported
  as a failed check of the running test case, which also holds for a
  suite that is not running, whose failure was previously reported at
  the level of the running suite, in the middle of the open test case.

- **#4 — The result of `expect()` and `require()` can be kept in a
  reference that dangles.** [internal] **[confirmed]** (withdrawn) `test.h` lines
  1434 to 1531: the functions return `detail::check_result&&` bound to
  a defaulted argument, whose lifetime ends with the full expression.
  `auto&& r = t.expect (eq (1, 2)); std::move (r) << "message";`
  compiles without a warning with Clang (`-Wall -Wextra`) and with
  `arm-none-eabi-g++` 15 (`-Wall -Wextra`), and ASan reports
  `stack-use-after-scope` in `check_result::operator<<`. Adding
  `[[clang::lifetimebound]]` to the defaulted parameter does not make
  Clang warn either. Returning the object by value would make the
  pattern well defined, but the reference would then extend its
  lifetime and delay the report to the end of the scope, which the
  rule of immediate reporting forbids. Two options, for the maintainer
  to choose: accept that delay in this unusual case (the order of the
  report is the only visible effect); or keep the current design and
  state, in the manual and in the declarations, that the result must
  not be named. With either, add a test that fails under ASan if the
  pattern regresses.

  Withdrawn: the probe forced the message operator with `std::move (r)`,
  which defeats the rvalue-qualified members that keep a named result
  from being used (`r << "message"` does not compile); the restriction is
  documented in the manual, in the Doxygen comments of `expect()`,
  `require()`, and `check_result`, and in the API review skill. See
  also #222 and #230 of the GitHub issues.

- **#5 — `throws()` and `nothrow()` reject mutable lambdas, and give
  deep diagnostics for non-callables.** [internal] **[confirmed]** (fixed)
  `exceptions.h` lines 96 to 131, `inlines/detail-inlines.h` lines 882
  to 988: the callable is taken by `const Callable_T&` and called as
  `func ()`, so `throws<std::runtime_error> ([n] () mutable { ... })`
  fails with `no matching function for call to object of type 'const
  (lambda ...)'` at `detail-inlines.h:889` (Clang, 16 lines; GCC, 20
  lines). `throws (42)` fails with `called object type 'int' is not a
  function` at `detail-inlines.h:936`. Take `Callable_T&& func`, call
  it with `std::invoke (func)`, and constrain the three functions with
  `std::invocable<Callable_T&>`, so that the error names `throws()` and
  the constraint.

  Fixed in `cb8f6a7a` (#262): as proposed, in the three functions and in the
  constructors of `throws_op` and `nothrow_op`; the error for a value
  that is not callable now names `throws()` and `'int &' does not satisfy
  'invocable'`.

- **#6 — A non-copyable test case body is copied.** [internal]
  **[confirmed]** (fixed) `inlines/test-inlines.h` lines 268 to 318:
  `create_test_case()` passes the callable through `bind_callable()`,
  whose `auto` return type decays and copies it, although the test
  case runs and ends within the call. `no_copy b; s.test ("nc", b);`
  fails with `call to deleted constructor of 'no_copy'` at
  `test-inlines.h:308`. With no bound arguments, build the
  `callable_ref` on the callable itself (the lvalue, or the temporary,
  which lives until the end of the `test()` call); copy only when
  arguments are bound.

  Fixed in `44a355d2` (#263): as proposed; a function is still referred to
  through its pointer, and the copies are kept when arguments are
  bound. An lvalue callable is now called in place, so it keeps the
  changes of its state; this is documented in the manual.

- **#7 — `std::optional<bool>` is accepted as a condition, and passes
  when it holds `false`.** [internal] **[confirmed]** (fixed) `extension.h`
  lines 268 to 315: `checkable` accepts every type that is contextually
  convertible to `bool`, and `suspicious_condition` lists only arrays,
  functions, member pointers, and character pointers.
  `t.expect (std::optional<bool>{ false })` is counted as a passed
  check. Add the specialisations of `std::optional` to
  `suspicious_condition`, so that `expect()` reports, through the
  existing `static_assert`, that the condition must be written as
  `eq (o, false)` or `o.has_value ()`. Migration: for one major release,
  route these types through the deprecated `legacy_checkable`
  overloads, whose message already explains the change.

  Fixed in `10479a1d` (#264): the wrappers `std::optional<bool>`,
  `std::unique_ptr<bool>`, and `std::shared_ptr<bool>` are rejected by
  `extension::checkable`, with a message in `expect()` and `require()`;
  no deprecation was needed, and the tag changed to [internal], since
  these types were accepted only since #155, in the unreleased 6.0.0
  (they did not compile in v5.0.1). The raw pointers to `bool` remain
  accepted.

## 2. Usability

The evidence of this section comes from the newcomer programs (in the
scratchpad folder `newcomer/`, with the mistakes in `newcomer/mistakes/`)
and from the reviewer's probes. The line counts are those of the first
diagnostic, with a `test_case&` body unless stated; "GCC" is
`arm-none-eabi-g++` 14.2.1.

- **#8 — A wrong test case or suite body is diagnosed only in terms of
  the internal concepts.** [internal] **[confirmed]** (fixed) `test.h` lines
  1097 to 1143 and 1330 to 1334, `runner.h` line 568: a body taking
  `int`, taking `suite&` for a test case, or taking nothing gives the
  same 24 (GCC) or 19 (Clang) lines: `'(lambda…)' does not satisfy
  'test_body'`, `'generic_callable'`, `'!requires { &…::operator(); }'
  evaluated to false`; only the last note, `is_invocable_v<…,
  test_case &> evaluated to false`, hints at the cause, and none says
  that a `test_case&` is expected. With an `auto&` body, a later error
  inside the body grows from 21 to 38 lines (GCC), and from 30 to 79
  for a bad message operand, because the stack runs through
  `detail::callable_ref` and `runnable_base::create_test_case`. Add, as
  for `expect()`, an overload constrained by the negation of the
  concept, whose `static_assert` says "the body of a test case takes
  `test_case&` as its first parameter, followed by the bound
  arguments" (and the same for the suites).

  Fixed in `aad44356` (#265): overloads for the callables that are not valid
  bodies, in `test_case::test()`, `suite::test()`, `runner::add_suite()`,
  and the `static_suite` constructor, with messages for the body written
  for the other kind, and for a body that cannot be copied; 13 or 14
  lines in Clang and GCC. The generic bodies remain unchecked (#246).

- **#9 — A comparison of unrelated types is diagnosed only in terms of
  the internal concepts.** [internal] **[confirmed]** (fixed)
  `function-comparators.h` lines 129 to 225,
  `inlines/detail-inlines.h` lines 426 to 433: `eq (point, 5)` gives 33
  (GCC) or 43 (Clang) lines; GCC reports `no operand of the disjunction
  is satisfied` over `comparison_lookup::can_compare`,
  `sign_mixed_integers`, and `function_pointer_pair`; Clang buries the
  useful `invalid operands to binary expression ('const app::point' and
  'const int')` at line 9, after `(detail::comparison)'\x00'`. The same
  shape appears for the containers of #12. Keep `printable` in the
  constraints, but move `comparable` into a `static_assert` in the
  body (or into a fallback overload), with a message such as "the
  operands of eq() cannot be compared with ==".

  Fixed in `e733b9ff` (#267): `detail::comparable_operands`, and an overload
  of each of the six comparators for the other operands, whose
  `static_assert` names the comparator and the operator, or says that an
  operand cannot be written (13 or 14 lines in Clang and GCC).

- **#10 — A message argument without `operator<<` is diagnosed through
  `check_result` and `lazy_message`.** [internal] **[confirmed]** (fixed)
  `check-result.h` lines 304 to 307: `t.expect (false) << opaque{}`
  gives 30 (GCC) or 25 (Clang) lines: `no match for 'operator<<'
  (operand types are '…detail::check_result' and 'app::opaque')`,
  followed by the candidates, the unrelated `operator<<` of other
  application types, and notes on `detail::lazy_message` and
  `std::invoke`. Add a fallback `operator<<` whose `static_assert` says
  "a message argument must be printable: define `operator<<
  (mt::expression_formatter&, const T&)` in the namespace of the type,
  or pass a callable that returns a printable value".

  Fixed in `728d5090` (#266): the concept `detail::message_argument` and an
  overload of the operator with a `static_assert` (11 or 12 lines); the
  probe also found that a lambda without captures returning `void`, or a
  value that cannot be written, was accepted and written as `true`, which
  is now rejected too.

- **#11 — An extension tag without `symbol` or `apply()` is diagnosed
  through the `compare_op` constructor.** [internal] **[confirmed]** (fixed)
  `detail.h` lines 887 to 890, `extension.h` lines 379 to 403: GCC
  gives 39 lines, starting with `no matching function for call to
  '…detail::compare_op<int, int, app::nosym_tag>::compare_op(<brace-
  enclosed initializer list>)'`, and reaches `nested requirement
  'printable<…decltype (Tag_T::symbol)…>' is not satisfied`; Clang (23
  lines) names the missing member, under a header that names
  `stored_operand_t<decltype(detail::as_operand(…))>`. Check the tag in
  the constructor body with two `static_assert`s ("the tag must have a
  static printable `symbol` member"; "the tag must have a static
  `apply (lhs, rhs)` that returns a value convertible to bool"), and
  leave only the operand constraints on the constructor.

  Fixed in `e5c75804` (#268): a second constructor of `compare_op` and
  `predicate_op` for the tags that do not satisfy the concept, with
  `static_assert`s that state what the tag needs (16 or 17 lines, one
  error); the formatter writes the symbol only when the tag has one, to
  avoid a second error. The tests of #8 to #11 check that the fallback
  overloads exist, not their messages.

- **#12 — Containers of different types cannot be compared, although
  arrays can.** [internal] **[confirmed]** (withdrawn) `inlines/detail-inlines.h`
  lines 1341 to 1363 and 426 to 433: `eq (int[2], std::vector<int>)`
  compiles (through `array_operand`), but `eq (std::vector<int>,
  std::array<int, 2>)`, `eq (std::vector<int>, std::vector<long>)`, and
  `eq (std::vector<int>, std::list<int>)` are rejected with the
  diagnostic of #9, while `eq (int, long)` is accepted. Compare any two
  ranges whose elements are equality-comparable element by element
  (with `std::ranges::equal` and
  `std::lexicographical_compare_three_way`), as is done for the arrays,
  when the standard provides no operator for the pair.

  Withdrawn: the comparators compare containers with the operators of the
  standard library, which define no comparison between different
  containers, and the manual says so ("the same type; a C array is also
  accepted against a container"); the arrays are the exception because
  they have no usable operator. The rejection of the other pairs is
  deliberate and has a clear message (see #9). A cross-container
  comparison would be a new feature. The API review skill now says so.

- **#13 — The `operator<<` of an application type is rendered
  differently in the reports and in `str()`.** [internal]
  **[confirmed]** (withdrawn) `inlines/expression-formatter-inlines.h` lines 421 to
  432 and 764 to 772: the operands that have no member `operator<<` are
  written through `plain_text::append()`, a formatter in the plain
  mode, so the strings that the application operator writes are not
  quoted, and the numbers have no suffix, although the built-in
  operands, pairs, tuples, and ranges are quoted. A report reads
  `named{alpha, t1, (1, 2)} == named{alpha , t1, (1, 2)}` (the trailing
  space is hard to see), and `rec{x , y , 5}`, even when the operator
  writes `formatter << std::string_view{ s }`; the same operator, run
  on a standalone formatter, gives `"rec{\"x \", \"y \", 5l}"` in
  `str()` (`t4b-quoting.cpp`). Testing the operator with `str()`
  therefore does not test what the reports show. Write the application
  operands in the same mode as the built-in operands (call `*this <<
  value`, and strip only the colour codes if they are the concern), so
  that there is one rendering.

  Withdrawn: the operands written by the `operator<<` of an application
  are written in the plain mode, as the messages are, on purpose (#233),
  since the members it writes were otherwise decorated with suffixes and
  quotes that the operator did not write; a formatter constructed by the
  application keeps the decorations of the reports, and the manual says
  so. The documentation error found while checking it is #33.

- **#14 — `throws<E>()` does not name the exception that was thrown
  instead.** [internal] **[confirmed]** (withdrawn) `inlines/detail-inlines.h`
  lines 882 to 911, `inlines/expression-formatter-inlines.h` lines 732
  to 752: `throws<std::out_of_range>, but a std::exception was thrown:
  "empty input"` (`t3-throws.cpp`) does not say that it was an
  `std::invalid_argument`. When `__cpp_rtti` is defined, record
  `typeid (e).name ()` (demangled with `abi::__cxa_demangle()` where
  available) in `callable_result`, and print it; without RTTI, keep the
  current text.

  Withdrawn: the type of the exception is deliberately not shown (#241);
  its name is available only with RTTI, in an implementation-defined
  (usually mangled) form, and the library must build with `-fno-rtti` and
  give the same reports in every build. The `what()` of a `std::exception`
  is reported. The API review skill now says so.

- **#15 — The first difference is shown for long ranges, but without
  its values, and never for long strings.** [internal] **[confirmed]** (withdrawn)
  `inlines/expression-formatter-inlines.h` lines 231 to 263 and 480 to
  506: two ranges of 300 elements print their first 16 elements and
  `(first difference at index 257)`, without the two differing values;
  two strings of 500 characters are printed in full on both sides, with
  no position (`t2b-large.cpp`). Print, after the index, the two
  elements at that index, and apply the same rule to the strings (an
  index, and a short window around it, when the strings are longer
  than a limit).

  Withdrawn: the report of a long range gives the index of the first
  difference, as decided (#208), to keep it short; the user finds the
  values with the index, and a string is written in full on purpose, so
  that the white space is visible. The values at the index would be a new
  feature. The API review skill now says so.

- **#16 — A lazy message is not shown for a passing check, even when
  the passing checks are reported.** [internal] **[confirmed]** (withdrawn)
  `inlines/check-result-inlines.h` lines 183 to 196: the lazy message
  is skipped whenever the check passes, while an eager message is kept
  whenever the check is written (`--verbose`, or an output file). With
  `--verbose`, `expect (eq (1, 1)) << "eager message"` prints `✓ eager
  message`, but `expect (eq (2, 2)) << [] { return std::string{ "lazy
  message" }; }` prints `✓ 2 == 2` (`p21`). Test `is_written_` for
  both kinds, so that the choice between them changes only when the
  message is computed, not whether it is shown.

  Withdrawn: a lazy message is called only if the check fails, by design.
  It exists for text that is valid only after a failure, such as the
  error of a `std::expected` that holds a value, which is undefined
  behaviour to evaluate after a success; the manual says so ("called only
  if the check fails"). The API review skill now says so.

- **#17 — The command-line errors appear twice on a terminal.**
  [internal] **[confirmed]** (withdrawn) `src/runner.cpp` lines 321 to 327: each
  error is written to `stderr` (`error: unknown option '--bogus'`) and
  to the console report on `stdout` (`Bail out! unknown option
  '--bogus'`), so an interactive user reads it twice. Write it to
  `stderr` only when the console report is silent or `stdout` is not
  the same terminal, or write it only through the reporter, which also
  writes the output file.

  Withdrawn: the command-line errors are written on `stderr` and by the
  reporter on purpose, as the manual says: the first for a shell or a
  script that discards the standard output, the second for the TAP stream
  and the output file (#175). On a terminal both are shown. The API review
  skill now says so.

- **#18 — The static suites of several translation units share the
  runner only by a naming convention.** [internal] **[confirmed]** (withdrawn)
  `test.h` lines 2383 to 2387: every `static_suite` takes a `runner&`,
  so each file that defines static suites must declare `extern
  mt::runner tr;` with the name chosen in `main()`'s file
  (`t7-static-suites.cpp`); together with the eight lines that every
  `main()` repeats (`t1` to `t7`), this is the only boilerplate. Offer
  a framework-provided default runner (for example
  `runner::default_runner()`, a function-local static, so that the
  initialisation order is safe) and a `static_suite` constructor
  without the runner argument that uses it.

  Withdrawn: the runner is an object that the application instantiates,
  and the static suites refer to it, on purpose; a program may have
  several runners, each with its own session, as the manual says ("Several
  runners"), and the framework has no global object, so the construction
  and the destruction order are the application's. A default runner would
  be a new feature. The API review skill now says so.

## 3. Structure and layering

- **#19 — Added suites run in name order, not in the order of
  `add_suite()`.** [internal] **[confirmed]** (withdrawn) `src/runner.cpp` lines
  598 to 620, `src/test.cpp` lines 655 to 671: `register_suite()` links
  the added suites into the same list as the static suites, which
  `link()` keeps sorted by `strcmp()`. Three suites added as `zeta`,
  `alpha`, and `Mid` run as `Mid`, `alpha`, `zeta`. The sorting is
  needed for the static suites, whose construction order depends on
  the link order; it is not needed for the added suites, whose order
  the application chooses, and nothing in the name `add_suite()`
  suggests it. Either keep the added suites in the order of the calls
  (run `children_suites_` in order, then the static suites, or append
  them at the end of the list), or make the sorting an explicit rule
  for all the suites, stated in the manual.

  Withdrawn: the single name order for all the suites is a deliberate
  design decision, documented in the user manual with a warning and the
  idiom of the numeric name prefixes; the static suites of different
  translation units have no defined construction order, so they must be
  sorted, and one rule for all the suites is simpler than two. The
  API review skill now says so.

- **#20 — The `extension` namespace exports two internal helpers.**
  [internal] (fixed) `extension.h` lines 267 to 332: `suspicious_condition`
  serves only to define `checkable`, and `legacy_checkable` only to
  select the deprecated `expect()` and `require()` overloads, yet it is
  defined even when the deprecated functionality is disabled. An
  application writing an extension needs neither, and the manual does
  not list them. Move both to `detail`, and define `legacy_checkable`
  only with `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED`.
  Migration: concepts cannot be marked `[[deprecated]]`, so the release
  notes must say that "the concepts `extension::suspicious_condition`
  and `extension::legacy_checkable` were internal and have been
  removed".

  Fixed in `d74a9b38` (#270): both concepts, and `ambiguous_condition`, are
  in `detail`; `legacy_checkable` is defined only with the deprecated
  functionality. The tag changed to [internal] and no alias was added,
  since the `extension` namespace does not exist in v5.0.1.

- **#21 — The public test classes expose `detail` in their base class
  and in their signatures.** [internal] (withdrawn) `test.h` lines 319 to 807,
  1227, 1796, and 1434 to 1531: `test_case` and `suite` derive publicly
  from `detail::runnable_base`, which provides their public `name()`
  and `totals()`; `expect()` and `require()` return
  `detail::check_result&&`; the constraints of `test()`, `add_suite()`,
  and the `static_suite` constructor are `detail::test_body` and
  `detail::suite_body`; and `mt::expression_formatter`,
  `extension::compare_op`, and `extension::predicate_op` are aliases or
  using-declarations of `detail` templates, whose members can be found
  only in `detail`. A newcomer limited to the public declarations had
  to learn by trial which bodies, operands, and formatter operations
  are accepted. Declare `name()` and `totals()` in `test_case` and
  `suite` themselves (or move the base out of `detail` under a public
  name that the applications cannot construct), give the body concepts
  public names, and declare the members of `expression_formatter` that
  the applications use (`operator<<` for the built-in types, `str()`)
  in a public section of its declaration.

  Withdrawn: the types of `detail` in the public signatures are accepted by
  design, as long as the applications never have to name them (the project
  documentation says so, and #51 removed the cases where they did); the
  diagnostics of the wrong bodies, operands, messages, and tags now state
  what is accepted without naming the concepts (#8 to #11). The API review
  skill now says so.

## 4. Naming and consistency

- **#22 — Characters and wide strings are formatted
  inconsistently.** [internal] **[confirmed]** (withdrawn)
  `src/expression-formatter.cpp` lines 411 to 457 and 473 to 543: in a
  message, `<< 'c'` prints `c`, but `<< L'x'` and `<< u8'y'` print
  `L'x'` and `u8'y'`, with the prefix and the quotes of the expression
  syntax (`p7`: `nullptr c 65 1.5 L'x' u8'y' 0x0`). In an expression,
  a `std::wstring`, `std::u8string`, `std::u16string`, or
  `std::u32string` operand prints as `"abc"`, exactly like a
  `std::string`, while their characters print with the prefix. Apply
  one rule: in the plain (message) mode print every character type as
  its UTF-8 text, as for `char`; in the expression mode prefix the
  wide strings as their characters are prefixed (`L"abc"`, `u8"abc"`).

  Withdrawn: both behaviours are deliberate and documented. The wide
  characters are written with their prefix, in the reports and in the
  messages (#151), since without it they would be mistaken for numbers;
  the strings of the wide types are written as UTF-8 text, without a
  prefix, so that they report like the `char` strings (#236). The manual
  says so. The API review skill now says so.

- **#23 — One line of `src/reporter-human.cpp` exceeds 80
  characters.** [internal] **[confirmed]** (fixed) `src/reporter-human.cpp`
  line 534 (a comment) has 81 characters. Rewrap it.

  Fixed in `05736e96`: the comment was rewrapped; no issue (a comment).

## 5. Simplicity and duplication

- **#24 — `runner_options` has a hand-written copy assignment.**
  [internal] (withdrawn) `inlines/runner-options-inlines.h` lines 58 to 64: the
  copy assignment constructs a copy and move-assigns it, while every
  other special member of the class is defaulted. The only difference
  from `= default` is the strong exception guarantee, which nothing
  relies on (the options are assigned once, in `initialise()`, by
  move). Declare it `= default`, and remove the inline definition.

  Withdrawn: the copy assignment is written by hand on purpose, to avoid
  the `-Waggregate-return` warning that the defaulted one triggers, in the
  standard library headers of GCC on some targets (#188); the comment of
  the declaration says so, and the review, which ignores the comments, did
  not see it. The API review skill now says so.

- **#25 — The six comparators and their six tags repeat one
  pattern.** [internal] (withdrawn) `function-comparators.h` lines 129 to 225,
  `inlines/function-comparators-inlines.h` lines 88 to 196, `detail.h`
  lines 429 to 771, `inlines/detail-inlines.h` lines 441 to 560: each
  of `eq()` to `le()` repeats the same constraint and body with another
  `detail::comparison` value and tag, and each tag repeats the
  `sign_mixed_integers` dispatch with another `std::cmp_*` function and
  operator. One tag template, parametrised by the `comparison` value
  (with the symbol, the `std::cmp_*` function, and the operator chosen
  by `if constexpr`), and one function template behind the six named
  functions, would remove about 200 lines of near-identical code
  without changing the API.

  Withdrawn: the gain is small, about 200 lines of mechanical code, none
  of the documentation, and nothing in the size, the speed, or the
  compile time, since all of it is inline templates; the cost is the
  names of the tags, which appear in the types of the expressions, in the
  diagnostics, in the formatter (the first difference is specific to
  `equal_to`), in the tests and in the developer pages, and a table of
  the deprecated tolerance results. The six relations are the complete set
  of the comparison operators, so the repetition will not grow.

## 6. Modern C++

- **#26 — Suite bodies and their arguments must be copyable.**
  [internal] (withdrawn) `test.h` lines 1137 to 1143 and 2141: `suite_body`
  requires copy-constructible callables and arguments, because the
  body is stored in a `std::function`. A suite body that owns a
  `std::unique_ptr`, or is bound to a move-only argument, is rejected,
  although the body is invoked only once. Store the body in a small
  owning type-erased holder (a `std::unique_ptr` to an internal
  `callable_holder<F>` with a virtual `invoke()`), which accepts
  move-only callables and also removes the `std::function` machinery
  from the image.

  Withdrawn: the suites keep their body in a `std::function` on purpose,
  since they run later (#140), and the manual says that the bodies and
  their arguments must be copyable; the compiler now says so (#265). The
  saving of program size was not measured, and a suite is created once;
  a move-only body can capture a pointer or a reference instead. The API
  review skill now says so.

## 7. Suitability for embedded targets

- **#27 — Every comparison copies its lvalue operands.** [internal]
  **[confirmed]** (withdrawn) `detail.h` lines 221 to 225 (`stored_operand_t`),
  used by the deduction guides of `compare_op`, `approx_op`, `and_op`,
  `or_op`, and `predicate_op`: an lvalue operand is stored by value
  whenever it is copyable. A passing `eq (v1, v2)` of two
  `std::vector<int>` of 1000 elements makes two heap allocations (and
  copies 8 KB); `eq (s1, s2)` of two 100-character `std::string` makes
  two; `eq (c1, c2)` of an application type copies each operand once
  (`p4`). The cost is paid for every check, passing or failing. An
  lvalue outlives the full expression in which `expect()` consumes the
  comparison, so storing a `const&` (as is already done for the
  non-copyable lvalues) is safe; keep the rvalues stored by value.

  Withdrawn: storing copies of the named operands is a deliberate
  trade-off. An expression built in a helper function from its
  parameters, and returned, or kept in a variable, must stay valid after
  the operands are destroyed, and a reference would dangle without any
  diagnostic. The cost is documented in the user manual and in the
  Doxygen comments, with the remedy of comparing a `std::string_view`
  (0 allocations in a probe, against 2 for two strings); the API review
  skill now says so. An opt-out for the large operands could be offered
  as a new feature.

## 8. Incidental observations

- **#28 — A generic `operator<<` template of the application is
  ambiguous with the range formatter.** [internal] **[confirmed]** (withdrawn)
  `expression-formatter.h` lines 835 to 838: for an application type
  with `begin()` and `end()`, a non-template
  `operator<< (expression_formatter&, const bag&)` is chosen correctly,
  but a template one (`template <class F> F& operator<< (F&, const
  bag&)`) is ambiguous with the member template for the ranges, so the
  type is not `printable`, and `eq()` reports `no matching function`
  (`p10`). Exclude from `formattable_range` the types for which a free
  `operator<<` is found, or state that the application operators must
  take `expression_formatter&` explicitly.

  Withdrawn: the manual prescribes an `operator<<` whose first parameter
  is an `mt::expression_formatter&`, and its example takes it; an operator
  with a generic first parameter is outside the contract, and a framework
  fix would be circular, since `extension::printable` is defined by the
  same expression. The API review skill now says so.

- **#29 — Scoped enumerations and `std::byte` print as their
  underlying type.** [internal] **[confirmed]** (withdrawn)
  `inlines/expression-formatter-inlines.h` lines 272 to 279: an
  enumeration with `unsigned char` as underlying type prints as
  `(unsigned char)65`, the same text as `std::byte{ 0x41 }` and as an
  `unsigned char` (`p7`), and one with `int` prints as `0 == 1`
  (`t4-apptype.cpp`), so the report does not show the type of the
  operands. Prefix the value with the enumeration name, which
  `reflection::type_name()` already provides (for example `colour{65}`,
  `std::byte{0x41}`).

  Withdrawn: the value of a scoped enumeration is written as its
  underlying type is written, deliberately, and the manual says so; the
  framework cannot know the names of the enumerators, which an
  application provides with an `operator<<`. Adding the name of the type
  would add noise to every report. The API review skill now says so.

- **#30 — The YAML `fileName:` value is not quoted.** [internal] (fixed)
  `src/reporter-tap.cpp` lines 1042 and 1043: the condition is written
  with `yaml_double_quoted()`, but the file name is written raw; a file
  name that contains a colon followed by a space, or starts with a YAML
indicator, makes the
  block invalid. Quote it with the same function. (Derived from reading
  the code; real source file names rarely trigger it.)

  Fixed in `c130b482` (#269): the name is quoted only when it is not made of
  letters, digits, and `_ . + / -`, so that the usual output does not
  change; verified with probes (`a #b.cpp` was read as `a`, `x: y.cpp`
  was a YAML error), with no automated test.

- **#31 — A test hook in a public class.** [internal] (withdrawn)
  `stopwatch.h`
  line 408: `friend struct stopwatch_test_access;` exists only for the
  unit tests. Since `stopwatch` is internal, a constructor taking the
  two time stamps, under `detail`, would serve the tests without a
  friend declared for them.

  Withdrawn: a friend declaration of a test accessor, defined only by the
  tests, is the usual way to reach the private readings of a class
  without any code in the program; the constructor proposed would add a
  public member, in `detail`, for the tests only. A preference.

- **#32 — The manual shows a different signature of `expect()` and
  `require()`.** [internal] (withdrawn) `website/docs/user/checks/index.mdx` lines
  69 to 79 show `auto expect (const Expr_T&, const source_location&)`;
  the header (`test.h` lines 1434 to 1531) has a third defaulted
  parameter, returns `detail::check_result&&`, and has a second
  overload for the rejected conditions. (`website-review`.)

  Withdrawn: the page says that the declarations show the parameters that an application passes, and that the return type is internal; the third, defaulted parameter is not passed by the applications.

- **#33 — The manual's advice on quoting in an application
  `operator<<` does not work in the reports.**
  `website/docs/user/checks/index.mdx` lines 453 to 457 advise
  `formatter << std::string_view{ s }` to quote a member; in a failure
  report the text is not quoted (see #13). Correct the manual together
  with #13. (`website-review`.)

  Fixed in `06c94f00` (a documentation fix, with no issue): the sentence of the checks
  page now says that the members of the application types are not quoted
  by the report, and that the operator writes the quotes if they are
  wanted.

- **#34 — The manual's comparator signatures omit the constraints.**
  `website/docs/user/checks/index.mdx` (the signatures of `eq()` to
  `le()` and `approx()`) show no `requires` clauses, while the header
  requires `extension::printable` on both operands, the comparability,
  and `extension::approx_operand` for `approx()`. (`website-review`.)

  Fixed in `f6714bc5`: the page says that the operands that cannot be compared or written are rejected with a message (#267), and which operands `approx()` rejects.

- **#35 — The manual's description of the diagnostic for a type
  without `operator<<` holds only for Clang.**
  `website/docs/user/extending/index.mdx` lines 70 to 72 say that the
  diagnostic names the type that does not satisfy
  `extension::printable`; GCC names the type only inside `[with Lhs_T
  = app::opaque&]`. (`website-review`.)

  Fixed in `f6714bc5`: the page describes the message of the rejection, not the notes of the concepts.

- **#36 — The manual copies the options that the header advises to
  move.** `website/docs/user/organising-tests/index.mdx` line 67 calls
  `tr.initialise (options)` with an lvalue, while `runner.h` lines 401
  to 403 advise a temporary or `std::move()`. (`website-review`.)

  Fixed in `f6714bc5`: the page keeps the examples that copy the options, and adds the example of the options moved into the runner.

- **#37 — The manual and the header name the `throws()` parameter
  differently.** The manual calls it `expr`; `exceptions.h` lines 96
  to 131 call it `func`. (`website-review`.)

  Fixed in `cb8f6a7a` (#262): the signatures of the page use the parameter name of the header, `func`.

- **#38 — The umbrella header comment lists removed concepts.**
  `include/micro-os-plus/micro-test-plus.h` lines 23 to 26 still name
  "assumptions" and "logical operators", which are deprecated.
  (`doxygen-review`.)

  Fixed in `f6714bc5`: the umbrella comment names the requirements, the function comparators, and the logical functions.

- **#39 — Public concept comments are explained by internal or
  deprecated entities.** The comments of `extension::is_op` refer to
  `detail::op` and `detail::value_base`, that of `extension::any_op`
  to the deprecated `operators` namespace, and the file comment of
  `extension.h` to the value wrappers and their tolerance.
  (`doxygen-review`.)

  Fixed in `f6714bc5`: the comments no longer rely on the deprecated value wrappers and tolerance, and `any_op` says that the framework uses it for the deprecated operators.

- **#40 — Two headers with public functions are described as
  internal.** The file comments of `function-comparators.h` and
  `expression-formatter.h` say they are "intended solely for internal
  use", although they hold the only declarations of `eq()` to
  `any_of()` and of `expression_formatter`. (`doxygen-review`.)

  Fixed in `f6714bc5`: the sentence was replaced in all the 22 files that had it, by one that is true for every header (included by the umbrella header, or by the header of the same name).

- **#41 — An example sets a default value.** `runner.h` lines 382 to
  384: the example of `initialise (runner_options)` sets
  `reporter_kind::tap`, which is already the default; set
  `reporter_kind::human`, which shows an effect. (`doxygen-review`.)

  Fixed in `f6714bc5`: the example of `initialise (runner_options)` sets the human-readable reporter.

## 9. Reviewed and found sound

- The session state machine: `initialise()` called twice, after the
  start, or not at all; `add_top_suite()` called twice; `run_suites()`
  called twice (it returns the same exit code); suites added after the
  start are rejected with an error and exit code 1.
- The static initialisation order: the `constinit` head of the static
  suites, independent of the runner, so that the suites may be
  constructed before it; the suites of another runner are skipped.
- The totals of the nested test cases: the checks of a nested test
  case reach the suite once, the parent test case fails when a child
  fails, and the session totals match the report (`p13`, `p20`).
- The exceptions: an exception from a test case body or a suite body
  is reported and the run continues; a failed `require()` stops only
  its test case; `throws()` and `nothrow()` let a failed requirement
  propagate. Without exceptions, a failed `require()` aborts the run,
  and the report says so (`✗ ... - test execution aborted`, `p11`);
  the difference is unavoidable without unwinding, and it is visible.
- The TAP output, on the console and in the file, at the normal,
  verbose, quiet, and silent verbosities, with and without filters,
  with skipped and nested test cases and with exceptions, is valid TAP
  14 (`p8`, `p20`); `#` and `\` are escaped in the descriptions, the
  newlines are replaced, the names with control characters are
  escaped, and the YAML conditions are double-quoted.
- The configuration errors, `--list-tests`, and the filter that
  selects nothing reach the output file and set exit code 2 (`p5`).
- The formatting of the fundamental types and of the special values:
  NaN, the infinities, `-0.0`, the largest `long double`, `'\0'`, an
  embedded null character, a null C string, `std::chrono` durations,
  the minimum `int8_t`, and the maximum `uint64_t` against `-1`, all
  with the type suffixes (`p7`); `__int128` is rejected cleanly as not
  printable.
- The mixed-sign integer comparisons, through `std::cmp_*`, and the
  integer path of `approx()`, which cannot overflow.
- Copy and move: every registered object (`runner`, the suites, the
  test cases, `check_result`, the reporters, the formatter, the
  stopwatch) is neither copyable nor movable; `counters` and
  `runner_options` are copyable.
- The shared formatter: the owner and pending mechanism keeps the text
  of each check when checks are nested in lazy messages.
- `expect()` and `require()` with a value that is neither a condition
  nor a comparison: one clear `static_assert`, 21 (GCC) or 22 (Clang)
  lines, in the user's terms.
- The `extension` namespace: the newcomer wrote a comparator and a
  predicate from the manual alone, and they report as the built-in
  ones (`{3, 1, 2} contains 7`, `not sorted {1, 2}`).
- `set_abort_handler()` returns the previous handler, as
  `std::set_terminate()` does; this deviation from the rule that the
  setters return `void` is justified.
- Header self-containment (18 headers), the header guards, the
  formatting, and the build integration (every `src/*.cpp` is in
  `xcdl-package.jsonc`, the generated `CMakeLists.txt`, and
  `meson.build`).
- The stack frames of the library on Cortex-M4 are at most 336 bytes
  (`reporter_tap::end_suite()`), with no `-Wframe-larger-than=512`
  warning, and the library builds without exceptions and without RTTI.
