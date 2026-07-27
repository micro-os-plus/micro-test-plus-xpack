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
 * type trait utilities.
 *
 * @details
 * This header provides the out-of-class template and inline implementations
 * for all methods declared in the type-traits struct templates in
 * `type-traits.h`. It defines the bodies of the constructors, conversion
 * operators, and accessor methods for `value_base_`, `integral_constant`,
 * `floating_point_constant`, `genuine_integral_value`, and the `value<T>`
 * templates.
 *
 * Separating the implementations from the declarations keeps `type-traits.h`
 * concise and focused on the interface, whilst grouping all method bodies
 * here for maintainability.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::type_traits` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TYPE_TRAITS_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TYPE_TRAITS_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  namespace type_traits
  {
    // ========================================================================

    /**
     * @details
     * Stores the supplied value in the `value_` member.
     */
    template <class T>
    constexpr value_base_<T>::value_base_ (const T& v) noexcept : value_{ v }
    {
    }

    /**
     * @details
     * Allows explicit conversion to the encapsulated value.
     */
    template <class T>
    constexpr value_base_<T>::
    operator T () const noexcept
    {
      return value_;
    }

    /**
     * @details
     * Returns the stored value by value.
     */
    template <class T>
    constexpr T
    value_base_<T>::get (void) const noexcept
    {
      return value_;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Delegates to `value_base_<decltype(N)>{ N }` to initialise the base.
     */
    template <auto N>
    constexpr integral_constant<N>::integral_constant () noexcept
        : value_base_<decltype (N)>{ N }
    {
    }

    /**
     * @details
     * Returns a new `integral_constant` instance representing the negative
     * of the current value.
     */
    template <auto N>
    constexpr auto
    integral_constant<N>::operator- () const noexcept
    {
      return integral_constant<-N>{};
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

    /**
     * @details
     * Delegates to `value_base_<T>{ _value }` to initialise the base.
     */
    template <class T>
    constexpr genuine_integral_value<T>::genuine_integral_value (
        const T& _value) noexcept
        : value_base_<T>{ _value }
    {
    }

    // ------------------------------------------------------------------------

    template <class T>
    constexpr value<T>::value (const T& _value) noexcept
        : value_base_<T>{ _value }
    {
    }

    // ------------------------------------------------------------------------
  } // namespace type_traits

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TYPE_TRAITS_INLINES_H_

// ----------------------------------------------------------------------------
