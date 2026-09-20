/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/device.h"

// Only the Pico SDK's register-definition headers are used below (no
// SDK library is linked); they provide the peripheral bit-field names
// used to program the clocks, matching the CMSIS register structs
// already pulled in via micro-os-plus/device.h (RP2040.h).
#include "hardware/platform_defs.h"
#include "hardware/regs/clocks.h"
#include "hardware/regs/pll.h"
#include "hardware/regs/resets.h"
#include "hardware/regs/xosc.h"

// ----------------------------------------------------------------------------

// The CLOCKS/XOSC/PLL_SYS/RESETS macros below expand to C-style pointer
// casts (e.g. `((CLOCKS_Type*) CLOCKS_BASE)`); silence the resulting
// warning at each expansion site below, since micro-os-plus/device.h
// only covers casts made while parsing RP2040.h itself, not macro uses
// here.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif // defined(__GNUC__)

namespace device
{
  // After reset, the RP2040 clk_sys is left running from the
  // uncalibrated ring oscillator (ROSC). `system_clock::initialise()`
  // below brings up the crystal oscillator and the system PLL, then
  // switches clk_sys/clk_ref/clk_peri to a calibrated 125 MHz, the same
  // target the Pico SDK itself uses by default for RP2040 (see
  // PLL_SYS_VCO_FREQ_HZ/POSTDIV1/POSTDIV2 in the SDK's
  // `hardware/clocks.h` for XOSC_HZ==12 MHz && SYS_CLK_HZ==125 MHz).
  //
  // This is a trimmed, hand-ported version of the Pico SDK's own
  // `runtime_init_clocks()` (src/rp2_common/pico_runtime_init/
  // `runtime_init_clocks.c`), combined with `xosc_init()`/`pll_init()`
  // (hardware_xosc/hardware_pll). Only clk_ref, clk_sys and clk_peri
  // are configured; clk_usb/clk_adc/clk_rtc and the tick generators are
  // not used by this platform and are left at their reset state.

  // PLL_SYS: 12 MHz / 1 * 125 = 1500 MHz VCO / 6 / 2 = 125 MHz.
  static constexpr std::uint32_t pll_sys_refdiv = 1;
  static constexpr std::uint32_t pll_sys_fbdiv = 125;
  static constexpr std::uint32_t pll_sys_postdiv1 = 6;
  static constexpr std::uint32_t pll_sys_postdiv2 = 2;

