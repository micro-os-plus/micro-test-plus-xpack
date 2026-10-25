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
 * @brief C++ header file with the declarations of the deprecated µTest++
 * definitions.
 *
 * @details
 * This header groups the deprecated definitions that are not members of
 * the framework classes, kept for compatibility with the applications
 * written for the previous versions:
 * - the v5.0.1 names of the logical functions (`_not`, `_and`, and
 *   `_or`);
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
 * Keeping the deprecated definitions separate makes them easy to
 * identify and, in a future major release, to remove.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
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
#include "literals.h"
#include "reflection.h"
#include "runner.h"
#include "stopwatch.h"
#include "test.h"

#include <concepts>
#include <ctime>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // The logical functions, now `negate()`, `all_of()`, and `any_of()`, in
  // `function-comparators.h`.

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **not** operation, the v5.0.1 name of
   * `negate()`.
   *
   * @details
   * The same as `negate()`. The name was changed since a leading
   * underscore is not used by the other public names.
   *
   * @tparam Expr_T Type of the operand.
   *
   * @param expr Logical expression to be negated.
   * @return An object that evaluates to true if the operand is false.
   */
  template <class Expr_T>
  [[deprecated ("use negate() (since 5.1.0)"), nodiscard]] constexpr auto
  _not (Expr_T&& expr);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical **and** operation, the v5.0.1 name of
   * `all_of()`.
   *
   * @details
   * The same as `all_of()`. The name was changed since a leading
   * underscore is not used by the other public names.
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
  [[deprecated ("use all_of() (since 5.1.0)"), nodiscard]] constexpr auto
  _and (Lhs_T&& lhs, Rhs_T&& rhs);

  /**
   * @ingroup micro-os-plus-micro-test-plus-logical-functions
   * @brief Generic logical (inclusive) **or** operation, the v5.0.1 name
   * of `any_of()`.
   *
   * @details
   * The same as `any_of()`. The name was changed since a leading
   * underscore is not used by the other public names.
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
  [[deprecated ("use any_of() (since 5.1.0)"), nodiscard]] constexpr auto
  _or (Lhs_T&& lhs, Rhs_T&& rhs);

  // --------------------------------------------------------------------------
  // The type wrappers, now `to_*`, in `literals.h`.

#if defined(__GNUC__)
#pragma GCC diagnostic push
// The aliases refer to the `to_*` names, deprecated too.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)

  /**
   * @addtogroup micro-os-plus-micro-test-plus-literals
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
   * 5.1.0).
   *
   * @{
   */

  /**
   * @brief Strongly-typed wrapper for `bool` values, the v5.0.1 name of
   * `to_b`.
   *
   * @details
   * The same type as `to_b`; kept for backwards compatibility.
   */
  using _b [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_b;

  /**
   * @brief Strongly-typed wrapper for `char` values, the v5.0.1 name of
   * `to_c`.
   *
   * @details
   * The same type as `to_c`; kept for backwards compatibility.
   */
  using _c [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_c;

  /**
   * @brief Strongly-typed wrapper for `signed char` values, the v5.0.1 name of
   * `to_sc`.
   *
   * @details
   * The same type as `to_sc`; kept for backwards compatibility.
   */
  using _sc [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_sc;

  /**
   * @brief Strongly-typed wrapper for `short` values, the v5.0.1 name of
   * `to_s`.
   *
   * @details
   * The same type as `to_s`; kept for backwards compatibility.
   */
  using _s [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_s;

  /**
   * @brief Strongly-typed wrapper for `int` values, the v5.0.1 name of
   * `to_i`.
   *
   * @details
   * The same type as `to_i`; kept for backwards compatibility.
   */
  using _i [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i;

  /**
   * @brief Strongly-typed wrapper for `long` values, the v5.0.1 name of
   * `to_l`.
   *
   * @details
   * The same type as `to_l`; kept for backwards compatibility.
   */
  using _l [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_l;

  /**
   * @brief Strongly-typed wrapper for `long long` values, the v5.0.1 name of
   * `to_ll`.
   *
   * @details
   * The same type as `to_ll`; kept for backwards compatibility.
   */
  using _ll [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_ll;

  /**
   * @brief Strongly-typed wrapper for `unsigned` values, the v5.0.1 name of
   * `to_u`.
   *
   * @details
   * The same type as `to_u`; kept for backwards compatibility.
   */
  using _u [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u;

  /**
   * @brief Strongly-typed wrapper for `unsigned char` values, the v5.0.1
   * name of `to_uc`.
   *
   * @details
   * The same type as `to_uc`; kept for backwards compatibility.
   */
  using _uc [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_uc;

  /**
   * @brief Strongly-typed wrapper for `unsigned short` values, the v5.0.1
   * name of `to_us`.
   *
   * @details
   * The same type as `to_us`; kept for backwards compatibility.
   */
  using _us [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_us;

  /**
   * @brief Strongly-typed wrapper for `unsigned long` values, the v5.0.1
   * name of `to_ul`.
   *
   * @details
   * The same type as `to_ul`; kept for backwards compatibility.
   */
  using _ul [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_ul;

  /**
   * @brief Strongly-typed wrapper for `unsigned long long` values, the v5.0.1
   * name of `to_ull`.
   *
   * @details
   * The same type as `to_ull`; kept for backwards compatibility.
   */
  using _ull [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_ull;

  /**
   * @brief Strongly-typed wrapper for `std::int8_t` values, the v5.0.1 name of
   * `to_i8`.
   *
   * @details
   * The same type as `to_i8`; kept for backwards compatibility.
   */
  using _i8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i8;

  /**
   * @brief Strongly-typed wrapper for `std::int16_t` values, the v5.0.1
   * name of `to_i16`.
   *
   * @details
   * The same type as `to_i16`; kept for backwards compatibility.
   */
  using _i16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i16;

  /**
   * @brief Strongly-typed wrapper for `std::int32_t` values, the v5.0.1
   * name of `to_i32`.
   *
   * @details
   * The same type as `to_i32`; kept for backwards compatibility.
   */
  using _i32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i32;

  /**
   * @brief Strongly-typed wrapper for `std::int64_t` values, the v5.0.1
   * name of `to_i64`.
   *
   * @details
   * The same type as `to_i64`; kept for backwards compatibility.
   */
  using _i64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_i64;

  /**
   * @brief Strongly-typed wrapper for `std::uint8_t` values, the v5.0.1
   * name of `to_u8`.
   *
   * @details
   * The same type as `to_u8`; kept for backwards compatibility.
   */
  using _u8 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u8;

  /**
   * @brief Strongly-typed wrapper for `std::uint16_t` values, the v5.0.1
   * name of `to_u16`.
   *
   * @details
   * The same type as `to_u16`; kept for backwards compatibility.
   */
  using _u16 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u16;

  /**
   * @brief Strongly-typed wrapper for `std::uint32_t` values, the v5.0.1
   * name of `to_u32`.
   *
   * @details
   * The same type as `to_u32`; kept for backwards compatibility.
   */
  using _u32 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u32;

  /**
   * @brief Strongly-typed wrapper for `std::uint64_t` values, the v5.0.1
   * name of `to_u64`.
   *
   * @details
   * The same type as `to_u64`; kept for backwards compatibility.
   */
  using _u64 [[deprecated (
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
  = to_u64;

  /**
   * @brief Strongly-typed wrapper for `float` values, the v5.0.1 name of
   * `to_f`.
   *
   * @details
   * The same type as `to_f`; kept for backwards compatibility.
   */
  using _f [[deprecated ("use approx() for tolerances (since 5.1.0)")]] = to_f;

  /**
   * @brief Strongly-typed wrapper for `double` values, the v5.0.1 name of
   * `to_d`.
   *
   * @details
   * The same type as `to_d`; kept for backwards compatibility.
   */
  using _d [[deprecated ("use approx() for tolerances (since 5.1.0)")]] = to_d;

  /**
   * @brief Strongly-typed wrapper for `long double` values, the v5.0.1 name of
   * `to_ld`.
   *
   * @details
   * The same type as `to_ld`; kept for backwards compatibility.
   */
  using _ld [[deprecated ("use approx() for tolerances (since 5.1.0)")]]
  = to_ld;

  /**
   * @brief Generic strongly-typed wrapper, the v5.0.1 name of `to_t`.
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
      "pass plain values to eq() and the other comparators (since 5.1.0)")]]
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
   * @ingroup micro-os-plus-micro-test-plus-test-case
   * @brief Deprecated name of `test_case`.
   *
   * @details
   * The v5.0.1 name of the class passed to the test case bodies, kept
   * for the functions and the lambdas that name it as the type of their
   * first parameter (`void f (mt::subtest& t)`); the lambdas with an
   * `auto&` parameter are not affected.
   */
  using subtest [[deprecated ("use test_case (since 5.1.0)")]] = test_case;

  // ==========================================================================
  // The runner class, now `runner`, in `runner.h`.

  /**
   * @ingroup micro-os-plus-micro-test-plus-runners
   * @brief Deprecated name of `runner`.
   *
   * @details
   * The `runner` also runs the `static_suite` objects that refer to it,
   * so a separate runner class is no longer needed.
   */
  using static_runner [[deprecated ("use runner (since 5.1.0)")]] = runner;

  // --------------------------------------------------------------------------

  namespace reflection
  {
    // ------------------------------------------------------------------------
    // Now `utility::extract_file_name()`, in `utility.h`.

    /**
     * @brief Extracts the file name from a path.
     *
     * @details
     * Forwards to `utility::extract_file_name()`, which the framework
     * uses internally; it is kept only for compatibility with the
     * existing applications.
     *
     * @param name The path, as a C-string.
     * @return A pointer to the file name within the input string, after
     * the last `/` or `\` separator, or the string itself if there is
     * no separator.
     */
    [[deprecated ("use utility::extract_file_name() (since 5.1.0)"),
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
     * @brief Deprecated name of `counters`.
     *
     * @details
     * The v5.0.1 name of the class returned by `totals()`, renamed since
     * the suites and the test cases own one too, not only the runner.
     */
    using runner_totals [[deprecated ("use counters (since 5.1.0)")]]
    = counters;

    // ========================================================================
    // The timings classes, now `stopwatch`, in `stopwatch.h`.

    /**
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
    using timestamps [[deprecated ("the timings are internal (since 5.1.0)")]]
    = stopwatch;

    // ========================================================================

    /**
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
    class [[deprecated ("the timings are internal (since 5.1.0)")]] timestamp
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
   * exception is `has_value`, which is not used by the framework any
   * more, and is restored with its v5.0.1 definition.
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
      [[deprecated ("use the extension namespace (since 5.1.0)")]] type_traits
  {
    // ------------------------------------------------------------------------
    // Concepts, now in the `extension` and `detail` namespaces.

    using extension::any_op;
    using extension::checkable;
    using extension::has_epsilon;
    using extension::is_op;
    using extension::printable;

    using detail::container_like;
    using detail::has_npos;

    /**
     * @brief Deprecated C++20 concept satisfied when `T` has a member
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
     * framework is internal (since 5.1.0).
     */
    template <class T>
    concept has_value = requires (const T& t) { t.value; };

    /**
     * @brief Deprecated C++20 concept satisfied when `T` is a
     * floating-point type.
     *
     * @tparam T The type to be checked.
     *
     * @details
     * The v5.0.1 name of `std::floating_point`, which the framework now
     * uses directly.
     *
     * @deprecated Use `std::floating_point` (since 5.1.0).
     */
    template <class T>
    concept is_floating_point = std::floating_point<T>;

    // ------------------------------------------------------------------------
    // Helpers removed from the framework, restored as in v5.0.1.

    /**
     * @brief Deprecated empty type list.
     *
     * @tparam Types The types in the list.
     *
     * @details
     * Used only as the type of `function_traits<>::args`; the framework no
     * longer uses it.
     *
     * @deprecated Not replaced (since 5.1.0).
     */
    template <class... Types>
    struct list
    {
    };

    /**
     * @brief Deprecated identity type.
     *
     * @tparam T The type to be exposed.
     * @tparam Extra Additional types, ignored.
     *
     * @details
     * Exposes `T` as the member type `type`, like `std::type_identity`,
     * which replaces it.
     *
     * @deprecated Use `std::type_identity` (since 5.1.0).
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
     * @deprecated Not replaced (since 5.1.0).
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
     * @brief Deprecated traits of the function pointers.
     *
     * @tparam R The return type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a pointer to a
     * free function.
     *
     * @deprecated Not replaced (since 5.1.0).
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
     * @brief Deprecated traits of the function types.
     *
     * @tparam R The return type.
     * @tparam Args_T The parameter types.
     *
     * @details
     * Exposes the return type and the parameter types of a function type.
     *
     * @deprecated Not replaced (since 5.1.0).
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
     * @deprecated Not replaced (since 5.1.0).
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
     * @deprecated Not replaced (since 5.1.0).
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
     * @deprecated The value wrappers are internal (since 5.1.0).
     */
    template <class T>
    using value_base_ = detail::value_base<T>;

    /**
     * @brief Deprecated integral value wrapper.
     *
     * @tparam T The integral type of the stored value.
     *
     * @details
     * In v5.0.1, a separate wrapper with the same members as `value<T>`,
     * never created by the framework; now `value<T>`, so the values are
     * compared and reported in the same way.
     *
     * @deprecated The value wrappers are internal (since 5.1.0).
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

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/deprecated-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_H_

// ----------------------------------------------------------------------------
