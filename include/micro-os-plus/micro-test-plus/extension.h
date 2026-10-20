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
 * @brief C++ header file with declarations for the µTest++ extension
 * concepts.
 *
 * @details
 * This header provides the C++20 concepts that the applications use to
 * extend the framework with their own comparators, operators, and helpers
 * (the expressions they return, `extension::compare_op` and
 * `extension::predicate_op`, are declared in `detail.h`):
 * the concepts that detect the framework expressions and value wrappers,
 * their floating-point tolerance, and the types accepted by `expect()`,
 * `require()`, and the message operator.
 *
 * The public concepts reside within the
 * `micro_os_plus::micro_test_plus::extension` namespace, separate from the
 * top namespace, so that `using namespace` on the top namespace does not
 * bring their generic names into the application code.
 *
 * The concepts used only by the implementation, which detect the framework
 * constants, the containers, and the strings, reside within the `detail`
 * namespace.
 *
 * The value wrappers themselves are declared in `values.h`, in the `detail`
 * namespace.
 *
 * All header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_EXTENSION_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_EXTENSION_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "values.h"

#include <concepts>
#include <string_view>
#include <type_traits>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace detail
  {
    // Forward definitions.
    class expression_formatter;
  } // namespace detail

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::extension
   * @brief The concepts for extending the µTest++ testing framework.
   *
   * @details
   * The `extension` namespace holds what the applications use to write
   * their own comparators, predicates, operators, and helpers, reported
   * as the built-in ones are:
   * - `compare_op` and `predicate_op` (declared in `detail.h`), the
   *   expressions of the binary comparisons and of the unary predicates,
   *   parametrised by a tag that defines the operation and its symbol in
   *   the failure reports;
   * - the C++20 concepts with the same constraints as the framework
   *   itself: whether a type is a framework expression or value wrapper
   *   (`is_op`, `any_op`), whether it carries a floating-point tolerance
   *   (`has_epsilon`), and whether it is accepted by `expect()` and
   *   `require()` (`checkable`) or by the message operator (`printable`).
   *
   * The namespace is separate from the top namespace, so that
   * `using namespace micro_os_plus::micro_test_plus` does not bring these
   * generic names into the application code; refer to them qualified, as
   * `mt::extension::is_op<T>`.
   */
  namespace extension
  {
    // ------------------------------------------------------------------------
    // Concepts.

    /**
     * @brief C++20 concept satisfied when a type is a framework expression
     * type.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `is_op` concept is satisfied when `T` has the `op_type` member
     * type alias of `detail::op`, either inherited from the `detail::op`
     * base struct, or declared directly, like in `detail::value_base`,
     * which avoids the empty base. It is used throughout the framework,
     * both as a constraint and as a boolean expression in `if constexpr`
     * contexts.
     *
     * A custom comparator or operator uses it to tell the framework
     * operands, like `to_i` or the `_i` literals, from the types of the
     * application. The applications build their own expressions with
     * `extension::compare_op` and `extension::predicate_op`, not by
     * declaring the `op_type` marker, which the formatter could not
     * report.
     */
    template <class T>
    concept is_op
        = requires { requires std::same_as<typename T::op_type, detail::op>; };

    /**
     * @brief C++20 concept satisfied when `T` is a framework floating-point
     * wrapper with a tolerance.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `has_epsilon` concept is satisfied when `T` is a framework
     * expression type (see `is_op`) with an `epsilon` member, like
     * `floating_point_constant` and the floating-point specialisation of
     * `value<T>`. The comparators treat the operands within this tolerance
     * as equal; a custom comparator uses it to do the same.
     *
     * The types of the application are excluded, even if they have a
     * member named `epsilon`, so that they are compared with their own
     * operators.
     */
    template <class T>
    concept has_epsilon = is_op<T> and requires (const T& t) { t.epsilon; };

    /**
     * @brief C++20 concept satisfied when at least one of two types is a
     * framework expression type.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @details
     * The `any_op` concept is satisfied when `Lhs_T` or `Rhs_T` (or both)
     * are framework expression types (see `is_op`). It is used to
     * constrain binary operator overloads in the `operators` namespace so
     * that they are enabled only when at least one operand is a framework
     * type, avoiding unintended conflicts with user-defined operators.
     *
     * A custom operator uses it in the same way, so that it does not
     * compete with the operators of the application types.
     */
    template <class Lhs_T, class Rhs_T>
    concept any_op = is_op<Lhs_T> or is_op<Rhs_T>;

    /**
     * @brief C++20 concept satisfied when a type can be used as a test
     * expression in `expect()` or `require()`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `checkable` concept is satisfied when `T` is either a
     * framework expression type (see `is_op`) or is implicitly
     * convertible to `bool`. It is used to constrain the `expect()` and
     * `require()` function templates, ensuring that only sensible
     * expression types are accepted; an application helper that forwards
     * its argument to them uses it for the same constraint.
     */
    template <class T>
    concept checkable = is_op<T> or std::convertible_to<T, bool>;

    /**
     * @brief C++20 concept satisfied when a type can be appended to the
     * message of a check result via `operator<<`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `printable` concept is satisfied when a value of type `T` can
     * be written to an `expression_formatter`, so the message of a check
     * accepts the same values as the operands of the comparators: the
     * strings, the characters, the arithmetic types, `std::nullptr_t`,
     * the pointers, the containers, the scoped enumerations, the pairs,
     * the tuples, the optionals, the value wrappers, and the application
     * types with an `operator<<` for the formatter, found by
     * argument-dependent lookup. It constrains the `operator<<` overload
     * of `check_result`; an application helper that forwards its argument
     * to the message uses it for the same constraint.
     *
     * The formatter is only declared here; the concept is checked where
     * it is used, after `expression-formatter.h` was included.
     */
    template <class T>
    concept printable = requires (detail::expression_formatter& formatter,
                                  const T& value) { formatter << value; };

    // ------------------------------------------------------------------------
  } // namespace extension

  // --------------------------------------------------------------------------

  namespace detail
  {
    // ------------------------------------------------------------------------
    // Concepts used only by the implementation.

    /**
     * @brief C++20 concept satisfied when `T` provides both `begin()` and
     * `end()` member functions.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `container_like` concept is satisfied when `T` exposes both a
     * `begin()` and an `end()` member function, as required by standard
     * range-based iteration. It is used to detect container types for
     * specialised comparison and reporting within the framework.
     */
    template <class T>
    concept container_like = requires (const T& t) {
      t.begin ();
      t.end ();
    };

    /**
     * @brief C++20 concept satisfied when `T` provides a `npos` member.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `has_npos` concept is satisfied when `T` exposes a static `npos`
     * member, as provided by `std::string_view` and similar types. It is
     * used to detect string-like types for specialised comparison and
     * reporting within the framework.
     */
    template <class T>
    concept has_npos = requires { T::npos; };

    /**
     * @brief C++20 concept satisfied when `T` is a framework compile-time
     * constant.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `has_value` concept is satisfied when `T` is a framework
     * expression type (see `extension::is_op`) with a static `value`
     * member, like `integral_constant` and `floating_point_constant`, the
     * types of the numeric literals. The comparators compare such operands
     * by their `T::value` constants.
     *
     * The types of the application are excluded, even if they have a
     * member named `value`, so that they are compared with their own
     * operators.
     */
    template <class T>
    concept has_value = extension::is_op<T> and requires { T::value; };

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

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_EXTENSION_H_

// ----------------------------------------------------------------------------
