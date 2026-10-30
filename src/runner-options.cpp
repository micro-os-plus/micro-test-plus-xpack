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
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/runner-options.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

#include <cstdio>
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
   *   Boost UT, to list the test cases instead of running them.
   *
   * When an option is repeated, the last one takes effect, except
   * `--filter`, whose patterns are all kept, in order, one per nesting
   * level; `--colour`, `--color`, `--use-colour`, and `--use-color` set
   * the same option. An option argument given separately is the next
   * argument, whatever its content; `--colour` and `--color` accept their
   * value only after `=`.
   *
   * The parsing ends at the first argument that does not start with `--`,
   * or at the first `--` alone; the arguments from there on are left to
   * the application, and are not interpreted, so they can be options of
   * the application. The `--` itself is not an application argument. The
   * whole command line is copied into `arguments`, to be listed by the
   * reporter; the option values are copied from there.
   *
   * A missing option argument, an unknown reporter name, an unknown
   * colour mode, or an unknown `--` option, is recorded by `add_error()`,
   * and the option is ignored; the parsing continues with the next
   * argument, to record all the errors. The runner then refuses to run
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
    arguments.reserve (static_cast<size_t> (argc));
    for (int i = 0; i < argc; ++i)
      {
        arguments.emplace_back (argv[i] != nullptr ? argv[i] : "");
      }

    // Unless the parsing stops earlier, there are no application arguments.
    application_begin_ = arguments.size ();

    static constexpr std::string_view reporter_option{ "--reporter" };
    static constexpr std::string_view output_file_option{ "--output-file" };
    static constexpr std::string_view colour_option{ "--colour" };
    static constexpr std::string_view color_option{ "--color" };
    static constexpr std::string_view use_colour_option{ "--use-colour" };
    static constexpr std::string_view use_color_option{ "--use-color" };
    static constexpr std::string_view filter_option{ "--filter" };

    // Get the value of an option given as `--option=<value>` or as
    // `--option <value>`; the latter advances the index past the value.
    // Return false if the argument is not this option, or if its value is
    // missing, which is reported as an error.
    auto get_value = [&] (std::string_view option, size_t& i,
                          std::string_view& value) -> bool
      {
        const std::string_view argument{ arguments[i] };
        if (argument == option)
          {
            if (i + 1 >= arguments.size ())
              {
                add_error ("", option, " option requires an argument");
                return false;
              }
            value = arguments[++i];
            return true;
          }
        if (argument.starts_with (option)
            && argument.substr (option.size ()).starts_with ('='))
          {
            value = argument.substr (option.size () + 1);
            return true;
          }
        return false;
      };

    // Whether the argument is one of the options with a value, possibly
    // with the value missing, which was already reported.
    auto is_known_option = [&] (std::string_view argument) -> bool
      {
        for (const std::string_view option :
             { reporter_option, output_file_option, use_colour_option,
               use_color_option, filter_option })
          {
            if (argument == option
                || (argument.starts_with (option)
                    && argument.substr (option.size ()).starts_with ('=')))
              {
                return true;
              }
          }
        return false;
      };

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

    for (size_t i = 1; i < arguments.size (); ++i)
      {
        const std::string_view argument{ arguments[i] };
        std::string_view value{};

        // The application arguments start at the first argument that is not
        // a `--` option, or after the first `--` alone.
        if (argument == "--")
          {
            application_begin_ = i + 1;
            break;
          }
        if (!argument.starts_with ("--"))
          {
            application_begin_ = i;
            break;
          }

        if (argument == "--verbose")
          {
            verbosity_level = verbosity::verbose;
          }
        else if (argument == "--quiet")
          {
            verbosity_level = verbosity::quiet;
          }
        else if (argument == "--silent")
          {
            verbosity_level = verbosity::silent;
          }
        else if (argument == "--list-tests" || argument == "--list")
          {
            list_tests = true;
          }
        else if (get_value (reporter_option, i, value))
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
        else if (get_value (output_file_option, i, value))
          {
            // An empty path disables the output file.
            output_file_path = value;
          }
        else if (get_value (use_colour_option, i, value)
                 || get_value (use_color_option, i, value))
          {
            set_colour_mode (value);
          }
        else if (argument == colour_option || argument == color_option)
          {
            // As in the GNU tools, the option alone means `always`, and
            // the next argument is never taken as its value.
            colour = colour_mode::always;
          }
        else if (argument.starts_with (colour_option)
                 && argument.substr (colour_option.size ()).starts_with ('='))
          {
            set_colour_mode (argument.substr (colour_option.size () + 1));
          }
        else if (argument.starts_with (color_option)
                 && argument.substr (color_option.size ()).starts_with ('='))
          {
            set_colour_mode (argument.substr (color_option.size () + 1));
          }
        else if (get_value (filter_option, i, value))
          {
            filter_patterns.emplace_back (value);
          }
        else if (argument.starts_with ("--") && !is_known_option (argument))
          {
            // A mistyped option must not silently disable the tests.
            add_error ("unknown option '", argument, "'");
          }
      }
  }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

  /**
   * @details
   * The message is written on `stderr` and kept in `errors_`, to be
   * written by the runner, since the reporter does not exist yet.
   */
  void
  runner_options::add_error (std::string_view before, std::string_view value,
                             std::string_view after)
  {
    std::string text{ before };
    text.append (value);
    text.append (after);

    fprintf (stderr, "error: %s\n", text.c_str ());
    errors_.push_back (std::move (text));
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
