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
 * @brief C++ header file with declarations for the µTest++ internals.
 *
 * @details
 * This header provides the declarations for the internal components of the
 * µTest++ framework, encapsulated within the
 * `micro_os_plus::micro_test_plus::detail` namespace. It defines the core
 * mechanisms, helper structures, and utility templates that underpin the
 * framework's assertion handling, value retrieval, comparator logic, deferred
 * reporting, and exception checking facilities.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::detail`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_DETAIL_H_
#define MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstdio>
#include <string>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  class test_node;

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::detail
   * @brief Internal implementation details for the µTest++ framework.
   *
   * @details
   * The `detail` namespace encapsulates the internal mechanisms, helper
   * structures, and implementation utilities employed by the µTest++ testing
   * framework. These components do not form part of the public API and may be
   * modified without prior notice.
   *
   * Within this namespace, one will find assertion handling, generic getter
   * utilities, comparator structures for logical and relational operations,
   * mechanisms for exception checking, and base classes for deferred reporting
   * of test results.
   *
   * All definitions within `detail` are intended exclusively for internal use,
   * ensuring a clear distinction between user-facing and internal components.
   * This approach enhances maintainability, mitigates the risk of naming
   * conflicts, and keeps the public API succinct.
   *
   * The relevant header files are organised within the `include/micro-os-plus`
   * folder to maintain a structured and modular codebase.
   */
  namespace detail
  {
    /**
     * @brief Assertion struct template for parameter passing to the evaluator.
     *
     * @tparam Expr_T The type of the expression being asserted.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Expr_T>
    struct assertion
    {
      /**
       * @brief The expression under evaluation.
       */
      Expr_T expr{};

      /**
       * @brief The source location associated with the assertion.
       */
      reflection::source_location location{};
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Generic getter function template for value retrieval.
     *
     * @tparam T The type from which the value is to be retrieved.
     *
     * @param t The object or value to be accessed.
     * @return The value obtained via the relevant getter implementation.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    get (const T& t);

    // ------------------------------------------------------------------------

    /**
     * @brief Common base struct template for unary comparators.
     *
     * @tparam T The type of the operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct unary_op_ : type_traits::op
    {
      /**
       * @brief Constructs a unary comparator with the given operand and
       * pre-computed result.
       *
       * @param t The operand.
       * @param value The pre-computed boolean result of the operation.
       */
      constexpr unary_op_ (const T& t, bool value);

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *	None.
       * @return The result of the operation.
       */
      [[nodiscard]] constexpr
      operator bool () const;

      /**
       * @brief Retrieves the wrapped operand expression.
       *
       * @par Parameters
       *	None.
       * @return The extracted operand value.
       */
      [[nodiscard]] constexpr auto
      operand () const;

    private:
      /**
       * @brief Stores the operand.
       */
      const T t_{};

      /**
       * @brief Stores the result of the operation.
       */
      const bool value_{};
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Common base struct template for binary comparators.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct binary_op_ : type_traits::op
    {
      /**
       * @brief Constructs a binary comparator with the given operands and
       * pre-computed result.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @param value The pre-computed boolean result of the comparison.
       */
      constexpr binary_op_ (const Lhs_T& lhs, const Rhs_T& rhs, bool value);

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *	None.
       * @return The result of the comparison.
       */
      [[nodiscard]] constexpr
      operator bool () const;

      /**
       * @brief Retrieves the left-hand operand.
       *
       * @par Parameters
       *	None.
       * @return The extracted left-hand operand.
       */
      [[nodiscard]] constexpr auto
      lhs (void) const;

      /**
       * @brief Retrieves the right-hand operand.
       *
       * @par Parameters
       *	None.
       * @return The extracted right-hand operand.
       */
      [[nodiscard]] constexpr auto
      rhs (void) const;

    private:
      /**
       * @brief Stores the left-hand operand.
       *
       * @note Operands are stored by value; passing a large container
       * will copy it into this member.
       */
      const Lhs_T lhs_{};

      /**
       * @brief Stores the right-hand operand.
       *
       * @note Operands are stored by value; passing a large container
       * will copy it into this member.
       */
      const Rhs_T rhs_{};

      /**
       * @brief Stores the result of the comparison.
       */
      const bool value_{};
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Equality comparator struct template.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct eq_ : binary_op_<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs an equality comparator for the given operands.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      constexpr eq_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {});
    };

    // Deduction guide.
    template <typename Lhs_T, typename Rhs_T>
    eq_ (const Lhs_T&, const Rhs_T&) -> eq_<Lhs_T, Rhs_T>;

    // ------------------------------------------------------------------------

    /**
     * @brief Non-equality comparator struct template.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct ne_ : binary_op_<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a non-equality comparator for the given operands.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      constexpr ne_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {});
    };

    // Deduction guide.
    template <typename Lhs_T, typename Rhs_T>
    ne_ (const Lhs_T&, const Rhs_T&) -> ne_<Lhs_T, Rhs_T>;

    // ------------------------------------------------------------------------

    /**
     * @brief Greater than comparator struct template.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct gt_ : binary_op_<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a greater than comparator for the given operands.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      constexpr gt_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {});
    };

    // Deduction guide.
    template <typename Lhs_T, typename Rhs_T>
    gt_ (const Lhs_T&, const Rhs_T&) -> gt_<Lhs_T, Rhs_T>;

    // ------------------------------------------------------------------------

    /**
     * @brief Greater than or equal comparator struct template.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct ge_ : binary_op_<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a greater than or equal comparator for the given
       * operands.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      constexpr ge_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {});
    };

    // Deduction guide.
    template <typename Lhs_T, typename Rhs_T>
    ge_ (const Lhs_T&, const Rhs_T&) -> ge_<Lhs_T, Rhs_T>;

    // ------------------------------------------------------------------------

    /**
     * @brief Less than comparator struct template.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct lt_ : binary_op_<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a less than comparator for the given operands.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      constexpr lt_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {});
    };

    // Deduction guide.
    template <typename Lhs_T, typename Rhs_T>
    lt_ (const Lhs_T&, const Rhs_T&) -> lt_<Lhs_T, Rhs_T>;

    // ------------------------------------------------------------------------

    /**
     * @brief Less than or equal comparator struct template.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct le_ : binary_op_<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a less than or equal comparator for the given
       * operands.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      constexpr le_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {});
    };

    // Deduction guide.
    template <typename Lhs_T, typename Rhs_T>
    le_ (const Lhs_T&, const Rhs_T&) -> le_<Lhs_T, Rhs_T>;

    // ------------------------------------------------------------------------

    /**
     * @brief Logical AND comparator struct template.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct and_ : binary_op_<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a logical AND comparator for the given operands.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      constexpr and_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {});
    };

    // Deduction guide.
    template <typename Lhs_T, typename Rhs_T>
    and_ (const Lhs_T&, const Rhs_T&) -> and_<Lhs_T, Rhs_T>;

    // ------------------------------------------------------------------------

    /**
     * @brief Logical OR comparator struct template.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Lhs_T, class Rhs_T>
    struct or_ : binary_op_<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a logical OR comparator for the given operands.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      constexpr or_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {});
    };

    // Deduction guide.
    template <typename Lhs_T, typename Rhs_T>
    or_ (const Lhs_T&, const Rhs_T&) -> or_<Lhs_T, Rhs_T>;

    // ------------------------------------------------------------------------

    /**
     * @brief Logical NOT comparator struct template.
     *
     * @tparam T The type of the operand.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct not_ : unary_op_<T>
    {
      /**
       * @brief Constructs a logical NOT comparator for the given operand.
       *
       * @param t The operand to be negated.
       */
      explicit constexpr not_ (const T& t = {});
    };

    // Deduction guide.
    template <typename T>
    not_ (const T&) -> not_<T>;

    // ------------------------------------------------------------------------

#if defined(__cpp_exceptions)

    /**
     * @brief Common base struct for callable-wrapping operators.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    struct callable_op_ : type_traits::op
    {
      /**
       * @brief Constructs a callable operator with the pre-computed
       * boolean result.
       *
       * @param value The pre-computed boolean result of the invocation.
       */
      constexpr explicit callable_op_ (bool value);

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *	None.
       * @return The result of the callable invocation.
       */
      [[nodiscard]] constexpr
      operator bool () const;

    private:
      /**
       * @brief Stores the result of the callable invocation.
       */
      const bool value_{};
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Operator struct template to check if an expression throws a
     * specific exception.
     *
     * @tparam Callable_T The type of the callable object to be invoked.
     * @tparam Exception_T The type of the exception to check for (defaults to
     * `void` for any exception).
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Callable_T, class Exception_T = void>
    struct throws_ : callable_op_
    {
      /**
       * @brief Constructs an exception checking operator for the given
       * callable.
       *
       * @param func The callable object to be invoked.
       */
      constexpr explicit throws_ (const Callable_T& func);
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Operator struct template to check if an expression throws any
     * exception.
     *
     * @tparam Callable_T The type of the callable object to be invoked.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Callable_T>
    struct throws_<Callable_T, void> : callable_op_
    {
      /**
       * @brief Constructs an exception checking operator for the given
       * callable.
       *
       * @param func The callable object to be invoked.
       */
      constexpr explicit throws_ (const Callable_T& func);
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Operator struct template to check if an expression does not throw
     * any exception.
     *
     * @tparam Callable_T The type of the callable object to be invoked.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Callable_T>
    struct nothrow_ : callable_op_
    {
      /**
       * @brief Constructs a nothrow checking operator for the given
       * callable.
       *
       * @param func The callable object to be invoked.
       */
      constexpr explicit nothrow_ (const Callable_T& func);
    };

#endif

    // ------------------------------------------------------------------------

    /**
     * @brief Appends the string representation of a numeric value to a
     * buffer, using `std::to_chars` for allocation-free,
     * locale-independent formatting.
     *
     * @tparam T The numeric type to format.
     * @param buffer The string to append to.
     * @param v The value to format.
     * @par Returns
     *   Nothing.
     */
    template <class T>
      requires std::is_arithmetic_v<T>
    void
    append_number_ (std::string& buffer, T v);

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ============================================================================
// Templates & constexpr implementations.

#include "inlines/detail-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------
