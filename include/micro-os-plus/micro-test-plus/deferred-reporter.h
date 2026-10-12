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
 * @brief C++ header file with declarations for the µTest++ deferred reporter.
 *
 * @details
 * This header provides the two deferred-reporter classes used by `expect()`
 * and `assume()` to capture a test-expression result and report the outcome
 * only when the reporter object is destroyed (i.e. at the semicolon
 * following the expression statement), after the optional user message was
 * appended.
 *
 * - `deferred_reporter_base` stores the boolean result, the source
 *   location, an optional user-supplied message (accumulated via
 *   `operator<<`), and a reference to the owning `subtest`. Its destructor
 *   calls the reporter to emit a pass or fail line.
 * - `deferred_reporter` derives from the base; its template constructor
 *   formats the expression (with the actual operand values) into the
 *   expression formatter of the reporter, so that it can be printed on
 *   failure.
 *
 * Both classes live in the `detail` namespace and are not part of the
 * public API.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_DEFERRED_REPORTER_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_DEFERRED_REPORTER_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "type-traits.h"
#include "reflection.h"
#include "expression-formatter.h"

#include <cstdio>
#include <string>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  class subtest;

  // --------------------------------------------------------------------------

  namespace detail
  {
    // ========================================================================

    /**
     * @brief Base class for a deferred reporter that collects messages into a
     * string.
     *
     * @details
     * The `deferred_reporter_base` class serves as the foundational component
     * for deferred reporting within the framework. It is responsible for
     * collecting expectation messages, typically passed via the
     * `operator<<()`, into a string for later reporting.
     *
     * This class maintains the result value, abort status, and the source
     * location associated with the report. It is intended exclusively for
     * internal use and is implemented in the
     * `include/micro-os-plus/micro-test-plus` folder to ensure a structured
     * and modular codebase.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class deferred_reporter_base
    {
    public:
      /**
       * @brief Constructs a deferred reporter base.
       *
       * @param value The result value associated with the report.
       * @param location The source location relevant to the report.
       * @param subtest The subtest that owns this deferred report.
       */
      deferred_reporter_base (bool value,
                              const reflection::source_location& location,
                              subtest& subtest);

      /**
       * @brief Deleted copy constructor to prevent copying.
       *
       * @details
       * Each instance reports exactly one check, from its destructor; a
       * copy would report it twice.
       */
      deferred_reporter_base (const deferred_reporter_base&) = delete;

      /**
       * @brief Deleted move constructor to prevent moving.
       *
       * @details
       * The instance is a temporary that lives only until the end of the
       * expression statement.
       */
      deferred_reporter_base (deferred_reporter_base&&) = delete;

      /**
       * @brief Deleted copy assignment operator to prevent copying.
       *
       * @details
       * Each instance reports exactly one check, from its destructor.
       */
      deferred_reporter_base&
      operator= (const deferred_reporter_base&)
          = delete;

      /**
       * @brief Deleted move assignment operator to prevent moving.
       *
       * @details
       * Each instance reports exactly one check, from its destructor.
       */
      deferred_reporter_base&
      operator= (deferred_reporter_base&&)
          = delete;

      /**
       * @brief Destructor for the deferred reporter base.
       */
      ~deferred_reporter_base ();

      /**
       * @brief Appends a message to the reporter.
       *
       * @tparam T The type of the message to append.
       *
       * @param msg The message to append.
       * @return Reference to the current reporter instance.
       */
      template <class T>
        requires type_traits::printable<T>
      auto&
      operator<< (const T& msg);

      /**
       * @brief Retrieves the result value.
       *
       * @par Parameters
       *   None.
       * @retval true  The reported condition was met.
       * @retval false The reported condition was not met.
       */
      [[nodiscard]] bool
      value () const;

    protected:
      /**
       * @brief Stores the result value of the report.
       *
       * @details
       * The boolean value of the checked expression, computed by the
       * constructor.
       */
      bool value_{};

      /**
       * @brief Indicates whether the reporting should abort further
       * processing.
       *
       * @details
       * Set for `assume()` checks; a failure then terminates the test
       * execution.
       */
      bool abort_ = false;

      /**
       * @brief Indicates whether the reporter has an associated expression.
       *
       * @details
       * Set when the checked expression is a framework comparator, whose
       * formatted text is displayed on failure.
       */
      bool has_expression_ = false;

      /**
       * @brief Stores the source location associated with the report.
       *
       * @details
       * Displayed with failures, and used when aborting.
       */
      const reflection::source_location location_{};

      /**
       * @brief String to collect the expectation message passed via
       * `operator<<()`.
       *
       * @details
       * Passed to the reporter by the destructor.
       */
      std::string deferred_output_{};

      /**
       * @brief Reference to the test case invoking this report.
       *
       * @details
       * Provides access to the reporter and to the totals to be updated.
       */
      subtest& subtest_;
    };

    // ========================================================================

    /**
     * @brief Deferred reporter class for a specific expression.
     *
     * @details
     * The `deferred_reporter` class extends `deferred_reporter_base`
     * to provide deferred reporting functionality for a specific test
     * expression within the framework.
     *
     * Its template constructor evaluates the expression, records the abort
     * status, and formats the expression into the expression formatter of
     * the reporter. It is intended exclusively for internal use and is
     * implemented in the `include/micro-os-plus/micro-test-plus` folder to
     * ensure a structured and modular codebase.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class deferred_reporter : public deferred_reporter_base
    {
    public:
      /**
       * @brief Constructs a deferred reporter for a specific expression.
       *
       * @param expr The expression under evaluation.
       * @param abort Indicates whether reporting should abort further
       * processing.
       * @param location The source location relevant to the report.
       * @param subtest The subtest that owns this deferred report.
       * @param expression The expression formatter to format the expression
       * text.
       */
      template <class Expr_T>
      deferred_reporter (const Expr_T& expr, bool abort,
                         const reflection::source_location& location,
                         subtest& subtest, expression_formatter& expression);

      /**
       * @brief Destructor for the deferred reporter.
       *
       * @details
       * Defaulted; the reporting is performed by the base class destructor.
       */
      ~deferred_reporter () = default;
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/deferred-reporter-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_DEFERRED_REPORTER_H_

// ----------------------------------------------------------------------------
