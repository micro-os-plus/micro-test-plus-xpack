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

#include <algorithm>

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#if defined(MICRO_OS_PLUS_TRACE)
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_TRACE

#include "micro-os-plus/micro-test-plus/runner.h"
#include "micro-os-plus/micro-test-plus/reporter-tap.h"
#include "micro-os-plus/micro-test-plus/reporter-human.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Performs the `static_runner` to `runner` upcast where both types are
   * complete, allowing headers with only forward declarations to request this
   * conversion safely.
   */
  runner&
  detail::to_runner (static_runner& static_runner_ref) noexcept
  {
    return static_cast<runner&> (static_runner_ref);
  }

  /**
   * @details
   * Performs static-suite registration where `static_runner` is complete,
   * allowing header-only template code to avoid direct dependence on
   * `runner.h` include order.
   */
  void
  detail::register_static_suite (static_runner& static_runner_ref,
                                 static_suite& static_suite_ref)
  {
    static_runner::register_static_suite (static_runner_ref, static_suite_ref);
  }

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
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  /**
   * @details
   * The `reporter_` unique pointer is released automatically. If tracing
   * is enabled, the function signature is output for diagnostic purposes.
   */
  runner::~runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

    // reporter_ is a unique_ptr; destroyed automatically.
  }

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
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

    std::vector<std::string_view> argvs (argv, argv + argc);

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
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  // --------------------------------------------------------------------------

  /**
   * @details
   * Takes ownership of the supplied `suite` unique pointer and appends
   * it to the internal `children_suites_` vector, deferring execution
   * until `run_suites_()` is called. If tracing is enabled, the suite
   * name is logged for diagnostic purposes.
   */
  void
  runner::register_suite_ (std::unique_ptr<class suite> suite)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite->name ());
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    children_suites_.push_back (std::move (suite));
  }

  /**
   * @details
   * Sorts `children_suites_` alphabetically by suite name using a
   * selection sort on `unique_ptr::swap`, avoiding the
   * `-Waggregate-return` diagnostic that `std::sort` would trigger on
   * unique-pointer iterators. Each suite is assigned a 1-based index
   * offset by the top-suite index, executed via `suite::run()`, and its
   * totals are accumulated into the runner totals. The executed-subtest
   * counter is not incremented; suites are not counted as subtests.
   */
  void
  runner::run_suites_ (void)
  {
    // Use selection sort with unique_ptr::swap (returns void) to avoid
    // std::sort triggering -Waggregate-return via std::move_backward,
    // which returns a class-type iterator when operating on unique_ptr
    // elements.
    const size_t n = children_suites_.size ();
    for (size_t i = 0; i < n; ++i)
      {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j)
          {
            if (std::string_view{ children_suites_[j]->name () }
                < std::string_view{ children_suites_[min_idx]->name () })
              min_idx = j;
          }
        if (min_idx != i)
          children_suites_[i].swap (children_suites_[min_idx]);
      }

    for (size_t i = 0; i < n; ++i)
      {
        auto* suite_ptr = children_suites_[i].get ();

        // +1 for 1-based index, +1 for top suite
        suite_ptr->own_index (i + 1 + 1);

        // Run the child suite immediately.
        suite_ptr->run ();

        // Accumulate the totals from the static suite into the runner
        // totals.
        // DO NOT increment executed_subtests here.
        totals_ += suite_ptr->totals ();
      }
  }

  /**
   * @details
   * Finalises the top suite by recording its end timestamp and notifying
   * the reporter, then accumulates its totals into the runner totals.
   * Subsequently invokes `run_suites_()` to sort, execute, and
   * accumulate all registered child suites. Finally, records the session
   * end timestamp, notifies the reporter, and returns `0` if all checks
   * passed or `1` otherwise.
   */
  int
  runner::exit_code (void)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (reporter_ == nullptr)
      {
        fprintf (stderr, "error: test runner not initialised\n");
        return 1;
      }

    top_suite_.timings ().timestamp_end ();
    reporter_->end_suite (top_suite_);
    totals_ += top_suite_.totals ();

    run_suites_ ();

    timings_.timestamp_end ();
    reporter_->end_session (*this);

    const int result = totals_.was_successful () ? 0 : 1;

