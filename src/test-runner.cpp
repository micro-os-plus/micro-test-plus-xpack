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
  test_runner::test_runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
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
  void
  test_runner::initialize (int argc, char* argv[], const char* name)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    argc_ = argc;
    argv_ = argv;

    default_suite_name_ = name;

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
        reporter = new test_reporter_basic ();
      }
    else if (strcmp (reporter_name, "tap") == 0)
      {
        reporter = new test_reporter_tap ();
      }
    else
      {
        fprintf (stderr, "error: unknown reporter '%s'\n", reporter_name);
        exit (1);
      }
    reporter->verbosity = verbosity;

    // ------------------------------------------------------------------------

#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) && defined(MICRO_OS_PLUS_TRACE))
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

    default_test_suite_ = new test_suite_base (default_suite_name_);
    current_test_suite = default_test_suite_;

    // Deferred to first test case or test suite end, to allow various
    // initialisations to display their messages.
    // reporter->begin_test (test_suites_count ());
    // default_test_suite_->begin_test_suite ();
  }
#pragma GCC diagnostic pop

  int
  test_runner::exit_code (void)
  {
    bool was_successful = true;

    if (!default_test_suite_->unused ())
      {
        default_test_suite_->end_test_suite ();
        was_successful = default_test_suite_->was_successful ();

        totals.successful_checks += default_test_suite_->successful_checks ();
        totals.failed_checks += default_test_suite_->failed_checks ();
        totals.test_cases_count += default_test_suite_->test_cases_count ();
      }

    if (test_suites != nullptr)
      {
        for (auto test_suite : *test_suites)
          {
            current_test_suite = test_suite;

            test_suite->begin_test_suite ();
            test_suite->run ();
            test_suite->end_test_suite ();

            was_successful &= test_suite->was_successful ();

            totals.successful_checks += test_suite->successful_checks ();
            totals.failed_checks += test_suite->failed_checks ();
            totals.test_cases_count += test_suite->test_cases_count ();
          }
        if (reporter->verbosity != verbosity::silent)
          {
            // printf ("\n");
          }
      }

    reporter->end_test (*this);

    return was_successful ? 0 : 1;
  }

  /**
   * @details
   * This method registers a new test suite with the test runner. If the
   * internal collection of test suites has not yet been created, it is
   * initialised at this point. The provided test suite is then added to the
   * collection, enabling the framework to manage and execute multiple test
   * suites across different files and folders within the project.
   *
   * Called by test suite constructors to register themselves with the
   * runner, enabling automatic management and execution.
   */
  void
  test_runner::register_test_suite (test_suite_base* suite)
  {
#if 0 // defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (test_suites == nullptr)
      {
        test_suites = new std::vector<test_suite_base*> ();
      }
    test_suites->push_back (suite);
    suite->index = test_suites->size () + 1;
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
    ::abort ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
