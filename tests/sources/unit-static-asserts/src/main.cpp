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

#include "micro-os-plus/platform.h"
#include "micro-os-plus/micro-test-plus.h"

namespace mt = micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
// Most of the checks in this file verify, at compile time, the literals,
// the type wrappers, and the operators, which are deprecated but still
// available; they cost nothing at run time, so they are kept here until
// the features are removed.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

namespace with_operators
{
  using namespace mt::operators;

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
  concept formattable = requires (mt::expression_formatter& formatter,
                                  const T& t) { formatter << t; };

  // A type with only the expression marker, and no formatter overload,
  // which the generic overload used to select and call recursively (#149).
  struct marker_only
  {
    using op_type = mt::detail::op;

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

namespace with_comparators
{
  // A type that can be compared, but not reported, since it has no
  // `operator<<` for the formatter.
  struct unreported
  {
    int id;

    constexpr auto
    operator<=> (const unreported&) const
        = default;
  };

  // Satisfied when all the function comparators accept the operands.
  template <class Lhs_T, class Rhs_T>
  concept all_accept = requires (const Lhs_T& lhs, const Rhs_T& rhs) {
    mt::eq (lhs, rhs);
    mt::ne (lhs, rhs);
    mt::gt (lhs, rhs);
    mt::ge (lhs, rhs);
    mt::lt (lhs, rhs);
    mt::le (lhs, rhs);
  };

  // Satisfied when at least one function comparator accepts the operands.
  template <class Lhs_T, class Rhs_T>
  concept any_accepts
      = requires (const Lhs_T& lhs, const Rhs_T& rhs) { mt::eq (lhs, rhs); }
        or requires (const Lhs_T& lhs, const Rhs_T& rhs) { mt::ne (lhs, rhs); }
        or requires (const Lhs_T& lhs, const Rhs_T& rhs) { mt::gt (lhs, rhs); }
        or requires (const Lhs_T& lhs, const Rhs_T& rhs) { mt::ge (lhs, rhs); }
        or requires (const Lhs_T& lhs, const Rhs_T& rhs) { mt::lt (lhs, rhs); }
        or requires (const Lhs_T& lhs, const Rhs_T& rhs) {
             mt::le (lhs, rhs);
           };
} // namespace with_comparators

// ----------------------------------------------------------------------------

namespace with_ranges
{
  // A range whose elements are of its own type, like
  // std::filesystem::path; only declared, as it is not iterated.
  struct self_range
  {
    const self_range*
    begin (void) const;

    const self_range*
    end (void) const;
  };

  // A type with begin() and end() members that do not return iterators,
  // like a transaction; only declared, as it is not iterated.
  struct transaction
  {
    void
    begin (void) const;

    void
    end (void) const;
  };

  // A range with begin() and end() functions, found by argument-dependent
  // lookup; only declared, as it is not iterated.
  struct number_pair
  {
    int numbers[2];
  };

  const int*
  begin (const number_pair& p);

  const int*
  end (const number_pair& p);
} // namespace with_ranges

// ----------------------------------------------------------------------------

namespace
{
  // Whether a suite can be added to a runner with a name of the given type.
  template <class Name_T>
  concept can_add_suite = requires (mt::runner& r, Name_T name) {
    r.add_suite (name, [] (mt::suite&) {});
  };

