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

// The tests of the `runner_options` class, independent of the runner: the
// defaults, the parsing of each option, the errors, the ownership of the
// strings, and the copies and moves. The use of the options by the runner
// (exit codes, filters, listing) is tested in `miscellaneous.cpp`.

#include "unit-miscellaneous-test.h"

#include <initializer_list>
#include <span>
#include <string>
#include <utility>
#include <vector>

using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

namespace
{
  // A writable command line, as `main()` receives it, with the `argv[]`
  // array terminated by a null pointer.
  class command_line
  {
  public:
    command_line (std::initializer_list<const char*> arguments)
    {
      strings_.reserve (arguments.size ());
      for (const char* argument : arguments)
        {
          strings_.emplace_back (argument);
        }

      pointers_.reserve (strings_.size () + 1);
      for (std::string& string : strings_)
        {
          pointers_.push_back (string.data ());
        }
      pointers_.push_back (nullptr);
    }

    int
    argc (void) const noexcept
    {
      return static_cast<int> (strings_.size ());
    }

    char**
    argv (void) noexcept
    {
      return pointers_.data ();
    }

    // Overwrite the characters of all arguments, keeping their lengths,
    // as an application that reuses its buffers would.
    void
    overwrite (void) noexcept
    {
      for (std::string& string : strings_)
        {
          for (char& c : string)
            {
              c = 'x';
            }
        }
    }

  private:
    std::vector<std::string> strings_{};
    std::vector<char*> pointers_{};
  };

  // Parse the given command line.
  runner_options
  parse (std::initializer_list<const char*> arguments)
  {
    command_line line{ arguments };
    return runner_options{ line.argc (), line.argv () };
  }

  // Tell whether the arguments are exactly the expected ones.
  bool
  same_arguments (std::span<const std::string> actual,
                  std::initializer_list<const char*> expected)
  {
    if (actual.size () != expected.size ())
      {
        return false;
      }

    std::size_t index = 0;
    for (const char* argument : expected)
      {
        if (actual[index] != argument)
          {
            return false;
          }
        ++index;
      }
    return true;
  }
} // namespace

// ----------------------------------------------------------------------------

