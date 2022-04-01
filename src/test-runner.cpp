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
  test_runner::initialize (int argc, char* argv[], const char* name)
  {
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE

    argc_ = argc;
    argv_ = argv;

    default_suite_name_ = name;

#if defined(MICRO_OS_PLUS_DEBUG)
    printf ("argv[");
    for (int i = 0; i < argc; ++i)
      {
        if (i > 0)
          {
            printf (", ");
          }
        printf ("'%s'", argv[i]);
      }
    puts ("]");
#endif

    verbosity_t verbosity = verbosity::normal;
    for (int i = 0; i < argc; ++i)
      {
        if (strcmp (argv[i], "--verbose") == 0)
          {
            verbosity = verbosity::verbose;
          }
        else if (strcmp (argv[i], "--quiet") == 0)
          {
            verbosity = verbosity::quiet;
          }
        else if (strcmp (argv[i], "--silent") == 0)
          {
            verbosity = verbosity::silent;
          }
      }

    // Pass the verbosity to the reporter.
    reporter.verbosity = verbosity;

    // ------------------------------------------------------------------------

    if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
      {
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
      }

    // ------------------------------------------------------------------------

    default_test_suite_ = new test_suite (default_suite_name_);
    current_test_suite = default_test_suite_;

    // Deferred to first test case or test suite end, to allow various
    // initialisations to display their messages.
    // default_test_suite_->begin ();
  }

  int
  test_runner::exit_code (void)
  {
    bool was_successful = true;

    if (!default_test_suite_->unused ())
      {
        default_test_suite_->end ();
        was_successful = default_test_suite_->was_successful ();
      }

    if (suites_ != nullptr)
      {
        for (auto suite : *suites_)
          {
            default_test_suite_ = suite;
            suite->run ();

            was_successful &= suite->was_successful ();
          }
      }
    return was_successful ? 0 : 1;
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
