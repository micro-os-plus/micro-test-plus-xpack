# Consistency check

Date: 2026-10-12, on branch `xpack-development`, commit `78076ae8`.

Scope: the whole project, excluding `website/`, `tests/build/`,
`node_modules/`, `xpacks/`, and all `stm32cubemx/` folders.

Checked: file and folder naming consistency, whether file names
represent their content, and whether the READMEs are up to date.

The check found 28 problems: 3 functional defects, 13 stale or
incorrect READMEs, and 12 naming inconsistencies. Two functional
defects (1.2 and 1.3) and all the README problems (section 2) have
since been fixed.

## Note on generated files

Many of the affected files carry the header "DO NOT EDIT! Automatically
generated from build-helper/templates/…". These include all platform
READMEs, `tests/scripts/README.md`, `tests/cmake/README.md`, the stray
linker script, and the xCDL toolchain files. They must be fixed in the
`@micro-os-plus/build-helper` templates and regenerated, not edited in
this repository.

## 1. Functional defects

1. **The `raspberry-pi-zero-2-w-*` names do not match.** In
   `tests/package.json` (around line 2577) the build configurations are
   named `raspberry-pi-pico-zero-2-w-aarch32/64-cmake-gcc-{debug,release}`,
   with `platformName: raspberry-pi-pico-zero-2-w-…`. The actions (around
   line 1078) and the platform folders use `raspberry-pi-zero-2-w-…`.
   Every one of those actions would fail with an unknown configuration.
   Both folders currently hold only `.gitkeep`, so the defect has not
   shown up yet.
2. **Missing actions (fixed).** The per-platform
   `link-dependencies-<platform>-cmake-gcc` wrapper action was missing
   for `raspberry-pi-pico-2-riscv`, `raspberry-pi-pico-2-riscv-sdk`, and
   the two `zero-2-w` platforms; the per-configuration
   `link-dependencies` actions existed. The wrappers were added to
   `tests/package.json` and to the build-helper template
   `templates/common/_micro-os-plus/tests/package-merge-liquid.json`.
   The two `zero-2-w` platforms are intentionally left out of
   `configs-boards`, and therefore out of the `*-boards` composite
   actions, until they become functional.
3. **`.vscode/launch.json` (lines 12-48) was stale (fixed).** The three
   native launch entries pointed to
   `tests/build/native-cmake-sys-debug/platform-bin/…` and
   `build/native-cmake-clang12-debug/…`. They now point to the build
   folder root of `synthetic-posix-cmake-sys-debug` and
   `synthetic-posix-cmake-clang-debug`, with the `tests/` prefix, and
   the entry names were updated to match.

## 2. Stale or incorrect READMEs

Status: fixed. The generated READMEs were fixed in the build-helper
templates and regenerated with `npm run generate-tests-commons` in
`tests/`. `CLAUDE.md` and `tests/README.md` have no templates.

### `tests/README.md` (fixed)

- It said "a unit test and two sample tests"; it now describes all five
  tests (`empty`, `minimal`, `sample`, `suite`, and `unit`) and their
  `sources/<name>/src/` locations.
- The false claim that `minimal` is built only on native CMake was
  removed.
- The obsolete Known issues items (gcc 11 on Darwin, where native gcc
  is no longer run, and clang 13/14) were removed. The `sys`
  strictness note is still valid and was kept.

### `tests/cmake/README.md` (fixed)

- It now documents all the toolchain files (`arm-none-eabi-gcc`,
  `aarch64-none-elf-gcc`, `riscv-none-elf-gcc`, `gcc`, and `clang`);
  the obsolete `riscv-none-embed-gcc` was later removed (section 3).

### `tests/scripts/README.md` (fixed)

- `platforms/native/…` now reads `platforms/synthetic-posix/…`.
- The `convert-startup-to-vectors.mjs` example now uses
  `platforms/nucleo-f411re-cubemx/device-stm32f411re/…`, the actual
  input and output paths.
- The project-specific `doubly-list-links.cpp` example was replaced by
  a generic `src/<file>.cpp`.

### `tests/platforms/synthetic-posix/README.md` (fixed)

- `XPACK_ENABLE_COVERAGE` is now documented as set in
  `cmake/artefacts.cmake`.
- The `doubly-list-links.cpp` example was replaced by `src/<file>.cpp`.

### `tests/platforms/qemu-cortex-m3/README.md`

