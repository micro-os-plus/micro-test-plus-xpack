/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021 Liviu Ionescu. All rights reserved.
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
 * @file test-suite.cpp
 * @brief Implementation of test suite management for the µTest++ testing
 * framework.
 * @details
 * This source file provides the implementation of the `test_suite_base` and
 * `test_suite` classes, which are responsible for grouping, registering, and
 * executing related test cases within the µTest++ framework.
 *
 * It includes methods for managing test suite state, tracking successful and
 * failed checks, handling the commencement and completion of test cases and
 * suites, and supporting deferred reporting. The implementation ensures that
 * test suites are correctly initialised, executed, and reported, thereby
 * facilitating automated test discovery and execution.
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

  test_suite_base::test_suite_base (const char* name)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    name_ = name;
    // The default test suite needs no registration.
  }

  test_suite_base::~test_suite_base ()
  {
  }

  void
  test_suite_base::run ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  void
  test_suite_base::begin_test_suite (void)
  {
    process_deferred_begin = false;

    reporter.begin_test_suite (name_);
  }

  void
  test_suite_base::end_test_suite (void)
  {
    if (process_deferred_begin)
      {
        begin_test_suite ();
      }
    reporter.end_test_suite (*this);
  }

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

  void
  test_suite_base::end_test_case (void)
  {
    reporter.end_test_case (test_case_name_);
  }

  void
  test_suite_base::increment_successful (void)
  {
    ++successful_checks_;
    ++current_test_case.successful_checks;
  }

  void
  test_suite_base::increment_failed (void)
  {
    ++failed_checks_;
    ++current_test_case.failed_checks;
  }

  // ==========================================================================

  void
  test_suite::run (void)
  {
    // Run the test suite function prepared with std::bin();
    callable_ ();
  }

  test_suite::~test_suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
