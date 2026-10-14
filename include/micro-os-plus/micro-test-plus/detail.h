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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_DETAIL_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "type-traits.h"
#include "reflection.h"

#include <compare>
#include <cstddef>
#include <cstdio>
#include <string>
#include <string_view>
#include <type_traits>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

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
   * Within this namespace, one will find assertion handling, the value
   * unwrapping helper, comparator structures for logical and relational
   * operations, mechanisms for exception checking, and base classes for
   * deferred reporting of test results.
   *
   * All definitions within `detail` are intended exclusively for internal use,
   * ensuring a clear distinction between user-facing and internal components.
   * This approach enhances maintainability, mitigates the risk of naming
   * conflicts, and keeps the public API succinct.
   *
   * The relevant header files are organised within the
   * `include/micro-os-plus/micro-test-plus` folder to maintain a structured
   * and modular codebase.
   */
  namespace detail
  {
    // ========================================================================

    /**
     * @brief Assertion struct template for parameter passing to the evaluator.
     *
     * @details
     * This structure encapsulates both the expression being tested and its
     * associated source location. Used internally by the framework to pass
     * assertion data through the evaluation pipeline, enabling accurate
     * reporting of where assertions occur in test code.
     *
     * @tparam Expr_T The type of the expression being asserted.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class Expr_T>
    struct assertion
    {
      /**
       * @brief The expression under evaluation.
       *
       * @details
       * Either a framework comparator (derived from `type_traits::op`) or a
       * value convertible to `bool`.
       */
      Expr_T expr{};

      /**
       * @brief The source location associated with the assertion.
       *
       * @details
       * Used by the reporter to show where a failed check is located.
       */
      reflection::source_location location{};
    };

    // ========================================================================

    /**
     * @brief Returns the value wrapped by a framework type, or the operand
     * itself.
     *
     * @details
     * Always call it qualified, as `detail::unwrap_()`, so that
     * argument-dependent lookup cannot select a function of the
     * application, defined in the namespace of an operand.
     *
     * @tparam T The type of the operand.
     *
     * @param t The operand.
     * @return The value returned by `t.get()` for the framework wrappers
     * (the literals and the `to_*` wrappers), otherwise `t`.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    unwrap_ (const T& t);

    /**
     * @brief Checks whether two operands are equal within the tolerance of
     * the floating-point wrappers.
     *
     * @details
     * Used by all six comparators, so that a value within the tolerance is
     * equal, and neither less nor greater; at least one operand must have
     * an `epsilon` member (a floating-point literal, a `to_f`, `to_d`, or
     * `to_ld` wrapper, or `approx()`).
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @param lhs The left-hand operand.
     * @param rhs The right-hand operand.
     * @retval true The absolute difference is less than the tolerance (the
     * smaller one, if both operands have one).
     * @retval false Otherwise.
     */
    template <class Lhs_T, class Rhs_T>
      requires (type_traits::has_epsilon<Lhs_T>
                or type_traits::has_epsilon<Rhs_T>)
    [[nodiscard]] constexpr bool
    within_tolerance_ (const Lhs_T& lhs, const Rhs_T& rhs);

    // ========================================================================

    /**
     * @brief Common base struct template for unary comparators.
     *
     * @details
     * This base struct stores a single operand and the pre-computed boolean
     * result of a unary operation. Derived structs such as `not_` inherit
     * from this to provide logical negation. The result is computed at
     * construction time, enabling consistent handling and reporting of
     * operations throughout the assertion framework.
     *
     * @tparam T The type of the operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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
       *   None.
       * @return The result of the operation.
       */
      [[nodiscard]] constexpr
      operator bool () const;

      /**
       * @brief Retrieves the wrapped operand expression.
       *
       * @par Parameters
       *   None.
       * @return The extracted operand value.
       */
      [[nodiscard]] constexpr auto
      operand () const;

    private:
      /**
       * @brief Stores the operand.
       *
       * @details
       * Stored by value, so that it remains available for reporting after
       * the original expression goes out of scope.
       */
      const T t_{};

      /**
       * @brief Stores the result of the operation.
       *
       * @details
       * Computed once, by the derived comparator constructor.
       */
      const bool value_{};
    };

    // ========================================================================

    /**
     * @brief Common base struct template for binary comparators.
     *
     * @details
     * This base struct stores two operands (left-hand and right-hand) along
     * with the pre-computed boolean result of a binary comparison. Derived
     * structs such as `eq_`, `lt_`, and others inherit from this to provide
     * relational and logical operations. The comparison result is computed at
     * construction time and cached, enabling efficient reporting and
     * composition of complex assertions without repeated computation.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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
       *   None.
       * @return The result of the comparison.
       */
      [[nodiscard]] constexpr
      operator bool () const;

      /**
       * @brief Retrieves the left-hand operand.
       *
       * @par Parameters
       *   None.
       * @return The extracted left-hand operand.
       */
      [[nodiscard]] constexpr auto
      lhs (void) const;

      /**
       * @brief Retrieves the right-hand operand.
       *
       * @par Parameters
       *   None.
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
       *
       * @details
       * Computed once, by the derived comparator constructor.
       */
      const bool value_{};
    };

    // ========================================================================

    /**
     * @brief Equality comparator struct template.
     *
     * @details
     * Derived from `binary_op_`, this struct checks whether the left-hand
     * operand is equal to the right-hand operand. It is used within test
     * expressions to provide human-readable equality assertions with
     * enhanced reporting of the actual and expected values upon failure.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the equality comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `eq_{ lhs, rhs }` can be written without explicit template arguments.
     */
    template <typename Lhs_T, typename Rhs_T>
    eq_ (const Lhs_T&, const Rhs_T&) -> eq_<Lhs_T, Rhs_T>;

    // ========================================================================

    /**
     * @brief Non-equality comparator struct template.
     *
     * @details
     * Derived from `binary_op_`, this struct checks whether the left-hand
     * operand is not equal to the right-hand operand. It is used within test
     * expressions to provide human-readable inequality assertions with
     * enhanced reporting of the actual and expected values upon failure.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the non-equality comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `ne_{ lhs, rhs }` can be written without explicit template arguments.
     */
    template <typename Lhs_T, typename Rhs_T>
    ne_ (const Lhs_T&, const Rhs_T&) -> ne_<Lhs_T, Rhs_T>;

    // ========================================================================

    /**
     * @brief Greater than comparator struct template.
     *
     * @details
     * Derived from `binary_op_`, this struct checks whether the left-hand
     * operand is greater than the right-hand operand. It is used within test
     * expressions to provide human-readable relational assertions with
     * enhanced reporting of the actual and expected values upon failure.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the greater than comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `gt_{ lhs, rhs }` can be written without explicit template arguments.
     */
    template <typename Lhs_T, typename Rhs_T>
    gt_ (const Lhs_T&, const Rhs_T&) -> gt_<Lhs_T, Rhs_T>;

    // ========================================================================

    /**
     * @brief Greater than or equal comparator struct template.
     *
     * @details
     * Derived from `binary_op_`, this struct checks whether the left-hand
     * operand is greater than or equal to the right-hand operand. It is used
     * within test expressions to provide human-readable relational
     * assertions with enhanced reporting of the actual and expected values
     * upon failure.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the greater than or equal comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `ge_{ lhs, rhs }` can be written without explicit template arguments.
     */
    template <typename Lhs_T, typename Rhs_T>
    ge_ (const Lhs_T&, const Rhs_T&) -> ge_<Lhs_T, Rhs_T>;

    // ========================================================================

    /**
     * @brief Less than comparator struct template.
     *
     * @details
     * Derived from `binary_op_`, this struct checks whether the left-hand
     * operand is less than the right-hand operand. It is used within test
     * expressions to provide human-readable relational assertions with
     * enhanced reporting of the actual and expected values upon failure.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the less than comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `lt_{ lhs, rhs }` can be written without explicit template arguments.
     */
    template <typename Lhs_T, typename Rhs_T>
    lt_ (const Lhs_T&, const Rhs_T&) -> lt_<Lhs_T, Rhs_T>;

    // ========================================================================

    /**
     * @brief Less than or equal comparator struct template.
     *
     * @details
     * Derived from `binary_op_`, this struct checks whether the left-hand
     * operand is less than or equal to the right-hand operand. It is used
     * within test expressions to provide human-readable relational
     * assertions with enhanced reporting of the actual and expected values
     * upon failure.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the less than or equal comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `le_{ lhs, rhs }` can be written without explicit template arguments.
     */
    template <typename Lhs_T, typename Rhs_T>
    le_ (const Lhs_T&, const Rhs_T&) -> le_<Lhs_T, Rhs_T>;

    // ========================================================================

    /**
     * @brief Logical AND comparator struct template.
     *
     * @details
     * Derived from `binary_op_`, this struct combines two sub-expressions
     * with a logical AND operation. It enables composition of complex
     * assertions by combining multiple conditions into a single logical
     * whole, with reporting that shows the combined result and individual
     * operand outcomes.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the logical AND comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `and_{ lhs, rhs }` can be written without explicit template arguments.
     */
    template <typename Lhs_T, typename Rhs_T>
    and_ (const Lhs_T&, const Rhs_T&) -> and_<Lhs_T, Rhs_T>;

    // ========================================================================

    /**
     * @brief Logical OR comparator struct template.
     *
     * @details
     * Derived from `binary_op_`, this struct combines two sub-expressions
     * with a logical OR operation. It enables composition of complex
     * assertions by combining multiple conditions into a single logical
     * whole, with reporting that shows the combined result and individual
     * operand outcomes.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the logical OR comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `or_{ lhs, rhs }` can be written without explicit template arguments.
     */
    template <typename Lhs_T, typename Rhs_T>
    or_ (const Lhs_T&, const Rhs_T&) -> or_<Lhs_T, Rhs_T>;

    // ========================================================================

    /**
     * @brief Logical NOT comparator struct template.
     *
     * @details
     * Derived from `unary_op_`, this struct negates a single sub-expression,
     * enabling test writers to assert that a condition does not hold. The
     * negation result is computed at construction time, ensuring consistent
     * reporting throughout the assertion framework.
     *
     * @tparam T The type of the operand.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    /**
     * @brief Deduction guide for the logical NOT comparator.
     *
     * @details
     * Deduces `T` from the constructor argument, so that `not_{ t }` can be
     * written without an explicit template argument.
     */
    template <typename T>
    not_ (const T&) -> not_<T>;

    // ========================================================================

