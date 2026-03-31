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
 * @brief C++ source file with implementations for the µTest++ test suite
 * methods.
 *
 * @details
 * This source file contains the core implementations for the test suite
 * facilities of the µTest++ framework. It provides the logic for constructing,
 * registering, and managing test suites and their associated test cases. The
 * implementation covers initialisation and clean-up routines, execution of
 * test suites and test cases, tracking of successful and failed checks, and
 * integration with the test reporter for structured output.
 *
 * The design ensures that test suites are non-copyable and non-movable,
 * maintaining unique ownership and consistent state. Flexible support for
 * callable objects enables a wide range of test suite definitions,
 * facilitating expressive and maintainable test organisation across embedded
 * and general C++ projects.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#include <stdio.h>

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

// ==========================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * The constructor initialises a new instance of the `test_suite_base` class
   * with the specified name. It sets up the internal state required for
   * managing test cases within the suite. If tracing is enabled, the function
   * signature is output for diagnostic purposes. The default test suite does
   * not require explicit registration, ensuring seamless integration within
   * the µTest++ framework and supporting organised test management across all
   * files and folders.
   */
  test_suite_base::test_suite_base (const char* name, class runner& runner,
                                    size_t own_index)
      : own_index_{ own_index }, runner_{ runner }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    name_ = name;
  }

  /**
   * @details
   * The destructor releases any resources associated with the
   * `test_suite_base` instance. It ensures that the test suite is properly
   * cleaned up after execution, supporting robust and reliable test management
   * across all files and folders within the µTest++ framework.
   */
  test_suite_base::~test_suite_base ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    for (size_t i = 0; i < test_cases_.size (); ++i)
      {
        delete test_cases_[i];
      }
  }

  // ==========================================================================

  test_suite_top::test_suite_top (const char* name, class runner& runner,
                                  size_t own_index)
      : test_suite_base{ name, runner, own_index }
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

  /**
   * @details
   * The destructor releases any resources associated with the `test_suite_top`
   * instance. If tracing is enabled, it outputs the function signature for
   * diagnostic purposes. This ensures that the test suite is properly cleaned
   * up after execution, supporting robust and reliable test management across
   * all files and folders within the µTest++ framework.
   */
  test_suite_top::~test_suite_top ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  /**
   * @details
   * This method executes the test suite by invoking its associated callable
   * object. If tracing is enabled, the function signature is output for
   * diagnostic purposes. The method ensures that all test cases grouped within
   * the suite are executed in an organised manner, supporting comprehensive
   * and structured testing across all files and folders within the µTest++
   * framework.
   */
  void
  test_suite_top::run ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' nop\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    // Should not be called, the top suite has no callable, so abort.
    abort ();
  }

  // ==========================================================================

  /**
   * @details
   * The destructor releases any resources associated with the
   * `test_suite_callable` instance. If tracing is enabled, it outputs the
   * function signature for diagnostic purposes. This ensures that the test
   * suite is properly cleaned up after execution, supporting robust and
   * reliable test management across all files and folders within the µTest++
   * framework.
   */
  test_suite_callable::~test_suite_callable ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  // ==========================================================================

  static_test_suite::~static_test_suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  void
  static_test_suite::update_own_index (size_t offset)
  {
    own_index_ += offset;

#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s own index -> %zu\n", __PRETTY_FUNCTION__, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
