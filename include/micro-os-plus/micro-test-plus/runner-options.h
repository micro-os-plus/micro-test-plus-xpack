/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ header file with declarations for the µTest++ runner options.
 *
 * @details
 * This header provides the `runner_options` structure, which holds the
 * configuration of a test session (the reporter, the verbosity, the
 * output file, the use of colours, and the suite filter), together with
 * the `reporter_kind`, `verbosity`, and `colour_mode` enumerations used
 * by its members.
 *
 * The options are usually parsed from the command line by
 * `runner::initialise (argc, argv)`; the applications without a command
 * line, such as the embedded ones without semihosting arguments, can set
 * them directly and pass them to `runner::initialise (options)`.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * The header is included through `micro-test-plus.h` and should not be
 * included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_OPTIONS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_OPTIONS_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include <span>
#include <string_view>
#include <vector>

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
   * command-line options, or with `runner_options::verbosity_level`; the
   * default is `normal`. The console output is intended for the people
   * who watch the tests run, while the optional output file is intended
   * for the integration with other tools. With the TAP reporter, the
   * level affects only the console output, and the output file always
   * receives the full report. The human reporter is intended for the
   * console; its output file receives the full report only with the
   * `normal` and `verbose` levels, and is incomplete otherwise.
   *
   * The `quiet` level tells whether the run failed, but not what
   * failed: the failed checks, their locations, and their test cases
   * are not displayed (except for a test case that aborts the test
   * execution, when exceptions are not enabled, since the summary is
   * never reached). To learn what failed, use the `normal` level,
   * which displays in full only the failed test cases, or keep
   * `quiet` and use the TAP reporter with an output file, which
   * receives them.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  enum class verbosity
  {
    silent = 0, /**< No console output; only the exit code is returned. */
    quiet = 1, /**< Displays only the overall session summary; the TAP
                  reporter also displays one result line per test suite,
                  counted by the plan. The failed checks are not
                  displayed. */
    normal = 2, /**< Displays test suite and test case results; the
                   individual checks are shown only for failures. */
    verbose = 3 /**< Displays all results, including passed checks, for maximum
                   detail. */
  };

  /**
   * @brief The built-in reporters.
   *
   * @details
   * Selected with the `--reporter` command-line option, or with
   * `runner_options::selected_reporter`; the default is `tap`.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   *
   * @since 5.1.0
   */
  enum class reporter_kind
  {
    tap, /**< The TAP reporter, compliant with TAP version 14. */
    human /**< The human-readable reporter, with optional colours. */
  };

  /**
   * @brief The use of colours in the console output.
   *
   * @details
   * Selected with the `--color` command-line option (or its alternative,
   * `--use-colour`), or with `runner_options::colour`; the default is
   * `automatic`. The names follow the values of `--color` in the GNU
   * tools.
   *
   * Only the human reporter uses colours; the TAP reporter never does,
   * since the ANSI escape sequences are not part of the TAP syntax. The
   * output file never receives colours, whatever the mode.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   *
   * @since 5.1.0
   */
  enum class colour_mode
  {
    automatic, /**< Colours are used when `stdout` is a terminal; on the
                  platforms without `isatty()`, such as the embedded
                  ones, they are not used. */
    always, /**< Colours are always used, for example in the CI systems
               that render the ANSI escape sequences but do not provide a
               terminal, or on embedded targets whose output is displayed
               by a terminal. */
    never /**< Colours are never used. */
  };

  // ==========================================================================

  /**
   * @brief The configuration of a test session.
   *
   * @details
   * `runner::initialise (argc, argv)` parses the command-line options into
   * this structure and passes it to `runner::initialise (options)`, which
   * creates the selected reporter and starts the session.
   *
   * The applications that do not have a command line, such as the
   * embedded ones without semihosting arguments, can define the options
   * directly, starting from the defaults, and call the second overload:
   *
   * @code{.cpp}
   * mt::runner_options options{};
   * options.selected_reporter = mt::reporter_kind::human;
   * options.verbosity_level = mt::verbosity::verbose;
   *
   * auto& ts = tr.initialise (options, "Main");
   * @endcode
   *
   * The structure only refers to the strings it uses; they must remain
   * valid until `initialise()` returns, which copies what it keeps.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   *
   * @since 5.1.0
   */
  struct runner_options
  {
    /**
     * @brief The reporter that displays the results.
     *
     * @details
     * Set by `--reporter=<name>` or `--reporter <name>`, where the name
     * is `tap` or `human`.
     */
    reporter_kind selected_reporter{ reporter_kind::tap };

    /**
     * @brief The level of detail of the console output.
     *
     * @details
     * Set by `--silent`, `--quiet`, or `--verbose`; when several are
     * given, the last one takes effect.
     */
    micro_test_plus::verbosity verbosity_level{
      micro_test_plus::verbosity::normal
    };

    /**
     * @brief Path of the optional output file, or `nullptr`.
     *
     * @details
     * Set by `--output-file=<path>` or `--output-file <path>`. When it
     * is `nullptr` or empty, no file is written. The reporter opens the
     * file, and keeps a copy of the path, when it is created by
     * `initialise()`; if the file cannot be opened, the program exits
     * with an error message.
     */
    const char* output_file_path{ nullptr };

    /**
     * @brief Whether the console output uses colours.
     *
     * @details
     * Set by `--color[=<when>]`, as in the GNU tools, where `<when>` is
     * `always`, `never`, or `auto`, or one of their GNU synonyms (`yes`
     * and `force`, `no` and `none`, `tty` and `if-tty`), and `--color`
     * alone means `always`; the value is accepted only after `=`. The
     * alternative `--use-colour=<mode>` or `--use-colour <mode>`, as in
     * Catch2 and Boost UT, takes `yes`, `no`, or `auto`, and also accepts
     * the other values of `--color`. Used only by the human reporter.
     *
     * @since 5.1.0
     */
    colour_mode colour{ colour_mode::automatic };

    /**
     * @brief The complete command line, including `argv[0]`, if any.
     *
     * @details
     * A view of the `argv[]` array of `main()`, set when the options are
     * parsed from the command line. When not empty, the reporters list it
     * at the beginning of the report, and `initialise()` derives the
     * default name of the top suite from `arguments[0]`.
     */
    std::span<char* const> arguments{};

    /**
     * @brief The patterns that select the suites and the test cases to
     * run, one per nesting level.
     *
     * @details
     * Each `--filter=<pattern>` or `--filter <pattern>` option adds one
     * pattern; unlike the other options, `--filter` may be repeated. As
     * with `--grep` in node-tap, the first pattern applies to the suite
     * names, the second to the names of the test cases, and each further
     * pattern to the names of the test cases nested one level deeper; the
     * levels without a pattern are not filtered.
     *
     * Within a pattern, `|` separates alternatives; a name matches when
     * it matches any of them, as defined by `utility::is_match()`: `*`
     * matches any sequence of characters, `?` matches any single
     * character, the match is case-sensitive, and the alternative must
     * cover the whole name.
     *
     * The suites and the test cases that do not match are reported as
     * skipped, and their bodies are not called. The top suite is never
     * skipped as a whole, since its body is `main()`, but when its name
     * does not match the first pattern, all its test cases are skipped.
     *
     * When the list is empty (the default), everything runs.
     *
     * @since 5.1.0
     */
    std::vector<std::string_view> filter_patterns{};
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_OPTIONS_H_

// ----------------------------------------------------------------------------
