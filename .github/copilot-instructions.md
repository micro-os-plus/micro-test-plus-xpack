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

Always use __GNUC__ guards, and, if necessary, __clang__ guards to apply 
compiler-specific pragmas.

```c
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wredundant-tags"
#endif // defined(__clang__)
#endif // defined(__GNUC__)
```

Brace the whole group of includes by separator lines.

## Documentation

- Add comprehensive documentation comments accepted by Doxygen
- Document all classes, methods, properties, parameters, and return types.
- The declarations should be in the headers, the definitions in the `src`
  folder, and the inline definitions in the `inlines` folder.
- Add @details sections to all declarations and definitions.
- The @brief and @details sections are displayed sequentially, so ensure the
  @details section expands on the @brief without repeating it. The @brief
  should be a concise summary of the member's purpose, whilst the @details
  should provide a more in-depth explanation, including any relevant
  information about the implementation, usage, or edge cases.
- Document private and protected members as well
- Keep the line length below 80 characters
- If the code already includes documentation, review and possibly improve it.

## Folder Structure

- `/src`: Contains the C++ source code
- `/include`: Contains the C++ header files
- `/tests`: Contains the test suites and test cases
- `/website`: Contains the project documentation and guides

When adding new source files, place them in the appropriate `src` or `include`
folder, and add corresponding entries in the top CMake and Meson configurations.

Avoid running `find /` commands that search the entire filesystem, as this 
always timeouts.

## Tools binaries

The tools binaries required for the project are located in the `xpacks/.bin`
folder within the build folders and the project root.

## Testing

After making changes, run in a terminal:

- `xpm run test -C tests` to execute the test with the system compiler
- `xpm run test-native-clang -C tests` to execute the test with clang
- `xpm run test-qemu-cortex-m7f-gcc -C tests` to execute the test with cross gcc

When editing non-native platforms, run one by one specific actions for the given configuration.

- xpm run setup --config <name>
- xpm run build --config <name>

For non-qemu plaforms, running the tests can be done only after confirming that the board is 
powered up, with the command:

- xpm run test --config <name>

QEMU tests can be done directly, without confirmation that the board is
powered up.

## Code Review

- When asked for a code review, follow the separate instructions in `.github/skills/code-review/SKILL.md` for a thorough and uncompromising review of the codebase.

## Version Control

When making changes to the codebase, follow these guidelines for version control:

- Use descriptive commit messages that clearly explain the purpose of the changes
