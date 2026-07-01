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

#ifndef MICRO_TEST_PLUS_UNIT_TEST_H_
#define MICRO_TEST_PLUS_UNIT_TEST_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <micro-os-plus/platform.h>
#include <micro-os-plus/micro-test-plus.h>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// ----------------------------------------------------------------------------

// Mock functions used to simulate code computing various
// integer/float/strings.

template <typename T = int>
T
my_actual_integral ()
{
  return 42;
}

template <typename T = int>
T
my_actual_integral_less (void)
{
  return 41;
}

template <typename T = int>
T
my_actual_integral_more (void)
{
  return 43;
}

#if defined(__GNUC__)
#pragma GCC diagnostic push
#endif

template <typename T>
T
my_expected_integral (void)
{
  return 42;
}

template <typename T>
T
my_actual_float (void)
{
  return 42.0;
}

template <typename T>
T
my_actual_float_less (void)
{
  return 41.0;
}

template <typename T>
T
my_actual_float_more (void)
{
  return 43.0;
}

template <typename T>
T
my_expected_float (void)
{
  return 42.0;
}

// ----------------------------------------------------------------------------

// The simple way of testing a testing framework without having to resort to
// another testing framework (which might have clashing primitives),
// is to use traditional asserts. To have some minimal control and do not
// depend on NDEBUG, define a custom assert locally.

#define test_assert(EX) \
  (void)((EX) || (local_test_assert (#EX, __FILE__, __LINE__), 0))

void __attribute__ ((noreturn))
local_test_assert (const char* failedexpr, const char* file, int line);

// ----------------------------------------------------------------------------

extern micro_os_plus::micro_test_plus::static_runner tr;

// ----------------------------------------------------------------------------

// Each test case exercises a method or a family of methods.
// After each test case, the caller checks if the counts of
// passed/failed test conditions matches the local counts.

typedef struct local_counts_s
{
  int executed_subtest;
  int successful_checks;
  int failed_checks;
} local_counts_t;

extern local_counts_t local_counts;

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_UNIT_TEST_H_
