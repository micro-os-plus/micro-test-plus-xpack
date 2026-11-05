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
 * `negate()`, `all_of()`, and `any_of()`, `mut()`, the overloaded
 * operators, the user-defined literals, and `approx (value, epsilon)`,
 * and the members of the `detail::timestamp` class.
 *
 * The constructor of `detail::timestamp` that reads the system clock is
 * defined in `src/deprecated.cpp`, with `detail::read_clock()`, the
 * clock access used by `detail::stopwatch`.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace.
 *
 * This file is included by `deprecated.h`; the applications include
 * `micro-os-plus/micro-test-plus.h`, not this file.
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
#pragma GCC diagnostic ignored "-Wconversion"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wc++20-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  namespace detail::math
  {
    /**
     * @details
     * This function template provides a constexpr implementation for raising a
     * base value to a given exponent, supporting any types that allow
     * multiplication.
     *
     * The function starts from one and multiplies the result by the base
     * `exp` times. If the exponent is zero (or negative), the function
     * returns one (the multiplicative identity for the type).
     */
    template <class T, class Exp_T>
    constexpr auto
    pow (const T base, const Exp_T exp) noexcept -> T
    {
      T result{ 1 };
      for (Exp_T i{}; i < exp; ++i)
        result *= base;
      return result;
    }

    /**
     * @details
     * Walks the characters once, counting the decimal digits before the
     * first decimal point (`Fraction` false) or after it (`Fraction`
     * true); the digit separators are skipped.
     */
    template <bool Fraction, char... Cs>
    consteval auto
    count_literal_digits (void) -> std::size_t
    {
      std::size_t count = 0;
      bool is_fraction = false;
      for (const char c : { Cs... })
        {
          if (c == '.')
            {
              is_fraction = true;
            }
          else if (c >= '0' and c <= '9' and is_fraction == Fraction)
            {
              ++count;
            }
        }
      return count;
    }

    /**
     * @details
     * This function template performs compile-time parsing of a numeric value
     * from a sequence of characters, typically provided as a template
     * parameter pack.
     *
     * The characters must be decimal digits, a dot (`.`), or digit
     * separators (`'`), which are skipped; otherwise (e.g. an exponent) the
     * compilation fails with an explicit message, as it does if the
     * integral part has more digits than `T` can always hold. Parsing stops
     * at the first dot, allowing the function to extract only the integral
     * part of the number.
     */
    template <class T, char... Cs>
    consteval auto
    num (void) -> T
    {
      static_assert (
          ((Cs == '.' or Cs == '\'' or (Cs >= '0' and Cs <= '9')) and ...),
          "µTest++: a floating-point literal must be written with decimal "
          "digits and a decimal point, without an exponent");
      static_assert (
          count_literal_digits<false, Cs...> ()
              <= static_cast<std::size_t> (std::numeric_limits<T>::digits10),
          "µTest++: the floating-point literal has too many "
          "digits before the decimal point");
      T result{};
      for (const char c : { Cs... })
        {
          if (c == '.')
            {
              break;
            }
          if (c >= '0' and c <= '9')
            {
              result = static_cast<T> (result * static_cast<T> (10)
                                       + static_cast<T> (c - '0'));
            }
        }
      return result;
    }

    /**
     * @details
     * This function template performs compile-time extraction of the decimal
     * (fractional) part from a sequence of characters, typically provided as a
     * template parameter pack.
     *
     * The function expects the character sequence to represent a numeric
     * value, where all characters are either digits, a dot (`.`), or an
     * apostrophe (`'`). Parsing begins after the first dot, accumulating the
     * decimal digits as an integer value and skipping the digit separators
     * (e.g. `1.25` yields 25), so that `den() / 10^den_size()` gives the
     * fraction. If the result could exceed `T`, the compilation fails with
     * an explicit message.
     */
    template <class T, char... Cs>
    consteval auto
    den (void) -> T
    {
      static_assert ((... || (Cs == '.')),
                     "den(): no decimal point in literal");
      // The result has as many digits as the decimals, and it must fit in
      // `T`.
      static_assert (
          count_literal_digits<true, Cs...> ()
              <= static_cast<std::size_t> (std::numeric_limits<T>::digits10),
          "µTest++: the floating-point literal has too many "
          "decimals");
      T result{};
      bool is_fraction = false;
      for (const char c : { Cs... })
        {
          if (c == '.')
            {
              is_fraction = true;
            }
          else if (is_fraction and c >= '0' and c <= '9')
            {
              // The digit separators are skipped.
              result = static_cast<T> (result * static_cast<T> (10)
                                       + static_cast<T> (c - '0'));
            }
        }
      return result;
    }

    /**
     * @details
     * This function template determines, at compile time, the number of
     * decimal (fractional) digits present in a numeric value represented by a
     * character sequence, typically provided as a template parameter pack.
     *
     * The function expects the character sequence to represent a numeric
     * value, where all characters are either digits, a dot (`.`), or an
     * apostrophe (`'`). It returns the number of digits that follow the
     * first dot (the digit separators are not counted; e.g. 2 for `1.25`),
     * which is the scale of the value returned by `den()`.
     */
    template <class T, char... Cs>
    consteval auto
    den_size (void) -> T
    {
      static_assert ((... || (Cs == '.')),
                     "den_size(): no decimal point in literal");
      return static_cast<T> (count_literal_digits<true, Cs...> ());
    }

    /**
     * @details
     * This function template determines the number of decimal (fractional)
     * digits present in a floating-point value, with a precision of about
     * seven digits. Being `constexpr`, it can also be evaluated at compile
     * time.
     *
     * The function repeatedly multiplies the absolute value by ten,
     * incrementing a counter until the distance to the nearest integer is
     * at most a defined precision threshold (1e-7). Using the distance to
     * the nearest integer, not the fractional part, prevents the rounding
     * noise of a value just below an integer (e.g. 2674.9999999999995) from
     * being taken as more decimals.
     *
     * The nearest integer is never zero: while the scaled value is below
     * one, its distance to one is used, so that the leading zeros of a
     * small value are counted as decimals, as in its notation (12 for
     * `1e-12`), instead of the count stopping as soon as the scaled value
     * is below the threshold. A zero value has no significant digit, and
     * the result is zero.
     *
     * The loop also stops when the value reaches the magnitude from which
     * the type can represent only integers (2^23 for `float`, 2^52 for
     * `double`), limited to 2^63 so that the conversion to
     * `unsigned long long` is always defined. This bounds the number of
     * steps for large values, infinities, and NaNs, for which the result
     * is one; for small values, the number of steps is bounded by the
     * decimal exponent of the smallest value of the type.
     */
    template <class T, class Value_T>
    constexpr auto
    count_decimals (Value_T value) -> T
    {
      constexpr auto precision = Value_T (1e-7);
      // From this magnitude upwards all values are integers.
      constexpr auto integral_limit
          = min_value (Value_T (1) / std::numeric_limits<Value_T>::epsilon (),
                       Value_T (1ULL << 63));

      value = abs (value);

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif // defined(__GNUC__)
      if (value == Value_T (0))
        {
          // A zero has no decimals.
          return T{};
        }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

      T result{};
      for (;;)
        {
          value *= 10;
          ++result;

          // Also true for infinities and NaNs.
          if (not(value < integral_limit))
            {
              break;
            }

          const auto fraction = value
                                - static_cast<Value_T> (
                                    static_cast<unsigned long long> (value));
          // Below one, the distance is to one, not to zero, so that the
          // leading zeros of a small value are counted.
          const auto distance
              = (value < Value_T (1))
                    ? Value_T (1) - fraction
                    : min_value (fraction, Value_T (1) - fraction);
          if (distance <= precision)
            {
              break;
            }
        }

      return result;
    }

    /**
     * @details
     * The number of decimal places is computed by `count_decimals()`, and
     * the tolerance is one divided by ten raised to that number, as for the
     * floating-point literals, which use the decimals written.
     *
     * A zero value has no decimals, and gets a zero tolerance, so that it
     * is compared exactly; a tolerance of one unit of an arbitrary decimal
     * would make the zero equal to unrelated small values. A zero
     * tolerance is also returned when ten raised to the number of decimals
     * would exceed the range of `Value_T` (values below about `1e-308` for
     * `double`), instead of computing an infinite power.
     */
    template <class Value_T>
    constexpr auto
    decimal_epsilon (Value_T value) -> Value_T
    {
      const auto decimals = count_decimals<unsigned long long> (value);
      if (decimals == 0
          or decimals > static_cast<unsigned long long> (
                 std::numeric_limits<Value_T>::max_exponent10))
        {
          return Value_T{};
        }
      return Value_T (1) / pow (Value_T (10), decimals);
    }

    /**
     * @details
     * The characters are those of a valid C++ literal, already checked by
     * the compiler (digits valid for the base, digit separators in valid
     * positions). The base is given by the prefix: `0x` or `0X` for
     * hexadecimal, `0b` or `0B` for binary, a leading `0` for octal, and
     * none for decimal. The digit separators (`'`) are skipped.
     *
     * Any other character (a decimal point, an exponent, or a digit not
     * valid for the base, as in the floating-point literal `09.5`) marks
     * the literal as not an integer. The value is accumulated in
     * `unsigned long long`, and the accumulation stops if it would
     * overflow.
     */
    template <char... Cs>
    consteval auto
    parse_integer_literal (void) -> integer_literal
    {
      constexpr std::array<char, sizeof...(Cs)> cs{ Cs... };
      constexpr unsigned long long max_value
          = std::numeric_limits<unsigned long long>::max ();

      integer_literal result{ 0, true, false };

      unsigned long long base = 10;
      std::size_t i = 0;
      if (cs.size () > 1 && cs[0] == '0')
        {
          if (cs[1] == 'x' || cs[1] == 'X')
            {
              base = 16;
              i = 2;
            }
          else if (cs[1] == 'b' || cs[1] == 'B')
            {
              base = 2;
              i = 2;
            }
          else
            {
              base = 8;
              i = 1;
            }
        }

      for (; i < cs.size (); ++i)
        {
          const char c = cs[i];
          if (c == '\'')
            {
              continue;
            }

          unsigned long long digit = 0;
          if (c >= '0' && c <= '9')
            {
              digit = static_cast<unsigned long long> (c - '0');
            }
          else if (base == 16 && c >= 'a' && c <= 'f')
            {
              digit = static_cast<unsigned long long> (c - 'a' + 10);
            }
          else if (base == 16 && c >= 'A' && c <= 'F')
            {
              digit = static_cast<unsigned long long> (c - 'A' + 10);
            }
          else
            {
              // A decimal point, an exponent, or a suffix character.
              result.is_integer = false;
              return result;
            }

          if (digit >= base)
            {
              // Possible only in a floating-point literal, like `09.5`.
              result.is_integer = false;
              return result;
            }

          if (result.value > (max_value - digit) / base)
            {
              result.is_too_large = true;
              return result;
            }

          result.value = result.value * base + digit;
        }

      return result;
    }

    /**
     * @details
     * The literal must be an integer literal, in any of the C++ forms
     * (decimal, hexadecimal, binary, or octal, with digit separators), and
     * its value must fit in `T`; otherwise the compilation fails with an
     * explicit message.
     *
     * Negative values are obtained with the unary minus, so the literal
     * itself is never negative. For the signed types, the limit is the
     * absolute value of the minimum, `max () + 1`, so that the minimum can
     * be written (e.g. `-128_i8`); the caller allows this magnitude only
     * when it is negated.
     *
     * When a check fails, zero is returned, so that the callers report no
     * further errors.
     */
    template <class T, char... Cs>
    consteval auto
    integer_magnitude (void) -> unsigned long long
    {
      constexpr integer_literal literal = parse_integer_literal<Cs...> ();
      constexpr unsigned long long max_magnitude
          = static_cast<unsigned long long> (std::numeric_limits<T>::max ())
            + (std::numeric_limits<T>::is_signed ? 1u : 0u);
      constexpr bool fits = literal.is_integer && !literal.is_too_large
                            && literal.value <= max_magnitude;

      static_assert (literal.is_integer,
                     "µTest++: an integer literal must not have a decimal "
                     "point or an exponent");
      static_assert (!literal.is_integer || !literal.is_too_large,
                     "µTest++: the integer literal is too large");
      static_assert (!literal.is_integer || literal.is_too_large || fits,
                     "µTest++: the integer literal value does not fit in the "
                     "type of the literal");

      return fits ? literal.value : 0;
    }

    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
  } // namespace detail::math

  namespace detail
  {
    // ========================================================================

    /**
     * @details
     * Stores the supplied value in the `value_` member.
     */
    template <class T>
    constexpr value_base<T>::value_base (const T& v) noexcept : value_{ v }
    {
    }

    /**
     * @details
     * Allows explicit conversion to the encapsulated value.
     */
    template <class T>
    constexpr value_base<T>::
    operator T () const noexcept
    {
      return value_;
    }

    /**
     * @details
     * Returns a `const` reference to the stored value, valid as long as
     * the wrapper.
     */
    template <class T>
    constexpr const T&
    value_base<T>::get (void) const noexcept
    {
      return value_;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Delegates to `value_base<decltype(N)>{ N }` to initialise the base.
     */
    template <auto N>
    constexpr integral_constant<N>::integral_constant (void) noexcept
        : value_base<decltype (N)>{ N }
    {
    }

    /**
     * @details
     * The built-in unary minus promotes the types narrower than `int`, so
     * its result is converted back to the type of `N`. For the unsigned
     * types, the value is subtracted from zero, which, after the
     * conversion, gives the value modulo 2^n for all widths. For the signed
     * types, the minimum is rejected before the negation, which would
     * otherwise overflow for `int` and the wider types.
     */
    template <auto N>
    constexpr auto
    integral_constant<N>::operator- () const noexcept
    {
      using value_type = decltype (N);

      if constexpr (!std::is_signed_v<value_type>)
        {
          return integral_constant<static_cast<value_type> (value_type{}
                                                            - N)>{};
        }
      else if constexpr (N == std::numeric_limits<value_type>::min ())
        {
          static_assert (N != std::numeric_limits<value_type>::min (),
                         "µTest++: the negation of the minimum value does "
                         "not fit in the type of the literal");
          return *this;
        }
      else
        {
          return integral_constant<static_cast<value_type> (-N)>{};
        }
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Returns the minimum of `T`, which is the negation of the absolute
     * value represented by this type.
     */
    template <class T>
    constexpr auto
    integral_min_magnitude<T>::operator- () const noexcept
    {
      return integral_constant<std::numeric_limits<T>::min ()>{};
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * The value is checked by `math::integer_magnitude()`, which accepts,
     * for the signed types, the absolute value of the minimum; this
     * value does not fit in `T`, so it is represented by
     * `integral_min_magnitude<T>`.
     */
    template <class T, char... Cs>
    constexpr auto
    integral_literal (void)
    {
      constexpr unsigned long long magnitude
          = math::integer_magnitude<T, Cs...> ();

      if constexpr (magnitude > static_cast<unsigned long long> (
                        std::numeric_limits<T>::max ()))
        {
          return integral_min_magnitude<T>{};
        }
      else
        {
          return integral_constant<static_cast<T> (magnitude)>{};
        }
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Returns the compile-time constant value as type `T`.
     */
    template <class T, auto N, auto D, auto Size, auto P>
    constexpr floating_point_constant<T, N, D, Size, P>::
    operator T () const noexcept
    {
      return value;
    }

    /**
     * @details
     * Returns the compile-time constant value as type `T`.
     */
    template <class T, auto N, auto D, auto Size, auto P>
    constexpr T
    floating_point_constant<T, N, D, Size, P>::get (void) const noexcept
    {
      return value;
    }

    /**
     * @details
     * Returns a new `floating_point_constant` instance representing the
     * negative of the current value by flipping the sign parameter `P`.
     */
    template <class T, auto N, auto D, auto Size, auto P>
    constexpr auto
    floating_point_constant<T, N, D, Size, P>::operator- () const noexcept
    {
      return floating_point_constant<T, N, D, Size, -P>{};
    }

    // ------------------------------------------------------------------------

    template <class T>
    constexpr value<T>::value (const T& _value) noexcept
        : value_base<T>{ _value }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Stores the view of the name; the characters are not copied.
     */
    constexpr named_bool::named_bool (std::string_view name) noexcept
        : name_{ name }
    {
    }

    /**
     * @details
     * Always returns `true`, the value of all named boolean constants.
     */
    constexpr named_bool::
    operator value_type () const noexcept
    {
      return true;
    }

    /**
     * @details
     * Returns the stored view of the name.
     */
    constexpr std::string_view
    named_bool::name (void) const noexcept
    {
      return name_;
    }

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------

  /**
   * @details
   * Forwards to `negate()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  // Deprecated since 6.0.0; use negate().
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
  // Deprecated since 6.0.0; use all_of().
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
  // Deprecated since 6.0.0; use any_of().
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _or (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return any_of (std::forward<Lhs_T> (lhs), std::forward<Rhs_T> (rhs));
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Removes the `const` qualifier from the reference with `const_cast`.
   */
  // Deprecated since 6.0.0; use const_cast<T&>.
  template <class T>
  constexpr auto
  mut (const T& t) noexcept -> T&
  {
    return const_cast<T&> (t);
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
  // Deprecated since 6.0.0, as the whole `timestamp` class; the timings are
  // internal.
  inline timestamp::timestamp (const timespec& ts) noexcept : value_{ ts }
  {
  }

  /**
   * @details
   * Returns `true` if either the seconds or the nanoseconds member is
   * not zero.
   */
  // Deprecated since 6.0.0, as the whole `timestamp` class; the timings are
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
  // Deprecated since 6.0.0, as the whole `timestamp` class; the timings are
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
  // Deprecated since 6.0.0, as the whole `timestamp` class; the timings are
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
