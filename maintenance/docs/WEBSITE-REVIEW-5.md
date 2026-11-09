# Website review

Date: 2026-11-09, on branch `webpreview`, commit `7f38f714`; published site
built from `webpreview` commit `a495ade7`.

Scope: the project-owned pages under `website/docs/`, that is, the files
without a `DO NOT EDIT!` header: the `_project/` partials, the guide pages
under `docs/user/` and `docs/developer/*/`, the glossary, the compatibility
notices page, and the History page. Excluded: the generated pages, `docs/api/`,
the blog, the home page, the navigation bar, and the footer.

Method: the published pages were not downloaded. `git diff` between
`origin/webpreview` and `HEAD` shows that the only difference in `website/`
(leaving out the API pages and the Doxygen files) is the release post, which
is out of scope, so the local sources of the pages in scope are the published
ones. The project-owned files were read in full, in render order for the
partials, except the eight pages of `docs/developer/*/`, which were not read
in full: they were compared with the changes made since
`WEBSITE-REVIEW-4.md` (`git diff 99339c89 HEAD`), and checked by two scripts
that look up each backticked identifier (417 in the guide pages) in
`include/` and `src/`, and each quoted file name in the repository. Only
`buffer_reporter`, `OBJECT`, and the names of external tools and of the
`xcdl` properties are not in the library sources, as expected. The statements
were checked against the headers, `src/`, `tests/expected/`,
`tests/sources/`, `tests/platforms/`, `npm pack --dry-run` (55 files, as the
page shows), the git tags, the npm registry, and the GitHub milestone. The
line numbers of the tutorial and of the extending listings were counted. No
probe program was built, since the library sources have not changed since
the previous review, except `expression-formatter-inlines.h` (#282). The
language rules were checked by search (contractions, "directory", the
inflated words, `TODO`). The earlier report, `WEBSITE-REVIEW-4.md`, has 60
problems, 59 fixed and 1 open; the open one is carried over as #2.

Summary: 7 problems (2 open, 5 fixed, 0 withdrawn; the open ones are #2 and #7). The only one that can
mislead a reader is #1, whose fix is a character replacement. #2 needs
measurements on the boards before the release. The others are small, and #7 concerns the release, not the pages.

## Note on generated files

The pages in scope are all project files, edited in place. While reading the
diff since the previous review, `docs/developer/_common/_content.mdx`, which
has a `DO NOT EDIT!` header, was seen to differ from the earlier version (the
Raspberry Pi Zero 2 W note); it is out of scope, and presumably regenerated
from the template package.

## 1. Defects

- **#1 — The option names in the verbosity table contain non-breaking
  hyphens.** (fixed) [project] `docs/user/running-tests/index.mdx` lines 108, 110, and
  111: `‑‑verbose`, `‑‑quiet`, and `‑‑silent` are written with U+2011
  (non-breaking hyphen), not with two ASCII hyphens (`grep -c` finds three
  lines, and no other file in `docs/` has the character). A reader who copies
  the option from the table gets an argument that the parser rejects as an
  unknown option, and the program returns 2. Replace the characters with
  `--`. If the characters were meant to stop the line break in the narrow
  column, the code span already prevents it.

  Fixed: The three characters are replaced with ASCII hyphens.

- **#2 — The sizes and the stack were measured before later changes.**
  (WEBSITE-REVIEW-4 #31) [project] `docs/user/embedded-targets/index.mdx`
  lines 53 to 58, 121 to 148: the footprint (`text 121188`), the stack table,
  and the "about 5 KB" figure come from the measurements of 2026-11-03 and
  earlier, labelled "Built with µTest++ 6.0.0", while the code of the test
  cases and of the reporters changed afterwards (the issues up to #282). The
  values were not re-measured for this review. Re-measure them on Cortex-M7F,
  Cortex-M33, and AArch64 before the release, or reword the text as an
  indication ("measured with a development version of 6.0").

- **#3 — The tutorial shows verbose output without saying so.**
  (fixed) [project] `docs/user/tutorial/index.mdx` lines 160 to 273: the outputs of
  the three examples after the minimal one are those of a `--verbose` run (the
  first line is `# Running: main --verbose`, and each test case has its
  `# Subtest:` block), but the text says "the output would be" and "the test
  output will be as follows". A reader who runs the program without the option
  sees a single `ok` line for the passed test case (as the page itself explains
  at line 95), and for the failed one a complete block, which differs from the
  listing in the passed checks. Say, before the first of them, that the
  following outputs are those of `--verbose`, which shows every check.

  Fixed: A paragraph before the first of the three outputs says that they are
  those of a `--verbose` run, and what the run without the option shows.

## 2. Version history

No problems found. The dates of the compatibility notices and of the History
page agree with the git tags and the npm registry (v3.3 2026-03-22, v4.0
2026-04-29, v4.1 2026-05-11/12, v5.0 2026-07-14), "12 October 2026" is the
creation date of the first issue of the milestone, and the 6.0.0 milestone has
the 252 issues. The notice "v6.0 (not yet released)" is the decision recorded
in the earlier reports, since there is no `v6` tag.

## 3. Structure

### Running tests

- **#4 — `--help` is not described on the page about the command line.**
  (fixed) [project] `docs/user/running-tests/index.mdx` line 32: the table of options
  sends the reader of `--help` to "Test result" in Organising tests, where the
  option is one sentence of a long paragraph about exit codes (line 152 of
  `organising-tests/index.mdx`), and no other section of the page mentions
  it. Add a short section "Help" after "Command line options" (what it
  writes, that it returns 0 without running any test, and that `-h` is the
  short form), or at least name the exit code in the table and link the
  paragraph.

  Fixed: A section "Help" follows the table; the table links to it.

## 4. Consistency

| # | Concept | Variants found (where) | Suggested |
| --- | --- | --- | --- |
| #5 (fixed, except the generated page) | the noun phrase | "command-line options" 9 times in `user/`; "Command line options" (heading, `user/running-tests/index.mdx` line 25) [project]; "command line options" (description of the generated `user/index.mdx` line 7) [template] | "command-line options" |

The generated API page keeps its own title, "Command Line Options" (the
Doxygen group name), which is not in scope. The other rows of the table of
`WEBSITE-REVIEW-4.md` (the colour option, the reporter name, the Meson and
GoogleTest spellings, `stdout`) were checked again and are consistent.

## 5. Language and style

- **#6 — Whitespace that the formatter would change.** (fixed) [project] Two blank
  lines in a row: `docs/user/checks/index.mdx` lines 55 and 56,
  `docs/user/organising-tests/index.mdx` lines 274 and 275, and 359 and 360.
  Trailing spaces: `docs/user/embedded-targets/index.mdx` line 214,
  `docs/install/_project/_install-folder-hierarchy.mdx` lines 7 and 8,
  `docs/install/_project/_configuration.mdx` lines 12 and 13, and
  `docs/getting-started/_project/_overview.mdx` line 11. Several of these
  paragraphs also have lines of over 100 characters (for example
  `_install-folder-hierarchy.mdx` line 7) in a file that wraps at 80. None of
  this changes the rendered pages; run the Markdown formatter on the files.

  Fixed: The double blank lines and the trailing spaces are removed, and the
  paragraphs of the install and overview partials are rewrapped at 80
  characters.

The rules of `.github/copilot-instructions.md` were checked by search over the
pages in scope: no contractions, no "directory" (only the CMake command
`target_include_directories` and the `tree` output), no `TODO` outside the
quoted name `parser # TODO rework`, and none of the inflated words listed by
the skill.

## 6. Proposed restructuring

None.

## 7. Incidental observations outside the website

- **#7 — The fixes of #283 to #287 are not on the branch of the published
  site.** The commits (`60585a5d`, `6e6f6cb4`, `9d91b102`, `c8bb215c`,
  `6c764cbb`, `04090403`, `4845186d`, `905b81c9`, `bfd9d5b7`) are on
  `xpack-development` only, while the release post, which lists the issues
  under "Bug fixes", is on `webpreview`. The pages in scope do not depend on
  them, but the `v6.0.0` tag the post links to must contain them. The
  comments "Fixed in ..." exist on all the issues. The Windows fix of #287
  also needs the same change in the `CMakeLists-liquid.txt` template of the
  build-helper xPack, as its commit message says; this was not checked.

## 8. Reviewed and found correct

- The user's guide: Overview (`user/_project/_content.mdx`), the tutorial (the
  three listings were counted: the lines 21 and 20 of the failure reports are
  right), Writing checks, Organising tests, Running tests (the options, the
  examples of the filter and of the listing against `sample-test.tap`), the
  extending page (the lines 37 and 59 to 61 of the reports are right),
  Embedded targets (apart from #2; the timing functions agree with
  `stopwatch.cpp`), and Migrating.
- The FAQ, the glossary, the History page, and the compatibility notices.
- The install partials: the list of the 12 source files and of the headers
  agrees with `src/` and `include/`, and the tree of the installed package
  agrees with `npm pack --dry-run` (55 files).
- The developer guide, within the limits of the Method paragraph: every
  identifier, source file, and `tests/` path named exists, the platform list
  agrees with `tests/platforms/`, the table of the test programs and the
  names of the reference files agree with `tests/sources/` and
  `tests/expected/`, and the excerpts changed since the previous review
  (`message_argument`, `comparable_operands`, `as_comparison_integer`,
  `reject_compare_tag`, the ratio of the durations) agree with the headers.
  The eight pages were not read sentence by sentence in this review.
