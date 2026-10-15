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
 * check result.
 *
 * @details
 * This header provides the inline and template implementations for the
 * check result: the template constructor, the result accessor, and the
 * `operator<<` that accumulates the expectation messages (handling both
 * arithmetic and string-like types). The non-template constructor and the
 * destructor are defined in `src/check-result.cpp`.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_CHECK_RESULT_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_CHECK_RESULT_INLINES_H_

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
     * The expression is evaluated, and the result is passed, together with
     * the abort status and whether the expression is a framework
     * comparator, to the non-template constructor, which also stores the
     * source location and the test case. The abort flag, set by
     * `require()`, determines whether the test case is stopped if the
     * check fails.
     *
     * The expression is then formatted into the expression formatter of the
     * reporter, which is shared by all checks; `begin_check()` assigns it
     * to this check, setting aside the text of a previous check not yet
     * reported, if any.
     */
    template <class Expr_T>
    check_result::check_result (const Expr_T& expr, bool abort,
                                const reflection::source_location& location,
                                test_case& test_case,
                                expression_formatter& expression)
        : check_result{ static_cast<bool> (expr), abort,
                        type_traits::is_op<Expr_T>, location, test_case }
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

      // The same address is used by the destructor, to retrieve the text,
      // even if other checks used the formatter in the meantime.
      expression.begin_check (this);

      expression << expr;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Returns the result value stored in `value_`.
     */
    inline bool
    check_result::value (void) const
    {
      return value_;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * This operator overload enables the check result to accumulate
     * expectation messages by appending the provided value to the internal
     * message string.
     *
     * If the argument is a `char`, it is appended directly as a character.
     * If it is a `bool`, `"true"` or `"false"` is appended, as the
     * expression formatter does (`std::to_chars()` has no `bool`
     * overload). If it is of another arithmetic type, it is converted by
     * `detail::append_number()`, the helper also used by the expression
     * formatter, which uses a fixed-size buffer (avoiding the temporary
     * string that `std::to_string()` would allocate) and handles the
     * platforms where `std::to_chars()` is not available for
     * `long double`. If it is `std::nullptr_t`, `"nullptr"` is appended.
     * If it is a pointer (the `printable` concept admits only the pointers
     * to `char`), the string is appended, or `"nullptr"` for a null
     * pointer, as the expression formatter and the reporter do, since
     * `std::string::append()` must not be called with a null pointer. For
     * all other types (convertible to `std::string_view`), the value is
     * appended directly.
     */
    template <class T>
      requires type_traits::printable<T>
    auto&
    check_result::operator<< (const T& msg)
    {
      if constexpr (std::is_same_v<T, char>)
        {
          message_.push_back (msg);
        }
      else if constexpr (std::is_same_v<T, bool>)
        {
          message_.append (msg ? "true" : "false");
        }
      else if constexpr (std::is_arithmetic_v<T>)
        {
          detail::append_number (message_, msg);
        }
      else if constexpr (std::is_null_pointer_v<T>)
        {
          message_.append ("nullptr");
        }
      else if constexpr (std::is_pointer_v<T>)
        {
          message_.append (msg != nullptr ? msg : "nullptr");
        }
      else
        {
          message_.append (msg);
        }
      return *this;
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

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_CHECK_RESULT_INLINES_H_

// ----------------------------------------------------------------------------
