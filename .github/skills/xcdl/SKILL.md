---
name: xcdl
description: 'How xcdl-package.jsonc is used in the µTest++ Testing Framework project: which of its properties affect the generated top-level CMakeLists.txt and meson.build, and why a commented-out defaultDefine does not mean that a macro is disabled. Use when the user asks about xcdl or xcdl-package.jsonc, or when adding, removing, or renaming a source file, a public include folder, or a dependency, or when a macro documented in xcdl-package.jsonc is discussed.'
argument-hint: 'Optional: the change to make to xcdl-package.jsonc, or the property or macro in question'
---

# xcdl — µTest++ Testing Framework

## When to Use

- A source file, a public include folder, a compiler/linker option 
  or a dependency is added, removed, or renamed, and
  `xcdl-package.jsonc` and `xcdl-test.jsonc` must be updated.
- The user asks what a property of `xcdl-*.jsonc` does, or why the
  top-level `CMakeLists.txt` or `meson.build` contain a given entry.
- A macro listed in `xcdl-*.jsonc` (a `defaultDefine`) is discussed,
  for example to decide whether it is enabled.

## Current Status

The `xcdl` tool is not yet available; `xcdl-*.jsonc` is used only
to generate the top-level and tests CMake and Meson files, with:

```sh
xpm run xcdl-export
```

## Manual edits

The generated top-level `CMakeLists.txt` and `meson.build`, and those
in the tests `sources` folders should not be edited by hand;
change `xcdl-*.jsonc` and run the action again.

## Properties

Only `publicIncludeFolders`, `sourceFiles`, `publicDefines`,
`compilerOptions`, and `dependencies` affect the
generated files. All the other properties (`generatedFile`, `activeIf`,
`defaultValue`, `implements`, and the commented-out `defaultDefine`
entries) are informative only.

## Macros

No `*-defines.h` file is generated, so a commented-out `defaultDefine`
does not mean that the macro is disabled. Its name documents the macro
that the application must define itself, either in
`micro-os-plus/project-config.h` or in project specific header files
(e.g., `micro-os-plus/startup-defines.h`).
