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
 * @brief C++ header file with the declarations of the deprecated µTest++
 * definitions.
 *
 * @details
 * This header groups the deprecated definitions that are not members of
 * the framework classes, kept for compatibility with the applications
 * written for the previous versions:
 * - the v5.0.1 names of the logical functions (`_not`, `_and`, and
 *   `_or`);
 * - the overloaded operators of the `operators` namespace, the
 *   user-defined literals of the `literals` namespace, the `to_*` type
 *   wrappers, `to_t<T>`, and `approx (value, epsilon)`, deprecated since
 *   5.1.0 in favour of the function comparators;
 * - the v5.0.1 names of the type wrappers (`_i`, `_u8`, etc.);
 * - the v5.0.1 names of the classes (`subtest`, `static_runner`,
 *   `detail::runner_totals`, and `detail::timestamps`);
 * - the `detail::timestamp` class;
 * - the `reflection::short_name()` function;
 * - the v5.0.1 `type_traits` namespace.
 *
 * The deprecated member functions and data members remain in the
 * declarations of their classes, since C++ does not allow them to be
 * declared elsewhere.
 *
 * Keeping the deprecated definitions separate makes them easy to
 * identify and, in a future major release, to remove.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "counters.h"
#include "extension.h"
#include "function-comparators.h"
#include "reflection.h"
#include "runner.h"
#include "stopwatch.h"
#include "test.h"

