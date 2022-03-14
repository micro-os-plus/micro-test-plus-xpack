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

#ifndef MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_
#define MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#if defined(MICRO_OS_PLUS_TRACE)
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_TRACE

#if defined(MICRO_OS_PLUS_DEBUG)
#define MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
#endif

#include "reflection.h"
#include "math.h"
#include "type-traits.h"
#include "literals.h"
#include "test-suite.h"
#include "test-runner.h"
#include "test-reporter.h"
#include "detail.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wmissing-include-dirs"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  class test_runner;
  class test_reporter;
  class test_suite;

  extern test_runner runner;
  extern test_reporter reporter;
  extern test_suite* current_test_suite;

  // --------------------------------------------------------------------------
  // Public API.

  /**
   * @brief Initialize the test framework.
   */
  void
  initialize (const char* name, int argc, char* argv[]);

  /**
   * @brief Define a test case.
   */
  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& func, Args_T&&... arguments);

  [[nodiscard]] int
  exit_code (void);

  template <class Expr_T = bool>
  constexpr auto
  pass (const char* message = "passed",
        const reflection::source_location& sl
        = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = true, .abort = false, .message = message, .location = sl });
  }

  template <class Expr_T = bool>
  constexpr auto
  fail (const char* message = "...", const reflection::source_location& sl
                                     = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = false, .abort = false, .message = message, .location = sl });
  }

  /**
   * @brief The generic evaluation function.
   */
  template <
      class Expr_T,
      type_traits::requires_t<
          type_traits::is_op_v<
              Expr_T> or type_traits::is_convertible_v<Expr_T, bool>> = 0>
  constexpr auto
  expect (const Expr_T& expr, const char* message = "",
          const reflection::source_location& sl
          = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = expr, .abort = false, .message = message, .location = sl });
  }

  /**
   * @brief The generic evaluation function.
   */
  template <
      class Expr_T,
      type_traits::requires_t<
          type_traits::is_op_v<
              Expr_T> or type_traits::is_convertible_v<Expr_T, bool>> = 0>
  constexpr auto
  assume (const Expr_T& expr, const char* message = "",
          const reflection::source_location& sl
          = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = expr, .abort = true, .message = message, .location = sl });
  }

#if defined(__cpp_exceptions)
  template <class Exception_T, class Expr_T>
  [[nodiscard]] constexpr auto
  throws (const Expr_T& expr)
  {
    return detail::throws_<Expr_T, Exception_T>{ expr };
  }

  template <class Expr_T>
  [[nodiscard]] constexpr auto
  throws (const Expr_T& expr)
  {
    return detail::throws_<Expr_T>{ expr };
  }

  template <class Expr_T>
  [[nodiscard]] constexpr auto
  nothrow (const Expr_T& expr)
  {
    return detail::nothrow_{ expr };
  }
#endif

  /**
   * @brief Generic equality comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @brief Pointer equality comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @brief Generic non-equality comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @brief Pointer non-equality comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @brief Generic greater than comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @brief Pointer greater than comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @brief Generic greater than or equal comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @brief Pointer greater than or equal comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @brief Generic less than comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @brief Generic less than comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @brief Generic less than or equal comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  /**
   * @brief Generic less than or equal comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T* expr)
  {
    return detail::not_{ expr };
  }

  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T& expr)
  {
    return detail::not_{ expr };
  }

  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::and_{ lhs, rhs };
  }

  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T* lhs, const Rhs_T* rhs)
  {
    return detail::and_{ lhs, rhs };
  }

  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _or (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::or_{ lhs, rhs };
  }

  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _or (const Lhs_T* lhs, const Rhs_T* rhs)
  {
    return detail::or_{ lhs, rhs };
  }

  /**
   * @brief Generic mutator, to remove const from any type.
   */
  template <class T>
  [[nodiscard]] constexpr auto
  mut (const T& t) noexcept -> T&
  {
    return const_cast<T&> (t);
  }

  // --------------------------------------------------------------------------

  namespace operators
  {
    [[nodiscard]] constexpr auto
    operator== (std::string_view lhs, std::string_view rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    [[nodiscard]] constexpr auto
    operator!= (std::string_view lhs, std::string_view rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator== (T&& lhs, T&& rhs)
    {
      return detail::eq_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator!= (T&& lhs, T&& rhs)
    {
      return detail::ne_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator== (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator!= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator> (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::gt_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator>= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ge_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator< (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::lt_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator<= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::le_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator and (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::and_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator or (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::or_{ lhs, rhs };
    }

    template <class T, type_traits::requires_t<type_traits::is_op_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator not (const T& t)
    {
      return detail::not_{ t };
    }
  } // namespace operators

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ===== Inline & template implementations ====================================

#include "test-suite-inlines.h"
#include "test-reporter-inlines.h"

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

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------
