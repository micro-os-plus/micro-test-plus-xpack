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
 * @brief C++ header file with declarations for the deprecated µTest++
 * definitions.
 *
 * @details
 * This header groups the deprecated definitions that are not members of
 * the framework classes, kept for compatibility with the applications
 * written for the previous versions:
 * - the v5.0.1 names of the logical functions (`_not`, `_and`, and
 *   `_or`);
 * - the `mut()` helper, not used by the framework;
 * - the overloaded operators of the `operators` namespace, the
 *   user-defined literals of the `literals` namespace, the `to_*` type
 *   wrappers, `to_t<T>`, and `approx (value, epsilon)`, deprecated since
 *   6.0.0 in favour of the function comparators;
 * - the v5.0.1 names of the type wrappers (`_i`, `_u8`, etc.);
 * - the v5.0.1 names of the classes (`subtest`, `static_runner`,
 *   `detail::runner_totals`, and `detail::timestamps`);
 * - the `detail::timestamp` class;
 * - the `reflection::short_name()` function;
 * - the v5.0.1 `type_traits` namespace.
 *
 * The deprecated member functions and data members remain in the
 * declarations of their classes, since C++ does not allow them to be
 * declared elsewhere.
 *
 * All the deprecated definitions, in this header and in the classes, are
 * available only when `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED`
 * is defined; without it, the applications that still use them fail to
 * compile.
 *
 * Keeping the deprecated definitions separate makes them easy to
 * identify and, in a future major release, to remove.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "counters.h"
#include "extension.h"
#include "function-comparators.h"
#include "math.h"
#include "reflection.h"
#include "runner.h"
#include "stopwatch.h"
#include "test.h"

