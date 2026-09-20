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

// system_RP2040.h (pulled in via micro-os-plus/device.h, RP2040.h) declares
// SystemCoreClock/SystemInit/SystemCoreClockUpdate inside its own
// `#ifdef __cplusplus extern "C"` block, so the definitions below must be
// given matching C language linkage.
extern "C" uint32_t SystemCoreClock;
uint32_t SystemCoreClock;

// A private instance, used only to read back the clock configuration;
// distinct from the one `src/hooks.cpp` uses to bring the clock up in
// `micro_os_plus_startup_initialise_hardware_early_hook()`, since
// `device::system_clock` carries no state of its own.
device::system_clock system_clock;

extern "C" void
SystemInit (void)
{
  SystemCoreClockUpdate ();
}

extern "C" void
SystemCoreClockUpdate (void)
{
  SystemCoreClock = system_clock.clock_get_frequency_hz ();
}

// ----------------------------------------------------------------------------
