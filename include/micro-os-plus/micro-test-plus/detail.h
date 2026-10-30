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
 * @brief C++ header file with declarations for the µTest++ internals.
 *
 * @details
 * This header provides the declarations for the internal components of the
 * µTest++ framework, encapsulated within the
 * `micro_os_plus::micro_test_plus::detail` namespace. It defines the core
 * mechanisms, helper structures, and utility templates that underpin the
 * framework's value retrieval, comparator logic, operand preparation, and
 * exception checking facilities.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::detail`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_DETAIL_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "extension.h"

#include <algorithm>
#include <compare>
#include <cstddef>
#include <cstdio>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>

// ----------------------------------------------------------------------------

/**
 * @def MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
 * @brief Portable `printf()` conversion for the `size_t` values.
 *
 * @details
 * Clang's format checker on Windows (the "ms_printf" archetype) rejects the
 * standard `z` modifier, even though the UCRT `printf()` implementation
 * supports it at run time, so the Microsoft-specific `I` modifier is used
 * there instead (`"Iu"`); elsewhere it is `"zu"`.
 *
 * It is used in all the library formats that print `size_t` values, in
 * the reporter output and in the trace messages alike, concatenated with
 * the adjacent string literals, as the standard `PRIu32` macros are
 * (for example `"%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE " checks"`).
 *
 * The templates in the inline headers use it too; their string literals
 * are concatenated when they are parsed, not when they are instantiated,
 * so the macro is undefined at the end of `micro-test-plus.h`, after all
 * the headers, to keep it out of the application code. The library
 * sources include the individual headers, which keep it defined.
 */
