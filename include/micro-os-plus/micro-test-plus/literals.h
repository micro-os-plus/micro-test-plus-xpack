/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file literals.h
 * @brief User-defined literals and type wrappers for the µTest++ testing
 * framework.
 *
 * @details
 * This header defines a comprehensive suite of user-defined literal operators
 * and type wrappers, enabling the explicit specification of operand types for
 * use with the µTest++ comparators and operators.
 *
 * The provided literals permit constants to be suffixed (for example, `1_i`,
 * `2_u16`) to yield strongly-typed values, thereby enhancing type safety and
 * ensuring that comparator functions and operators can display actual values
 * in test reports.
 *
 * In addition to literals, this file includes wrappers for converting dynamic
 * values and expressions to recognised types, both via deprecated aliases
 * (such as `_i`, `_u8`) and the preferred `to_*` forms (such as `to_i`,
 * `to_u8`).
 *
 * The implementation is significantly inspired by Boost UT, with adaptations
 * and extensions to address the requirements of embedded development and the
 * µTest++ framework.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::literals`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * All relevant source files are organised within the `include/micro-os-plus`
 * folder to maintain a structured and modular codebase.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_LITERALS_H_
#define MICRO_TEST_PLUS_LITERALS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include "type-traits.h"
#include "math.h"
#include <cstdint>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

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
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int` from character sequences
     * at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i` (for example, `42_i`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the integer
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i ()
    {
      return type_traits::integral_constant<math::num<int, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `short`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `short` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_s` (for example, `123_s`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the integer
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `short` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_s ()
    {
      return type_traits::integral_constant<math::num<short, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `char`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `char` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_c` (for example, <tt>'A'_c</tt>) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the character
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `char` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_c ()
    {
      return type_traits::integral_constant<math::num<char, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `signed char`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `signed char` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_sc` (for example, `65_sc`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the signed
     * character constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `signed char` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_sc ()
    {
      return type_traits::integral_constant<
          math::num<signed char, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `long` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_l` (for example, `123_l`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the long
     * integer constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `long` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_l ()
    {
      return type_traits::integral_constant<math::num<long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long long`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `long long` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_ll` (for example, `123_ll`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the long long
     * integer constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `long long` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ll ()
    {
      return type_traits::integral_constant<math::num<long long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u` (for example, `123_u`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * integer constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u ()
    {
      return type_traits::integral_constant<math::num<unsigned, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned char`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned char` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_uc` (for example, `65_uc`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * character constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned char` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_uc ()
    {
      return type_traits::integral_constant<
          math::num<unsigned char, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned short`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned short` from
     * character sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_us` (for example, `123_us`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * short constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned short` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_us ()
    {
      return type_traits::integral_constant<
          math::num<unsigned short, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned long`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned long` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_ul` (for example, `123_ul`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * long integer constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned long` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ul ()
    {
      return type_traits::integral_constant<
          math::num<unsigned long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `unsigned long long`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned long long` from
     * character sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_ull` (for example, `123_ull`) to produce
     * a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * long long integer constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `unsigned long long` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ull ()
    {
      return type_traits::integral_constant<
          math::num<unsigned long long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int8_t`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int8_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i8` (for example, `127_i8`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the `int8_t`
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int8_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i8 ()
    {
      return type_traits::integral_constant<
          math::num<std::int8_t, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int16_t`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int16_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i16` (for example, `32767_i16`) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the `int16_t`
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int16_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i16 ()
    {
      return type_traits::integral_constant<
          math::num<std::int16_t, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int32_t`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int32_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i32` (for example, `2147483647_i32`) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the `int32_t`
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int32_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i32 ()
    {
      return type_traits::integral_constant<
          math::num<std::int32_t, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `int64_t`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int64_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i64` (for example,
     * `9223372036854775807_i64`) to produce a type-safe value that integrates
     * seamlessly with the µTest++ comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the `int64_t`
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `int64_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i64 ()
    {
      return type_traits::integral_constant<
          math::num<std::int64_t, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint8_t`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `uint8_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u8` (for example, `255_u8`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the `uint8_t`
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `uint8_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u8 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint8_t, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint16_t`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `uint16_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u16` (for example, `65535_u16`) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the `uint16_t`
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `uint16_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u16 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint16_t, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint32_t`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `uint32_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u32` (for example, `4294967295_u32`) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the `uint32_t`
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `uint32_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u32 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint32_t, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `uint64_t`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `uint64_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u64` (for example,
     * `18446744073709551615_u64`) to produce a type-safe value that integrates
     * seamlessly with the µTest++ comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the `uint64_t`
     * constant.
     * @return A `type_traits::integral_constant` instance holding the parsed
     * `uint64_t` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u64 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint64_t, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `float`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed floating-point constants of type `float` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_f` (for example, `3.14_f`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     * @return A `type_traits::floating_point_constant` instance holding the
     * parsed `float` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_f ()
    {
      return type_traits::floating_point_constant<
          float, math::num<unsigned long, Cs...> (),
          math::den<unsigned long, Cs...> (),
          math::den_size<unsigned long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `double`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed floating-point constants of type `double` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_d` (for example, `2.718_d`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     * @return A `type_traits::floating_point_constant` instance holding the
     * parsed `double` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_d ()
    {
      return type_traits::floating_point_constant<
          double, math::num<unsigned long, Cs...> (),
          math::den<unsigned long, Cs...> (),
          math::den_size<unsigned long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `long double`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed floating-point constants of type `long double` from
     * character sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_ld` (for example, `1.618_ld`) to produce
     * a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     * @return A `type_traits::floating_point_constant` instance holding the
     * parsed `long double` value.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ld ()
    {
      return type_traits::floating_point_constant<
          long double, math::num<unsigned long long, Cs...> (),
          math::den<unsigned long long, Cs...> (),
          math::den_size<unsigned long long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief User-defined literal operator to convert to `bool`.
     *
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed boolean constants from character sequences at compile
     * time.
     *
     * The operator is particularly useful in test expressions, allowing string
     * literals to be suffixed with `_b` (for example, `"feature_enabled"_b`)
     * to produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     *
     * The returned type is a lightweight wrapper that behaves as a `bool` and
     * supports equality comparison with both other named instances and boolean
     * values.
     *
     * @param name Pointer to the character sequence representing the literal.
     * @param size The size of the character sequence.
     * @return An instance of a wrapper type convertible to `bool` and
     * supporting equality comparisons.
     *
     * @note This operator is intended to facilitate expressive and type-safe
     * test conditions.
     */
    constexpr auto
    operator""_b (const char* name, decltype (sizeof ("")) size)
    {
      /**
       * @brief Wrapper type for named boolean literals.
       *
       * @details
       * This structure inherits from `std::string_view` and a type trait base,
       * providing a strongly-typed boolean value for use in test expressions.
       *
       * It defines conversion to `bool` and equality operators for comparison
       * with other named instances and boolean values.
       */
      struct named : std::string_view, type_traits::op
      {
        /**
         * @brief The underlying value type.
         */
        using value_type = bool;

        /**
         * @brief Conversion operator to `bool`.
         *
         * @details
         * Always returns `true`, representing the presence of the named
         * literal in a test context.
         * @return `true`
         */
        [[nodiscard]] constexpr
        operator value_type () const
        {
          return true;
        }

        [[nodiscard]] constexpr auto
        operator== (const named&) const
        {
          return true;
        }

        [[nodiscard]] constexpr auto
        operator== (const bool other) const
        {
          return other;
        }
      };

      return named{ { name, size }, {} };
    }
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
   * @deprecated Use the corresponding `to_*` type wrappers instead
   * (since 3.2.0).
   */

  /**
   * @brief Strongly-typed wrapper for `bool` values.
   * @deprecated Use @c to_b (since 3.2.0).
   */
  using _b = type_traits::value<bool>;

  /**
   * @brief Strongly-typed wrapper for `char` values.
   * @deprecated Use @c to_c (since 3.2.0).
   */
  using _c = type_traits::value<char>;

  /**
   * @brief Strongly-typed wrapper for `signed char` values.
   * @deprecated Use @c to_sc (since 3.2.0).
   */
  using _sc = type_traits::value<signed char>;

  /**
   * @brief Strongly-typed wrapper for `short` values.
   * @deprecated Use @c to_s (since 3.2.0).
   */
  using _s = type_traits::value<short>;

  /**
   * @brief Strongly-typed wrapper for `int` values.
   * @deprecated Use @c to_i (since 3.2.0).
   */
  using _i = type_traits::value<int>;

  /**
   * @brief Strongly-typed wrapper for `long` values.
   * @deprecated Use @c to_l (since 3.2.0).
   */
  using _l = type_traits::value<long>;

  /**
   * @brief Strongly-typed wrapper for `long long` values.
   * @deprecated Use @c to_ll (since 3.2.0).
   */
  using _ll = type_traits::value<long long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values.
   * @deprecated Use @c to_u (since 3.2.0).
   */
  using _u = type_traits::value<unsigned>;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values.
   * @deprecated Use @c to_uc (since 3.2.0).
   */
  using _uc = type_traits::value<unsigned char>;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values.
   * @deprecated Use @c to_us (since 3.2.0).
   */
  using _us = type_traits::value<unsigned short>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values.
   * @deprecated Use @c to_ul (since 3.2.0).
   */
  using _ul = type_traits::value<unsigned long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values.
   * @deprecated Use @c to_ull (since 3.2.0).
   */
  using _ull = type_traits::value<unsigned long long>;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values.
   * @deprecated Use @c to_i8 (since 3.2.0).
   */
  using _i8 = type_traits::value<std::int8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values.
   * @deprecated Use @c to_i16 (since 3.2.0).
   */
  using _i16 = type_traits::value<std::int16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values.
   * @deprecated Use @c to_i32 (since 3.2.0).
   */
  using _i32 = type_traits::value<std::int32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values.
   * @deprecated Use @c to_i64 (since 3.2.0).
   */
  using _i64 = type_traits::value<std::int64_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values.
   * @deprecated Use @c to_u8 (since 3.2.0).
   */
  using _u8 = type_traits::value<std::uint8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values.
   * @deprecated Use @c to_u16 (since 3.2.0).
   */
  using _u16 = type_traits::value<std::uint16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values.
   * @deprecated Use @c to_u32 (since 3.2.0).
   */
  using _u32 = type_traits::value<std::uint32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values.
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
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  template <class T>
  struct _t : type_traits::value<T>
  {
    /**
     * @brief Constructor for the deprecated strongly-typed wrapper.
     *
     * @details
     * Constructs an `_t` instance by forwarding the provided value to the base
     * `type_traits::value<T>` wrapper.
     * @param t The value to be wrapped and explicitly converted.
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
   * @since 3.2.0
   */
  using to_b = type_traits::value<bool>;

  /**
   * @brief Strongly-typed wrapper for `char` values.
   * @since 3.2.0
   */
  using to_c = type_traits::value<char>;

  /**
   * @brief Strongly-typed wrapper for `signed char` values.
   * @since 3.2.0
   */
  using to_sc = type_traits::value<signed char>;

  /**
   * @brief Strongly-typed wrapper for `short` values.
   * @since 3.2.0
   */
  using to_s = type_traits::value<short>;

  /**
   * @brief Strongly-typed wrapper for `int` values.
   * @since 3.2.0
   */
  using to_i = type_traits::value<int>;

  /**
   * @brief Strongly-typed wrapper for `long` values.
   * @since 3.2.0
   */
  using to_l = type_traits::value<long>;

  /**
   * @brief Strongly-typed wrapper for `long long` values.
   * @since 3.2.0
   */
  using to_ll = type_traits::value<long long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values.
   * @since 3.2.0
   */
  using to_u = type_traits::value<unsigned>;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values.
   * @since 3.2.0
   */
  using to_uc = type_traits::value<unsigned char>;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values.
   * @since 3.2.0
   */
  using to_us = type_traits::value<unsigned short>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values.
   * @since 3.2.0
   */
  using to_ul = type_traits::value<unsigned long>;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values.
   * @since 3.2.0
   */
  using to_ull = type_traits::value<unsigned long long>;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values.
   * @since 3.2.0
   */
  using to_i8 = type_traits::value<std::int8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values.
   * @since 3.2.0
   */
  using to_i16 = type_traits::value<std::int16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values.
   * @since 3.2.0
   */
  using to_i32 = type_traits::value<std::int32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values.
   * @since 3.2.0
   */
  using to_i64 = type_traits::value<std::int64_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values.
   * @since 3.2.0
   */
  using to_u8 = type_traits::value<std::uint8_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values.
   * @since 3.2.0
   */
  using to_u16 = type_traits::value<std::uint16_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values.
   * @since 3.2.0
   */
  using to_u32 = type_traits::value<std::uint32_t>;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values.
   * @since 3.2.0
   */
  using to_u64 = type_traits::value<std::uint64_t>;

  /**
   * @brief Strongly-typed wrapper for `float` values.
   * @since 3.2.0
   */
  using to_f = type_traits::value<float>;

  /**
   * @brief Strongly-typed wrapper for `double` values.
   * @since 3.2.0
   */
  using to_d = type_traits::value<double>;

  /**
   * @brief Strongly-typed wrapper for `long double` values.
   * @since 3.2.0
   */
  using to_ld = type_traits::value<long double>;

  /**
   * @}
   */

  /**
   * @ingroup micro-test-plus-literals
   * @brief Generic strongly-typed wrapper for explicit type conversion.
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
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
   * @par Example
   *
   * @code
   * MyType obj;
   * auto wrapped = to_t<MyType>{obj}; // Explicitly treat obj as MyType for
   * test comparison
   * @endcode
   */
  template <class T>
  struct to_t : type_traits::value<T>
  {
    /**
     * @brief Constructor for the strongly-typed wrapper.
     *
     * @details
     * Constructs a `to_t` instance by forwarding the provided value to the
     * base `type_traits::value<T>` wrapper.
     * @param t The value to be wrapped and explicitly converted.
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
