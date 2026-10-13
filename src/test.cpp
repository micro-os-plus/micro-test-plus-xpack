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
 * @brief C++ source file with implementations for the µTest++ test
 * hierarchy methods.
 *
 * @details
 * This source file contains the non-template implementations for the test
 * hierarchy of the µTest++ framework: the constructors and destructors, the
 * `run()` methods of the subtests and suites, which call the reporter
 * before and after invoking the stored callable, and the registration of
 * the child subtests, including the accumulation of their totals.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/test.h"
#include "micro-os-plus/micro-test-plus/runner.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#else // GCC only
#pragma GCC diagnostic ignored "-Wredundant-tags"
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

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
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
    }

    /**
     * @details
     * No resources are owned by `test_node`; the destructor performs no
     * explicit clean-up. If tracing is enabled, the node name is output
     * for diagnostic purposes.
     */
    test_node::~test_node ()
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
    }

    // ========================================================================

    /**
     * @details
     * The constructor initialises a new instance of the `runnable_base` class
     * with the specified name, runner reference, and own index; the child
     * test point index starts at zero and the children collection is empty.
     * If tracing is enabled, the function signature is output for
     * diagnostic purposes.
     */
    runnable_base::runnable_base (const char* name, class runner& runner,
                                  size_t own_index)
        : test_node{ name }, runner_{ runner }, own_index_{ own_index }
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
    }

    /**
     * @details
     * The destructor destroys the owned child subtests, held by
     * `std::unique_ptr` in `children_subtests_`. If tracing is enabled, the
     * name is output for diagnostic purposes.
     */
    runnable_base::~runnable_base ()
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

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
     * The parent's executed-subtest counter is then incremented, and, if
     * the child failed (a failed check, or a failed nested subtest), its
     * failed-subtest counter too, so that the parent fails as well, as in
     * node-tap. The child's check counters are intentionally not merged
     * into the parent totals; each subtest reports only its own counters.
     * The child's totals are, however, accumulated into @p suite so that
     * the suite summary reflects all checks performed by its subtests.
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
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s subtest '%s' executed one more subtest\n",
                     __PRETTY_FUNCTION__, name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
      totals ().increment_executed_subtests ();

      // Do not accumulate the totals from the child test into the current test
      // totals, each subtest shows only its counters. But a failed child
      // fails this test too, as in node-tap; the failure reaches all outer
      // tests, one level at a time, when they end.
      if (!subtest.totals ().was_successful ())
        {
          totals ().increment_failed_subtests ();
        }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s suite '%s' totals\n", __PRETTY_FUNCTION__,
                     suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

      // Accumulate the totals from the child test into the suite totals.
      suite.totals () += subtest.totals ();
    }
  } // namespace detail

  // ==========================================================================

  /**
   * @details
   * No resources are owned directly by `subtest`; the nested subtests are
   * destroyed by the base class. If tracing is enabled, the name is output
   * for diagnostic purposes.
   */
  subtest::~subtest ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * Invokes the stored callable with the `Self_T` instance, surrounded by
   * reporter calls to begin and end the subtest.
   */
  void
  subtest::run (void)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

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
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * Invokes the stored callable with the `Self_T` instance, surrounded by
   * reporter calls to begin and end the suite.
   */
  void
  suite::run (void)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

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
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

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
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
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
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
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
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

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

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
