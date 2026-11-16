# Website review

Date: 2026-11-16, on branch `xpack-development`, commit `b0c4f8a1`;
published site built from `webpreview` commit `b0c4f8a1`.

Scope: the whole published site, except the API reference pages under
`/docs/api/`: the home page, the 31 pages under `/docs/` listed in the
sitemap, the 27 blog posts and the blog index pages, the navigation bar,
the sidebars, and the footer. No page is `unlisted`; the two pages under
`docs/test/` are `draft: true`, and return 404 on the published site, as
intended.

Method: `origin/webpreview` and `HEAD` are the same commit, and the working
tree is clean, so every page was read from the published site, downloaded
with `curl` (the `<article>` element, and the `<main>` element of the home
page), and then from its sources in `website/`, following the imports in
render order. The statements were checked against the headers and `src/`,
the reference outputs in `tests/expected/`, `tests/package.json` (all the 37
`xpm run` actions named on the Contributor's Guide exist), the CMake, Meson,
and xcdl files, `npm pack --dry-run` (55 files), the git tags, the GitHub
workflows, and `tests/sources/benchmarks/footprint-sizes.json` (all the
figures of the Flash, RAM, and Sizes tables of the comparison page were
recomputed from it by a script, and agree). A script looked up every
backticked identifier of the User's and Contributor's Guides in `include/`
and `src/` (all found, except those of the other frameworks), and another
resolved every link into this repository against its tag or branch (all
58 resolve). Probe programs were built natively with clang 17, against the
library sources, to confirm the behaviour of the option errors, of the top
suite, of the empty session, of the verbosity levels, and of the comparators
in `static_assert()`; one more probe, built with the Boost UT 2.3.1 of
`tests/benchmarks-frameworks/`, confirmed #2. The site was not built locally,
since nothing differs from the published version. The earlier report,
`WEBSITE-REVIEW-5.md`, has 7 problems: 5 marked fixed, #7 resolved
meanwhile (its commits are in the `v6.0.0` tag, as `git merge-base`
confirms), and #2 still open, carried over as #10. The extracted text lost
the empty lines of the code blocks and flattened the `<details>` elements,
which caused the withdrawn #23 and the overstated #36; the website-review
skill now warns about it.

Summary: 39 problems (2 open, both partly fixed, 34 fixed, 3 withdrawn).
The ones that gave the reader wrong information, #1 to #5, are fixed. The
two partly fixed ones, #20 and #22, keep the duplicated release steps and
one shared partial, for the reasons given in their notes.

## Note on generated files

Most of the files under `docs/_common/`, `docs/*/_common/`, `blog/_common/`,
`blog/_templates/`, `sidebars.ts`, `docusaurus.config.ts`, the home page
(`src/pages/index.tsx`), and several components carry a `DO NOT EDIT!`
header. They are generated from the `@xpack/docusaurus-template-liquid`
package (`website/node_modules/@xpack/docusaurus-template-liquid/`, a link to
a writable checkout), with `npm run generate-website-commons` in `website/`.
The headers name the templates as `templates/common/...`, while the files are
in `templates/docusaurus/common/...` (see #38). The `_project/` partials, the
guide pages under `docs/user/` and `docs/developer/*/`, the glossary, the
compatibility notices page, the History page, the blog posts, the home page
components `HomepageExample` and `HomepageFeatures/CustomFeatureList.tsx`,
and the custom sidebar files are project files, edited in place.

## 1. Defects

- **#1 — The output file after an option error is described wrongly.** (fixed)
  [project] `docs/user/organising-tests/index.mdx` line 206 says "After an
  option error, or when the output file cannot be opened, no output file is
  created", and `blog/2026-11-09-micro-test-plus-v6-0-0-released.mdx`
  line 714 says the same of the option errors. The code does the opposite,
  since the fix of #232 (listed in the same post): `runner::initialise()`
  keeps the output file path when the options have errors, so the reporter
  opens the file with `"w"`, truncating it, and writes the errors to it
  (`src/runner.cpp`, the comment before `if (options_.has_errors () ||
  options_.help)`). A probe run with `--output-file=out.tap --bogus` creates
  `out.tap` with the `Bail out! unknown option '--bogus'` and the `# Use
  --help ...` lines. `docs/user/embedded-targets/index.mdx` ("Console
  output") and `docs/developer/runner/index.mdx` ("Initialisation") describe
  it correctly. Replace the sentence of the Organising tests page with:
  "After an option error, the output file, if its option was valid, receives
  the error lines, and is truncated, so that it never keeps the report of an
  earlier run; when it cannot be opened, there is no output file." In the
  post, replace "no output file is created" with "the output file receives
  the same lines".

  Fixed: The Organising tests page and the 6.0.0 post now say that the
  output file receives the error lines.

- **#2 — The fatal failure of Boost UT is said to end the program.** (fixed)
  [project] `docs/user/checks/index.mdx` line 536 (table: "the program
  exits") and line 550 ("Boost UT reports the fatal failure and calls
  `std::exit()`, so the remaining tests do not run, as `require()`, then
  named `assume()`, did before version 6.0"), and
  `docs/developer/comparison/index.mdx` line 447 (the same claim). In Boost
  UT 2.3.1, the version measured by the comparison page, a fatal failure
  throws `events::fatal_assertion` (`ut.hpp` lines 2180 to 2194), which the
  runner catches around each test (line 2133), so only the current test
  stops; without exceptions, the runner calls `std::abort()`. A probe with
  two tests, the first ending with `expect (1 == 2) << fatal;`, ran the
  second test. The `std::exit()` calls of `ut.hpp` are for `abort_early`
  and the command line options, not for `fatal`. Change the table cell to
  "the test is stopped (without exceptions, the program is aborted)", and
  the bullet to: "Boost UT stops the test with an exception; without
  exceptions, it reports the summary and calls `std::abort()`." On the
  comparison page, replace the bullet with the same text, and drop the
  sentence on `require()`, which then no longer differs. The two pages also
  write the suffix differently (`<< fatal` and `>> fatal`); both forms
  exist in 2.3.1, but one should be chosen (the README of Boost UT uses
  `>> fatal`).

  Fixed: The table says "the test is stopped", with the `>> fatal` form; the
  bullets of both pages describe the exception and, without exceptions,
  `std::abort()`.

- **#3 — Two statements of the comparison page say the frameworks were not
  built or measured.** (fixed) [project] `docs/developer/comparison/index.mdx`
  line 639 (Catch2: "heavier machinery than µTest++, which was not compared
  by measurement") and line 715 (Boost.Test: "The sources were read, but not
  built, for this page, since a build needs the rest of Boost"). Since #292,
  the Footprint section of the same page gives the sizes of both, built on
  nine platforms (Catch2 adds 506 KiB on the Cortex-M3, Boost.Test 479 KiB,
  in its single-header variant). Replace the first with "and a footprint
  about eleven times that of µTest++ (see Footprint)", and the second with
  "The single-header variant was built for the footprint measurements; the
  other variants need the rest of Boost."

  Fixed: Catch2 now has "a footprint about eleven times that of µTest++",
  and Boost.Test says that the single-header variant was built.

- **#4 — doctest is called the closest to µTest++ in the concern for the
  footprint.** (fixed) [project] `docs/developer/comparison/index.mdx` line 681:
  "The closest to µTest++ in the concern for the footprint and the compile
  times." The measurements of the same page put doctest at 388 KiB added on
  the Cortex-M3, eight times µTest++, and the page introduces snitch as "the
  closest in purpose" (line 41) and in the Embedded targets section. Replace
  with "Its documentation emphasises the compile times, which were not
  measured here; its footprint is close to that of Boost UT (see
  Footprint)."

  Fixed: The doctest paragraph now refers to its compile times, not
  measured, and to a footprint close to that of Boost UT.

- **#5 — The xcdl properties that affect the generated files are listed
  wrongly.** (fixed) [project] `docs/developer/making-changes/index.mdx` line 50:
  "Only the `publicIncludeFolders`, `sourceFiles`, `publicDefines`,
  `compilerOptions`, and `dependencies` properties affect the generated
  files". According to `.github/skills/xcdl/SKILL.md`, the top-level
  exporter reads `publicIncludeFolders`, `sourceFiles`, `dependencies`,
  `alias`, `publicDefines`, `privateDefines`, `publicCompilerOptions`,
  `privateCompilerOptions` (maps of categories), and `cdlArtefacts`, and a
  property named `compilerOptions` is ignored without any warning. A
  contributor who follows the page loses the options silently. Replace the
  sentence with the list of the skill, or with "The properties read by the
  exporter are listed in `.github/skills/xcdl/SKILL.md`; a misspelt property
  is ignored without a warning."

  Fixed: The sentence lists the properties read by the exporter, warns about
  the misspelt names, and refers to the xcdl skill.

- **#6 — The command that installs xpm has a single-dash option.** (fixed)
  [template] `docs/_common/_prerequisites.mdx` line 47 (Contributor's and
  Maintainer's Guides): `npm install -location=global xpm@latest`. The
  option is `--location=global`, as the Integration Guide writes it
  (`docs/install/_common/_prerequisites.mdx` line 23). Template:
  `templates/docusaurus/common/docs/_common/_prerequisites-liquid.mdx`
  line 59; the same typo is in
  `templates/docusaurus/common/docs/install/_common/_xpack/_prerequisites-cli-liquid.mdx`
  line 51 (`npm@latest`), used by the xPack sites.

  Fixed: `--location=global` in `_prerequisites-liquid.mdx` and in
  `_xpack/_prerequisites-cli-liquid.mdx` (`npm@latest`) of the template
  package (not committed there); the site commons were regenerated.

- **#7 — The name of the workflow is misspelt.** (fixed) [template]
  `docs/_common/_continuous-integration.mdx` line 18, shown on the Getting
  Started page and on the Contributor's Guide: "the `Eun all tests`
  workflow". The workflow is named `Run all tests`
  (`.github/workflows/test-all.yml`). Template:
  `templates/docusaurus/common/docs/_common/_micro-os-plus/_continuous-integration-liquid.mdx`
  line 18; it affects all the µOS++ sites.

  Fixed: `Run all tests` in
  `_micro-os-plus/_continuous-integration-liquid.mdx` of the template
  package (not committed there); the site commons were regenerated.

- **#8 — The explanation of the dependency commands is wrong.** (fixed) [template]
  `docs/developer/_common/_content.mdx` lines 55 to 65: of the three
  commands, "The last two commands install the dependencies of the tests
  project, such as the build tools." The second one installs the npm
  dependencies of `tests` (`tap-parser`), but the third,
  `xpm install -C ~/Work/micro-os-plus/micro-test-plus-xpack.git`, installs
  the xpm dependencies of the top project (`@xpack-dev-tools/clang`, for
  `clang-format`), not those of `tests` (`cmake`, `meson-build`,
  `ninja-build`, and `diag-trace`, installed by the `install` actions).
  Template: `templates/docusaurus/common/docs/developer/_common/_micro-os-plus/_content-liquid.mdx`
  lines 59 to 65. Say what each command installs: "The first two install
  the npm dependencies of the project and of the tests; the third installs
  the development tools of the project, such as `clang-format`. The build
  tools and the toolchains of the tests are installed by the `install`
  actions ...".

  Fixed: the paragraph says that the first two commands install the npm
  dependencies of the project and of the tests project, and the third the
  xpm development dependencies of the project, such as the code formatters;
  template `developer/_common/_micro-os-plus/_content-liquid.mdx` (not
  committed there).

- **#9 — "Start the local web server" sends the reader to the Maintainer's
  Guide from the Maintainer's Guide.** (fixed) [template]
  `docs/_common/_start-local-web-server.mdx` line 16: "Navigate to the
  Maintainer's Guide page, the Start the local web server section", with a
  link to the same section of the local server. On the Maintainer's Guide,
  the reader is already in that section; on the Contributor's Guide, which
  includes the same partial under "The website", the instruction refers to
  another guide for no reason. Replace with "Open
  <http://localhost:3000/micro-test-plus-xpack/> to view the local copy of
  the site", and, for the Maintainer's Guide only, "and continue the release
  from the local copy of this page". Template:
  `templates/docusaurus/common/docs/_common/_start-local-web-server-liquid.mdx`.

  Fixed: the partial now gives the address of the local copy of the site,
  `http://localhost:3000/micro-test-plus-xpack/`, and says that its pages
  are updated when the source files change, which suits both guides;
  template `_start-local-web-server-liquid.mdx` (not committed there).

- **#10 — The stack figures were measured before the release.** (fixed)
  (WEBSITE-REVIEW-5 #2) [project] `docs/user/embedded-targets/index.mdx`
  lines 155 to 190: the stack table, the 0.5 KB of the reporter, and the
  "about 5 KB" of the deeply nested test come from measurements made before
  the last changes of the test cases and of the reporters of 6.0 (the
  footprint figures above them were re-measured for 6.0.1, the stack ones
  were not). Re-measure them on Cortex-M33 and AArch64 with 6.0.1, in the
  same run as the footprint benchmarks, or say that they are "measured with
  a development version of 6.0".

  Fixed: Re-measured with 6.0.1 and GCC 15.2.1, under QEMU and GDB, on
  `suite-test` run with an output file: the per-level cost grew (Cortex-M33
  416 and 232 bytes, AArch64 720 and 432 bytes, `-Og` 304 bytes), the deeply
  nested test uses about 5.6 KiB before the reporter and 6.6 KiB of the 8
  KiB with it, and the table has two more rows, the reporter and
  `vsnprintf()`. The method is in a new Stack Usage section of the
  footprint-benchmarks skill, whose Presentation section was also brought in
  line with #15 and #24.

- **#11 — Two sizes are not in KiB, as the text says.** (fixed) [project]
  `docs/user/embedded-targets/index.mdx` line 76 and
  `docs/developer/comparison/index.mdx` line 153: "about 24 KiB are the
  functions of µTest++"; `footprint-sizes.json` gives 23 925 to 23 935 bytes
  on the Cortex-M platforms, which is 23.4 KiB (24 KB). Line 86 of the
  Embedded targets page: "The baseline is already about 77 KiB on this
  platform"; the `text` of the Cortex-M7F baseline is 77 160 bytes, which is
  75.4 KiB, and its flash (`text` plus `data`) is 77.7 KiB, shown as 78 in
  the Flash table of the comparison page. Write "about 23 KiB" and "about
  78 KiB of flash".

  Fixed: "about 23 KiB" on both pages; the baseline is "about 81 KiB of
  flash", after the move to the Cortex-M4F of #24.

- **#12 — A sentence of the test details is garbled.** (fixed) [project]
  `docs/developer/_project/_test-details.mdx` line 82: "the output file of
  the `minimal-test` program, run as with the human-readable reporter".
  Replace with "run with the human-readable reporter, as shown on the first
  line".

  Fixed: "run with the human-readable reporter, as shown on the first line";
  the paragraph is rewrapped.

## 2. Version history

The compatibility notices, the History page, the release posts, the
Releases page, and `CHANGELOG.md` agree with the git tags (v6.0.0
2026-11-09, v6.0.1 2026-11-15). The two tags without a post, `v3.2.1` and
`v4.1.0`, are explained in the posts of 3.2.2 and 4.1.1. The library is the
same in `v6.0.0` and `v6.0.1` (`git diff` of `include/` and `src/` is
empty), as the 6.0.1 post says.

- **#13 — The History heading of v6.0 gives the month the work started.** (fixed)
  [project] `docs/project/history/_project/_content.mdx` line 46:
  "## October 2026 (v6.0)". The other headings give the month of the
  release (April 2022 for v3.0, April 2026 for v4.0, although its work
  started in March, July 2026 for v5.0), and v6.0.0 was released on
  2026-11-09. Write "## November 2026 (v6.0)"; the text already says that
  the reviews started on 12 October.

  Fixed: The heading is "November 2026 (v6.0)".

- **#14 — The History page names the release post without linking it.** (fixed)
  [project] `docs/project/history/_project/_content.mdx` line 87: "and, in
  detail, in the release post." Link it, as the compatibility notices do:
  `[release post](/blog/2026/11/09/micro-test-plus-v6-0-0-released/#details)`.

  Fixed: The release post is linked to its `#details` section.

## 3. Structure

### Home page

- **#15 — The footprint comparison of the home page leaves out the two
  smaller frameworks.** (fixed) [project] `src/components/HomepageExample/index.tsx`
  lines 70 to 74, and the 6.0.1 post: "127 KiB of flash with µTest++,
  against 435 to 588 KiB with Boost UT, doctest, GoogleTest, Boost.Test, and
  Catch2". The figures are right (Cortex-M4F, `text` plus `data`), but
  CppUTest (183 KiB), the other C++ framework for embedded targets, and
  snitch (556 KiB, within the range quoted) are omitted, so the reader of
  the home page gets a more favourable picture than the comparison page
  gives. The feature text ("a fraction of that of the major C++ testing
  frameworks", `CustomFeatureList.tsx` line 37) has the same bias. This is
  a decision for the maintainer: either add "and 183 KiB with CppUTest", or
  say which frameworks are compared and why ("the frameworks that use the
  C++ streams").

  Fixed: The home page and the 6.0.1 post compare the flash added to an
  empty program (46 KiB against 102 KiB for CppUTest, and 354 to 507 KiB for
  the six other C++ frameworks, snitch included), and the feature text says
  that, on Cortex-M, the flash added is "less than half of that added by the
  other C++ testing frameworks measured" (on AArch64 and RISC-V, where the
  empty program has no C++ run-time, CppUTest adds only about 15% more).

### Writing checks and the comparison page

- **#16 — The use of the comparators in `static_assert()` is not
  documented.** (fixed) [project] A probe confirms that
  `static_assert (mt::eq (6 * 7, 42))` and
  `static_assert (mt::all_of (mt::lt (1, 2), mt::ne (3, 4)))` compile, since
  the expressions are `constexpr`; the Extending page shows it only for the
  application comparators. The Writing checks page does not mention it, and
  the comparison page lists "No compile-time variants of the checks" among
  the limits (line 992), which a reader takes to mean that nothing can be
  checked at compile time. Add a short section "Compile-time checks" to
  `docs/user/checks/index.mdx`, and reword the limit: "The checks run at
  run time; the comparators can be used in `static_assert()`, but a failure
  there is reported by the compiler, without the operands."

  Fixed: A section "Compile-time checks" follows "Logical functions" in
  Writing checks (its example was compiled), and the limit of the comparison
  page refers to it.

### Extending the framework

- **#17 — The page about extensions starts with the utility functions.** (fixed)
  [project] `docs/user/extending/index.mdx` line 25: "Utility functions"
  (`is_match()`, `split()`) is the first section, before the introduction
  of the page is followed up, which says that the page is about the types
  and the comparators of the applications; the User's Guide overview lists
  the utility functions last. Move the section to the end of the page.

  Fixed: The section is the last one of the page, and the introduction
  mentions it.

### Architecture overview

- **#18 — The table of the headers omits `deprecated.h`.** (fixed) [project]
  `docs/developer/architecture/index.mdx` lines 93 to 112: the table says
  it lists the headers "in the order in which `micro-test-plus.h` includes
  them", but `micro-test-plus.h` line 137 also includes `deprecated.h`,
  last. Add a row: "`deprecated.h` | the deprecated operators, literals, and
  wrappers, compiled only with
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED` | [Migrating from
  earlier versions](/docs/user/migrating/)".

  Fixed: A row for `deprecated.h` ends the table.

### Glossary

- **#19 — The glossary lacks the TAP terms that the guides use.** (fixed) [project]
  `docs/getting-started/glossary/index.mdx`: "test point" and "plan" are
  used without definition on Running tests ("bare `ok` lines ... so that
  the plan of the block matches its test points"), Organising tests, and the
  Reporters page. Add to "Protocols and tools": "test point: an `ok` or
  `not ok` line of a TAP report, one for each check or nested test case;
  plan: the `1..N` line that gives the number of test points of a block".

  Fixed: The glossary defines "test point" and "plan".

### Site-wide

- **#20 — The same sections appear on several pages.** (partly fixed) [template] The
  "Testing" section of Getting Started and the "Continuous integration"
  section of the Contributor's Guide are the same partial
  (`_continuous-integration.mdx`, with the typo of #7); "Prerequisites",
  "Install xpm", "Obtain project sources", "Code formatting", "Manual
  tests", and "Clean-ups" are identical in the Contributor's and
  Maintainer's Guides; "Regenerate the Doxygen pages", "Prepare the
  website", "Build the static website locally", and "Start the local web
  server" are in both guides too, although publishing the site is a
  maintainer task. Keep each in one guide (the build and the tests in the
  Contributor's Guide, the website in the Maintainer's Guide), and link to
  it from the other; in Getting Started, keep one sentence on the CI and a
  link. Template: `_content-liquid.mdx` of `developer/_common/_micro-os-plus/`
  and `maintainer/_common/_micro-os-plus/`.

  Partly fixed: the duplicates come from shared partials, so they cannot
  diverge, and the Maintainer's Guide is meant as a self-contained release
  checklist, so the prerequisites, the sources, the formatting, and the
  tests stay in both guides. The parts with a single owner are fixed in the
  templates (not committed there): on the Getting Started page of the µOS++
  sites, the Testing section is one paragraph with a link to the Continuous
  integration section of the Contributor's Guide; and the Contributor's
  Guide no longer has "Prepare the website" (regenerating the commons and
  committing, a maintainer task), but a paragraph saying that the generated
  pages are regenerated by the maintainers, with a link to Publish the
  website.

- **#21 — The "Last updated" dates do not reflect the content.** (withdrawn) [template]
  `docusaurus.config.ts` line 104 (`showLastUpdateTime: true`) takes the date
  of the `index.mdx` file, while most pages are built from partials. The
  FAQ shows "Mar 10, 2025", the History and About pages "Mar 10, 2025", and
  the User's Guide overview "Oct 12, 2026", although their partials changed
  in November 2026. A reader takes the date as the age of the content. This
  is a decision for the maintainer: disable the option, or set
  `last_update` in the front matter of these pages when a partial changes.

  Withdrawn: The maintainer keeps the "Last updated" dates as they are.

- **#22 — Five generated partials are not used.** (partly fixed) [template]
  `docs/_common/_generate-top-commons.mdx`,
  `docs/_common/_symbolic-links-require-ntfs.mdx`,
  `docs/_common/_update-top-commons.mdx`,
  `docs/_common/_update-website-commons.mdx`, and
  `docs/getting-started/_common/_credits-mac-stadium.mdx` are imported by
  no page. They are not published, but they are regenerated and reviewed
  for nothing. Generate them only for the projects that import them, or
  delete them from this project if the generator does not recreate them.

  Partly fixed: the template folders by organisation are used, without a
  change of the generator. `_generate-top-commons`, `_update-top-commons`,
  and `_update-website-commons`, imported only by the Maintainer's Guide of
  the xpack-dev-tools sites, are now in `docs/_common/_xpack-dev-tools/`,
  and `_symbolic-links-require-ntfs`, imported only by two xpack sites, in
  `docs/_common/_xpack/` (moved with `mv`, not committed there); the
  regenerated site no longer has them. `_credits-mac-stadium`, imported by
  the xpack and the xpack-dev-tools sites, would need a copy in each folder,
  and is left.

- **#23 — The sample outputs omit the blank lines of the console.** (withdrawn)
  [project] The console output has blank lines that the reference files of
  the output file do not have: before the `# Running:` line, before the plan
  of each suite, and before the final plan with TAP, and around the suite
  lines with the human-readable reporter (a probe of the tutorial program
  shows them, and so do `tests/expected/tap/unit-test-console.tap` and
  `tests/expected/txt/unit-test-console.txt`). The tutorial says "the output
  looks like this" (line 79 of `docs/user/tutorial/index.mdx`), and Running
  tests shows the human output "for the minimal test", without them. Either
  show them, or say once, in the tutorial before the first output, that
  "the blank lines that separate the suites on the console are omitted";
  the home page already lists what its outputs omit, and should add them.

  Withdrawn: The guide pages do show the blank lines; the text extraction
  used for the review dropped the empty lines. Only the home page omits
  them, and its note now lists "the blank lines" among the omissions.

## 4. Consistency

| # | Concept | Variants found (where) | Suggested |
| --- | --- | --- | --- |
| #24 (fixed: Cortex-M4F on the home page, in Getting Started, and in Embedded targets (with the M4F sizes)) | the platform of the quoted footprint | Cortex-M4F (`HomepageExample/index.tsx` line 70, 6.0.1 post); Cortex-M7F (`user/embedded-targets/index.mdx` line 74); "a Cortex-M device" (`getting-started/_project/_features.mdx` line 39); "the Cortex-M platforms" (comparison page) | one platform everywhere, for example Cortex-M4F, with its 127 KiB and 81 KiB |
| #25 (fixed: the stack figures, the program size, and the flash of the boards are in KiB, and the flash of the Pico boards in MiB) | the unit of the sizes | KiB for the footprint; KB for the stack figures (`user/embedded-targets/index.mdx` lines 155 to 200: 1.1 KB, 0.5 KB, 8 KB, 5 KB) and for the program size of the overview (`user/_project/_content.mdx` line 77: "over 120 KB"); KB for the flash of the boards (home page, overview) | KiB for every measured size; the board flash in the vendor's units, with "KB" defined once as 1024 bytes |
| #26 (fixed: the glossary, the home page example, and the templates `_prerequisites-liquid.mdx`, `install/_common/_prerequisites-liquid.mdx`, `_xpack-dev-tools/_content-liquid.mdx`, and the semihosting paragraph of the Contributor's Guide) | "command line" used as an adjective | "command line application" (`install/_common/_prerequisites.mdx`, `_common/_prerequisites.mdx`), "command line tool" (glossary), "command line arguments" (home page code comment, `developer/_common/_content.mdx`) [template and project]; "command-line options" in the guides | "command-line" before a noun, as decided in WEBSITE-REVIEW-5 #5 |
| #27 (fixed: the Embedded targets link uses the `xpack` branch) | the branch of the links into the repository | `xpack-development` in `user/embedded-targets/index.mdx` line 31 and in the comparison page; `xpack` for the licence, the changelog, and `package.json`; the tags in the posts | the `xpack` branch, or the release tag, in the User's Guide, which describes the released version; `xpack-development` only in the Contributor's Guide |
| #28 (fixed: the About page, the defines sample, the `description` of `xcdl-package.jsonc`, and the `description` of `package.json`, with its copies in `README.md`, `CMakeLists.txt`, and `meson.build`, and the tagline of `website/package.json`; the old posts are left) | "lightweight" | removed from the tagline by #292, as unquantified; kept in `project/about/_project/_more-intro.mdx` line 4, in the comment of the defines sample (`install/_project/_configuration.mdx` line 24, copied from the `description` of `xcdl-package.jsonc`), in `meson.build`, and in the introduction of the posts up to 6.0.0 | remove it from the About page and from `xcdl-package.jsonc`, or give the figure ("about 46 KiB of flash on Cortex-M"); leave the old posts |
| #29 (fixed: History and the v5.0.0 post) | Meson | "meson files" (`project/history/_project/_content.mdx` line 39), "the meson dependency" and "meson files" (v5.0.0 post); "Meson" in the Integration Guide and the other pages | "Meson" in the text; `meson` only for the command |

## 5. Language and style

- **#30 — Missing Oxford commas.** (fixed) "Windows and GNU/Linux hosts"
  (`src/components/HomepageFeatures/CustomFeatureList.tsx` line 42)
  [project]; "Cortex-M, Cortex-A and RISC-V"
  (`docs/_common/_continuous-integration.mdx`) and "`SYS_OPEN`, `SYS_WRITE`
  and `SYS_CLOSE`" (`docs/developer/_common/_content.mdx` line 160)
  [template]. Add the comma before "and".

  Fixed: the comma is added in `CustomFeatureList.tsx`, and in the templates
  `_micro-os-plus/_continuous-integration-liquid.mdx` (where "running using
  QEMU" also became "running under QEMU") and
  `developer/_common/_micro-os-plus/_content-liquid.mdx` (not committed
  there).

- **#31 — A contraction.** (fixed) [template] `docs/_common/_prerequisites.mdx`
  line 43: "If you're confident and prefer a shortcut". Write "For a
  shortcut, run the following command". Template:
  `_prerequisites-liquid.mdx` line 55.

  Fixed: "As a shortcut, run the following command:", in
  `_prerequisites-liquid.mdx` of the template package (not committed there);
  the site commons were regenerated.

- **#32 — "e.g.," and "i.e.,".** (fixed) "e.g., `.tar.gz` for Unix"
  (`docs/getting-started/_common/_what-are-xpm-packages.mdx` line 51)
  [template]; "in a nested manner, i.e., a test case can include"
  (`docs/user/organising-tests/index.mdx` line 339) [project]. The rest of
  the site writes "for example" and "that is"; use them here too.

  Fixed: "that is," in Organising tests, and "for example," in the template
  `getting-started/_common/_what-are-xpm-packages-liquid.mdx` (not committed
  there).

- **#33 — Trailing spaces in the code shown to the reader.** (fixed)
  `src/components/HomepageExample/index.tsx` line 23 (`// Add a test case to
  the top suite; ` ends with a space, visible when the code is copied), and
  the µTest++ and Boost UT listings of
  `docs/developer/comparison/index.mdx` (lines 374 to 386 and 429 to 438,
  `[] { ` and `{ ` at the ends of lines) [project]. Remove them; they also
  make these listings differ from the formatting of the rest of the site.

  Fixed: The trailing spaces are removed from the home page example, from
  `CustomFeatureList.tsx`, and from the listings of the comparison page.

- **#34 — The compatibility notices skip a heading level.** (fixed) [project]
  `docs/getting-started/_project/_compatibility-notices.mdx` uses `###` for
  each version, directly under the `#` title of the page (h1 to h3, no h2);
  the partial is imported only by that page. Use `##`.

  Fixed: The partial uses `##` for the versions.

The language rules of `.github/copilot-instructions.md` were checked by
search over the text of all the published pages: no `TODO` outside the
quoted name `parser # TODO rework` and the maintainer's instructions about
the template placeholders, no "directory" in the prose (only CMake's
`add_subdirectory` and the `tree` output), no American spellings outside
the option names (`--color`) and the quoted `initialize()` of another
package, and none of the inflated words listed by the skill. The only
contraction is #31.

## 6. Proposed restructuring

- **#35 — Move "Comparison with other frameworks" out of the Contributor's
  Guide.** (fixed) The page (`docs/developer/comparison/index.mdx`) says it is
  written "to help the contributors judge which design choices are
  deliberate", but it is now mostly read by the users who choose a
  framework: the home page, Getting Started, the User's Guide overview,
  Writing checks, Embedded targets, and the 6.0.1 post link to it for the
  measurements, and the Contributor's Guide category is collapsed in the
  sidebar. Options for the maintainer: a page of Getting Started
  (`docs/getting-started/comparison/`), next to the compatibility notices,
  or a top-level "Comparison" entry of the sidebar; in both cases, rewrite
  the first paragraph for the users, and keep the Design choices section,
  or move it to the Architecture overview, for the contributors.

  Fixed: The page is now `docs/getting-started/comparison/index.mdx`, listed
  after the glossary in the Getting Started sidebar, and removed from the
  Contributor's Guide sidebar; its first paragraph addresses the readers who
  choose a framework, and also the contributors; the Design choices section
  is kept. The links of the home page, of Getting Started, of the User's
  Guide, of the 6.0.1 post, and of the Contributor's Guide page list point
  to the new path; `docusaurus-config-redirects.ts` redirects the old path;
  the paths in the footprint-benchmarks skill, in its scripts, and in
  `frameworks.jsonc` are updated. The other items of this report keep the
  old path, `docs/developer/comparison/index.mdx`.

- **#36 — Give the footprint its own page.** (fixed differently) The comparison page has about
  1040 source lines, of which the Footprint section (method, the Flash and
  RAM tables, the notes, and nine Sizes tables) is about 300, and is the
  part that changes at each measurement. A page "Footprint"
  (`docs/developer/footprint/` or under the location chosen in #35) would
  take the Footprint section and the measured tags of Sources; the
  comparison page would keep the summary matrix, with a link, and the
  framework sections. The skill `footprint-benchmarks` would then update
  one page.

  Fixed differently: The item overstated the problem: the nine Sizes tables
  were already folded, one `<details>` element per platform, which the text
  extraction of the review had flattened. The maintainer chose to keep the
  footprint on the comparison page; `generate-footprint-tables.mjs` now
  writes a single fold with three tables (`text`, `data`, and `bss`, in
  bytes, with the platforms as columns, as in the Flash and RAM tables). The
  297 values were compared with those of the nine tables, and are the same;
  the Flash and RAM tables are unchanged.

- **#37 — Move the TAP escaping rules from the tutorial to Running
  tests.** (fixed) `docs/user/tutorial/index.mdx`, the paragraph after the verbose
  output (the escaping of `#` and `\`, the line breaks, the `# Subtest:`
  lines) is reference material in the first page of the guide, before the
  reader has written a second test. Move it to the "Output file" section of
  `docs/user/running-tests/index.mdx`, after the paragraph on the YAML
  block, and leave a sentence and a link in the tutorial.

  Fixed: The paragraph is in the "Output file" section of Running tests; the
  tutorial keeps one sentence and a link.

## 7. Incidental observations outside the website

- **#38 — The generated headers name templates that do not exist.** (withdrawn)
  [template] The `DO NOT EDIT!` headers of the generated files name their
  template as `docusaurus-template-liquid/templates/common/...` (for example
  line 2 of `docs/developer/_common/_content.mdx`), but the package has only
  `templates/docusaurus/common/...`; the path as written cannot be opened,
  and a reviewer must guess the missing segment. The fix is in the
  generator of the template package, which should write the path relative
  to the package root.

  Withdrawn: The maintainer does not want the generator changed.

- **#39 — `xpm run xcdl-export` fails.** (fixed) [template] Since the commit
  `319161be` ("re-generate top commons", 2026-11-12), the templates
  `maintenance/scripts/templates/CMakeLists-liquid.txt` (line 8) and
  `meson-liquid.build` (line 8) write `Copyright (c) 2021-{{currentYear}}`,
  but `maintenance/scripts/xcdl-export.mjs` does not define `currentYear` in
  its Liquid context, so the export stops with `UndefinedVariableError:
  undefined variable: currentYear`, and the top-level `CMakeLists.txt` and
  `meson.build` cannot be regenerated. The script and the templates are
  generated from the `npm-packages-helper` package
  (`templates/common/maintenance/scripts/xcdl-export-liquid.mjs`), where the
  fix belongs: add `currentYear: new Date().getFullYear()` to the context,
  and regenerate the top commons. For #28, the description lines of the two
  files were edited by hand, with the text that the export writes.

  Fixed: `currentYear: new Date().getFullYear()` is added to the Liquid
  context in `templates/common/maintenance/scripts/xcdl-export-liquid.mjs`
  of `npm-packages-helper` (not committed there), and `npm run
  generate-top-commons` regenerated `maintenance/scripts/xcdl-export.mjs`,
  the only file it changed. `xpm run xcdl-export`, followed by `xpm run
  cmake-format`, now produces `CMakeLists.txt` and `meson.build` identical
  to the hand edits of #28.

## 8. Reviewed and found correct

- The home page: the example program and its two outputs (compared with a
  probe run with `--verbose`, apart from #23), the footprint figures
  (Cortex-M4F, from `footprint-sizes.json`), and the boards named.
- Getting Started: the overview, the features (the 46 KiB and 350 KiB
  figures), the CI section (the workflows run on Ubuntu, macOS, and
  Windows; the trigger script uses `curl` and `GITHUB_API_DISPATCH_TOKEN`),
  the compatibility notices (dates against the tags), and the glossary
  (the order of the suites, the top suite, and the use of `tap-parser`).
- The Integration Guide: the tree of the package (55 files, against `npm pack
  --dry-run`), the list of the 12 sources, the three CMake targets
  (`EXCLUDE_FROM_ALL`, the `micro-test-plus` output name), the Meson
  dependency, the configuration macros and the xcdl option ids, and the
  optional `diag-trace` include.
- The User's Guide: the tutorial (the line numbers 21 and 20 of the
  listings, and the outputs against the console references), Writing checks
  (apart from #2 and #16), Organising tests (apart from #1; the top suite
  name `default suite`, the second `add_top_suite()`, the empty session, and
  the exit codes were confirmed by probes), Running tests (the options
  against `runner-options.cpp`, `--help`, the quiet output of both
  reporters, the filter and the list, confirmed by probes; the colour
  detection against `reporter-human.cpp`), Extending (the line numbers 37
  and 59 to 61), Embedded targets (apart from #10 and #11), and Migrating.
- The FAQ, the Help Centre, the Releases page, About, and History (apart
  from #13 and #14).
- The Contributor's Guide: every `xpm run` and `npm run` command, the list
  of the platforms against `tests/platforms/`, the test runs of each
  program (four verbosities with each reporter, in `artefacts.cmake`), what
  `compare-files.sh` ignores, the table of the test programs, the reference
  outputs shown, and the eight pages on the internals (every identifier
  exists; the excerpts of `runner::abort()`, `run_child_suites()`,
  `is_selected()`, the option table, `test.h`, and `micro-test-plus.h`
  were compared with the sources).
- The comparison page: all the figures of the Flash, RAM, and Sizes tables
  (recomputed from `footprint-sizes.json`), the summary matrix row of the
  flash, the ratios quoted, and the release tags of Sources.
- The Maintainer's Guide (the commands and the branch operations; "rebase
  the `xpack` branch onto `xpack-development`" is the right description of
  `git rebase xpack-development` run on `xpack`).
- The blog: the 6.0.1 post (the library is unchanged since 6.0.0), the 6.0.0
  post (apart from #1; the runner members it names exist), the posts of
  5.0.x, 4.x, and the older releases, read for placeholders and wrong
  links; all the links into the repository resolve.
- The navigation bar, the footer, and the sidebars: every page in the
  sitemap is reachable, and the sidebar labels match the page titles.
