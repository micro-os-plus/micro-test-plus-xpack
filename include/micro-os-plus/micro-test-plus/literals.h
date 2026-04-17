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
 * In addition to literal operators, this header declares both deprecated and
 * modern type wrappers for explicit type conversion, supporting enhanced
 * clarity and type safety in test conditions. The preferred `to_*` forms are
 * recommended for new code, while the older `_i`, `_u8`, etc. aliases are
 * retained for backwards compatibility.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::literals`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_LITERALS_H_
#define MICRO_TEST_PLUS_LITERALS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstdint>
#include "type-traits.h"
#include "math.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// =============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::literals
   * @brief User-defined literals and type wrappers for the µTest++ testing
   * framework.
   *
   * @details
   * The `literals` namespace provides an extensive collection of user-defined
   * literal operators and type wrappers, enabling explicit specification
   * of operand types for use with the µTest++ comparators and operators.
   *
   * These operators allow constants to be suffixed (for example, `1_i`,
   * `2_u16`) to produce strongly-typed values, thereby enhancing type safety
   * and ensuring that comparator functions and operators can display actual
   * values in test reports.
   *
   * In addition to literals, the namespace includes wrappers for converting
   * dynamic values and expressions to recognised types, both via deprecated
   * aliases (such as `_i`, `_u8`) and the preferred `to_*` forms (such as
   * `to_i`, `to_u8`).
   *
   * All definitions within this namespace are intended to facilitate clear and
   * type-safe test expressions, and are implemented in the
   * `include/micro-os-plus` folder to maintain a structured and modular
   * codebase.
   */
  namespace literals
  {
    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int`.
     *
     * @tparam Cs The character pack representing the digits of the integer
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `short`.
     *
     * @tparam Cs The character pack representing the digits of the integer
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `short` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_s ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `char`.
     *
     * @tparam Cs The character pack representing the digits of the character
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `char` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_c ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `signed char`.
     *
     * @tparam Cs The character pack representing the digits of the signed
     * character constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `signed char` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_sc ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long`.
     *
     * @tparam Cs The character pack representing the digits of the long
     * integer constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `long` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_l ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long long`.
     *
     * @tparam Cs The character pack representing the digits of the long long
     * integer constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `long long` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ll ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * integer constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned char`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * character constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned char` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_uc ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned short`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * short constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned short` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_us ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned long`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * long integer constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned long` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ul ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned long long`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * long long integer constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned long long` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ull ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int8_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int8_t`
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int8_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i8 ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int16_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int16_t`
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int16_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i16 ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int32_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int32_t`
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int32_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i32 ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int64_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int64_t`
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int64_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i64 ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint8_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint8_t`
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `uint8_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u8 ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint16_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint16_t`
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `uint16_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u16 ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint32_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint32_t`
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `uint32_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u32 ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint64_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint64_t`
     * constant.
     *
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `uint64_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u64 ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `float`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `type_traits::floating_point_constant` instance holding the
     * parsed `float` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_f ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `double`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `type_traits::floating_point_constant` instance holding the
     * parsed `double` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_d ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long double`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `type_traits::floating_point_constant` instance holding the
     * parsed `long double` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ld ();

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `bool`.
     *
     * @param name Pointer to the character sequence representing the literal.
     * @param size The size of the character sequence.
     * @return An instance of a wrapper type convertible to `bool` and
     * supporting equality comparisons.
     */
    constexpr auto
    operator""_b (const char* name, decltype (sizeof ("")) size);

    // ------------------------------------------------------------------------
  } // namespace literals

  // --------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdocumentation-deprecated-sync"
#endif
#endif

  /**
   * @addtogroup micro-test-plus-literals
   * @{
   */

  /**
   * @name Deprecated Type Wrappers
   * @brief Strongly-typed wrappers for explicit type conversion.
   *
   * @details
   * These type aliases provide wrappers for converting values and expressions
   * to specific types for use with µTest++ comparators and test expressions.
   *
   * The `_i`, `_u8`, etc. forms are now deprecated as of version 3.2.0. Please
   * use the preferred `to_*` type wrappers for new code, as they offer
   * improved clarity and consistency.
   *
   * @par Deprecated
   * Use the corresponding `to_*` type wrappers instead
   * (since 3.2.0).
   */

  /**
   * @brief Strongly-typed wrapper for `bool` values.
   *
   * @deprecated Use @c to_b (since 3.2.0).
   */
  using _b = type_traits::value<bool>;

  /**
   * @brief Strongly-typed wrapper for `char` values.
   *
   * @deprecated Use @c to_c (since 3.2.0).
   */
  using _c = type_traits::value<char>;

  /**
   * @brief Strongly-typed wrapper for `signed char` values.
   *
   * @deprecated Use @c to_sc (since 3.2.0).
   */
  using _sc = type_traits::value<signed char>;

  /**
   * @brief Strongly-typed wrapper for `short` values.
   *
   * @deprecated Use @c to_s (since 3.2.0).
   */
  using _s = type_traits::value<short>;

  /**
   * @brief Strongly-typed wrapper for `int` values.
   *
   * @deprecated Use @c to_i (since 3.2.0).
   */
  using _i = type_traits::value<int>;

  /**
   * @brief Strongly-typed wrapper for `long` values.
   *
   * @deprecated Use @c to_l (since 3.2.0).
   */
  using _l = type_traits::value<long>;

  /**
   * @brief Strongly-typed wrapper for `long long` values.
   *
   * @deprecated Use @c to_ll (since 3.2.0).
   */
  using _ll = type_traits::value<long long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values.
   *
   * @deprecated Use @c to_u (since 3.2.0).
   */
  using _u = type_traits::value<unsigned>;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values.
   *
   * @deprecated Use @c to_uc (since 3.2.0).
   */
  using _uc = type_traits::value<unsigned char>;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values.
   *
   * @deprecated Use @c to_us (since 3.2.0).
   */
  using _us = type_traits::value<unsigned short>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values.
   *
   * @deprecated Use @c to_ul (since 3.2.0).
   */
  using _ul = type_traits::value<unsigned long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values.
   *
   * @deprecated Use @c to_ull (since 3.2.0).
   */
  using _ull = type_traits::value<unsigned long long>;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values.
   *
   * @deprecated Use @c to_i8 (since 3.2.0).
   */
  using _i8 = type_traits::value<std::int8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values.
   *
   * @deprecated Use @c to_i16 (since 3.2.0).
   */
  using _i16 = type_traits::value<std::int16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values.
   *
   * @deprecated Use @c to_i32 (since 3.2.0).
   */
  using _i32 = type_traits::value<std::int32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values.
   *
   * @deprecated Use @c to_i64 (since 3.2.0).
   */
  using _i64 = type_traits::value<std::int64_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values.
   *
   * @deprecated Use @c to_u8 (since 3.2.0).
   */
  using _u8 = type_traits::value<std::uint8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values.
   *
   * @deprecated Use @c to_u16 (since 3.2.0).
   */
  using _u16 = type_traits::value<std::uint16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values.
   *
   * @deprecated Use @c to_u32 (since 3.2.0).
   */
  using _u32 = type_traits::value<std::uint32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values.
   *
   * @deprecated Use @c to_u64 (since 3.2.0).
   */
  using _u64 = type_traits::value<std::uint64_t>;

  /**
   * @brief Strongly-typed wrapper for `float` values. @deprecated
   * Use @c to_f (since 3.2.0).
   */
  using _f = type_traits::value<float>;

  /**
   * @brief Strongly-typed wrapper for `double` values. @deprecated
   * Use @c to_d (since 3.2.0).
   */
  using _d = type_traits::value<double>;

  /**
   * @brief Strongly-typed wrapper for `long double` values.
   *
   * @deprecated Use @c to_ld (since 3.2.0).
   */
  using _ld = type_traits::value<long double>;

  /**
   * @brief Deprecated generic strongly-typed wrapper for explicit type
   * conversion.
   *
   * @details
   * The `_t` template provides a public, strongly-typed wrapper for any type
   * `T`, enabling explicit conversion of dynamic values and expressions to a
   * type recognised by the µTest++ comparators and reporting mechanisms.
   *
   * This wrapper inherits from `type_traits::value<T>`, ensuring that the
   * encapsulated value is treated as the specified type within the framework.
   *
   * @deprecated Use `to_t` (since 3.2.0).
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  template <class T>
  struct _t : type_traits::value<T>
  {
    /**
     * @brief Constructor for the deprecated strongly-typed wrapper.
     *
     * @param t The value to be wrapped and explicitly converted.
     *
     * @details
     * Constructs an `_t` instance by forwarding the provided value to the base
     * `type_traits::value<T>` wrapper.
     */
    constexpr explicit _t (const T& t) : type_traits::value<T>{ t }
    {
    }
  };

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  /**
   * @name Type Wrappers
   * @brief Strongly-typed wrappers for converting dynamic values and
   * expressions to specific types recognised by µTest++ comparators.
   *
   * @details
   * These type aliases provide a modern, type-safe mechanism for explicitly
   * converting values to the required types for µTest++ test expressions and
   * comparators. Each alias is a wrapper around `type_traits::value<T>`,
   * ensuring that the value is treated as the specified type within the
   * framework.
   *
   * The `to_*` forms are the preferred approach since version 3.2.0,
   * superseding the older `_i`, `_u8`, etc. aliases, which are now deprecated.
   *
   * @par Example
   *
   * @code
   * int x = 42;
   * auto wrapped = to_i{x}; // Explicitly treat x as an int for test
   * comparison
   * @endcode
   *
   * @since 3.2.0
   */

  /**
   * @brief Strongly-typed wrapper for `bool` values.
   *
   * @since 3.2.0
   */
  using to_b = type_traits::value<bool>;

  /**
   * @brief Strongly-typed wrapper for `char` values.
   *
   * @since 3.2.0
   */
  using to_c = type_traits::value<char>;

  /**
   * @brief Strongly-typed wrapper for `signed char` values.
   *
   * @since 3.2.0
   */
  using to_sc = type_traits::value<signed char>;

  /**
   * @brief Strongly-typed wrapper for `short` values.
   *
   * @since 3.2.0
   */
  using to_s = type_traits::value<short>;

  /**
   * @brief Strongly-typed wrapper for `int` values.
   *
   * @since 3.2.0
   */
  using to_i = type_traits::value<int>;

  /**
   * @brief Strongly-typed wrapper for `long` values.
   *
   * @since 3.2.0
   */
  using to_l = type_traits::value<long>;

  /**
   * @brief Strongly-typed wrapper for `long long` values.
   *
   * @since 3.2.0
   */
  using to_ll = type_traits::value<long long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values.
   *
   * @since 3.2.0
   */
  using to_u = type_traits::value<unsigned>;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values.
   *
   * @since 3.2.0
   */
  using to_uc = type_traits::value<unsigned char>;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values.
   *
   * @since 3.2.0
   */
  using to_us = type_traits::value<unsigned short>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values.
   *
   * @since 3.2.0
   */
  using to_ul = type_traits::value<unsigned long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values.
   *
   * @since 3.2.0
   */
  using to_ull = type_traits::value<unsigned long long>;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values.
   *
   * @since 3.2.0
   */
  using to_i8 = type_traits::value<std::int8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values.
   *
   * @since 3.2.0
   */
  using to_i16 = type_traits::value<std::int16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values.
   *
   * @since 3.2.0
   */
  using to_i32 = type_traits::value<std::int32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values.
   *
   * @since 3.2.0
   */
  using to_i64 = type_traits::value<std::int64_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values.
   *
   * @since 3.2.0
   */
  using to_u8 = type_traits::value<std::uint8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values.
   *
   * @since 3.2.0
   */
  using to_u16 = type_traits::value<std::uint16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values.
   *
   * @since 3.2.0
   */
  using to_u32 = type_traits::value<std::uint32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values.
   *
   * @since 3.2.0
   */
  using to_u64 = type_traits::value<std::uint64_t>;

  /**
   * @brief Strongly-typed wrapper for `float` values.
   *
   * @since 3.2.0
   */
  using to_f = type_traits::value<float>;

  /**
   * @brief Strongly-typed wrapper for `double` values.
   *
   * @since 3.2.0
   */
  using to_d = type_traits::value<double>;

  /**
   * @brief Strongly-typed wrapper for `long double` values.
   *
   * @since 3.2.0
   */
  using to_ld = type_traits::value<long double>;

  /**
   * @}
   */

  /**
   * @ingroup micro-test-plus-literals
   * @brief Generic strongly-typed wrapper for explicit type conversion.
   *
   * @since 3.2.0
   *
   * @details
   * The `to_t` template provides a public, strongly-typed wrapper for any type
   * `T`, enabling explicit conversion of dynamic values and expressions to a
   * type recognised by the µTest++ comparators and reporting mechanisms.
   *
   * This wrapper inherits from `type_traits::value<T>`, ensuring that the
   * encapsulated value is treated as the specified type within the framework.
   * It is particularly useful for enhancing type safety and clarity in test
   * expressions, especially when working with user-defined or less common
   * types.
   *
   * **Example**
   *
   * @code
   * MyType obj;
   * auto wrapped = to_t<MyType>{obj}; // Explicitly treat obj as MyType for
   * test comparison
   * @endcode
   *
   * This file is intended solely for internal use within the framework and
   * should not be included directly by user code.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  template <class T>
  struct to_t : type_traits::value<T>
  {
    /**
     * @brief Constructor for the strongly-typed wrapper.
     *
     * @param t The value to be wrapped and explicitly converted.
     *
     * @details
     * Constructs a `to_t` instance by forwarding the provided value to the
     * base `type_traits::value<T>` wrapper.
     */
    constexpr explicit to_t (const T& t) : type_traits::value<T>{ t }
    {
    }
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_LITERALS_H_

// ----------------------------------------------------------------------------
