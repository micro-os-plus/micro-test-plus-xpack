/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2025 Liviu Ionescu. All rights reserved.
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
 * @brief C++ header file with inline implementations for the µTest++ Testing
 * Framework.
 *
 * @details
 * This header provides the inline implementations for the principal public API
 * functions and utilities of the µTest++ framework, including test case
 * registration, expectation and assumption evaluation, exception verification,
 * and utility helpers for string processing in tests.
 *
 * It defines the logic for registering and executing test cases, evaluating
 * logical conditions and custom comparators, and reporting test results with
 * detailed diagnostics. The exception verification functions enable robust
 * testing of error handling and exception safety, while utility functions such
 * as string splitting support flexible validation of string processing logic.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
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

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#endif
  /**
   * @details
   * The `test_case` function template registers and executes a test case
   * within the µTest++ framework. It accepts a descriptive name, a callable
   * object (such as a lambda or function pointer), and an optional list of
   * arguments to be passed to the callable. The test case is reported using
   * the provided name, and its execution is managed by the framework's test
   * runner.
   *
   * Each test case typically involves evaluating a logical expression, such as
   * comparing a computed result to an expected value. For C++ projects, it is
   * also possible to verify whether evaluating an expression throws
   * exceptions. Each test either succeeds or fails, and for expectations, the
   * test runner maintains counts of successful and failed checks.
   *
   * This function template enables flexible and expressive test case
   * definitions, supporting both parameterised and non-parameterised tests. It
   * is typically invoked at global scope or within test suite definitions to
   * ensure automatic registration and execution.
   *
   * A test case is characterised by a name, a function that performs the
   * checks, and optionally, arguments to be passed to that function. The
   * implementation of `test_case` invokes the provided function with the given
   * arguments and reports the results to the test runner.
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

  /**
   * @details
   * The `expect` function template evaluates a logical condition or custom
   * expression and reports the result within the µTest++ framework. It is
   * designed to provide detailed diagnostics for test failures, including the
   * actual and expected values, when using the provided comparators (`eq()`,
   * `ne()`, `lt()`, `le()`, `gt()`, `ge()`) or custom operators.
   *
   * The function template can be used with any expression that evaluates to a
   * boolean or with custom comparators/operators derived from the local
   * `detail::op` type. For complex checks performed outside the `expect()`
   * logical expression (such as within `if` or `try`/`catch` statements), the
   * result can be reported by calling `expect(true)` or `expect(false)`.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report.
   *
   * **Example**
   *
   * @code{.cpp}
   * namespace mt = micro_os_plus::micro_test_plus;
   * mt::expect(compute_answer() == 42) << "answer is 42";
   * @endcode
   */

  template <class Expr_T, type_traits::requires_t<
                              type_traits::is_op_v<Expr_T>
                              or type_traits::is_convertible_v<Expr_T, bool>>>
  constexpr auto
  expect (const Expr_T& expr, const reflection::source_location& sl)
  {
    return detail::deferred_reporter<Expr_T>{ expr, false, sl };
  }

  /**
   * @details
   * The `assume` function template evaluates a logical condition or custom
   * expression and reports the result within the µTest++ framework. It is
   * designed to provide detailed diagnostics for test failures, including the
   * actual and expected values, when using the provided comparators (`eq()`,
   * `ne()`, `lt()`, `le()`, `gt()`, `ge()`) or custom operators.
   *
   * The function template can be used with any expression that evaluates to a
   * boolean or with custom comparators/operators derived from the local
   * `detail::op` type. For complex checks performed outside the `expect()`
   * logical expression (such as within `if` or `try`/`catch` statements), the
   * result can be reported by calling `expect(true)` or `expect(false)`.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report.
   *
   * **Example**
   *
   * @code{.cpp}
   * namespace mt = micro_os_plus::micro_test_plus;
   * mt::assume(compute_answer() == 42) << "answer is 42";
   * @endcode
   */
  template <class Expr_T, type_traits::requires_t<
                              type_traits::is_op_v<Expr_T>
                              or type_traits::is_convertible_v<Expr_T, bool>>>
  constexpr auto
  assume (const Expr_T& expr, const reflection::source_location& sl)
  {
    return detail::deferred_reporter<Expr_T>{ expr, true, sl };
  }

#if defined(__cpp_exceptions)

  /**
   * @details
   * The `throws` function template verifies whether invoking the provided
   * callable object results in the throwing of a specific exception type
   * within the µTest++ framework. This is useful for testing error handling
   * and exception safety in code under test.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   */
  template <class Exception_T, class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T, Exception_T>{ func };
  }

  /**
   * @details
   * The `throws` function template verifies whether invoking the provided
   * callable object results in the throwing of any exception within the
   * µTest++ framework. This is useful for testing general exception safety and
   * ensuring that code under test properly signals error conditions.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T>{ func };
  }

  /**
   * @details
   * The `nothrow` function template verifies whether invoking the provided
   * callable object does not result in the throwing of any exception within
   * the µTest++ framework. This is useful for testing exception safety and
   * ensuring that code under test does not unexpectedly signal error
   * conditions.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  nothrow (const Callable_T& func)
  {
    return detail::nothrow_<Callable_T>{ func };
  }

#endif // defined(__cpp_exceptions)

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
     * **Example**
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

    // ------------------------------------------------------------------------
  } // namespace utility

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_INLINES_H_

// ----------------------------------------------------------------------------