#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s -> %d\n", __PRETTY_FUNCTION__, result);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
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

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    fprintf (stderr, "\nerror: test execution aborted at %s:%u\n",
             reflection::short_name (sl.file_name ()), sl.line ());
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

    ::abort ();
  }

  /**
   * @details
   * Returns the number of registered child suites plus one, accounting
   * for the top suite.
   */
  size_t
  runner::suites_count (void) const noexcept
  {
    return children_suites_.size () + 1;
  }

  /**
   * @details
   * For the base `runner`, the total suite count equals `suites_count()`,
   * as there are no additional static suites.
   */
  size_t
  runner::total_suites_count (void) const noexcept
  {
    return suites_count ();
  }

  // ==========================================================================

  /**
   * @details
   * Delegates construction to the `runner` base class with the given
   * @p top_suite_name. If tracing is enabled, the function signature
   * and suite name are output for diagnostic purposes.
   */
  static_runner::static_runner (const char* top_suite_name)
      : runner{ top_suite_name }
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  /**
   * @details
   * If `static_children_suites_` is non-null, the dynamically allocated
   * vector of raw pointers is deleted and the pointer is reset to
   * `nullptr`. The pointed-to `static_suite` objects are not deleted,
   * as they are static storage-duration objects. If tracing is enabled,
   * the function signature is output for diagnostic purposes.
   */
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

  /**
   * @details
   * Returns the number of elements in `static_children_suites_`, or
   * zero if the vector has not been allocated yet.
   */
  size_t
  static_runner::static_suites_count (void) const noexcept
  {
    return static_children_suites_ != nullptr
               ? static_children_suites_->size ()
               : 0;
  }

  /**
   * @details
   * Returns the combined count of dynamically registered suites (from
   * the base `runner`) and statically registered suites.
   */
  size_t
  static_runner::total_suites_count (void) const noexcept
  {
    return suites_count () + static_suites_count ();
  }

  /**
   * @details
   * First invokes `runner::run_suites_()` to execute all dynamically
   * registered child suites. If `static_children_suites_` is non-null,
   * its contents are sorted alphabetically by suite name using selection
   * sort on raw pointers, each suite is assigned a 1-based index offset
   * by the dynamic suite count, executed via `suite::run()`, and its
   * totals are accumulated into the runner totals.
   */
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
        // Use selection sort with std::swap on raw pointers (returns void)
        // to avoid std::sort triggering -Waggregate-return via
        // std::move_backward returning a class-type iterator.
        const size_t n = static_children_suites_->size ();
        auto& suites = *static_children_suites_;
        for (size_t i = 0; i < n; ++i)
          {
            size_t min_idx = i;
            for (size_t j = i + 1; j < n; ++j)
              {
                if (std::string_view{ suites[j]->name () }
                    < std::string_view{ suites[min_idx]->name () })
                  min_idx = j;
              }
            if (min_idx != i)
              std::swap (suites[i], suites[min_idx]);
          }

        for (size_t i = 0; i < n; ++i)
          {
            auto* suite_ptr = suites[i];

            suite_ptr->own_index (i + 1 + suites_count ());

            // Run the child suite immediately.
            suite_ptr->run ();

            // Accumulate the totals from the static suite into the runner
            // totals.
            // DO NOT increment executed_subtests here.
            totals_ += suite_ptr->totals ();
          }
      }
  }

  /**
   * @details
   * If `runner.static_children_suites_` is null, a new
   * `std::vector<static_suite*>` is heap-allocated and assigned to it.
   * The address of @p suite is then appended to the vector. This method
   * is intended to be called from the constructor of `static_suite`,
   * before test execution begins.
   */
  void
  static_runner::register_static_suite (static_runner& runner,
                                        static_suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
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
