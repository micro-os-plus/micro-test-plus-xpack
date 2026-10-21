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
 * @brief C++ header file with inline implementations for the µTest++
 * internal detail namespace.
 *
 * @details
 * This header provides the out-of-line template and inline implementations
 * for all types declared in `detail.h`. It defines the bodies of the
 * `unwrap()` helper, the unary and binary operator base class templates, all
 * relational and logical comparator constructors, the callable operator
 * types (`throws_op`, `nothrow_op`), and the `append_number()` formatting
 * helper.
 *
 * Separating the implementations from the declarations keeps `detail.h`
 * concise and focused on the interface, whilst grouping the complex
 * lambda-based constructor bodies here for maintainability.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DETAIL_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DETAIL_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include <cerrno>
#include <cfloat>
#include <charconv>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  namespace detail
  {
    // ========================================================================

    /**
     * @details
     * If the type `T` is a framework type (see `extension::is_op`)
     * that provides a `get()` member function, it is invoked and its result
     * returned. Otherwise a reference to the argument itself is returned,
     * so that the types of the application, even those with a `get()`
     * member function, are compared with their own operators, without a
     * copy. The selection is performed at compile time via
     * `if constexpr` with an inline `requires` expression; the return
     * type is deduced with `decltype (auto)` from the selected branch.
     */
    template <class T>
    constexpr decltype (auto)
    unwrap (const T& t)
    {
      if constexpr (extension::is_op<T> && requires { t.get (); })
        return t.get ();
      else
        return t;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Stores the operand and the pre-computed boolean result of the
     * operation in the corresponding private members.
     */
    template <class T>
    template <class U>
    constexpr unary_op<T>::unary_op (U&& t, bool value)
        : t_{ std::forward<U> (t) }, value_{ value }
    {
    }

    /**
     * @details
     * Returns the pre-computed boolean result stored by the derived
     * comparator's constructor.
     */
    template <class T>
    constexpr unary_op<T>::
    operator bool () const
    {
      return value_;
    }

    /**
     * @details
     * Returns the operand, unwrapped by `detail::unwrap()` if it is a
     * framework wrapper type; the stored operand is not copied.
     */
    template <class T>
    constexpr decltype (auto)
    unary_op<T>::operand (void) const
    {
      return detail::unwrap (t_);
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Stores the two operands and the pre-computed boolean result of the
     * comparison in the corresponding private members.
     */
    template <class Lhs_T, class Rhs_T>
    template <class L, class R>
    constexpr binary_op<Lhs_T, Rhs_T>::binary_op (L&& lhs, R&& rhs, bool value)
        : lhs_{ std::forward<L> (lhs) }, rhs_{ std::forward<R> (rhs) },
          value_{ value }
    {
    }

    /**
     * @details
     * Returns the pre-computed boolean result stored by the derived
     * comparator's constructor.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr binary_op<Lhs_T, Rhs_T>::
    operator bool () const
    {
      return value_;
    }

    /**
     * @details
     * Returns the value of the left-hand operand, unwrapped by
     * `detail::unwrap()` if it is a framework wrapper type; the stored
     * operand is not copied.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr decltype (auto)
    binary_op<Lhs_T, Rhs_T>::lhs (void) const
    {
      return detail::unwrap (lhs_);
    }

    /**
     * @details
     * Returns the value of the right-hand operand, unwrapped by
     * `detail::unwrap()` if it is a framework wrapper type; the stored
     * operand is not copied.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr decltype (auto)
    binary_op<Lhs_T, Rhs_T>::rhs (void) const
    {
      return detail::unwrap (rhs_);
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * The tolerance is the smaller `epsilon` of the two operands, if both
     * have one, otherwise the `epsilon` of the operand that has one. The
     * operands are equal when the absolute value of their difference is
     * less than the tolerance.
     */
    template <class Lhs_T, class Rhs_T>
      requires (extension::has_epsilon<Lhs_T> or extension::has_epsilon<Rhs_T>)
    constexpr bool
    within_tolerance (const Lhs_T& lhs, const Rhs_T& rhs)
    {
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)
      const auto difference
          = math::abs (detail::unwrap (lhs) - detail::unwrap (rhs));
      if constexpr (extension::has_epsilon<Lhs_T>
                    and extension::has_epsilon<Rhs_T>)
        {
          // If both values have precision, use the smallest one.
          return difference < math::min_value (lhs.epsilon, rhs.epsilon);
        }
      else if constexpr (extension::has_epsilon<Lhs_T>)
        {
          return difference < lhs.epsilon;
        }
      else
        {
          return difference < rhs.epsilon;
        }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
    }

    // ------------------------------------------------------------------------

    // The operands are compared as they are, including mixed signedness
    // and mixed integer and floating-point types; the warnings would be
    // reported in the test code of the application, not in the library.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator==` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    equal_to::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator==;
      return lhs == rhs;
    }

    /**
     * @details
     * The using-declarations make the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup; `operator==` is also needed for the C++20 rewritten
     * candidates of `!=`.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    not_equal_to::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator==;
      using std::operator!=;
      return lhs != rhs;
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator>` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    greater::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator>;
      return lhs > rhs;
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator>=` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    greater_equal::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator>=;
      return lhs >= rhs;
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator<` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    less::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator<;
      return lhs < rhs;
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator<=` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    less_equal::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator<=;
      return lhs <= rhs;
    }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the comparison inside an immediately invoked lambda, which
     * converts the result of `Compare_T::apply()` to `bool`, and passes it
     * to the `binary_op` base class constructor:
     * - for the framework constants with static `value` members (the
     *   numeric literals), the two values are compared directly;
     * - if at least one operand is a framework floating-point wrapper with
     *   an `epsilon` member, and the tag defines a
     *   `within_tolerance_result` (all the built-in tags do), operands
     *   within the tolerance give this result; otherwise the unwrapped
     *   values are compared; the tags of the application without it
     *   ignore the tolerance;
     * - for all other types, the framework wrappers are unwrapped, and the
     *   values, including the types of the application, are compared as
     *   they are.
     */
    template <class Lhs_T, class Rhs_T, class Compare_T>
    template <class L, class R>
    constexpr compare_op<Lhs_T, Rhs_T, Compare_T>::compare_op (L&& lhs,
                                                               R&& rhs,
                                                               Compare_T)
        : binary_op<Lhs_T, Rhs_T>{ std::forward<L> (lhs),
                                   std::forward<R> (rhs), [&] () -> bool
      {
        // The result is computed before the arguments are moved, since
        // the base constructor is entered only after all its arguments
        // are evaluated.
        using lhs_type = std::remove_cvref_t<L>;
        using rhs_type = std::remove_cvref_t<R>;

        if constexpr (detail::has_value<lhs_type>
                      and detail::has_value<rhs_type>)
          {
            return Compare_T::apply (lhs_type::value, rhs_type::value);
          }
        else if constexpr ((extension::has_epsilon<lhs_type>
                            or extension::has_epsilon<rhs_type>)
                           and requires {
                                 Compare_T::within_tolerance_result;
                               })
          {
            return detail::within_tolerance (lhs, rhs)
                       ? Compare_T::within_tolerance_result
                       : Compare_T::apply (detail::unwrap (lhs),
                                           detail::unwrap (rhs));
          }
        else
          {
            return Compare_T::apply (detail::unwrap (lhs),
                                     detail::unwrap (rhs));
          }
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * For the integers, the larger value is selected with
     * `std::cmp_less()`, and the distance is computed in
     * `std::uintmax_t`: when both values have the same sign, as the
     * modular difference of their conversions, which is exact; otherwise,
     * as the sum of the larger value and of the magnitude of the negative
     * one, saturated at the maximum of the type, which is then larger than
     * any tolerance, as the true distance is. The tolerance is compared
     * with `std::cmp_less()`, so a negative one gives `false`.
     *
     * For the other types, the values are converted to their common type,
     * which is a floating-point one, so `std::int64_t` values compared
     * with a `float` tolerance lose precision; the comparison is strict,
     * as in the tolerances of the floating-point wrappers.
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    constexpr bool
    differ_by_less_than (Lhs_T lhs, Rhs_T rhs, Epsilon_T epsilon)
    {
      if constexpr (std::is_integral_v<Lhs_T> and std::is_integral_v<Rhs_T>
                    and std::is_integral_v<Epsilon_T>)
        {
          const auto distance
              = [] (auto larger, auto smaller) constexpr -> std::uintmax_t
            {
              if constexpr (std::is_signed_v<decltype (smaller)>)
                {
                  if (smaller < 0 and std::cmp_greater_equal (larger, 0))
                    {
                      // The magnitude of the negative value, without
                      // negating the minimum of its type.
                      const auto magnitude
                          = static_cast<std::uintmax_t> (-(smaller + 1)) + 1u;
                      const auto upper = static_cast<std::uintmax_t> (larger);
                      if (upper > std::numeric_limits<std::uintmax_t>::max ()
                                      - magnitude)
                        {
                          return std::numeric_limits<std::uintmax_t>::max ();
                        }
                      return upper + magnitude;
                    }
                }
              return static_cast<std::uintmax_t> (larger)
                     - static_cast<std::uintmax_t> (smaller);
            };

          const std::uintmax_t difference = std::cmp_less (lhs, rhs)
                                                ? distance (rhs, lhs)
                                                : distance (lhs, rhs);
          return std::cmp_less (difference, epsilon);
        }
      else
        {
          using float_type = std::common_type_t<Lhs_T, Rhs_T, Epsilon_T>;
          return math::abs (static_cast<float_type> (lhs)
                            - static_cast<float_type> (rhs))
                 < static_cast<float_type> (epsilon);
        }
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * The result is computed from the unwrapped arguments, with
     * `detail::differ_by_less_than()`, before the operands are forwarded
     * to the base and the tolerance to its member.
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    template <class L, class R, class E>
    constexpr approx_op<Lhs_T, Rhs_T, Epsilon_T>::approx_op (L&& lhs, R&& rhs,
                                                             E&& epsilon)
        : binary_op<Lhs_T, Rhs_T>{ std::forward<L> (lhs),
                                   std::forward<R> (rhs),
                                   detail::differ_by_less_than (
                                       detail::unwrap (lhs),
                                       detail::unwrap (rhs),
                                       detail::unwrap (epsilon)) },
          epsilon_{ std::forward<E> (epsilon) }
    {
    }

    /**
     * @details
     * Returns the stored tolerance, unwrapped with `detail::unwrap()`.
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    constexpr decltype (auto)
    approx_op<Lhs_T, Rhs_T, Epsilon_T>::epsilon (void) const
    {
      return detail::unwrap (epsilon_);
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical conjunction `static_cast<bool>(lhs) and
     * static_cast<bool>(rhs)` and passes the result to the `binary_op`
     * base class constructor.
     */
    template <class Lhs_T, class Rhs_T>
    template <class L, class R>
    constexpr and_op<Lhs_T, Rhs_T>::and_op (L&& lhs, R&& rhs)
        : binary_op<Lhs_T, Rhs_T>{ std::forward<L> (lhs),
                                   std::forward<R> (rhs),
                                   static_cast<bool> (lhs)
                                       and static_cast<bool> (rhs) }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical disjunction `static_cast<bool>(lhs) or
     * static_cast<bool>(rhs)` and passes the result to the `binary_op`
     * base class constructor.
     */
    template <class Lhs_T, class Rhs_T>
    template <class L, class R>
    constexpr or_op<Lhs_T, Rhs_T>::or_op (L&& lhs, R&& rhs)
        : binary_op<Lhs_T, Rhs_T>{ std::forward<L> (lhs),
                                   std::forward<R> (rhs),
                                   static_cast<bool> (lhs)
                                       or static_cast<bool> (rhs) }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical negation `not static_cast<bool>(t)` and
     * passes the result to the `unary_op` base class constructor.
     */
    template <class T>
    template <class U>
      requires (not std::is_same_v<std::remove_cvref_t<U>, not_op<T>>)
    constexpr not_op<T>::not_op (U&& t)
        : unary_op<T>{ std::forward<U> (t), not static_cast<bool> (t) }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Applies the predicate of the tag to the unwrapped operand, and passes
     * the boolean result to the `unary_op` base class constructor.
     */
    template <class T, class Predicate_T>
    template <class U>
    constexpr predicate_op<T, Predicate_T>::predicate_op (U&& t, Predicate_T)
        : unary_op<T>{ std::forward<U> (t),
                       static_cast<bool> (
                           Predicate_T::apply (detail::unwrap (t))) }
    {
    }

    // ------------------------------------------------------------------------

#if defined(__cpp_exceptions)

    /**
     * @details
     * Stores the pre-computed boolean result in the private `value_`
     * member.
     */
    constexpr callable_op::callable_op (bool value) : value_{ value }
    {
    }

    /**
     * @details
     * Returns the pre-computed boolean result stored by the derived
     * operator's constructor.
     */
    constexpr callable_op::
    operator bool () const
    {
      return value_;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Invokes `func` inside a try/catch block. If `func` throws an
     * exception of type `Exception_T`, the result is `true`; if it throws
     * any other exception the result is `false`; if no exception is thrown
     * the result is `false`. The result is passed to the `callable_op`
     * base class constructor.
     */
    template <class Exception_T>
    template <class Callable_T>
    constexpr throws_op<Exception_T>::throws_op (const Callable_T& func)
        : callable_op{ [&func]
      {
        try
          {
            func ();
          }
        catch (const Exception_T&)
          {
            return true;
          }
        catch (...)
          {
            return false;
          }
        return false;
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Invokes `func` inside a try/catch block. If `func` throws any
     * exception the result is `true`; if no exception is thrown the result
     * is `false`. The result is passed to the `callable_op` base class
     * constructor.
     */
    template <class Callable_T>
    constexpr throws_op<void>::throws_op (const Callable_T& func)
        : callable_op{ [&func]
      {
        try
          {
            func ();
          }
        catch (...)
          {
            return true;
          }
        return false;
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Invokes `func` inside a try/catch block. If `func` completes without
     * throwing, the result is `true`; if any exception is thrown the result
     * is `false`. The result is passed to the `callable_op` base class
     * constructor.
     */
    template <class Callable_T>
    constexpr nothrow_op::nothrow_op (const Callable_T& func)
        : callable_op{ [&func]
      {
        try
          {
            func ();
          }
        catch (...)
          {
            return false;
          }
        return true;
      }() }
    {
    }

#endif // defined(__cpp_exceptions)

    // ------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wfloat-equal"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

    /**
     * @details
     * The value is formatted into a local buffer, which is then appended
     * to `buffer`.
     *
     * For `long double`, a platform-specific path is chosen:
     * - On Windows and on platforms where `long double` has the same
     *   storage width as `double` (e.g. 32-bit Arm), the value is cast
     *   to `double` and formatted with `std::to_chars`.
     * - On all other platforms (e.g. x86-64 Linux/macOS with 80-bit
     *   extended precision, or AArch64 and RISC-V with 128-bit quad
     *   precision), `snprintf` with `%.*Lg` is used as a portable
     *   fallback, because `std::to_chars` for `long double` may be
     *   unavailable (e.g. when linking with `lld`). The precision starts
     *   at `LDBL_DIG` and is increased until the text reads back, with
     *   `strtold`, as the same value, up to `LDBL_DECIMAL_DIG`, which
     *   always reads back exactly. This gives the shortest exact form,
     *   as `std::to_chars` gives for the other types; a shorter form
     *   would need fewer than `LDBL_DIG` digits, and `%Lg` removes the
     *   trailing zeros, so starting at `LDBL_DIG` does not lose it. For
     *   zero and the subnormal values, which have fewer significant
     *   digits, the precision starts at 1. The value of `errno`, which
     *   `strtold` may set for subnormal values, is preserved. If no
     *   precision reads back exactly, the C library handles `long double`
     *   with the precision of `double` (e.g. newlib on AArch64 and
     *   RISC-V), and the value is cast to `double` and formatted with
     *   `std::to_chars`, as above.
     *
     * For all other numeric types, `std::to_chars` is called directly,
     * providing locale-independent formatting.
     */
    template <class T>
      requires std::is_arithmetic_v<T>
    void
    append_number (std::string& buffer, const T v)
    {
      if constexpr (std::is_same_v<T, long double>)
        {
#if defined(_WIN32) \
    || (defined(__SIZEOF_LONG_DOUBLE__) \
        && __SIZEOF_LONG_DOUBLE__ == __SIZEOF_DOUBLE__)
          // On Windows (all toolchains: MinGW, Clang, MSVC), the C runtime
          // does not handle the %Lg printf specifier correctly for 80-bit
          // long double, producing garbage output. On platforms where long
          // double has the same width as double (e.g. 32-bit Arm), the cast
          // is lossless. In both cases, cast to double and use
          // std::to_chars.
          char buf[32];
          const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf),
                                                static_cast<double> (v));
          if (ec == std::errc{})
            buffer.append (buf, ptr);
#else
          // On other platforms (80-bit extended precision on x86-64,
          // 128-bit quad precision on AArch64 and RISC-V), std::to_chars
          // for long double may be unavailable (e.g., with lld).
          // Use snprintf as a portable fallback; %Lg is supported by the C
          // libraries used on these platforms (e.g. glibc, the macOS libc,
          // and newlib, the latter with the precision of double on AArch64
          // and RISC-V). Use the smallest precision that reads back as the
          // same value; the buffer fits the 36 digits of the 128-bit
          // format, with the sign, the point, and the exponent.
          char buf[48];
          const int saved_errno = errno;
          // The subnormal values have fewer significant digits.
          const int min_precision
              = (v > -LDBL_MIN && v < LDBL_MIN) ? 1 : LDBL_DIG;
          bool is_exact = false;
          for (int precision = min_precision; precision <= LDBL_DECIMAL_DIG;
               ++precision)
            {
              snprintf (buf, sizeof (buf), "%.*Lg", precision, v);
              // A NaN is never equal to itself, and has no digits.
              if (v != v || strtold (buf, nullptr) == v)
                {
                  is_exact = true;
                  break;
                }
            }
          errno = saved_errno;
          if (is_exact)
            {
              buffer.append (buf);
            }
          else
            {
              // The C library formats or reads long double with the
              // precision of double (e.g. newlib on AArch64 and RISC-V),
              // and its long text would only show the error of the
              // conversion; use the shortest form of the double value,
              // as on the platforms above.
              const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf),
                                                    static_cast<double> (v));
              if (ec == std::errc{})
                buffer.append (buf, ptr);
            }
#endif // defined(_WIN32) || (defined(__SIZEOF_LONG_DOUBLE__) && __SIZEOF_LONG_DOUBLE__ == __SIZEOF_DOUBLE__)
        }
      else
        {
          char buf[32];
          const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf), v);
          if (ec == std::errc{})
            buffer.append (buf, ptr);
        }
    }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

    // ------------------------------------------------------------------------

    /**
     * @details
     * Null pointers are rendered as `"0x0"`, regardless of the platform,
     * avoiding platform-specific representations such as `"(nil)"` on
     * Linux/glibc. Non-null pointers are formatted with `snprintf()`,
     * using the `%p` specifier.
     *
     * The `%p` specifier expects a `void*`. Object pointers are converted
     * implicitly to `const volatile void*`, which accepts any
     * qualification, and the qualifiers are then removed with
     * `const_cast`; a `reinterpret_cast` to `void*` would not compile for
     * pointers to `const` objects. The object is not accessed. Function
     * pointers, which do not convert to `void*` implicitly, use
     * `reinterpret_cast`.
     */
    template <class T>
    void
    append_pointer (std::string& buffer, T* v)
    {
      if (v == nullptr)
        {
          buffer.append ("0x0");
          return;
        }

      void* p;
      if constexpr (std::is_function_v<T>)
        {
          p = reinterpret_cast<void*> (v);
        }
      else
        {
          const volatile void* cvp = v;
          p = const_cast<void*> (cvp);
        }

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

      char buf[20];
      snprintf (buf, sizeof (buf), "%p", p);
      buffer.append (buf);

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
    }

    // ========================================================================

    /**
     * @details
     * The length is computed with `std::char_traits<char>::length()`,
     * which, unlike `strlen()`, can be evaluated at compile time.
     */
    constexpr c_string::c_string (const char* str) noexcept
        : str_{ str },
          size_{ str == nullptr ? 0 : std::char_traits<char>::length (str) }
    {
    }

    /**
     * @details
     * The characters are counted up to the first null character, or up to
     * `capacity`.
     */
    constexpr c_string::c_string (const char* str,
                                  std::size_t capacity) noexcept
        : str_{ str }, size_{ capacity }
    {
      // Search within the array only; the view avoids indexing the raw
      // pointer.
      const std::size_t terminator
          = std::string_view{ str, capacity }.find ('\0');
      if (terminator != std::string_view::npos)
        {
          size_ = terminator;
        }
    }

    /**
     * @details
     * Returns an empty view for a null pointer.
     */
    constexpr std::string_view
    c_string::view (void) const noexcept
    {
      return str_ == nullptr ? std::string_view{}
                             : std::string_view{ str_, size_ };
    }

    /**
     * @details
     * Returns whether the stored pointer is null.
     */
    constexpr bool
    c_string::is_null (void) const noexcept
    {
      return str_ == nullptr;
    }

    /**
     * @details
     * Two null pointers are equal; a null pointer is not equal to any
     * string, not even an empty one.
     */
    constexpr bool
    operator== (const c_string& lhs, const c_string& rhs) noexcept
    {
      if (lhs.is_null () || rhs.is_null ())
        {
          return lhs.is_null () && rhs.is_null ();
        }
      return lhs.view () == rhs.view ();
    }

    /**
     * @details
     * A null pointer is not equal to any string.
     */
    constexpr bool
    operator== (const c_string& lhs, std::string_view rhs) noexcept
    {
      return !lhs.is_null () && lhs.view () == rhs;
    }

    /**
     * @details
     * Returns whether the operand is a null pointer.
     */
    constexpr bool
    operator== (const c_string& lhs, std::nullptr_t) noexcept
    {
      return lhs.is_null ();
    }

    /**
     * @details
     * A null pointer orders before any string.
     */
    constexpr std::strong_ordering
    operator<=> (const c_string& lhs, const c_string& rhs) noexcept
    {
      if (lhs.is_null () || rhs.is_null ())
        {
          return !lhs.is_null () <=> !rhs.is_null ();
        }
      return lhs.view () <=> rhs.view ();
    }

    /**
     * @details
     * A null pointer orders before any string.
     */
    constexpr std::strong_ordering
    operator<=> (const c_string& lhs, std::string_view rhs) noexcept
    {
      if (lhs.is_null ())
        {
          return std::strong_ordering::less;
        }
      return lhs.view () <=> rhs;
    }

    /**
     * @details
     * Arrays of `char` are converted using their size as a bound, pointers
     * to `char` using the null terminator; the cv-qualifiers of the
     * characters are ignored. Every other operand is forwarded, unchanged,
     * as an lvalue or an rvalue reference.
     */
    template <class T>
    constexpr auto
    as_operand (T&& t) noexcept -> decltype (auto)
    {
      using type = std::remove_cvref_t<T>;

      if constexpr (std::is_array_v<type>
                    && std::is_same_v<
                        std::remove_cv_t<std::remove_extent_t<type>>, char>)
        {
          return c_string{ t, std::extent_v<type> };
        }
      else if constexpr (std::is_pointer_v<type>
                         && std::is_same_v<
                             std::remove_cv_t<std::remove_pointer_t<type>>,
                             char>)
        {
          return c_string{ t };
        }
      else if constexpr (std::is_array_v<type>)
        {
          // Other arrays (e.g. byte buffers) are compared by address, as
          // pointers to their first element.
          return static_cast<const std::remove_extent_t<type>*> (t);
        }
      else if constexpr (std::is_function_v<type>)
        {
          // Functions are compared by address, as function pointers.
          return &t;
        }
      else
        {
          return std::forward<T> (t);
        }
    }

    // ------------------------------------------------------------------------

  } // namespace detail

  // --------------------------------------------------------------------------

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DETAIL_INLINES_H_

// ----------------------------------------------------------------------------
