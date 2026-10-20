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
 * results and the session, suite, and test case events to the concrete
 * reporters (`reporter_human` and `reporter_tap`).
 *
 * The formatting of the values and the comparison expressions is delegated
 * to `detail::expression_formatter`.
 *
 * The `verbosity` enumeration is defined in the
 * `micro_os_plus::micro_test_plus` namespace; the manipulators and the
 * reporter are defined in the `micro_os_plus::micro_test_plus::detail`
 * namespace, since the reporters are internal to the framework.
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

#include "check-result.h"
#include "detail.h"
#include "expression-formatter.h"
#include "extension.h"
#include "reflection.h"
#include "runner-options.h"

#include <cstdio>
#include <string_view>
#include <string>
#include <memory>
#include <span>
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

  // Forward definitions.
  class runner;
  class suite;
  class test_case;

  namespace detail
  {
    class check_result;
    class reporter;
    class stopwatch;

    /**
     * @brief Output stream manipulator for ending a line in test reports.
     *
     * @details
     * Calls `reporter::end_line()`, which appends a line ending to the
     * internal buffer. Unlike `std::endl`, it does not flush; the buffer
     * is written later, by the concrete reporters.
     *
     * @param stream Reference to the `reporter` instance.
     * @return Reference to the same `reporter` instance, enabling chaining
     * of output operations.
     */
    reporter&
    endl (reporter& stream);

    // ------------------------------------------------------------------------

    /**
     * @brief Parameterised stream manipulator for outputting indentation.
     *
     * @details
     * Holds the indentation level; used with `reporter::operator<<` so
     * that `*this << indent(n) << "text"` works naturally in chains.
     */
    struct indentation
    {
      /**
       * @brief Number of four-space indentation levels.
       *
       * @details
       * Converted into spaces by `reporter::operator<<`.
       */
      size_t level;
    };

    /**
     * @brief Factory function that creates an `indentation` manipulator.
     *
     * @details
     * Allows writing `reporter << indent(n)` instead of constructing the
     * manipulator explicitly.
     *
     * @param level The number of four-space indentation levels.
     * @return An `indentation` value for use with `operator<<`.
     */
    [[nodiscard]] indentation
    indent (size_t level);

    // ========================================================================

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
     * pre-formatted by its `expression_formatter` (with type suffixes
     * for numbers), supporting precise diagnostics and efficient debugging.
     * The class supports multiple verbosity levels and colour-coded output to
     * distinguish between successful and failed checks.
     *
     * The pure virtual member functions report the beginning and end of the
     * session, the suites, and the test cases, and format the pass and fail
     * results; they are implemented by `reporter_human` and `reporter_tap`.
     * The concrete reporter is created by the runner, as selected by the
     * `--reporter` command-line option.
     *
     * The reporters are internal to the framework: their public members are
     * the protocol between the runner, the test nodes, the checks, and the
     * reporter, and custom reporters are not supported. The applications
     * select a reporter with the `--reporter` command-line option, and read
     * the verbosity with `runner::verbosity_level()`.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class reporter
    {
      // Pass the expression formatter to the checks, and format their
      // expressions.
      friend class micro_test_plus::test_case;
      friend class check_result;

    public:
      /**
       * @brief Constructor for the reporter class.
       *
       * @param opts The session options, passed to `runner::initialise()`
       * or parsed by it from the command line.
       */
      explicit reporter (const runner_options& opts);

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

      /**
       * @brief Output operator for the `indentation` manipulator.
       *
       * @details
       * Appends `indent_size_` spaces for each indentation level.
       *
       * @param m The indentation manipulator produced by `indent(n)`.
       * @return Reference to the current reporter instance.
       */
      reporter&
      operator<< (indentation m);

      // ----------------------------------------------------------------------

      /**
       * @brief Appends a line ending to the internal output buffer.
       *
       * @details
       * Nothing is written to the console or to the output file; the
       * buffer is written by the concrete reporters, at the end of each
       * test case or suite.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      void
      end_line (void);

      /**
       * @brief Output the current buffered content to the console.
       *
       * @details
       * The console is the standard output stream; the buffer is written
       * verbatim, without appending a line ending, and is not cleared.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      void
      write_buffer_to_console (void);

      /**
       * @brief Flushes the standard output stream and the output file.
       *
       * @details
       * Only the C streams are flushed; the internal output buffer is not
       * written.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      void
      flush_streams (void);

      /**
       * @brief Returns whether the output file could not be opened.
       *
       * @details
       * Checked by `runner::initialise()`, which reports it as an option
       * error; the report is then written only to the console.
       *
       * @par Parameters
       *   None.
       * @retval true The output file was requested but could not be
       * opened.
       * @retval false No output file was requested, or it was opened.
       */
      [[nodiscard]] bool
      has_output_file_error (void) const noexcept;

      // ----------------------------------------------------------------------

      /**
       * @brief Report a passed condition.
       *
       * @param message The message to display.
       * @param expression The string representation of the expression.
       * @param test_case The test case that owns this check.
       * @par Returns
       *   Nothing.
       */
      void
      pass (const std::string& message, const std::string& expression,
            const test_case& test_case);

      /**
       * @brief Report a failed condition.
       *
       * @param failure The failure details: the kind of the check, the
       * message to display, whether the expression is a compound op to
       * display, and the source location of the failure.
       * @param expression The string representation of the expression.
       * @param test_case The test case that owns this check.
       * @par Returns
       *   Nothing.
       */
      void
      fail (const failure_info& failure, const std::string& expression,
            const test_case& test_case);

      // ----------------------------------------------------------------------

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
      begin_session (const runner& runner)
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
      end_session (const runner& runner)
          = 0;

      /**
       * @brief Mark the beginning of a test suite.
       *
       * @details
       * Called by `suite::run()` before the suite body, for the suites
       * registered with `runner::add_suite()` and for the static suites, and
       * by `runner::initialise()` for the top suite.
       *
       * @param suite Reference to the test suite.
       * @par Returns
       *   Nothing.
       */
      virtual void
      begin_suite (const suite& suite)
          = 0;

      /**
       * @brief Mark the end of a test suite.
       *
       * @details
       * Called by `suite::run()` after the suite body, also when an
       * exception escaped it, for the suites registered with
       * `runner::add_suite()` and for the static suites, and by
       * `runner::run()` for the top suite; implementations display the
       * suite results.
       *
       * @param suite Reference to the test suite.
       * @par Returns
       *   Nothing.
       */
      virtual void
      end_suite (const suite& suite)
          = 0;

      /**
       * @brief Report a test suite skipped by the filter.
       *
       * @details
       * Called by `runner::run_suites()`, instead of running the suite,
       * when its name does not match the first filter pattern; the suite
       * has already been assigned its index. Implementations display a
       * single line, without the suite body.
       *
       * @param suite Reference to the skipped test suite.
       * @par Returns
       *   Nothing.
       *
       * @since 5.1.0
       */
      virtual void
      skip_suite (const suite& suite)
          = 0;

      /**
       * @brief Report a failure of a test suite outside its test cases.
       *
       * @details
       * Called by `suite::run()` when an exception escapes the suite body,
       * between `begin_suite()` and `end_suite()`; the suite has already
       * advanced to its next test point, which numbers the failure after
       * the test cases already run. Implementations add a failed line to
       * the output buffer, at the indentation of the test cases, which
       * `end_suite()` displays; there is no source location to show.
       *
       * @param message The message to display.
       * @param suite Reference to the test suite.
       * @par Returns
       *   Nothing.
       * @since 5.1.0
       */
      virtual void
      fail_suite (const std::string& message, const suite& suite)
          = 0;

      /**
       * @brief Mark the beginning of a test case.
       *
       * @details
       * Called by `test_case::run()` before the test case body; the output
       * buffer is expected to be empty at this point.
       *
       * @param test_case Reference to the test case.
       * @par Returns
       *   Nothing.
       */
      virtual void
      begin_test_case (const test_case& test_case)
          = 0;

      /**
       * @brief Mark the end of a test case.
       *
       * @details
       * Called by `test_case::run()` after the test case body; implementations
       * display the test case results and clear the output buffer.
       *
       * @param test_case Reference to the test case.
       * @par Returns
       *   Nothing.
       */
      virtual void
      end_test_case (const test_case& test_case)
          = 0;

      /**
       * @brief Report a test case skipped by the filter.
       *
       * @details
       * Called instead of `begin_test_case()` and `end_test_case()`, when the
       * name of the test case, or of its suite, does not match the filter
       * pattern of its level; the test case has already been assigned its
       * index. Implementations display a single line, at the indentation
       * of the test case.
       *
       * @param test_case Reference to the skipped test case.
       * @par Returns
       *   Nothing.
       *
       * @since 5.1.0
       */
      virtual void
      skip_test_case (const test_case& test_case)
          = 0;

      /**
       * @brief Report the abort of the test execution.
       *
       * @details
       * Called by `runner::abort()` between `begin_session()` and
       * `end_session()`, before the abort handler and `::abort()`;
       * neither the `end_test_case()` of the running test cases, if any,
       * nor `end_session()` are called afterwards. The abort is caused
       * either by a failed `require()`, when exceptions are disabled,
       * after the failure was added to the output buffer, or by an
       * explicit call of `runner::abort()`, from a test case body, from a
       * suite body, or from the application.
       *
       * Implementations display the buffered results, if any, with the
       * context that identifies the running test case, followed by a
       * line with the location of the abort, unless the verbosity is
       * silent, and write them to the output file, if open, since the
       * totals are never reached. They then clear the buffer, since the
       * abort handler may throw an exception that the application
       * catches, and the results must not be written again.
       *
       * @param location The source location of the failed requirement,
       * or of the `runner::abort()` call.
       * @param is_requirement `true` if the abort is caused by a failed
       * requirement.
       * @par Returns
       *   Nothing.
       *
       * @since 5.1.0
       */
      virtual void
      abort_session (const reflection::source_location& location,
                     bool is_requirement)
          = 0;

      /**
       * @brief Returns the comment-prefix string used by this reporter format.
       *
       * @details
       * Used by `write_info()` to prefix the informational lines, so that
       * they are valid comments in the output format.
       *
       * @par Parameters
       *   None.
       * @return A null-terminated prefix string.
       */
      virtual const char*
      comment_prefix (void) const noexcept
          = 0;

      // ----------------------------------------------------------------------

    protected:
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
      write_buffer_to_file (void);

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
      write_console (const char* format, ...)
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
      write_file (const char* format, ...)
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
      write_info (void);

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
      clear_buffer (void);

      /**
       * @brief Size of the array that receives the elapsed time text.
       *
       * @details
       * Large enough for `", time: 4294967295.999 ms"`, the longest text
       * produced by `format_elapsed_time()`.
       */
      static constexpr size_t elapsed_time_size_ = 32;

      /**
       * @brief Formats the elapsed time of a suite or of the session.
       *
       * @details
       * The text is appended to the summary lines by the concrete
       * reporters, in the form `", time: 1.234 ms"`; it is empty when
       * the stopwatch has no elapsed time, so that the summary lines
       * remain identical on the platforms without a clock.
       *
       * The array has a fixed size, known at compile time, so that the
       * compiler can verify that the text is never truncated.
       *
       * @param stopwatch The stopwatch of the suite or of the runner.
       * @param message The character array that receives the
       * null-terminated text.
       * @par Returns
       *   Nothing.
       */
      static void
      format_elapsed_time (const stopwatch& stopwatch,
                           char (&message)[elapsed_time_size_]);

      /**
       * @brief Outputs the prefix for a passing condition.
       *
       * @details
       * Called by `pass()` before the expression text; the prefix includes
       * the message, if any.
       *
       * @param message The message to display.
       * @param test_case The test case that owns this check.
       * @par Returns
       *   Nothing.
       */
      virtual void
      output_pass_prefix (const std::string& message,
                          const test_case& test_case)
          = 0;

      /**
       * @brief Outputs the suffix for a passing condition.
       *
       * @details
       * Called by `pass()` after the expression text, to complete the line.
       *
       * @param test_case The test case that owns this check.
       * @par Returns
       *   Nothing.
       */
      virtual void
      output_pass_suffix (const test_case& test_case)
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
       * @param test_case The test case that owns this check.
       * @par Returns
       *   Nothing.
       */
      virtual void
      output_fail_prefix (const std::string& message,
                          const bool has_expression,
                          const reflection::source_location& location,
                          const test_case& test_case)
          = 0;

      /**
       * @brief Outputs the suffix for a failing condition.
       *
       * @details
       * Called by `fail()` after the expression text, to complete the
       * output. The kind of the check lets a reporter show that a failed
       * requirement stops the test case, or aborts the test execution.
       *
       * @param location The source location of the failure.
       * @param kind The kind of the check (expectation or requirement).
       * @param test_case The test case that owns this check.
       * @par Returns
       *   Nothing.
       */
      virtual void
      output_fail_suffix (const reflection::source_location& location,
                          check_kind kind, const test_case& test_case)
          = 0;

    protected:
      /**
       * @brief Number of spaces per nesting level.
       *
       * @details
       * Used by the concrete reporters to indent the lines of the nested
       * test cases; four spaces is also the TAP 14 subtest indentation.
       */
      static constexpr size_t indent_size_ = 4;

      /**
       * @brief The verbosity level for test reporting.
       *
       * @details
       * A copy of the level kept by the runner, set by the constructor from
       * the same session options and not changed afterwards. The public
       * accessor is `runner::verbosity_level()`.
       */
      const micro_test_plus::verbosity verbosity_;

      /**
       * @brief ANSI colour codes for output formatting.
       *
       * @details
       * Empty strings by default; the concrete reporters may assign
       * `detail::colours_red_green` when the console supports colours.
       */
      colours colours_{};

      /**
       * @brief Output accumulation buffer.
       *
       * @details
       * Accumulates all reporter output until it is written to the
       * console or the output file via `write_buffer_to_console()` or
       * `write_buffer_to_file()`.
       */
      std::string buffer_{};

      /**
       * @brief Whether the output buffer contains a failed check.
       *
       * @details
       * Set by `fail()` and reset by `clear_buffer()`. When a nested test
       * case begins, the concrete reporters use it to decide whether the
       * results already buffered for the outer test case are displayed
       * with normal verbosity.
       */
      bool buffer_has_failures_{ false };

      /**
       * @brief Expression formatter for pass and fail reporting.
       *
       * @details
       * Used by the checks (`test_case::expect()`,
       * `test_case::require()`, and `detail::check_result`), which are
       * friends, to pre-format expressions at construction time; `pass()`
       * and `fail()` then append the formatted text to `buffer_`. The
       * applications format their own types by defining `operator<<` for
       * the public `expression_formatter` alias.
       */
      expression_formatter expression_{ colours_ };

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
       * Copied by the constructor from the session options, so that the
       * caller's string need not outlive `runner::initialise()`. Used to
       * name the file in the confirmation message displayed when the file
       * is closed (not displayed with the `silent` verbosity).
       */
      std::string output_file_path_{};

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
       * @brief Whether the output file could not be opened.
       *
       * @details
       * Set by the constructor, and returned by `has_output_file_error()`.
       */
      bool has_output_file_error_{ false };

      /**
       * @brief The command-line arguments passed to the test runner.
       *
       * @details
       * A view of the `argv[]` array of `main()`, copied from the
       * session options by the constructor, and listed by `write_info()`,
       * which is called only by `begin_session()`, within
       * `runner::initialise()`; it is not used afterwards.
       */
      std::span<char* const> arguments_{};
    };

    // ------------------------------------------------------------------------
  } // namespace detail
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
