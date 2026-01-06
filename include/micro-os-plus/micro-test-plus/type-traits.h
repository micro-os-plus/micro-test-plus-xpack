/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
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
 * @brief C++ header file with declarations for the µTest++ type trait
 * utilities and metaprogramming support.
 *
 * @details
 * This header provides the declarations for the type trait utilities and
 * metaprogramming constructs used within the µTest++ framework. It defines
 * templates and variable traits for function traits, type lists, identity,
 * value wrappers, compile-time checks for container and floating-point types,
 * and type convertibility.
 *
 * These utilities underpin advanced template programming, type deduction, and
 * compile-time introspection, supporting the flexible and type-safe design of
 * the framework. The provided traits and wrappers enable expressive and
 * generic handling of types, values, and callable objects, facilitating robust
 * and maintainable test code.
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

#ifndef MICRO_TEST_PLUS_TYPE_TRAITS_H_
#define MICRO_TEST_PLUS_TYPE_TRAITS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include "math.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

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
   * This includes templates for function traits, type lists, identity, value
   * wrappers, and compile-time checks for container types, floating point
   * types, and type convertibility. It also provides generic integral and
   * floating point constant wrappers, as well as mechanisms for SFINAE and
   * requirements checking.
   *
   * These utilities facilitate advanced template programming, type deduction,
   * and compile-time introspection, supporting the flexible and type-safe
   * design of the framework.
   *
   * All definitions within this namespace are implemented in the
   * `include/micro-os-plus` folder to maintain a structured and modular
   * codebase.
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
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class... Types>
    struct list
    {
    };

    /**
     * @brief Struct template for compile-time type identity.
     *
     * @tparam T The type to be preserved.
     * @tparam Extra Additional template parameters, ignored.
     *
     * @details
     * The `identity` struct template provides a mechanism for preserving a
     * type `T` during template metaprogramming. It is commonly used to delay
     * type evaluation or to forward types in complex template constructs
     * within the µTest++ framework.
     *
     * This utility is particularly useful in scenarios where type deduction or
     * SFINAE is required, as it allows the type to be carried through template
     * specialisations without modification.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T, class... Extra>
    struct identity
    {
      /**
       * @brief Alias for the preserved type.
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
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct function_traits : function_traits<decltype (&T::operator())>
    {
    };
#endif

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
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class R, class... Args_T>
    struct function_traits<R (*) (Args_T...)>
    {
      /**
       * @brief The return type of the function.
       */
      using result_type = R;

      /**
       * @brief Type list of all argument types.
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
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class R, class... Args_T>
    struct function_traits<R (Args_T...)>
    {
      /**
       * @brief The return type of the function.
       */
      using result_type = R;

      /**
       * @brief Type list of all argument types.
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
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...)>
    {
      /**
       * @brief The return type of the member function.
       */
      using result_type = R;

      /**
       * @brief Type list of all argument types.
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
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...) const>
    {
      /**
       * @brief The return type of the const member function.
       */
      using result_type = R;

      /**
       * @brief Type list of all argument types.
       */
      using args = list<Args_T...>;
    };

    /**
     * @brief Utility function template to simulate std::declval for type
     * deduction.
     *
     * @tparam T The type for which an rvalue reference is required.
     *
     * @par Parameters
     *	 None.
     * @return An rvalue reference to type `T`.
     *
     * @details
     * The `declval` function template provides a mechanism for obtaining an
     * rvalue reference to a type `T` without requiring an actual object. This
     * is primarily used in unevaluated contexts, such as within `decltype`, to
     * deduce types during template metaprogramming in the µTest++ framework.
     */
    template <class T>
    T&&
    declval (void);
    template <class... Ts, class Expr_T>
    constexpr auto
    is_valid (Expr_T expr) -> decltype (expr (declval<Ts...> ()), bool ())
    {
      return true;
    }

    /**
     * @brief Fallback function template for is_valid, returns false if the
     * expression is not valid.
     *
     * @tparam Ts The argument types to be tested.
     *
     * @return `false` indicating the expression is not valid for the given
     * argument types.
     *
     * @details
     * This overload is selected when the primary `is_valid` template cannot be
     * instantiated, providing a `false` result for invalid expressions.
     */
    template <class... Ts>
    constexpr auto
    is_valid (...) -> bool
    {
      return false;
    }

    /**
     * @brief Variable template to determine if a type models a container.
     *
     * @tparam T The type to be checked for container-like behaviour.
     *
     * @retval true if `T` has both `begin()` and `end()` member functions.
     * @retval false otherwise.
     *
     * @details
     * The `is_container_v` variable template evaluates to `true` if the given
     * type `T` provides both `begin()` and `end()` member functions,
     * indicating that it models a standard container concept. This trait is
     * determined at compile time using SFINAE and is_valid, and is used
     * throughout the µTest++ framework to enable generic handling of container
     * types in template metaprogramming.
     */
    template <class T>
    static constexpr auto is_container_v = is_valid<T> (
        [] (auto t) -> decltype (t.begin (), t.end (), void ()) {});

    /**
     * @brief Variable template to determine if a type provides a static `npos`
     * member.
     *
     * @tparam T The type to be checked for the presence of a static `npos`
     * member.
     *
     * @retval true if `T` has a static member named `npos`.
     * @retval false otherwise.
     *
     * @details
     * The `has_npos_v` variable template evaluates to `true` if the given type
     * `T` defines a static member named `npos`. This trait is determined at
     * compile time using SFINAE and the `is_valid` utility, and is used
     * throughout the µTest++ framework to enable generic handling of types
     * that follow the standard string or container conventions.
     */
    template <class T>
    static constexpr auto has_npos_v
        = is_valid<T> ([] (auto t) -> decltype (void (t.npos)) {});

    /**
     * @brief Variable template to determine if a type provides a `value`
     * member.
     *
     * @tparam T The type to be checked for the presence of a `value` member.
     *
     * @retval true if `T` has a member named `value`.
     * @retval false otherwise.
     *
     * @details
     * The `has_value_v` variable template evaluates to `true` if the given
     * type `T` defines a member named `value`. This trait is determined at
     * compile time using SFINAE and the `is_valid` utility, and is used
     * throughout the µTest++ framework to enable generic handling of types
     * that encapsulate a value, such as wrappers or constant types.
     */
    template <class T>
    static constexpr auto has_value_v
        = is_valid<T> ([] (auto t) -> decltype (void (t.value)) {});

    /**
     * @brief Variable template to determine if a type provides an `epsilon`
     * member.
     *
     * @tparam T The type to be checked for the presence of an `epsilon`
     * member.
     *
     * @retval true if `T` has a member named `epsilon`.
     * @retval false otherwise.
     *
     * @details
     * The `has_epsilon_v` variable template evaluates to `true` if the given
     * type `T` defines a member named `epsilon`. This trait is determined at
     * compile time using SFINAE and the `is_valid` utility, and is used
     * throughout the µTest++ framework to enable generic handling of types
     * that represent floating-point values or require precision control.
     */
    template <class T>
    static constexpr auto has_epsilon_v
        = is_valid<T> ([] (auto t) -> decltype (void (t.epsilon)) {});

    /**
     * @brief Variable template to determine if a type is a floating point
     * type.
     *
     * @tparam T The type to be checked for floating point classification.
     *
     * @retval true if `T` is a floating point type.
     * @retval false otherwise.
     *
     * @details
     * The `is_floating_point_v` variable template evaluates to `true` if the
     * given type `T` is a floating point type (`float`, `double`, or `long
     * double`). For all other types, it evaluates to `false`. This trait is
     * used throughout the µTest++ framework to enable type-safe handling and
     * specialisation for floating point types in template metaprogramming.
     *
     * Specialisations are provided for `float`, `double`, and `long double`,
     * each evaluating to `true`.
     */
    template <class T>
    inline constexpr auto is_floating_point_v = false;

    /**
     * @brief Variable template specialisation indicating that `float` is a
     * floating point type.
     *
     * @details
     * This specialisation of the `is_floating_point_v` variable template
     * evaluates to `true` for the `float` type, confirming that it is
     * recognised as a floating point type within the µTest++ framework. This
     * enables type-safe handling and specialisation for floating point types
     * in template metaprogramming.
     *
     * @see is_floating_point_v
     */
    template <>
    inline constexpr auto is_floating_point_v<float> = true;

    /**
     * @brief Variable template specialisation indicating that `double` is a
     * floating point type.
     *
     * @details
     * This specialisation of the `is_floating_point_v` variable template
     * evaluates to `true` for the `double` type, confirming that it is
     * recognised as a floating point type within the µTest++ framework. This
     * enables type-safe handling and specialisation for floating point types
     * in template metaprogramming.
     *
     * @see is_floating_point_v
     */
    template <>
    inline constexpr auto is_floating_point_v<double> = true;

    /**
     * @brief Variable template specialisation indicating that `long double` is
     * a floating point type.
     *
     * @details
     * This specialisation of the `is_floating_point_v` variable template
     * evaluates to `true` for the `long double` type, confirming that it is
     * recognised as a floating point type within the µTest++ framework. This
     * enables type-safe handling and specialisation for floating point types
     * in template metaprogramming.
     *
     * @see is_floating_point_v
     */
    template <>
    inline constexpr auto is_floating_point_v<long double> = true;

