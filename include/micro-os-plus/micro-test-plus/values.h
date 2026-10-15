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
 * created by the literals, and the run-time `genuine_integral_value` and
 * `value<T>` types, the latter named by the `to_*` and `_*` aliases.
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
    // ========================================================================

    /**
     * @brief Empty base struct for all framework expression types.
     *
     * @details
     * The `op` struct is the common base of the value wrappers defined in
     * this header and of the comparators defined in `detail.h`. It
     * provides a unified type hierarchy, which the `type_traits::is_op`
     * and `type_traits::any_op` concepts use to distinguish the framework
     * types from the user types, so that `expect()`, `require()`, and the
     * operators in the `operators` namespace accept them.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct op
    {
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
     * `get()` accessor, shared by `integral_constant`,
     * `genuine_integral_value`, `value<T>`, and the floating point
     * specialisation of `value<T>`.
     *
     * It inherits from `op` so that all derived types satisfy the
     * `type_traits::is_op` concept without each struct needing to inherit
     * from `op` directly.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct value_base : op
    {
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
       * Value-initialised by default. Derived wrappers and comparators
       * access it via `get()` or the explicit conversion operator.
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
     * from `value_base<decltype(N)>`, which supplies the `value_type` alias,
     * the runtime value storage, the explicit conversion operator, and the
     * `get()` accessor.
     *
     * This struct retains the compile-time `value` constant and provides a
     * unary minus operator to obtain the negative value as a new
     * `integral_constant` instance.
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
     * @tparam D The fractional part of the constant value, scaled as
     * returned by `math::den()` (e.g. 250 for `1.25`).
     * @tparam Size The scale of `D`, as returned by `math::den_size()`,
     * i.e. the number of decimal digits plus one (e.g. 3 for `1.25`).
     * @tparam P The sign of the value (1 for positive, -1 for negative).
     * Defaults to 1.
     *
     * @details
     * The `floating_point_constant` struct template provides a compile-time
     * constant value of a floating point type, supporting custom size and
     * precision. It inherits from `op` directly rather than from
     * `value_base<T>`, which avoids introducing a user-provided constructor
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
       * Calculated as 1 divided by 10 raised to the power of (Size - 1),
       * i.e. one unit of the last decimal digit of the literal.
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
     * @brief Struct template representing a genuine integral value.
     *
     * @tparam T The type of the integral value.
     *
     * @details
     * The `genuine_integral_value` struct template encapsulates a runtime
     * integral value. The stored value, explicit conversion operator, and
     * getter are provided by the `value_base` base.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct genuine_integral_value : value_base<T>
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
     * comparisons and can be set explicitly or computed as a default based
     * on the number of decimal digits in the value.
     *
     * This specialisation is intended for use cases where floating point
     * values require controlled precision, supporting advanced template
     * metaprogramming and type-safe comparisons within the framework.
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
