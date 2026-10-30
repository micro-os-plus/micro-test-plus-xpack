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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_CHECKS_TEST_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_CHECKS_TEST_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include "unit-common-test.h"

#include "micro-os-plus/platform.h"
#include "micro-os-plus/micro-test-plus.h"

#include <cstddef>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

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
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

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

// The checks tests are split in two functions, so that a driver can run them
// around its own `run_suites()` call.

// Run the test cases of the top suite; must be called before `run_suites()`.
void
unit_checks_run_tests (micro_os_plus::micro_test_plus::suite& ts);

// Check the state of the session after `run_suites()` returned `code`.
void
unit_checks_verify_session (
    int argc, char* argv[], micro_os_plus::micro_test_plus::suite& ts,
    int code);

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_CHECKS_TEST_H_
