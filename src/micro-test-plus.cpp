/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ source file with implementations for the µTest++ methods.
 *
 * @details
 * This source file contains the core implementations for the µTest++ testing
 * framework, including initialisation and shutdown routines, utility
 * functions, and the management of global framework state. It provides the
 * logic for setting up the test environment, registering and executing test
 * suites, reporting results, and supporting utility operations such as file
 * name extraction and pattern-based string matching.
 *
 * All definitions are contained within the `micro_os_plus::micro_test_plus`
 * namespace and its nested namespaces, ensuring clear separation from user
 * code and minimising the risk of naming conflicts.
 *
 * The implementation is optimised for embedded environments, avoiding heavy
 * dependencies and providing lightweight, efficient mechanisms for test
 * execution and reporting.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>
#include <cstring>
// <iostream> is too heavy for embedded, use printf().
#include <stdio.h>
#include <unistd.h>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // Public API.

  /**
   * @details
   * The `initialize` function sets up the µTest++ testing framework, preparing
   * it for test execution. It processes command-line arguments, configures the
   * test environment, and establishes the default test suite name. This
   * function should be called at the beginning of the test programme,
   * typically from the `main()` function, to ensure proper initialisation of
   * all framework components.
   *
   * The provided arguments may be used to configure verbosity or other
   * run-time options for the test session.
   */
  void
  initialize (int argc, char* argv[], const char* name)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif
    runner.initialize (argc, argv, name);
  }

  /**
   * @details
   * In addition to the test cases defined in `main()`, additional test suites
   * may be declared as static objects either within the same file or in other
   * files, and are automatically registered via the static constructors
   * mechanism.
   *
   * The `exit_code` function finalises the execution of all registered test
   * suites and test cases within the µTest++ framework, and returns an
   * appropriate exit code to the operating system. This function should be
   * called at the end of the test program, typically from the `main()`
   * function, to ensure that all results are properly reported and the correct
   * status is communicated.
   *
   * The returned value indicates the overall success or failure of the test
   * run, allowing integration with build systems and continuous integration
   * environments.
   */
  int
  exit_code (void)
  {
    return runner.exit_code ();
  }

  // --------------------------------------------------------------------------
  // Too small to deserve a separate source file.
  namespace reflection
  {

    /**
     * @details
     * This function extracts the short name from a given file path by locating
     * the final folder separator ('/'). If a separator is found, it returns a
     * pointer to the character immediately following it, effectively providing
     * the file or folder name. If no separator is present, the original input
     * string is returned. This utility is useful for reporting concise file or
     * folder names in test output.
     */
    const char*
    short_name (const char* name)
    {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
      const char* p = strrchr (name, '/');
      if (p != nullptr)
        return p + 1;
      else
        return name;
#pragma GCC diagnostic pop
    }

  } // namespace reflection

  namespace utility
  {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#endif
/**
 * @details
 * This function enables pattern-based string comparison for tests, supporting
 * both exact matches and wildcard patterns. The pattern may include `*` to
 * match any sequence of characters and `?` to match any single character. This
 * allows for flexible validation of string content in test assertions,
 * accommodating variable or partially known values.
 *
 * @par Examples
 *
 * @code{.cpp}
 * namespace mt = micro_os_plus::micro_test_plus;
 *
 * mt::expect (mt::utility::is_match ("abc", "a?c")) << "abc matches a?c";
 * mt::expect (mt::utility::is_match ("abc", "a*c")) << "abc matches a*c";
 * @endcode
 */
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    [[nodiscard]] bool
    is_match (std::string_view input, std::string_view pattern)
    {
      if (std::empty (pattern))
        {
          return std::empty (input);
        }

      if (std::empty (input))
        {
          return pattern[0] == '*' ? is_match (input, pattern.substr (1))
                                   : false;
        }

      if (pattern[0] != '?' and pattern[0] != '*' and pattern[0] != input[0])
        {
          return false;
        }

      if (pattern[0] == '*')
        {
          for (decltype (std::size (input)) i = 0u; i <= std::size (input);
               ++i)
            {
              if (is_match (input.substr (i), pattern.substr (1)))
                {
                  return true;
                }
            }
          return false;
        }

      return is_match (input.substr (1), pattern.substr (1));
    }

  } // namespace utility

  namespace detail
  {
    /**
     * @details
     * This constructor updates the current test suite's statistics based on
     * the outcome of the test expression. If the evaluated value is true, the
     * count of successful tests is incremented; otherwise, the count of failed
     * tests is incremented. The source location is recorded for reporting
     * purposes, enabling precise identification of the test case within the
     * relevant file or folder.
     */
    deferred_reporter_base::deferred_reporter_base (
        bool value, const reflection::source_location location)
        : value_{ value }, location_{ location }
    {
      if (value_)
        {
          current_test_suite->increment_successful ();
        }
      else
        {
          current_test_suite->increment_failed ();
        }
    }

    /**
     * @details
     * The destructor ensures that if an abort condition is set and the test
     * expression has failed, the test output is flushed and the process is
     * terminated. This mechanism guarantees immediate feedback and halts
     * further execution upon critical test failures, aiding in rapid
     * identification and resolution of issues during test runs.
     */
    deferred_reporter_base::~deferred_reporter_base ()
    {
#if 0 // defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
      printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

      if (abort_ && !value_)
        {
          printf ("\n");
          reporter.output ();
          abort ();
        }
    }

  } // namespace detail

  // ==========================================================================

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#endif

  // Static instances;
  /**
   * @brief Global instance of `test_runner`.
   *
   * @details
   * This global instance of `test_runner` manages the lifecycle of test suites
   * and test cases within the µTest++ framework. It is responsible for
   * initialising the test environment, registering test suites, executing
   * tests, and collecting results. By maintaining a single shared runner, the
   * framework ensures consistent test execution and reporting across all test
   * cases and folders.
   */
  test_runner runner;

  /**
   * @brief Global instance of `test_reporter`.
   *
   * @details
   * This global instance of `test_reporter` is responsible for collecting,
   * formatting, and outputting the results of test execution within the
   * µTest++ framework. It manages the reporting of test outcomes, including
   * successes and failures, and ensures that all relevant information is
   * presented clearly to the user. By maintaining a single shared reporter,
   * the framework provides consistent and centralised reporting across all
   * test cases and folders.
   */
  test_reporter reporter;

  /**
   * @brief Global pointer references the currently active test suite.
   *
   * @details
   * This global pointer references the currently active test suite within the
   * µTest++ framework. It is used to track and update the state of the test
   * suite during test execution, including recording test results and
   * statistics. By maintaining a pointer to the current test suite, the
   * framework ensures accurate association of test outcomes with their
   * respective suites, supporting clear and organised reporting across all
   * test cases and folders.
   */
  test_suite_base* current_test_suite;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------
