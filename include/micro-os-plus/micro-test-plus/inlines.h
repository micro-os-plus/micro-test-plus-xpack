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
 * @file inlines.h
 * @brief Inline implementations for the µTest++ testing framework.
 *
 * @details
 * This header provides inline definitions for key components of the µTest++
 * framework, including the management of test suites and test cases, deferred
 * reporting, and utility functions.
 *
 * The file offers template implementations for registering and executing test
 * suites and test cases, as well as mechanisms for reporting test results in a
 * deferred manner. It also includes utility functions, such as string
 * splitting, to facilitate test development.
 *
 * All definitions are contained within the `micro_os_plus::micro_test_plus`
 * namespace and its nested namespaces, ensuring a clear distinction between
 * user-facing and internal components. This approach enhances maintainability,
 * encourages modularity, and reduces the risk of name clashes.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_INLINES_H_
#define MICRO_TEST_PLUS_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-c++17-compat-pedantic"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * This constructor initialises a test suite by binding the provided callable
   * and its arguments, and registers the suite with the test runner.
   *
   * The callable is bound using `std::bind`, allowing for flexible test suite
   * definitions with arbitrary arguments. Upon construction, the test suite is
   * automatically registered with the global runner for execution.
   */
  template <typename Callable_T, typename... Args_T>
  test_suite::test_suite (const char* name, Callable_T&& callable,
                          Args_T&&... arguments)
      : test_suite_base{ name },
        callable_{ std::bind (callable, arguments...) }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    runner.register_test_suite (this);
  }

  // --------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#endif
  /**
   * @details
   * The `test_case` function template defines a test case, which is a sequence
   * of test conditions (also referred to as tests or checks) that represent
   * expectations or assumptions—conditions expected to be true.
   *
   * Each test is based on a logical expression, typically involving the
   * computation of a result and its comparison to an expected value. For C++
   * projects, it is also possible to verify whether evaluating an expression
   * throws exceptions. Each test either succeeds or fails. For expectations,
   * the test runner maintains counts of successful and failed tests.
   *
   * A test case is characterised by a name, a function that performs the
   * checks, and optionally, arguments to be passed to that function.
   *
   * The implementation of `test_case` invokes the provided function with the
   * given arguments and reports the results to the test runner.
   *
   * @par Example
   *
   * @code{.cpp}
   *   namespace mt = micro_os_plus::micro_test_plus;
   *
   *   mt::test_case ("Check answer with comparator", [] {
   *     mt::expect (mt::eq (compute_answer (), 42)) << "answer is 42";
   *   });
   * @endcode
   */
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& callable, Args_T&&... arguments)
  {
#if 0 // defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    current_test_suite->begin_test_case (name);
    std::invoke (std::forward<Callable_T> (callable),
                 std::forward<Args_T> (arguments)...);
    current_test_suite->end_test_case ();
  }

  // --------------------------------------------------------------------------
  namespace detail
  {
    // ------------------------------------------------------------------------

    /**
     * @details
     * This operator overload enables the deferred reporter to accumulate
     * expectation messages by appending the provided value to the internal
     * message string.
     *
     * If the argument is of an arithmetic type, it is first converted to a
     * string using `std::to_string` before being appended. For all other
     * types, the value is appended directly. This ensures that both numeric
     * and string-like messages are handled appropriately and consistently.
     */
    template <class T>
    auto&
    deferred_reporter_base::operator<< (const T& msg)
    {
      if constexpr (std::is_arithmetic_v<T>)
        {
          message_.append (std::to_string (msg));
        }
      else
        {
          message_.append (msg);
        }
      return *this;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * This constructor initialises a deferred reporter for a specific
     * expression, capturing the evaluation result, abort status, and source
     * location.
     *
     * The expression is evaluated and its boolean result is passed to the base
     * class. The abort flag determines whether further test execution should
     * be halted if the expectation fails. The source location provides
     * contextual information for reporting purposes.
     */
    template <class Expr_T>
    constexpr deferred_reporter<Expr_T>::deferred_reporter (
        const Expr_T& expr, bool abort,
        const reflection::source_location& location)
        : deferred_reporter_base{ static_cast<bool> (expr), location },
          expr_{ expr }
    {
#if 0 // defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
      printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
      abort_ = abort;
    }

    /**
     * @details
     * The destructor finalises the deferred reporting process for a test
     * expression. If the evaluated expression is true, the reporter records a
     * successful outcome along with any accumulated message. If the expression
     * is false, the reporter records a failure, including the abort status,
     * message, and source location for comprehensive reporting.
     *
     * This mechanism ensures that all relevant information about the test
     * outcome is captured and reported accurately when the deferred reporter
     * goes out of scope.
     */
    template <class Expr_T>
    deferred_reporter<Expr_T>::~deferred_reporter ()
    {
      if (value_)
        {
          reporter.pass (expr_, message_);
        }
      else
        {
          reporter.fail (expr_, abort_, message_, location_);
        }
    }

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
  namespace utility
  {
    /**
     * @details
     * This function template facilitates string handling in tests by splitting
     * a string into a vector of substrings, using the specified delimiter.
     *
     * The function iterates through the input string, identifying delimiter
     * positions and extracting substrings between them. Each resulting
     * substring is added to the output vector. This approach supports flexible
     * parsing of delimited data, which is particularly useful for validating
     * string processing logic in test cases.
     *
     * @par Example
     *
     * @code{.cpp}
     * namespace mt = micro_os_plus::micro_test_plus;
     *
     * mt::expect (std::vector<std::string_view>{ "a", "b" }
     *             == mt::utility::split<std::string_view> ("a.b", "."))
     *         << "a.b splits into [a,b]";
     * @endcode
     */
    template <class T = std::string_view, class Delim_T>
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>
    {
      std::vector<T> output{};
      std::size_t first{};
      while (first < std::size (input))
        {
          const auto second = input.find_first_of (delim, first);
          if (first != second)
            {
              output.emplace_back (input.substr (first, second - first));
            }
          if (second == T::npos)
            {
              break;
            }
          first = second + 1;
        }
      return output;
    }
  } // namespace utility

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_INLINES_H_

// ----------------------------------------------------------------------------
