# Website API reference review

Date: 2026-11-05, on branch `xpack-development`, commit `101bb480`; published
version `webpreview` commit `d51bb01c`.

Scope: the whole API reference published on the webpreview site, under
<https://micro-os-plus.github.io/micro-test-plus-xpack-webpreview/docs/api/>
(236 pages, listed by the sitemap), with the sources that produce it. The rest
of the website is in the latest `WEBSITE-REVIEW-<n>.md`, the API design in
`API-REVIEW-10.md`.

Method: all the 236 published pages were downloaded and their text was
extracted. The API home page, the topic tree, the top namespace page, and the
Classes, Namespaces, Concepts, and Files indices were read on the published
pages. The text of the 20 topics was read in full from their sources, with the
published member lists of most of them. The prose of `test_case` and the
descriptions of `suite`, `static_suite`, `top_suite`, `located_name`, and
`counters` were read on their pages, in part; `runner` and `runner_options`
were read from their headers, with the index of the `runner` page. The other
indices, the Deprecated List, the internal class and namespace pages, and the
file pages were only sampled with searches, so this review does not cover
their prose. The published version has no differences from `HEAD` in the API
sources (`website/docs/api`, `website/doxygen`, `include`, `src`, and the
sidebar), and no source commit follows the last regeneration, so the sources
that were read are those of the published pages, and no page is stale.

