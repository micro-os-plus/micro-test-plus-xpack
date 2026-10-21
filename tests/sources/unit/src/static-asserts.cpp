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

#include <cstddef>
#include <cstdint>
#include <functional>
#include <limits>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
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

namespace with_extension
{
  // Satisfied when `t` can be written to the expression formatter.
  template <class T>
  concept formattable = requires (expression_formatter& formatter,
                                  const T& t) { formatter << t; };

  // A type with only the expression marker, and no formatter overload,
  // which the generic overload used to select and call recursively (#149).
  struct marker_only
  {
    using op_type = detail::op;

    constexpr explicit
    operator bool () const
    {
      return false;
    }
  };

  // A comparison of the application, without a tolerance.
  struct divides
  {
    static constexpr const char* symbol = " divides ";

    template <class Lhs_T, class Rhs_T>
    static constexpr bool
    apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return rhs % lhs == 0;
    }
  };

  // A comparison of the application, with a tolerance.
  struct not_greater
  {
    static constexpr const char* symbol = " <= ";
    static constexpr bool within_tolerance_result = true;

    template <class Lhs_T, class Rhs_T>
    static constexpr bool
    apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return lhs <= rhs;
    }
  };

  // The same comparison, without a tolerance.
  struct exactly_not_greater
  {
    static constexpr const char* symbol = " <= ";

    template <class Lhs_T, class Rhs_T>
    static constexpr bool
    apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return lhs <= rhs;
    }
  };

  // A predicate of the application, whose result is converted to `bool`.
  struct even
  {
    static constexpr const char* symbol = "even ";

    template <class T>
    static constexpr int
    apply (const T& t)
    {
      return t % 2 == 0;
    }
  };
} // namespace with_extension

// ----------------------------------------------------------------------------

namespace with_conversions
{
  // A type that converts to `bool` only explicitly.
  struct explicit_bool
  {
    constexpr explicit
    operator bool (void) const noexcept
    {
      return true;
    }
  };

