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
 * @brief C++ source file with implementations for the µTest++ runner
 * totals methods.
 *
 * @details
 * This source file contains the implementation of the
 * `runner_totals::operator+=` method, which aggregates test result
 * counters from one `runner_totals` instance into another. It
 * accumulates successful checks, failed checks, and executed subtests.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#if defined(MICRO_OS_PLUS_TRACE)
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_TRACE

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // ===========================================================================

  /**
   * @details
   * Adds the successful check count, failed check count, and executed
   * subtest count of @p other to the corresponding members of this
   * instance. Returns a reference to `*this` to support chaining.
   * When tracing is enabled, the updated totals are output for
   * diagnostic purposes.
   */
  runner_totals&
  runner_totals::operator+= (const runner_totals& other) noexcept
  {
    successful_checks_ += other.successful_checks ();
    failed_checks_ += other.failed_checks ();
    executed_subtests_ += other.executed_subtests ();

#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s -> +%zu -%zu in xs%zu\n", __PRETTY_FUNCTION__,
                   successful_checks_, failed_checks_, executed_subtests_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    return *this;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
