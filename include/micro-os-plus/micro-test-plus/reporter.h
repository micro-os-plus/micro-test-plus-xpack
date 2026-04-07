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

// #include <functional>
#include <stdio.h>
#include <string_view>
#include <string>

#include "type-traits.h"
#include "detail.h"

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
   * @struct colors
   * @brief Colours used to highlight pass and fail results in test reports.
   *
   * @details
   * The `colors` structure defines ANSI escape sequences for terminal output,
   * enabling colour-coded highlighting of test outcomes. The `pass` member
   * specifies the colour for successful results (typically green), while the
   * `fail` member specifies the colour for failed results (typically red). The
   * `none` member resets the colour to the terminal default.
   *
   * These colour codes enhance the clarity and professionalism of test reports
   * by making it immediately apparent which tests have passed or failed,
   * thereby improving the overall user experience when reviewing test results.
   *
   * @var colors::none
   * ANSI escape sequence to reset the terminal colour to default.
   * @var colors::pass
   * ANSI escape sequence to set the terminal colour for passing results
   * (green).
   * @var colors::fail
   * ANSI escape sequence to set the terminal colour for failing results (red).
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  struct colors
  {
    const char* none = ""; /**< @brief Default colour. */
    const char* pass = ""; /**< @brief Green colour. */
    const char* fail = ""; /**< @brief Red colour. */
  };

  inline constexpr colors colors_red_green = {
    "\033[0m", /**< @brief Default colour. */
    "\033[32m", /**< @brief Green colour. */
    "\033[31m" /**< @brief Red colour. */
  };

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

  /**
   * @brief Type alias for the verbosity enumeration used in test reporting.
   *
   * @details
   * The `verbosity_t` type alias provides a convenient shorthand for referring
   * to the `verbosity` enumeration, which defines the available levels of
   * detail for test output within the reporting system.
   *
   * Using this alias improves code readability and consistency throughout the
   * framework, especially when specifying or configuring verbosity levels for
   * test reporters.
   */
  using verbosity_t = verbosity;

  // Forward definitions.
  class reporter;
  class runner;

  /**
   * @brief Output stream manipulator for ending a line in test reports.
   *
   * @param stream Reference to the `reporter` instance.
   * @return Reference to the same `reporter` instance, enabling chaining
   * of output operations.
   */
  reporter&
  endl (reporter& stream);

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

  /**
   * @brief Factory function that creates an `indent_t` manipulator.
   *
   * @param level The number of four-space indentation levels.
   * @return An `indent_t` value for use with `operator<<`.
   */
  [[nodiscard]] inline indent_t
  indent (size_t level)
  {
    return { level };
  }

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
     * @details
     * Parses the command-line arguments to determine the desired verbosity
     * level and applies it to the reporter. The `--verbose`, `--quiet`, and
     * `--silent` options are recognised.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     */
    reporter (int argc, char* argv[]);

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
     * @brief Output operator for a mutable character string.
     *
     * @param s The string to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (char* s);

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
     * @brief Output operator for signed char values.
     *
     * @param c The signed char value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (signed char c);

    /**
     * @brief Output operator for unsigned char values.
     *
     * @param c The unsigned char value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (unsigned char c);

    /**
     * @brief Output operator for signed short values.
     *
     * @param v The signed short value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (signed short v);

    /**
     * @brief Output operator for unsigned short values.
     *
     * @param v The unsigned short value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (unsigned short v);

    /**
     * @brief Output operator for signed int values.
     *
     * @param v The signed int value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (signed int v);

    /**
     * @brief Output operator for unsigned int values.
     *
     * @param v The unsigned int value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (unsigned int v);

    /**
     * @brief Output operator for signed long values.
     *
     * @param v The signed long value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (signed long v);

    /**
     * @brief Output operator for unsigned long values.
     *
     * @param v The unsigned long value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (unsigned long v);

    /**
     * @brief Output operator for signed long long values.
     *
     * @param v The signed long long value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (signed long long v);

    /**
     * @brief Output operator for unsigned long long values.
     *
     * @param v The unsigned long long value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (unsigned long long v);

    /**
     * @brief Output operator for float values.
     *
     * @param v The float value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (float v);

    /**
     * @brief Output operator for double values.
     *
     * @param v The double value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (double v);

    /**
     * @brief Output operator for long double values.
     *
     * @param v The long double value to output.
     * @return Reference to the current reporter instance.
     */
    reporter&
    operator<< (long double v);

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

    /**
     * @brief Output operator for types with a getter.
     *
     * @tparam T The type with a getter method.
     *
     * @param t The object to output.
     * @return Reference to the current reporter instance.
     */
    template <class T>
      requires type_traits::is_op_v<T>
    reporter&
    operator<< (const T& t);

    /**
     * @brief Output operator to display genuine integers, without the type
     * suffix.
     *
     * @tparam T The underlying integral type.
     *
     * @param v The strongly-typed integral value to output.
     * @return Reference to the current reporter instance.
     */
    template <class T>
    reporter&
    operator<< (const type_traits::genuine_integral_value<T>& v);

    /**
     * @brief Output operator to display containers. Iterates all members.
     *
     * @tparam T The container type.
     *
     * @param t The container to output.
     * @return Reference to the current reporter instance.
     */
    template <class T>
      requires (type_traits::container_like<T>
                and not type_traits::has_npos<T>)
    reporter&
    operator<< (T&& t);

    /**
     * @brief Output operator to display eq() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The equality comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    reporter&
    operator<< (const detail::eq_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display ne() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The inequality comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    reporter&
    operator<< (const detail::ne_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display gt() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The greater-than comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    reporter&
    operator<< (const detail::gt_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display ge() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The greater-than-or-equal-to comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    reporter&
    operator<< (const detail::ge_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display lt() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The less-than comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    reporter&
    operator<< (const detail::lt_<Rhs_T, Lhs_T>& op);

    /**
     * @brief Output operator to display le() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The less-than-or-equal-to comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    reporter&
    operator<< (const detail::le_<Rhs_T, Lhs_T>& op);

    /**
     * @brief Output operator to display and() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The logical conjunction (AND) expression.
     * @return Reference to the current reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    reporter&
    operator<< (const detail::and_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display or() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The logical disjunction (OR) expression.
     * @return Reference to the current reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    reporter&
    operator<< (const detail::or_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display not() expressions.
     *
     * @tparam T The operand type.
     *
     * @param op The logical negation expression.
     * @return Reference to the current reporter instance.
     */
    template <class T>
    reporter&
    operator<< (const detail::not_<T>& op);

