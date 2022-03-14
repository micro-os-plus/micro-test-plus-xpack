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

#ifndef MICRO_TEST_PLUS_TEST_SUITE_H_
#define MICRO_TEST_PLUS_TEST_SUITE_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <functional>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
//#pragma clang diagnostic ignored "-Wc++98-c++11-compat"
//#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @brief Test suites are classes that represent a named group of
   * test cases which self registers to the runner.
   */
  class test_suite
  {
  public:
    /**
     * @brief Construct the default suite used in main().
     */
    test_suite (const char* name);

    /**
     * @brief Construct a suite in a separate compile unit, usually with
     * a lambda.
     */
    template <class Callable_T>
    test_suite (const char* name, Callable_T callable);

    /**
     * @brief Run the sequence of test cases in the suite.
     */
    void
    run ();

    /**
     * @brief Mark the begining of a named test case.
     */
    void
    begin_test_case (const char* name);

    /**
     * @brief Mark the end of a test case.
     */
    void
    end_test_case (void);

    /**
     * @brief Get the suite name.
     */
    [[nodiscard]] constexpr const char*
    name ()
    {
      return name_;
    }

    /**
     * @brief Count one more passed test condition.
     */
    constexpr void
    increment_passed (void)
    {
      ++passed_;
    }

    /**
     * @brief Count one more failed test condition.
     */
    constexpr void
    increment_failed (void)
    {
      ++failed_;
    }

    /**
     * @brief Get the number of passed conditions.
     */
    constexpr int
    passed (void)
    {
      return passed_;
    }

    /**
     * @brief Get the number of failed conditions.
     */
    constexpr int
    failed (void)
    {
      return failed_;
    }

    /**
     * @brief Get the number of test cases.
     */
    constexpr int
    test_cases (void)
    {
      return test_cases_;
    }

    /**
     * @brief Begin the execution of the test suite.
     */
    void
    begin (void);

    /**
     * @brief Mark the end of the test suite.
     */
    void
    end (void);

    /**
     * @brief Get the test suite result.
     */
    [[nodiscard]] constexpr bool
    success (void)
    {
      // Also fail if none passed.
      return (failed_ == 0 && passed_ != 0);
    }

  private:
    /**
     * @brief The test suite name.
     */
    const char* name_;

    /**
     * @brief The current test case name.
     */
    const char* test_case_name_;

    /**
     * @brief The functions/lambda to perform the tests.
     */
    std::function<void ()> callable_ = nullptr;

    /**
     * @brief Count of passed test conditions.
     */
    int passed_ = 0;

    /**
     * @brief Count of failed test conditions.
     */
    int failed_ = 0;

    /**
     * @brief Count of test cases in the test suite.
     */
    int test_cases_ = 0;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_SUITE_H_

// ----------------------------------------------------------------------------
