---
name: website-review
description: 'Review the content of the µTest++ Testing Framework website (the Docusaurus site in website/), excluding the API reference pages under docs/api/: readability, ease of understanding, structure, consistency, language, and technical accuracy against the code. Report the problems found, each with a permanent number, and suggest improvements in the source files, naming the template to fix when a file is generated. Use when the user asks to "review the website", "check the web pages", "analyse the documentation site", or to find stale, wrong, or placeholder content on the site.'
argument-hint: 'Optional: page or folder to review (e.g. docs/user, blog); defaults to the whole site except docs/api'
---

# Website Review — µTest++ Testing Framework

## When to Use

- The user asks for a review of the website content, or of some of its
  pages.
- Before a release, to find stale versions, commands, and outputs.
- After API or command line changes, to find the pages left behind.

This skill reports problems and suggests improvements; it does not edit
the website, unless the user asks for that separately (e.g. "fix #4").

The API reference pages (`website/docs/api/`, generated from the Doxygen
comments) are **out of scope**; they are reviewed separately (see the
`website-api-review` skill). Links from the reviewed pages into
`/docs/api/` are in scope: check that they point to the right group.

## Scope

If the user specifies a page or a folder, review only that. Otherwise
review:

- the home page (`website/src/pages/index.tsx` and
  `website/src/components/HomepageFeatures/`);
- every page under `website/docs/`, except `docs/api/`, with all the
  partials it imports;
- the blog (`website/blog/`), including `_common/` and `_templates/`;
- the navigation: `website/docusaurus.config.ts` (navigation bar and
  footer), `website/sidebars.ts`, and the `sidebar-*-custom.*` files;
- the site configuration in `website/config/` that feeds the pages
  (e.g. `website-templates.json`).

State the scope, the branch, and the commit (`git rev-parse --short
HEAD`) at the top of the report.

## Reading the Site

The server at <http://localhost:3000/micro-test-plus-xpack/> is
usually the Docusaurus development server (`npm run start` in
`website/`). It returns only the client-side shell, not the page text,
so `curl` or `WebFetch` on it is useless. Work from the sources:

1. Start from each page's `index.mdx`, read its front matter, and
   follow every `import` of a partial (`_common/`, `_project/`,
   `@site/docs/_common/`, …), recursively. Read the partials in the
   order in which the page renders them; this is the order the reader
   sees, and the order in which to judge the structure.
2. Note the properties passed to partials (e.g.
   `<CommonPrerequisites nodeVersion="…"/>`); check whether the partial
   actually uses them.
3. To know which pages are **published**, use the built site:
   `website/build/sitemap.xml` (run `npm run build` in `website/` if
   the build is missing or older than the sources; this also reports
   broken internal links). Pages present in the sitemap but absent
   from the sidebar and navigation bar are suspect. Front matter
   `unlisted: true` hides a page from the sitemap; `draft: true`
   excludes it from production.
4. Partials that no page imports are dead; find them with `grep` over
   the `import` lines.

## Generated Files

Most website files carry a header "DO NOT EDIT! Automatically
generated from docusaurus-template-liquid/…", naming their template.
They are regenerated with `npm run generate-website-commons` in
`website/`, so changes made in place are lost. The templates are in
the `@xpack/docusaurus-template-liquid` package
(`website/node_modules/@xpack/docusaurus-template-liquid/`, usually a
link to a writable checkout); for every problem in a generated file,
open the named template, confirm the problem is there, and name it in
the report.

The files owned by the project, edited in place, are those without the
header: all `_project/` partials, the glossary, the blog posts (but not
`blog/_common/` and `blog/_templates/`), and any page added by hand.

Mark each finding **[template]** or **[project]**. Template problems
usually affect the other µOS++ and xPack sites as well; say so when
relevant.

## Checks

Read the full text; do not skim. For every technical statement,
verify it against the project, not against another page.

### 1. Defects

Problems a reader would notice as broken or wrong. Report these first.

