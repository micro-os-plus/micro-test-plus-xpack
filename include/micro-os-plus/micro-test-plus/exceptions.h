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
 * @brief C++ header file with declarations for the µTest++ exception-checking
 * functions.
 *
 * @details
 * This header provides the declarations for the exception-checking facilities
 * of the µTest++ framework. It exposes three function templates —
 * `throws<Exception_T>()`, `throws()`, and `nothrow()` — which allow test
 * cases to verify that a callable throws a specific exception, throws any
 * exception, or throws no exception, respectively.
 *
 * All declarations are conditionally compiled under `__cpp_exceptions` and
 * reside within the `micro_os_plus::micro_test_plus` namespace.
 *
 * This header is located in the `include/micro-os-plus/micro-test-plus`
 * folder.
 * Users should include `"micro-os-plus/micro-test-plus.h"` rather than this
 * header directly.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_EXCEPTIONS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_EXCEPTIONS_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "detail.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

#if defined(__cpp_exceptions)

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-exceptions
   * @brief Checks whether a callable throws a specific exception, for
   * `expect()` or `require()`.
   *
   * @details
   * The callable is invoked once, immediately. The check passes if it
   * throws an exception of type `Exception_T` or of a type derived from
   * it, so `throws<std::exception>()` passes for any standard exception.
   * An exception of another type, or no exception, fails the check, and
   * the report states what was thrown.
   *
   * @tparam Exception_T The type of the exception expected to be thrown.
   * @tparam Callable_T The type of the callable object to be invoked; it
   * must be invocable without arguments, as an lvalue, so a `mutable`
   * lambda is accepted.
   * @param func The callable object to check for exception throwing
   * behaviour.
   * @return An object of an unspecified type, holding the result, to be
   * passed to `expect()` or `require()`.
   */
  template <class Exception_T, class Callable_T>
    requires std::invocable<Callable_T&>
  [[nodiscard]] auto
  throws (Callable_T&& func);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-exceptions
   * @brief Checks whether a callable throws any exception, for `expect()`
   * or `require()`.
   *
   * @details
   * The callable is invoked once, immediately. The check passes if it
   * throws an exception of any type.
   *
   * @tparam Callable_T The type of the callable object to be invoked; it
   * must be invocable without arguments, as an lvalue, so a `mutable`
   * lambda is accepted.
   * @param func The callable object to check for exception throwing
   * behaviour.
   * @return An object of an unspecified type, holding the result, to be
   * passed to `expect()` or `require()`.
   */
  template <class Callable_T>
    requires std::invocable<Callable_T&>
  [[nodiscard]] auto
  throws (Callable_T&& func);

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-exceptions
   * @brief Checks whether a callable does not throw any exception, for
   * `expect()` or `require()`.
   *
   * @tparam Callable_T The type of the callable object to be invoked; it
   * must be invocable without arguments, as an lvalue, so a `mutable`
   * lambda is accepted.
   * @param func The callable object to check.
   * @return An object of an unspecified type, holding the result, to be
   * passed to `expect()` or `require()`.
   */
  template <class Callable_T>
    requires std::invocable<Callable_T&>
  [[nodiscard]] auto
  nothrow (Callable_T&& func);

#endif // defined(__cpp_exceptions)

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/exceptions-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_EXCEPTIONS_H_

// ----------------------------------------------------------------------------
