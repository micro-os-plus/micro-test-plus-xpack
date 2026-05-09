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
 * @brief C++ header file with declarations for the µTest++ test reporter.
 *
 * @details
 * This header provides the declarations for the test reporting facilities used
 * within the µTest++ framework. It defines the interfaces for formatting and
 * outputting test results, including operator overloads for a wide range of
 * value types, containers, and comparison expressions, as well as structured
 * output for logical and exception-related assertions.
 *
 * The test reporter is responsible for presenting test outcomes in a clear,
 * consistent, and expressive manner, supporting both value and pointer
 * semantics, and providing detailed diagnostics for both successful and failed
 * test cases. Special attention is given to formatting, colour highlighting,
 * and extensibility, enabling professional and readable test reports suitable
 * for embedded and general C++ development.
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

#ifndef MICRO_TEST_PLUS_TEST_REPORTER_H_
#define MICRO_TEST_PLUS_TEST_REPORTER_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstdio>
#include <string_view>
#include <string>
#include <memory>
#include <vector>
#include <charconv>

#include "type-traits.h"
#include "detail.h"
#include "expression-formatter.h"
#include "reflection.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// =============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @brief The verbosity levels for test reporting.
   *
   * @details
   * The `verbosity` enumeration defines the available levels of detail for
   * test output produced by the reporting system. These levels control the
   * amount and type of information displayed during test execution, allowing
   * users to tailor the output to their specific requirements.
   *
   * Selecting an appropriate verbosity level enhances the usability of test
   * reports, whether for concise summaries or comprehensive diagnostics.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  enum class verbosity
  {
    silent = 0, /**< No output is produced; only the exit code is returned. */
    quiet = 1, /**< Displays results for test suites only. */
    normal = 2, /**< Displays results for test suites and failed test cases. */
    verbose = 3 /**< Displays all results, including passed checks, for maximum
                   detail. */
  };

  // Forward definitions.
  class reporter;
  class runner;
  class suite;
  class subtest;

  /**
   * @brief Output stream manipulator for ending a line in test reports.
   *
   * @param stream Reference to the `reporter` instance.
   * @return Reference to the same `reporter` instance, enabling chaining
   * of output operations.
   */
  reporter&
  endl (reporter& stream);

  namespace detail
  {
    // ------------------------------------------------------------------------

    /**
     * @brief Parameterised stream manipulator for outputting indentation.
     *
     * @details
     * Holds the indentation level; used with `operator<<` on `reporter`
     * so that `*this << indent(n) << "text"` works naturally in chains.
     */
    struct indent_t
    {
      size_t level; /**< @brief Number of four-space indentation levels. */
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  /**
   * @brief Factory function that creates an `indent_t` manipulator.
   *
   * @param level The number of four-space indentation levels.
   * @return An `indent_t` value for use with `operator<<`.
   */
  [[nodiscard]] detail::indent_t
  indent (size_t level);

  // ==========================================================================

  /**
   * @brief Reporter to display test results, including operand values and
   * types for failures.
   *
   * @details
   * The `reporter` class is responsible for formatting and presenting
   * test results within the µTest++ framework. It provides a comprehensive
   * suite of output operators for a wide range of data types, containers, and
   * comparator expressions, enabling detailed and informative reporting of
   * test outcomes.
   *
   * For failed tests, the reporter prints the actual values of the operands
   * along with their types, supporting precise diagnostics and efficient
   * debugging. The class supports multiple verbosity levels and colour-coded
   * output to distinguish between successful and failed tests, thereby
   * enhancing the clarity and professionalism of test reports.
   *
   * The `reporter` also offers methods for reporting the commencement and
   * completion of test cases and suites, as well as for handling pass and fail
   * conditions. Additional features include output stream manipulators,
   * support for exception-related expressions, and configurable formatting
   * options.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class reporter
  {
  public:
    /**
     * @brief Constructor for the reporter class.
     *
     * @param argvs Owning pointer to the command-line arguments vector;
     * the reporter takes ownership via move.
     */
    reporter (std::unique_ptr<std::vector<std::string_view>> argvs);

    /**
     * @brief Virtual destructor for the reporter class.
     */
    virtual ~reporter ();

    /**
     * @brief Output operator for std::string_view.
     *
     * @param sv The string view to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (std::string_view sv);

    /**
     * @brief Output operator for a single character.
     *
     * @param c The character to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (char c);

    /**
     * @brief Output operator for a constant character string.
     *
     * @param s The string to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (const char* s);

    /**
     * @brief Output operator for boolean values.
     *
     * @param v The boolean value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (bool v);

    /**
     * @brief Output operator for nullptr.
     * @return Reference to the current reporter instance.
     */
    reporter& operator<< (std::nullptr_t);

    /**
     * @brief Output operator for arithmetic types, with type suffixes.
     *
     * @tparam T The arithmetic type.
     *
     * @param v The value to output.
     * @return Reference to the current reporter instance.
     */
    template <class T>
      requires std::is_arithmetic_v<T>
    reporter&
    operator<< (T v);

    /**
     * @brief Output operator to display any pointer.
     *
     * @tparam T The type of the pointer.
     *
     * @param v The pointer value to output.
     * @return Reference to the current reporter instance.
     */
    template <typename T>
    reporter&
    operator<< (T* v);

    /**
     * @brief Output operator to display the endl.
     *
     * @param func Function pointer to the stream manipulator.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (reporter& (*func) (reporter&));

    // ------------------------------------------------------------------------
    // Specific operators.

    // ------------------------------------------------------------------------

    /**
     * @brief Inserts a line ending into the output buffer.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    endline (void);

    /**
     * @brief Output the current buffered content.
     *
     * @note Public because `deferred_reporter_base` calls this
     *   from its destructor when aborting, after the subtest
     *   instance is no longer accessible via the normal
     *   reporting path.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    write_buffer_to_stdout (void);

    /**
     * @brief Flush the current buffered content.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    flush (void);

    // ------------------------------------------------------------------------

    /**
     * @brief Report a passed condition.
     *
     * @param message The message to display.
     * @param expression The string representation of the expression.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    pass (std::string& message, const std::string& expression,
          subtest& subtest);

    /**
     * @brief Report a failed condition.
     *
     * @param abort Whether to abort execution after failure.
     * @param message The message to display.
     * @param expression The string representation of the expression.
     * @param has_expression Whether the expression is a compound op to
     * display.
     * @param location The source location of the failure.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    fail (bool abort, std::string& message, const std::string& expression,
          bool has_expression, const reflection::source_location& location,
          subtest& subtest);

    // ------------------------------------------------------------------------

    /**
     * @brief Mark the beginning of a test session.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_session (runner& runner) = 0;

    /**
     * @brief Mark the end of a test session.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_session (runner& runner) = 0;

    /**
     * @brief Mark the beginning of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_suite (suite& suite) = 0;

    /**
     * @brief Mark the end of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_suite (suite& suite) = 0;

    /**
     * @brief Mark the beginning of a subtest.
     *
     * @param subtest Reference to the subtest.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_subtest (subtest& subtest) = 0;

    /**
     * @brief Mark the end of a subtest.
     *
     * @param subtest Reference to the subtest.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_subtest (subtest& subtest) = 0;

    /**
     * @brief Returns the comment-prefix string used by this reporter format.
     *
     * @par Parameters
     *	 None.
     * @return A null-terminated prefix string.
     */
    virtual const char*
    get_comment_prefix (void) = 0;

    /**
     * @brief Returns the current verbosity level.
     *
     * @par Parameters
     *	 None.
     * @return The active `verbosity` value.
     */
    auto
    verbosity () const -> micro_test_plus::verbosity;

    /**
     * @brief Provides access to the expression formatter for this reporter.
     *
     * @par Parameters
     *	 None.
     * @return Reference to the `expression_formatter` instance used by this
     * reporter.
     */
    detail::expression_formatter&
    expression ();

    // ------------------------------------------------------------------------

  protected:
    /**
     * @brief Selects the appropriate colour code based on a condition.
     *
     * @param cond Boolean value indicating pass (true) or fail (false).
     * @return The corresponding ANSI colour code as a string.
     */
    [[nodiscard]] inline auto
    colour_ (const bool cond) const;

    void
    write_buffer_to_file_ (void);

    /**
     * @brief Appends informational (non-result) text to the output buffer.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    write_info_ (void);

    /**
     * @brief Outputs the prefix for a passing condition.
     *
     * @param message The message to display.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_pass_prefix_ (std::string& message, subtest& subtest) = 0;

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_pass_suffix_ (subtest& subtest) = 0;

    /**
     * @brief Outputs the prefix for a failing condition.
     *
     * @param message The message to display.
     * @param has_expression Whether the failure is associated with an
     * expression.
     * @param location The source location of the failure.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_fail_prefix_ (std::string& message, const bool has_expression,
                         const reflection::source_location& location,
                         subtest& subtest) = 0;

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @param location The source location of the failure.
     * @param abort Whether to abort execution after failure.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_fail_suffix_ (const reflection::source_location& location,
                         bool abort, subtest& subtest) = 0;

  protected:
    /**
     * @brief The verbosity level for test reporting.
     */
    enum verbosity verbosity_ = verbosity::normal;

    /**
     * @brief ANSI colour codes for output formatting.
     */
    detail::colours colours_{};

    /**
     * @brief Output accumulation buffer.
     *
     * @details
     * Accumulates all reporter output until it is written to standard
     * output or the output file via `write_buffer_to_stdout()` or
     * `write_buffer_to_file_()`.
     */
    std::string buffer_{};

    /**
     * @brief Expression formatter for pass and fail reporting.
     *
     * @details
     * Used in `pass()` and `fail()` to format expression values before
     * appending the result to `buffer_`. Will also be used by
     * `detail::deferred_reporter` to pre-format expressions at
     * construction time.
     */
    detail::expression_formatter expression_{ colours_ };

    /**
     * @brief Controls whether to add an empty line between successful test
     * cases.
     *
     * @details
     * Used to nicely format the output.
     */
    bool add_empty_line_{ true };

    /**
     * @brief Optional file path for redirecting test report output.
     *
     * @details
     * When non-null, `write_buffer_to_file_()` writes accumulated output
     * to this path in addition to (or instead of) standard output.
     */
    const char* output_file_path_{ nullptr };

    /**
     * @brief Optional output file for redirecting test report output.
     *
     * @details
     * When non-null, all output is written to this file instead of
     * standard output. The reporter does not own the file; the caller
     * is responsible for its lifetime.
     */
    FILE* output_file_{ nullptr };

    /**
     * @brief Owns the command-line arguments passed to the test runner.
     */
    std::unique_ptr<std::vector<std::string_view>> argvs_{};
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ============================================================================
// Templates & constexpr implementations.

#include "inlines/reporter-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_REPORTER_H_

// ----------------------------------------------------------------------------
