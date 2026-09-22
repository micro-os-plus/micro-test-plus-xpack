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
#include "micro-os-plus/rp2350/registers.h"

// Only the Pico SDK's register-definition headers are used below (no SDK
// library is linked, and no `hardware_structs`/CMSIS dependency -- see
// rp2350/registers.h); they provide the peripheral base addresses and
// bit-field names used to program the clocks.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wundef" // PICO_RP2350A, only used by the
// SDK's own CMake build.
#endif // defined(__GNUC__)
#include "hardware/platform_defs.h"
#include "hardware/regs/addressmap.h"
#include "hardware/regs/clocks.h"
#include "hardware/regs/pll.h"
#include "hardware/regs/resets.h"
#include "hardware/regs/xosc.h"
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

namespace device
{
  // After reset, the RP2350 clk_sys is left running from the
  // uncalibrated ring oscillator (ROSC). `system_clock::initialise()`
  // below brings up the crystal oscillator and the system PLL, then
  // switches clk_sys/clk_ref/clk_peri to a calibrated 150 MHz, the same
  // target the Pico SDK itself uses by default for RP2350 (see
  // PLL_SYS_VCO_FREQ_HZ/POSTDIV1/POSTDIV2 in the SDK's
  // `hardware/clocks.h` for XOSC_HZ==12 MHz && SYS_CLK_HZ==150 MHz).
  //
  // This is a trimmed, hand-ported version of the Pico SDK's own
  // `runtime_init_clocks()` (src/rp2_common/pico_runtime_init/
  // `runtime_init_clocks.c`), combined with `xosc_init()`/`pll_init()`
  // (hardware_xosc/hardware_pll), identical in substance to the sibling
  // ARM platform's `device/rp2350/src/system-clock.cpp`, only ported
  // from CMSIS struct access (`XOSC->...`) to the plain register-offset
  // accessor `RP2350_REG32()` (rp2350/registers.h). Only clk_ref,
  // clk_sys and clk_peri are configured; clk_usb/clk_adc/clk_hstx/
  // clk_rtc and the tick generators are not used by this platform and
  // are left at their reset state.

  // PLL_SYS: 12 MHz / 1 * 125 = 1500 MHz VCO / 5 / 2 = 150 MHz.
  static constexpr std::uint32_t pll_sys_refdiv = 1;
  static constexpr std::uint32_t pll_sys_fbdiv = 125;
  static constexpr std::uint32_t pll_sys_postdiv1 = 5;
  static constexpr std::uint32_t pll_sys_postdiv2 = 2;

  std::uint32_t
  system_clock::initialise (void)
  {
    // Disable resus, in case it was left enabled by previous software.
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_RESUS_CTRL_OFFSET) = 0;

    // Bring up the crystal oscillator.
    RP2350_REG32 (XOSC_BASE, XOSC_CTRL_OFFSET)
        = XOSC_CTRL_FREQ_RANGE_VALUE_1_15MHZ;
    RP2350_REG32 (XOSC_BASE, XOSC_STARTUP_OFFSET)
        = ((XOSC_HZ / 1000) + 128) / 256;
    RP2350_REG32 (XOSC_BASE, XOSC_CTRL_OFFSET)
        |= (XOSC_CTRL_ENABLE_VALUE_ENABLE << XOSC_CTRL_ENABLE_LSB);
    while (!(RP2350_REG32 (XOSC_BASE, XOSC_STATUS_OFFSET)
             & XOSC_STATUS_STABLE_BITS))
      {
        // Busy wait for the crystal to stabilise.
      }

