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
 * @brief C++ header file with declarations for the µTest++ user-defined
 * literals and type wrappers.
 *
 * @details
 * This header provides the declarations for the user-defined literal operators
 * and type wrappers used within the µTest++ framework. It defines interfaces
 * for generating strongly-typed integral, floating-point, and boolean
 * constants at compile time, enabling expressive and type-safe test
 * expressions.
 *
 * The declared literal operators support a wide range of C++ fundamental
 * types, allowing constants to be suffixed with type-specific identifiers
 * (such as `_i`, `_u16`, `_f`, `_d`, `_b`, etc.) to produce values that
 * integrate seamlessly with the µTest++ comparators and reporting mechanisms.
 *
 * In addition to literal operators, this header declares the `to_*` type
 * wrappers for explicit type conversion, supporting enhanced clarity and type
 * safety in test conditions, and their deprecated `_i`, `_u8`, etc. aliases,
 * kept for backwards compatibility.
 *
 * The literal operators reside within the
 * `micro_os_plus::micro_test_plus::literals` namespace, and the type wrappers
 * within the `micro_os_plus::micro_test_plus` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "extension.h"
#include "math.h"

#include <cstdint>
#include <type_traits>

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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
    [[nodiscard]] constexpr auto
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
   * The `to_*` forms replace the older `_i`, `_u8`, etc. aliases, which
   * were deprecated in version 3.2.0, and are marked `[[deprecated]]`
   * since version 5.1.0.
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
  using to_b = detail::value<bool>;

  /**
   * @brief Strongly-typed wrapper for `char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `char`.
   *
   * @since 3.2.0
   */
  using to_c = detail::value<char>;

  /**
   * @brief Strongly-typed wrapper for `signed char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `signed char`.
   *
   * @since 3.2.0
   */
  using to_sc = detail::value<signed char>;

  /**
   * @brief Strongly-typed wrapper for `short` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `short`.
   *
   * @since 3.2.0
   */
  using to_s = detail::value<short>;

  /**
   * @brief Strongly-typed wrapper for `int` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `int`.
   *
   * @since 3.2.0
   */
  using to_i = detail::value<int>;

  /**
   * @brief Strongly-typed wrapper for `long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long`.
   *
   * @since 3.2.0
   */
  using to_l = detail::value<long>;

  /**
   * @brief Strongly-typed wrapper for `long long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long long`.
   *
   * @since 3.2.0
   */
  using to_ll = detail::value<long long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned`.
   *
   * @since 3.2.0
   */
  using to_u = detail::value<unsigned>;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned char`.
   *
   * @since 3.2.0
   */
  using to_uc = detail::value<unsigned char>;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned short`.
   *
   * @since 3.2.0
   */
  using to_us = detail::value<unsigned short>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned long`.
   *
   * @since 3.2.0
   */
  using to_ul = detail::value<unsigned long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned long long`.
   *
   * @since 3.2.0
   */
  using to_ull = detail::value<unsigned long long>;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int8_t`.
   *
   * @since 3.2.0
   */
  using to_i8 = detail::value<std::int8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int16_t`.
   *
   * @since 3.2.0
   */
  using to_i16 = detail::value<std::int16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int32_t`.
   *
   * @since 3.2.0
   */
  using to_i32 = detail::value<std::int32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int64_t`.
   *
   * @since 3.2.0
   */
  using to_i64 = detail::value<std::int64_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint8_t`.
   *
   * @since 3.2.0
   */
  using to_u8 = detail::value<std::uint8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint16_t`.
   *
   * @since 3.2.0
   */
  using to_u16 = detail::value<std::uint16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint32_t`.
   *
   * @since 3.2.0
   */
  using to_u32 = detail::value<std::uint32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint64_t`.
   *
   * @since 3.2.0
   */
  using to_u64 = detail::value<std::uint64_t>;

  /**
   * @brief Strongly-typed wrapper for `float` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `float`.
   *
   * @since 3.2.0
   */
  using to_f = detail::value<float>;

  /**
   * @brief Strongly-typed wrapper for `double` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `double`.
   *
   * @since 3.2.0
   */
  using to_d = detail::value<double>;

  /**
   * @brief Strongly-typed wrapper for `long double` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long double`.
   *
   * @since 3.2.0
   */
  using to_ld = detail::value<long double>;

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
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  template <class T>
  struct to_t : detail::value<T>
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
   * @since 5.1.0
   */
  template <class T>
    requires std::is_floating_point_v<T>
  [[nodiscard]] constexpr auto
  approx (T value, std::type_identity_t<T> epsilon) noexcept
      -> detail::value<T>;

  // --------------------------------------------------------------------------

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
   * Use the corresponding `to_*` type wrappers instead (since 3.2.0).
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
  using _b [[deprecated ("use to_b (since 3.2.0)")]] = to_b;

  /**
   * @brief Strongly-typed wrapper for `char` values, the v5.0.1 name of
   * `to_c`.
   *
   * @details
   * The same type as `to_c`; kept for backwards compatibility.
   */
  using _c [[deprecated ("use to_c (since 3.2.0)")]] = to_c;

  /**
   * @brief Strongly-typed wrapper for `signed char` values, the v5.0.1 name of
   * `to_sc`.
   *
   * @details
   * The same type as `to_sc`; kept for backwards compatibility.
   */
  using _sc [[deprecated ("use to_sc (since 3.2.0)")]] = to_sc;

  /**
   * @brief Strongly-typed wrapper for `short` values, the v5.0.1 name of
   * `to_s`.
   *
   * @details
   * The same type as `to_s`; kept for backwards compatibility.
   */
  using _s [[deprecated ("use to_s (since 3.2.0)")]] = to_s;

  /**
   * @brief Strongly-typed wrapper for `int` values, the v5.0.1 name of
   * `to_i`.
   *
   * @details
   * The same type as `to_i`; kept for backwards compatibility.
   */
  using _i [[deprecated ("use to_i (since 3.2.0)")]] = to_i;

  /**
   * @brief Strongly-typed wrapper for `long` values, the v5.0.1 name of
   * `to_l`.
   *
   * @details
   * The same type as `to_l`; kept for backwards compatibility.
   */
  using _l [[deprecated ("use to_l (since 3.2.0)")]] = to_l;

  /**
   * @brief Strongly-typed wrapper for `long long` values, the v5.0.1 name of
   * `to_ll`.
   *
   * @details
   * The same type as `to_ll`; kept for backwards compatibility.
   */
  using _ll [[deprecated ("use to_ll (since 3.2.0)")]] = to_ll;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values, the v5.0.1 name of
   * `to_u`.
   *
   * @details
   * The same type as `to_u`; kept for backwards compatibility.
   */
  using _u [[deprecated ("use to_u (since 3.2.0)")]] = to_u;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values, the v5.0.1
   * name of `to_uc`.
   *
   * @details
   * The same type as `to_uc`; kept for backwards compatibility.
   */
  using _uc [[deprecated ("use to_uc (since 3.2.0)")]] = to_uc;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values, the v5.0.1
   * name of `to_us`.
   *
   * @details
   * The same type as `to_us`; kept for backwards compatibility.
   */
  using _us [[deprecated ("use to_us (since 3.2.0)")]] = to_us;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values, the v5.0.1
   * name of `to_ul`.
   *
   * @details
   * The same type as `to_ul`; kept for backwards compatibility.
   */
  using _ul [[deprecated ("use to_ul (since 3.2.0)")]] = to_ul;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values, the v5.0.1
   * name of `to_ull`.
   *
   * @details
   * The same type as `to_ull`; kept for backwards compatibility.
   */
  using _ull [[deprecated ("use to_ull (since 3.2.0)")]] = to_ull;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values, the v5.0.1 name of
   * `to_i8`.
   *
   * @details
   * The same type as `to_i8`; kept for backwards compatibility.
   */
  using _i8 [[deprecated ("use to_i8 (since 3.2.0)")]] = to_i8;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values, the v5.0.1
   * name of `to_i16`.
   *
   * @details
   * The same type as `to_i16`; kept for backwards compatibility.
   */
  using _i16 [[deprecated ("use to_i16 (since 3.2.0)")]] = to_i16;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values, the v5.0.1
   * name of `to_i32`.
   *
   * @details
   * The same type as `to_i32`; kept for backwards compatibility.
   */
  using _i32 [[deprecated ("use to_i32 (since 3.2.0)")]] = to_i32;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values, the v5.0.1
   * name of `to_i64`.
   *
   * @details
   * The same type as `to_i64`; kept for backwards compatibility.
   */
  using _i64 [[deprecated ("use to_i64 (since 3.2.0)")]] = to_i64;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values, the v5.0.1
   * name of `to_u8`.
   *
   * @details
   * The same type as `to_u8`; kept for backwards compatibility.
   */
  using _u8 [[deprecated ("use to_u8 (since 3.2.0)")]] = to_u8;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values, the v5.0.1
   * name of `to_u16`.
   *
   * @details
   * The same type as `to_u16`; kept for backwards compatibility.
   */
  using _u16 [[deprecated ("use to_u16 (since 3.2.0)")]] = to_u16;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values, the v5.0.1
   * name of `to_u32`.
   *
   * @details
   * The same type as `to_u32`; kept for backwards compatibility.
   */
  using _u32 [[deprecated ("use to_u32 (since 3.2.0)")]] = to_u32;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values, the v5.0.1
   * name of `to_u64`.
   *
   * @details
   * The same type as `to_u64`; kept for backwards compatibility.
   */
  using _u64 [[deprecated ("use to_u64 (since 3.2.0)")]] = to_u64;

  /**
   * @brief Strongly-typed wrapper for `float` values, the v5.0.1 name of
   * `to_f`.
   *
   * @details
   * The same type as `to_f`; kept for backwards compatibility.
   */
  using _f [[deprecated ("use to_f (since 3.2.0)")]] = to_f;

  /**
   * @brief Strongly-typed wrapper for `double` values, the v5.0.1 name of
   * `to_d`.
   *
   * @details
   * The same type as `to_d`; kept for backwards compatibility.
   */
  using _d [[deprecated ("use to_d (since 3.2.0)")]] = to_d;

  /**
   * @brief Strongly-typed wrapper for `long double` values, the v5.0.1 name of
   * `to_ld`.
   *
   * @details
   * The same type as `to_ld`; kept for backwards compatibility.
   */
  using _ld [[deprecated ("use to_ld (since 3.2.0)")]] = to_ld;

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
  using _t [[deprecated ("use to_t (since 3.2.0)")]] = to_t<T>;

  /**
   * @}
   */

  /**
   * @}
   */

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/literals-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_LITERALS_H_

// ----------------------------------------------------------------------------
