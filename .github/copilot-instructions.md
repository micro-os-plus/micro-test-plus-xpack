# Copilot Instructions

## Project Overview

This is the **µTest++ Testing Framework** project, part of µOS++.

## General

These rules apply to every response.

- Avoid sycophantic behaviour; never soften criticism to protect the
  person's ego.
- If something has a flaw, say so directly.
- When the meaning of a question is uncertain, or when you do not know the
  answer, say so and ask questions rather than guess.
- When multiple valid answers are possible, say so and ask questions to
  identify the most appropriate one, rather than assuming that a single
  answer is correct.

## Language and Tone

- Use British English spelling and grammar (for example, "behaviour",
  "colour", "organise", "analyse", "favour", and "initialise").
- Maintain a professional and formal tone in all generated content.
- Avoid colloquialisms, slang, and informal expressions.
- Avoid humour, jokes, and casual remarks.
- Use clear and precise language, appropriate for technical documentation.
- Avoid contractions (for example, use "do not" instead of "don't").
- Use the Oxford comma in lists.
- Use the same terminology consistently throughout the project.
- Prefer "folder" to "directory".

## Code Style

- Format the C/C++ code as defined by `maintenance/config/.clang-format`,
  the CMake files as defined by `maintenance/config/.cmake-format.py`, and
  the JavaScript scripts as defined by `maintenance/config/.prettierrc.json`.
- For C/C++, use the snake_case naming convention.
- For C++, write nested namespaces on a single line (for example,
  `namespace micro_os_plus::micro_test_plus`).

## Folder Structure

- `src/`: the C++ source files.
- `include/`: the C++ header files.
- `tests/`: the test suites and test cases.
- `website/`: the project documentation and guides.
- `maintenance/`: the project maintenance resources, which are not
  published with the package: `maintenance/config/` (the formatter
  configuration files), `maintenance/scripts/` (the maintenance scripts
  and their templates), and `maintenance/docs/` (the developer notes).

When adding new source files, place them in the appropriate `src/` or
`include/` folder, and add them to `xcdl-package.jsonc`, from which the
top-level CMake and meson configurations are generated with
`xpm run xcdl-export` (see the xcdl section below); do not edit the
generated files.

## Includes Order

Group the `#include` directives in the following order:

1. Project-specific headers.
2. µOS++ headers.
3. Third-party library headers.
4. Standard library headers.

Use alphabetical order within each group, separate the groups with a
blank line, and enclose the whole block of includes between two separator
lines (`// ---...---`, up to column 79).

## Compiler Pragmas

When warnings must be silenced, use a separate group of pragmas for each
compiler. Guard all of them with `__GNUC__`, and the clang-specific ones
also with `__clang__`, nested inside, since clang also defines
`__GNUC__`:

```c++
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#pragma GCC diagnostic ignored "-Wredundant-tags"
#endif // defined(__GNUC__)
```

Enclose the whole block of pragmas between two separator lines.

## Doxygen Documentation

- With every change of the code, in the same edit, write or update the
  Doxygen documentation comments of all the affected entities (classes,
  members, parameters, return values, and the files in `inlines/` and
  `src/`), so that the comments always match the code; never leave the
  documentation for a later step.
- Apply the rules and the checks described in
  `.github/skills/doxygen-review/SKILL.md` to every edit that touches the
  code or the comments, not only when asked for a documentation review.
- Review and improve the existing comments of the entities that are
  edited.

## Tool Binaries

The compiler and the other binary tools are installed in the
`build/<configuration>/xpacks/.bin` folder of each build configuration,
or in the `<project>/xpacks/.bin` folder of the project root; the
JavaScript tools are in the `node_modules/.bin` folders.

Never run `find /` or other commands that search the entire file system,
since they always time out; limit the search to the relevant folders.

## Testing

After major changes, run a minimal selection of tests:

- `xpm run test-selected -C tests`

After minor changes, run only the tests built with the system compiler:

- `xpm run test -C tests`

When the dependencies are linked to writable projects, run the linking
step first, so that they are resolved correctly:

- `xpm run link-dependencies --config <name> -C tests`

For the non-native platforms, run the actions of the given configuration
one by one:

- `xpm run setup --config <name> -C tests`
- `xpm run build --config <name> -C tests`
- `xpm run test --config <name> -C tests`

The QEMU tests can be run directly; on physical boards, run the `test`
action only after the user confirms that the board is powered up.

## Reviews

When asked for one of the following reviews, follow the separate
instructions of the corresponding skill:

- a design review, or an API review: `.github/skills/design-review/SKILL.md`;
- a code review: `.github/skills/code-review/SKILL.md`;
- a website review: `.github/skills/website-review/SKILL.md`;
- a review of the API reference pages:
  `.github/skills/website-api-review/SKILL.md`;
- a consistency check: `.github/skills/consistency-check/SKILL.md`.

The review skills share the rules in `.github/skills/review-common.md`,
and all the skills read the facts of this project in
`.github/skills/project.md`. Most skills are generated from the
`npm-packages-helper` templates (`npm run generate-top-commons`), so
the project-specific rules go in `.github/skills/project.md`, or in a
`project.md` file in the folder of the skill, never in a generated
`SKILL.md` (see `.github/skills/README.md`).

## Git Commits

- When asked to commit, or to write a commit message, follow the separate
  instructions in `.github/skills/github-commit/SKILL.md`, which cover the
  commit message format, the issue references, and the issue comment.
- Do not commit without user review and approval.

## Issues

- When asked to open an issue, follow the separate instructions in
  `.github/skills/create-github-issue/SKILL.md`.
- After committing a fix for a GitHub issue, add the closing comment to
  that issue, as described in `.github/skills/github-commit/SKILL.md`
  ("Issue Comment"); that skill also covers the issues without a number.

## xcdl

When working with `xcdl-package.jsonc` or `xcdl-test.jsonc`, or when
adding, removing, or renaming a source file, an include folder, a
compiler or linker option, or a dependency, follow the separate
instructions in `.github/skills/xcdl/SKILL.md`.

## Platforms

- When asked to add or fix a board LED driver, follow the separate
  instructions in `.github/skills/led/SKILL.md`.
- When asked to add a standalone variant of a Nucleo board, follow
  `.github/skills/nucleo-standalone-platform/SKILL.md`.

## Footprint Benchmarks

When asked to measure the footprint of µTest++ or of the compared
frameworks, to upgrade the compared frameworks, or to update the
footprint figures of the website, follow the separate instructions in
`.github/skills/footprint-benchmarks/SKILL.md`.

## JavaScript Scripts

When asked to create a new `.mjs` (Node.js) script, follow the separate
instructions in `.github/skills/create-javascript-mjs/SKILL.md`; for the
conversion of an existing bash script, follow
`.github/skills/rewrite-bash-to-javascript/SKILL.md`.

## Verbal Questions

When more input from the user is required, first ask a short version
of the question aloud, with the macOS `say` program, and only then show
the full question in the chat window (in the text of the reply, or in a
question dialog), so that the spoken question draws the attention of
the user before the text appears.
