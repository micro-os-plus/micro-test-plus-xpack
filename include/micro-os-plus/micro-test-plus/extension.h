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
 * The deprecated v5.0.1 `type_traits` namespace, which refers to these
 * concepts and to the value wrappers, is declared in `deprecated.h`.
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
#include <iterator>
#include <string_view>
#include <type_traits>
#include <utility>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wdocumentation"
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
     * @brief C++20 concept satisfied when a type is contextually
     * convertible to `bool`, but is most likely not a condition.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `suspicious_condition` concept is satisfied by the arrays
     * (including the string literals), the functions, the pointers to
     * functions and to members, and the pointers to the character types.
     * All of them are contextually convertible to `bool`, so, when
     * passed to `expect()` or `require()`, the check silently passes,
     * usually because the description was written instead of the
     * condition, or because a function name was written without the
     * call. The pointers to other object types are not included, since
     * checking a pointer for null is a legitimate use.
     */
    template <class T>
    concept suspicious_condition
        = std::is_array_v<T> or std::is_function_v<T>
          or std::is_member_pointer_v<T>
          or (std::is_pointer_v<T>
              and (std::is_function_v<std::remove_pointer_t<T>>
                   or std::is_same_v<
                       std::remove_cv_t<std::remove_pointer_t<T>>, char>
                   or std::is_same_v<
                       std::remove_cv_t<std::remove_pointer_t<T>>, wchar_t>
                   or std::is_same_v<
                       std::remove_cv_t<std::remove_pointer_t<T>>, char8_t>
                   or std::is_same_v<
                       std::remove_cv_t<std::remove_pointer_t<T>>, char16_t>
                   or std::is_same_v<
                       std::remove_cv_t<std::remove_pointer_t<T>>, char32_t>));

    /**
     * @brief C++20 concept satisfied when a type can be used as a test
     * expression in `expect()` or `require()`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `checkable` concept is satisfied when `T` is either a
     * framework expression type (see `is_op`) or a type contextually
     * convertible to `bool`, as the condition of an `if` statement is.
     * This includes the types with an `explicit operator bool`, such as
     * `std::optional`, `std::unique_ptr`, `std::shared_ptr`, and
     * `std::function`, but not the scoped enumerations, which only a
     * cast converts, nor the types satisfying `suspicious_condition`
     * (the arrays, the functions, the pointers to functions, to members,
     * and to characters), which would make the check pass by mistake.
     * It is used to constrain the `expect()` and
     * `require()` function templates, ensuring that only sensible
     * expression types are accepted; an application helper that forwards
     * its argument to them uses it for the same constraint.
     *
     * The condition of the conditional operator, which cannot be
     * overloaded, is used to test the contextual conversion, applied to
     * a `const` value, as `expect()` and `require()` receive it.
     */
    template <class T>
    concept checkable
        = is_op<T> or (not suspicious_condition<T> and requires (const T& t) {
            t ? true : false;
          });

    /**
     * @brief C++20 concept satisfied when a type was accepted by
     * `expect()` and `require()` before the exclusion of the suspicious
     * conditions.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * Satisfied by the types that are contextually convertible to `bool`
     * but are not `checkable`, i.e. the `suspicious_condition` types. It
     * constrains the deprecated overloads of `expect()` and `require()`,
     * which keep such code compiling for one release, with a warning.
     */
    template <class T>
    concept legacy_checkable = (not checkable<T>) and suspicious_condition<T>
                               and requires (const T& t) { t ? true : false; };

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
     * of `check_result`, which also accepts the callable objects that
     * return a printable value, called only if the check fails; an
     * application helper that forwards a value to the message uses it for
     * the same constraint.
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
     * `end()` member functions returning an iterator and its sentinel.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `container_like` concept is satisfied when `T` exposes both a
     * `begin()` and an `end()` member function, as required by standard
     * range-based iteration, and `begin()` returns a
     * `std::input_or_output_iterator` for which `end()` returns a
     * `std::sentinel_for`. The check is part of the concept, so a type
     * whose `begin()` and `end()` return something else (`void`, for
     * example) is not a container, instead of being a hard error where
     * the element type is formed. It is used to detect the ranges that the
     * formatter writes element by element (see `formattable_range`), and
     * the ranges of values of `test_each()`.
     */
    template <class T>
    concept container_like = requires (const T& t) {
      requires std::input_or_output_iterator<decltype (t.begin ())>;
      requires std::sentinel_for<decltype (t.end ()), decltype (t.begin ())>;
    };

    /**
     * @brief C++20 concept satisfied when `T` provides a `npos` member.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `has_npos` concept is satisfied when `T` exposes a static `npos`
     * member, as provided by `std::string_view` and similar types. It is
     * used to detect the string-like types, which the formatter writes as
     * text, not element by element (see `formattable_range`).
     */
    template <class T>
    concept has_npos = requires { T::npos; };

    /**
     * @brief C++20 concept satisfied when `T` provides `begin()` and
     * `end()` only as functions found by argument-dependent lookup.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `free_range` concept is satisfied when `T` has no `begin()`
     * and `end()` members (see `container_like`), but calls of `begin()`
     * and `end()` with a `const T&` argument are valid and return an
     * iterator and its sentinel, as in a range-based `for` statement,
     * which then uses them.
     */
    template <class T>
    concept free_range = (not container_like<T>) and requires (const T& t) {
      requires std::input_or_output_iterator<decltype (begin (t))>;
      requires std::sentinel_for<decltype (end (t)), decltype (begin (t))>;
    };

    /**
     * @brief The type of the elements of a range, as iterated by a
     * range-based `for` statement.
     *
     * @tparam T The range type, satisfying `container_like` or
     * `free_range`.
     *
     * @details
     * Only declared; the partial specialisations define the member
     * `type`, for the two ways of iterating a range. Used by
     * `formattable_range`.
     */
    template <class T>
    struct range_element;

    /**
     * @brief The type of the elements of a range with `begin()` and
     * `end()` members.
     *
     * @tparam T The range type.
     */
    template <class T>
      requires container_like<T>
    struct range_element<T>
    {
      /**
       * @brief The element type, without references and qualifiers.
       *
       * @details
       * The type of the dereferenced `begin()` member, as iterated by a
       * range-based `for` statement over a `const` range.
       */
      using type = std::remove_cvref_t<
          decltype (*std::declval<const T&> ().begin ())>;
    };

    /**
     * @brief The type of the elements of a range with `begin()` and
     * `end()` functions.
     *
     * @tparam T The range type.
     */
    template <class T>
      requires free_range<T>
    struct range_element<T>
    {
      /**
       * @brief The element type, without references and qualifiers.
       *
       * @details
       * The type of the dereferenced `begin()` function, found by
       * argument-dependent lookup, as in a range-based `for` statement
       * over a `const` range.
       */
      using type
          = std::remove_cvref_t<decltype (*begin (std::declval<const T&> ()))>;
    };

    /**
     * @brief C++20 concept satisfied when `T` is a range that the formatter
     * writes element by element.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `formattable_range` concept is satisfied when `T` can be
     * iterated by a range-based `for` statement, with `begin()` and
     * `end()` members (`container_like`) or functions (`free_range`),
     * and:
     * - is not an array, since the arrays are compared by address, and
     *   are written as addresses, as the pointers they decay to;
     * - is not a string (see `has_npos`), which is written as text;
     * - does not have elements of its own type, like
     *   `std::filesystem::path`, whose elements are paths, so that
     *   formatting it would recurse without end;
     * - has elements that satisfy `extension::printable`, so that a range
     *   of elements that cannot be reported is rejected where it is
     *   compared, not where its elements are formatted.
     *
     * The conditions are tested in this order, so the elements of a
     * recursive range are not tested.
     */
    template <class T>
    concept formattable_range
        = (container_like<T> or free_range<T>) and (not std::is_array_v<T>)
          and (not has_npos<T>)
          and (not std::is_same_v<typename range_element<T>::type, T>)
          and extension::printable<typename range_element<T>::type>;

    /**
     * @brief C++20 concept satisfied when `T` is a callable object that
     * returns a printable message.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `lazy_message` concept is satisfied when `T` is a class type,
     * such as a lambda or a `std::function`, callable without arguments
     * as a `const` object, whose result is not `void` and satisfies
     * `extension::printable`. The message operator of the checks calls
     * such an object only when the check fails, and appends its result,
     * so that a message that is valid only after a failure (the error of
     * a `std::expected`, for example) is not evaluated after a success.
     *
     * The function pointers are excluded, since they are printable (as
     * addresses), and calling them by mistake could have side effects; a
     * lambda without captures, which converts to a function pointer and
     * then to `bool`, is printable too, and is called, since it is a
     * class type.
     */
    template <class T>
    concept lazy_message
        = std::is_class_v<T> and std::invocable<const T&>
          and (not std::is_void_v<std::invoke_result_t<const T&>>)
          and extension::printable<std::invoke_result_t<const T&>>;

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
