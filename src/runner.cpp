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
#include <micro-os-plus/diag/trace.h>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
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
      : test_node{ "runner" }, top_suite_{ top_suite_name, *this }
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  runner::~runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

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
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) && defined(MICRO_OS_PLUS_TRACE))
#if defined(MICRO_OS_PLUS_DEBUG)
    trace::printf ("argv[");
    for (int i = 0; i < argc; ++i)
      {
        if (i > 0)
          {
            trace::printf (", ");
          }
        trace::printf ("'%s'", argv[i]);
      }
    trace::puts ("]");
#endif // defined(MICRO_OS_PLUS_DEBUG)
#endif // !defined(MICRO_OS_PLUS_INCLUDE_STARTUP)

    std::vector<std::string_view> argvs (static_cast<size_t> (argc));
    for (size_t i = 0; i < static_cast<size_t> (argc); ++i)
      {
        argvs[i] = argv[i];
      }

    std::string_view reporter_name{ "tap" };
    static constexpr std::string_view reporter_prefix{ "--reporter=" };
    for (size_t i = 0; i < argvs.size (); ++i)
      {
        if (argvs[i].starts_with (reporter_prefix))
          {
            reporter_name = argvs[i].substr (reporter_prefix.size ());
          }
        else if (argvs[i]
                 == reporter_prefix.substr (0, reporter_prefix.size () - 1))
          {
            if (i + 1 < argvs.size ())
              {
                reporter_name = argvs[++i];
              }
            else
              {
                fprintf (stderr, "error: --reporter option requires a "
                                 "reporter name argument\n");
                exit (1);
              }
          }
      }

    // Initialise and configure the reporter.
    if (reporter_name == "human")
      {
        reporter_ = std::make_unique<reporter_human> (
            std::make_unique<std::vector<std::string_view>> (
                std::move (argvs)));
      }
    else if (reporter_name == "tap")
      {
        reporter_ = std::make_unique<reporter_tap> (
            std::make_unique<std::vector<std::string_view>> (
                std::move (argvs)));
      }
    else
      {
        fprintf (stderr, "error: unknown reporter '%.*s'\n",
                 static_cast<int> (reporter_name.size ()),
                 reporter_name.data ());
        exit (1);
      }

    // ------------------------------------------------------------------------

    timings_.timestamp_begin ();
    reporter_->begin_session (*this);

    top_suite_.timings ().timestamp_begin ();
    reporter_->begin_suite (top_suite_);

    return top_suite_;
  }
#pragma GCC diagnostic pop

  // --------------------------------------------------------------------------

  void
  runner::register_suite_ (std::unique_ptr<class suite> suite)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite->name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    children_suites_.push_back (std::move (suite));
  }

  void
  runner::run_suites_ (void)
  {
    std::sort (children_suites_.begin (), children_suites_.end (),
               [] (const std::unique_ptr<class suite>& a,
                   const std::unique_ptr<class suite>& b) noexcept
      {
        return std::string_view{ a->name () } < std::string_view{ b->name () };
      });

    for (const auto& suite_ref : children_suites_)
      {
        // Run the child suite immediately.
        suite_ref->run ();

        // Accumulate the totals from the static suite into the runner
        // totals.
        // DO NOT increment executed_subtests here.
        totals_ += suite_ref->totals ();
      }
  }

  int
  runner::exit_code (void)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    top_suite_.timings ().timestamp_end ();
    reporter_->end_suite (top_suite_);
    totals_ += top_suite_.totals ();

    run_suites_ ();

    timings_.timestamp_end ();
    reporter_->end_session (*this);

    const int result = totals_.was_successful () ? 0 : 1;

#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf ("%s -> %d\n", __PRETTY_FUNCTION__, result);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    return result;
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
  runner::abort (const reflection::source_location& sl)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    fprintf (stderr, "\nerror: test execution aborted at %s:%u\n",
             reflection::short_name (sl.file_name ()), sl.line ());
#pragma GCC diagnostic pop

    ::abort ();
  }

  size_t
  runner::suites_count (void) const noexcept
  {
    return children_suites_.size () + 1;
  }

  size_t
  runner::total_suites_count (void) const noexcept
  {
    return suites_count ();
  }

  // ==========================================================================

  static_runner::static_runner (const char* top_suite_name)
      : runner{ top_suite_name }
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  static_runner::~static_runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

    if (static_children_suites_ != nullptr)
      {
        // The tests are static, so we do not delete them, but we need to
        // delete the array of pointers.
        delete static_children_suites_;
        static_children_suites_ = nullptr;
      }
  }

  size_t
  static_runner::static_suites_count (void) const noexcept
  {
    return static_children_suites_ != nullptr
               ? static_children_suites_->size ()
               : 0;
  }

  size_t
  static_runner::total_suites_count (void) const noexcept
  {
    return suites_count () + static_suites_count ();
  }

  void
  static_runner::run_suites_ (void)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    runner::run_suites_ ();

    if (static_children_suites_ != nullptr)
      {
        std::sort (static_children_suites_->begin (),
                   static_children_suites_->end (),
                   [] (const static_suite* a, const static_suite* b) noexcept
          {
            return std::string_view{ a->name () }
                   < std::string_view{ b->name () };
          });

        for (auto* suite_ptr : *static_children_suites_)
          {
            // Update the suite's own index, this is needed for the TAP
            // reporter to report the test number correctly, as the
            // static suites are not registered with the runner, but are
            // run directly.
            suite_ptr->update_own_index (suites_count ());

            // Run the child suite immediately.
            suite_ptr->run ();

            // Accumulate the totals from the static suite into the runner
            // totals.
            // DO NOT increment executed_subtests here.
            totals_ += suite_ptr->totals ();
          }
      }
  }

  void
  static_runner::register_static_suite (static_runner& runner,
                                        static_suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (runner.static_children_suites_ == nullptr)
      {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
        trace::printf ("%s new static_children_suites_ array\n",
                       __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
        runner.static_children_suites_ = new std::vector<static_suite*>;
      }
    runner.static_children_suites_->push_back (&suite);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