#if defined(_WIN32) && defined(__clang__) && !defined(__MINGW32__)
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "Iu"
#else
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "zu"
#endif // defined(_WIN32) && defined(__clang__) && !defined(__MINGW32__)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wdocumentation"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  /**
   * @namespace micro_os_plus::micro_test_plus::detail
   * @brief Internal implementation details for the µTest++ framework.
   *
   * @details
   * The `detail` namespace encapsulates the internal mechanisms, helper
   * structures, and implementation utilities employed by the µTest++ testing
   * framework. These components do not form part of the public API and may be
   * modified without prior notice.
   *
   * Within this namespace, one will find the value wrappers (declared in
   * `values.h`), the value unwrapping helper, comparator structures for
   * logical and relational operations, mechanisms for exception checking,
   * the reporters, the check result, and the expression formatter.
   *
   * All definitions within `detail` are intended exclusively for internal use,
   * ensuring a clear distinction between user-facing and internal components.
   * This approach enhances maintainability, mitigates the risk of naming
   * conflicts, and keeps the public API succinct.
   *
   * The relevant header files are organised within the
   * `include/micro-os-plus/micro-test-plus` folder to maintain a structured
   * and modular codebase.
   */
  namespace detail
  {
    // ========================================================================

    /**
     * @brief Returns the value wrapped by a framework type, or the operand
     * itself.
     *
     * @details
     * Always call it qualified, as `detail::unwrap()`, so that
     * argument-dependent lookup cannot select a function of the
     * application, defined in the namespace of an operand.
     *
     * The operand is returned by reference, without a copy; the result
     * is valid only as long as the operand.
     *
     * @tparam T The type of the operand.
     *
     * @param t The operand.
     * @return The value returned by `t.get()` for the framework wrappers
     * (the literals and the `to_*` wrappers), otherwise a reference to
     * `t`.
     */
    template <class T>
    // The specifier order works around a Doxygen (1.17, 1.18) mismatch
    // with the definition, reported as "no matching file member found".
    [[nodiscard]] decltype (auto) constexpr unwrap (const T& t);

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
     * @brief Deprecated check whether two operands are equal within the
     * tolerance of the floating-point wrappers.
     *
     * @details
     * Used by `compare_op` for all six tags, so that a value within the
     * tolerance is equal, and neither less nor greater; at least one
     * operand must have an `epsilon` member (a floating-point literal, a
     * `to_f`, `to_d`, or `to_ld` wrapper, or `approx()`).
     *
     * Used only by the deprecated floating-point wrappers, it is available
     * only when `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED` is defined.
     *
     * @deprecated To be removed with the deprecated floating-point
     * wrappers (since 6.0.0).
     *
     * @tparam Lhs_T The type of the left-hand operand.
     * @tparam Rhs_T The type of the right-hand operand.
     *
     * @param lhs The left-hand operand.
     * @param rhs The right-hand operand.
     * @retval true The absolute difference is less than the tolerance (the
     * smaller one, if both operands have one).
     * @retval false Otherwise.
     */
    template <class Lhs_T, class Rhs_T>
      requires (extension::has_epsilon<Lhs_T> or extension::has_epsilon<Rhs_T>)
    [[nodiscard]] constexpr bool
    within_tolerance (const Lhs_T& lhs, const Rhs_T& rhs);
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    // ========================================================================

    /**
     * @brief The type with which an expression stores an operand.
     *
     * @details
     * Applied by the deduction guides and the factory functions to the
     * type deduced for a forwarding reference: `X&` (or `const X&`) for
     * an lvalue, `X` for an rvalue.
     *
     * An lvalue of class type is stored as a `const` reference, so that
     * comparing two named containers does not copy them, and a nested
     * expression stores a reference to its operand expressions. An
     * rvalue is moved into the expression, so that an expression that
     * outlives the statement, like `auto op = eq (f (), 1);`, does not
     * refer to a destroyed temporary. The scalars are always stored by
     * value, since a copy is as cheap as a reference.
     *
     * A reference remains valid only as long as the named operand; this
     * is always the case within the statement that checks the
     * expression.
     *
     * @tparam T The type deduced for a forwarding reference.
     */
    template <class T>
    using stored_operand_t = std::conditional_t<
        std::is_lvalue_reference_v<T>
            and not std::is_scalar_v<std::remove_cvref_t<T>>,
        const std::remove_reference_t<T>&, std::remove_cvref_t<T>>;

    // ========================================================================

    /**
     * @brief Common base struct template for unary comparators.
     *
     * @details
     * This base struct stores a single operand and the pre-computed boolean
     * result of a unary operation. Derived structs such as `not_op` inherit
     * from this to provide logical negation. The result is computed at
     * construction time, enabling consistent handling and reporting of
     * operations throughout the assertion framework.
     *
     * @tparam T The type of the stored operand, either the operand type,
     * or a `const` reference to it (see `stored_operand_t`).
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct unary_op : op
    {
      /**
       * @brief Constructs a unary comparator with the given operand and
       * pre-computed result.
       *
       * @details
       * The operand is forwarded to the member, so that an rvalue is
       * moved, not copied.
       *
       * @tparam U The type of the operand argument.
       *
       * @param t The operand.
       * @param value The pre-computed boolean result of the operation.
       */
      template <class U>
      constexpr unary_op (U&& t, bool value);

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *   None.
       * @return The result of the operation.
       */
      [[nodiscard]] constexpr
      operator bool () const;

      /**
       * @brief Retrieves the wrapped operand expression.
       *
       * @details
       * The operand is unwrapped with `detail::unwrap()` and returned by
       * reference, so that formatting it does not copy it.
       *
       * @par Parameters
       *   None.
       * @return The extracted operand value.
       */
      [[nodiscard]] constexpr decltype (auto)
      operand (void) const;

    private:
      /**
       * @brief Stores the operand.
       *
       * @details
       * Either a value, moved from a temporary, or a `const` reference to
       * a named operand (see `stored_operand_t`). It is not `const`, so
       * that a temporary expression can be moved into an enclosing one.
       */
      T t_;

      /**
       * @brief Stores the result of the operation.
       *
       * @details
       * Computed once, by the derived comparator constructor.
       */
      const bool value_{};
    };

    // ========================================================================

    /**
     * @brief Common base struct template for binary comparators.
     *
     * @details
     * This base struct stores two operands (left-hand and right-hand) along
     * with the pre-computed boolean result of a binary comparison. Derived
     * structs such as `compare_op`, `and_op`, and `or_op` inherit from this
     * to provide relational and logical operations. The comparison result is
     * computed at construction time and cached, enabling efficient
     * reporting and composition of complex assertions without repeated
     * computation.
     *
     * @tparam Lhs_T The type of the stored left-hand operand, either the
     * operand type, or a `const` reference to it (see `stored_operand_t`).
     * @tparam Rhs_T The type of the stored right-hand operand, either the
     * operand type, or a `const` reference to it.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class Lhs_T, class Rhs_T>
    struct binary_op : op
    {
      /**
       * @brief Constructs a binary comparator with the given operands and
       * pre-computed result.
       *
       * @details
       * The operands are forwarded to the members, so that the rvalues are
       * moved, not copied.
       *
       * @tparam L The type of the left-hand operand argument.
       * @tparam R The type of the right-hand operand argument.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @param value The pre-computed boolean result of the comparison.
       */
      template <class L, class R>
      constexpr binary_op (L&& lhs, R&& rhs, bool value);

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *   None.
       * @return The result of the comparison.
       */
      [[nodiscard]] constexpr
      operator bool () const;

      /**
       * @brief Retrieves the left-hand operand.
       *
       * @details
       * The operand is unwrapped with `detail::unwrap()` and returned by
       * reference, so that formatting it does not copy it.
       *
       * @par Parameters
       *   None.
       * @return The extracted left-hand operand.
       */
      [[nodiscard]] constexpr decltype (auto)
      lhs (void) const;

      /**
       * @brief Retrieves the right-hand operand.
       *
       * @details
       * The operand is unwrapped with `detail::unwrap()` and returned by
       * reference, so that formatting it does not copy it.
       *
       * @par Parameters
       *   None.
       * @return The extracted right-hand operand.
       */
      [[nodiscard]] constexpr decltype (auto)
      rhs (void) const;

    private:
      /**
       * @brief Stores the left-hand operand.
       *
       * @details
       * Either a value, moved from a temporary, or a `const` reference to
       * a named operand (see `stored_operand_t`), so that a named
       * container is not copied. It is not `const`, so that a temporary
       * expression can be moved into an enclosing one.
       */
      Lhs_T lhs_;

      /**
       * @brief Stores the right-hand operand.
       *
       * @details
       * Stored as the left-hand operand is.
       */
      Rhs_T rhs_;

      /**
       * @brief Stores the result of the comparison.
       *
       * @details
       * Computed once, by the derived comparator constructor.
       */
      const bool value_{};
    };

    // ========================================================================

    /**
     * @brief Equality tag for `compare_op`.
     *
     * @details
     * Defines the operator applied by `compare_op`, its symbol in the
     * failure reports, and the result when the operands are within the
     * tolerance of the floating-point wrappers.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct equal_to
    {
      /**
       * @brief The operator symbol, as displayed in the failure reports.
       *
       * @details
       * Includes the surrounding spaces, so that the formatter appends it
       * with a single call; a C string, not a `std::string_view`, which
       * would take two registers at each call site and enlarge the code.
       */
      static constexpr const char* symbol = " == ";

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
      /**
       * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
       * @brief Deprecated result when the operands are within the
       * tolerance.
       *
       * @details
       * Values within the tolerance are equal.
       *
       * Used only by the tolerance of the deprecated floating-point
       * wrappers.
       *
       * @deprecated To be removed with the deprecated floating-point
       * wrappers (since 6.0.0).
       */
      static constexpr bool within_tolerance_result = true;
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

      /**
       * @brief Compares the operands with `==`.
       *
       * @details
       * Always inlined, also at `-O0`, so that the debug builds do not
       * get one more function for each combination of operand types.
       *
       * @tparam Lhs_T The type of the left-hand operand.
       * @tparam Rhs_T The type of the right-hand operand.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @return The result of `lhs == rhs`, converted to `bool`.
       */
      template <class Lhs_T, class Rhs_T>
      [[nodiscard, gnu::always_inline]] static constexpr bool
      apply (const Lhs_T& lhs, const Rhs_T& rhs);
    };

    /**
     * @brief Non-equality tag for `compare_op`.
     *
     * @details
     * Defines the operator applied by `compare_op`, its symbol in the
     * failure reports, and the result when the operands are within the
     * tolerance of the floating-point wrappers.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct not_equal_to
    {
      /**
       * @brief The operator symbol, as displayed in the failure reports.
       *
       * @details
       * Includes the surrounding spaces, so that the formatter appends it
       * with a single call; a C string, not a `std::string_view`, which
       * would take two registers at each call site and enlarge the code.
       */
      static constexpr const char* symbol = " != ";

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
      /**
       * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
       * @brief Deprecated result when the operands are within the
       * tolerance.
       *
       * @details
       * Values within the tolerance are equal.
       *
       * Used only by the tolerance of the deprecated floating-point
       * wrappers.
       *
       * @deprecated To be removed with the deprecated floating-point
       * wrappers (since 6.0.0).
       */
      static constexpr bool within_tolerance_result = false;
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

      /**
       * @brief Compares the operands with `!=`.
       *
       * @details
       * Always inlined, also at `-O0`, so that the debug builds do not
       * get one more function for each combination of operand types.
       *
       * @tparam Lhs_T The type of the left-hand operand.
       * @tparam Rhs_T The type of the right-hand operand.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @return The result of `lhs != rhs`, converted to `bool`.
       */
      template <class Lhs_T, class Rhs_T>
      [[nodiscard, gnu::always_inline]] static constexpr bool
      apply (const Lhs_T& lhs, const Rhs_T& rhs);
    };

    /**
     * @brief Greater than tag for `compare_op`.
     *
     * @details
     * Defines the operator applied by `compare_op`, its symbol in the
     * failure reports, and the result when the operands are within the
     * tolerance of the floating-point wrappers.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct greater
    {
      /**
       * @brief The operator symbol, as displayed in the failure reports.
       *
       * @details
       * Includes the surrounding spaces, so that the formatter appends it
       * with a single call; a C string, not a `std::string_view`, which
       * would take two registers at each call site and enlarge the code.
       */
      static constexpr const char* symbol = " > ";

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
      /**
       * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
       * @brief Deprecated result when the operands are within the
       * tolerance.
       *
       * @details
       * Values within the tolerance are equal, not ordered.
       *
       * Used only by the tolerance of the deprecated floating-point
       * wrappers.
       *
       * @deprecated To be removed with the deprecated floating-point
       * wrappers (since 6.0.0).
       */
      static constexpr bool within_tolerance_result = false;
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

      /**
       * @brief Compares the operands with `>`.
       *
       * @details
       * Always inlined, also at `-O0`, so that the debug builds do not
       * get one more function for each combination of operand types.
       *
       * @tparam Lhs_T The type of the left-hand operand.
       * @tparam Rhs_T The type of the right-hand operand.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @return The result of `lhs > rhs`, converted to `bool`.
       */
      template <class Lhs_T, class Rhs_T>
      [[nodiscard, gnu::always_inline]] static constexpr bool
      apply (const Lhs_T& lhs, const Rhs_T& rhs);
    };

    /**
     * @brief Greater than or equal tag for `compare_op`.
     *
     * @details
     * Defines the operator applied by `compare_op`, its symbol in the
     * failure reports, and the result when the operands are within the
     * tolerance of the floating-point wrappers.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct greater_equal
    {
      /**
       * @brief The operator symbol, as displayed in the failure reports.
       *
       * @details
       * Includes the surrounding spaces, so that the formatter appends it
       * with a single call; a C string, not a `std::string_view`, which
       * would take two registers at each call site and enlarge the code.
       */
      static constexpr const char* symbol = " >= ";

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
      /**
       * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
       * @brief Deprecated result when the operands are within the
       * tolerance.
       *
       * @details
       * Values within the tolerance are equal.
       *
       * Used only by the tolerance of the deprecated floating-point
       * wrappers.
       *
       * @deprecated To be removed with the deprecated floating-point
       * wrappers (since 6.0.0).
       */
      static constexpr bool within_tolerance_result = true;
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

      /**
       * @brief Compares the operands with `>=`.
       *
       * @details
       * Always inlined, also at `-O0`, so that the debug builds do not
       * get one more function for each combination of operand types.
       *
       * @tparam Lhs_T The type of the left-hand operand.
       * @tparam Rhs_T The type of the right-hand operand.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @return The result of `lhs >= rhs`, converted to `bool`.
       */
      template <class Lhs_T, class Rhs_T>
      [[nodiscard, gnu::always_inline]] static constexpr bool
      apply (const Lhs_T& lhs, const Rhs_T& rhs);
    };

    /**
     * @brief Less than tag for `compare_op`.
     *
     * @details
     * Defines the operator applied by `compare_op`, its symbol in the
     * failure reports, and the result when the operands are within the
     * tolerance of the floating-point wrappers.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct less
    {
      /**
       * @brief The operator symbol, as displayed in the failure reports.
       *
       * @details
       * Includes the surrounding spaces, so that the formatter appends it
       * with a single call; a C string, not a `std::string_view`, which
       * would take two registers at each call site and enlarge the code.
       */
      static constexpr const char* symbol = " < ";

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
      /**
       * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
       * @brief Deprecated result when the operands are within the
       * tolerance.
       *
       * @details
       * Values within the tolerance are equal, not ordered.
       *
       * Used only by the tolerance of the deprecated floating-point
       * wrappers.
       *
       * @deprecated To be removed with the deprecated floating-point
       * wrappers (since 6.0.0).
       */
      static constexpr bool within_tolerance_result = false;
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

      /**
       * @brief Compares the operands with `<`.
       *
       * @details
       * Always inlined, also at `-O0`, so that the debug builds do not
       * get one more function for each combination of operand types.
       *
       * @tparam Lhs_T The type of the left-hand operand.
       * @tparam Rhs_T The type of the right-hand operand.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @return The result of `lhs < rhs`, converted to `bool`.
       */
      template <class Lhs_T, class Rhs_T>
      [[nodiscard, gnu::always_inline]] static constexpr bool
      apply (const Lhs_T& lhs, const Rhs_T& rhs);
    };

    /**
     * @brief Less than or equal tag for `compare_op`.
     *
     * @details
     * Defines the operator applied by `compare_op`, its symbol in the
     * failure reports, and the result when the operands are within the
     * tolerance of the floating-point wrappers.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct less_equal
    {
      /**
       * @brief The operator symbol, as displayed in the failure reports.
       *
       * @details
       * Includes the surrounding spaces, so that the formatter appends it
       * with a single call; a C string, not a `std::string_view`, which
       * would take two registers at each call site and enlarge the code.
       */
      static constexpr const char* symbol = " <= ";

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
      /**
       * @ingroup micro-os-plus-micro-test-plus-cpp-api-deprecated
       * @brief Deprecated result when the operands are within the
       * tolerance.
       *
       * @details
       * Values within the tolerance are equal.
       *
       * Used only by the tolerance of the deprecated floating-point
       * wrappers.
       *
       * @deprecated To be removed with the deprecated floating-point
       * wrappers (since 6.0.0).
       */
      static constexpr bool within_tolerance_result = true;
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

      /**
       * @brief Compares the operands with `<=`.
       *
       * @details
       * Always inlined, also at `-O0`, so that the debug builds do not
       * get one more function for each combination of operand types.
       *
       * @tparam Lhs_T The type of the left-hand operand.
       * @tparam Rhs_T The type of the right-hand operand.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @return The result of `lhs <= rhs`, converted to `bool`.
       */
      template <class Lhs_T, class Rhs_T>
      [[nodiscard, gnu::always_inline]] static constexpr bool
      apply (const Lhs_T& lhs, const Rhs_T& rhs);
    };

    // ========================================================================

    /**
     * @brief Relational comparator struct template.
     *
     * @details
     * Derived from `binary_op`, this struct compares the left-hand operand
     * with the right-hand operand, using the operator defined by the tag
     * `Compare_T` (`equal_to`, `not_equal_to`, `greater`, `greater_equal`,
     * `less`, or `less_equal`). It is used within test expressions to
     * provide human-readable relational assertions, with the actual and
     * expected values, and the symbol of the tag, reported upon failure.
     *
     * The tag is passed as an empty constructor argument, so that all
     * three template arguments are deduced, for example
     * `compare_op{ lhs, rhs, equal_to{} }`. A factory function would do the
     * same, but at `-O0` it adds one function per instantiation.
     *
     * It is also public, as `extension::compare_op`, so that the
     * applications can define their own comparisons with their own tags.
     * A tag is an empty struct with:
     * - a `static constexpr const char* symbol`, written between the
     *   operands in the failure reports, with the surrounding spaces
     *   (for example `" divides "`);
     * - a static `apply (lhs, rhs)` member function template, which
     *   receives the unwrapped operands (the values of the `to_*` wrappers
     *   and of the literals) and returns the result as `bool`;
     * - optionally, a `static constexpr bool within_tolerance_result`;
     *   when present, and an operand is a floating-point wrapper (see
     *   `extension::has_epsilon`), the operands within the tolerance give
     *   this result, as for the built-in comparators; when absent, the
     *   tolerance is ignored.
     *
     * The operands are not copied: the temporaries are moved into the
     * comparator, and the named operands of class type are referred to
     * (see `stored_operand_t`). A comparator built in a function from
     * its `const&` parameters refers to the arguments of that function,
     * so it must be checked in the statement that calls the function.
     *
     * @tparam Lhs_T The type of the stored left-hand operand, either the
     * operand type, or a `const` reference to it.
     * @tparam Rhs_T The type of the stored right-hand operand, either the
     * operand type, or a `const` reference to it.
     * @tparam Compare_T The tag that defines the comparison.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class Lhs_T, class Rhs_T, class Compare_T>
    struct compare_op : binary_op<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a comparator for the given operands.
       *
       * @details
       * The result is computed from the arguments, before they are
       * forwarded to the base. The tag argument is used only to deduce
       * `Compare_T`.
       *
       * @tparam L The type of the left-hand operand argument.
       * @tparam R The type of the right-hand operand argument.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      template <class L, class R>
      constexpr compare_op (L&& lhs, R&& rhs, Compare_T);
    };

    /**
     * @brief Deduction guide for the relational comparator.
     *
     * @details
     * Deduces `Lhs_T`, `Rhs_T`, and `Compare_T` from the constructor
     * arguments, so that `compare_op{ lhs, rhs, equal_to{} }` can be written
     * without explicit template arguments. The operand types are deduced
     * as forwarding references, and stored as `stored_operand_t` selects.
     */
    template <class Lhs_T, class Rhs_T, class Compare_T>
    compare_op (Lhs_T&&, Rhs_T&&, Compare_T)
        -> compare_op<stored_operand_t<Lhs_T>, stored_operand_t<Rhs_T>,
                      Compare_T>;

    // ========================================================================

    /**
     * @brief The type of an operand, after the framework wrappers are
     * removed by `detail::unwrap()`.
     *
     * @tparam T The type of the operand, possibly a reference.
     *
     * @details
     * Without references and qualifiers; for example `int` for a `to_i`
     * wrapper and for a `42_i` literal, and the type itself for the other
     * operands. Used by `approx_operand`.
     */
    template <class T>
    using unwrapped_t = std::remove_cvref_t<decltype (detail::unwrap (
        std::declval<const std::remove_cvref_t<T>&> ()))>;

    /**
     * @brief C++20 concept satisfied when `T` is a valid operand of the
     * approximate comparator.
     *
     * @tparam T The type to be checked, possibly a reference.
     *
     * @details
     * The `approx_operand` concept is satisfied when `T`, or the value it
     * wraps (for the framework value wrappers and the numeric literals), is
     * an arithmetic type other than `bool` and the character types (`char`,
     * `wchar_t`, `char8_t`, `char16_t`, and `char32_t`), which are not
     * numbers; `signed char` and `unsigned char` are accepted, as the
     * integer types they are.
     */
    template <class T>
    concept approx_operand = std::is_arithmetic_v<unwrapped_t<T>>
                             and not std::is_same_v<unwrapped_t<T>, bool>
                             and not std::is_same_v<unwrapped_t<T>, char>
                             and not std::is_same_v<unwrapped_t<T>, wchar_t>
                             and not std::is_same_v<unwrapped_t<T>, char8_t>
                             and not std::is_same_v<unwrapped_t<T>, char16_t>
                             and not std::is_same_v<unwrapped_t<T>, char32_t>;

    /**
     * @brief Tells whether two numbers differ by at most a tolerance.
     *
     * @details
     * If the three values are integers, the distance is computed exactly,
     * as an unsigned value, also for operands of mixed signedness, and
     * compared with the tolerance with `std::cmp_less_equal()`, so that neither
     * overflows nor wraps around. Otherwise, the values are converted to
     * their common floating-point type, and the absolute value of the
     * difference is compared with the tolerance. A negative tolerance, or
     * a NaN, makes the result `false`.
     *
     * @tparam Lhs_T The arithmetic type of the first value.
     * @tparam Rhs_T The arithmetic type of the second value.
     * @tparam Epsilon_T The arithmetic type of the tolerance.
     *
     * @param lhs The first value.
     * @param rhs The second value.
     * @param epsilon The tolerance.
     * @retval true The distance between the values is less than or equal
     * to the tolerance.
     * @retval false Otherwise.
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    [[nodiscard]] constexpr bool
    differ_by_at_most (Lhs_T lhs, Rhs_T rhs, Epsilon_T epsilon);

    /**
     * @brief Approximate comparator struct template.
     *
     * @details
     * Derived from `binary_op`, this struct compares two numbers with an
     * explicit tolerance, given as a third operand: the comparison
     * succeeds if the distance between the numbers is at most the
     * tolerance (see `detail::differ_by_at_most()`). The result is
     * computed at construction time. It is created by the
     * `approx (lhs, rhs, epsilon)` function comparator, and reported as
     * `lhs ~ (rhs +/- epsilon)`.
     *
     * The operands may be framework value wrappers or numeric literals,
     * which are unwrapped; their own tolerance, if any, is not used.
     *
     * @tparam Lhs_T The type of the stored left-hand operand, either the
     * operand type, or a `const` reference to it (see `stored_operand_t`).
     * @tparam Rhs_T The type of the stored right-hand operand, either the
     * operand type, or a `const` reference to it.
     * @tparam Epsilon_T The type of the stored tolerance, either the
     * operand type, or a `const` reference to it.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    struct approx_op : binary_op<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs an approximate comparator for the given operands.
       *
       * @details
       * The result is computed from the arguments, before they are
       * forwarded to the members.
       *
       * @tparam L The type of the left-hand operand argument.
       * @tparam R The type of the right-hand operand argument.
       * @tparam E The type of the tolerance argument.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       * @param epsilon The tolerance.
       */
      template <class L, class R, class E>
      constexpr approx_op (L&& lhs, R&& rhs, E&& epsilon);

      /**
       * @brief Retrieves the tolerance.
       *
       * @details
       * The tolerance is unwrapped with `detail::unwrap()`, as the
       * operands are.
       *
       * @par Parameters
       *   None.
       * @return The extracted tolerance.
       */
      [[nodiscard]] constexpr decltype (auto)
      epsilon (void) const;

    private:
      /**
       * @brief The stored tolerance.
       *
       * @details
       * Stored as the operands are (see `stored_operand_t`), only to be
       * reported; the result was already computed by the constructor.
       */
      Epsilon_T epsilon_;
    };

    /**
     * @brief Deduction guide for the approximate comparator.
     *
     * @details
     * Deduces `Lhs_T`, `Rhs_T`, and `Epsilon_T` from the constructor
     * arguments, which are stored as `stored_operand_t` selects.
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    approx_op (Lhs_T&&, Rhs_T&&, Epsilon_T&&)
        -> approx_op<stored_operand_t<Lhs_T>, stored_operand_t<Rhs_T>,
                     stored_operand_t<Epsilon_T>>;

    // ========================================================================

    /**
     * @brief Logical AND comparator struct template.
     *
     * @details
     * Derived from `binary_op`, this struct combines two sub-expressions
     * with a logical AND operation. It enables composition of complex
     * assertions by combining multiple conditions into a single logical
     * whole, with reporting that shows the combined result and individual
     * operand outcomes.
     *
     * The sub-expressions are not copied: the temporaries are moved into
     * the comparator, and the named ones are referred to (see
     * `stored_operand_t`).
     *
     * @tparam Lhs_T The type of the stored left-hand sub-expression,
     * either its type, or a `const` reference to it.
     * @tparam Rhs_T The type of the stored right-hand sub-expression,
     * either its type, or a `const` reference to it.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class Lhs_T, class Rhs_T>
    struct and_op : binary_op<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a logical AND comparator for the given operands.
       *
       * @details
       * The result is computed from the arguments, before they are
       * forwarded to the base.
       *
       * @tparam L The type of the left-hand operand argument.
       * @tparam R The type of the right-hand operand argument.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      template <class L, class R>
      constexpr and_op (L&& lhs, R&& rhs);
    };

    /**
     * @brief Deduction guide for the logical AND comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `and_op{ lhs, rhs }` can be written without explicit template arguments.
     * The operand types are deduced as forwarding references, and stored
     * as `stored_operand_t` selects.
     */
    template <typename Lhs_T, typename Rhs_T>
    and_op (Lhs_T&&, Rhs_T&&)
        -> and_op<stored_operand_t<Lhs_T>, stored_operand_t<Rhs_T>>;

    // ========================================================================

    /**
     * @brief Logical OR comparator struct template.
     *
     * @details
     * Derived from `binary_op`, this struct combines two sub-expressions
     * with a logical OR operation. It enables composition of complex
     * assertions by combining multiple conditions into a single logical
     * whole, with reporting that shows the combined result and individual
     * operand outcomes.
     *
     * The sub-expressions are not copied: the temporaries are moved into
     * the comparator, and the named ones are referred to (see
     * `stored_operand_t`).
     *
     * @tparam Lhs_T The type of the stored left-hand sub-expression,
     * either its type, or a `const` reference to it.
     * @tparam Rhs_T The type of the stored right-hand sub-expression,
     * either its type, or a `const` reference to it.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class Lhs_T, class Rhs_T>
    struct or_op : binary_op<Lhs_T, Rhs_T>
    {
      /**
       * @brief Constructs a logical OR comparator for the given operands.
       *
       * @details
       * The result is computed from the arguments, before they are
       * forwarded to the base.
       *
       * @tparam L The type of the left-hand operand argument.
       * @tparam R The type of the right-hand operand argument.
       *
       * @param lhs The left-hand operand.
       * @param rhs The right-hand operand.
       */
      template <class L, class R>
      constexpr or_op (L&& lhs, R&& rhs);
    };

    /**
     * @brief Deduction guide for the logical OR comparator.
     *
     * @details
     * Deduces `Lhs_T` and `Rhs_T` from the constructor arguments, so that
     * `or_op{ lhs, rhs }` can be written without explicit template arguments.
     * The operand types are deduced as forwarding references, and stored
     * as `stored_operand_t` selects.
     */
    template <typename Lhs_T, typename Rhs_T>
    or_op (Lhs_T&&, Rhs_T&&)
        -> or_op<stored_operand_t<Lhs_T>, stored_operand_t<Rhs_T>>;

    // ========================================================================

    /**
     * @brief Logical NOT comparator struct template.
     *
     * @details
     * Derived from `unary_op`, this struct negates a single sub-expression,
     * enabling test writers to assert that a condition does not hold. The
     * negation result is computed at construction time, ensuring consistent
     * reporting throughout the assertion framework.
     *
     * The sub-expression is not copied: a temporary is moved into the
     * comparator, and a named one is referred to (see
     * `stored_operand_t`).
     *
     * There is no deduction guide: with a single argument that is itself
     * a `not_op`, the class template argument deduction prefers the copy
     * deduction candidate, so `not_op{ inner }` would copy `inner`
     * instead of negating it. Name the template argument instead, as
     * `not_op<stored_operand_t<T>>{ t }`.
     *
     * @tparam T The type of the stored sub-expression, either its type,
     * or a `const` reference to it.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct not_op : unary_op<T>
    {
      /**
       * @brief Constructs a logical NOT comparator for the given operand.
       *
       * @details
       * The result is computed from the argument, before it is forwarded
       * to the base. The constraint leaves the copies and the moves of a
       * `not_op` to the implicit constructors.
       *
       * @tparam U The type of the operand argument.
       *
       * @param t The operand to be negated.
       */
      template <class U>
        requires (not std::is_same_v<std::remove_cvref_t<U>, not_op<T>>)
      explicit constexpr not_op (U&& t);
    };

    // ========================================================================

    /**
     * @brief Unary predicate struct template.
     *
     * @details
     * Derived from `unary_op`, this struct checks a property of a single
     * operand, using the predicate defined by the tag `Predicate_T`, and
     * reports the symbol of the tag followed by the operand upon failure,
     * as `not_op` reports `not`.
     *
     * It is public, as `extension::predicate_op`, so that the applications
     * can define their own predicates with their own tags. A tag is an
     * empty struct with:
     * - a `static constexpr const char* symbol`, written before the
     *   operand in the failure reports, with the trailing space (for
     *   example `"even "`);
     * - a static `apply (operand)` member function template, which
     *   receives the unwrapped operand (the value of a `to_*` wrapper or of
     *   a literal) and returns the result as `bool`.
     *
     * The tag is passed as an empty constructor argument, so that both
     * template arguments are deduced, for example
     * `predicate_op{ value, even{} }`.
     *
     * The operand is not copied: a temporary is moved into the
     * predicate, and a named operand of class type is referred to (see
     * `stored_operand_t`). A predicate built in a function from its
     * `const&` parameter refers to the argument of that function, so it
     * must be checked in the statement that calls the function.
     *
     * @tparam T The type of the stored operand, either the operand type,
     * or a `const` reference to it.
     * @tparam Predicate_T The tag that defines the predicate.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T, class Predicate_T>
    struct predicate_op : unary_op<T>
    {
      /**
       * @brief Constructs a predicate for the given operand.
       *
       * @details
       * The result is computed from the argument, before it is forwarded
       * to the base. The tag argument is used only to deduce
       * `Predicate_T`.
       *
       * @tparam U The type of the operand argument.
       *
       * @param t The operand.
       */
      template <class U>
      constexpr predicate_op (U&& t, Predicate_T);
    };

    /**
     * @brief Deduction guide for the unary predicate.
     *
     * @details
     * Deduces `T` and `Predicate_T` from the constructor arguments, so that
     * `predicate_op{ t, even{} }` can be written without explicit template
     * arguments. The operand type is deduced as a forwarding reference,
     * and stored as `stored_operand_t` selects.
     */
    template <class T, class Predicate_T>
    predicate_op (T&&, Predicate_T)
        -> predicate_op<stored_operand_t<T>, Predicate_T>;

    // ========================================================================

