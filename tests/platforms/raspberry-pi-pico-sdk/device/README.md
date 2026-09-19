# device/rp2040

Definitions specific to the RP2040 device.

The result is a CMake interface library `micro-os-plus::device`.

## Implementation

Rather than linking the full `pico_stdlib` (which pulls in UART/USB
stdio, flash, and other subsystems that are not needed here), this
folder links only a limited selection of the Pico SDK's own CMake
libraries, and overrides the handful of functions needed to divert
the startup sequence into the µOS++ `micro-os-plus::startup` machinery.

### Pico SDK libraries used

`device/CMakeLists.txt` links directly against:

- `cmsis_core` — the CMSIS-Core headers for the RP2040 (`RP2040.h`,
  included by [include/micro-os-plus/device.h](include/micro-os-plus/device.h))
- `pico_standard_link` — the SDK's default linker script and memory map
- `pico_crt0` — the reset handler and vector table (`_start()`)
- `pico_runtime_init` — the weak, overridable `runtime_init()` hook
  called by `pico_crt0` once the C runtime (data/bss) has been set up
- `hardware_gpio` — the SDK's GPIO driver, used by
  [../src/led-green.cpp](../src/led-green.cpp) to drive the onboard
  green LED; not pulled in transitively by any of the above, so it is
  linked explicitly

None of the other higher-level SDK libraries (`pico_stdlib`,
`pico_clib_interface`, and so on) are linked.

### Overridden functions

Because `pico_clib_interface` and the SDK's default `runtime_init()`
implementation are not linked, two functions normally provided by the
SDK are supplied locally instead:

- [src/runtime-init.cpp](src/runtime-init.cpp) — replaces the weak
  `runtime_init()` from `pico_runtime_init`; instead of performing the
  SDK's own runtime initialisation and calling `main()`, it forwards
  to `micro_os_plus_startup_run_main()`, handing control to the
  µOS++ startup sequence.
- [src/_sbrk.c](src/_sbrk.c) — a copy (cosmetic formatting changes
  only) of the `_sbrk()` implementation from the SDK's
  `pico_clib_interface`, reused here because that component is not
  linked and newlib still requires `_sbrk()` for heap allocation.

## `experimental/`

The [experimental](experimental) folder holds an alternative, currently
unused implementation that bypasses `pico_crt0`/`pico_runtime_init`
entirely, replacing them with a fully custom reset handler, vector
table, exception handlers, and hardware initialisation, plus
matching [linker scripts](experimental/linker-scripts). It is kept for
reference, and predates the current µOS++ startup API in places (it
still refers to the older `cmsis-plus/rtos/os-hooks.h`); it is not
wired into `device/CMakeLists.txt` and does not take part in the build.