  // A type whose explicit conversion to `bool` is not `const`.
  struct mutable_bool
  {
    constexpr explicit
    operator bool (void) noexcept
    {
      return true;
    }
  };
} // namespace with_conversions

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

      using namespace literals;

      // Only the framework constants are detected, not the types of the
      // application with a member named `value`.
      static_assert (not detail::has_value<foo>);
      static_assert (not detail::has_value<bar>);
      static_assert (not detail::has_value<int>);
      static_assert (not detail::has_value<void>);
      static_assert (detail::has_value<decltype (42_i)>);
      static_assert (detail::has_value<decltype (1.5_d)>);
      static_assert (not detail::has_value<to_i>);
    }

    {
      struct foo
      {
      };

      static_assert (detail::container_like<std::vector<int>>);
      static_assert (detail::container_like<std::array<bool, 0>>);
      static_assert (detail::container_like<std::string>);
      static_assert (detail::container_like<std::string_view>);
      // static_assert (detail::container_like<std::map<int, int>>);
      static_assert (not detail::container_like<int>);
      static_assert (not detail::container_like<foo>);
      static_assert (not detail::container_like<void>);
    }

    {
      using namespace literals;

      // The value wrappers are in `detail`, not in `extension`.
      static_assert (std::is_same_v<to_i, detail::value<int>>);
      static_assert (std::is_base_of_v<detail::value<double>, to_t<double>>);
      static_assert (
          std::is_same_v<decltype (42_i), detail::integral_constant<42>>);
      static_assert (extension::is_op<to_i>);
      static_assert (extension::is_op<decltype (42_i)>);
      static_assert (extension::is_op<decltype (1.5_d)>);
      static_assert (extension::is_op<to_f>);
      static_assert (not extension::is_op<int>);
      // The value wrappers must not have an empty base, which would
      // trigger the AArch64 GCC 10.1 `-Wpsabi` note for `approx()`.
      static_assert (not std::is_base_of_v<detail::op, to_f>);
      static_assert (extension::has_epsilon<to_d>);
      static_assert (extension::has_epsilon<decltype (1.5_d)>);
      static_assert (not extension::has_epsilon<to_i>);
      static_assert (not extension::has_epsilon<decltype (42_i)>);

      // Only the framework floating-point wrappers are detected, not the
      // types of the application with a member named `epsilon`.
      struct gauge
      {
        double epsilon;
      };
      static_assert (not extension::has_epsilon<gauge>);
    }

    {
      using namespace literals;
      using namespace with_extension;

      // The expressions of the application are evaluated as the built-in
      // ones, on the unwrapped operands, also at compile time (#149).
      static_assert (extension::compare_op{ 3, 9, divides{} });
      static_assert (not extension::compare_op{ 2, 9, divides{} });
      static_assert (extension::compare_op{ 3_i, to_i{ 12 }, divides{} });
      static_assert (extension::predicate_op{ 4, even{} });
      static_assert (not extension::predicate_op{ to_i{ 7 }, even{} });
      static_assert (extension::is_op<decltype (extension::compare_op{
                         1, 2, divides{} })>);
      static_assert (
          extension::is_op<decltype (extension::predicate_op{ 1, even{} })>);

      // The tolerance applies only to the tags that define its result.
      static_assert (
          extension::compare_op{ to_d{ 1.05, 0.1 }, 1.0, not_greater{} });
      static_assert (not extension::compare_op{ to_d{ 1.05, 0.1 }, 1.0,
                                                exactly_not_greater{} });

      // The formatter writes the expressions and the value wrappers, and
      // rejects at compile time the types with only the marker (#149).
      static_assert (
          formattable<decltype (extension::compare_op{ 1, 2, divides{} })>);
      static_assert (
          formattable<decltype (extension::predicate_op{ 1, even{} })>);
      static_assert (formattable<to_i>);
      static_assert (formattable<decltype (42_i)>);
      static_assert (extension::is_op<marker_only>);
      static_assert (not formattable<marker_only>);
    }

    {
      // The mathematical utilities are in `detail::math`.
      static_assert (detail::math::abs (-42) == 42);
      static_assert (detail::math::min_value (1, 2) == 1);
      static_assert (detail::math::pow (10, 3) == 1000);
      static_assert (detail::math::integer_magnitude<int, '4', '2'> () == 42);
      static_assert (detail::math::num<int, '1', '.', '2', '5'> () == 1);
      static_assert (detail::math::den<int, '1', '.', '2', '5'> () == 25);
      static_assert (detail::math::den_size<int, '1', '.', '2', '5'> () == 2);

      // The number of decimals of a run-time value is computed without
      // undefined behaviour for negative and large values (a compile-time
      // error in a constant expression), and is not affected by the
      // rounding noise below an integer.
      using ull = unsigned long long;
      static_assert (detail::math::count_decimals<ull> (1.25) == 2);
      static_assert (detail::math::count_decimals<ull> (2.0) == 1);
      static_assert (detail::math::count_decimals<ull> (-2.25) == 2);
      static_assert (detail::math::count_decimals<ull> (0.011) == 3);
      static_assert (detail::math::count_decimals<ull> (42.42f) == 2);
      static_assert (detail::math::count_decimals<ull> (1.25L) == 2);
      static_assert (detail::math::count_decimals<ull> (1e20) == 1);
      static_assert (detail::math::count_decimals<ull> (
                         std::numeric_limits<double>::infinity ())
                     == 1);

      // The leading zeros of a small value are counted as decimals, and a
      // zero has none, so its tolerance is zero, an exact comparison.
      static_assert (detail::math::count_decimals<ull> (1e-8) == 8);
      static_assert (detail::math::count_decimals<ull> (1e-12) == 12);
      static_assert (detail::math::count_decimals<ull> (-2.5e-9) == 10);
      static_assert (detail::math::count_decimals<ull> (1e-300) == 300);
      static_assert (detail::math::count_decimals<ull> (1e-12L) == 12);
      static_assert (detail::math::count_decimals<ull> (0.0) == 0);
      static_assert (detail::math::count_decimals<ull> (-0.0f) == 0);
      static_assert (detail::math::decimal_epsilon (1.25) > 0.0099
                     and detail::math::decimal_epsilon (1.25) < 0.0101);
      static_assert (detail::math::decimal_epsilon (1e-12) > 0.99e-12
                     and detail::math::decimal_epsilon (1e-12) < 1.01e-12);
      static_assert (detail::math::decimal_epsilon (0.0) <= 0.0);
      static_assert (detail::math::decimal_epsilon (
                         std::numeric_limits<double>::denorm_min ())
                     <= 0.0);
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

      // The negation keeps the type of the literal, also for the types
      // narrower than `int`; the negation of an unsigned literal wraps
      // around, and the minimum of a signed type can be written.
      // The negation of the minimum is a compilation
      // error.
      static_assert (
          std::is_same_v<decltype (-1_i8)::value_type, std::int8_t>);
      static_assert (decltype (-1_i8)::value == -1);
      static_assert (std::is_same_v<decltype (-1_s)::value_type, short>);
      static_assert (decltype (-1_s)::value == -1);
      static_assert (
          std::is_same_v<decltype (-1_u8)::value_type, std::uint8_t>);
      static_assert (decltype (-1_u8)::value == 255u);
      static_assert (decltype (-1_us)::value
                     == std::numeric_limits<unsigned short>::max ());
      static_assert (decltype (-1_u)::value
                     == std::numeric_limits<unsigned int>::max ());
      static_assert (decltype (-1_u64)::value
                     == std::numeric_limits<std::uint64_t>::max ());
      static_assert (decltype (-0_u8)::value == 0u);
      static_assert (decltype (-1_c)::value == static_cast<char> (-1));
      static_assert (decltype (-(-127_i8))::value == 127);
      static_assert (-128 == -128_i8);
      static_assert (-0x80 == -0x80_i8);
      static_assert (-128 == -128_sc);
      static_assert (std::numeric_limits<std::int16_t>::min () == -32768_i16);
      static_assert (std::numeric_limits<std::int32_t>::min ()
                     == -2147483648_i32);
      static_assert (std::numeric_limits<std::int64_t>::min ()
                     == -9223372036854775808_i64);
      static_assert (
          std::is_same_v<decltype (-128_i8)::value_type, std::int8_t>);

      // The integer literals follow the C++ syntax: hexadecimal, binary, and
      // octal prefixes, and digit separators. A decimal
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
      // platforms, and accept digit separators also after the decimal point.
      // Too many digits, or an exponent, is a
      // compilation error.
      static_assert (1.000'5 == 1.000'5_d);
      static_assert (1'000.5 == 1'000.5_d);
      static_assert (5000000000.5 == 5000000000.5_d);
      static_assert (1.9999999999 == 1.9999999999_d);
      static_assert (decltype (1.000'5_d)::epsilon > 0.000099
                     && decltype (1.000'5_d)::epsilon < 0.000101);
      // Without decimals, the epsilon is one unit.
      static_assert (decltype (2._d)::epsilon > 0.99
                     && decltype (2._d)::epsilon < 1.01);

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

      // There are no string operators; the standard ones compare strings,
      // also in the application code that follows the using directive.
      static_assert (
          std::is_same_v<equal_t<std::string_view, std::string_view>, bool>);
      static_assert (
          std::is_same_v<equal_t<std::string, std::string_view>, bool>);
      static_assert (
          std::is_same_v<equal_t<std::string_view, const char*>, bool>);
      static_assert (std::is_same_v<equal_t<std::string, std::string>, bool>);
      static_assert (std::is_same_v<equal_t<std::string, const char*>, bool>);

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
      // must not reveal a standard implementation that it did not choose.
#if defined(__cpp_lib_source_location)
      static_assert (
          std::is_same_v<reflection::source_location, std::source_location>);
#endif // defined(__cpp_lib_source_location)
    }

    {
      // The counters are a value type, so that a test can take a snapshot
      // of them.
      static_assert (std::is_trivially_copyable_v<counters>);
      static_assert (std::is_nothrow_copy_constructible_v<counters>);
      static_assert (std::is_nothrow_copy_assignable_v<counters>);
      static_assert (std::is_nothrow_move_constructible_v<counters>);
      static_assert (std::is_nothrow_move_assignable_v<counters>);
    }

    {
      struct unformatted
      {
      };

      // The messages accept the values that the formatter writes, as the
      // expressions do.
      static_assert (extension::printable<const char*>);
      static_assert (extension::printable<char[4]>);
      static_assert (extension::printable<std::string>);
      static_assert (extension::printable<char>);
      static_assert (extension::printable<bool>);
      static_assert (extension::printable<int>);
      static_assert (extension::printable<long double>);
      static_assert (extension::printable<std::nullptr_t>);
      static_assert (extension::printable<int*>);
      static_assert (extension::printable<std::vector<int>>);
      static_assert (extension::printable<std::pair<int, char>>);
      static_assert (extension::printable<to_i>);
      static_assert (not extension::printable<unformatted>);
      static_assert (not extension::printable<with_extension::marker_only>);
    }

    {
      using with_conversions::explicit_bool;
      using with_conversions::mutable_bool;

      struct no_conversion
      {
      };

      enum class scoped
      {
        zero
      };

      // The checks accept what an `if` statement accepts, including the
      // types with an `explicit operator bool`.
      static_assert (extension::checkable<bool>);
      static_assert (extension::checkable<int>);
      static_assert (extension::checkable<double>);
      static_assert (extension::checkable<int*>);
      static_assert (extension::checkable<std::nullptr_t>);
      static_assert (extension::checkable<to_i>);
      static_assert (extension::checkable<explicit_bool>);
      static_assert (extension::checkable<std::optional<int>>);
      static_assert (extension::checkable<std::unique_ptr<int>>);
      static_assert (extension::checkable<std::shared_ptr<int>>);
      static_assert (extension::checkable<std::function<void (void)>>);
      // The argument is `const`, so a non-`const` conversion is not usable.
      static_assert (not extension::checkable<mutable_bool>);
      // A scoped enumeration converts only with a cast.
      static_assert (not extension::checkable<scoped>);
      static_assert (not extension::checkable<std::string>);
      static_assert (not extension::checkable<no_conversion>);
    }

    {
      struct unformatted
      {
      };

      int number = 0;
      [[maybe_unused]] auto captureless = [] () noexcept { return 42; };
      [[maybe_unused]] auto capturing
          = [&number] () noexcept { return number; };
      [[maybe_unused]] auto no_result = [] () noexcept {};
      [[maybe_unused]] auto unformatted_result
          = [] () noexcept { return unformatted{}; };
      [[maybe_unused]] auto with_argument = [] (int i) noexcept { return i; };

      // The messages may be callable objects that return a printable
      // value, called only if the check fails.
      static_assert (detail::lazy_message<decltype (captureless)>);
      static_assert (detail::lazy_message<decltype (capturing)>);
      static_assert (detail::lazy_message<std::function<std::string (void)>>);
      static_assert (not detail::lazy_message<decltype (no_result)>);
      static_assert (not detail::lazy_message<decltype (unformatted_result)>);
      static_assert (not detail::lazy_message<decltype (with_argument)>);
      static_assert (not detail::lazy_message<std::function<void (void)>>);
      // The function pointers are printed, not called.
      static_assert (not detail::lazy_message<int (*) (void)>);
      static_assert (extension::printable<int (*) (void)>);
    }

    {
      using namespace literals;
      using namespace operators;

      [[maybe_unused]] const std::string str{ "abc" };
      [[maybe_unused]] int number = 1;
      [[maybe_unused]] const auto wrapped = to_i{ 1 };

      // The comparators refer to the named operands of class type, and
      // store by value the temporaries, which are moved, and the scalars.
      static_assert (
          std::is_same_v<decltype (eq (str, str)),
                         detail::compare_op<const std::string&,
                                            const std::string&,
                                            detail::equal_to>>);
      static_assert (
          std::is_same_v<decltype (eq (std::string{}, str)),
                         detail::compare_op<std::string, const std::string&,
                                            detail::equal_to>>);
      static_assert (
          std::is_same_v<decltype (eq (number, 1)),
                         detail::compare_op<int, int, detail::equal_to>>);
      static_assert (
          std::is_same_v<decltype (eq ("abc", str)),
                         detail::compare_op<detail::c_string,
                                            const std::string&,
                                            detail::equal_to>>);
      static_assert (
          std::is_same_v<decltype (wrapped == 1),
                         detail::compare_op<const to_i&, int,
                                            detail::equal_to>>);
      static_assert (
          std::is_same_v<decltype (to_i{ 1 } == 1_i),
                         detail::compare_op<to_i, decltype (1_i),
                                            detail::equal_to>>);

      // The nested expressions are stored as the operands are.
      using inner_t = decltype (eq (number, 1));
      static_assert (std::is_same_v<
                     decltype (both (std::declval<const inner_t&> (),
                                     eq (number, 2))),
                     detail::and_op<const inner_t&, inner_t>>);

      // A double negation negates the inner negation, instead of
      // copying it.
      static_assert (not not (1_i == 1_i));
      static_assert (
          std::is_same_v<decltype (not not (1_i == 1_i)),
                         detail::not_op<detail::not_op<
                             decltype (1_i == 1_i)>>>);
    }

#if defined(__cpp_exceptions)
    {
      [[maybe_unused]] auto returns = [] {};
      [[maybe_unused]] auto returns_int = [] { return 42; };

      // The exception checks keep only their result, so their types depend
      // on the expected exception, not on the callable.
      static_assert (std::is_same_v<decltype (throws (returns)),
                                    decltype (throws (returns_int))>);
      static_assert (std::is_same_v<decltype (throws<int> (returns)),
                                    decltype (throws<int> (returns_int))>);
      static_assert (std::is_same_v<decltype (nothrow (returns)),
                                    decltype (nothrow (returns_int))>);
      static_assert (not std::is_same_v<decltype (throws (returns)),
                                        decltype (throws<int> (returns))>);

      static_assert (extension::printable<decltype (throws (returns))>);
      static_assert (extension::printable<decltype (throws<int> (returns))>);
      static_assert (extension::printable<decltype (nothrow (returns))>);
    }
#endif // defined(__cpp_exceptions)
  }
}

// ----------------------------------------------------------------------------
