# API reference review

Date: 2026-10-12, on branch `xpack-development`, commit `00a0f8c4`.

Scope: the API reference pages under `website/docs/api/` (172 generated
files: topics, namespaces, classes, structs, concepts, files, folders,
indices, and the deprecated list), and everything they are generated
from:

- the Doxygen comments in `include/` (with `inlines/`) and `src/`;
- the hand-written Doxygen sources in `website/doxygen/`: `topics.h`,
  `pages/mainpage.dox`, `files/topics-h.dox`, `folders/*.dox`,
  `macros/*.dox`, `topics/*.dox`, and `topics/cpp-api/*.dox`;
- the generated `website/doxygen/top-common.h`;
- the configuration: `website/doxygen/config.doxyfile`,
  `common-config.doxyfile`, and `original-config.doxyfile`;
- the API navigation: `website/sidebar-category-doxygen.json` and
  `website/docusaurus-config-navbar-doxygen.json`.

The rest of the website is reviewed separately
(`maintenance/docs/WEBSITE-REVIEW.md`).

Method: every topic source and every public, internal, and inline header
was read in full, together with the `src/*.cpp` definitions, and each
statement was checked against the code. The generated pages were read
for structure and rendering (group, namespace, class, index, and
deprecated pages). The site was built (`docusaurus build`, no broken
links reported). The automatic checks of the `doxygen-review` skill were
run: Doxygen with strict settings reports no warnings; the merged check
reports 6 entities without details; the style check reports 3 long
lines. Claims about behaviour were verified with small probe programs
compiled with Apple clang 17 against the headers (`-std=c++20`), and the
sample outputs were compared with `tests/assets/tap/` and
`tests/assets/txt/`.

Summary: 89 problems (89 open, 0 fixed, 0 withdrawn).

The most serious problems are those a reader acting on the reference
would trip over:

