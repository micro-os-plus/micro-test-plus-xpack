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
 * and less than or equal, and the approximate comparison with an explicit
 * tolerance (`approx`). Additionally, it declares logical combinators such
 * as conjunction (`all_of`), disjunction (`any_of`), and negation
 * (`negate`); their deprecated v5.0.1 names are declared in
 * `deprecated.h`.
 *
 * These comparators and logical operators enable expressive and type-safe test
 * expectations and assertions. The C strings (the arrays, including the
 * string literals, and the pointers of the character types) are compared
 * by content, and so are
 * the other arrays (e.g. byte buffers), element by element; the other
 * pointers are compared by address.
 * The temporaries are moved into the returned expressions, and the named
 * operands are copied, so an expression can be returned from the function
 * that builds it, and kept after the operands are destroyed, except for the
 * arrays, which are referred to and must outlive the expression. The copy is
 * made for every check, passing or failing, so a large container or string
 * costs an allocation; compare a `std::string_view` of a string instead,
 * when the cost matters.
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
 * This file is included by `micro-os-plus/micro-test-plus.h`, which is the
 * header that the applications include.
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
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-function-comparators
   * @brief Generic equality comparator.
   *
   * @details
   * The C strings (the arrays, including the string literals, and the
   * pointers of `char`, `wchar_t`, `char8_t`, `char16_t`, and `char32_t`)
   * are compared by content, also with the standard strings and string
   * views of the same character type; a null pointer is equal only to
   * another null pointer. The other arrays (e.g. byte buffers) are
   * compared element by element, also with a container, with the elements
   * compared as the single values are, and written as ranges; the other
   * pointers are compared by address. The
   * integers of different signedness are compared by value, as by
   * `std::cmp_equal()`, not after the usual arithmetic conversions, so
   * `eq (-1, static_cast<unsigned> (-1))` fails.
   *
   * Both operands must satisfy `extension::printable`, since they are
   * reported on failure; an application type needs an `operator<<` for
   * `mt::expression_formatter`, otherwise the call is rejected, with a
   * diagnostic that names the operand type. The operands must also be
   * comparable with the operator of the comparator, otherwise the call is
   * rejected in the same way.
   *
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
    requires detail::comparable_operands<detail::comparison::equal, Lhs_T,
                                         Rhs_T>
  [[nodiscard]] constexpr auto
  eq (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @brief Rejects operands that cannot be compared with `==` or written.
   *
   * @details
   * Selected for the operands that `eq()` does not accept (see
   * `detail::comparable_operands`); it stops the compilation with a message
   * that states what is wrong, instead of the notes of the concepts. Never
   * called.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return `false`, to avoid further errors in the check; the type is not
   * deduced, so that the call can be used in an unevaluated operand.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::equal, Lhs_T,
                                              Rhs_T>)
  [[nodiscard]] constexpr bool
  eq (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-function-comparators
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
    requires detail::comparable_operands<detail::comparison::not_equal, Lhs_T,
                                         Rhs_T>
  [[nodiscard]] constexpr auto
  ne (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @brief Rejects operands that cannot be compared with `!=` or written.
   *
   * @details
   * Selected for the operands that `ne()` does not accept (see
   * `detail::comparable_operands`); it stops the compilation with a message
   * that states what is wrong, instead of the notes of the concepts. Never
   * called.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return `false`, to avoid further errors in the check; the type is not
   * deduced, so that the call can be used in an unevaluated operand.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::not_equal,
                                              Lhs_T, Rhs_T>)
  [[nodiscard]] constexpr bool
  ne (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-function-comparators
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
    requires detail::comparable_operands<detail::comparison::greater, Lhs_T,
                                         Rhs_T>
  [[nodiscard]] constexpr auto
  gt (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @brief Rejects operands that cannot be compared with `>` or written.
   *
   * @details
   * Selected for the operands that `gt()` does not accept (see
   * `detail::comparable_operands`); it stops the compilation with a message
   * that states what is wrong, instead of the notes of the concepts. Never
   * called.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return `false`, to avoid further errors in the check; the type is not
   * deduced, so that the call can be used in an unevaluated operand.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::greater,
                                              Lhs_T, Rhs_T>)
  [[nodiscard]] constexpr bool
  gt (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-function-comparators
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
    requires detail::comparable_operands<detail::comparison::greater_equal,
                                         Lhs_T, Rhs_T>
  [[nodiscard]] constexpr auto
  ge (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @brief Rejects operands that cannot be compared with `>=` or written.
   *
   * @details
   * Selected for the operands that `ge()` does not accept (see
   * `detail::comparable_operands`); it stops the compilation with a message
   * that states what is wrong, instead of the notes of the concepts. Never
   * called.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return `false`, to avoid further errors in the check; the type is not
   * deduced, so that the call can be used in an unevaluated operand.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<
              detail::comparison::greater_equal, Lhs_T, Rhs_T>)
  [[nodiscard]] constexpr bool
  ge (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-function-comparators
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
    requires detail::comparable_operands<detail::comparison::less, Lhs_T,
                                         Rhs_T>
  [[nodiscard]] constexpr auto
  lt (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @brief Rejects operands that cannot be compared with `<` or written.
   *
   * @details
   * Selected for the operands that `lt()` does not accept (see
   * `detail::comparable_operands`); it stops the compilation with a message
   * that states what is wrong, instead of the notes of the concepts. Never
   * called.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return `false`, to avoid further errors in the check; the type is not
   * deduced, so that the call can be used in an unevaluated operand.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::less, Lhs_T,
                                              Rhs_T>)
  [[nodiscard]] constexpr bool
  lt (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-function-comparators
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
    requires detail::comparable_operands<detail::comparison::less_equal, Lhs_T,
                                         Rhs_T>
  [[nodiscard]] constexpr auto
  le (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @brief Rejects operands that cannot be compared with `<=` or written.
   *
   * @details
   * Selected for the operands that `le()` does not accept (see
   * `detail::comparable_operands`); it stops the compilation with a message
   * that states what is wrong, instead of the notes of the concepts. Never
   * called.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return `false`, to avoid further errors in the check; the type is not
   * deduced, so that the call can be used in an unevaluated operand.
   */
  template <class Lhs_T, class Rhs_T>
    requires (not detail::comparable_operands<detail::comparison::less_equal,
                                              Lhs_T, Rhs_T>)
  [[nodiscard]] constexpr bool
  le (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-function-comparators
   * @brief Approximate equality comparator, with an explicit tolerance.
   *
   * @details
   * The comparison succeeds if the distance between `lhs` and `rhs` is
   * less than or equal to `epsilon`, so a tolerance of zero requires
   * equal values. The operands are numbers, integral or
   * floating-point, possibly of different types (the deprecated value
   * wrappers and numeric literals are also accepted, and their own
   * tolerance is not used). For
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
   * The deprecated `approx (value, epsilon)` form, available only with
   * `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED`, is a value
   * wrapper instead, which applies its tolerance to the six comparisons
   * and to the operators; it accepts only floating-point values.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @tparam Epsilon_T Type of the tolerance.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @param epsilon The tolerance; a negative one fails all comparisons.
   * @return A comparator object that evaluates to true if `lhs` and `rhs`
   * differ by at most `epsilon`.
   *
   * @since 6.0.0
   */
  template <class Lhs_T, class Rhs_T, class Epsilon_T>
    requires (extension::approx_operand<Lhs_T>
              and extension::approx_operand<Rhs_T>
              and extension::approx_operand<Epsilon_T>)
  [[nodiscard]] constexpr auto
  approx (Lhs_T&& lhs, Rhs_T&& rhs, Epsilon_T&& epsilon);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-logical-functions
   * @brief Generic logical **not** operation.
   *
   * @tparam Expr_T Type of the operand.
   *
   * @param expr Logical expression to be negated.
   * @par Constraints
   *   Enabled only if the operand satisfies `extension::checkable`, as
   *   for `expect()`; the values that are always true (C strings, arrays,
   *   function pointers) are rejected at compile time.
   * @return An object that evaluates to true if the operand is false.
   */
  template <class Expr_T>
    requires extension::checkable<std::remove_cvref_t<Expr_T>>
  [[nodiscard]] constexpr auto
  negate (Expr_T&& expr);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-logical-functions
   * @brief Generic logical **and** operation, for two or more operands.
   *
   * @tparam First_T Type of the first operand.
   * @tparam Second_T Type of the second operand.
   * @tparam Rest_T Types of the other operands, if any.
   *
   * @param first First operand.
   * @param second Second operand.
   * @param rest The other operands, if any.
   * @par Constraints
   *   Enabled only if each operand satisfies `extension::checkable`, as
   *   for `expect()`.
   * @return An object that evaluates to true if all the operand expressions
   * are true.
   */
  template <class First_T, class Second_T, class... Rest_T>
    requires (extension::checkable<std::remove_cvref_t<First_T>>
              and extension::checkable<std::remove_cvref_t<Second_T>>
              and (extension::checkable<std::remove_cvref_t<Rest_T>> and ...))
  [[nodiscard]] constexpr auto
  all_of (First_T&& first, Second_T&& second, Rest_T&&... rest);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-logical-functions
   * @brief Generic logical (inclusive) **or** operation, for two or more
   * operands.
   *
   * @tparam First_T Type of the first operand.
   * @tparam Second_T Type of the second operand.
   * @tparam Rest_T Types of the other operands, if any.
   *
   * @param first First operand.
   * @param second Second operand.
   * @param rest The other operands, if any.
   * @par Constraints
   *   Enabled only if each operand satisfies `extension::checkable`, as
   *   for `expect()`.
   * @return An object that evaluates to true if at least one of the operand
   * expressions is true, including when all are.
   */
  template <class First_T, class Second_T, class... Rest_T>
    requires (extension::checkable<std::remove_cvref_t<First_T>>
              and extension::checkable<std::remove_cvref_t<Second_T>>
              and (extension::checkable<std::remove_cvref_t<Rest_T>> and ...))
  [[nodiscard]] constexpr auto
  any_of (First_T&& first, Second_T&& second, Rest_T&&... rest);

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
