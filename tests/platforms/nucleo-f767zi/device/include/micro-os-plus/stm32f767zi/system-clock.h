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

#ifndef MICRO_OS_PLUS_STM32F767ZI_SYSTEM_CLOCK_H_
#define MICRO_OS_PLUS_STM32F767ZI_SYSTEM_CLOCK_H_

// ----------------------------------------------------------------------------

// This is a C++ only header (the driver is a class, not a C API); do not
// include it from C translation units.
#if defined(__cplusplus)

#include <cstdint>

namespace device
{
  // Driver bringing up the STM32F767 system clock as configured by the
  // original STM32CubeMX project (`stm32cubemx.ioc`, no longer part of
  // the build, see device/README.md): HSI (16 MHz) fed straight to
  // SYSCLK, with no PLL; implemented directly on the CMSIS
  // `RCC`/`FLASH`/`PWR` register structs (no HAL calls).
  //
  // Unlike the sibling nucleo-f411re platform, this does not raise the
  // clock anywhere near the device's maximum (216 MHz, which would
  // additionally require enabling Over-drive mode); it merely
  // reproduces, on bare registers, the modest clock tree the
  // CubeMX-generated `SystemClock_Config()` used to set up.
  class system_clock
  {
  public:
    system_clock () = default;

    system_clock (const system_clock&) = delete;
    system_clock&
    operator= (const system_clock&)
        = delete;

    ~system_clock () = default;

    // Select voltage scale 3 (sufficient for HCLK up to 144 MHz, well
    // above the 16 MHz used here), set the flash latency for that
    // frequency (0 wait states), and divide APB1 (PCLK1) by 2 (its
    // 54 MHz maximum), leaving AHB (HCLK) and APB2 (PCLK2) undivided,
    // with HSI, already running at reset, selected as the SYSCLK
    // source. Returns the resulting HCLK frequency, in Hz.
    std::uint32_t
    initialise (void);

    // Read back the clock configuration registers (RCC_CFGR) and
    // compute the current HCLK frequency, in Hz. Assumes SYSCLK is
    // sourced from HSI, as programmed by initialise().
    std::uint32_t
    clock_get_frequency_hz (void);
  };
} // namespace device

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_STM32F767ZI_SYSTEM_CLOCK_H_

// ----------------------------------------------------------------------------
