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
 * @brief C++ header file with declarations for the µTest++ check result.
 *
 * @details
 * This header provides the `check_result` class, the object returned by
 * `expect()` and `require()`, together with the `check_kind` enumeration
 * and the `failure_info` structure, passed to the reporter. The check
 * result captures the result of one check and reports the outcome only
 * when it is destroyed (i.e. at the semicolon following the expression
 * statement), after the optional user message was appended via
 * `operator<<`.
 *
 * It also defines `failed_requirement`, the exception thrown to stop a
 * test case after a failed `require()`.
 *
 * Both live in the `detail` namespace and are not part of the
 * public API.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_CHECK_RESULT_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_CHECK_RESULT_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "expression-formatter.h"
#include "extension.h"
#include "reflection.h"

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
  class test_case;

  // --------------------------------------------------------------------------

  namespace detail
  {
    // ========================================================================

    /**
     * @brief The exception thrown to stop a test case after a failed
     * `require()`.
     *
     * @details
     * Thrown by the destructor of `check_result`, after the
     * failure was reported and counted, when exceptions are enabled, and
     * caught by `test_case::run()`, which ends the test case normally; the
     * run continues with the next test case.
     *
     * It is deliberately not derived from `std::exception`, so that a
     * `catch (const std::exception&)` in the test case body does not stop
     * it; a `catch (...)` does, and should rethrow it.
     */
    struct failed_requirement
    {
    };

    // ========================================================================

    /**
     * @brief The kind of a check, which determines what happens when it
     * fails.
     *
     * @details
     * An enumeration rather than a Boolean flag, so that the call sites
     * name the kind of the check.
     */
    enum class check_kind
    {
      /**
       * @brief A check created by `expect()`.
       *
       * @details
       * A failure is reported and counted, and the test case continues.
       */
      expectation,

      /**
       * @brief A check created by `require()`.
       *
       * @details
       * A failure is reported and counted, and the test case is stopped,
       * or, without exceptions, the test execution is aborted.
       */
      requirement
    };

    // ========================================================================

    /**
     * @brief The details of a check, displayed when it fails.
     *
     * @details
     * Grouped in one object, passed to `reporter::fail()`, so that the
     * call sites do not pass unlabelled Boolean arguments. Held by
     * `check_result`, and built by `test_case` when reporting an
     * unexpected exception.
     *
     * The message is also displayed when the check passes.
     */
    struct failure_info
    {
      /**
       * @brief The kind of the check.
       *
       * @details
       * Determines whether the failure stops the test case, and whether
       * the reporter displays the abort notice.
       */
      check_kind kind;

      /**
       * @brief The message passed via `operator<<()`, if any.
       *
       * @details
       * Displayed before the expression and the source location.
       */
      std::string message;

      /**
       * @brief Indicates whether the check has an associated expression.
       *
       * @details
       * Set when the checked expression is a framework comparator, whose
       * formatted text is displayed on failure.
       */
      bool has_expression;

      /**
       * @brief The source location of the check.
       *
       * @details
       * Displayed with failures, and used when aborting.
       */
      reflection::source_location location;
    };

    // ========================================================================

    /**
     * @brief The result of one check, reported when destroyed.
     *
     * @details
     * Returned by `expect()` and `require()`, it lives until the end of
     * the expression statement. Its template constructor evaluates the
     * expression and formats it, with the actual operand values, into the
     * expression formatter of the reporter, which keeps the text for this
     * check until it is reported, so that it can be displayed on failure.
     * The messages passed via `operator<<()` are collected into a string.
     * The destructor reports the outcome, updates the counters of the test
     * case, and, after a failed `require()`, stops the test case.
     *
     * A passed check whose line the reporter never writes (see
     * `reporter::writes_passed_checks()`) formats neither its expression
     * nor its messages, and is only counted.
     *
     * Only the template constructor depends on the type of the expression;
     * it delegates to a private non-template constructor, and the
     * destructor, which does the reporting, is not a template either, so
     * this code is compiled once, in `src/check-result.cpp`, not for each
     * type of expression.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class check_result
    {
    public:
      /**
       * @brief Constructs the result of a check of an expression.
       *
       * @details
       * The expression is evaluated, and, if the outcome is written,
       * formatted into the expression formatter.
       *
       * @tparam Expr_T The type of the expression.
       *
       * @param expr The expression under evaluation.
       * @param kind The kind of the check, `check_kind::requirement` for
       * `require()`, whose failure stops the test case.
       * @param location The source location of the check.
       * @param test_case The test case that owns this check.
       * @param expression The expression formatter to format the expression
       * text.
       * @param writes_passed Whether the reporter writes the passed checks;
       * if not, a passed check is not formatted.
       */
      template <class Expr_T>
      check_result (const Expr_T& expr, check_kind kind,
                    const reflection::source_location& location,
                    test_case& test_case, expression_formatter& expression,
                    bool writes_passed);

      /**
       * @brief Deleted copy constructor to prevent copying.
       *
       * @details
       * Each instance reports exactly one check, from its destructor; a
       * copy would report it twice.
       */
      check_result (const check_result&) = delete;

      /**
       * @brief Deleted move constructor to prevent moving.
       *
       * @details
       * The instance is a temporary that lives only until the end of the
       * expression statement.
       */
      check_result (check_result&&) = delete;

      /**
       * @brief Deleted copy assignment operator to prevent copying.
       *
       * @details
       * Each instance reports exactly one check, from its destructor.
       */
      check_result&
      operator= (const check_result&)
          = delete;

      /**
       * @brief Deleted move assignment operator to prevent moving.
       *
       * @details
       * Each instance reports exactly one check, from its destructor.
       */
      check_result&
      operator= (check_result&&)
          = delete;

      /**
       * @brief Destructor that reports the check.
       *
       * @details
       * It may throw `failed_requirement`, after a failed `require()`, to
       * stop the test case, hence `noexcept (false)`.
       */
      ~check_result () noexcept (false);

      /**
       * @brief Appends a message to the check.
       *
       * @tparam T The type of the message to append.
       *
       * @param msg The message to append.
       * @return Reference to the current check result.
       */
      template <class T>
        requires extension::printable<T>
      auto&
      operator<< (const T& msg);

      /**
       * @brief Retrieves the result value.
       *
       * @par Parameters
       *   None.
       * @retval true  The checked condition was met.
       * @retval false The checked condition was not met.
       */
      [[nodiscard]] bool
      value (void) const noexcept;

    private:
      /**
       * @brief Constructs the result of a check from its parts.
       *
       * @details
       * The non-template part of the construction, shared by all the
       * instantiations of the template constructor, which delegates to it.
       *
       * @param value The result of the evaluated expression.
       * @param kind The kind of the check.
       * @param has_expression Indicates whether the expression is a
       * framework comparator, whose text is displayed on failure.
       * @param location The source location of the check.
       * @param test_case The test case that owns this check.
       * @param writes_passed Whether the reporter writes the passed checks.
       */
      check_result (bool value, check_kind kind, bool has_expression,
                    const reflection::source_location& location,
                    test_case& test_case, bool writes_passed);

      /**
       * @brief Stores the result value of the check.
       *
       * @details
       * The boolean value of the checked expression, computed by the
       * template constructor.
       */
      const bool value_;

      /**
       * @brief Whether the outcome of the check is written.
       *
       * @details
       * Set by the constructor for a failed check, and for a passed one
       * when the reporter writes the passed checks. When not set, the
       * expression and the messages are not formatted, and the destructor
       * only updates the counters.
       */
      const bool is_written_;

      /**
       * @brief The details displayed when the check fails.
       *
       * @details
       * The kind, the expression flag, and the location are set by the
       * constructor; the message is collected via `operator<<()`. Passed
       * to the reporter by the destructor; the message is also displayed
       * when the check passes.
       */
      failure_info info_;

      /**
       * @brief The number of uncaught exceptions when the check was
       * created.
       *
       * @details
       * If the destructor finds more, it runs during stack unwinding (for
       * a result kept in a variable), and must not throw.
       */
      int uncaught_exceptions_ = 0;

      /**
       * @brief Reference to the test case invoking this check.
       *
       * @details
       * Provides access to the reporter and to the totals to be updated.
       */
      test_case& test_case_;
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

#include "inlines/check-result-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_CHECK_RESULT_H_

// ----------------------------------------------------------------------------
