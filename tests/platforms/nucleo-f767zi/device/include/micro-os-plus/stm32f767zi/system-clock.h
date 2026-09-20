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
  // Driver bringing up the STM32F767 system clock on HSE, in bypass
  // mode, rather than on the internal HSI the original STM32CubeMX
  // project (`stm32cubemx.ioc`, no longer part of the build, see
  // device/README.md) actually configures (HSI is accurate to roughly
  // ±1% over temperature; HSE, crystal-derived, is typically better
  // than ±50 ppm); implemented directly on the CMSIS `RCC`/`FLASH`/
  // `PWR` register structs (no HAL calls).
  //
  // Nucleo-F767ZI's `PH0/OSC_IN` is wired, per the `.ioc`
  // (`PH0/OSC_IN.Mode=HSE-External-Clock-Source`, `PH0/OSC_IN.
  // GPIO_Label=MCO [STM32F103CBT6_PA8]`), to receive the MCO output of
  // the onboard ST-LINK/V2-1's own STM32F103CBT6, at a nominal 16 MHz
  // (`RCC.HSE_VALUE=16000000` in the same `.ioc`) — the same
  // frequency, and the same mechanism, HSI already used here, just
  // more accurate. Confirmed working on real hardware (unlike the
  // sibling nucleo-h533re platform, where the equivalent attempt hung
  // on `HSERDY`, indicating that board's ST-Link clock does not reach
  // the target's HSE pin; F767ZI's `.ioc` at least named the actual
  // source chip/pin, which H533RE's did not).
  //
  // Unlike the sibling nucleo-f411re platform, this does not raise the
  // clock anywhere near the device's maximum (216 MHz, which would
  // additionally require enabling Over-drive mode); it merely selects
  // a more accurate clock source than the CubeMX-generated
  // `SystemClock_Config()` used, at the same, otherwise undivided,
  // frequency.
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
    // frequency (0 wait states), bring up HSE in bypass mode, and
    // switch SYSCLK to it, dividing APB1 (PCLK1) by 2 (its 54 MHz
    // maximum), leaving AHB (HCLK) and APB2 (PCLK2) undivided. Returns
    // the resulting HCLK frequency, in Hz.
    std::uint32_t
    initialise (void);

    // Read back the clock configuration register (RCC_CFGR) and
    // compute the current HCLK frequency, in Hz. Assumes SYSCLK is
    // sourced from HSE, as programmed by initialise().
    std::uint32_t
    clock_get_frequency_hz (void);
  };
} // namespace device

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_STM32F767ZI_SYSTEM_CLOCK_H_

// ----------------------------------------------------------------------------
