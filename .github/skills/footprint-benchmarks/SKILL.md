---
name: footprint-benchmarks
description: 'Measure the memory footprint of µTest++ and of the other testing frameworks (Unity, CppUTest, doctest, Catch2, Boost UT, Boost.Test, GoogleTest, and snitch) with the footprint programs in tests/sources/benchmarks/footprint, on all the QEMU platforms, and update the figures on the website (the comparison page, the landing page, the embedded targets page, and the Getting Started features). Use when the user asks to "re-run the footprint benchmarks", "measure the footprint", "update the footprint figures", to upgrade the compared frameworks to newer releases, or when a change of µTest++, of the toolchains, or of the platforms may have changed the sizes.'
argument-hint: 'Optional: the frameworks to upgrade, or the platforms to measure'
---

# Footprint benchmarks — µTest++ Testing Framework

## When to Use

- The figures on the website must be refreshed: after a release of
  µTest++, an upgrade of the toolchains, or a change of the platforms
  or of the startup code.
- One of the compared frameworks has a new release.
- A new framework, or a new platform, is added to the comparison.

## What Is Measured

Each program in `tests/sources/benchmarks/footprint/<name>/src/` runs
one test case with the same two checks (an equality and a condition,
on `volatile` values), written with one framework, in its default
configuration. Two programs have no framework: `baseline`, an empty
`main()` (the reference of all the increases), and `printf`, with a
single `printf()` call (the cost of the formatted output of the C
library). `common/src/posix-stubs.c` holds the POSIX functions that
GoogleTest, Catch2, and Boost.Test call and a bare-metal newlib does
not have.

The frameworks are not in the repository: their release tags and
commits are in `tests/sources/benchmarks/frameworks.jsonc`, and
`xpm run fetch-benchmarks-frameworks -C tests` fetches them into the
`tests/benchmarks-frameworks` folder (ignored by git, removed by
`deep-clean`).

The measured sizes are kept in
`tests/sources/benchmarks/footprint-sizes.json`, with the conditions of
the measurement (the date, the µTest++ commit, the toolchains, and the
size of the µTest++ symbols).

## How the Programs Are Built

- Only the CMake configurations build them; the meson configurations
  do not.
- `XPACK_ENABLE_FOOTPRINT_BENCHMARKS_TEST`, in
  `tests/cmake/project-definitions.cmake`, enables them, and then
  **replaces all the other test programs**. It is `false` in the
  committed file, which is generated from the build-helper template
  `templates/common/_micro-os-plus/tests/cmake/project-definitions-liquid.cmake`;
  set it to `true` only temporarily, in the generated file, and never
  commit it.
- The project definitions select the programs: those without a
  framework always, the others only if their folder exists in
  `tests/benchmarks-frameworks`.
- Each platform's `cmake/artefacts.cmake` defines the executables, and
  its `cmake/definitions.cmake` sets two lists:
  `xpack_footprint_benchmarks_not_built` (skipped) and
  `xpack_footprint_benchmarks_not_run` (built, but not run).

## Procedure

1. **Upgrade the frameworks**, if required: update the tags and the
   commits (and, for Boost, the archive URL, the version, and the
   SHA-256) in `frameworks.jsonc`, then fetch them again:

   ```sh
   xpm run fetch-benchmarks-frameworks -C tests
   (cd tests && node scripts/fetch-benchmarks-frameworks.mjs --force <name>)
   ```

   A new release may need new configuration macros, new POSIX stubs,
   or a different source list; see "Known Problems". When the
   `xcdl-test.jsonc` of a program changes, regenerate its CMake and
   meson files with `xpm run xcdl-export -C tests`, and format the
   CMake files with `cmake-format` (see the xcdl skill).

2. **Enable the programs**, temporarily:

   ```sh
   sed -i '' 's/^set (XPACK_ENABLE_FOOTPRINT_BENCHMARKS_TEST false)$/set (XPACK_ENABLE_FOOTPRINT_BENCHMARKS_TEST true)/' \
     tests/cmake/project-definitions.cmake
   ```