#if defined(__cpp_exceptions)

    /**
     * @brief Common base struct for callable-wrapping operators.
     *
     * @details
     * This base struct provides common functionality for operators that wrap
     * callable invocations, particularly for exception-checking operations.
     * Derived structs (such as `throws_` and `nothrow_`) use this base to
     * store and manage the pre-computed boolean result of a callable
     * invocation, enabling consistent reporting and composition of
     * exception-checking assertions.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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
       *   None.
       * @return The result of the callable invocation.
       */
      [[nodiscard]] constexpr
      operator bool () const;

    private:
      /**
       * @brief Stores the result of the callable invocation.
       *
       * @details
       * Computed once, by the derived operator constructor, which invokes
       * the callable.
       */
      const bool value_{};
    };

    // ========================================================================

    /**
     * @brief Operator struct template to check if an expression throws a
     * specific exception.
     *
     * @details
     * This primary template checks whether invoking the given callable
     * throws an exception of the specified type. The check is performed at
     * construction time, with the result cached for reporting and
     * composition. Use this when a test must verify that an operation raises
     * an expected exception of a particular type.
     *
     * @tparam Callable_T The type of the callable object to be invoked.
     * @tparam Exception_T The type of the exception to check for (defaults to
     * `void` for any exception).
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    // ========================================================================

    /**
     * @brief Operator struct template to check if an expression throws any
     * exception.
     *
     * @details
     * This partial specialisation checks whether invoking the given callable
     * throws any exception, regardless of type. The check is performed at
     * construction time, with the result cached for reporting and
     * composition. Use this when a test must verify that an operation raises
     * an exception without caring about the specific exception type.
     *
     * @tparam Callable_T The type of the callable object to be invoked.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

    // ========================================================================

    /**
     * @brief Operator struct template to check if an expression does not throw
     * any exception.
     *
     * @details
     * This struct checks whether invoking the given callable completes
     * without throwing an exception. The check is performed at construction
     * time, with the result cached for reporting and composition. Use this
     * when a test must verify that an operation does not throw.
     *
     * @tparam Callable_T The type of the callable object to be invoked.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
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

#endif // defined(__cpp_exceptions)

    // ========================================================================

    /**
     * @brief Appends the string representation of a numeric value to a
     * buffer, using locale-independent formatting.
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

    /**
     * @brief Converts any pointer to the `void*` expected by the `%p`
     * conversion of `printf()`.
     *
     * @details
     * Pointers to `const` or `volatile` objects are accepted too; the
     * qualifiers are removed only to pass the address to `printf()`, which
     * does not access the object.
     *
     * @tparam T The type pointed to (an object or a function type).
     * @param v The pointer.
     * @return The same address, as `void*`.
     */
    template <class T>
    [[nodiscard]] constexpr void*
    to_printable_pointer_ (T* v) noexcept;

    // ========================================================================

    /**
     * @brief A C string operand of a comparator.
     *
     * @details
     * The comparators convert the `char` arrays (including the string
     * literals) and the `char` pointers to this type (see `as_operand_()`),
     * so that they are compared by content, as a reader of a test expects,
     * and not by address. A null pointer is equal only to another null
     * pointer (not to an empty string), and is less than any string.
     *
     * The characters are not copied; the operand must outlive the
     * comparison, which is always the case within a check.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct c_string_
    {
      /**
       * @brief Constructs the operand from a pointer to a null-terminated
       * string.
       *
       * @param str The string, or `nullptr`.
       */
      constexpr explicit c_string_ (const char* str) noexcept;

      /**
       * @brief Constructs the operand from a `char` array.
       *
       * @details
       * The string ends at the first null character, or at the end of the
       * array, so that an array without a terminator is not read beyond
       * its end.
       *
       * @param str The first character of the array.
       * @param capacity The number of elements of the array.
       */
      constexpr c_string_ (const char* str, std::size_t capacity) noexcept;

      /**
       * @brief Returns the characters, as a string view.
       *
       * @par Parameters
       *   None.
       * @return The characters, without the terminator; empty for a null
       * pointer.
       */
      [[nodiscard]] constexpr std::string_view
      view (void) const noexcept;

      /**
       * @brief Returns whether the operand is a null pointer.
       *
       * @par Parameters
       *   None.
       * @retval true The operand is a null pointer.
       * @retval false The operand is a string, possibly empty.
       */
      [[nodiscard]] constexpr bool
      is_null (void) const noexcept;

    private:
      /**
       * @brief The first character, or `nullptr`.
       *
       * @details
       * Not owned; points into the operand passed to the comparator.
       */
      const char* str_;

      /**
       * @brief The number of characters, without the terminator.
       *
       * @details
       * Computed by the constructors; zero for a null pointer.
       */
      std::size_t size_;
    };

    /**
     * @brief Compares two C string operands for equality.
     *
     * @param lhs The left operand.
     * @param rhs The right operand.
     * @retval true Both are null, or both are strings with the same
     * characters.
     * @retval false Otherwise.
     */
    [[nodiscard]] constexpr bool
    operator== (const c_string_& lhs, const c_string_& rhs) noexcept;

    /**
     * @brief Compares a C string operand with a string.
     *
     * @details
     * Also used for `std::string` operands, which convert to
     * `std::string_view`, and, as a rewritten candidate, with the operands
     * in the reverse order.
     *
     * @param lhs The C string operand.
     * @param rhs The string.
     * @retval true The operand is not null and has the same characters.
     * @retval false Otherwise.
     */
    [[nodiscard]] constexpr bool
    operator== (const c_string_& lhs, std::string_view rhs) noexcept;

    /**
     * @brief Checks whether a C string operand is a null pointer.
     *
     * @param lhs The C string operand.
     * @retval true The operand is a null pointer.
     * @retval false Otherwise.
     */
    [[nodiscard]] constexpr bool
    operator== (const c_string_& lhs, std::nullptr_t) noexcept;

    /**
     * @brief Orders two C string operands.
     *
     * @param lhs The left operand.
     * @param rhs The right operand.
     * @return The lexicographic order of the characters; a null pointer is
     * equal to another null pointer and less than any string.
     */
    [[nodiscard]] constexpr std::strong_ordering
    operator<=> (const c_string_& lhs, const c_string_& rhs) noexcept;

    /**
     * @brief Orders a C string operand and a string.
     *
     * @param lhs The C string operand.
     * @param rhs The string.
     * @return The lexicographic order of the characters; a null pointer is
     * less than any string.
     */
    [[nodiscard]] constexpr std::strong_ordering
    operator<=> (const c_string_& lhs, std::string_view rhs) noexcept;

    /**
     * @brief Prepares an operand of a comparator.
     *
     * @details
     * The `char` arrays and the `char` pointers (not those of `signed
     * char` or `unsigned char`, which are byte buffers) are converted to
     * `c_string_`, so that they are compared by content; the other arrays
     * are converted to pointers to their first element, the functions to
     * function pointers, and all other operands are returned unchanged, so
     * the other pointers, arrays, and functions are compared by address.
     *
     * @tparam T The type of the operand.
     *
     * @param t The operand.
     * @return A `c_string_` for the C strings, otherwise a reference to
     * `t`.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    as_operand_ (const T& t) noexcept -> decltype (auto);

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/detail-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------
