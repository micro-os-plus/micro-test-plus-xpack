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
 * generic getter, the unary and binary operator base class templates, all
 * relational and logical comparator constructors, and the callable operator
 * types (`throws_`, `nothrow_`).
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

#include <charconv>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  namespace detail
  {
    // ========================================================================

    /**
     * @details
     * If the type `T` provides a `get()` member function, it is invoked
     * and its result returned. Otherwise the argument itself is returned
     * unchanged. The selection is performed at compile time via
     * `if constexpr` with an inline `requires` expression.
     */
    template <class T>
    constexpr auto
    get (const T& t)
    {
      if constexpr (requires { t.get (); })
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
    constexpr unary_op_<T>::unary_op_ (const T& t, bool value)
        : t_{ t }, value_{ value }
    {
    }

    /**
     * @details
     * Returns the pre-computed boolean result stored by the derived
     * comparator's constructor.
     */
    template <class T>
    constexpr unary_op_<T>::
    operator bool () const
    {
      return value_;
    }

    /**
     * @details
     * Returns the wrapped operand, applying the generic getter to ensure
     * correct extraction for both custom and standard types.
     */
    template <class T>
    constexpr auto
    unary_op_<T>::operand () const
    {
      return get (t_);
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Stores the two operands and the pre-computed boolean result of the
     * comparison in the corresponding private members.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr binary_op_<Lhs_T, Rhs_T>::binary_op_ (const Lhs_T& lhs,
                                                    const Rhs_T& rhs,
                                                    bool value)
        : lhs_{ lhs }, rhs_{ rhs }, value_{ value }
    {
    }

    /**
     * @details
     * Returns the pre-computed boolean result stored by the derived
     * comparator's constructor.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr binary_op_<Lhs_T, Rhs_T>::
    operator bool () const
    {
      return value_;
    }

    /**
     * @details
     * Returns the value of the left-hand operand, applying the generic
     * getter to ensure correct extraction for both custom and standard
     * types.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr auto
    binary_op_<Lhs_T, Rhs_T>::lhs (void) const
    {
      return get (lhs_);
    }

    /**
     * @details
     * Returns the value of the right-hand operand, applying the generic
     * getter to ensure correct extraction for both custom and standard
     * types.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr auto
    binary_op_<Lhs_T, Rhs_T>::rhs (void) const
    {
      return get (rhs_);
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the equality of `lhs` and `rhs` inside an immediately
     * invoked lambda and passes the boolean result to the `binary_op_`
     * base class constructor. Supports types with static `value` members,
     * types with an `epsilon` precision member, and generic types.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr eq_<Lhs_T, Rhs_T>::eq_ (const Lhs_T& lhs, const Rhs_T& rhs)
        : binary_op_<Lhs_T, Rhs_T>{ lhs, rhs, [&]
      {
        // This lambda is called in the constructor to evaluate the
        // comparison. Its result is implicitly converted to bool via
        // the operator bool() of whatever type the branch returns.
        // This is intentional: all result types (integral_constant,
        // comparator objects, plain bool) define operator bool().
        using std::operator==;
        using std::operator<;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
        if constexpr (type_traits::has_value<Lhs_T>
                      and type_traits::has_value<Rhs_T>)
          {
            // If both types have values (like numeric constants),
            // compare them directly.
            return Lhs_T::value == Rhs_T::value;
          }
        else if constexpr (type_traits::has_epsilon<Lhs_T>
                           and type_traits::has_epsilon<Rhs_T>)
          {
            // If both values have precision, compare them using
            // the smallest precision.
            return math::abs (get (lhs) - get (rhs))
                   < math::min_value (lhs.epsilon, rhs.epsilon);
          }
        else if constexpr (type_traits::has_epsilon<Lhs_T>)
          {
            // If only the left operand has precision, use it.
            return math::abs (get (lhs) - get (rhs)) < lhs.epsilon;
          }
        else if constexpr (type_traits::has_epsilon<Rhs_T>)
          {
            // If only the right operand has precision, use it.
            return math::abs (get (lhs) - get (rhs)) < rhs.epsilon;
          }
        else
          {
            // Call the generic getters, which might
            // either call the type get() or return the value.
            return get (lhs) == get (rhs);
          }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the non-equality of `lhs` and `rhs` inside an immediately
     * invoked lambda and passes the boolean result to the `binary_op_`
     * base class constructor. Supports types with static `value` members,
     * types with an `epsilon` precision member, and generic types.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr ne_<Lhs_T, Rhs_T>::ne_ (const Lhs_T& lhs, const Rhs_T& rhs)
        : binary_op_<Lhs_T, Rhs_T>{ lhs, rhs, [&]
      {
        using std::operator==;
        using std::operator!=;
        using std::operator>;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
        if constexpr (type_traits::has_value<Lhs_T>
                      and type_traits::has_value<Rhs_T>)
          {
            return Lhs_T::value != Rhs_T::value;
          }
        else if constexpr (type_traits::has_epsilon<Lhs_T>
                           and type_traits::has_epsilon<Rhs_T>)
          {
            return math::abs (get (lhs) - get (rhs))
                   >= math::min_value (lhs.epsilon, rhs.epsilon);
          }
        else if constexpr (type_traits::has_epsilon<Lhs_T>)
          {
            return math::abs (get (lhs) - get (rhs)) >= lhs.epsilon;
          }
        else if constexpr (type_traits::has_epsilon<Rhs_T>)
          {
            return math::abs (get (lhs) - get (rhs)) >= rhs.epsilon;
          }
        else
          {
            return get (lhs) != get (rhs);
          }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates whether `lhs > rhs` inside an immediately invoked lambda
     * and passes the boolean result to the `binary_op_` base class
     * constructor. Supports types with static `value` members and generic
     * types.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr gt_<Lhs_T, Rhs_T>::gt_ (const Lhs_T& lhs, const Rhs_T& rhs)
        : binary_op_<Lhs_T, Rhs_T>{ lhs, rhs, [&]
      {
        using std::operator>;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
        if constexpr (type_traits::has_value<Lhs_T>
                      and type_traits::has_value<Rhs_T>)
          {
            return Lhs_T::value > Rhs_T::value;
          }
        else
          {
            return get (lhs) > get (rhs);
          }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates whether `lhs >= rhs` inside an immediately invoked lambda
     * and passes the boolean result to the `binary_op_` base class
     * constructor. Supports types with static `value` members and generic
     * types.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr ge_<Lhs_T, Rhs_T>::ge_ (const Lhs_T& lhs, const Rhs_T& rhs)
        : binary_op_<Lhs_T, Rhs_T>{ lhs, rhs, [&]
      {
        using std::operator>=;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
        if constexpr (type_traits::has_value<Lhs_T>
                      and type_traits::has_value<Rhs_T>)
          {
            return Lhs_T::value >= Rhs_T::value;
          }
        else
          {
            return get (lhs) >= get (rhs);
          }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates whether `lhs < rhs` inside an immediately invoked lambda
     * and passes the boolean result to the `binary_op_` base class
     * constructor. Supports types with static `value` members and generic
     * types.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr lt_<Lhs_T, Rhs_T>::lt_ (const Lhs_T& lhs, const Rhs_T& rhs)
        : binary_op_<Lhs_T, Rhs_T>{ lhs, rhs, [&]
      {
        using std::operator<;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
        if constexpr (type_traits::has_value<Lhs_T>
                      and type_traits::has_value<Rhs_T>)
          {
            return Lhs_T::value < Rhs_T::value;
          }
        else
          {
            return get (lhs) < get (rhs);
          }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates whether `lhs <= rhs` inside an immediately invoked lambda
     * and passes the boolean result to the `binary_op_` base class
     * constructor. Supports types with static `value` members and generic
     * types.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr le_<Lhs_T, Rhs_T>::le_ (const Lhs_T& lhs, const Rhs_T& rhs)
        : binary_op_<Lhs_T, Rhs_T>{ lhs, rhs, [&]
      {
        using std::operator<=;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
        if constexpr (type_traits::has_value<Lhs_T>
                      and type_traits::has_value<Rhs_T>)
          {
            return Lhs_T::value <= Rhs_T::value;
          }
        else
          {
            return get (lhs) <= get (rhs);
          }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical conjunction `static_cast<bool>(lhs) and
     * static_cast<bool>(rhs)` and passes the result to the `binary_op_`
     * base class constructor.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr and_<Lhs_T, Rhs_T>::and_ (const Lhs_T& lhs, const Rhs_T& rhs)
        : binary_op_<Lhs_T, Rhs_T>{
            lhs, rhs, static_cast<bool> (lhs) and static_cast<bool> (rhs)
          }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical disjunction `static_cast<bool>(lhs) or
     * static_cast<bool>(rhs)` and passes the result to the `binary_op_`
     * base class constructor.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr or_<Lhs_T, Rhs_T>::or_ (const Lhs_T& lhs, const Rhs_T& rhs)
        : binary_op_<Lhs_T, Rhs_T>{
            lhs, rhs, static_cast<bool> (lhs) or static_cast<bool> (rhs)
          }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical negation `not static_cast<bool>(t)` and
     * passes the result to the `unary_op_` base class constructor.
     */
    template <class T>
    constexpr not_<T>::not_ (const T& t)
        : unary_op_<T>{ t, not static_cast<bool> (t) }
    {
    }

    // ------------------------------------------------------------------------

#if defined(__cpp_exceptions)

    /**
     * @details
     * Stores the pre-computed boolean result in the private `value_`
     * member.
     */
    constexpr callable_op_::callable_op_ (bool value) : value_{ value }
    {
    }

    /**
     * @details
     * Returns the pre-computed boolean result stored by the derived
     * operator's constructor.
     */
    constexpr callable_op_::
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
     * the result is `false`. The result is passed to the `callable_op_`
     * base class constructor.
     */
    template <class Callable_T, class Exception_T>
    constexpr throws_<Callable_T, Exception_T>::throws_ (
        const Callable_T& func)
        : callable_op_{ [&func]
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
     * is `false`. The result is passed to the `callable_op_` base class
     * constructor.
     */
    template <class Callable_T>
    constexpr throws_<Callable_T, void>::throws_ (const Callable_T& func)
        : callable_op_{ [&func]
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
     * is `false`. The result is passed to the `callable_op_` base class
     * constructor.
     */
    template <class Callable_T>
    constexpr nothrow_<Callable_T>::nothrow_ (const Callable_T& func)
        : callable_op_{ [&func]
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
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

    /**
     * @details
     * For `long double`, a platform-specific path is chosen:
     * - On Windows and on platforms where `long double` has the same
     *   storage width as `double` (e.g., ARM, RISC-V), the value is cast
     *   to `double` and formatted with `std::to_chars`.
     * - On x86-64 Linux/macOS with 80-bit extended precision, `snprintf`
     *   with `%Lg` is used as a portable fallback because
     *   `std::to_chars` for `long double` may be unavailable when linking
     *   with `lld`.
     *
     * For all other numeric types, `std::to_chars` is called directly,
     * providing locale-independent, allocation-free formatting.
     */
    template <class T>
      requires std::is_arithmetic_v<T>
    void
    append_number_ (std::string& buffer, const T v)
    {
      char buf[32];
      if constexpr (std::is_same_v<T, long double>)
        {
#if defined(_WIN32) \
    || (defined(__SIZEOF_LONG_DOUBLE__) \
        && __SIZEOF_LONG_DOUBLE__ == __SIZEOF_DOUBLE__)
          // On Windows (all toolchains: MinGW, Clang, MSVC), the C runtime
          // does not handle the %Lg printf specifier correctly for 80-bit
          // long double, producing garbage output. On platforms where long
          // double has the same width as double (ARM, RISC-V), the cast is
          // lossless. In both cases, cast to double and use std::to_chars.
          const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf),
                                                static_cast<double> (v));
          if (ec == std::errc{})
            buffer.append (buf, ptr);
#else
          // On x86-64 Linux/macOS with 80-bit extended-precision long double,
          // std::to_chars for long double may be unavailable (e.g., with lld).
          // Use snprintf as a portable fallback; %Lg is supported correctly
          // by glibc and libc++ on these platforms.
          snprintf (buf, sizeof (buf), "%Lg", v);
          buffer.append (buf);
#endif
        }
      else
        {
          const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf), v);
          if (ec == std::errc{})
            buffer.append (buf, ptr);
        }
    }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

    // ------------------------------------------------------------------------

  } // namespace detail

  // --------------------------------------------------------------------------

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DETAIL_INLINES_H_

// ----------------------------------------------------------------------------
