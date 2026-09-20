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
// made while parsing stm32h5xx.h itself, not macro uses here.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif // defined(__GNUC__)

namespace device
{
  // The STM32H533 HSI oscillator's nominal (factory-trimmed) frequency;
  // matches HSI_VALUE in the CubeMX-generated stm32h5xx_hal_conf.h.
  static constexpr std::uint32_t hsi_hz = 64'000'000;

  std::uint32_t
  system_clock::initialise (void)
  {
    // Select voltage scale 3 (sufficient up to 24 MHz HCLK).
    PWR->VOSCR = (PWR->VOSCR & ~PWR_VOSCR_VOS_Msk) | PWR_VOSCR_VOS_0;
    while (!(PWR->VOSSR & PWR_VOSSR_VOSRDY))
      {
        // Busy wait for the regulator to reach the new voltage scale.
      }

    // Set the flash latency (1 wait state) and programming delay (0,
    // for flash running at up to 84 MHz) for the target HCLK (32 MHz);
    // already their reset values, set explicitly for clarity.
    FLASH->ACR
        = (FLASH->ACR & ~(FLASH_ACR_LATENCY_Msk | FLASH_ACR_WRHIGHFREQ_Msk))
          | FLASH_ACR_LATENCY_1WS;

    // HSI is already on and selected as the SYSCLK source at reset;
    // bring it up explicitly, in case some earlier code turned it off,
    // while dividing it by 2 (64 MHz -> 32 MHz).
    RCC->CR = (RCC->CR & ~RCC_CR_HSIDIV_Msk) | RCC_CR_HSIDIV_0 | RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY))
      {
        // Busy wait for HSI to stabilise.
      }

    // AHB (HCLK), APB1 (PCLK1), APB2 (PCLK2) and APB3 (PCLK3) all
    // undivided (32 MHz; well within their 250 MHz/250 MHz/250 MHz/
    // 250 MHz maxima).
    RCC->CFGR2 &= ~(RCC_CFGR2_HPRE_Msk | RCC_CFGR2_PPRE1_Msk
                    | RCC_CFGR2_PPRE2_Msk | RCC_CFGR2_PPRE3_Msk);

    // Switch SYSCLK to HSI; already the case at reset, set explicitly
    // for clarity.
    RCC->CFGR1 = (RCC->CFGR1 & ~RCC_CFGR1_SW_Msk);
    while ((RCC->CFGR1 & RCC_CFGR1_SWS_Msk) != 0U)
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
    std::uint32_t hsidiv = (RCC->CR & RCC_CR_HSIDIV_Msk) >> RCC_CR_HSIDIV_Pos;
    std::uint32_t sysclk_hz = hsi_hz >> hsidiv;

    static constexpr std::uint32_t hpre_shift[16]
        = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9 };
    std::uint32_t hpre
        = (RCC->CFGR2 & RCC_CFGR2_HPRE_Msk) >> RCC_CFGR2_HPRE_Pos;

    return sysclk_hz >> hpre_shift[hpre];
  }

} // namespace device

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------
