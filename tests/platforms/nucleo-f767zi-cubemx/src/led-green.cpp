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

// ----------------------------------------------------------------------------

#include "micro-os-plus/nucleo-f767zi-cubemx/led-green.h"

// The CMSIS/HAL headers pulled in below (transitively, via `main.h`) use
// C-style casts and, in the CMSIS core inline functions, casts that are
// useless in C but not in C++; silence both for this translation unit,
// matching `micro-os-plus/device.h`.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif // defined(__GNUC__)

// The CubeMX-generated `main.h` (STM32F7xx HAL, `#ifdef __cplusplus extern
// "C"`-wrapped); provides `LD1_Pin`/`LD1_GPIO_Port` and, transitively,
// `stm32f7xx_hal.h` for the `HAL_GPIO_*()` declarations used below.
#include "main.h"

namespace platform::nucleo_f767zi_cubemx
{
  void
  led_green::power_up (void)
  {
    // The pin's clock, mode (output push-pull) and speed are already
    // configured by the CubeMX-generated `MX_GPIO_Init()`, called from
    // `micro_os_plus_startup_initialise_hardware_hook()`; only the
    // output level needs setting here.
    HAL_GPIO_WritePin (LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
  }

  void
  led_green::turn_on (void)
  {
    // Active-high: drive the pin high to turn the LED on.
    HAL_GPIO_WritePin (LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
  }

  void
  led_green::turn_off (void)
  {
    // Active-high: drive the pin low to turn the LED off.
    HAL_GPIO_WritePin (LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
  }

  void
  led_green::toggle (void)
  {
    HAL_GPIO_TogglePin (LD1_GPIO_Port, LD1_Pin);
  }

  void
  led_green::power_down (void)
  {
    // Returns the pin to its reset (analog input, no pull) state.
    HAL_GPIO_DeInit (LD1_GPIO_Port, LD1_Pin);
  }

} // namespace platform::nucleo_f767zi_cubemx

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------
