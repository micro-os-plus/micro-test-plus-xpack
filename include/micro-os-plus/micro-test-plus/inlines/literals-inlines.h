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
 * @brief C++ header file with inline implementations for the µTest++ literals
 * and type wrappers.
 *
 * @details
 * This header provides the inline implementations for the user-defined literal
 * operators and type wrappers used within the µTest++ framework. It defines
 * the logic for generating strongly-typed integral, floating-point, and
 * boolean constants at compile time, enabling expressive and type-safe test
 * expressions.
 *
 * The implemented literal operators support a wide range of C++ fundamental
 * types, allowing constants to be suffixed with type-specific identifiers
 * (such as `_i`, `_u16`, `_f`, `_d`, `_b`, etc.) to produce values that
 * integrate seamlessly with the µTest++ comparators and reporting mechanisms.
 *
 * Specialised wrappers are provided for named boolean literals, supporting
 * enhanced expressiveness and type safety in test conditions.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::literals`
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

#ifndef MICRO_TEST_PLUS_LITERALS_INLINES_H_
#define MICRO_TEST_PLUS_LITERALS_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstdint>

// #include "type-traits.h"

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

  namespace literals
  {

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int` from character sequences
     * at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i` (for example, `42_i`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i ()
    {
      return type_traits::integral_constant<math::num<int, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `short` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_s` (for example, `123_s`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_s ()
    {
      return type_traits::integral_constant<math::num<short, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `char` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_c` (for example, <tt>'A'_c</tt>) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_c ()
    {
      return type_traits::integral_constant<math::num<char, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `signed char` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_sc` (for example, `65_sc`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_sc ()
    {
      return type_traits::integral_constant<
          math::num<signed char, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `long` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_l` (for example, `123_l`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_l ()
    {
      return type_traits::integral_constant<math::num<long, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `long long` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_ll` (for example, `123_ll`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ll ()
    {
      return type_traits::integral_constant<math::num<long long, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u` (for example, `123_u`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u ()
    {
      return type_traits::integral_constant<math::num<unsigned, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned char` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_uc` (for example, `65_uc`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_uc ()
    {
      return type_traits::integral_constant<
          math::num<unsigned char, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned short` from
     * character sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_us` (for example, `123_us`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_us ()
    {
      return type_traits::integral_constant<
          math::num<unsigned short, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned long` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_ul` (for example, `123_ul`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ul ()
    {
      return type_traits::integral_constant<
          math::num<unsigned long, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `unsigned long long` from
     * character sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_ull` (for example, `123_ull`) to produce
     * a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ull ()
    {
      return type_traits::integral_constant<
          math::num<unsigned long long, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int8_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i8` (for example, `127_i8`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i8 ()
    {
      return type_traits::integral_constant<
          math::num<std::int8_t, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int16_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i16` (for example, `32767_i16`) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i16 ()
    {
      return type_traits::integral_constant<
          math::num<std::int16_t, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int32_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i32` (for example, `2147483647_i32`) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i32 ()
    {
      return type_traits::integral_constant<
          math::num<std::int32_t, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `int64_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_i64` (for example,
     * `9223372036854775807_i64`) to produce a type-safe value that integrates
     * seamlessly with the µTest++ comparators and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i64 ()
    {
      return type_traits::integral_constant<
          math::num<std::int64_t, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `uint8_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u8` (for example, `255_u8`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u8 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint8_t, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `uint16_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u16` (for example, `65535_u16`) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u16 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint16_t, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `uint32_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u32` (for example, `4294967295_u32`) to
     * produce a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u32 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint32_t, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed integral constants of type `uint64_t` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_u64` (for example,
     * `18446744073709551615_u64`) to produce a type-safe value that integrates
     * seamlessly with the µTest++ comparators and reporting mechanisms.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u64 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint64_t, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed floating-point constants of type `float` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_f` (for example, `3.14_f`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
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
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed floating-point constants of type `double` from character
     * sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_d` (for example, `2.718_d`) to produce a
     * type-safe value that integrates seamlessly with the µTest++ comparators
     * and reporting mechanisms.
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
     * @details
     * This user-defined literal operator enables the creation of
     * strongly-typed floating-point constants of type `long double` from
     * character sequences at compile time.
     *
     * The operator is particularly useful in test expressions, allowing
     * constants to be suffixed with `_ld` (for example, `1.618_ld`) to produce
     * a type-safe value that integrates seamlessly with the µTest++
     * comparators and reporting mechanisms.
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
         * @return `true`
         *
         * @details
         * Always returns `true`, representing the presence of the named
         * literal in a test context.
         */
        [[nodiscard]] constexpr
        operator value_type () const
        {
          return true;
        }

        /**
         * @brief Equality comparison with another named instance.
         *
         * @return `true`
         *
         * @details
         * Always returns `true`, indicating that any two named literals are
         * considered equal in this context.
         */
        [[nodiscard]] constexpr auto
        operator== (const named&) const
        {
          return true;
        }

        /**
         * @brief Equality comparison with a boolean value.
         *
         * @return The value of @p other.
         *
         * @details
         * Returns the value of the boolean operand, allowing the named literal
         * to be compared directly with a boolean.
         */
        [[nodiscard]] constexpr auto
        operator== (const bool other) const
        {
          return other;
        }
      };

      return named{ { name, size }, {} };
    }

    // ------------------------------------------------------------------------
  } // namespace literals

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_LITERALS_INLINES_H_

// ----------------------------------------------------------------------------
