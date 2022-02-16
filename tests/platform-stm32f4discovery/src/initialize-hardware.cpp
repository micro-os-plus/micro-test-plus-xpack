/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2017 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 */

#if defined(__ARM_EABI__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/platform.h>
#include <micro-os-plus/startup/hooks.h>

// ----------------------------------------------------------------------------

#if 0
// Called early, before copying .data and clearing .bss.
// Should initialize the clocks and possible other RAM areas.
void
micro_os_plus_startup_initialize_hardware_early (void)
{
  // None so far.
}
#endif

#pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wsign-conversion"

extern "C"
{
  void
  SystemClock_Config (void);
  void
  MX_GPIO_Init (void);
}

// Called before running the static constructors.
void
micro_os_plus_startup_initialize_hardware (void)
{
  // Initialise the HAL Library; it must be the first function
  // to be executed before the call of any HAL function.
  HAL_Init ();

  // Enable HSE Oscillator and activate PLL with HSE as source
  SystemClock_Config ();

  // Call the CSMSIS system clock routine to store the clock frequency
  // in the SystemCoreClock global RAM location.
  SystemCoreClockUpdate ();

  // Initialize all configured peripherals.
  MX_GPIO_Init ();

  HAL_SYSTICK_Config (HAL_RCC_GetHCLKFreq () / 1000);

  HAL_SYSTICK_CLKSourceConfig (SYSTICK_CLKSOURCE_HCLK);
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

#endif /* defined(__ARM_EABI__) */

// ----------------------------------------------------------------------------
