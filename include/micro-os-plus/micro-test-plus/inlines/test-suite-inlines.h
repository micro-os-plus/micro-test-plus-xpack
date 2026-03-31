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

#ifndef MICRO_TEST_PLUS_TEST_SUITE_INLINES_H_
#define MICRO_TEST_PLUS_TEST_SUITE_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <cstring>
// #include "test-runner.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#else
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  // extern test_runner runner;

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns the test reporter reference.
   */
  inline test_reporter&
  test_suite_base::reporter (void)
  {
    return runner_.reporter ();
  }

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
  test_suite_callable_common<Self_T>::test_suite_callable_common (
      const char* name, class runner& runner, size_t own_index,
      Callable_T&& callable, Args_T&&... arguments)
      : test_suite_base{ name, runner, own_index },
        callable_{ std::bind (std::forward<Callable_T> (callable),
                              std::placeholders::_1,
                              std::forward<Args_T> (arguments)...) }
  {
  }

  template <typename Self_T>
  test_suite_callable_common<Self_T>::~test_suite_callable_common ()
  {
  }

  /**
   * @details
   * Invokes the stored callable with the `Self_T` instance, surrounded by
   * reporter calls to begin and end the test suite.
   */
  template <typename Self_T>
  void
  test_suite_callable_common<Self_T>::run (void)
  {
    test_reporter& reporter = this->reporter ();

    this->runner ().top_suite ().timings.timestamp_end ();
    reporter.maybe_end_top_suite (this->runner ().top_suite ());

    this->timings.timestamp_begin ();
    reporter.begin_test_suite (*this);

    // Invoke the callable, passing the derived Self_T reference.
    callable_ (static_cast<Self_T&> (*this));

    this->timings.timestamp_end ();
    reporter.end_test_suite (*this);
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Delegates to `test_suite_callable_common`, which binds the callable with
   * its arguments.
   */
  template <typename Callable_T, typename... Args_T>
  test_suite_callable::test_suite_callable (const char* name,
                                            class runner& runner,
                                            size_t own_index,
                                            Callable_T&& callable,
                                            Args_T&&... arguments)
      : test_suite_callable_common<test_suite_callable>{
          name, runner, own_index, std::forward<Callable_T> (callable),
          std::forward<Args_T> (arguments)...
        }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  template <typename Callable_T, typename... Args_T>
  void
  test_suite_base::test_case (const char* name, Callable_T&& callable,
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

    size_t own_index = increment_child_index ();
    auto* child_test_case = new test_case_callable (
        name, *this, own_index, 1, std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...);

    // Remember test cases to delete them at the end.
    test_cases_.push_back (child_test_case);

    // Run the child test case immediately.
    child_test_case->run ();

    // Accumulate the totals from the child test case into the test suite
    // totals.
    totals += child_test_case->totals;
    totals.increment_executed_test_cases ();

    // Does not need to return the test case reference, as it is passed to
    // the callable and can be accessed there.
  }

  // ==========================================================================

  /**
   * @details
   * Delegates to `test_suite_callable_common`, which binds the callable with
   * its arguments. After construction, the suite is registered with the
   * static test runner.
   */
  template <typename Callable_T, typename... Args_T>
  static_test_suite::static_test_suite (const char* name,
                                        static_runner& runner,
                                        Callable_T&& callable,
                                        Args_T&&... arguments)
      : test_suite_callable_common<static_test_suite>{
          name, runner, runner.static_test_suites_count () + 1,
          std::forward<Callable_T> (callable),
          std::forward<Args_T> (arguments)...
        }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    static_runner::register_static_test_suite (runner, *this);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_SUITE_INLINES_H_

// ----------------------------------------------------------------------------
