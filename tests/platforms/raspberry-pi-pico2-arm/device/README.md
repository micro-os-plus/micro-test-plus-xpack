# device/rp2350

Definitions specific to the RP2350 device.

The result is a CMake interface library `micro-os-plus::device`.

## Implementation

Rather than linking the full `pico_stdlib` (which pulls in UART/USB
stdio, flash, and other subsystems that are not needed here), this
folder links only a limited selection of the Pico SDK's own CMake
libraries, and overrides the handful of functions needed to divert
the startup sequence into the µOS++ `micro-os-plus::startup` machinery.

### Pico SDK libraries used

`device/CMakeLists.txt` links directly against:

- `cmsis_core` — the CMSIS-Core headers for the RP2350 (`RP2350.h`,
  included by [include/micro-os-plus/device.h](include/micro-os-plus/device.h))
- `pico_standard_link` — the SDK's default linker script and memory map
- `pico_crt0` — the reset handler and vector table (`_start()`)
- `pico_runtime_init` — the weak, overridable `runtime_init()` hook
  called by `pico_crt0` once the C runtime (data/bss) has been set up

None of the higher-level SDK libraries (`pico_stdlib`,
`pico_clib_interface`, hardware drivers, and so on) are linked.

### Overridden functions

Because `pico_clib_interface` and the SDK's default `runtime_init()`
implementation are not linked, two functions normally provided by the
SDK are supplied locally instead:

- [src/runtime-init.cpp](src/runtime-init.cpp) — replaces the weak
  `runtime_init()` from `pico_runtime_init`; instead of running the
  SDK's own staged `runtime_init()` dispatcher and calling `main()`,
  it calls `runtime_init_per_core_enable_coprocessors()` (otherwise
  the FPU coprocessor is never enabled, and the first floating-point
  instruction, e.g. in `printf`, faults with a `UsageFault`/`NOCP`),
  then forwards to `micro_os_plus_startup_run_main()`, handing control
  to the µOS++ startup sequence.
- [src/_sbrk.c](src/_sbrk.c) — a copy (cosmetic formatting changes
  only) of the `_sbrk()` implementation from the SDK's
  `pico_clib_interface`, reused here because that component is not
  linked and newlib still requires `_sbrk()` for heap allocation.
