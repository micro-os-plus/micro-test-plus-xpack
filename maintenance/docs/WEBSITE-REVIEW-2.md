# Website review

Date: 2026-11-02, on branch `webpreview`, commit `cfcdfcc3`; published
site built from `webpreview` commit `cfcdfcc3`.

Scope: the preview site at
<https://micro-os-plus.github.io/micro-test-plus-xpack-webpreview/>:
the home page, every page under `/docs/` listed in the sitemap, the
blog (the 25 posts, the index pages, the archive, and the tags), the
navigation bar, the sidebar, and the footer. The API reference pages
under `/docs/api/` are excluded (see the `website-api-review` skill);
only the links into them were checked. The two `draft: true` pages
(`docs/test/`, `docs/test/md/`) were checked and are not published
(HTTP 404).

Method: every page was downloaded with `curl` after the publish
workflow of `cfcdfcc3` had completed, and the text of its `<article>`
(or `<main>`, for the home page) was read in full. No page was read
from the local sources only, since the published site and `HEAD` were
identical. The sources were followed through their imports, and the
generated files were checked against the templates in
`website/node_modules/@xpack/docusaurus-template-liquid/templates/`.
The site was not built locally. The technical statements were checked
against `include/`, `src/`, `CMakeLists.txt`, `meson.build`,
`xcdl-package.jsonc`, the three `package.json` files, the reference
files in `tests/expected/`, `npm pack --dry-run`, the git tags, the npm
publication dates, and the xpm sources (`src/xpm/run-action.js`).
Five complete examples of the User's Guide were compiled with Apple
clang 17 and run against the library sources, and the native
`minimal-test` program of `tests/build/` was run with several options.
`WEBSITE-REVIEW-1.md` was read first; besides the 15 items it already
marked fixed or not applicable (one of which, 2.3.1, has regressed;
see item #1), 12 of its problems were fixed
meanwhile (3.2.1, the missing v5.0 notice; 3.4.2; 3.5.3 to 3.5.6;
3.5.8 to 3.5.10; 3.5.14; 7.2; and the "DO NOT EDIT!" header left in
`CustomFeatureList.tsx` by 2.1.1), and 3.5.21 needs no change, since
`math.h` is internal. The open problems are carried over below, each citing its
section in that report.

Summary: 117 problems (0 open, 111 fixed, 6 withdrawn).

The most serious problems are those that make a reader's build or
command fail: the Integration Guide omits `runner-options.cpp` from the
source files (#12) and misdescribes the `diag-trace` dependency (#14);
the Contributor's and Maintainer's Guides give commands that fail
(`xpm run deep-clean`, #23; `website-generate-commons`, #24); and a
`TODO` page is published again (#1). Next come the samples that do not
match the code or its output (#3 to #9), two compatibility notices
that contradict the code (#10, #11), and the wrong release dates
(#43).

Suggested order of work:

1. The broken commands and build instructions: #12, #14, #23, #24,
   #1, then #13 and #15 to #19.
2. The samples and the factual errors of the User's Guide and of the
   compatibility notices: #3 to #11, #40.
3. The version history: #43 to #50.
4. The template corrections shared with the other sites: #20, #22,
   #27 to #38, #41, #42, and the style items in the templates (#89
   to #91, #96 to #98, #101, #102).
5. The restructuring (#104 to #113), then the consistency and style
   items, which are cheaper to apply once the pages are split.

## Note on generated files

Most website files carry a "DO NOT EDIT!" header naming their template
in the `@xpack/docusaurus-template-liquid` package
(`website/node_modules/@xpack/docusaurus-template-liquid/templates/`).
They are regenerated with `npm run generate-website-commons` in
`website/`, so the fixes must be made in the template. The paths given
below as `templates/…` are relative to that package. Template problems
usually affect the other µOS++ sites as well.

The files owned by the project, edited in place, are the `_project/`
partials, `docs/getting-started/glossary/index.mdx`,
`config/website-templates.json`, the two `sidebar-*-custom.*` files,
`src/components/HomepageFeatures/CustomFeatureList.tsx`,
`src/components/HomepageExample/index.tsx`, and the blog posts (not
`blog/_common/` and `blog/_templates/`). The template also proposes
"first-time" files, copied only when missing; deleting one is undone
by the next regeneration (see #1).

Each finding is marked **[template]** or **[project]**.

## 1. Defects

- **#1 — A `TODO` page is published again.** (fixed) [template]
  `/docs/developer/install/prerequisites/` shows a page titled "index"
  whose whole content is "TODO" (WEBSITE-REVIEW-1 2.3.1, marked fixed,
  regressed). The file was deleted in `e9ffb1d0`, but it is a
  first-time proposal of the template
  (`templates/docusaurus/first-time/docs/developer/_micro-os-plus/install/prerequisites/index.mdx`),
  so `generate-website-commons` recreated it. Remove it from the
  template, or skip it in `generate-website-commons.mjs`; deleting it
  again in this repository only lasts until the next regeneration.

  Fixed: the first-time template file was deleted from
  `docusaurus-template-liquid`; after `npm run generate-website-commons`
  the page is not recreated (checked 2026-11-02). Pending: commit the
  template change, and the deletion of the page here.

- **#2 — The FAQ gives the same form of `--output-file` twice.**
  (fixed) [project] `docs/faq/_project/_content.mdx` lines 60–61: "either as
  `--output-file=<path>` or as `--output-file=<path>`". The second form
  must be `--output-file <path>` (both are accepted,
  `src/runner-options.cpp` line 174).

  Fixed: the second form is now `--output-file <path>`.

- **#3 — The comparator example does not print the message shown.**
  (fixed) [project] `docs/user/_project/_content.mdx` line 237: the listing of
  "More advanced comparators" appends `<< "answer is 42"`, but the
  output below it shows `not ok 1 - the answer is 42`. The program,
  compiled and run, prints `not ok 1 - answer is 42`. The message was
  changed in the outputs of the previous examples, but not in this
  listing. Change the listing to `<< "the answer is 42"`.

  Fixed: the listing now appends `<< "the answer is 42"`.

- **#4 — The verbose samples name the program `main` and the suite
  `minimal-test`.** (fixed) [project] `docs/user/_project/_content.mdx` lines
  107–122: the first sample starts with `# Running: main --verbose`,
  but its top suite, created with `add_top_suite ()` without a name, is
  `minimal-test`. Without a name, the top suite is named after the
  program (`src/runner.cpp` lines 457–476), so a program run as `main`
  reports `# Subtest: main`. Write `# Running: minimal-test --verbose`
  in this sample, as on the home page; the other samples (lines 159,
  189, 247), whose suite is named explicitly, may keep `main`.

  Fixed: the first sample now starts with
  `# Running: minimal-test --verbose`.

- **#5 — The custom type example reports the wrong line.** (fixed) [project]
  `docs/user/_project/_content.mdx` line 1141: `lineNumber: 35`. In the
  listing of "Custom Types", the check is on line 37, and the compiled
  program reports `lineNumber: 37`. Change it to 37.

  Fixed: the sample now shows `lineNumber: 37`.

- **#6 — The custom comparator example reports the wrong lines.**
  (fixed) [project] `docs/user/_project/_content.mdx` lines 1261–1263:
  `main.cpp:58`, `:59`, and `:60`. The checks are on lines 59, 60, and
  61 of the listing, which the compiled program reports. Change them
  to 59, 60, and 61.

  Fixed: the sample now shows `main.cpp:59`, `:60`, and `:61`.

- **#7 — The human-readable report sample is out of date.** (fixed) [project]
  `docs/user/_project/_content.mdx` lines 1863–1871: the banner is
  shown as `µTest++ human report`; the reporter writes `µTest++
  human-readable report` (`tests/expected/txt/minimal-test.txt`, and a
  run of `minimal-test --reporter=human`). The suite is called
  `Minimal`, which matches neither the minimal example of the page
  (unnamed top suite) nor the reference output (`minimal-test`).
  Regenerate the sample from a run of the minimal test.

  Fixed: the sample is the output of the minimal test of the page,
  run with `--reporter=human`.

- **#8 — The Timings sample uses the summary format of v3.3.**
  (fixed) [project] `docs/user/_project/_content.mdx` line 1675: `ok 1 - Minimal
  # { test suite passed, 1 check in 1 test case, time: 0.007 ms }`. The
  current format is `# { passed, 1 check in 1 test case, time: … }`
  (`tests/expected/tap/minimal-test.tap`). Copy the two lines from the
  reference file.

  Fixed: the sample is now the last lines of a run of the minimal test
  of the page.

- **#9 — The reason given for the missing timings is wrong.** (fixed) [project]
  `docs/user/_project/_content.mdx` line 1680: "On embedded platforms
  using Arm semihosting, the clock resolution is in the range of tens
  of milliseconds … and timings are therefore omitted". The clock is
  read only with `timespec_get()` on Windows and with
  `clock_gettime(CLOCK_MONOTONIC)` where `CLOCK_MONOTONIC` is defined;
  elsewhere it is not read at all (`src/stopwatch.cpp` lines 66–74),
  and no time is shown. Suggested text: "The times are measured with
  `clock_gettime (CLOCK_MONOTONIC)` on POSIX platforms and with
  `timespec_get()` on Windows. On the platforms that provide neither,
  usually the embedded ones, the times are not measured, and are
  omitted from the output." The sentence before it ("such as the POSIX
  `clock_gettime()`") should mention Windows too.

  Fixed: both sentences rewritten as suggested.

- **#10 — A compatibility notice says that the comparators no longer
  copy their operands.** (fixed) [project]
  `docs/getting-started/_project/_compatibility-notices.mdx` line 186:
  "the named class-type operands and the nested expressions are
  referred to … An expression kept in a variable, as in `auto op =
  mt::eq (v, w);`, must be checked before `v` and `w` are destroyed".
  The code copies the named operands: `eq()` builds a `compare_op`
  through the deduction guide, which stores `stored_operand_t`, a copy
  for every copyable lvalue, and a reference only for the non-copyable
  ones (`include/micro-os-plus/micro-test-plus/detail.h` lines
  198–225, 902–908). The User's Guide ("Custom Comparators") states the
  current behaviour correctly. Rewrite the notice: "The temporaries are
  moved into the expression and the named operands are copied; only a
  named operand that cannot be copied (for example a
  `std::unique_ptr`) is referred to, and must outlive the check."
  Check the sentence on `not not (x == 1_i)` at the same time.

  Fixed: the notice is rewritten as suggested. A probe confirmed that a
  kept `mt::eq (x, 2)` reports `1 == 2` after `x` is changed to 2, and
  that a double `negate()` keeps the value. The statement that `not not`
  "was negated once" before 6.0 was not checked.

- **#11 — The notice on the `type_traits` names misstates what was
  kept.** (fixed) [project]
  `docs/getting-started/_project/_compatibility-notices.mdx` lines
  122–131: "The `type_traits` names are kept, referring to the current
  concepts, so with their current semantics", followed by a list of
  concepts moved to `detail`, including `has_value`, `has_npos`, and
  `value`. In `deprecated.h`, `type_traits::has_npos` and
  `type_traits::has_value` keep their own v5.0.1 definitions (lines
  2576, 2597), and `genuine_integral_value` is an alias of the template
  `detail::value<T>`, not a concept (line 2862). State which names
  refer to the current concepts and which keep their v5.0.1
  definitions, as `CLAUDE.md` does.

  Fixed: the notice now says which names refer to the current concepts,
  that `genuine_integral_value` is an alias of `detail::value`, and that
  `has_npos` and `has_value` keep their v5.0.1 definitions. `has_npos`
  is no longer listed among the names moved to `detail`.

- **#12 — The list of source files omits `runner-options.cpp`.**
  (fixed) [project] `docs/install/_project/_build-and-integration-info.mdx`
  lines 41–56 list eleven files; `src/` has twelve, and
  `CMakeLists.txt`, `meson.build`, and `xcdl-package.jsonc` all include
  `src/runner-options.cpp`. A project that adds the listed files by
  hand fails to link (`runner_options` is undefined). Add the file;
  better, replace the list with "all the `.cpp` files of the `src`
  folder", so that it cannot go out of date.

  Fixed: `runner-options.cpp` added to the list (twelve files, as in
  `src/`). The list itself was kept; the sentence above it already says
  "all source files in the `src` folder".

- **#13 — The installed folder hierarchy is out of date.** (fixed) [project]
  `docs/install/_project/_install-folder-hierarchy.mdx` lines 8–71: the
  tree omits `runner-options.h`, `inlines/runner-options-inlines.h`,
  and `src/runner-options.cpp`, which `npm pack --dry-run` includes, and
  its summary says "55 files", whilst the tree lists 51 and the
  package has 54. Regenerate the tree from the installed package.

  Fixed: the tree was regenerated from the `npm pack --dry-run` file
  list (54 files, with the three missing ones). The page was not
  checked against an actual `xpm install` of 6.0.0.

- **#14 — The `diag-trace` dependency is described as optional, but
  the build files require it.** (fixed) [project]
  `docs/install/_project/_build-and-integration-info.mdx` lines
  139–146 (WEBSITE-REVIEW-1 3.2.3): "a single external dependency, used
  to output trace messages in Debug mode". All three CMake targets link
  `micro-os-plus::diag-trace` unconditionally (`CMakeLists.txt` lines
  93, 185, 264), and the meson dependency includes
  `micro_os_plus_diag_trace_dependency` (`meson.build` line 71), but
  `package.json` declares no xpm dependency, so `xpm install` does not
  install it, and CMake reports a missing `micro-os-plus::diag-trace`
  target. State that the CMake and meson integrations need
  `@micro-os-plus/diag-trace` (with its install command), and that
  only the manual integration can omit it (since 5.0.1, `trace.h` is
  included only if available). See also #114.

  Fixed: `diag-trace` is now listed as an optional dependency in
  `xcdl-package.jsonc` (`cef82bb4`), the generated CMake and meson files
  no longer link it, and the page says that there are no required
  dependencies and how to enable the trace messages.

- **#15 — The configuration header is said to be generated by xCDL.**
  (fixed) [project] `docs/install/_project/_build-and-integration-info.mdx`
  lines 114–131 (WEBSITE-REVIEW-1 3.2.3): "For xCDL enabled projects,
  this file is automatically generated", followed by an
  `xcdl-project.jsonc` snippet. The `xcdl` tool is not yet available
  and no `*-defines.h` file is generated (`.github/skills/xcdl/`). The
  snippet also does not match `xcdl-package.jsonc`: the option is
  `trace-constructors`, not `trace.constructors`, and the `deprecated`
  option is missing. Remove the paragraph and the snippet, or mark them
  clearly as planned and correct the names.

  Fixed: by decision, the paragraph was kept, and its first
  sentence now says that the file will be generated once the xCDL tool
  is available, and the option name is now `trace-constructors`. The
  `deprecated` option is deliberately not shown in the snippet, since
  it is not usually needed.

- **#16 — `-std=c++20` is said to be a linker option.** (fixed) [project]
  `docs/install/_project/_build-and-integration-info.mdx` line 135
  (WEBSITE-REVIEW-1 3.2.3): "must be supplied to the compiler and
  linker". It is a compiler option only.

  Fixed: "and linker" removed. A test with GCC 15.2.1 and Apple clang
  17 confirmed that an `-flto` link needs no `-std` option.

- **#17 — The effect of `MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED` is not
  explained.** (fixed) [project]
  `docs/install/_project/_build-and-integration-info.mdx` line 67
  (WEBSITE-REVIEW-1 3.2.3): "to include and enable the µTest++ library
  in the build". Say that it is required: without it, the headers and
  the sources compile to nothing, and the first error is `use of
  undeclared identifier 'micro_os_plus'` (as the v5.0 notice and the
  User's Guide say).

  Fixed: the effect is added to the macro's entry in the list of
  preprocessor definitions.

- **#18 — The CMake section describes a single interface library.**
  (fixed) [template] `templates/docusaurus/common/docs/install/_common/_micro-os-plus/_cmake-integration-liquid.mdx`
  (WEBSITE-REVIEW-1 3.2.3): "The result is an interface library".
  `CMakeLists.txt` also defines
  `micro-os-plus::micro-test-plus-objects-library` and
  `micro-os-plus::micro-test-plus-static-library`. Document the three
  targets and when to use each: the interface library compiles the
  µTest++ sources in each consumer, the objects library shares one set of
  compiled object files, and the static library packs them in an archive
  (the configuration used by the tests). The choice concerns only how the
  µTest++ sources are built. It does not affect the static suites: the
  pitfall described in the FAQ applies to the application's own suite
  files, which must not be packed in a static library, whichever target
  is used for µTest++. (An earlier version of this item, and
  WEBSITE-REVIEW-1 3.2.3, linked the two.)

  Fixed: a project subsection, "CMake library targets", was added after
  the generated CMake section, in `_build-and-integration-info.mdx`, with
  a table of the three targets. The generated sentence was completed in the
  template (`_cmake-integration-liquid.mdx`): "The result is an
  interface library, whose sources are compiled in each target that
  links it". Pending: commit the template change.

- **#19 — The meson example is not valid meson.** (fixed) [template]
  `templates/docusaurus/common/docs/install/_common/_micro-os-plus/_meson-integration-liquid.mdx`
  (WEBSITE-REVIEW-1 3.2.3): `executable(your-target, link_with: [ #
  Nothing, not static. ], …)`. The name must be a quoted string, the
  sources are missing, and the empty `link_with` with its comment is
  unclear. Suggested: `exe = executable('my-test', sources: [
  'main.cpp' ], dependencies: [ micro_os_plus_micro_test_plus_dependency
  ])`.

  Fixed: the template example is now `executable('your-target',
  sources: ['main.cpp'], dependencies: [ … ])`, without the empty
  `link_with`. Pending: commit the template change. The example was not
  run through meson.

- **#20 — Semihosting is described as Arm semihosting only.**
  (fixed) [project] and [template] (WEBSITE-REVIEW-1 3.2.3, 3.7.8): the
  Integration Guide ("the most common approach is **Arm semihosting**",
  `_build-and-integration-info.mdx` line 18), the User's Guide
  ("Timings" and "Console output"), the FAQ ("forwarded to the host
  through Arm semihosting"), and the "Semihosting" section of the
  Contributor's Guide
  (`templates/docusaurus/common/docs/developer/_common/_micro-os-plus/_content-liquid.mdx`).
  The RISC-V platforms use RISC-V semihosting. Write "semihosting", and
  link both specifications in the Contributor's Guide.

  Fixed: "Arm semihosting" replaced by "semihosting" in the Integration
  Guide, the FAQ, and the User's Guide; the Contributor's Guide template
  now links the specification and says that it is defined by Arm and
  used with the same protocol on RISC-V (the RISC-V protocol is
  identical by design). Pending: commit the template change.

- **#21 — The preview shows an unpublished version.** (withdrawn) [template] The
  home page and the Integration Guide show `xpm install
  @micro-os-plus/micro-test-plus@6.0.0 --verbose`, and the navigation
  bar shows `6.0.0`, linked to its npm page. The version is
  `6.0.0-pre`; `customFields.ts` removes the `-pre` suffix. Version
  6.0.0 is not on npm, so the command fails and the link leads to a
  missing page. This is correct after the release; decide whether the
  preview should show the latest published version, or a note that
  the version is not yet released.

  Withdrawn: not a defect. The version is correct once 6.0.0 is
  released, as the page is meant to show the version being prepared.

- **#22 — `minimumXpmRequired` is shown as 0.20.7.** (fixed) [template]
  `templates/docusaurus/common/docs/install/_common/_reproducibility-and-dependencies-liquid.mdx`
  (WEBSITE-REVIEW-1 3.2.4); the project requires 0.20.8
  (`package.json`). Take the value from the top `package.json`.

  Fixed, with a correction of the finding: the snippet shows the
  `package.json` that `xpm init` writes in the user's project, not that of
  this library, so its value is not the 0.20.8 of this project's
  `package.json`. The current xpm (0.23.3, checked with `xpm init` and
  `npm view xpm`) writes its own version; the template now shows
  `0.23.3`. The value is still a literal, and will go stale with the next
  xpm release. Pending: commit the template change.

- **#23 — `xpm run deep-clean -C tests` fails.** (fixed) [template]
  `templates/docusaurus/common/docs/_common/_manual-tests-liquid.mdx`,
  and the "Clean-ups" section of the Contributor's and Maintainer's
  Guides. `deep-clean` is an npm script of `tests/package.json`, not an
  xpm action, and `xpm run` looks only in `xpack.actions`; it stops
  with `action "deep-clean" not found` (`xpm`
  `src/xpm/run-action.js`, `executeAction()`). Use `npm --prefix
  ~/Work/…/tests run deep-clean`, or add a `deep-clean` xpm action to
  the tests template.

  Fixed: `_manual-tests-liquid.mdx` now uses `npm --prefix …/tests run
  deep-clean` in both places (the Contributor's and Maintainer's Guides
  share the partial). `deep-clean` is an npm script, not an xpm action,
  in the `tests/package.json` of this project, `diag-trace`, and
  `utils-lists`. The `xpm run deep-clean --config …` commands of the
  xPack binary-package templates were not changed. Pending: commit the
  template change.

- **#24 — `npm run website-generate-commons` fails.** (fixed) [template]
  `templates/docusaurus/common/docs/_common/_prepare-website-liquid.mdx`
  (WEBSITE-REVIEW-1 3.7.11), shown in the Contributor's and Maintainer's
  Guides: the script is `generate-website-commons`, as the
  Maintainer's Guide itself writes a few sections earlier.

  Fixed: `_prepare-website-liquid.mdx` now uses
  `generate-website-commons` in both places. Pending: commit the template
  change.

- **#25 — The test logs of the Contributor's Guide come from older
  builds.** (fixed) [project] `docs/developer/_project/_test-details.mdx`
  (WEBSITE-REVIEW-1 3.7.9): the `ctest -V` logs show test commands with
  the options after the application arguments (`minimal-test "one"
  "two" "--output-file" … "--verbose"`), which the current parser
  would pass to the application; a `1..0` line inside a passed test
  case at the normal verbosity, which the current reporter no longer
  writes (a run of `minimal-test` shows a single `ok` line); the banner
  `µTest++ human report`; the trace type `test_case_name`, now
  `located_name`; and, without explanation, `error: test runner already
  initialised`, which the unit tests provoke on purpose
  (`tests/sources/unit-common/src/support.cpp` line 59). They also
  contain personal absolute paths (`/Users/ilg/…`, `/Users/ilg/.nvm/…`).
  Replace each log with one paragraph on what the program tests, the
  command that runs it, and a link to its reference output in
  `tests/expected/`; keep at most one short log, regenerated, in a
  `<details>` block.

  Fixed: `_test-details.mdx` is rewritten (84 lines, from 605): how the
  tests are run and compared (`compare-files.sh`, `validate-tap.mjs`), a
  table of the eleven test programs with what each tests and its
  reference outputs, the explanation that the intended failures are part
  of the reference outputs, and one folded example, the reference output
  of the minimal test. The links use the `xpack-development` branch (see
  #26). The descriptions of `unit-exceptions` and `unit-miscellaneous`
  were taken from the earlier page, and not checked against their
  sources. `tests/README.md` still says that there are five programs.

- **#26 — A link to the unit test sources leads to a missing file.**
  (fixed) [project] `docs/developer/_project/_test-details.mdx` line 306 links
  `blob/xpack/tests/sources/unit-checks/src/main.cpp`. The `xpack`
  branch (v5.0.1) has no `unit-checks` folder, so the link is broken
  until 6.0.0 is released. Either accept this until the release, or
  link the files on the branch from which the page is built.

  Fixed with #25: the page was rewritten, and its links use the
  `xpack-development` branch.

- **#27 — The CI description lists platforms that are not tested on
  every push.** (fixed) [template]
  `templates/docusaurus/common/docs/_common/_micro-os-plus/_continuous-integration-liquid.mdx`,
  shown in Getting Started, the Integration Guide, and the
  Contributor's Guide: "continuous integration (CI) testing with every
  push … Testing is conducted on … Cortex-M0, Cortex-M3, Cortex-M4F,
  Cortex-M7F, Cortex-A15, Cortex-A72, RISC-V RV32IMAC, and RV64IMAFDC".
  On a push, `test-ci` runs only `configs-ci` (`tests/package.json`):
  native clang (CMake and meson), native GCC (not on macOS), and QEMU
  Cortex-M0, Cortex-M7F, AArch64 A72, and RV32IMAC. The full list runs
  in the manually triggered `test-all`, and it also includes
  Cortex-M33, which the text omits. Distinguish the two, and take the
  platform list from the project configuration.

  Fixed in the template (checked 2026-11-02, after regeneration): the
  text now says "a selection of" the platforms, and adds that an optional
  workflow, triggered manually, tests all the platforms and
  configurations (`test-all.yml` has `workflow_dispatch`). Cortex-M33,
  which `test-all` runs, was added to the list, the paragraph was
  rewrapped, and the final newline added. The list is still hard-coded,
  so it is the same for all packages. Pending: commit the template
  change.

- **#28 — The list of target platforms is out of date.** (fixed) [template]
  `templates/docusaurus/common/docs/developer/_common/_micro-os-plus/_content-liquid.mdx`
  (WEBSITE-REVIEW-1 3.7.6): `platforms/native` is now
  `platforms/synthetic-posix`, and the list omits `qemu-cortex-m33`,
  the `nucleo-*` boards, and the `raspberry-pi-*` boards
  (`tests/platforms/`). List them, separating the QEMU platforms (run
  in CI) from the physical boards (run by hand).

  Fixed: the "Target Platforms" section of the template
  `_content-liquid.mdx` now builds its lists from `platforms` in
  `tests/config/tests-templates.json`, in three groups: the native
  platform (`synthetic-posix`), the QEMU platforms, and the physical
  boards (the others). The per-platform descriptions (QEMU board
  models) were dropped, since they cannot be derived from the names.
  To make `testsConfig` available to the website templates,
  `generate-website-commons.mjs` in `docusaurus-template-liquid` now
  passes the `tests` folder to `computeContext()` when it exists.
  Caveats: the platforms that are not yet functional
  (`raspberry-pi-zero-2-w-*`, according to `CLAUDE.md`) are listed with
  the others; and a package without a `tests-templates.json` gets no
  list. Pending: commit the changes in `docusaurus-template-liquid`.
  During the work, a failed generation deleted the generated files in
  `website/`; they were restored by a successful run.

- **#29 — The RISC-V toolchain is misspelt.** (fixed) [template] Same template
  (WEBSITE-REVIEW-1 3.7.7): `risc-none-elf-gcc` should be
  `riscv-none-elf-gcc`.

  Fixed: `riscv-none-elf-gcc` in the template. Pending: commit the
  template change.

- **#30 — The host platforms include Windows 7 and 8.** (fixed) [template]
  Same template (WEBSITE-REVIEW-1 3.7.5). Node.js 20, required by
  `package.json`, does not support them; update the list.

  Fixed: the list now has Windows 10 and Windows 11, the versions that
  Node.js 20 supports (not checked against the Node.js documentation).
  The mention of the Universal C Runtime was dropped, since it is part
  of Windows 10. Pending: commit the template change.

- **#31 — The Contributor's Guide requires Node.js 18.** (fixed) [template]
  Same template, `<CommonPrerequisites nodeVersion="18.0.0"/>`
  (WEBSITE-REVIEW-1 3.7.2); the Maintainer's Guide shows 20.0, which
  `package.json` (`engines.node: >=20.0`) requires. The blog template
  passes `nodeVersion="18.0.0"` too, to a partial that ignores it
  (WEBSITE-REVIEW-1 3.11.3). Use `enginesNodeVersion` from
  `customFields` in both.

  Fixed: the Contributor's Guide template and the project's blog post
  template (`blog/_templates/blog-post-release-liquid.mdx`) now use
  `{{packageEnginesNodeVersion}}` (and `…Major`), as the Maintainer's
  Guide does, so the generated guide shows 20.0. The 24 existing posts
  keep their literal `18.0.0`, by decision: a post records the
  requirement at the time of its release. Pending: commit the template
  change.

- **#32 — One command uses a different work folder.** (fixed) [template] Same
  template, line 36 ("Satisfy dependencies", WEBSITE-REVIEW-1 3.7.3):
  `cd ~/Work/xpack/micro-os-plus/…`; every other command uses
  `~/Work/micro-os-plus/…`.

  Fixed: `cd ~/Work/{{githubProjectOrganization}}/…` in the template.
  Pending: commit the template change.

- **#33 — The code formatting instructions are out of date.**
  (fixed) [template] `templates/docusaurus/common/docs/_common/_code-formatting-liquid.mdx`
  (WEBSITE-REVIEW-1 3.7.10), shown in both guides: VS Code is said to
  use the `.clang-format` file directly, and the Eclipse CppStyle
  plug-in is recommended. The configuration is in
  `maintenance/config/`, with no `.clang-format` at the root. Document
  the top-level actions `xpm run clang-format`, `cmake-format`,
  `jsonc-format`, and `prettier`, and give the command in the
  Maintainer's Guide step "Reformat source files" (WEBSITE-REVIEW-1
  3.8.3).

  Fixed: `_code-formatting-liquid.mdx` now says that the configuration is
  in `maintenance/config`, gives the command `xpm run clang-format -C …`,
  mentions the `cmake-format` and `jsonc-format` actions, and says that
  `clang-format` comes from the development dependency (`xpacks/.bin`).
  The VS Code and Eclipse instructions were removed, since they could not
  be verified; the `prettier` action, which exists only in this project,
  is not mentioned. The Maintainer's Guide step "Reformat source files"
  now names the action and links the section. Pending: commit the
  template changes.

- **#34 — "Edit this page" opens a generated file on the `website`
  branch.** (fixed) [template] `docusaurus.config.ts` lines 102 and 116 set
  `editUrl` to `…/edit/website/website/`. The link of the User's Guide
  opens `docs/user/index.mdx`, which only imports
  `_project/_content.mdx`; the same holds for every page with
  partials. An edit made there is overwritten by the next regeneration,
  and is proposed against the `website` branch, not `xpack-development`
  (to which, as the guides say, the pull requests must go). For the
  same reason, "Last updated" shows the date of `index.mdx` (the User's
  Guide says "Oct 12, 2026", although its content changed on
  2026-11-02). Point `editUrl` to `xpack-development`, and either hide
  the link on the pages built from partials or replace it with a link
  to the partial.

  Fixed, by decision (hide the links): `editUrl` is removed from the
  docs and blog presets in `docusaurus.config-liquid.ts`, so no page
  shows "Edit this page". This applies to every site generated from the
  template. The "Last updated" date remains (`showLastUpdateTime`), and
  still shows the date of the generated `index.mdx`, not of the content
  (see above). Pending: commit the template change.

- **#35 — A blog post names the `details` namespace.** (fixed) [project]
  `blog/2026-05-12-micro-test-plus-v4-1-1-released.mdx`
  (WEBSITE-REVIEW-1 3.11.5); the namespace is `detail`.

  Fixed: `details` replaced by `detail`.

- **#36 — The release posts show `-verbose` with a single dash.**
  (fixed) [template] All 24 release posts and
  `templates/docusaurus/first-time/blog/_templates/_micro-os-plus/blog-post-release-liquid-liquid.mdx`
  (WEBSITE-REVIEW-1 3.11.1). Use `--verbose`, and fix the existing
  posts.

  Fixed: `--verbose` in the 24 posts, in the project's blog template, and
  in the first-time template. Pending: commit the template change.

- **#37 — The Maintainer's Guide places the website configuration in
  `website/package.json`.** (fixed) [template] Step "Update the
  `websiteConfig`" (WEBSITE-REVIEW-1 3.8.2); it is in
  `website/config/website-templates.json`.

  Fixed: `_update-website-config-liquid.mdx` now refers to
  `website/config/website-templates.json`, with the heading "Update the
  website configuration (if necessary)", and says that the version comes
  from the top `package.json` (as `customFields.ts` does). The earlier
  wording about "release-specific properties, like the version and
  release date" was dropped. Pending: commit the template change.

- **#38 — A page is called "Maintainer Info".** (fixed) [template]
  `templates/docusaurus/common/docs/_common/_start-local-web-server-liquid.mdx`
  (WEBSITE-REVIEW-1 3.8.6); the page is the Maintainer's Guide.

  Fixed: "Maintainer's Guide" (with the `s` when `usePluralGuides` is
  set, as in the sidebar and the page title). Pending: commit the
  template change.

- **#39 — The sidebar "License" link ignores the Boost licence.**
  (withdrawn) [template] `templates/docusaurus/common/sidebars-liquid.ts`, generated
  `sidebars.ts` line 79 (WEBSITE-REVIEW-1 2.2.2): it opens
  `https://opensource.org/license/mit`. The project is distributed under
  the MIT licence and, for the Boost-derived parts, the Boost Software
  License (Getting Started, "Licence"). Link the repository `LICENSE`
  file, or the "Licence" section of Getting Started.

  Withdrawn, by decision: the sidebar link is kept as it is.

- **#40 — The User's Guide says both that the suites run
  alphabetically and that they do not.** (fixed) [project]
  `docs/user/_project/_content.mdx`, admonition "Suites run by name,
  not in the order of the calls" (section "Non-static test suites"):
  "sorted alphabetically by name (see above)". The section above, and
  the FAQ, say that the names are compared byte by byte, as with
  `strcmp()`, "not alphabetically" (`"Zeta"` before `"alpha"`). Write
  "sorted by name, byte by byte (see above)".

  Fixed: "sorted by name, byte by byte (see above)".

- **#41 — The Contributor's Guide shows the licence badge twice.**
  (fixed) [template] `docs/developer/index.mdx` lines 28 and 32
  (WEBSITE-REVIEW-1 3.7.1), generated from
  `templates/docusaurus/common/docs/developer/index-liquid.mdx`. Remove
  one.

  Fixed: the second badge, after the code style badges, is removed from
  the template. Pending: commit the template change.

- **#42 — Two different commands install the test dependencies.**
  (fixed) [template] (WEBSITE-REVIEW-1 3.7.4) "Satisfy dependencies" runs
  `xpm install -C tests`, and "Manual tests" runs `xpm run install -C
  tests`; neither mentions `xpm run link-dependencies -C tests`, which
  is needed when the dependencies are linked writable projects. Say
  which command to use, and when.

  Fixed, by decision without `link-dependencies`: the commands are not
  contradictory (`xpm run install` runs `xpm install` and then installs
  the toolchains of the configurations; `tests/package.json`), so
  "Satisfy dependencies" now says what its last command installs and
  refers to "Manual tests" for the toolchains. Pending: commit the
  template change.

- **#117 — The FAQ and the User's Guide name the wrong stdio function.**
  (fixed) [project] `docs/faq/_project/_content.mdx` line 140 and
  `docs/user/_project/_content.mdx` line 1685 (section "Console
  output"): the reporters write through `vfprintf()`, `fputs()`, and
  `fflush()`. The reporters call `vfprintf()`, `fwrite()`, and
  `fflush()` on `stdout` (`src/reporter.cpp` lines 357, 447, 527, and
  623), and never `fputs()`. The advice (route `stdout` and the
  `printf()` family to the same destination) is unchanged.

  Fixed: `fputs()` replaced by `fwrite()` in both places.

## 2. Version history

- **#43 — Two compatibility notices give wrong dates.** (fixed) [project]
  `docs/getting-started/_project/_compatibility-notices.mdx`: "v4.0
  (2026-04-20)" (line 413, WEBSITE-REVIEW-1 3.2.1); the tag, the npm
  publication, and the blog post are dated 2026-04-29. "v5.0
  (2026-08-06)" (line 360); v5.0.0 was published on npm and announced
  on 2026-07-14, and only its tag was recreated on 2026-08-06, the day
  of v5.0.1. Use 2026-04-29 and 2026-07-14.

  Fixed: v4.0 (2026-04-29) and v5.0 (2026-07-14).

- **#44 — Two notices refer to versions that were never tagged.**
  (fixed) [project] Same file: "v2.3.0 (2022-02-19)" (line 431, WEBSITE-REVIEW-1
  3.2.1) has no tag and no post, and uses three numbers where the
  others use two; "v1.0 (2021-02-04)" (line 441) has no tag either,
  and the v1.1.0 post says "Version 1.1.0 is the first release". Say
  in which published versions these changes shipped (v2.1.1 or v3.0.0;
  v1.1.0).

  Fixed, from the git history: the `run_test_case` deprecation (commit
  `436a1ae2`, 2022-02-19) is first contained in the tag v3.0.0, so its
  text moved into the v3.0 entry, and the v2.3.0 section was removed.
  The v1.0 heading is now "v1.1 (2021-02-05)", the first tag and the
  first release.

- **#45 — The v5.0.0 post lists the breaking changes as enhancements.**
  (fixed) [project] `blog/2026-07-14-micro-test-plus-v5-0-0-released.mdx`
  (WEBSITE-REVIEW-1 3.2.2): "Major changes: None", with two of the
  breaking changes under "Enhancements", and "updated for xcdl
  configuration" in the summary, although the xcdl tool is not
  available. The v5.0 compatibility notice describes four breaking changes
  (the required `MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED`, the removed
  `config.h` mechanism, the five renamed macros, and the renamed CMake
  OBJECT library), besides less important ones (the include guards, the
  C++20 error, and the meson dependency). Move the four to "Major
  changes", and link the notice.

  Fixed: the four breaking changes are under "Major changes", the
  enhancements are the new STATIC library, the include guards, and the
  C++20 error, and the summary line says "new major release; the C++ API
  is unchanged … in preparation for the xCDL configuration". The stale
  paragraph about 5.0.1 was already removed. A link from the v5.0
  compatibility notice points to the "Detailed changes" section
  (`#details`).

- **#46 — Two published versions have no post.** (fixed) [project]
  (WEBSITE-REVIEW-1 3.10.2) v3.2.1 (2025-03-14) and v4.1.0
  (2026-05-11) are tagged and on npm, but the Releases page and the
  blog skip them. The v4.1.1 post describes the changes of v4.1.0
  without saying so; add one sentence to it, and one to the v3.2.2
  post.

  Fixed, with a correction: the git history shows that both versions had
  a post (`d89c8511` for 3.2.1, `bb42b969` for 4.1.0), which was deleted
  when the next patch version, published within hours, replaced it
  (`ed2ee938`, `b77ea4d3`). The v3.2.2 and v4.1.1 posts now say that the
  earlier version contains the same fixes or changes and has no separate
  post. The Releases page still lists 24 versions, without 3.2.1 and
  4.1.0, as intended.

- **#47 — The History page stops at v4.0 and contradicts the other
  pages.** (fixed) [project] `docs/project/history/_project/_content.mdx`
  (WEBSITE-REVIEW-1 3.2.7): the heading "April 2026" introduces "In
  March 2026", and "April 2022" introduces "At the beginning of 2022";
  it says that the v4 rework added the TAP reporter, which v3.3 added;
  there is no entry for v4.1, v5, or the coming v6; and all the
  headings are level 3, under no level-2 heading.

  Fixed: `_project/_content.mdx` of the History page is rewritten, with
  level-2 headings that give the month and the version; the TAP reporter
  is attributed to v3.3 and the explicit objects to v4.0; entries were
  added for v4.1 and v5.0 (a short explanation of why the configuration
  changed), and a longer one for v6.0 (the systematic reviews, their
  findings, the themes of the rework, and the deprecated definitions).
  The reasons given for v5.0 are taken from the v5.0 notice and the
  commits, not from a statement of the author; please check them.

- **#48 — The User's Guide repeats the history, up to v4.** (fixed) [project]
  `docs/user/_project/_content.mdx`, "Overview" (WEBSITE-REVIEW-1
  3.2.8). Replace it with one sentence and a link to the History page.

  Fixed, by decision (not replaced by a single sentence): the Overview
  keeps its sentences on v1, v3, and v4, adds one on the review and
  rework of v6, and links the History page for the details.

- **#49 — The v4.0 notice seems to contradict the Features list.**
  (fixed) [project] (WEBSITE-REVIEW-1 3.2.1) "Internal static objects are no
  longer used" (line 413) against "each test suite can be defined as a
  static global object … registration … via the C++ static
  constructors" (`_features.mdx`). Both are true, but one sentence
  should say that only the framework's own static objects were removed,
  and that the static suites are application objects.

  Fixed: the v4.0 notice now says that the static objects of the framework
  itself (the runner and the reporter) are no longer used, and that the
  static suites remain objects of the application, which register
  themselves with a runner.

- **#50 — Getting Started says that the notices are in the release
  notes.** (withdrawn) [template]
  `templates/docusaurus/common/docs/getting-started/index-liquid.mdx`
  (WEBSITE-REVIEW-1 3.3.4): "This information … is readily available in
  the respective release notes". The release posts list "Major
  changes: None" even for v5.0.0 (#45). Remove the sentence.

  Withdrawn: the release posts of v4.0, v5.0, and v6.0 now describe the
  breaking changes (see #45), so the sentence is correct for the recent
  versions. The posts of the earlier major versions were not checked.

## 3. Structure

### Getting Started

- **#51 — The page leads with logistics, and the notices dominate
  it.** (fixed) [template] (WEBSITE-REVIEW-1 3.3.1) A new reader passes the
  xpm explanation, Install, Status, Testing, Release schedule,
  Releases, Change log, and Support before the compatibility notices,
  which are now about 300 lines of the page (the v6.0 notice alone is
  some 200 lines of rendered text). Suggested order: Overview, a
  minimal example with its output, Features, Status, "Where to go
  next" (the three guides and the API reference), and then the project
  information. Move the notices to their own page (#112).

  Fixed, by decision: the notices no longer dominate the page (the
  v6.0 text moved to the release post), and a "Where to go next" section
  was added after "Status", in its own project partial,
  `_project/_where-to-go-next.mdx`, linking the
  Integration Guide, the User's Guide, and the API reference. The
  "What are xpm packages?" section now follows the Install summary,
  after the Features (template `_content-liquid.mdx` of the µOS++
  variant). Not done: the notices were not moved to a page of their own
  (#112). Pending: commit the template changes.

- **#52 — The Features list is said to be derived from Boost UT.**
  (fixed) [project] `docs/getting-started/_project/_features.mdx`
  (WEBSITE-REVIEW-1 3.3.2, 3.3.3): "largely derived from Boost UT" is
  followed by features that are not (suites, TAP, registration). Say
  which parts are derived (the comparators and the deprecated
  operators and literals). Move "(which consequently raised the
  minimum C++20 requirement across the entire µOS++ project)" to the
  History page, and add "(the tests are written in C++20)" to the
  first bullet.

  Fixed, by decision (keep Boost UT as an inspiration, focus on TAP and
  node-tap): the introduction now says that the model, with the suites,
  the test cases, and the TAP results, follows Node TAP, and that the
  function comparators were inspired by Boost UT. The list starts with
  TAP and the suites and test cases. The first bullet says that the tests
  are written in C++20. The remark on the C++20 requirement of µOS++ moved
  to the History page (the v3.0 entry, since the C++20 commit is from
  February 2022 and the v3.0.0 README requires `-std=c++20`).

### Integration Guide

- **#53 — The sections do not follow the reader's task.** (fixed) [template]
  `templates/docusaurus/common/docs/install/` (WEBSITE-REVIEW-1 3.6.1):
  Uninstall and npm installation come before the integration
  information, which gives the page its name. Suggested order:
  Prerequisites, Install, Integrate (CMake, meson, other build
  systems), Configure, Alternatives, Uninstall.

  Fixed, with one deviation: the order is now Automated installation
  (prerequisites, initialisation, installation via xpm, details, folder
  hierarchy, uninstall), Integration (include folders, source files,
  compiler options, dependencies, CMake, CMake library targets, Meson),
  Configuration (the preprocessor definitions, split from the integration
  partial into `_project/_configuration.mdx`), and Alternative
  installation (npm, copying the files, Git submodule). The uninstall
  section stays after the installation via xpm, since its partial is
  shared with the xPack binary packages and has a fixed heading level. The
  template `_content-liquid.mdx` of the install page has the new order, a
  first-time placeholder was added for `_configuration.mdx`, and
  `_manual-install-liquid.mdx` lost its own level-2 heading. The headings
  "Include folders", "Source files", and "Compiler options" are in sentence
  case, and "Build & Integration Information" is now "Integration"
  (this also covers part of #81). The site was built locally (`npm run
  build`): the first build found two broken anchors, caused by this change
  and by the new post summaries (a link to `#details` shown in the blog
  index, and a link in the User's Guide to the old heading), both fixed;
  the second build succeeded. Pending: commit the template changes.

- **#54 — "Status" and "Testing" repeat Getting Started.** (fixed) [template]
  (WEBSITE-REVIEW-1 3.6.2) Replace them with a link.

  Fixed, by decision: the "Testing" section (the CI description) is removed
  from the Integration Guide template (`_content-liquid.mdx` of the install
  page); its fragment, `docs/_common/_continuous-integration.mdx`, is still
  used by Getting Started and the Contributor's Guide. The "Status" section
  was kept. Pending: commit the template change.

### Contributor's and Maintainer's Guides

- **#55 — The Maintainer's Guide repeats the Contributor's Guide.**
  (withdrawn) [template] (WEBSITE-REVIEW-1 3.7.12) Both pages contain the
  prerequisites, the sources and branches, the development links, the
  code formatting, the manual tests, the clean-ups, and the website
  procedures, almost word for word; they have already diverged (Node.js
  18 and 20, #31). Keep these sections in the Contributor's Guide, and
  link them from the Maintainer's Guide, which a maintainer reads after
  it.

  Withdrawn, by decision: the repetition is intended. Both pages import the
  same fragments from `docs/_common` (the prerequisites, the project and
  helper sources, the code formatting, the manual tests, and the website
  procedures: ten in common), so that no page has to link to the other. The
  divergence found in the review (Node.js 18 and 20) came from a property
  passed to a fragment, and was fixed with #31.

### Navigation and supporting pages

- **#56 — The Glossary is missing from the navigation bar.**
  (withdrawn) [template] `templates/docusaurus/common/docusaurus.config-liquid.ts`
  (WEBSITE-REVIEW-1 2.2.2): the "Documentation" menu lists every guide
  and About, but not the Glossary, which is reachable only through the
  sidebar.

  Withdrawn, by decision: the Glossary does not need an entry in the
  top menu; it stays reachable from the sidebar.

- **#57 — The Glossary defines three terms.** (fixed) [project]
  `docs/getting-started/glossary/index.mdx` (WEBSITE-REVIEW-1 3.4.1):
  only the ISTQB test condition, test case, and test suite. Add one
  line each for runner, top suite, static suite, check, expectation,
  requirement, comparator, reporter, TAP, xpm, and xPack, which the
  site uses throughout.

  Fixed, by decision: the terms that ISTQB already defines are not
  redefined: the ISTQB section keeps test condition, test case, and test
  suite, each with its implementation in µTest++ (check, expectation, and
  requirement; nested test cases; the top, added, and static suites). A
  second section, "Other µTest++ terms", defines the runner, the comparator,
  and the reporter, and "Protocols and tools" defines TAP, node-tap, xpm,
  and xpm package (xPack). The definitions were written from the User's Guide and the
  code, and not reviewed by the author. This also covers #58.

- **#58 — The Glossary's suite omits the suite kinds.** (fixed) [project] Same
  file (WEBSITE-REVIEW-1 3.4.3): "instances of the `suite` class" omits
  `static_suite` and `top_suite`, and does not say that suites are
  created with `add_suite()` or as `static_suite` objects.

  Fixed with #57: the "test suite" entry now lists the top suite, the
  suites added with `add_suite()`, and the static suites.

- **#59 — The Help Centre asks the reader to check a documentation it
  does not link.** (fixed) [template]
  `templates/docusaurus/common/docs/support/index-liquid.mdx`
  (WEBSITE-REVIEW-1 3.9.1): "Check documentation" has no link, since
  `docs/_project/_documentation.mdx` is empty by decision. Refer to the
  sidebar, or list the guides in the template sentence. The page also
  does not mention the "Edit this page" link as the quickest way to
  report a website error (WEBSITE-REVIEW-1 3.9.4; but see #34).

  Fixed, in the project fragment, with no template change:
  `docs/_project/_documentation.mdx`, which the Help Centre already
  imports, now lists the Integration Guide, the User's Guide, and the API
  reference. The "Where to go next" section of Getting Started renders the
  same fragment, so that the list exists in one place. The Getting Started
  page is not in the list, to avoid a link from that page to itself. This
  reverses the earlier decision to keep the fragment empty (WEBSITE-REVIEW-1
  2.4.4). Not built.

- **#60 — The Discord channels are not verified.** (fixed) [template] Help
  Centre (WEBSITE-REVIEW-1 3.9.3): "`#rtos`" and "`#general`". Check
  that they exist, and whether one is intended for testing questions.

  Fixed in part, by the author: the invitation links were updated in the
  templates (`support/index-liquid.mdx` and `docusaurus.config-liquid.ts`,
  for the footer) to the `https://discord.gg/…` form. The links and the
  channel names `#rtos` and `#general` were not checked by me, since the
  server needs an account. Pending: commit the template changes.

### Blog

- **#61 — The "Prerequisites" section of the posts describes the
  manual installation.** (fixed) [template]
  `templates/docusaurus/common/blog/_micro-os-plus/_common/_prerequisites-liquid.mdx`
  (WEBSITE-REVIEW-1 3.11.4): its second paragraph, on copying the files
  or adding a submodule, is not a prerequisite. Move it under
  "Installation".

  Fixed: the paragraph is removed from the shared partial
  (`_prerequisites-liquid.mdx` of the blog), and added at the end of the
  "Install" or "Installation" section, before the pointer to the
  installation guide, in all 25 release posts, in the project's blog
  template, and in the first-time blog template. Pending: commit the
  template changes.

### User's Guide

- **#62 — The concepts are listed before they are defined.**
  (fixed) [project] `docs/user/_project/_content.mdx`, "Concepts and features"
  (WEBSITE-REVIEW-1 3.5.1): the first bullet, "test cases may be
  organised into test suites", precedes the definition of both. Order
  them from the top: runner, suite, test case, check, reporter.

  Fixed: the list now starts with the runner, then the test suite, the test case, the checks (expectations and requirements), and the reporter, in the order of the review. The list was rewritten, and the output file bullet is last.

- **#63 — The counting of the checks is misstated.** (fixed) [project] Same
  section (WEBSITE-REVIEW-1 3.5.2): "For expectations, the runner
  maintains a count of occurrences". Write "The runner counts the
  passed and the failed checks".

  Fixed with #62: the runner bullet says that it counts the passed and failed checks.

- **#64 — The utility functions are listed without a description.**
  (fixed) [project] "Utility functions" (WEBSITE-REVIEW-1 3.5.11): `is_match()`
  and `split()` are shown as declarations only. Say what they do
  (`*`, `?`, and `|` patterns, as in `--filter`; splitting at
  delimiters), and that `split()` returns a `std::vector`, which uses
  the heap.

  Fixed, with a correction: `is_match()` supports only `*` and `?`; the `|`
  that separates alternatives is handled by the runner around it, in the
  `--filter` option (`src/runner.cpp`), not by the function. The guide now
  describes `is_match()` (whole input, case-sensitive, `*` and `?`) and
  `split()` (any delimiter character, empty parts omitted, views or copies
  according to the type, heap allocation).

- **#65 — "Checking exceptions" does not cover builds without
  exceptions.** (fixed) [project] (WEBSITE-REVIEW-1 3.5.19) `throws()` and
  `nothrow()` exist only when `__cpp_exceptions` is defined
  (`exceptions.h` line 133). Say so, and show how to guard such
  checks.

  Fixed: the section now describes the three forms, shows examples, says
  that the functions exist only when `__cpp_exceptions` is defined
  (`exceptions.h`), and shows how to guard them. The examples were compiled and run
  with exceptions, and a probe confirmed that `mt::throws` does not exist
  with `-fno-exceptions`.

- **#66 — The suite arguments are promised but not shown.** (fixed) [project]
  "More complex tests" (WEBSITE-REVIEW-1 3.5.15) promises suites
  "invoked, potentially multiple times with different arguments". The
  additional arguments of `add_suite()`, `test()`, and `static_suite`
  are described in "Test cases", but no example passes them; add one
  (the `Args suite` of `tests/sources/sample/`).

  Fixed: "More complex tests" now shows a suite function with a parameter
  added twice with `add_suite()`, with different arguments. The example was
  compiled (no warnings with `-Wall -Wextra -Wshadow`) and run; the second
  sentence, on `static_suite`, follows the "Args suite" of the sample program.

- **#67 — The real-world example does not stand alone.** (fixed) [project]
  "Example" (WEBSITE-REVIEW-1 3.5.16, 4.3): it uses µOS++ types and an
  `sr` that the snippet does not declare, and calls `initialize()` and
  `uninitialized()`, which a reader may take for alternative spellings
  of the framework API. Add `extern mt::runner sr;` and one sentence
  saying that these are the µOS++ `utils-lists` names, or replace the
  example with a link to `tests/sources/sample/src/`.

  Fixed: `extern mt::runner sr;` was added, and the introduction now says
  that the types belong to another µOS++ package, that `initialize()` and
  `uninitialized()` are its functions with the American spelling, and that
  the runner is defined in another file. The package is not named, since
  the type `static_double_list_links` of the example could not be traced to
  a single package in the current sources. The example was not compiled.

- **#68 — "Static test suites" omits the static library pitfall.**
  (fixed) [project] (WEBSITE-REVIEW-1 3.5.12) The FAQ now explains why static
  suites compiled into a static library do not run; the section that
  introduces them does not. Add one sentence and a link to the FAQ
  entry.

  Fixed: a paragraph at the end of the description of the static suites
  explains that their object files must not be packed in a static library,
  and links to the FAQ page (the FAQ entries are collapsible blocks without
  an anchor).

- **#69 — "C API" is a top-level section with two sentences.**
  (withdrawn) [project] (WEBSITE-REVIEW-1 3.5.20) The FAQ has the same content
  ("Can µTest++ be used to test C code?"). Remove the section, or
  merge it into the Overview.

  Withdrawn, by decision: the section is kept, to state explicitly that
  there is no C API.

- **#70 — "Explicit Namespaces" repeats "Namespaces".** (fixed) [project]
  (WEBSITE-REVIEW-1 3.5.17) The alias it recommends is used in every
  example. Merge it into "Namespaces".

  Fixed, as decided: the "Explicit Namespaces" section is merged into
  "Namespaces", with its advice and the alias example (the stray braces of
  the example were removed); the `operators` and `literals` namespaces are
  no longer listed there, and the section points to "Deprecated operators,
  literals, and wrappers". The info box was dropped (this also covers #99).

- **#71 — The memory footprint figures cannot be reproduced.**
  (fixed) [project] "Memory Footprint" (WEBSITE-REVIEW-1 3.5.18): 105 552 and
  410 200 bytes, without the µTest++ and Boost UT versions, the
  toolchain, or the optimisation level. Add them, or regenerate the
  figures for 6.0.0.

  Fixed: the section now states µTest++ 6.0.0, Boost UT 2.3.1 (the latest
  version in `BOOST-UT-CHANGES.md`), the xPack GNU Arm Embedded GCC 15.2.1,
  and the `release` build with `-Os`, on the figures that the author
  updated. The versions were given by the author as "the current" ones; the
  exact GCC and Boost UT versions of the measurement were not checked. The
  contraction, "utilised", and "programme" were also corrected, and the link
  was moved out of the `<summary>`.

- **#72 — The verbose output is shown before the default output.**
  (fixed) [project] "TAP output" (WEBSITE-REVIEW-1 3.5.7): the first sample is
  the verbose output, and the default (normal) output, which a reader
  sees first, appears nowhere on the page. Show the default output
  first, then the verbose one, and say that it is selected with
  `--verbose`.

  Fixed: "TAP output" now shows the default output of the minimal test
  first, then says what the first two lines are and how `--verbose` changes
  the output, and then shows the verbose output (unchanged; its text matches
  a run of the program). The default output is the output of the program,
  with the toolchain line and the timings written as in the other samples.
  The later samples of the guide, which show `--verbose` output, keep their
  `main --verbose` command line.

## 4. Consistency

| # | Concept | Variants found (where) | Suggested |
| --- | --- | --- | --- |
| #73 (fixed) | `docs/install` guide | Integration Guide (sidebar, navigation bar); Installation Guide (page title, `install/index-liquid.mdx`; Getting Started link, `_install-summary-liquid.mdx` line 15); Install Guide (all 24 release posts, blog template); "How to install …" (H1) (WEBSITE-REVIEW-1 4.1 row 1) | Integration Guide; H1 "How to integrate the µTest++ Testing Framework" |
| #74 (fixed) | `docs/developer` guide | Contributor's Guide (title, sidebar); "developers" ("This page is designed for developers who intend to contribute"); `/developer/` (URL) (WEBSITE-REVIEW-1 4.1 row 2) | Contributor's Guide, "contributors"; keep the URL |
| #75 (fixed) | The human-readable reporter | "human-readable reporter" (User's Guide, 8); "human reporter" (compatibility notices, FAQ, User's Guide heading "The _human_ reporter" and its first paragraph); "(human)" (notice, line 290) | "human-readable reporter"; heading "The human-readable reporter"; keep `human` only as the option value |
| #76 (fixed) | node-tap | "node-tap" (Getting Started, User's Guide); "Node TAP" (History, User's Guide Overview) (WEBSITE-REVIEW-1 4.1 row 5) | node-tap |
| #77 (fixed) | Boost UT | "Boost UT" (13 places); "Boost.UT" (User's Guide comparison table and its notes) | Boost UT, as on the rest of the site |
| #78 (fixed) | TAP version | "TAP 14" (home page, FAQ); "TAP14" (User's Guide, History) | TAP 14 |
| #79 (fixed) | Licence | "Licence" (heading), "MIT Licence" (text), "License" (sidebar), `license`/`licence` (badge alt text, Contributor's and Maintainer's Guides) (WEBSITE-REVIEW-1 4.1 row 4) | Licence in text; "MIT License" and "Boost Software License" as proper names |
| #80 (fixed) | Website | "website" (everywhere); "web site" (title of `blog/2025-03-03-website.mdx`) (WEBSITE-REVIEW-1 4.1 row 8) | website |
| #81 (fixed) | Meson | "Meson" (text); "Meson Build" (heading, `_meson-integration-liquid.mdx`) | Meson; `meson` for the command |
| #82 (fixed) | The runner variable | `tr` (all examples); `sr` with the comment `// static runner` ("Static test suites", "Example") | `tr`; remove the comment, which refers to the deprecated `static_runner` |
| #83 (fixed) | The logical functions | "logical functions" (section heading, API group); "logical comparators" ("Custom Comparators") | logical functions |
| #84 (fixed) | Release schedule | "There are no fixed releases" (Maintainer's Guide); "continuous release strategy" (Getting Started) (WEBSITE-REVIEW-1 3.8.1) | one wording, in one partial |
| #85 (fixed) | Download badges | "all releases" for `dt` (Maintainer's Guide); "total downloads" for `d18m`, the last 18 months (blog) (WEBSITE-REVIEW-1 3.8.9) | the same badge, with an accurate label |
| #86 (fixed) | Heading case | title case: "Features & Benefits", "Support & feedback", "Enjoyed Using This Project? Please Let Us Know!", "Build & Integration Information", "Include Folders", "Source Files", "Preprocessor Definitions", "Compiler Options", "Meson Build", "Custom Types", "Custom Comparators", "Explicit Namespaces", "Memory Footprint", "Host Platforms", "Target Platforms", "Test Details", "Continuous Integration (CI)" (WEBSITE-REVIEW-1 4.2) | sentence case, "and" instead of "&" |
| #87 (fixed) | Sample outputs | the home page omits the time on the suite line and the totals line, without saying so; the User's Guide samples keep both, and omit `# Running:` only on some; the human-readable samples omit `, time: …` on the suite lines, which the reporter writes | full outputs, regenerated from runs; or one note per page saying what is omitted |

The rows of the table are fixed as follows:

- #73: Fixed: the page title and the guide's name in the Getting Started summary and in the blog templates come from `customInstallLabel` ("Integration Guide"), the H1 is "How to integrate the µTest++ Testing Framework" when the label contains "Integration", and the link text in all 25 posts is "Integration Guide".
- #74: Fixed: "contributors" in the description and in the introduction of the Contributor's Guide (template `developer/index-liquid.mdx`). The `/developer/` URL is kept.
- #75: Fixed: the heading is "The human-readable reporter" and its first paragraph uses the same name; the other uses had been changed earlier. `(human)` in the detailed changes of the v6.0.0 post is now "(human-readable reporter)". The title of issue #162 on GitHub still says "human reporter".
- #76: Fixed: "node-tap" everywhere in the pages (History, Overview, Features).
- #77: Fixed: "Boost UT" in the comparison table and its notes.
- #78: Fixed: "TAP 14" in the User's Guide and in the History page.
- #79: Fixed: "Licence" in the sidebar label, "MIT License" in Getting Started as a proper name, and `licence` as the alt text of the badges, in the templates.
- #80: Fixed: "website" in the title and the SEO title of the post.
- #81: Fixed: the heading is "Meson" (template `_meson-integration-liquid.mdx`).
- #82: Fixed: `tr` in the static suite examples and in the real-world example; the comment `// static runner` was removed.
- #83: Fixed: "logical functions" in "Custom comparators".
- #84: Fixed: the Maintainer's Guide template renders the project fragment `docs/_project/_release-schedule.mdx`, as Getting Started does, so the wording ("continuous release") is written once.
- #85: Fixed: both fragments list the latest version, the last month downloads (`dm`), and the total downloads (`dt`); the blog fragment used `d18m`, the last 18 months, for "total downloads".
- #86: Fixed in the templates and the pages: "Features and benefits", "Support and feedback", "Enjoyed using this project? Let us know!", "Custom types", "Custom comparators", "Memory footprint", "Host platforms", "Target platforms", "Continuous integration (CI)", "Continuous integration tests" in the posts, and "Meson" (#81). The headings of the Integration Guide were changed earlier (#53).
- #87: Fixed, by a note: the home page says that the header lines, the timings, and the totals are omitted. The samples of the User's Guide that were regenerated (the default and verbose TAP output, the human-readable output, the timings) are full outputs; the other samples were not changed.

## 5. Language and style

- **#88 — "After following the links" is unclear.** (fixed) [project]
  `docs/install/_project/_install-folder-hierarchy.mdx` line 6
  (WEBSITE-REVIEW-1 3.6.3). Write "Following the
  `xpacks/@micro-os-plus/micro-test-plus` link, the installed package
  contains:".

  Fixed: "Following the `xpacks/@micro-os-plus/micro-test-plus` link, the installed package is a folder hierarchy that includes only …".

- **#89 — Inflated vocabulary.** (fixed) [template] and [project]
  (WEBSITE-REVIEW-1 5.1) Outside the API pages, forms of "utilise"
  occur 44 times (Contributor's Guide 12, Maintainer's Guide 9,
  Integration Guide 8, Help Centre 8, Getting Started 4, User's Guide
  2, About 1), "comprehensive" 11 times, "it is advisable" twice
  (Help Centre, User's Guide), and "readily" twice. Replace "utilise"
  with "use" everywhere, and remove "comprehensive" and "readily"
  unless they distinguish something.

  Fixed: all the forms of "utilise" became "use", "uses", "used", and "using" in 90 files (the templates, the project pages, and the posts); "Comprehensive instructions" became "Detailed instructions"; the other "comprehensive", "readily", and "advisable" phrases were removed or rephrased (the sentence on the notices in Getting Started now says "The details are in the respective release notes."). None of the four words remains outside the API pages. The templates are shared with the xPack sites, which are also changed.

- **#90 — "Programme" is used for software.** (fixed) [template] and [project]
  User's Guide line 1602 ("the overall programme size"), and "the
  doxygen programme" (`_regenerate-doxygen-liquid.mdx`, in both
  guides). In British English, a computer program is spelt "program".

  Fixed: "program size" (User's Guide, with #71) and "the doxygen program" (template). "Programme" remains in the MacStadium credits, where it is the name of a sponsorship programme.

- **#91 — Informal headings and admonition titles.** (fixed) [template]
  (WEBSITE-REVIEW-1 3.3.5, 3.9.2) "What the heck are xpm packages
  (xPacks)? Please, do not introduce another package format!"
  (`_what-are-xpm-packages.mdx`); "Please, please, please!" (Help
  Centre); "Enjoyed Using This Project? Please Let Us Know!"
  (`_enjoyed-using-liquid.mdx`); "Getting Started!" (home page,
  `HomepageFeatures/index.tsx`). Suggested: "Why xpm packages, and not
  another package format?"; "Private email"; "Support the project";
  "Getting Started".

  Fixed: "Why xpm packages, and not another package format?", "Private email", "Enjoyed using this project? Let us know!", and "Getting Started" on the home page.

- **#92 — The website post is informal.** (fixed) [project]
  `blog/2025-03-03-website.mdx` (WEBSITE-REVIEW-1 3.11.7): "The new kid
  on the block", "a static site (kind of)", "lots of JavaScript code";
  the last sentence has no full stop.

  Fixed: the three phrases were rewritten ("The pages are written in MDX, a format that integrates JSX with markdown"; "The result is a static site, enhanced with JavaScript code specific to React components"), and the last sentence has its full stop.

- **#93 — A comma splice in "Non-static test suites".** (fixed) [project]
  `docs/user/_project/_content.mdx` line 1362: "However they are not
  mandatory, test suites can be manually added to the runner." Write
  "However, they are not mandatory; suites can also be added to the
  runner explicitly, with `add_suite()`."

  Fixed: "However, they are not mandatory; suites can also be added to the runner explicitly, with `add_suite()`."

- **#94 — "Until 5.0" is ambiguous.** (fixed) [project] Same file, line 366:
  "Until 5.0, `initialise (argc, argv, name)` also created and returned
  the top suite". It did so up to 5.0.1, and still does when the
  deprecated definitions are enabled. Write "Before 6.0.0".

  Fixed: "Before 6.0.0".

- **#95 — The static suite example shadows its parameter.** (fixed) [project]
  Same file, "Static test suites" (WEBSITE-REVIEW-1 3.5.13): the nested
  lambda parameter `t` shadows the outer `t` (clang
  `-Wshadow-uncaptured-local`, confirmed by a compilation of the
  example), and the variable is named `suite`, the name of a class of
  the same namespace. Use `t` and `nt`, as in "Nested test cases", and
  name the variable `static_suite_1` or similar.

  Fixed: the nested lambda parameter is `nt`, and the variable is `static_suite_1`; the example was compiled without warnings under `-Wshadow-all`.

- **#96 — "Rebase A onto B" is used for the opposite operation.**
  (fixed) [template] (WEBSITE-REVIEW-1 3.8.4) "the `xpack-development` branch
  is rebased onto `xpack`", and "Rebase the `xpack-development` branch
  onto the `webpreview` branch" (`_branches-details.mdx`,
  `_publish-website.mdx`, `_update-main-branch.mdx`). In Git, this
  replays `xpack-development` on top of `xpack`; the intended operation
  brings `xpack` up to `xpack-development`. Give the commands actually
  used (for example `git checkout xpack && git merge --ff-only
  xpack-development`).

  Fixed: the branch that is brought up to date is the one rebased: "Rebase the `xpack` branch onto the `xpack-development` branch (`git rebase xpack-development`)", and the same for the `webpreview` and `website` branches. The commands are those that the steps imply (switch to the branch, then rebase it onto the development branch); they should be confirmed against the actual practice.

- **#97 — Inconsistent list styles in the Maintainer's Guide.**
  (fixed) [template] (WEBSITE-REVIEW-1 3.8.5) Steps start in upper or lower
  case ("run the `npm install` command", "check GitHub Pages
  workflow"), and mix fragments and sentences. Use imperative fragments
  without full stops.

  Fixed for the steps of "Publish the website": all start with a capitalised verb, and the step that continued on an unindented line is one line. The other lists of the Maintainer's Guide were not changed.

- **#98 — Heading level jumps.** (fixed) [template] and [project]
  (WEBSITE-REVIEW-1 3.2.7, 3.8.8) The History page uses level 3 under
  no level 2; in the Maintainer's Guide, "Share on X/Twitter" and
  "Analytics" are level 2 among the level-3 steps of "Final updates".

  Fixed: the History headings are level 2 (#47), and "Share on X/Twitter" and "Analytics" are level 3 in "Final updates".

- **#99 — An admonition for an ordinary statement.** (fixed) [project]
  (WEBSITE-REVIEW-1 5.4) "Explicit Namespaces": "To avoid naming
  conflicts, it is advisable to use comparator functions with explicit
  namespaces" is an info box. Make it a sentence (and see #70).

  Fixed with #70: the advice is now a sentence of the "Namespaces" section.

- **#100 — The post descriptions carry no information.** (fixed) [project]
  (WEBSITE-REVIEW-1 3.11.6) Most posts have `description: Version X is
  a new release` (or "maintenance release"); the description is the
  link preview. Write one line on the main change, as for v3.3.0 and
  v5.0.1.

  Fixed: the posts of 2.0.0, 3.0.0, 3.2.2, 3.2.3, 3.3.1, 4.0.0, 4.1.1, 5.0.0, 5.0.1, and 6.0.0 have a description with the main change. The 14 older posts (1.1.0, 2.0.1 to 2.1.1, 3.0.1 to 3.2.0) list no changes, and are left as they are, by decision.

- **#101 — `npm unpublish` is suggested without its restriction.**
  (fixed) [template] `_tag-npm-latest-liquid.mdx` (WEBSITE-REVIEW-1 3.8.7): npm
  allows unpublishing only within 72 hours; mention `npm deprecate` as
  the usual alternative.

  Fixed: `npm deprecate` is given first, and `npm unpublish` is described as allowed only within 72 hours of the publication.

- **#102 — Blank lines in a generated page.** (fixed) [template]
  `templates/docusaurus/common/docs/getting-started/index-liquid.mdx`
  (WEBSITE-REVIEW-1 3.3.7): three blank lines before "Credits" in the
  generated `index.mdx`. Harmless, but the generated files should be
  tidy.

  Fixed: the template no longer leaves blank lines before "Credits".

- **#103 — Very long source lines.** (fixed) [project]
  `docs/user/_project/_content.mdx` (WEBSITE-REVIEW-1 5.5): many lines
  are several hundred characters long, whilst the other files wrap at
  80, which makes the reviews and the diffs harder. Rewrap when the
  page is split.

  Fixed: the paragraphs and the list items of the User's Guide are wrapped at 80 columns, with a script that checks that only whitespace changed. 25 lines remain longer, in code blocks, tables, and links.

## 6. Proposed restructuring

The User's Guide (`docs/user/_project/_content.mdx`, about 1900 source
lines, and 1650 lines of rendered text) combines a tutorial, the
concepts, the API, the extension mechanism, the command line
reference, and the embedded considerations (WEBSITE-REVIEW-1 section
6). Set `hasCustomUserSidebar: true` in `config/website-templates.json`,
and list the new pages in `sidebar-docs-user-custom.js`, which now has
a single item labelled "TODO" (WEBSITE-REVIEW-1 2.2.3).

The split is done (#104 to #112): `hasCustomUserSidebar` is set, and `sidebar-docs-user-custom.js` lists the seven pages.

- **#104 — Overview.** (fixed) The rationale (shortened), the concepts in
  top-down order (#62), and a link to History (#48).

  Fixed: The overview (`docs/user/_project/_content.mdx`, rendered by `user/index.mdx`) keeps the rationale, the overview with the link to History, and the concepts, and has a new "Contents of this guide" list, with the C API note and the known problems.

- **#105 — Tutorial.** (fixed) "Getting started": the minimal test, a computed
  value, a failed check, the comparators, and nested test cases, each
  with the code and its actual output, with matching line numbers (#3
  to #6, #72).

  Fixed: `docs/user/tutorial/index.mdx`: the minimal test, the TAP output, the computed value, the comparators, and the more complex tests, with their outputs.

- **#106 — Writing checks.** (fixed) "Expectations and requirements", the
  comparison with the other frameworks, the function comparators, the
  logical functions, exceptions (#65), strings, containers, and the
  other standard types.

  Fixed: `docs/user/checks/index.mdx`: Namespaces, Expectations and requirements (with the comparison with other frameworks), the function comparators, the logical functions, the exceptions, the strings, the containers, and the other standard types.

- **#107 — Extending the framework.** (fixed) "Custom Types" and "Custom
  Comparators", which are for the advanced reader.

  Fixed: `docs/user/extending/index.mdx`: Utility functions, Custom types, and Custom comparators.

- **#108 — Organising tests.** (fixed) The runner, the top suite, test cases,
  "Test cases for each value", the test suites (static, non-static,
  several runners), the order of execution, and aborting the test
  execution.

  Fixed: `docs/user/organising-tests/index.mdx`: the runner (instantiation, initialisation, top suite, test result, aborting), the test cases, the nested test cases, the test cases for each value, and the test suites.

- **#109 — Running tests.** (fixed) "Command line options", "Verbosity",
  "Filter", "List test cases", "Output file", the reporters, and the
  colours.

  Fixed: `docs/user/running-tests/index.mdx`: the command line options, with verbosity, filter, list of test cases, output file, human-readable reporter, and colours.

- **#110 — Embedded targets.** (fixed) "Memory Footprint", "Stack usage",
  "Timings", "Console output", and the builds without exceptions.

  Fixed: `docs/user/embedded-targets/index.mdx`: memory footprint (with stack usage), timings, console output, and a new section, Builds without exceptions, which gathers the behaviour that was scattered in the other sections.

- **#111 — Migrating from earlier versions.** (fixed) "Deprecated operators,
  literals, and wrappers", with its table, and a link to the
  compatibility notices.

  Fixed: `docs/user/migrating/index.mdx`: the deprecated operators, literals, and wrappers, with an introduction that links to the compatibility notices.

- **#112 — Compatibility notices on their own page.** (fixed) Move
  `_compatibility-notices.mdx` from Getting Started to a page of its
  own (for example under Releases), and keep, in Getting Started, one
  paragraph that links to it (#51).

  Fixed: The page is `docs/getting-started/compatibility-notices/index.mdx`, in the Getting Started category of the sidebar (not under Releases, which is a flat list of posts). Getting Started keeps a paragraph that links to it. The generated pages are controlled by the new `hasCompatibilityNoticesPage` flag of `website-templates.json`, handled by `getting-started/index-liquid.mdx` and `_add-compatibility-notice-liquid.mdx` (templates), and listed in `scripts-helper.mjs` of `npm-packages-helper` and in the README of the template package.

- **#113 — Test logs folded.** (fixed) In the Contributor's Guide, replace the
  logs by a short description of each program and its reference
  outputs (#25).

  Fixed: Already done with #25: `docs/developer/_project/_test-details.mdx` describes each program and its reference outputs, without the logs.

## 7. Incidental observations outside the website

- **#114 — `diag-trace` is required by the build files but not
  declared.** (fixed) The CMake targets and the meson dependency require
  `diag-trace` (#14), but the top `package.json` has no
  `xpack.dependencies`, so a project that installs the package with
  xpm does not get it. Either declare the dependency (if it is
  required), or make the CMake and meson links conditional (if it is
  optional, as the v5.0.1 post says); the page must then follow.

  Fixed: the dependency was made optional, as the v5.0.1 post says
  (`cef82bb4`); see #14. The quick route was taken (the dependency is no
  longer linked by the generated files), so the OBJECT and STATIC
  libraries no longer add its include path, and their sources are
  compiled without the trace messages. The tests still install
  `diag-trace` themselves (`tests/package.json`).

- **#115 — `LICENSE-Boost` is not in the npm package.** (fixed)
  (WEBSITE-REVIEW-1 7.1) The generated `.npmignore` excludes
  `LICENSE-*` (line 61, with exceptions only for `LICENSE-XPACK` and
  `LICENSE-liquid`), and `npm pack --dry-run` confirms the omission.
  Getting Started says that the Boost-derived portions are distributed
  under the Boost Software License, whose text must accompany the
  source. Add `!LICENSE-Boost` (in the `npm-packages-helper` template
  of `.npmignore`).

  Fixed: `!LICENSE-Boost` added to `templates/common/.npmignore-liquid` of `npm-packages-helper` and `.npmignore` regenerated; `npm pack --dry-run` now lists `LICENSE-Boost`.

- **#116 — A stray tag `t` is published.** (fixed) The tag `t` (2026-04-17, on
  commit `d1c27e2a`, "tests: update platforms without exceptions") is
  present on `origin`, where it appears among the release tags. Delete
  it locally and on `origin`, if it is not needed.

  Fixed: the tag was deleted locally and on `origin`.

## 8. Reviewed and found correct

- The two `draft: true` pages are not published (HTTP 404).
- The home page feature cards match the code (the options,
  `--reporter=human`, `--output-file`, and the exit code), and the
  home page example matches the minimal test program, apart from the
  omissions noted in #87.
- The User's Guide sections "Command line options", "Verbosity",
  "Filter", "List test cases", "Output file", and "Colours" match
  `src/runner-options.cpp` and `src/runner.cpp`: the option names and
  synonyms, the colour modes, the `=` rule of `--colour`, the error
  messages, the `# SKIP filtered` text, the list headers, and the exit
  codes 0, 1, and 2.
- The examples "Testing a computed value" and "More advanced
  comparators" report the line numbers shown (21 and 20), and the
  "Custom Types" and "Custom Comparators" examples compile without
  warnings under `-Wall -Wextra -Wshadow` and report the values shown.
- The `expect()` and `require()` declarations, the `throws()` and
  `nothrow()` signatures, the utility function signatures, and the
  default name of the top suite (`default suite` without a command
  line) match the headers and `src/runner.cpp`.
- The runner members cited by the deprecation table
  (`added_suites_count()`, `total_suites_count()`,
  `application_arguments()`, `is_listing()`, `set_abort_handler()`)
  exist in `runner.h`, and `extension::suspicious_condition` exists in
  `extension.h`.
- The FAQ entries on the static suites, the order of execution,
  `--quiet`, the reporter selection, and C code are correct.
- The links into `/docs/api/` point to the groups they name (Test
  Runners, Test Cases, Expectations, Requirements, Function
  Comparators, Logical Functions, Checking Exceptions, Operators,
  Literals and Wrappers, Utility Functions, Test Suites, and Command
  Line Options).
- The Releases page and the blog index list the posts in reverse
  chronological order, with titles matching the posts; the tags page
  counts 24 release posts and one website post.
- The About page, apart from "utilise" (#89).
- The xpm actions shown in the guides (`install`, `install-selected`,
  `install-latest`, `install-all`, the matching `test-*` actions, and
  `trigger-workflow-test-all`) and the npm scripts `git-log`,
  `npm-pack`, `generate-website-doxygen`, `generate-website-blog-post`,
  `build`, `clear`, and `start` exist.
- The comparison with the other frameworks ("Comparison with other
  frameworks") was not checked against those frameworks.
