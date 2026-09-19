# platforms/raspberry-pi-pico-2-arm-sdk

Support files for building Cortex-M33 tests to run on the
Raspberry Pi Pico 2 board with the
[Pico SDK](https://www.raspberrypi.com/documentation/pico-sdk/).

## Prerequisites

- [Raspberry Pi Pico 2 or Pico 2 with headers](https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html#pico2)
- [Raspberry Pi Debug Probe](https://www.raspberrypi.com/products/debug-probe/)

The **Pico 2 with headers** is a newer version, with a small 3 pin connector soldered,
which can be directly connected to the Debug Probe, without any
custom wiring.

The **Debug Probe** is a cheap SWD (Serial Wire Debug) probe, implementing
CMSIS-DAP; for best results, this probe requires a recent OpenOCD (>= 0.12),
the current Raspberry OpenOCD fork (0.11.x) is too verbose for the use with
semihosting.

An alternate setup can be a pair of Pico's (preferably the initial model,
without the debug connector soldered) and some custom wiring, with one
Pico running the [Picoprobe](https://github.com/raspberrypi/picoprobe)
firmware.

## Include folders

The following folders should be passed to the compiler during the build:

- `include`

## Source files

- `src/hooks.cpp` — the `micro_os_plus_startup_post_init_array_hook`/
  `micro_os_plus_startup_finalise_hardware_hook` hooks (called from
  `micro_os_plus_startup_run_main()`/`exit()`, see `__wrap_main()` in
  `device/src/wraps.c`); instantiates the `activity_led`
  (`platform::raspberry_pi_pico_2_arm_sdk::led_green`), turning it on/off around the
  application's run. `post_init_array_hook` (not
  `initialise_hardware_hook`) is used so `activity_led` is touched only
  after its static initialiser has run; no
  `initialise_hardware_early_hook` is needed, as the Pico SDK's own
  `pico_crt0`/`pico_runtime_init` already bring up the clocks.
- `src/led-green.cpp` — `platform::raspberry_pi_pico_2_arm_sdk::led_green` driver for the
  onboard green LED (`PICO_DEFAULT_LED_PIN`), implemented on top of the
  Pico SDK's own `hardware_gpio` driver, unlike the sibling
  raspberry-pi-pico-2-arm platform, which drives the RP2350 CMSIS
  registers directly.

## Memory range

The applications are built for the following memory range:

- FLASH: 0x1000_0000-0x103F_FFFF (4 MB)
- RAM: 0x2000_0000-0x2007_FFFF (512 KB main SRAM)
- SCRATCH: 0x2008_0000 0x2008_1FFF (two 4 KB banks)
- stack: 0x2008_2000 (top of `SCRATCH_Y`)

## Eclipse OpenOCD launcher

Main tab
C/C++ Application: absolute path to `app.elf`

Debugger tab
OpenOCD Setup
Executable path: absolute path to `openocd`
Config options:
`-f "interface/cmsis-dap.cfg"`
`-c "adapter speed 5000"`
`-f "target/rp2350.cfg"`
GDB Client Setup
Executable path: absolute path to `arm-none-eabi-gdb`
Commands:
`set mem inaccessible-by-default off`
`set remotetimeout 4000`

Startup tab
Initialization commands
`monitor arm semihosting_cmdline test one two`
Set breakpoint at: `_start`

## OpenOCD invocation

To run the tests, invoke them via OpenOCD:

```sh
openocd \
      -c "tcl port disabled" \
      -c "telnet port disabled" \
      -c "set USE_CORE 0" \
      -f "interface/cmsis-dap.cfg" \
      -c "adapter speed 5000" \
      -f "target/rp2350.cfg" \
      -c "program test.elf verify" \
      -c "arm semihosting enable" \
      -c "arm semihosting_cmdline test one two" \
      -c "reset"
```

## Links

- [Pico SDK](https://www.raspberrypi.com/documentation/pico-sdk/)
