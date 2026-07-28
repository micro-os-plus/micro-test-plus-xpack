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
 * @brief C++ header file with inline implementations for the µTest++
 * exceptions comparators.
 *
 * @details
 * This header provides the inline implementations for the exception comparator
 * templates used within the µTest++ framework.
 *
 * ...
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_EXCEPTIONS_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_EXCEPTIONS_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // Exceptions related comparators.

#if defined(__cpp_exceptions)

  /**
   * @details
   * The `throws` function template verifies whether invoking the provided
   * callable object results in the throwing of a specific exception type
   * within the µTest++ framework. This is useful for testing error handling
   * and exception safety in code under test.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   */
  template <class Exception_T, class Callable_T>
  constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T, Exception_T>{ func };
  }

  /**
   * @details
   * The `throws` function template verifies whether invoking the provided
   * callable object results in the throwing of any exception within the
   * µTest++ framework. This is useful for testing general exception safety and
   * ensuring that code under test properly signals error conditions.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   */
  template <class Callable_T>
  constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T>{ func };
  }

  /**
   * @details
   * The `nothrow` function template verifies whether invoking the provided
   * callable object does not result in the throwing of any exception within
   * the µTest++ framework. This is useful for testing exception safety and
   * ensuring that code under test does not unexpectedly signal error
   * conditions.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   */
  template <class Callable_T>
  constexpr auto
  nothrow (const Callable_T& func)
  {
    return detail::nothrow_<Callable_T>{ func };
  }

#endif // defined(__cpp_exceptions)

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_EXCEPTIONS_INLINES_H_

// ----------------------------------------------------------------------------
