/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2020 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 */

#if defined(__ARM_EABI__)

// ----------------------------------------------------------------------------

#include <micro-os-plus/platform.h>
#include <micro-os-plus/architecture-cortexm/exception-handlers.h>
#include <micro-os-plus/diag/trace.h>

// #include "sysclock.h"

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

void __attribute__ ((section (".after_vectors"))) SysTick_Handler (void)
{
  // sysclock.internal_increment_count ();
  HAL_IncTick ();
}

// ----------------------------------------------------------------------------

#endif /* defined(__ARM_EABI__) */

// ----------------------------------------------------------------------------
