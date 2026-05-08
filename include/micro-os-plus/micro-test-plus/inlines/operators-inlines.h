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

#if !defined(MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_)
// clang-format off
#error "Do not include this file directly; use <micro-os-plus/micro-test-plus.h>."
// clang-format on
#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

/**
 * @file
 * @brief C++ header file with inline implementations for the µTest++
 * operator overloads.
 *
 * @details
 * This header provides the inline implementations for all operator overloads
 * declared in `operators.h`. Each operator constructs and returns the
 * appropriate comparator or logical object from the `detail` namespace.
 *
 * Separating the implementations from the declarations keeps `operators.h`
 * concise and focused on the interface, whilst grouping all operator bodies
 * here for maintainability.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::operators` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_OPERATORS_INLINES_H_
#define MICRO_TEST_PLUS_OPERATORS_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/detail.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  namespace operators
  {
    // ========================================================================

    /**
     * @details
     * Constructs an `eq_` comparator object from the two `string_view`
     * operands and returns it. The comparator evaluates to `true` if the
     * string views are equal.
     */
    constexpr auto
    operator== (std::string_view lhs, std::string_view rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `ne_` comparator object from the two `string_view`
     * operands and returns it. The comparator evaluates to `true` if the
     * string views are not equal.
     */
    constexpr auto
    operator!= (std::string_view lhs, std::string_view rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `eq_` comparator object from the two container
     * operands and returns it. The comparator evaluates to `true` if the
     * containers are equal in content and order.
     *
     * The operator is enabled only for types recognised as containers by the
     * framework's type traits.
     */
    template <class Lhs_T, class Rhs_T>
      requires (type_traits::container_like<Lhs_T>
                and type_traits::container_like<Rhs_T>)
    constexpr auto
    operator== (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `ne_` comparator object from the two container
     * operands and returns it. The comparator evaluates to `true` if the
     * containers are not equal in content or order.
     *
     * The operator is enabled only for types recognised as containers by the
     * framework's type traits.
     */
    template <class Lhs_T, class Rhs_T>
      requires (type_traits::container_like<Lhs_T>
                and type_traits::container_like<Rhs_T>)
    constexpr auto
    operator!= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `eq_` comparator object from the two operands and
     * returns it. The comparator evaluates to `true` if the operands are
     * equal. At least one operand must derive from the local `op` base.
     */
    template <class Lhs_T, class Rhs_T>
      requires type_traits::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator== (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `ne_` comparator object from the two operands and
     * returns it. The comparator evaluates to `true` if the operands are
     * not equal. At least one operand must derive from the local `op` base.
     */
    template <class Lhs_T, class Rhs_T>
      requires type_traits::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator!= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs a `gt_` comparator object from the two operands and
     * returns it. The comparator evaluates to `true` if `lhs` is greater
     * than `rhs`. At least one operand must derive from the local `op` base.
     */
    template <class Lhs_T, class Rhs_T>
      requires type_traits::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator> (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::gt_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs a `ge_` comparator object from the two operands and
     * returns it. The comparator evaluates to `true` if `lhs` is greater
     * than or equal to `rhs`. At least one operand must derive from the
     * local `op` base.
     */
    template <class Lhs_T, class Rhs_T>
      requires type_traits::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator>= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ge_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `lt_` comparator object from the two operands and
     * returns it. The comparator evaluates to `true` if `lhs` is less
     * than `rhs`. At least one operand must derive from the local `op` base.
     */
    template <class Lhs_T, class Rhs_T>
      requires type_traits::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator< (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::lt_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `le_` comparator object from the two operands and
     * returns it. The comparator evaluates to `true` if `lhs` is less than
     * or equal to `rhs`. At least one operand must derive from the local
     * `op` base.
     */
    template <class Lhs_T, class Rhs_T>
      requires type_traits::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator<= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::le_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `and_` logical conjunction object from the two operands
     * and returns it. The object evaluates to `true` if both operands are
     * true. At least one operand must derive from the local `op` base.
     */
    template <class Lhs_T, class Rhs_T>
      requires type_traits::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator and (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::and_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs an `or_` logical disjunction object from the two operands
     * and returns it. The object evaluates to `true` if at least one operand
     * is true. At least one operand must derive from the local `op` base.
     */
    template <class Lhs_T, class Rhs_T>
      requires type_traits::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator or (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::or_{ lhs, rhs };
    }

    /**
     * @details
     * Constructs a `not_` logical negator object from the operand and
     * returns it. The object evaluates to `true` if the operand is false.
     * The operand must derive from the local `op` base.
     */
    template <class T>
      requires type_traits::is_op<T>
    constexpr auto
    operator not(const T& t)
    {
      return detail::not_{ t };
    }

    // ------------------------------------------------------------------------
  } // namespace operators

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_OPERATORS_INLINES_H_

// ----------------------------------------------------------------------------
