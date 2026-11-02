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
 * @brief C++ source file with implementations for the µTest++ runner
 * options.
 *
 * @details
 * This source file contains the command-line parser of the µTest++
 * framework, implemented by the `runner_options` constructor taking the
 * `main()` arguments, and the recording of the errors it finds.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/runner-options.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

#include <string>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wc++20-compat"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

  /**
   * @details
   * Scans the arguments after `argv[0]`, in order, for:
   *
   * - `--reporter=<name>` or `--reporter <name>`, with `tap` (the default)
   *   or `human`;
   * - `--verbose`, `--quiet`, and `--silent`;
   * - `--output-file=<path>` or `--output-file <path>`;
   * - `--colour[=<when>]`, or its American spelling `--color[=<when>]`,
   *   as in the GNU tools, with `always`, `never`, or `auto` (the
   *   default), and their GNU synonyms (`yes` and `force`, `no` and
   *   `none`, `tty` and `if-tty`); `--colour` alone means `always`;
   * - `--use-colour=<mode>` or `--use-colour <mode>`, or the American
   *   spelling `--use-color`, the Catch2 and Boost UT alternative to
   *   `--colour`, with `yes`, `no`, or `auto`, or any of the `--colour`
   *   values;
   * - `--filter=<pattern>` or `--filter <pattern>`;
   * - `--list-tests`, or its short form `--list`, as in Catch2 and
   *   Boost UT, to list the test cases instead of running them;
   * - `--help`, or its short form `-h`, to display the usage instead of
   *   running the tests.
   *
   * When an option is repeated, the last one takes effect, except
   * `--filter`, whose patterns are all kept, in order, one per nesting
   * level; `--colour`, `--color`, `--use-colour`, and `--use-color` set
   * the same option. An option argument given separately is the next
   * argument, whatever its content; `--colour` and `--color` accept their
   * value only after `=`.
   *
   * The parsing ends at the first argument that does not start with a
   * dash, or at the first `--` alone; the arguments from there on are
   * left to the application, and are not interpreted, so they can be
   * options of the application. The `--` itself is not an application
   * argument. An argument that starts with a dash, before that point,
   * and is not a µTest++ option, is reported as an unknown option. The
   * whole command line is copied into `arguments_`, to be listed by the
   * reporter; the option values are copied from there.
   *
   * A missing option argument, an unknown reporter name, an unknown
   * colour mode, a colour mode given separately after `--colour` or
   * `--color`, or an unknown option (any other argument that starts with
   * a dash, including a single one), is recorded by `add_error()`, and
   * the option is ignored; the parsing continues with the next
   * argument, to record all the errors. Nothing is written by the
   * constructor; the runner then writes the errors and refuses to run
   * the tests.
   */
  runner_options::runner_options (int argc, char* argv[])
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (argc <= 0 || argv == nullptr)
      {
        return;
      }

    // Copy the strings one by one, since the vector assignment uses
    // std::copy, which triggers -Waggregate-return in the standard library
    // headers on some targets.
    arguments_.reserve (static_cast<size_t> (argc));
    for (int i = 0; i < argc; ++i)
      {
        arguments_.emplace_back (argv[i] != nullptr ? argv[i] : "");
      }

    // Unless the parsing stops earlier, there are no application arguments.
    application_begin_ = arguments_.size ();

    // What an option with a value sets.
    enum class setting
    {
      set_reporter,
      set_output_file,
      set_colour,
      add_filter
    };

    // The options with a value, which is given as `--option=<value>`,
    // or, if `value_may_follow`, also as `--option <value>`. As in the GNU
    // tools, `--colour` and `--color` alone mean `always`, and the next
    // argument is never taken as their value.
