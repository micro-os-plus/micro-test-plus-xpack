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
 * deferred reporter.
 *
 * @details
 * This header provides the inline and template implementations for the
 * deferred reporters: the result accessor, the `operator<<` that
 * accumulates the expectation messages (handling both arithmetic and
 * string-like types), and the template constructor of `deferred_reporter`.
 * The non-template constructor and the destructor of
 * `deferred_reporter_base` are defined in `src/deferred-reporter.cpp`.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEFERRED_REPORTER_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEFERRED_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

#include <cstdio>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace detail
  {
    // ========================================================================

    /**
     * @details
     * Returns the result value stored in `value_`.
     */
    inline bool
    deferred_reporter_base::value () const
    {
      return value_;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * This operator overload enables the deferred reporter to accumulate
     * expectation messages by appending the provided value to the internal
     * message string.
     *
     * If the argument is a `char`, it is appended directly as a character.
     * If it is a `bool`, `"true"` or `"false"` is appended, as the
     * expression formatter does (`std::to_chars()` has no `bool`
     * overload). If it is of another arithmetic type, it is converted by
     * `detail::append_number_()`, the helper also used by the expression
     * formatter, which uses a fixed-size buffer (avoiding the temporary
     * string that `std::to_string()` would allocate) and handles the
     * platforms where `std::to_chars()` is not available for
     * `long double`. For all other types (convertible to
     * `std::string_view`), the value is appended directly.
     */
    template <class T>
      requires type_traits::printable<T>
    auto&
    deferred_reporter_base::operator<< (const T& msg)
    {
      if constexpr (std::is_same_v<T, char>)
        {
          deferred_output_.push_back (msg);
        }
      else if constexpr (std::is_same_v<T, bool>)
        {
          deferred_output_.append (msg ? "true" : "false");
        }
      else if constexpr (std::is_arithmetic_v<T>)
        {
          detail::append_number_ (deferred_output_, msg);
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
     * be halted if the expectation fails. The expression is formatted into
     * the expression formatter of the reporter, which is shared by all
     * checks; `begin_check()` assigns it to this check, setting aside the
     * text of a previous check not yet reported, if any.
     * `has_expression_` records whether it is a framework comparator, whose
     * text is to be displayed on failure.
     */
    template <class Expr_T>
    deferred_reporter::deferred_reporter (
        const Expr_T& expr, bool abort,
        const reflection::source_location& location, subtest& subtest,
        expression_formatter& expression)
        : deferred_reporter_base{ static_cast<bool> (expr), location, subtest }

    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
      abort_ = abort;
      has_expression_ = type_traits::is_op<Expr_T>;

      // The same address is used by the base destructor, to retrieve the
      // text, even if other checks used the formatter in the meantime.
      expression.begin_check (static_cast<deferred_reporter_base*> (this));

      expression << expr;
    }

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEFERRED_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------
