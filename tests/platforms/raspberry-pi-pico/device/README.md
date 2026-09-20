# device/rp2040

Definitions specific to the RP2040 device.

The result is a CMake interface library `micro-os-plus::device`.

## Implementation

This folder does not link any Pico SDK CMake library. 
The reset handler, vector table, and
runtime start-up are entirely custom, implemented on top of the
`micro-os-plus::architecture` and `micro-os-plus::startup` machinery,
the same way as the other Cortex-M platforms in this project.

The only thing still taken from the Pico SDK is its bundled
CMSIS-Core/CMSIS-Device headers for the RP2040, used purely as
include folders (no sources, no libraries are linked from there).

### Pico SDK headers used

`device/CMakeLists.txt` adds, as plain include folders, the CMSIS
stub headers from the `@xpack-3rd-party/raspberrypi-pico-sdk` package:

- `.../cmsis/stub/CMSIS/Core/Include` — the standard CMSIS-Core headers
- `.../cmsis/stub/CMSIS/Device/RP2040/Include` — the RP2040 CMSIS-Device
  headers (`RP2040.h`, included by
  [include/micro-os-plus/device.h](include/micro-os-plus/device.h))

No Pico SDK CMake targets are linked, and no other Pico SDK sources
are compiled.

### Custom implementation

- [src/vectors-rp2040.c](src/vectors-rp2040.c) — the interrupt vector
  table (`_interrupt_vectors[]`) and the weak IRQ handler declarations
  for the RP2040, all aliased to `Default_Handler`; the reset handler
  itself (`Reset_Handler`) and the other Cortex-M core handlers come
  from `micro-os-plus::architecture-cortexm`.
- [src/system-rp2040.cpp](src/system-rp2040.cpp) — the CMSIS-mandated
  `SystemInit()` and `SystemCoreClockUpdate()` functions, and the
  `SystemCoreClock` variable, built only when
  `MICRO_OS_PLUS_STARTUP_ENABLED` is defined.
- [src/bs2_default_padded_checksummed.S](src/bs2_default_padded_checksummed.S) —
  a static copy of the second-stage bootloader (`boot2`) binary,
  originally built with the Pico SDK, padded and checksummed as
  required by the RP2040 boot ROM to locate and validate the
  application in flash; it is stored here as raw bytes and is not
  rebuilt from, or dependent on, the Pico SDK.
