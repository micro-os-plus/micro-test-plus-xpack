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
#include "micro-os-plus/rp2040/clock.h"

// ----------------------------------------------------------------------------

uint32_t SystemCoreClock;

// ----------------------------------------------------------------------------

void
SystemInit (void)
{
  SystemCoreClockUpdate ();
}

void
SystemCoreClockUpdate (void)
{
  SystemCoreClock = micro_os_plus_rp2040_clock_get_frequency_hz ();
}

// ----------------------------------------------------------------------------
