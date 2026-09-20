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
  // The STM32F767 HSI oscillator's nominal (factory-trimmed) frequency;
  // matches HSI_VALUE in the CubeMX-generated stm32f7xx_hal_conf.h.
  static constexpr std::uint32_t hsi_hz = 16'000'000;

  std::uint32_t
  system_clock::initialise (void)
  {
    // Select voltage scale 3 (sufficient up to 144 MHz HCLK).
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR1 = (PWR->CR1 & ~PWR_CR1_VOS_Msk) | PWR_CR1_VOS_0;

    // Set the flash latency for the target HCLK (0 wait states at
    // 16 MHz); already its reset value, set explicitly for clarity.
    FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_LATENCY_Msk) | FLASH_ACR_LATENCY_0WS;

    // HSI is already on and selected as the SYSCLK source at reset;
    // bring it up explicitly, in case some earlier code turned it off.
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY))
      {
        // Busy wait for HSI to stabilise.
      }

    // AHB (HCLK) undivided (16 MHz); APB1 (PCLK1) divided by 2 (its
    // 54 MHz maximum, well above 8 MHz); APB2 (PCLK2) undivided
    // (within its 108 MHz maximum).
    RCC->CFGR
        = (RCC->CFGR
           & ~(RCC_CFGR_HPRE_Msk | RCC_CFGR_PPRE1_Msk | RCC_CFGR_PPRE2_Msk))
          | RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_PPRE2_DIV1;

    // Switch SYSCLK to HSI; already the case at reset, set explicitly
    // for clarity.
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW_Msk) | RCC_CFGR_SW_HSI;
    while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSI)
      {
        // Busy wait for the glitchless mux to settle on HSI.
      }

    return clock_get_frequency_hz ();
  }

  std::uint32_t
  system_clock::clock_get_frequency_hz (void)
  {
    // Assumes SYSCLK is sourced from HSI, as programmed by
    // initialise(); nothing else in this codebase changes the source
    // afterwards.
    static constexpr std::uint32_t hpre_shift[16]
        = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9 };
    std::uint32_t hpre = (RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos;

    return hsi_hz >> hpre_shift[hpre];
  }

} // namespace device

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------
