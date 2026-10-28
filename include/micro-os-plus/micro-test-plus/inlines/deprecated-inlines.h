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
 * @brief C++ header file with inline implementations for the deprecated
 * µTest++ definitions.
 *
 * @details
 * This header provides the inline implementations for the deprecated
 * definitions declared in `deprecated.h`: the v5.0.1 names of the
 * logical functions (`_not`, `_and`, and `_or`), which forward to
 * `negate()`, `all_of()`, and `any_of()`, the overloaded operators, the
 * user-defined literals, and `approx (value, epsilon)`, and the members
 * of the `detail::timestamp` class.
 *
 * The constructor of `detail::timestamp` that reads the system clock is
 * defined in `src/deprecated.cpp`, with `detail::read_clock()`, the
 * clock access used by `detail::stopwatch`.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEPRECATED_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEPRECATED_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Forwards to `negate()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  // Deprecated since 5.1.0; use negate().
  template <class Expr_T>
  constexpr auto
  _not (Expr_T&& expr)
  {
    return negate (std::forward<Expr_T> (expr));
  }

  /**
   * @details
   * Forwards to `all_of()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  // Deprecated since 5.1.0; use all_of().
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _and (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return all_of (std::forward<Lhs_T> (lhs), std::forward<Rhs_T> (rhs));
  }

  /**
   * @details
   * Forwards to `any_of()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  // Deprecated since 5.1.0; use any_of().
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _or (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return any_of (std::forward<Lhs_T> (lhs), std::forward<Rhs_T> (rhs));
  }

  // --------------------------------------------------------------------------

  namespace operators
  {
    // ========================================================================

    /**
     * @details
     * Constructs a comparator object, with the `equal_to` tag, from the two
     * operands and returns it. The comparator evaluates to `true` if the
     * operands are equal. At least one operand must be a framework type (see
     * `extension::is_op`).
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    constexpr auto
    operator== (Lhs_T&& lhs, Rhs_T&& rhs)
    {
      return detail::compare_op{ std::forward<Lhs_T> (lhs),
                                 std::forward<Rhs_T> (rhs),
                                 detail::equal_to{} };
    }

    /**
     * @details
     * Constructs a comparator object, with the `not_equal_to` tag, from the
     * two operands and returns it. The comparator evaluates to `true` if the
     * operands are not equal. At least one operand must be a framework type
     * (see `extension::is_op`).
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    constexpr auto
    operator!= (Lhs_T&& lhs, Rhs_T&& rhs)
    {
      return detail::compare_op{ std::forward<Lhs_T> (lhs),
                                 std::forward<Rhs_T> (rhs),
                                 detail::not_equal_to{} };
    }

    /**
     * @details
     * Constructs a comparator object, with the `greater` tag, from the two
     * operands and returns it. The comparator evaluates to `true` if `lhs` is
     * greater than `rhs`. At least one operand must be a framework type (see
     * `extension::is_op`).
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    constexpr auto
    operator> (Lhs_T&& lhs, Rhs_T&& rhs)
    {
      return detail::compare_op{ std::forward<Lhs_T> (lhs),
                                 std::forward<Rhs_T> (rhs),
                                 detail::greater{} };
    }

    /**
     * @details
     * Constructs a comparator object, with the `greater_equal` tag, from the
     * two operands and returns it. The comparator evaluates to `true` if `lhs`
     * is greater than or equal to `rhs`. At least one operand must be a
     * framework type (see `extension::is_op`).
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    constexpr auto
    operator>= (Lhs_T&& lhs, Rhs_T&& rhs)
    {
      return detail::compare_op{ std::forward<Lhs_T> (lhs),
                                 std::forward<Rhs_T> (rhs),
                                 detail::greater_equal{} };
    }

    /**
     * @details
     * Constructs a comparator object, with the `less` tag, from the two
     * operands and returns it. The comparator evaluates to `true` if `lhs` is
     * less than `rhs`. At least one operand must be a framework type (see
     * `extension::is_op`).
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    constexpr auto
    operator< (Lhs_T&& lhs, Rhs_T&& rhs)
    {
      return detail::compare_op{ std::forward<Lhs_T> (lhs),
                                 std::forward<Rhs_T> (rhs), detail::less{} };
    }

    /**
     * @details
     * Constructs a comparator object, with the `less_equal` tag, from the two
     * operands and returns it. The comparator evaluates to `true` if `lhs` is
     * less than or equal to `rhs`. At least one operand must be a framework
     * type (see `extension::is_op`).
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    constexpr auto
    operator<= (Lhs_T&& lhs, Rhs_T&& rhs)
    {
      return detail::compare_op{ std::forward<Lhs_T> (lhs),
                                 std::forward<Rhs_T> (rhs),
                                 detail::less_equal{} };
    }

    /**
     * @details
     * Constructs an `and_op` logical conjunction object from the two operands
     * and returns it. The object evaluates to `true` if both operands are
     * true. At least one operand must be a framework type (see
     * `extension::is_op`).
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    constexpr auto
    operator and (Lhs_T&& lhs, Rhs_T&& rhs)
    {
      return detail::and_op{ std::forward<Lhs_T> (lhs),
                             std::forward<Rhs_T> (rhs) };
    }

    /**
     * @details
     * Constructs an `or_op` logical disjunction object from the two operands
     * and returns it. The object evaluates to `true` if at least one operand
     * is true. At least one operand must be a framework type (see
     * `extension::is_op`).
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    constexpr auto
    operator or (Lhs_T&& lhs, Rhs_T&& rhs)
    {
      return detail::or_op{ std::forward<Lhs_T> (lhs),
                            std::forward<Rhs_T> (rhs) };
    }

    /**
     * @details
     * Constructs a `not_op` logical negator object from the operand and
     * returns it. The object evaluates to `true` if the operand is false. The
     * operand must be a framework type (see `extension::is_op`).
     */
    template <class T>
      requires extension::is_op<std::remove_cvref_t<T>>
    constexpr auto
    operator not(T&& t)
    {
      // Not `not_op{ t }`, which would copy an operand that is itself
      // a `not_op`, instead of negating it.
      return detail::not_op<detail::stored_operand_t<T>>{ std::forward<T> (
          t) };
    }

    // ------------------------------------------------------------------------
  } // namespace operators

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

} // namespace micro_os_plus::micro_test_plus

// ============================================================================

namespace micro_os_plus::micro_test_plus::detail
{
  // ==========================================================================

  /**
   * @details
   * Copies @p ts into the stored value.
   */
  // Deprecated since 5.1.0, as the whole `timestamp` class; the timings are
  // internal.
  inline timestamp::timestamp (const timespec& ts) noexcept : value_{ ts }
  {
  }

  /**
   * @details
   * Returns `true` if either the seconds or the nanoseconds member is
   * not zero.
   */
  // Deprecated since 5.1.0, as the whole `timestamp` class; the timings are
  // internal.
  inline bool
  timestamp::has_clock (void) const noexcept
  {
    return value_.tv_sec != 0 || value_.tv_nsec != 0;
  }

  /**
   * @details
   * The caller may modify the stored time through the returned
   * reference.
   */
  // Deprecated since 5.1.0, as the whole `timestamp` class; the timings are
  // internal.
  inline timespec&
  timestamp::value (void) noexcept
  {
    return value_;
  }

  /**
   * @details
   * The returned reference is valid as long as the object exists.
   */
  // Deprecated since 5.1.0, as the whole `timestamp` class; the timings are
  // internal.
  inline const timespec&
  timestamp::value (void) const noexcept
  {
    return value_;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEPRECATED_INLINES_H_

// ----------------------------------------------------------------------------
