# Website review

Date: 2026-10-12, on branch `xpack-development`, commit `87931611`.

Scope: the project website served at
<http://localhost:3000/micro-test-plus-xpack/>, excluding the API
reference pages under `/docs/api/`. This covers the home page, all the
pages under `website/docs/` (other than `docs/api/`), the blog, the
navigation bar, the sidebar, and the footer.

Method: the local server is the Docusaurus development server. It
returns only the client-side shell, so the review used the MDX sources
(including every imported partial, in the order in which it is
rendered), the generated `website/build/sitemap.xml`, and the library
sources, against which the technical statements were checked.

Checked: readability, ease of understanding, consistency, structure,
and technical accuracy.

## Summary

The website is broad, and its framework (Getting Started, guides per
audience, releases, blog) is sound. However, the content most important
to a new user is the weakest part:

- Several published pages are placeholders (FAQ, a `TODO` page, a
  markdown test page).
- The User's Guide, the only page that teaches how to use the library,
  is a single 930-line page. Its API signatures and sample outputs no
  longer match the code, and it does not document several
  user-visible features (`--output-file`, the `<<` message syntax, and
  the exact effect of a failed assumption).
- The Integration Guide describes a `diag-trace` dependency that v5.0.1
  removed, and an xCDL-generated configuration header that is not
  generated.
- The version history is told in four places (Getting Started
  compatibility notices, History, the User's Guide overview, and the
  blog), which disagree with each other, and none of them mentions v5.
- The same guide is called the Integration Guide, the Installation
  Guide, and the Install Guide.

The suggested order of work is:

1. Remove or fill the placeholder pages (section 3.1).
2. Correct the factually wrong statements (section 3.2).
3. Regenerate all sample outputs from the reference files in
   `tests/assets/` (item 3.2.6).
4. Split and restructure the User's Guide (section 6).
5. Apply the consistency and style changes (sections 4 and 5).

## 1. Note on generated files

Most of the website sources carry the header "DO NOT EDIT!
Automatically generated from docusaurus-template-liquid/…". These
include all `_common/` partials, all `index.mdx` pages,
`docusaurus.config.ts`, `sidebars.ts`, `src/pages/index.tsx`, and the
`src/components/` files. They must be fixed in the
`docusaurus-template-liquid` templates and regenerated with
`npm run generate-website-commons` in `website/`. Fixes made directly in
this repository will be overwritten.

The files owned by this project, which can be edited directly, are:

- all files in `_project/` folders;
- `docs/getting-started/glossary/index.mdx`;
- `config/website-templates.json`, the flags that select which
  template files are generated and which are left to the project;
- the custom sidebars, `sidebar-docs-getting-started-custom.ts` and
  `sidebar-docs-user-custom.js`;
- the custom home page components,
  `src/components/HomepageFeatures/CustomFeatureList.tsx` and
  `src/components/HomepageExample/index.tsx`;
- the blog posts (but not `blog/_common/` or `blog/_templates/`, which
  are generated).

Each finding below is marked **[template]** or **[project]** to show
where the fix belongs. Since several template problems also affect the
other µOS++ and xPack sites, fixing them in the template has a wider
benefit.

## 2. Site-wide structure and navigation

### 2.1 Home page

