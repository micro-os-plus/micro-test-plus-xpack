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
 * @brief C++ source file with implementations for the µTest++ deferred
 * reporter methods.
 *
 * @details
 * This source file contains the implementation of the
 * `detail::deferred_reporter_base` class, which supports deferred
 * reporting of test expression results. The constructor captures the
 * result value, source location, and subtest reference; the destructor
 * updates the subtest counters and optionally aborts execution on
 * critical failures.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace.
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
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  namespace detail
  {
    /**
     * @details
     * Stores the evaluated Boolean @p value, the @p location identifying
     * the source line of the assertion, and a reference to the owning
     * @p subtest. The subtest's check index counter is incremented
     * immediately so that the first check is reported as check #1.
     */
    deferred_reporter_base::deferred_reporter_base (
        bool value, const reflection::source_location& location,
        subtest& subtest)
        : value_{ value }, location_{ location }, subtest_{ subtest }
    {
      // The index starts at 0, must be incremented before the first check is
      // reported, to ensure that the first check is reported as check #1.
      subtest_.increment_subtest_index ();
    }

    /**
     * @details
     * The destructor ensures that if an abort condition is set and the test
     * expression has failed, the test output is flushed and the process is
     * terminated. This mechanism guarantees immediate feedback and halts
     * further execution upon critical test failures, aiding in rapid
     * identification and resolution of issues during test runs.
     */
    deferred_reporter_base::~deferred_reporter_base ()
    {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
      trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

      if (value_) [[likely]]
        {
          subtest_.totals ().increment_successful_checks ();
        }
      else
        {
          subtest_.totals ().increment_failed_checks ();
        }

      if (abort_ && !value_) [[unlikely]]
        {
          subtest_.reporter ().write_buffer_to_stdout ();
          subtest_.reporter ().flush ();
          subtest_.abort (location_);
        }
    }

  } // namespace detail

  // ==========================================================================
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
