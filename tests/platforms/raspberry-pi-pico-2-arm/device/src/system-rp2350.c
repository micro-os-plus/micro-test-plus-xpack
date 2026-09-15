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

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_STARTUP_ENABLED)

// SystemInit() below does not configure any clock (no clocks_init()
// equivalent is linked), so clk_sys is left running from the ring
// oscillator (ROSC), as documented in the Pico SDK's hardware/rosc.h:
// "RP2 chips boot from the ring oscillator initially, meaning the first
// stages of the bootrom, [...] will be clocked by the ring oscillator."
// The ROSC is not a calibrated source; its frequency depends on process,
// voltage and temperature. This value is only an approximation, carried
// over from RP2040's documented ~6.5 MHz typical default ROSC frequency
// and not verified against the RP2350 datasheet. For an accurate reading,
// call `rosc_measure_freq_khz()` (Pico SDK `hardware/rosc.h`) at runtime.
#define SYSTEM_CLOCK (6500000)
uint32_t SystemCoreClock = SYSTEM_CLOCK;

// ----------------------------------------------------------------------------

void
SystemInit (void)
{
}

void
SystemCoreClockUpdate (void)
{
  SystemCoreClock = SYSTEM_CLOCK;
}

#endif // defined(MICRO_OS_PLUS_STARTUP_ENABLED)

// ----------------------------------------------------------------------------
