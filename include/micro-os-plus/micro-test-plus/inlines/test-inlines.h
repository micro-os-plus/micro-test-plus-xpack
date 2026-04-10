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
 * @brief C++ header file with inline implementations for the µTest++ test
 * suite.
 *
 * @details
 * This header provides the inline implementations for the test suite
 * facilities used within the µTest++ framework. It defines the logic for
 * constructing and registering test suites, including the binding of callable
 * objects and their arguments for flexible test suite definitions.
 *
 * The implementation ensures that each test suite is automatically registered
 * with the global test runner upon construction, enabling automated discovery
 * and execution of test suites. The use of `std::bind` allows for versatile
 * test suite initialisation with arbitrary callable types and arguments.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, maintaining a clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_TEST_INLINES_H_
#define MICRO_TEST_PLUS_TEST_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <cstring>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#else // GCC only
// #pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // ==========================================================================

  /**
   * @details
   * Binds the callable and its arguments into the stored `callable_` function
   * object. When `run()` is called, the stored function is invoked with a
   * reference to the derived `Self_T` instance as its first argument,
   * followed by the bound arguments.
   */
  template <typename Self_T>
  template <typename Callable_T, typename... Args_T>
  runnable<Self_T>::runnable (const char* name, class runner& runner,
                              size_t own_index, Callable_T&& callable,
                              Args_T&&... arguments)
      : runnable_base{ name, runner, own_index }
  {
    // When there are no extra arguments the callable already has the signature
    // void(Self_T&), so store it directly. Only use std::bind when additional
    // arguments must be pre-bound, to avoid triggering a GCC ARM bug in
    // __is_nothrow_invocable<_Bind<...>, Self_T&> (GCC 15.2.1).
    if constexpr (sizeof...(arguments) == 0)
      {
        callable_ = std::forward<Callable_T> (callable);
      }
    else
      {
        callable_ = std::bind (std::forward<Callable_T> (callable),
                               std::placeholders::_1,
                               std::forward<Args_T> (arguments)...);
      }

#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  template <typename Self_T>
  runnable<Self_T>::~runnable ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  // ==========================================================================

  /**
   * @details
   * Delegates to `runnable`, which binds the callable with
   * its arguments.
   */
  template <typename Callable_T, typename... Args_T>
  subtest::subtest (const char* name, class runner& runner,
                    suite& parent_suite, size_t own_index,
                    size_t nesting_depth, Callable_T&& callable,
                    Args_T&&... arguments)
      : runnable<subtest>{ name, runner, own_index,
                           std::forward<Callable_T> (callable),
                           std::forward<Args_T> (arguments)... },
        parent_suite_{ parent_suite }, nesting_depth_{ nesting_depth }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu %zu\n", __PRETTY_FUNCTION__, name, own_index_,
            nesting_depth_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  template <typename Callable_T, typename... Args_T>
  void
  subtest::test (const char* name, Callable_T&& callable,
                 Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    size_t own_index = increment_subtest_index ();
    auto child_test = std::make_unique<subtest> (
        name, runner (), parent_suite_, own_index, nesting_depth_ + 1,
        std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...);

    after_subtest_create (std::move (child_test), parent_suite_);
  }

  // ==========================================================================

  /**
   * @details
   * Delegates to `runnable`, which binds the callable with
   * its arguments. After construction, the suite is registered with the
   * static test runner.
   */
  template <typename Callable_T, typename... Args_T>
  suite::suite (const char* name, class runner& runner, size_t own_index,
                Callable_T&& callable, Args_T&&... arguments)
      : runnable<suite>{ name, runner, own_index,
                         std::forward<Callable_T> (callable),
                         std::forward<Args_T> (arguments)... }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  template <typename Callable_T, typename... Args_T>
  void
  suite::test (const char* name, Callable_T&& callable, Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    size_t own_index = increment_subtest_index ();
    auto child_test
        = std::make_unique<subtest> (name, runner (), *this, own_index, 1,
                                     std::forward<Callable_T> (callable),
                                     std::forward<Args_T> (arguments)...);

    after_subtest_create (std::move (child_test), *this);
  }

  // ==========================================================================

  /**
   * @details
   * Delegates to `runnable`, which binds the callable with
   * its arguments. After construction, the suite is registered with the
   * static test runner.
   */
  template <typename Callable_T, typename... Args_T>
  static_suite::static_suite (const char* name, static_runner& runner,
                              Callable_T&& callable, Args_T&&... arguments)
      : suite{ name, runner, runner.static_suites_count () + 1,
               [] (suite&) noexcept {} }
  {
    if constexpr (sizeof...(arguments) == 0)
      {
        static_callable_ = std::forward<Callable_T> (callable);
      }
    else
      {
        static_callable_ = std::bind (std::forward<Callable_T> (callable),
                                      std::placeholders::_1,
                                      std::forward<Args_T> (arguments)...);
      }

#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

    static_runner::register_static_suite (runner, *this);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_INLINES_H_

// ----------------------------------------------------------------------------
