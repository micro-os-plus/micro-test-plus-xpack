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
 * @brief C++ source file with implementations for the µTest++ test runner
 * methods.
 *
 * @details
 * This source file contains the core implementations for the test runner
 * facilities of the µTest++ framework. It provides the logic for initialising
 * the test environment, registering and managing test suites, handling
 * command-line arguments, orchestrating test execution, and determining the
 * overall test result. The implementation supports automated discovery and
 * execution of test suites, flexible verbosity control, and robust mechanisms
 * for aborting test execution in critical scenarios.
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
#include <stdlib.h>
#include <vector>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * The constructor initialises a new instance of the `test_runner` class,
   * preparing the test runner for managing test suites and cases within the
   * µTest++ framework. If tracing is enabled, it outputs the function
   * signature for diagnostic purposes. This setup ensures the test runner is
   * ready to coordinate the registration, execution, and reporting of tests
   * across all test cases and folders.
   */
  test_runner::test_runner (const char* top_suite_name)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, top_suite_name);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    // Create the top suite, which is special since it has no callable.
    top_suite_ = new test_suite_top (top_suite_name, *this, 1);
  }

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
  /**
   * @details
   * This method initialises the test runner by capturing the command-line
   * arguments and the default test suite name, configuring the framework for
   * subsequent test execution. It parses the arguments to determine the
   * desired verbosity level (normal, verbose, quiet, or silent) and applies
   * this setting to the test reporter. The method also outputs build and
   * environment information when appropriate, aiding diagnostics and
   * transparency. Finally, it creates and registers the default test suite,
   * preparing the framework to manage and execute all test cases and suites
   * across the project’s folders.
   */
  test_suite_top&
  test_runner::initialise (int argc, char* argv[])
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    argc_ = argc;
    argv_ = argv;

#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) && defined(MICRO_OS_PLUS_TRACE))
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
#endif // defined(MICRO_OS_PLUS_DEBUG)
#endif // !defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

    verbosity_t verbosity = verbosity::normal;
    const char* reporter_name = "tap";
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
        else if (strncmp (argv[i], "--reporter=", 11) == 0)
          {
            reporter_name = argv[i] + 11;
          }
      }

    // Initialize and configure the reporter.
    if (strcmp (reporter_name, "basic") == 0)
      {
        reporter_ = new test_reporter_basic ();
      }
    else if (strcmp (reporter_name, "tap") == 0)
      {
        reporter_ = new test_reporter_tap ();
      }
    else
      {
        fprintf (stderr, "error: unknown reporter '%s'\n", reporter_name);
        exit (1);
      }
    reporter_->verbosity = verbosity;

    // ------------------------------------------------------------------------

#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) && defined(MICRO_OS_PLUS_TRACE))
    if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
      {
        printf ("\n# ");
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
#if !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) \
      || defined(WIN32))
// This is relevant only on bare-metal.
#if defined(__ARM_PCS_VFP) || defined(__ARM_FP)
        printf (", with FP");
#else
        printf (", no FP");
#endif
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
#endif // !defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

    // ------------------------------------------------------------------------

    timings.timestamp_begin ();
    reporter_->begin_test (*this);

    // Begin the top suite here and end it when the first explicit suite is
    // created or at exit.

    top_suite_->timings.timestamp_begin ();
    reporter_->begin_test_suite (*top_suite_);

    return *top_suite_;
  }
#pragma GCC diagnostic pop

  int
  test_runner::exit_code (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, top_suite_->name ());
#pragma GCC diagnostic pop
#endif //

    top_suite ().timings.timestamp_end ();
    reporter_->maybe_end_top_suite (*top_suite_);

    // Accumulate the top suite counters, this is a special suite that
    // is not run explicitly, so was not accounted.
    totals += top_suite_->totals;

    timings.timestamp_end ();
    reporter_->end_test (*this);

    int exit_code = totals.was_successful () ? 0 : 1;

#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s -> %d\n", __PRETTY_FUNCTION__, exit_code);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    return exit_code;
  }

  /**
   * @details
   * This method immediately terminates the process by invoking the standard C
   * library `abort()` function. It is used to halt test execution in critical
   * failure scenarios, ensuring that no further tests are run and that the
   * cause of the failure can be promptly investigated. This approach provides
   * a robust mechanism for enforcing strict test outcomes across all test
   * cases and folders.
   */
  void
  test_runner::abort (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, top_suite_->name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
    ::abort ();
  }

  size_t
  test_runner::test_suites_count (void) const
  {
    return test_suites.size () + 1;
  }

  size_t
  test_runner::total_test_suites_count (void) const
  {
    return test_suites_count ();
  }

  test_runner::~test_runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    for (size_t i = 0; i < test_suites.size (); ++i)
      {
        // The suites are dynamically allocated, so we need to delete them.
        delete test_suites[i];
      }

    delete top_suite_;
    delete reporter_;
  }

  // ==========================================================================

  static_test_runner::static_test_runner (const char* top_suite_name)
      : test_runner (top_suite_name)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, top_suite_name);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  static_test_runner::~static_test_runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (static_test_suites_ != nullptr)
      {
        // The suites are static, so we do not delete them, but we need to
        // delete the array of pointers.
        delete static_test_suites_;
      }
  }

  size_t
  static_test_runner::static_test_suites_count (void) const
  {
    return static_test_suites_ != nullptr ? static_test_suites_->size () : 0;
  }

  size_t
  static_test_runner::total_test_suites_count (void) const
  {
    return test_suites_count () + static_test_suites_count ();
  }

  void
  static_test_runner::register_static_test_suite (
      static_test_runner& runner, static_test_suite& test_suite)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_suite.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (runner.static_test_suites_ == nullptr)
      {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
        printf ("%s - new array\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
        runner.static_test_suites_ = new std::vector<static_test_suite*>;
      }
    runner.static_test_suites_->push_back (&test_suite);
  }

  void
  static_test_runner::run_static_test_suites (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (static_test_suites_ != nullptr)
      {
        for (size_t i = 0; i < static_test_suites_->size (); ++i)
          {
            static_test_suite* test_suite = (*static_test_suites_)[i];

            // Update the test suite's own index, this is needed for the TAP
            // reporter to report the test suite number correctly, as the
            // static test suites are not registered with the runner, but are
            // run directly.
            test_suite->update_own_index (test_suites_count ());

            // Run the child test suite immediately.
            test_suite->run ();

            // Accumulate the totals from the static test suite into the runner
            // totals.
            totals += test_suite->totals;
          }
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