The site was built from the working tree, with no broken links or anchors. The
strict Doxygen checks report 0 warnings (one configuration warning, see #23),
the merged completeness check 0 problems, and the style check 3 problems
(see #62). The probes were built with Apple clang 17, with `-Wall -Wextra
-Wpedantic -Wshadow` for the examples, and also with `-fno-exceptions
-fno-rtti` and with the deprecated definitions enabled; no native GCC was
installed, so nothing was confirmed with GCC. The outputs were compared with
the real `minimal` and `sample` programs, built without their platform header,
and with `tests/expected/`. Unless an item says "derived from reading the
code", it was reproduced by a probe or by a search of the published pages.

Summary: 71 problems (0 open, 53 fixed, 18 withdrawn). Of the fixed ones, #1
and #2 are committed (`55868b39`), and the others are staged, not committed;
#3, #36, and #64 are fixed in the source of the converter; #3 and #36 are
verified on the pages regenerated with it. The prose is careful, all the
examples compile, and the sample outputs are close to the real ones. The
serious problems came mostly from the generation, not from the text: Doxygen
merged the comments of the overloads that differ only in their `requires`
clause, so that the real `expect()` and `require()` were described as
"Deprecated" and as stopping the compilation (#1, #2, fixed by hiding the
rejecting overloads from Doxygen), and the converter dropped all the
enumerator descriptions (#3). The most misleading statements of the text were
#4, #5, #6, and #8, all corrected. The maintainer accepted the design and
configuration points (#22, #35, #37, #38, #41 to #48, #50, #66 to #68, and
#70), which are withdrawn, and the `website-api-review` skill records them, so
that a later review does not report them. No item is open.

## Note on generated pages

The published pages are built by Docusaurus, after a push to the `webpreview`
branch, from `website/docs/api/`, which `npm run generate-website-doxygen`
generates from the Doxygen XML, which comes from `include/`, `src/`, and
`website/doxygen/`. No fix belongs in a generated page; each item names its
source, marked as:

- **[topic]**: a hand-written source in `website/doxygen/`;
- **[header]**: a Doxygen comment in `include/` or `src/`;
- **[config]**: a Doxygen configuration file;
- **[template]**: `top-common.h`, fixed in the
  `@xpack/docusaurus-template-liquid` package;
- **[converter]**: the `@xpack/doxygen2docusaurus` package;
- **[code]**: a change to the library code or API.

## 1. Defects

- **#1 (fixed) — The comments of overloads that differ only in `requires` are
  merged.** Fixed in `55868b39` with option (a) for the rejecting overloads,
  and with a guard on the out-of-line definitions of the deprecated `expect()`
  and `require()`; the Doxygen XML no longer has the merged text. The
  published pages change when they are regenerated. [header]
  `inlines/test-inlines.h` lines 588, 642, 701, 732, 749, 989, 1186;
  `inlines/runner-inlines.h` line 208; `inlines/detail-inlines.h` lines 898,
  1101; `inlines/check-result-inlines.h` line 213. Doxygen ignores the
  `requires` clause when it matches a definition to a declaration, so the
  `@details` of the rejecting and deprecated definitions join the real
  function. The XML already has the merged text (for example, `Never called;`
  in the real `test_case::test()`), so the converter is not at fault. As
  published:
  - the Expectations topic says of the real `expect()`: "Stops the compilation
    with the message of the `static_assert`, which states what expect()
    takes", and "Deprecated; the check is the same as that of expect(), for
    the arguments that are always true"; the Requirements topic says the same
    of `require()`;
  - `runner::add_suite()`, `suite::test()`, `test_case::test()`, and the
    `static_suite` constructor end with "Never called; the compilation stops
    in ...", on the entities that the applications call;
  - the same applies to the constructors on the `compare_op` and
    `predicate_op` pages, in `detail` and in `extension`, and on the
    `check_result` page.

  Decision for the maintainer. The options, none of which was tried: (a)
  exclude the rejecting overloads from Doxygen (with `#if
  !defined(__DOXYGEN__)` or `@cond`), which conflicts with the rule of the
  `doxygen-review` skill that every entity is documented, and needs an
  exception there; (b) keep only the declaration comments for these overloads,
  and remove the `@details` from their out-of-line definitions; (c) report the
  problem to Doxygen, and do (a) or (b) meanwhile. Option (a) is recommended
  for the rejecting overloads, since the applications never call them, and it
  also solves #2. The deprecated overloads need (b).

- **#2 (fixed) — The `test_case` page documents `expect()` and `require()`
  only as rejections.** Fixed with #1, in `55868b39`: the XML of `test_case`
  no longer has the rejecting entries. [header] `test.h` lines 1596, 1660,
  1642, 1719. The real functions have `@ingroup`, so that their sections are
  on the Expectations and Requirements topics. The `expect()` and `require()`
  sections of the `test_case` page are therefore those of the rejecting
  overloads ("Rejects a value that is not a condition"), and the first entries
  of the member index carry the same brief; the real ones are listed last,
  without context. A reader of the main class of the test bodies finds that
  its main function rejects values. The fix of #1 (a) removes the rejecting
  sections; the index entries of the real functions then need to stay visibly
  linked to their topics.

- **#3 (fixed in the converter, not committed or released) — The enumerator
  descriptions are lost.** [converter] The XML has them (`Colours are used
  when stdout is a terminal...`, as the `detaileddescription` of `enumvalue`),
  and neither `website/docs/api/` nor the published pages do. The "Enumeration
  values" tables show the names only, for `verbosity`, `reporter_kind`,
  `colour_mode`, and all the other enumerations, public and internal. The
  reader cannot learn from its page what `verbosity::quiet` displays, or what
  `colour_mode::automatic` does on an embedded target. Fix the converter to
  render the detailed description of the enumerators. Meanwhile, the
  `@details` of the three public enumerations (`runner-options.h` lines 83,
  117, and 134) could list the values, which would duplicate the `/**< */`
  comments.

  Fixed in the source of `@xpack/doxygen2docusaurus` (`members-vm.ts`,
  `EnumValue`): the detailed description is rendered after the brief, and the
  initialiser value follows it. Verified by converting the Doxygen XML of this
  project into a scratch folder: 236 pages, no empty enumerator cell. The
  website uses the fix after a new release of the package. Verified on the
  pages regenerated with the fixed converter: the Test Runners topic shows the
  descriptions of `colour_mode`, `reporter_kind`, and `verbosity`, and no
  enumerator cell is empty in the 236 pages.

- **#4 (fixed, not committed) — `expect()` does not accept "any value that
  converts to `bool`".** [topic] `topics/cpp-api/expectations.dox` lines 13
  and 14. Probes: a string literal and a function name are rejected by
  `static_assert` ("expect() takes a Boolean condition or a comparison"), and
  `std::optional<bool>` is rejected too ("does not take a wrapper of a bool");
  the page cites `std::optional` as an example of what is accepted. Suggested
  text: "any other value that converts to `bool`, such as `x == 1`, a pointer,
  or a `std::optional<int>`, which reports only the location of the failed
  check. The values that are most likely not conditions (string literals and
  function names) do not compile, nor do the wrappers of a `bool`, such as
  `std::optional<bool>`, whose condition tests the wrapper, not the value."

  Fixed in `topics/cpp-api/expectations.dox`: the page now lists the rejected
  values, and the deprecated mode, verified with a probe of ten cases; the
  optional `bool` wrapper, the smart pointers to `bool`, and the scoped
  enumerations stay rejected with the deprecated definitions.

- **#5 (fixed, not committed) — Two topics disagree about the types without
  `operator<<`.** [topic] `topics/cpp-api/function-comparators.dox` lines 63
  to 65 say that the values of the application types "are displayed only if"
  the application provides the operator, which implies that the comparison
  compiles without it; `topics/cpp-api/customisation.dox` lines 16 and 17 say
  that `eq()` does not compile. Customisation is right (probe:
  `static_assert`, "an operand of the comparator cannot be written in the
  report"). Suggested text: "The application types need an `operator<<` for
  the formatter; without it, the comparator does not compile; see ...".

  Fixed in `topics/cpp-api/function-comparators.dox`, with the suggested text;
  the comment of the `expression_formatter` alias in `expression-formatter.h`
  already says that the comparators do not compile, so it was left unchanged.

- **#6 (fixed, not committed) — The limit of the digits of the floating-point
  literals is wrong.** [topic] `topics/cpp-api/deprecated/literals.dox` lines
  39 to 42 say that the digits are limited to `digits10` of the type of the
  literal, "6 for `_f` and 15 for `_d`", "otherwise the compilation fails".
  Probes: `1.1234567_f`, `1234567.0_f`, `1.1234567890123456_d`, and
  `1234567890123456.0_d` all compile; a literal of 21 digits fails. The
  operators pass `unsigned long long` to `detail::math::num()` and `den()`
  (`inlines/deprecated-inlines.h` lines 1183 and 1184), so the limit is 19
  digits for all the types, derived from reading the code. Decision for the
  maintainer: correct the text, or change the code (see #70). Since the
  literals are deprecated, correcting the text is recommended: "are each
  limited to 19 digits, the capacity of `unsigned long long`, whatever the
  type of the literal".

  Fixed in `topics/cpp-api/deprecated/literals.dox`, by correcting the text,
  as recommended. A probe confirmed the limit: 19 digits are accepted and 20
  fail, in the integer part and in the decimals, for `_f` and `_d` alike. The
  code is unchanged (see #70).

- **#7 (fixed, not committed) — The reason given for deprecating `_and()` is
  false.** [topic] `topics/cpp-api/deprecated/logical-functions.dox` lines 7
  and 8: "because no other public name starts with an underscore". The public
  aliases `_i`, `_b`, `_u8`, and so on exist (`deprecated.h` lines 1993 to
  2247), although they are deprecated too, and the Deprecated List shows them.
  Suggested text: "because no other current public name starts with an
  underscore".

  Fixed with the suggested wording in
  `topics/cpp-api/deprecated/logical-functions.dox`, and in the same sentence
  of the comments of `_and()`, `_or()`, and `_not()` in `deprecated.h` ("the
  other current public names").

- **#8 (fixed, not committed) — `initialise (argc, argv)` is documented as
  having no effect when it is called twice.** [header] `runner.h` lines 358 to
  361: "a later call ... reports an error on `stderr`, without other effects".
  Probe: the second call also writes a failed test point in the report, and
  `run_suites()` returns 1, as the other overload (lines 389 to 391) and
  `src/runner.cpp` (lines 266 to 270) correctly say. Only a call after an
  abort has no other effect. Suggested text: "a later call reports an error on
  `stderr` and in the report, and is rejected, so that `run_suites()` returns
  1; the options are not parsed, so their errors do not change the exit code;
  a call after the test execution was aborted reports an error on `stderr`,
  without other effects."

  Fixed in `runner.h` (the comment of `initialise (int argc, char* argv[])`),
  with the suggested text. The comment of the definition in `src/runner.cpp`
  was already correct. Re-checked with a probe: the second call writes `not ok
  2 - test runner already initialised` and `run_suites()` returns 1.

- **#9 (fixed, not committed) — The top namespace page lists a `math`
  namespace that does not exist there.** [header] `runner.h` line 100. The
  namespace is `detail::math`, as the Namespaces index shows. The paragraph
  also says "the runners" for one class, omits the deprecated `type_traits`,
  and does not say that `literals` and `operators` are deprecated. Suggested
  text: remove `math`, write "the runner", mark `literals` and `operators` as
  deprecated, and add `type_traits`.

  Fixed in `runner.h`, with the suggested text: `math` removed (`detail::math`
  is named under `detail`), "the runner", `type_traits` added, and the
  deprecated namespaces marked.

- **#10 (fixed, not committed) — The briefs of the deprecated namespaces do
  not say so.** [header] `deprecated.h` line 886: "Custom operator overloads
  for expressive and type-safe test assertions", also promotional (see #61);
  the `literals` brief: "User-defined literals for the µTest++ testing
  framework". Both appear in the Namespaces index beside the current
  namespaces, while `type_traits` says "Deprecated". Suggested: "Deprecated
  comparison and logical operators", and "Deprecated user-defined literals".

  Fixed in `deprecated.h`: the briefs are "Deprecated comparison and logical
  operators of the test checks." and "Deprecated user-defined literals of the
  test checks." The promotional brief of `operators` is gone too, which
  settles that occurrence of #61.

- **#11 (fixed, not committed) — The `extension` brief omits the templates.**
  [header] `extension.h` line 265: "The concepts for extending ..."; the
  namespace also has the templates `compare_op` and `predicate_op`, its main
  content for the applications. Lines 30 to 34 have the same gap. Suggested:
  "The templates and the concepts for extending ...".

  Fixed in `extension.h`: the brief of the namespace is "The templates and the
  concepts for extending the µTest++ testing framework.", and the file comment
  names `compare_op` and `predicate_op` among the entities of the namespace.

- **#12 (fixed, not committed) — A stale reference to an unknown reporter.**
  [header] `runner-options.h` line 200: "whether the reporter was unknown".
  The private member is `unknown_option_`, and an unknown reporter is an
  ordinary error. Suggested: "whether an unknown option was found".

  Fixed in `runner-options.h`, with the suggested text.

- **#13 (fixed, not committed) — The `src` folder page omits
  `deprecated.cpp`.** [topic] `folders/src.dox` lines 9 to 25. The file
  exists, and has its own file page.

  Fixed in `folders/src.dox`: `deprecated.cpp` is listed, after
  `counters.cpp`; all the 12 files of the `src` folder are now listed.

- **#14 (fixed, not committed) — The `src` folder page places the option
  parsing in `runner.cpp`.** [topic] `folders/src.dox` line 18. The parser is
  in `runner-options.cpp`, as line 13 of the same file says; `runner.cpp` only
  reports the errors. Suggested: "`runner` constructors, initialisation, suite
  registration, `run_suites()`, and `abort()`".

  Fixed in `folders/src.dox`, with the suggested text for `runner.cpp`.

- **#15 (fixed, not committed) — `approx()` does not take integers "of any
  type".** [topic] `topics/cpp-api/function-comparators.dox` line 72. Probe:
  `char` and `bool` operands are rejected; the concept `approx_operand`
  (`detail.h` lines 1958 to 1965) also excludes `wchar_t`, `char8_t`,
  `char16_t`, and `char32_t`. Since these are integral types in C++, say so:
  "integral (other than `bool` and the character types) or floating-point
  numbers".

  Fixed in `topics/cpp-api/function-comparators.dox`: the text names the
  rejected types and the accepted `signed char` and `unsigned char`. Probe:
  `char`, `bool`, `wchar_t`, `char8_t`, `char16_t`, and `char32_t` do not
  compile, as operands or as the tolerance; `signed char`, `unsigned char`,
  and `std::int8_t` do.

- **#16 (fixed, not committed) — The macro pages suggest that the header
  defines the macros.** [topic] `macros/*.dox`. Each one ends with "Definition
  at line 73 of file micro-test-plus.h", followed by the line `#define ...`,
  while the same page says that "neither the library nor its ... build files
  define them". The definitions exist only under `#if defined(__DOXYGEN__)`,
  and nothing on the page explains it. Add to `topics/config.dox`: "The
  definitions shown below exist only for this documentation; the library does
  not define these macros"

  Fixed in `topics/config.dox` with the suggested sentence, at the
  end of the topic.

- **#17 (fixed, not committed) — "Otherwise the link fails" is too general.**
  [topic] `topics/config.dox` lines 20 and 21. It is true for the main macro,
  and, for the deprecated macro, only if non-inline members are used, as
  `macros/micro-os-plus-micro-test-plus-deprecated-enabled.dox` says
  precisely; the trace macros only add calls to `trace::printf()` and do not
  change the declarations. Derived from reading the code. Suggested: "must be
  compiled with the same `ENABLED` and `DEPRECATED_ENABLED` macros".

  Fixed in `topics/config.dox`: the text names the two macros that must match,
  refers to the pages of the macros for the deprecated one, and says that the
  trace macros only add trace calls to the function bodies.
.
- **#18 (fixed, not committed) — "Nothing" and `--silent`.** [topic]
  `topics/cli.dox` lines 36 to 38, 91, and 189. Probe: `--silent -x` writes
  `error: unknown option '-x'` on `stderr`, which the user sees on the
  console, and writes nothing on `stdout`. The page says that errors are
  reported "on the console", and that with `--silent` "nothing is displayed".
  Say that `--silent` silences the standard output, while the errors of the
  options and of the rejected calls still go to `stderr`.

  Fixed in `topics/cli.dox`: the three places say that `--silent` writes
  nothing on the console, that the errors are still written on `stderr`, and
  that `--help` and `--list-tests` are displayed. Probe: with `--silent`, `-x`
  writes only on `stderr` (exit code 2), `--help` and `--list-tests` still
  write on `stdout`.

- **#19 (fixed, not committed) — The exit code of `--help` is missing from the
  lists.** [topic] `topics/cpp-api/runners.dox` line 19, and [header]
  `runner.h` lines 500 to 509 (`run_suites()`). Probe: `--help` returns 0 and
  runs no test; both lists read as if 0 meant that the checks passed. Add "or
  when `--help` was given".

  Fixed in `topics/cpp-api/runners.dox` and in the `@return` of `run_suites()`
  in `runner.h`. Probe: `--help` returns 0, also with an application argument.

- **#20 (fixed, not committed) — A stale line number in a sample output.**
  [topic] `topics/cli.dox` line 172: `lineNumber: 454`;
  `tests/expected/tap/unit-checks-test-console-quiet.tap` line 22 has 399.

  Fixed in `topics/cli.dox`: the line number is 399, as in the reference file.

- **#21 (fixed, not committed) — Inconsistent line numbers in a sample
  output.** [topic] `topics/cpp-api/customisation.dox` lines 93 and 95:
  `main.cpp:75` and `main.cpp:80`, five lines apart, while the two checks of
  the example are four lines apart (probe: lines 47 and 51). Use `main.cpp:75`
  and `main.cpp:79`.

  Fixed in `topics/cpp-api/customisation.dox`: the second line number is
  `main.cpp:79`. The example compiled and run gave lines 47 and 51, four lines
  apart.

- **#22 (withdrawn) — Spurious relations between the entities.** [config]
  `common-config.doxyfile`, `REFERENCES_RELATION` and
  `REFERENCED_BY_RELATION`. For example, `add_suite()` is "Referenced by
  add_suite, operator= and suite", `expect()` by `test_case::test`, whose body
  does not call it, a deleted constructor has "Reference test_case", and
  `eq()` both references and is referenced by `eq`. Doxygen resolves these by
  name, across overloads. The lists do not help the application writers, and
  they add to #37. Suggested: set both options to `NO`.

  Withdrawn: the maintainer keeps both options set to `YES`, for the
  "References" and "Referenced by" lists. The configuration is unchanged, and
  the `website-api-review` skill now says so, so that later reviews do not
  report them.

- **#23 (fixed, not committed) — `SITEMAP_URL` is stale.** [config]
  `common-config.doxyfile`:
  `https://micro-os-plus.github.io/micro-test-plus-xpack/reference/` returns
  404, and Doxygen warns "Setting SITEMAP_URL requires GENERATE_HTML=YES" in
  the overlay used for the checks. Point it to the `doxygen/` pages of the
  site, or remove it.

  Fixed locally in `website/doxygen/common-config.doxyfile`, and in the
  template `common-config-liquid.doxyfile` of `docusaurus-template-liquid`
  (uncommitted in that repository): the value is now
  `{{packageHomepage}}doxygen/`, here
  `https://micro-os-plus.github.io/micro-test-plus-xpack/doxygen/`, which
  returns 200, with its `sitemap.xml`. The other projects that share the
  template (`diag-trace-xpack`, `utils-lists-xpack`) still have `reference/`
  until they regenerate their commons.

## 2. Missing information

- **#24 (fixed, not committed) — What happens to an exception that escapes a
  test case or a suite body.** [topic] `topics/cpp-api/test-case.dox`. Probe:
  an exception that escapes a test case is reported as a failed check
  ("unexpected exception: escaped"), the test case ends, and the next one
  runs; one that escapes a suite body fails that suite, and the run continues.
  Only `located_name` hints at it.

  Fixed in `topics/cpp-api/test-case.dox`: a new paragraph describes the
  report of an exception that escapes a test case or a suite body, including
  the nested and the unknown-type cases. Probes: `unexpected exception: inner
  boom` is reported by the innermost test case, the outer one then reports `1
  test case failed`, and a thrown `int` gives `unexpected exception of unknown
  type`.

- **#25 (fixed, not committed) — A test case without checks passes.** [topic]
  `topics/cpp-api/test-case.dox`. Probe: `✓ empty - passed (0 checks)`. This
  is a trap (a body that forgets its checks passes); say so.

  Fixed in `topics/cpp-api/test-case.dox`, in the same edit as #24: the text
  says that a test case without checks passes, as `passed (0 checks)`.

- **#26 (fixed, not committed) — No example of a run without a command line.**
  [topic] `topics/cpp-api/runners.dox` lines 8 and 9, and the sections of
  `topics/cli.dox`, name `runner_options`, but the topics show no use of it,
  although it is the normal case on embedded targets. The example is in the
  class comment (`runner-options.h` lines 180 to 186); add it to the topic.

  Fixed in `topics/cpp-api/runners.dox`: a new section, "Without a command
  line", with the example of the class comment of `runner_options`, completed
  as a program. The example was compiled with `-Wall -Wextra -Wpedantic
  -Wshadow` without warnings and run.

- **#27 (fixed, not committed) — No example of a predicate.** [topic]
  `topics/cpp-api/customisation.dox` lines 98 to 100 describe it in one
  sentence. Probe of the form that works, with the report `(is even 2 and is
  even 3)`: `mt::extension::predicate_op{ value, is_even_tag{} }`, whose
  `symbol` is `"is even "`. Show it, including the trailing space of the
  symbol, which the text does not mention.

  Fixed in `topics/cpp-api/customisation.dox`: an example of a predicate, with
  its report, and the note on the trailing space of the symbol. The example
  was compiled with `-Wall -Wextra -Wpedantic -Wshadow` without warnings, and
  run; the combination with `negate()` was run too.

- **#28 (fixed, not committed) — The list of the public extension names is
  incomplete.** [topic] `topics/cpp-api/customisation.dox` lines 30 to 32 omit
  the concept `approx_operand`, and `has_epsilon`, available only with the
  deprecated definitions; the optional `within_tolerance_result` of the tags
  is only on the `compare_op` page.

  Fixed in `topics/cpp-api/customisation.dox`: the list names
  `approx_operand`, `has_epsilon` (with the deprecated definitions), and the
  optional `within_tolerance_result` of the tags, as `detail-inlines.h` uses
  them.

- **#29 (fixed, not committed) — The cost and the lifetime of the operands.**
  [topic] `topics/cpp-api/function-comparators.dox`. The header comment of
  `function-comparators.h` explains that the named operands are copied for
  every check, passing or failing, so that a large container or string costs
  an allocation, and that the arrays and C strings are only referred to. This
  matters on embedded targets, and is only on a file page, which the
  application writers do not read. Add it to the topic.

  Fixed in `topics/cpp-api/function-comparators.dox`: a new paragraph, "Cost
  and lifetime of the operands". Probe with a type that counts its copies: a
  named operand is copied twice for a passing `eq()`, the temporaries are
  moved, and the expression keeps its copies. The statement on the arrays and
  the C strings is taken from the header comment and from API-REVIEW-10.md #2.

- **#30 (fixed, not committed) — The `_i`, `_u8`, and similar aliases are not
  explained.** [topic] `topics/cpp-api/deprecated/literals.dox` and
  `deprecated.dox`. They are listed in the index of the topic, but the text
  mentions only the `to_*` wrappers; v5.0.1 code that uses `mt::_i{ value }`
  finds no replacement in the text.

  Fixed in `topics/cpp-api/deprecated/literals.dox`: a new paragraph, "The
  v5.0.1 aliases". Probe: `mt::_i{ ... }`, `mt::_u8{ ... }`, and `mt::_d{ ...
  }` compile with the deprecated definitions, with the same deprecation
  messages as the `to_*` wrappers.

- **#31 (fixed, not committed) — Repeated options.** [topic] `topics/cli.dox`.
  The last one takes effect (`src/runner-options.cpp` lines 94 to 97; probe
  with `--reporter` and verbosity options), except for `--filter`, whose
  repetition has a meaning of its own. The page does not say it.

  Fixed in `topics/cli.dox`: a bullet in "Options and application arguments".
  Probes: `--quiet --verbose` shows the passed checks, `--verbose --quiet`
  does not; the last of `--reporter` and of `--colour` wins; repeated
  `--filter` options are all kept.

- **#32 (fixed, not committed) — The console line about the output file.**
  [topic] `topics/cli.dox` lines 179 to 181. Probe: the run ends with `# Test
  output written to 's.tap'.`; the sentence "only the failures" does not
  prepare the reader for it, and the example shows no output.

  Fixed in `topics/cli.dox`: the example of the quiet section shows the line,
  and the output file section describes it, including that `--silent` omits
  it. Probe: the line is `# Test output written to ...` with the TAP reporter,
  and `Test output written to ...` with the human-readable one.

- **#33 (fixed, not committed) — An empty output path.** [topic]
  `topics/cli.dox`, `cli-output-file` section. `--output-file=` disables the
  file (`src/runner-options.cpp` line 243; probe), and the option is otherwise
  documented as requiring a value.

  Fixed in `topics/cli.dox`, in the output file section. Probes:
  `--output-file=` and `--output-file ""` write no file, and a later empty
  path cancels an earlier one.

- **#34 (fixed, not committed) — More than one runner.** [topic]
  `topics/cpp-api/runners.dox` line 5: "A test program has one runner", while
  the class comment (`runner.h` lines 143 to 149) explains that several may
  coexist, each with its suites. Write "usually has one runner", with a link.

  Fixed in `topics/cpp-api/runners.dox`: "usually has one runner", and a
  paragraph on several runners, with a link to the class. The statement comes
  from the class comment of `runner`; it was not probed here.

## 3. Structure and presentation

- **#35 (withdrawn) — The class pages start with what the reader needs
  least.** [config] [header] The index of `test_case` has, in order: Friends,
  deleted public constructors, a private constructor, the destructor, deleted
  operators, and only then the member functions, starting with the rejecting
  `expect()`. Decision for the maintainer: `EXTRACT_PRIVATE = NO` removes the
  private entries, at the cost of the published internal documentation, which
  `doxygen-review` requires in the sources but not on the site; the
  `HIDE_FRIEND_COMPOUNDS` option removes the friends; `@name` groups can place
  the deleted members last. The `EXTRACT_PRIVATE` change is recommended, since
  the sources keep the comments.

  Withdrawn: the maintainer keeps `EXTRACT_PRIVATE = YES` and
  `HIDE_FRIEND_COMPOUNDS = NO`, so that the private members and the friends
  stay on the pages. The configuration is unchanged, and the
  `website-api-review` skill now says so. The placement of the deleted
  members, with `@name` groups, was not decided, and nothing was changed.

- **#36 (fixed, not committed) — A private enumeration comes first on the
  `runner` page.** [config] [converter] `session_state` is private, yet is
  listed as "Enumerations Index", without the word "Private", before the
  Friends and the constructors. The private members stay on the pages (see
  #35), so the converter should label the private enumerations, as it does the
  other private members.

  Fixed in the source of `@xpack/doxygen2docusaurus` (not committed or
  released): `compound-base-vm.ts` keeps the access prefix of the section for
  the enumerations, as for the typedefs, and `members-vm.ts` has the headers
  "Public", "Protected", "Private", and "Package Enumerations". Verified by
  converting the Doxygen XML of this project into a scratch folder: the
  `runner` page now has "Private Enumerations Index" and "Private
  Enumerations"; the other class pages have no enumerations, and the namespace
  pages keep "Enumerations". The position of the section is unchanged.
  Verified on the pages regenerated with the fixed converter: the `runner`
  page has "Private Enumerations Index" and "Private Enumerations".

- **#37 (withdrawn) — The pages are very large.** [config] The 236 pages make
  25.0 MB of HTML; 30 exceed 200 KB, and 6 exceed 500 KB (`reporter_tap` 763
  KB, `reporter_human` 732 KB; the public `runner` page has 513 KB). The
  causes are `INLINE_SOURCES`, `INLINE_INHERITED_MEMB`, and the relation
  lists, which the maintainer keeps (see #22). Decision for the maintainer;
  `INLINE_SOURCES = NO` is recommended, since the file pages keep the source
  listings. The reduction was not measured.

  Withdrawn: the maintainer keeps `INLINE_SOURCES = YES` and accepts the page
  sizes. The configuration is unchanged, and the `website-api-review` skill
  now has a section on the Doxygen configuration, which lists the options that
  are kept, and asks that the configuration is changed only for a real defect.

- **#38 (withdrawn) — Internal entities are mixed with the public ones in the
  indices.** [config] [converter] The Classes index starts with
  `array_operand` and `basic_c_string`; the Concepts index lists the 27
  concepts of `detail` before the public ones of `extension`; the Namespaces
  index shows `anonymous{runner.cpp}` and three more, from
  `EXTRACT_ANON_NSPACES`. Options for the maintainer: add to the converter a
  separation of the `detail` entries, or keep the indices, and make the topics
  the entry point (see #65).

  Withdrawn: the maintainer keeps `EXTRACT_ANON_NSPACES = YES`, and the
  indices as they are; the entry points are the topics (see #65). The
  configuration is unchanged, and the `website-api-review` skill lists the
  option among those that are kept, and says not to propose an option to
  separate the internal entities.

- **#39 (fixed, not committed) — Some public entities are in no topic.**
  [header] `runner_options`, `verbosity`, `reporter_kind`, `colour_mode`, and
  `counters` should join Test Runners; `top_suite` and `located_name` should
  join Test Suites, with `@ingroup`. The Test Runners topic lists only
  `runner`, and Test Suites lists `suite` and `static_suite`, although its
  text explains the top suite.

  Fixed in `runner-options.h`, `counters.h`, and `test.h`, with `@ingroup`:
  `runner_options`, `counters`, `verbosity`, `reporter_kind`, and
  `colour_mode` are in Test Runners, and `top_suite` and `located_name` in
  Test Suites. Checked in the Doxygen XML of both topics.

- **#40 (fixed, not committed) — The topic texts link to few of the entities
  that they name.** [topic] Some mentions become links, and others do not:
  Test Suites links `add_top_suite` and `run_suites`; Test Runners links
  neither of them, nor `runner_options`; the Command-Line Options page
  mentions `runner_options` six times, and has no link to any class; the
  Customisation page has no link to `extension::compare_op`, `predicate_op`,
  or the concepts, its main subject. Use `@ref`, at least for the first
  mention on each page.

  Fixed in `topics/cpp-api/runners.dox`, `topics/cli.dox`, and
  `topics/cpp-api/customisation.dox`, with `@ref` for the first mention of
  `runner`, `runner::run_suites()`, `runner_options`, `extension::compare_op`,
  and `extension::predicate_op`. Checked in the Doxygen XML, where each is a
  resolved reference. Doxygen does not link a plain code span such as
  `runner::run_suites()`, whose links on the Test Suites topic come from its
  code examples, so the other mentions stay plain. The concepts of the
  Customisation topic are not linked.

- **#41 (withdrawn) — Duplicate index entries.** [converter] `compare_op` and
  `predicate_op` appear twice in the Classes index, with the same brief
  (`detail` and `extension`, the second being a using-declaration), and so
  does `comparison_integer<T>`, with nearly the same text (primary template
  and specialisation). Show the qualified names, or the template arguments
  that differ.

  Withdrawn: the maintainer accepts the duplicate entries, which are distinct
  entities with the same brief. Nothing is changed, and the
  `website-api-review` skill says so.

- **#42 (withdrawn) — "Deprecated Functions Index" appears twice.** [config]
  On `suite`, one list has `timings()`, and the other `own_index()`, since
  each class has its own `@name` group, and `INLINE_INHERITED_MEMB` adds the
  group of the base class, derived from reading the configuration. Removing
  the inlined inherited members, by changing the configuration, would remove
  the second list.

  Withdrawn: the only fix is a change of the Doxygen configuration, which is
  made only for a real defect; a duplicated list heading is not one.

- **#43 (withdrawn) — Documentation-only files are published as library
  files.** [template] [topic] `top-common.h` and `topics.h` are in the Files
  index, after `src`, with no sign that they are not part of the library,
  apart from the text of their own pages.

  Withdrawn: the maintainer accepts that the two files are listed, since their
  own pages say that they are documentation-only. Nothing is changed, and the
  `website-api-review` skill says so.

## 4. API design

These are decisions for the maintainer. No item is listed in
`API-REVIEW-10.md`, whose scope was the defects only.

- **#44 (withdrawn) — `detail::check_result&&` in the signature of the main
  functions.** [code] `test.h` lines 1626 to 1630. The first thing that the
  reader sees of `expect()` is an internal return type, and a third parameter
  that must never be passed. The page explains it well, but it is the first
  impression of the framework.

  Withdrawn: the maintainer accepts it as it is. Nothing is changed, and the
  `website-api-review` skill lists it among the accepted design points, so
  that later reviews do not report it.

- **#45 (withdrawn) — `expression_formatter` is an alias of a `detail`
  class.** [code] Customisation links to `detail::expression_formatter`, a
  page of 571 KB, where the application writers look for the operators that
  they can use, among internal members.

  Withdrawn: the maintainer accepts it as it is. Nothing is changed, and the
  `website-api-review` skill lists it among the accepted design points, so
  that later reviews do not report it.

- **#46 (withdrawn) — `class suite&` in the signatures.** [code] `runner.h`
  lines 448 and 465. The elaborated specifier is needed because the deprecated
  member `runner::suite()` hides the class; it can go when that member is
  removed, and looks like a mistake until then.

  Withdrawn: the maintainer accepts it as it is. Nothing is changed, and the
  `website-api-review` skill lists it among the accepted design points, so
  that later reviews do not report it.

- **#47 (withdrawn) — Public classes document their public members through
  `detail`.** [code] `name()` and `totals()` of `suite` and `test_case` come
  from `detail::runnable_base`; the "Base class" entry sends the application
  writers to an internal page, whose other members they must ignore.

  Withdrawn: the maintainer accepts it as it is. Nothing is changed, and the
  `website-api-review` skill lists it among the accepted design points, so
  that later reviews do not report it.

## 5. Consistency

| #   | Concept | Variants found (where) | Suggested | Status |
| --- | ------- | ---------------------- | --------- | ------ |
| #48 | The whole run | "test session" (27), "test run" (36), "test execution" (39), in `runner.h`, `requirements.dox`, and `test-suites.dox` | "test session"; keep "abort" for the verb | Withdrawn |
| #49 | One verification | "check" (topics), "assertion" (17: `function-comparators.h` line 35, `detail.h` line 836, the `operators` brief), "expectation" for all checks in the comparator comments | "check"; "assertion" only when citing other frameworks | Fixed, not committed |
| #50 | A test unit | "test case", and "subtest" (20: the deprecated names, and the sample names in `cli.dox` line 166) | "test case"; rename the sample names in the unit test when convenient | Withdrawn |
| #51 | Time of execution | "run-time" (24, adjective), "run time" (4, noun), "runtime" (10: `deprecated.h` lines 330, 424) | "run-time" adjective, "run time" noun; no "runtime" | Fixed, not committed |
| #52 | Adjectives with hyphens | "floating point value/type/members" (15) against "floating-point" (75); "command line options" (`runner.cpp` line 83) against "command-line options" | Hyphenate the adjectives | Fixed, not committed |
| #53 | Topic titles | Title case ("Test Runners", "Function Comparators", "Checking Exceptions", "Command-Line Options"), and within `cli.dox`, "Output File", "Listing the Test Cases" against "Default mode"; the website uses sentence case | Sentence case, in the `@defgroup` lines and the `@section` lines | Fixed, not committed |
| #54 | Example headings | `@par Example` (18), `@par Examples` (3), `**Example**` (2) | `@par Example`, or `@par Examples` for several | Fixed, not committed |
| #55 | Concept briefs | "C++20 concept satisfied ..." and "Concept satisfied ...", on the Concepts page | "Concept satisfied ..." | Fixed, not committed |
| #56 | File briefs | "C++ header file with declarations", "C++ header with declarations" (`exceptions.h`), "with the declaration of" (`stopwatch.h`), "Main C++ header" | "C++ header file with the declarations of ..." | Fixed, not committed |
| #57 | Parameter markup | `@p` (69), `\c` (6), `\p` (3), in `deprecated.h` and `reflection-inlines.h` | `@p` and backticks | Fixed, not committed |
| #58 | Option values | `--colour[=always,never,auto]` (`cli.dox` line 14), `--colour[=always\|never\|auto]` (`--help`) | The form of `--help` | Fixed, not committed |
| #59 | Sample outputs | The time as `0.039 ms` (`runners.dox`) or `X.XXX ms` (`cli.dox`); the test case summary line present in `function-comparators.dox`, omitted in `expectations.dox` and `customisation.dox` | `X.XXX ms`; complete blocks, or `...` where lines are omitted | Fixed, not committed |

Notes on the table. #48: withdrawn; the maintainer keeps the three terms,
which overlap in meaning and are used in about a hundred comments. #49: the
remaining uses of "assertion" are static assertions, or references to the
other frameworks. #50: withdrawn; the "subtest" names are the deprecated
aliases and the names of real test cases of the unit tests, and the skill says
that all these terms are kept. #51: a code comment in `detail-inlines.h` that
speaks of the C runtime of Windows is kept. #54: `@par Examples` is kept where
there are several examples. #58: the cell is written as three code spans
joined by `\|`, because a `\|` inside one code span is shown with its
backslash. #59: only the time format was unified.

## 6. Language and style

- **#60 (fixed, not committed) — A sentence repeated in the file comments.**
  [header] "The header files are organised within the ... folder to maintain a
  structured and modular codebase" (20 times). It describes the project, not
  the file, and appears on each file page. Remove it. "For diagnostic
  purposes" (13 times) can also go.

  Fixed in the 20 file comments of `include`, where the paragraph is removed,
  and in the umbrella header `micro-test-plus.h`, whose sentence now only says
  where the other headers are. The sentence "for diagnostic purposes" is kept:
  it is an accurate description of the trace output, and not a boilerplate of
  the project.

- **#61 (fixed, not committed) — Promotional wording.** [header] "expressive
  and type-safe" (3: `function-comparators.h` line 34,
  `inlines/function-comparators-inlines.h` line 33, and `deprecated.h` line
  886). The last one praises what the framework deprecates.

  Fixed in `function-comparators.h` and
  `inlines/function-comparators-inlines.h`; the `operators` brief was changed
  with #10.

- **#62 (withdrawn) — Long lines.** [topic] [header] Lines over 80 characters
  in the `.dox` files: 5 `@defgroup` lines (`function-comparators.dox`,
  `logical-functions.dox`, `utility-functions.dox`, and
  `deprecated/literals.dox` and `deprecated/logical-functions.dox`), which
  Doxygen needs on one line, and 7 lines of sample output (`cli.dox` lines
  112, 137, 154, 265, 280, 283; `runners.dox` line 63), which can stay. The
  style check reports `deprecated.h` lines 799, 817, and 838, at 80
  characters; fix those.

  Withdrawn: the five `@defgroup` lines cannot be wrapped, and the sample
  output lines are kept. The three lines that the style check reports are
  `@ingroup` lines of 80 characters, whose argument is the name of a group,
  which cannot be wrapped without renaming the group, and so the page address.
  Nothing is changed.

- **#63 (fixed, not committed) — A wrong term in a brief.** [header] `test.h`
  line 2632: "Class template constructor for static_suite"; the class is not a
  template, the constructor is. Suggested: "Constructs a static suite, and
  links it into the list of suites."

  Fixed in `test.h`, with the suggested text.

- **#64 (fixed, not committed) — Awkward generated sentences, and a vague
  phrase.** [converter] [topic] The home page says "µTest++ Testing Framework
  topics with brief descriptions are:", and the Classes index "The classes,
  structs, union and interfaces used by this project are:" (the project has no
  union or interface). `folders/include-micro-os-plus-micro-test-plus.dox`
  line 19: "in the `detail` namespace and the like" should name the
  namespaces.

  The folder page is fixed in
  `folders/include-micro-os-plus-micro-test-plus.dox`, which now names the
  `detail` and `reflection` namespaces. The generated sentences are fixed in
  the source of `@xpack/doxygen2docusaurus` (not committed or released):
  `groups-vm.ts` writes "The ... topics, with their brief descriptions, are:"
  and `classes-vm.ts` writes "The classes and structs used by this project
  are:". Verified by converting the Doxygen XML of this project into a scratch
  folder; the concepts and namespaces sentences are unchanged.

  Partly fixed: `folders/include-micro-os-plus-micro-test-plus.dox` now names
  the `detail` and `reflection` namespaces. The generated sentences of the
  home page and of the Classes index are the converter's, and stay open.

## 7. Proposed topic tree

In the sidebar, the first useful page is below three collapsed levels (µOS++
Topics, µTest++, and C++ API), although the API home page lists all the topics
at once. Each move can be accepted on its own, in `website/doxygen/topics.h`;
the anchors of the merged topics should remain, as the rest of the website may
use them.

- **#65 (fixed, not committed) — Link the main classes from the home page.**
  [topic] `pages/mainpage.dox`. It lists all the topics, but not `runner`,
  `runner_options`, `suite`, and `test_case`, which most readers look for, so
  that the indices (#38) matter less.

  Fixed in `pages/mainpage.dox`: a sentence names `runner`, `runner_options`,
  `suite`, and `test_case`, each with `@ref`. Checked in the XML of the main
  page, where all four are resolved references.

- **#66 (withdrawn) — Show the µTest++ topics at the first level.** [template]
  [converter] `top-common.h`, `topics.h` lines 27 to 30. "µOS++ Topics" has
  one child on this site. This is shared with the other µOS++ sites, so it is
  a decision for the maintainer. Failing that, expand these three levels in
  `website/sidebar-category-doxygen.json`, which is generated, so the change
  needs a setting in the converter.

  Withdrawn: the maintainer keeps the tree as it is, since the API home page
  lists every topic and the root is shared with the other µOS++ sites. Nothing
  is changed, and the `website-api-review` skill says so, so that later
  reviews do not report it.

- **#67 (withdrawn) — Merge Expectations and Requirements into "Checks".**
  [topic] `topics.h` lines 45 and 46, `topics/cpp-api/expectations.dox`, and
  `requirements.dox`. Each has one member, and the second is defined by its
  difference from the first. Decision for the maintainer: the separate names
  are clearer in the sidebar, but one page shows the choice between them.

  Withdrawn: the maintainer keeps Expectations and Requirements as two topics.
  Nothing is changed, and the `website-api-review` skill says so, so that
  later reviews do not report it.

- **#68 (withdrawn) — Move "C API" out of the reference.** [topic] `topics.h`
  line 35. It is a page about the absence of an API, and belongs in the user
  manual. Keep the anchor. Decision for the maintainer, since the present page
  answers a question that a C developer does ask.

  Withdrawn: the maintainer keeps the "C API" topic in the reference. Nothing
  is changed, and the `website-api-review` skill says so, so that later
  reviews do not report it.

- **#69 (fixed, not committed) — Rename the deprecated "Logical Functions".**
  [topic] `topics/cpp-api/deprecated/logical-functions.dox` line 1. The
  sidebar has two entries with this name, and the deprecated one has only
  three functions. Suggested: "Old logical function names".

  Fixed in `topics/cpp-api/deprecated/logical-functions.dox`: the title is
  "Old logical function names"; the group name, and so the page address, is
  unchanged.

## 8. Incidental observations in the code

- **#70 (withdrawn) — `num()` and `den()` check the limit of the parsing type,
  not of the literal.** [code] `inlines/deprecated-inlines.h` lines 145 to 148
  and 188 to 191, called from lines 1183 and 1184. `digits10` is that of
  `unsigned long long`, so `1.1234567_f` is accepted, with more decimals than
  a `float` can hold, and `den_size()` then computes its tolerance. This is
  the cause of #6; only the deprecated literals are affected.

  Withdrawn: the maintainer leaves the deprecated code as it is, and the topic
  of the literals states the actual limit (see #6). The `website-api-review`
  skill says that the deprecated code is not changed, and that a defect in it
  is a finding about the page.

- **#71 (fixed, not committed) — The same error has two spellings.** [code]
  Probe of an output file that cannot be opened: `error: Failed to open output
  file '...'` on `stderr`, and `Bail out! failed to open output file '...'` on
  the console. Use the lower-case form, as the other errors do.

  Fixed in `src/reporter.cpp`: the message is `error: failed to open output
  file ...`. No test compares it. `xpm run test -C tests` passes (7 OK, 0
  failed); the probe shows both lines in lower case.

## 9. Reviewed and found correct

- All the examples of the topics compile with no warnings, and run as
  described: the home page, Test Runners, Test Suites (in two source files,
  with the `extern` runner and arguments), Test Cases, Expectations,
  Requirements, Function Comparators, Logical Functions, Checking Exceptions,
  Utility Functions, Customisation, and C API. The examples of the Deprecated
  topics compile with the macro defined.
- The sample outputs of `cli.dox` match the real `minimal` and `sample`
  programs, in the default, `--verbose`, and `--quiet` modes, with `--filter`
  and `--list-tests`, except for #20, and so do those of Expectations and
  Function Comparators.
- The options: `--help` (also with `--silent`, and the priority of the
  errors), the attached and separate values, `--colour` with a separate mode
  word, unknown options (`-x`, `-`, `-verbose`), the missing values, the
  unwritable output file, exit codes 0, 1, and 2, the filter that selects
  nothing, and the error messages.
- The output file: complete and identical at all the verbosity levels, with
  both reporters, with no colours, and with the option errors.
- The execution order: top suite first, byte order (`Gamma` before `alpha`),
  static suites before added ones with the same name, and a failure for a test
  case on a suite that is not running. A run with no suites returns 1, with
  the default name `default suite`.
- `require()`: with exceptions, the test case stops and the next one runs;
  without them, a `Bail out!` line, no totals, and `::abort()` (exit status
  134). A failed `require()` in the callable of `throws()` is not an exception
  of the callable.
- The comparators: mixed signedness, characters compared as integers, C
  strings by content, an unterminated array, null pointers, element-wise
  arrays, pointers by address, the 16-element limit and the index of the first
  difference, the reports of `approx()`, and the negative tolerance.
- The logical functions: the group report; the `using namespace std` trap of
  `all_of()`.
- The exception reports, and the unavailability of the functions without
  exceptions.
- `split()` (the return types), `extract_file_name()` (both separators), and
  `is_match()`.
- `test_each()`, with a range, a span, a braced list, a tuple, and a type
  without `operator<<` (`Records (#2)`).
- The deprecated definitions: the integer literal forms, `300_u8`, a decimal
  point in an integer literal, an exponent, `42_f`, the digit separators, the
  tolerance in all six comparisons, `"false"_b`, the two-operand `_and()`, the
  messages of the deprecation warnings, and the "since 4.1.0" of the `runner
  (const char*)` constructor, which the tag `v4.1.0` confirms.
- The links of the home page to the Getting Started and User's Guide pages,
  the published Doxygen HTML pages mentioned in the note of the home page, and
  the completeness of the sitemap (236 pages, the same number as the local
  files).
- The boilerplate phrases "ensuring clear separation" and "minimising the risk
  of naming conflicts", and the words "seamless", "enhance", "facilitate",
  "comprehensive", "robust", and "professional": none is left.