- **Placeholders**: `TODO`, `@todo`, `TBD`, lorem ipsum, template
  leftovers (e.g. `description: TODO`, "TODO new/maintenance
  release"), sample content in another language, empty sections.
- **Published by mistake**: test pages, empty pages, pages without
  front matter (see "Reading the Site").
- **Wrong facts**, checked against the sources of truth:
  - API names, signatures, constraints, and return types: the headers
    in `include/micro-os-plus/micro-test-plus/` and their `inlines/`;
  - behaviour (what a failed assumption does, execution order, which
    command line options exist and their forms): `src/*.cpp`, in
    particular `runner.cpp` and `reporter.cpp`;
  - sample outputs: the reference files in `tests/assets/tap/` and
    `tests/assets/txt/`, and the programs in `tests/sources/*/src/`;
    check the format, the totals, the names, and the line numbers
    against the listing shown next to the output;
  - files, folders, and the package content: the repository tree and
    `npm pack --dry-run` (or the latest `*.tgz`);
  - build integration: `CMakeLists.txt` (all targets), `meson.build`,
    `xcdl-package.jsonc`, and the preprocessor macros actually used in
    `include/` and `src/`;
  - dependencies and engine versions: `package.json` (`engines`,
    `xpack.dependencies`, `minimumXpmRequired`);
  - commands: the scripts in `package.json`, `website/package.json`,
    and `tests/package.json`, and the xpm actions in their
    `xpack.actions`; every command shown must exist and work as
    written (also check single-dash typos such as `-verbose`);
  - platforms, toolchains, and CI: `tests/platforms/`,
    `tests/package.json`, and `.github/workflows/`;
  - versions and dates: `git tag`, `CHANGELOG.md`, and the blog posts.
- **Statements contradicted by the project rules**, e.g. claims about
  xCDL generating files (see the xcdl section of
  `.github/copilot-instructions.md`).
- **Broken links**: internal links are checked by the build; check the
  external links to this repository by hand (paths renamed in the
  repository, e.g. `tests/src/` → `tests/sources/`, and the branch in
  the URL).

### 2. Version history

The history of the project is told in several places: the
compatibility notices (`docs/getting-started/_project/`), the History
page, the User's Guide overview, the release blog posts, and
`CHANGELOG.md`. Check that:

- every major (and relevant minor) version has a compatibility notice
  listing its breaking changes, with the old and new names;
- the dates and the version in which each change was introduced agree
  everywhere, and agree with the git tags;
- every published tag has a blog post (or the omission is explained);
- breaking changes are listed as "Major changes" in the blog post, not
  as "Enhancements".

### 3. Structure

For each page, and for the site as a whole:

- **Audience**: who the page is for (user, contributor, or
  maintainer); content for one audience should not be mixed into
  another's page.
- **Order**: the sections follow the reader's task (e.g. install →
  integrate → configure → alternatives → uninstall), and the most
  important content comes first. Note where the reader must pass
  project logistics or secondary content to reach what they came for.
- **Length**: very long pages that combine tutorial, concepts, and
  reference should be split; propose the split, with page titles and
  contents.
- **Duplication**: the same content on several pages (it diverges);
  propose one location and links elsewhere.
- **Navigation**: every page is reachable from the sidebar or the
  navigation bar; collapsed categories do not hide the only route to
  a page; labels match page titles; the home page tells the visitor
  what the project is and where to start.
- **Completeness**: user-visible features (from the headers, the
  command line parser, and the release notes) that no page documents;
  concepts used before they are defined; sections with no example
  where one is needed; a glossary covering the terms the site relies
  on.

### 4. Consistency

Build a table of the names used for the same thing, and propose one:

- the guides (page title, H1, sidebar label, navigation bar label,
  links in text, blog posts);
- project terms (test case/subtest/check, suite, runner, reporter);
- product and tool names (node-tap, Meson, Docusaurus, xpm/xPack);
- spelling variants (licence/license, website/web site);
- versions repeated in several places (Node.js, xpm), and example
  paths (e.g. `~/Work/micro-os-plus/…`);
- heading capitalisation (sentence case, "and" rather than "&") and
  heading levels (no level jumps, no level-2 steps among level-3
  siblings);
- the format of sample outputs across pages.

### 5. Language and style

The rules are those in `.github/copilot-instructions.md` (Language and
Tone): British English, formal tone, no contractions, no colloquialisms
or humour, the Oxford comma, and "folder" rather than "directory".
In addition, check readability:

