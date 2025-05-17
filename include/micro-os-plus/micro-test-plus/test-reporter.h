/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file test-reporter.h
 * @brief Reporting of test results for the µTest++ testing framework.
 *
 * @details
 * This header defines the `test_reporter` class and related types, which are
 * responsible for formatting and presenting test results within the µTest++
 * framework.
 *
 * The `test_reporter` class offers a comprehensive suite of output operators
 * for various data types, containers, and comparator expressions, enabling
 * detailed and informative reporting of test outcomes. It supports multiple
 * verbosity levels and colour-coded output to distinguish between successful
 * and failed tests.
 *
 * The file also defines supporting types such as `colors` and `verbosity`, and
 * provides methods for reporting the commencement and completion of test cases
 * and suites, as well as for handling pass and fail conditions.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
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
#include <string_view>
#include <string>

#include "type-traits.h"
#include "test-suite.h"
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
    const char* none = "\033[0m"; /**< @brief Default colour. */
    const char* pass = "\033[32m"; /**< @brief Green colour. */
    const char* fail = "\033[31m"; /**< @brief Red colour. */
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
  typedef verbosity verbosity_t;

  // Forward definition.
  class test_reporter;

  /**
   * @brief Output stream manipulator for ending a line in test reports.
   *
   * @param stream Reference to the `test_reporter` instance.
   * @return Reference to the same `test_reporter` instance, enabling chaining
   * of output operations.
   */
  test_reporter&
  endl (test_reporter& stream);

  // Requires events::assertion_* for  and detailed operators.

  /**
   * @brief Reporter to display test results, including operand values and
   * types for failures.
   *
   * @details
   * The `test_reporter` class is responsible for formatting and presenting
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
   * The `test_reporter` also offers methods for reporting the commencement and
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
  class test_reporter
  {
  public:
    /**
     * @brief Default constructor for the test_reporter class.
     */
    test_reporter () = default;

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
    color (const bool cond)
    {
      return cond ? colors_.pass : colors_.fail;
    }

    /**
     * @brief Output operator for std::string_view.
     *
     * @param sv The string view to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (std::string_view sv);

    /**
     * @brief Output operator for a single character.
     *
     * @param c The character to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (char c);

    /**
     * @brief Output operator for a constant character string.
     *
     * @param s The string to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (const char* s);

    /**
     * @brief Output operator for a mutable character string.
     *
     * @param s The string to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (char* s);

    /**
     * @brief Output operator for boolean values.
     *
     * @param v The boolean value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (bool v);

    /**
     * @brief Output operator for nullptr.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter& operator<< (std::nullptr_t);

    /**
     * @brief Output operator for signed char values.
     *
     * @param c The signed char value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (signed char c);

    /**
     * @brief Output operator for unsigned char values.
     *
     * @param c The unsigned char value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (unsigned char c);

    /**
     * @brief Output operator for signed short values.
     *
     * @param c The signed short value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (signed short c);

    /**
     * @brief Output operator for unsigned short values.
     *
     * @param c The unsigned short value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (unsigned short c);

    /**
     * @brief Output operator for signed int values.
     *
     * @param v The signed int value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (signed int v);

    /**
     * @brief Output operator for unsigned int values.
     *
     * @param v The unsigned int value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (unsigned int v);

    /**
     * @brief Output operator for signed long values.
     *
     * @param v The signed long value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (signed long v);

    /**
     * @brief Output operator for unsigned long values.
     *
     * @param v The unsigned long value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (unsigned long v);

    /**
     * @brief Output operator for signed long long values.
     *
     * @param v The signed long long value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (signed long long v);

    /**
     * @brief Output operator for unsigned long long values.
     *
     * @param v The unsigned long long value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (unsigned long long v);

    /**
     * @brief Output operator for float values.
     *
     * @param v The float value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (float v);

    /**
     * @brief Output operator for double values.
     *
     * @param v The double value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (double v);

    /**
     * @brief Output operator for long double values.
     *
     * @param v The long double value to output.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (long double v);

    /**
     * @brief Output operator to display any pointer.
     *
     * @tparam T The type of the pointer.
     *
     * @param v The pointer value to output.
     * @return Reference to the current test_reporter instance.
     */
    template <typename T>
    test_reporter&
    operator<< (T* v);

    /**
     * @brief Output operator to display the endl.
     *
     * @param func Function pointer to the stream manipulator.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter&
    operator<< (test_reporter& (*func) (test_reporter&));

    // ------------------------------------------------------------------------
    // Specific operators.

    /**
     * @brief Output operator for types with a getter.
     *
     * @tparam T The type with a getter method.
     *
     * @param t The object to output.
     * @return Reference to the current test_reporter instance.
     */
    template <class T>
    test_reporter&
    operator<< (const T& t);

    /**
     * @brief Output operator to display genuine integers, without the type
     * suffix.
     *
     * @tparam T The underlying integral type.
     *
     * @param v The strongly-typed integral value to output.
     * @return Reference to the current test_reporter instance.
     */
    template <class T>
    test_reporter&
    operator<< (const type_traits::genuine_integral_value<T>& v);

    /**
     * @brief Output operator to display containers. Iterates all members.
     *
     * @tparam T The container type.
     *
     * @param t The container to output.
     * @return Reference to the current test_reporter instance.
     */
    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>
                                      and not type_traits::has_npos_v<T>>
              = 0>
    test_reporter&
    operator<< (T&& t);

    /**
     * @brief Output operator to display eq() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The equality comparator expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::eq_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display ne() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The inequality comparator expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::ne_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display gt() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The greater-than comparator expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::gt_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display ge() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The greater-than-or-equal-to comparator expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::ge_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display lt() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The less-than comparator expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::lt_<Rhs_T, Lhs_T>& op);

    /**
     * @brief Output operator to display le() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The less-than-or-equal-to comparator expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::le_<Rhs_T, Lhs_T>& op);

    /**
     * @brief Output operator to display and() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The logical conjunction (AND) expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::and_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display or() expressions.
     *
     * @tparam Lhs_T The left-hand side type.
     * @tparam Rhs_T The right-hand side type.
     *
     * @param op The logical disjunction (OR) expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::or_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display not() expressions.
     *
     * @tparam T The operand type.
     *
     * @param op The logical negation expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class T>
    test_reporter&
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
     * @return Reference to the current test_reporter instance.
     */
    template <class Expr_T, class Exception_T>
    test_reporter&
    operator<< (const detail::throws_<Expr_T, Exception_T>& op);

    /**
     * @brief Output operator to display throws expressions for any exception.
     *
     * @tparam Expr_T The expression type.
     *
     * @param op The throws comparator expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Expr_T>
    test_reporter&
    operator<< (const detail::throws_<Expr_T, void>& op);

    /**
     * @brief Output operator to display nothrow expressions.
     *
     * @tparam Expr_T The expression type.
     *
     * @param op The nothrow comparator expression.
     * @return Reference to the current test_reporter instance.
     */
    template <class Expr_T>
    test_reporter&
    operator<< (const detail::nothrow_<Expr_T>& op);
