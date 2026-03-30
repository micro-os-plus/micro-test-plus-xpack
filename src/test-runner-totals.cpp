/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ source file with implementations for the µTest++ test runner
 * methods.
 *
 * @details
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#include <stdio.h>
// #include <stdlib.h>
// #include <vector>

// ----------------------------------------------------------------------------

// #pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
// #pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
// #pragma clang diagnostic ignored "-Wunknown-warning-option"
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus2
{
  // ===========================================================================

  test_runner_totals&
  test_runner_totals::operator+= (const test_runner_totals& other)
  {
    successful_checks_ += other.successful_checks ();
    failed_checks_ += other.failed_checks ();
    executed_test_cases_ += other.executed_test_cases ();

#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s -> s%zu f%zu c%zu\n", __PRETTY_FUNCTION__, successful_checks_,
            failed_checks_, executed_test_cases_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    return *this;
  }

  bool
  test_runner_totals::was_successful (void) const
  {
    // Initially it also failed if there were no checks, but it is more
    // intuitive to consider it successful if there were no checks, as it did
    // not fail any check.
    return failed_checks_ == 0;
  }

  [[nodiscard]] bool
  test_runner_totals::is_unused (void) const
  {
    return failed_checks_ == 0 && successful_checks_ == 0
           && executed_test_cases_ == 0;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus2

// ----------------------------------------------------------------------------
