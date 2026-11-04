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
 * conjunction (`all_of`), disjunction (`any_of`), and negation
 * (`negate`).
 *
 * These comparators and logical operators enable expressive and type-safe test
 * expectations and assertions; the C strings are compared by content, the
 * other pointers by address.
 * The logical combinators have descriptive names, since `and`, `or`, and
 * `not` are alternative tokens and cannot be used as identifiers.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is included by `function-comparators.h`; the applications include
 * `micro-os-plus/micro-test-plus.h`, not this file.
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
   * converts the C strings to `detail::basic_c_string`, and the other arrays to
   * `detail::array_operand`, so that they are compared by content. It
   * constructs a comparator object, with the `detail::equal_to` tag, which
   * evaluates to `true` if the two values are equal, and which is reported
   * with both values if not.
   *
   * The operands are forwarded, so that the comparator moves the
   * temporaries, and copies the named operands (see `stored_operand_t`),
   * so that the expression stays valid after the operands are destroyed.
   */
  template <class Lhs_T, class Rhs_T>
    requires detail::comparable_operands<detail::comparison::equal, Lhs_T,
                                         Rhs_T>
  constexpr auto
  eq (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::equal_to{} };
  }

  /**
   * @details
   * Never called; the compilation stops in `detail::reject_comparison()`,
   * with a message that names the mistake.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::equal, Lhs_T,
                                              Rhs_T>)
  constexpr bool
  eq ([[maybe_unused]] Lhs_T&& lhs, [[maybe_unused]] Rhs_T&& rhs)
  {
    detail::reject_comparison<detail::comparison::equal, Lhs_T, Rhs_T> ();
    return false;
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings and the arrays are compared by content. It constructs a
   * comparator object, with the `detail::not_equal_to` tag, which evaluates to
   * `true` if the two values are not equal, and which is reported with both
   * values if not.
   */
  template <class Lhs_T, class Rhs_T>
    requires detail::comparable_operands<detail::comparison::not_equal, Lhs_T,
                                         Rhs_T>
  constexpr auto
  ne (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::not_equal_to{} };
  }

  /**
   * @details
   * Never called; the compilation stops in `detail::reject_comparison()`,
   * with a message that names the mistake.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::not_equal,
                                              Lhs_T, Rhs_T>)
  constexpr bool
  ne ([[maybe_unused]] Lhs_T&& lhs, [[maybe_unused]] Rhs_T&& rhs)
  {
    detail::reject_comparison<detail::comparison::not_equal, Lhs_T, Rhs_T> ();
    return false;
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings and the arrays are compared by content. It constructs a
   * comparator object, with the `detail::greater` tag, which evaluates to
   * `true` if `lhs` is greater than `rhs`, and which is reported with both
   * values if not.
   */
  template <class Lhs_T, class Rhs_T>
    requires detail::comparable_operands<detail::comparison::greater, Lhs_T,
                                         Rhs_T>
  constexpr auto
  gt (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::greater{} };
  }

  /**
   * @details
   * Never called; the compilation stops in `detail::reject_comparison()`,
   * with a message that names the mistake.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::greater,
                                              Lhs_T, Rhs_T>)
  constexpr bool
  gt ([[maybe_unused]] Lhs_T&& lhs, [[maybe_unused]] Rhs_T&& rhs)
  {
    detail::reject_comparison<detail::comparison::greater, Lhs_T, Rhs_T> ();
    return false;
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings and the arrays are compared by content. It constructs a
   * comparator object, with the `detail::greater_equal` tag, which evaluates
   * to `true` if `lhs` is greater than or equal to `rhs`, and which is
   * reported with both values if not.
   */
  template <class Lhs_T, class Rhs_T>
    requires detail::comparable_operands<detail::comparison::greater_equal,
                                         Lhs_T, Rhs_T>
  constexpr auto
  ge (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::greater_equal{} };
  }

  /**
   * @details
   * Never called; the compilation stops in `detail::reject_comparison()`,
   * with a message that names the mistake.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<
              detail::comparison::greater_equal, Lhs_T, Rhs_T>)
  constexpr bool
  ge ([[maybe_unused]] Lhs_T&& lhs, [[maybe_unused]] Rhs_T&& rhs)
  {
    detail::reject_comparison<detail::comparison::greater_equal, Lhs_T,
                              Rhs_T> ();
    return false;
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings and the arrays are compared by content. It constructs a
   * comparator object, with the `detail::less` tag, which evaluates to `true`
   * if `lhs` is less than `rhs`, and which is reported with both values if
   * not.
   */
  template <class Lhs_T, class Rhs_T>
    requires detail::comparable_operands<detail::comparison::less, Lhs_T,
                                         Rhs_T>
  constexpr auto
  lt (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::less{} };
  }

  /**
   * @details
   * Never called; the compilation stops in `detail::reject_comparison()`,
   * with a message that names the mistake.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::less, Lhs_T,
                                              Rhs_T>)
  constexpr bool
  lt ([[maybe_unused]] Lhs_T&& lhs, [[maybe_unused]] Rhs_T&& rhs)
  {
    detail::reject_comparison<detail::comparison::less, Lhs_T, Rhs_T> ();
    return false;
  }

  /**
   * @details
   * The operands are passed to `detail::as_operand()`, as for `eq()`, so that
   * the C strings and the arrays are compared by content. It constructs a
   * comparator object, with the `detail::less_equal` tag, which evaluates to
   * `true` if `lhs` is less than or equal to `rhs`, and which is reported with
   * both values if not.
   */
  template <class Lhs_T, class Rhs_T>
    requires detail::comparable_operands<detail::comparison::less_equal, Lhs_T,
                                         Rhs_T>
  constexpr auto
  le (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return detail::compare_op{ detail::as_operand (std::forward<Lhs_T> (lhs)),
                               detail::as_operand (std::forward<Rhs_T> (rhs)),
                               detail::less_equal{} };
  }

  /**
   * @details
   * Never called; the compilation stops in `detail::reject_comparison()`,
   * with a message that names the mistake.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::less_equal,
                                              Lhs_T, Rhs_T>)
  constexpr bool
  le ([[maybe_unused]] Lhs_T&& lhs, [[maybe_unused]] Rhs_T&& rhs)
  {
    detail::reject_comparison<detail::comparison::less_equal, Lhs_T, Rhs_T> ();
    return false;
  }

  /**
   * @details
   * The `approx` function template constructs a `detail::approx_op`
   * from the forwarded operands and tolerance; the operands are numbers,
   * so `detail::as_operand()`, which converts the C strings, is not
   * needed.
   */
  template <class Lhs_T, class Rhs_T, class Epsilon_T>
    requires (extension::approx_operand<Lhs_T>
              and extension::approx_operand<Rhs_T>
              and extension::approx_operand<Epsilon_T>)
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
    requires extension::checkable<std::remove_cvref_t<Expr_T>>
  constexpr auto
  negate (Expr_T&& expr)
  {
    return detail::not_op<detail::stored_operand_t<Expr_T>>{
      std::forward<Expr_T> (expr)
    };
  }

  /**
   * @details
   * The `all_of` function template provides a generic logical conjunction
   * for any expression types. It constructs a `detail::and_op` logical
   * conjunction object, which evaluates to `true` if all the operands are
   * true. For more than two operands, the objects are nested from the
   * left, `(a and b) and c`, and the expression formatter writes them as
   * a single chain, `(a and b and c)`.
   *
   * All the operands are evaluated before the check, so, unlike the
   * standard algorithm of the same name, the function does not stop at the
   * first operand that is false.
   *
   * The name is the same as that of `std::all_of`: after a
   * `using namespace std`, an unqualified call with three or more operands
   * of the same type selects the standard algorithm, so the function must
   * be called as `mt::all_of()`.
   */
  template <class First_T, class Second_T, class... Rest_T>
    requires (extension::checkable<std::remove_cvref_t<First_T>>
              and extension::checkable<std::remove_cvref_t<Second_T>>
              and (extension::checkable<std::remove_cvref_t<Rest_T>> and ...))
  constexpr auto
  all_of (First_T&& first, Second_T&& second, Rest_T&&... rest)
  {
    if constexpr (sizeof...(Rest_T) == 0)
      {
        return detail::and_op{ std::forward<First_T> (first),
                               std::forward<Second_T> (second) };
      }
    else
      {
        return micro_test_plus::all_of (
            detail::and_op{ std::forward<First_T> (first),
                            std::forward<Second_T> (second) },
            std::forward<Rest_T> (rest)...);
      }
  }

  /**
   * @details
   * The `any_of` function template provides a generic logical disjunction
   * for any expression types. It constructs a `detail::or_op` logical
   * disjunction object, which evaluates to `true` if at least one of the
   * operands is true; the disjunction is inclusive, so the result is also
   * true when all the conditions are true. For more than two operands, the
   * objects are nested from the left, and the expression formatter writes
   * them as a single chain, `(a or b or c)`.
   *
   * All the operands are evaluated before the check, so the function does
   * not stop at the first operand that is true; and, as for `all_of()`, it
   * must be called as `mt::any_of()` after a `using namespace std`.
   */
  template <class First_T, class Second_T, class... Rest_T>
    requires (extension::checkable<std::remove_cvref_t<First_T>>
              and extension::checkable<std::remove_cvref_t<Second_T>>
              and (extension::checkable<std::remove_cvref_t<Rest_T>> and ...))
  constexpr auto
  any_of (First_T&& first, Second_T&& second, Rest_T&&... rest)
  {
    if constexpr (sizeof...(Rest_T) == 0)
      {
        return detail::or_op{ std::forward<First_T> (first),
                              std::forward<Second_T> (second) };
      }
    else
      {
        return micro_test_plus::any_of (
            detail::or_op{ std::forward<First_T> (first),
                           std::forward<Second_T> (second) },
            std::forward<Rest_T> (rest)...);
      }
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
