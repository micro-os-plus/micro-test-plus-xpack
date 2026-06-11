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
 * @brief C++ source file with implementations for the µTest++ test suite
 * methods.
 *
 * @details
 * This source file contains the core implementations for the test suite
 * facilities of the µTest++ framework. It provides the logic for constructing,
 * registering, and managing test suites and their associated test cases. The
 * implementation covers initialisation and clean-up routines, execution of
 * test suites and test cases, tracking of successful and failed checks, and
 * integration with the test reporter for structured output.
 *
 * The design ensures that test suites are non-copyable and non-movable,
 * maintaining unique ownership and consistent state. Flexible support for
 * callable objects enables a wide range of test suite definitions,
 * facilitating expressive and maintainable test organisation across embedded
 * and general C++ projects.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if __has_include(<micro-os-plus/project-config.h>)
#include <micro-os-plus/project-config.h>
#elif __has_include(<micro-os-plus/config.h>)
#pragma message "micro-os-plus/config.h is deprecated, rename to micro-os-plus/project-config.h and include it instead of micro-os-plus/config.h"
#include <micro-os-plus/config.h>
#endif // __has_include(<micro-os-plus/project-config.h>)

#if defined(MICRO_OS_PLUS_TRACE)
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_TRACE

#include "micro-os-plus/micro-test-plus/test.h"
#include "micro-os-plus/micro-test-plus/runner.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#else // GCC only
#pragma GCC diagnostic ignored "-Wredundant-tags"
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  namespace detail
  {
    // ========================================================================

    /**
     * @details
     * Stores the supplied @p name pointer, which is expected to point to
     * a string with a lifetime exceeding that of this instance. If
     * tracing is enabled, the name is output for diagnostic purposes.
     */
    test_node::test_node (const char* name) : name_{ name }
    {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
      trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
    }

    /**
     * @details
     * No resources are owned by `test_node`; the destructor performs no
     * explicit clean-up. If tracing is enabled, the node name is output
     * for diagnostic purposes.
     */
    test_node::~test_node ()
    {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
      trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
    }

    // ========================================================================

    /**
     * @details
     * The constructor initialises a new instance of the `runnable_base` class
     * with the specified name. It sets up the internal state required for
     * managing test cases within the suite. If tracing is enabled, the
     * function signature is output for diagnostic purposes. The default test
     * suite does not require explicit registration, ensuring seamless
     * integration within the µTest++ framework and supporting organised test
     * management across all files and folders.
     */
    runnable_base::runnable_base (const char* name, class runner& runner,
                                  size_t own_index)
        : test_node{ name }, runner_{ runner }, own_index_{ own_index }
    {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
      trace::printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
    }

    /**
     * @details
     * The destructor releases any resources associated with the
     * `runnable_base` instance. It ensures that the test suite is properly
     * cleaned up after execution, supporting robust and reliable test
     * management across all files and folders within the µTest++ framework.
     */
    runnable_base::~runnable_base ()
    {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
      trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

      // children_subtests_ holds unique_ptrs; destroyed automatically.
    }

    /**
     * @details
     * Delegates immediately to `runner_.reporter()`, returning the
     * reporter associated with the owning runner instance.
     */
    [[nodiscard]] reporter&
    runnable_base::reporter (void) const noexcept
    {
      return runner_.reporter ();
    }

    /**
     * @details
     * Delegates immediately to `runner_.abort()`, passing the supplied
     * source location so that the error message identifies the call site
     * before the process is terminated via `::abort()`.
     */
    [[noreturn]] void
    runnable_base::abort (const reflection::source_location& sl)
    {
      runner_.abort (sl);
    }

    /**
     * @details
     * Transfers ownership of @p child_test into `children_subtests_` and
     * immediately invokes `subtest::run()` on the newly stored subtest.
     * The parent's executed-subtest counter is then incremented. The
     * child's check counters are intentionally not merged into the parent
     * totals; each subtest reports only its own counters. The child's
     * totals are, however, accumulated into @p suite so that the suite
     * summary reflects all checks performed by its subtests.
     */
    void
    runnable_base::after_subtest_create_ (
        std::unique_ptr<class subtest> child_test, suite& suite)
    {
      // Transfer ownership into the vector.
      children_subtests_.push_back (std::move (child_test));

      // Run the child test case immediately.
      class subtest& subtest = *children_subtests_.back ();
      subtest.run ();

      // This test executed one more subtest.
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
      trace::printf ("%s subtest '%s' executed one more subtest\n",
                     __PRETTY_FUNCTION__, name ());
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
      totals ().increment_executed_subtests ();
      // Do not accumulate the totals from the child test into the current test
      // totals, each subtest shows only its counters.

#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
      trace::printf ("%s suite '%s' totals\n", __PRETTY_FUNCTION__,
                     suite.name ());
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

      // Accumulate the totals from the child test into the suite totals.
      suite.totals () += subtest.totals ();
    }
  } // namespace detail

  // ==========================================================================

  /**
   * @details
   * The destructor releases any resources associated with the
   * `subtest` instance. If tracing is enabled, it outputs the
   * function signature for diagnostic purposes. This ensures that the test
   * suite is properly cleaned up after execution, supporting robust and
   * reliable test management across all files and folders within the µTest++
   * framework.
   */
  subtest::~subtest ()
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  /**
   * @details
   * Invokes the stored callable with the `Self_T` instance, surrounded by
   * reporter calls to begin and end the subtest.
   */
  void
  subtest::run (void)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    class reporter& reporter = this->reporter ();

    // For now, subtests do not record the time.
    // this->timings.timestamp_begin ();
    reporter.begin_subtest (*this);

    // Invoke the callable, passing the self reference followed by the variadic
    // arguments.
    callable_ (*this);

    // this->timings.timestamp_end ();
    reporter.end_subtest (*this);
  }

  // ==========================================================================

  /**
   * @details
   * No resources are owned directly by `suite`; the destructor performs
   * no explicit clean-up. If tracing is enabled, the suite name is
   * output for diagnostic purposes.
   */
  suite::~suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  /**
   * @details
   * Invokes the stored callable with the `Self_T` instance, surrounded by
   * reporter calls to begin and end the suite.
   */
  void
  suite::run (void)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    class reporter& reporter = this->reporter ();

    this->timings ().timestamp_begin ();
    reporter.begin_suite (*this);

    // Invoke the callable, passing the self reference followed by the variadic
    // arguments.
    callable_ (*this);

    this->timings ().timestamp_end ();
    reporter.end_suite (*this);
  }

  // ==========================================================================

  /**
   * @details
   * Initialises the base `suite` with @p name, the given @p runner, and
   * a no-op callable. Sets `own_index` to 1, reserving index 0 for the
   * runner itself. If tracing is enabled, the name is output for
   * diagnostic purposes.
   */
  top_suite::top_suite (const char* name, class runner& runner)
      : suite{ name, runner, [] (suite&) noexcept {} }
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

    own_index (1);
  }

  /**
   * @details
   * No resources are owned directly by `top_suite`; the destructor
   * performs no explicit clean-up. If tracing is enabled, the suite
   * name is output for diagnostic purposes.
   */
  top_suite::~top_suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  // ==========================================================================

  /**
   * @details
   * No resources are owned directly by `static_suite`; the destructor
   * performs no explicit clean-up. If tracing is enabled, the suite
   * name is output for diagnostic purposes.
   */
  static_suite::~static_suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  /**
   * @details
   * Records the suite begin timestamp, notifies the reporter via
   * `begin_suite()`, invokes the stored static callable with `*this`,
   * records the suite end timestamp, and notifies the reporter via
   * `end_suite()`.
   */
  void
  static_suite::run (void)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    class reporter& reporter = this->reporter ();

    this->timings ().timestamp_begin ();
    reporter.begin_suite (*this);

    static_callable_ (*this);

    this->timings ().timestamp_end ();
    reporter.end_suite (*this);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
