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
  extern test_suite_base* current_test_suite;

  // --------------------------------------------------------------------------
  // Public API.

  /**
   * @ingroup micro-test-plus-inits
   * @brief Initialize the test framework.
   * @param [in] argc The number of arguments.
   * @param [in] argv Array of pointers to null terminated arguments.
   * @param [in] name The name of the default test suite.
   * @par Returns
   *  Nothing.
   */
  void
  initialize (int argc, char* argv[], const char* name = "Main");

  /**
   * @ingroup micro-test-plus-inits
   * @brief Complete the test and return the exit code.
   * @par Parameters
   *	None.
   * @return 0 for success, 1 for failure.
   */
  [[nodiscard]] int
  exit_code (void);

  /**
   * @ingroup micro-test-plus-test-case
   * @brief Define and execute a test case.
   * @tparam Callable_T The type of an object that can be called.
   * @tparam Args_T The type of the callable arguments.
   * @param [in] name The test case name or description.
   * A short string used in the report.
   * @param [in] callable A generic callable object,
   * invoked to perform the test. Usually a lambda.
   * @param [in] arguments A possibly empty list of arguments to be
   * passed to the callable.
   * @par Returns
   *  Nothing.
   */
  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& callable, Args_T&&... arguments);

  /**
   * @ingroup micro-test-plus-expectations
   * @brief Evaluate a generic condition and report the results.
   * @tparam Expr_T The type of the custom expression.
   * @param [in] expr Logical expression to evaluate.
   * @param [in] sl Optional source location, by default the current line.
   * @return An output stream to write optional messages.
   *
   * @details
   * The expression can be any logical expression, but, in order to
   * allow the framework to help identify the reason why the check failed
   * (by displaying the actual vs. the expected values), the expression
   * should use the provided `eq()`, `ne()`, `lt()`, `le()`, `gt()`, `ge()`
   * comparators, or, if the custom operators namespace is included,
   * to use the custom type operands.
   *
   * The function template can be used only for expressions that evaluate to
   * a boolean or use custom comparators/operators derived from the
   * local `detail::op` type.
   *
   * For generic checks performed with standard C/C++
   *`if` statements outside the `expect()` logical expression
   * (like complex `try`/`catch` statements),
   * the results can be reported with `expect(true)` or `expect(false)`.
   *
   * @par Example
   * ```cpp
   * expect (compute_answer () == 42) << "answer is 42";
   * ```
   */
  template <class Expr_T, type_traits::requires_t<
                              type_traits::is_op_v<Expr_T>
                              or type_traits::is_convertible_v<Expr_T, bool>>
                          = 0>
  constexpr auto
  expect (const Expr_T& expr, const reflection::source_location& sl
                              = reflection::source_location::current ())
  {
    return detail::deferred_reporter<Expr_T>{ expr, false, sl };
  }

  /**
   * @ingroup micro-test-plus-assumptions
   * @brief Check a condition and, if false, abort.
   * @tparam Expr_T The type of the custom expression.
   * @param [in] expr Logical expression to evaluate.
   * @param [in] sl Optional source location, by default the current line.
   * @return An output stream to write optional messages.
   *
   * The template is usable only for expressions that evaluate to
   * a boolean or use custom comparators/operators derived from the
   * local `detail::op` type.
   *
   * @par Example
   * ```cpp
   * assert (compute_answer () == 42) << "answer is 42";
   * ```
   */
  template <class Expr_T, type_traits::requires_t<
                              type_traits::is_op_v<Expr_T>
                              or type_traits::is_convertible_v<Expr_T, bool>>
                          = 0>
  constexpr auto
  assume (const Expr_T& expr, const reflection::source_location& sl
                              = reflection::source_location::current ())
  {
    return detail::deferred_reporter<Expr_T>{ expr, true, sl };
  }

  // --------------------------------------------------------------------------

