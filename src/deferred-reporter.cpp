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

#include "micro-os-plus/micro-test-plus/deferred-reporter.h"
#include "micro-os-plus/micro-test-plus/test.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  namespace detail
  {
    /**
     * @details
     * Stores the evaluated Boolean @p value, the @p location identifying
     * the source line of the assertion, and a reference to the owning
     * @p subtest. The check number is assigned later, by the destructor,
     * when the check is reported.
     */
    deferred_reporter_base::deferred_reporter_base (
        bool value, const reflection::source_location& location,
        subtest& subtest)
        : value_{ value }, location_{ location }, subtest_{ subtest }
    {
    }

    /**
     * @details
     * The destructor finalises the deferred reporting process for a test
     * expression, at the end of the expression statement, after all the
     * user messages were appended.
     *
     * The subtest's check index counter is incremented first, so that the
     * check numbers follow the order in which the checks are reported (the
     * first check is reported as check #1), also when the result of a check
     * is kept in a variable and reported after later checks.
     *
     * If the evaluated expression is true, the
     * reporter records a successful outcome along with any accumulated
     * message, and the successful checks counter of the subtest is
     * incremented. If the expression is false, the reporter records a
     * failure, including the abort status, message, expression, and source
     * location, and the failed checks counter is incremented.
     *
     * The expression text is obtained from the expression formatter with
     * `check_text()`, which returns the text of this check even if later
     * checks used the formatter, and is released with `end_check()`.
     *
     * If an abort condition is set and the test expression has failed, the
     * buffered test output is written to the console and flushed, and the
     * process is terminated via `runner::abort()`.
     */
    deferred_reporter_base::~deferred_reporter_base ()
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

      // The index starts at 0; it must be incremented before the check is
      // reported, so that the first check is reported as check #1.
      subtest_.increment_subtest_index ();

      // The text formatted by this check, even if the formatter was used by
      // other checks in the meantime (when this result was kept).
      auto& expression = subtest_.reporter ().expression ();
      const std::string& expression_str = expression.check_text (this);

      if (value_) [[likely]]
        {
          subtest_.reporter ().pass (deferred_output_, expression_str,
                                     subtest_);
          subtest_.totals_.increment_successful_checks ();
        }
      else
        {
          subtest_.reporter ().fail (abort_, deferred_output_, expression_str,
                                     has_expression_, location_, subtest_);
          subtest_.totals_.increment_failed_checks ();
        }

      expression.end_check (this);

      if (abort_ && !value_) [[unlikely]]
        {
          subtest_.reporter ().write_buffer_to_console ();
          subtest_.reporter ().flush ();
          subtest_.abort (location_);
        }
    }
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