- examples that do not compile or do not link as written (#3, #4, #6,
  #31);
- an empty Configuration page for the one macro without which nothing
  compiles (#2);
- wrong behavioural statements: failed assumptions terminate the whole
  process (#8), container comparisons neither iterate elements nor show
  operand values (#11, #12), `"false"_b` is true (#14);
- undocumented traps: floating-point literals compare with a tolerance
  derived from their decimals (#32), `eq()` on C strings compares
  addresses (#33);
- the pages lag behind the sources (#1).

Suggested order of work: regenerate the pages (#1); fix the defects in
the topic sources and comments (#2 to #31); add the missing information
(#32 to #40); decide on the restructuring of the topic tree (#76
to #83) and the presentation options (#41 to #47); then the language
items (#68 to #75). The API design items (#48 to #55) are decisions for
the maintainer, most of them breaking changes, and best scheduled for a
major release.

## Note on generated pages

All files under `website/docs/api/` carry "DO NOT EDIT! Automatically
generated via doxygen2docusaurus by Doxygen" and are regenerated with
`npm run generate-website-doxygen` in `website/`. Every finding below
therefore names the source to change, marked as:

- **[topic]**: a hand-written source in `website/doxygen/` (topics,
  pages, folders, macros, `topics.h`);
- **[header]**: a Doxygen comment in `include/` or `src/` (the
  `doxygen-review` skill applies);
- **[config]**: a Doxygen configuration file in `website/doxygen/`;
- **[template]**: `website/doxygen/top-common.h`, generated from
  `docusaurus-template-liquid/templates/docusaurus` (shared with the
  other µOS++ sites);
- **[converter]**: the `@xpack/doxygen2docusaurus` package (shared with
  the other µOS++ and xPack sites);
- **[code]**: a change to the library code or API.

## 1. Defects

- **#1 — The generated pages are older than the sources.** [topic,
  header] `website/docs/api/` was last regenerated in commit `6af9731d`;
  commit `00a0f8c4` (#32) then added the public `expression_formatter`
  alias and its documentation (how to report user-defined types) to
  `include/micro-os-plus/micro-test-plus/expression-formatter.h`. No
  generated page contains it (`grep "Public name of the formatter"`
  finds nothing). Regenerate with `npm run generate-website-doxygen`,
  and regenerate after every change to the comments or topics.

- **#2 — The enabling macro has a placeholder description.** [topic]
  `website/doxygen/macros/micro-os-plus-micro-test-plus-enabled.dox`
  line 5: the details are `...`. Without this macro,
  `micro-test-plus.h` (line 87) expands to nothing and every test fails
  to compile with unrelated errors; the page also shows "Definition at
  line 80 of file micro-test-plus.h", which suggests that the library
  defines it, while that definition exists only under `__DOXYGEN__`.
  Suggested text:

  ```text
  @details
  Must be defined by the application, otherwise the µTest++ headers
  declare nothing. Define it in `micro-os-plus/micro-test-plus-defines.h`
  or `micro-os-plus/project-config.h` (both are included, if present,
  by `micro-test-plus.h`), or on the compiler command line.

  The definition shown below exists only for the documentation.
  ```

  The two trace macros need the same note, and their condition is the
  application defining them, not "when MICRO_OS_PLUS_DIAG_TRACE_ENABLED
  is present" (the trace calls are compiled in whenever the µTest++
  macro is defined; `MICRO_OS_PLUS_DIAG_TRACE_ENABLED` only decides
  whether the trace output goes anywhere).

- **#3 — `42_f` does not compile.** [topic]
  `website/doxygen/topics/cpp-api/literals.dox` lines 5 and 27 use
  `42_f`. The floating-point literal operators require a decimal point:
  `include/micro-os-plus/micro-test-plus/inlines/math-inlines.h` line
  208 fails a static assertion ("den(): no decimal point in literal").
  Use `42.0_f`, and state the requirement (see #39).

- **#4 — The Test Suites example does not link.** [topic]
  `website/doxygen/topics/cpp-api/test-suites.dox` line 36 declares
  `static mt::static_runner tr{ "Sample" };` in `main.cpp` and line 51
  uses `tr` "in a separate source file". `static` gives the runner
  internal linkage, so the other file cannot refer to it. The test
  projects do it correctly: `mt::static_runner sr;` in
  `tests/sources/suite/src/main.cpp` and `extern ... static_runner sr;`
  in `tests/sources/suite/include/suite.h` line 28. Show the definition
  without `static`, and the `extern` declaration in a shared header.

- **#5 — An example uses the deprecated constructor.** [topic]
  `test-suites.dox` line 36 passes the suite name to the `static_runner`
  constructor, deprecated since 4.1.0 ("Use the anonymous constructor",
  `include/micro-os-plus/micro-test-plus/runner.h`). Use
  `mt::static_runner tr;` and pass the name to `initialise()`.

- **#6 — The Test Suites example says a plain runner also works.**
  [topic] `test-suites.dox` line 35: "create the runner (the
  static_runner variant also works)". The example needs a
  `static_runner`: the `static_suite` constructor takes a
  `static_runner&` (`test.h`, `static_suite::static_suite`), so with an
  `mt::runner` it does not compile. Replace the comment with "A
  `static_runner` is required by the `static_suite` objects."

- **#7 — The top suite is described as created and executed by
  `initialise()`.** [topic] `test-suites.dox` lines 5 to 7: "the
  top-level test suite, which is created by `runner::initialise()` and
  executed immediately". The top suite is a member of the runner,
  created by its constructor (`runner.h`, `top_suite_`);
  `initialise()` names it, starts its timing, and returns it; its test
  cases run one by one as `test()` is called; `exit_code()` closes it.
  Suggested text: "Test cases added to the suite returned by
  `runner::initialise()` belong to the top suite, and each runs as soon
  as `test()` is called."

- **#8 — A failed assumption terminates the process, not the test.**
  [topic, header]
  `website/doxygen/topics/cpp-api/assumptions.dox` line 6: "the test is
  terminated immediately". The deferred reporter destructor
  (`src/deferred-reporter.cpp`, `~deferred_reporter_base`) flushes the
  output and calls `runner::abort()`, which prints the location and
  calls `::abort()` (`src/runner.cpp`). No further test case or suite
  runs, no summary is printed, and the exit status is that of
  `SIGABRT`, not the value of `exit_code()`. It also happens at the end
  of the statement (after the message is appended), not immediately.
  The same wording needs correcting in the `subtest::assume()` brief
  ("abort test execution", `test.h`), the `runner::abort()` brief
  ("Aborts test execution immediately"), and the `abort_` member of
  `deferred_reporter_base` ("terminates the test execution"). Suggested
  topic text: "If an assumption fails, the failure is reported and the
  test program is terminated, with `abort()`, at the end of the
  statement; the remaining test cases and suites are not run, and no
  summary is displayed."

- **#9 — `expect()` and `assume()` are said to return an output
  stream.** [header] `include/micro-os-plus/micro-test-plus/test.h`,
  `subtest::expect()` and `subtest::assume()`, `@return An output
  stream to write optional messages.` They return a temporary
  `detail::deferred_reporter`, whose `operator<<` accepts only
  arithmetic values and values convertible to `std::string_view`
  (`type_traits::printable`), and which reports the check when it is
  destroyed, at the end of the statement. Suggested text: "A temporary
  object to which a message can be appended with `<<`; the check is
  reported when it is destroyed, at the end of the statement."

- **#10 — The sample failure output of the Function Comparators topic
  is obsolete.** [topic]
  `website/doxygen/topics/cpp-api/function-comparators.dox` lines 35 to
  42. The file name (`unit-test.cpp`, now `comparisons.cpp`), the line
  numbers, and the number format (`42.000000`, now `42f` or `42`) do
  not match the current output, and the second line has lost its
  expression. Replace it with lines from
  `tests/assets/txt/unit-test.txt`, e.g. lines 296, 303, and 409:

  ```text
  ✗ actual != 42 FAILED (comparisons.cpp:115, 42 != 42)
  ✗ 42 != 42_i FAILED (comparisons.cpp:142, 42 != 42)
  ✗ (actual == 42) and (actual != 42.0) FAILED (comparisons.cpp:611,
  (42 == 42 and 42f != 42))
  ```

- **#11 — Containers are not compared element by element.** [topic]
  `function-comparators.dox` lines 13 to 15 ("each element is assessed
  individually, and the results are reported in detail") and lines 46
  to 48 ("Comparison is performed by iterating through each element and
  evaluating it individually"). `detail::eq_` and `detail::ne_` call
  the container's own `operator==`/`operator!=`
  (`inlines/detail-inlines.h` line 245); only the failure message
  iterates the elements, to print them as `{ 1, 2, 3 }`
  (`expression_formatter`, container `operator<<`). Suggested text:
  "Containers are compared with their own equality operators; when the
  check fails, both containers are displayed, element by element."

- **#12 — The container operators are not used for standard
  containers.** [topic]
  `website/doxygen/topics/cpp-api/container-operators.dox`. With
  `using namespace mt::operators;`, the expression
  `std::vector<int>{ 1, 2 } == std::vector<int>{ 1, 2 }` selects the
  standard `operator==` (a more specialised template than the
  framework's `operator==(const Lhs_T&, const Rhs_T&)`) and yields a
  plain `bool`; a probe confirms the same for `std::string`. The
  example therefore works, but a failure shows no operand values, which
  is the purpose of the topic. Recommend `mt::eq()`/`mt::ne()` for
  containers, or fix the operators (see #53).

- **#13 — The operator constraint names a namespace that does not
  exist.** [topic] `website/doxygen/topics/cpp-api/operators.dox` lines
  15 and 16: "operands derived from the local `detail::op` type". The
  base is `type_traits::op` (`type-traits.h`); the constraint is
  `type_traits::any_op`. Write "operands of a framework type, i.e.
  derived from `type_traits::op` (the literals and the `to_*`
  wrappers)".

- **#14 — The `_b` literal does not convert to `bool`.** [header]
  `include/micro-os-plus/micro-test-plus/literals.h`, `operator""_b`,
  brief "User-defined literal operator to convert to `bool`". The
  literal returns a named object that always converts to `true`
  (`inlines/literals-inlines.h`); `"false"_b` is `true` (probe), and
  `"name"_b == x` returns `x` as a plain `bool`, so the name never
  reaches the report. Describe what it does ("Creates a named value
  that is always `true`; comparing it with a `bool` yields that
  `bool`"), or deprecate it (see #54).

- **#15 — Wrong path to the CLI example source.** [topic]
  `website/doxygen/topics/cli.dox` lines 58 and 59:
  `tests/sources/minimal-test/src/main.cpp`. The file is
  `tests/sources/minimal/src/main.cpp`.

- **#16 — The CLI sample outputs do not match the program they cite.**
  [topic] `cli.dox` lines 13 to 28, 68 to 85, and 94 to 101 show a top
  suite named `Minimal`, but `tests/sources/minimal/src/main.cpp` calls
  `initialise (argc, argv)` without a name, so the suite is named after
  the executable, `minimal-test`
  (`tests/assets/tap/minimal-test.tap`). The samples also omit the
  `# Running: ...` and `# Built with ...` lines that the normal and
  verbose modes print (`src/reporter.cpp`, `write_info_()`). Either
  show the exact output, or say that the samples are abridged.

- **#17 — Contradictory advice about the human reporter.** [topic]
  `cli.dox` lines 34 and 35: "the proprietary format implemented by the
  initial releases will also be retained, but it is not recommended for
  new projects", while `pages/mainpage.dox` line 16 says "A
  human-readable reporter is also available for interactive use". The
  human reporter is current and maintained (renamed in commit
  `c8671880`, #20). Decide which statement holds; if the human reporter
  is supported, replace lines 34 and 35 with "The human-readable
  reporter is intended for interactive use; the TAP reporter is
  intended for automated processing."

- **#18 — The Test Runners sample output is the verbose form.** [topic]
  `website/doxygen/topics/cpp-api/inits.dox` lines 35 to 46 present as
  "the output" a listing with `ok 1 - true`, which the console shows
  only with `--verbose` (with the default verbosity, the passed checks
  of a successful test case are not shown, and its plan counts only the
  nested subtests, here `1..0`; `src/reporter-tap.cpp`,
  `end_subtest()`). It also omits the
  blank lines that the CLI samples show. Add "with `--verbose`", or
  show the default output.

- **#19 — The explicit exception check records nothing when no
  exception is thrown.** [topic]
  `website/doxygen/topics/cpp-api/exceptions.dox` lines 35 to 54. If
  `compute_answer()` returns normally, no `expect()` is executed, so
  the test case passes with zero checks. Add
  `t.expect (false) << "no exception thrown";` after the call inside
  the `try` block. The unused `e` names in the `catch` clauses can be
  dropped, and a function that can throw is a better illustration than
  `compute_answer()`.

- **#20 — A backslash renders as `\\endiskip`.** [header]
  `include/micro-os-plus/micro-test-plus/utility.h`,
  `extract_file_name()`, `@return ... (`/` or `\`)`, and the details in
  `src/utility.cpp`; the page shows "(/ or \\endiskip)". Doxygen reads
  `` \` `` as a command. Write "a slash or a backslash".

- **#21 — `detail::assertion` describes an evaluator that does not
  exist.** [header] `include/micro-os-plus/micro-test-plus/detail.h`,
  struct `assertion`: "Assertion struct template for parameter passing
  to the evaluator ... through the evaluation pipeline". Nothing in
  `include/` or `src/` uses the struct, and there is no evaluator. It
  is a leftover of the Boost UT design; remove it (code), or say that it
  is unused.

- **#22 — The function traits are not used by the framework.** [header]
  `include/micro-os-plus/micro-test-plus/type-traits.h`,
  `function_traits` ("This mechanism allows the µTest++ framework to
  deduce argument types ... flexible test case registration"), and
  likewise `list` and `identity`. None of them is used in `include/` or
  `src/`; only `tests/sources/unit/src/static-asserts.cpp` exercises
  them. Correct the text, or remove the templates (decision, see #52).

- **#23 — The folder page places the main header in the wrong
  folder.** [topic]
  `website/doxygen/folders/include-micro-os-plus-micro-test-plus.dox`
  line 5: "This folder provides the primary public header". The primary
  header, `micro-test-plus.h`, is in `include/micro-os-plus/`; this
  folder contains the internal headers, which the headers themselves
  say "should not be included directly by user code". Line 20 also
  lacks a noun ("include only the top
  `micro-os-plus/micro-test-plus.h`" → "include only the
  `micro-os-plus/micro-test-plus.h` header").

- **#24 — The `topics.h` description is wrong in two places.** [topic]
  `website/doxygen/files/topics-h.dox` lines 24 to 27. The topics and
  groups are not "maintained in this file"; `topics.h` only includes
  `topics/*.dox`, `macros/*.dox`, `folders/*.dox`, and
  `pages/mainpage.dox`. And `topics.h` is in `website/doxygen/`, not in
  `website/doxygen/files/` (that folder holds this `.dox` file).

- **#25 — Nested subtests are said to be owned by the suite.** [header]
  `test.h`: the `subtest` class details say the result is registered
  "with the parent node", and the constructor documents `parent_suite`
  as "The suite that owns this subtest". A nested subtest is owned by
  the subtest that created it (`children_subtests_`, filled by
  `after_subtest_create_()`, `src/test.cpp`); `parent_suite` is the
  suite whose totals receive its checks. The parent subtest only counts
  it as an executed subtest.

- **#26 — The output file is not always the full report.** [header]
  `include/micro-os-plus/micro-test-plus/reporter.h`, `verbosity`:
  "It affects only the console output; the optional output file always
  receives the full report." True for the TAP reporter; the human
  reporter filters the file by verbosity (`src/reporter-human.cpp`
  lines 264, 322, and 470), e.g. `tests/assets/txt/minimal-test-quiet.txt`
  contains no checks. Either correct the text or the human reporter
  (see #85).

- **#27 — The deprecation notes of the runner constructors.** [header]
  `runner.h`, `runner (const char*)` and `static_runner (const char*)`:
  "Use the anonymous constructor." The term is "default constructor",
  and, unlike the other deprecations ("since 3.2.0"), the version is
  missing: they were deprecated in 4.1.0 (commit `9239ecac`, #31).
  Suggested text: "Use the default constructor and pass the name to
  `initialise()` (since 4.1.0)."

- **#28 — "Locale-independent" number formatting is not always
  locale-independent.** [header] `detail.h`, `append_number_()`, brief
  "using locale-independent formatting". For `long double` on x86-64,
  AArch64, and RISC-V, the definition (`inlines/detail-inlines.h`) uses
  `snprintf ("%Lg")`, which honours the C locale. Qualify the claim.

- **#29 — A stray `</b>` in the API home page.** [converter]
  `website/docs/api/index.md`, the note "the original Doxygen html
  pages continue to be available via the
  `<a ...>.../doxygen/*.html</b></a>` URLs" has a closing `</b>`
  without an opening tag. Fix the template in `doxygen2docusaurus`.

- **#30 — The µTest++ topic names the wrong classes.** [topic]
  `website/doxygen/topics/micro-test-plus.dox` lines 10 to 12: the API
  "is centred on the `runner` and `subtest` classes, which provide
  methods for registering tests, evaluating expectations and
  assumptions". Test cases are registered with `suite::test()` (and
  `subtest::test()`), suites with `runner::suite()` or `static_suite`;
  `subtest` provides `expect()` and `assume()`. Name `runner`, `suite`,
  and `subtest`, each with its role.

- **#31 — Several examples do not compile as written.** [topic, header]
  `topics/cpp-api/operators.dox` lines 28, 29, 50, and 51, and
  `topics/cpp-api/literals.dox` lines 23 and 24 use
  `using namespace micro_test_plus::operators;`, which compiles only
  inside `namespace micro_os_plus`; the other examples use the `mt`
  alias. `literals.dox` lines 26 and 27 use undeclared names (`answer`,
  `expression`). The `expression_formatter` example in
  `expression-formatter.h` uses `mt::` inside `namespace app` without
  declaring the alias. Use `mt::operators` and `mt::literals`
  throughout, and either declare every name or use the helper functions
  of the other examples (`compute_answer()`).

## 2. Missing information

- **#32 — The floating-point tolerance is not documented.** [topic,
  header] Comparisons with `_f`, `_d`, and `_ld` literals use a
  tolerance of one unit in the last decimal of the literal
  (`type_traits::floating_point_constant::epsilon`): `42.0_f` has a
  tolerance of 0.1, so `42.05f == 42.0_f` is true (probe). The `to_f`,
  `to_d`, and `to_ld` wrappers compute their own tolerance from the
  decimals of the run-time value (up to seven), and when both operands
  have one, the smaller applies (`detail::eq_`), so
  `mt::to_f{ 42.05f } == 42.0_f` is false. Plain floating-point
  operands are compared exactly. Add a paragraph to `literals.dox` and
  `operators.dox`, and a `@note` to the `_f`, `_d`, and `_ld` literal
  operators and to `type_traits::value<T>` for floating-point types.

- **#33 — `eq()` on C strings compares addresses.** [topic, header]
  The pointer overloads of `eq`, `ne`, `lt`, `le`, `gt`, and `ge`
  (`function-comparators.h`) compare pointers; `mt::eq (buf1, buf2)`
  with two arrays holding `"abc"`, or with two `const char*`, is false
  (probe). This is a likely mistake in tests of C code. Add a
  `@warning` to the pointer overloads, and a sentence to
  `function-comparators.dox`: "To compare C strings, wrap one operand in
  `std::string_view`."

- **#34 — The logical functions and operators always evaluate both
  operands.** [topic, header] `detail::and_` and `detail::or_` receive
  both operands already evaluated (`inlines/detail-inlines.h`); the
  overloaded `&&` and `||` (`operators.h`) therefore lose
  short-circuiting, so `mt::to_i{ n } != 0 && 10 / n > 1` divides by
  zero when `n` is 0. Add a `@note` to `both()`, `either()`, and the
  operators, and a sentence to `logical-functions.dox` and
  `operators.dox`.

- **#35 — The exception checks depend on exception support.** [topic]
  `exceptions.dox` does not say that `throws()` and `nothrow()` exist
  only when exceptions are enabled (`exceptions.h` is compiled under
  `__cpp_exceptions`); embedded projects often build with
  `-fno-exceptions`, and the tests have `-noexcept` variants for this
  reason. Add: "Available only when the compiler supports exceptions
  (not with `-fno-exceptions`)."

- **#36 — The command line options are incompletely documented.**
  [topic] `cli.dox` does not mention:
  - `--output-file=<path>` and `--output-file <path>`, which write a
    copy of the report, without colours, to a file
    (`src/reporter.cpp`, constructor);
  - the two-token form `--reporter <name>` (`src/runner.cpp`,
    `initialise()`);
  - that an unknown reporter name, or a missing option argument,
    terminates the program with exit code 1;
  - that unrecognised arguments (e.g. `one two` in the samples) are
    ignored and left to the application;
  - the effect of the verbosity on the output file (see #26).

  The group brief, "Options for controlling test output verbosity at
  run-time", should also cover the reporter and the output file:
  "Options for selecting the reporter, the verbosity, and the output
  file."

- **#37 — The Test Suites topic omits the dynamic suites and the
  execution order.** [topic] `test-suites.dox` documents only
  `static_suite`. `runner::suite()` (suites registered from `main()`,
  owned by the runner) is not mentioned, although it is the variant that
  works with a plain `runner`. The execution order is not stated either:
  the top suite's test cases run as they are added; `exit_code()` then
  runs the suites added with `runner::suite()`, sorted by name, then
  the static suites, sorted by name (`src/runner.cpp`, `run_suites_()`).
  Sorting by name also means that the order is deterministic, which the
  topic contradicts ("they can be executed in any order", line 22).

- **#38 — The Expectations topic does not explain the messages.**
  [topic] `expectations.dox` does not show `<< "message"`, nor say what
  is displayed: on success, the message, or the expression if there is
  no message; on failure, the message, the location, and, for
  comparators and framework operators only, the expression with its
  operand values; for a plain `bool`, only the location
  (`src/reporter.cpp`, `pass()` and `fail()`). It should also say which
  types the message accepts (#9).

- **#39 — The Literals topic does not list the literals or their
  rules.** [topic] `literals.dox` names only `1_i` and `42_f`. List the
  suffixes (`_i`, `_s`, `_c`, `_sc`, `_l`, `_ll`, `_u`, `_uc`, `_us`,
  `_ul`, `_ull`, `_i8` to `_i64`, `_u8` to `_u64`, `_f`, `_d`, `_ld`,
  `_b`) and the corresponding `to_*` wrappers, and state that the
  floating-point literals need a decimal point (#3) and that `_c` takes
  a number (`65_c`), not a character literal.

- **#40 — The reporting of user-defined types is not reachable from
  the topics.** [topic] The only documentation (#32 of the issue
  tracker, commit `00a0f8c4`) is on the `expression_formatter` alias,
  in the Function Comparators group; the Operators, Literals, and
  Expectations topics do not mention that comparing user-defined types
  with `eq()` requires an `operator<<` for the formatter. See #81.

## 3. Structure and presentation

- **#41 — The topics are four levels deep, and collapsed.** [template,
  converter, topic] The reader goes from the API home page to "µOS++
  Topics" (defined by the generated `top-common.h`), to "µTest++", to
  "C++ API", before reaching any content; in
  `sidebar-category-doxygen.json` the three intermediate categories are
  `"collapsed": true`, and the first two contain no information about
  µTest++. Make the µTest++ topics the first level of the API sidebar
  (see #83).

- **#42 — Internal entities dominate the indices.** [config, header]
  The Classes index lists about 40 entries, of which only nine are
  meant for users (`runner`, `static_runner`, `suite`, `static_suite`,
  `subtest`, `to_t`, and the three reporters); the rest are `detail`,
  `type_traits`, and `reflection` internals, listed first. The
  Namespaces index presents `detail`, `math`, `type_traits`, and
  `reflection` beside the user namespaces, and the Files index lists
  every `inlines/` header and `src/` file. Options, for the maintainer:
  (a) keep everything but add a sentence at the top of each index
  saying which entities are public; (b) exclude `detail` from the
  generated reference (`EXCLUDE_SYMBOLS`), at the cost of dangling
  types in public signatures (see #48); (c) produce two references, a
  user reference and a full one.

- **#43 — The pages are very large and carry spurious
  cross-references.** [config] `INLINE_SOURCES = YES`,
  `REFERENCES_RELATION = YES`, and `REFERENCED_BY_RELATION = YES`
  (`common-config.doxyfile`) inline the source of every member and its
  references: `reporter_tap` is 367 KB, `reporter_human` 359 KB, the
  Literals topic 244 KB, and all API pages together 3.1 MB. Some
  references are wrong, e.g. `expect()` is "Referenced by
  `subtest::operator=`". Set the three options to `NO` for the
  Docusaurus output (`SOURCE_BROWSER` keeps the source links).

- **#44 — Documentation-only files are published as library files.**
  [config, topic] `top-common.h` and `topics.h` appear in the Files
  index and have their own pages (`files/top-common-h`,
  `files/topics-h`), next to the real headers, although they are not
  part of the package. Exclude their file pages (e.g. with `@cond`
  around the file documentation, or by moving the content into `.dox`
  files listed in `INPUT`). Note that `topics-h.dox` says the content
  "cannot be provided as a Markdown file or as a `.doxyfile`"; Doxygen
  reads `.dox` files as input (`FILE_PATTERNS` includes `*.dox`), so
  the claim should be checked.

- **#45 — Deleted and deprecated members lead the class indices.**
  [header] On the `runner` page, the deprecated `runner (const char*)`
  is the first constructor listed, followed by the deleted copy and
  move constructors; the same applies to every class. Group the special
  members with `@name` (e.g. "Construction" and "Non-copyable"), so
  that the members a user calls come first.

- **#46 — The constructor of `_t` is listed as a Literals function.**
  [header] The Literals topic's "Functions Index" contains only
  `_t (const T& t)`, the constructor of the deprecated struct, because
  `literals.h` opens `@addtogroup micro-os-plus-micro-test-plus-literals
  @{` before the deprecated aliases and closes it with `@}` only after
  `to_ld`, so `_t` and its constructor fall inside the block. Move `_t`
  after the closing `@}` and give it its own `@ingroup`, as `to_t`
  already has.

- **#47 — An `@important` block renders as a tip.** [converter]
  `test-suites.dox` line 16 uses `@important`; the page shows a
  `:::tip` admonition. Map `@important` to `:::important` (or
  `:::warning`) in `doxygen2docusaurus`.

## 4. API design

These items are decisions for the maintainer; most are breaking changes.

- **#48 — Public signatures expose `detail` types.** [code]
  `runner::timings()` and `suite::timings()` return
  `detail::timestamps&`; `test_node::totals()` (inherited by every
  public class) returns `detail::runner_totals&`;
  `reporter::expression()` returns `detail::expression_formatter&`;
  the public classes derive from `detail::test_node` and
  `detail::runnable<>`; and the customisation point added in #32 is an
  alias of a `detail` class. The `detail` namespace is documented as
  "may be modified without prior notice", which conflicts with its
  presence in the public API. Either promote these types to the public
  namespace (`timestamps`, `totals`, `expression_formatter`), or make
  the accessors non-public.

- **#49 — The reporters are public but cannot be extended.** [code]
  `reporter`, `reporter_human`, and `reporter_tap` are in the public
  namespace, with a large public interface (`pass()`, `fail()`,
  `begin_suite()`, `endline()`, `operator<<`), but the runner creates
  only the two built-in reporters, selected by name
  (`src/runner.cpp`), and `reporter_human`'s own documentation admits
  that a new format "requires ... an extension of the runner". Either
  move them to `detail`, or add a way to register a reporter (e.g. a
  factory passed to `initialise()`).

- **#50 — Member functions named after classes.** [code]
  `runner::suite()`, `runner::reporter()`, `runnable_base::reporter()`,
  and `runnable_base::runner()` hide the class names inside the
  classes, so the signatures need elaborated type specifiers, and the
  pages show them (`class suite& initialise (...)`,
  `class reporter& reporter (void)`). Consider `add_suite()`,
  `get_reporter()`, `get_runner()`, or similar. As decided,
  `runner::suite()` keeps its short name, and
  `runnable_base::runner()` is renamed `test_runner()` and made
  protected (see API-REVIEW #32).

- **#51 — Three implementations of "file name of a path".** [code]
  `reflection::short_name()` (only `/`), `utility::extract_file_name()`
  (`/` and `\`), and an inline `rfind ('/')` in
  `reporter::write_info_()`. On Windows, the failure locations
  (`reporter-human.cpp` line 646, `reporter-tap.cpp` line 656) and the
  abort message keep the full path. Keep one function, handling both
  separators.

- **#52 — Internal helpers in public namespaces.** [code]
  `indent_size`, `indent()`, and `endl()` (reporter internals), and
  `mut()` (a `const_cast` helper, unused by the framework and the
  tests) are in `micro_test_plus`; `math`, `reflection`, and
  `type_traits` are public namespaces with internal content, including
  unused templates (#21, #22). Move them to `detail`, or document which
  of them users may rely on.

- **#53 — The container and string operators.** [code] The container
  operators are never selected for same-type standard containers (#12)
  and fail to compile, deep in `detail-inlines.h`, for mixed container
  types (#84); the string operators are useful only when both operands
  are `std::string_view`. Either remove them and recommend
  `mt::eq()`/`mt::ne()`, or make them effective (e.g. by requiring
  one operand to be wrapped, as for the other operators).

- **#54 — Deprecated and doubtful entities still in the API.** [code]
  The 23 `_x` wrappers and `_t` have been deprecated since 3.2.0 and
  double the size of the Literals topic; the `_b` literal (#14) has no
  useful effect. Remove them in the next major release, or move them
  to a separate "Deprecated" topic (see #82).

- **#55 — `static_suite` requires `static_runner`.** [code] Suites
  defined in other files need a `static_runner`, while suites added
  from `main()` work with any runner; the asymmetry is the reason for
  #6. A `static_suite` could register with a registry independent of
  the runner type (see also #87), so that a single `runner` class
  suffices.

## 5. Consistency

| # | Concept | Variants found (where) | Suggested |
| --- | --- | --- | --- |
| #56 | A test case | "Test Cases" (topic), class `subtest`, `suite::test()`, "test", "subtest", "test runnable" (`runnable_base` briefs) | "test case" in text; explain once that the class is `subtest` |
| #57 | One check | "check", "expectation", "assertion" (`operators.h`, `detail.h`), "condition" (`reporter::pass()`) | "check"; "expectation" and "assumption" for the two kinds |
| #58 | Command line | "Command Line Options" (`cli.dox` title), "command-line options" (`cli.dox`, `reporter.h`) | "command line" as a noun, "command-line" as an adjective; title "Command-line options" |
| #59 | Run time | "run-time" (`cli.dox` brief, `literals.dox`), "run time" (`micro-test-plus.dox`), "runtime" (`type-traits.h`) | "run time" (noun), "run-time" (adjective) |
| #60 | Floating point | "floating point" (`type-traits.h`), "floating-point" (`literals.dox`, `type-traits.h`) | "floating-point" as an adjective |
| #61 | Topic titles | Title Case ("Command Line Options", "Literals and Wrappers", "Checking Exceptions"), while the website uses sentence case | sentence case |
| #62 | Example headings | `@par Example`, `@par Examples`, `**Example**` (`to_t`), `@code` without heading (`to_*` group) | `@par Example` / `@par Examples` |
| #63 | Framework types | "local type", "local `op`", "derived from local `op`" (`operators.h` briefs), "framework type", "`detail::op`" (#13) | "framework type (derived from `type_traits::op`)" |
| #64 | Brief mood | "Check if a callable throws" / "Checks whether all executed checks" / "Evaluate a generic condition" / "Enables" / "Enable trace" (`macros/*.dox`) | third person throughout ("Checks", "Evaluates", "Enables") |
| #65 | List dashes | em dash and hyphen mixed (`folders/src.dox` lines 9 to 21), en dash and hyphen mixed (`cli.dox` lines 41, 42, 50 to 52) | one style (em dash) |
| #66 | Parameter markup | `\p`, `\c` (`math.h`) versus `@p` and backticks elsewhere | `@p` and backticks |
| #67 | Empty parameter lists | `name (void)`, `suites_count (void)` versus `timings ()`, `totals ()`, `own_index ()` in the same classes; all visible in the indices | one form (the project style uses `(void)`) |

## 6. Language and style

- **#68 — Boilerplate sentences repeated in nearly every comment.**
  [header] "ensuring clear separation from user code and minimising the
  risk of naming conflicts" (36 occurrences), "organised within the
  `include/micro-os-plus/micro-test-plus` folder to maintain a
  structured and modular codebase" (most file and namespace comments,
  and the `deferred_reporter` classes), "All members and methods are
  defined within the ... namespace" (class comments). They add length
  to every page without information. Remove them; keep the namespace
  statement only on the namespace pages.

- **#69 — Inflated vocabulary.** [header, topic] Counted in `include/`,
  `src/`, and the topic sources: "seamless(ly)" 27, "advanced" 18,
  "enhance(d/s)" 19, "facilitate(s)" 19, "comprehensive" 9, "robust" 6,
  "professional" 3. Replace with plain words or delete, e.g. "integrate
  seamlessly with the µTest++ comparators" → "can be used with the
  comparators"; "advanced string handling" → "string helpers".

- **#70 — Promotional sentences.** [topic, template] Sentences that
  evaluate instead of inform, for example:
  - `pages/mainpage.dox` line 22: "By adopting µTest++, you can achieve
    robust and maintainable code ... across your entire project.";
  - `topics/c-api.dox` lines 12 to 14: "This approach enables
    comprehensive testing ... supporting professional software quality
    assurance.";
  - `topics/cli.dox` lines 54 to 56: "demonstrating how µTest++ adapts
    its reporting to support professional and efficient testing
    workflows across all files and folders";
  - `topics/cpp-api/test-suites.dox` line 28: "guaranteeing
    comprehensive test coverage across the project";
  - `folders/include-micro-os-plus-micro-test-plus-inlines.dox`
    lines 14 and 15 and the `utility` namespace ("The implementations
    are efficient"), which are unverified claims;
  - `top-common.h`: "By adopting µOS++, developers benefit from a
    robust, scalable, and well-documented foundation" [template].

  Delete them.

- **#71 — Lines longer than 80 characters in the topic sources.**
  [topic] `cli.dox` lines 9 (196), 27, 32, 46 (122), 54 (194), 56
  (200), 84, and 100; `cpp-api.dox` lines 5 (285) and 7 (266);
  `cpp-api/function-comparators.dox` line 1; `cpp-api/inits.dox` line
  45 (sample output, acceptable). In the code, the style check reports
  `micro-test-plus.h` line 65, `inlines/detail-inlines.h` line 706,
  and `src/reporter.cpp` line 381.

- **#72 — Two-sentence briefs.** [header] The operator briefs in
  `operators.h` ("Equality operator for custom types. Matches only if
  at least one operand is of local type.") put the constraint in the
  one-line summary of the indices. Keep the first sentence in `@brief`
  and move the second to `@details`; "for custom types" is also
  misleading, since the operands are framework types (#63).

- **#73 — Repetition and sentences about the text in `cli.dox`.**
  [topic] Lines 9 and 46 say the same thing ("detailed results only
  for failed test cases"); line 54 restates the options; line 56
  describes the examples ("The examples provided illustrate ...").
  Keep one statement of the default, and introduce each example with
  its command only.

- **#74 — Group briefs that do not match the content.** [topic]
  "Utility Functions — Utility functions for advanced string handling
  in tests" contains `mut()`, which is not a string function, and
  `extract_file_name()`, which is an internal helper; "Test Runners —
  Classes for initialising the framework and returning an exit code"
  omits suite registration. Adjust the briefs after #52.

- **#75 — Remaining language points.** [template, header]
  - `top-common.h`: "GitHub organization" (American spelling; but it
    is GitHub's term, so "the micro-os-plus organisation on GitHub" is
    better), and "provide the main interface to the utilities
    functionality", text copied from the µOS++ utilities project
    [template];
  - the merged Doxygen check reports six entities without details:
    the `operator<<` of `reporter_human` (`reporter-human.h` line 179,
    twice), of `reporter_tap` (`reporter-tap.h` line 173, twice), and
    of `reporter` (`reporter.h` lines 258 and 266) [header];
  - `test-suites.dox` lines 52 and 53: the inner lambda parameter `t`
    shadows the outer one (`-Wshadow` warns); rename one [topic];
  - `floating_point_constant` explains a GCC ARM PSABI note "under
    C++17", while the library requires C++20; check whether the
    rationale still applies [header].

## 7. Proposed topic tree

The present tree (`topics.h`) is: Test Runners, Test Cases,
Expectations, Assumptions, Function Comparators, Logical Functions,
Checking Exceptions, Operators, String Operators, Container Operators,
Literals and Wrappers, Utility Functions, Test Suites; then C API,
Configuration, and Command Line Options. Each move below can be
accepted on its own.

- **#76 — Move "Test suites" after "Test runners".** The suites are
  the second level of the hierarchy (runner, suites, test cases), but
  the topic is now last, after the utility functions. Reorder the
  `@include{doc}` lines in `topics.h`.

- **#77 — Merge "Expectations" and "Assumptions" into "Checks".** Each
  group documents a single member function of `subtest`; together they
  can explain the shared mechanism (deferred reporting, messages,
  #38) and the difference (#8) on one page. Keep the two anchors for
  the existing links.

- **#78 — Merge "String operators" and "Container operators" into
  "Operators".** Each has two members and a short example; as sections
  of "Operators" they can share the namespace and constraint
  explanation, and carry the caveat of #12.

- **#79 — Order the comparison topics from simple to advanced.**
  "Checks", "Function comparators", "Logical functions", "Operators",
  "Literals and wrappers", "Checking exceptions", then the new topic of
  #81.

- **#80 — Remove the "C API" group.** The group states that there is
  no C API; move its first paragraph to the µTest++ topic
  (`micro-test-plus.dox`) and delete `topics/c-api.dox`.

- **#81 — Add a "Custom types" topic.** Move the documentation of
  `expression_formatter` (now in the Function Comparators group, on an
  alias) into a topic of its own, explaining how to make user-defined
  types usable with `eq()` and the operators, and link to it from
  "Function comparators" and "Operators" (#40).

- **#82 — Move the deprecated wrappers out of "Literals and
  wrappers".** Put the `_x` aliases and `_t` in a "Deprecated" topic
  (or rely on the generated Deprecated List page), so that the Literals
  page documents only the current API (#54).

- **#83 — Make "µTest++" the root of the API sidebar.** Drop the
  "µOS++ Topics" level for this site (it is defined by the template
  `top-common.h` and is common to all µOS++ sites), and expand the
  µTest++ category by default (#41) [template, converter].

## 8. Incidental observations in the code

- **#84 — Mixed-type container comparisons fail deep in the
  internals.** [code] With `using namespace mt::operators`,
  `std::vector<int>{ 1, 2 } == std::array<int, 2>{ 1, 2 }` selects the
  framework container operator (its constraint, `container_like` on
  both sides, is satisfied) and then fails to compile at
  `inlines/detail-inlines.h` line 245 ("invalid operands to binary
  expression"). Constrain the operator on the comparability of the
  operands, or remove it (#53).

- **#85 — The human reporter filters the output file by verbosity.**
  [code] `src/reporter-human.cpp` lines 264, 322, and 470 put the file
  writes inside the verbosity tests, whereas the TAP reporter writes
  the file unconditionally (`src/reporter-tap.cpp` lines 340 and 491).
  With `--quiet` or `--silent`, the human file contains only the
  headings and the subtest names (`tests/assets/txt/*-quiet.txt`,
  `*-silent.txt`). Check which behaviour is intended (#26).

- **#86 — Stale forward declaration.** [code] `test.h` declares
  `class runner_totals;` in `micro_os_plus::micro_test_plus`, but the
  class is `detail::runner_totals` (`runner-totals.h`); the forward
  declaration names a class that is never defined.

- **#87 — The static suite registration relies on writing to an
  object before its lifetime begins.** [code] A `static_suite`
  constructed before the `static_runner` stores into the runner's
  `static_children_suites_` member before the runner's constructor has
  run (`runner.h`, the member documentation explains the workaround).
  This works because the storage is zero-initialised and the member has
  no initialiser, but it is formally undefined behaviour. A registry
  outside the runner object (e.g. a function-local static, or a
  `constinit` pointer at namespace scope) avoids it.

- **#88 — Template parameters swapped in two formatter overloads.**
  [code] `expression-formatter.h` declares
  `operator<< (const detail::lt_<Rhs_T, Lhs_T>& op)` and the same for
  `le_`, while the documentation (`@tparam Lhs_T Left-hand operand
  type`) and the other overloads use `<Lhs_T, Rhs_T>`. Harmless, but
  confusing on the page.

- **#89 — Doxygen configuration leftovers.** [config]
  `common-config.doxyfile` sets `PROJECT_NUMBER = 5.0.1`, while the
  package is `5.1.0-pre`; `original-config.doxyfile` line 2954 sets
  `DOT_MULTI_TARGETS`, which Doxygen 1.17 reports as obsolete.
  Consider taking the version from `package.json` when generating, and
  run `doxygen -u` on the original configuration.

## 9. Reviewed and found correct

- The site builds without broken links or anchors; the API sidebar and
  the "API Reference" navigation menu point to existing pages.
- Doxygen, with the strict settings of the `doxygen-review` skill,
  reports no warnings; every documented entity has a brief.
- The runner documentation (`runner.h`, `src/runner.cpp`) matches the
  code: reporter selection, default name from `argv[0]` without the
  extension, "default suite" fallback, sorting of the suites by name,
  1-based suite indices, and exit code 0/1 (also 1 when not
  initialised).
- `runnable_base`, `runnable<>`, `suite`, `top_suite`, and
  `static_suite` constructors, `run()` methods, and indexing match the
  code, apart from #25.
- The deferred reporter documentation matches the code (evaluation at
  construction, reporting at destruction, message types), apart from
  #8 and #9.
- The function comparator, logical function, exception check, and
  operator declarations: parameters, return descriptions, and
  constraints match the code, apart from #13, #33, and #34.
- The `type_traits` concepts (`container_like`, `has_npos`,
  `has_value`, `has_epsilon`, `is_op`, `any_op`, `checkable`,
  `printable`), `value_base_`, `integral_constant`, and the
  `floating_point_constant` formulas for `value` and `epsilon`.
- `math::num()`, `den()`, and `den_size()` descriptions, including the
  scaling example (250 and 3 for `1.25`).
- The TAP reporter's verbosity behaviour described in `src/reporter-tap.cpp`
  (summary lines, `1..0` plans in normal and quiet modes), and the
  default and quiet CLI samples in their structure, apart from #16.
- The Deprecated List page: all 26 deprecations (23 wrappers, `_t`,
  and the two runner constructors) are listed, with working links.