#if defined(__clang__) or defined(_MSC_VER)
    /**
     * @brief Variable template to determine if one type is convertible to
     * another.
     *
     * @tparam From The source type to be checked for convertibility.
     * @tparam To The target type to which conversion is tested.
     *
     * @retval true if `From` is convertible to `To`.
     * @retval false otherwise.
     *
     * @details
     * The `is_convertible_v` variable template evaluates to `true` if the type
     * `From` is implicitly convertible to the type `To`, and `false`
     * otherwise. This trait is determined at compile time and is used
     * throughout the µTest++ framework to enable type-safe conversions and
     * requirements checking in template metaprogramming.
     *
     * On supported compilers, this trait leverages compiler intrinsics for
     * optimal performance and accuracy.
     */
    template <class From, class To>
    static constexpr auto is_convertible_v = __is_convertible_to (From, To);
#else
    /**
     * @brief Function template to determine if one type is convertible to
     * another.
     *
     * @tparam From The source type to be checked for convertibility.
     * @tparam To The target type to which conversion is tested.
     *
     * @param n Dummy parameter used for overload resolution.
     * @retval true if `From` is convertible to `To`.
     *
     * @details
     * The `is_convertible` function template checks, at compile time, whether
     * a value of type `From` can be implicitly converted to type `To`. This is
     * achieved using SFINAE and is primarily used as an implementation detail
     * for the `is_convertible_v` variable template within the µTest++
     * framework.
     *
     * If the conversion is valid, this overload is selected and returns
     * `true`.
     */
    template <class From, class To>
    constexpr auto
    is_convertible (int n) -> decltype (bool (To (declval<From> ())))
    {
      (void)n; // Prevent the unused parameter warning.
      return true;
    }

    /**
     * @brief Fallback function template for is_convertible, returns false if
     * the conversion is not valid.
     *
     * @tparam ...Unused Unused template parameters.
     *
     * @retval false indicating the conversion is not valid.
     *
     * @details
     * This overload is selected when the primary `is_convertible` template
     * cannot be instantiated, providing a `false` result for invalid
     * conversions.
     */
    template <class...>
    constexpr auto
    is_convertible (...)
    {
      return false;
    }

    /**
     * @brief Variable template to determine if one type is convertible to
     * another.
     *
     * @tparam From The source type to be checked for convertibility.
     * @tparam To The target type to which conversion is tested.
     *
     * @retval true if `From` is convertible to `To`.
     * @retval false otherwise.
     *
     * @details
     * The `is_convertible_v` variable template evaluates to `true` if the type
     * `From` is implicitly convertible to the type `To`, and `false`
     * otherwise. This trait is determined at compile time and is used
     * throughout the µTest++ framework to enable type-safe conversions and
     * requirements checking in template metaprogramming.
     */
    template <class From, class To>
    constexpr auto is_convertible_v = is_convertible<From, To> (0);
