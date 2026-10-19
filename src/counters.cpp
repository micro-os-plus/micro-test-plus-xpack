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
 * @brief C++ source file with implementations for the µTest++ counters
 * methods.
 *
 * @details
 * This source file contains the implementation of the
 * `counters::operator+=` method, which aggregates test result
 * counters from one `counters` instance into another. It
 * accumulates passed checks, failed checks, and the executed, failed,
 * and skipped test cases.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/counters.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus
{
  // ==========================================================================

  /**
   * @details
   * Adds the passed check count, failed check count, executed
   * test case count, failed test case count, and skipped test case count of
   * @p other to the corresponding members of this instance. Returns a
   * reference to `*this` to support chaining. When tracing is enabled, the updated
   * totals are output for diagnostic purposes.
   */
  counters&
  counters::operator+= (const counters& other) noexcept
  {
    passed_checks_ += other.passed_checks ();
    failed_checks_ += other.failed_checks ();
    executed_test_cases_ += other.executed_test_cases ();
    failed_test_cases_ += other.failed_test_cases ();
    skipped_test_cases_ += other.skipped_test_cases ();

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s -> +%zu -%zu in xs%zu -xs%zu\n", __PRETTY_FUNCTION__,
                   passed_checks_, failed_checks_, executed_test_cases_,
                   failed_test_cases_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    return *this;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
