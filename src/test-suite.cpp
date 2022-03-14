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

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
//#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  test_suite::test_suite (const char* name)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    name_ = name;
    // callable_ = [] {};

    // The default test suite needs no registration.
  }

  void
  test_suite::run ()
  {
    if (callable_ != nullptr)
      {
        begin ();
        callable_ ();
        end ();
      }
  }

  void
  test_suite::begin (void)
  {
    current_test_suite = this;

    reporter.begin_test_suite (name_);
  }

  void
  test_suite::end (void)
  {
    reporter.end_test_suite (*this);
  }

  void
  test_suite::begin_test_case (const char* name)
  {
    test_case_name_ = name;
    ++test_cases_;

    reporter.begin_test_case (test_case_name_);
  }

  void
  test_suite::end_test_case (void)
  {
    reporter.end_test_case (test_case_name_);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
