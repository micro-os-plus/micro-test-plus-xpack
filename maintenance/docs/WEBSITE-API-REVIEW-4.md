# Website API reference review

Date: 2026-11-05, on branch `xpack-development`, commit `01834cff`;
published version `webpreview` commit `01834cff`.

Scope: the whole API reference published under `/docs/api/` (236 pages of
the sitemap) and the sources that produce it. The rest of the website is
in `WEBSITE-REVIEW-3.md`, the API design in `API-REVIEW-10.md`.

Method: all the published pages were downloaded with `curl` (all 236 have
an `<article>`; 24 MB in total). No page was reviewed from local sources,
since the published version is the current commit, and the working tree
is clean.

- Coverage: the home page, the topics, the namespace and folder pages,
  the Deprecated List, and the public classes were read in full. For the
  internal classes, the structs, the concepts, and the files, the
  descriptions were read, and the member descriptions only where a
  finding led to them. The indices were sampled, and the source listings
  and the deprecated members of each literal were not read one by one.
- Site build: `docusaurus build` succeeded, with no broken link or anchor
  and no warning (`onBrokenLinks` and `onBrokenAnchors` are `throw`).
- Automatic checks: Doxygen with the strict overlay 0 warnings, and only
  the expected `SITEMAP_URL requires GENERATE_HTML` message of the overlay;
  merged completeness 0 problems; style 3 problems
  (see #47).
- Page sizes (observation only): the largest are `reporter_tap` 763 KB,
  `reporter_human` 732 KB, `detail-inlines.h` 603 KB,
  `expression_formatter` 571 KB, `runner` 510 KB.
- Probes: Apple clang 17, with the library built three times (default,
  with the deprecated definitions, and with `-fno-exceptions -fno-rtti`).
  GCC was not available on this machine, so the probes about name lookup
  and diagnostics are confirmed with Clang only.
- Reference outputs: the samples of `cli.dox` were compared with
  `tests/expected/tap/*-console-quiet.tap`, and with the `sample` and
  `minimal` programs, built and run. Every finding is confirmed by a
  probe or a code path, unless it says otherwise.

Summary: 47 problems (0 open, 44 fixed, 3 accepted, 0 withdrawn). The
topics are mostly accurate: all their examples compile, and their sample
outputs match the programs. The most serious problems are:

- #1, in the converter, which rewrites the numeric code spans, so that the
  page says that `10_i` is 8, and that the floating-point values are
  written as `42` to distinguish them from the integers;
- #2, in the converter, which shows `char * argv=[]` in the signatures of
  the public functions;
- #3 and #6, statements contradicted by the probes;
- #4, a function that does not exist;
- #5, four deprecation notes with no text.

Status: every item is closed: 44 are fixed in the working tree, and 3 (#29,
#31, and #47) were accepted as they are. The changes are staged, not
committed. The pages need a regeneration, and the converter fixes (#1, #2,
and #27) need a release of `doxygen2docusaurus`.

Suggested order of work: the converter (#1, #2, #27), then the defects
in the sources (#3 to #19), the missing information (#20 to #26), the
presentation (#28 to #32), the consistency (#33 to #40), and the
language (#41 to #47). No regeneration is pending, and no topic tree
change is proposed. The maintainer has to decide items #26, #28, #29,
as well as #30, #31, #36, and #47.

## Note on generated pages

The pages under `website/docs/api/` are generated, and carry "DO NOT EDIT!";
no fix is proposed in them. `npm run generate-website-doxygen`, in
`website/`, runs Doxygen and `doxygen2docusaurus`, and a push to the
`webpreview` branch publishes the result. The sources are marked as:

- **[topic]**: a hand-written source in `website/doxygen/`;
- **[header]**: a Doxygen comment in `include/` or `src/`;
- **[config]**: a configuration file;
- **[template]**: `top-common.h`, in `@xpack/docusaurus-template-liquid`;
- **[converter]**: the `@xpack/doxygen2docusaurus` package, shared with
  the other sites;
- **[code]**: a change to the library code or API.

## 1. Defects

- **#1 (fixed) — The converter rewrites the numeric code spans.** [converter]
  `src/doxygen/data-model/doxygen-xml-parser.ts` line 93 of the package
  (`dist/.../doxygen-xml-parser.js` line 14): `parseTagValue: true` makes
  `fast-xml-parser` convert each text node that looks like a number. The
  Doxygen XML is correct (`<computeroutput>010<ref...`). A run of the
  parser with the same options gives `010` -> `10`, `42.0` -> `42`, and
  `0x7F` -> `127`, and keeps `0x10_i`. A scan of the XML finds these values
  in the published pages:
  - `010_i` is shown as `10_i`, in "octal (`10_i`, which is 8)", which is
    false (a probe confirms that `010_i` is 8 and `10_i` is 10), on the
    "Literals and wrappers" topic (`literals.dox` line 40);
  - `42.0` is shown as `42`, on the `expression_formatter` class page and
    the formatter source page, which then say that the floating-point
    values "always have a decimal point or an exponent (42)", and "42 is
    formatted as 42" (`expression-formatter.h` lines 202 and 728,
    `src/expression-formatter.cpp` line 941);
  - `0x7F`, `0x10FFFF`, `0xD800`, and `0xDFFF` are shown as 127, 1114111,
    55296, and 57343 (for example, `expression-formatter.h` lines 424 and
    1390), where the values are right but the notation is lost.

  Fix: `parseTagValue: false`, after checking whether the data model
  relies on numeric tag values. Until a release, the two false sentences
  can be reworded so that the number is not alone in a code span.

  Fixed in `doxygen2docusaurus-cli-ts`, `src/doxygen/data-model/
  doxygen-xml-parser.ts` (not yet committed or released): the text of the
  elements is kept as written; the data model already accepted strings,
  and the methods that need a number (`getInnerElementNumber()`) or a
  boolean convert the text themselves. A run of the rebuilt converter on
  the current Doxygen XML changes 32 generated pages and 73 lines, all
  restoring numeric text: besides the cases above, `Boost Version 1.0`
  in the licence line of the source listings, full stops after numbers
  in code comments ("returns 2."), and `09.5`. The text of every
  changed line is otherwise identical. The pages need a regeneration
  after the release.

- **#2 (fixed) — Array parameters are shown as default arguments.** [converter]
  `dist/docusaurus/renderers/paramtype.js` lines 25-26 of the package write
  `=${element.array}`. The signature in the member section of the page is
  then wrong, while the index on the same page is right (it uses the
  `argsstring`). There are nine affected pages, including public functions:
  `runner::initialise (int argc, char * argv=[])`, the same for the
  `runner_options` constructor, and
  `located_name (const char(&) name=[N], ...)`, as well as
  `expression_formatter::operator<<` and the `reporter::format_*()`
  functions. Fix: write the array without `=`, and place the declarator
  correctly for the references to arrays (`const char (&name)[N]`), or
  use the `argsstring` of the XML for these members.

  Fixed in `doxygen2docusaurus-cli-ts`, `src/docusaurus/renderers/
  paramtype.ts` (not yet committed or released): the array is appended to
  the name, and, when the type ends with the empty declarator `(&)` or
  `(*)` (HTML-escaped as `&amp;`), the name is placed inside it. A run of
  the rebuilt converter changes the nine pages, and the signatures are the
  same as the `argsstring` of Doxygen: `char * argv[]`,
  `const char(&name)[N]`, and `char(&message)[totals_size_]`. The pages
  need a regeneration after the release.

- **#3 (fixed) — The `reporter_human` page says that its output file follows the
  verbosity.** [header] `reporter-human.h` lines 85-88: "Most writes to the
  optional output file follow the console verbosity, so the file receives
  the full report only with normal or verbose verbosity; ... the TAP
  reporter, whose output file is always complete, is the one to use". It
  contradicts the `verbosity` enumeration and the "Output file" section of
  `cli.dox` ("whatever the verbosity, with both reporters"). A probe
  confirms the topics: the files written with `--reporter=human` and
  `--quiet`, `--verbose`, the default, and `--silent` have 70 lines each,
  and the quiet and verbose ones differ only in the command line and the
  times. Fix: "The optional output file receives the full report, whatever
  the verbosity, as with the TAP reporter."

  Fixed (staged, not committed): `reporter-human.h`: the output file receives
  the complete report, whatever the verbosity.

- **#4 (fixed) — `test_case::timings()` does not exist.** [topic]
  `topics/cpp-api/deprecated.dox` line 62. The deprecated members are
  `runner::timings()` and `suite::timings()` (`test.h` lines 2299-2333); a
  probe with the deprecated definitions enabled reports "no member named
  'timings' in 'test_case'", while `ts.timings ()` compiles. Fix: replace
  it with `suite::timings()`.

  Fixed (staged, not committed): `deprecated.dox`: `suite::timings()`.

- **#5 (fixed) — Four deprecated members have an empty note.** [header]
  `runner::initialise (argc, argv, top_suite_name)` (`runner.h` line 338),
  `runner::name()` (`runner.h` line 842), and the deprecated overloads of
  `test_case::expect()` and `test_case::require()` (`test.h` lines 1765 and
  1789) show "Deprecated" with no text, on their pages and in the Deprecated
  List, so the reader gets no replacement and no version. Doxygen takes
  the text from the `[[deprecated ("...")]]` attribute, and these are
  exactly the four attributes whose message is split into two adjacent
  string literals. Fix: add a `@deprecated` command with the same text
  to each comment, for example "@deprecated write the condition (since
  6.0.0)".

  Fixed (staged, not committed): `@deprecated` added to the four comments
  (`runner.h`, `test.h`).

- **#6 (fixed) — The `operators` namespace page says that named operands are not
  copied.** [header] `deprecated.h` lines 906-909: "the named operands of
  class type, including the nested expressions, are referred to, without
  copies". The operators use the `compare_op` deduction guide, with
  `stored_operand_t`, which copies every copyable lvalue. A probe with two
  named `mt::to_t<tracked>` operands counts 2 copies for `a == b`, as for
  `mt::eq (a, b)`. It also contradicts the "as by the function comparators"
  in the same sentence, and the "Cost and lifetime of the operands" section.
  Fix: "the temporaries are moved into the returned expression, and the
  named operands are copied, unless they cannot be copied, when they are
  referred to."

  Fixed (staged, not committed): `deprecated.h`: the named operands are
  copied, unless they cannot be copied.

- **#7 (fixed) — `runner::list_test_case()` is said to be silent.** [header]
  `runner.h` line 1195: "to the console, unless the verbosity is `silent`".
  The code calls `write_line (true, ...)` (`src/runner.cpp`, in
  `list_test_case()`), and a probe with `--list --silent` displays the
  list, as `cli.dox` states. Fix: delete "unless the verbosity is
  `silent`".

  Fixed (staged, not committed): `runner.h`: "whatever the verbosity".

- **#8 (fixed) — The Configuration topic overstates the link failure.** [topic]
  `topics/config.dox` lines 21-23: the application and the library "must be
  compiled with the same `..._ENABLED` and `..._DEPRECATED_ENABLED` macros,
  otherwise the link fails". For the second macro, a probe of both
  mismatches links and runs, and the sizes of the main classes are
  identical in both builds. The failure occurs only for an application that
  uses the non-inline deprecated members, as the page of the macro says.
  Fix: state the rule for `..._ENABLED` alone, and refer to the macro page
  for the other.

  Fixed (staged, not committed): `config.dox`: the rule is stated for
  `..._ENABLED`; the deprecated macro only for the non-inline members.

- **#9 (fixed) — Stale description of how the check result is built.** [header]
  The class has a default constructor and a template function `init()`, as
  its own page explains, but `inlines/check-result-inlines.h` lines 21-23
  name "the template constructor" and "the non-template constructor",
  `src/check-result.cpp` lines 22-23 say that "the constructor captures the
  result value", and `expression-formatter.h` line 34 says "at construction
  time". Also, `check-result.h` line 30 says "Both live in the `detail`
  namespace" after four entities. Fix: name `init()`, and write "All live".
  Derived from reading the code.

  Fixed (staged, not committed): `check-result-inlines.h`,
  `check-result.cpp`, `check-result.h`, `expression-formatter.h`: `init()`,
  `start()`, "All live".

- **#10 (fixed) — The reporter source page names the wrong parser.** [header]
  `src/reporter.cpp` lines 25-26: "The command-line options are parsed by
  the runner." They are parsed by the `runner_options` constructor, in
  `src/runner-options.cpp`. The similar `runner.h` line 26 ("processing
  command-line arguments") and the `src/runner.cpp` file comment ("handling
  command-line arguments") are acceptable only through
  `initialise (argc, argv)`. Fix: name `runner_options`.

  Fixed (staged, not committed): `reporter.cpp`: parsed by `runner_options`.
  The wording of `runner.h` and `runner.cpp` was left, being right through
  `initialise (argc, argv)`.

- **#11 (fixed) — The `src` folder page says that `runner-options.cpp` reports the
  errors.** [topic] `folders/src.dox` lines 15-16: "the reporting of the
  option errors". The constructor only records them, and writes nothing
  (`add_error()`, and the file comment "the recording of the errors it
  finds"); the runner reports them. Fix: "the recording of the option
  errors".

  Fixed (staged, not committed): `src.dox`: "the recording of the option
  errors".

- **#12 (fixed) — `math-inlines.h` lists functions that are elsewhere.** [header]
  The file comment (lines 24-28) lists the exponentiation and the
  compile-time parsing of numbers, and "`constexpr` or `consteval`". The
  file defines only `abs()` and `min_value()`; `pow()` and the parsing are in
  `deprecated-inlines.h`, as `math.h` correctly says. Fix: reduce the text
  to the two functions, and also delete the reference to the literals.

  Fixed (staged, not committed): `math-inlines.h`: reduced to `abs()` and
  `min_value()`.

- **#13 (fixed) — The `reflection` pages promise a file name function.** [header]
  `reflection.h` lines 29-31, and the namespace description ("utilities for
  extracting file names from paths"). The only such function in the
  namespace is the deprecated `short_name()`, which exists only with the
  deprecated definitions enabled; the current one is
  `utility::extract_file_name()`. Fix: delete it from the two descriptions.

  Fixed (staged, not committed): `reflection.h`: the file name function was
  removed from both descriptions.

- **#14 (fixed) — `--help` does not write one line for each option.** [header]
  `runner-options.h` line 462. The output (probe) has one line for
  `--verbose | --quiet | --silent`, and six lines for `--filter`. Fix: "the
  usage and the list of the options", as `cli.dox` says.

  Fixed (staged, not committed): `runner-options.h`: "the usage and the list
  of the options".

- **#15 (fixed) — The list is not the same with both reporters when it has an
  error.** [topic, header] `cli.dox` lines 314-318 and `runner-options.h`
  line 444 say "the same with both reporters", and "an `error:` line". A
  probe writes `error: ...` with the human-readable reporter, and
  `# error: ...` with the TAP one. Fix: "(the error is written in the list,
  as an `error:` line, or a `# error:` comment with the TAP reporter, and
  on `stderr`)".

  Fixed (staged, not committed): `cli.dox` and `runner-options.h`: the `#
  error:` comment of the TAP reporter.

- **#16 (fixed) — Placeholder in the `test_each()` examples.** [header] `test.h`
  lines 1533 and 2233: `[] (auto& t, const auto& value) { ... }`, which does
  not compile. The body exists in `test-case.dox`. Fix: use
  `{ t.expect (mt::eq (value, value)); }`.

  Fixed (staged, not committed): `test.h`: both examples have a body now.

- **#17 (fixed) — Examples with names that do not resolve in application
  code.** [header] `deprecated.h` lines 1545 (`to_i{x}`) and 1880
  (`to_t<MyType>{obj}`), and `src/utility.cpp` line 89
  (`utility::extract_file_name (path)`) have neither the `mt::` prefix nor a
  using-directive, unlike all the other examples. With the prefix they
  compile (probe). Fix: add `mt::`.

  Fixed (staged, not committed): `deprecated.h` and `utility.cpp`: `mt::`
  prefix, with the alias line.

- **#18 (fixed) — Unmatched tag in the note of the home page.** [config]
  `website/config/doxygen2docusaurus.json` lines 23 and 46:
  `.../doxygen/*.html</b></a>`. There is no opening `<b>`. Fix: add the
  opening `<b>` (or delete `</b>`).

  Fixed (staged, not committed): `website/config/doxygen2docusaurus.json`:
  both notes have the opening `<b>` now. The example in the documentation
  of `doxygen2docusaurus-cli-ts` (`website/docs/user/_project/
  _content.mdx` line 119) had the same typo, and is the source of the
  copies; the maintainer corrected it there in the same way.

- **#19 (fixed) — Two deprecation notes on `to_t`.** [header] `deprecated.h`,
  `struct to_t`: both the attribute and a `@deprecated` command are
  shown, one after the other, with different texts. Fix: keep one text, in
  the attribute, and delete the command.

  Fixed (staged, not committed): `deprecated.h`: the `@par Deprecated` of
  `to_t` became `@par Replacement`, with no second deprecation text; the
  attribute keeps the text.

## 2. Missing information

- **#20 (fixed) — The exit code list omits the output file.** [topic]
  `topics/cpp-api/runners.dox` lines 31-32. An output file that cannot be
  opened also gives 2 (probe, and `cli.dox`). Fix: "2 when the command line
  had an error, when the output file could not be opened, or when the
  filters selected no test case".

  Fixed (staged, not committed): `runners.dox`.

- **#21 (fixed) — The list of the option members omits `help`.** [topic]
  `runners.dox` lines 110-113 give the members of `runner_options`, without
  `help`. Fix: add "the display of the usage".

  Fixed (staged, not committed): `runners.dox`: "the display of the usage".

- **#22 (fixed) — The trace macros need a header that is not mentioned.** [topic]
  `topics/config.dox` line 23 ("only add trace calls"), and both
  `macros/*trace*.dox`. Without `micro-os-plus/diag/trace.h` in the include
  path, a program defining `..._TRACE_ENABLED` fails to compile, with "use
  of undeclared identifier 'trace'" in `test-inlines.h` (probe). Fix: state
  that these macros need that header, from the µOS++ `diag-trace` package.

  Fixed (staged, not committed): `config.dox` and the two trace macro pages.

- **#23 (fixed) — The trap of `using namespace std` also applies to `negate()`.**
  [topic] `logical-functions.dox` lines 33-36 name only `all_of()` and
  `any_of()`. With both using-directives, `negate (eq (1, 1))` is rejected:
  "reference to 'negate' is ambiguous", because of the `std::negate` class
  template (probe). Fix: add a sentence, and write `mt::negate()` there.

  Fixed (staged, not committed): `logical-functions.dox`.

- **#24 (fixed) — "The limit included" is not reliable for decimal values.** [topic]
  `function-comparators.dox` line 81. `mt::approx (1.0, 1.1, 0.1)` fails
  (probe), since the computed distance is slightly above 0.1. The sentence
  is true for the computed values, but a reader expects the opposite. Fix:
  add "for floating-point values, the distance is computed, so it may be
  rounded above a limit such as 0.1; do not rely on the exact limit".

  Fixed (staged, not committed): `function-comparators.dox`.

- **#25 (fixed) — The Deprecated topic omits several definitions.** [topic]
  `deprecated.dox`, "Other deprecated definitions", against the Deprecated
  List: `mut()`, `runner::name()`, `expression_formatter::c_str()` and
  `empty()` (public through the alias), the
  `runnable_base::children_subtests_count()`, `current_subtest_index()`,
  and `own_index()` members, and `extension::has_epsilon`. Fix: add them,
  with their replacements.

  Fixed (staged, not committed): `deprecated.dox`: five bullets added, and
  `mut()`, `runner::name()`, `c_str()`/`empty()`, the three index members,
  and `has_epsilon` with their replacements.

- **#26 (fixed) — The runner topic does not mention the abort and the session
  accessors.** [topic] `runners.dox`. `runner::abort()`,
  `set_abort_handler()`, which embedded applications need, `totals()`,
  `is_listing()`, and `verbosity_level()` can be found only on the class
  page. Decision for the maintainer: add a short section with links, or
  accept the single link to the class.

  Fixed (staged, not committed): `runners.dox`: two sections, "Aborting the
  session" and "Reading the session", with links to `abort()`,
  `set_abort_handler()`, `totals()`, `verbosity_level()`, `is_listing()`, and
  `application_arguments()`.

## 3. Structure and presentation

- **#27 (fixed) — The headings of the named member groups lack the
  parentheses.** [converter] In the "Deprecated Functions" sections, the
  headings are `expect`, `require`, and `children_subtests_count`, while
  all the others are `test()` and `name()`. The table of contents shows the
  same difference. Fix: use the same heading for all the functions.

  Fixed (not committed) in `doxygen2docusaurus-cli-ts`, `src/docusaurus/
  view-model/members-vm.ts`: whether a member is a function was decided
  from the kind of its section, which is `user-defined` for the `@name`
  groups; the kind of the member is used now. A run of the rebuilt converter changes the
  headings of 12 pages, all of deprecated functions, and nothing else. The
  pages need a regeneration after the release.


- **#28 (fixed) — Two or three sections named "Deprecated Functions" on a page.**
  [header] `test_case`, `suite`, and `top_suite` have two, and
  `static_suite` has three, since each class and the inherited
  `runnable_base` have a `@name Deprecated Functions` group (`test.h` lines
  475, 1741, 2294, and 2697). Decision for the maintainer: name the group of
  the base class differently ("Deprecated Functions of the base class"), or
  have the converter merge the sections with the same title.

  Fixed (staged, not committed): `test.h`: the groups of `runnable_base` and
  `suite` are named "Deprecated Functions of runnable_base" and "Deprecated
  Functions of suite", so that the titles on every class page are different.

- **#29 (accepted) — The deleted members come first in the constructors.** [converter]
  On the `runner` page, the two deleted constructors precede `runner (void)`,
  the only one that a user needs; on the `static_suite` page, the useful
  constructor is between the two deleted ones; and on the `suite`,
  `top_suite`, and `test_case` pages, the deleted ones are the only public
  constructors listed. Decision for the maintainer: sort the deleted members
  last in the converter, or accept the alphabetical order.

  Accepted: the maintainer keeps the order of Doxygen, which sorts the
  overloads by name and then by argument string, and the converter keeps it;
  the deleted constructors are short entries, and the useful one is among the
  first.

- **#30 (fixed) — The deprecated functions come first on the main namespace page.**
  [header] On `micro_test_plus`, the "Functions Index" starts with `_and()`,
  `_not()`, and `_or()`, and has `approx (value, epsilon)` and `mut()` among
  the current functions. The wrappers already have their own group ("Type
  Wrappers"). Decision for the maintainer: put these functions in a `@name
  Deprecated Functions` group in `deprecated.h`.

  Fixed (staged, not committed): `deprecated.h`: `_not()`, `_and()`, `_or()`,
  `mut()`, and the deprecated `approx (value, epsilon)` are in a `@name
  Deprecated Functions` group (two blocks, which Doxygen merges into one
  section); the namespace page has a "Deprecated Functions Index", and its
  "Functions Index" lists only the current functions.

- **#31 (accepted) — The Deprecated topic lists internal entities.** [header] Its
  sections hold `detail::within_tolerance()`, six identical
  `within_tolerance_result` variables, `genuine_integral_value`,
  `value_base_`, `runner_totals`, and `timestamps`, through `@ingroup`,
  which a user has no reason to migrate, since the applications do not name
  them, and they take most of the page. Decision for the maintainer: keep
  them in the Deprecated List only, by removing `@ingroup` from the entries
  of `detail` and `type_traits`.

  Accepted: the maintainer keeps the internal deprecated entities in the
  topic.

- **#32 (fixed) — The Customisation topic does not index what it describes.**
  [header] Its index shows only the `expression_formatter` typedef; the
  templates `compare_op` and `predicate_op` and the concepts of `extension`
  appear only in the text. Fix: add them to the group, if Doxygen and the
  converter support it for the using-declarations and the concepts (not
  tested); otherwise, keep the page as it is.

  Fixed (staged, not committed), partly: `extension.h` and `detail.h`: the
  seven public concepts (`is_op`, `any_op`, `checkable`, `printable`,
  `compare_tag`, `predicate_tag`, and `approx_operand`) have `@ingroup` for
  the Customisation topic, which now has a "Concepts Index" (tested with
  Doxygen and the converter, 0 warnings). `compare_op` and `predicate_op` are
  not listed: Doxygen documents them in `detail`, and the using-declarations
  of `extension` cannot be put in a group; adding the `detail` structs would
  list a `detail::` name that the applications must not use. The text of the
  topic describes them.

## 4. API design

No item. `API-REVIEW-10.md` has 6 problems, all fixed, and the reference
exposed no new design problem besides those that the maintainer has already
accepted.

## 5. Consistency

| #   | Concept | Variants found (where) | Suggested |
| --- | ------- | ---------------------- | --------- |
| #33 (fixed) | Text of the deprecation notes | "use all_of() (since 6.0.0)" (most); "Use std::type_identity (since 6.0.0)." and "To be removed with ... (since 6.0.0)." (`deprecated.h`, `extension.h`); "Not replaced (since 6.0.0)."; "internal to the framework (since 6.0.0)"; "The value wrappers are internal (since 6.0.0)." | Lower case, no final period, as in the attributes, since the compiler prints them: "use all_of() (since 6.0.0)" and "not replaced (since 6.0.0)" |
| #34 (fixed) | How a file page says that it is not included directly | "This file is included by micro-test-plus.h, which is the header that the applications include." (most); "intended for internal use within the framework and should not be included directly by user code" (`deprecated.h`, `extension.h`, although they hold names for the applications); "Users should include ..." (`exceptions.h`); "included through micro-test-plus.h and should not be included directly" (`counters.h`, `runner-options.h`); none (`utility.h`, some `inlines/`) | The first form, on all the headers |
| #35 (fixed) | Parts of a string | "sub-string" (8 in the sources, 1 in the topics); "substring" (5 in `inlines/utility-inlines.h` and others) | "sub-string" |
| #36 (fixed) | What the operators accept | "framework type" (22, the operator pages); "framework expression type" and "framework expression" (17, `extension.h`); "framework expression or value wrapper" (`deprecated.h`), all for `extension::is_op` | "framework expression type", since this is the name in `extension.h`; decision for the maintainer |
| #37 (fixed) | The deprecated wrappers | "value wrapper" (21); "type wrapper" (8); "wrapper" (topics) | "value wrapper", keeping the "Type Wrappers" group name only if the group is not renamed |
| #38 (fixed) | Mood of the briefs | "Reject a suite ...", "Insert a static suite ...", "Insert this suite ..." (`runner.h` lines 1051 and 1111, `test.h` line 2796); all the others in the third person | "Rejects" and "Inserts" |
| #39 (fixed) | Accessor briefs | "Gets the totals", "Gets the node name", "Gets the command-line arguments"; "Returns the count", "Returns the verbosity level" (all in `runner.h` and `test.h`) | "Returns" |
| #40 (fixed) | Functions without parameters | "Parameters: None." on most; absent on `runner_options::has_errors()` and `has_unknown_option()`, and on `runner::has_option_errors()` | Add it, as on the other functions |

Fixed (staged, not committed): #33 the `@deprecated` texts of
`deprecated.h`, `detail.h`, and `extension.h` start in lower case, with no
final period; #34 the sentence of `runner.h` is now in `deprecated.h`,
`extension.h`, `exceptions.h`, `counters.h`, `runner-options.h`, and
`utility.h`, and in the three inlines that lacked it; #35 `utility-inlines.h`;
#38 `runner.h` and `test.h`; #39 every `@brief Gets` is now
`@brief Returns`; #40 `@par Parameters None.` added to `has_errors()`,
`has_unknown_option()`, and `has_option_errors()`; #36 "framework
expression type" is used for every mention of `extension::is_op` (`deprecated.h`,
`deprecated-inlines.h`, `detail-inlines.h`, `test.h`, `extension.h`, and the
two deprecated topics); #37 "value wrapper" is used everywhere, and the group
"Type Wrappers" of `deprecated.h` is now "Value Wrappers" (also in
`CLAUDE.md`, `deprecated.dox`, and the macro page).

## 6. Language and style

- **#41 (fixed) — Briefs of two sentences.** [header] `deprecated.h` line 936 and
  the eight operators after it ("Deprecated equality operator. Matches only
  if at least one operand is a framework type ..."), and line 441 ("Default
  constructor. Initialises the base with `N`."), which is also published
  through `type_traits`. They are repeated in every index. Fix: move the
  second sentence to `@details`.

  Fixed (staged, not committed): `deprecated.h`: the nine operator briefs
  have one sentence (the condition is in the `@details` of the inlines), and
  so has the `integral_constant` constructor.

- **#42 (fixed) — "Within the µTest++ framework".** [header] 15 occurrences in the
  sources, 21 on the pages, and in most of them it adds nothing. In
  `inlines/exceptions-inlines.h` lines 87 and 106 it is wrong: "verifies
  whether invoking the provided callable object results in the throwing of
  any exception within the µTest++ framework"; the exception is thrown by the
  code under test. Fix: delete the phrase, and write "checks whether the
  callable throws".

  Fixed (staged, not committed): `exceptions-inlines.h`; the other
  occurrences, in file comments, were left.

- **#43 (fixed) — Evaluative and filler sentences.** [header] `deprecated.h` lines
  918-920: "ensuring a modular and maintainable codebase"; line 893:
  "Please be aware that"; `detail.h` line 1168: "ensuring consistent
  reporting throughout the framework". Counts: "ensuring" 7, "lightweight" 5,
  "This is useful" 3, "particularly useful" 2, "flexible" 2. Fix: delete the
  sentence from the `operators` namespace, and use the plain statement of
  fact in the others. `top-common.h` has a similar sentence ("to ensure a
  consistent and modular structure"), which is a **[template]** fix.

  Fixed (staged, not committed): the `operators` paragraph and the `Please be
  aware`, the two `ensuring` of `detail.h`, and `particularly useful` were
  removed. The other `ensuring` (`extension.h`, two in `deprecated.h`) are
  accurate and were kept; the `top-common.h` sentence is a [template] fix,
  not done.

- **#44 (fixed) — `__PRETTY_FUNCTION__` is not a macro.** [header] `reflection.h`
  lines 32-33, the namespace description, and `reflection-inlines.h` line 122:
  "compiler-specific `__PRETTY_FUNCTION__` macro". It is a predefined
  identifier. Fix: "compiler-specific `__PRETTY_FUNCTION__` identifier".

  Fixed (staged, not committed): `reflection.h`, `reflection-inlines.h`:
  "identifier".

- **#45 (fixed) — The `check-result-inlines.h` file comment mentions "expectation
  messages".** [header] Line 22: the same messages apply to both kinds of
  checks. Fix: "the messages of the checks".

  Fixed (staged, not committed): `check-result-inlines.h`, together with #9.

- **#46 (fixed) — A long prose line in a topic source.** [topic]
  `pages/mainpage.dox` line 58 has 120 characters. The other lines over 80
  in the `.dox` files are the group definitions and the sample outputs,
  which cannot be wrapped. Fix: wrap the line.

  Fixed (staged, not committed): `mainpage.dox`.

- **#47 (accepted) — Three comment lines of 80 characters.** [header] `deprecated.h`
  lines 795, 813, and 834, reported by the style check: the `@ingroup` line
  of the longest group name, which cannot be wrapped. Decision for the
  maintainer: accept them, or shorten the group name
  `...-deprecated-logical-functions`.

  Accepted: the maintainer accepts the three lines of 80 characters.

## 7. Proposed topic tree

No change is proposed. The order of the topics follows the task of the
reader (runner, suites, test cases, checks, conditions, utilities,
customisation, deprecated), with the configuration and the command line
one level above, as the "µTest++" topic explains.

## 8. Incidental observations in the code

No item. No code defect was found; the problems reported above are in the
documentation or in the converter.

## 9. Reviewed and found correct

- The home page and the examples of `mainpage.dox`, `runners.dox`,
  `test-suites.dox` (compiled as two translation units), `test-case.dox`,
  `expectations.dox`, `requirements.dox`, `function-comparators.dox`,
  `logical-functions.dox`, `exceptions.dox`, `utility-functions.dox`,
  `customisation.dox`, and `c-api.dox`, compiled with `-Wall -Wextra
  -Wpedantic -Wshadow` without warnings, and run where a result is claimed;
  the examples of the deprecated topics, compiled without these flags, and
  with the deprecation warnings disabled.
- Comparator reports: the sample outputs, the mixed-sign integers, the
  characters, the C strings (unterminated arrays, embedded nulls, null
  pointers, wide strings), the byte buffers, the pointers by address, the
  arrays with containers, the copies of the named operands, the 16 elements
  and the index of the first difference, and the `approx()` rules
  (`bool` and character types rejected, negative tolerance, mixed signs).
- Conditions of `expect()`: the rejected string literals, arrays, function
  names, function and member pointers, wrappers of `bool`, and scoped
  enumerations, and which of them the deprecated overloads accept; the
  `auto r`, `auto&& r`, and `value()` statements of the warning.
- Requirements: with exceptions, and without them (the `Bail out!` line,
  no totals, `::abort()`, and the handler), including in quiet mode, and
  `require()` inside the callable of `throws()` and `nothrow()`.
- `cli.dox`: all the options and their spellings, the end of the options,
  `--`, the errors and their exit codes, `--help` priority, the colours,
  the verbosity levels, the output file (truncation, empty path, failure to
  open), the filter examples, and the list, against the `sample` and
  `minimal` programs and the reference files.
- Suites: the execution order (byte order, equal names, top suite first),
  the rejected calls, the misdirected test cases, and the session with no
  suite; several runners were not probed, but the unit tests cover them
  (`tests/sources/unit-miscellaneous/src/miscellaneous.cpp`).
- Test cases: nested cases, the arguments of the callable, the exceptions
  that escape, `test_each()` on vectors, lists, tuples, arrays, spans, and
  views, and the names of the generated test cases.
- Deprecated definitions: the literal rules (bases, separators, range, the
  19-digit limits, the required decimal point, no exponent), the tolerance
  of the floating-point literals, `"false"_b`, `"name"_b`, and the migration
  example. "since 4.1.0" of the deprecated constructor was checked against
  the `v4.1.0` tag.
- Configuration: the guard of `MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED`, in the
  headers and the library sources, and the `__has_include` of the
  configuration headers in the public headers.
- The link of the home page note to `/doxygen/topics.html`, and the links of
  `test_case` to the topics that document `expect()` and `require()`.
- The converter fixes of the earlier review: the descriptions of the
  enumerators, and the sentences of the indices, are present on the pages
  (`doxygen2docusaurus` 2.2.7).

  