#endif

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
    pass (Expr_T& expr, std::string& message);

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
          const reflection::source_location& location);

    /**
     * @brief Mark the beginning of a test case.
     *
     * @param name The name of the test case.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test_case (const char* name);

    /**
     * @brief Mark the end of a test case.
     *
     * @param name The name of the test case.
     * @par Returns
     *   Nothing.
     */
    void
    end_test_case (const char* name);

    /**
     * @brief Mark the beginning of a test suite.
     *
     * @param name The name of the test suite.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test_suite (const char* name);

    /**
     * @brief Mark the end of a test suite.
     *
     * @param suite Reference to the test suite base.
     * @par Returns
     *   Nothing.
     */
    void
    end_test_suite (test_suite_base& suite);

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

    /**
     * @brief Output the current buffered content.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    output (void);

    /**
     * @brief Controls whether to add an empty line between successful test
     * cases.
     *
     * @details
     * Used to nicely format the output.
     */
    bool add_empty_line{ true };

    /**
     * @brief The verbosity level for test reporting.
     */
    verbosity_t verbosity{};

  protected:
    /**
     * @brief Outputs the prefix for a passing condition.
     *
     * @param message The message to display.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_prefix_ (std::string& message);

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_suffix_ (void);

    /**
     * @brief Outputs the prefix for a failing condition.
     *
     * @param message The message to display.
     * @param location The source location of the failure.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_prefix_ (std::string& message,
                         const reflection::source_location& location);

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @param abort Whether to abort execution after failure.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_suffix_ (bool abort);

    /**
     * @brief ANSI colour codes for output formatting.
     */
    colors colors_{};

    /**
     * @brief Internal output buffer for accumulating report content.
     */
    std::string out_{};

    /**
     * @brief Indicates whether the reporter is currently within a test case.
     */
    bool is_in_test_case_ = false;
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