  std::uint32_t
  system_clock::initialise (void)
  {
    // Disable resus, in case it was left enabled by previous software.
    CLOCKS->CLK_SYS_RESUS_CTRL = 0;

    // Bring up the crystal oscillator.
    XOSC->CTRL = XOSC_CTRL_FREQ_RANGE_VALUE_1_15MHZ;
    XOSC->STARTUP = ((XOSC_HZ / 1000) + 128) / 256;
    XOSC->CTRL |= (XOSC_CTRL_ENABLE_VALUE_ENABLE << XOSC_CTRL_ENABLE_LSB);
    while (!(XOSC->STATUS & XOSC_STATUS_STABLE_BITS))
      {
        // Busy wait for the crystal to stabilise.
      }

    // Cleanly switch clk_sys and clk_ref away from their aux sources
    // before reconfiguring the PLL and the aux muxes, to avoid
    // glitches.
    CLOCKS->CLK_SYS_CTRL &= ~CLOCKS_CLK_SYS_CTRL_SRC_BITS;
    while (CLOCKS->CLK_SYS_SELECTED != 0x1)
      {
        // Busy wait for the glitchless mux to settle on clk_ref.
      }
    CLOCKS->CLK_REF_CTRL &= ~CLOCKS_CLK_REF_CTRL_SRC_BITS;
    while (CLOCKS->CLK_REF_SELECTED != 0x1)
      {
        // Busy wait for the glitchless mux to settle on the ROSC.
      }

    // Release the system PLL from reset.
    RESETS->RESET &= ~RESETS_RESET_PLL_SYS_BITS;
    while (!(RESETS->RESET_DONE & RESETS_RESET_PLL_SYS_BITS))
      {
        // Busy wait for the reset to complete.
      }

    // Configure the system PLL for a 125 MHz clk_sys.
    PLL_SYS->CS = pll_sys_refdiv;
    PLL_SYS->FBDIV_INT = pll_sys_fbdiv;
    PLL_SYS->PWR &= ~(PLL_PWR_PD_BITS | PLL_PWR_VCOPD_BITS);
    while (!(PLL_SYS->CS & PLL_CS_LOCK_BITS))
      {
        // Busy wait for the PLL to lock.
      }
    PLL_SYS->PRIM = (pll_sys_postdiv1 << PLL_PRIM_POSTDIV1_LSB)
                    | (pll_sys_postdiv2 << PLL_PRIM_POSTDIV2_LSB);
    PLL_SYS->PWR &= ~PLL_PWR_POSTDIVPD_BITS;

    // clk_ref = XOSC, undivided.
    CLOCKS->CLK_REF_CTRL
        = (CLOCKS->CLK_REF_CTRL & ~CLOCKS_CLK_REF_CTRL_SRC_BITS)
          | (CLOCKS_CLK_REF_CTRL_SRC_VALUE_XOSC_CLKSRC
             << CLOCKS_CLK_REF_CTRL_SRC_LSB);
    while (!(CLOCKS->CLK_REF_SELECTED
             & (1u << CLOCKS_CLK_REF_CTRL_SRC_VALUE_XOSC_CLKSRC)))
      {
        // Busy wait for the glitchless mux to settle on the XOSC.
      }
    CLOCKS->CLK_REF_DIV = 1u << CLOCKS_CLK_REF_DIV_INT_LSB;

    // clk_sys = PLL_SYS, via the aux mux, undivided.
    CLOCKS->CLK_SYS_CTRL
        = (CLOCKS->CLK_SYS_CTRL & ~CLOCKS_CLK_SYS_CTRL_AUXSRC_BITS)
          | (CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS
             << CLOCKS_CLK_SYS_CTRL_AUXSRC_LSB);
    CLOCKS->CLK_SYS_CTRL
        = (CLOCKS->CLK_SYS_CTRL & ~CLOCKS_CLK_SYS_CTRL_SRC_BITS)
          | (CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX
             << CLOCKS_CLK_SYS_CTRL_SRC_LSB);
    while (!(CLOCKS->CLK_SYS_SELECTED
             & (1u << CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX)))
      {
        // Busy wait for the glitchless mux to settle on the aux
        // (PLL_SYS).
      }
    CLOCKS->CLK_SYS_DIV = 1u << CLOCKS_CLK_SYS_DIV_INT_LSB;

    // clk_peri = clk_sys, undivided; feeds the UART/SPI baud
    // generators.
    CLOCKS->CLK_PERI_CTRL = CLOCKS_CLK_PERI_CTRL_ENABLE_BITS
                            | (CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLK_SYS
                               << CLOCKS_CLK_PERI_CTRL_AUXSRC_LSB);

    return SYS_CLK_HZ;
  }

  std::uint32_t
  system_clock::clock_get_frequency_hz (void)
  {
    // Assumes clk_sys is sourced from PLL_SYS via the aux mux, as
    // programmed by initialise(); nothing else in this codebase
    // changes the source afterwards.
    std::uint32_t refdiv = PLL_SYS->CS & PLL_CS_REFDIV_BITS;
    std::uint32_t fbdiv_int = PLL_SYS->FBDIV_INT & PLL_FBDIV_INT_BITS;
    std::uint32_t postdiv1
        = (PLL_SYS->PRIM & PLL_PRIM_POSTDIV1_BITS) >> PLL_PRIM_POSTDIV1_LSB;
    std::uint32_t postdiv2
        = (PLL_SYS->PRIM & PLL_PRIM_POSTDIV2_BITS) >> PLL_PRIM_POSTDIV2_LSB;
    std::uint32_t clk_sys_div_int
        = (CLOCKS->CLK_SYS_DIV & CLOCKS_CLK_SYS_DIV_INT_BITS)
          >> CLOCKS_CLK_SYS_DIV_INT_LSB;

    std::uint32_t vco_hz = (XOSC_HZ / refdiv) * fbdiv_int;
    std::uint32_t pll_hz = vco_hz / (postdiv1 * postdiv2);
    return pll_hz / clk_sys_div_int;
  }

} // namespace device

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------
