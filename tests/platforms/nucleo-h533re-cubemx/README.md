# platforms/nucleo-h533re-cubemx

Note: It cannot be a static library, since it makes extensive use of `weak` symbols.

## Source files

- `src/hooks.cpp` — the `micro_os_plus_startup_post_init_array_hook`/
  `micro_os_plus_startup_finalise_hardware_hook` hooks (called from
  `micro_os_plus_startup_run_main()`/`exit()`); instantiates the
  `activity_led` (`platform::nucleo_h533re_cubemx::led_green`), turning
  it on/off around the application's run. `post_init_array_hook` (not
  `initialise_hardware_hook`) is used so `activity_led` is touched only
  after its static initialiser has run; no
  `initialise_hardware_early_hook` is needed, as the CubeMX-generated
  `main()` (renamed
  `micro_os_plus_startup_initialise_hardware_hook()`) already brings up
  the clocks and calls `BSP_LED_Init(LED_GREEN)`/`BSP_LED_On(LED_GREEN)`
  itself; this driver only adds turning the LED off again on exit.
- `src/led-green.cpp` — `platform::nucleo_h533re_cubemx::led_green`
  driver for the onboard green LED (`LED_GREEN`, `LED2`/`PA5` on this
  Nucleo-64 board), implemented on top of the STM32H5xx Nucleo BSP's
  `BSP_LED_*()` calls, already linked in via
  `stm32cubemx-drivers-objects-library` (see `device/CMakeLists.txt`),
  unlike the sibling nucleo-f411re-cubemx/nucleo-f767zi-cubemx
  platforms, whose CubeMX projects have no BSP layer and drive
  `HAL_GPIO_*()` directly.

## OpenOCD invocation

To run the tests, invoke them via OpenOCD:

```sh
openocd \
      -c "gdb port disabled" \
      -c "tcl port disabled" \
      -c "telnet port disabled" \
      -f interface/stlink-dap.cfg \
      -c "adapter speed 5000" \
      -f target/stm32h5x.cfg \
      -c "program test.elf verify" \
      -c "arm semihosting enable" \
      -c "arm semihosting_cmdline test one two" \
      -c "reset"
```
