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

#include <string_view>
#include <type_traits>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

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
   * This includes templates for function traits, type lists, identity, value
   * wrappers, and compile-time checks for container types, floating point
   * types, and type convertibility. It also provides generic integral and
   * floating point constant wrappers, as well as C++20 concepts and
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

    // ------------------------------------------------------------------------

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
     * @brief C++20 concept satisfied when `T` is a standard floating point
     * type.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `is_floating_point` concept is satisfied when `T` is one of the
     * standard floating point types (`float`, `double`, or `long double`).
     * It is the primary definition; `is_floating_point_v` is derived from
     * it for use in `if constexpr` and non-concept contexts.
     */
    template <class T>
    concept is_floating_point = std::is_floating_point_v<T>;

    /**
     * @brief C++20 concept satisfied when a type derives from `op`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `is_op` concept is satisfied when `T` is derived from the
     * `type_traits::op` base struct. It is the primary definition used
     * throughout the framework; `is_op_v` is derived from it for use in
     * `if constexpr` and boolean contexts.
     */
    template <class T>
    concept is_op = std::is_base_of_v<type_traits::op, T>;

    /**
     * @brief C++20 concept satisfied when at least one of two types derives
     * from `op`.
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @details
     * The `any_op` concept is satisfied when `Lhs_T` or `Rhs_T` (or both)
     * are derived from the `type_traits::op` base struct. It is used to
     * constrain binary operator overloads in the `operators` namespace so
     * that they are enabled only when at least one operand is a framework
     * type, avoiding unintended conflicts with user-defined operators.
     */
    template <class Lhs_T, class Rhs_T>
    concept any_op = is_op<Lhs_T> or is_op<Rhs_T>;

    /**
     * @brief C++20 concept satisfied when a type can be used as a test
     * expression in `expect()` or `assume()`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The `checkable` concept is satisfied when `T` is either a
     * framework operator type (derived from `op`) or is implicitly
     * convertible to `bool`. It is used to constrain the `expect()` and
     * `assume()` function templates, ensuring that only sensible
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
     * type or is implicitly convertible to `std::string_view`. It
     * constrains the `operator<<` overload of `deferred_reporter_base`,
     * ensuring that only types that can be meaningfully appended to the
     * output message are accepted.
     */
    template <class T>
    concept printable = std::is_arithmetic_v<T>
                        or std::is_convertible_v<T, std::string_view>;

    // ------------------------------------------------------------------------

    /**
     * @brief Base struct template providing common storage and accessors
     * for runtime value-wrapper types.
     *
     * @tparam T The type of the stored value.
     *
     * @details
     * The `value_base_` struct template provides the `T value_{}` member,
     * an explicit `operator T()` conversion, and a `get()` accessor,
     * shared by `genuine_integral_value`, `value<T>`, and the floating
     * point specialisation `value<T>`.
     *
     * It inherits from `op` so that all derived types satisfy the `is_op`
     * concept without each struct needing to inherit from `op` directly.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct value_base_ : op
    {
      /**
       * @brief The type of the stored value.
       */
      using value_type = T;

      /**
       * @brief Constructs a `value_base_` with the given value.
       *
       * @param v The value to be stored.
       */
      constexpr explicit value_base_ (const T& v) noexcept;

      /**
       * @brief Explicit conversion operator to the underlying value type.
       *
       * @return The stored value as type `T`.
       */
      [[nodiscard]] constexpr explicit
      operator T () const noexcept;

      /**
       * @brief Getter for the stored value.
       *
       * @par Parameters
       *	 None.
       * @return The stored value.
       */
      [[nodiscard]] constexpr T
      get (void) const noexcept;

      /**
       * @brief The stored value.
       */
      T value_{};
    };

    /**
     * @brief Struct template representing a generic integral constant.
     *
     * @tparam N The compile-time constant value.
     *
     * @details
     * The `integral_constant` struct template provides a compile-time constant
     * value of an integral type, with additional utility features. It inherits
     * from `value_base_<decltype(N)>`, which supplies the `value_type` alias,
     * the `value_` runtime member, the explicit conversion operator, and the
     * `get()` accessor.
     *
     * This struct retains the compile-time `value` constant and provides a
     * unary minus operator to obtain the negative value as a new
     * `integral_constant` instance.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <auto N>
    struct integral_constant : value_base_<decltype (N)>
    {
      /**
       * @brief The compile-time constant value.
       */
      static constexpr auto value = N;

      /**
       * @brief Default constructor. Initialises the base with `N`.
       */
      constexpr integral_constant () noexcept;

      /**
       * @brief Unary minus operator.
       *
       * @return An `integral_constant` with value `-N`.
       */
      [[nodiscard]] constexpr auto
      operator- () const noexcept;
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
     * precision. It inherits from `op` directly rather than from
     * `value_base_<T>`, which avoids introducing a user-provided constructor
     * into the type and keeps it trivially default-constructible. This
     * prevents the GCC ARM PSABI note about parameter-passing ABI changes
     * that is emitted for non-trivially-constructible types under C++17.
     *
     * The `value_type` alias, explicit conversion operator, and `get()`
     * accessor are provided directly by this struct. The compile-time
     * `epsilon` and `value` static constants are retained, and a unary
     * minus operator is provided to obtain the negative value as a new
     * `floating_point_constant` instance.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T, auto N, auto D, auto Size, auto P = 1>
    struct floating_point_constant : op
    {
      static_assert (P == 1 || P == -1,
                     "floating_point_constant: P must be +1 or -1");

      /**
       * @brief The type of the stored value.
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
       * @brief The compile-time constant value.
       *
       * @details
       * Computed as `P * (N + D / 10^Size)`.
       */
      static constexpr auto value
          = T (P) * (T (N) + (T (D) / math::pow (T (10), Size)));

      /**
       * @brief Explicit conversion operator to the underlying value type.
       *
       * @return The compile-time constant as type `T`.
       */
      [[nodiscard]] constexpr explicit
      operator T () const noexcept;

      /**
       * @brief Getter for the compile-time constant value.
       *
       * @par Parameters
       *	 None.
       * @return The compile-time constant as type `T`.
       */
      [[nodiscard]] constexpr T
      get (void) const noexcept;

      /**
       * @brief Unary minus operator.
       *
       * @return A `floating_point_constant` with negated sign parameter.
       */
      [[nodiscard]] constexpr auto
      operator- () const noexcept;
    };

    /**
     * @brief Struct template representing a genuine integral value.
     *
     * @tparam T The type of the integral value.
     *
     * @details
     * The `genuine_integral_value` struct template encapsulates a runtime
     * integral value. The stored value, explicit conversion operator, and
     * getter are provided by the `value_base_` base.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct genuine_integral_value : value_base_<T>
    {
      /**
       * @brief Constructs a genuine_integral_value with the specified value.
       *
       * @param _value The integral value to be stored.
       */
      constexpr genuine_integral_value (const T& _value) noexcept;
    };

    /**
     * @brief Struct template representing a generic value, accessible via a
     * getter.
     *
     * @tparam T The type of the value to be encapsulated.
     *
     * @details
     * The `value` struct template encapsulates a value of type `T`. The
     * stored value, explicit conversion operator, and getter are provided
     * by the `value_base_` base.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct value : value_base_<T>
    {
      /**
       * @brief Constructs a value object with the specified value.
       *
       * @param _value The value to be stored.
       * 
       * @details
       * Delegates to `value_base_<T>{ _value }` to initialise the base.
       */
      constexpr value (const T& _value) noexcept;
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
     * for precision control during comparisons. The stored value, explicit
     * conversion operator, and getter are provided by the `value_base_` base.
     *
     * The `epsilon` member defines the precision used for floating point
     * comparisons and can be set explicitly or computed as a default based
     * on the number of decimal digits in the value.
     *
     * This specialisation is intended for use cases where floating point
     * values require controlled precision, supporting advanced template
     * metaprogramming and type-safe comparisons within the framework.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
      requires is_floating_point<T>
    struct value<T> : value_base_<T>
    {
      /**
       * @brief The epsilon value used for floating-point comparisons.
       *
       * @details
       * This instance member defines the precision for comparisons. It
       * is set via the constructor, either explicitly or computed as a
       * default based on the number of decimal digits in the value.
       * Each instance carries its own epsilon, so two `value<T>` objects
       * with different precisions do not interfere with each other.
       */
      T epsilon = T{};

      // Note: These constructor bodies are defined inline rather than
      // out-of-line in type-traits-inlines.h. Clang 16 has a deficiency
      // where it fails to match out-of-line constructor definitions to a
      // `requires`-constrained partial specialisation: it either rejects
      // the `requires` clause on the definition as differing from the
      // declaration, or — when the clause is omitted — incorrectly matches
      // the definition against the primary template instead of this
      // specialisation. Keeping the bodies here avoids both failure modes.

      /**
       * @brief Constructs a floating-point value with a specified precision.
       *
       * @param _value The floating-point value to be stored.
       * @param precision The epsilon value to be used for comparisons.
       *
       * @details
       * Delegates to `value_base_<T>{ _value }` and stores the supplied
       * precision in `epsilon`.
       */
      constexpr value (const T& _value, const T precision) noexcept
          : value_base_<T>{ _value }, epsilon{ precision }
      {
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
      constexpr value (const T& val)
          : value{ val,
                   T (1)
                       / math::pow (T (10),
                                    math::den_size<unsigned long long> (val)) }
      {
      }
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

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/type-traits-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TYPE_TRAITS_H_

// ----------------------------------------------------------------------------
