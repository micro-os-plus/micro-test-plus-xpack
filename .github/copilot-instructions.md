# Copilot Instructions

## Project Overview

This is the **µTest++ Testing Framework** project, part of
µOS++.

## General

- Avoid sycophantic behaviour; for all conversation, never soften criticism
  to protect the person's ego.
- If something has a flaw, say so directly.
- When the meaning of a question is uncertain, say so and ask questions
  rather than guess.
- When multiple valid answers are possible, say so and ask questions to
  identify the most appropriate one, rather than assuming a single
  correct answer.
- This applies to every response.

## Language and Tone

- Use British English spelling and grammar (e.g., "behaviour", "colour",
  "organise", "analyse", "favour", "initialise", etc.)
- Maintain a professional and formal tone in all generated content
- Avoid colloquialisms, slang, or informal expressions
- Avoid humour, jokes, or casual remarks
- Use clear, precise, and professional language appropriate for technical
  documentation
- Avoid contractions (e.g., use "do not" instead of "don't")
- Use the Oxford comma in lists for clarity
- Maintain consistency in terminology throughout the codebase
- Prefer "folder" to "directory"

## Code Style

- Follow the existing C++ code style defined in the .clang-format file.
- Use consistent formatting and naming conventions based on prettier and
  clang-format configurations.
- For C/C++, the naming convention is snake_case.
- For C++, write multiple level namespaces on the same line.

## Folder Structure

- `/src`: Contains the C++ source code
- `/include`: Contains the C++ header files
- `/tests`: Contains the test suites and test cases
- `/website`: Contains the project documentation and guides
- `/maintenance`: Contains the project maintenance resources, which are
  not published with the package: `/maintenance/config` (the formatter
  configuration files), `/maintenance/scripts` (the maintenance scripts
  and their templates), and `/maintenance/docs` (the developer notes)

When adding new source files, place them in the appropriate `src` or `include`
folder, and add corresponding entries in the top CMake and Meson configurations.

Avoid running `find /` commands that search the entire filesystem, as this
always times out.

## Includes order

- Project-specific headers.
- µOS++ headers
- Third-party library headers.
- Standard library headers.
- Use alphabetical order within each group.
- Separate each group with a blank line.
- Brace the whole group of includes by separator lines

## Compiler pragmas

When needed to silence warnings, use separate groups of pragmas for each compiler.

Always use `__GNUC__` guards, and, if necessary, `__clang__` guards to apply
compiler-specific pragmas.

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

Brace the whole group of pragmas by separator lines.

## Doxygen Documentation

- With every change of the code, in the same edit, write or update the
  Doxygen documentation comments of all the affected entities (classes,
  members, parameters, return values, and the files in `inlines/` and
  `src/`), so that the comments always match the code; never leave the
  documentation for a later step.
- Apply the rules and the checks described in
  `.github/skills/doxygen-review/SKILL.md` to every edit that touches the
  code or the comments, not only when asked for a documentation review.
- Review and improve the existing comments of the entities that are edited.

## Tools binaries

The binary tools required for the project are located in the `xpacks/.bin`
folder within the build folders and the project root, and the JavaScript 
tools are in `node_modules/.bin`

## Testing

After making major changes, run in a terminal:

- `xpm run test-selected -C tests` -- to execute a minimal selection of tests

After minor changes, take a shortcut and run only:

- `xpm run test -C tests` -- to execute the test with the system compiler.

When using linked writable projects, it is necessary to run the linking step to ensure all dependencies are correctly resolved.

- `xpm run link-dependencies --config <name>`

When using non-native platforms, run one by one specific actions for the given configuration.

- `xpm run setup --config <name>`
- `xpm run build --config <name>`

For non-qemu platforms, running the tests can be done only after confirming that the board is
powered up, with the command:

- `xpm run test --config <name>`

QEMU tests can be done directly, without confirmation that the board is
powered up.

## Code Review

- When asked for an API review, follow the separate instructions in
  `.github/skills/api-review/SKILL.md` for a thorough and uncompromising
  review of the codebase API.
- When asked for a code review, follow the separate instructions in
  `.github/skills/code-review/SKILL.md` for a thorough and uncompromising
  review of the codebase implementation.

## Git Commits

- When asked to commit (to Git), or to write a commit message, follow the
  separate instructions in `.github/skills/github-commit/SKILL.md`, which
  cover the commit message format, the issue references, and the issue comment.
- Do not commit without user review and approval.

## Issue Updates

- After committing a fix for a GitHub issue, add the closing comment to that
  issue, as described in `.github/skills/github-commit/SKILL.md` ("Issue
  Comment"); that skill also covers the issues without a number.

## xcdl

- When working with `xcdl-package.jsonc`, and `xcdl-test.jsonc`,
  or when adding, removing, or
  renaming a source file, an include folder, compiler/linker options,
  or a dependency, follow
  the separate instructions in `.github/skills/xcdl/SKILL.md`.
