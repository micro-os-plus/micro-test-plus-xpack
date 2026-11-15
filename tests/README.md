# Tests

The test programs are `empty`, `minimal`, `sample`, `suite`, and the
unit tests (`unit`, `unit-checks`, `unit-combinations`,
`unit-exceptions`, `unit-miscellaneous`, `unit-deprecated`, and
`unit-static-asserts`). The programs in `sources/benchmarks/` compare
µTest++ with other frameworks; they are not tests of µTest++.

The CI workflow runs several tests, both as native processes and as
semihosted applications emulated by QEMU; for details see
[test-ci.yml](../.github/workflows/test-ci.yml).

Exactly the same source files are built on all platforms, without
changes.

Each test lives in its own `sources/<name>` folder, with the source
files in `src/`, the headers, if any, in `include/`, and its own
`CMakeLists.txt`, `meson.build`, and `xcdl-test.jsonc`. The resulting
executables are named `<name>-test`.

The output of each program is compared with the reference files in
`expected/tap` and `expected/txt`. The `-noexcept` variants are for
the builds without exceptions; the `-console`, `-console-quiet`, and
`-colour` variants hold the console output of the unit tests, captured
on the synthetic-posix platform. A change that alters the reports, or
adds or removes checks, must update these files.

## Empty

The `sources/empty/src/main.cpp` file checks the behaviour of runners
and suites that have no checks, or only empty test cases. It uses
plain assertions instead of the framework primitives.

## Minimal

The `sources/minimal/src/main.cpp` file is a really small test,
intended for initial user experimentation with the framework.

## Sample

The `sources/sample/src/main.cpp` file is a simple example exercising
the primitives available in the testing framework.

If exceptions are enabled, this example also shows how to write a
test that checks if exceptions are caught properly.

## Suite

The files in `sources/suite/src/` exercise the test hierarchy: a global
runner, local runners, and suites, including the static suites defined
in a separate file (`suite.cpp`).

## Unit

The unit tests check that the framework evaluates and reports the
checks, and counts the results (successes and failures), correctly.
Some checks are expected to fail.

- `unit-checks`: the checks, the comparators, and the reported
  operands;
- `unit-combinations`: the integral and floating-point comparators,
  for many combinations of the numeric types;
- `unit-exceptions`: the `throws()` and `nothrow()` comparators, the
  unexpected exceptions, and the failed `require()`; without
  exceptions, it has no suites;
- `unit-miscellaneous`: the formatter and reporter output, the
  messages, the runner options and filters, the test hierarchy, the
  abort handler, the utility functions, and the stopwatch;
- `unit-deprecated`: the deprecated features, kept for compatibility
  with the previous releases;
- `unit-static-asserts`: the checks done at compile time; there is
  nothing to run.

The `unit` program links the bodies of `unit-checks`,
`unit-combinations`, `unit-exceptions`, and `unit-miscellaneous` into a
single program. The platforms with enough memory (QEMU and
synthetic-posix) build it instead of the four separate programs; the
physical boards, where it does not fit, build the four separate
programs instead. The choice is made in each platform's
`cmake/definitions.cmake` and `meson/definitions/meson.build`.

The helpers shared by the unit tests are in `sources/unit-common`,
which is a library, not a program.

## Benchmarks

The folders in `sources/benchmarks/` hold the programs that compare
µTest++ with other testing frameworks; they are not tests of µTest++.

The programs in `sources/benchmarks/footprint/<name>/src/` measure the
code and data sizes: `baseline` is an empty program, `printf` adds a
single `printf()` call, and each of the others (`micro-test-plus`,
`unity`, `cpputest`, `doctest`, `catch2`, `boost-ut`, `boost-test`,
`googletest`, and `snitch`) runs one test case with the same two
checks, written with one framework. The POSIX stubs required by some
of the frameworks on bare metal are in `common/src/`.

The other frameworks are not part of this repository; their versions
(the release tags and the expected commits) are listed in
`sources/benchmarks/frameworks.jsonc`, and they are fetched, once for
all the platforms, into the `benchmarks-frameworks` folder (ignored by
git, and removed by `npm run deep-clean`) with:

```sh
xpm run fetch-benchmarks-frameworks -C tests
```

The frameworks already at the listed versions are skipped; use
`node scripts/fetch-benchmarks-frameworks.mjs --force [name ...]`, in
the `tests` folder, to fetch them again.

On the synthetic-posix and QEMU platforms, the footprint programs are
built and run, as `footprint-<name>`, only in the CMake configurations,
and only when `XPACK_ENABLE_FOOTPRINT_BENCHMARKS_TEST` is set to `true`
in `cmake/project-definitions.cmake` (generated from the build-helper
template, where it is `false`); they then replace all the other test
programs. Each run passes if the program exits with zero. The programs without a third-party framework (`baseline`,
`printf`, and `micro-test-plus`) are always built; those of the other
frameworks only if the framework was fetched. The selection is in
`cmake/project-definitions.cmake` (generated from the build-helper
template), and the executables are defined in each platform's
`cmake/artefacts.cmake`.

The programs that fail on a platform are only built, not run; they are
listed in `xpack_footprint_benchmarks_not_run`, in the platform's
`cmake/definitions.cmake`. The programs that cannot be built on a
platform are listed in `xpack_footprint_benchmarks_not_built`, in the
same file, and are skipped. Currently:

- `boost-test` overflows the stack at any size, and its run does not
  end, so it is not run on the Cortex-M and AArch32 platforms; it
  requires exceptions, so it is not built on the platforms without
  them (AArch64 and RISC-V);
- `snitch` needs more than the 8 KB stack, so it is not run on
  qemu-cortex-m33, which checks the stack limit (on the other
  Cortex-M platforms, the overflow goes undetected and the run
  passes).

## Platforms

The platform-specific files are in `platforms/<name>`.

The device support comes from one of two sources:

- For the QEMU and Raspberry Pi platforms, it comes from shared µOS++
  packages (e.g. `@micro-os-plus/devices-qemu-cortexm`,
  `@micro-os-plus/devices-raspberry-pi`), which serve several cores. The
  platform selects the core by defining the device macros (e.g.
  `MICRO_OS_PLUS_DEVICE_QEMU_CORTEX_CORE_M7`) in
  `include/micro-os-plus/device-defines.h`, which the package's
  `micro-os-plus/device.h` includes when present.
- For the NUCLEO platforms, it is part of the platform, in a
  `device-<chip>` folder (e.g. `device-stm32f411re`), with its own
  `include/micro-os-plus/device.h`; no `device-defines.h` is needed.

## Known issues

- older meson fails on Darwin new linker, since it no longer supports
`--version` -> 1.3.0 (<https://github.com/mesonbuild/meson/issues/12419>)
- meson 1.3.0 still fails with gcc 11
  (<https://github.com/mesonbuild/meson/issues/12552>)

- `test-synthetic-posix-cmake-sys` and `test-synthetic-posix-meson-sys` are strict only on
Darwin, which is known to have the toolchain; otherwise it is allowed to fail

- on Linux the linker complains about libpthread:

```console
/home/ilg/.local/xPacks/@xpack-dev-tools/gcc/13.2.0-1.1/.content/bin/../lib/gcc/aarch64-unknown-linux-gnu/13.2.0/../../../../aarch64-unknown-linux-gnu/bin/ld: warning: libpthread.so.0, needed by /home/ilg/.local/xPacks/@xpack-dev-tools/gcc/13.2.0-1.1/.content/bin/../lib/gcc/aarch64-unknown-linux-gnu/13.2.0/../../../../lib64/libstdc++.so, not found (try using -rpath or -rpath-link)
```
