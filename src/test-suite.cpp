/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from <https://opensource.org/licenses/MIT/>.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from <https://www.boost.org/LICENSE_1_0.txt>.
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
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE

    name_ = name;
    // The default test suite needs no registration.
  }

  test_suite_base::~test_suite_base ()
  {
  }

  void
  test_suite_base::run ()
  {
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE
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
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
