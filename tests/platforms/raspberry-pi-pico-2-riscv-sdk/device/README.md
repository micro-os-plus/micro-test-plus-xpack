# device/rp2350

Definitions specific to the RP2350 device, Hazard3 (RISC-V) core.

The result is a CMake interface library `micro-os-plus::device`.

## Implementation

Rather than linking the full `pico_stdlib` (which pulls in UART/USB
stdio, flash, and other subsystems that are not needed here), this
folder links only a limited selection of the Pico SDK's own CMake
libraries, and overrides the handful of functions needed to divert
the startup sequence into the µOS++ `micro-os-plus::startup` machinery.

### Pico SDK libraries used

`device/CMakeLists.txt` links directly against:

- `hardware_hazard3` — the Hazard3-core-specific RISC-V CSR/intrinsics
  headers (`hardware/hazard3.h`, included by
  [include/micro-os-plus/device.h](include/micro-os-plus/device.h)); the
  RISC-V counterpart of the sibling Arm platform's `cmsis_core`
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
implementation are not linked, `pico_crt0`'s empty weak `runtime_init()`
stub is the one that runs; two functions normally provided by the SDK
are supplied locally instead:

- [src/wraps.c](src/wraps.c) — uses `--wrap` to intercept `main()` and
  `__libc_init_array()`. `__wrap_main()` forwards directly to
  `micro_os_plus_startup_run_main()`, handing control to the µOS++
  startup sequence (unlike the sibling Arm platform, there is no FPU
  coprocessor to enable here — Hazard3 has no hardware float unit, and
  the SDK's own `runtime_init_per_core_enable_coprocessors()` is not
  even compiled on RISC-V builds). `__wrap__libc_init_array()` is
  silenced, since static initialisers are run by the µOS++ startup code
  instead.
- [src/_sbrk.c](src/_sbrk.c) — a copy (cosmetic formatting changes
  only) of the `_sbrk()` implementation from the SDK's
  `pico_clib_interface`, reused here because that component is not
  linked and newlib still requires `_sbrk()` for heap allocation.
