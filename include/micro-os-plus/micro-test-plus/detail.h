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
     * @details
     * The `assertion` struct template is used to encapsulate assertion
     * parameters, including the expression under evaluation and its associated
     * source location. This design enables precise reporting and diagnostics
     * within the framework.
     *
     * The structure is intended exclusively for internal use and is
     * implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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

    // in C++14/17/20, a function template with a deduced return type
    // (auto) cannot be used before its definition is visible.
    // Therefore it is not possible to split definitions.

    /**
     * @brief Generic getter function template for value retrieval.
     *
     * @tparam T The type from which the value is to be retrieved.
     *
     * @param t The object or value to be accessed.
     * @return The value obtained via the relevant getter implementation.
     *
     * @details
     * The `get` function template retrieves the value from the provided
     * object or type. If the type provides a `get()` member function, it
     * is invoked; otherwise the argument itself is returned unchanged.
     *
     * The selection is performed at compile time using `if constexpr` and
     * an inline `requires` expression, superseding the classic two-overload
     * SFINAE technique used prior to C++20.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    get (const T& t)
    {
      if constexpr (requires { t.get (); })
        return t.get ();
      else
        return t;
    }

    // ------------------------------------------------------------------------

    /**
     * @brief Common base struct template for unary comparators.
     *
     * @tparam T The type of the operand.
     *
     * @details
     * The `unary_op_` struct template provides the shared state and
     * interface for unary comparator types within the framework. It stores
     * the single operand and the boolean result of the operation, and
     * exposes a conversion operator and an operand accessor common to all
     * unary comparators.
     *
     * Derived comparator structs (e.g. `not_`) inherit from this base and
     * supply the operation-specific logic via their constructors.
     *
     * All definitions are intended for internal use within the framework
     * and are implemented in the
     * `include/micro-os-plus/micro-test-plus` folder to maintain a
     * structured and modular codebase.
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
      constexpr unary_op_ (const T& t, bool value) : t_{ t }, value_{ value }
      {
      }

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *	None.
       * @return The result of the operation.
       *
       * @details
       * Returns the pre-computed boolean result stored by the derived
       * comparator's constructor.
       */
      [[nodiscard]] constexpr
      operator bool () const
      {
        return value_;
      }

      /**
       * @brief Retrieves the wrapped operand expression.
       *
       * @par Parameters
       *	None.
       * @return The extracted operand value.
       *
       * @details
       * Returns the wrapped operand, applying the generic getter to
       * ensure correct extraction for both custom and standard types.
       * Named `operand()` to distinguish it from the boolean result
       * stored in `value_`.
       */
      [[nodiscard]] constexpr auto
      operand () const
      {
        return get (t_);
      }

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
     * @details
     * The `binary_op_` struct template provides the shared state and interface
     * for all binary comparator types within the framework. It stores the
     * two operands and the boolean result of the comparison, and exposes
     * a conversion operator and value accessors common to all binary
     * comparators.
     *
     * Derived comparator structs (`eq_`, `ne_`, `gt_`, `ge_`, `lt_`, `le_`,
     * `and_`, `or_`) inherit from this base and supply the
     * operation-specific logic via their constructors.
     *
     * All definitions are intended for internal use within the framework
     * and are implemented in the
     * `include/micro-os-plus/micro-test-plus` folder to maintain a
     * structured and modular codebase.
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
      constexpr binary_op_ (const Lhs_T& lhs, const Rhs_T& rhs, bool value)
          : lhs_{ lhs }, rhs_{ rhs }, value_{ value }
      {
      }

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *	None.
       * @return The result of the comparison.
       *
       * @details
       * Returns the pre-computed boolean result stored by the derived
       * comparator's constructor.
       */
      [[nodiscard]] constexpr
      operator bool () const
      {
        return value_;
      }

      /**
       * @brief Retrieves the left-hand operand.
       *
       * @par Parameters
       *	None.
       * @return The extracted left-hand operand.
       *
       * @details
       * Returns the value of the left-hand operand, applying the generic
       * getter to ensure correct extraction for both custom and standard
       * types.
       */
      [[nodiscard]] constexpr auto
      lhs (void) const
      {
        return get (lhs_);
      }

      /**
       * @brief Retrieves the right-hand operand.
       *
       * @par Parameters
       *	None.
       * @return The extracted right-hand operand.
       *
       * @details
       * Returns the value of the right-hand operand, applying the generic
       * getter to ensure correct extraction for both custom and standard
       * types.
       */
      [[nodiscard]] constexpr auto
      rhs (void) const
      {
        return get (rhs_);
      }

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
     * @details
     * The `eq_` struct template provides a type-safe mechanism for evaluating
     * equality between two operands within the framework.
     *
     * This comparator supports a variety of operand types, including those
     * with static values, types with precision (epsilon), and generic types.
     * For types with static values, the comparison is performed directly. For
     * types supporting precision, the comparison accounts for the smallest
     * epsilon to ensure accuracy, particularly for floating-point types. For
     * all other types, the generic getter is used to retrieve and compare the
     * values.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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
       *
       * @details
       * Evaluates the equality of the provided operands and passes the
       * result to the `binary_op_` base class constructor.
       * Supports static values, types with precision, and generic types.
       */
      constexpr eq_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
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
     * @details
     * The `ne_` struct template provides a type-safe mechanism for evaluating
     * non-equality between two operands within the framework.
     *
     * This comparator supports a variety of operand types, including those
     * with static values, types with precision (epsilon), and generic types.
     * For types with static values, the comparison is performed directly. For
     * types supporting precision, the comparison accounts for the smallest
     * epsilon to ensure accuracy, particularly for floating-point types. For
     * all other types, the generic getter is used to retrieve and compare the
     * values.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus` folder to maintain a
     * structured and modular codebase.
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
       *
       * @details
       * Evaluates the non-equality of the provided operands and passes the
       * result to the `binary_op_` base class constructor.
       * Supports static values, types with precision, and generic types.
       */
      constexpr ne_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
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
     * @details
     * The `gt_` struct template provides a type-safe mechanism for evaluating
     * whether the left-hand operand is greater than the right-hand operand
     * within the framework.
     *
     * This comparator supports a variety of operand types, including those
     * with static values and generic types. For types with static values, the
     * comparison is performed directly. For all other types, the generic
     * getter is used to retrieve and compare the values.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus` folder to maintain a
     * structured and modular codebase.
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
       *
       * @details
       * Evaluates whether the left-hand operand is greater than the
       * right-hand operand and passes the result to the `binary_op_` base
       * class constructor.
       * Supports static values and generic types.
       */
      constexpr gt_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
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
     * @details
     * The `ge_` struct template provides a type-safe mechanism for evaluating
     * whether the left-hand operand is greater than or equal to the right-hand
     * operand within the framework.
     *
     * This comparator supports a variety of operand types, including those
     * with static values and generic types. For types with static values, the
     * comparison is performed directly. For all other types, the generic
     * getter is used to retrieve and compare the values.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus` folder to maintain a
     * structured and modular codebase.
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
       *
       * @details
       * Evaluates whether the left-hand operand is greater than or equal
       * to the right-hand operand and passes the result to the `binary_op_`
       * base class constructor.
       * Supports static values and generic types.
       */
      constexpr ge_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
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
     * @details
     * The `lt_` struct template provides a type-safe mechanism for evaluating
     * whether the left-hand operand is less than the right-hand operand within
     * the framework.
     *
     * This comparator supports a variety of operand types, including those
     * with static values and generic types. For types with static values, the
     * comparison is performed directly. For all other types, the generic
     * getter is used to retrieve and compare the values.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus` folder to maintain a
     * structured and modular codebase.
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
       *
       * @details
       * Evaluates whether the left-hand operand is less than the right-hand
       * operand and passes the result to the `binary_op_` base class
       * constructor.
       * Supports static values and generic types.
       */
      constexpr lt_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
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
     * @details
     * The `le_` struct template provides a type-safe mechanism for evaluating
     * whether the left-hand operand is less than or equal to the right-hand
     * operand within the framework.
     *
     * This comparator supports a variety of operand types, including those
     * with static values and generic types. For types with static values, the
     * comparison is performed directly. For all other types, the generic
     * getter is used to retrieve and compare the values.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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
       *
       * @details
       * Evaluates whether the left-hand operand is less than or equal to
       * the right-hand operand and passes the result to the `binary_op_` base
       * class constructor.
       * Supports static values and generic types.
       */
      constexpr le_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
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
     * @details
     * The `and_` struct template provides a type-safe mechanism for evaluating
     * the logical conjunction (AND) of two operands within the framework.
     *
     * This comparator supports a wide range of operand types, applying the
     * generic getter to ensure correct value extraction for both custom and
     * standard types. The result of the logical AND operation is stored in the
     * `value_` member for efficient access.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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
       *
       * @details
       * Evaluates the logical conjunction of the provided operands and
       * passes the result to the `binary_op_` base class constructor.
       */
      constexpr and_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : binary_op_<Lhs_T, Rhs_T>{
              lhs, rhs, static_cast<bool> (lhs) and static_cast<bool> (rhs)
            }
      {
      }
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
     * @details
     * The `or_` struct template provides a type-safe mechanism for evaluating
     * the logical disjunction (OR) of two operands within the framework.
     *
     * This comparator supports a wide range of operand types, applying the
     * generic getter to ensure correct value extraction for both custom and
     * standard types. The result of the logical OR operation is stored in the
     * `value_` member for efficient access.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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
       *
       * @details
       * Evaluates the logical disjunction of the provided operands and
       * passes the result to the `binary_op_` base class constructor.
       */
      constexpr or_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : binary_op_<Lhs_T, Rhs_T>{
              lhs, rhs, static_cast<bool> (lhs) or static_cast<bool> (rhs)
            }
      {
      }
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
     * @details
     * The `not_` struct template provides a type-safe mechanism for evaluating
     * the logical negation (NOT) of an operand within the framework.
     *
     * This comparator supports a wide range of operand types, applying the
     * generic getter to ensure correct value extraction for both custom and
     * standard types. The result of the logical NOT operation is stored in the
     * `value_` member for efficient access.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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
       *
       * @details
       * Evaluates the logical negation of the provided operand and passes
       * the result to the `unary_op_` base class constructor.
       */
      explicit constexpr not_ (const T& t = {})
          : unary_op_<T>{ t, not static_cast<bool> (t) }
      {
      }
    };

    // Deduction guide.
    template <typename T>
    not_ (const T&) -> not_<T>;

    // ------------------------------------------------------------------------

