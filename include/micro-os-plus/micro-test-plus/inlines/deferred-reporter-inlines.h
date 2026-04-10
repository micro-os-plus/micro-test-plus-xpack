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
 * @brief C++ header file with inline implementations for the µTest++
 * internals.
 *
 * @details
 * This header provides the inline implementations for internal components of
 * the µTest++ framework, including operator overloads and constructors for
 * deferred reporting mechanisms.
 *
 * It defines the logic for accumulating expectation messages, handling both
 * arithmetic and string-like types, as well as the construction and
 * destruction behaviour of deferred reporters, ensuring that test outcomes are
 * accurately captured and reported.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::detail`
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

#ifndef MICRO_TEST_PLUS_DEFERRED_REPORTER_INLINES_H_
#define MICRO_TEST_PLUS_DEFERRED_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <charconv>
#include <cstdio>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
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
     * If the argument is a `char`, it is appended directly as a character.
     * If the argument is of another arithmetic type, it is converted to a
     * string using a fixed-size buffer and `std::to_chars` to avoid dynamic
     * memory allocation. For all other types, the value is appended directly.
     */
    template <class T>
      requires (std::is_arithmetic_v<T>
                or std::is_convertible_v<T, std::string_view>)
    auto&
    deferred_reporter_base::operator<< (const T& msg)
    {
      if constexpr (std::is_same_v<T, char>)
        {
          deferred_output_.push_back (msg);
        }
      else if constexpr (std::is_arithmetic_v<T>)
        {
          // Optimise to avoid dynamic memory allocation in std::to_string by
          // using a fixed-size buffer and std::to_chars.
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
          char buf[64];
          auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf), msg);
          if (ec == std::errc{})
            deferred_output_.append (buf, ptr);
#pragma GCC diagnostic pop
        }
      else
        {
          deferred_output_.append (msg);
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
    deferred_reporter<Expr_T>::deferred_reporter (
        const Expr_T& expr, bool abort,
        const reflection::source_location& location, subtest& subtest)
        : deferred_reporter_base{ static_cast<bool> (expr), location,
                                  subtest },
          expr_{ expr }
    {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
      trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
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
      if (value_) [[likely]]
        {
          subtest_.reporter ().pass (expr_, deferred_output_, subtest_);
        }
      else
        {
          subtest_.reporter ().fail (expr_, abort_, deferred_output_,
                                     location_, subtest_);
        }
    }

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_DEFERRED_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------
