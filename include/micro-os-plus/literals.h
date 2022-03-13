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

#include "type_traits.h"
#include "math.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  namespace literals
  {
    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i ()
    {
      return type_traits::integral_constant<math::num<int, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_s ()
    {
      return type_traits::integral_constant<math::num<short, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_c ()
    {
      return type_traits::integral_constant<math::num<char, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_sc ()
    {
      return type_traits::integral_constant<
          math::num<signed char, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_l ()
    {
      return type_traits::integral_constant<math::num<long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_ll ()
    {
      return type_traits::integral_constant<math::num<long long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u ()
    {
      return type_traits::integral_constant<math::num<unsigned, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_uc ()
    {
      return type_traits::integral_constant<
          math::num<unsigned char, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_us ()
    {
      return type_traits::integral_constant<
          math::num<unsigned short, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_ul ()
    {
      return type_traits::integral_constant<
          math::num<unsigned long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_ull ()
    {
      return type_traits::integral_constant<
          math::num<unsigned long long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i8 ()
    {
      return type_traits::integral_constant<
          math::num<std::int8_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i16 ()
    {
      return type_traits::integral_constant<
          math::num<std::int16_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i32 ()
    {
      return type_traits::integral_constant<
          math::num<std::int32_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i64 ()
    {
      return type_traits::integral_constant<
          math::num<std::int64_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u8 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint8_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u16 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint16_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u32 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint32_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u64 ()
    {
      return type_traits::integral_constant<
          math::num<std::uint64_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_f ()
    {
      return type_traits::floating_point_constant<
          float, math::num<unsigned long, Cs...> (),
          math::den<unsigned long, Cs...> (),
          math::den_size<unsigned long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_d ()
    {
      return type_traits::floating_point_constant<
          double, math::num<unsigned long, Cs...> (),
          math::den<unsigned long, Cs...> (),
          math::den_size<unsigned long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_ld ()
    {
      return type_traits::floating_point_constant<
          long double, math::num<unsigned long long, Cs...> (),
          math::den<unsigned long long, Cs...> (),
          math::den_size<unsigned long long, Cs...> ()>{};
    }

    constexpr auto operator""_b (const char* name, decltype (sizeof ("")) size)
    {
      struct named : std::string_view, type_traits::op
      {
        using value_type = bool;
        [[nodiscard]] constexpr operator value_type () const
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

  using _b = type_traits::value<bool>;
  using _c = type_traits::value<char>;
  using _sc = type_traits::value<signed char>;
  using _s = type_traits::value<short>;
  using _i = type_traits::value<int>;
  using _l = type_traits::value<long>;
  using _ll = type_traits::value<long long>;
  using _u = type_traits::value<unsigned>;
  using _uc = type_traits::value<unsigned char>;
  using _us = type_traits::value<unsigned short>;
  using _ul = type_traits::value<unsigned long>;
  using _ull = type_traits::value<unsigned long long>;
  using _i8 = type_traits::value<std::int8_t>;
  using _i16 = type_traits::value<std::int16_t>;
  using _i32 = type_traits::value<std::int32_t>;
  using _i64 = type_traits::value<std::int64_t>;
  using _u8 = type_traits::value<std::uint8_t>;
  using _u16 = type_traits::value<std::uint16_t>;
  using _u32 = type_traits::value<std::uint32_t>;
  using _u64 = type_traits::value<std::uint64_t>;
  using _f = type_traits::value<float>;
  using _d = type_traits::value<double>;
  using _ld = type_traits::value<long double>;

  template <class T>
  struct _t : type_traits::value<T>
  {
    constexpr explicit _t (const T& t) : type_traits::value<T>{ t }
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