3. **Build the release configurations** of the nine QEMU platforms
   (`qemu-cortex-m0`, `-m3`, `-m4f`, `-m7f`, `-m33`, `qemu-aarch32-a15`,
   `qemu-aarch64-a72`, `qemu-riscv-rv32imac`, and
   `qemu-riscv-rv64imafdc`), one configuration at a time, in the
   background:

   ```sh
   for p in qemu-cortex-m0 qemu-cortex-m3 qemu-cortex-m4f qemu-cortex-m7f \
     qemu-cortex-m33 qemu-aarch32-a15 qemu-aarch64-a72 \
     qemu-riscv-rv32imac qemu-riscv-rv64imafdc
   do
     for a in setup build test
     do
       xpm run $a --config $p-cmake-gcc-release -C tests || break
     done
   done
   ```

   The `test` step is optional for the sizes, but it shows whether a
   program that used to run now fails, or the reverse; update the two
   lists of the platform accordingly. Do not edit the sources or the
   CMake files while the builds run.

4. **Extract the sizes**, right after the builds, before committing
   anything (the script records the current commit):

   ```sh
   node .github/skills/footprint-benchmarks/scripts/extract-footprint-sizes.mjs \
     tests tests/sources/benchmarks/footprint-sizes.json
   ```

   Compare the new file with the committed one (`git diff`), and look
   for unexpected changes before going further.

5. **Restore the flag**:

   ```sh
   git checkout -- tests/cmake/project-definitions.cmake
   ```

6. **Regenerate the tables** of the comparison page, between the
   `{/* BEGIN generated footprint-* */}` and `{/* END generated ... */}`
   markers:

   ```sh
   node .github/skills/footprint-benchmarks/scripts/generate-footprint-tables.mjs \
     tests/sources/benchmarks/footprint-sizes.json \
     --update website/docs/developer/comparison/index.mdx
   ```

   The script also prints the figures quoted in the text (see the next
   step). Without `--update`, it only prints.

7. **Update the figures in the text**, by hand, with the values printed
   by the script; check each one, since the wording may need to change
   with the values:

   - `website/docs/developer/comparison/index.mdx`:
     - the "Flash added on Cortex-M3" row of the summary matrix;
     - "Reading the figures": the range of the empty program on Arm,
       the µTest++ increase on Cortex-M and its own symbols, the range
       of the large frameworks and the ratio to µTest++, the snitch
       buffers, and the `printf()` cost on AArch64 and RISC-V;
     - the Boost UT and Unity sections, and "Operands reported by the
       comparators";
     - the toolchain versions, and the Sources table (the release
       tags, the commits, and the µTest++ commit);
     - the `date` of the front matter.
   - `website/src/components/HomepageExample/index.tsx`: the
     "Footprint" paragraph, with the absolute Cortex-M4F values (the
     µTest++ program, the range of Boost UT, doctest, GoogleTest,
     Boost.Test, and Catch2, and the empty program).
   - `website/docs/user/embedded-targets/index.mdx`: the µTest++ and
     Boost UT programs, if they changed, the `size` lines on
     Cortex-M7F, the increase, the µTest++ symbols, the empty program,
     the Boost UT increase and version, and the `date`.
   - `website/docs/getting-started/_project/_features.mdx`: the
     "Reduced memory footprint" bullet.
   - `website/src/components/HomepageFeatures/CustomFeatureList.tsx`:
     the "Built for bare-metal" card, which states the footprint only
     qualitatively; check that it still holds.

8. **Verify**: compile the pages (`npm run build` in `website`, which
   also checks the `#footprint` links), and run `xpm run test -C tests`,
   to confirm that the regular tests are back.

9. **Commit**, with the github-commit skill: the sizes file, the
   website pages, and, separately, any change of the programs or of
   the platforms.

## Reading the Results

- **Compare within a platform, not across platforms.** On the Arm
  platforms, the µOS++ startup already links the formatted output of
  newlib and the C++ exception run-time support, including the
  demangler of the verbose terminate handler (`d_print_comp_inner`), so
  the empty program is about 80 KiB and the increase is mostly the
  framework. On AArch64 and RISC-V, the empty program is under 8 KiB,
  and each framework also brings these libraries; µTest++ adds about
  180 KiB there, against about 46 KiB on Cortex-M.
- **The µTest++ symbols** (`microTestPlusSymbols`, the code and
  read-only symbols whose names contain `micro_test_plus`) are about
  24 KiB on Cortex-M and RISC-V; the rest of the increase comes from
  the libraries.
