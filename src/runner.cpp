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
  runner::runner (const char* top_suite_name)
      : test_node{ "-" }, top_suite_{ top_suite_name, *this }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  runner::~runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    // reporter_ is a unique_ptr; destroyed automatically.
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
  suite&
  runner::initialise (int argc, char* argv[])
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
    if (strcmp (reporter_name, "human") == 0)
      {
        reporter_ = std::make_unique<reporter_human> ();
      }
    else if (strcmp (reporter_name, "tap") == 0)
      {
        reporter_ = std::make_unique<reporter_tap> ();
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
        printf ("\n");

        reporter_->output_comment_prefix ();

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
    reporter_->begin_session (*this);

    top_suite_.timings.timestamp_begin ();
    reporter_->begin_suite (top_suite_);

    return top_suite_;
  }
#pragma GCC diagnostic pop

  // --------------------------------------------------------------------------

  void
  runner::register_suite_ (std::unique_ptr<class suite> suite)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite->name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    children_suites_.push_back (std::move (suite));
  }

  void
  runner::run_suites_ (void)
  {
    for (size_t i = 0; i < children_suites_.size (); ++i)
      {
        class suite* suite = children_suites_[i].get ();

        // Run the child suite immediately.
        suite->run ();

        // Accumulate the totals from the static suite into the runner
        // totals.
        // DO NOT increment executed_subtests here.
        totals += suite->totals;
      }
  }

  void
  runner::run_static_suites_ (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (has_static_suites_ && static_children_suites_ != nullptr)
      {
        for (size_t i = 0; i < static_children_suites_->size (); ++i)
          {
            static_suite* suite = (*static_children_suites_)[i];

            // Update the suite's own index, this is needed for the TAP
            // reporter to report the test number correctly, as the
            // static suites are not registered with the runner, but are
            // run directly.
            suite->update_own_index (suites_count ());

            // Run the child suite immediately.
            suite->run ();

            // Accumulate the totals from the static suite into the runner
            // totals.
            // DO NOT increment executed_subtests here.
            totals += suite->totals;
          }
      }
  }

  int
  runner::exit_code (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    top_suite_.timings.timestamp_end ();
    reporter_->end_suite (top_suite_);
    totals += top_suite_.totals;

    run_suites_ ();
    if (has_static_suites_)
      {
        run_static_suites_ ();
      }

    timings.timestamp_end ();
    reporter_->end_session (*this);

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
  runner::abort (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
    ::abort ();
  }

  size_t
  runner::suites_count (void) const
  {
    return children_suites_.size () + 1;
  }

  size_t
  runner::total_suites_count (void) const
  {
    return suites_count ();
  }

  // ==========================================================================

  static_runner::static_runner (const char* top_suite_name)
      : runner{ top_suite_name }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  static_runner::~static_runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (has_static_suites_ && static_children_suites_ != nullptr)
      {
        // The tests are static, so we do not delete them, but we need to
        // delete the array of pointers.
        delete static_children_suites_;
        static_children_suites_ = nullptr;
      }
  }

  size_t
  static_runner::static_suites_count (void) const
  {
    return has_static_suites_ && static_children_suites_ != nullptr
               ? static_children_suites_->size ()
               : 0;
  }

  size_t
  static_runner::total_suites_count (void) const
  {
    return suites_count () + static_suites_count ();
  }

  void
  static_runner::register_static_suite (static_runner& runner,
                                        static_suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (runner.static_children_suites_ == nullptr)
      {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
        printf ("%s - new array\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
        runner.static_children_suites_ = new std::vector<static_suite*>;
      }
    runner.static_children_suites_->push_back (&suite);

    runner.has_static_suites_ = true;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
