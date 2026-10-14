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
 * @brief C++ header file with declarations for the µTest++ type trait
 * utilities and metaprogramming support.
 *
 * @details
 * This header provides the declarations for the type trait utilities and
 * metaprogramming constructs used within the µTest++ framework. It defines
 * templates for function traits, type lists, and identity, and the concepts
 * that detect containers, strings, the framework value wrappers and
 * comparators, and the types accepted by `expect()` and by the message
 * operator.
 *
 * The value wrappers themselves are declared in `values.h`, in the `detail`
 * namespace.
 *
 * These utilities underpin advanced template programming, type deduction, and
 * compile-time introspection, supporting the flexible and type-safe design of
 * the framework.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::type_traits` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * All header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_TYPE_TRAITS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TYPE_TRAITS_H_

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

  /**
   * @namespace micro_os_plus::micro_test_plus::type_traits
   * @brief Type trait utilities and metaprogramming support for the µTest++
   * testing framework.
   *
   * @details
   * The `type_traits` namespace offers a comprehensive suite of type trait
   * templates and metaprogramming utilities employed throughout the µTest++
   * framework.
   *
   * This includes templates for function traits, type lists, and identity,
   * and the C++20 concepts that detect container and string types, the
   * framework value wrappers and comparators, and the types accepted by
   * `expect()`, `require()`, and the message operator.
   *
   * These utilities facilitate advanced template programming, type deduction,
   * and compile-time introspection, supporting the flexible and type-safe
   * design of the framework.
   *
   * All definitions within this namespace are implemented in the
   * `include/micro-os-plus/micro-test-plus` folder to maintain a structured
   * and modular codebase.
   */
  namespace type_traits
  {
    /**
     * @brief Struct template representing a compile-time type list.
     *
     * @tparam Types The types to be included in the list.
     *
     * @details
     * The `list` struct template provides a mechanism for grouping an
     * arbitrary number of types into a single type list at compile time. This
     * is a fundamental building block for template metaprogramming, enabling
     * operations such as type iteration, transformation, and introspection
     * within the µTest++ framework.
     *
     * The type list is commonly used in conjunction with function traits and
     * other metaprogramming utilities to facilitate advanced type
     * manipulations and compile-time computations.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class... Types>
    struct list
    {
    };

    /**
     * @brief Struct template for compile-time type identity.
     *
     * @tparam T The type to be preserved.
     * @tparam Extra Additional template parameters, ignored. The variadic
     *   `Extra` parameter pack absorbs additional type arguments that may
     *   arise during template argument deduction in some metaprogramming
     *   contexts, preventing substitution failures.
     *
     * @details
     * The `identity` struct template provides a mechanism for preserving a
     * type `T` during template metaprogramming. It is commonly used to delay
     * type evaluation or to forward types in complex template constructs
     * within the µTest++ framework.
     *
     * This utility is particularly useful in scenarios where type deduction or
     * concept constraints are required, as it allows the type to be carried
     * through template specialisations without modification.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T, class... Extra>
    struct identity
    {
      /**
       * @brief Alias for the preserved type.
       *
       * @details
       * Always `T`; the `Extra` parameters do not affect it.
       */
      using type = T;
    };

#if defined(__DOXYGEN__)
    // error: Detected potential recursive class relation between class
    // micro_os_plus::micro_test_plus::type_traits::function_traits and base
    // class micro_os_plus::micro_test_plus::type_traits::function_traits<
    // decltype(&T::operator())>!
    // https://github.com/doxygen/doxygen/issues/9915
#else
    /**
     * @brief Struct template for extracting function traits from callable
     * types.
     *
     * @tparam T The callable type for which traits are to be extracted.
     *
     * @details
     * The `function_traits` struct template provides compile-time
     * introspection of callable types, such as function pointers, member
     * functions, and functors (including lambdas). For generic callable types,
     * this primary template inherits from the specialisation for the type of
     * the call operator, enabling seamless trait extraction for user-defined
     * functors and lambdas.
     *
     * This mechanism allows the µTest++ framework to deduce argument types and
     * return types of arbitrary callables, supporting advanced template
     * metaprogramming and flexible test case registration.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct function_traits : function_traits<decltype (&T::operator())>
    {
    };
#endif // defined(__DOXYGEN__)

    /**
     * @brief Struct template specialisation for extracting function traits
     * from function pointer types.
     *
     * @tparam R The return type of the function.
     * @tparam Args_T The argument types of the function.
     *
     * @details
     * This specialisation of the `function_traits` struct template provides
     * compile-time introspection for function pointer types. It exposes the
     * return type and argument types of a function pointer, enabling advanced
     * template metaprogramming and type deduction within the µTest++
     * framework.
     *
     * The `result_type` member defines the return type of the function, while
     * the `args` member is a type list containing all argument types.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class R, class... Args_T>
    struct function_traits<R (*) (Args_T...)>
    {
      /**
       * @brief The return type of the function.
       *
       * @details
       * Deduced from the function signature.
       */
      using result_type = R;

      /**
       * @brief Type list of all argument types.
       *
       * @details
       * Deduced from the function signature, in declaration order.
       */
      using args = list<Args_T...>;
    };

    /**
     * @brief Struct template specialisation for extracting function traits
     * from plain function types.
     *
     * @tparam R The return type of the function.
     * @tparam Args_T The argument types of the function.
     *
     * @details
     * This specialisation of the `function_traits` struct template provides
     * compile-time introspection for plain function types (i.e., non-pointer,
     * non-member functions). It exposes the return type and argument types of
     * a function, enabling advanced template metaprogramming and type
     * deduction within the µTest++ framework.
     *
     * The `result_type` member defines the return type of the function, while
     * the `args` member is a type list containing all argument types.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class R, class... Args_T>
    struct function_traits<R (Args_T...)>
    {
      /**
       * @brief The return type of the function.
       *
       * @details
       * Deduced from the function signature.
       */
      using result_type = R;

      /**
       * @brief Type list of all argument types.
       *
       * @details
       * Deduced from the function signature, in declaration order.
       */
      using args = list<Args_T...>;
    };

    /**
     * @brief Struct template specialisation for extracting function traits
     * from non-const member function types.
     *
     * @tparam R The return type of the member function.
     * @tparam T The class type to which the member function belongs.
     * @tparam Args_T The argument types of the member function.
     *
     * @details
     * This specialisation of the `function_traits` struct template provides
     * compile-time introspection for non-const member function types. It
     * exposes the return type and argument types of a member function,
     * enabling advanced template metaprogramming and type deduction within the
     * µTest++ framework.
     *
     * The `result_type` member defines the return type of the member function,
     * while the `args` member is a type list containing all argument types.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...)>
    {
      /**
       * @brief The return type of the member function.
       *
       * @details
       * Deduced from the function signature.
       */
      using result_type = R;

      /**
       * @brief Type list of all argument types.
       *
       * @details
       * Deduced from the function signature, in declaration order.
       */
      using args = list<Args_T...>;
    };

    /**
     * @brief Struct template specialisation for extracting function traits
     * from const member function types.
     *
     * @tparam R The return type of the const member function.
     * @tparam T The class type to which the member function belongs.
     * @tparam Args_T The argument types of the const member function.
     *
     * @details
     * This specialisation of the `function_traits` struct template provides
     * compile-time introspection for const member function types. It exposes
     * the return type and argument types of a const member function, enabling
     * advanced template metaprogramming and type deduction within the µTest++
     * framework.
     *
     * The `result_type` member defines the return type of the const member
     * function, while the `args` member is a type list containing all argument
     * types.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...) const>
    {
      /**
       * @brief The return type of the const member function.
       *
       * @details
       * Deduced from the function signature.
       */
      using result_type = R;

      /**
       * @brief Type list of all argument types.
       *
       * @details
       * Deduced from the function signature, in declaration order.
       */
      using args = list<Args_T...>;
    };

    // ------------------------------------------------------------------------
    // Concepts.

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
     * @brief C++20 concept satisfied when `T` provides a `value` member.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `has_value` concept is satisfied when an instance of `T` exposes
     * a `value` member. It is used to detect framework value-wrapper types
     * such as `integral_constant`, `floating_point_constant`, and `value<T>`,
     * enabling specialised comparison and reporting.
     */
    template <class T>
    concept has_value = requires (const T& t) { t.value; };

    /**
     * @brief C++20 concept satisfied when `T` provides an `epsilon` member.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `has_epsilon` concept is satisfied when an instance of `T` exposes
     * an `epsilon` member. It is used to detect floating point value-wrapper
     * types such as `floating_point_constant` and the floating point
     * specialisation of `value<T>`, enabling precision-aware comparisons.
     */
    template <class T>
    concept has_epsilon = requires (const T& t) { t.epsilon; };

    /**
     * @brief C++20 concept satisfied when a type derives from `op`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `is_op` concept is satisfied when `T` is derived from the
     * `detail::op` base struct. It is used throughout the framework,
     * both as a constraint and as a boolean expression in `if constexpr`
     * contexts.
     */
    template <class T>
    concept is_op = std::is_base_of_v<detail::op, T>;

    /**
     * @brief C++20 concept satisfied when at least one of two types derives
     * from `op`.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @details
     * The `any_op` concept is satisfied when `Lhs_T` or `Rhs_T` (or both)
     * are derived from the `detail::op` base struct. It is used to
     * constrain binary operator overloads in the `operators` namespace so
     * that they are enabled only when at least one operand is a framework
     * type, avoiding unintended conflicts with user-defined operators.
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
     * framework operator type (derived from `op`) or is implicitly
     * convertible to `bool`. It is used to constrain the `expect()` and
     * `require()` function templates, ensuring that only sensible
     * expression types are accepted.
     */
    template <class T>
    concept checkable = is_op<T> or std::convertible_to<T, bool>;

    /**
     * @brief C++20 concept satisfied when a type can be appended to the
     * deferred reporter's output via `operator<<`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `printable` concept is satisfied when `T` is an arithmetic
     * type, `std::nullptr_t`, or is implicitly convertible to
     * `std::string_view`. It constrains the `operator<<` overload of
     * `deferred_reporter_base`, ensuring that only types that can be
     * meaningfully appended to the output message are accepted.
     *
     * `std::nullptr_t` is listed explicitly since it is convertible to
     * `std::string_view` in C++20, but not in C++23, where the
     * corresponding constructor is deleted.
     */
    template <class T>
    concept printable = std::is_arithmetic_v<T> or std::is_null_pointer_v<T>
                        or std::is_convertible_v<T, std::string_view>;

    // ------------------------------------------------------------------------
  } // namespace type_traits

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TYPE_TRAITS_H_

// ----------------------------------------------------------------------------
