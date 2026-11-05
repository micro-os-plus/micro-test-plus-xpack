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

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ source file with implementations for the µTest++ check
 * result member functions.
 *
 * @details
 * This source file contains the non-template members of the
 * `detail::check_result` class, which reports the result of one check
 * when destroyed. The constructor captures the result value, the kind of
 * the check, the source location, and the test case reference; the
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
     * The members have their initial values: the result is not initialised,
     * has no test case, and its destructor reports nothing.
     */
    check_result::check_result (void) = default;

    /**
     * @details
     * Stores the evaluated Boolean @p value, and, in the failure details,
     * the @p kind of the check, the @p has_expression flag, and the
     * @p location identifying the source line of the check, with an
     * empty message; it also stores a pointer to the owning
     * @p test_case, which marks the result as initialised. The outcome is
     * written when the check failed, or when the reporter writes the passed
     * checks (@p writes_passed). The check number is assigned later, by the
     * destructor, when the check is reported.
     *
     * When exceptions are enabled, the number of uncaught exceptions is
     * also stored, so that the destructor can tell whether it runs during
     * stack unwinding.
     */
    void
    check_result::start (bool value, check_kind kind, bool has_expression,
                         const reflection::source_location& location,
                         test_case& test_case, bool writes_passed)
    {
      value_ = value;
      is_written_ = !value || writes_passed;
      info_ = failure_info{ kind, {}, has_expression, location };
      test_case_ = &test_case;
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
     * first check is reported as check #1), also when a check is reported
     * after checks that began later, such as those made by a function called
     * in its arguments.
     *
     * If the evaluated expression is true, the reporter records a
     * successful outcome along with any accumulated message, or, if it
     * does not write the passed checks, only the test point, with
     * `reporter::pass_without_text()`, and the passed checks counter of
     * the test case is incremented. If the expression is false, the
     * reporter records a failure, with the failure details (the kind of
     * the check, the message, and the source location) and the
     * expression, and the failed checks counter is incremented.
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
     * unwinding (caused by an exception thrown while the rest of the
     * statement is evaluated, such as by the argument of a message), it
     * does not throw, since the test case is already being stopped.
     *
     * Without exceptions, the test execution is aborted via the runner,
     * whose reporter writes the buffered test output, in place of the
     * `end_test_case()` that is never reached (see `runner::abort()`).
     */
    check_result::~check_result () noexcept (false)
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

      // A result that was not initialised, such as a default argument
      // whose function did not run, reports nothing.
      if (test_case_ == nullptr) [[unlikely]]
        {
          return;
        }

      // The index starts at 0; it must be incremented before the check is
      // reported, so that the first check is reported as check #1.
      test_case_->next_test_point_number ();

      // The text formatted by this check, even if the formatter was used by
      // other checks in the meantime (when this result was kept).
      auto& expression = test_case_->test_reporter ().expression_;
      const std::string& expression_str = expression.check_text (this);

      if (value_) [[likely]]
        {
          if (is_written_)
            {
              test_case_->test_reporter ().pass (info_.message, expression_str,
                                                 *test_case_);
            }
          else
            {
              test_case_->test_reporter ().pass_without_text (*test_case_);
            }
          test_case_->totals_.increment_passed_checks ();
        }
      else
        {
          test_case_->test_reporter ().fail (info_, expression_str,
                                             *test_case_);
          test_case_->totals_.increment_failed_checks ();
        }

      expression.end_check (this);

      if (info_.kind == check_kind::requirement && !value_) [[unlikely]]
        {
#if defined(__cpp_exceptions)
          if (std::uncaught_exceptions () <= uncaught_exceptions_)
            {
              throw failed_requirement{};
            }
#else
          test_case_->abort (info_.location);
#endif // defined(__cpp_exceptions)
        }
    }
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
