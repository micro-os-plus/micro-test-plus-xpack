/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from <https://opensource.org/licenses/MIT/>.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from <https://www.boost.org/LICENSE_1_0.txt>.
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
   * @brief User Defined Literals (UDL). Use them to suffix
   * constants and obtain specific explicit types, like `1_i`.
   */
  namespace literals
  {
    /**
     * @ingroup micro-test-plus-literals
     * @brief Operator to convert to `int`.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_i ()
    {
      return type_traits::integral_constant<math::num<int, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief Operator to convert to `short`.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_s ()
    {
      return type_traits::integral_constant<math::num<short, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief Operator to convert to `char`.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_c ()
    {
      return type_traits::integral_constant<math::num<char, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief Operator to convert to `signed char`.
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
     * @brief Operator to convert to `long`.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_l ()
    {
      return type_traits::integral_constant<math::num<long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief Operator to convert to `long long`.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_ll ()
    {
      return type_traits::integral_constant<math::num<long long, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief Operator to convert to `unsigned`.
     */
    template <char... Cs>
    [[nodiscard]] constexpr auto
    operator""_u ()
    {
      return type_traits::integral_constant<math::num<unsigned, Cs...> ()>{};
    }

    /**
     * @ingroup micro-test-plus-literals
     * @brief Operator to convert to `unsigned char`.
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
     * @brief Operator to convert to `unsigned short`.
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
     * @brief Operator to convert to `unsigned long`.
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
     * @brief Operator to convert to `unsigned long long`.
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
     * @brief Operator to convert to `int8_t`.
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
     * @brief Operator to convert to `int16_t`.
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
     * @brief Operator to convert to `int32_t`.
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
     * @brief Operator to convert to `int64_t`.
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
     * @brief Operator to convert to `uint8_t`.
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
     * @brief Operator to convert to `uint16_t`.
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
     * @brief Operator to convert to `uint32_t`.
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
     * @brief Operator to convert to `uint64_t`.
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
     * @brief Operator to convert to `float`.
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
     * @brief Operator to convert to `double`.
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
     * @brief Operator to convert to `long double`.
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
     * @brief Operator to convert to `bool`.
     */
    constexpr auto
    operator""_b (const char* name, decltype (sizeof ("")) size)
    {
      struct named : std::string_view, type_traits::op
      {
        using value_type = bool;
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

  /** @deprecated Use `to_b` (since 3.2.0). */
  using _b = type_traits::value<bool>;
  /** @deprecated Use `to_c` (since 3.2.0). */
  using _c = type_traits::value<char>;
  /** @deprecated Use `to_sc` (since 3.2.0). */
  using _sc = type_traits::value<signed char>;
  /** @deprecated Use `to_s` (since 3.2.0). */
  using _s = type_traits::value<short>;
  /** @deprecated Use `to_i` (since 3.2.0). */
  using _i = type_traits::value<int>;
  /** @deprecated Use `to_l` (since 3.2.0). */
  using _l = type_traits::value<long>;
  /** @deprecated Use `to_ll` (since 3.2.0). */
  using _ll = type_traits::value<long long>;
  /** @deprecated Use `to_u` (since 3.2.0). */
  using _u = type_traits::value<unsigned>;
  /** @deprecated Use `to_uc` (since 3.2.0). */
  using _uc = type_traits::value<unsigned char>;
  /** @deprecated Use `to_us` (since 3.2.0). */
  using _us = type_traits::value<unsigned short>;
  /** @deprecated Use `to_ul` (since 3.2.0). */
  using _ul = type_traits::value<unsigned long>;
  /** @deprecated Use `to_ull` (since 3.2.0). */
  using _ull = type_traits::value<unsigned long long>;
  /** @deprecated Use `to_i8` (since 3.2.0). */
  using _i8 = type_traits::value<std::int8_t>;
  /** @deprecated Use `to_i16` (since 3.2.0). */
  using _i16 = type_traits::value<std::int16_t>;
  /** @deprecated Use `to_i32` (since 3.2.0). */
  using _i32 = type_traits::value<std::int32_t>;
  /** @deprecated Use `to_i64` (since 3.2.0). */
  using _i64 = type_traits::value<std::int64_t>;
  /** @deprecated Use `to_u8` (since 3.2.0). */
  using _u8 = type_traits::value<std::uint8_t>;
  /** @deprecated Use `to_u16` (since 3.2.0). */
  using _u16 = type_traits::value<std::uint16_t>;
  /** @deprecated Use `to_u32` (since 3.2.0). */
  using _u32 = type_traits::value<std::uint32_t>;
  /** @deprecated Use `to_u64` (since 3.2.0). */
  using _u64 = type_traits::value<std::uint64_t>;
  /** @deprecated Use `to_f` (since 3.2.0). */
  using _f = type_traits::value<float>;
  /** @deprecated Use `to_d` (since 3.2.0). */
  using _d = type_traits::value<double>;
  /** @deprecated Use `to_ld` (since 3.2.0). */
  using _ld = type_traits::value<long double>;

  /**
   * @deprecated Use `to_t` (since 3.2.0).
   * @}
   */

  /**
   * @ingroup micro-test-plus-literals
   * @brief Template for wrapping any other type.
   */
  template <class T>
  struct _t : type_traits::value<T>
  {
    constexpr explicit _t (const T& t) : type_traits::value<T>{ t }
    {
    }
  };


  /**
   * @addtogroup micro-test-plus-literals
   * @{
   */

  // Wrappers that can be used to convert dynamic values to specific types
  // that are recognised by the comparators.
  // The syntax is similar to function calls, like `_i(expression)`, but the
  // results have custom types expected by comparators.
  /** @since 3.2.0 */
  using to_b = type_traits::value<bool>;
  /** @since 3.2.0 */
  using to_c = type_traits::value<char>;
  /** @since 3.2.0 */
  using to_sc = type_traits::value<signed char>;
  /** @since 3.2.0 */
  using to_s = type_traits::value<short>;
  /** @since 3.2.0 */
  using to_i = type_traits::value<int>;
  /** @since 3.2.0 */
  using to_l = type_traits::value<long>;
  /** @since 3.2.0 */
  using to_ll = type_traits::value<long long>;
  /** @since 3.2.0 */
  using to_u = type_traits::value<unsigned>;
  /** @since 3.2.0 */
  using to_uc = type_traits::value<unsigned char>;
  /** @since 3.2.0 */
  using to_us = type_traits::value<unsigned short>;
  /** @since 3.2.0 */
  using to_ul = type_traits::value<unsigned long>;
  /** @since 3.2.0 */
  using to_ull = type_traits::value<unsigned long long>;
  /** @since 3.2.0 */
  using to_i8 = type_traits::value<std::int8_t>;
  /** @since 3.2.0 */
  using to_i16 = type_traits::value<std::int16_t>;
  /** @since 3.2.0 */
  using to_i32 = type_traits::value<std::int32_t>;
  /** @since 3.2.0 */
  using to_i64 = type_traits::value<std::int64_t>;
  /** @since 3.2.0 */
  using to_u8 = type_traits::value<std::uint8_t>;
  /** @since 3.2.0 */
  using to_u16 = type_traits::value<std::uint16_t>;
  /** @since 3.2.0 */
  using to_u32 = type_traits::value<std::uint32_t>;
  /** @since 3.2.0 */
  using to_u64 = type_traits::value<std::uint64_t>;
  /** @since 3.2.0 */
  using to_f = type_traits::value<float>;
  /** @since 3.2.0 */
  using to_d = type_traits::value<double>;
  /** @since 3.2.0 */
  using to_ld = type_traits::value<long double>;

  /**
   * @}
   */

  /**
   * @ingroup micro-test-plus-literals
   * @brief Template for wrapping any other type.
   * @since 3.2.0
   *
   * @details
   * A public class used only to convert the type.
   */
  template <class T>
  struct to_t : type_traits::value<T>
  {
    /** @brief Constructor. */
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
