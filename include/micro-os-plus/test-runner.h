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

#ifndef MICRO_TEST_PLUS_TEST_RUNNER_H_
#define MICRO_TEST_PLUS_TEST_RUNNER_H_

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

  class test_suite;

  // --------------------------------------------------------------------------

  /**
   * @brief The test runner. It maintaines a list of test suites which
   * automatically register themselves in their constructors.
   */
  class test_runner
  {
  public:
    test_runner ();

    // The rule of five.
    test_runner (const test_runner&) = delete;
    test_runner (test_runner&&) = delete;
    test_runner&
    operator= (const test_runner&)
        = delete;
    test_runner&
    operator= (test_runner&&)
        = delete;

    ~test_runner () = default;

    /**
     * @brief Pass the main arguments explicitly, if the default
     * contructor was used.
     */
    void
    initialize (const char* name, int argc, char* argv[]);

    /**
     * @brief Return 0 if the all tests were successful, 1 otherwise.
     */
    int
    exit_code (void);

    /**
     * @brief Called by test suite constructors to register them
     * to the runner.
     */
    void
    register_test_suite (test_suite* suite);

    constexpr const char*
    name (void)
    {
      return default_suite_name_;
    }

    [[noreturn]] void
    abort (void);

  protected:
    int argc_ = 0;
    char** argv_ = nullptr;

    const char* default_suite_name_ = "Test";

    /**
     * @brief Pointer to the default test suite which groups
     * the main tests.
     */
    test_suite* default_test_suite_;

    /**
     * @brief Pointer to array of registered test suites.
     * Statically initialised to zero as BSS, such that
     * test suites defined as static objects in different
     * compilation units can  be automatically executed.
     */
    std::vector<test_suite*>* suites_;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_RUNNER_H_

// ----------------------------------------------------------------------------