- Fixed: `mps2-an365` and `mps2-an5365` now read `mps2-an385`.
- Not changed: the debug command has no `--kernel`. All the QEMU
  READMEs follow this pattern, presumably because the debugger loads
  the image.
- Fixed: the `virt` link did not describe the `mps2-an385` machine; the
  same link appeared in the `qemu-cortex-m0`, `m4f`, and `m7f` READMEs.
  All four now link to the QEMU "Arm MPS2 and MPS3 boards" page, like
  `qemu-cortex-m33`. The `virt` link is kept in the `qemu-aarch32-a15`,
  `qemu-aarch64-a72`, and `qemu-riscv-*` READMEs, which do use it.
- Additionally fixed: `qemu-cortex-m4f/README.md` said "The
  `mps2-an385` machine defines"; it now says `mps2-an386`.

### `tests/platforms/qemu-aarch32-a15/README.md` (fixed)

- Typo "mising" corrected.

### Raspberry Pi Pico 2 READMEs (fixed)

- The links to the non-existent `device/README.md` were removed. The
  "Known limitation" sections were obsolete, since the
  `@micro-os-plus/devices-raspberry-pi` package now provides the
  RP2350 image metadata block (`embedded-block-rp2350-*.c`); they were
  replaced by a short "Boot-ROM image metadata" section.
- The "VS Code debug launcher above" reference now reads "the VS Code
  debug launchers".

### Device READMEs (fixed)

- `Core/src/main.c` now reads `Core/Src/main.c` in the four CubeMX
  device READMEs.
- `stm32f411xe_FLASH.ld` now reads `STM32F411xx_FLASH.ld`.
- The first line now names the specific device in all of them
  (`stm32f411re`, `stm32f767zi`, and `stm32h533re`), matching the
  folder names.

### `CLAUDE.md` (fixed)

- The commands now read `test-synthetic-posix-cmake-clang` and
  `test-qemu-cortex-m7f-cmake-gcc`.
- The platform list now names `synthetic-posix` and includes the
  `-cubemx`, `-cubemx-startup`, `-sdk`, `pico-2-*`, and `zero-2-w-*`
  variants (the latter marked as not yet functional).
- The `top_suite` and deferred reporter descriptions were corrected.

### `.github/copilot-instructions.md` (fixed)

- Line 116: `test-native-cmake-clang` now reads
  `test-synthetic-posix-cmake-clang`. The file is generated (and kept
  read-only) from the `@xpack/npm-packages-helper` template
  `templates/common/.github/copilot-instructions-liquid.md`; the template
  was fixed and the file regenerated with `npm run generate-top-commons`.
- Correction to the original report: `test-qemu-cortex-m7f-cmake-gcc`
  (line 117) does exist; the matrix actions also accept an empty
  toolchain version, which selects the latest toolchain.

### Up to date

The top-level `README.md` (v5.0.1) and
`include/micro-os-plus/micro-test-plus/README.md` are current.

## 3. File and folder names

### Library

- Fixed: `include/micro-os-plus/micro-test-plus/inlines/exceptions-inline.h`
  was renamed to `exceptions-inlines.h`, matching every other file in
  `inlines/` and its own include guard. The include in `exceptions.h`
  and the folder tree in
  `website/docs/install/_project/_install-folder-hierarchy.mdx` were
  updated; the generated Doxygen output under `website/` will follow on
  the next documentation build.
- Fixed: the include guards now match their file names:
  - `reporter-human.h` used `…_TEST_REPORTER_BASIC_H_`, a leftover from
    the old `reporter_basic` name; it now uses `…_REPORTER_HUMAN_H_`.
  - `reporter.h`, `reporter-tap.h`, `runner.h`, and `runner-totals.h`
    no longer carry the extra `TEST_`.
- Fixed (during the Doxygen review): some `@file` `@brief` lines were
  wrong or too generic:
  - `inlines/deferred-reporter-inlines.h` said "internals".
  - `src/reflection.cpp` and `src/utility.cpp` said only "µTest++
    methods".
  - `src/reporter-tap.cpp` said "TAP suite reporter" where the header
    says "TAP test reporter".

### Tests

- Fixed:
  `tests/platforms/raspberry-pi-pico-2-riscv/include/micro-os-plus/diag/linker-scripts/mem.ld`
  was a stray duplicate in the wrong place (identical to the
  `linker-scripts/mem.ld` used by the build), generated from the
  misplaced build-helper template
  `templates/common/_micro-os-plus/tests/platforms/raspberry-pi-pico-2-riscv/include/micro-os-plus/diag/linker-scripts/mem-liquid.ld`.
  Both the template and the generated file were deleted.
