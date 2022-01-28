# platform-qemu-mps2-an386

Support files for building application to run on the "QEMU mps2-an386"
emulated board.

Apart from the CMake and meson configurations, there are only a few
files, with minimal content:

- `include/micro-os-plus/config.h`
- `include/micro-os-plus/platform.h`
- `src/initialize-hardware.cpp`
- `src/interrupt-handlers.cpp`
