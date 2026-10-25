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
 * the µTest++ comparators and operators report with their types.
 *
 * It also defines the constructor of `to_t`, and the `approx()` value
 * wrapper with an explicit tolerance.
 *
 * The literal operators reside within the
 * `micro_os_plus::micro_test_plus::literals` namespace, and the constructor
 * of the `to_t` type wrapper within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_LITERALS_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_LITERALS_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include <cstdint>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ===========================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace literals
  {

    /**
     * @details
     * Creates a compile-time `int` constant, for example `42_i`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_i ()
    {
      return detail::integral_literal<int, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `short` constant, for example `123_s`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_s ()
    {
      return detail::integral_literal<short, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `char` constant, for example `65_c`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_c ()
    {
      return detail::integral_literal<char, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `signed char` constant, for example `65_sc`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_sc ()
    {
      return detail::integral_literal<signed char, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `long` constant, for example `123_l`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_l ()
    {
      return detail::integral_literal<long, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `long long` constant, for example `123_ll`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_ll ()
    {
      return detail::integral_literal<long long, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `unsigned` constant, for example `123_u`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_u ()
    {
      return detail::integral_literal<unsigned, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `unsigned char` constant, for example `65_uc`,
     * with `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_uc ()
    {
      return detail::integral_literal<unsigned char, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `unsigned short` constant, for example `123_us`,
     * with `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_us ()
    {
      return detail::integral_literal<unsigned short, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `unsigned long` constant, for example `123_ul`,
     * with `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_ul ()
    {
      return detail::integral_literal<unsigned long, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `unsigned long long` constant, for example
     * `123_ull`, with `detail::integral_literal()`. The literal is parsed, and
     * its value checked against the range of the type, at compile time; a
     * negative constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_ull ()
    {
      return detail::integral_literal<unsigned long long, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `int8_t` constant, for example `127_i8`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_i8 ()
    {
      return detail::integral_literal<std::int8_t, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `int16_t` constant, for example `32767_i16`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_i16 ()
    {
      return detail::integral_literal<std::int16_t, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `int32_t` constant, for example `2147483647_i32`,
     * with `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_i32 ()
    {
      return detail::integral_literal<std::int32_t, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `int64_t` constant, for example
     * `9223372036854775807_i64`, with `detail::integral_literal()`. The
     * literal is parsed, and its value checked against the range of the type,
     * at compile time; a negative constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_i64 ()
    {
      return detail::integral_literal<std::int64_t, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `uint8_t` constant, for example `255_u8`, with
     * `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_u8 ()
    {
      return detail::integral_literal<std::uint8_t, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `uint16_t` constant, for example `65535_u16`,
     * with `detail::integral_literal()`. The literal is parsed, and its value
     * checked against the range of the type, at compile time; a negative
     * constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_u16 ()
    {
      return detail::integral_literal<std::uint16_t, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `uint32_t` constant, for example
     * `4294967295_u32`, with `detail::integral_literal()`. The literal is
     * parsed, and its value checked against the range of the type, at compile
     * time; a negative constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_u32 ()
    {
      return detail::integral_literal<std::uint32_t, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `uint64_t` constant, for example
     * `18446744073709551615_u64`, with `detail::integral_literal()`. The
     * literal is parsed, and its value checked against the range of the type,
     * at compile time; a negative constant is written with the unary minus.
     */
    template <char... Cs>
    constexpr auto
    operator""_u64 ()
    {
      return detail::integral_literal<std::uint64_t, Cs...> ();
    }

    /**
     * @details
     * Creates a compile-time `float` constant, for example `3.14_f`, from the
     * integral part, the decimals, and the number of decimals of the literal,
     * parsed at compile time by `detail::math::num()`, `den()`, and
     * `den_size()`; the comparison tolerance is one unit of the last decimal
     * written.
     */
    template <char... Cs>
    constexpr auto
    operator""_f ()
    {
      return detail::floating_point_constant<
          float, detail::math::num<unsigned long long, Cs...> (),
          detail::math::den<unsigned long long, Cs...> (),
          detail::math::den_size<unsigned long long, Cs...> ()>{};
    }

    /**
     * @details
     * Creates a compile-time `double` constant, for example `2.718_d`, from
     * the integral part, the decimals, and the number of decimals of the
     * literal, parsed at compile time by `detail::math::num()`, `den()`, and
     * `den_size()`; the comparison tolerance is one unit of the last decimal
     * written.
     */
    template <char... Cs>
    constexpr auto
    operator""_d ()
    {
      return detail::floating_point_constant<
          double, detail::math::num<unsigned long long, Cs...> (),
          detail::math::den<unsigned long long, Cs...> (),
          detail::math::den_size<unsigned long long, Cs...> ()>{};
    }

    /**
     * @details
     * Creates a compile-time `long double` constant, for example `1.618_ld`,
     * from the integral part, the decimals, and the number of decimals of the
     * literal, parsed at compile time by `detail::math::num()`, `den()`, and
     * `den_size()`; the comparison tolerance is one unit of the last decimal
     * written.
     */
    template <char... Cs>
    constexpr auto
    operator""_ld ()
    {
      return detail::floating_point_constant<
          long double, detail::math::num<unsigned long long, Cs...> (),
          detail::math::den<unsigned long long, Cs...> (),
          detail::math::den_size<unsigned long long, Cs...> ()>{};
    }

    /**
     * @details
     * This user-defined literal operator creates a named boolean constant,
     * with the value `true`, from a string literal (for example,
     * `"feature_enabled"_b`).
     *
     * The returned `detail::named_bool` converts implicitly to `bool`, and
     * the expression formatter prints its name instead of its value. With
     * the operators in the `operators` namespace, a comparison like
     * `"feature_enabled"_b == flag` is true when `flag` is true, and, when
     * it fails, it is reported as `feature_enabled == false`; the same
     * applies to `eq ("feature_enabled"_b, flag)`. Without these
     * operators, the comparison is a plain `bool` expression, and its
     * operands are not reported.
     */
    constexpr auto
    operator""_b (const char* name, decltype (sizeof ("")) size)
    {
      return detail::named_bool{ std::string_view{ name, size } };
    }

    // ------------------------------------------------------------------------
  } // namespace literals

  // ==========================================================================

#if defined(__GNUC__)
#pragma GCC diagnostic push
// The definition of the deprecated class.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)

  /**
   * @details
   * Constructs a `to_t` instance by forwarding the provided value to the
   * base `detail::value<T>` wrapper.
   */
  template <class T>
  constexpr to_t<T>::to_t (const T& t) : detail::value<T>{ t }
  {
  }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

  /**
   * @details
   * Constructs the floating-point `detail::value<T>` with the given
   * tolerance, instead of the one derived from the number of decimals of
   * the value.
   */
  template <class T>
    requires std::is_floating_point_v<T>
  constexpr auto
  approx (T value, std::type_identity_t<T> epsilon) noexcept
      -> detail::value<T>
  {
    return detail::value<T>{ value, epsilon };
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_LITERALS_INLINES_H_

// ----------------------------------------------------------------------------