- Fixed: `tests/xcdl/toolchains/*.json` were exact duplicates of the
  `*.jsonc` files, left over from an older template (the build-helper
  templates now produce only `*.jsonc`), and nothing referenced them.
  They were deleted.
- Fixed: `tests/cmake/toolchains/riscv-none-embed-gcc.cmake` was for an
  obsolete toolchain that no µOS++ project uses. The build-helper
  template
  `templates/common/_micro-os-plus/tests/cmake/toolchains/riscv-none-embed-gcc-liquid.cmake`
  and the generated file were deleted, and the deprecation paragraph
  was removed from the `tests/cmake/README.md` template. The copies
  generated earlier in other projects are not removed by regeneration
  and must be deleted there.
- Fixed (intentional, now documented): `wraps.c` sits under
  `device-stm32f411re/src/` in `nucleo-f411re-cubemx-startup`, but
  under the platform's `src/` in the three `-sdk` platforms. In
  `nucleo-f411re-cubemx-startup` it adapts the STM32CubeMX startup code
  kept in the device folder, and the matching `-Wl,--wrap=main` and
  `-Wl,--wrap=__libc_init_array` linker options are also set there. The
  reason is now explained in the device README (build-helper
  template).

  Decision: the rule is that `wraps.c` goes where the foreign startup
  code is added to the build, i.e. the platform folder for the Pico SDK
  (`pico_crt0`) and the device folder for the STM32CubeMX startup code;
  the different locations are intentional and must not be reported
  again. Moving the Pico SDK wrappers into `devices-raspberry-pi` was
  considered (the three copies differ per core), but proved too
  complicated, and was abandoned. The rule is also stated in the three
  `-sdk` platform READMEs (build-helper templates).
- Fixed: `device-defines.h` exists for the QEMU and Pico platforms but
  not for the NUCLEO platforms. This is intentional: the former use the
  shared device packages, whose `device.h` includes it when present to
  select the core, while the NUCLEO platforms have their own device
  folder. It is now documented in the "Platforms" section of
  `tests/README.md`.
- Fixed: the QEMU matrix variable was `qemu-cortex-variant` in the
  actions but `qemu-cortexm-variant` in the configurations. All the
  names (the matrix variable, the `qemu-cortex-variants` property, and
  the `add-qemu-cortex-variants-*` properties) now use `qemu-cortex-`,
  like the platform names, in the build-helper template
  `package-merge-liquid.json` and in `tests/package.json`. The other
  projects generated from the same template (e.g. `utils-lists`,
  `diag-trace`) need the same in-place rename before regeneration,
  since the merge keeps the old keys.
- Fixed: the copy-pasted suite variables in the unit test were renamed
  after their files (`ts_comparisons`, `ts_operators`, and
  `ts_miscellaneous`), and the combination suites now use the same word
  order (`ts_failed_floats`, `ts_passed_floats`, `ts_failed_integrals`,
  and `ts_passed_integrals`).

### `.github/skills`

These still describe an older layout.

- `nucleo-standalone-platform/SKILL.md` uses `device/…` throughout;
  since commit `90500ede` the folders are `device-<chip>/`.
- `led/SKILL.md` describes `device/<chip>/src/gpio.c`, `led.c`,
  `led-user.h`, and `raspberry-pi-pico/device/rp2040/clock.*`, none of
  which exist. The actual pattern is
  `include/micro-os-plus/<board>/led-green.h` with `src/led-green.cpp`.
- `code-review/SKILL.md` was copied from an architecture project: it
  cites `instructions-inlines.h`, `architecture.h`, and the
  `aarch64_architecture_*` symmetry rule, none of which apply here.

## 4. Verified as consistent

- The platform folder names match `tests/config/tests-templates.json`.
- Every reference file in `tests/expected` is used.
- The `src/*.cpp` files pair up with their headers.
- The device CMake target names and `.ioc` file names match their
  READMEs.
- The platform README titles follow a single pattern.

## 5. Proposed next steps

- Fix the files in this repository that are not generated: the library
  sources, `tests/README.md`, `CLAUDE.md`,
  `.github/copilot-instructions.md`, `.vscode/launch.json`, the skills,
  and the unit test variable names.
- Fix the build-helper templates for the generated files listed above,
  then regenerate them.
