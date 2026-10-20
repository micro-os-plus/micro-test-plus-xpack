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
 * `operator<<` that accumulates the expectation messages (written by the
 * expression formatter, in its plain mode). The non-template constructor
 * and the destructor are defined in `src/check-result.cpp`.
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
#include <utility>

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
     * the kind of the check and whether the expression is a framework
     * comparator, to the non-template constructor, which also stores the
     * source location and the test case. The kind,
     * `check_kind::requirement` for `require()`, determines whether the
     * test case is stopped if the check fails.
     *
     * The expression formatter of the reporter, which is shared by all
     * checks, is then assigned to this check by `begin_check()`, which sets
     * aside the text of a previous check not yet reported, if any. The
     * expression is formatted into it only when the outcome is written: on
     * failure, or, if @p writes_passed, also on success. Otherwise the
     * text of this check stays empty, and the operands, which may be
     * application types with an expensive `operator<<`, are not formatted.
     *
     * The decision is taken here, while the operands are alive; a result
     * kept in a variable outlives them.
     */
    template <class Expr_T>
    check_result::check_result (const Expr_T& expr, check_kind kind,
                                const reflection::source_location& location,
                                test_case& test_case,
                                expression_formatter& expression,
                                bool writes_passed)
        : check_result{ static_cast<bool> (expr),
                        kind,
                        extension::is_op<Expr_T>,
                        location,
                        test_case,
                        writes_passed }
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

      // The same address is used by the destructor, to retrieve the text,
      // even if other checks used the formatter in the meantime.
      expression.begin_check (this);

      if (is_written_)
        {
          expression << expr;
        }
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Returns the result value stored in `value_`.
     */
    inline bool
    check_result::value (void) const noexcept
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
     * The value is written by the same `operator<<` overloads as the
     * operands of the expressions, so that both accept the same types,
     * including the application types with an `operator<<` for the
     * formatter. The message is moved into a local formatter in the plain
     * mode, which writes the numbers without the type suffixes and the
     * `char` values unchanged, and is moved back after the value is
     * appended, so that no other buffer is allocated. The formatter of the
     * reporter is not used, since it may hold the expression of this
     * check, or of a pending one.
     *
     * When the outcome of the check is not written, the message is not
     * needed, and the value is not formatted.
     */
    template <class T>
      requires extension::printable<T>
    auto&
    check_result::operator<< (const T& msg)
    {
      if (!is_written_)
        {
          return *this;
        }

      expression_formatter formatter{ std::move (info_.message) };
      formatter << msg;
      info_.message = std::move (formatter.buffer_);
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
