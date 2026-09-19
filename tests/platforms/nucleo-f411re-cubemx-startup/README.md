# platforms/nucleo-f411re-cubemx-startup

Note: It cannot be a static library, since it makes extensive use of `weak` symbols.

## Source files

- `src/hooks.cpp` — the `micro_os_plus_startup_post_init_array_hook`/
  `micro_os_plus_startup_finalise_hardware_hook` hooks (called from
  `micro_os_plus_startup_run_main()`/`exit()`); instantiates the
  `activity_led` (`platform::nucleo_f411re_cubemx_startup::led_green`),
  turning it on/off around the application's run. `post_init_array_hook`
  (not `initialise_hardware_hook`) is used so `activity_led` is touched
  only after its static initialiser has run; no
  `initialise_hardware_early_hook` is needed, as the CubeMX-generated
  `main()` (renamed
  `micro_os_plus_startup_initialise_hardware_hook()`, see
  `device/README.md`) already brings up the clocks and the LD2 pin.
- `src/led-green.cpp` — `platform::nucleo_f411re_cubemx_startup::led_green`
  driver for the onboard green LED (`LD2`, `PA5`), implemented on top of
  the STM32F4xx HAL's `HAL_GPIO_*()` calls, already linked in via
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
      -f target/stm32f4x.cfg \
      -c "program test.elf verify" \
      -c "arm semihosting enable" \
      -c "arm semihosting_cmdline test one two" \
      -c "reset"
```
