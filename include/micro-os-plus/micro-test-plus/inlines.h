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
 * @brief C++ header file with inline implementations for the µTest++ methods.
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
   * @par Example
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
   * @par Example
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

  /**
   * @details
   * The `eq` function template provides a generic equality comparator for any
   * non-pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that two values are equal. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::eq_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `eq` function template provides a pointer equality comparator for any
   * pointer types. It constructs a comparator object that can be used within
   * the µTest++ framework to assert that two pointers are equal. This function
   * is typically used in test expectations and assertions to compare the
   * addresses of objects or resources.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::eq_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `ne` function template provides a generic non-equality comparator for
   * any types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that two values are not equal. This function
   * is typically used in test expectations and assertions to compare the
   * actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ne_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `ne` function template provides a pointer non-equality comparator for
   * any pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that two pointers are not equal.
   * This function is typically used in test expectations and assertions to
   * compare the addresses of objects or resources.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ne_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `gt` function template provides a generic greater than comparator for
   * any types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that one value is greater than another. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::gt_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `gt` function template provides a pointer greater than comparator for
   * any pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that one pointer is greater than
   * another. This function is typically used in test expectations and
   * assertions to compare the addresses of objects or resources.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::gt_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `ge` function template provides a generic greater than or equal
   * comparator for any types. It constructs a comparator object that can be
   * used within the µTest++ framework to assert that one value is greater than
   * or equal to another. This function is typically used in test expectations
   * and assertions to compare the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ge_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `ge` function template provides a pointer greater than or equal
   * comparator for any pointer types. It constructs a comparator object that
   * can be used within the µTest++ framework to assert that one pointer is
   * greater than or equal to another. This function is typically used in test
   * expectations and assertions to compare the addresses of objects or
   * resources.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ge_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `lt` function template provides a generic less than comparator for any
   * types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that one value is less than another. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::lt_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `lt` function template provides a pointer less than comparator for any
   * pointer types. It constructs a comparator object that can be used within
   * the µTest++ framework to assert that one pointer is less than another.
   * This function is typically used in test expectations and assertions to
   * compare the addresses of objects or resources.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::lt_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `le` function template provides a generic less than or equal
   * comparator for any types. It constructs a comparator object that can be
   * used within the µTest++ framework to assert that one value is less than or
   * equal to another. This function is typically used in test expectations and
   * assertions to compare the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::le_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `le` function template provides a pointer less than or equal
   * comparator for any pointer types. It constructs a comparator object that
   * can be used within the µTest++ framework to assert that one pointer is
   * less than or equal to another. This function is typically used in test
   * expectations and assertions to compare the addresses of objects or
   * resources.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::le_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `_not` function template provides a generic logical negation for any
   * expression type. It constructs a logical negator object that can be used
   * within the µTest++ framework to assert that a given condition is false.
   * This function is typically used in test expectations and assertions to
   * invert logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical not operator.
   */
  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T& expr)
  {
    return detail::not_<Expr_T>{ expr };
  }

  /**
   * @details
   * The `_and` function template provides a generic logical conjunction for
   * any expression types. It constructs a logical conjunction object that can
   * be used within the µTest++ framework to assert that both given conditions
   * are true. This function is typically used in test expectations and
   * assertions to combine logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical and operator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::and_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `_or` function template provides a generic logical disjunction for any
   * expression types. It constructs a logical disjunction object that can be
   * used within the µTest++ framework to assert that at least one of the given
   * conditions is true. This function is typically used in test expectations
   * and assertions to combine logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical or operator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _or (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::or_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `mut` function template provides a safe and generic mechanism to
   * remove the `const` qualifier from any type. It returns a non-const
   * reference to the input object, enabling modification of objects that were
   * originally declared as `const`. This utility is particularly useful in
   * testing scenarios where controlled mutation of test data is required.
   */
  template <class T>
  [[nodiscard]] constexpr auto
  mut (const T& t) noexcept -> T&
  {
    return const_cast<T&> (t);
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
