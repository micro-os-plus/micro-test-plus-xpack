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

#ifndef MICRO_OS_PLUS_RP2350_SYSTEM_CLOCK_H_
#define MICRO_OS_PLUS_RP2350_SYSTEM_CLOCK_H_

// ----------------------------------------------------------------------------

// This is a C++ only header (the driver is a class, not a C API); do not
// include it from C translation units.
#if defined(__cplusplus)

#include <cstdint>

namespace device
{
  // Driver bringing the RP2350 system clock up to its maximum
  // frequency, implemented directly on the register offsets borrowed
  // from the Pico SDK's header-only `hardware_regs` (no SDK library
  // calls, no CMSIS/`hardware_structs` dependency -- see
  // rp2350/registers.h).
  class system_clock
  {
  public:
    system_clock () = default;

    system_clock (const system_clock&) = delete;
    system_clock&
    operator= (const system_clock&)
        = delete;

    ~system_clock () = default;

    // Bring up the crystal oscillator and the system PLL, and switch
    // clk_ref/clk_sys/clk_peri from the reset-time ROSC to the
    // resulting calibrated clock. Returns the resulting clk_sys
    // frequency, in Hz.
    std::uint32_t
    initialise (void);

    // Read back the clock configuration registers (PLL_SYS and the
    // CLK_SYS divider) and compute the current clk_sys frequency, in
    // Hz. Assumes clk_sys is sourced from PLL_SYS via the aux mux, as
    // programmed by initialise().
    std::uint32_t
    clock_get_frequency_hz (void);
  };
} // namespace device

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_RP2350_SYSTEM_CLOCK_H_

// ----------------------------------------------------------------------------
