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
 * generic comparison functions, including equality, non-equality, greater
 * than, less than, greater than or equal, less than or equal, and the
 * approximate comparison. Additionally, it implements logical combinators
 * such as
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
   * compared by content. It constructs a comparator object, with the
   * `detail::equal_to` tag, which evaluates to `true` if the two values are
   * equal, and which is reported with both values if not.
   *
   * The operands are forwarded, so that the comparator moves the
   * temporaries and refers to the named operands, without copying them.
   */
  template <class Lhs_T, class Rhs_T>
    requires (extension::printable<Lhs_T> and extension::printable<Rhs_T>)
  constexpr auto
  eq (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::equal_to{} };
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings are compared by content. It constructs a comparator object,
   * with the `detail::not_equal_to` tag, which evaluates to `true` if the two
   * values are not equal, and which is reported with both values if not.
   */
  template <class Lhs_T, class Rhs_T>
    requires (extension::printable<Lhs_T> and extension::printable<Rhs_T>)
  constexpr auto
  ne (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::not_equal_to{} };
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings are compared by content. It constructs a comparator object,
   * with the `detail::greater` tag, which evaluates to `true` if `lhs` is
   * greater than `rhs`, and which is reported with both values if not.
   */
  template <class Lhs_T, class Rhs_T>
    requires (extension::printable<Lhs_T> and extension::printable<Rhs_T>)
  constexpr auto
  gt (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::greater{} };
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings are compared by content. It constructs a comparator object,
   * with the `detail::greater_equal` tag, which evaluates to `true` if `lhs`
   * is greater than or equal to `rhs`, and which is reported with both values
   * if not.
   */
  template <class Lhs_T, class Rhs_T>
    requires (extension::printable<Lhs_T> and extension::printable<Rhs_T>)
  constexpr auto
  ge (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::greater_equal{} };
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings are compared by content. It constructs a comparator object,
   * with the `detail::less` tag, which evaluates to `true` if `lhs` is less
   * than `rhs`, and which is reported with both values if not.
   */
  template <class Lhs_T, class Rhs_T>
    requires (extension::printable<Lhs_T> and extension::printable<Rhs_T>)
  constexpr auto
  lt (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::less{} };
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings are compared by content. It constructs a comparator object,
   * with the `detail::less_equal` tag, which evaluates to `true` if `lhs` is
   * less than or equal to `rhs`, and which is reported with both values if
   * not.
   */
  template <class Lhs_T, class Rhs_T>
    requires (extension::printable<Lhs_T> and extension::printable<Rhs_T>)
  constexpr auto
  le (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::less_equal{} };
  }

  /**
   * @details
   * The `approx` function template constructs a `detail::approx_op`
   * from the forwarded operands and tolerance; the operands are numbers,
   * so `detail::as_operand()`, which converts the C strings, is not
   * needed.
   */
  template <class Lhs_T, class Rhs_T, class Epsilon_T>
    requires (detail::approx_operand<Lhs_T> and detail::approx_operand<Rhs_T>
              and detail::approx_operand<Epsilon_T>)
  constexpr auto
  approx (Lhs_T&& lhs, Rhs_T&& rhs, Epsilon_T&& epsilon)
  {
    return detail::approx_op{ std::forward<Lhs_T> (lhs),
                              std::forward<Rhs_T> (rhs),
                              std::forward<Epsilon_T> (epsilon) };
  }

  // --------------------------------------------------------------------------
  // Logical operators.

  /**
   * @details
   * The `negate` function template provides a generic logical negation for
   * any expression type. It constructs a `detail::not_op` logical negator
   * object, which evaluates to `true` if the operand is false; the template
   * argument is named, since the class template argument deduction would
   * copy an operand that is itself a `not_op`, instead of negating it.
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
   * any expression types. It constructs a `detail::and_op` logical
   * conjunction object, which evaluates to `true` if both operands are
   * true.
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
   * for any expression types. It constructs a `detail::or_op` logical
   * disjunction object, which evaluates to `true` if at least one of the
   * operands is true.
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
