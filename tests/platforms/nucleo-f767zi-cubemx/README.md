# platforms/nucleo-f767zi-cubemx

Note: It cannot be a static library, since it makes extensive use of `weak` symbols.

## Source files

- `src/hooks.cpp` — the `micro_os_plus_startup_post_init_array_hook`/
  `micro_os_plus_startup_finalise_hardware_hook` hooks (called from
  `micro_os_plus_startup_run_main()`/`exit()`); instantiates the
  `activity_led` (`platform::led_green`), turning
  it on/off around the application's run. `led_green` has no data
  members and a trivial default constructor, so there is no actual
  ordering hazard; `post_init_array_hook` is used simply as the
  conventional point, once the C++ runtime is fully up, to touch
  peripherals. No `initialise_hardware_early_hook` is needed, as the
  CubeMX-generated
  `main()` (renamed
  `micro_os_plus_startup_initialise_hardware_hook()`, see
  `device/README.md`) already brings up the clocks and the LD1 pin.
- `src/led-green.cpp` — `platform::led_green`
  driver for the onboard green LED (`LD1`, `PB0`), implemented on top of
  the STM32F7xx HAL's `HAL_GPIO_*()` calls, already linked in via
  `stm32cubemx-drivers-objects-library` (see `device/CMakeLists.txt`).

## OpenOCD invocation

To run the tests, invoke them via OpenOCD:

```sh
openocd \
      -c "gdb port disabled" \
      -c "tcl port disabled" \
      -c "telnet port disabled" \
      -f interface/stlink-dap.cfg \
      -c "adapter speed 5000" \
      -f target/stm32f7x.cfg \
      -c "program test.elf verify" \
      -c "arm semihosting enable" \
      -c "arm semihosting_cmdline test one two" \
      -c "reset"
```
