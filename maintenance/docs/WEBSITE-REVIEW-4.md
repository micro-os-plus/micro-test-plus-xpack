# Website review

Date: 2026-11-06, on branch `webpreview`, commit `99339c89`; published site
built from `webpreview` commit `99339c89`.

Scope: the whole site published at
<https://micro-os-plus.github.io/micro-test-plus-xpack-webpreview/>: the home
page, every page under `/docs/`, the 26 blog posts and the blog index pages,
the navigation bar, the sidebars, and the footer. Excluded: `docs/api/` (links
into it were checked), and `docs/test/`, which is a draft and is not published.

Method: the 57 pages listed in the sitemap were downloaded with `curl`, and the
text of their `<article>` or `<main>` element was read; no page differs from
the local sources, and no page has `unlisted: true`, so the site was not built
locally. The statements were checked against the headers, the inlines, and the
sources; `tests/expected/`, `tests/sources/`, and `tests/platforms/`;
`CMakeLists.txt`, `meson.build`, `xcdl-package.jsonc`, and
`.github/workflows/`; the scripts and actions of the three `package.json`
files; `npm pack --dry-run`; the git tags, the npm registry, and the GitHub
milestone. The behaviour was checked with probe programs built with Apple clang
17 (`-std=c++20`), including the complete listings of the tutorial and of the
extending page, about 35 accepted and rejected forms, and a CMake project that
links each of the three library targets. The external links were fetched; the
code excerpts of the Contributor's Guide were compared, line by line, with the
sources. The claims about Boost UT and doctest were checked against their
current `ut.hpp` and `doctest.h`; those about the other frameworks were not
checked against their sources. The earlier report, `WEBSITE-REVIEW-3.md`, has
no open items, and neither has `WEBSITE-REVIEW-2.md`; none is carried over. The
decisions recorded in them were not reopened (for example, the preview showing
the unreleased 6.0.0, which is why the `v6.0.0` tag link and the npm links of
6.0.0 are not reported).

Summary: 60 problems (2 open, 58 fixed, 0 withdrawn). The open items are #7
(the code or the page must change, a decision for the maintainer) and #31 (to
re-measure before the release).

## Note on generated files

