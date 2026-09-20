# device/rp2350

Definitions specific to the RP2350 device.

The result is a CMake interface library `micro-os-plus::device`.

## Implementation

This folder does not link any Pico SDK CMake library. The reset handler,
vector table, and runtime start-up are entirely custom, implemented on top
of the `micro-os-plus::architecture` and `micro-os-plus::startup`
machinery, the same way as the other Cortex-M platforms in this project
(including [platforms/raspberry-pi-pico](../raspberry-pi-pico/device/README.md),
its RP2040 counterpart).

The only thing still taken from the Pico SDK is its bundled
CMSIS-Core/CMSIS-Device headers for the RP2350, used purely as
include folders (no sources, no libraries are linked from there).

### Pico SDK headers used

`device/CMakeLists.txt` adds, as plain include folders, the CMSIS
stub headers from the `@xpack-3rd-party/raspberrypi-pico-sdk` package:

- `.../cmsis/stub/CMSIS/Core/Include` — the standard CMSIS-Core headers
- `.../cmsis/stub/CMSIS/Device/RP2350/Include` — the RP2350 CMSIS-Device
  headers (`RP2350.h`, included by
  [include/micro-os-plus/device.h](include/micro-os-plus/device.h))

No Pico SDK CMake targets are linked, and no other Pico SDK sources
are compiled.

### Custom implementation

- [src/vectors-rp2350.c](src/vectors-rp2350.c) — the interrupt vector
  table (`_interrupt_vectors[]`) and the weak IRQ handler declarations
  for the RP2350's 52 device interrupts (per `RP2350.h`'s `IRQn_Type`),
  all aliased to `Default_Handler`; the reset handler itself
  (`Reset_Handler`) and the other Cortex-M core handlers, including the
  Armv8-M-specific `MemManage_Handler`/`BusFault_Handler`/
  `UsageFault_Handler`/`SecureFault_Handler`/`DebugMon_Handler`, come
  from `micro-os-plus::architecture-cortexm`.
- [src/system-rp2350.cpp](src/system-rp2350.cpp) — the CMSIS-mandated
  `SystemInit()` and `SystemCoreClockUpdate()` functions, and the
  `SystemCoreClock` variable, built only when
  `MICRO_OS_PLUS_STARTUP_ENABLED` is defined.

### Known limitation: no boot ROM image metadata block yet

Unlike the RP2040, the RP2350 does not need a `boot2`-style second-stage
flash/XIP setup blob (its boot ROM has built-in flash support), so this
platform correctly has no `linker-scripts/section-boot2.ld` counterpart.

However, the RP2350 boot ROM does still expect a small `IMAGE_DEF`/picobin
metadata block (image type, vector-table pointer, entry-point items,
"block loop") placed immediately after the vector table, so it can locate
and validate the application on a cold flash boot. The Pico SDK normally
generates this via `pico_crt0/embedded_start_block.inc.S`
(`PICO_CRT0_INCLUDE_PICOBIN_BLOCK`, on by default for RP2350). This
platform does not yet produce that block, so while it builds and links
cleanly, a cold reset will not (yet) locate and run the application via
the normal OpenOCD `program ... verify` + `reset` flow. This is a known,
deliberately deferred follow-up.