static static_suite ts_runner_options{ "Runner options suite", tr,
                                       [] (auto& ts)
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

    // ------------------------------------------------------------------------

    ts.test ("Default options", [] (auto& t)
      {
        const runner_options options{};

        t.expect (options.selected_reporter == reporter_kind::tap)
            << "the TAP reporter";
        local_counts.passed_checks++;

        t.expect (options.verbosity_level == verbosity::normal)
            << "the normal verbosity";
        local_counts.passed_checks++;

        t.expect (options.output_file_path.empty ()) << "no output file";
        local_counts.passed_checks++;

        t.expect (options.colour == colour_mode::automatic)
            << "automatic colours";
        local_counts.passed_checks++;

        t.expect (options.arguments.empty ()
                  and options.filter_patterns.empty () and !options.list_tests)
            << "no command line, no filter, no listing";
        local_counts.passed_checks++;

        t.expect (!options.has_errors () and options.errors ().empty ())
            << "no errors";
        local_counts.passed_checks++;

        const runner_options empty_options{ 0, nullptr };

        t.expect (empty_options.arguments.empty ()
                  and !empty_options.has_errors ())
            << "an empty command line is accepted";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Command line without options", [] (auto& t)
      {
        const runner_options options = parse ({ "name", "one", "-v", "two" });

        t.expect (eq (options.arguments.size (), 4u)
                  and eq (options.arguments[0], "name")
                  and eq (options.arguments[3], "two"))
            << "the command line is kept";
        local_counts.passed_checks++;

        t.expect (!options.has_errors ())
            << "the arguments without `--` are ignored";
        local_counts.passed_checks++;

        t.expect (options.selected_reporter == reporter_kind::tap
                  and options.verbosity_level == verbosity::normal)
            << "the defaults are kept";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The parsing of the µTest++ options ends at the first argument that
    // does not start with `--`, or at the first `--` alone; the arguments
    // from there on are left to the application.
    ts.test ("Application arguments", [] (auto& t)
      {
        const runner_options after_options
            = parse ({ "name", "--verbose", "one", "two" });

        t.expect (after_options.verbosity_level == verbosity::verbose
                  and same_arguments (after_options.application_arguments (),
                                      { "one", "two" }))
            << "the application arguments follow the options";
        local_counts.passed_checks++;

        const runner_options option_after_argument
            = parse ({ "name", "one", "--verbose" });

        t.expect (
            option_after_argument.verbosity_level == verbosity::normal
            and !option_after_argument.has_errors ()
            and same_arguments (option_after_argument.application_arguments (),
                                { "one", "--verbose" }))
            << "an option after an application argument is not an option";
        local_counts.passed_checks++;

        const runner_options terminator = parse (
            { "name", "--quiet", "--", "--verbose", "--app-opt", "x" });

        t.expect (terminator.verbosity_level == verbosity::quiet
                  and !terminator.has_errors ()
                  and same_arguments (terminator.application_arguments (),
                                      { "--verbose", "--app-opt", "x" }))
            << "the arguments after -- are left to the application";
        local_counts.passed_checks++;

        const runner_options application_options
            = parse ({ "name", "one", "--app-opt", "--" });

        t.expect (
            !application_options.has_errors ()
            and same_arguments (application_options.application_arguments (),
                                { "one", "--app-opt", "--" }))
            << "the application options are not reported";
        local_counts.passed_checks++;

        const runner_options separate_value
            = parse ({ "name", "--reporter", "human", "--filter", "A*",
                       "--output-file", "out.txt", "one" });

        t.expect (separate_value.selected_reporter == reporter_kind::human
                  and eq (separate_value.filter_patterns.size (), 1u)
                  and eq (separate_value.output_file_path, "out.txt")
                  and same_arguments (separate_value.application_arguments (),
                                      { "one" }))
            << "the separate option arguments belong to their options";
        local_counts.passed_checks++;

        const runner_options unknown_option
            = parse ({ "name", "--bogus", "one" });

        t.expect (unknown_option.has_errors ()
                  and same_arguments (unknown_option.application_arguments (),
                                      { "one" }))
            << "an unknown option before the application arguments";
        local_counts.passed_checks++;

        const runner_options single_dash
            = parse ({ "name", "-v", "--verbose" });

        t.expect (single_dash.verbosity_level == verbosity::normal
                  and same_arguments (single_dash.application_arguments (),
                                      { "-v", "--verbose" }))
            << "a single dash ends the options";
        local_counts.passed_checks++;

        t.expect (
            parse ({ "name" }).application_arguments ().empty ()
            and parse ({ "name", "--verbose" })
                    .application_arguments ()
                    .empty ()
            and parse ({ "name", "--" }).application_arguments ().empty ()
            and runner_options{}.application_arguments ().empty ()
            and runner_options{ 0, nullptr }.application_arguments ().empty ())
            << "no application arguments";
        local_counts.passed_checks++;

        const runner_options original
            = parse ({ "name", "--silent", "one", "two" });
        runner_options copy{ original };
        runner_options moved{ std::move (copy) };

        t.expect (same_arguments (original.application_arguments (),
                                  { "one", "two" })
                  and same_arguments (moved.application_arguments (),
                                      { "one", "two" })
                  and moved.application_arguments ().data ()
                          != original.application_arguments ().data ())
            << "the copies refer to their own arguments";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Reporter, verbosity, and listing", [] (auto& t)
      {
        t.expect (parse ({ "name", "--reporter=human" }).selected_reporter
                  == reporter_kind::human)
            << "--reporter=human";
        local_counts.passed_checks++;

        t.expect (parse ({ "name", "--reporter", "human", "--reporter=tap" })
                      .selected_reporter
                  == reporter_kind::tap)
            << "the last --reporter wins";
        local_counts.passed_checks++;

        t.expect (parse ({ "name", "--silent" }).verbosity_level
                  == verbosity::silent)
            << "--silent";
        local_counts.passed_checks++;

        t.expect (parse ({ "name", "--verbose" }).verbosity_level
                  == verbosity::verbose)
            << "--verbose";
        local_counts.passed_checks++;

        t.expect (parse ({ "name", "--verbose", "--quiet" }).verbosity_level
                  == verbosity::quiet)
            << "the last verbosity wins";
        local_counts.passed_checks++;

        t.expect (parse ({ "name", "--list-tests" }).list_tests)
            << "--list-tests";
        local_counts.passed_checks++;

        t.expect (parse ({ "name", "--list" }).list_tests) << "--list";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Output file and filters", [] (auto& t)
      {
        t.expect (
            eq (parse ({ "name", "--output-file=a.tap" }).output_file_path,
                "a.tap"))
            << "--output-file=<path>";
        local_counts.passed_checks++;

        t.expect (
            eq (parse ({ "name", "--output-file", "b.tap" }).output_file_path,
                "b.tap"))
            << "--output-file <path>";
        local_counts.passed_checks++;

        t.expect (parse ({ "name", "--output-file=a.tap", "--output-file=" })
                      .output_file_path.empty ())
            << "an empty path disables the output file";
        local_counts.passed_checks++;

        const runner_options options
            = parse ({ "name", "--filter=A*", "--filter", "b|c" });

        t.expect (eq (options.filter_patterns.size (), 2u)
                  and eq (options.filter_patterns[0], "A*")
                  and eq (options.filter_patterns[1], "b|c"))
            << "all the --filter patterns are kept, in order";
        local_counts.passed_checks++;

        const runner_options taken_options
            = parse ({ "name", "--filter", "--verbose" });

        t.expect (eq (taken_options.filter_patterns.size (), 1u)
                  and eq (taken_options.filter_patterns[0], "--verbose")
                  and taken_options.verbosity_level == verbosity::normal)
            << "a separate value is taken whatever its content";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Colours", [] (auto& t)
      {
        // Check that the option, in both its spellings, selects the mode,
        // starting from a different mode; the message shows both.
        auto check_spellings = [&t] (const char* british, const char* american,
                                     const char* suffix, colour_mode mode)
          {
            const char* const opposite
                = (mode == colour_mode::never) ? "=always" : "=never";
            bool passed = true;
            for (const char* spelling : { british, american })
              {
                const std::string opposite_argument
                    = std::string{ "--colour" } + opposite;
                const std::string argument = std::string{ spelling } + suffix;
                const runner_options options = parse (
                    { "name", opposite_argument.c_str (), argument.c_str () });

                passed = passed and options.colour == mode
                         and !options.has_errors ();
              }

            t.expect (passed)
                << british << suffix << ", " << american << suffix;
            local_counts.passed_checks++;
          };

        auto check_colour
            = [&check_spellings] (const char* suffix, colour_mode mode)
          { check_spellings ("--colour", "--color", suffix, mode); };

        check_colour ("", colour_mode::always);
        check_colour ("=always", colour_mode::always);
        check_colour ("=yes", colour_mode::always);
        check_colour ("=force", colour_mode::always);
        check_colour ("=never", colour_mode::never);
        check_colour ("=no", colour_mode::never);
        check_colour ("=none", colour_mode::never);
        check_colour ("=auto", colour_mode::automatic);
        check_colour ("=tty", colour_mode::automatic);
        check_colour ("=if-tty", colour_mode::automatic);

        check_spellings ("--use-colour", "--use-color", "=yes",
                         colour_mode::always);
        check_spellings ("--use-colour", "--use-color", "=no",
                         colour_mode::never);
        check_spellings ("--use-colour", "--use-color", "=never",
                         colour_mode::never);

        t.expect (parse ({ "name", "--use-colour", "no" }).colour
                      == colour_mode::never
                  and parse ({ "name", "--use-color", "no" }).colour
                          == colour_mode::never)
            << "--use-colour <mode>, --use-color <mode>";
        local_counts.passed_checks++;

        const runner_options colour_options
            = parse ({ "name", "--colour", "never" });
        const runner_options color_options
            = parse ({ "name", "--color", "never" });

        t.expect (colour_options.colour == colour_mode::always
                  and !colour_options.has_errors ()
                  and color_options.colour == colour_mode::always
                  and !color_options.has_errors ())
            << "--colour and --color do not take a separate value";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Option errors", [] (auto& t)
      {
        const runner_options missing_options
            = parse ({ "name", "--silent", "--reporter" });

        t.expect (missing_options.has_errors ()
                  and eq (missing_options.errors ().size (), 1u))
            << "a missing option argument";
        local_counts.passed_checks++;

        t.expect (missing_options.verbosity_level == verbosity::silent)
            << "the valid options are still applied";
        local_counts.passed_checks++;

        const runner_options reporter_options
            = parse ({ "name", "--reporter=junit" });

        t.expect (
            reporter_options.has_errors ()
            and eq (reporter_options.errors ().size (), 1u)
            and eq (reporter_options.errors ()[0], "unknown reporter 'junit'")
            and reporter_options.selected_reporter == reporter_kind::tap)
            << "an unknown reporter";
        local_counts.passed_checks++;

        const runner_options colour_options
            = parse ({ "name", "--color=maybe" });

        t.expect (colour_options.has_errors ()
                  and eq (colour_options.errors ().size (), 1u)
                  and colour_options.colour == colour_mode::automatic)
            << "an unknown colour mode";
        local_counts.passed_checks++;

        t.expect (parse ({ "name", "--verbos" }).has_errors ())
            << "an unknown option";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Owned strings", [] (auto& t)
      {
        command_line line{ "/path/name.elf", "--output-file", "out.tap",
                           "--filter=Alpha" };
        const runner_options options{ line.argc (), line.argv () };

        line.overwrite ();

        t.expect (eq (options.arguments[0], "/path/name.elf")
                  and eq (options.arguments[2], "out.tap"))
            << "the command line is copied";
        local_counts.passed_checks++;

        t.expect (eq (options.output_file_path, "out.tap"))
            << "the output file path is copied";
        local_counts.passed_checks++;

        t.expect (eq (options.filter_patterns[0], "Alpha"))
            << "the filter patterns are copied";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Copies and moves", [] (auto& t)
      {
        const runner_options original
            = parse ({ "name", "--reporter=junit", "--quiet", "--filter=A" });

        runner_options copy{ original };

        t.expect (copy.has_errors () and eq (copy.errors ().size (), 1u)
                  and copy.verbosity_level == verbosity::quiet
                  and eq (copy.filter_patterns.size (), 1u)
                  and eq (copy.arguments.size (), 4u))
            << "the copy has all the members";
        local_counts.passed_checks++;

        copy.verbosity_level = verbosity::verbose;
        copy.filter_patterns.emplace_back ("B");

        t.expect (original.verbosity_level == verbosity::quiet
                  and eq (original.filter_patterns.size (), 1u))
            << "the copy is independent of the original";
        local_counts.passed_checks++;

        runner_options assigned{};
        assigned = original;

        t.expect (assigned.has_errors ()
                  and assigned.verbosity_level == verbosity::quiet
                  and eq (assigned.filter_patterns.size (), 1u))
            << "the copy assignment copies all the members";
        local_counts.passed_checks++;

        runner_options moved{ std::move (copy) };

        t.expect (moved.has_errors ()
                  and moved.verbosity_level == verbosity::verbose
                  and eq (moved.filter_patterns.size (), 2u)
                  and eq (moved.filter_patterns[1], "B"))
            << "the move constructor moves all the members";
        local_counts.passed_checks++;

        runner_options move_assigned{};
        move_assigned = std::move (moved);

        t.expect (eq (move_assigned.errors ().size (), 1u)
                  and eq (move_assigned.filter_patterns.size (), 2u)
                  and eq (move_assigned.arguments[0], "name"))
            << "the move assignment moves all the members";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // ------------------------------------------------------------------------

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------
  } };

// ----------------------------------------------------------------------------