#include <concepts>
#include <cstdint>
#include <ctime>
#include <type_traits>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // The logical functions, now `negate()`, `all_of()`, and `any_of()`, in
  // `function-comparators.h`.

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **not** operation, the v5.0.1 name of
   * `negate()`.
   *
   * @details
   * The same as `negate()`. The name was changed since a leading
   * underscore is not used by the other public names.
   *
   * @tparam Expr_T Type of the operand.
   *
   * @param expr Logical expression to be negated.
   * @return An object that evaluates to true if the operand is false.
   */
  template <class Expr_T>
  [[deprecated ("use negate() (since 5.1.0)"), nodiscard]] constexpr auto
  _not (Expr_T&& expr);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **and** operation, the v5.0.1 name of
   * `all_of()`.
   *
   * @details
   * The same as `all_of()`. The name was changed since a leading
   * underscore is not used by the other public names.
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
  [[deprecated ("use all_of() (since 5.1.0)"), nodiscard]] constexpr auto
  _and (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical (inclusive) **or** operation, the v5.0.1 name
   * of `any_of()`.
   *
   * @details
   * The same as `any_of()`. The name was changed since a leading
   * underscore is not used by the other public names.
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
  [[deprecated ("use any_of() (since 5.1.0)"), nodiscard]] constexpr auto
  _or (Lhs_T&& lhs, Rhs_T&& rhs);

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::operators
   * @brief Custom operator overloads for expressive and type-safe test
   * assertions.
   *
   * @details
   * The `micro_os_plus::micro_test_plus::operators` namespace provides a
   * comprehensive set of custom operator overloads designed to enable
   * expressive, concise, and type-safe test assertions within the µTest++
   * framework.
   *
   * This namespace includes equality, inequality, relational, and logical
   * operators tailored for use with the framework’s custom types. These
   * operators facilitate the creation of clear and readable test
   * expressions, supporting both strongly-typed constants (via user-defined
   * literals) and dynamic values (via wrappers).
   *
   * @warning Please be aware that these operators
   * may conflict with other operators defined within the application under
   * test.
   *
   * To minimise conflicts with application-defined operators, these
   * overloads are enabled only when an operand is a framework expression
   * or value wrapper (see `extension::is_op`). Constants typically
   * require a literal suffix (e.g.,
   * `1_i`), while dynamic values should be wrapped using the provided
   * casting utilities (e.g., `mt::to_i{...}`). When neither operand is of
   * such a type, the standard operators are selected; they return a plain
   * `bool`, so a failed check cannot show the operands.
   *
   * The operands are forwarded, as by the function comparators: the
   * temporaries are moved into the returned expression, and the named
   * operands of class type, including the nested expressions, are
   * referred to, without copies.
   *
   * There are no operators for strings and containers: the standard
   * operators would be selected for `std::string` objects and for
   * containers of the same type, and the framework operators for
   * `std::string_view` objects would also replace the standard ones in the
   * application code that follows the using directive. Use `mt::eq()` and
   * `mt::ne()` to compare strings and containers.
   *
   * All definitions within this namespace are implemented in the
   * `include/micro-os-plus/micro-test-plus` folder, ensuring a modular and
   * maintainable codebase.
   *
   * @par Deprecated
   * Use the function comparators `eq()`, `ne()`, `gt()`, `ge()`, `lt()`,
   * and `le()`, with the plain values, and `all_of()`, `any_of()`, and
   * `negate()` for the logical combinations (since 5.1.0). The function
   * comparators accept the same operands, compare them and report them in
   * the same way, and do not need the literal suffixes or the type
   * wrappers.
   *
   * @since 3.2.0
   */
  namespace operators
  {
    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Equality operator. Matches only if at least one operand is a
     * framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the operands are
     * equal.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use eq() (since 5.1.0)"), nodiscard]] constexpr auto
    operator== (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Non-equality operator. Matches only if at least one operand
     * is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the operands are
     * not equal.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use ne() (since 5.1.0)"), nodiscard]] constexpr auto
    operator!= (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Greater than operator. Matches only if at least one operand is
     * a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is greater than the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use gt() (since 5.1.0)"), nodiscard]] constexpr auto
    operator> (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Greater than or equal operator. Matches only if at least one
     * operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is greater than or equal to the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use ge() (since 5.1.0)"), nodiscard]] constexpr auto
    operator>= (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Less than operator. Matches only if at least one operand is
     * a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is less than the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use lt() (since 5.1.0)"), nodiscard]] constexpr auto
    operator< (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Less than or equal operator. Matches only if at least one operand
     * is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is less than or equal to the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use le() (since 5.1.0)"), nodiscard]] constexpr auto
    operator<= (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Logical `&&` (and) operator. Matches only if at least one operand
     * is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A logical conjunction object that evaluates to true if both
     * operands are true.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use all_of() (since 5.1.0)"), nodiscard]] constexpr auto
    operator and (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Logical `||` (or) operator. Matches only if at least one operand
     * is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A logical disjunction object that evaluates to true if at least
     * one operand is true.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use any_of() (since 5.1.0)"), nodiscard]] constexpr auto
    operator or (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-operators
     * @brief Logical `!` (not) operator. Matches only if the operand is a
     * framework type (see `extension::is_op`).
     *
     * @tparam T Type of the operand, constrained to the framework types.
     *
     * @param t Operand to be logically negated.
     * @return A logical negator object that evaluates to true if the operand
     * is false.
     */
    template <class T>
      requires extension::is_op<std::remove_cvref_t<T>>
    [[deprecated ("use negate() (since 5.1.0)"), nodiscard]] constexpr auto
    operator not(T&& t);

    // ------------------------------------------------------------------------
  } // namespace operators

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::literals
   * @brief User-defined literals for the µTest++ testing framework.
   *
   * @details
   * The `literals` namespace provides an extensive collection of user-defined
   * literal operators, enabling explicit specification of operand types for
   * use with the µTest++ comparators and operators.
   *
   * These operators allow constants to be suffixed (for example, `1_i`,
   * `2_u16`) to produce strongly-typed values, thereby enhancing type safety
   * and ensuring that comparator functions and operators can display actual
   * values in test reports.
   *
   * The complementary wrappers for converting dynamic values and
   * expressions to recognised types (such as `to_i`, `to_u8`) are defined
   * in the parent `micro_os_plus::micro_test_plus` namespace.
   *
   * All definitions within this namespace are intended to facilitate clear and
   * type-safe test expressions, and are implemented in the
   * `include/micro-os-plus/micro-test-plus` folder to maintain a structured
   * and modular codebase.
   *
   * @par Deprecated
   * Pass the plain values to the function comparators `eq()`, `ne()`,
   * `gt()`, `ge()`, `lt()`, and `le()`, and use `approx()` for the
   * floating-point values compared with a tolerance (since 5.1.0). The
   * function comparators report the operands in the same way, and do not
   * need the literal suffixes.
   *
   * @since 3.2.0
   */
  namespace literals
  {
    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int`.
     *
     * @tparam Cs The character pack representing the digits of the integer
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_i ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `short`.
     *
     * @tparam Cs The character pack representing the digits of the integer
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `short` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_s ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `char`.
     *
     * @tparam Cs The character pack representing the digits of the character
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `char` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_c ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `signed char`.
     *
     * @tparam Cs The character pack representing the digits of the signed
     * character constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `signed char` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_sc ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long`.
     *
     * @tparam Cs The character pack representing the digits of the long
     * integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `long` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_l ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long long`.
     *
     * @tparam Cs The character pack representing the digits of the long long
     * integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `long long` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_ll ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_u ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned char`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * character constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned char` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_uc ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned short`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * short constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned short` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_us ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned long`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * long integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned long` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_ul ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned long long`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * long long integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned long long` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_ull ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int8_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int8_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int8_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_i8 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int16_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int16_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int16_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_i16 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int32_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int32_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int32_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_i32 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int64_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int64_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int64_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_i64 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint8_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint8_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `uint8_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_u8 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint16_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint16_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `uint16_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_u16 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint32_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint32_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `uint32_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_u32 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint64_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint64_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `uint64_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_u64 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `float`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `detail::floating_point_constant` instance holding the
     * parsed `float` value.
     */
    template <char... Cs>
    [[deprecated ("use approx() for tolerances (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_f ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `double`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `detail::floating_point_constant` instance holding the
     * parsed `double` value.
     */
    template <char... Cs>
    [[deprecated ("use approx() for tolerances (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_d ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long double`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `detail::floating_point_constant` instance holding the
     * parsed `long double` value.
     */
    template <char... Cs>
    [[deprecated ("use approx() for tolerances (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_ld ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-literals
     * @brief User-defined literal operator to create a named boolean
     * constant.
     *
     * @param name Pointer to the character sequence representing the literal.
     * @param size The size of the character sequence.
     * @return A `detail::named_bool` instance, with the value `true`,
     * reported by its name.
     */
    [[deprecated ("use a plain bool and a check message (since 5.1.0)"),
      nodiscard]] constexpr auto
    operator""_b (const char* name, decltype (sizeof ("")) size);

    // ------------------------------------------------------------------------
  } // namespace literals

  // --------------------------------------------------------------------------

  /**
   * @addtogroup micro-os-plus-micro-test-plus-literals
   * @{
   */

  /**
   * @name Type Wrappers
   * @brief Strongly-typed wrappers for converting dynamic values and
   * expressions to specific types recognised by µTest++ comparators.
   *
   * @details
   * These type aliases provide a type-safe mechanism for explicitly
   * converting values to the required types for µTest++ test expressions and
   * comparators. Each alias is a wrapper around `detail::value<T>`,
   * ensuring that the value is treated as the specified type within the
   * framework.
   *
   * The `to_*` forms replaced the older `_i`, `_u8`, etc. aliases, which
   * were deprecated in version 3.2.0.
   *
   * @par Deprecated
   * Pass the plain values to the function comparators `eq()`, `ne()`,
   * `gt()`, `ge()`, `lt()`, and `le()` instead; they report the operands
   * in the same way. For the floating-point values compared with a
   * tolerance, use `approx()` (since 5.1.0).
   *
   * @par Example
   *
   * @code
   * int x = 42;
   * // Explicitly treat x as an int for test comparison.
   * auto wrapped = to_i{x};
   * @endcode
   *
   * @since 3.2.0
   *
   * @{
   */

  /**
   * @brief Strongly-typed wrapper for `bool` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `bool`.
   *
   * @since 3.2.0
   */
  using to_b [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<bool>;

  /**
   * @brief Strongly-typed wrapper for `char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `char`.
   *
   * @since 3.2.0
   */
  using to_c [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<char>;

  /**
   * @brief Strongly-typed wrapper for `signed char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `signed char`.
   *
   * @since 3.2.0
   */
  using to_sc [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<signed char>;

  /**
   * @brief Strongly-typed wrapper for `short` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `short`.
   *
   * @since 3.2.0
   */
  using to_s [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<short>;

  /**
   * @brief Strongly-typed wrapper for `int` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `int`.
   *
   * @since 3.2.0
   */
  using to_i [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<int>;

  /**
   * @brief Strongly-typed wrapper for `long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long`.
   *
   * @since 3.2.0
   */
  using to_l [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<long>;

  /**
   * @brief Strongly-typed wrapper for `long long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long long`.
   *
   * @since 3.2.0
   */
  using to_ll [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<long long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned`.
   *
   * @since 3.2.0
   */
  using to_u [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<unsigned>;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned char`.
   *
   * @since 3.2.0
   */
  using to_uc [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<unsigned char>;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned short`.
   *
   * @since 3.2.0
   */
  using to_us [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<unsigned short>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned long`.
   *
   * @since 3.2.0
   */
  using to_ul [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<unsigned long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned long long`.
   *
   * @since 3.2.0
   */
  using to_ull [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<unsigned long long>;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int8_t`.
   *
   * @since 3.2.0
   */
  using to_i8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<std::int8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int16_t`.
   *
   * @since 3.2.0
   */
  using to_i16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<std::int16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int32_t`.
   *
   * @since 3.2.0
   */
  using to_i32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<std::int32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int64_t`.
   *
   * @since 3.2.0
   */
  using to_i64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<std::int64_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint8_t`.
   *
   * @since 3.2.0
   */
  using to_u8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<std::uint8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint16_t`.
   *
   * @since 3.2.0
   */
  using to_u16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<std::uint16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint32_t`.
   *
   * @since 3.2.0
   */
  using to_u32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<std::uint32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint64_t`.
   *
   * @since 3.2.0
   */
  using to_u64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = detail::value<std::uint64_t>;

  /**
   * @brief Strongly-typed wrapper for `float` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `float`.
   *
   * @since 3.2.0
   */
  using to_f [[deprecated ("use approx() for tolerances (since 5.1.0)")]]
  = detail::value<float>;

  /**
   * @brief Strongly-typed wrapper for `double` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `double`.
   *
   * @since 3.2.0
   */
  using to_d [[deprecated ("use approx() for tolerances (since 5.1.0)")]]
  = detail::value<double>;

  /**
   * @brief Strongly-typed wrapper for `long double` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long double`.
   *
   * @since 3.2.0
   */
  using to_ld [[deprecated ("use approx() for tolerances (since 5.1.0)")]]
  = detail::value<long double>;

  /**
   * @}
   */

  /**
   * @}
   */

  /**
   * @ingroup micro-os-plus-micro-test-plus-literals
   * @brief Generic strongly-typed wrapper for explicit type conversion.
   *
   * @since 3.2.0
   *
   * @details
   * The `to_t` template provides a public, strongly-typed wrapper for any type
   * `T`, enabling explicit conversion of dynamic values and expressions to a
   * type recognised by the µTest++ comparators and reporting mechanisms.
   *
   * This wrapper inherits from `detail::value<T>`, ensuring that the
   * encapsulated value is treated as the specified type within the framework,
   * for the types without a `to_*` alias, including the application types;
   * with the operators of the `operators` namespace, the comparisons are
   * then reported with their operands.
   *
   * **Example**
   *
   * @code
   * MyType obj;
   * // Explicitly treat obj as MyType for test comparison.
   * auto wrapped = to_t<MyType>{obj};
   * @endcode
   *
   * @par Deprecated
   * Pass the plain value to the function comparators `eq()`, `ne()`,
   * `gt()`, `ge()`, `lt()`, and `le()` instead; the application types
   * are reported with the `operator<<` of `expression_formatter`
   * (since 5.1.0).
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  template <class T>
  struct [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  to_t : detail::value<T>
  {
    /**
     * @brief Constructor for the strongly-typed wrapper.
     *
     * @param t The value to be wrapped and explicitly converted.
     */
    constexpr explicit to_t (const T& t);
  };

  /**
   * @ingroup micro-os-plus-micro-test-plus-literals
   * @brief Wraps a floating-point value with an explicit comparison
   * tolerance.
   *
   * @details
   * The floating-point literals (`1.5_d`) and wrappers (`to_d{ 1.5 }`)
   * compare with a tolerance derived from the number of decimals written
   * (0.1 for `1.5`). `approx()` makes the tolerance explicit, independent
   * of how the value is written. All six comparisons apply it: values
   * whose difference is less than the tolerance are equal, and neither
   * less nor greater. If both operands have a tolerance, the smaller one
   * is used.
   *
   * @code{.cpp}
   * t.expect (mt::eq (compute_float (), mt::approx (42.0f, 0.001f)));
   * @endcode
   *
   * For a single comparison, also of integers, the
   * `approx (lhs, rhs, epsilon)` function comparator may be used instead.
   *
   * @tparam T The floating-point type of the value.
   *
   * @param value The expected value.
   * @param epsilon The tolerance, converted to `T`.
   * @return A `detail::value<T>` wrapper, recognised by the
   * comparators and the operators.
   *
   * @par Deprecated
   * Use the function comparator `approx (lhs, rhs, epsilon)` instead
   * (since 5.1.0).
   *
   * @since 5.1.0
   */
  template <class T>
    requires std::is_floating_point_v<T>
  [[deprecated ("use approx (lhs, rhs, epsilon) (since 5.1.0)"),
    nodiscard]] constexpr auto
  approx (T value, std::type_identity_t<T> epsilon) noexcept
      -> detail::value<T>;

#if defined(__GNUC__)
#pragma GCC diagnostic push
// The aliases refer to the `to_*` names, deprecated too.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)

  /**
   * @addtogroup micro-os-plus-micro-test-plus-literals
   * @{
   */

  /**
   * @name Deprecated Type Wrappers
   * @brief The v5.0.1 names of the `to_*` type wrappers.
   *
   * @details
   * The Boost UT style names, with a leading underscore, kept for
   * compatibility with the existing applications. Each one is an alias
   * of the corresponding `to_*` wrapper, so the wrapped values are
   * compared and reported in the same way. They do not conflict with
   * the literal operators with the same suffixes (`42_i`), which are
   * in the `literals` namespace.
   *
   * GCC reports the deprecation only when the alias names the type of a
   * declaration, not when it is used in an expression, as in
   * `_i (expr)`; Clang reports it in both cases.
   *
   * @par Deprecated
   * Pass the plain values to the function comparators `eq()`, `ne()`,
   * `gt()`, `ge()`, `lt()`, and `le()` instead; the `to_*` type wrappers
   * that replaced these aliases (since 3.2.0) are deprecated too (since
   * 5.1.0).
   *
   * @{
   */

  /**
   * @brief Strongly-typed wrapper for `bool` values, the v5.0.1 name of
   * `to_b`.
   *
   * @details
   * The same type as `to_b`; kept for backwards compatibility.
   */
  using _b [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_b;

  /**
   * @brief Strongly-typed wrapper for `char` values, the v5.0.1 name of
   * `to_c`.
   *
   * @details
   * The same type as `to_c`; kept for backwards compatibility.
   */
  using _c [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_c;

  /**
   * @brief Strongly-typed wrapper for `signed char` values, the v5.0.1 name of
   * `to_sc`.
   *
   * @details
   * The same type as `to_sc`; kept for backwards compatibility.
   */
  using _sc [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_sc;

  /**
   * @brief Strongly-typed wrapper for `short` values, the v5.0.1 name of
   * `to_s`.
   *
   * @details
   * The same type as `to_s`; kept for backwards compatibility.
   */
  using _s [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_s;

  /**
   * @brief Strongly-typed wrapper for `int` values, the v5.0.1 name of
   * `to_i`.
   *
   * @details
   * The same type as `to_i`; kept for backwards compatibility.
   */
  using _i [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i;

  /**
   * @brief Strongly-typed wrapper for `long` values, the v5.0.1 name of
   * `to_l`.
   *
   * @details
   * The same type as `to_l`; kept for backwards compatibility.
   */
  using _l [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_l;

  /**
   * @brief Strongly-typed wrapper for `long long` values, the v5.0.1 name of
   * `to_ll`.
   *
   * @details
   * The same type as `to_ll`; kept for backwards compatibility.
   */
  using _ll [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_ll;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values, the v5.0.1 name of
   * `to_u`.
   *
   * @details
   * The same type as `to_u`; kept for backwards compatibility.
   */
  using _u [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values, the v5.0.1
   * name of `to_uc`.
   *
   * @details
   * The same type as `to_uc`; kept for backwards compatibility.
   */
  using _uc [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_uc;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values, the v5.0.1
   * name of `to_us`.
   *
   * @details
   * The same type as `to_us`; kept for backwards compatibility.
   */
  using _us [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_us;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values, the v5.0.1
   * name of `to_ul`.
   *
   * @details
   * The same type as `to_ul`; kept for backwards compatibility.
   */
  using _ul [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_ul;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values, the v5.0.1
   * name of `to_ull`.
   *
   * @details
   * The same type as `to_ull`; kept for backwards compatibility.
   */
  using _ull [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_ull;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values, the v5.0.1 name of
   * `to_i8`.
   *
   * @details
   * The same type as `to_i8`; kept for backwards compatibility.
   */
  using _i8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i8;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values, the v5.0.1
   * name of `to_i16`.
   *
   * @details
   * The same type as `to_i16`; kept for backwards compatibility.
   */
  using _i16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i16;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values, the v5.0.1
   * name of `to_i32`.
   *
   * @details
   * The same type as `to_i32`; kept for backwards compatibility.
   */
  using _i32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i32;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values, the v5.0.1
   * name of `to_i64`.
   *
   * @details
   * The same type as `to_i64`; kept for backwards compatibility.
   */
  using _i64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i64;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values, the v5.0.1
   * name of `to_u8`.
   *
   * @details
   * The same type as `to_u8`; kept for backwards compatibility.
   */
  using _u8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u8;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values, the v5.0.1
   * name of `to_u16`.
   *
   * @details
   * The same type as `to_u16`; kept for backwards compatibility.
   */
  using _u16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u16;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values, the v5.0.1
   * name of `to_u32`.
   *
   * @details
   * The same type as `to_u32`; kept for backwards compatibility.
   */
  using _u32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u32;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values, the v5.0.1
   * name of `to_u64`.
   *
   * @details
   * The same type as `to_u64`; kept for backwards compatibility.
   */
  using _u64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u64;

  /**
   * @brief Strongly-typed wrapper for `float` values, the v5.0.1 name of
   * `to_f`.
   *
   * @details
   * The same type as `to_f`; kept for backwards compatibility.
   */
  using _f [[deprecated ("use approx() for tolerances (since 5.1.0)")]] = to_f;

  /**
   * @brief Strongly-typed wrapper for `double` values, the v5.0.1 name of
   * `to_d`.
   *
   * @details
   * The same type as `to_d`; kept for backwards compatibility.
   */
  using _d [[deprecated ("use approx() for tolerances (since 5.1.0)")]] = to_d;

  /**
   * @brief Strongly-typed wrapper for `long double` values, the v5.0.1 name of
   * `to_ld`.
   *
   * @details
   * The same type as `to_ld`; kept for backwards compatibility.
   */
  using _ld [[deprecated ("use approx() for tolerances (since 5.1.0)")]]
  = to_ld;

  /**
   * @brief Generic strongly-typed wrapper, the v5.0.1 name of `to_t`.
   *
   * @details
   * The same type as `to_t<T>`, so it takes the same argument and is
   * reported in the same way; kept for backwards compatibility. In
   * v5.0.1 it was a separate class, also derived from
   * `detail::value<T>`.
   *
   * @tparam T The type of the wrapped value.
   */
  template <class T>
  using _t [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_t<T>;

  /**
   * @}
   */

  /**
   * @}
   */

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

  // ==========================================================================
  // The test case class, now `test_case`, in `test.h`.

  /**
   * @ingroup micro-os-plus-micro-test-plus-test-case
   * @brief Deprecated name of `test_case`.
   *
   * @details
   * The v5.0.1 name of the class passed to the test case bodies, kept
   * for the functions and the lambdas that name it as the type of their
   * first parameter (`void f (mt::subtest& t)`); the lambdas with an
   * `auto&` parameter are not affected.
   */
  using subtest [[deprecated ("use test_case (since 5.1.0)")]] = test_case;

  // ==========================================================================
  // The runner class, now `runner`, in `runner.h`.

  /**
   * @ingroup micro-os-plus-micro-test-plus-runners
   * @brief Deprecated name of `runner`.
   *
   * @details
   * The `runner` also runs the `static_suite` objects that refer to it,
   * so a separate runner class is no longer needed.
   */
  using static_runner [[deprecated ("use runner (since 5.1.0)")]] = runner;

  // --------------------------------------------------------------------------

  namespace reflection
  {
    // ------------------------------------------------------------------------
    // Now `utility::extract_file_name()`, in `utility.h`.

    /**
     * @brief Extracts the file name from a path.
     *
     * @details
     * Forwards to `utility::extract_file_name()`, which the framework
     * uses internally; it is kept only for compatibility with the
     * existing applications.
     *
     * @param name The path, as a C-string.
     * @return A pointer to the file name within the input string, after
     * the last `/` or `\` separator, or the string itself if there is
     * no separator.
     */
    [[deprecated ("use utility::extract_file_name() (since 5.1.0)"),
      nodiscard]] const char*
    short_name (const char* name) noexcept;

    // ------------------------------------------------------------------------
  } // namespace reflection

  // --------------------------------------------------------------------------

  namespace detail
  {
    // ========================================================================
    // The counters class, now `counters`, in `counters.h`.

    /**
     * @brief Deprecated name of `counters`.
     *
     * @details
     * The v5.0.1 name of the class returned by `totals()`, renamed since
     * the suites and the test cases own one too, not only the runner.
     */
    using runner_totals [[deprecated ("use counters (since 5.1.0)")]]
    = counters;

    // ========================================================================
    // The timings classes, now `stopwatch`, in `stopwatch.h`.

    /**
     * @brief Deprecated name of `stopwatch`.
     *
     * @details
     * The v5.0.1 name of the class returned by the `timings()` functions
     * of the runner and of the suites, which kept the two timestamps of
     * the measured interval. Its public members are kept, on `stopwatch`;
     * its protected members, the two optional `timestamp` objects, are
     * not. The timings are internal; the elapsed times are shown by the
     * reporters.
     */
    using timestamps [[deprecated ("the timings are internal (since 5.1.0)")]]
    = stopwatch;

    // ========================================================================

    /**
     * @brief Deprecated clock reading.
     *
     * @details
     * The v5.0.1 class of the two readings kept by `detail::timestamps`,
     * restored for the applications that used it directly; the framework
     * no longer uses it, since `stopwatch` keeps the readings as
     * `timespec` members. The timings are internal; use `stopwatch`
     * instead.
     *
     * A zero `timespec` means that the clock was not read, or that the
     * platform has no clock.
     *
     * The data member is `protected`, as in v5.0.1, so that the existing
     * derived classes can still access it.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class [[deprecated ("the timings are internal (since 5.1.0)")]] timestamp
    {
    public:
      /**
       * @brief Constructs a timestamp with the current time.
       *
       * @details
       * Reads the system clock, as `stopwatch::start()` does; without a
       * clock, the value remains zero.
       */
      timestamp (void) noexcept;

      /**
       * @brief Constructs a timestamp with a given time.
       *
       * @details
       * Not `explicit`, as in v5.0.1, so that a `timespec` converts
       * implicitly.
       *
       * @param ts The time to be stored.
       */
      timestamp (const timespec& ts) noexcept;

      /**
       * @brief Defaulted copy constructor.
       *
       * @details
       * A timestamp is a plain value, so it may be copied.
       */
      timestamp (const timestamp&) = default;

      /**
       * @brief Defaulted move constructor.
       *
       * @details
       * Equivalent to the copy, since the value is trivially copyable.
       */
      timestamp (timestamp&&) = default;

      /**
       * @brief Defaulted copy assignment operator.
       *
       * @details
       * A timestamp is a plain value, so it may be assigned.
       *
       * @return A reference to the current object.
       */
      timestamp&
      operator= (const timestamp&)
          = default;

      /**
       * @brief Defaulted move assignment operator.
       *
       * @details
       * Equivalent to the copy assignment, since the value is trivially
       * copyable.
       *
       * @return A reference to the current object.
       */
      timestamp&
      operator= (timestamp&&)
          = default;

      /**
       * @brief Defaulted destructor.
       *
       * @details
       * No resources are owned, so there is nothing to release.
       */
      ~timestamp () = default;

      /**
       * @brief Checks whether the value is a clock reading.
       *
       * @details
       * The value is not a reading if both its members are zero.
       *
       * @par Parameters
       *   None.
       * @retval true  At least one of the members is not zero.
       * @retval false Both members are zero.
       */
      [[nodiscard]] bool
      has_clock (void) const noexcept;

      /**
       * @brief Gets the stored time, for modification.
       *
       * @par Parameters
       *   None.
       * @return A reference to the stored `timespec`.
       */
      [[nodiscard]] timespec&
      value (void) noexcept;

      /**
       * @brief Gets the stored time.
       *
       * @par Parameters
       *   None.
       * @return A constant reference to the stored `timespec`.
       */
      [[nodiscard]] const timespec&
      value (void) const noexcept;

    protected:
      /**
       * @brief The stored time.
       *
       * @details
       * Set by the constructors; zero if the clock was not read.
       */
      timespec value_{};
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
  // The concepts, now in the `extension` namespace, in `extension.h`.
  // Kept last, since the pragma below applies to the rest of the file.

  /**
   * @namespace micro_os_plus::micro_test_plus::type_traits
   * @brief Deprecated v5.0.1 namespace of the concepts and of the value
   * wrapper templates.
   *
   * @details
   * In v5.0.1, the concepts, the base of the expressions, and the value
   * wrapper templates were outside `detail`, in the `type_traits`
   * namespace. The namespace is kept for compatibility with the existing
   * applications: the names that still exist refer to their current
   * definitions, in the `extension` and `detail` namespaces, and the
   * removed helpers are restored here.
   *
   * The concepts refer to the current ones, so their semantics are the
   * current ones: `is_op` detects the `op_type` member, not the
   * inheritance from `op`; `has_epsilon` also requires `is_op`;
   * `checkable` also accepts the types with an `explicit operator bool`;
   * `printable` accepts everything the formatter can print. The
   * exception is `has_value`, which is not used by the framework any
   * more, and is restored with its v5.0.1 definition.
   *
   * The concepts cannot be deprecated individually, so the attribute is
   * on the namespace. Clang reports the deprecation at every qualified
   * use. GCC reports it only for the names declared in the namespace
   * itself (the restored helpers and the alias templates), and, for the
   * alias templates, only when they name the type of a declaration; it
   * does not report the concepts, nor the names introduced by the
   * using-declarations.
   *
   * Use the concepts in the `extension` namespace, and
   * `extension::compare_op` or `extension::predicate_op` for the
   * application expressions; the value wrapper templates are internal.
   */

  // --------------------------------------------------------------------------

#if defined(__GNUC__)
  // GCC reports the partial specialisations of `function_traits` below,
  // since they name the deprecated namespace.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)

  // --------------------------------------------------------------------------

  namespace
      [[deprecated ("use the extension namespace (since 5.1.0)")]] type_traits
  {
    // ------------------------------------------------------------------------
    // Concepts, now in the `extension` and `detail` namespaces.

    using extension::any_op;
    using extension::checkable;
    using extension::has_epsilon;
    using extension::is_op;
    using extension::printable;

    using detail::container_like;
    using detail::has_npos;

    /**
     * @brief Deprecated C++20 concept satisfied when `T` has a member
     * named `value`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * Restored with its v5.0.1 definition, satisfied by any type with a
     * member named `value`, static or not, including the application
     * types, so that the v5.0.1 code that uses it keeps its result. It
     * is not the concept used by the framework, `detail::has_value`,
     * which is satisfied only by the framework types, so that the
     * application types with a `value` member are compared as values.
     *
     * @deprecated There is no replacement; the concept used by the
     * framework is internal (since 5.1.0).
     */
    template <class T>
    concept has_value = requires (const T& t) { t.value; };

    /**
     * @brief Deprecated C++20 concept satisfied when `T` is a
     * floating-point type.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The v5.0.1 name of `std::floating_point`, which the framework now
     * uses directly.
     *
     * @deprecated Use `std::floating_point` (since 5.1.0).
     */
    template <class T>
    concept is_floating_point = std::floating_point<T>;

    // ------------------------------------------------------------------------
    // Helpers removed from the framework, restored as in v5.0.1.

    /**
     * @brief Deprecated empty type list.
     *
     * @tparam Types The types in the list.
     *
     * @details
     * Used only as the type of `function_traits<>::args`; the framework no
     * longer uses it.
     *
     * @deprecated Not replaced (since 5.1.0).
     */
    template <class... Types>
    struct list
    {
    };

    /**
     * @brief Deprecated identity type.
     *
     * @tparam T The type to be exposed.
     * @tparam Extra Additional types, ignored.
     *
     * @details
     * Exposes `T` as the member type `type`, like `std::type_identity`,
     * which replaces it.
     *
     * @deprecated Use `std::type_identity` (since 5.1.0).
     */
    template <class T, class... Extra>
    struct identity
    {
      /**
       * @brief The type `T`.
       *
       * @details
       * The additional template arguments do not affect it.
       */
      using type = T;
    };

    /**
     * @brief Deprecated traits of the callable objects.
     *
     * @tparam T The type of the callable object; its `operator()` is
     * inspected.
     *
     * @details
     * The primary template applies to the lambdas and to the function
     * objects, and forwards to the specialisation for the type of their
     * `operator()`. The specialisations expose the return type as
     * `result_type`, and the parameter types as `args`, a `list`.
     *
     * @deprecated Not replaced (since 5.1.0).
     */
    template <class T>
    struct function_traits
#if !defined(__DOXYGEN__)
        // Hidden from Doxygen, which reports a recursive class relation.
        // https://github.com/doxygen/doxygen/issues/9915
        : function_traits<decltype (&T::operator())>
#endif // !defined(__DOXYGEN__)
    {
    };

    /**
     * @brief Deprecated traits of the function pointers.
     *
     * @tparam R The return type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a pointer to a
     * free function.
     *
     * @deprecated Not replaced (since 5.1.0).
     */
    template <class R, class... Args_T>
    struct function_traits<R (*) (Args_T...)>
    {
      /**
       * @brief The return type.
       *
       * @details
       * The type `R` of the specialisation.
       */
      using result_type = R;

      /**
       * @brief The parameter types, as a `list`.
       *
       * @details
       * The types `Args_T` of the specialisation, without the object
       * parameter of the member functions.
       */
      using args = list<Args_T...>;
    };

    /**
     * @brief Deprecated traits of the function types.
     *
     * @tparam R The return type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a function type.
     *
     * @deprecated Not replaced (since 5.1.0).
     */
    template <class R, class... Args_T>
    struct function_traits<R (Args_T...)>
    {
      /**
       * @brief The return type.
       *
       * @details
       * The type `R` of the specialisation.
       */
      using result_type = R;

      /**
       * @brief The parameter types, as a `list`.
       *
       * @details
       * The types `Args_T` of the specialisation, without the object
       * parameter of the member functions.
       */
      using args = list<Args_T...>;
    };

    /**
     * @brief Deprecated traits of the pointers to member functions.
     *
     * @tparam R The return type.
     * @tparam T The class type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a pointer to a
     * non-`const` member function.
     *
     * @deprecated Not replaced (since 5.1.0).
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...)>
    {
      /**
       * @brief The return type.
       *
       * @details
       * The type `R` of the specialisation.
       */
      using result_type = R;

      /**
       * @brief The parameter types, as a `list`.
       *
       * @details
       * The types `Args_T` of the specialisation, without the object
       * parameter of the member functions.
       */
      using args = list<Args_T...>;
    };

    /**
     * @brief Deprecated traits of the pointers to `const` member
     * functions.
     *
     * @tparam R The return type.
     * @tparam T The class type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a pointer to a
     * `const` member function, like the `operator()` of a lambda.
     *
     * @deprecated Not replaced (since 5.1.0).
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...) const>
    {
      /**
       * @brief The return type.
       *
       * @details
       * The type `R` of the specialisation.
       */
      using result_type = R;

      /**
       * @brief The parameter types, as a `list`.
       *
       * @details
       * The types `Args_T` of the specialisation, without the object
       * parameter of the member functions.
       */
      using args = list<Args_T...>;
    };

    // ------------------------------------------------------------------------
    // The base of the expressions and the value wrappers, now in `detail`.

    using detail::floating_point_constant;
    using detail::integral_constant;
    using detail::op;
    using detail::value;

    /**
     * @brief Deprecated name of `detail::value_base`.
     *
     * @tparam T The type of the stored value.
     *
     * @details
     * The v5.0.1 name, with a trailing underscore. The stored value is now
     * private, and `get()` returns a reference; the value is read with
     * `get()` or with the explicit conversion, not through the v5.0.1
     * public member `value_`.
     *
     * @deprecated The value wrappers are internal (since 5.1.0).
     */
    template <class T>
    using value_base_ = detail::value_base<T>;

    /**
     * @brief Deprecated integral value wrapper.
     *
     * @tparam T The integral type of the stored value.
     *
     * @details
     * In v5.0.1, a separate wrapper with the same members as `value<T>`,
     * never created by the framework; now `value<T>`, so the values are
     * compared and reported in the same way.
     *
     * @deprecated The value wrappers are internal (since 5.1.0).
     */
    template <class T>
    using genuine_integral_value = detail::value<T>;

    // ------------------------------------------------------------------------
  } // namespace type_traits

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/deprecated-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_H_

// ----------------------------------------------------------------------------