#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
#endif // defined(__GNUC__)

    struct value_option
    {
      std::string_view name;
      setting what;
      bool value_may_follow;
    };

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

    static constexpr value_option value_options[]
        = { { "--reporter", setting::set_reporter, true },
            { "--output-file", setting::set_output_file, true },
            { "--use-colour", setting::set_colour, true },
            { "--use-color", setting::set_colour, true },
            { "--colour", setting::set_colour, false },
            { "--color", setting::set_colour, false },
            { "--filter", setting::add_filter, true } };

    // Set the colour mode from the value of `--colour`, `--color`,
    // `--use-colour`, or `--use-color`; all accept the values and the
    // synonyms of the GNU tools, which include those of Catch2 and Boost
    // UT (`yes`, `no`, and `auto`). An unknown mode is reported as an
    // error.
    auto set_colour_mode = [&] (std::string_view value)
      {
        if (value == "always" || value == "yes" || value == "force")
          {
            colour = colour_mode::always;
          }
        else if (value == "never" || value == "no" || value == "none")
          {
            colour = colour_mode::never;
          }
        else if (value == "auto" || value == "tty" || value == "if-tty")
          {
            colour = colour_mode::automatic;
          }
        else
          {
            add_error ("unknown colour mode '", value, "'");
          }
      };

    // Whether an argument is a value of `--colour`, to detect a value
    // given separately, which the option does not take.
    auto is_colour_mode = [] (std::string_view value) -> bool
      {
        for (const std::string_view mode :
             { "always", "yes", "force", "never", "no", "none", "auto", "tty",
               "if-tty" })
          {
            if (value == mode)
              {
                return true;
              }
          }
        return false;
      };

    // Apply the value of an option with a value; an invalid value is
    // reported as an error.
    auto apply_value = [&] (setting what, std::string_view value)
      {
        if (what == setting::set_reporter)
          {
            if (value == "human")
              {
                selected_reporter = reporter_kind::human;
              }
            else if (value == "tap")
              {
                selected_reporter = reporter_kind::tap;
              }
            else
              {
                add_error ("unknown reporter '", value, "'");
              }
          }
        else if (what == setting::set_output_file)
          {
            // An empty path disables the output file.
            output_file_path = value;
          }
        else if (what == setting::set_colour)
          {
            set_colour_mode (value);
          }
        else
          {
            filter_patterns.emplace_back (value);
          }
      };

    for (size_t i = 1; i < arguments_.size (); ++i)
      {
        const std::string_view argument{ arguments_[i] };

        // The application arguments start at the first argument that does
        // not start with a dash, or after the first `--` alone.
        if (argument == "--")
          {
            application_begin_ = i + 1;
            break;
          }
        if (!argument.starts_with ('-'))
          {
            application_begin_ = i;
            break;
          }

        if (argument == "--verbose")
          {
            verbosity_level = verbosity::verbose;
            continue;
          }
        if (argument == "--quiet")
          {
            verbosity_level = verbosity::quiet;
            continue;
          }
        if (argument == "--silent")
          {
            verbosity_level = verbosity::silent;
            continue;
          }
        if (argument == "--list-tests" || argument == "--list")
          {
            list_tests = true;
            continue;
          }
        if (argument == "--help" || argument == "-h")
          {
            help = true;
            continue;
          }

        // Match the options with a value, alone or followed by `=`.
        const value_option* matched = nullptr;
        bool has_inline_value = false;
        std::string_view value{};
        for (const value_option& option : value_options)
          {
            if (argument == option.name)
              {
                matched = &option;
                break;
              }
            if (argument.starts_with (option.name)
                && argument.substr (option.name.size ()).starts_with ('='))
              {
                matched = &option;
                has_inline_value = true;
                value = argument.substr (option.name.size () + 1);
                break;
              }
          }

        if (matched == nullptr)
          {
            // A mistyped option must not silently disable the tests.
            add_error ("unknown option '", argument, "'");
            unknown_option_ = true;
            continue;
          }

        if (!has_inline_value)
          {
            if (!matched->value_may_follow)
              {
                // The option alone means `always`. If the next argument
                // looks like a mode, it was probably meant to be the
                // value, so report it instead of silently passing it to
                // the application.
                colour = colour_mode::always;
                if (i + 1 < arguments_.size ()
                    && is_colour_mode (arguments_[i + 1]))
                  {
                    std::string text{ "'" };
                    text.append (argument);
                    text.append ("' takes its value only after '='; write '");
                    text.append (argument);
                    text.append ("=");
                    text.append (arguments_[i + 1]);
                    text.append (
                        "', or put '--' before the application argument");
                    add_error (text);
                  }
                continue;
              }

            if (i + 1 >= arguments_.size ())
              {
                add_error ("", matched->name, " option requires an argument");
                continue;
              }
            value = arguments_[++i];
          }

        apply_value (matched->what, value);
      }
  }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

  /**
   * @details
   * The message is only kept in `errors_`, so that the constructor has
   * no output; the runner writes it on `stderr` and on the console,
   * since the reporter does not exist yet.
   */
  void
  runner_options::add_error (std::string_view before, std::string_view value,
                             std::string_view after)
  {
    std::string text{ before };
    text.append (value);
    text.append (after);

    errors_.push_back (std::move (text));
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