    // Cleanly switch clk_sys and clk_ref away from their aux sources
    // before reconfiguring the PLL and the aux muxes, to avoid
    // glitches.
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_CTRL_OFFSET)
        &= ~CLOCKS_CLK_SYS_CTRL_SRC_BITS;
    while (RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_SELECTED_OFFSET) != 0x1)
      {
        // Busy wait for the glitchless mux to settle on clk_ref.
      }
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_REF_CTRL_OFFSET)
        &= ~CLOCKS_CLK_REF_CTRL_SRC_BITS;
    while (RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_REF_SELECTED_OFFSET) != 0x1)
      {
        // Busy wait for the glitchless mux to settle on the ROSC.
      }

    // Release the system PLL from reset.
    RP2350_REG32 (RESETS_BASE, RESETS_RESET_OFFSET)
        &= ~RESETS_RESET_PLL_SYS_BITS;
    while (!(RP2350_REG32 (RESETS_BASE, RESETS_RESET_DONE_OFFSET)
             & RESETS_RESET_PLL_SYS_BITS))
      {
        // Busy wait for the reset to complete.
      }

    // Configure the system PLL for a 150 MHz clk_sys.
    RP2350_REG32 (PLL_SYS_BASE, PLL_CS_OFFSET) = pll_sys_refdiv;
    RP2350_REG32 (PLL_SYS_BASE, PLL_FBDIV_INT_OFFSET) = pll_sys_fbdiv;
    RP2350_REG32 (PLL_SYS_BASE, PLL_PWR_OFFSET)
        &= ~(PLL_PWR_PD_BITS | PLL_PWR_VCOPD_BITS);
    while (!(RP2350_REG32 (PLL_SYS_BASE, PLL_CS_OFFSET) & PLL_CS_LOCK_BITS))
      {
        // Busy wait for the PLL to lock.
      }
    RP2350_REG32 (PLL_SYS_BASE, PLL_PRIM_OFFSET)
        = (pll_sys_postdiv1 << PLL_PRIM_POSTDIV1_LSB)
          | (pll_sys_postdiv2 << PLL_PRIM_POSTDIV2_LSB);
    RP2350_REG32 (PLL_SYS_BASE, PLL_PWR_OFFSET) &= ~PLL_PWR_POSTDIVPD_BITS;

    // clk_ref = XOSC, undivided.
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_REF_CTRL_OFFSET)
        = (RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_REF_CTRL_OFFSET)
           & ~CLOCKS_CLK_REF_CTRL_SRC_BITS)
          | (CLOCKS_CLK_REF_CTRL_SRC_VALUE_XOSC_CLKSRC
             << CLOCKS_CLK_REF_CTRL_SRC_LSB);
    while (!(RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_REF_SELECTED_OFFSET)
             & (1u << CLOCKS_CLK_REF_CTRL_SRC_VALUE_XOSC_CLKSRC)))
      {
        // Busy wait for the glitchless mux to settle on the XOSC.
      }
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_REF_DIV_OFFSET)
        = 1u << CLOCKS_CLK_REF_DIV_INT_LSB;

    // clk_sys = PLL_SYS, via the aux mux, undivided.
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_CTRL_OFFSET)
        = (RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_CTRL_OFFSET)
           & ~CLOCKS_CLK_SYS_CTRL_AUXSRC_BITS)
          | (CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS
             << CLOCKS_CLK_SYS_CTRL_AUXSRC_LSB);
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_CTRL_OFFSET)
        = (RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_CTRL_OFFSET)
           & ~CLOCKS_CLK_SYS_CTRL_SRC_BITS)
          | (CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX
             << CLOCKS_CLK_SYS_CTRL_SRC_LSB);
    while (!(RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_SELECTED_OFFSET)
             & (1u << CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX)))
      {
        // Busy wait for the glitchless mux to settle on the aux
        // (PLL_SYS).
      }
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_DIV_OFFSET)
        = 1u << CLOCKS_CLK_SYS_DIV_INT_LSB;

    // clk_peri = clk_sys, undivided; feeds the UART/SPI baud
    // generators.
    RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_PERI_CTRL_OFFSET)
        = CLOCKS_CLK_PERI_CTRL_ENABLE_BITS
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
    std::uint32_t refdiv
        = RP2350_REG32 (PLL_SYS_BASE, PLL_CS_OFFSET) & PLL_CS_REFDIV_BITS;
    std::uint32_t fbdiv_int = RP2350_REG32 (PLL_SYS_BASE, PLL_FBDIV_INT_OFFSET)
                              & PLL_FBDIV_INT_BITS;
    std::uint32_t postdiv1
        = (RP2350_REG32 (PLL_SYS_BASE, PLL_PRIM_OFFSET)
           & PLL_PRIM_POSTDIV1_BITS)
          >> PLL_PRIM_POSTDIV1_LSB;
    std::uint32_t postdiv2
        = (RP2350_REG32 (PLL_SYS_BASE, PLL_PRIM_OFFSET)
           & PLL_PRIM_POSTDIV2_BITS)
          >> PLL_PRIM_POSTDIV2_LSB;
    std::uint32_t clk_sys_div_int
        = (RP2350_REG32 (CLOCKS_BASE, CLOCKS_CLK_SYS_DIV_OFFSET)
           & CLOCKS_CLK_SYS_DIV_INT_BITS)
          >> CLOCKS_CLK_SYS_DIV_INT_LSB;

    std::uint32_t vco_hz = (XOSC_HZ / refdiv) * fbdiv_int;
    std::uint32_t pll_hz = vco_hz / (postdiv1 * postdiv2);
    return pll_hz / clk_sys_div_int;
  }

} // namespace device

// The global instance declared `extern` in micro-os-plus/device.h; stateless
// (no data members), so it is safe to use from
// micro_os_plus_startup_initialise_hardware_early_hook() before bss is
// initialised.
device::system_clock system_clock;

// ----------------------------------------------------------------------------
