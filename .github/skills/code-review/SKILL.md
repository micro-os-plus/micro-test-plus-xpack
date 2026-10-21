---
name: code-review
description: 'Perform a thorough, uncompromising code review of C++ sources, headers, and documentation in the µTest++ Testing Framework project. Use when the user asks for a "code review", to "review the code", to "review changes", or to check a file, folder, or pull request for style, naming, documentation, and correctness issues.'
argument-hint: 'Optional: path or folder to review; defaults to the whole repository'
---

# Code Review — µTest++ Testing Framework

## When to Use

- The user asks for a code review of a file, folder, diff, or the whole
  repository.
- The user asks to check adherence to the project's coding standards before
  a commit or release.

Related skills, with different scopes:

- `api-review`: the design and the implementation of the whole C++
  API, judged from the code alone (with probe programs), with a
  new numbered report in `maintenance/docs/API-REVIEW-<n>.md`;
- `doxygen-review`: verifies and fixes the Doxygen comments.

## Review Scope

If the user specifies a path, review only that path. Otherwise review
`include/`, `src/`, and `tests/` (excluding `tests/build/`).

## Checklist

Review every item below. Do not soften findings; state flaws directly and
specifically, with file and line references.

### Naming and style

- C/C++ identifiers use `snake_case` (types, functions, variables, members).
- File names are lower-case words separated by dashes (e.g.
  `runner-inlines.h`).
- Formatting matches `maintenance/config/.clang-format`; check it
  without modifying the files:

  ```sh
  xpacks/.bin/clang-format --dry-run --Werror \
    --style=file:maintenance/config/.clang-format <files>
  ```

- No lines exceed 80 characters, including comments, except possibly the
  file path in a `DO NOT EDIT` generated-file comment, link URLs.

### Folder structure

- Declarations live in `include/`, out-of-line definitions in `src/`,
  inline (header-only) definitions in `inlines/`.
- There is only one public header,
  `include/micro-os-plus/micro-test-plus.h`; the other headers are
  located in the subfolder named after it,
  `include/micro-os-plus/micro-test-plus/`, and the inline bodies of
  `<name>.h` are in `inlines/<name>-inlines.h`.
- New source files are registered in `xcdl-package.jsonc`, and the
  top-level `CMakeLists.txt` and `meson.build` are regenerated from it
  with `xpm run xcdl-export`; the generated files are not edited by hand.

### Documentation (Doxygen)

- Every class, method, property, parameter, and return value has a
  Doxygen comment, including `private` and `protected` members.
- Each declaration/definition has both `@brief` and `@details`.
- `@details` expands on `@brief` rather than repeating it; it is located
  immediately after `@brief` in the comment block, or, if the declaration
  and definition are in separate files, in the comment immediately before
  the definition.
- `@details` should provide a more in-depth explanation, including any relevant
  information about the implementation, usage, or edge cases.
- Documentation uses British English spelling (e.g. "behaviour",
  "colour", "initialise") and formal, contraction-free wording.
- If the code already includes documentation, review and possibly improve it.
- If Doxygen can be run, check its warning log (undocumented parameters,
  `@ref`/`@tparam` targets that do not resolve, mismatched signatures)
  rather than relying solely on a manual read.

### Licensing and metadata

- Every source and header file carries the identical MIT licence header
  block, with a plausible copyright year range for the project.
- If a change is significant enough to affect behaviour, check whether
  `CHANGELOG.md` and the package version should be updated.

### Conditional compilation

- Header guards are the only construct permitted to use `#ifndef`.
- All other conditional compilation uses `#if defined(...)` or
  `#if !defined(...)`, never bare `#ifdef` / `#ifndef`.
- Every `#endif` is followed by a C++ comment (`// ...`) repeating the
  exact expression from its paired `#if`/`#if defined`/`#if !defined`,
  so nested and distant guards remain traceable.
- The above applies to pragmas where `#if defined(__GNUC__)`,
  `#if defined(__clang__)` or similar are used.

### Modern C++

- The codebase targets C++20; flag code written in an older style where
  a modern equivalent is clearly preferable.
- Prefer `concepts` and `requires` clauses over SFINAE and
  `std::enable_if`.
- Prefer `constexpr`/`consteval` over macros and runtime checks where the
  value is known at compile time.
- Prefer range-based `for`, structured bindings, `auto`, and `<=>`
  (three-way comparison) where they simplify the code without harming
  readability.
- Prefer `[[nodiscard]]`, `[[maybe_unused]]`, and other standard
  attributes over compiler-specific equivalents.
- Flag unnecessary use of raw pointers, casts, or macros where a
  standard C++20 facility would be clearer and safer, while respecting
  the embedded constraints of the project: the library may use the
  heap and the standard containers, but program size matters more than
  speed, and the library must build without exceptions and without
  RTTI (code that needs them is guarded by `__cpp_exceptions` or
  `__cpp_rtti`, not by compiler-specific macros).
- `noexcept` is specified explicitly wherever it is warranted (e.g.
  move constructors/assignment, destructors, and functions that
  provably cannot throw); flag missing or incorrect `noexcept`.

### Correctness and maintainability

- Look for undefined behaviour, dangling pointers and references
  (names kept as `const char*` or `std::string_view`), and missing
  `const`-correctness.
- Flag weak assumptions, missing edge-case handling, and any deviation
  from existing patterns in the codebase without justification.
- Check that a changed public entity keeps the symmetry between the
  parallel forms of the API (`suite` and `static_suite`, `expect()`
  and `require()`, the function comparators and the operators, the
  `to_i` wrappers and the `_i` literals); a feature added to one form
  should be added to the others, unless the omission is deliberate
  and justified.
- Check that the changed code works with both reporters (human and
  TAP) and at every verbosity level.

### Toolchain verification

- Where feasible, prefer verifying claims by actually building rather than
  reading only: build with `-Wall -Wextra -Wpedantic` (or run the
  `xpm run test*` variants) and report any warnings, rather than only
  flagging style issues that look suspicious. The probe build
  described in the `api-review` skill ("Confirming Findings with
  Probes") needs no other dependency.
- For pointer-arithmetic or type-punning idioms (e.g. `reinterpret_cast`
  member-offset tricks, null-pointer-based `offsetof` substitutes), check
  whether a sanitizer build (`-fsanitize=undefined`/`-fsanitize=address`)
  is available and flag any UB it reports.

### Tests

- Changes to behaviour are covered by tests in `tests/`.
- Note which tests should be re-run, as required by the Testing
  section of `.github/copilot-instructions.md` (`test-selected` after
  major changes, `test` after minor ones).

## Procedure

1. Identify the review scope (explicit path, or the default scope above).
2. Read the relevant files fully; do not review based on partial context.
3. Go through the checklist section by section, collecting concrete
   findings (file, line, description, why it matters).
4. Explicitly note anything left out of the review because you were not
   certain enough to include it.
5. Write the results to `CODE-REVIEW.md` at the root of the project,
   with:
   - a summary of findings, and
   - specific, actionable recommendations, grouped by checklist section.
6. Number the findings (`#1`, `#2`, and so on, through the whole
   report), so that the user can refer to them when asking to fix
   them.
7. Do not fix the issues automatically unless the user asks for that
   separately.