- inflated vocabulary that adds length without content ("utilise" for
  "use", "comprehensive", "readily", "seamlessly", "it is advisable
  to"); count the occurrences and propose the plain word;
- sentences that describe the text instead of saying something;
- informal headings, summaries, and admonition titles;
- admonitions used for ordinary statements;
- inconsistent list styles (fragments and sentences mixed,
  inconsistent capitalisation and punctuation);
- unclear or wrong technical terms (e.g. "rebase A onto B" used for
  the opposite operation);
- code examples that would not compile, shadow names, or trigger
  warnings under the project's flags.

Do not report the API reference wording (out of scope), and do not
rewrite text merely to suit a preference; report a style problem only
when it hinders understanding or breaks a project rule.

### 6. Incidental observations

Problems found in the code, the package, or the tests while checking
the website (e.g. a file missing from the npm package, an option that
does not behave as documented). Report them in a separate section; it
is not always clear whether the page or the code is wrong, so say
which needs checking.

## Numbering

Every actionable item in the report gets a permanent number, `#1`,
`#2`, and so on, counting through the whole report (not restarting in
each section), so that the user can refer to any of them (e.g. "fix
#12", "apply #40 to #43"). This covers all the problems, every row of
the consistency table, every language and style item, every proposal in
the restructuring section, and every incidental observation. Only the
descriptive parts (the header, the summary, the note on generated
files) and the "Reviewed and found correct" list are not numbered.

- Each problem is a separate numbered item; several occurrences of the
  same problem (e.g. the same typo in all blog posts) are one item.
- Do not group independent problems under one number, and do not use
  nested sub-items for separate problems; a sub-list is acceptable only
  for the details of a single problem.
- In a proposed restructuring, number each proposed page or section
  move separately, so that each can be accepted or rejected on its own.
- The summary and the proposed order of work refer to the items by
  number, not by section.
- The numbers never change once assigned. When the report already
  exists, read it first: keep the numbers of the problems already
  listed, mark those fixed meanwhile with `(fixed)` and a one-line note,
  keep those still open, and number the new problems after the highest
  existing number. Never reuse a number.
- If a problem turns out to be wrong, mark it `(withdrawn)` with the
  reason; do not delete it.
- If the existing report predates this numbering (it uses section
  numbers only), number its items once, in order, say so at the top,
  and keep those numbers from then on.
- When the user later refers to a number (e.g. "fix #7"), act on that
  item and update its status in the report.

## Report

Write the report to `maintenance/docs/WEBSITE-REVIEW.md`, in British
English and in a formal tone, with lines shorter than 80 characters:

```markdown
# Website review

Date: <date>, on branch `<branch>`, commit `<hash>`.

Scope: <pages reviewed; exclusions, always including docs/api/>.

Method: <sources read, whether the site was built, what the
statements were checked against>.

Summary: <n> problems (<open> open, <fixed> fixed, <withdrawn>
withdrawn). <The most serious problems, by number, and the suggested
order of work.>

## Note on generated files

<the template package, how to regenerate, which files are project
files>

## 1. Defects

- **#1 — <short title>.** [template|project] `<file>` line <n>:
  <what is wrong, the evidence (file, setting, or command checked), and
  the suggested change>

## 2. Version history

## 3. Structure

### <page or site-wide area>

## 4. Consistency

| # | Concept | Variants found (where) | Suggested |
| --- | --- | --- | --- |
| #20 | <concept> | <variants, with files> | <the one to use> |

## 5. Language and style

- **#25 — <short title>.** <description>

## 6. Proposed restructuring

<only when a page should be split or reordered>

- **#30 — <proposed page or move>.** <its contents, and the source
  sections it takes them from>

## 7. Incidental observations outside the website

- **#35 — <short title>.** <description, and whether the page or the
  code needs checking>

## 8. Reviewed and found correct

- <pages and areas checked without problems, so that the next review
  knows what was covered>
```

Each item names the source file to change (not only the URL), states
the problem directly, gives the evidence, and proposes the concrete
replacement text or action. When the fix is a decision for the
maintainer (e.g. remove a page or write it), say so and offer the
options, rather than choosing silently.

## Procedure

1. Determine the scope; read the existing report, if any.
2. List the pages (sidebar, navigation bar, sitemap) and the sources in
   scope; build the site if needed.
3. Read each page through its imports, in render order, noting
   findings as you go.
4. Verify every technical finding against the sources of truth listed
   in check 1, and every generated-file finding against its template.
5. Do the cross-page checks (version history, consistency table,
   duplication, navigation).
6. Number the findings and write the report.
7. Give the user a short summary: the counts, the most serious problems
   by number, and the decisions needed. Do not fix anything unless
   asked.
