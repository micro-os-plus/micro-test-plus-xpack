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
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

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

  /**
   * @brief Return the test result. Also trigger the execution of the
   * globally registered test suites.
   */
  [[nodiscard]] int
  exit_code (void);

  /**
   * @brief Mark a passed check.
   */
  template <class Expr_T = bool>
  constexpr auto
  pass (const char* message = "passed",
        const reflection::source_location& sl
        = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = true, .abort = false, .message = message, .location = sl });
  }

  /**
   * @brief Mark a failed check.
   */
  template <class Expr_T = bool>
  constexpr auto
  fail (const char* message = "...", const reflection::source_location& sl
                                     = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = false, .abort = false, .message = message, .location = sl });
  }

  /**
   * @brief Evaluate a generic condition. The expression must use
   * the provided `eq(), ne(), lt(), le(), gt(), ge()` comparators,
   * or, if the custom operators are used, to include custom type
   * operands, otherwise support for identifying the failed check
   * is not provided.
   *
   * The template is usable only for expressions that evaluate to
   * a boolean or use custom comparators/operators derived from the
   * local `op` type.
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
   * @brief Check a condition and, if false, abort.
   *
   * The template is usable only for expressions that evaluate to
   * a boolean or use custom comparators/operators derived from the
   * local `op` type.
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
  /**
   * @brief Check if a callable throws a specific exception.
   */
  template <class Exception_T, class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T, Exception_T>{ func };
  }

  /**
   * @brief Check if a callable throws an exception (any exception).
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T>{ func };
  }

  /**
   * @brief Check if a callable doesn't throw an exception.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  nothrow (const Callable_T& func)
  {
    return detail::nothrow_{ func };
  }
#endif

  /**
   * @brief Generic equality comparator. Matches any
   * non-pointer type.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @brief Pointer equality comparator. Matches pointers
   * to any types.
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

  /**
   * @brief Generic logical not. The underscore is intentional,
   * to differentiate from the standard operator.
   */
  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T& expr)
  {
    return detail::not_{ expr };
  }

  /**
   * @brief Generic logical and. The underscore is intentional,
   * to differentiate from the standard operator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::and_{ lhs, rhs };
  }

  /**
   * @brief Generic logical or. The underscore is intentional,
   * to differentiate from the standard operator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _or (const Lhs_T& lhs, const Rhs_T& rhs)
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

  /**
   * @brief Separate namespace with custom operators.
   *
   * @warning Please note that they
   * may interfere with other operators existing in the tested application.
   *
   * To minimise the interferences, these operators are recognised only
   * for specific types, and generally require constants to be
   * suffixed with literals (like `1_i`), and dynamic values to be
   * casted to the custom types (like `_i(...)`).
   */
  namespace operators
  {
    /**
     * @brief Equality operator for string_view objects.
     */
    [[nodiscard]] constexpr auto
    operator== (std::string_view lhs, std::string_view rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @brief Non-equality operator for string_view objects.
     */
    [[nodiscard]] constexpr auto
    operator!= (std::string_view lhs, std::string_view rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @brief Equality operator for containers.
     */
    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator== (T&& lhs, T&& rhs)
    {
      return detail::eq_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    /**
     * @brief Non-equality operator for containers.
     */
    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator!= (T&& lhs, T&& rhs)
    {
      return detail::ne_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    /**
     * @brief Equality operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator== (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @brief Non-equality operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator!= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @brief Greater than operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator> (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::gt_{ lhs, rhs };
    }

    /**
     * @brief Greater than or equal operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator>= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ge_{ lhs, rhs };
    }

    /**
     * @brief Less than operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator< (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::lt_{ lhs, rhs };
    }

    /**
     * @brief Less than or equal operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator<= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::le_{ lhs, rhs };
    }

    /**
     * @brief Logical `and` operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator and (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::and_{ lhs, rhs };
    }

    /**
     * @brief Logical `or` operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator or (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::or_{ lhs, rhs };
    }

    /**
     * @brief Logical `not` operator. It matches only if the
     * operand is of local type (derived from local `op`).
     */
    template <class T, type_traits::requires_t<type_traits::is_op_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator not (const T& t)
    {
      return detail::not_{ t };
    }
  } // namespace operators

  namespace utility
  {
    [[nodiscard]] bool
    is_match (std::string_view input, std::string_view pattern);

    template <class T, class Delim_T>
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>;

  } // namespace utility

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ===== Inline & template implementations ====================================

#include "test-suite-inlines.h"
#include "test-reporter-inlines.h"
#include "detail-inlines.h"

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------
