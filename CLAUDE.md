# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

@.github/copilot-instructions.md

## Project Overview

µTest++ is a lightweight, header-mostly C++20 testing framework for embedded
and general C++ projects, part of the µOS++ project family
(<https://micro-os-plus.github.io/>). Its API is significantly inspired by
Boost UT (BDD-style `"..."_test`, `expect`, `that`, operators), adapted for
constrained embedded targets (bare-metal Cortex-M/A, RISC-V) as well as
native Linux/macOS/Windows builds. Requires C++20.

This is a source **library** xpm package, not an application: the top-level
folder builds the library and exposes it via CMake/meson/xPack (xcdl)
integration; a separate `tests/` sub-project builds and runs sample
programs against it on many toolchains and platforms.

## Repository Layout

- `include/micro-os-plus/micro-test-plus.h` — single public entry header;
  users include only this file.
- `include/micro-os-plus/micro-test-plus/*.h` — public headers, one per
  concern (`runner.h`, `test.h`, `reporter.h`, `reporter-human.h`,
  `reporter-tap.h`, `check-result.h`, `operators.h`,
  `function-comparators.h`, `expression-formatter.h`, `reflection.h`,
  `extension.h`, `stopwatch.h`, `counters.h`, `literals.h`,
  `math.h`, `utility.h`, `exceptions.h`, `detail.h`, and
  `deprecated.h`, which groups the deprecated definitions that are not
  class members).
- `include/micro-os-plus/micro-test-plus/inlines/*.h` — inline/template
  definitions for the above headers (kept separate from the declarations).
- `src/*.cpp` — non-inline definitions, one file per header of the same
  name (e.g. `runner.h` ↔ `src/runner.cpp`).
- `tests/` — a **separate npm/xpm sub-project** (own `package.json`) that
  builds and runs sample test programs against the library across many
  toolchains and platforms; see "Testing" below.
- `website/` — Docusaurus-based project documentation/guides.
- `maintenance/` — project maintenance resources, not part of the
  published package: `maintenance/config/` (formatter configurations
  `.clang-format`, `.cmake-format.py`, `.prettierrc.json`,
  `.prettierignore`, and `top-templates.json`),
  `maintenance/scripts/` (the `.mjs` scripts behind the top-level
  `xpm run clang-format`, `cmake-format`, `jsonc-format`,
  `xcdl-export` actions, plus their Liquid `templates/`), and
  `maintenance/docs/` (developer notes).
- `xcdl-package.jsonc`, `CMakeLists.txt`, `meson.build` — build-system
  integration for consumers (xCDL/xpm, CMake, meson).

## Architecture

The public API lives in the `micro_os_plus::micro_test_plus` namespace
(usually aliased as `mt`) and in four of its sub-namespaces:

- the top namespace: the runner (`runner`, with `runner_options`,
  `verbosity`, and `reporter_kind`; `static_runner` is a deprecated
  alias), the test hierarchy (`test_case`, `suite`, `static_suite`,
  `top_suite`, `test_case_name`), `counters`, the function comparators
  (`eq()`, `ne()`, `gt()`, `ge()`, `lt()`, `le()`, `negate()`,
  `both()`, `either()`), `throws()` and `nothrow()` (with exceptions),
  the value wrappers (`to_i`, `to_f`, ..., `to_t<T>`, `approx()`), and
  `expression_formatter` (an alias of `detail::expression_formatter`,
  for the `operator<<` of the application types);
- `literals` — the user-defined literals (`42_i`, `1.5_d`, `"..."_b`);
- `operators` — the comparison and logical operators, enabled with
  `using namespace mt::operators`;
- `utility` — `is_match()` and `split()`;
- `extension` — what the applications use to write their own
  comparators, predicates, operators, and helpers that report their
  operands as the built-in ones do: the expression templates
  `compare_op` and `predicate_op`, parametrised by an application tag
  with `symbol` and `apply()` (using-declarations of the `detail`
  templates, at the end of `detail.h`), and the concepts `is_op`,
  `any_op`, `has_epsilon`, `checkable`, and `printable`
  (`extension.h`). It is deliberately a separate namespace, so that
  `using namespace mt` does not bring its generic names into the
  application code.

`reflection::source_location` appears in the public signatures (as a
defaulted parameter), but users rarely name it. Everything in `detail`
(including `detail::math`, the reporters, `check_result`, the value
wrapper templates, and the concepts `has_value`, `container_like`, and
`has_npos`) is internal; the applications must not need to name it.

- `runner` (in `runner.h`, defined in `src/runner.cpp`) is the top-level
  test session driver: it owns the tree of suites/tests, tracks pass/fail
  totals (`counters.h`), timings (`stopwatch.h`), and drives a
  `reporter` to print progress and the final summary. It also runs the
  `static_suite` objects that refer to it, which are kept in an
  intrusive list sorted by name, with a `constinit` head pointer
  (`static_suite::first_`), independent of the runner object, so they
  may be constructed before it. `static_runner` is a deprecated alias
  of `runner`.
- Test hierarchy (`test.h`, `src/test.cpp`), all deriving from the
  internal `detail::runnable_base` base (`suite` and `test_case` each store
  their body in a `std::function` taking a reference to their own class):
  - `top_suite` — the implicit root suite owned by each `runner`,
    returned by `runner::initialise()`; users do not construct it
    directly.
  - `suite` — a named group of test cases; `static_suite` is the
    statically-allocated variant.
  - `test_case` — a named sequence of checks inside a suite; test cases
    may be nested.
- `detail::reporter` (`reporter.h`) is the internal abstract base for
  formatting test results; the concrete implementations are
  `detail::reporter_human` (`reporter-human.h`, human-readable console
  output) and `detail::reporter_tap` (`reporter-tap.h`, TAP-format
  output for CI/tooling consumption). Custom reporters are not
  supported; the reporter is selected with the `--reporter` option or
  with `runner_options`.
  `check-result.h` (internal, `detail` namespace) holds the object
  returned by `expect()`/`require()` (`assume()` is a deprecated alias
  of `require()`): it stores the result, the source
  location, and the message accumulated via `operator<<`, and reports
  the outcome when it is destroyed, at the end of the expression
  statement.
- `expression-formatter.h`/`src/expression-formatter.cpp` and
  `reflection.h` provide the machinery behind the
  reports of the `expect()`/`require()` expressions, so failed checks
  print the actual operands and operator, not just "assertion failed".
- `operators.h` and `function-comparators.h` supply the comparison
  operators and function-based comparators used inside `expect (...)`
  expressions; they return the expression templates of `detail.h`
  (`detail::compare_op` with the tags `equal_to`, `less`, ..., and the
  logical `and_op`, `or_op`, `not_op`), which the formatter reports.
  `extension.h` holds the concepts that constrain them, and `math.h`
  (`detail::math`) supports the floating-point comparisons. The
  application extensions reuse the same templates, through the
  `extension` namespace, so they need no formatter of their own.
- `literals.h` defines user-defined literals (e.g. for naming tests).
- Headers declare, `inlines/*.h` hold template/inline bodies, `src/*.cpp`
  hold non-template definitions — keep new code split the same way when
  extending a header (declaration in `include/.../<name>.h`, inline
  bodies in `include/.../inlines/<name>-inlines.h`, non-inline definitions
  in `src/<name>.cpp`).
- Feature/behaviour macros (e.g. enabling reporters, exceptions support)
  are read from an optional, consumer-provided
  `micro-os-plus/micro-test-plus-defines.h` / `micro-os-plus/project-config.h`
  included at the top of `micro-test-plus.h`; do not assume a fixed
  configuration when reasoning about conditional compilation.

## Build System Integration

The library itself has no standalone build; it is consumed as source by
downstream projects via one of:

- **CMake** (`CMakeLists.txt`): defines `micro-os-plus::micro-test-plus`
  (INTERFACE), `micro-os-plus::micro-test-plus-objects-library` (OBJECT),
  and a STATIC library variant, all built from the same `src/*.cpp` list
  and depending on `micro-os-plus::diag-trace`. When adding a new `.cpp`
  file, add it to **all** of these `target_sources()` lists.
- **meson** (`meson.build`): declares an equivalent
  `micro_os_plus_micro_test_plus_dependency`.
- **xPack/xCDL** (`xcdl-package.jsonc`): package metadata for the xpm
  package manager.

## Testing

Tests live in the `tests/` folder, which is its own npm/xpm project (own
`package.json`, `node_modules`) driven by `xpm` (the xPack project
manager) and GitHub Actions matrices. Sample test programs live under
`tests/sources/{empty,minimal,sample,suite,unit}/src`, each with its own
`CMakeLists.txt`, `meson.build` and `xcdl-test.jsonc`, and are built and
executed for each platform/toolchain combination — not run through a
single `ctest`/`meson test` command from the top level.

Common commands (run from the repository root):

```sh
xpm run test -C tests               # native build with the system compiler
xpm run test-selected -C tests      # a minimal selection
xpm run test-latest -C tests        # native and qemu tests with latest compiler versions
xpm run test-all -C tests           # native and qemu tests with all compiler versions

xpm run test-synthetic-posix-cmake-clang -C tests    # native build with clang
xpm run test-qemu-cortex-m33-cmake-gcc -C tests      # cross build run under QEMU (Cortex-M33)
```

Other platforms available under `tests/platforms/` (each with its own
`test-<platform>-*` action): synthetic-posix (native),
qemu-cortex-{m0,m3,m33,m4f,m7f}, qemu-aarch32-a15, qemu-aarch64-a72,
qemu-riscv-{rv32imac,rv64imafdc}, nucleo-f411re{,-cubemx,-cubemx-startup},
nucleo-f767zi{,-cubemx}, nucleo-h533re{,-cubemx},
raspberry-pi-pico{,-sdk}, raspberry-pi-pico-2-{arm,riscv}{,-sdk}, and
raspberry-pi-zero-2-w-{aarch32,aarch64} (not yet functional).
`xpm run <action> -C tests` runs any action defined in
`tests/package.json`'s `xpack.actions` (inspect that file for the exact
generated action names, e.g.
`test-synthetic-posix-<builder>-gcc<version>`,
`test-qemu-cortex-<variant>-<builder>-gcc<version>`; with the version
omitted, the latest toolchain is used).

Before considering a change complete, run the tests required by the
Testing section of the Copilot instructions above: `test-selected`
after major changes, and only `test` after minor ones.
