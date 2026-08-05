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
 * @brief C++ header file with declarations for the µTest++ human test
 * reporter.
 *
 * @details
 * This header provides the declaration for `reporter_human`, the default
 * concrete implementation of the `reporter` abstract interface. It
 * formats and presents test results using `printf`-based standard output,
 * accumulating output in an internal string buffer and supporting
 * colour-coded diagnostics and multiple verbosity levels.
 *
 * Users who require custom output behaviour (e.g. redirecting to a serial
 * port on bare-metal targets) may derive a new class from `reporter`
 * instead of using this class.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_REPORTER_BASIC_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_REPORTER_BASIC_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "reporter.h"
#include "reflection.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  class runner;
  class suite;
  class subtest;

  // ==========================================================================

  /**
   * @brief Human (standard output) implementation of `reporter`.
   *
   * @details
   * `reporter_human` provides the default concrete implementation of the
   * `reporter` abstract interface, formatting and presenting test results
   * using `printf`-based output. It accumulates output in an internal string
   * buffer and writes it to the standard output stream, supporting
   * colour-coded diagnostics and multiple verbosity levels.
   *
   * Users who require custom output behaviour (e.g. redirecting to a serial
   * port on bare-metal targets) may derive a new class from `reporter`
   * and supply an instance via the `reporter` global pointer before calling
   * `initialize()`.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class reporter_human final : public reporter
  {
  public:
    /**
     * @brief Constructor for the reporter_human class.
     *
     * @param argvs Owning pointer to the command-line arguments vector;
     * the reporter takes ownership via move.
     */
    reporter_human (std::unique_ptr<std::vector<std::string_view>> argvs);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    reporter_human (const reporter_human&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    reporter_human (reporter_human&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    reporter_human&
    operator= (const reporter_human&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    reporter_human&
    operator= (reporter_human&&)
        = delete;

    /**
     * @brief Destructor for the reporter_human class.
     */
    ~reporter_human () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Output operator for the `indent_t` manipulator.
     *
     * @param m The indentation manipulator produced by `indent(n)`.
     * @return Reference to the current reporter instance.
     */
    reporter_human&
    operator<< (detail::indent_t m);

    // Bring base class operator<< overloads into scope to prevent name hiding.
    using reporter::operator<<;

    // ------------------------------------------------------------------------

    /**
     * @brief Mark the beginning of a test session.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    void
    begin_session (runner& runner) override;

    /**
     * @brief Mark the end of a test session.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    void
    end_session (runner& runner) override;

    /**
     * @brief Mark the beginning of a suite.
     *
     * @param suite Reference to the suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_suite (suite& suite) override;

    /**
     * @brief Mark the end of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_suite (suite& suite) override;

    /**
     * @brief Mark the beginning of a subtest.
     *
     * @param subtest Reference to the subtest.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_subtest (subtest& subtest) override;

    /**
     * @brief Mark the end of a subtest.
     *
     * @param subtest Reference to the subtest.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_subtest (subtest& subtest) override;

    /**
     * @brief Returns an empty comment prefix string.
     *
     * @par Parameters
     *	 None.
     * @return An empty string, as the human-readable format does not
     * use a comment prefix.
     */
    virtual const char*
    get_comment_prefix (void) override;

  protected:
    /**
     * @brief Outputs the prefix for a passing condition.
     *
     * @param message The message to display.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_prefix_ (std::string& message, subtest& subtest) override;

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_suffix_ (subtest& subtest) override;

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
    void
    output_fail_prefix_ (std::string& message, const bool has_expression,
                         const reflection::source_location& location,
                         subtest& subtest) override;

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @param location The source location of the failure.
     * @param abort Whether to abort execution after failure.
     * @param subtest The subtest that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_suffix_ (const reflection::source_location& location,
                         bool abort, subtest& subtest) override;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_REPORTER_BASIC_H_

// ----------------------------------------------------------------------------
