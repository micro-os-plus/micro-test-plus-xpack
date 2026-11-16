---
name: website-api-review
description: 'Review the API reference pages of the µTest++ Testing Framework website, as published under /docs/api/ (generated from the Doxygen comments and the topic sources in website/doxygen/): structure, consistency, readability, language, and accuracy against the code, with examples and behaviour claims confirmed by probe programs. Report the numbered problems, with fixes in the generating sources. Use when the user asks to "review the API reference", "review the API pages", "check the Doxygen pages on the website", or to find stale, wrong, or placeholder content in docs/api.'
argument-hint: 'Optional: URL, topic, page, or source to review (e.g. a topics/*.dox file, or a classes/... page); defaults to the whole API reference on the published site'
---

<!--
DO NOT EDIT!
Automatically generated from template file: npm-packages-helper/templates/common/.github/skills/_micro-os-plus/website-api-review/SKILL-liquid.md;
put the project rules in .github/skills/project.md (all the skills) or
in .github/skills/website-api-review/project.md (this skill only);
see .github/skills/README.md.
-->

# Website API Reference Review — µTest++ Testing Framework

## When to Use

- The user asks for a review of the API reference pages, or of some
  topics or classes in it.
- Before a release, to find stale examples, outputs, and descriptions.
- After changes to the API, the Doxygen comments, or the topic
  sources, to check what the reader now sees.

This skill only reports problems and suggests improvements (see
"Procedure"); applying a finding is a separate request (for example
"fix #4").

Related skills, with different scopes:

- `website-review`: the rest of the website (excludes `docs/api/`);
- `doxygen-review`: verifies and fixes the Doxygen comments in
  `include/` and `src/` (use it to apply the **[header]** findings);
- `design-review`: the design of the C++ API, from the code alone;
- `code-review`: style, documentation, and correctness of a change.

This review looks at the API through the reference pages: what a
reader learns, in which order, and whether it is true. API design
problems belong to `design-review`; report them here only when they
affect the reference (for example `detail` types in public signatures
that the pages cannot explain), and cross-reference the latest design
review report (see "Report Files" in `.github/skills/review-common.md`,
and "Review Documents" in `.github/skills/project.md` for older names).

Read `.github/skills/website-api-review/common.md` (the published version,
reading the pages, the local build, numbering, and the procedure), and
`.github/skills/review-common.md` (the rules shared by the review
skills) and `.github/skills/project-defaults.md`, `.github/skills/project.md` first, and `project.md` in this
folder, if it exists (for the decisions of the maintainer, the reading
order of the pages, the sources of truth, and the past findings of this
project); their rules extend these, and take precedence where they
differ.

## Scope

If the user specifies a URL, a page, or a folder, review only that.
Otherwise review the whole API reference, as published on the
site, which is the reference for the review, since it is what the
readers see:

