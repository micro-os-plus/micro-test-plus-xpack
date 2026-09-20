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

#include "micro-os-plus/device.h"

// ----------------------------------------------------------------------------

// The RCC/FLASH/PWR macros below expand to C-style pointer casts (e.g.
// `((RCC_TypeDef*) RCC_BASE)`); silence the resulting warning at each
// expansion site below, since micro-os-plus/device.h only covers casts
// made while parsing stm32f7xx.h itself, not macro uses here.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif // defined(__GNUC__)

namespace device
{
  // Nominal frequency of the clock the onboard ST-Link feeds into
  // PH0/OSC_IN; matches RCC.HSE_VALUE in stm32cubemx.ioc. Confirmed
  // working on real hardware; see system-clock.h.
  static constexpr std::uint32_t hse_hz = 16'000'000;

  std::uint32_t
  system_clock::initialise (void)
  {
    // Select voltage scale 3 (sufficient up to 144 MHz HCLK).
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR1 = (PWR->CR1 & ~PWR_CR1_VOS_Msk) | PWR_CR1_VOS_0;

    // Set the flash latency for the target HCLK (0 wait states at
    // 16 MHz); already its reset value, set explicitly for clarity.
    FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_LATENCY_Msk) | FLASH_ACR_LATENCY_0WS;

    // Bring up HSE in bypass mode (an external clock signal is being
    // fed in, not a resonator); HSEBYP may only be written while
    // HSEON is cleared, which it already is, at reset.
    RCC->CR |= RCC_CR_HSEBYP;
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY))
      {
        // Busy wait for HSE to stabilise (or, if the clock signal is
        // not actually present on this board, forever).
      }

    // AHB (HCLK) undivided (16 MHz); APB1 (PCLK1) divided by 2 (its
    // 54 MHz maximum, well above 8 MHz); APB2 (PCLK2) undivided
    // (within its 108 MHz maximum).
    RCC->CFGR
        = (RCC->CFGR
           & ~(RCC_CFGR_HPRE_Msk | RCC_CFGR_PPRE1_Msk | RCC_CFGR_PPRE2_Msk))
          | RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_PPRE2_DIV1;

    // Switch SYSCLK to HSE.
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW_Msk) | RCC_CFGR_SW_HSE;
    while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSE)
      {
        // Busy wait for the glitchless mux to settle on HSE.
      }

    return clock_get_frequency_hz ();
  }

  std::uint32_t
  system_clock::clock_get_frequency_hz (void)
  {
    // Assumes SYSCLK is sourced from HSE, as programmed by
    // initialise(); nothing else in this codebase changes the source
    // afterwards.
    static constexpr std::uint32_t hpre_shift[16]
        = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9 };
    std::uint32_t hpre = (RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos;

    return hse_hz >> hpre_shift[hpre];
  }

} // namespace device

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------
