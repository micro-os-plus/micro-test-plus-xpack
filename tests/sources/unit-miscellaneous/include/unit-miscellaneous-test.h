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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_MISCELLANEOUS_TEST_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_MISCELLANEOUS_TEST_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include "unit-common-test.h"

#include "micro-os-plus/platform.h"
#include "micro-os-plus/micro-test-plus.h"

#include <cstddef>

// ----------------------------------------------------------------------------

// The number of calls to the global allocation function, replaced in
// `allocations.cpp`, to check that the test cases do not allocate their
// bodies.
extern std::size_t allocations_count;

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_MISCELLANEOUS_TEST_H_
