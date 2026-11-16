# Skills migration report — micro-test-plus-xpack

The rules of the original skills (kept as `*-original.*` files until they are deleted) that are not word-for-word in the new generated skills and project files; the rows that are the same are left out. Score: fraction of the words of the rule found in the best-matching text of the new files. Verdicts of the unmatched rows were set after reading them, per skill, not per row.

## api-review

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| frontmatter | argument-hint: 'Optional: header, file, or folder to review (e.g. incl | design-review/SKILL.md (frontmatter) | 0.82 | reworded: example dropped |
| A Fresh Review Each Time | The only use of the earlier reports is their file names, to choose the | design-review/project.md (Earlier Reports) | 0.84 | moved: design-review/project.md (Earlier Reports) |
| Reading the Code | ```sh node .github/skills/api-review/scripts/strip-comments.mjs <scrat | design-review/SKILL.md (Reading the Code) | 0.83 | CHANGED: path api-review -> design-review |
| Reading the Code | ```sh node .github/skills/api-review/scripts/check-headers.mjs <scratc | design-review/project.md (Header Check) | 0.83 | CHANGED: path, and folder/flags arguments (design-review/project.md Header Check) |
| Confirming Findings with Probes | A suspected defect is reported as a defect only after it has been repr | project.md (Probes), review-common.md | 0.73 | moved: recipe to project.md (Probes), principle to review-common |
| Confirming Findings with Probes | ```sh P=<scratch>/probe W="-Wall -Wextra -Wpedantic" for f in src/*.cp | project-defaults.md (Probes) + project.md (Probes) | 0.70 | reworded: the generic recipe is in project-defaults.md (Probes); project.md keeps only the project-specific macro, options, and validator |
| Confirming Findings with Probes | ```sh arm-none-eabi-g++ -std=c++20 -mcpu=cortex-m4 -mthumb \ -mfloat- | design-review/SKILL.md (Probes), project.md (Probes) | 0.79 | reworded: -D macro moved to project.md (Probes) |
| 1. Defects | Behaviour a user would see as wrong. These come first in the report. T | design-review/project.md | 0.83 | split: generic questions + design-review/project.md (Additional Defect Questions) |
| 1. Defects | - **Lifetimes**: which pointers and references does an object keep (na | design-review/project.md (Additional Defect Questions) | 0.83 | split: generic + example to project.md |
| 1. Defects | - **Special values**: `'\0'` (which may truncate the rest of the outpu | design-review/project.md (Additional Defect Questions) | 0.77 | split: generic + details to project.md |
| 1. Defects | - **Literals**: octal, hexadecimal, and binary prefixes, digit separat | design-review/project.md | 0.84 | moved: design-review/project.md (Additional Defect Questions) |
| 1. Defects | - **Exceptions**: what happens when a test body or a suite body throws | design-review/project.md (Additional Defect Questions) | 0.79 | split: generic + details to project.md |
| 3. Structure and layering | - **Extensibility**: are the classes that look extensible (the reporte | design-review/project.md (Additional Checks) | 0.79 | split: generic + examples to project.md |
| 3. Structure and layering | - **Symmetry**: the same concept offered in several forms with differe | design-review/project.md (Additional Checks) | 0.71 | split: generic + forms to project.md |
| 4. Naming and consistency | - **Other member functions** start with a verb that states their effec | design-review/project.md (Additional Checks) | 0.80 | split: generic + examples to project.md |
| 4. Naming and consistency | - Several names for one concept (test case, subtest, test); several sp | design-review/project.md (Additional Checks) | 0.75 | split: generic + examples to project.md |
| 5. Simplicity and duplication | - The same logic implemented twice or more (sorting, formatting of tim | design-review/project.md (Additional Checks) | 0.61 | split: generic + examples to project.md |
| 7. Suitability for embedded targets | - Heap allocations per test case and per check; objects kept alive aft | design-review/project.md (Additional Checks) | 0.80 | split: generic + example to project.md |
| Judging Findings | - Tag each finding **[breaking]** when the suggested change alters the | review-common.md | 0.65 | moved: review-common.md (Judging Findings) + project.md (Breaking Changes) |
| Numbering | - The numbers never change once assigned, and are never reused. When a | review-common.md | 0.73 | moved: review-common.md (Numbering) |
| Numbering | - If a problem turns out to be wrong, mark it `(withdrawn)` with the r | review-common.md (Numbering) | 0.74 | moved: review-common.md (Numbering) |
| Report | Write the report to a new file, `maintenance/docs/API-REVIEW-<n>.md`, | design-review/SKILL.md (Report), project.md (Review Documents) | 0.79 | CHANGED: new reports are DESIGN-REVIEW-<n>.md; API-REVIEW-<n>.md still count (project.md) |
| Report | Paths in the report are relative to the repository root, or to `includ | project.md (Paths) | 0.75 | moved: project.md (Paths) |
| Acting on an Item | 2. Change the code, keeping the split between the headers, the inlines | review-common.md | 0.71 | moved: review-common.md (Acting on an Item 3) |
| Acting on an Item | 3. Where the item is a defect, turn its probe into a regression test i | review-common.md (Acting 4), project.md (Tests), design-review/project.md | 0.60 | CHANGED (corrected): regression tests go to tests/sources/unit-*/ (the unit program was split) |
| Acting on an Item | 5. Run the tests required by the Testing section of `.github/copilot-i | review-common.md | 0.50 | moved: review-common.md (Acting 6) + project.md (Tests) |
| Acting on an Item | 6. Commit only when the user asks, following `.github/skills/github-co | review-common.md | 0.73 | same (review-common.md Acting 7) |

## code-review

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| Review Scope | If the user specifies a path, review only that path. Otherwise review | code-review/SKILL.md (Review Scope) | 0.78 | same, plus commit-range scope added |
| Naming and style | - Formatting matches `.clang-format` (run `xpm run clang-format` menta | code-review/SKILL.md (Tooling Verification) | 0.44 | CHANGED: replaced by a real clang-format --dry-run check (Tooling Verification) |
| Correctness and maintainability | - Look for undefined behaviour, missing `const`-correctness, and incor | code-review/SKILL.md (Correctness) | 0.74 | split: generic inline-assembly rule; AArch64 detail dropped for µTest++ (goes to architecture-aarch64 project.md) |
| Correctness and maintainability | - Check for potential ABI implications of changes to the public types | code-review/SKILL.md (Correctness) | 0.83 | reworded: 'interfaces shared with other components'; semihosting detail to architecture-aarch64 |
| Correctness and maintainability | - Check API symmetry between the parallel forms of each API (the `aarc | code-review/SKILL.md (Correctness) | 0.73 | split: generic symmetry rule; AArch64 names to architecture-aarch64 project.md |
| Correctness and maintainability | - Check API symmetry between related class templates (e.g. `doubly_lis | code-review/SKILL.md (Correctness) | 0.37 | merged into the generic symmetry rule; list names to utils-lists project.md |
| Toolchain verification | - Where feasible, prefer verifying claims by actually building rather | code-review/SKILL.md (Tooling Verification) | 0.77 | reworded: run the tests of project.md (Tests) |
| Toolchain verification | - For pointer-arithmetic or type-punning idioms (e.g. `reinterpret_cas | code-review/SKILL.md (Tooling Verification) | 0.84 | reworded: build a sanitizer probe |
| Tests | - Note if `xpm run test -C tests` (and the clang/qemu variants mention | code-review/SKILL.md (Tests) | 0.55 | reworded: refers to project.md (Tests) |
| Procedure | 5. Write the results to `CODE-REVIEW.md` at the root of the project, w | code-review/SKILL.md (Report) | 0.57 | CHANGED: report is maintenance/docs/CODE-REVIEW-<n>.md (review-common Report Files) |
| Procedure | - a summary of findings, and | code-review/SKILL.md (Report) | 0.83 | same (Report template, Summary line) |
| Procedure | - specific, actionable recommendations, grouped by checklist section. | code-review/SKILL.md (Report) | 0.63 | same (Report template, sections per checklist) |
| Procedure | 6. Index open issues numerically, to be refered when asking to close t | review-common.md (Numbering) | 0.38 | moved: review-common.md (Numbering) |

## consistency-check

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| 3. Names | - Similar items placed inconsistently (e.g. a platform-level file kept | consistency-check/SKILL.md (3. Names) | 0.79 | reworded: example generalised ('a file kept in one sibling folder only') |
| Numbering | - The numbers never change once assigned. When the report already exis | consistency-check/SKILL.md (Numbering), review-common.md (Numbering) | 0.52 | same (reworded into consistency-check Numbering + review-common) |
| Numbering | - If a problem turns out to be wrong, mark it `(withdrawn)`, with the | review-common.md (Numbering) | 0.74 | moved: review-common.md (Numbering) |
| Numbering | - When the user later refers to a number (e.g. "fix #7"), act on that | consistency-check/SKILL.md (Procedure 6) | 0.75 | moved: Procedure 6 + review-common.md (Acting on an Item) |

## create-github-issue

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| When to Use | - The user asks to turn the findings of a review (code, API, Doxygen, | create-github-issue/SKILL.md (When to Use) | 0.81 | reworded: list of review kinds dropped (generic 'a review') |
| Title | - Good: `The TAP reporter formats most of its lines twice` | create-github-issue/SKILL.md (Length) | 0.45 | dropped by decision (project example, label, milestone) or unified wording |
| Title | - Good: `` `initialise (argc, argv)` handles a second call twice `` | create-github-issue/SKILL.md (Title) | 0.30 | dropped by decision (project example, label, milestone) or unified wording |
| Title | - Bad: `Refactor the TAP reporter output` (describes the fix). | create-github-issue/SKILL.md (Title) | 0.80 | dropped by decision (project example, label, milestone) or unified wording |
| Body | 1. **Location.** Open with the file and the function or member, and, w | create-github-issue/SKILL.md (Body 1), project.md (Paths) | 0.73 | split: generic rule + the header-path rule in project.md (Paths); the examples were dropped (your decision) |
| Body | 4. **Proposed change.** In the imperative (`Remove it.`, `Add to `repo | create-github-issue/SKILL.md (Body 4) | 0.79 | split: generic rule; the build-helper note is in project.md (Generated Files) |
| Length | - The body has at most two paragraphs (the location and the observatio | create-github-issue/SKILL.md (Body, Length) | 0.88 | CHANGED (your decision): about 150 words, one line per paragraph |
| Milestone | - List the open milestones: | create-github-issue/SKILL.md (Milestone), project.md (Milestones) | 0.80 | changed: lists all milestones (?state=all), handles none; policy in project.md (Milestones) |
| Milestone | - If no milestone is applicable, ask the user whether to proceed witho | create-github-issue/SKILL.md (Milestone) | 0.65 | CHANGED (your decision): every issue gets a milestone, unless the user decides otherwise |
| Issues from Review Findings | - After the issue is created, the number of the issue is recorded in t | create-github-issue/SKILL.md (Issues from Review Findings) | 0.84 | CHANGED (your decision): recorded as a `GitHub issue #N.` line at the end of the item, after asking |
| Example | Title: `The quiet summary omits the count of the skipped test cases` | create-github-issue/SKILL.md (Length) | 0.50 | dropped by decision (project example, label, milestone) or unified wording |
| Example | ```markdown `src/reporter-human.cpp`, `end_session()`: with `--quiet`, | create-github-issue/SKILL.md (Body) | 0.37 | dropped by decision (project example, label, milestone) or unified wording |

## create-javascript-mjs

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| Conventions | - **Module system**: ES modules with the `.mjs` extension (`package.js | create-javascript-mjs/SKILL.md (Conventions) | 0.75 | reworded: Node version taken from engines; the 'type' remark generalised |

## doxygen-review

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| Step 2 — Read and Verify Against the Code | - **Shared enumerations and options.** Describe the behaviour of every | - | 0.67 | dropped: a past example, removed with the project.md section (your decision) |
| Step 2 — Read and Verify Against the Code | - **Examples.** Every `@code` example must compile and be correct (e.g | - | 0.70 | dropped: a past example, removed with the project.md section (your decision) |
| Step 4 — Verify | 3. Build and run the tests, at least with the system compiler, with cl | doxygen-review/SKILL.md (Step 4) | 0.84 | reworded: refers to project.md (Tests) |

## github-commit

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| Procedure | 3. **Check that the tests were run** as required by the "Testing" sect | github-commit/SKILL.md (Procedure 3) + project.md (Tests) | 0.74 | reworded: commands moved to project.md (Tests) |
| Procedure | 4. **Check the generated files.** If `xcdl-package.jsonc` or the build | github-commit/SKILL.md (Procedure 4), project.md | 0.72 | split: generic rule + project.md (Generated Files) + project.md (Tests) |
| Procedure | 8. **Report** the commit hash and subject, with `git log -1 --format=' | github-commit/SKILL.md (Procedure 8), project.md (Short Hashes) | 0.84 | split: generic '%h' rule + project.md (Short Hashes) |
| Subject | - `#N: ` followed by a summary in the imperative mood, starting with a | github-commit/SKILL.md (Subject) | 0.63 | CHANGED (your decision): unified commit subject rule (lower case) |
| Subject | - Describe the change, not the problem (the issue title describes the | project.md (Examples) | 0.70 | dropped: a project example (your decision) |
| Body | > In v5.0.1, the test case bodies received a subtest&, and the > appl | github-commit/SKILL.md (Procedure) | 0.43 | dropped by decision (project example, label, milestone) or unified wording |
| Body | > Add back subtest, as an alias of test_case, marked > [[deprecated]] | review-common.md (Judging Findings) | 0.55 | dropped by decision (project example, label, milestone) or unified wording |
| Body | > Test it in deprecated.cpp, update the compatibility notices, and > | github-commit/SKILL.md (Body) | 0.53 | dropped by decision (project example, label, milestone) or unified wording |
| Example | ```text #155: Accept explicit bool conversions in checks The checks ac | github-commit/SKILL.md (Procedure) | 0.36 | dropped by decision (project example, label, milestone) or unified wording |
| Commits without an Issue | - The subject has no `#N: ` prefix; the other subject rules apply (the | github-commit/SKILL.md (Commits without an Issue, Subject) | 0.63 | CHANGED (your decision): unified commit subject rule (lower case) |
| Issue Comment | After a commit with `Fixes #N`, add a comment to the issue. GitHub can | github-commit/SKILL.md (Issue Comment) | 0.58 | reworded: common Issue Comment (posted after the push, with the final hash) |
| Issue Comment | - Start with `Fixed in <short hash>`, followed by a brief explanation | github-commit/SKILL.md (Issue Comment) | 0.63 | CHANGED (your decision): short closing comment |
| Issue Comment | - Write the paragraphs unwrapped (one line each), in Markdown, with ba | github-commit/SKILL.md (Issue Comment) | 0.79 | same (common Issue Comment, reworded) |
| Review Documents | If an item refers to the issue or to the same finding, **ask the user* | github-commit/SKILL.md (Review Documents) | 0.82 | same (common Review Documents, reworded) |
| Review Documents | - `` Fixed in `a8733dc2` (#96): <what was done>. `` (the format of `AP | github-commit/SKILL.md (Review Documents), project.md (Review Documents) | 0.65 | CHANGED (your decision): unified note format (GitHub issue #N); the old format is kept for the earlier items (project.md) |
| Review Documents | - `` Status: fixed in #155, commit `2933857e`, on 2026-10-21. <what wa | github-commit/SKILL.md (Review Documents) | 0.55 | dropped by decision (project example, label, milestone) or unified wording |

## rewrite-bash-to-javascript

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| frontmatter | description: 'Rewrite a bash/shell script (.sh) in this project as an | rewrite-bash-to-javascript/SKILL.md (frontmatter) | 0.84 | reworded: description refers to create-javascript-mjs instead of the two scripts |

## website-api-review

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| The Published Version | 3. If there are differences, tell the user (naming the files) and ask | website-review/SKILL.md (The Published Version) | 1.00 | reworded: the three options of the common Published Version (the published site, the local build, or the site as it is) |
| The Site Sources | - the hand-written Doxygen sources in `website/doxygen/`: `topics.h` ( | website-api-review/SKILL.md + project.md (The Published Pages) | 0.84 | split: generic list + exact list in website-api-review/project.md |
| Step 2 — Read the Pages as the Reader Sees Them | 1. the API home page (`index.html`) and the topic tree (the sidebar of | website-api-review/project.md (Reading Order) | 0.75 | split: generic + task order in website-api-review/project.md |
| Step 2 — Read the Pages as the Reader Sees Them | 4. the class pages of the public classes (`runner`, `runner_options`, | website-api-review/project.md (Reading Order) | 0.82 | moved: website-api-review/project.md (Reading Order) |
| Sources of truth | - behaviour: `src/*.cpp` and `inlines/*.h`, following the call chain ( | website-api-review/project.md (Sources of Truth) | 0.81 | moved: call-chain example to website-api-review/project.md |
| Sources of truth | - configuration macros: `micro-test-plus.h`, `xcdl-package.jsonc` (inf | website-api-review/project.md (Sources of Truth) | 0.74 | split: generic + exact files in website-api-review/project.md |
| Completeness | - conditional availability (e.g. the exception checks exist only with | website-api-review/project.md (Completeness) | 0.85 | split: generic + example in website-api-review/project.md |
| Completeness | - the traps a user is likely to hit (tolerances, pointer comparisons, | website-api-review/project.md (Completeness) | 0.68 | moved: website-api-review/project.md (Completeness) |
| Completeness | - the customisation points (`expression_formatter` for user-defined ty | website-api-review/project.md (Completeness) | 0.69 | moved: website-api-review/project.md (Completeness) |
| 1. Defects | - wrong paths, versions, names, namespaces (e.g. `detail::op` for `typ | website-api-review/project.md (Past Findings) | 0.57 | moved: example to website-api-review/project.md (Past Findings) |
| 3. Structure and presentation | - depth of the topic tree and collapsed categories; the root of the tr | website-api-review/project.md (Kept on Purpose) | 0.69 | split: generic root rule + µTest++ levels in project.md (Kept on Purpose) |
| 3. Structure and presentation | - documentation-only files (`top-common.h`, `topics.h`) published as l | website-api-review/project.md (Kept on Purpose) | 0.75 | moved: website-api-review/project.md (Kept on Purpose) |
| 3. Structure and presentation | - duplicate entries in the class indices (`compare_op`, `predicate_op` | website-api-review/project.md (Kept on Purpose) | 0.71 | moved: website-api-review/project.md (Kept on Purpose) |
| 3. Structure and presentation | - topics with a single member, or with two members, that would be clea | website-api-review/project.md (Kept on Purpose) | 0.84 | split: generic rule + decision in project.md (Kept on Purpose) |
| 3. Structure and presentation | - topics whose brief does not match their members; the "C API" topic, | website-api-review/project.md (Kept on Purpose) | 0.51 | split: generic rule + decision in project.md (Kept on Purpose) |
| 4. API design, as seen in the reference | Only what the reference exposes and cannot explain well: `detail` type | website-api-review/project.md (Kept on Purpose, Design Review Reports) | 0.55 | split: generic + accepted items and API-REVIEW naming in project.md |
| 5. Consistency | - test case / subtest / test; check / expectation / assertion / condit | website-api-review/project.md (Kept on Purpose) | 0.74 | moved: website-api-review/project.md (Kept on Purpose) |
| 6. Language and style | ```sh grep -rio '<phrase>' include src website/doxygen/topics \ websi | website-api-review/SKILL.md (6. Language) | 0.63 | reworded: one grep over website/doxygen (*.h, *.cpp, *.dox) |
| 6. Language and style | ```sh awk 'length > 80 {print FILENAME":"FNR": "length}' \ website/do | website-api-review/SKILL.md (6. Language) | 0.79 | reworded: find over all website/doxygen *.dox |
| 8. Incidental observations in the code | Code defects found while verifying the reference (e.g. an operator who | website-api-review/project.md (Kept on Purpose) | 0.66 | moved: website-api-review/project.md (Kept on Purpose) |
| Numbering | Every actionable item in the report gets a permanent number, `#1`, `#2 | website-api-review/SKILL.md (Numbering) | 0.77 | split: review-common + website-api-review Numbering |
| Numbering | - Each problem is a separate numbered item; several occurrences of the | review-common.md (Numbering) | 0.85 | same (example dropped; review-common) |
| Numbering | - Do not group independent problems under one number (e.g. a wrong lin | review-common.md (Numbering) | 0.80 | reworded: example dropped (review-common) |
| Numbering | - The numbers never change once assigned, within the report of the run | website-api-review/SKILL.md (Numbering) | 0.72 | same (website-api-review Numbering) |
| Numbering | - If a problem turns out to be wrong, mark it `(withdrawn)` with the r | review-common.md (Numbering) | 0.74 | moved: review-common.md (Numbering) |
| Numbering | The check counts only the items that start with `- **#n` or `\| #n`, | review-common.md (Numbering) | 0.64 | moved: review-common.md (Numbering, item forms) |
| Report | Write the report to a new file, `maintenance/docs/WEBSITE-API-REVIEW-< | website-api-review/SKILL.md (Report), review-common.md | 0.79 | moved: review-common.md (Report Files) |

## website-review

| Backup section | Rule (start) | Where it is now | Score | Verdict |
| --- | --- | --- | --- | --- |
| The Published Version | 3. If there are differences, tell the user (naming the files) and ask | website-review/SKILL.md (The Published Version) | 0.64 | reworded: the three options of the common Published Version (the published site, the local build, or the site as it is) |
| Reading the Published Pages | - keep the `<details>` and `<summary>` elements, or mark them, since t | website-review/SKILL.md (Reading the Published Pages) | 0.85 | split: the rule is kept in website-review/SKILL.md; the past-finding reference was dropped (your decision) |
| 1. Defects | - sample outputs: the reference files in `tests/expected/tap/` and `t | website-review/SKILL.md (1. Defects) + website-review/project.md | 0.83 | split: generic rule + paths to website-review/project.md |
| 4. Consistency | - project terms (test case/subtest/check, suite, runner, reporter); | website-review/project.md (Terms) | 0.75 | moved: website-review/project.md (Terms) |
| 4. Consistency | - versions repeated in several places (Node.js, xpm), and example path | website-review/project.md (Terms) | 0.80 | moved: example to website-review/project.md (Terms) |
| Numbering | Every actionable item in the report gets a permanent number, `#1`, `#2 | website-review/SKILL.md (Numbering), review-common.md | 0.76 | split: general part in review-common; coverage list kept in website-review Numbering |
| Numbering | - Do not group independent problems under one number, and do not use n | website-review/SKILL.md (Numbering) | 0.83 | same (website-review Numbering + review-common) |
| Numbering | - Each review writes a new report (see "Report"), numbered from `#1`. | review-common.md (Numbering) | 0.59 | moved: review-common.md (Numbering) |
| Numbering | - If a problem turns out to be wrong, mark it `(withdrawn)` with the r | review-common.md (Numbering) | 0.74 | moved: review-common.md (Numbering) |
| Numbering | - When the user later refers to a number (e.g. "fix #7"), it means the | review-common.md (Acting on an Item) | 0.73 | moved: review-common.md (Acting on an Item) |
| Report | Write the report to the next `maintenance/docs/WEBSITE-REVIEW-N.md` fi | website-review/SKILL.md (Report), review-common.md | 0.76 | moved: review-common.md (Report Files) |

