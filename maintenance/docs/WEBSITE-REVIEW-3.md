# Website review

Date: 2026-11-04, on branch `xpack-development`, commit `5faa077c`;
published site built from `webpreview` commit `00ffcc30`.

Scope: the eight new pages of the Contributor's Guide
(`website/docs/developer/{architecture,comparators,checks,formatter,
test-cases-and-suites,runner,reporters,making-changes}/index.mdx`), the
sidebar category `website/sidebar-docs-developer-custom.js`, and the
generated `website/docs/developer/index.mdx`, as their entry point.
Excluded: every other page, and `docs/api/`.

Method: the pages are not published, and not yet committed (they are
untracked), so they were read from the local sources, in full; the site
was built locally (`npm run build`, no warnings). The statements were
checked against the headers, the inlines, and the sources at
`0bacbd67`, the reference outputs in `tests/expected/`, and probe
programs built with Apple clang 17 (`-std=c++20`), including a count of
the heap allocations made per test case and per check. The earlier
report, `WEBSITE-REVIEW-2.md`, has no open items; none is carried over.

Summary: 29 problems (0 open, 28 fixed, 1 withdrawn). The wrong
statements come first: the description of the writer functions (#8), the
claims about the allocations (#4), the dangling C string operands (#5),
and the passages written before #258 (#2, #6, #7). The other defects are
small corrections (#1, #3, #9 to #17). Suggested order: the defects,
then #11 and #19 on the rules page, the consistency items (#20 to #24),
the style items (#25 and #26), the incidental items (#27 to #29), and
finally #18, which needs a decision on the template. None remains
open.

## Note on generated files

The new pages and the sidebar file are project files, edited in place.
`website/docs/developer/index.mdx` and its `_common/_content.mdx` are
generated from the `@xpack/docusaurus-template-liquid` templates (see
`website/node_modules/@xpack/docusaurus-template-liquid/`), and are
regenerated with `npm run generate-website-commons` in `website/`;
`sidebars.ts` is generated too, and includes the category through the
`hasCustomDeveloperSidebar` flag.

## 1. Defects

- **#1 — Builds without exceptions overstated.** (fixed) [project]
  `docs/developer/architecture/index.mdx` line 51: "every feature works
  with `-fno-exceptions`" contradicts the comparators page, which says
  that `throws()` and `nothrow()` are not defined without exceptions
  (`exceptions.h`, under `#if defined(__cpp_exceptions)`). Write "every
  feature, except the comparators of exceptions, works with
  `-fno-exceptions`".
  Fixed: Written as proposed.
- **#2 — The walk-through predates #258.** (fixed) [project]
  `docs/developer/architecture/index.mdx` lines 213 and 277 to 279: the
  passed check of the minimal program is said to call
  `reporter::pass()`; at the default verbosity, without an output file,
  it calls `reporter::pass_without_text()` (`src/check-result.cpp`).
  Write "`reporter::pass()`, or `pass_without_text()` when the passed
  check is not written" in both places.
  Fixed: The walk-through and the "A check" section now name
  `pass_without_text()`.
- **#3 — Exit code 2 incomplete.** (fixed) [project]
  `docs/developer/architecture/index.mdx` lines 289 to 291: the list of
  the cases of `2` omits the output file that cannot be opened, which
  the runner page lists (`src/runner.cpp`, `initialise()`). Add it, or
  link to [The exit code](/docs/developer/runner/#the-exit-code)
  instead of repeating the list.
  Fixed: The sentence now gives `0` and links to the exit code table of
  the runner page.
- **#4 — The allocations of a test case.** (fixed) [project]
  `docs/developer/architecture/index.mdx` lines 62 to 66,
  `docs/developer/test-cases-and-suites/index.mdx` lines 109 to 112,
  and `docs/developer/making-changes/index.mdx` lines 72 to 74: the
  pages say that nothing is allocated for a test case, and that a test
  case must not allocate. The name is passed as a `located_name`
  temporary, which holds a `std::string`; a probe counted 1 allocation
  for a test case named with 40 characters, and 0 for a short name.
  State that a name longer than the small-string capacity is copied into
  a `std::string`, and decide whether the rule of the last page is kept
  (see #27).
  Fixed: The three pages state the exception of the long names; the rule
  of `making-changes` says "should not allocate", pending #27.
- **#5 — C strings and arrays are not copied.** (fixed) [project]
  `docs/developer/comparators/index.mdx` lines 313 to 325: the copies of
  the named operands are said to keep an expression valid after the
  objects are gone, with the example of an expression returned from a
  function; but a `char` array or any other array becomes a `c_string`
  or an `array_operand`, which refer to the original characters and
  elements (lines 243 to 245). An expression built from a local array,
  and returned, refers to a destroyed object. Add this exception after
  the example.
  Fixed: Added after the example, with a link to the operands that
  change type.
- **#6 — The cost of a passed check.** (fixed) [project]
  `docs/developer/checks/index.mdx` lines 242 to 247: "a passed check
  costs only the comparison and a counter" predates #258; with the TAP
  reporter, at the normal verbosity, it also costs a virtual call and a
  bare `ok <n>` line appended to the buffer. Write "the comparison, a
  counter, and, with the TAP reporter, its test point number".
  Fixed: Written as proposed.
- **#7 — The unwritten passed checks, again.** (fixed) [project]
  `docs/developer/reporters/index.mdx` lines 158 to 162: "the passed
  checks are only counted" predates #258, and contradicts lines 186 to
  188 of the same page. Write "are counted, and, with the TAP reporter,
  recorded as bare `ok <n>` lines".
  Fixed: Written as proposed.
- **#8 — The writer functions.** (fixed) [project]
  `docs/developer/reporters/index.mdx` lines 101 to 104: the page says
  that `write_console()`, `write_file()`, and `write_line()` format the
  text into a local array of 128 bytes; only `write_line()` does, while
  `write_console()` and `write_file()` call `vfprintf()` directly
  (`src/reporter.cpp`). Describe them separately; the 128-byte array
  remark of `making-changes` line 80 is correct only for
  `write_line()`.
  Fixed: The writer functions are described separately; the stack remark
  of `making-changes` now names `write_line()`.
- **#9 — A caller of `fail()` missing.** (fixed) [project]
  `docs/developer/reporters/index.mdx` line 49: the protocol table lists
  only `~check_result()` as the caller of `fail()`;
  `test_case::fail_unexpected_exception()` (`src/test.cpp`) calls it
  too, for an exception that escapes a test case. Add it to the row.
  Fixed: A row for `test_case::fail_unexpected_exception()` was added.
- **#10 — Colours on the platforms without `isatty()`.** (fixed) [project]
  `docs/developer/reporters/index.mdx` lines 317 and 318: "on the
  embedded platforms, `auto` means no colours"; the test is compiled
  only for `__APPLE__`, `__linux__`, and `__unix__`, so `auto` also
  means no colours on native Windows. Write "on the other platforms,
  including Windows and the embedded ones".
  Fixed: Written as proposed.
- **#11 — `std::invoke()` advice inverted.** (fixed) [project]
  `docs/developer/making-changes/index.mdx` line 82: "prefer direct
  calls to `std::invoke()`" reads as "call `std::invoke()` directly",
  the opposite of the intent (`callable_ref` avoids it). Write "call
  the callables directly, rather than through `std::invoke()`".
  Fixed: Written as proposed.
- **#12 — "Defined" for "declared".** (fixed) [project]
  `docs/developer/comparators/index.mdx` line 27: "The expression
  templates are defined in `detail.h`, with their definitions in
  `inlines/detail-inlines.h`". Write "declared in `detail.h`".
  Fixed: Written as proposed.
- **#13 — Not all the expression types are templates.** (fixed) [project]
  `docs/developer/comparators/index.mdx` line 34: `nothrow_op` and its
  base `callable_op` are classes. Write "All the expression types are
  in the `detail` namespace; most are templates".
  Fixed: Written as proposed.
- **#14 — Which code is a template.** (fixed) [project]
  `docs/developer/architecture/index.mdx` lines 58 to 61: "the
  templates ... only evaluate and format the expressions; everything
  else ... is non-template code"; the creation of the test cases
  (`create_test_case()`, `bind_callable()`, `test_each()`) and
  `add_suite()` are templates too. Write "the templates do only the
  work that depends on the types; the counting, the reporting, and the
  control of the test cases are non-template code, compiled once".
  Fixed: Written as proposed.
- **#15 — xPack does not compile.** (fixed) [project]
  `docs/developer/architecture/index.mdx` lines 83 and 84: "The build
  systems (CMake, meson, and xPack) compile all of them"; the library
  is compiled by CMake or meson, whose top files are generated from
  `xcdl-package.jsonc`. Write "CMake and meson compile all of them;
  their top files are generated from `xcdl-package.jsonc`".
  Fixed: Written as proposed.
- **#16 — The integer suffix example.** (fixed) [project]
  `docs/developer/formatter/index.mdx` lines 134 to 137: "so that
  `1 == 1u` shows why an `int` and an `unsigned int` differ" is
  unclear, since `eq (1, 1u)` passes, and the sentence is about the
  casts of the types without suffix. Write "so that the type of each
  operand is visible, as in `-1 == 4294967295u`", and keep the casts in
  a separate sentence.
  Fixed: Written as proposed.
- **#17 — The stop of a failed `require()`.** (fixed) [project]
  `docs/developer/architecture/index.mdx` lines 279 to 281: "the
  destructor also stops the test case, by throwing an exception"; add
  "with exceptions; without them, it aborts the test execution", as the
  constraints of the same page state.
  Fixed: Written as proposed.

## 2. Version history

Not applicable to these pages.

## 3. Structure

### The Contributor's Guide

- **#18 — The entry page does not mention the new pages.** (fixed) [template]
  `docs/developer/index.mdx`, generated from
  `templates/docusaurus/common/docs/developer/_common/_micro-os-plus/_content-liquid.mdx`:
  the page describes the build and the tests only, and the new pages
  are reachable only from the sidebar, in a category that is collapsed
  by default. Options: add to the template an optional project partial
  (for example `_project/_more.mdx`) rendered at the end of the page
  when it exists, listing the internals pages; or have the template add
  a sentence pointing to the sidebar when `hasCustomDeveloperSidebar`
  is set; or expand the category by default. A decision for the
  maintainer, since the template is shared by the other µOS++ sites.
  Fixed: The template `docs/developer/index-liquid.mdx` imports
  `./_project/_pages.mdx` when `hasCustomDeveloperSidebar` is set, and
  renders it after the introduction; the new project partial lists the
  eight pages; the template README documents the file.

### Making changes

- **#19 — The rule learnt in #258 is missing.** (fixed) [project]
  `docs/developer/making-changes/index.mdx`, "The constraints of the
  embedded targets": a new virtual function of `detail::reporter` must
  be pure virtual, with an override in both reporters and in the
  `buffer_reporter` of `unit-miscellaneous`, since the Cortex-M GCC
  release builds reject a virtual with a body in the base class
  (`-Wsuggest-final-types`, `-Wsuggest-final-methods`, with `-Werror`).
  Add it under "Warnings", with the advice to run `test-selected`.
  Fixed: Added under "Warnings".

## 4. Consistency

| # | Concept | Variants found (where) | Suggested |
| --- | --- | --- | --- |
| #20 | the build and test page | "the [Contributor's Guide](/docs/developer/)" used, within the guide, for its first page (`making-changes` lines 21 to 23 and 164 to 165) | "the [first page](/docs/developer/) of the Contributor's Guide", or the anchor of the section (fixed) |
| #21 | the checks page | title and H1 "Checks: expect(), require(), and the check result" (`checks`); sidebar and list "Checks and the check result"; table "Checks" (`architecture` lines 93 and 100) | title, H1, and sidebar "Checks and the check result" (fixed) |
| #22 | the second reporter | "human reporter" (`formatter` line 110); "human-readable reporter" (`reporters`, 4 times) | "human-readable reporter" (fixed) |
| #23 | the page links of the headers table | "Expression templates", "Checks" (`architecture` lines 91 to 105) for pages titled differently | the full titles (fixed) |
| #24 | the sample check | "such as `6 == 42`" (`architecture` line 152), while the program shown checks `eq (6 * 7, 42)`, written `42 == 42` | "such as `42 == 42`" (fixed) |

## 5. Language and style

- **#25 — "The probe" without introduction.** (fixed) The pages refer to "the
  probe" four times (`checks` line 425, `comparators` line 426,
  `test-cases-and-suites` lines 126 and 447), a program the reader has
  not seen. Write "the output is", "a test that counts the copies
  shows", and so on.
  Fixed: The four passages were reworded.
- **#26 — Paragraphs not rewrapped.** (fixed) Some paragraphs were edited
  without rewrapping, leaving short lines and lines over 80 characters:
  `architecture` lines 129 to 131 and 237 to 242, `checks` lines 446
  to 450 and 545 to 547, `test-cases-and-suites` lines 446 to 449, and
  `runner` lines 262 to 267. Rewrap them.
  Fixed: The paragraphs were rewrapped.

## 6. Proposed restructuring

None; the eight pages have a consistent scope, from 300 to 550 lines.

## 7. Incidental observations outside the website

- **#27 — Long test case names allocate.** (fixed) `test.h`, `located_name`:
  the name of each test case is copied into a `std::string`, so a name
  longer than the small-string capacity allocates once per test case
  (measured: 1 allocation for 40 characters). The test case and its
  body are otherwise not allocated. If the rule "a test case does not
  allocate" is wanted, the test cases could refer to the string of the
  caller, which outlives them, and only the suites copy it; otherwise,
  the pages should state the exception (#4).
  Fixed: kept as it is, and documented. The copy is a temporary of the
  statement that calls `test()`, freed when it returns; measured, 1000
  test cases with names of 40 characters made 1000 allocations but held
  at most one name (48 bytes), and nothing remained; nested test cases
  hold one name per level. The pages state this, and the rule of
  `making-changes` asks to keep the heap from growing.
- **#28 — Stale console reference files.** (withdrawn)
  `tests/expected/tap/unit-checks-test-console*.tap` and
  `tests/expected/txt/unit-checks-test-console*.txt` are out of date
  (fewer subtests, other line numbers than the `unit` program), and no
  configuration compares them, since the console tests exist only on
  synthetic-posix, where `unit-checks` is replaced by the combined
  `unit` program. Delete them, or wire up their comparison.
  Withdrawn: left as they are, by decision. The five files are
  referenced only by the synthetic-posix artefacts.cmake, inside the
  XPACK_ENABLE_UNIT_CHECKS_TEST block, which definitions.cmake disables
  there; the same outputs are covered by the console tests of the unit
  program. They must be regenerated if the option is enabled again.
- **#29 — The Copilot instructions template.** (fixed)
  `npm-packages-helper/templates/first-time/.github/copilot-instructions-liquid.md`
  line 155 still tells the new projects to add the source files to the
  top CMake and Meson configurations by hand; the project file was
  corrected in `5faa077c`. Correct the template, if all the projects
  that use it generate these files with `xpm run xcdl-export`.
  Fixed: the sentence of the template, which is in the branch of the
  µOS++ projects, now says to add the files to `xcdl-package.jsonc` and
  to regenerate the top files with `xpm run xcdl-export`, as the project
  file; it applies only to the new projects, since the template is
  copied once.

## 8. Reviewed and found correct

- The front matter, the titles, and the H1 of the eight pages; the
  sidebar order and the links between the pages (the build checks
  them).
- The excerpts compared with the sources: `op` and `is_op`,
  `checkable`, `binary_op`, `equal_to`, `compare_op`, `eq()`, the
  deduction guide, `stored_operand_t`, `approx_op`, `all_of()`,
  `and_op`, `throws_op`, the `extension` using-declarations,
  `check_result` (members, `init()`, `start()`, `operator<<`, the
  destructor), `begin_check()`, `runner::abort()`,
  `create_test_case()`, `callable_ref`, `test_case::run()`,
  `suite::test()`, `test_each_value()`, the suite constructor,
  `suite::link()`, `add_suite()`, `register_suite()`, the static suite
  constructor, `link_static_suite()`, `top_suite`, `counters`, the
  runner members, the option table, `run_child_suites()`,
  `is_selected()`, `reporter::pass()`, `fail()`, `route()`,
  `open_test_case`, and the human reporter constructor.
- The outputs: the formatter table, the nested and pending checks, the
  misdirected check, the filtered and listed runs, the exit codes, the
  `Bail out!` lines, and the TAP, quiet, and human reports of the
  reporters page, all reproduced with probes after `0bacbd67`.
- The operand copy and move counts, the expression types (checked with
  `static_assert`), the `sizeof` of `eq (int, int)`, and the run order
  of the static and added suites.