#include <array>
#include <concepts>
#include <cstdint>
#include <ctime>
#include <limits>
#include <string_view>
#include <type_traits>

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wc++20-compat"
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // The value wrappers and the parsing of the numeric literals, used only
  // by the deprecated literals and type wrappers, and the constants that
  // they define (moved here from `values.h` and `math.h`).

  namespace detail::math
  {
    /**
     * @brief Generic exponentiation function to compute the power of a base
     * raised to an exponent.
     *
     * @tparam T The type of the base value. Must support multiplication
     * assignment and construction from an integer.
     * @tparam Exp_T The type of the exponent. Must be default-constructible
     * (to zero), and support the `<` and prefix `++` operators.
     *
     * @param base The base value to be raised to the power of @p exp.
     * @param exp The exponent value.
     * @return The result of raising @p base to the power of @p exp.
     */
    template <class T, class Exp_T>
    [[nodiscard]] constexpr auto
    pow (const T base, const Exp_T exp) noexcept -> T;

    /**
     * @brief Counts the decimal digits of a floating-point literal, before
     * or after the decimal point.
     *
     * @details
     * The digit separators (`'`) are not counted.
     *
     * @tparam Fraction `true` to count the digits after the decimal point,
     * `false` to count those before it.
     * @tparam Cs The characters of the literal.
     *
     * @par Parameters
     *   None.
     * @return The number of digits.
     */
    template <bool Fraction, char... Cs>
    [[nodiscard]] consteval auto
    count_literal_digits (void) -> std::size_t;

    /**
     * @brief Computes the integral part of a decimal floating-point number
     * represented as an array of characters.
     *
     * @details
     * Used by the floating-point literal operators; the integer literals
     * use `integer_magnitude()`, which also accepts the C++ prefixes and
     * checks the range.
     *
     * @tparam T The target integral type for the result.
     * @tparam Cs The character pack representing the numeric value.
     *
     * @par Parameters
     *   None.
     * @return The parsed integral value of type `T`.
     */
    template <class T, char... Cs>
    [[nodiscard]] consteval auto
    num (void) -> T;

    /**
     * @brief Computes the decimal part of a number represented as an array
     * of characters.
     *
     * @tparam T The target integral type for the result.
     * @tparam Cs The character pack representing the numeric value; it must
     * contain a decimal point.
     *
     * @par Parameters
     *   None.
     * @return The digits after the decimal point, as an integral value of
     * type `T` (e.g. 25 for `1.25`), to be divided by ten raised to the
     * power returned by `den_size()`.
     */
    template <class T, char... Cs>
    [[nodiscard]] consteval auto
    den (void) -> T;

    /**
     * @brief Counts the decimal places of a number represented as an array
     * of characters.
     *
     * @tparam T The integral type for the result.
     * @tparam Cs The character pack representing the numeric value; it must
     * contain a decimal point.
     *
     * @par Parameters
     *   None.
     * @return The number of decimal places (e.g. 2 for `1.25`), as a value
     * of type `T`; it is the scale of the value returned by `den()`.
     */
    template <class T, char... Cs>
    [[nodiscard]] consteval auto
    den_size (void) -> T;

    /**
     * @brief Computes the number of decimal places of a value, with a
     * precision of about seven digits.
     *
     * @tparam T The integral type for the result.
     * @tparam Value_T The type of the input value, a floating-point type.
     *
     * @param value The value whose decimal precision is to be determined;
     * it may be negative, infinite, or a NaN.
     * @return The number of decimal places, as a value of type `T`, at
     * least one, or zero for a zero value; the leading zeros of a value
     * below one are counted; it is limited by the magnitude from which
     * `Value_T` represents only integers.
     */
    template <class T, class Value_T>
    [[nodiscard]] constexpr auto
    count_decimals (Value_T value) -> T;

    /**
     * @brief Computes the default comparison tolerance of a floating-point
     * value, one unit of its last decimal.
     *
     * @tparam Value_T The type of the value, a floating-point type.
     *
     * @param value The value whose tolerance is to be determined; it may
     * be negative, infinite, or a NaN.
     * @return Ten raised to minus the number of decimal places returned by
     * `count_decimals()` (0.01 for `1.25`, 1e-12 for `1e-12`), or zero, which
     * means an exact comparison, for a zero value and for a value whose
     * tolerance would be below the range of `Value_T`.
     */
    template <class Value_T>
    [[nodiscard]] constexpr auto
    decimal_epsilon (Value_T value) -> Value_T;

    /**
     * @brief The result of parsing the characters of an integer literal.
     *
     * @details
     * Returned by `parse_integer_literal()`; the checks of
     * `integer_magnitude()` are based on it.
     */
    struct integer_literal
    {
      /**
       * @brief The value of the literal.
       *
       * @details
       * Valid only if `is_integer` is true and `is_too_large` is false.
       */
      unsigned long long value;

      /**
       * @brief Whether the characters form an integer literal.
       *
       * @details
       * False for the floating-point literals (with a decimal point or an
       * exponent), which the literal operator templates also receive.
       */
      bool is_integer;

      /**
       * @brief Whether the value exceeds `unsigned long long`.
       *
       * @details
       * Detected while the digits are accumulated.
       */
      bool is_too_large;
    };

    /**
     * @brief Parses the characters of an integer literal.
     *
     * @tparam Cs The characters of the literal, as received by a literal
     * operator template.
     *
     * @par Parameters
     *   None.
     * @return The value, and whether the characters form an integer literal
     * and whether its value fits in `unsigned long long`.
     */
    template <char... Cs>
    [[nodiscard]] consteval auto
    parse_integer_literal (void) -> integer_literal;

    /**
     * @brief Computes the value of an integer literal of type @c T, before
     * any negation.
     *
     * @tparam T The integral type of the literal.
     * @tparam Cs The characters of the literal, as received by a literal
     * operator template.
     *
     * @par Parameters
     *   None.
     * @return The value of the literal, up to `max()` of `T`, or, for the
     * signed types, up to `max () + 1`, the absolute value of the minimum.
     */
    template <class T, char... Cs>
    [[nodiscard]] consteval auto
    integer_magnitude (void) -> unsigned long long;

    // ------------------------------------------------------------------------
  } // namespace detail::math

  namespace detail
  {
    // ------------------------------------------------------------------------

    /**
     * @brief Base struct template providing common storage and accessors
     * for run-time value-wrapper types.
     *
     * @tparam T The type of the stored value.
     *
     * @details
     * The `value_base` struct template stores the value in a private
     * member, and provides an explicit `operator T()` conversion and a
     * `get()` accessor, shared by `integral_constant`, `value<T>`, and the
     * floating-point specialisation of `value<T>`.
     *
     * It declares the `op_type` marker, so that all derived types satisfy
     * the `extension::is_op` concept without each struct needing to
     * declare it.
     *
     * It does not derive from the empty `op` struct: a type with an
     * empty base and only floating-point members, like `value<float>`,
     * is a homogeneous floating-point aggregate whose parameter passing
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
     * the run-time value storage, the explicit conversion operator, and the
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
     * @brief Struct template representing a generic floating-point constant
     * with custom size and precision.
     *
     * @tparam T The floating-point type (e.g., float, double).
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
     * constant value of a floating-point type, supporting custom size and
     * precision. It inherits from `op` directly rather than from
     * `value_base<T>`, since its value is the compile-time `value`
     * constant, and it needs no run-time storage; the struct is empty, and
     * the literal operators create it with `{}`, without a constructor.
     * Having no non-static floating-point members, it is not a
     * homogeneous floating-point aggregate, so the `-Wpsabi` note
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
       * @brief The epsilon value used for floating-point comparisons.
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
     * @brief Struct template representing a floating-point value with
     * precision control.
     *
     * @tparam T The floating-point type to be encapsulated.
     *
     * @details
     * The `value` struct template specialisation for floating-point types
     * encapsulates a value of type `T` and provides an associated `epsilon`
     * for precision control during comparisons. The stored value, explicit
     * conversion operator, and getter are provided by the `value_base` base.
     *
     * The `epsilon` member defines the precision used for floating-point
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
      // out-of-line in deprecated-inlines.h. Clang 16 has a deficiency where
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
       * @brief Constructs a floating-point value with default precision.
       *
       * @param val The floating-point value to be stored.
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
  // The logical functions, now `negate()`, `all_of()`, and `any_of()`, in
  // `function-comparators.h`.

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-logical-functions
   * @brief Deprecated generic logical **not** operation, the v5.0.1 name of
   * `negate()`.
   *
   * @details
   * The same as `negate()`. The name was changed since a leading
   * underscore is not used by the other current public names.
   *
   * @tparam Expr_T Type of the operand.
   *
   * @param expr Logical expression to be negated.
   * @return An object that evaluates to true if the operand is false.
   */
  template <class Expr_T>
  [[deprecated ("use negate() (since 6.0.0)"), nodiscard]] constexpr auto
  _not (Expr_T&& expr);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-logical-functions
   * @brief Deprecated generic logical **and** operation, the v5.0.1 name of
   * `all_of()`.
   *
   * @details
   * The same as `all_of()`. The name was changed since a leading
   * underscore is not used by the other current public names.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return An object that evaluates to true if both operand expressions are
   * true.
   */
  template <class Lhs_T, class Rhs_T>
  [[deprecated ("use all_of() (since 6.0.0)"), nodiscard]] constexpr auto
  _and (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-logical-functions
   * @brief Deprecated generic logical (inclusive) **or** operation, the v5.0.1
   * name of `any_of()`.
   *
   * @details
   * The same as `any_of()`. The name was changed since a leading
   * underscore is not used by the other current public names.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   *
   * @param lhs Left hand side operand.
   * @param rhs Right hand side operand.
   * @return An object that evaluates to true if at least one of the operand
   * expressions is true, including when both are.
   */
  template <class Lhs_T, class Rhs_T>
  [[deprecated ("use any_of() (since 6.0.0)"), nodiscard]] constexpr auto
  _or (Lhs_T&& lhs, Rhs_T&& rhs);

  // --------------------------------------------------------------------------
  // The `mut()` helper, not used by the framework.

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
   * @brief Deprecated generic mutator to remove const qualification from a
   * reference.
   *
   * @details
   * Not used by the framework. Equivalent to `const_cast<T&> (t)`, which
   * replaces it.
   *
   * @warning Modifying an object that was originally declared as `const`
   * through the returned reference is undefined behaviour.
   *
   * @tparam T The type of the input object.
   *
   * @param t The object from which to remove const qualification.
   * @return A non-const reference to the input object.
   */
  template <class T>
  [[deprecated ("use const_cast<T&> (since 6.0.0)"), nodiscard]] constexpr auto
  mut (const T& t) noexcept -> T&;

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::operators
   * @brief Deprecated comparison and logical operators of the test checks.
   *
   * @details
   * The `micro_os_plus::micro_test_plus::operators` namespace provides the
   * deprecated overloaded operators of the test checks.
   *
   * This namespace includes the equality, inequality, relational, and
   * logical operators of the framework types, which apply to the
   * strongly-typed constants (the user-defined literals) and to the
   * dynamic values (the wrappers).
   *
   * @warning Please be aware that these operators
   * may conflict with other operators defined within the application under
   * test.
   *
   * To minimise conflicts with application-defined operators, these
   * overloads are enabled only when an operand is a framework expression
   * or value wrapper (see `extension::is_op`). Constants typically
   * require a literal suffix (e.g.,
   * `1_i`), while dynamic values should be wrapped using the provided
   * casting utilities (e.g., `mt::to_i{...}`). When neither operand is of
   * such a type, the standard operators are selected; they return a plain
   * `bool`, so a failed check cannot show the operands.
   *
   * The operands are forwarded, as by the function comparators: the
   * temporaries are moved into the returned expression, and the named
   * operands of class type, including the nested expressions, are
   * referred to, without copies.
   *
   * There are no operators for strings and containers: the standard
   * operators would be selected for `std::string` objects and for
   * containers of the same type, and the framework operators for
   * `std::string_view` objects would also replace the standard ones in the
   * application code that follows the using directive. Use `mt::eq()` and
   * `mt::ne()` to compare strings and containers.
   *
   * All definitions within this namespace are implemented in the
   * `include/micro-os-plus/micro-test-plus` folder, ensuring a modular and
   * maintainable codebase.
   *
   * @par Deprecated
   * Use the function comparators `eq()`, `ne()`, `gt()`, `ge()`, `lt()`,
   * and `le()`, with the plain values, and `all_of()`, `any_of()`, and
   * `negate()` for the logical combinations (since 6.0.0). The function
   * comparators accept the same operands, compare them and report them in
   * the same way, and do not need the literal suffixes or the type
   * wrappers.
   *
   * @since 3.2.0
   */
  namespace operators
  {
    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated equality operator. Matches only if at least one
     * operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the operands are
     * equal.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use eq() (since 6.0.0)"), nodiscard]] constexpr auto
    operator== (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated non-equality operator. Matches only if at least one
     * operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the operands are
     * not equal.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use ne() (since 6.0.0)"), nodiscard]] constexpr auto
    operator!= (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated greater than operator. Matches only if at least one
     * operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is greater than the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use gt() (since 6.0.0)"), nodiscard]] constexpr auto
    operator> (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated greater than or equal operator. Matches only if at
     * least one operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is greater than or equal to the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use ge() (since 6.0.0)"), nodiscard]] constexpr auto
    operator>= (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated less than operator. Matches only if at least one
     * operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is less than the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use lt() (since 6.0.0)"), nodiscard]] constexpr auto
    operator< (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated less than or equal operator. Matches only if at least
     * one operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is less than or equal to the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use le() (since 6.0.0)"), nodiscard]] constexpr auto
    operator<= (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated logical `&&` (and) operator. Matches only if at least
     * one operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A logical conjunction object that evaluates to true if both
     * operands are true.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use all_of() (since 6.0.0)"), nodiscard]] constexpr auto
    operator and (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated logical `||` (or) operator. Matches only if at least
     * one operand is a framework type (see `extension::is_op`).
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     *
     * @param lhs Left hand side operand.
     * @param rhs Right hand side operand.
     * @return A logical disjunction object that evaluates to true if at least
     * one operand is true.
     */
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<std::remove_cvref_t<Lhs_T>,
                                 std::remove_cvref_t<Rhs_T>>
    [[deprecated ("use any_of() (since 6.0.0)"), nodiscard]] constexpr auto
    operator or (Lhs_T&& lhs, Rhs_T&& rhs);

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-operators
     * @brief Deprecated logical `!` (not) operator. Matches only if the
     * operand is a framework type (see `extension::is_op`).
     *
     * @tparam T Type of the operand, constrained to the framework types.
     *
     * @param t Operand to be logically negated.
     * @return A logical negator object that evaluates to true if the operand
     * is false.
     */
    template <class T>
      requires extension::is_op<std::remove_cvref_t<T>>
    [[deprecated ("use negate() (since 6.0.0)"), nodiscard]] constexpr auto
    operator not(T&& t);

    // ------------------------------------------------------------------------
  } // namespace operators

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::literals
   * @brief Deprecated user-defined literals of the test checks.
   *
   * @details
   * The `literals` namespace provides the deprecated user-defined literal
   * operators, which set the type of the operands of the µTest++
   * comparators and operators.
   *
   * These operators allow constants to be suffixed (for example, `1_i`,
   * `2_u16`) to produce strongly-typed values, which the comparator
   * functions and the operators display in the test reports.
   *
   * The complementary wrappers for converting dynamic values and
   * expressions to recognised types (such as `to_i`, `to_u8`) are defined
   * in the parent `micro_os_plus::micro_test_plus` namespace.
   *
   * @par Deprecated
   * Pass the plain values to the function comparators `eq()`, `ne()`,
   * `gt()`, `ge()`, `lt()`, and `le()`, and use `approx()` for the
   * floating-point values compared with a tolerance (since 6.0.0). The
   * function comparators report the operands in the same way, and do not
   * need the literal suffixes.
   *
   * @since 3.2.0
   */
  namespace literals
  {
    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `int`.
     *
     * @tparam Cs The character pack representing the digits of the integer
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_i ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `short`.
     *
     * @tparam Cs The character pack representing the digits of the integer
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `short` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_s ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `char`.
     *
     * @tparam Cs The character pack representing the digits of the character
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `char` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_c ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `signed
     * char`.
     *
     * @tparam Cs The character pack representing the digits of the signed
     * character constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `signed char` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_sc ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `long`.
     *
     * @tparam Cs The character pack representing the digits of the long
     * integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `long` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_l ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `long
     * long`.
     *
     * @tparam Cs The character pack representing the digits of the long long
     * integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `long long` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_ll ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to
     * `unsigned`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_u ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `unsigned
     * char`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * character constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned char` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_uc ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `unsigned
     * short`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * short constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned short` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_us ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `unsigned
     * long`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * long integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned long` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_ul ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `unsigned
     * long long`.
     *
     * @tparam Cs The character pack representing the digits of the unsigned
     * long long integer constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `unsigned long long` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_ull ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `int8_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int8_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int8_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_i8 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `int16_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int16_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int16_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_i16 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `int32_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int32_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int32_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_i32 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `int64_t`.
     *
     * @tparam Cs The character pack representing the digits of the `int64_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `int64_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_i64 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `uint8_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint8_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `uint8_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_u8 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to
     * `uint16_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint16_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `uint16_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_u16 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to
     * `uint32_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint32_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `uint32_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_u32 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to
     * `uint64_t`.
     *
     * @tparam Cs The character pack representing the digits of the `uint64_t`
     * constant.
     *
     * @return A `detail::integral_constant` instance holding the parsed
     * `uint64_t` value.
     */
    template <char... Cs>
    [[deprecated (
          "pass plain values to eq() and the other comparators (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_u64 ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `float`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `detail::floating_point_constant` instance holding the
     * parsed `float` value.
     */
    template <char... Cs>
    [[deprecated ("use approx() for tolerances (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_f ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `double`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `detail::floating_point_constant` instance holding the
     * parsed `double` value.
     */
    template <char... Cs>
    [[deprecated ("use approx() for tolerances (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_d ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to convert to `long
     * double`.
     *
     * @tparam Cs The character pack representing the digits of the
     * floating-point constant.
     *
     * @return A `detail::floating_point_constant` instance holding the
     * parsed `long double` value.
     */
    template <char... Cs>
    [[deprecated ("use approx() for tolerances (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_ld ();

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
     * @brief Deprecated user-defined literal operator to create a named
     * boolean constant.
     *
     * @param name Pointer to the character sequence representing the literal.
     * @param size The size of the character sequence.
     * @return A `detail::named_bool` instance, with the value `true`,
     * reported by its name.
     */
    [[deprecated ("use a plain bool and a check message (since 6.0.0)"),
      nodiscard]] constexpr auto
    operator""_b (const char* name, decltype (sizeof ("")) size);

    // ------------------------------------------------------------------------
  } // namespace literals

  // --------------------------------------------------------------------------

  /**
   * @addtogroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
   * @{
   */

  /**
   * @name Type Wrappers
   * @brief Strongly-typed wrappers for converting dynamic values and
   * expressions to specific types recognised by µTest++ comparators.
   *
   * @details
   * These type aliases provide a type-safe mechanism for explicitly
   * converting values to the required types for µTest++ test expressions and
   * comparators. Each alias is a wrapper around `detail::value<T>`,
   * ensuring that the value is treated as the specified type within the
   * framework.
   *
   * The `to_*` forms replaced the older `_i`, `_u8`, etc. aliases, which
   * were deprecated in version 3.2.0.
   *
   * @par Deprecated
   * Pass the plain values to the function comparators `eq()`, `ne()`,
   * `gt()`, `ge()`, `lt()`, and `le()` instead; they report the operands
   * in the same way. For the floating-point values compared with a
   * tolerance, use `approx()` (since 6.0.0).
   *
   * @par Example
   *
   * @code
   * int x = 42;
   * // Explicitly treat x as an int for test comparison.
   * auto wrapped = to_i{x};
   * @endcode
   *
   * @since 3.2.0
   *
   * @{
   */

  /**
   * @brief Deprecated strongly-typed wrapper for `bool` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `bool`.
   *
   * @since 3.2.0
   */
  using to_b [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<bool>;

  /**
   * @brief Deprecated strongly-typed wrapper for `char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `char`.
   *
   * @since 3.2.0
   */
  using to_c [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<char>;

  /**
   * @brief Deprecated strongly-typed wrapper for `signed char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `signed char`.
   *
   * @since 3.2.0
   */
  using to_sc [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<signed char>;

  /**
   * @brief Deprecated strongly-typed wrapper for `short` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `short`.
   *
   * @since 3.2.0
   */
  using to_s [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<short>;

  /**
   * @brief Deprecated strongly-typed wrapper for `int` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `int`.
   *
   * @since 3.2.0
   */
  using to_i [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<int>;

  /**
   * @brief Deprecated strongly-typed wrapper for `long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long`.
   *
   * @since 3.2.0
   */
  using to_l [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<long>;

  /**
   * @brief Deprecated strongly-typed wrapper for `long long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long long`.
   *
   * @since 3.2.0
   */
  using to_ll [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<long long>;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned`.
   *
   * @since 3.2.0
   */
  using to_u [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<unsigned>;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned char` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned char`.
   *
   * @since 3.2.0
   */
  using to_uc [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<unsigned char>;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned short` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned short`.
   *
   * @since 3.2.0
   */
  using to_us [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<unsigned short>;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned long`.
   *
   * @since 3.2.0
   */
  using to_ul [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<unsigned long>;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned long long` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `unsigned long long`.
   *
   * @since 3.2.0
   */
  using to_ull [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<unsigned long long>;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::int8_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int8_t`.
   *
   * @since 3.2.0
   */
  using to_i8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<std::int8_t>;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::int16_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int16_t`.
   *
   * @since 3.2.0
   */
  using to_i16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<std::int16_t>;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::int32_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int32_t`.
   *
   * @since 3.2.0
   */
  using to_i32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<std::int32_t>;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::int64_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::int64_t`.
   *
   * @since 3.2.0
   */
  using to_i64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<std::int64_t>;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::uint8_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint8_t`.
   *
   * @since 3.2.0
   */
  using to_u8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<std::uint8_t>;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::uint16_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint16_t`.
   *
   * @since 3.2.0
   */
  using to_u16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<std::uint16_t>;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::uint32_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint32_t`.
   *
   * @since 3.2.0
   */
  using to_u32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<std::uint32_t>;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::uint64_t` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `std::uint64_t`.
   *
   * @since 3.2.0
   */
  using to_u64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = detail::value<std::uint64_t>;

  /**
   * @brief Deprecated strongly-typed wrapper for `float` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `float`.
   *
   * @since 3.2.0
   */
  using to_f [[deprecated ("use approx() for tolerances (since 6.0.0)")]]
  = detail::value<float>;

  /**
   * @brief Deprecated strongly-typed wrapper for `double` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `double`.
   *
   * @since 3.2.0
   */
  using to_d [[deprecated ("use approx() for tolerances (since 6.0.0)")]]
  = detail::value<double>;

  /**
   * @brief Deprecated strongly-typed wrapper for `long double` values.
   *
   * @details
   * Wraps a run-time value, so that the comparators and the reporter
   * treat it as `long double`.
   *
   * @since 3.2.0
   */
  using to_ld [[deprecated ("use approx() for tolerances (since 6.0.0)")]]
  = detail::value<long double>;

  /**
   * @}
   */

  /**
   * @}
   */

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
   * @brief Deprecated generic strongly-typed wrapper for explicit type
   * conversion.
   *
   * @since 3.2.0
   *
   * @details
   * The `to_t` template provides a public, strongly-typed wrapper for any type
   * `T`, enabling explicit conversion of dynamic values and expressions to a
   * type recognised by the µTest++ comparators and reporting mechanisms.
   *
   * This wrapper inherits from `detail::value<T>`, ensuring that the
   * encapsulated value is treated as the specified type within the framework,
   * for the types without a `to_*` alias, including the application types;
   * with the operators of the `operators` namespace, the comparisons are
   * then reported with their operands.
   *
   * @par Example
   *
   * @code
   * MyType obj;
   * // Explicitly treat obj as MyType for test comparison.
   * auto wrapped = to_t<MyType>{obj};
   * @endcode
   *
   * @par Deprecated
   * Pass the plain value to the function comparators `eq()`, `ne()`,
   * `gt()`, `ge()`, `lt()`, and `le()` instead; the application types
   * are reported with the `operator<<` of `expression_formatter`
   * (since 6.0.0).
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  template <class T>
  struct [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  to_t : detail::value<T>
  {
    /**
     * @brief Constructor for the strongly-typed wrapper.
     *
     * @param t The value to be wrapped and explicitly converted.
     */
    constexpr explicit to_t (const T& t);
  };

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
   * @brief Deprecated wrapping of a floating-point value with an explicit
   * comparison tolerance.
   *
   * @details
   * The floating-point literals (`1.5_d`) and wrappers (`to_d{ 1.5 }`)
   * compare with a tolerance derived from the number of decimals written
   * (0.1 for `1.5`). `approx()` makes the tolerance explicit, independent
   * of how the value is written. All six comparisons apply it: values
   * whose difference is less than the tolerance are equal, and neither
   * less nor greater. If both operands have a tolerance, the smaller one
   * is used.
   *
   * @code{.cpp}
   * t.expect (mt::eq (compute_float (), mt::approx (42.0f, 0.001f)));
   * @endcode
   *
   * For a single comparison, also of integers, the
   * `approx (lhs, rhs, epsilon)` function comparator may be used instead.
   *
   * @tparam T The floating-point type of the value.
   *
   * @param value The expected value.
   * @param epsilon The tolerance, converted to `T`.
   * @return A `detail::value<T>` wrapper, recognised by the
   * comparators and the operators.
   *
   * @par Deprecated
   * Use the function comparator `approx (lhs, rhs, epsilon)` instead
   * (since 6.0.0).
   *
   * @since 6.0.0
   */
  template <class T>
    requires std::is_floating_point_v<T>
  [[deprecated ("use approx (lhs, rhs, epsilon) (since 6.0.0)"),
    nodiscard]] constexpr auto
  approx (T value, std::type_identity_t<T> epsilon) noexcept
      -> detail::value<T>;

#if defined(__GNUC__)
#pragma GCC diagnostic push
// The aliases refer to the `to_*` names, deprecated too.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)

  /**
   * @addtogroup micro-os-plus-micro-test-plus-cpp-api-deprecated-literals
   * @{
   */

  /**
   * @name Deprecated Type Wrappers
   * @brief The v5.0.1 names of the `to_*` type wrappers.
   *
   * @details
   * The Boost UT style names, with a leading underscore, kept for
   * compatibility with the existing applications. Each one is an alias
   * of the corresponding `to_*` wrapper, so the wrapped values are
   * compared and reported in the same way. They do not conflict with
   * the literal operators with the same suffixes (`42_i`), which are
   * in the `literals` namespace.
   *
   * GCC reports the deprecation only when the alias names the type of a
   * declaration, not when it is used in an expression, as in
   * `_i (expr)`; Clang reports it in both cases.
   *
   * @par Deprecated
   * Pass the plain values to the function comparators `eq()`, `ne()`,
   * `gt()`, `ge()`, `lt()`, and `le()` instead; the `to_*` type wrappers
   * that replaced these aliases (since 3.2.0) are deprecated too (since
   * 6.0.0).
   *
   * @{
   */

  /**
   * @brief Deprecated strongly-typed wrapper for `bool` values, the v5.0.1
   * name of `to_b`.
   *
   * @details
   * The same type as `to_b`; kept for backwards compatibility.
   */
  using _b [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_b;

  /**
   * @brief Deprecated strongly-typed wrapper for `char` values, the v5.0.1
   * name of `to_c`.
   *
   * @details
   * The same type as `to_c`; kept for backwards compatibility.
   */
  using _c [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_c;

  /**
   * @brief Deprecated strongly-typed wrapper for `signed char` values, the
   * v5.0.1 name of `to_sc`.
   *
   * @details
   * The same type as `to_sc`; kept for backwards compatibility.
   */
  using _sc [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_sc;

  /**
   * @brief Deprecated strongly-typed wrapper for `short` values, the v5.0.1
   * name of `to_s`.
   *
   * @details
   * The same type as `to_s`; kept for backwards compatibility.
   */
  using _s [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_s;

  /**
   * @brief Deprecated strongly-typed wrapper for `int` values, the v5.0.1 name
   * of `to_i`.
   *
   * @details
   * The same type as `to_i`; kept for backwards compatibility.
   */
  using _i [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_i;

  /**
   * @brief Deprecated strongly-typed wrapper for `long` values, the v5.0.1
   * name of `to_l`.
   *
   * @details
   * The same type as `to_l`; kept for backwards compatibility.
   */
  using _l [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_l;

  /**
   * @brief Deprecated strongly-typed wrapper for `long long` values, the
   * v5.0.1 name of `to_ll`.
   *
   * @details
   * The same type as `to_ll`; kept for backwards compatibility.
   */
  using _ll [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_ll;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned` values, the v5.0.1
   * name of `to_u`.
   *
   * @details
   * The same type as `to_u`; kept for backwards compatibility.
   */
  using _u [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_u;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned char` values, the
   * v5.0.1 name of `to_uc`.
   *
   * @details
   * The same type as `to_uc`; kept for backwards compatibility.
   */
  using _uc [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_uc;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned short` values, the
   * v5.0.1 name of `to_us`.
   *
   * @details
   * The same type as `to_us`; kept for backwards compatibility.
   */
  using _us [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_us;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned long` values, the
   * v5.0.1 name of `to_ul`.
   *
   * @details
   * The same type as `to_ul`; kept for backwards compatibility.
   */
  using _ul [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_ul;

  /**
   * @brief Deprecated strongly-typed wrapper for `unsigned long long` values,
   * the v5.0.1 name of `to_ull`.
   *
   * @details
   * The same type as `to_ull`; kept for backwards compatibility.
   */
  using _ull [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_ull;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::int8_t` values, the
   * v5.0.1 name of `to_i8`.
   *
   * @details
   * The same type as `to_i8`; kept for backwards compatibility.
   */
  using _i8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_i8;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::int16_t` values, the
   * v5.0.1 name of `to_i16`.
   *
   * @details
   * The same type as `to_i16`; kept for backwards compatibility.
   */
  using _i16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_i16;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::int32_t` values, the
   * v5.0.1 name of `to_i32`.
   *
   * @details
   * The same type as `to_i32`; kept for backwards compatibility.
   */
  using _i32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_i32;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::int64_t` values, the
   * v5.0.1 name of `to_i64`.
   *
   * @details
   * The same type as `to_i64`; kept for backwards compatibility.
   */
  using _i64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_i64;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::uint8_t` values, the
   * v5.0.1 name of `to_u8`.
   *
   * @details
   * The same type as `to_u8`; kept for backwards compatibility.
   */
  using _u8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_u8;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::uint16_t` values, the
   * v5.0.1 name of `to_u16`.
   *
   * @details
   * The same type as `to_u16`; kept for backwards compatibility.
   */
  using _u16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_u16;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::uint32_t` values, the
   * v5.0.1 name of `to_u32`.
   *
   * @details
   * The same type as `to_u32`; kept for backwards compatibility.
   */
  using _u32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_u32;

  /**
   * @brief Deprecated strongly-typed wrapper for `std::uint64_t` values, the
   * v5.0.1 name of `to_u64`.
   *
   * @details
   * The same type as `to_u64`; kept for backwards compatibility.
   */
  using _u64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_u64;

  /**
   * @brief Deprecated strongly-typed wrapper for `float` values, the v5.0.1
   * name of `to_f`.
   *
   * @details
   * The same type as `to_f`; kept for backwards compatibility.
   */
  using _f [[deprecated ("use approx() for tolerances (since 6.0.0)")]] = to_f;

  /**
   * @brief Deprecated strongly-typed wrapper for `double` values, the v5.0.1
   * name of `to_d`.
   *
   * @details
   * The same type as `to_d`; kept for backwards compatibility.
   */
  using _d [[deprecated ("use approx() for tolerances (since 6.0.0)")]] = to_d;

  /**
   * @brief Deprecated strongly-typed wrapper for `long double` values, the
   * v5.0.1 name of `to_ld`.
   *
   * @details
   * The same type as `to_ld`; kept for backwards compatibility.
   */
  using _ld [[deprecated ("use approx() for tolerances (since 6.0.0)")]]
  = to_ld;

  /**
   * @brief Deprecated generic strongly-typed wrapper, the v5.0.1 name of
   * `to_t`.
   *
   * @details
   * The same type as `to_t<T>`, so it takes the same argument and is
   * reported in the same way; kept for backwards compatibility. In
   * v5.0.1 it was a separate class, also derived from
   * `detail::value<T>`.
   *
   * @tparam T The type of the wrapped value.
   */
  template <class T>
  using _t [[deprecated (
      "pass plain values to eq() and the other comparators (since 6.0.0)")]]
  = to_t<T>;

  /**
   * @}
   */

  /**
   * @}
   */

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

  // ==========================================================================
  // The test case class, now `test_case`, in `test.h`.

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
   * @brief Deprecated name of `test_case`.
   *
   * @details
   * The v5.0.1 name of the class passed to the test case bodies, kept
   * for the functions and the lambdas that name it as the type of their
   * first parameter (`void f (mt::subtest& t)`); the lambdas with an
   * `auto&` parameter are not affected.
   */
  using subtest [[deprecated ("use test_case (since 6.0.0)")]] = test_case;

  // ==========================================================================
  // The runner class, now `runner`, in `runner.h`.

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
   * @brief Deprecated name of `runner`.
   *
   * @details
   * The `runner` also runs the `static_suite` objects that refer to it,
   * so a separate runner class is no longer needed.
   */
  using static_runner [[deprecated ("use runner (since 6.0.0)")]] = runner;

  // --------------------------------------------------------------------------

  namespace reflection
  {
    // ------------------------------------------------------------------------
    // Now `utility::extract_file_name()`, in `utility.h`.

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated extraction of the file name from a path.
     *
     * @details
     * Forwards to `utility::extract_file_name()`, which the framework
     * uses internally; it is kept only for compatibility with the
     * existing applications.
     *
     * @param name The path, as a C-string.
     * @return A pointer to the file name within the input string, after
     * the last `/` or backslash separator, or the string itself if there is
     * no separator.
     */
    [[deprecated ("use utility::extract_file_name() (since 6.0.0)"),
      nodiscard]] const char*
    short_name (const char* name) noexcept;

    // ------------------------------------------------------------------------
  } // namespace reflection

  // --------------------------------------------------------------------------

  namespace detail
  {
    // ========================================================================
    // The counters class, now `counters`, in `counters.h`.

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated name of `counters`.
     *
     * @details
     * The v5.0.1 name of the class returned by `totals()`, renamed since
     * the suites and the test cases own one too, not only the runner.
     */
    using runner_totals [[deprecated ("use counters (since 6.0.0)")]]
    = counters;

    // ========================================================================
    // The timings classes, now `stopwatch`, in `stopwatch.h`.

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated name of `stopwatch`.
     *
     * @details
     * The v5.0.1 name of the class returned by the `timings()` functions
     * of the runner and of the suites, which kept the two timestamps of
     * the measured interval. Its public members are kept, on `stopwatch`;
     * its protected members, the two optional `timestamp` objects, are
     * not. The timings are internal; the elapsed times are shown by the
     * reporters.
     */
    using timestamps [[deprecated ("the timings are internal (since 6.0.0)")]]
    = stopwatch;

    // ========================================================================

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated clock reading.
     *
     * @details
     * The v5.0.1 class of the two readings kept by `detail::timestamps`,
     * restored for the applications that used it directly; the framework
     * no longer uses it, since `stopwatch` keeps the readings as
     * `timespec` members. The timings are internal; use `stopwatch`
     * instead.
     *
     * A zero `timespec` means that the clock was not read, or that the
     * platform has no clock.
     *
     * The data member is `protected`, as in v5.0.1, so that the existing
     * derived classes can still access it.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class [[deprecated ("the timings are internal (since 6.0.0)")]] timestamp
    {
    public:
      /**
       * @brief Constructs a timestamp with the current time.
       *
       * @details
       * Reads the system clock, as `stopwatch::start()` does; without a
       * clock, the value remains zero.
       */
      timestamp (void) noexcept;

      /**
       * @brief Constructs a timestamp with a given time.
       *
       * @details
       * Not `explicit`, as in v5.0.1, so that a `timespec` converts
       * implicitly.
       *
       * @param ts The time to be stored.
       */
      timestamp (const timespec& ts) noexcept;

      /**
       * @brief Defaulted copy constructor.
       *
       * @details
       * A timestamp is a plain value, so it may be copied.
       */
      timestamp (const timestamp&) = default;

      /**
       * @brief Defaulted move constructor.
       *
       * @details
       * Equivalent to the copy, since the value is trivially copyable.
       */
      timestamp (timestamp&&) = default;

      /**
       * @brief Defaulted copy assignment operator.
       *
       * @details
       * A timestamp is a plain value, so it may be assigned.
       *
       * @return A reference to the current object.
       */
      timestamp&
      operator= (const timestamp&)
          = default;

      /**
       * @brief Defaulted move assignment operator.
       *
       * @details
       * Equivalent to the copy assignment, since the value is trivially
       * copyable.
       *
       * @return A reference to the current object.
       */
      timestamp&
      operator= (timestamp&&)
          = default;

      /**
       * @brief Defaulted destructor.
       *
       * @details
       * No resources are owned, so there is nothing to release.
       */
      ~timestamp () = default;

      /**
       * @brief Checks whether the value is a clock reading.
       *
       * @details
       * The value is not a reading if both its members are zero.
       *
       * @par Parameters
       *   None.
       * @retval true  At least one of the members is not zero.
       * @retval false Both members are zero.
       */
      [[nodiscard]] bool
      has_clock (void) const noexcept;

      /**
       * @brief Gets the stored time, for modification.
       *
       * @par Parameters
       *   None.
       * @return A reference to the stored `timespec`.
       */
      [[nodiscard]] timespec&
      value (void) noexcept;

      /**
       * @brief Gets the stored time.
       *
       * @par Parameters
       *   None.
       * @return A constant reference to the stored `timespec`.
       */
      [[nodiscard]] const timespec&
      value (void) const noexcept;

    protected:
      /**
       * @brief The stored time.
       *
       * @details
       * Set by the constructors; zero if the clock was not read.
       */
      timespec value_{};
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
  // The concepts, now in the `extension` namespace, in `extension.h`.
  // Kept last, since the pragma below applies to the rest of the file.

  /**
   * @namespace micro_os_plus::micro_test_plus::type_traits
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
   * @brief Deprecated v5.0.1 namespace of the concepts and of the value
   * wrapper templates.
   *
   * @details
   * In v5.0.1, the concepts, the base of the expressions, and the value
   * wrapper templates were outside `detail`, in the `type_traits`
   * namespace. The namespace is kept for compatibility with the existing
   * applications: the names that still exist refer to their current
   * definitions, in the `extension` and `detail` namespaces, and the
   * removed helpers are restored here.
   *
   * The concepts refer to the current ones, so their semantics are the
   * current ones: `is_op` detects the `op_type` member, not the
   * inheritance from `op`; `has_epsilon` also requires `is_op`;
   * `checkable` also accepts the types with an `explicit operator bool`;
   * `printable` accepts everything the formatter can print. The
   * exceptions are `has_value` and `has_npos`, which are not used by the
   * framework any more, and are restored with their v5.0.1 definitions.
   *
   * The concepts cannot be deprecated individually, so the attribute is
   * on the namespace. Clang reports the deprecation at every qualified
   * use. GCC reports it only for the names declared in the namespace
   * itself (the restored helpers and the alias templates), and, for the
   * alias templates, only when they name the type of a declaration; it
   * does not report the concepts, nor the names introduced by the
   * using-declarations.
   *
   * Use the concepts in the `extension` namespace, and
   * `extension::compare_op` or `extension::predicate_op` for the
   * application expressions; the value wrapper templates are internal.
   */

  // --------------------------------------------------------------------------

#if defined(__GNUC__)
  // GCC reports the partial specialisations of `function_traits` below,
  // since they name the deprecated namespace.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)

  // --------------------------------------------------------------------------

  namespace
      [[deprecated ("use the extension namespace (since 6.0.0)")]] type_traits
  {
    // ------------------------------------------------------------------------
    // Concepts, now in the `extension` and `detail` namespaces.

    using extension::any_op;
    using extension::checkable;
    using extension::has_epsilon;
    using extension::is_op;
    using extension::printable;

    using detail::container_like;

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated concept satisfied when `T` provides a
     * `npos` member.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * Restored with its v5.0.1 definition, satisfied by any type with a
     * member named `npos`. It is not used by the framework any more,
     * which detects the strings with `detail::string_like`, so that the
     * containers with a member named `npos` are compared element by
     * element.
     *
     * @deprecated There is no replacement; the concept used by the
     * framework is internal (since 6.0.0).
     */
    template <class T>
    concept has_npos = requires { T::npos; };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated concept satisfied when `T` has a member
     * named `value`.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * Restored with its v5.0.1 definition, satisfied by any type with a
     * member named `value`, static or not, including the application
     * types, so that the v5.0.1 code that uses it keeps its result. It
     * is not the concept used by the framework, `detail::has_value`,
     * which is satisfied only by the framework types, so that the
     * application types with a `value` member are compared as values.
     *
     * @deprecated There is no replacement; the concept used by the
     * framework is internal (since 6.0.0).
     */
    template <class T>
    concept has_value = requires (const T& t) { t.value; };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated concept satisfied when `T` is a
     * floating-point type.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The v5.0.1 name of `std::floating_point`, which the framework now
     * uses directly.
     *
     * @deprecated Use `std::floating_point` (since 6.0.0).
     */
    template <class T>
    concept is_floating_point = std::floating_point<T>;

    // ------------------------------------------------------------------------
    // Helpers removed from the framework, restored as in v5.0.1.

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated empty type list.
     *
     * @tparam Types The types in the list.
     *
     * @details
     * Used only as the type of `function_traits<>::args`; the framework no
     * longer uses it.
     *
     * @deprecated Not replaced (since 6.0.0).
     */
    template <class... Types>
    struct list
    {
    };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated identity type.
     *
     * @tparam T The type to be exposed.
     * @tparam Extra Additional types, ignored.
     *
     * @details
     * Exposes `T` as the member type `type`, like `std::type_identity`,
     * which replaces it.
     *
     * @deprecated Use `std::type_identity` (since 6.0.0).
     */
    template <class T, class... Extra>
    struct identity
    {
      /**
       * @brief The type `T`.
       *
       * @details
       * The additional template arguments do not affect it.
       */
      using type = T;
    };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated traits of the callable objects.
     *
     * @tparam T The type of the callable object; its `operator()` is
     * inspected.
     *
     * @details
     * The primary template applies to the lambdas and to the function
     * objects, and forwards to the specialisation for the type of their
     * `operator()`. The specialisations expose the return type as
     * `result_type`, and the parameter types as `args`, a `list`.
     *
     * @deprecated Not replaced (since 6.0.0).
     */
    template <class T>
    struct function_traits
#if !defined(__DOXYGEN__)
        // Hidden from Doxygen, which reports a recursive class relation.
        // https://github.com/doxygen/doxygen/issues/9915
        : function_traits<decltype (&T::operator())>
#endif // !defined(__DOXYGEN__)
    {
    };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated traits of the function pointers.
     *
     * @tparam R The return type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a pointer to a
     * free function.
     *
     * @deprecated Not replaced (since 6.0.0).
     */
    template <class R, class... Args_T>
    struct function_traits<R (*) (Args_T...)>
    {
      /**
       * @brief The return type.
       *
       * @details
       * The type `R` of the specialisation.
       */
      using result_type = R;

      /**
       * @brief The parameter types, as a `list`.
       *
       * @details
       * The types `Args_T` of the specialisation, without the object
       * parameter of the member functions.
       */
      using args = list<Args_T...>;
    };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated traits of the function types.
     *
     * @tparam R The return type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a function type.
     *
     * @deprecated Not replaced (since 6.0.0).
     */
    template <class R, class... Args_T>
    struct function_traits<R (Args_T...)>
    {
      /**
       * @brief The return type.
       *
       * @details
       * The type `R` of the specialisation.
       */
      using result_type = R;

      /**
       * @brief The parameter types, as a `list`.
       *
       * @details
       * The types `Args_T` of the specialisation, without the object
       * parameter of the member functions.
       */
      using args = list<Args_T...>;
    };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated traits of the pointers to member functions.
     *
     * @tparam R The return type.
     * @tparam T The class type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a pointer to a
     * non-`const` member function.
     *
     * @deprecated Not replaced (since 6.0.0).
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...)>
    {
      /**
       * @brief The return type.
       *
       * @details
       * The type `R` of the specialisation.
       */
      using result_type = R;

      /**
       * @brief The parameter types, as a `list`.
       *
       * @details
       * The types `Args_T` of the specialisation, without the object
       * parameter of the member functions.
       */
      using args = list<Args_T...>;
    };

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated traits of the pointers to `const` member
     * functions.
     *
     * @tparam R The return type.
     * @tparam T The class type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a pointer to a
     * `const` member function, like the `operator()` of a lambda.
     *
     * @deprecated Not replaced (since 6.0.0).
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...) const>
    {
      /**
       * @brief The return type.
       *
       * @details
       * The type `R` of the specialisation.
       */
      using result_type = R;

      /**
       * @brief The parameter types, as a `list`.
       *
       * @details
       * The types `Args_T` of the specialisation, without the object
       * parameter of the member functions.
       */
      using args = list<Args_T...>;
    };

    // ------------------------------------------------------------------------
    // The base of the expressions and the value wrappers, now in `detail`.

    using detail::floating_point_constant;
    using detail::integral_constant;
    using detail::op;
    using detail::value;

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated name of `detail::value_base`.
     *
     * @tparam T The type of the stored value.
     *
     * @details
     * The v5.0.1 name, with a trailing underscore. The stored value is now
     * private, and `get()` returns a reference; the value is read with
     * `get()` or with the explicit conversion, not through the v5.0.1
     * public member `value_`.
     *
     * @deprecated The value wrappers are internal (since 6.0.0).
     */
    template <class T>
    using value_base_ = detail::value_base<T>;

    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated integral value wrapper.
     *
     * @tparam T The integral type of the stored value.
     *
     * @details
     * In v5.0.1, a separate wrapper with the same members as `value<T>`,
     * never created by the framework; now `value<T>`, so the values are
     * compared and reported in the same way.
     *
     * @deprecated The value wrappers are internal (since 6.0.0).
     */
    template <class T>
    using genuine_integral_value = detail::value<T>;

    // ------------------------------------------------------------------------
  } // namespace type_traits

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/deprecated-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_H_

// ----------------------------------------------------------------------------