- <https://micro-os-plus.github.io/micro-test-plus-xpack-webpreview/docs/api/>
- the list of the published pages is in the site's
  [`sitemap.xml`](https://micro-os-plus.github.io/micro-test-plus-xpack-webpreview/sitemap.xml);
  filter the URLs that contain `/docs/api/`.

The local pages under `website/docs/api/` are not the reference; they
are only the input of the site build.

The review reads the published text, but reports every finding against
the source file that produces it, since that is where the fixes go (see
"The Site Sources").

Each run is a fresh review: do not open the earlier
`WEBSITE-API-REVIEW-<n>.md` reports (list their names only, to choose
the next number). When a finding matches an earlier one, say so only if
the user asks for it.

## The Site Sources

For each published page, find its sources in the following locations:

- the Doxygen comments in `include/` (with `inlines/`) and `src/`;
- the hand-written Doxygen sources in `website/doxygen/`: `topics.h`
  (the topic tree and its order), `pages/mainpage.dox` (the API home
  page), and the `*.dox` files of its sub-folders (for example
  `files/`, `folders/`, `macros/`, and `topics/`);
- `website/doxygen/top-common.h`, generated from
  `docusaurus-template-liquid` (the "µOS++ Topics" group, the `include`
  folders, and the `micro_os_plus` namespace);
- the configuration: `website/doxygen/config.doxyfile`,
  `common-config.doxyfile`, and `original-config.doxyfile`;
- the API navigation: `website/sidebar-category-doxygen.json` and
  `website/docusaurus-config-navbar-doxygen.json`.

State the scope, the branch, the commit (`git rev-parse --short
HEAD`), and the commit of the published version (`git rev-parse --short
origin/webpreview`) at the top of the report.

## How the Pages Are Made

```text
include/, src/  ─┐
website/doxygen/ ┼─ doxygen ─> website/doxygen/xml/ ─ doxygen2docusaurus
top-common.h    ─┘   (config.doxyfile)                       │
                                                             v
                        website/docs/api/**/*.md, sidebar and navbar JSON
                                                             │
                 published HTML <─ docusaurus build <─ push to webpreview
```

- `npm run generate-website-doxygen` in `website/` runs both steps of
  the generation; a push to the `webpreview` branch publishes
  the result.
- Every generated Markdown file carries "DO NOT EDIT! Automatically
  generated via doxygen2docusaurus by Doxygen"; never report a fix to be
  made in a generated page. Name the source instead, marked as one of:
  - **[topic]**: a hand-written source in `website/doxygen/`;
  - **[header]**: a Doxygen comment in `include/` or `src/`;
  - **[config]**: a Doxygen configuration file;
  - **[template]**: `top-common.h`, fixed in the
    `@xpack/docusaurus-template-liquid` package (shared with the other
    µOS++ sites);
  - **[converter]**: the `@xpack/doxygen2docusaurus` package (a
    rendering problem present in the XML but lost or garbled in the
    Markdown; shared with the other µOS++ and xPack sites);
  - **[code]**: a change to the library code or API.
- `topics.h` defines the topic tree with `@addtogroup` and
  `@include{doc}`; the order of the includes is the order of the
  sidebar.
- Members join a topic with `@ingroup` in their comment, or by being
  inside an `@addtogroup ... @{ ... @}` block; the latter also pulls in
  members of classes declared inside the block.

## The Doxygen Configuration

The Doxygen configuration (`website/doxygen/config.doxyfile`,
`common-config.doxyfile`, which is generated from a template of
`docusaurus-template-liquid`, and `original-config.doxyfile`) is changed
only for a real defect, such as a value that is wrong. Do not
propose a change of an option to improve the pages; fix the comments or
the topics instead, or report the finding as an observation. In
particular, the maintainer keeps these on purpose:

- `REFERENCES_RELATION = YES` and `REFERENCED_BY_RELATION = YES`, for the
  "References" and "Referenced by" lists, including the entries that
  Doxygen resolves by name, across overloads;
- `EXTRACT_PRIVATE = YES` and `HIDE_FRIEND_COMPOUNDS = NO`, so that the
  private members and the friends stay on the pages;
- `EXTRACT_ANON_NSPACES = YES`, so that the anonymous namespaces of the
  source files, with their local helpers, stay in the indices;
- `INLINE_SOURCES = YES`, so that the file pages keep the source
  listings, and the page sizes that result.

The decisions of the maintainer about this project (what is kept on
purpose, and the conventions to apply) are listed in `project.md` in
this folder. Do not report them again, and do not ask about them; if
one of them seems wrong, say so in one line, without a numbered
finding.

## Step 1 — Baseline

Use the session scratchpad (shown as `<scratch>`) for every output;
do not write into the repository, except for the final report and the
tool caches that the commands below create (for example
`website/.docusaurus/`, which is not tracked).

1. **Freshness.** Besides the differences between the published version
   and the current branch ("The Published Version"), compare the last
   regeneration on the `webpreview` branch with the last change
   of the sources on it:

   ```sh
   git log -1 --format='%h %ci %s' origin/webpreview -- website/docs/api
   git log --oneline <that hash>..origin/webpreview -- \
     include src website/doxygen
   ```

   Any commit listed means that the published pages are stale; check
   whether its content appears in them (`grep` the downloaded pages for
   a sentence it added), and report it as the first defect. Also grep
   for a sentence of the last regeneration, to confirm that the site was
   published from it.

   Do not regenerate the pages in the repository
   (`npm run generate-website-doxygen` overwrites `website/docs/api/`
   and `website/doxygen/xml/`). When the pages are stale, ask the user
   to regenerate and publish them before the page-level checks
   (structure, sizes, links); until then, take the text of the stale
   pages from the sources and the structure from the Doxygen XML
   generated into `<scratch>` in the next step.

2. **Doxygen strict checks.** Run the three automatic checks of the
   `doxygen-review` skill, following its "Step 1 — Automatic Checks"
   for the exact commands (the overlay `check.doxyfile`, with
   `EXTRACT_ALL = NO` and the `WARN_*` options, run from
   `website/doxygen`; then
   `node .github/skills/doxygen-review/scripts/check-doxygen-merged.mjs <scratch>/out/xml`
   and
   `node .github/skills/doxygen-review/scripts/check-doxygen-style.mjs`),
   and record the counts in the report. Also note the configuration
   warnings Doxygen prints (obsolete tags, options that need other
   options).

3. **Build the site** into the scratchpad, to find broken links and
   anchors (it checks the working tree, so it covers the published pages
   only when "The Published Version" found no differences):

   ```sh
   cd website && npx docusaurus build --out-dir <scratch>/site-build \
     > <scratch>/build.log 2>&1
   grep -n -i -E 'broken|warn|error' <scratch>/build.log
   ```

   It takes a few minutes; run it in the background and continue.

4. **Page sizes.** The size of the downloaded HTML is what the reader's
   browser loads:

   ```sh
   wc -c <scratch>/pages/html/*.html | sort -n | tail
   ```

   Pages of hundreds of kilobytes are slow and usually come from
   `INLINE_SOURCES`, `REFERENCES_RELATION`, `REFERENCED_BY_RELATION`,
   or inherited members. The maintainer keeps these options as they are,
   on purpose, and accepts the page sizes that result (see "The Doxygen
   Configuration"): record the sizes in the report, but do not report
   them as a defect.

## Step 2 — Read the Pages as the Reader Sees Them

Read the downloaded pages, as described in "Reading the Published
Pages", in this order (`project.md` in this folder may give the order
of the topics and the public classes of this project):

1. the API home page (`index.html`) and the topic tree (the sidebar of
   a published page, and its source,
   `website/sidebar-category-doxygen.json`): how many levels before the
   first useful content, which categories are collapsed, whether the
   order follows the reader's task;
2. every topic page (`groups--*.html`), with its source `.dox`;
3. the namespace pages (`namespaces--*.html`), starting with the main
   namespace of the project;
4. the class pages of the public classes (list the `classes--*.html`
   files to find the current ones; deprecated aliases have no page of
   their own), then the internal ones;
5. the indices (`classes.html`, `namespaces.html`, `concepts.html`,
   `files.html`, and `indices--*.html`), the folder and file pages
   (`folders--*.html` and `files--*.html`), and the Deprecated List
   (`pages--deprecated.html`).

For each page, note what the reader needs first (the user-facing
entities, an example) and what stands in the way (deleted special
members, deprecated members listed first, internal types, inlined
sources).

## Step 3 — Verify Against the Code

Read each topic source and each header comment together with the code
it describes (`include/`, `inlines/`, and `src/`), in full. The text
is right only if the code says so; do not check one page against
another.

### Sources of truth

The general ones, completed by `project.md` in this folder:

- signatures, constraints, and return types: the headers;
- behaviour: `src/*.cpp` and `inlines/*.h`, following the call chain;
- command line options, if any: every parser (`grep -n '"--' src/*.cpp`),
  the error paths (`exit()`), and what happens to unknown arguments;
- sample outputs: the reference outputs of the tests, and the programs
  they come from (check the names, the file names, the line numbers,
  and the number format);
- example paths: the repository tree;
- versions and deprecations: `git tag`, `git log -S'<text>'` to find
  when a deprecation was introduced, and `package.json`;
- configuration macros: the public headers, `xcdl-package.jsonc`
  (informative only, see the `xcdl` skill), and the `*-defines.h`
  files of the test platforms, if any.

### Probes

Confirm every claim about behaviour that is not obvious from the code,
and every example, with a probe program in `<scratch>/probe/`, built
as described under "Confirming Findings with Probes" in
`.github/skills/review-common.md`. Report a finding as confirmed only
when the probe reproduced it; otherwise say that it is derived from
reading the code.

**Compile every example** in the topics and in the `@code` blocks,
completed with the declarations it assumes, and with the project
warning flags where practical. `project.md` in this folder lists the
reasons for which the examples of this project have failed before;
they may be fixed by now, so re-verify each one and look for new kinds.

### Claims that need a probe or a code path

Words such as "immediately", "terminated", "aborted", "always",
"never", "each element", "by default", "full report", "any order",
"locale-independent", "returns an output stream". `project.md` in this
folder lists what checks of this kind found in this project; re-verify
before reporting, since the code may have changed.

### Completeness

For each topic, list what a user needs and check that it is there (the
subjects specific to this project are listed in `project.md` in this
folder):

- every option the parsers accept, the error behaviour, and the
  interaction between options;
- the execution order, when the library runs code on behalf of the
  application;
- conditional availability (for example the parts that exist only with
  `__cpp_exceptions`);
- the traps a user is likely to hit;
- the customisation points, reachable from the topics that need them;
- the configuration macros: which ones the application must define,
  where, and what happens otherwise. Doxygen-only definitions
  (`#if defined(__DOXYGEN__)`) appear on the page as "Definition at
  line ... of <header>"; check that the text explains it.

## Checks

### 1. Defects

Problems a reader would notice as broken or wrong. Report these first.

- stale pages (Step 1);
- placeholders (`...`, `TODO`, empty `@details`);
- examples that do not compile, link, or do what the text says;
- sample outputs that differ from the reference outputs or from the
  program they cite;
- wrong paths, versions, names, and namespaces;
- statements contradicted by the code, by the probes, or by another
  statement of the reference (for example two topics giving opposite
  advice);
- descriptions of entities that are unused or describe a design that
  no longer exists; check with `grep` over `include/`, `src/`, and
  `tests/`;
- folder and file pages that misplace files or make wrong claims about
  where the documentation is maintained;
- deprecation notes without a version or with the wrong term;
- rendering defects: text that Doxygen or the converter garbles
  (a backslash inside backticks became `\\endiskip`), stray HTML tags,
  admonitions mapped to the wrong kind (`@important` as a tip),
  members that leak into a topic through an `@addtogroup` block. Compare
  the page with the source to decide between **[header]**/**[topic]** and
  **[converter]**. The "References" and "Referenced by" lists are kept on
  purpose (see "The Doxygen Configuration"); an entry in them that
  Doxygen resolved by name, across overloads, is not a defect.

### 2. Missing information

The completeness list of Step 3; one item per missing subject.

### 3. Structure and presentation

- depth of the topic tree and collapsed categories; the root of the
  tree ("µOS++ Topics") is shared with the other µOS++ sites, so do not
  propose to change it;
- internal entities (`detail`, `inlines/`, `src/`, and the anonymous
  namespaces) mixed with the public ones in the indices; do not propose
  a Doxygen option to separate them (see "The Doxygen Configuration"),
  only a change of the converter, or of the entry points of the topics
  and of the home page;
- page size, as an observation only (see "The Doxygen Configuration");
- order of the members in the class indices (deleted, deprecated, and
  special members before the useful ones), and the use of `@name`
  groups to fix it; the private members (`EXTRACT_PRIVATE = YES`) and
  the friends (`HIDE_FRIEND_COMPOUNDS = NO`) are kept on purpose, so do
  not propose hiding them, or removing the private members from the
  pages;
- topics with a single member, or with two members, that would be
  clearer as sections of a larger topic;
- topics whose brief does not match their members.

### 4. API design, as seen in the reference

Only what the reference exposes and cannot explain well: `detail`
types in public signatures, public classes without an extension point,
member functions named after classes, duplicated helpers, internal
helpers in public namespaces, long-deprecated entities. Read the latest
design review report first, and write "Same as <report> #m" or
"Overlaps <report> #m" instead of repeating its analysis; when there is
none, report only what the reference exposes. These items are decisions
for the maintainer; say so.

### 5. Consistency

Build a table of the names used for the same thing and propose one (the
project terms, and those kept on purpose, are listed in `project.md` in
this folder):

- command line / command-line, run time / run-time / runtime,
  floating point / floating-point;
- topic title capitalisation (the website uses sentence case);
- example headings (`@par Example`, `@par Examples`, `**Example**`);
- the mood of the briefs (third person: "Checks", "Returns");
- list dashes, `\p`/`\c` versus `@p`/backticks, `(void)` versus `()`;
- the format of deprecation notes.

### 6. Language and style

The rules are those of `.github/copilot-instructions.md` (Language and
Tone, and the Doxygen Documentation rules in the `doxygen-review` skill):
British English, formal tone, no contractions, the Oxford comma, "folder"
rather than "directory", lines shorter than 80 characters (also in the
`.dox` sources), `@details` not repeating the `@brief`. In addition:

- count the boilerplate sentences repeated in every comment (for
  example "ensuring clear separation from user code and minimising the
  risk of naming conflicts", "to maintain a structured and modular
  codebase") and the inflated words ("seamless", "advanced", "enhance",
  "facilitate", "comprehensive", "robust", "professional"):

  ```sh
  grep -rio '<phrase>' include src website/doxygen --include='*.h' \
    --include='*.cpp' --include='*.dox' | wc -l
  ```

- promotional or evaluative sentences, and unverified claims ("the
  implementations are efficient");
- sentences that describe the text instead of informing;
- briefs of more than one sentence (they appear in every index);
- long lines in the `.dox` sources:

  ```sh
  find website/doxygen -name '*.dox' -exec \
    awk 'length > 80 {print FILENAME":"FNR": "length}' {} +
  ```

Report a style problem only when it hinders understanding or breaks a
project rule.

### 7. Proposed topic tree

When the topic tree should change, propose the new tree, with each
move numbered separately so that it can be accepted on its own (move a
topic, merge two topics, add a topic, remove a group, change the root).
Name the `topics.h` lines and the `.dox` files involved, and keep the
anchors of merged topics for existing links (including links from the
rest of the website into `/docs/api/`).

### 8. Incidental observations in the code

Code defects found while verifying the reference (for example an
operator whose constraint accepts types it cannot compare, a stale
forward declaration, swapped template parameters, configuration
leftovers). Say whether the page or the code needs changing;
cross-reference the latest design review report when it already lists
the problem.

## Report

Write the report to a new file, `maintenance/docs/WEBSITE-API-REVIEW-<n>.md`
(see "Report Files" in `.github/skills/review-common.md`), with lines
shorter than 80 characters (tables excepted):

```markdown
# Website API reference review

Date: <date>, on branch `<branch>`, commit `<hash>`; published version
`webpreview` commit `<hash>`.

Scope: <pages and sources reviewed; the rest of the website is in
the latest WEBSITE-REVIEW-<n>.md, the API design in the latest design
review report>.

Method: <the published pages downloaded and read, those reviewed from
their local sources because they differ from the published version,
whether the site was built, the results of the automatic checks, the
compiler used for the probes, the reference outputs compared>.

Summary: <n> problems (<open> open, <fixed> fixed, <withdrawn>
withdrawn). <The most serious problems, by number, and the suggested
order of work: regenerate, defects, missing information, topic tree
and presentation, language; the API design decisions last.>

## Note on generated pages

<how the pages are generated and regenerated; the meaning of the
markers [topic], [header], [config], [template], [converter], [code]>

## 1. Defects

- **#1 — <short title>.** [topic|header|config|template|converter|code]
  `<source file>` line <n>: <what is wrong, the evidence (code path,
  probe, reference output), and the suggested replacement text>

## 2. Missing information

## 3. Structure and presentation

## 4. API design

## 5. Consistency

| #   | Concept | Variants found (where) | Suggested |
| --- | ------- | ---------------------- | --------- |
| #n  | <name>  | <variant (file), ...>  | <choice>  |

## 6. Language and style

## 7. Proposed topic tree

## 8. Incidental observations in the code

## 9. Reviewed and found correct

- <pages, topics, and claims checked without problems, so that the
  next review knows what was covered>
```

Each item names the source file to change (never only the generated
page), states the problem directly, gives the evidence, and proposes
the concrete replacement text or action. When the fix is a decision
for the maintainer, say so and offer the options, rather than choosing
silently.
