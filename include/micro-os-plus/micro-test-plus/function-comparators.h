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
 * @brief C++ header file with declarations for the µTest++ function
 * comparators.
 *
 * @details
 * This header provides the declarations for the function comparator templates
 * and logical operators used within the µTest++ framework. It defines the
 * interfaces for generic and pointer-based comparison functions, including
 * equality, non-equality, greater than, less than, greater than or equal,
 * and less than or equal. Additionally, it declares logical combinators such
 * as conjunction (`_and`), disjunction (`_or`), and negation (`_not`), as
 * well as a utility for safely removing constness from objects.
 *
 * These comparators and logical operators enable expressive and type-safe test
 * expectations and assertions, supporting both value and pointer semantics.
 * The underscore-prefixed logical operators are intentionally named to avoid
 * conflicts with standard operators and provide clear, readable test
 * expressions.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_FUNCTION_COMPARATORS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_FUNCTION_COMPARATORS_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ===========================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Generic equality comparator for non-pointer types.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return A comparator object that evaluates to true if the operands are
   * equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (const Lhs_T& lhs, const Rhs_T& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Pointer equality comparator for any pointer types.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param lhs Left hand side pointer operand.
   * @param rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the pointers are
   * equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (Lhs_T* lhs, Rhs_T* rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Generic non-equality comparator.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return A comparator object that evaluates to true if the operands are not
   * equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (const Lhs_T& lhs, const Rhs_T& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Pointer non-equality comparator.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param lhs Left hand side pointer operand.
   * @param rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the pointers are not
   * equal.
   *
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (Lhs_T* lhs, Rhs_T* rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Generic greater than comparator.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return A comparator object that evaluates to true if `lhs` is greater
   * than `rhs`.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (const Lhs_T& lhs, const Rhs_T& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Pointer greater than comparator.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param lhs Left hand side pointer operand.
   * @param rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the left hand side
   * pointer is greater than the right hand side pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (Lhs_T* lhs, Rhs_T* rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Generic greater than or equal comparator.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return A comparator object that evaluates to true if `lhs` is greater
   * than or equal to `rhs`.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (const Lhs_T& lhs, const Rhs_T& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Pointer greater than or equal comparator.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   *
   * @param lhs Left hand side pointer operand.
   * @param rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the left hand side
   * pointer is greater than or equal to the right hand side pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (Lhs_T* lhs, Rhs_T* rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Generic less than comparator.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return A comparator object that evaluates to true if `lhs` is less than
   * `rhs`.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (const Lhs_T& lhs, const Rhs_T& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Pointer less than comparator.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   *
   * @param lhs Left hand side pointer operand.
   * @param rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the left hand side
   * pointer is less than the right hand side pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (Lhs_T* lhs, Rhs_T* rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Generic less than or equal comparator.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return A comparator object that evaluates to true if `lhs` is less than
   * or equal to `rhs`.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (const Lhs_T& lhs, const Rhs_T& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Pointer less than or equal comparator.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   *
   * @param lhs Left hand side pointer operand.
   * @param rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the left hand side
   * pointer is less than or equal to the right hand side pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (Lhs_T* lhs, Rhs_T* rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **not** operation.
   *
   * @tparam Expr_T Type of the operand.
   *
   * @param expr Logical expression to be negated.
   * @return An object that evaluates to true if the operand is false.
   */
  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T& expr);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **and** operation.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return An object that evaluates to true if both operand expressions are
   * true.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T& lhs, const Rhs_T& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **or** operation.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return An object that evaluates to true if at least one of the operand
   * expressions is true.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _or (const Lhs_T& lhs, const Rhs_T& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-utility-functions
   * @brief Generic mutator to remove const qualification from any type.
   *
   * @tparam T The type of the input object.
   *
   * @param t The object from which to remove const qualification.
   * @return A non-const reference to the input object.
   */
  template <class T>
  [[nodiscard]] constexpr auto
  mut (const T& t) noexcept -> T&;

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/function-comparators-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_FUNCTION_COMPARATORS_H_

// ----------------------------------------------------------------------------
