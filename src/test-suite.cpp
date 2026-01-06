/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
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
  test_suite_base::test_suite_base (const char* name)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    name_ = name;
    // The default test suite needs no registration.
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
  test_suite_base::run ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  /**
   * @details
   * This method marks the beginning of a test suite's execution. It resets the
   * deferred begin flag and notifies the test reporter to start the suite,
   * passing the suite's name. This ensures that test suite output is clearly
   * delineated and properly initialised, supporting organised and readable
   * reporting across all test cases and folders.
   */
  void
  test_suite_base::begin_test_suite (void)
  {
    process_deferred_begin = false;

    reporter.begin_test_suite (name_);
  }

  /**
   * @details
   * This method marks the end of a test suite's execution. If the suite's
   * start was deferred, it ensures the suite is properly begun before
   * finalising. The method then notifies the test reporter to conclude the
   * suite, passing a reference to the suite instance. This guarantees that all
   * results are accurately summarised and reported, supporting clear and
   * organised test management across all test cases and folders.
   */
  void
  test_suite_base::end_test_suite (void)
  {
    if (process_deferred_begin)
      {
        begin_test_suite ();
      }
    reporter.end_test_suite (*this);
  }

  /**
   * @details
   * This method marks the beginning of a test case within the suite. If the
   * start of the suite was deferred, it ensures the suite is properly begun
   * before proceeding. The method sets the current test case name, increments
   * the total number of test cases, resets the current test case statistics,
   * and notifies the test reporter to begin the test case. This approach
   * guarantees that each test case is clearly identified, accurately tracked,
   * and properly reported across all test cases and folders.
   */
  void
  test_suite_base::begin_test_case (const char* name)
  {
    if (process_deferred_begin)
      {
        begin_test_suite ();
      }

    test_case_name_ = name;
    ++test_cases_;

    current_test_case = {};

    reporter.begin_test_case (test_case_name_);
  }

  /**
   * @details
   * This method marks the end of a test case within the suite. It notifies the
   * test reporter to conclude the test case, passing the current test case
   * name. This ensures that the results of the test case are accurately
   * finalised and clearly reported, supporting organised and reliable test
   * management across all test cases and folders.
   */
  void
  test_suite_base::end_test_case (void)
  {
    reporter.end_test_case (test_case_name_);
  }

  /**
   * @details
   * This method increments the count of successful checks for the test suite
   * and the current test case. It ensures that each passing assertion is
   * accurately recorded, supporting precise tracking and reporting of test
   * outcomes across all test cases and folders.
   */
  void
  test_suite_base::increment_successful (void)
  {
    ++successful_checks_;
    ++current_test_case.successful_checks;
  }

  /**
   * @details
   * This method increments the count of failed checks for the test suite and
   * the current test case. It ensures that each failing assertion is
   * accurately recorded, supporting precise tracking and reporting of test
   * outcomes across all test cases and folders.
   */
  void
  test_suite_base::increment_failed (void)
  {
    ++failed_checks_;
    ++current_test_case.failed_checks;
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
  test_suite::run (void)
  {
    // Run the test suite function prepared with std::bin();
    callable_ ();
  }

  /**
   * @details
   * The destructor releases any resources associated with the `test_suite`
   * instance. If tracing is enabled, it outputs the function signature for
   * diagnostic purposes. This ensures that the test suite is properly cleaned
   * up after execution, supporting robust and reliable test management across
   * all files and folders within the µTest++ framework.
   */
  test_suite::~test_suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
