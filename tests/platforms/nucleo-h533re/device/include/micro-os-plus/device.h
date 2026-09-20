/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2023-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

#ifndef MICRO_OS_PLUS_DEVICE_H
#define MICRO_OS_PLUS_DEVICE_H

// ----------------------------------------------------------------------------

#include "micro-os-plus/architecture.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__cplusplus)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#else
#pragma GCC diagnostic ignored "-Wnested-externs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#endif // defined(__cplusplus)
#endif // defined(__GNUC__)

#include "stm32h5xx.h"

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

#include "micro-os-plus/stm32h533re/system-clock.h"

// ----------------------------------------------------------------------------

extern device::system_clock system_clock;

// ----------------------------------------------------------------------------

#endif /* MICRO_OS_PLUS_DEVICE_H */

// ----------------------------------------------------------------------------
