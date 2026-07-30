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
 * @brief C++ header with declarations for the µTest++ exception-checking
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
 * reside within the `micro_os_plus::micro_test_plus` namespace, ensuring
 * clear separation from user code and minimising the risk of naming conflicts.
 *
 * This header is located in the top-level `include/micro-os-plus` folder.
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

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

#if defined(__cpp_exceptions)

  /**
   * @ingroup micro-os-plus-micro-test-plus-exceptions
   * @brief Check if a callable throws a specific exception.
   *
   * @tparam Exception_T The type of the exception expected to be thrown.
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param func The callable object to check for exception throwing
   * behaviour.
   * @return An output stream to write optional messages.
   */
  template <class Exception_T, class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func);

  /**
   * @ingroup micro-os-plus-micro-test-plus-exceptions
   * @brief Check if a callable throws an exception (any exception).
   *
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param func The callable object to check for exception throwing
   * behaviour.
   * @return An output stream to write optional messages.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func);

  /**
   * @ingroup micro-os-plus-micro-test-plus-exceptions
   * @brief Check if a callable does not throw an exception.
   *
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param func The callable object to check for exception safety.
   * @return An output stream to write optional messages.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  nothrow (const Callable_T& func);

#endif

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/exceptions-inline.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_EXCEPTIONS_H_

// ----------------------------------------------------------------------------