#if defined(__cpp_exceptions)

    /**
     * @brief Common base struct for callable-wrapping operators.
     *
     * @details
     * This base struct provides common functionality for operators that wrap
     * callable invocations, particularly for exception-checking operations.
     * Derived structs (such as `throws_op` and `nothrow_op`) use this base to
     * store and manage the pre-computed boolean result of a callable
     * invocation, enabling consistent reporting and composition of
     * exception-checking assertions.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct callable_op : op
    {
      /**
       * @brief Constructs a callable operator with the pre-computed
       * boolean result.
       *
       * @param value The pre-computed boolean result of the invocation.
       */
      constexpr explicit callable_op (bool value);

      /**
       * @brief Conversion operator to boolean.
       *
       * @par Parameters
       *   None.
       * @return The result of the callable invocation.
       */
      [[nodiscard]] constexpr
      operator bool () const;

    private:
      /**
       * @brief Stores the result of the callable invocation.
       *
       * @details
       * Computed once, by the derived operator constructor, which invokes
       * the callable.
       */
      const bool value_{};
    };

    // ========================================================================

    /**
     * @brief Operator struct template to check if an expression throws a
     * specific exception.
     *
     * @details
     * This primary template checks whether invoking the given callable
     * throws an exception of the specified type. The check is performed at
     * construction time, with the result cached for reporting and
     * composition. Use this when a test must verify that an operation raises
     * an expected exception of a particular type.
     *
     * The callable is used only by the constructor, so it is a parameter
     * of the constructor, not of the struct; all checks of the same
     * exception type share one struct, and one formatter instantiation.
     *
     * @tparam Exception_T The type of the exception to check for (defaults to
     * `void` for any exception).
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class Exception_T = void>
    struct throws_op : callable_op
    {
      /**
       * @brief Constructs an exception checking operator for the given
       * callable.
       *
       * @tparam Callable_T The type of the callable object to be invoked.
       * @param func The callable object to be invoked.
       */
      template <class Callable_T>
      constexpr explicit throws_op (const Callable_T& func);
    };

    // ========================================================================

    /**
     * @brief Operator struct to check if an expression throws any
     * exception.
     *
     * @details
     * This explicit specialisation checks whether invoking the given
     * callable throws any exception, regardless of type. The check is
     * performed at construction time, with the result cached for reporting
     * and composition. Use this when a test must verify that an operation
     * raises an exception without caring about the specific exception type.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <>
    struct throws_op<void> : callable_op
    {
      /**
       * @brief Constructs an exception checking operator for the given
       * callable.
       *
       * @tparam Callable_T The type of the callable object to be invoked.
       * @param func The callable object to be invoked.
       */
      template <class Callable_T>
      constexpr explicit throws_op (const Callable_T& func);
    };

    // ========================================================================

    /**
     * @brief Operator struct to check if an expression does not throw
     * any exception.
     *
     * @details
     * This struct checks whether invoking the given callable completes
     * without throwing an exception. The check is performed at construction
     * time, with the result cached for reporting and composition. Use this
     * when a test must verify that an operation does not throw.
     *
     * The callable is a parameter of the constructor only, so all the
     * checks share one struct, and one formatter overload.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct nothrow_op : callable_op
    {
      /**
       * @brief Constructs a nothrow checking operator for the given
       * callable.
       *
       * @tparam Callable_T The type of the callable object to be invoked.
       * @param func The callable object to be invoked.
       */
      template <class Callable_T>
      constexpr explicit nothrow_op (const Callable_T& func);
    };