#if defined(__cpp_exceptions)
    /**
     * @brief Output operator to display throws expressions for a specific
     * exception type.
     *
     * @tparam Expr_T The expression type.
     * @tparam Exception_T The exception type.
     *
     * @param op The throws comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Expr_T, class Exception_T>
    reporter&
    operator<< (const detail::throws_<Expr_T, Exception_T>& op);

    /**
     * @brief Output operator to display throws expressions for any exception.
     *
     * @tparam Expr_T The expression type.
     *
     * @param op The throws comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Expr_T>
    reporter&
    operator<< (const detail::throws_<Expr_T, void>& op);

    /**
     * @brief Output operator to display nothrow expressions.
     *
     * @tparam Expr_T The expression type.
     *
     * @param op The nothrow comparator expression.
     * @return Reference to the current reporter instance.
     */
    template <class Expr_T>
    reporter&
    operator<< (const detail::nothrow_<Expr_T>& op);
#endif

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
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    write_buffer_to_stdout (void);

    // ------------------------------------------------------------------------

    /**
     * @brief Report a passed condition.
     *
     * @tparam Expr_T The expression type.
     *
     * @param expr The evaluated expression.
     * @param message The message to display.
     * @par Returns
     *   Nothing.
     */
    template <class Expr_T>
    void
    pass (Expr_T& expr, std::string& message, subtest& subtest);

    /**
     * @brief Report a failed condition.
     *
     * @tparam Expr_T The expression type.
     *
     * @param expr The evaluated expression.
     * @param abort Whether to abort execution after failure.
     * @param message The message to display.
     * @param location The source location of the failure.
     * @par Returns
     *   Nothing.
     */
    template <class Expr_T>
    void
    fail (Expr_T& expr, bool abort, std::string& message,
          const reflection::source_location& location, subtest& subtest);

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

    virtual const char*
    get_comment_prefix (void) = 0;

    // ------------------------------------------------------------------------

  protected:
    /**
     * @brief Selects the appropriate colour code based on a condition.
     *
     * @param cond Boolean value indicating pass (true) or fail (false).
     * @return The corresponding ANSI colour code as a string.
     *
     * @details
     * Returns the ANSI colour code for pass or fail, depending on the boolean
     * condition provided.
     */
    [[nodiscard]] inline auto
    color (const bool cond) const
    {
      return cond ? colors_.pass : colors_.fail;
    }

    void
    write_buffer_to_file (void);

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

    void
    write_info (void);

    /**
     * @brief Outputs the prefix for a passing condition.
     *
     * @param message The message to display.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_pass_prefix_ (std::string& message, subtest& subtest) = 0;

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_pass_suffix_ (subtest& subtest) = 0;

    /**
     * @brief Outputs the prefix for a failing condition.
     *
     * @param message The message to display.
     * @param hasExpression Whether the failure is associated with an
     * expression.
     * @param location The source location of the failure.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_fail_prefix_ (std::string& message, const bool hasExpression,
                         const reflection::source_location& location,
                         subtest& subtest) = 0;

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @param location The source location of the failure.
     * @param abort Whether to abort execution after failure.
     * @par Returns
     *   Nothing.
     */
    virtual void
    output_fail_suffix_ (const reflection::source_location& location,
                         bool abort, subtest& subtest) = 0;

  public:
    /**
     * @brief The verbosity level for test reporting.
     */
    verbosity_t verbosity{};

  protected:
    /**
     * @brief ANSI colour codes for output formatting.
     */
    colors colors_{};

    /**
     * @brief Internal output buffer for accumulating report content.
     */
    std::string buffer_{};

    /**
     * @brief Controls whether to add an empty line between successful test
     * cases.
     *
     * @details
     * Used to nicely format the output.
     */
    bool add_empty_line_{ true };

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
     * @brief Stores the argument count passed to the test runner.
     */
    int argc_ = 0;

    /**
     * @brief Stores the argument vector passed to the test runner.
     */
    char** argv_ = nullptr;

  private:
    /**
     * @brief Appends the string representation of a numeric value to a
     * buffer, using `std::to_chars` for allocation-free, locale-independent
     * formatting.
     *
     * @tparam T The numeric type to format.
     *
     * @param buffer The string to append to.
     * @param v The value to format.
     * @par Returns
     *   Nothing.
     */
    template <class T>
    static void
    append_number (std::string& buffer, T v);
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_REPORTER_H_

// ----------------------------------------------------------------------------