  // Whether the top suite can be added with a name of the given type.
  template <class Name_T>
  concept can_add_top_suite
      = requires (mt::runner& r, Name_T name) { r.add_top_suite (name); };
} // namespace

int
main ([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  // --------------------------------------------------------------------------

  {
    static_assert (std::is_convertible_v<const char*, mt::test_case_name>);
    static_assert (std::is_convertible_v<std::string, mt::test_case_name>);
    // Not null-terminated, so not accepted.
    static_assert (
        !std::is_convertible_v<std::string_view, mt::test_case_name>);
  }

  // The names of the suites are accepted as those of the test cases:
  // a C string or a `std::string`, but not a `std::string_view`.
  {
    static_assert (can_add_suite<const char*>);
    static_assert (can_add_suite<const char (&)[5]>);
    static_assert (can_add_suite<std::string>);
    static_assert (can_add_suite<const std::string&>);
    static_assert (!can_add_suite<std::string_view>);

    static_assert (can_add_top_suite<const char*>);
    static_assert (can_add_top_suite<const std::string&>);
    static_assert (!can_add_top_suite<std::string_view>);

    using body_t = void (*) (mt::suite&);
    static_assert (std::is_constructible_v<mt::static_suite, const char*,
                                           mt::runner&, body_t>);
    static_assert (
        std::is_constructible_v<mt::static_suite, const std::string&,
                                mt::runner&, body_t>);
    static_assert (!std::is_constructible_v<mt::static_suite, std::string_view,
                                            mt::runner&, body_t>);
  }

  {
    static_assert (static_cast<int> (mt::verbosity::silent) == 0);
    static_assert (static_cast<int> (mt::verbosity::quiet) == 1);
    static_assert (static_cast<int> (mt::verbosity::normal) == 2);
    static_assert (static_cast<int> (mt::verbosity::verbose) == 3);
  }

  {
    struct foo
    {
      int value;
    };

    struct bar
    {
    };

    using namespace mt::literals;

    // Only the framework constants are detected, not the types of the
    // application with a member named `value`.
    static_assert (not mt::detail::has_value<foo>);
    static_assert (not mt::detail::has_value<bar>);
    static_assert (not mt::detail::has_value<int>);
    static_assert (not mt::detail::has_value<void>);
    static_assert (mt::detail::has_value<decltype (42_i)>);
    static_assert (mt::detail::has_value<decltype (1.5_d)>);
    static_assert (not mt::detail::has_value<mt::to_i>);
  }

  {
    struct foo
    {
    };

    static_assert (mt::detail::container_like<std::vector<int>>);
    static_assert (mt::detail::container_like<std::array<bool, 0>>);
    static_assert (mt::detail::container_like<std::string>);
    static_assert (mt::detail::container_like<std::string_view>);
    // static_assert (detail::container_like<std::map<int, int>>);
    static_assert (not mt::detail::container_like<int>);
    static_assert (not mt::detail::container_like<foo>);
    static_assert (not mt::detail::container_like<void>);
  }

  {
    using with_comparators::unreported;
    using with_ranges::number_pair;
    using with_ranges::self_range;
    using with_ranges::transaction;

    // The formatter writes element by element the ranges with members
    // or functions, except the arrays, the strings, the ranges of
    // their own type, and the ranges of elements that cannot be
    // reported.
    static_assert (mt::detail::formattable_range<std::vector<int>>);
    static_assert (
        mt::detail::formattable_range<std::vector<std::vector<int>>>);
    static_assert (mt::detail::formattable_range<std::array<bool, 0>>);
    static_assert (mt::detail::formattable_range<number_pair>);
    static_assert (mt::detail::free_range<number_pair>);
    static_assert (not mt::detail::formattable_range<int[2]>);
    static_assert (not mt::detail::formattable_range<std::string[2]>);
    static_assert (not mt::detail::formattable_range<std::string>);
    static_assert (not mt::detail::formattable_range<std::string_view>);
    static_assert (not mt::detail::formattable_range<self_range>);
    static_assert (not mt::detail::formattable_range<std::vector<unreported>>);
    static_assert (not mt::detail::formattable_range<int>);

    // The members must return iterators, otherwise the type is not a
    // range, instead of a hard error when forming the element type.
    static_assert (not mt::detail::container_like<transaction>);
    static_assert (not mt::detail::free_range<transaction>);
    static_assert (not mt::detail::formattable_range<transaction>);

    // So the ranges that cannot be reported are rejected by the
    // comparators.
    static_assert (mt::extension::printable<number_pair>);
    static_assert (not mt::extension::printable<self_range>);
    static_assert (not mt::extension::printable<std::vector<unreported>>);
    static_assert (not with_comparators::any_accepts<std::vector<unreported>,
                                                     std::vector<unreported>>);
  }

  {
    using namespace mt::literals;

    // The value wrappers are in `detail`, not in `extension`.
    static_assert (std::is_same_v<mt::to_i, mt::detail::value<int>>);
    static_assert (
        std::is_base_of_v<mt::detail::value<double>, mt::to_t<double>>);
    static_assert (
        std::is_same_v<decltype (42_i), mt::detail::integral_constant<42>>);
    static_assert (mt::extension::is_op<mt::to_i>);
    static_assert (mt::extension::is_op<decltype (42_i)>);
    static_assert (mt::extension::is_op<decltype (1.5_d)>);
    static_assert (mt::extension::is_op<mt::to_f>);
    static_assert (not mt::extension::is_op<int>);
    // The value wrappers must not have an empty base, which would
    // trigger the AArch64 GCC 10.1 `-Wpsabi` note for `approx()`.
    static_assert (not std::is_base_of_v<mt::detail::op, mt::to_f>);
    static_assert (mt::extension::has_epsilon<mt::to_d>);
    static_assert (mt::extension::has_epsilon<decltype (1.5_d)>);
    static_assert (not mt::extension::has_epsilon<mt::to_i>);
    static_assert (not mt::extension::has_epsilon<decltype (42_i)>);

    // Only the framework floating-point wrappers are detected, not the
    // types of the application with a member named `epsilon`.
    struct gauge
    {
      double epsilon;
    };
    static_assert (not mt::extension::has_epsilon<gauge>);
  }

  {
    using namespace mt::literals;
    using namespace with_extension;

    // The expressions of the application are evaluated as the built-in
    // ones, on the unwrapped operands, also at compile time (#149).
    static_assert (mt::extension::compare_op{ 3, 9, divides{} });
    static_assert (not mt::extension::compare_op{ 2, 9, divides{} });
    static_assert (
        mt::extension::compare_op{ 3_i, mt::to_i{ 12 }, divides{} });
    static_assert (mt::extension::predicate_op{ 4, even{} });
    static_assert (not mt::extension::predicate_op{ mt::to_i{ 7 }, even{} });
    static_assert (mt::extension::is_op<decltype (mt::extension::compare_op{
                       1, 2, divides{} })>);
    static_assert (mt::extension::is_op<decltype (mt::extension::predicate_op{
                       1, even{} })>);

    // The tolerance applies only to the tags that define its result.
    static_assert (mt::extension::compare_op{ mt::to_d{ 1.05, 0.1 }, 1.0,
                                              not_greater{} });
    static_assert (not mt::extension::compare_op{ mt::to_d{ 1.05, 0.1 }, 1.0,
                                                  exactly_not_greater{} });

    // The formatter writes the expressions and the value wrappers, and
    // rejects at compile time the types with only the marker (#149).
    static_assert (
        formattable<decltype (mt::extension::compare_op{ 1, 2, divides{} })>);
    static_assert (
        formattable<decltype (mt::extension::predicate_op{ 1, even{} })>);
    static_assert (formattable<mt::to_i>);
    static_assert (formattable<decltype (42_i)>);
    static_assert (mt::extension::is_op<marker_only>);
    static_assert (not formattable<marker_only>);
  }

  {
    // The mathematical utilities are in `detail::math`.
    static_assert (mt::detail::math::abs (-42) == 42);
    static_assert (mt::detail::math::min_value (1, 2) == 1);
    static_assert (mt::detail::math::pow (10, 3) == 1000);
    static_assert (mt::detail::math::integer_magnitude<int, '4', '2'> ()
                   == 42);
    static_assert (mt::detail::math::num<int, '1', '.', '2', '5'> () == 1);
    static_assert (mt::detail::math::den<int, '1', '.', '2', '5'> () == 25);
    static_assert (mt::detail::math::den_size<int, '1', '.', '2', '5'> ()
                   == 2);

    // The number of decimals of a run-time value is computed without
    // undefined behaviour for negative and large values (a compile-time
    // error in a constant expression), and is not affected by the
    // rounding noise below an integer.
    using ull = unsigned long long;
    static_assert (mt::detail::math::count_decimals<ull> (1.25) == 2);
    static_assert (mt::detail::math::count_decimals<ull> (2.0) == 1);
    static_assert (mt::detail::math::count_decimals<ull> (-2.25) == 2);
    static_assert (mt::detail::math::count_decimals<ull> (0.011) == 3);
    static_assert (mt::detail::math::count_decimals<ull> (42.42f) == 2);
    static_assert (mt::detail::math::count_decimals<ull> (1.25L) == 2);
    static_assert (mt::detail::math::count_decimals<ull> (1e20) == 1);
    static_assert (mt::detail::math::count_decimals<ull> (
                       std::numeric_limits<double>::infinity ())
                   == 1);

    // The leading zeros of a small value are counted as decimals, and a
    // zero has none, so its tolerance is zero, an exact comparison.
    static_assert (mt::detail::math::count_decimals<ull> (1e-8) == 8);
    static_assert (mt::detail::math::count_decimals<ull> (1e-12) == 12);
    static_assert (mt::detail::math::count_decimals<ull> (-2.5e-9) == 10);
    static_assert (mt::detail::math::count_decimals<ull> (1e-300) == 300);
    static_assert (mt::detail::math::count_decimals<ull> (1e-12L) == 12);
    static_assert (mt::detail::math::count_decimals<ull> (0.0) == 0);
    static_assert (mt::detail::math::count_decimals<ull> (-0.0f) == 0);
    static_assert (mt::detail::math::decimal_epsilon (1.25) > 0.0099
                   and mt::detail::math::decimal_epsilon (1.25) < 0.0101);
    static_assert (mt::detail::math::decimal_epsilon (1e-12) > 0.99e-12
                   and mt::detail::math::decimal_epsilon (1e-12) < 1.01e-12);
    static_assert (mt::detail::math::decimal_epsilon (0.0) <= 0.0);
    static_assert (mt::detail::math::decimal_epsilon (
                       std::numeric_limits<double>::denorm_min ())
                   <= 0.0);
  }

  {
    using namespace mt::literals;
    using namespace mt::operators;

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
    static_assert (std::is_same_v<decltype (-1_i8)::value_type, std::int8_t>);
    static_assert (decltype (-1_i8)::value == -1);
    static_assert (std::is_same_v<decltype (-1_s)::value_type, short>);
    static_assert (decltype (-1_s)::value == -1);
    static_assert (std::is_same_v<decltype (-1_u8)::value_type, std::uint8_t>);
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
    using namespace mt::literals;
    using namespace mt::operators;

    static_assert (not std::is_same_v<decltype (mt::to_sc{ 42 }),
                                      decltype (mt::to_c{ 42 })>);
    static_assert (not std::is_same_v<decltype (42_sc), decltype (42_c)>);
    static_assert (not std::is_same_v<decltype (mt::to_sc{ 42 }),
                                      decltype (mt::to_uc{ 42u })>);
    static_assert (not std::is_same_v<decltype (42_sc), decltype (42_uc)>);
  }

  {
    using namespace mt::literals;
    using namespace mt::operators;

    // The to_* wrappers.
    static_assert (mt::to_i{ 42 } == 42_i);
    static_assert (mt::to_b{ true });
    static_assert (not mt::to_b{ false });
    static_assert (mt::to_s{ 42 } == 42_s);
    static_assert (mt::to_c{ 42 } == 42_c);
    static_assert (mt::to_sc{ 42 } == 42_sc);
    static_assert (mt::to_l{ 42 } == 42_l);
    static_assert (mt::to_ll{ 42 } == 42_ll);
    static_assert (mt::to_u{ 42u } == 42_u);
    static_assert (mt::to_uc{ 42u } == 42_uc);
    static_assert (mt::to_us{ 42u } == 42_us);
    static_assert (mt::to_ul{ 42u } == 42_ul);
    static_assert (mt::to_ull{ 42u } == 42_ull);
    static_assert (mt::to_ull{ 18'446'744'073'709'551'615ull }
                   == 18'446'744'073'709'551'615_ull);

    // Generic to_t<T> wrapper (since 3.2.0).
    static_assert (mt::to_t<int>{ 42 }.get () == 42);
    static_assert (mt::to_t<bool>{ true }.get ());
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
        std::is_same_v<mt::reflection::source_location, std::source_location>);
#endif // defined(__cpp_lib_source_location)
  }

  {
    // The counters are a value type, so that a test can take a snapshot
    // of them.
    static_assert (std::is_trivially_copyable_v<mt::counters>);
    static_assert (std::is_nothrow_copy_constructible_v<mt::counters>);
    static_assert (std::is_nothrow_copy_assignable_v<mt::counters>);
    static_assert (std::is_nothrow_move_constructible_v<mt::counters>);
    static_assert (std::is_nothrow_move_assignable_v<mt::counters>);
  }

  {
    struct unformatted
    {
    };

    // The messages accept the values that the formatter writes, as the
    // expressions do.
    static_assert (mt::extension::printable<const char*>);
    static_assert (mt::extension::printable<char[4]>);
    static_assert (mt::extension::printable<std::string>);
    static_assert (mt::extension::printable<char>);
    static_assert (mt::extension::printable<bool>);
    static_assert (mt::extension::printable<int>);
    static_assert (mt::extension::printable<long double>);
    static_assert (mt::extension::printable<std::nullptr_t>);
    static_assert (mt::extension::printable<int*>);
    static_assert (mt::extension::printable<std::vector<int>>);
    static_assert (mt::extension::printable<std::pair<int, char>>);
    static_assert (mt::extension::printable<mt::to_i>);
    static_assert (not mt::extension::printable<unformatted>);

    // The pairs, tuples, optionals, and durations are printable only if
    // their elements are.
    static_assert (mt::extension::printable<std::tuple<int, char>>);
    static_assert (mt::extension::printable<std::optional<int>>);
    static_assert (
        mt::extension::printable<std::optional<std::pair<int, char>>>);
    static_assert (mt::extension::printable<std::chrono::milliseconds>);
    static_assert (mt::extension::printable<std::chrono::duration<double>>);
    static_assert (not mt::extension::printable<std::pair<int, unformatted>>);
    static_assert (not mt::extension::printable<std::pair<unformatted, int>>);
    static_assert (not mt::extension::printable<std::tuple<int, unformatted>>);
    static_assert (not mt::extension::printable<std::optional<unformatted>>);
    static_assert (not mt::extension::printable<
                   std::vector<std::pair<int, unformatted>>>);
    static_assert (
        not mt::extension::printable<std::chrono::duration<unformatted>>);

    // The test cases of a range of elements that cannot be printed are
    // numbered, instead of failing to compile; the function is not called.
    [[maybe_unused]] auto test_each_of_unformatted = [] (mt::suite& s)
      {
        s.test_each ("elements", std::vector<std::pair<int, unformatted>>{},
                     [] (mt::test_case&, const auto&) {});
      };
    static_assert (not mt::extension::printable<with_extension::marker_only>);
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
    static_assert (mt::extension::checkable<bool>);
    static_assert (mt::extension::checkable<int>);
    static_assert (mt::extension::checkable<double>);
    static_assert (mt::extension::checkable<int*>);
    static_assert (mt::extension::checkable<std::nullptr_t>);
    static_assert (mt::extension::checkable<mt::to_i>);
    static_assert (mt::extension::checkable<explicit_bool>);
    static_assert (mt::extension::checkable<std::optional<int>>);
    static_assert (mt::extension::checkable<std::unique_ptr<int>>);
    static_assert (mt::extension::checkable<std::shared_ptr<int>>);
    static_assert (mt::extension::checkable<std::function<void (void)>>);
    // The argument is `const`, so a non-`const` conversion is not usable.
    static_assert (not mt::extension::checkable<mutable_bool>);
    // A scoped enumeration converts only with a cast.
    static_assert (not mt::extension::checkable<scoped>);
    static_assert (not mt::extension::checkable<std::string>);
    static_assert (not mt::extension::checkable<no_conversion>);
    // The arguments that are always true are not accepted: a string
    // literal, a function name, and the pointers to functions, to
    // members, and to characters.
    static_assert (not mt::extension::checkable<char[4]>);
    static_assert (not mt::extension::checkable<int[3]>);
    static_assert (not mt::extension::checkable<void (void)>);
    static_assert (not mt::extension::checkable<void (*) (void)>);
    static_assert (not mt::extension::checkable<int no_conversion::*>);
    static_assert (not mt::extension::checkable<const char*>);
    static_assert (not mt::extension::checkable<wchar_t*>);
    static_assert (not mt::extension::checkable<const char8_t*>);
    static_assert (mt::extension::legacy_checkable<char[4]>);
    static_assert (mt::extension::legacy_checkable<void (void)>);
    static_assert (mt::extension::legacy_checkable<const char*>);
    static_assert (not mt::extension::legacy_checkable<bool>);
    static_assert (not mt::extension::legacy_checkable<no_conversion>);
  }

  {
    struct unformatted
    {
    };

    int number = 0;
    [[maybe_unused]] auto captureless = [] () noexcept { return 42; };
    [[maybe_unused]] auto capturing = [&number] () noexcept { return number; };
    [[maybe_unused]] auto no_result = [] () noexcept {};
    [[maybe_unused]] auto unformatted_result
        = [] () noexcept { return unformatted{}; };
    [[maybe_unused]] auto with_argument = [] (int i) noexcept { return i; };

    // The messages may be callable objects that return a printable
    // value, called only if the check fails.
    static_assert (mt::detail::lazy_message<decltype (captureless)>);
    static_assert (mt::detail::lazy_message<decltype (capturing)>);
    static_assert (
        mt::detail::lazy_message<std::function<std::string (void)>>);
    static_assert (not mt::detail::lazy_message<decltype (no_result)>);
    static_assert (
        not mt::detail::lazy_message<decltype (unformatted_result)>);
    static_assert (not mt::detail::lazy_message<decltype (with_argument)>);
    static_assert (not mt::detail::lazy_message<std::function<void (void)>>);
    // The function pointers are printed, not called.
    static_assert (not mt::detail::lazy_message<int (*) (void)>);
    static_assert (mt::extension::printable<int (*) (void)>);
  }

  {
    using namespace mt::literals;
    using int64_limits = std::numeric_limits<std::int64_t>;
    using uint64_limits = std::numeric_limits<std::uint64_t>;

    // The approximate comparator succeeds when the distance is less than
    // or equal to the tolerance.
    static_assert (mt::approx (10, 11, 2));
    static_assert (mt::approx (12, 10, 3));
    static_assert (mt::approx (10, 12, 2));
    static_assert (not mt::approx (10, 13, 2));
    static_assert (mt::approx (1.0, 1.05, 0.1));
    static_assert (not mt::approx (1.0, 1.2, 0.1));
    static_assert (mt::approx (10, 10.4, 0.5));
    static_assert (mt::approx (42_i, 43, 2));
    static_assert (mt::approx (mt::to_u16 (500), 512, 13));
    // The integer distance is exact, without wrap around or overflow.
    static_assert (mt::approx (5u, 3u, 3));
    static_assert (mt::approx (3u, 5u, 2u));
    static_assert (not mt::approx (3u, 6u, 2u));
    static_assert (mt::approx (0u, -1, 2));
    static_assert (mt::approx (0u, -1, 1));
    static_assert (not mt::approx (0u, -2, 1));
    static_assert (
        not mt::approx (std::uint8_t{ 1 }, std::int8_t{ -128 }, 128));
    static_assert (mt::approx (std::uint8_t{ 1 }, std::int8_t{ -128 }, 129));
    static_assert (mt::approx (std::uint8_t{ 1 }, std::int8_t{ -128 }, 130));
    static_assert (
        mt::approx (uint64_limits::max (), uint64_limits::max () - 1, 2));
    static_assert (mt::approx (int64_limits::max (), int64_limits::min () + 1,
                               uint64_limits::max ()));
    static_assert (mt::approx (int64_limits::min (), int64_limits::max (),
                               uint64_limits::max ()));
    static_assert (not mt::approx (int64_limits::min (), int64_limits::max (),
                                   uint64_limits::max () - 1));
    static_assert (not mt::approx (uint64_limits::max (), std::int64_t{ -1 },
                                   uint64_limits::max ()));
    // A negative tolerance fails; a zero one requires equal values.
    static_assert (not mt::approx (1, 1, -1));
    static_assert (not mt::approx (1.0, 1.0, -1.0));
    static_assert (mt::approx (1, 1, 0));
    static_assert (mt::approx (1.0, 1.0, 0.0));
    static_assert (not mt::approx (1, 2, 0));
    static_assert (mt::extension::is_op<decltype (mt::approx (1, 2, 3))>);

    // The operands are numbers or framework wrappers.
    static_assert (mt::detail::approx_operand<int>);
    static_assert (mt::detail::approx_operand<const double&>);
    static_assert (mt::detail::approx_operand<signed char>);
    static_assert (mt::detail::approx_operand<mt::to_i>);
    static_assert (mt::detail::approx_operand<decltype (1.5_d)>);
    static_assert (not mt::detail::approx_operand<bool>);
    static_assert (not mt::detail::approx_operand<char>);
    static_assert (not mt::detail::approx_operand<char32_t>);
    static_assert (not mt::detail::approx_operand<const char*>);
    static_assert (not mt::detail::approx_operand<std::string>);
  }

  {
    using namespace mt::literals;
    using with_comparators::all_accept;
    using with_comparators::any_accepts;
    using with_comparators::unreported;

    // The function comparators accept only operands that can be
    // reported, so the others are rejected at the call.
    static_assert (unreported{ 1 } == unreported{ 1 });
    static_assert (not any_accepts<unreported, unreported>);
    static_assert (not any_accepts<unreported, int>);
    static_assert (not any_accepts<int, unreported>);
    static_assert (all_accept<int, long>);
    static_assert (all_accept<double, decltype (1.5_d)>);
    static_assert (all_accept<std::string, const char*>);
    static_assert (all_accept<std::vector<int>, std::vector<int>>);
    static_assert (all_accept<mt::to_i, int>);
  }

  {
    using namespace mt::literals;
    using namespace mt::operators;

    [[maybe_unused]] const std::string str{ "abc" };
    [[maybe_unused]] int number = 1;
    [[maybe_unused]] const auto wrapped = mt::to_i{ 1 };

    // The comparators refer to the named operands of class type, and
    // store by value the temporaries, which are moved, and the scalars.
    static_assert (
        std::is_same_v<
            decltype (mt::eq (str, str)),
            mt::detail::compare_op<const std::string&, const std::string&,
                                   mt::detail::equal_to>>);
    static_assert (
        std::is_same_v<decltype (mt::eq (std::string{}, str)),
                       mt::detail::compare_op<std::string, const std::string&,
                                              mt::detail::equal_to>>);
    static_assert (std::is_same_v<
                   decltype (mt::eq (number, 1)),
                   mt::detail::compare_op<int, int, mt::detail::equal_to>>);
    static_assert (
        std::is_same_v<
            decltype (mt::eq ("abc", str)),
            mt::detail::compare_op<mt::detail::c_string, const std::string&,
                                   mt::detail::equal_to>>);
    static_assert (
        std::is_same_v<decltype (wrapped == 1),
                       mt::detail::compare_op<const mt::to_i&, int,
                                              mt::detail::equal_to>>);
    static_assert (
        std::is_same_v<decltype (mt::to_i{ 1 } == 1_i),
                       mt::detail::compare_op<mt::to_i, decltype (1_i),
                                              mt::detail::equal_to>>);

    // The nested expressions are stored as the operands are.
    using inner_t = decltype (mt::eq (number, 1));
    static_assert (
        std::is_same_v<decltype (mt::all_of (std::declval<const inner_t&> (),
                                             mt::eq (number, 2))),
                       mt::detail::and_op<const inner_t&, inner_t>>);

    // More than two operands are folded from the left, and the results
    // are known at compile time.
    static_assert (
        std::is_same_v<decltype (mt::all_of (mt::eq (number, 1),
                                             mt::eq (number, 2),
                                             mt::eq (number, 3))),
                       mt::detail::and_op<
                           mt::detail::and_op<decltype (mt::eq (number, 1)),
                                              decltype (mt::eq (number, 2))>,
                           decltype (mt::eq (number, 3))>>);
    static_assert (mt::all_of (mt::eq (1, 1), mt::lt (1, 2), mt::ne (3, 4)));
    static_assert (
        not mt::all_of (mt::eq (1, 1), mt::lt (2, 2), mt::ne (3, 4)));
    static_assert (mt::any_of (mt::eq (1, 2), mt::eq (3, 4), mt::eq (5, 5)));
    static_assert (not mt::any_of (mt::eq (1, 2), mt::eq (3, 4), mt::eq (5, 6),
                                   mt::eq (7, 8)));

    // A double negation negates the inner negation, instead of
    // copying it.
    static_assert (not not(1_i == 1_i));
    static_assert (
        std::is_same_v<
            decltype (not not(1_i == 1_i)),
            mt::detail::not_op<mt::detail::not_op<decltype (1_i == 1_i)>>>);
  }

#if defined(__cpp_exceptions)
  {
    [[maybe_unused]] auto returns = [] {};
    [[maybe_unused]] auto returns_int = [] { return 42; };

    // The exception checks keep only their result, so their types depend
    // on the expected exception, not on the callable.
    static_assert (std::is_same_v<decltype (mt::throws (returns)),
                                  decltype (mt::throws (returns_int))>);
    static_assert (std::is_same_v<decltype (mt::throws<int> (returns)),
                                  decltype (mt::throws<int> (returns_int))>);
    static_assert (std::is_same_v<decltype (mt::nothrow (returns)),
                                  decltype (mt::nothrow (returns_int))>);
    static_assert (not std::is_same_v<decltype (mt::throws (returns)),
                                      decltype (mt::throws<int> (returns))>);

    static_assert (mt::extension::printable<decltype (mt::throws (returns))>);
    static_assert (
        mt::extension::printable<decltype (mt::throws<int> (returns))>);
    static_assert (mt::extension::printable<decltype (mt::nothrow (returns))>);
  }
#endif // defined(__cpp_exceptions)

  // Integers of different signedness are compared by value, not
  // converted to the unsigned type (-1 < 1u, -1 != UINT_MAX).
  {
    constexpr unsigned int umax = std::numeric_limits<unsigned int>::max ();

    static_assert (static_cast<bool> (mt::lt (-1, 1u)));
    static_assert (static_cast<bool> (mt::le (-1, 1u)));
    static_assert (static_cast<bool> (mt::gt (1u, -1)));
    static_assert (static_cast<bool> (mt::ge (1u, -1)));
    static_assert (static_cast<bool> (mt::ne (-1, umax)));
    static_assert (!static_cast<bool> (mt::eq (-1, umax)));
    static_assert (static_cast<bool> (mt::lt (-5LL, 5ULL)));
    static_assert (static_cast<bool> (mt::eq (3, 3u)));
    static_assert (static_cast<bool> (mt::lt (
        static_cast<signed char> (-1), static_cast<unsigned char> (1))));
    static_assert (static_cast<bool> (mt::eq ('a', 97)));
  }

  return 0;
}

// ----------------------------------------------------------------------------
