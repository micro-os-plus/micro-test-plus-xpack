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
 * @brief C++ source file with implementations for the µTest++ check
 * result methods.
 *
 * @details
 * This source file contains the non-template members of the
 * `detail::check_result` class, which reports the result of one check
 * when destroyed. The constructor captures the result value, the abort
 * status, the source location, and the test case reference; the
 * destructor updates the test case counters and, after a failed
 * `require()`, stops the test case.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/check-result.h"
#include "micro-os-plus/micro-test-plus/test.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

#include <exception>

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
     * Stores the evaluated Boolean @p value, the @p abort and
     * @p has_expression flags, the @p location identifying the source line
     * of the assertion, and a reference to the owning @p test_case. The
     * check number is assigned later, by the destructor, when the check is
     * reported.
     *
     * When exceptions are enabled, the number of uncaught exceptions is
     * also stored, so that the destructor can tell whether it runs during
     * stack unwinding.
     */
    check_result::check_result (bool value, bool abort, bool has_expression,
                                const reflection::source_location& location,
                                test_case& test_case)
        : value_{ value }, abort_{ abort }, has_expression_{ has_expression },
          location_{ location }, test_case_{ test_case }
    {
#if defined(__cpp_exceptions)
      uncaught_exceptions_ = std::uncaught_exceptions ();
#endif // defined(__cpp_exceptions)
    }

    /**
     * @details
     * The destructor reports the result of the check, at the end of the
     * expression statement, after all the user messages were appended.
     *
     * The test point number of the test case is advanced first, so that the
     * check numbers follow the order in which the checks are reported (the
     * first check is reported as check #1), also when the result of a check
     * is kept in a variable and reported after later checks.
     *
     * If the evaluated expression is true, the reporter records a
     * successful outcome along with any accumulated message, and the
     * successful checks counter of the test case is incremented. If the
     * expression is false, the reporter records a failure, including the
     * abort status, message, expression, and source location, and the
     * failed checks counter is incremented.
     *
     * The expression text is obtained from the expression formatter with
     * `check_text()`, which returns the text of this check even if later
     * checks used the formatter, and is released with `end_check()`.
     *
     * If the check is a `require()` and the test expression has failed,
     * the test case is stopped: when exceptions are enabled, by throwing
     * `failed_requirement`, caught by `test_case::run()`, as the fatal
     * assertions of most C++ test frameworks do; the run then continues
     * with the next test case. If the destructor runs during stack
     * unwinding (for a result kept in a variable), it does not throw,
     * since the test case is already being stopped.
     *
     * Without exceptions, the buffered test output is written to the
     * console and flushed, and the test execution is aborted via
     * `runner::abort()`.
     */
    check_result::~check_result () noexcept (false)
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

      // The index starts at 0; it must be incremented before the check is
      // reported, so that the first check is reported as check #1.
      test_case_.next_test_point_number ();

      // The text formatted by this check, even if the formatter was used by
      // other checks in the meantime (when this result was kept).
      auto& expression = test_case_.reporter ().expression ();
      const std::string& expression_str = expression.check_text (this);

      if (value_) [[likely]]
        {
          test_case_.reporter ().pass (message_, expression_str, test_case_);
          test_case_.totals_.increment_successful_checks ();
        }
      else
        {
          test_case_.reporter ().fail (abort_, message_, expression_str,
                                       has_expression_, location_, test_case_);
          test_case_.totals_.increment_failed_checks ();
        }

      expression.end_check (this);

      if (abort_ && !value_) [[unlikely]]
        {
#if defined(__cpp_exceptions)
          if (std::uncaught_exceptions () <= uncaught_exceptions_)
            {
              throw failed_requirement{};
            }
#else
          test_case_.reporter ().write_buffer_to_console ();
          test_case_.reporter ().flush ();
          test_case_.abort (location_);
#endif // defined(__cpp_exceptions)
        }
    }
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
