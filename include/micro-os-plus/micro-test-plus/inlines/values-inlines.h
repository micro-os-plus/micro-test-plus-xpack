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
 * value wrappers.
 *
 * @details
 * This header provides the out-of-class template and inline implementations
 * for all methods declared in the value wrapper struct templates in
 * `values.h`. It defines the bodies of the constructors, conversion
 * operators, and accessor methods for `value_base`, `integral_constant`,
 * `floating_point_constant`, the primary `value<T>` template, and
 * `named_bool`. The
 * constructors of the floating point specialisation of `value<T>` are
 * defined in the class body, to work around a Clang 16 limitation with
 * constrained partial specialisations.
 *
 * Separating the implementations from the declarations keeps `values.h`
 * concise and focused on the interface, whilst grouping all method bodies
 * here for maintainability.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_VALUES_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_VALUES_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
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
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_VALUES_INLINES_H_

// ----------------------------------------------------------------------------
