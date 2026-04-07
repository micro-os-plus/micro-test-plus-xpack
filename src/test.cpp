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

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#include <stdio.h>

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#else // GCC only
#pragma GCC diagnostic ignored "-Wredundant-tags"
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif

// ==========================================================================

namespace micro_os_plus::micro_test_plus
{
  // ==========================================================================

  test_node::test_node (const char* name) : name_{ name }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  test_node::~test_node ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  // ==========================================================================

  /**
   * @details
   * The constructor initialises a new instance of the `runnable_base` class
   * with the specified name. It sets up the internal state required for
   * managing test cases within the suite. If tracing is enabled, the function
   * signature is output for diagnostic purposes. The default test suite does
   * not require explicit registration, ensuring seamless integration within
   * the µTest++ framework and supporting organised test management across all
   * files and folders.
   */
  runnable_base::runnable_base (const char* name, class runner& runner,
                                size_t own_index)
      : test_node{ name }, runner_{ runner }, own_index_{ own_index }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  /**
   * @details
   * The destructor releases any resources associated with the
   * `runnable_base` instance. It ensures that the test suite is properly
   * cleaned up after execution, supporting robust and reliable test management
   * across all files and folders within the µTest++ framework.
   */
  runnable_base::~runnable_base ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

    // children_subtests_ holds unique_ptrs; destroyed automatically.
  }

  [[nodiscard]] reporter&
  runnable_base::reporter (void) const
  {
    return runner_.reporter ();
  }

  void
  runnable_base::after_subtest_create (
      std::unique_ptr<class subtest> child_test, suite& suite)
  {
    // Transfer ownership into the vector.
    children_subtests_.push_back (std::move (child_test));

    // Run the child test case immediately.
    class subtest& subtest = *children_subtests_.back ();
    subtest.run ();

    // Accumulate the totals from the child test into the suite totals.
    suite.totals ().increment_executed_subtests ();
    suite.totals () += subtest.totals ();
  }

  // ==========================================================================

  /**
   * @details
   * The destructor releases any resources associated with the
   * `test` instance. If tracing is enabled, it outputs the
   * function signature for diagnostic purposes. This ensures that the test
   * suite is properly cleaned up after execution, supporting robust and
   * reliable test management across all files and folders within the µTest++
   * framework.
   */
  subtest::~subtest ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
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
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    class reporter& reporter = this->reporter ();

    // this->timings.timestamp_begin ();
    reporter.begin_subtest (*this);

    // Invoke the callable, passing the self reference followed by the variadic
    // arguments.
    callable_ (*this);

    // this->timings.timestamp_end ();
    reporter.end_subtest (*this);
  }

  // ==========================================================================

  suite::~suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
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
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
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

  top_suite::top_suite (const char* name, class runner& runner)
      : suite{ name, runner, 1, [] (suite&) noexcept {} }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  top_suite::~top_suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  // ==========================================================================

  static_suite::~static_suite ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  void
  static_suite::update_own_index (size_t offset)
  {
    own_index_ += offset;

#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s own index -> %zu\n", __PRETTY_FUNCTION__, own_index_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  void
  static_suite::run (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#pragma GCC diagnostic pop
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
