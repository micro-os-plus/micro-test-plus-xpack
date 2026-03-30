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
 * @brief C++ source file with implementations for the µTest++ test case
 * methods.
 *
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

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * The constructor initialises a new instance of the `test_case_base` class
   * with the specified name. It sets up the internal state required for
   * managing test cases within the suite. If tracing is enabled, the function
   * signature is output for diagnostic purposes. The default test suite does
   * not require explicit registration, ensuring seamless integration within
   * the µTest++ framework and supporting organised test management across all
   * files and folders.
   */
  test_case_base::test_case_base (const char* name,
                                  test_suite_base& test_suite,
                                  size_t own_index, size_t nesting_depth)
      : own_index_{ own_index }, test_suite_{ test_suite },
        nesting_depth_{ nesting_depth }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu %zu %zu\n", __PRETTY_FUNCTION__, name, own_index,
            nesting_depth, nesting_depth_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    name_ = name;
  }

  /**
   * @details
   * The destructor releases any resources associated with the
   * `test_case_base` instance. It ensures that the test case is properly
   * cleaned up after execution, supporting robust and reliable test management
   * across all files and folders within the µTest++ framework.
   */
  test_case_base::~test_case_base ()
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

  [[nodiscard]] test_reporter&
  test_case_base::reporter ()
  {
    return test_suite_.reporter ();
  }

  // ==========================================================================

  /**
   * @details
   * This method executes the test suite by invoking the stored callable object
   * associated with the suite. It ensures that all test cases registered
   * within the suite are executed in sequence, supporting comprehensive and
   * structured testing across all files and folders within the µTest++
   * framework.
   */
  void
  test_case_callable::run (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    test_reporter& reporter = this->reporter ();

    reporter.begin_test_case (*this);
    // Run the test case callable prepared with std::bind();
    callable_ (*this);
    reporter.end_test_case (*this);
  }

  /**
   * @details
   * The destructor releases any resources associated with the `test_suite`
   * instance. If tracing is enabled, it outputs the function signature for
   * diagnostic purposes. This ensures that the test suite is properly cleaned
   * up after execution, supporting robust and reliable test management across
   * all files and folders within the µTest++ framework.
   */
  test_case_callable::~test_case_callable ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
