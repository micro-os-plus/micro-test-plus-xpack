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

#include <vector>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  test_runner::test_runner ()
  {
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE
  }

  void
  test_runner::initialize (const char* name, int argc, char* argv[])
  {
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE

    default_suite_name_ = name;

    this->argc_ = argc;
    this->argv_ = argv;

#if defined(__clang__)
    printf ("Built with clang " __VERSION__);
#elif defined(__GNUC__)
    printf ("Built with GCC " __VERSION__);
#elif defined(_MSC_VER)
    // https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170
    printf ("Built with MSVC %d", _MSC_VER);
#else
    printf ("Built with an unknown compiler");
#endif
#if defined(__ARM_PCS_VFP)
    printf (", with FP");
#else
    printf (", no FP");
#endif
#if defined(__EXCEPTIONS)
    printf (", with exceptions");
#else
    printf (", no exceptions");
#endif
#if defined(MICRO_OS_PLUS_DEBUG)
    printf (", with MICRO_OS_PLUS_DEBUG");
#endif
    puts (".");

#if defined(MICRO_OS_PLUS_DEBUG)
    printf ("argv[] = ");
    for (int i = 0; i < argc; ++i)
      {
        printf ("'%s' ", argv[i]);
      }
    puts ("");
#endif

    default_test_suite_ = new test_suite (default_suite_name_);

    default_test_suite_->begin ();
  }

  int
  test_runner::exit_code (void)
  {
    default_test_suite_->end ();

    bool success = default_test_suite_->success ();

    if (suites_ != nullptr)
      {
        for (auto suite : *suites_)
          {
            default_test_suite_ = suite;
            suite->run ();

            success &= suite->success ();
          }
      }
    return success ? 0 : 1;
  }

  void
  test_runner::register_test_suite (test_suite* suite)
  {
#if 0 // defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE

    if (suites_ == nullptr)
      {
        suites_ = new std::vector<test_suite*> ();
      }
    suites_->push_back (suite);
  }

  void
  test_runner::abort (void)
  {
    ::abort ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
