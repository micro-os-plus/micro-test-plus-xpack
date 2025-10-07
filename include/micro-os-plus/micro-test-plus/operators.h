/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2025 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ header file with declarations for the µTest++ operators.
 *
 * @details
 * This header provides the declarations for the custom operator overloads used
 * within the µTest++ framework. It defines interfaces for equality,
 * inequality, relational, and logical operators tailored for use with the
 * framework’s strongly-typed constants, wrappers, containers, and string
 * views.
 *
 * These operator overloads enable expressive, concise, and type-safe test
 * assertions, supporting both compile-time and run-time evaluation. The
 * operators are selectively enabled for types recognised by the framework,
 * minimising the risk of conflicts with user-defined or standard operators.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::operators` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_OPERATORS_H_
#define MICRO_TEST_PLUS_OPERATORS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <string_view>

#include "detail.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::operators
   * @brief Custom operator overloads for expressive and type-safe test
   * assertions.
   *
   * @details
   * The `micro_os_plus::micro_test_plus::operators` namespace provides a
   * comprehensive set of custom operator overloads designed to enable
   * expressive, concise, and type-safe test assertions within the µTest++
   * framework.
   *
   * This namespace includes equality, inequality, relational, and logical
   * operators tailored for use with the framework’s custom types, containers,
   * and string views. These operators facilitate the creation of clear and
   * readable test expressions, supporting both strongly-typed constants (via
   * user-defined literals) and dynamic values (via wrappers).
   *
   * @warning Please be aware that these operators
   * may conflict with other operators defined within the application under
   * test.
   *
   * To minimise conflicts with application-defined operators, these overloads
   * are enabled only for specific types recognised by the framework, such as
   * those derived from the local `op` base type or identified as containers or
   * string views. Constants typically require a literal suffix (e.g., `1_i`),
   * while dynamic values should be wrapped using the provided casting
   * utilities (e.g., `mt::to_i{...}`).
   *
   * All definitions within this namespace are implemented in the
   * `include/micro-os-plus/micro-test-plus` folder, ensuring a modular and
   * maintainable codebase.
   */
  namespace operators
  {
    // In order to simplify things and use the return type `auto`,
    // the definition must be included before any use.

    /**
     * @ingroup micro-test-plus-string-operators
     * @brief Equality operator for `string_view` objects.
     *
     * @param [in] lhs The left hand side `std::string_view` operand.
     * @param [in] rhs The right hand side `std::string_view` operand.
     * @return A comparator object that evaluates to true if the string views
     * are equal.
     *
     * @details
     * This overload of the equality operator enables direct comparison of two
     * `std::string_view` objects within the µTest++ framework. It constructs a
     * comparator object that can be used in test expectations and assertions
     * to verify that two string views are equal.
     */
    [[nodiscard]] constexpr auto
    operator== (std::string_view lhs, std::string_view rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-string-operators
     * @brief Non-equality operator for `string_view` objects.
     *
     * @param [in] lhs The left hand side `std::string_view` operand.
     * @param [in] rhs The right hand side `std::string_view` operand.
     * @return A comparator object that evaluates to true if the string views
     * are not equal.
     *
     * @details
     * This overload of the non-equality operator enables direct comparison of
     * two `std::string_view` objects within the µTest++ framework. It
     * constructs a comparator object that can be used in test expectations and
     * assertions to verify that two string views are not equal.
     */
    [[nodiscard]] constexpr auto
    operator!= (std::string_view lhs, std::string_view rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-container-operators
     * @brief Equality operator for containers.
     *
     * @tparam T The container type, constrained to recognised container types.
     *
     * @param [in] lhs The left hand side container operand.
     * @param [in] rhs The right hand side container operand.
     * @return A comparator object that evaluates to true if the containers are
     * equal.
     *
     * @details
     * This overload of the equality operator enables direct comparison of two
     * container objects within the µTest++ framework. It constructs a
     * comparator object that can be used in test expectations and assertions
     * to verify that two containers are equal in content and order.
     *
     * The operator is enabled only for types recognised as containers by the
     * framework's type traits.
     */
    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator== (T&& lhs, T&& rhs)
    {
      return detail::eq_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    /**
     * @ingroup micro-test-plus-container-operators
     * @brief Non-equality operator for containers.
     *
     * @tparam T The container type, constrained to recognised container types.
     *
     * @param [in] lhs The left hand side container operand.
     * @param [in] rhs The right hand side container operand.
     * @return A comparator object that evaluates to true if the containers are
     * not equal.
     *
     * @details
     * This overload of the non-equality operator enables direct comparison of
     * two container objects within the µTest++ framework. It constructs a
     * comparator object that can be used in test expectations and assertions
     * to verify that two containers are not equal in content or order.
     *
     * The operator is enabled only for types recognised as containers by the
     * framework's type traits.
     */
    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator!= (T&& lhs, T&& rhs)
    {
      return detail::ne_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Equality operator for custom types. Matches only if at least one
     * operand is of local type.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the operands are
     * equal.
     *
     * @details
     * This overload of the equality operator enables comparison between two
     * operands, where at least one is a local type derived from the local `op`
     * base. It constructs a comparator object that can be used within the
     * µTest++ framework to assert that the operands are equal. This operator
     * is intended for use with the framework's strongly-typed constants,
     * wrappers, or other custom types, ensuring type-safe and expressive test
     * assertions.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator== (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Non-equality operator for custom types. Matches only if at least
     * one operand is of local type.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the operands are
     * not equal.
     *
     * @details
     * This overload of the non-equality operator enables comparison between
     * two operands, where at least one is a local type derived from the local
     * `op` base. It constructs a comparator object that can be used within the
     * µTest++ framework to assert that the operands are not equal. This
     * operator is intended for use with the framework's strongly-typed
     * constants, wrappers, or other custom types, ensuring type-safe and
     * expressive test assertions.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator!= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Greater than operator. Matches only if at least one operand is of
     * local type (derived from local `op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is greater than the right hand side operand.
     *
     * @details
     * This overload of the greater than operator enables comparison between
     * two operands, where at least one is a local type derived from the local
     * `op` base. It constructs a comparator object that can be used within the
     * µTest++ framework to assert that the left hand side operand is greater
     * than the right hand side operand. This operator is intended for use with
     * the framework's strongly-typed constants, wrappers, or other custom
     * types, ensuring type-safe and expressive test assertions.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator> (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::gt_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Greater than or equal operator. Matches only if at least one
     * operand is of local type (derived from local `op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is greater than or equal to the right hand side operand.
     *
     * @details
     * This overload of the greater than or equal operator enables comparison
     * between two operands, where at least one is a local type derived from
     * the local `op` base. It constructs a comparator object that can be used
     * within the µTest++ framework to assert that the left hand side operand
     * is greater than or equal to the right hand side operand. This operator
     * is intended for use with the framework's strongly-typed constants,
     * wrappers, or other custom types, ensuring type-safe and expressive test
     * assertions.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator>= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ge_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Less than operator. Matches only if at least one operand is of
     * local type (derived from local `op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is less than the right hand side operand.
     *
     * @details
     * This overload of the less than operator enables comparison between two
     * operands, where at least one is a local type derived from the local `op`
     * base. It constructs a comparator object that can be used within the
     * µTest++ framework to assert that the left hand side operand is less than
     * the right hand side operand. This operator is intended for use with the
     * framework's strongly-typed constants, wrappers, or other custom types,
     * ensuring type-safe and expressive test assertions.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator< (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::lt_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Less than or equal operator. Matches only if at least one operand
     * is of local type (derived from local `op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is less than or equal to the right hand side operand.
     *
     * @details
     * This overload of the less than or equal operator enables comparison
     * between two operands, where at least one is a local type derived from
     * the local `op` base. It constructs a comparator object that can be used
     * within the µTest++ framework to assert that the left hand side operand
     * is less than or equal to the right hand side operand. This operator is
     * intended for use with the framework's strongly-typed constants,
     * wrappers, or other custom types, ensuring type-safe and expressive test
     * assertions.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator<= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::le_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `&&` (and) operator. Matches only if at least one operand
     * is of local type (derived from local `op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A logical conjunction object that evaluates to true if both
     * operands are true.
     *
     * @details
     * This overload of the logical `&&` (and) operator enables conjunction
     * between two operands, where at least one is a local type derived from
     * the local `op` base. It constructs a logical conjunction object that can
     * be used within the µTest++ framework to assert that both operands
     * evaluate to true. This operator is intended for use with the framework's
     * strongly-typed constants, wrappers, or other custom types, ensuring
     * type-safe and expressive test assertions.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator and (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::and_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `||` (or) operator. Matches only if at least one operand
     * is of local type (derived from local `op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A logical disjunction object that evaluates to true if at least
     * one operand is true.
     *
     * @details
     * This overload of the logical `||` (or) operator enables disjunction
     * between two operands, where at least one is a local type derived from
     * the local `op` base. It constructs a logical disjunction object that can
     * be used within the µTest++ framework to assert that at least one operand
     * evaluates to true. This operator is intended for use with the
     * framework's strongly-typed constants, wrappers, or other custom types,
     * ensuring type-safe and expressive test assertions.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator or (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::or_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `!` (not) operator. Matches only if the operand is of
     * local type (derived from local `op`).
     *
     * @tparam T Type of the operand, constrained to types derived from the
     * local `op` base.
     *
     * @param [in] t Operand to be logically negated.
     * @return A logical negator object that evaluates to true if the operand
     * is false.
     *
     * @details
     * This overload of the logical `!` (not) operator enables logical negation
     * of an operand, provided it is a local type derived from the local `op`
     * base. It constructs a logical negator object that can be used within the
     * µTest++ framework to assert that a given condition is false. This
     * operator is intended for use with the framework's strongly-typed
     * constants, wrappers, or other custom types, ensuring type-safe and
     * expressive test assertions.
     */
    template <class T, type_traits::requires_t<type_traits::is_op_v<T>> = 0>
    [[nodiscard]] constexpr auto
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

#endif // MICRO_TEST_PLUS_OPERATORS_H_

// ----------------------------------------------------------------------------