- **The RAM figures** are the static RAM (`data` plus `bss`); the heap
  and the stack used at run time are not measured.
- To find what a program brings, list its largest symbols:
  `<prefix>-nm --size-sort -S -C --radix=d <elf> | tail -20`.

## Known Problems

- **Boost.Test** (the single-header variant, Boost 1.92):
  - it does not build without exceptions, since
    `framework_shutdown_helper` in `unit_test_main.ipp` uses `try` and
    `catch` unconditionally; it is in the `not_built` list of the
    AArch64 and RISC-V platforms, which build with `-fno-exceptions`;
  - where it builds, it does not complete on bare metal: it overflows
    the stack at any size (a `STKOF` UsageFault on the Cortex-M33,
    even with a 1 MiB stack), and it never ended on the Cortex-M3 and
    the Cortex-A15; it is in the `not_run` list of all the platforms
    where it builds, including the Cortex-M0, M4F, and M7F, where it
    was not tried, since, like the Cortex-M3, they have no stack limit
    check;
  - it needs `_POSIX_MONOTONIC_CLOCK=200112L`, `_POSIX_TIMERS=1`, and
    the `clock_gettime()` stub, and `BOOST_SP_DISABLE_THREADS`, since
    ARMv6-M (Cortex-M0) has no atomic instructions.
- **snitch** keeps the default capacities, which take about 256 KiB of
  initialised data (512 KiB on 64-bit), and its test case needs more
  than the 8 KiB stack: on the Cortex-M33, the stack limit check stops
  it (it is in that platform's `not_run` list); on the other platforms
  the overflow is not detected. It is compiled as a unity build
  (`src/snitch.cpp` only), with the configuration header generated by
  CMake into `benchmarks-frameworks/snitch-config`.
- **CppUTest** without exceptions needs `CPPUTEST_STD_CPP_LIB_DISABLED`
  and `CPPUTEST_MEM_LEAK_DETECTION_DISABLED`, set by
  `include/generated/CppUTestGeneratedConfig.h` (with `HAVE_CONFIG_H`).
- **doctest** needs `DOCTEST_CONFIG_NO_MULTITHREADING` and
  `DOCTEST_CONFIG_NO_POSIX_SIGNALS`, **Catch2**
  `CATCH_CONFIG_NO_POSIX_SIGNALS`, and **GoogleTest**
  `GTEST_HAS_PTHREAD=0`.
- **GoogleTest** aborts if `getcwd()` fails; the stub returns `/`.
- **macOS** (synthetic-posix): doctest, Catch2, and Boost.Test need
  `_DARWIN_C_SOURCE`, since `_POSIX_C_SOURCE` hides the BSD types used
  by `<sys/sysctl.h>`.
- **Hanging programs.** A program that never ends keeps
  `qemu-system-*` at 100% CPU, and ctest has no short default timeout.
  To find such programs, run ctest directly, with a timeout, from the
  build folder:

  ```sh
  (cd tests/build/<config> &&
    PATH="$PWD/xpacks/.bin:$PWD/../../xpacks/.bin:$PATH" \
    ctest --timeout 120)
  ```

  `ctest` and `cmake` are in `tests/xpacks/.bin`, not in the build
  folders; the toolchain is in the build folders.
- **Removals with variables.** Do not use `rm` with an unchecked shell
  variable (`rm -f $S/*.log`); the safety checks block it. Overwrite
  the logs instead.

## Adding a Framework or a Platform

- **A framework**: add the folder in `tests/sources/benchmarks/footprint`
  (with `src/main.cpp` and `xcdl-test.jsonc`; the frameworks reached
  through `../../../../benchmarks-frameworks/...`, with `-w`, and with a
  dependency on `benchmark.footprint-common` if it needs the stubs),
  add its entry to `frameworks.jsonc` and, if needed, to the fetch
  script, add the pair `"<name>:<folder>"` to the project definitions
  template in build-helper and regenerate it (`npm run
  generate-tests-commons` in `tests`), add it to the lists of the two
  scripts of this skill, and add its row and column to the pages.
- **A platform**: copy the footprint block of the `cmake/artefacts.cmake`
  of a QEMU platform, set the two lists in its `cmake/definitions.cmake`,
  and add it, with its toolchain prefix, to the two scripts.