#if defined(__cpp_exceptions)

    /**
     * @brief Common base struct for callable-wrapping operators.
     *
     * @details
     * The `callable_op_` struct provides the shared state and interface
     * for operator types that invoke a callable and reduce the outcome to
     * a single boolean result. It stores the result and exposes a
     * conversion operator, which is common to `throws_` and `nothrow_`.
     *
     * Unlike `unary_op_` and `binary_op_`, no template parameter is
     * needed because the callable itself is not retained after
     * construction.
     *
     * All definitions are intended for internal use within the framework
     * and are implemented in the
     * `include/micro-os-plus/micro-test-plus` folder to maintain a
     * structured and modular codebase.
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
      constexpr explicit callable_op_ (bool value) : value_{ value }
      {
      }

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *	None.
       * @return The result of the callable invocation.
       *
       * @details
       * Returns the pre-computed boolean result stored by the derived
       * operator's constructor.
       */
      [[nodiscard]] constexpr
      operator bool () const
      {
        return value_;
      }

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
     * @details
     * The `throws_` struct template provides a type-safe mechanism for
     * verifying whether a callable expression throws a specified exception
     * type during its execution within the framework.
     *
     * This comparator is designed to support both custom and standard callable
     * types. The result of the exception check is stored in the `value_`
     * member for efficient access.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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
       *
       * @details
       * Invokes the provided callable and determines whether it throws an
       * exception of the specified type, then passes the result to the
       * `callable_op_` base class constructor.
       */
      constexpr explicit throws_ (const Callable_T& func)
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
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Operator struct template to check if an expression throws any
     * exception.
     *
     * @tparam Callable_T The type of the callable object to be invoked.
     *
     * @details
     * The `throws_` struct template provides a type-safe mechanism for
     * verifying whether a callable expression throws any exception during its
     * execution within the framework.
     *
     * This comparator is designed to support both custom and standard callable
     * types. The result of the exception check is stored in the `value_`
     * member for efficient access.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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
       * @details
       * Invokes the provided callable and determines whether it throws any
       * exception, then passes the result to the `callable_op_` base
       * class constructor.
       *
       * @param func The callable object to be invoked.
       */
      constexpr explicit throws_ (const Callable_T& func)
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
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Operator struct template to check if an expression does not throw
     * any exception.
     *
     * @tparam Callable_T The type of the callable object to be invoked.
     *
     * @details
     * The `nothrow_` struct template provides a type-safe mechanism for
     * verifying whether a callable expression completes without throwing any
     * exception during its execution within the framework.
     *
     * This comparator is designed to support both custom and standard callable
     * types. The result of the exception check is stored in the `value_`
     * member for efficient access.
     *
     * The implementation is optimised for use in embedded environments and
     * supports both compile-time and run-time evaluation.
     *
     * All definitions are intended for internal use within the framework and
     * are implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * maintain a structured and modular codebase.
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
       *
       * @details
       * Invokes the provided callable and determines whether it completes
       * without throwing any exception, then passes the result to the
       * `callable_op_` base class constructor.
       */
      constexpr explicit nothrow_ (const Callable_T& func)
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
    };

#endif

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------
