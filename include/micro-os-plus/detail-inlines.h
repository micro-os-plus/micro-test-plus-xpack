/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from <https://opensource.org/licenses/MIT/>.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from <https://www.boost.org/LICENSE_1_0.txt>.
 */

#ifndef MICRO_TEST_PLUS_DETAIL_INLINES_H_
#define MICRO_TEST_PLUS_DETAIL_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-c++17-compat-pedantic"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  namespace detail
  {
    /**
     * @brief Internal function to evaluate the expression and
     * report the result.
     */
    template <class Expr_T>
    [[nodiscard]] bool
    evaluate_and_report_ (detail::assertion<Expr_T> assertion)
    {
      // This cast calls the bool operator, which evaluates the expression.
      if (static_cast<bool> (assertion.expr))
        {
          reporter.pass (
              detail::assertion<Expr_T>{ .expr = assertion.expr,
                                         .abort = assertion.abort,
                                         .message = assertion.message,
                                         .location = assertion.location });
          return true;
        }

      reporter.fail (
          detail::assertion<Expr_T>{ .expr = assertion.expr,
                                     .abort = assertion.abort,
                                     .message = assertion.message,
                                     .location = assertion.location });
      if (assertion.abort)
        {
          current_test_suite->end ();
          runner.abort ();
        }
      return false;
    }
  } // namespace detail
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_DETAIL_INLINES_H_

// ----------------------------------------------------------------------------
