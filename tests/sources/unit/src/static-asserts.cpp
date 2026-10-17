/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

#include "unit-test.h"

#include <version>

using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

namespace with_operators
{
  using namespace micro_os_plus::micro_test_plus::operators;

  // Satisfied when `==` is valid with the framework operators in scope.
  template <class Lhs_T, class Rhs_T>
  concept equality_comparable
      = requires (const Lhs_T& lhs, const Rhs_T& rhs) { lhs == rhs; };

  // The type of `lhs == rhs` with the framework operators in scope.
  template <class Lhs_T, class Rhs_T>
  using equal_t = decltype (std::declval<const Lhs_T&> ()
                            == std::declval<const Rhs_T&> ());
} // namespace with_operators

// ----------------------------------------------------------------------------

[[maybe_unused]] static void
static_asserts ()
{
  // --------------------------------------------------------------------------
  {
    {
      static_assert (static_cast<int> (verbosity::silent) == 0);
      static_assert (static_cast<int> (verbosity::quiet) == 1);
      static_assert (static_cast<int> (verbosity::normal) == 2);
      static_assert (static_cast<int> (verbosity::verbose) == 3);
    }

    {
      struct foo
      {
        int value;
      };

      struct bar
      {
      };

      static_assert (type_traits::has_value<foo>);
      static_assert (not type_traits::has_value<bar>);
      static_assert (not type_traits::has_value<int>);
      static_assert (not type_traits::has_value<void>);
    }

    {
      struct foo
      {
      };

      static_assert (type_traits::container_like<std::vector<int>>);
      static_assert (type_traits::container_like<std::array<bool, 0>>);
      static_assert (type_traits::container_like<std::string>);
      static_assert (type_traits::container_like<std::string_view>);
      // static_assert (type_traits::container_like<std::map<int, int>>);
      static_assert (not type_traits::container_like<int>);
      static_assert (not type_traits::container_like<foo>);
      static_assert (not type_traits::container_like<void>);
    }

    {
      using namespace literals;

      // The value wrappers are in `detail`, not in `type_traits`.
      static_assert (std::is_same_v<to_i, detail::value<int>>);
      static_assert (std::is_base_of_v<detail::value<double>, to_t<double>>);
      static_assert (
          std::is_same_v<decltype (42_i), detail::integral_constant<42>>);
      static_assert (type_traits::is_op<to_i>);
      static_assert (type_traits::is_op<decltype (42_i)>);
      static_assert (type_traits::is_op<decltype (1.5_d)>);
      static_assert (type_traits::has_epsilon<to_d>);
      static_assert (not type_traits::has_epsilon<to_i>);
    }

    {
      // The mathematical utilities are in `detail::math`.
      static_assert (detail::math::abs (-42) == 42);
      static_assert (detail::math::min_value (1, 2) == 1);
      static_assert (detail::math::pow (10, 3) == 1000);
      static_assert (detail::math::integer<int, '4', '2'> () == 42);
      static_assert (detail::math::num<int, '1', '.', '2', '5'> () == 1);
      static_assert (detail::math::den<int, '1', '.', '2', '5'> () == 250);
      static_assert (detail::math::den_size<int, '1', '.', '2', '5'> () == 3);

      // The number of decimals of a run-time value is computed without
      // undefined behaviour for negative and large values (a compile-time
      // error in a constant expression), and is not affected by the
      // rounding noise below an integer (API-REVIEW.md #60).
      using ull = unsigned long long;
      static_assert (detail::math::den_size<ull> (1.25) == 2);
      static_assert (detail::math::den_size<ull> (2.0) == 1);
      static_assert (detail::math::den_size<ull> (-2.25) == 2);
      static_assert (detail::math::den_size<ull> (0.011) == 3);
      static_assert (detail::math::den_size<ull> (42.42f) == 2);
      static_assert (detail::math::den_size<ull> (1.25L) == 2);
      static_assert (detail::math::den_size<ull> (1e20) == 1);
      static_assert (detail::math::den_size<ull> (
                         std::numeric_limits<double>::infinity ())
                     == 1);
    }

    {
      using namespace literals;
      using namespace operators;

      static_assert ("true"_b);
      static_assert ((not "true"_b) != "true"_b);
      static_assert ("named"_b);
      static_assert (42 == 42_i);
      static_assert (0u == 0_u);
      static_assert (42u == 42_u);
      static_assert (42 == 42_s);
      static_assert (42 == 42_c);
      static_assert (42 == 42_l);
      static_assert (42 == 42_ll);
      static_assert (42u == 42_uc);
      static_assert (42u == 42_us);
      static_assert (42u == 42_us);
      static_assert (42u == 42_ul);
      static_assert (42 == 42_i8);
      static_assert (42 == 42_i16);
      static_assert (42 == 42_i32);
      static_assert (42 == 42_i64);
      static_assert (42u == 42_u8);
      static_assert (42u == 42_u16);
      static_assert (42u == 42_u32);
      static_assert (42u == 42_u64);
      static_assert (42.42f == 42.42_f);
      static_assert (42.42 == 42.42_d);
      static_assert (240.209996948 == 240.209996948_d);
      static_assert (static_cast<long double> (42.42) == 42.42_ld);
      static_assert (240.20999694824218 == 240.20999694824218_ld);
      static_assert (0 == 0_i);
      static_assert (10'000 == 10'000_i);
      static_assert (42'000'000 == 42'000'000_i);
      static_assert (9'999 == 9'999_i);
      static_assert (42 == 42_i);
      static_assert (-42 == -42_i);
      static_assert (-42 == -42_i);

      // The integer literals follow the C++ syntax: hexadecimal, binary, and
      // octal prefixes, and digit separators (API-REVIEW.md #8). A decimal
      // point, or a value that does not fit in the type of the literal (e.g.
      // `300_u8`), is a compilation error.
      static_assert (010 == 010_i);
      static_assert (0x10 == 0x10_i);
      static_assert (0X1F == 0X1F_i);
      static_assert (0b101 == 0b101_i);
      static_assert (0B1'0000 == 0B1'0000_i);
      static_assert (0xFFu == 0xFF_u8);
      static_assert (255u == 255_u8);
      static_assert (127 == 127_i8);
      static_assert (0xFFFF'FFFF'FFFF'FFFFull == 0xFFFF'FFFF'FFFF'FFFF_u64);
      static_assert (18446744073709551615ull == 18446744073709551615_ull);

      // The floating-point literals are computed with 64-bit integers on all
      // platforms, and accept digit separators also after the decimal point
      // (API-REVIEW.md #10). Too many digits, or an exponent, is a
      // compilation error.
      static_assert (1.000'5 == 1.000'5_d);
      static_assert (1'000.5 == 1'000.5_d);
      static_assert (5000000000.5 == 5000000000.5_d);
      static_assert (1.9999999999 == 1.9999999999_d);
      static_assert (decltype (1.000'5_d)::epsilon > 0.000099
                     && decltype (1.000'5_d)::epsilon < 0.000101);

      static_assert (0. == 0.0_d);
      static_assert (0.f == .0_f);
      static_assert (0.1 == .1_d);
      static_assert (0.1 == 0.1_d);
      static_assert (0.1177 == 0.1177_d);
      static_assert (-0.1177 == -0.1177_d);
      static_assert (0.01177 == 0.01177_d);
      static_assert (-0.01177 == -0.01177_d);
      static_assert (0.001177 == 0.001177_d);
      static_assert (-0.001177 == -0.001177_d);
      static_assert (001.001177 == 001.001177_d);
      static_assert (-001.001177 == -001.001177_d);
      static_assert (01.001177 == 01.001177_d);
      static_assert (-01.001177 == -01.001177_d);
      static_assert (0.42f == 0.42_f);
      static_assert (2.42f == 2.42_f);
      static_assert (-2.42 == -2.42_d);
      static_assert (123.456 == 123.456_d);
    }

    {
      using namespace literals;
      using namespace operators;

      static_assert (
          not std::is_same_v<decltype (to_sc{ 42 }), decltype (to_c{ 42 })>);
      static_assert (not std::is_same_v<decltype (42_sc), decltype (42_c)>);
      static_assert (
          not std::is_same_v<decltype (to_sc{ 42 }), decltype (to_uc{ 42u })>);
      static_assert (not std::is_same_v<decltype (42_sc), decltype (42_uc)>);
    }

    {
      using namespace literals;
      using namespace operators;

      // The to_* wrappers.
      static_assert (to_i{ 42 } == 42_i);
      static_assert (to_b{ true });
      static_assert (not to_b{ false });
      static_assert (to_s{ 42 } == 42_s);
      static_assert (to_c{ 42 } == 42_c);
      static_assert (to_sc{ 42 } == 42_sc);
      static_assert (to_l{ 42 } == 42_l);
      static_assert (to_ll{ 42 } == 42_ll);
      static_assert (to_u{ 42u } == 42_u);
      static_assert (to_uc{ 42u } == 42_uc);
      static_assert (to_us{ 42u } == 42_us);
      static_assert (to_ul{ 42u } == 42_ul);
      static_assert (to_ull{ 42u } == 42_ull);
      static_assert (to_ull{ 18'446'744'073'709'551'615ull }
                     == 18'446'744'073'709'551'615_ull);

      // Generic to_t<T> wrapper (since 3.2.0).
      static_assert (to_t<int>{ 42 }.get () == 42);
      static_assert (to_t<bool>{ true }.get ());
    }

    {
      using namespace with_operators;

      // The string_view operators are selected when at least one operand
      // is a std::string_view.
      static_assert (
          not std::is_same_v<equal_t<std::string_view, std::string_view>,
                             bool>);
      static_assert (
          not std::is_same_v<equal_t<std::string, std::string_view>, bool>);
      static_assert (
          not std::is_same_v<equal_t<std::string_view, const char*>, bool>);
      static_assert (std::is_same_v<equal_t<std::string, std::string>, bool>);

      // There are no container operators; the standard ones compare
      // containers of the same type, and mixed containers do not compile.
      static_assert (
          std::is_same_v<equal_t<std::vector<int>, std::vector<int>>, bool>);
      static_assert (
          not equality_comparable<std::vector<int>, std::vector<long>>);
      static_assert (
          not equality_comparable<std::vector<int>, std::array<int, 1>>);
    }

    {
      // The choice of the `source_location` type does not depend on the
      // headers included before µTest++; `<version>`, included after it,
      // must not reveal a standard implementation that it did not choose
      // (API-REVIEW.md #1).
#if defined(__cpp_lib_source_location)
      static_assert (
          std::is_same_v<reflection::source_location, std::source_location>);
#endif // defined(__cpp_lib_source_location)
    }
  }
}

// ----------------------------------------------------------------------------