1. **[template] (fixed)**
   `src/components/HomepageFeatures/FeatureList.tsx`: the
   three feature cards ("Modern, portable, configurable", "Easy to use &
   reproducible", and "Part of the Node.js ecosystem") are generic
   xPack text. None of them mentions testing. The distinguishing
   properties of µTest++ (macro-free, TAP output, small footprint on
   bare-metal targets, and tested on Cortex-M/A, RISC-V, and native)
   appear only in the tagline. Suggestion: let the template take
   project-specific feature cards from `website/config/`, and use:
   - "Macro-free, expressive checks": `t.expect (mt::eq (a, 42))` reports
     the file, line, and actual values without C macros.
   - "Built for bare-metal": no `iostream`, small footprint, and output
     through `stdout` only, so semihosting or a serial port suffices.
   - "Standard TAP output": TAP 14 by default, a human-readable reporter
     on request, and the result returned as the process exit code.

   Status: fixed. `website/config/website-templates.json` now sets
   `hasCustomHomepageFeatures`, so the generator skips `FeatureList.tsx`,
   and `index.tsx` imports the project-specific
   `src/components/HomepageFeatures/CustomFeatureList.tsx`. It has the
   three cards above, extended with automatic suite registration, the
   supported platforms, and the `--reporter=human` and `--output-file`
   options. Two details remain open: the file still carries the
   generated "DO NOT EDIT!" header although the project owns it, and the
   icons are still the generic xPack ones.
2. **[template] (not applicable)** `src/pages/index.tsx` line 36
   hard-codes `5.0.1` in the install command. It is correct now, but
   it is stale between a version bump and the next regeneration.
   `customFields.releaseVersion` is already available and is used in
   the navigation bar.

   Status: not applicable. `index.tsx` is generated from
   `templates/docusaurus/common/src/pages/index-liquid.tsx` in
   `@xpack/docusaurus-template-liquid`, which writes the version as
   `{{releaseVersion}}`. The literal `5.0.1` is only the result of the
   last generation, and the release process regenerates it.
3. **[template] (fixed)** The home page has no code. One five-line
   example (`ts.test ("…", [] (auto& t) { t.expect (…); });`) under the
   hero section would show the style of the API immediately.

   Status: fixed. The template `index-liquid.tsx` renders a
   project-provided `HomepageExample` component below the feature cards
   when the new `hasHomepageExample` flag is set, and
   `website-templates.json` sets it. The flag is also registered in
   `websiteConfigProperties` in `npm-packages-helper`
   (`scripts-helper.mjs`), which now warns about unknown properties.
   `src/components/HomepageExample/index.tsx` shows the minimal test
   program and its TAP output side by side.

### 2.2 Sidebar and navigation bar

1. **[project] (fixed)** The "Getting Started" sidebar category is
   collapsed (`collapsed: true` in
   `sidebar-docs-getting-started-custom.ts`), so its only child, the
   Glossary, cannot be seen. Either expand the category or move the
   Glossary under the User's Guide, where its terms are used.

   Status: fixed in `fd7a5b05`; the category is now expanded
   (`collapsed: false`). The file is owned by the project
   (`hasCustomGettingStartedSidebar`), not generated, so the item was
   originally mislabelled **[template]**.
2. **[template]** The navigation bar "Documentation" menu lists "About"
   but not "History" or "Glossary"; the sidebar lists "History" and
   links "License" to the generic opensource.org page instead of the
   repository `LICENSE` file, which also covers the Boost-derived
   portions (`LICENSE-Boost`).

   Status: partly not applicable. History is left out of the
   navigation bar menu intentionally. The missing Glossary entry and
   the License link (`sidebars.ts` line 79,
   `https://opensource.org/license/mit`) remain open.
3. **[project] (deferred to section 6)** `sidebar-docs-user-custom.js`
   is an unused starter file: it defines a User's Guide sidebar
   category whose only item is labelled "TODO". It has no effect on
   the site, since `sidebars.ts` imports it only when
   `hasCustomUserSidebar` is set in `website-templates.json`, which it
   is not. (`hasCustomUser`, which is set, controls the guide's
   content, not its sidebar.) Keep the file; it is the mechanism for
   listing the pages of the split proposed in section 6.

### 2.3 Pages published by mistake

`website/build/sitemap.xml` lists two pages that must not be public:

1. **[project] (fixed)** `/docs/developer/install/prerequisites/` —
   the source (`docs/developer/install/prerequisites/index.mdx`) has no
   front matter and its whole content is "TODO". Delete the file.

   Status: fixed in `e9ffb1d0`; the file, and with it the empty
   `docs/developer/install/` folder, was deleted. No page links to it.
   However, the deletion does not persist: the file comes from the
   template's first-time proposals
   (`templates/docusaurus/first-time/docs/developer/_micro-os-plus/install/prerequisites/index.mdx`),
   which `npm run generate-website-commons` copies whenever they are
   missing, so every regeneration recreates it. Remove it from the
   template (or skip it in `generate-website-commons.mjs`), or delete
   it again after each regeneration.
2. **[template] (fixed)** `/docs/test/md/` — a markdown rendering test
   page (`<baburiba>hey</baburiba>`, …). Its sibling
   `docs/test/index.mdx` has `unlisted: true`; this one does not. Add
   `unlisted: true`, or, better, exclude `docs/test/` from production
   builds.

   Status: fixed in the template. Both `docs/test/index.mdx` and
   `docs/test/md/index.md` now have `draft: true` instead of
   `unlisted: true`, so they are shown only by the development server
   and are not built for production. No page links to them.

### 2.4 Dead or empty partials

These do not show on the site, but they mislead whoever edits it:

All four files are first-time proposals of the template: the generator
copies them whenever they are missing, unless it is told to skip them.
Items 2 to 4 are also extension points, imported unconditionally by
generated pages, so they cannot be deleted; an empty one is valid.

1. **[project] (fixed)** `docs/install/_project/_content.mdx` is not
   imported anywhere (the page uses `_common/_content.mdx`). Delete it.

   Status: fixed; the file was deleted. The deletion persists, since
   the generator skips this file when `hasCustomInstall` is not set.
   The other files in `docs/install/_project/` are still imported by
   `_common/_content.mdx`.
2. **[project] (not applicable)**
   `docs/getting-started/_project/_benefits.mdx` contains only a
   comment ("merged into `_features.mdx`").

   Status: not applicable. The µOS++ variant of the Getting Started
   template imports this file unconditionally, and the comment already
   says why it is empty.
3. **[project] (fixed)** `docs/project/about/_project/_more-intro.mdx`
   is empty.

   Status: fixed. It now has two paragraphs on the purpose of the
   project (C++20, embedded and native targets) and its relationship
   with µOS++ (used to test the other packages, but independent of
   them). This also covers the missing paragraph noted in 3.10.1.
4. **[project] (not applicable)** `docs/_project/_documentation.mdx`
   is empty. As a result, the Help Centre section "Check documentation"
   says that one should read the documentation, but links to none of
   it (see 3.9.1).

   Status: not applicable; the partial is kept empty by decision. A
   list of the guides was tried, together with a "Documentation"
   section on the Getting Started page, and both were reverted as not
   needed. The Help Centre remark is tracked in 3.9.1.

## 3. Page-by-page findings

### 3.1 Placeholder content (fix first)

1. **[project] (fixed)** `docs/faq/_project/_content.mdx`: the whole FAQ is a
   German placeholder, "Warum? Darum! (placeholder)". The FAQ is linked
   from the sidebar, from the navigation bar, and from the Help Centre
   ("Check the FAQ for similar problems"). Either remove the page from
   the navigation until it has content, or write real entries.
   Candidate questions, all answered by the current code:
   - Why are the actual values not shown when a check fails? (Plain
     `bool` expressions; use comparators or typed operands.)
   - What happens when an assumption fails? (The whole process is
     terminated through `runner::abort()`; see 3.5.5.)
   - How do I write the results to a file? (`--output-file`.)
   - How do I select the human-readable output? (`--reporter human`.)
   - Why do my static test suites not run? (Object files in a static
     library are not linked unless referenced; see 3.5.12.)
   - Why is the test output interleaved on my board? (See the "Console
     output" section of the User's Guide.)
   - Can I test C code? (Yes; the tests are written in C++20.)
   - In what order do the suites run? (Sorted by name, when
     `exit_code()` is called.)

   Status: fixed. The placeholder was replaced with eight entries, one
   for each candidate question above, each answer checked against the
   code. The order entry also covers the top suite test cases, which
   run immediately when `ts.test (…)` is called (see 3.5.14). The
   entry on failed checks quotes the actual output field,
   `condition: 43 == 42`; the User's Guide samples show `expect:`
   instead, which is one more outdated sample (see 3.2.6).
2. **[template] (fixed)** `docs/user/index.mdx` line 7:
   `description: TODO`. This text is used as the meta description, so
   it appears in search results and link previews. The template
   `docs/user/_micro-os-plus/index-liquid.mdx` already supports a
   `userGuideDescription` property for the `xpack` and
   `xpack-dev-tools` sites, but the branch used by the µOS++ sites
   ignores it and writes `TODO`.

   Status: fixed. `website-templates.json` sets a project-specific
   `userGuideDescription`. The template, now reduced to the µOS++ case
   only (the organisation branches and the `isXpackBinary` and
   `hasTypedocApi` branches were dead in the `_micro-os-plus` variant),
   uses it, and otherwise defaults to "How to use the
   `{{topConfig.preferredName}}`, with examples and a summary of the
   API." The value
   is written through the Liquid `json` filter, so it is quoted and
   escaped, and any text is valid YAML.
3. **[project] (fixed)** `docs/user/_project/_content.mdx` line 604: a
   literal "@todo Provide guidance on this process and include an
   example test." appears on the published page under "Custom Types".
   Either write the section or remove it; a visible "todo" reads as
   unfinished work.

   Status: fixed. Checking the code showed that the first sentence of
   the section was also misleading: the comparators already accept any
   type with the required operators, but they need to print the
   operand values, and the only formatter was the internal
   `detail::expression_formatter`, so `eq()` did not compile for user
   types. The library now exposes it as the public
   `mt::expression_formatter` (in `expression-formatter.h`, documented
   with an example), and the unit test has "Custom types" test cases
   in the "Miscellaneous suite"; the reference outputs in
   `tests/assets/` were updated accordingly. The section now explains
   the operators required by each comparator and the `operator<<`
   needed to report the values, with a complete example, compiled and
   run, and its actual output.

### 3.2 Factually incorrect or outdated statements

1. **[project]** Compatibility notices
   (`docs/getting-started/_project/_compatibility-notices.mdx`):
   - There is no v5.0 entry, although v5.0.0 is a major release. Its
     breaking changes (the configuration header renamed to
     `micro-os-plus/micro-test-plus-defines.h`, and the renamed
     `MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED` and
     `…_TRACE_CONSTRUCTORS_ENABLED` macros) must be listed, with the
     old names, so that users can migrate.
   - "v4.0 (2026-04-20)": the `v4.0.0` tag and the blog post are dated
     2026-04-29.
   - "v2.3.0 (2022-02-19)": there is no `v2.3.0` tag and no blog post;
     the other entries use `X.Y` only. Either say in which published
     version the change shipped, or mark it as unreleased.
   - The v4.0 entry says "Internal static objects are no longer used",
     whilst the Features section advertises automatic registration
     through static constructors. Both are true (`static_runner` and
     `static_suite` are user-created static objects), but the reader
     needs one sentence that reconciles them.
2. **[project]** Blog post
   `blog/2026-07-14-micro-test-plus-v5-0-0-released.mdx`: "Major
   changes: None", with the breaking changes listed under
   "Enhancements". Move them to "Major changes" and describe the
   migration. The summary "updated for xcdl configuration" is also
   misleading, since xCDL is not yet available (see the next item).
3. **[project]** Integration Guide,
   `docs/install/_project/_build-and-integration-info.mdx`:
   - "Dependencies: This library has a single external dependency …
     µOS++ Tracing Infrastructure". v5.0.1 removed the hard dependency
     (`trace.h` is included only if available), and `package.json`
     declares no xpm dependencies. State that `diag-trace` is optional
     and what it adds.
   - "For xCDL enabled projects, this file is automatically generated."
     It is not: the `xcdl` tool is not yet available, and no
     `*-defines.h` file is generated. The following `xcdl-project.jsonc`
     snippet presents a mechanism that does not yet work. Either
     remove it or mark it clearly as planned.
   - "The following options must be supplied to the compiler and
     linker: `-std=c++20`". This is a compiler option only.
   - `MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED` is described as "to include
     and enable the µTest++ library in the build", without saying what
     happens when it is not defined. Explain the effect.
   - The CMake section says the result is "an interface library". The
     `CMakeLists.txt` also defines
     `micro-os-plus::micro-test-plus-objects-library` and
     `micro-os-plus::micro-test-plus-static-library`. Document the three
     targets and when to use each; the choice matters for static
     suites (see 3.5.12).
   - The meson example `executable(your-target, …)` is not valid meson
     (the name must be a quoted string, and the sources are missing).
     The comment `# Nothing, not static.` inside `link_with` is
     unclear; remove the empty `link_with`.
   - "the most common approach is **Arm semihosting**": the RISC-V
     targets use RISC-V semihosting. Write "semihosting".
4. **[template]** `docs/install/_common/_reproducibility-and-dependencies.mdx`
   shows `"minimumXpmRequired": "0.20.7"`; the project uses `0.20.8`.
   The snippet also shows the library as a dependency with
   `"local": "link"`; check that this matches what the current `xpm`
   writes.
5. **[project] (fixed)** User's Guide
   (`docs/user/_project/_content.mdx`), API signatures:
   - `expect()` and `assume()` (lines 351–357) are shown as
     `bool expect (const Expr_T& expr)` with
     `type_traits::requires_t<....>`. The current declaration is
     `requires type_traits::checkable<Expr_T> auto expect (const Expr_T&
     expr, const reflection::source_location& sl = …::current ())`, and
     it returns an object that accepts `<<` messages and reports when
     the full expression ends. Since v4.0 (#26), the variable templates
     have been replaced by concepts.
   - The operators (lines 437–465) are shown with
     `type_traits::requires_t<....>`; they use
     `requires type_traits::any_op<Lhs_T, Rhs_T>`, and the container
     operators use `container_like`.
   - `_b` (line 529) is shown as `operator""_b ()`; it is a string
     literal operator, `operator""_b (const char* name, size)`.
   - Placeholders such as `<....>` look like typing errors. Either show
     the real constraint or write "(constrained)".

   Status: fixed. `expect()` and `require()` are shown with
   `requires type_traits::checkable<Expr_T>` and return `auto`. The
   operators are shown with their real constraints
   (`type_traits::any_op`, `type_traits::is_op`, and
   `type_traits::container_like` for both container operands) and
   return `auto`, as do the string operators; no `<....>` placeholder
   remains. `_b` is shown as
   `operator""_b (const char* name, std::size_t size)`. The wrapper
   aliases are shown as `detail::value<T>`, where they moved with
   API-REVIEW #30.
6. **[project]** Sample outputs. They no longer match the program
   output, and they disagree with each other:
   - The User's Guide shows summaries such as `# { test case passed,
     1 check }` and `# { test suite passed, … }`. The reference file
     `tests/assets/tap/minimal-test.tap` and the Contributor's Guide
     show `# { passed, 2 checks }`.
   - In the failing example (line 181) the total says "1 check passed,
     1 failed", whilst the lines above say "0 checks passed, 1 failed".
   - The reported line numbers do not match the listings: line 17
     (the `t.expect` call is on line 18 of the numbered listing), and
     lines 69, 76, and 77 for a 21-line listing.
   - Blank lines after `TAP version 14` appear in some samples but not
     in others, and not in the reference files.
   - The real output starts with `# Running: …` and `# Built with …`
     lines, which the samples omit without saying so.
   - The human reporter sample shows "Check various conditions (2
     checks)" under a suite named "Minimal", which matches neither the
     minimal example on the same page nor the current reference output
     (`tests/assets/txt/minimal-test.txt`, which names the suite
     `minimal-test`).

   Suggestion: regenerate every sample from an actual run of the code
   shown next to it. To keep them correct, consider importing the
   reference files from `tests/assets/` (with a raw loader) instead of
   pasting copies.
7. **[project]** History (`docs/project/history/_project/_content.mdx`):
   - The heading "April 2026" introduces a paragraph that starts "In
     March 2026"; the heading "April 2022" introduces "At the
     beginning of 2022".
   - It says that v4 added the TAP reporter; the compatibility notices
     and the v3.3.0 blog post say that v3.3 added it.
   - There is no entry for v4.1 or v5.
   - All headings are level 3 under no level-2 heading.
8. **[project]** User's Guide, overview (lines 28–31): it describes
   v1, v3, and v4, but not v5, and duplicates the History page. Replace
   it with one sentence and a link to History.

### 3.3 Getting Started

1. **[template]** The page is long and mixes several audiences. In
   rendered order it contains: an audience note, Overview, an
   "embedded" note, repository locations, a collapsible xpm explanation,
   Features, Install, Status, Testing (CI), Release schedule, Releases,
   Change log, Support, Compatibility notices, Licence, Credits, and a
   request for support. A new user must read past the project
   logistics to reach any example. Suggested order:
   1. Overview (two sentences);
   2. A minimal example with its output (taken from the User's Guide);
   3. Features;
   4. Status;
   5. "Where to go next": the Integration Guide, the User's Guide, and
      the API reference, each with one line on what it contains;
   6. Compatibility notices;
   7. Project information: CI, release schedule, releases, change log,
      support, licence, and credits.
2. **[project]** `_features.mdx`: "largely derived from Boost UT" is
   followed by a list of features that are mostly not from Boost UT
   (test suites, TAP, automatic registration). Say what is derived: the
   comparators, the operators, and the literals. The first bullet,
   "Designed to facilitate testing of both C and C++ projects", needs
   "(the tests themselves are written in C++20)", as the C API section
   of the User's Guide states.
3. **[project]** `_features.mdx`: the parenthesis "(which consequently
   raised the minimum C++20 requirement across the entire µOS++
   project)" is project history, not a feature. Remove it or move it to
   History.
4. **[project]** `index.mdx` (generated, but the text is in the
   template): the paragraph before the compatibility notices quotes
   SemVer and then says the notices are "readily available in the
   respective release notes", which they are not (see 3.2.2).
5. **[template]** `_what-are-xpm-packages.mdx`: the summary "What the
   heck are xpm packages (xPacks)? Please, do not introduce another
   package format!" is informal and not in the tone of the rest of the
   site. Suggestion: "Why xpm packages, and not another package format?"
6. **[template]** `_install-summary.mdx` links to the "Installation
   Guide"; the sidebar and the navigation bar call it "Integration
   Guide" (see 4.1.1).
7. **[template]** `index.mdx` lines 85–87: three blank lines before
   "Credits"; harmless, but the generated output should be tidy.

### 3.4 Glossary

1. **[project]** The page defines only three ISTQB terms. The site also
   relies on: runner, static runner, top suite, suite, static suite,
   test case, subtest, check, expectation, assumption, comparator,
   reporter, TAP, xpm, and xPack. Add one line for each.
2. **[project]** "test case … corresponds to instances of the `subtest`
   class". The User's Guide uses "test case" and "subtest" as two
   different things ("Test cases" and "Subtests" sections); the API
   has `subtest`; the output says "test case". Choose one term for the
   reader (suggested: "test case", with "implemented by the `subtest`
   class") and use it everywhere.
3. **[project]** "test suite … corresponds to instances of the `suite`
   class" omits `static_suite` and `top_suite`.
4. **[project]** The heading "Terminology used in the **µTest++ Testing
   Framework**" contains bold text, unlike every other page title.
5. **[project]** The ISTQB link ends in `?term=test_case&…`, so it
   opens a single term rather than the glossary.

### 3.5 User's Guide

Structural problems are covered in section 6; this section lists the
content problems.

1. "Concepts and features" starts with "For more complex applications,
   test cases may be organised into test suites", before either term
   is defined. Reorder from the top down: runner, suite, test case,
   check (expectation or assumption), and reporter.
2. "For expectations, the runner maintains a count of occurrences"
   should read "The runner counts the passed and failed checks".
3. "Optionally, the detailed test results can be written to a separate
   file, for example in TAP format": the option that does this,
   `--output-file`, is not documented anywhere on the page, although
   it exists since v4.0 (#17, #25). Document it in "Command line
   options", together with the `--reporter=NAME` form and the error
   given for an unknown reporter.
4. The `<<` message syntax (`t.expect (…) << "answer is 42";`) is used
   in almost every example but never explained. Add a paragraph: the
   message becomes the TAP description; if none is given, the
   expression is used (`ok 1 - true`).
5. "Failed assumptions result in the test being aborted" understates
   the effect: the deferred reporter calls `runner::abort()`, which
   terminates the whole process. Say so, and say what is reported and
   what exit code is returned.
6. The comment in the minimal example, "Create a local instance of the
   runner. Name the top suite.", is on the line that does not name the
   suite. Since v4.1 the name is optional and defaults to the program
   name, which is what the test programs use; say so here.
7. "For the above test, the verbose output would look like" does not
   say how verbose mode is selected (`--verbose`) or what the default
   output looks like.
8. "a custom literal (`_i`) is available, also defined in the separate
   `micro_test_plus` namespace" should read "in the `literals`
   namespace".
9. "this custom operator is defined in a separate namespace (which must
   be explicitly referenced as shown)" should read "which must be
   brought into scope with `using namespace mt::operators;`".
10. "Subtests" is a single sentence with no example, although nesting
    is a v4 feature (#12). Add an example and show how nesting appears
    in the TAP output.
11. "Utility functions" lists `is_match()` and `split()` without saying
    what they do (wildcard matching with `*` and `?`, and string
    splitting). `split()` returns a `std::vector`; note the heap use,
    which matters on embedded targets.
12. "Static test suites" omits the most common pitfall: when the suite
    source files are compiled into a static library, the linker drops
    the unreferenced object files, and the suites silently do not run.
    Recommend the interface or objects library target (see 3.2.3).
13. The static suite example names its variable `suite` (the name of a
    class in the same namespace), and the nested lambda parameter `t`
    shadows the outer `t`, which also triggers `-Wshadow`. Use, for
    example, `ts`, `t`, and `st`.
14. The page says that registered suites run, sorted by name, when
    `exit_code()` is called, but not when the test cases added to the
    top suite in `main()` run relative to them. Readers need this to
    understand the output order and the timing of side effects.
15. "More complex tests" promises suites "invoked, potentially multiple
    times with different arguments", but no example passes arguments
    (the `Args_T&&... arguments` of `suite()` and `test()`). The sample
    test has an "Args suite"; use it.
16. The "real-world example" (double list links) relies on µOS++ types
    and on an `sr` that the snippet does not declare. Either add
    `extern mt::static_runner sr;` and a sentence of context, or
    replace it with a link to `tests/sources/sample/src/`.
17. "Explicit Namespaces" repeats the namespace alias already used in
    every example. Merge it into "Namespaces".
18. "Memory Footprint" gives sizes (105 552 bytes of text against
    410 200 for Boost UT) without the µTest++ and Boost UT versions,
    the toolchain, or the optimisation level. Add them, or the figures
    cannot be reproduced or kept current.
19. "Checking exceptions" does not say what happens when the library
    is built with `-fno-exceptions`, although the test assets include
    `-noexcept` variants.
20. "C API" is two sentences under a top-level heading. Merge it into
    the overview or the FAQ.
21. `math.h` (floating-point support) and the `MICRO_OS_PLUS_…_PRI_SIZE`
    macro are not mentioned. If they are part of the public API,
    document them; if not, nothing is needed.

### 3.6 Integration Guide

In addition to the errors in 3.2.3:

1. **[template]** The order of the sections does not follow the reader's
   task. In rendered order: refresher, Automated installation
   (prerequisites, initialise, install via xpm, details, dependencies,
   folder hierarchy, **uninstall**, **installation via npm**), Manual
   installation, Build & Integration Information, Status, and Testing.
   The integration information, which gives the page its sidebar name,
   comes after uninstalling. Suggested order: Prerequisites, Install
   (xpm, with the details folded), Integrate (CMake, meson, other build
   systems: include folder, sources, compiler options), Configure
   (preprocessor definitions), Alternatives (npm, copy, submodule), and
   Uninstall.
2. **[template]** "Status" and "Testing" repeat the Getting Started
   page. Replace them with a link.
3. **[project]** `_install-folder-hierarchy.mdx`: "After following the
   links" is unclear; say "Following the `xpacks/…` link, the installed
   package contains:".
4. **[project]** `_build-and-integration-info.mdx`: the headings use
   title case ("Include Folders", "Source Files", "Preprocessor
   Definitions") whilst the rest of the page uses sentence case.

### 3.7 Contributor's Guide

1. **[template]** `docs/developer/index.mdx` shows the licence badge
   twice (lines 28 and 32).
2. **[template]** `docs/developer/_common/_content.mdx` passes
   `nodeVersion="18.0.0"`; `package.json` requires `>=20.0`, and the
   Maintainer's Guide passes `20.0`.
3. **[template]** "Satisfy dependencies" uses
   `cd ~/Work/xpack/micro-os-plus/…`; every other command uses
   `~/Work/micro-os-plus/…`.
4. **[template]** "Satisfy dependencies" runs `xpm install -C tests`,
   whilst "Manual tests" runs `xpm run install -C tests`. Neither
   mentions `xpm run link-dependencies`, which is needed before
   building when the dependencies are linked writable projects.
   Explain which command to use, and when.
5. **[template]** Host platforms: "Windows 7 with the Universal C
   Runtime (UCRT), Windows 8, …". The required Node.js 20 does not
   support Windows 7 or 8. Check and update the list.
6. **[template]** Target platforms: `platforms/native` is now
   `platforms/synthetic-posix`, and the list omits `qemu-cortex-m33`,
   the `nucleo-*` boards, and the `raspberry-pi-*` boards. List them,
   separating the QEMU targets (run in CI) from the physical boards
   (built in CI, run manually).
7. **[template]** Toolchains: `risc-none-elf-gcc` should be
   `riscv-none-elf-gcc`.
8. **[template]** Semihosting links only the Arm specification; the
   RISC-V targets use the RISC-V semihosting specification.
9. **[project]** `docs/developer/_project/_test-details.mdx` (865
   lines, almost all raw `ctest -V` logs):
   - The logs contain personal absolute paths
     (`/Users/ilg/MyProjects/…`, `/home/ilg/Work/…`), the old
     configuration name `native-cmake-sys-release`, and the old
     `platforms/native` folder.
   - The output format is the old one (see 3.2.6).
   - The links to `tests/src/minimal/src/main.cpp` and similar are
     broken on GitHub; the folder is now `tests/sources/`.
   - Only three of the five test programs are described; `empty` and
     `suite` are missing.
   - The unit test output ends with "357 checks passed, 326 failed"
     followed by "Overall, the µTest++ unit tests were successful!",
     with no explanation of how deliberately failing checks are
     verified. This is the most confusing passage on the site.
   - The sample test section says "All possible verbosity modes are
     exercised", but shows only one.

   Suggestion: for each of the five programs, give one paragraph on
   what it tests, the command that runs it, and a link to its reference
   output in `tests/assets/`. Keep at most one short log, folded in a
   `<details>` block.
10. **[template]** "Code formatting" says that VS Code uses the
    `.clang-format` file directly, and mentions the Eclipse CppStyle
    plug-in. The configuration is now in `maintenance/config/`, with
    no `.clang-format` at the root, so VS Code will not find it.
    Document `xpm run clang-format` (and the `cmake-format`,
    `jsonc-format`, and `prettier` actions) instead.
11. **[template]** `_prepare-website.mdx` runs
    `npm run website-generate-commons`; the script is
    `generate-website-commons`. The command fails as written.
12. **[template]** The website subsections (regenerate Doxygen,
    prepare, build, and start the server) are repeated almost
    unchanged in the Maintainer's Guide. A contributor needs only "how
    to preview my documentation change"; keep the full procedure in
    the Maintainer's Guide.

### 3.8 Maintainer's Guide

1. **[template]** "Release schedule" says "There are no fixed releases";
   Getting Started says "continuous release strategy". Use one wording.
2. **[template]** "Update the `websiteConfig`" refers to
   `website/package.json`; the configuration now lives in
   `website/config/website-templates.json` (which `customFields.ts`
   reads first).
3. **[template]** "Reformat source files" says only "Reformat the
   source files that were changed"; give the `xpm run clang-format`
   command.
4. **[template]** "Rebase the `xpack-development` branch onto the
   `xpack` branch" (also in `_branches-details.mdx`,
   `_publish-website.mdx`, and `_update-main-branch.mdx`). In Git
   terminology this means replaying `xpack-development` on top of
   `xpack`, which is the opposite of the intended operation (bringing
   `xpack` up to `xpack-development`). Give the exact commands, for
   example `git checkout xpack && git merge --ff-only
   xpack-development`, or whatever is actually used.
5. **[template]** `_publish-website.mdx`: the list mixes capitalised
   and lower-case steps ("run the `npm install` command", "check
   [GitHub Pages]"), and one step continues on an unindented line.
6. **[template]** `_start-local-web-server.mdx` refers to the
   "Maintainer Info" page; the page is the Maintainer's Guide.
7. **[template]** `_tag-npm-latest.mdx` suggests `npm unpublish`.
   npm restricts unpublishing after 72 hours; mention `npm deprecate`
   as the normal alternative.
8. **[template]** "Share on X/Twitter" and "Analytics" are level-2
   headings among level-3 steps in "Final updates".
9. **[template]** `_analytics.mdx` labels a `dt` badge "all releases";
   the blog version (`blog/_common/_download-analytics.mdx`) labels a
   `d18m` badge (last 18 months) "total downloads". Use the same badge
   and an accurate label in both.

### 3.9 Help Centre

1. **[template]** "Check documentation" contains no links (the
   `_documentation.mdx` partial is empty). List the guides here.

   Status: open. The partial is kept empty (see 2.4.4), so the section
   still asks the reader to review the documentation without pointing
   to it. Since the sidebar already lists the guides, an alternative
   is to change the template sentence to refer to the sidebar.
2. **[template]** "Please, please, please!" is the title of a caution
   box; it is informal. Suggestion: "Private email".
3. **[template]** "Discord … channels `#rtos` and `#general`": check
   that these exist, and whether there is a channel for testing
   questions.
4. **[template]** "Web page issues" asks for the full page URL and the
   section; every page has an "Edit this page" link, which is the
   quickest way to propose a correction. Mention it.

### 3.10 About and Releases

1. **[project] (fixed)** About is five short paragraphs, two of which only
   link elsewhere. The "The web site" section (spelt as two words,
   unlike everywhere else) says that the Docusaurus template was
   instantiated in February 2025. This is acceptable, but the page
   would gain from one paragraph on the project's purpose and
   relationship with µOS++.

   Status: fixed, in project files. The paragraph was added to
   `_project/_more-intro.mdx` (see 2.4.3), and the heading in
   `_project/_website.mdx` now reads "The website".
2. Releases: correct. Note that the list has no entries for v3.2.1 and
   v4.1.0, which are tagged and published but have no blog post. The
   v4.1.1 post describes the v4.1 changes; say so in the post.

### 3.11 Blog

1. **[template]** All 25 release posts, and the template
   `blog/_templates/blog-post-release-liquid.mdx`, show
   `xpm install …@X.Y.Z -verbose` with a single dash; everywhere else it
   is `--verbose`.
2. **[template]** The posts link to the "Install Guide" (a third name
   for the Integration Guide).
3. **[template]** The template passes `nodeVersion="18.0.0"` to
   `blog/_common/_prerequisites.mdx`, which ignores the property. Remove
   it, or use it.
4. **[template]** `blog/_common/_prerequisites.mdx`: a "Prerequisites"
   section whose second paragraph describes manual installation, which
   is not a prerequisite. Move it under "Installation".
5. **[project]** `blog/2026-05-12-micro-test-plus-v4-1-1-released.mdx`
   mentions "the `details` namespace"; it is `detail`.
6. **[project]** The `description` of most posts ("Version X is a new
   release") carries no information. Since it is used as the link
   preview, write one line on the main change, as in v3.3.0 and v5.0.1.
7. **[project]** `blog/2025-03-03-website.mdx`: "The _new kid on the
   block_", "a static site (kind of)", and "lots of JavaScript code"
   are informal.

## 4. Consistency

### 4.1 Names of things

| # | Concept | Variants found | Suggested |
| --- | --- | --- | --- |
| 1 | `docs/install` guide | Integration Guide (sidebar, navigation bar), Installation Guide (page title, Getting Started link), Install Guide (blog), "How to install …" (H1) | Integration Guide, with H1 "How to integrate …" |
| 2 | `docs/developer` guide | Contributor's Guide (title), "developers" (body), `/developer/` (URL) | Contributor's Guide; keep the URL |
| 3 | `docs/maintainer` guide | Maintainer's Guide, "Maintainer Info" page | Maintainer's Guide |
| 4 | Licence | Licence (heading), License (sidebar), `licence`/`license` (badge alt text) | Licence in text; "MIT License" as the proper name |
| 5 | Node TAP | Node TAP, node-tap | node-tap (its own spelling) |
| 6 | Meson | Meson, meson, "Meson Build" | Meson (in text), `meson` (the command) |
| 7 | Test case | test case, subtest, test, check (see 3.4.2) | test case, implemented by `subtest` |
| 8 | Website | website, web site | website |
| 9 | Node.js version | 18.0.0 (Contributor's Guide, blog), 20.0 (Maintainer's Guide, `package.json`) | the `package.json` value, through `customFields` |
| 10 | Work folder | `~/Work/micro-os-plus/…`, `~/Work/xpack/micro-os-plus/…` | `~/Work/micro-os-plus/…` |

### 4.2 Headings

The capitalisation of headings varies within the same page:
"Features & Benefits", "Build & Integration Information", "Include
Folders", "Custom Types", "Explicit Namespaces", and "Memory Footprint"
use title case, whilst "Test cases", "Install folder hierarchy",
"Automated installation", and most others use sentence case. Use
sentence case throughout, and write "and" instead of "&".

### 4.3 British spelling in API names

The pages use British spelling, and so does the API (`initialise`).
The double-list example in the User's Guide calls the µOS++ methods
`initialize()` and `uninitialized()`. These are the real µOS++ names,
so they are correct, but a reader may think that the framework accepts
both spellings. A short note, or a different example, avoids the
doubt.

## 5. Language and style

1. The register is formal, as required, but often inflated. Examples:
   forms of "utilise" occur 38 times outside the API pages, where
   "use" is the standard British word; "comprehensive" occurs 33 times,
   mostly in phrases such as "comprehensive list" or "comprehensive
   instructions", where it adds nothing; and "it is advisable to",
   "readily", and "seamlessly" add length without content. Replace
   "utilise" with "use" in all cases, and remove "comprehensive" unless
   it distinguishes the item from a partial one.
2. Several sentences describe what the reader will read instead of
   saying it, for example "This information provides a comprehensive
   overview of significant modifications and is readily available in
   the respective release notes". Remove such sentences.
3. Many lists of steps mix sentence fragments, full sentences, and
   capitalised and lower-case starts (Maintainer's Guide). Choose
   imperative fragments without full stops, consistently.
4. Admonitions are used for ordinary statements (for example "The µOS++
   projects favour the use of explicit comparator functions" as an
   info box). Reserve them for warnings and genuinely secondary notes.
5. The source lines of `docs/user/_project/_content.mdx` are up to
   several hundred characters long, whilst the other files wrap at 80.
   This does not affect the rendered page, but it makes reviews and
   diffs harder; rewrap when the page is split.

## 6. Proposed structure for the User's Guide

The User's Guide is the most important page and currently combines a
tutorial, concept explanations, an API summary, command line reference,
and embedded considerations on one 930-line page. Using the existing
custom sidebar mechanism, split it into pages that each answer one
question. Set `hasCustomUserSidebar: true` in
`website/config/website-templates.json`, and replace the "TODO" item
in `website/sidebar-docs-user-custom.js` with the new pages (see
2.2.3). The proposed pages are:

1. **Overview**: rationale (shortened), concepts (runner, suite, test
   case, check, and reporter, in this order, with one diagram of the
   hierarchy), and a link to History for the background.
2. **Tutorial**: the minimal test, a computed value, a failing check,
   comparators and operators, and nested test cases. Each step shows
   the code and its actual output, with matching line numbers.
3. **Writing checks**: expectations and assumptions (including the
   `<<` message and the effect of a failed assumption), function
   comparators, logical functions, operators, literals and wrappers,
   strings and containers, exceptions, and "functions or operators?".
4. **Organising tests**: the top suite, suites, static suites (with
   the static library pitfall), passing arguments, the execution order,
   and the double-list example.
5. **Running tests**: command line options (`--verbose`, `--quiet`,
   `--silent`, `--reporter`, and `--output-file`), the TAP and human
   reporters, the exit code, and the use with CTest, meson, and TAP
   consumers.
6. **Embedded targets**: console output routing, semihosting, timings,
   memory footprint, and builds without exceptions.
7. **API summary**: the namespaces and a table linking each topic to
   its `/docs/api/` group page, in place of the signatures copied into
   the guide, which go out of date (see 3.2.5).

Splitting also gives each page its own entry in the search index and a
usable table of contents.

## 7. Incidental observations outside the website

These were found whilst checking the website text against the code;
they are not website problems, but they affect what the website should
say.

1. `LICENSE-Boost` is not included in the npm package
   (`micro-os-plus-micro-test-plus-5.0.1.tgz` contains only `LICENSE`),
   although Getting Started says that the Boost-derived portions are
   distributed under the Boost Software License, which requires the
   licence text to accompany the source.
2. `tests/assets/txt/minimal-test-silent.txt` contains the "µTest++
   human report" banner and a "• Check various conditions" line,
   although the User's Guide says that `--silent` suppresses all
   output. Either the reporter or the documentation is wrong; check
   which.