#if defined(__cpp_exceptions)
  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable throws a specific exception.
   * @tparam Exception_T Type of the exception.
   * @tparam Callable_T The type of an object that can be called.
   * @param [in] func Function to check.
   * @return An output stream to write optional messages.
   */
  template <class Exception_T, class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T, Exception_T>{ func };
  }

  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable throws an exception (any exception).
   * @tparam Callable_T The type of an object that can be called.
   * @param [in] func Function to check.
   * @return An output stream to write optional messages.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T>{ func };
  }

  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable doesn't throw an exception.
   * @tparam Callable_T The type of an object that can be called.
   * @param [in] func Function to check.
   * @return An output stream to write optional messages.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  nothrow (const Callable_T& func)
  {
    return detail::nothrow_{ func };
  }
#endif

  // --------------------------------------------------------------------------

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic equality comparator. Matches any
   * non-pointer type.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if the operands are equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer equality comparator. Matches pointers
   * to any types.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if the pointers are equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic non-equality comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if the operands are not equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer non-equality comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if the pointers are not equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic greater than comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if lhs > rhs.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer greater than comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if the lhs pointer > rhs pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic greater than or equal comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if lhs >= rhs.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer greater than or equal comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if the lhs pointer >= rhs pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic less than comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if lhs < rhs.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic less than comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if the lhs pointer < rhs pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic less than or equal comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if lhs <= rhs.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic less than or equal comparator.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if the lhs pointer <= rhs pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-logical-functions
   * @brief Generic logical **not**.
   * @tparam Expr_T Type of the operand.
   * @param [in] expr Logical expression.
   * @return True if the operand is false.
   *
   * @note
   * The underscore is intentional,
   * to differentiate from the standard operator.
   */
  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T& expr)
  {
    return detail::not_{ expr };
  }

  /**
   * @ingroup micro-test-plus-logical-functions
   * @brief Generic logical **and**.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if both operand expressions are true.
   *
   * @note
   * The underscore is intentional,
   * to differentiate from the standard operator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::and_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-logical-functions
   * @brief Generic logical **or**.
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return True if at least one of the operand expressions is true.
   *
   * @note
   * The underscore is intentional,
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
     * @ingroup micro-test-plus-strings-operators
     * @brief Equality operator for `string_view` objects.
     */
    [[nodiscard]] constexpr auto
    operator== (std::string_view lhs, std::string_view rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-strings-operators
     * @brief Non-equality operator for `string_view` objects.
     */
    [[nodiscard]] constexpr auto
    operator!= (std::string_view lhs, std::string_view rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-comparing-containers
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
     * @ingroup micro-test-plus-comparing-containers
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
     * @ingroup micro-test-plus-operators
     * @brief Equality operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator== (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Non-equality operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator!= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Greater than operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator> (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::gt_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Greater than or equal operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator>= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ge_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Less than operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator< (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::lt_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Less than or equal operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator<= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::le_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `&&` (and) operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator and (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::and_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `||` (or) operator. It matches only if at least one
     * operand is of local type (derived from local `op`).
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator or (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::or_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `!` (not) operator. It matches only if the
     * operand is of local type (derived from local `op`).
     */
    template <class T, type_traits::requires_t<type_traits::is_op_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator not(const T& t)
    {
      return detail::not_{ t };
    }
  } // namespace operators

  namespace utility
  {
    /**
     * @ingroup micro-test-plus-utility-functions
     * @brief Check if a string matches a pattern.
     * @param [in] input String view to check.
     * @param [in] pattern Sting view with the pattern.
     * @return True if the string matches the pattern.
     */
    [[nodiscard]] bool
    is_match (std::string_view input, std::string_view pattern);

    /**
     * @ingroup micro-test-plus-utility-functions
     * @brief Split a string into a vector of sub-strings.
     * @tparam T Type of the input string.
     * @tparam Delim_T Type of the delimiter.
     * @param [in] input Input string to split.
     * @param [in] delim Delimiter string.
     * @return An array of strings.
     */
    template <class T, class Delim_T>
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>;

  } // namespace utility

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ===== Inline & template implementations ====================================

#include "test-reporter-inlines.h"

// All other inlines.
#include "inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------
