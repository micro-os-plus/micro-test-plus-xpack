# platforms/qemu-cortex-m3

> DO NOT EDIT! Automatically generated from template file:
> build-helper/templates/common/\_micro-os-plus/tests/platforms/qemu-cortex-m33/README-liquid.md

Support files for building Cortex-M33 application to run on the
QEMU "mps2-an505" emulated board (which is a Cortex-M33 board).

## Include folders

The following folders should be passed to the compiler during the build:

- `include`

The header files to be included in user projects are:

```cpp
#include "micro-os-plus/platform.h"
```

## Source files

The source files to be added to user projects are:

- none

## Memory range

The applications are built for the following memory range:

- FLASH: 0x1000_0000-0x100F_FFFF (1 MB)
- RAM: 0x1010_0000-0x103F_FFFF (3 MB)
- HEAP: TBD
- stack: 0x1040_0000

The heap and stack are set automatically in `_startup()` to the values
returned by `SEMIHOSTING_SYS_HEAPINFO`.

## QEMU invocation

To run tests, pass the ELF file and the arguments:

```sh
qemu-system-arm --machine mps2-an505 --cpu cortex-m33 --nographic -d unimp,guest_errors --kernel "unit-test.elf" --semihosting-config enable=on,target=native,arg=unit-test,arg=--reporter,arg=human
```

For debug sessions start QEMU in GDB server mode by passing both `-s -S`:

```sh
qemu-system-arm --machine mps2-an505 --cpu cortex-m33 --nographic -d unimp,guest_errors -s -S --semihosting-config enable=on,target=native,arg=unit-test,arg=--reporter,arg=human
```

## Links

- [QEMU Arm](https://www.qemu.org/docs/master/system/target-arm.html)
- [Arm MPS2 and MPS3 boards](https://www.qemu.org/docs/master/system/arm/mps2.html)
- [CMSIS-Zone](https://arm-software.github.io/CMSIS_5/Zone/html/index.html)
- [Cortex-M33 IoT Subsystem FPGA image for the V2M-MPS2+ prototyping platform](https://github.com/Introduction-To-System-On-Chip/QEMU_an505)

Arm Application Note AN505 defines the
[Cortex-M33 IoT Subsystem FPGA image for the V2M-MPS2+ prototyping platform](https://github.com/Introduction-To-System-On-Chip/QEMU_an505),
serving as a reference for evaluating Armv8-M TrustZone technology.

The specification, which outlines a processor core with Secure and
Non-Secure memory mapping, is widely supported in QEMU, Arm Virtual
Hardware, and the Zephyr RTOS, facilitating development without physical
hardware.

Detailed technical specifications and source files are available
at the [Arm AN505 Download Page](https://support.arm.com/downloads/view/AN505).
