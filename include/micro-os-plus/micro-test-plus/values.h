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
 * @brief C++ header file with declarations for the µTest++ value wrappers.
 *
 * @details
 * This header provides the declarations for the value wrapper types used
 * within the µTest++ framework: the `op` base struct, shared by all the
 * framework expression types, the `value_base` common base, the
 * compile-time `integral_constant` and `floating_point_constant` types,
 * created by the literals, the run-time `value<T>` type, named by the
 * `to_*` and `_*` aliases, and the `named_bool` type, created by the `_b`
 * literal.
 *
 * The wrappers carry the operands of the comparisons, so that the
 * comparators can apply the type-specific rules (for example the
 * precision of the floating point values) and the reporters can print
 * the actual values.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::detail`
 * namespace, since users name these types only through the literals and
 * the aliases, never directly.
 *
 * All header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_VALUES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_VALUES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "math.h"

#include <concepts>
#include <limits>
#include <string_view>
#include <type_traits>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
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
     * @brief Base struct template providing common storage and accessors
     * for runtime value-wrapper types.
     *
     * @tparam T The type of the stored value.
     *
     * @details
     * The `value_base` struct template stores the value in a private
     * member, and provides an explicit `operator T()` conversion and a
     * `get()` accessor, shared by `integral_constant`, `value<T>`, and the
     * floating point specialisation of `value<T>`.
     *
     * It declares the `op_type` marker, so that all derived types satisfy
     * the `extension::is_op` concept without each struct needing to
     * declare it.
     *
     * It does not derive from the empty `op` struct: a type with an
     * empty base and only floating point members, like `value<float>`,
     * is a homogeneous floating point aggregate whose parameter passing
     * with C++17 and later changed in GCC 10.1, and GCC emits a
     * `-Wpsabi` note for each function passing or returning it by value,
     * like `approx()`, on AArch64 and on 32-bit Arm with the hard-float
     * ABI.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct value_base
    {
      /**
       * @brief Marker identifying the framework expression types.
       *
       * @details
       * Declared directly rather than inherited from `op`, to avoid the
       * empty base; detected by the `extension::is_op` concept.
       */
      using op_type = op;

      /**
       * @brief The type of the stored value.
       *
       * @details
       * Exposed for use by generic code that inspects wrapper types.
       */
      using value_type = T;

      /**
       * @brief Constructs a `value_base` with the given value.
       *
       * @param v The value to be stored.
       */
      constexpr explicit value_base (const T& v) noexcept;

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
       * @details
       * Returns a reference, so that a wrapped object (for example a
       * `to_t<std::string>`) is not copied each time it is compared or
       * formatted.
       *
       * @par Parameters
       *   None.
       * @return A reference to the stored value.
       */
      [[nodiscard]] constexpr const T&
      get (void) const noexcept;

    private:
      /**
       * @brief The stored value.
       *
       * @details
       * Set by the constructor. Derived wrappers and comparators access
       * it via `get()` or the explicit conversion operator.
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
     * value of an integral type, created by the integer literals. It inherits
     * from `value_base<decltype(N)>`, which supplies the `value_type` alias,
     * the runtime value storage, the explicit conversion operator, and the
     * `get()` accessor.
     *
     * This struct retains the compile-time `value` constant and provides a
     * unary minus operator to obtain the negative value as a new
     * `integral_constant` instance, of the same type.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <auto N>
    struct integral_constant : value_base<decltype (N)>
    {
      /**
       * @brief The compile-time constant value.
       *
       * @details
       * Equal to `N`; also available at run time via `get()`.
       */
      static constexpr auto value = N;

      /**
       * @brief Default constructor. Initialises the base with `N`.
       */
      constexpr integral_constant (void) noexcept;

      /**
       * @brief Unary minus operator.
       *
       * @details
       * The result has the type of `N`, not the type promoted by the
       * built-in unary minus, so `-1_i8` is an `int8_t`. The negation of an
       * unsigned value wraps around, as for `unsigned int` in C++ (`-1_u8`
       * is 255). The negation of the minimum of a signed type does not fit
       * in the type, so it is a compilation error.
       *
       * @return An `integral_constant` with value `-N`, converted to the
       * type of `N`.
       */
      [[nodiscard]] constexpr auto
      operator- () const noexcept;
    };

    /**
     * @brief Struct template representing the absolute value of the
     * minimum of a signed integral type, as written in a literal.
     *
     * @tparam T The signed integral type of the literal.
     *
     * @details
     * The absolute value of the minimum of a signed type (e.g. 128 for
     * `int8_t`) does not fit in the type, but the literal must be accepted
     * to write the minimum with the unary minus (e.g. `-128_i8`). The
     * literal operators return this type for such a literal; its only
     * operation is the unary minus, so any other use of the literal fails
     * to compile.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct integral_min_magnitude
    {
      /**
       * @brief Unary minus operator.
       *
       * @details
       * The only operation of the type, the one that makes the literal
       * valid.
       *
       * @return An `integral_constant` with the minimum value of `T`.
       */
      [[nodiscard]] constexpr auto
      operator- () const noexcept;
    };

    /**
     * @brief Creates the compile-time constant of an integer literal.
     *
     * @tparam T The integral type of the literal.
     * @tparam Cs The characters of the literal, as received by a literal
     * operator template.
     *
     * @details
     * Used by the integer literal operators (`_i`, `_u8`, etc.).
     *
     * @par Parameters
     *   None.
     * @return An `integral_constant` with the value of the literal, or,
     * when the value is the absolute value of the minimum of a signed `T`,
     * an `integral_min_magnitude<T>`, valid only when negated.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    integral_literal (void);

    /**
     * @brief Struct template representing a generic floating point constant
     * with custom size and precision.
     *
     * @tparam T The floating point type (e.g., float, double).
     * @tparam N The integral part of the constant value.
     * @tparam D The digits of the fractional part of the constant value,
     * as returned by `math::den()` (e.g. 25 for `1.25`).
     * @tparam Size The number of decimal digits, the scale of `D`, as
     * returned by `math::den_size()` (e.g. 2 for `1.25`).
     * @tparam P The sign of the value (1 for positive, -1 for negative).
     * Defaults to 1.
     *
     * @details
     * The `floating_point_constant` struct template provides a compile-time
     * constant value of a floating point type, supporting custom size and
     * precision. It inherits from `op` directly rather than from
     * `value_base<T>`, since its value is the compile-time `value`
     * constant, and it needs no run-time storage; the struct is empty, and
     * the literal operators create it with `{}`, without a constructor.
     * Having no non-static floating point members, it is not a
     * homogeneous floating point aggregate, so the `-Wpsabi` note
     * described for `value_base` does not apply to it, despite its empty
     * base. On 32-bit Arm, GCC emits another note, about a change in GCC
     * 7.1, for each function passing a `double` or `long double` constant
     * by value, since the earlier versions computed its alignment from its
     * static `double` members; the framework does not pass the constants
     * by value.
     *
     * The `value_type` alias, explicit conversion operator, and `get()`
     * accessor are provided directly by this struct. The compile-time
     * `epsilon` and `value` static constants are retained, and a unary
     * minus operator is provided to obtain the negative value as a new
     * `floating_point_constant` instance.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T, auto N, auto D, auto Size, auto P = 1>
    struct floating_point_constant : op
    {
      static_assert (P == 1 || P == -1,
                     "floating_point_constant: P must be +1 or -1");

      /**
       * @brief The type of the stored value.
       *
       * @details
       * Provided directly, since this struct does not derive from
       * `value_base`.
       */
      using value_type = T;

      /**
       * @brief The epsilon value used for floating point comparisons.
       *
       * @details
       * Calculated as 1 divided by 10 raised to the power of `Size`, i.e.
       * one unit of the last decimal digit of the literal.
       */
      static constexpr auto epsilon = T (1) / math::pow (T (10), Size);

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
       *   None.
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
     * @brief Struct template representing a generic value, accessible via a
     * getter.
     *
     * @tparam T The type of the value to be encapsulated.
     *
     * @details
     * The `value` struct template encapsulates a value of type `T`. The
     * stored value, explicit conversion operator, and getter are provided
     * by the `value_base` base.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct value : value_base<T>
    {
      /**
       * @brief Constructs a value object with the specified value.
       *
       * @param _value The value to be stored.
       *
       * @details
       * Delegates to `value_base<T>{ _value }` to initialise the base.
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
     * conversion operator, and getter are provided by the `value_base` base.
     *
     * The `epsilon` member defines the precision used for floating point
     * comparisons and can be set explicitly (by `approx()`) or computed as
     * a default based on the number of decimal digits in the value (by
     * the `to_f`, `to_d`, and `to_ld` wrappers).
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
      requires std::floating_point<T>
    struct value<T> : value_base<T>
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
      // out-of-line in values-inlines.h. Clang 16 has a deficiency where
      // it fails to match out-of-line constructor definitions to a
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
       * Delegates to `value_base<T>{ _value }` and stores the supplied
       * precision in `epsilon`.
       */
      constexpr value (const T& _value, const T precision) noexcept
          : value_base<T>{ _value }, epsilon{ precision }
      {
      }

      /**
       * @brief Constructs a floating point value with default precision.
       *
       * @param val The floating point value to be stored.
       *
       * @details
       * The epsilon is computed by `math::decimal_epsilon()` as 1 divided
       * by 10 raised to the number of decimal digits in the value, with
       * the leading zeros of a value below one counted (1e-12 for
       * `1e-12`); a zero value gets a zero epsilon, so that it is compared
       * exactly.
       */
      constexpr value (const T& val)
          : value{ val, math::decimal_epsilon (val) }
      {
      }
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Struct representing a named boolean constant, created by the
     * `_b` literal.
     *
     * @details
     * The `named_bool` struct holds the constant `true`, together with a
     * name, which the expression formatter prints instead of the value, so
     * that a failed comparison like `"flag"_b == flag`, with the operators
     * in the `operators` namespace, is reported as `flag == false`.
     *
     * The value is available only via the implicit conversion to `bool`,
     * and the struct has neither a `get()` accessor nor comparison
     * operators. Thus `detail::unwrap()` returns the object itself, so that
     * the formatter receives the name, the comparators compare it as the
     * `bool` value `true`, and the generic operators in the `operators`
     * namespace, not a better matching operator of this struct, are
     * selected for it.
     *
     * The name is not owned; it refers to the string literal, which has
     * static storage duration.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct named_bool : op
    {
      /**
       * @brief The type of the value.
       *
       * @details
       * The named literal behaves as a boolean value.
       */
      using value_type = bool;

      /**
       * @brief Constructs a named boolean constant with the given name.
       *
       * @param name The name, printed in place of the value.
       */
      constexpr explicit named_bool (std::string_view name) noexcept;

      /**
       * @brief Conversion operator to `bool`.
       *
       * @par Parameters
       *   None.
       * @return `true`.
       */
      [[nodiscard]] constexpr
      operator value_type () const noexcept;

      /**
       * @brief Returns the name of the constant.
       *
       * @par Parameters
       *   None.
       * @return The name passed to the constructor.
       */
      [[nodiscard]] constexpr std::string_view
      name (void) const noexcept;

    private:
      /**
       * @brief The name of the constant.
       *
       * @details
       * Not owned; refers to the characters of the string literal.
       */
      std::string_view name_;
    };

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

#include "inlines/values-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_VALUES_H_

// ----------------------------------------------------------------------------
