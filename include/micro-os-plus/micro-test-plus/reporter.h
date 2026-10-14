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
 * within the µTest++ framework. It defines the `verbosity` levels, the
 * `endl` and `indent()` stream manipulators, and the abstract `reporter`
 * base class, which accumulates output in a buffer, writes it to the
 * console and to an optional output file, and dispatches the pass/fail
 * results and the session, suite, and subtest events to the concrete
 * reporters (`reporter_human` and `reporter_tap`).
 *
 * The formatting of the values and the comparison expressions is delegated
 * to `detail::expression_formatter`.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_H_

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
#include "detail.h"
#include "expression-formatter.h"
#include "reflection.h"

#include <cstdio>
#include <string_view>
#include <string>
#include <memory>
#include <vector>
#include <charconv>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
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

  /**
   * @brief The verbosity levels for test reporting.
   *
   * @details
   * The `verbosity` enumeration defines the available levels of detail for
   * test output produced by the reporting system. These levels control the
   * amount and type of information displayed during test execution, allowing
   * users to tailor the output to their specific requirements.
   *
   * The level is selected with the `--silent`, `--quiet`, and `--verbose`
   * command-line options; the default is `normal`. It affects only the
   * console output; the optional output file always receives the full
   * report.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  enum class verbosity
  {
    silent = 0, /**< No console output; only the exit code is returned. */
    quiet = 1, /**< Displays only the overall session summary. */
    normal = 2, /**< Displays test suite and test case results; the
                   individual checks are shown only for failures. */
    verbose = 3 /**< Displays all results, including passed checks, for maximum
                   detail. */
  };

  // Forward definitions.
  class reporter;
  class runner;
  class suite;
  class subtest;

  namespace detail
  {
    class deferred_reporter_base;
  } // namespace detail

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
     * Holds the indentation level; used with `operator<<` on the concrete
     * reporters so that `*this << indent(n) << "text"` works naturally in
     * chains.
     */
    struct indent_t
    {
      /**
       * @brief Number of four-space indentation levels.
       *
       * @details
       * Converted into spaces by the concrete reporters.
       */
      size_t level;
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  /**
   * @brief Factory function that creates an `indent_t` manipulator.
   *
   * @details
   * Allows writing `reporter << indent(n)` instead of constructing the
   * manipulator explicitly.
   *
   * @param level The number of four-space indentation levels.
   * @return An `indent_t` value for use with `operator<<`.
   */
  [[nodiscard]] detail::indent_t
  indent (size_t level);

  // ==========================================================================

  /**
   * @brief Abstract base class for the reporters that display test
   * results, including operand values for failures.
   *
   * @details
   * The `reporter` class is responsible for presenting test results within
   * the µTest++ framework. It accumulates output in a buffer, using basic
   * output operators for strings, characters, booleans, numbers, and
   * pointers, and writes it to the console and to an optional output file.
   *
   * For failed checks, the reporter prints the actual values of the operands,
   * pre-formatted by its `detail::expression_formatter` (with type suffixes
   * for numbers), supporting precise diagnostics and efficient debugging.
   * The class supports multiple verbosity levels and colour-coded output to
   * distinguish between successful and failed checks.
   *
   * The pure virtual methods report the beginning and end of the session,
   * the suites, and the subtests, and format the pass and fail results; they
   * are implemented by `reporter_human` and `reporter_tap`. The concrete
   * reporter is created by the runner, as selected by the `--reporter`
   * command-line option.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class reporter
  {
    // Pass the expression formatter to the checks, and format their
    // expressions.
    friend class subtest;
    friend class detail::deferred_reporter_base;

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
     *
     * @details
     * Virtual, so that the concrete reporters, owned through a pointer to
     * this base class, are destroyed correctly.
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
     * @details
     * Also selected for the non-const `char` pointers and arrays, which
     * the pointer template does not accept. A null pointer is output as
     * `"nullptr"`.
     *
     * @param s The string to output, or a null pointer.
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
     *
     * @return Reference to the current reporter instance.
     */
    reporter& operator<< (std::nullptr_t);

    /**
     * @brief Output operator for arithmetic types.
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
     * @details
     * The `char` pointers are excluded, so that they are output as
     * strings by the `const char*` overload, as the `const char`
     * pointers are.
     *
     * @tparam T The type pointed to, other than `char`.
     *
     * @param v The pointer value to output.
     * @return Reference to the current reporter instance.
     */
    template <typename T>
      requires (not std::is_same_v<T, char>)
    reporter&
    operator<< (T* v);

    /**
     * @brief Output operator for stream manipulators, such as `endl`.
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
     * @brief Inserts a line ending into the output buffer and flushes the
     * output streams.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    endline (void);

    /**
     * @brief Output the current buffered content to the console.
     *
     * @details
     * The console is the standard output stream; the buffer is written
     * verbatim, without appending a line ending, and is not cleared.
     *
     * @note Public because `deferred_reporter_base` calls this
     *   from its destructor when aborting, after the subtest
     *   instance is no longer accessible via the normal
     *   reporting path.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    write_buffer_to_console (void);

    /**
     * @brief Flush the standard output stream and the output file.
     *
     * @par Parameters
     *   None.
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
     * @details
     * Called by `runner::initialise()`, after the reporter is created;
     * implementations display the session heading.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_session (runner& runner)
        = 0;

    /**
     * @brief Mark the end of a test session.
     *
     * @details
     * Called by `runner::run()`, after all suites have run;
     * implementations display the session summary.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_session (runner& runner)
        = 0;

    /**
     * @brief Mark the beginning of a test suite.
     *
     * @details
     * Called by `suite::run()` and `static_suite::run()` before the suite
     * body, and by `runner::initialise()` for the top suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_suite (suite& suite)
        = 0;

    /**
     * @brief Mark the end of a test suite.
     *
     * @details
     * Called by `suite::run()` and `static_suite::run()` after the suite
     * body, and by `runner::run()` for the top suite;
     * implementations display the suite results.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_suite (suite& suite)
        = 0;

    /**
     * @brief Mark the beginning of a subtest.
     *
     * @details
     * Called by `subtest::run()` before the subtest body; the output
     * buffer is expected to be empty at this point.
     *
     * @param subtest Reference to the subtest.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_subtest (subtest& subtest)
        = 0;

    /**
     * @brief Mark the end of a subtest.
     *
     * @details
     * Called by `subtest::run()` after the subtest body; implementations
     * display the subtest results and clear the output buffer.
     *
     * @param subtest Reference to the subtest.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_subtest (subtest& subtest)
        = 0;

    /**
     * @brief Returns the comment-prefix string used by this reporter format.
     *
     * @details
     * Used by `write_info_()` to prefix the informational lines, so that
     * they are valid comments in the output format.
     *
     * @par Parameters
     *   None.
     * @return A null-terminated prefix string.
     */
    virtual const char*
    get_comment_prefix (void)
        = 0;

    /**
     * @brief Returns the current verbosity level.
     *
     * @par Parameters
     *   None.
     * @return The active `verbosity` value.
     */
    auto
    verbosity () const -> micro_test_plus::verbosity;

    // ------------------------------------------------------------------------

  protected:
    /**
     * @brief Provides access to the expression formatter for this reporter.
     *
     * @details
     * Protected, since the formatter is an implementation detail; it is
     * used only by the checks (`subtest::expect()`, `subtest::assume()`,
     * and the deferred reporter), which are friends, and by the derived
     * reporters. The applications format their own types by defining
     * `operator<<` for the public `expression_formatter` alias.
     *
     * @par Parameters
     *   None.
     * @return Reference to the `expression_formatter` instance used by this
     * reporter.
     */
    detail::expression_formatter&
    expression ();

    /**
     * @brief Selects the appropriate colour code based on a condition.
     *
     * @param cond Boolean value indicating pass (true) or fail (false).
     * @return The corresponding ANSI colour code as a string.
     */
    [[nodiscard]] inline auto
    colour_ (const bool cond) const;

    /**
     * @brief Output the current buffered content to the output file.
     *
     * @details
     * The buffer is written without appending a line ending, and is not
     * cleared. ANSI colour sequences are removed, so the file receives
     * plain text even when the console output is coloured. If no output
     * file is open, the call has no effect.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    write_buffer_to_file_ (void);

    /**
     * @brief Write formatted text to the console.
     *
     * @details
     * All reporter console output is routed through this function, so
     * that it reaches the standard output stream via a single path,
     * shared with the output of the user `printf()` calls. Using one
     * stream-based path keeps the reporter and user output in the same
     * buffer, preserving their relative order.
     *
     * @param format A `printf()`-style format string.
     * @param ... The arguments referred to by the format string.
     * @par Returns
     *   Nothing.
     */
    void
    write_console_ (const char* format, ...)
#if defined(__GNUC__)
        __attribute__ ((format (printf, 2, 3)))
#endif // defined(__GNUC__)
        ;

    /**
     * @brief Write formatted text to the output file.
     *
     * @details
     * If no output file is open, the call has no effect, so callers do
     * not need to check `output_file_` themselves.
     *
     * @param format A `printf()`-style format string.
     * @param ... The arguments referred to by the format string.
     * @par Returns
     *   Nothing.
     */
    void
    write_file_ (const char* format, ...)
#if defined(__GNUC__)
        __attribute__ ((format (printf, 2, 3)))
#endif // defined(__GNUC__)
        ;

    /**
     * @brief Writes the informational (non-result) lines to the console
     * and to the output file.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    write_info_ (void);

    /**
     * @brief Clears the output buffer.
     *
     * @details
     * Also resets `buffer_has_failures_`, so that the flag always
     * describes the current content of the buffer.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    clear_buffer_ (void);

    /**
     * @brief Outputs the prefix for a passing condition.
     *
     * @details
     * Called by `pass()` before the expression text; the prefix includes
     * the message, if any.
     *
     * @param message The message to display.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_pass_prefix_ (std::string& message, subtest& subtest)
        = 0;

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @details
     * Called by `pass()` after the expression text, to complete the line.
     *
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_pass_suffix_ (subtest& subtest)
        = 0;

    /**
     * @brief Outputs the prefix for a failing condition.
     *
     * @details
     * Called by `fail()` before the expression text; the prefix includes
     * the message, if any, and the source location.
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
                         subtest& subtest)
        = 0;

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @details
     * Called by `fail()` after the expression text, to complete the
     * output, including the abort notice, if any.
     *
     * @param location The source location of the failure.
     * @param abort Whether to abort execution after failure.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_fail_suffix_ (const reflection::source_location& location,
                         bool abort, subtest& subtest)
        = 0;

  protected:
    /**
     * @brief The verbosity level for test reporting.
     *
     * @details
     * Set by the constructor from the command-line options.
     */
    enum verbosity verbosity_ = verbosity::normal;

    /**
     * @brief ANSI colour codes for output formatting.
     *
     * @details
     * Empty strings by default; the concrete reporters may assign
     * `detail::colours_red_green` when the console supports colours.
     */
    detail::colours colours_{};

    /**
     * @brief Output accumulation buffer.
     *
     * @details
     * Accumulates all reporter output until it is written to the
     * console or the output file via `write_buffer_to_console()` or
     * `write_buffer_to_file_()`.
     */
    std::string buffer_{};

    /**
     * @brief Whether the output buffer contains a failed check.
     *
     * @details
     * Set by `fail()` and reset by `clear_buffer_()`. When a nested test
     * case begins, the concrete reporters use it to decide whether the
     * results already buffered for the outer test case are displayed
     * with normal verbosity.
     */
    bool buffer_has_failures_{ false };

    /**
     * @brief Expression formatter for pass and fail reporting.
     *
     * @details
     * Used by `detail::deferred_reporter` to pre-format expressions at
     * construction time; `pass()` and `fail()` then append the formatted
     * text to `buffer_`.
     */
    detail::expression_formatter expression_{ colours_ };

    /**
     * @brief Controls whether to add an empty line between successful test
     * cases.
     *
     * @details
     * Used by the concrete reporters to insert blank lines between groups
     * of output lines.
     */
    bool add_empty_line_{ true };

    /**
     * @brief Path of the optional output file.
     *
     * @details
     * Set from the `--output-file` command-line option; it points into the
     * original `argv[]` string. Used to name the file in the confirmation
     * message displayed when the file is closed.
     */
    const char* output_file_path_{ nullptr };

    /**
     * @brief Optional output file, receiving a copy of the test report.
     *
     * @details
     * When non-null, the report is written to this file in addition to
     * the console, without colour sequences and regardless of the
     * verbosity. The file is opened by the constructor and closed by the
     * destructor.
     */
    FILE* output_file_{ nullptr };

    /**
     * @brief Owns the command-line arguments passed to the test runner.
     *
     * @details
     * Parsed by the constructor for options, and listed by
     * `write_info_()`.
     */
    std::unique_ptr<std::vector<std::string_view>> argvs_{};
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/reporter-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_H_

// ----------------------------------------------------------------------------
