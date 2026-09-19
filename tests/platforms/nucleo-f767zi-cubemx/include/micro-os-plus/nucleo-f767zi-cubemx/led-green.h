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

#ifndef MICRO_OS_PLUS_NUCLEO_F767ZI_CUBEMX_LED_GREEN_H_
#define MICRO_OS_PLUS_NUCLEO_F767ZI_CUBEMX_LED_GREEN_H_

// ----------------------------------------------------------------------------

// This is a C++ only header (the driver is a class, not a C API); do not
// include it from C translation units.
#if defined(__cplusplus)

namespace platform::nucleo_f767zi_cubemx
{
  // Driver for the Nucleo-F767ZI onboard green LED (`LD1`, `PB0`),
  // implemented on top of the STM32F7xx HAL's `hardware_gpio`-equivalent
  // driver (`stm32f7xx_hal_gpio.c`, already linked in via
  // `stm32cubemx-drivers-objects-library`), matching the approach used
  // by the sibling nucleo-f411re-cubemx platform.
  class led_green
  {
  public:
    led_green () = default;

    led_green (const led_green&) = delete;
    led_green&
    operator= (const led_green&)
        = delete;

    ~led_green () = default;

    // Drive the pin low (LED off). The pin itself (clock, mode,
    // output-push-pull) is already configured by the CubeMX-generated
    // `MX_GPIO_Init()`, called from
    // `micro_os_plus_startup_initialise_hardware_hook()` well before
    // this driver ever runs, so only the output level needs setting
    // here.
    void
    power_up (void);

    // Drive the pin high (LED on; the LED is active-high).
    void
    turn_on (void);

    // Drive the pin low (LED off; the LED is active-high).
    void
    turn_off (void);

    // Invert the current output level.
    void
    toggle (void);

    // Return the pin to its reset (analog input, no pull) state via
    // `HAL_GPIO_DeInit()`.
    void
    power_down (void);
  };
} // namespace platform::nucleo_f767zi_cubemx

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_NUCLEO_F767ZI_CUBEMX_LED_GREEN_H_

// ----------------------------------------------------------------------------
