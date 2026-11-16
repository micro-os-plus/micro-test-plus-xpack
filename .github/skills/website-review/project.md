# website-review — µTest++ Testing Framework

The rules of the `website-review` skill that are specific to this
project. This file is owned by the project, and it is never
regenerated; it extends the generated `SKILL.md` in this folder, and
takes precedence over it where they differ.

## Sources of Truth

In addition to the general ones of check 1:

- API names, signatures, constraints, and return types: the headers
  in `include/micro-os-plus/micro-test-plus/` and their `inlines/`;
- behaviour (what a failed assumption does, execution order, which
  command line options exist and their forms): `src/*.cpp`, in
  particular `runner.cpp` and `reporter.cpp`;
- sample outputs: the reference files in `tests/expected/tap/` and
  `tests/expected/txt/`, and the programs in `tests/sources/*/src/`;
- statements contradicted by the project rules, for example claims
  about xCDL generating files (see the `xcdl` skill).

Repository paths that were renamed, and may remain in external links:
`tests/src/` → `tests/sources/`.

## Version History

The history of the project is told in the compatibility notices
(`docs/getting-started/_project/`), the History page, the User's Guide
overview, the release blog posts, and `CHANGELOG.md`.

## Terms

The project terms to check for consistency: test case / subtest /
check, suite, runner, reporter; the tool names include node-tap.
Example paths such as `~/Work/micro-os-plus/…` must agree across pages.

## Earlier Reports

`WEBSITE-REVIEW-1.md` predates the numbering of the items; cite its
items by the section number, when carrying its open problems over.
