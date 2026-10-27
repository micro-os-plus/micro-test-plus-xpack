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
 * This header provides the `runner_options` class, which holds the
 * configuration of a test session (the reporter, the verbosity, the
 * output file, the use of colours, the filter, and the listing of the
 * test cases) and parses it from the command line, together with
 * the `reporter_kind`, `verbosity`, and `colour_mode` enumerations used
 * by its members.
 *
 * The options are usually parsed from the command line by the
 * constructor called by `runner::initialise (argc, argv)`; the
 * applications without a command line, such as the embedded ones without
 * semihosting arguments, can set them directly and pass them to
 * `runner::initialise (options)`.
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

#include <string>
#include <string_view>
#include <utility>
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
   * for the integration with other tools. The level affects only the
   * console output; the output file always receives the full report.
   *
   * The `quiet` level displays the failed checks, with the names of the
   * suite and of the test cases that contain them, and the totals; the
   * passed checks and the passed test cases are not displayed. To also
   * see them, use the `verbose` level, or keep `quiet` and use an output
   * file, which receives them.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  enum class verbosity
  {
    silent = 0, /**< No console output; only the exit code is returned. */
    quiet = 1, /**< Displays only the failed checks and the overall session
                  summary; the TAP reporter also displays one result line
                  per test suite, counted by the plan, and the failed
                  checks as comments. */
    normal = 2, /**< Displays test suite and test case results; the
                   individual checks are shown only for failures, the
                   passed checks being only counted. */
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
   * @brief The configuration of a test session, and its command-line
   * parser.
   *
   * @details
   * `runner::initialise (argc, argv)` constructs the options from the
   * command line and passes them to `runner::initialise (options)`, which
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
   * The applications can also parse the command line themselves, and
   * adjust the result before passing it to the runner:
   *
   * @code{.cpp}
   * mt::runner_options options{ argc, argv };
   * options.list_tests = true;
   *
   * auto& ts = tr.initialise (options, "Main");
   * @endcode
   *
   * The configuration members are public, since any combination of their
   * values is valid; only the results of the parsing (whether errors
   * were found, and whether the reporter was unknown) are private, and
   * are read by the runner.
   *
   * The options own their strings (the command line, the path of the
   * output file, and the filter patterns), so they do not depend on the
   * lifetime of the caller's strings; the runner keeps its own copy of
   * them.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   *
   * @since 5.1.0
   */
  class runner_options
  {
  public:
    /**
     * @brief Constructs the default options.
     *
     * @details
     * The TAP reporter, the `normal` verbosity, no output file, automatic
     * colours, no filter, and no command line; the test cases are run,
     * not listed.
     */
    runner_options (void) = default;

    /**
     * @brief Constructs the options by parsing the command line.
     *
     * @details
     * Starts from the defaults, and parses the µTest++ options
     * (`--reporter`, `--silent`, `--quiet`, `--verbose`, `--output-file`,
     * `--color`, `--use-colour`, `--filter`, and `--list-tests`). The
     * other arguments are ignored, since the applications may define
     * their own, except for those starting with `--`, which are reported
     * as unknown options.
     *
     * A missing option argument, an unknown reporter name, an unknown
     * colour mode, or an unknown option, is reported on `stderr`, the
     * option is ignored, and `has_errors()` is set; `run()` then returns
     * 2. The errors are not written in the report, since the reporter
     * does not exist yet.
     *
     * The `argv[]` strings are copied, so they need not outlive the
     * options.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     *
     * @since 5.1.0
     */
    explicit runner_options (int argc, char* argv[]);

    /**
     * @brief Copy constructor.
     *
     * @details
     * Copies all the members, including the strings and the results of
     * the parsing, so the copy initialises a runner exactly as the
     * original does; the copy is independent of the original.
     *
     * @param other The instance to copy.
     *
     * @since 5.1.0
     */
    runner_options (const runner_options& other) = default;

    /**
     * @brief Move constructor.
     *
     * @details
     * Moves the strings and the vectors, and copies the other members;
     * `other` is left valid, with unspecified strings.
     *
     * @param other The instance to move from.
     *
     * @since 5.1.0
     */
    runner_options (runner_options&& other) = default;

    /**
     * @brief Copy assignment operator.
     *
     * @details
     * Replaces all the members with copies of those of `other`.
     *
     * Not defaulted: it copies `other` with the copy constructor, and
     * moves the copy into this instance, since the copy assignment of the
     * vectors of strings uses `std::copy`, which triggers
     * `-Waggregate-return` in the standard library headers of GCC on some
     * targets. If the copy fails, this instance is not changed.
     *
     * @param other The instance to copy.
     * @return Reference to this instance.
     *
     * @since 5.1.0
     */
    runner_options&
    operator= (const runner_options& other);

    /**
     * @brief Move assignment operator.
     *
     * @details
     * Moves the strings and the vectors, and copies the other members.
     *
     * @param other The instance to move from.
     * @return Reference to this instance.
     *
     * @since 5.1.0
     */
    runner_options&
    operator= (runner_options&& other)
        = default;

    /**
     * @brief Destructor.
     *
     * @details
     * Releases the owned strings.
     */
    ~runner_options () = default;

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
     * @brief Path of the optional output file.
     *
     * @details
     * Set by `--output-file=<path>` or `--output-file <path>`. When it
     * is empty (the default), no file is written. The reporter opens the
     * file when it is created by `initialise()`; if the file cannot be opened, the error is reported
     * on `stderr`, the report is written only to the console, and
     * `runner::run()` returns 2.
     */
    std::string output_file_path{};

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
     * A copy of the `argv[]` strings of `main()`, set when the options
     * are parsed from the command line. When not empty, the reporters list it
     * at the beginning of the report, and `initialise()` derives the
     * default name of the top suite from `arguments[0]`.
     */
    std::vector<std::string> arguments{};

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
    std::vector<std::string> filter_patterns{};

    /**
     * @brief Whether the test cases are listed instead of run.
     *
     * @details
     * Set by the `--list-tests` option, or by its short form `--list`.
     * When set, the suite bodies run, as usual, to create their test
     * cases, but the bodies of the test cases do not, so no check is
     * evaluated. The selected test cases (see `filter_patterns`) are
     * listed under the names of their suites, as Catch2 lists them:
     *
     * @code{.txt}
     * All available test cases:
     *   Sample
     *     Check various conditions
     *     Check strings
     *   Explicit namespace suite
     *     Check one
     * 3 test cases in 2 test suites
     * @endcode
     *
     * The header is `Matching test cases:` when there are filter
     * patterns, and the suites without selected test cases are not
     * listed. The nested test cases are not listed, since they are
     * created by the bodies of their parents, which do not run. The list
     * is written to the console, unless the verbosity is `silent`, and to
     * the output file, if any; no report is written, and `run()` returns
     * 0, or 2 after an option error.
     *
     * @since 5.1.0
     */
    bool list_tests{ false };

    /**
     * @brief Checks whether errors were found while parsing the command
     * line.
     *
     * @details
     * The errors were already written on `stderr` by the constructor;
     * when set, `runner::run()` returns 2. Never set for the default
     * options.
     *
     * @return `true` if at least one error was found.
     *
     * @since 5.1.0
     */
    [[nodiscard]] bool
    has_errors (void) const noexcept;

    /**
     * @brief Checks whether the command line selected an unknown reporter.
     *
     * @details
     * When set, `runner::initialise()` does not proceed: no output file
     * is created, nothing is reported, no test is run, and `run()`
     * returns 2, even if `selected_reporter` was changed after the
     * parsing.
     *
     * @return `true` if the reporter name was not recognised.
     *
     * @since 5.1.0
     */
    [[nodiscard]] bool
    has_invalid_reporter (void) const noexcept;

  private:
    /**
     * @brief Records and reports a command-line error.
     *
     * @details
     * Writes `error: <text>` on `stderr`, and sets `has_errors_`.
     *
     * @param before The start of the message, without the `error:`
     * prefix.
     * @param value The variable part, usually an option or a value.
     * @param after The end of the message, without the newline.
     * @par Returns
     *   Nothing.
     */
    void
    add_error (std::string_view before, std::string_view value = {},
               std::string_view after = {});

    /**
     * @brief Whether errors were found while parsing the command line.
     *
     * @details
     * Set by `add_error()`; returned by `has_errors()`.
     */
    bool has_errors_{ false };

    /**
     * @brief Whether the reporter name was not recognised.
     *
     * @details
     * Set by the parsing constructor; returned by
     * `has_invalid_reporter()`.
     */
    bool has_invalid_reporter_{ false };
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

#include "inlines/runner-options-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_OPTIONS_H_

// ----------------------------------------------------------------------------
