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
#if !defined(__clang__) // GCC only
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @brief Base class for all test suites.
   */
  class test_suite_base
  {
  public:
    /**
     * @brief Construct a test suite.
     * @param [in] name The test suite name.
     */
    test_suite_base (const char* name);

    // The rule of five.
    test_suite_base (const test_suite_base&) = delete;
    test_suite_base (test_suite_base&&) = delete;
    test_suite_base&
    operator= (const test_suite_base&)
        = delete;
    test_suite_base&
    operator= (test_suite_base&&)
        = delete;

    virtual ~test_suite_base ();

    /**
     * @brief Run the sequence of test cases in the suite.
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    virtual void
    run (void);

    /**
     * @brief Mark the beginning of a named test case.
     * @param [in] name The test case name.
     * @par Returns
     *  Nothing.
     */
    void
    begin_test_case (const char* name);

    /**
     * @brief Mark the end of a test case.
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    end_test_case (void);

    /**
     * @brief Get the suite name.
     * @par Parameters
     *	None.
     * @return A pointer to the null terminated test suite name.
     */
    [[nodiscard]] constexpr const char*
    name ()
    {
      return name_;
    }

    /**
     * @brief Count one more passed test conditions.
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    increment_successful (void);

    /**
     * @brief Count one more failed test conditions.
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    increment_failed (void);

    /**
     * @brief Get the number of conditions that passed.
     * @par Parameters
     *	None.
     * @return An integer with the number checks that passed.
     */
    [[nodiscard]] constexpr int
    successful_checks (void)
    {
      return successful_checks_;
    }

    /**
     * @brief Get the number of conditions that failed.
     * @par Parameters
     *	None.
     * @return An integer with the number checks that failed.
     */
    [[nodiscard]] constexpr int
    failed_checks (void)
    {
      return failed_checks_;
    }

    /**
     * @brief Get the number of test cases.
     * @par Parameters
     *	None.
     * @return An integer with the number of test cases.
     */
    [[nodiscard]] constexpr int
    test_cases (void)
    {
      return test_cases_;
    }

    /**
     * @brief Begin the execution of the test suite.
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    begin_test_suite (void);

    /**
     * @brief Mark the end of the test suite.
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    end_test_suite (void);

    /**
     * @brief Get the test suite result.
     * @par Parameters
     *	None.
     * @return True if the test suite was successful.
     */
    [[nodiscard]] constexpr bool
    was_successful (void)
    {
      // Also fail if none passed.
      return (failed_checks_ == 0 && successful_checks_ != 0);
    }

    /**
     * @brief If all counter are null, it is unused.
     * @par Parameters
     *	None.
     * @return True if the test suite is not used.
     */
    [[nodiscard]] constexpr bool
    unused (void)
    {
      return (failed_checks_ == 0 && successful_checks_ == 0
              && test_cases_ == 0);
    }

  protected:
    /**
     * @brief The test suite name.
     */
    const char* name_;

    /**
     * @brief The current test case name.
     */
    const char* test_case_name_;

    /**
     * @brief Count of test conditions that passed.
     */
    int successful_checks_ = 0;

    /**
     * @brief Count of test conditions that failed.
     */
    int failed_checks_ = 0;

    /**
     * @brief Count of test cases in the test suite.
     */
    int test_cases_ = 0;

  public:
    bool process_deferred_begin = true;
    struct
    {
      int successful_checks;
      int failed_checks;
    } current_test_case{};
  };

  /**
   * @ingroup mtp-test-suites
   * @brief Test suites are classes that represent a named group of
   * test cases which self register to the runner.
   */
  class test_suite : public test_suite_base
  {
  public:
    /**
     * @brief Construct a test suite.
     * @tparam Callable_T The type of an object that can be called.
     * @tparam Args_T The type of the callable arguments.
     * @param [in] name The test case name or description.
     * A short string used in the report.
     * @param [in] callable A generic callable object,
     * invoked to perform the test. Usually a lambda.
     * @param [in] arguments A possibly empty list of arguments to be
     * passed to the callable.
     */
    template <typename Callable_T, typename... Args_T>
    test_suite (const char* name, Callable_T&& callable,
                Args_T&&... arguments);

    // The rule of five.
    test_suite (const test_suite&) = delete;
    test_suite (test_suite&&) = delete;
    test_suite&
    operator= (const test_suite&)
        = delete;
    test_suite&
    operator= (test_suite&&)
        = delete;

    virtual ~test_suite () override;

    virtual void
    run (void) override;

  protected:
    std::function<void (void)> callable_;
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
