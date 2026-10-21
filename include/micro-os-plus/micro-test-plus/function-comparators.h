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
 * interfaces for the generic comparison functions, including
 * equality, non-equality, greater than, less than, greater than or equal,
 * and less than or equal. Additionally, it declares logical combinators such
 * as conjunction (`both`), disjunction (`either`), and negation
 * (`negate`).
 *
 * These comparators and logical operators enable expressive and type-safe test
 * expectations and assertions. The C strings (`char` arrays, including the
 * string literals, and `char` pointers) are compared by content; the other
 * pointers and arrays are compared by address.
 * The operands are not copied: the temporaries are moved into the
 * returned expressions, and the named operands of class type are
 * referred to, so the expressions must be checked before the named
 * operands are destroyed, as they are in `expect (eq (a, b))`.
 * The logical combinators have descriptive names, since `and`, `or`, and
 * `not` are alternative tokens and cannot be used as identifiers.
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

#include "detail.h"

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
   * @brief Generic equality comparator.
   *
   * @details
   * The C strings (`char` arrays, including the string literals, and
   * `char` pointers) are compared by content, also with `std::string` and
   * `std::string_view`; a null `char` pointer is equal only to another
   * null pointer. The other pointers and arrays are compared by address.
   * The same rules apply to `ne()`, `gt()`, `ge()`, `lt()`, and `le()`.
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
  eq (Lhs_T&& lhs, Rhs_T&& rhs);

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
  ne (Lhs_T&& lhs, Rhs_T&& rhs);

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
  gt (Lhs_T&& lhs, Rhs_T&& rhs);

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
  ge (Lhs_T&& lhs, Rhs_T&& rhs);

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
  lt (Lhs_T&& lhs, Rhs_T&& rhs);

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
  le (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Approximate equality comparator, with an explicit tolerance.
   *
   * @details
   * The comparison succeeds if the distance between `lhs` and `rhs` is
   * less than `epsilon`. The operands are numbers, integral or
   * floating-point, possibly of different types, or the framework value
   * wrappers and numeric literals, whose own tolerance is not used. For
   * the integers, the distance is computed exactly, also for operands of
   * different signedness, so `approx (0u, -1, 2)` succeeds; for the other
   * types, in their common floating-point type. A failure is reported as
   * `lhs ~ (rhs +/- epsilon)`.
   *
   * @code{.cpp}
   * t.expect (mt::approx (read_adc (), 512, 3)) << "ADC reading";
   * t.expect (mt::approx (compute_float (), 42.0f, 0.001f));
   * @endcode
   *
   * The `approx (value, epsilon)` form is a value wrapper instead, which
   * applies its tolerance to the six comparisons and to the operators;
   * it accepts only floating-point values.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @tparam Epsilon_T Type of the tolerance.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @param epsilon The tolerance; a negative one fails all comparisons.
   * @return A comparator object that evaluates to true if `lhs` and `rhs`
   * differ by less than `epsilon`.
   *
   * @since 5.1.0
   */
  template <class Lhs_T, class Rhs_T, class Epsilon_T>
    requires (detail::approx_operand<Lhs_T> and detail::approx_operand<Rhs_T>
              and detail::approx_operand<Epsilon_T>)
  [[nodiscard]] constexpr auto
  approx (Lhs_T&& lhs, Rhs_T&& rhs, Epsilon_T&& epsilon);

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
  negate (Expr_T&& expr);

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
  both (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical (inclusive) **or** operation.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return An object that evaluates to true if at least one of the operand
   * expressions is true, including when both are.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  either (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **not** operation, the v5.0.1 name of
   * `negate()`.
   *
   * @details
   * The same as `negate()`. The name was changed since a leading
   * underscore is not used by the other public names.
   *
   * @deprecated Use `negate()` (since 5.1.0).
   *
   * @tparam Expr_T Type of the operand.
   *
   * @param expr Logical expression to be negated.
   * @return An object that evaluates to true if the operand is false.
   */
  template <class Expr_T>
  [[deprecated ("use negate()"), nodiscard]] constexpr auto
  _not (Expr_T&& expr);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **and** operation, the v5.0.1 name of
   * `both()`.
   *
   * @details
   * The same as `both()`. The name was changed since a leading
   * underscore is not used by the other public names.
   *
   * @deprecated Use `both()` (since 5.1.0).
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
  [[deprecated ("use both()"), nodiscard]] constexpr auto
  _and (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical (inclusive) **or** operation, the v5.0.1 name
   * of `either()`.
   *
   * @details
   * The same as `either()`. The name was changed since a leading
   * underscore is not used by the other public names.
   *
   * @deprecated Use `either()` (since 5.1.0).
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return An object that evaluates to true if at least one of the operand
   * expressions is true, including when both are.
   */
  template <class Lhs_T, class Rhs_T>
  [[deprecated ("use either()"), nodiscard]] constexpr auto
  _or (Lhs_T&& lhs, Rhs_T&& rhs);

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
