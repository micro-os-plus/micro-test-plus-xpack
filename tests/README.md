# Tests

There are five test programs available: `empty`, `minimal`, `sample`,
`suite`, and `unit`.

The CI workflow runs several tests, both as native processes and as
semihosted applications emulated by QEMU; for details see
[test-ci.yml](../.github/workflows/test-ci.yml).

Exactly the same source files are built on all platforms, without
changes.

Each test lives in its own `sources/<name>` folder, with the source
files in `src/` and its own `CMakeLists.txt`, `meson.build`, and
`xcdl-test.jsonc`. The resulting executables are named `<name>-test`.

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

The files in `sources/suite/src/` exercise the test hierarchy: local
runners, a static runner, and suites, including a statically
allocated suite defined in a separate file (`suite.cpp`).

## Unit

The files in `sources/unit/src/` check if the framework counts the
test results (successes and failures) correctly. Some checks are
expected to fail.

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
