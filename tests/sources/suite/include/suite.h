/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_SUITE_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_SUITE_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if __has_include(<micro-os-plus/project-config.h>)
#include <micro-os-plus/project-config.h>
#elif __has_include(<micro-os-plus/config.h>)
#pragma message \
    "micro-os-plus/config.h is deprecated, rename to micro-os-plus/project-config.h and include it instead of micro-os-plus/config.h"
#include <micro-os-plus/config.h>
#endif // __has_include(<micro-os-plus/project-config.h>)

#include <micro-os-plus/platform.h>
#include <micro-os-plus/micro-test-plus.h>

#include <string_view>
#include <stdexcept>
#include <vector>

extern micro_os_plus::micro_test_plus::static_runner sr;

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_SUITE_H_