#endif

    /**
     * @brief Struct template for SFINAE requirements.
     *
     * @details
     * The `requires_` struct template is a utility for SFINAE (Substitution
     * Failure Is Not An Error) in template metaprogramming. It is typically
     * used to enable or disable template specialisations and function
     * templates based on compile-time boolean conditions.
     *
     * When the boolean template parameter is `true`, the specialisation
     * provides a nested `type` alias, which can be used in conjunction with
     * `typename` and `requires_t` to enforce requirements in template
     * declarations.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <bool Cond>
    struct requires_
    {
    };

    /**
     * @brief Specialisation of the requirements struct template for `true`.
     *
     * @details
     * When the condition is `true`, this specialisation provides a nested
     * `type` alias, typically used for SFINAE and requirements checking in
     * template metaprogramming.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <>
    struct requires_<true>
    {
      /**
       * @brief Alias type provided when the requirement is satisfied.
       */
      using type = int;
    };

    /**
     * @brief Alias template for extracting the `type` member from `requires_`.
     *
     * @tparam Cond The boolean condition to be checked at compile time.
     *
     * @details
     * The `requires_t` alias template simplifies the use of the `requires_`
     * struct template by directly exposing the nested `type` member. It is
     * commonly used to enforce compile-time requirements in template
     * declarations.
     */
    template <bool Cond>
    using requires_t = typename requires_<Cond>::type;

    /**
     * @brief Empty base struct for all operator types.
     *
     * @details
     * The `op` struct serves as a common base for all operator and value
     * wrapper types used in the µTest++ framework's type traits and
     * metaprogramming utilities. It provides a unified type hierarchy,
     * enabling compile-time detection and generic handling of operator-like
     * types within the framework.
     *
     * This struct is intended for internal use as a base for integral
     * constants, floating point constants, and other value wrappers,
     * supporting advanced template metaprogramming and type introspection.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    struct op
    {
    };

    /**
     * @brief Struct template representing a generic integral constant.
     *
     * @tparam N The compile-time constant value.
     *
     * @details
     * The `integral_constant` struct template provides a compile-time constant
     * value of an integral type, with additional utility features. It inherits
     * from `op` to enable unified handling within the µTest++ framework's type
     * traits and metaprogramming utilities.
     *
     * This struct template exposes the constant value via a static member, a
     * getter method, and explicit conversion operators. It also provides a
     * unary minus operator to obtain the negative value as a new
     * `integral_constant` instance.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <auto N>
    struct integral_constant : op
    {
      /**
       * @brief The type of the constant value.
       */
      using value_type = decltype (N);

      /**
       * @brief The constant value.
       */
      static constexpr auto value = N;

      /**
       * @brief Unary minus operator.
       *
       * @return An `integral_constant` with value `-N`.
       *
       * @details
       * Returns a new `integral_constant` instance representing the negative
       * of the current value.
       */
      [[nodiscard]] constexpr auto
      operator- () const
      {
        return integral_constant<-N>{};
      }

      /**
       * @brief Explicit conversion operator to value_type.
       *
       * @par Parameters
       *	 None.
       * @return The constant value as type `value_type`.
       *
       * @details
       * Allows explicit conversion to the underlying value type.
       */
      [[nodiscard]] constexpr explicit
      operator value_type (void) const
      {
        return N;
      }

      /**
       * @brief Getter for the constant value.
       *
       * @par Parameters
       *	 None.
       * @return The constant value.
       *
       * @details
       * Returns the compile-time constant value.
       */
      [[nodiscard]] constexpr auto
      get (void) const
      {
        return N;
      }
    };

    /**
     * @brief Struct template representing a generic floating point constant
     * with custom size and precision.
     *
     * @tparam T The floating point type (e.g., float, double).
     * @tparam N The integral part of the constant value.
     * @tparam D The fractional part of the constant value.
     * @tparam Size The number of decimal digits for the fractional part.
     * @tparam P The sign of the value (1 for positive, -1 for negative).
     * Defaults to 1.
     *
     * @details
     * The `floating_point_constant` struct template provides a compile-time
     * constant value of a floating point type, supporting custom size and
     * precision. It inherits from `op` to enable unified handling within the
     * µTest++ framework's type traits and metaprogramming utilities.
     *
     * This struct template exposes the constant value via a static member, a
     * getter method, and explicit conversion operators. It also provides a
     * unary minus operator to obtain the negative value as a new
     * `floating_point_constant` instance. The `epsilon` member defines the
     * precision used for floating point comparisons, calculated based on the
     * specified size.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T, auto N, auto D, auto Size, auto P = 1>
    struct floating_point_constant : op
    {
      /**
       * @brief The type of the constant value.
       */
      using value_type = T;

      /**
       * @brief The epsilon value used for floating point comparisons.
       *
       * @details
       * Calculated as 1 divided by 10 raised to the power of (Size - 1).
       */
      static constexpr auto epsilon = T (1) / math::pow (T (10), Size - 1);

      /**
       * @brief The constant value.
       *
       * @details
       * Computed as `P * (N + D / 10^Size)`.
       */
      static constexpr auto value
          = T (P) * (T (N) + (T (D) / math::pow (T (10), Size)));

      /**
       * @brief Unary minus operator.
       *
       * @return A `floating_point_constant` with value `-value`.
       *
       * @details
       * Returns a new `floating_point_constant` instance representing the
       * negative of the current value.
       */
      [[nodiscard]] constexpr auto
      operator- () const
      {
        return floating_point_constant<T, N, D, Size, -1>{};
      }

      /**
       * @brief Explicit conversion operator to value_type.
       *
       * @return The constant value as type `value_type`.
       *
       * @details
       * Allows explicit conversion to the underlying floating point value
       * type.
       */
      [[nodiscard]] constexpr explicit
      operator value_type () const
      {
        return value;
      }

      /**
       * @brief Getter for the constant value.
       *
       * @return The constant value.
       *
       * @details
       * Returns the compile-time floating point constant value.
       */
      [[nodiscard]] constexpr auto
      get () const
      {
        return value;
      }
    };

    /**
     * @brief Struct template representing a genuine integral value.
     *
     * @tparam T The type of the integral value.
     *
     * @details
     * The `genuine_integral_value` struct template encapsulates a runtime
     * integral value, providing a consistent interface for value access and
     * conversion. It inherits from `op` to enable unified handling within the
     * µTest++ framework's type traits and metaprogramming utilities.
     *
     * This struct template exposes the value via a member variable, a getter
     * method, and an explicit conversion operator. It is intended for use
     * cases where a value must be wrapped and treated generically within the
     * framework, supporting advanced template metaprogramming and type
     * introspection.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct genuine_integral_value : op
    {
      /**
       * @brief The type of the encapsulated value.
       */
      using value_type = T;

      /**
       * @brief Constructs a genuine_integral_value with the specified value.
       *
       * @param _value The integral value to be stored.
       */
      constexpr genuine_integral_value (const T& _value) : value_{ _value }
      {
      }

      /**
       * @brief Explicit conversion operator to the underlying value type.
       *
       * @return The stored value as type `T`.
       *
       * @details
       * Allows explicit conversion to the encapsulated value.
       */
      [[nodiscard]] constexpr explicit
      operator T () const
      {
        return value_;
      }

      /**
       * @brief Getter for the encapsulated value.
       *
       * @return The value of type `T`.
       *
       * @details
       * Returns the stored integral value.
       */
      [[nodiscard]] constexpr decltype (auto)
      get () const
      {
        return value_;
      }

      /**
       * @brief The encapsulated integral value.
       */
      T value_{};
    };

    /**
     * @brief Variable template to determine if a type derives from `op`.
     *
     * @tparam T The type to be checked for derivation from `op`.
     *
     * @retval true if `T` is derived from `type_traits::op`.
     * @retval false otherwise.
     *
     * @details
     * The `is_op_v` variable template evaluates to `true` if the given type
     * `T` is derived from the `type_traits::op` base struct, and `false`
     * otherwise. This trait is determined at compile time using compiler
     * intrinsics and is used throughout the µTest++ framework to enable
     * generic handling and detection of operator-like or value wrapper types
     * in template metaprogramming.
     */
    template <class T>
    inline constexpr auto is_op_v = __is_base_of (type_traits::op, T);

    /**
     * @brief Struct template representing a generic value, accessible via a
     * getter.
     *
     * @tparam T The type of the value to be encapsulated.
     * @tparam Opt An optional parameter for SFINAE or specialisation,
     * defaults to `int`.
     *
     * @details
     * The `value` struct template encapsulates a value of type `T`, providing
     * a consistent interface for value access and conversion. It inherits from
     * `type_traits::op` to enable unified handling within the µTest++
     * framework's type traits and metaprogramming utilities.
     *
     * This struct template exposes the value via a member variable, a getter
     * method, and an explicit conversion operator. It is intended for use
     * cases where a value must be wrapped and treated generically within the
     * framework, supporting advanced template metaprogramming and type
     * introspection.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T, class Opt = int>
    struct value : type_traits::op
    {
      /**
       * @brief The type of the encapsulated value.
       */
      using value_type = T;

      /**
       * @brief Constructs a value object with the specified value.
       *
       * @param _value The value to be stored.
       */
      constexpr value (const T& _value) : value_{ _value }
      {
      }

      /**
       * @brief Explicit conversion operator to the underlying value type.
       *
       * @return The stored value as type `T`.
       *
       * @details
       * Allows explicit conversion to the encapsulated value.
       */
      [[nodiscard]] constexpr explicit
      operator T () const
      {
        return value_;
      }

      /**
       * @brief Getter for the encapsulated value.
       *
       * @par Parameters
       *	 None.
       * @return The value of type `T`.
       *
       * @details
       * Returns the stored value.
       */
      [[nodiscard]] constexpr decltype (auto)
      get (void) const
      {
        return value_;
      }

      /**
       * @brief The encapsulated value.
       */
      T value_{};
    };

    /**
     * @brief Struct template representing a floating point value with
     * precision control.
     *
     * @tparam T The floating point type to be encapsulated.
     *
     * @details
     * The `value` struct template specialisation for floating point types
     * encapsulates a value of type `T` and provides an associated `epsilon`
     * for precision control during comparisons. It inherits from
     * `type_traits::op` to enable unified handling within the µTest++
     * framework's type traits and metaprogramming utilities.
     *
     * This struct template exposes the value via a member variable, a getter
     * method, and an explicit conversion operator. The `epsilon` member
     * defines the precision used for floating point comparisons and can be set
     * explicitly or computed as a default based on the number of decimal
     * digits in the value.
     *
     * This specialisation is intended for use cases where floating point
     * values require controlled precision, supporting advanced template
     * metaprogramming and type-safe comparisons within the framework.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct value<T,
                 type_traits::requires_t<type_traits::is_floating_point_v<T>>>
        : type_traits::op
    {
      /**
       * @brief The type of the encapsulated value.
       */
      using value_type = T;

      /**
       * @brief The epsilon value used for floating point comparisons.
       *
       * @details
       * This static inline member defines the precision for comparisons. It
       * can be set explicitly via the constructor or computed as a default
       * based on the number of decimal digits in the value.
       */
      static inline auto epsilon = T{}; // Why static?

      /**
       * @brief Constructs a floating point value with a specified precision.
       *
       * @param _value The floating point value to be stored.
       * @param precision The epsilon value to be used for comparisons.
       */
      constexpr value (const T& _value, const T precision) : value_{ _value }
      {
        epsilon = precision;
      }

      /**
       * @brief Constructs a floating point value with default precision.
       *
       * @param val The floating point value to be stored.
       *
       * @details
       * The epsilon is computed as 1 divided by 10 raised to the number of
       * decimal digits in the value.
       */
      constexpr /*explicit(false)*/ value (const T& val)
          : value{ val,
                   T (1)
                       / math::pow (T (10),
                                    math::den_size<unsigned long long> (val)) }
      {
      }

      /**
       * @brief Explicit conversion operator to the underlying value type.
       *
       * @return The stored value as type `T`.
       *
       * @details
       * Allows explicit conversion to the encapsulated floating point value.
       */
      [[nodiscard]] constexpr explicit
      operator T () const
      {
        return value_;
      }

      /**
       * @brief Getter for the encapsulated value.
       *
       * @par Parameters
       *	 None.
       * @return The value of type `T`.
       *
       * @details
       * Returns the stored floating point value.
       */
      [[nodiscard]] constexpr decltype (auto)
      get (void) const
      {
        return value_;
      }

      /**
       * @brief The encapsulated floating point value.
       */
      T value_{};
    };

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

#endif // MICRO_TEST_PLUS_TYPE_TRAITS_H_

// ----------------------------------------------------------------------------