The files with a `DO NOT EDIT!` header are generated from the templates of the
`@xpack/docusaurus-template-liquid` package, and are regenerated with `npm run
generate-website-commons` in `website/`. The writable checkout is
`~/MyProjects/xpack.github/packages/docusaurus-template-liquid.git`; the copy
in `website/node_modules` was not linked to it when the review started, and is
linked now (see #58). The template paths below are relative to
`templates/docusaurus/common/` in that package. Template problems usually
affect the other µOS++ sites as well. The `_project/` partials, the guide pages
under `docs/user/` and `docs/developer/*/`, the glossary, and the blog posts
are project files, edited in place.

## 1. Defects

- **#1 — The support channel does not exist.** (fixed) [template] The site
  sends all questions and feedback to
  `https://github.com/micro-os-plus/micro-test-plus-xpack/discussions`, which
  returns 404: the repository has Discussions disabled (`gh api
  repos/micro-os-plus/micro-test-plus-xpack` gives `has_discussions: false`).
  The link is in the Help Centre (six times, `docs/support/index-liquid.mdx`),
  in "Support and feedback" of Getting Started
  (`docs/getting-started/_common/_support-and-feedback-liquid.mdx`), and in the
  footer (`docusaurus.config-liquid.ts` line 514). The Help Centre also forbids
  the issue tracker and private email for questions, so a reader who follows it
  has nowhere to ask. Options, for the maintainer: enable Discussions in the
  repository settings, which needs no page change (recommended); or link to the
  organisation discussions,
  `https://github.com/orgs/micro-os-plus/discussions`, which exist, by changing
  the template.

  Fixed: Discussions was enabled in the repository settings; the
  discussions page returns 200, and no page changed.
- **#2 — The deprecated definitions are not simply "still available".** (fixed)
  [project] `docs/user/migrating/index.mdx` line 33: "They are still available,
  but the compiler reports their use." Without
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED`, a program that uses them
  does not compile (a probe gives `no namespace named 'literals'`), and the
  page never names the macro, although this is the first thing a migrating
  reader meets. Write: "They are available only when
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED` is defined, for the
  application and for the library sources; the compiler then reports their use.
  Without it, the programs that use them do not compile."

  Fixed: The paragraph now names the macro, says where it must be
  defined, links the Configuration section, and gives the procedure.
- **#3 — The object and static CMake targets fail at link time.** (fixed)
  [project] `docs/install/_project/_build-and-integration-info.mdx`, "CMake"
  and "CMake library targets": the page says that the three targets differ only
  in how the sources are built, and recommends the object or the static library
  for several executables, but does not say that these targets do not inherit
  the options of the application, or how to select C++20. A probe in which the
  folder of `micro-os-plus/micro-test-plus-defines.h` is on the include path of
  the application only links with the interface target, and fails with
  `Undefined symbols` with the other two, since their sources are compiled
  without the macro and are empty.

  Fixed: The section "CMake language standard" gives `CMAKE_CXX_STANDARD` and
  `CMAKE_CXX_STANDARD_REQUIRED`; the section "CMake common options" explains
  that the object and the static libraries must get the same common options as
  the application, in particular the folder of the defines header and
  `-fno-exceptions`, and shows an interface library of the project linked to
  both, by the real target names, since the aliases cannot be modified. The
  example was built and run with both targets, also with a relative include
  folder, and the failure was reproduced without it. A closing paragraph states
  that the Meson configurations support only the interface approach, so the
  options apply automatically. The section on the static suites moved before
  the build systems, since it applies to both.

- **#4 — `std::unique_ptr` is not a valid operand.** (fixed) [project]
  `docs/user/checks/index.mdx` line 348, `docs/user/extending/index.mdx` line
  276, and the v6.0.0 post line 505 give `std::unique_ptr` as the example of an
  operand that is referred to, since it cannot be copied. It cannot be written
  either, so it is rejected: `mt::eq (p, nullptr)` stops at the `static_assert`
  in `inlines/detail-inlines.h` line 563, and an `extension::predicate_op` with
  a `std::unique_ptr` fails in `expression-formatter-inlines.h` line 492. A
  move-only application type with an `operator<<` is referred to as described
  (probe). Replace the example with "an application type that cannot be copied,
  and has an `operator<<`", and show `mt::ne (p.get (), nullptr)` for a smart
  pointer.

  Fixed: The three passages give an application type with a deleted copy
  constructor as the example, and the checks page states that a smart pointer
  is not a valid operand, with `mt::ne (p.get (), nullptr)` and `t.expect (p)`
  as the alternatives.
- **#5 — The abort example does not compile with a global runner.** (fixed)
  [project] `docs/user/organising-tests/index.mdx` line 222: `[&tr]`, with the
  text "for example captured by reference". Every complete program of the guide
  defines `mt::runner tr;` as a global, for which clang reports `'tr' cannot be
  captured because it does not have automatic storage duration`. Write `[]` in
  the example, and: "A global runner can be used directly; a local one must be
  captured by reference."

  Fixed: The example uses `[]`, and the text says that a global runner can be
  used directly, and a local one must be captured by reference.
- **#6 — The strings of a chain are quoted.** (fixed) [project]
  `docs/user/checks/index.mdx` line 401: `(1 == 1 and abc == abd and 3 < 2)`.
  The output is `(1 == 1 and "abc" == "abd" and 3 < 2)`, as the same page says
  of the strings. Correct the sample.

  Fixed: The sample shows the quoted strings.
- **#7 — The other periods of a duration.** [project, or code]
  `docs/user/checks/index.mdx` line 518: "as `3[1/30]s`". The output with Apple
  clang is `3[1ll/30ll]s`, since `inlines/expression-formatter-inlines.h` lines
  400 and 401 write the ratio as `long long` values, with the suffix. The code
  needs checking first: the page describes the sensible text, so write the two
  numbers without a suffix (in plain mode, or with `append_number()`), and add
  a check to the unit tests.
- **#8 — The exit code of a filter that selects nothing.** (fixed)
  [project]
  `docs/user/organising-tests/index.mdx` lines 138 to 152, "Test result": the
  list of the cases of `2` omits it, while `docs/user/running-tests/index.mdx`
  and `docs/developer/runner/index.mdx` state it, and a probe returns 2 with
  `error: the filters selected no test case`. Add: "If the filters select no
  test case, the error is reported, and the result is 2."

  Fixed: The section states the error and the result 2, also when listing.
- **#9 — The examples name suites that the sample does not have.**
  (fixed) [project]
  `docs/user/running-tests/index.mdx` lines 151 and 172 to 181: the filter
  `Args*|*namespace*` and the list with `Explicit namespace suite` and "4 test
  cases in 2 test suites". The `sample` program
  (`tests/expected/tap/sample-test.tap`) has the suites `Sample` (9 test
  cases), `Args suite`, and `Static suite`, so 12 test cases in 3 suites; a
  reader who runs the command gets another list. Use the real names
  (`Args*|Static*`), and the real list, or a neutral program name instead of
  `sample-test`.

  Fixed: The filter example is `Args*|Static*`, the SKIP example names the
  filter that produces it (`Static*`), and the list is the real output of the
  `sample` program, 12 test cases in 3 test suites; the program was built and
  run for this, with a stub for the platform header.
- **#10 — What doctest does without exceptions.** (fixed) [project]
  `docs/user/checks/index.mdx` lines 252 and 253: "doctest either removes
  `REQUIRE()`, or makes it behave as `CHECK()`". In the current `doctest.h`,
  with `DOCTEST_CONFIG_NO_EXCEPTIONS`, `DOCTEST_REQUIRE` is a `static_assert`
  that fails, so it is not removed; with
  `DOCTEST_CONFIG_NO_EXCEPTIONS_BUT_WITH_ALL_ASSERTS`, it keeps its normal
  definition, and `throwException()` is empty, so it behaves as `CHECK()`.
  Write: "doctest rejects `REQUIRE()` at compile time or, with a configuration
  macro, makes it behave as `CHECK()`".

  Fixed: The page says so. The first version of this item said that the macro
  turns `REQUIRE()` into an empty function; that was wrong, and was corrected
  from a second reading of the source. Both statements come from reading
  `doctest.h`, not from compiling a program.

- **#11 — The installed files omit `LICENSE-Boost`.** (fixed) [project]
  `docs/install/_project/_install-folder-hierarchy.mdx` lines 55 and 74: the
  tree has no `LICENSE-Boost`, which `npm pack --dry-run` includes, and ends
  with "6 directories, 54 files"; `tree -l` on the package content gives "6
  directories, 55 files". Add the file, and correct the count.

  Fixed: The tree lists `LICENSE-Boost`, after `LICENSE`, and ends with "6
  directories, 55 files", as `npm pack --dry-run` reports 55 files.
- **#12 — The reference file is not the output of a `--verbose` run.**
  (fixed) [project] `docs/developer/_project/_test-details.mdx` lines 65 and
  66: "is the output of the `minimal` program, run with `--verbose`". The
  sample itself shows `--reporter=tap --output-file=minimal-test.tap one two`,
  and `tests/platforms/synthetic-posix/cmake/artefacts.cmake` lines 255 and 256
  run it so. The checks are listed because the output file receives them at any
  verbosity. Write: "is the output file of the `minimal` program, which
  receives every check, whatever the verbosity".

  Fixed: The page says that the reference file is the output file of the
  program, run as shown on the first line, and that it receives every check,
  whatever the verbosity of the console.
- **#13 — A stale constraint in the check result excerpt.** (fixed) [project]
  `docs/developer/checks/index.mdx` line 190: `requires
  (extension::printable<T> or detail::lazy_message<T>)`. `check-result.h` line
  318 has `requires detail::message_argument<T>`, as the excerpt in the
  "Messages" section of the same page shows (changed by #266). Correct it.

  Fixed: The excerpt shows `requires detail::message_argument<T>`, as the
  "Messages" section of the page does.
- **#14 — A stale constraint in the `eq()` excerpt.** (fixed) [project]
  `docs/developer/comparators/index.mdx` lines 221 and 222 show the two
  conditions, under "(simplified)"; `function-comparators.h` lines 131 and 132
  have `detail::comparable_operands`, which the text below then introduces as
  something else. Show the real constraint and the second overload, and start
  "The constraints at the call site" with what `comparable_operands` joins. In
  the same page, lines 151 and following show `std::cmp_equal (lhs, rhs)` for
  `std::cmp_equal (as_comparison_integer (lhs), as_comparison_integer (rhs))`,
  the function that the text explains next; show the real call.

  Fixed: The `eq()` excerpt shows the real constraint,
  `detail::comparable_operands`, and the excerpt of `equal_to::apply()` shows
  its `as_comparison_integer ()` conversions. The second overload is not added
  to the excerpt, since the text below it already describes it, together with
  the concept.
- **#15 — The description of the reporter predates v6.0.** (fixed) [project]
  `docs/user/_project/_content.mdx` lines 61 to 66: "with each test on a
  separate line", and "Optionally, the detailed test results can be written to
  a separate file, for example in TAP format". At the default verbosity, passed
  checks are not displayed, and TAP is already the default on the console.
  Write: "The **reporter** writes the results on `stdout`, in TAP format by
  default: one line for each passed test case, and, for the failed ones, the
  failed checks, with their location and, where possible, the values of their
  operands. Optionally, the complete report is also written to a file."

  Fixed: The bullet describes the TAP output on `stdout` and the report file,
  with a link to the output file section.
- **#16 — A concept that is no longer in `extension`.** (fixed)
  [project] v6.0.0 post
  line 516: "the new `extension::suspicious_condition` concept". #270 moved it
  to `detail`, so the name does not compile (probe). Remove the clause, or
  write "the arguments are listed in the User's Guide".

  Fixed: The sentence no longer names the concept, which moved to `detail`, and
  lists the rejected arguments.
- **#17 — The character types are not unchanged.** (fixed)
  [project] v6.0.0 post line
  551: "`bool` and the character types are unchanged". Since #272, the
  characters are compared as integers, by value (`mt::gt (U'a', -1)` passes, as
  `docs/user/checks/index.mdx` states). Write "only `bool` is unchanged", and
  add the characters to the sentence.

  Fixed: The sentence says that the characters are compared as integers, and
  that only `bool` is compared as before.
- **#18 — "but but" on the Help Centre.** (fixed) [template]
  `docs/support/index-liquid.mdx` lines 198 and 199 of the writable checkout,
  and `docs/support/index.mdx` lines 120 and 121: "not intended to be
  discourteous, but but to save time". Remove one `but`.

  Fixed: The word is removed in the template of the writable checkout (not
  committed there). The generated `docs/support/index.mdx` is read-only and
  unchanged: it is corrected by the next `generate-website-commons`, which must
  run with the linked template package (see #58).
- **#19 — A time format that the program does not write.** (fixed) [project]
  `docs/user/tutorial/index.mdx`, 10 occurrences: `time: 0.04 ms`. The time is
  written with three decimals (`src/reporter.cpp` line 817), as on the other
  pages. Write `0.040 ms`.

  Fixed: The ten times are written with three decimals, as the program writes
  them.
- **#20 — A missing space.** (fixed) [project]
  `docs/install/_project/_configuration.mdx` line 13: "header
  file,`micro-os-plus/micro-test-plus-defines.h`". Add the space.

  Fixed: The space is added.
- **#21 — What the first filter does to the top suite.** (fixed) [project]
  `docs/user/running-tests/index.mdx` line 162: "its test cases are filtered
  like those of any other suite". A reader takes this to mean only the second
  pattern, but with `--filter=Beta`, all the test cases of a top suite named
  `Top` are skipped (probe), since the first pattern also applies to its name,
  as `docs/developer/runner/index.mdx` says. Add: "A first pattern that does
  not match its name skips all its test cases."

  Fixed: The paragraph says that the first pattern also applies to the name of
  the top suite.
## 2. Version history

- **#22 — The release post omits 22 issues.** (fixed)
  [project] v6.0.0 post, "Major
  changes", "Bug fixes", and "Enhancements": the lists stop at #258; the
  issues #259 to #280 of the 6.0.0 milestone, 22 of them, are in no list, since
  the post was last changed on 2026-11-04. Add them; #261, #264, and #270
  change what compiles, so they belong to "Major changes".

  Fixed: The 22 issues are added to the lists: #261, #264, and #270 to "Major
  changes", the bugs to "Bug fixes", and the enhancements to "Enhancements".
- **#23 — The detailed changes omit the changes made after #258.** (fixed)
  [project]
  v6.0.0 post, "Detailed changes", which is what the compatibility notice sends
  the readers to. Missing or out of date:
  - the wrappers of a `bool` are rejected (#264), while line 363 lists
    `std::optional`, `std::unique_ptr`, and `std::shared_ptr` as accepted,
    without this exception;
  - a test case started on another suite, or on an outer test case, is rejected
    (#261); lines 591 to 594 describe only the nesting;
  - the wide and Unicode strings are compared by content and written as text
    (#260, #278), while line 552 lists only the `char` types;
  - the arrays are compared by element value (#276), and a full `char` array is
    read only within its bounds (#271);
  - the `operator<<` of an application enumeration or range is written in plain
    mode (#273);
  - a rejected call is written in the report (#274), and errors while listing
    change the exit code (#277, #280);
  - the TAP file name is double-quoted when needed (#269).

  Fixed: The detailed changes list the wrappers of a `bool`, the rejected test
  cases and calls, the wide and Unicode strings, the arrays, the application
  operators, the listing errors, and the TAP file name.
- **#24 — The link to `diag-trace` was removed without a notice.** (fixed)
  [project]
  v5.0.1 links `micro-os-plus::diag-trace` in CMake, and
  `micro_os_plus_diag_trace_dependency` in Meson (`git show
  v5.0.1:CMakeLists.txt` line 91, `meson.build` line 68); `cef82bb4`
  (2026-11-02) removed both. An application that uses the trace functions
  through this library must now link the package itself, as
  `docs/install/_project/_build-and-integration-info.mdx` says, but the v6.0.0
  post does not mention it, and the v5.0.0 post ends with "the CMake targets
  still link" it. Add it to "Changes that break the compilation".

  Fixed: The change is listed under "Changes that break the compilation".
- **#25 — `--help` and `is_listing()` are not listed as new.** (fixed)
  [project] The
  History page lists `--help`, but the v6.0.0 post (introduction and "New
  features") and the notice in
  `docs/getting-started/_project/_compatibility-notices.mdx` do not, and the
  post does not mention `runner::is_listing()`. An application with its own
  `--help` or `-h` is also affected, so they belong to the sentence at line 343
  about the options that an application must rename.

  Fixed: The post (introduction and new features) and the notice list `--help`,
  and the post describes `runner::is_listing()` and the options that an
  application must rename.
- **#26 — The History page is out of date.** (fixed) [project]
  `docs/project/history/_project/_content.mdx`: line 49 says "seven successive
  reviews, between 12 October and 1 November 2026", but `maintenance/docs/` has
  ten API reviews, up to 5 November; line 58 says "223 GitHub issues", but the
  milestone has 245; and the heading at line 46, "October 2026 (v6.0)", is the
  only one that does not use the month of the release (the post is dated
  November 2026). Avoid the numbers that change until the release: "in
  successive reviews, from 12 October 2026", and "registered as GitHub issues";
  change the heading when the release date is known.

  Fixed: The page no longer gives the number of the reviews and of the issues,
  and the first review date is kept. The heading "October 2026 (v6.0)" is
  unchanged until the release date is known.
- **#27 — Two damaged issue titles.** (fixed)
  [project] v6.0.0 post lines 202 and 204:
  "Three names for a test case & subtest_index\` counts TAP test points" and
  "The timing vocabulary is inconsisten". The titles on GitHub are damaged in
  the same way. Correct both.

  Fixed: The two titles are corrected in the post. The titles of #69 and #71 on
  GitHub were not changed.
- **#28 — The notices are not only for the major releases.** (fixed) [project]
  `docs/getting-started/compatibility-notices/index.mdx` lines 3 and 26, and
  `docs/getting-started/index.mdx` line 72: "The breaking changes introduced in
  each major release". The page also has v4.1 and v3.3, and the v3.3 entry
  breaks nothing. The v6.0 entry also lists new features. Write "The changes
  that affect existing code in each major and minor release".

  Fixed: The notices page (front matter and introduction) says "the changes
  that affect existing code". The template sentence of Getting Started is
  changed in the writable checkout (not committed there); the generated page is
  read-only and follows with the next regeneration (see #58).
## 3. Structure

### User's Guide

- **#29 — No list of the command line options.** (fixed) [project]
  `docs/user/running-tests/index.mdx` describes the parsing rules first, but
  has no list of the options, and never mentions `--help` or `-h` (they are
  only in "Test result" on the Organising page, and in the FAQ); `--reporter`
  is mentioned only in the section on the human-readable reporter. The reader
  must go to the API page. Add, after the first paragraph, a table from the
  output of `--help`, with a link to the section of each option.

  Fixed: The page starts with a table of the options, each linked to its
  section.
- **#30 — The Migrating page covers only one of the changes.** (fixed)
  [project]
  `docs/user/migrating/index.mdx`: the title promises migration, but a v5.0.1
  program first fails on other things: `auto& ts = tr.initialise (argc, argv)`,
  `run()` and `exit_code()`, `subtest`, `assume()`, and the name given to the
  runner constructor. These are only in the release post, two links away
  (through the notice). Add a first section, "From v5.x", with these
  replacements and a direct link to [Detailed
  changes](/blog/2026/11/03/micro-test-plus-v6-0-0-released/#details).

  Fixed: The page has a first section, "From version 5.x", with the
  replacements that a program meets first, and links the detailed changes of
  the release post.
- **#31 — The sizes and the stack were measured before later changes.**
  [project] `docs/user/embedded-targets/index.mdx` lines 54 to 58 and 127: the
  values come from `f3b568f3` (2026-11-03) and earlier, while the code that
  runs a test case changed after that (for example #263, 2026-11-04, and the 22
  issues of #22). The page says "Built with µTest++ 6.0.0". The values were not
  re-measured for this review, so they may still be close; re-measure them on
  Cortex-M7F, Cortex-M33, and AArch64 before the release.

### Getting Started

- **#32 — The feature list predates v6.0.** (fixed) [project]
  `docs/getting-started/_project/_features.mdx`: it does not mention the custom
  comparators, `test_each()`, the filter, the listing, or the builds without
  exceptions, which matter to an embedded reader. "Test suites and test cases,
  which may be nested" reads as if the suites could be nested. Add one line for
  each, and write "Test suites, and test cases that may be nested".

### Contributor's Guide

  Fixed: The list names the parametrised tests, the custom types and
  comparators, the selection and listing, and the builds without exceptions,
  and says "test cases that may be nested".
- **#33 — The Raspberry Pi Zero 2 W platforms are listed as usable.** (fixed)
  [template, from `tests/config/tests-templates.json`]
  `docs/developer/_common/_content.mdx`, "Target platforms": the two platforms
  are among those that "are built for physical boards", while `CLAUDE.md` says
  that they are "not yet functional". A decision for the maintainer: mark them
  on the page, or remove them from the configuration until they work.

  Fixed: The page has a note under the target platforms that the Raspberry Pi
  Zero 2 W platforms are work in progress. The note is in the generated
  `docs/developer/_common/_content.mdx`, so it must also be in its template to
  survive the next regeneration; its text says "platforms is", which should be
  "platforms are".
## 4. Consistency

| # | Concept | Variants found (where) | Suggested |
| --- | --- | --- | --- |
| #34 | the colour option | `--colour` as the main name (`running-tests`, FAQ, notices); `colour` to `--color` (or `--use-colour`) (`organising-tests` line 72) | `--colour` (or `--use-colour`) (fixed) |
| #35 | the second reporter | "human-readable reporter" (site); "human reporter" (FAQ lines 27 and 28; v6.0.0 post lines 341 and 663, which WEBSITE-REVIEW-2 #75 missed) | "human-readable reporter"; keep the title of #162 (fixed) |
| #36 | adding a suite | "added with `add_suite()`" (User's Guide); "registered with the runner" (FAQ lines 175 and 179) | "added with `add_suite()`" (fixed) |
| #37 | the native hosts | "native POSIX, macOS, and Windows hosts" (`HomepageFeatures/CustomFeatureList.tsx` line 40, although macOS is POSIX); "Linux, macOS, and Windows" (About); "Ubuntu, macOS, and Windows" (CI) | "native Linux, macOS, and Windows hosts"; keep Ubuntu for CI (fixed) |
| #38 | the Google framework | "Google Test" (`user/_project/_content.mdx` line 17); "GoogleTest" (`checks`, FAQ) | "GoogleTest" (fixed) |
| #39 | xpm | "the xPack Project Manager" (`_what-are-xpm-packages.mdx` line 19); "the xPack project manager" (glossary line 66) | "the xPack Project Manager" (fixed) |
| #40 | the build tool | "meson" 9 times (Integration Guide text, Contributor's Guide); "Meson" 2 (the heading, one sentence) | "Meson", except in commands and file names (fixed) |
| #41 | the noun | "command line" 16 times; "command-line" 4 (`user/`) as a noun modifier; the two are mixed in `organising-tests` | "command line" as a noun, "command-line" only before a noun (fixed) |
| #42 | the include form | `<micro-os-plus/micro-test-plus.h>` (home page, `architecture`); `"micro-os-plus/micro-test-plus.h"` (all the others) | `"..."`, as the Integration Guide shows (fixed) |
| #43 | the code of the examples | `main(int argc`, `compute_answer()`, `42+1` (`tutorial`), `tr.add_suite("External suite"` (`organising-tests`), against `main (int argc` elsewhere | the `clang-format` style of the project, as in the other examples (fixed) |

Notes on the fixed rows: #35 leaves the title of issue #162, which says "human
reporter", as it is on GitHub. #40 and #41 were applied in the project files
and, for #40, in the template of the Meson integration (writable checkout, not
committed there); the generated files
`docs/install/_common/_meson-integration.mdx`, `docs/install/index.mdx`, and
`docs/user/index.mdx` are read-only, and follow with the next regeneration (see
#58), which also needs the same change in the template of the description of
the user page. #43 changed only the spacing of the code of the tutorial and of
the Organising tests page.
| #44 | the standard output | "STDOUT" (`user/_project/_content.mdx` line 61); `stdout` (elsewhere) | `stdout` (see #15) (fixed) |

## 5. Language and style

- **#45 — `assume()` is not explained.** (fixed)
  [project] `docs/user/checks/index.mdx`
  lines 254 and 255: "as with the previous versions of `assume()`"; this page
  does not otherwise name the function. Write "as `require()`, then named
  `assume()`, did before v6.0".

  Fixed: The sentence says that `require()`, then named `assume()`, did the
  same before version 6.0.
- **#46 — "Tests" for the checks.** (fixed)
  [project] `docs/user/_project/_content.mdx`
  lines 50 to 51, 61 to 64, and 68: "test conditions (also referred to as tests
  or checks)", "with each test on a separate line", "no failed tests". A test
  is a test case, or a program, elsewhere on the site. Write "checks" here, and
  drop "tests" from the definition.

  Fixed: The definition says "checks" and links the Glossary for the test
  conditions, and the summary sentence says "no failed checks".
- **#47 — The same rule twice in one section.** (fixed) [project]
  `docs/user/checks/index.mdx`, lines 64 and 139: the returned object must not
  be named, stated first in the introduction of the section, and again in a
  longer form, 75 lines later. Keep the first with a link to a single, later
  explanation.

  Fixed: The introduction says that the object must not be named, with a
  pointer to the explanation below, which keeps the full rule.
- **#48 — Bare issue numbers in the guide.** (fixed) [project]
  `docs/developer/formatter/index.mdx` line 236 "(#279)", and
  `docs/developer/test-cases-and-suites/index.mdx` line 370 "(#280)": the only
  two in the guide, and not links. Remove them, or link them.

  Fixed: The two numbers are removed.
- **#49 — An example that needs C++23.** (fixed)
  [project] `docs/user/checks/index.mdx`
  line 167: `std::expected`, on a site that gives C++20 as the requirement. Say
  "(C++23)", or use `std::optional` with a separate error string.

  Fixed: The example has a comment that `std::expected` requires C++23.
- **#50 — Lines not rewrapped.** (fixed)
  [project] Text lines over 80 characters:
  `user/checks` 263, 265, 374, and 410; `user/extending` 55 and 137;
  `user/migrating` 66 and 68; `user/organising-tests` 170 and 332;
  `user/running-tests` 286; `developer/comparators` 377 and 580;
  `developer/formatter` 165; and `developer/reporters` 293. Rewrap them.

  Fixed: The five paragraphs that could be rewrapped (`checks`, `extending`,
  `organising-tests`, and two in `comparators`) are rewrapped. The other lines
  are API reference links, which cannot be broken, and lines inside code
  blocks.
- **#51 — Inflated vocabulary.** (fixed)
  [template and project] Remaining occurrences,
  outside the API pages: "straightforward" 10 (8 in the template text of the
  blog posts, and `getting-started/_project/_overview.mdx` and
  `_features.mdx`), "facilitate" 4, "employs" 2, "subsequently" 2, "whilst" 2,
  "amongst" 1. Use "simple", "help", "uses", "later", "while", and "among";
  leave the older posts, which are records.

  Fixed: The project files use "simple", "while", and "report"; the occurrences
  in the generated pages (the templates `_get-project-sources`,
  `_code-formatting`, `_release-schedule-continuous`,
  `_symbolic-links-require-ntfs`, the support page) are shared by the other
  sites, and the older release posts are records, so they are left as they are.
- **#52 — A list that loses its punctuation.** (fixed) [template]
  `docs/install/_common/_installation-details.mdx` lines 13 to 21: the first
  item ends in `;`, and the second has no punctuation. Add the `;`.

  Fixed: A `;` is added in the template of the writable checkout (not committed
  there); the generated page is read-only and follows with the next
  regeneration (see #58).
- **#53 — Mixed dashes in a list.** (fixed) [project]
  `docs/install/_project/_configuration.mdx` lines 7 to 10: one item uses `–`,
  and three use `-`. Use the same one.

  Fixed: The four items use the same dash.
## 6. Proposed restructuring

- **#54 — Make "Rejected calls" a section of the runner.** (fixed)
  `docs/user/organising-tests/index.mdx` line 624: a level-4 heading under
  "Non-static test suites", although it covers the second `initialise()`, the
  top suite, and the static suites, which link to it. Move it to a level-3
  section after "Test result".

  Fixed: "Rejected calls" is a level-3 section at the end of "Test runner",
  with the reference link of the runner. The paragraph on the names of the
  suites, which was under it, is back in "Non-static test suites".
- **#55 — Move "Aborting the test execution" to the end of the page.** (fixed)
  `docs/user/organising-tests/index.mdx` lines 153 to 295: 140 lines on an
  uncommon case, before "Test cases", which a reader of the page came for. Move
  it after "Test suites", as a level-2 section, with a pointer from "Test
  result".

  Fixed: "Aborting the test execution" is a level-2 section at the end of the
  page; its anchor is unchanged, so the links from the other pages still work.
  "Test result" points to it.
- **#56 — Put the common types before the details of the operands.** (fixed)
  `docs/user/checks/index.mdx`: "Function comparators" (lines 269 to 376) gives
  eight paragraphs on arrays, `volatile`, signedness, and the copies of the
  operands before "Strings" and "Containers" (lines 463 and 475), the sections
  that most readers need. Keep the declarations and `approx()` under "Function
  comparators", follow with "Strings", "Containers", and "Other standard
  types", and collect the rules into a new section, "How the operands are
  compared and stored", after them.

  Fixed: The declarations and `approx()` stay under "Function comparators",
  which points to a new last section, "How the operands are compared and
  stored", with the rules of the strings, arrays, `volatile` operands,
  integers, wide strings, rejections, copies, and smart pointers. "Strings",
  "Containers", and "Other standard types" now come before it.
- **#57 — Move the comparison with other frameworks.** (fixed)
  `docs/user/checks/index.mdx` lines 225 to 268: a level-3 section in the
  middle of the description of the checks. Move it to the end of the page, or
  to the FAQ answer that already links to it.

  Fixed: The section is now the last of the page, at level 2, with the same
  anchor; the "Requirements" section points to it, and the reference links of
  the expectations and requirements stay where they were.
## 7. Incidental observations outside the website

- **#58 — The installed template package is older than the published pages.**
  (fixed)
  `website/node_modules/@xpack/docusaurus-template-liquid` is a directory
  installed from `github:xpack/docusaurus-template-liquid`, not a link. The
  writable checkout is 3 commits ahead of `origin/master`, with 4 uncommitted
  files. The installed copy lacks, for example, the `hasCustomDeveloperSidebar`
  support of `docs/developer/index-liquid.mdx`, and has the older text of the
  Help Centre ("Utilise"), so running `generate-website-commons` as it stands
  would revert those pages. Commit and push the template changes, or run `npm
  run npm-link-helpers` in `website/`, before regenerating. The page is not at
  fault.

  Fixed: The package in `website/node_modules` is now a link to the writable
  checkout, so `generate-website-commons` uses the current templates, including
  the template changes of this review (#18, #28, #40, and #52). The checkout is
  still 3 commits ahead of `origin/master`, with uncommitted changes, which
  must be committed and pushed before the other µOS++ sites regenerate their
  pages. The generated pages of this site, which are read-only, were not
  regenerated.
- **#59 — Issue #258 is not in the milestone.** (fixed)
  The v6.0.0 post lists it under "Bug fixes", but `gh issue list --milestone
  6.0.0` does not. Assign it, so that the milestone linked from the History
  page is complete.

  Fixed: The issue is assigned to the 6.0.0 milestone, which has 246 issues
  (checked with the GitHub API). The issue itself is still open.
- **#60 — `CLAUDE.md` is out of date on `diag-trace`.** (fixed)
  `CLAUDE.md` line 182 says that the CMake libraries are "depending on
  `micro-os-plus::diag-trace`"; `CMakeLists.txt` no longer links it, and
  `xcdl-package.jsonc` lists it under `optionalDependencies`. Correct the
  instruction file (see #24).

  Fixed: The sentence says that the libraries do not link
  `micro-os-plus::diag-trace`, an optional dependency of the package.

## 8. Reviewed and found correct

- The complete listings of the tutorial and of the extending page: they
  compile, their outputs and all the line numbers match, and the home page
  sample matches the output with `--verbose`.
- The formatter table, the `approx()` report, the `test_each()` names
  (including `Records (#2)`), the nested and stopped test cases, the unexpected
  exceptions, `Bail out!` lines, the abort with `--quiet` and `--silent`, the
  list with and without a filter, the suite order for equal names, the rejected
  calls, and exit codes 0, 1, 2, and `SIGABRT`.
- The accepted and rejected forms of the checks page: the always-true
  arguments, the wrappers of a `bool`, `volatile` arrays and pointers, wide
  strings, arrays against containers, `std::filesystem::path`, `approx()` with
  `bool` and characters, lazy messages, and named results.
- The migration table, with the deprecated functionality enabled.
- The command line parser against `src/runner-options.cpp`: all the option
  forms, the colour synonyms, and the application arguments.
- The code excerpts of the eight internals pages, apart from #13 and #14; the
  header order and the protocol tables.
- The commands: the npm scripts and xpm actions on the Integration,
  Contributor's, and Maintainer's pages exist; the platform lists match
  `tests/platforms/`; CI matches the description of the hosts and toolchains.
- CMake target names, output name, and `EXCLUDE_FROM_ALL`; the Meson dependency
  name; the macros and the `cdlSettings` names.
- The size arithmetic of the Cortex-M7F and Boost UT tables; `std::exit()` and
  the `--list-tests` and `--use-colour` options in Boost UT.
- The release list and tags: every tag has a post, or the omission is explained
  (3.2.1, 4.1.0); the dates agree with npm (the v5.0.0 tag was recreated, as
  WEBSITE-REVIEW-2 records).
- The external links: all were fetched. Apart from #1 and the unreleased
  `v6.0.0` tag, the only failures were sites that refuse automated requests
  (npm, PayPal, Stack Overflow, SVG Repo), which were not checked further.
- The navigation bar, the sidebars, and the footer: all the pages are
  reachable, and the labels match the titles. The links into `/docs/api/` lead
  to the groups they name.
