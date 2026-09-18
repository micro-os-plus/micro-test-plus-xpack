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

#ifndef MICRO_OS_PLUS_RP2040_CLOCK_H_
#define MICRO_OS_PLUS_RP2040_CLOCK_H_

// ----------------------------------------------------------------------------

#include <stdint.h>

#if defined(__cplusplus)
extern "C"
{
#endif // defined(__cplusplus)

  // Bring up the crystal oscillator and the system PLL, and switch
  // clk_ref/clk_sys/clk_peri from the reset-time ROSC to the resulting
  // calibrated clock. Returns the resulting clk_sys frequency, in Hz.
  uint32_t
  micro_os_plus_rp2040_clock_init (void);

  // Read back the clock configuration registers (PLL_SYS and the
  // CLK_SYS divider) and compute the current clk_sys frequency, in Hz.
  // Assumes clk_sys is sourced from PLL_SYS via the aux mux, as
  // programmed by micro_os_plus_rp2040_clock_init().
  uint32_t
  micro_os_plus_rp2040_clock_get_frequency_hz (void);

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_RP2040_CLOCK_H_

// ----------------------------------------------------------------------------
