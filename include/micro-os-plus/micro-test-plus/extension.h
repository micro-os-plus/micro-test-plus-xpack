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
 * the concepts that detect the framework expression types, and the types
 * accepted by `expect()`, `require()`, and the message operator.
 *
 * The public concepts, and the templates `compare_op` and `predicate_op`,
 * reside within the `micro_os_plus::micro_test_plus::extension` namespace,
 * separate from the top namespace, so that `using namespace` on the top
 * namespace does not bring their generic names into the application code.
 *
 * The concepts used only by the implementation, which detect the framework
 * constants, the containers, and the strings, reside within the `detail`
 * namespace.
 *
 * The marker base `detail::op` of the framework expression types is
 * defined here; the deprecated value wrappers, in the `detail` namespace,
 * are declared in `deprecated.h`.
 *
 * The deprecated v5.0.1 `type_traits` namespace, which refers to these
 * concepts and to the value wrappers, is declared in `deprecated.h`.
 *
 * This file is included by `micro-os-plus/micro-test-plus.h`, which is the
 * header that the applications include.
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

#include <concepts>
#include <iterator>
#include <memory>
#include <optional>
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

    // ========================================================================

    /**
     * @brief Empty base struct for the framework expression types.
     *
     * @details
     * The `op` struct is the common base of the comparators defined in
     * `detail.h`, of `floating_point_constant`, and of `named_bool`. It
     * provides the
     * `op_type` marker, which the `extension::is_op` and
     * `extension::any_op` concepts use to distinguish the framework
     * types from the user types, so that `expect()`, `require()`, and the
     * operators in the `operators` namespace accept them.
     *
     * The types that must not have an empty base, like `value_base`,
     * declare the `op_type` marker directly instead of deriving from
     * `op`.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct op
    {
      /**
       * @brief Marker identifying the framework expression types.
       *
       * @details
       * Detected by the `extension::is_op` concept, and inherited by
       * all types derived from `op`.
       */
      using op_type = op;
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Trait marking the wrappers of a `bool`, whose condition is
     * ambiguous.
     *
     * @details
     * The primary template is `false`; it is `true` for `std::optional`,
     * `std::unique_ptr`, and `std::shared_ptr` of `bool` (ignoring the
     * cv-qualifiers of the wrapper and of the element).
     *
     * @tparam T The type to check.
     */
    template <class T>
    struct is_bool_wrapper : std::false_type
    {
    };

    /**
     * @brief The specialisation for `std::optional<bool>`.
     *
     * @details
     * `true`; the condition of the optional tells whether a value is
     * present, not the value itself.
     *
     * @tparam T The element type, `bool`, possibly cv-qualified.
     */
    template <class T>
      requires std::is_same_v<std::remove_cv_t<T>, bool>
    struct is_bool_wrapper<std::optional<T>> : std::true_type
    {
    };

    /**
     * @brief The specialisation for `std::unique_ptr` of `bool`.
     *
     * @details
     * `true`, for any deleter; the condition of the pointer tells whether
     * it is not null, not the value it points to.
     *
     * @tparam T The element type, `bool`, possibly cv-qualified.
     * @tparam Deleter_T The type of the deleter.
     */
    template <class T, class Deleter_T>
      requires std::is_same_v<std::remove_cv_t<T>, bool>
    struct is_bool_wrapper<std::unique_ptr<T, Deleter_T>> : std::true_type
    {
    };

    /**
     * @brief The specialisation for `std::shared_ptr` of `bool`.
     *
     * @details
     * `true`; the condition of the pointer tells whether it is not null,
     * not the value it points to.
     *
     * @tparam T The element type, `bool`, possibly cv-qualified.
     */
    template <class T>
      requires std::is_same_v<std::remove_cv_t<T>, bool>
    struct is_bool_wrapper<std::shared_ptr<T>> : std::true_type
    {
    };

    /**
     * @brief Concept satisfied by the wrappers of a `bool`, whose
     * condition is ambiguous.
     *
     * @details
     * The condition of a `std::optional<bool>`, or of a smart pointer to
     * a `bool`, tests the wrapper (a value is present, or the pointer is
     * not null), not the `bool` that it holds, which is what a reader
     * of `t.expect (flag)` assumes; a check with `false` inside would
     * pass, and be reported as `true`, for another reason than the one
     * the author had in mind, as the checks of the arguments that are
     * always true (see `suspicious_condition`). A check that passes
     * silently by mistake is worse than one that does not compile, so
     * `extension::checkable` rejects these types, and the application
     * writes `has_value()`, `!= nullptr`, or compares the value with
     * `eq()`. The wrappers of the other types are accepted, since the
     * presence of a value is then the only meaning of the condition.
     *
     * @tparam T The type to check.
     */
    template <class T>
    concept ambiguous_condition = is_bool_wrapper<std::remove_cv_t<T>>::value;

    // ------------------------------------------------------------------------

    /**
     * @brief Concept satisfied when a type is contextually
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

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::extension
   * @brief The templates and the concepts for extending the µTest++ testing
   * framework.
   *
   * @details
   * The `extension` namespace holds what the applications use to write
   * their own comparators, predicates, operators, and helpers, reported
   * as the built-in ones are:
   * - `compare_op` and `predicate_op` (defined in `detail.h`), the
   *   expressions of the binary comparisons and of the unary predicates,
   *   parametrised by a tag that defines the operation and its symbol in
   *   the failure reports; they are built from the operands and a tag
   *   object, for example `compare_op{ lhs, rhs, my_tag{} }`, with the
   *   template arguments deduced, and the tag satisfies `compare_tag`
   *   (`predicate_tag` for the predicates);
   * - the C++20 concepts with the same constraints as the framework
   *   itself: whether a type is a framework expression type (`is_op`,
   *   `any_op`), and whether it is accepted by `expect()` and
   *   `require()` (`checkable`) or by the message operator (`printable`),
   *   and the constraints of the tags (`compare_tag`, `predicate_tag`)
   *   and of the operands of the approximate comparator
   *   (`approx_operand`);
   *   with the deprecated functionality enabled, they also tell whether a
   *   deprecated value wrapper carries a floating-point tolerance
   *   (`has_epsilon`).
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
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-customisation
     * @brief Concept satisfied when a type is a framework expression
     * type.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `is_op` concept is satisfied when `T` has the `op_type` member
     * type alias of `detail::op`, either inherited from the `detail::op`
     * base struct, or declared directly, which avoids the empty base. It is
     * used throughout the framework,
     * both as a constraint and as a boolean expression in `if constexpr`
     * contexts.
     *
     * A custom comparator or operator uses it to tell the framework
     * expressions, like the result of `eq()` or `lt()`, from the values of
     * the application. The applications build their own expressions with
     * `extension::compare_op` and `extension::predicate_op`, not by
     * declaring the `op_type` marker, which the formatter could not
     * report.
     */
    template <class T>
    concept is_op
        = requires { requires std::same_as<typename T::op_type, detail::op>; };

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated concept satisfied when `T` is a framework
     * floating-point wrapper with a tolerance.
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
     *
     * Only the deprecated floating-point wrappers have a tolerance, so the
     * concept is deprecated with them, and is available only when
     * `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED` is defined.
     *
     * @deprecated to be removed with the deprecated floating-point
     * wrappers (since 6.0.0)
     */
    template <class T>
    concept has_epsilon = is_op<T> and requires (const T& t) { t.epsilon; };
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-customisation
     * @brief Concept satisfied when at least one of two types is a
     * framework expression type.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @details
     * The `any_op` concept is satisfied when `Lhs_T` or `Rhs_T` (or both)
     * are framework expression types (see `is_op`). A custom operator
     * constrains its overload with it, so that the overload is enabled only
     * when at least one operand is a framework expression type, and does not
     * compete with the operators of the application types. The framework
     * itself uses it only for the deprecated operators.
     */
    template <class Lhs_T, class Rhs_T>
    concept any_op = is_op<Lhs_T> or is_op<Rhs_T>;

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-customisation
     * @brief Concept satisfied when a type can be used as a test
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
     * and to characters), which would make the check pass by mistake,
     * nor the wrappers of a `bool` (`std::optional<bool>`, and the smart
     * pointers to `bool`), whose condition tests the wrapper, not the
     * `bool` that it holds.
     * It is used to constrain the `expect()` and
     * `require()` function templates, and the operands of `all_of()`,
     * `any_of()`, and `negate()`, ensuring that only sensible
     * expression types are accepted, also when they are wrapped in a
     * logical combinator; an application helper that forwards its
     * argument to them uses it for the same constraint.
     *
     * The condition of the conditional operator, which cannot be
     * overloaded, is used to test the contextual conversion, applied to
     * a `const` value, as `expect()` and `require()` receive it.
     */
    template <class T>
    concept checkable = is_op<T>
                        or (not detail::suspicious_condition<T>
                            and not detail::ambiguous_condition<T>
                            and requires (const T& t) { t ? true : false; });

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-customisation
     * @brief Concept satisfied when a type can be appended to the
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

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-customisation
     * @brief Concept satisfied by a tag that defines a custom comparator.
     *
     * @details
     * The tag of `extension::compare_op` is a structure with a static
     * `symbol`, which the failure reports write between the two operands,
     * and a static `apply()` member function template, which receives the
     * operands, unwrapped, and returns the result of the comparison. The
     * `symbol` must be printable, usually a `const char*` that includes
     * the surrounding spaces; the result of `apply()` must be convertible
     * to `bool`.
     *
     * @tparam Tag_T The type of the tag.
     * @tparam Lhs_T The type of the left hand side operand, as `apply()`
     * receives it.
     * @tparam Rhs_T The type of the right hand side operand, as `apply()`
     * receives it.
     */
    template <class Tag_T, class Lhs_T, class Rhs_T>
    concept compare_tag = requires (const Lhs_T& lhs, const Rhs_T& rhs) {
      requires printable<std::remove_cvref_t<decltype (Tag_T::symbol)>>;
      { Tag_T::apply (lhs, rhs) } -> std::convertible_to<bool>;
    };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-customisation
     * @brief Concept satisfied by a tag that defines a custom predicate.
     *
     * @details
     * The tag of `extension::predicate_op` is a structure with a static
     * `symbol`, which the failure reports write before the operand, and
     * a static `apply()` member function template, which receives the
     * operand, unwrapped, and returns the result of the predicate. The
     * `symbol` must be printable; the result of `apply()` must be
     * convertible to `bool`.
     *
     * @tparam Tag_T The type of the tag.
     * @tparam T The type of the operand, as `apply()` receives it.
     */
    template <class Tag_T, class T>
    concept predicate_tag = requires (const T& operand) {
      requires printable<std::remove_cvref_t<decltype (Tag_T::symbol)>>;
      { Tag_T::apply (operand) } -> std::convertible_to<bool>;
    };

    // ------------------------------------------------------------------------
  } // namespace extension

  // --------------------------------------------------------------------------

  namespace detail
  {

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @brief Concept satisfied when a type was accepted by
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
    concept legacy_checkable
        = (not extension::checkable<T>) and suspicious_condition<T>
          and requires (const T& t) { t ? true : false; };
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    // ------------------------------------------------------------------------
    // Concepts used only by the implementation.

    /**
     * @brief Concept satisfied when `T` provides both `begin()` and
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
     * @brief Concept satisfied when `T` is a string, convertible to
     * a `std::basic_string_view` of a character type.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `string_like` concept is satisfied when a `const` object of
     * type `T` is implicitly convertible to a `std::basic_string_view`
     * of `char`, `wchar_t`, `char8_t`, `char16_t`, or `char32_t`, as the
     * standard strings and the string views are. It is used to detect the
     * strings, which the formatter writes as text, not element by element
     * (see `formattable_range`). A container that has only a member named
     * `npos`, or that is not convertible, is not a string.
     */
    template <class T>
    concept string_like
        = std::convertible_to<const T&, std::basic_string_view<char>>
          or std::convertible_to<const T&, std::basic_string_view<wchar_t>>
          or std::convertible_to<const T&, std::basic_string_view<char8_t>>
          or std::convertible_to<const T&, std::basic_string_view<char16_t>>
          or std::convertible_to<const T&, std::basic_string_view<char32_t>>;

    /**
     * @brief Concept satisfied when `T` provides `begin()` and
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
     * @brief Concept satisfied when `T` is a range that the formatter
     * writes element by element.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `formattable_range` concept is satisfied when `T` can be
     * iterated by a range-based `for` statement, with `begin()` and
     * `end()` members (`container_like`) or functions (`free_range`),
     * and:
     * - is not an array, since the comparators convert the arrays to
     *   `basic_c_string`, written as text, or to `array_operand`, a
     *   range (see `as_operand()`), and an array given to the formatter
     *   directly is written as text, if it holds characters, or
     *   otherwise as the address it decays to;
     * - is not a string (see `string_like`), which is written as text;
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
          and (not string_like<T>)
          and (not std::is_same_v<typename range_element<T>::type, T>)
          and extension::printable<typename range_element<T>::type>;

    /**
     * @brief Concept satisfied when `T` is a callable object that
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
     * @brief Concept satisfied when `T` can be appended to the
     * message of a check.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `message_argument` concept is satisfied by a `lazy_message`, or
     * by a value that satisfies `extension::printable`, except a class
     * type callable without arguments that is not a `lazy_message`. A
     * lambda without captures, which returns `void` or a value that
     * cannot be written, converts to a function pointer and then to
     * `bool`, so it would be written as `true` instead of being rejected;
     * the message must be a value, or a callable object that returns one.
     */
    template <class T>
    concept message_argument
        = lazy_message<T>
          or (extension::printable<T>
              and not(std::is_class_v<T> and std::invocable<const T&>));

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @brief Concept satisfied when `T` is a framework compile-time
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
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

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
