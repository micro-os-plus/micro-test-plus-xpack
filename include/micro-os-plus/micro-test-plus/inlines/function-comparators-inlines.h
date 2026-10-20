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
 * @brief C++ header file with inline implementations for the µTest++ function
 * comparators.
 *
 * @details
 * This header provides the inline implementations for the function comparator
 * templates used within the µTest++ framework. It defines the logic for
 * generic comparison operators, including equality,
 * non-equality, greater than, less than, and their respective logical
 * variants. Additionally, it implements logical combinators such as
 * conjunction (`both`), disjunction (`either`), and negation
 * (`negate`).
 *
 * These comparators and logical operators enable expressive and type-safe test
 * expectations and assertions; the C strings are compared by content, the
 * other pointers by address.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_FUNCTION_COMPARATORS_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_FUNCTION_COMPARATORS_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * The `eq` function template provides a generic equality comparator for any
   * types. The operands are first passed to `detail::as_operand()`, which
   * converts the C strings to `detail::c_string`, so that they are
   * compared by content. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that two values are equal. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   *
   * The operands are forwarded, so that the comparator moves the
   * temporaries and refers to the named operands, without copying them.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  eq (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::equal_to{} };
  }

  /**
   * @details
   * The `ne` function template provides a generic non-equality comparator for
   * any types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that two values are not equal. This function
   * is typically used in test expectations and assertions to compare the
   * actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  ne (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::not_equal_to{} };
  }

  /**
   * @details
   * The `gt` function template provides a generic greater than comparator for
   * any types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that one value is greater than another. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  gt (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::greater{} };
  }

  /**
   * @details
   * The `ge` function template provides a generic greater than or equal
   * comparator for any types. It constructs a comparator object that can be
   * used within the µTest++ framework to assert that one value is greater than
   * or equal to another. This function is typically used in test expectations
   * and assertions to compare the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  ge (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::greater_equal{} };
  }

  /**
   * @details
   * The `lt` function template provides a generic less than comparator for any
   * types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that one value is less than another. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  lt (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::less{} };
  }

  /**
   * @details
   * The `le` function template provides a generic less than or equal
   * comparator for any types. It constructs a comparator object that can be
   * used within the µTest++ framework to assert that one value is less than or
   * equal to another. This function is typically used in test expectations and
   * assertions to compare the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  le (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::less_equal{} };
  }

  // --------------------------------------------------------------------------
  // Logical operators.

  /**
   * @details
   * The `negate` function template provides a generic logical negation for
   * any expression type. It constructs a logical negator object that can be
   * used within the µTest++ framework to assert that a given condition is
   * false. This function is typically used in test expectations and
   * assertions to invert logical expressions or custom comparators.
   *
   * It is the function form of the `!` operator from the
   * `micro_test_plus::operators` namespace.
   */
  template <class Expr_T>
  constexpr auto
  negate (Expr_T&& expr)
  {
    return detail::not_op<detail::stored_operand_t<Expr_T>>{
      std::forward<Expr_T> (expr)
    };
  }

  /**
   * @details
   * The `both` function template provides a generic logical conjunction for
   * any expression types. It constructs a logical conjunction object that can
   * be used within the µTest++ framework to assert that both given conditions
   * are true. This function is typically used in test expectations and
   * assertions to combine logical expressions or custom comparators.
   *
   * It is the function form of the `&&` operator from the
   * `micro_test_plus::operators` namespace.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  both (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::and_op{ std::forward<Lhs_T> (lhs),
                           std::forward<Rhs_T> (rhs) };
  }

  /**
   * @details
   * The `either` function template provides a generic logical disjunction
   * for any expression types. It constructs a logical disjunction object that
   * can be used within the µTest++ framework to assert that at least one of
   * the given conditions is true. This function is typically used in test
   * expectations and assertions to combine logical expressions or custom
   * comparators.
   *
   * It is the function form of the `||` operator from the
   * `micro_test_plus::operators` namespace; the disjunction is inclusive, so
   * the result is also true when both conditions are true.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  either (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::or_op{ std::forward<Lhs_T> (lhs),
                          std::forward<Rhs_T> (rhs) };
  }

  /**
   * @details
   * Forwards to `negate()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  template <class Expr_T>
  constexpr auto
  _not (Expr_T&& expr)
  {
    return negate (std::forward<Expr_T> (expr));
  }

  /**
   * @details
   * Forwards to `both()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _and (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return both (std::forward<Lhs_T> (lhs), std::forward<Rhs_T> (rhs));
  }

  /**
   * @details
   * Forwards to `either()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _or (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return either (std::forward<Lhs_T> (lhs), std::forward<Rhs_T> (rhs));
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_FUNCTION_COMPARATORS_INLINES_H_

// ----------------------------------------------------------------------------