#endif // defined(__cpp_exceptions)

    // ========================================================================

    /**
     * @brief Appends the shortest decimal representation of a numeric
     * value to a buffer.
     *
     * @tparam T The numeric type to format.
     * @param buffer The string to append to.
     * @param v The value to format.
     * @par Returns
     *   Nothing.
     */
    template <class T>
      requires std::is_arithmetic_v<T>
    void
    append_number (std::string& buffer, T v);

    /**
     * @brief Appends the hexadecimal address of a pointer to a buffer.
     *
     * @details
     * Shared by the `reporter` and the `expression_formatter`, so that
     * the pointers are displayed identically in the messages and in the
     * expressions. Pointers to `const` or `volatile` objects, and function
     * pointers, are accepted too.
     *
     * @tparam T The type pointed to (an object or a function type).
     * @param buffer The string to append to.
     * @param v The pointer.
     * @par Returns
     *   Nothing.
     */
    template <class T>
    void
    append_pointer (std::string& buffer, T* v);

    // ========================================================================

    /**
     * @brief A C string operand of a comparator.
     *
     * @details
     * The comparators convert the `char` arrays (including the string
     * literals) and the `char` pointers to this type (see `as_operand()`),
     * so that they are compared by content, as a reader of a test expects,
     * and not by address. A null pointer is equal only to another null
     * pointer (not to an empty string), and is less than any string.
     *
     * The characters are not copied; the operand must outlive the
     * comparison, which is always the case within a check.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct c_string
    {
      /**
       * @brief Constructs the operand from a pointer to a null-terminated
       * string.
       *
       * @param str The string, or `nullptr`.
       */
      constexpr explicit c_string (const char* str) noexcept;

      /**
       * @brief Constructs the operand from a `char` array.
       *
       * @details
       * The string ends at the first null character, or at the end of the
       * array, so that an array without a terminator is not read beyond
       * its end.
       *
       * @param str The first character of the array.
       * @param capacity The number of elements of the array.
       */
      constexpr c_string (const char* str, std::size_t capacity) noexcept;

      /**
       * @brief Returns the characters, as a string view.
       *
       * @par Parameters
       *   None.
       * @return The characters, without the terminator; empty for a null
       * pointer.
       */
      [[nodiscard]] constexpr std::string_view
      view (void) const noexcept;

      /**
       * @brief Returns whether the operand is a null pointer.
       *
       * @par Parameters
       *   None.
       * @retval true The operand is a null pointer.
       * @retval false The operand is a string, possibly empty.
       */
      [[nodiscard]] constexpr bool
      is_null (void) const noexcept;

    private:
      /**
       * @brief The first character, or `nullptr`.
       *
       * @details
       * Not owned; points into the operand passed to the comparator.
       */
      const char* str_;

      /**
       * @brief The number of characters, without the terminator.
       *
       * @details
       * Computed by the constructors; zero for a null pointer.
       */
      std::size_t size_;
    };

    /**
     * @brief Compares two C string operands for equality.
     *
     * @param lhs The left operand.
     * @param rhs The right operand.
     * @retval true Both are null, or both are strings with the same
     * characters.
     * @retval false Otherwise.
     */
    [[nodiscard]] constexpr bool
    operator== (const c_string& lhs, const c_string& rhs) noexcept;

    /**
     * @brief Compares a C string operand with a string.
     *
     * @details
     * Also used for `std::string` operands, which convert to
     * `std::string_view`, and, as a rewritten candidate, with the operands
     * in the reverse order.
     *
     * @param lhs The C string operand.
     * @param rhs The string.
     * @retval true The operand is not null and has the same characters.
     * @retval false Otherwise.
     */
    [[nodiscard]] constexpr bool
    operator== (const c_string& lhs, std::string_view rhs) noexcept;

    /**
     * @brief Checks whether a C string operand is a null pointer.
     *
     * @param lhs The C string operand.
     * @retval true The operand is a null pointer.
     * @retval false Otherwise.
     */
    [[nodiscard]] constexpr bool
    operator== (const c_string& lhs, std::nullptr_t) noexcept;

    /**
     * @brief Orders two C string operands.
     *
     * @param lhs The left operand.
     * @param rhs The right operand.
     * @return The lexicographic order of the characters; a null pointer is
     * equal to another null pointer and less than any string.
     */
    [[nodiscard]] constexpr std::strong_ordering
    operator<=> (const c_string& lhs, const c_string& rhs) noexcept;

    /**
     * @brief Orders a C string operand and a string.
     *
     * @param lhs The C string operand.
     * @param rhs The string.
     * @return The lexicographic order of the characters; a null pointer is
     * less than any string.
     */
    [[nodiscard]] constexpr std::strong_ordering
    operator<=> (const c_string& lhs, std::string_view rhs) noexcept;

    /**
     * @brief An array operand of a comparator, other than a `char` array.
     *
     * @details
     * The comparators convert the arrays of any element type except `char`
     * (the byte buffers, the arrays of numbers, and the arrays of the
     * wide character types) to this type (see `as_operand()`), so that
     * they are compared element by element, and written as ranges,
     * instead of being compared and written as the addresses they decay
     * to. Two arrays of different sizes are never equal.
     *
     * The elements are not copied; the operand must outlive the
     * comparison, which is always the case within a check.
     *
     * @tparam T The element type, possibly `const`.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <class T>
    struct array_operand
    {
      /**
       * @brief Constructs the operand from the first element and the
       * size of an array.
       *
       * @param first The first element of the array.
       * @param count The number of elements of the array.
       */
      constexpr array_operand (const T* first, std::size_t count) noexcept;

      /**
       * @brief Returns an iterator to the first element.
       *
       * @par Parameters
       *   None.
       * @return A pointer to the first element.
       */
      [[nodiscard]] constexpr const T*
      begin (void) const noexcept;

      /**
       * @brief Returns an iterator past the last element.
       *
       * @par Parameters
       *   None.
       * @return A pointer past the last element.
       */
      [[nodiscard]] constexpr const T*
      end (void) const noexcept;

    private:
      /**
       * @brief The first element.
       *
       * @details
       * Not owned; points into the array passed to the comparator.
       */
      const T* first_;

      /**
       * @brief The number of elements.
       */
      std::size_t count_;
    };

    /**
     * @brief Compares an array operand with a range for equality.
     *
     * @tparam T The element type of the array operand.
     * @tparam R The type of the range.
     *
     * @param lhs The array operand.
     * @param rhs The range, which may be another array operand.
     * @retval true The ranges have the same size and equal elements.
     * @retval false Otherwise.
     */
    template <class T, class R>
      requires (container_like<R>
                and std::equality_comparable_with<
                    T, typename range_element<R>::type>)
    [[nodiscard]] constexpr bool
    operator== (const array_operand<T>& lhs, const R& rhs);

    /**
     * @brief Orders an array operand and a range lexicographically.
     *
     * @tparam T The element type of the array operand.
     * @tparam R The type of the range.
     *
     * @param lhs The array operand.
     * @param rhs The range, which may be another array operand.
     * @return The lexicographic order of the elements.
     */
    template <class T, class R>
      requires (container_like<R>
                and std::three_way_comparable_with<
                    T, typename range_element<R>::type>)
    [[nodiscard]] constexpr auto
    operator<=> (const array_operand<T>& lhs, const R& rhs);

    /**
     * @brief Prepares an operand of a comparator.
     *
     * @details
     * The `char` arrays and the `char` pointers (not those of `signed
     * char` or `unsigned char`, which are byte buffers) are converted to
     * `c_string`, so that they are compared by content; the other arrays
     * are converted to `array_operand`, so that they are compared by
     * content, the functions to function pointers, and all other operands
     * are returned unchanged, so the other pointers and the functions are
     * compared by address.
     *
     * The other operands are forwarded, so that the comparator moves a
     * temporary, and refers to a named operand.
     *
     * @tparam T The type deduced for the forwarding reference.
     *
     * @param t The operand.
     * @return A `c_string` for the C strings, an `array_operand` for the
     * other arrays, otherwise `t`, forwarded.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    as_operand (T&& t) noexcept -> decltype (auto);

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------

  namespace extension
  {
    // ------------------------------------------------------------------------
    // The expressions of the custom comparators, predicates, and operators.

    // The definitions are in `detail`, with the built-in expressions that
    // share them; the using-declarations name the same templates, so the
    // class template argument deduction applies, and the formatter
    // reports them as the built-in ones.

    using detail::compare_op;
    using detail::predicate_op;

    // ------------------------------------------------------------------------
  } // namespace extension

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/detail-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------
