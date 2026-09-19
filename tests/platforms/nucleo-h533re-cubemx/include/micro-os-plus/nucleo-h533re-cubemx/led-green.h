/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

#ifndef MICRO_OS_PLUS_NUCLEO_H533RE_CUBEMX_LED_GREEN_H_
#define MICRO_OS_PLUS_NUCLEO_H533RE_CUBEMX_LED_GREEN_H_

// ----------------------------------------------------------------------------

// This is a C++ only header (the driver is a class, not a C API); do not
// include it from C translation units.
#if defined(__cplusplus)

namespace platform::nucleo_h533re_cubemx
{
  // Driver for the Nucleo-H533RE onboard green LED (`LED_GREEN`,
  // `LED2`, `PA5` on this Nucleo-64 board; the BSP maps `LED_GREEN` to
  // a different LED/pin on Nucleo-144 boards), implemented on top of
  // the STM32H5xx Nucleo BSP's
  // `BSP_LED_*()` calls (`stm32h5xx_nucleo.c`, already linked in via
  // `stm32cubemx-drivers-objects-library`), unlike the sibling
  // nucleo-f411re-cubemx/nucleo-f767zi-cubemx platforms, whose CubeMX
  // projects have no BSP layer and drive `HAL_GPIO_*()` directly. This
  // is the same BSP the CubeMX-generated `main()` itself already calls
  // (`BSP_LED_Init(LED_GREEN)`/`BSP_LED_On(LED_GREEN)`) to light the
  // LED at boot; this driver only adds turning it off again on exit.
  class led_green
  {
  public:
    led_green () = default;

    led_green (const led_green&) = delete;
    led_green&
    operator= (const led_green&)
        = delete;

    ~led_green () = default;

    // Configure the pin via `BSP_LED_Init()`. Harmless to call again
    // even though the CubeMX-generated
    // `micro_os_plus_startup_initialise_hardware_hook()` (renamed
    // `main()`) already did so before this driver ever runs.
    void
    power_up (void);

    // Turn the LED on via `BSP_LED_On()`.
    void
    turn_on (void);

    // Turn the LED off via `BSP_LED_Off()`.
    void
    turn_off (void);

    // Invert the current output level via `BSP_LED_Toggle()`.
    void
    toggle (void);

    // Return the pin to its reset state via `BSP_LED_DeInit()`.
    void
    power_down (void);
  };
} // namespace platform::nucleo_h533re_cubemx

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_NUCLEO_H533RE_CUBEMX_LED_GREEN_H_

// ----------------------------------------------------------------------------
