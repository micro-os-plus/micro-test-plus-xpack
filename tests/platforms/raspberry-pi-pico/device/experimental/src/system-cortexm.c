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

#define SYSTEM_CLOCK (16000000UL)
uint32_t SystemCoreClock = SYSTEM_CLOCK;

// ----------------------------------------------------------------------------

void
SystemInit (void)
{
  // FPU settings
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
  // set CP10 and CP11 Full Access
  SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));
#endif // (__FPU_PRESENT == 1) && (__FPU_USED == 1)
}

void
SystemCoreClockUpdate (void)
{
  SystemCoreClock = SYSTEM_CLOCK;
}

#endif // defined(MICRO_OS_PLUS_STARTUP_ENABLED)

// ----------------------------------------------------------------------------
