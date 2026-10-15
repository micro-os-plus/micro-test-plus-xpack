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

#include "unit-test.h"

#include <limits>

using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

namespace
{
  // A user-defined type, to check the comparators with custom types.
  struct point
  {
    int x;
    int y;
  };

  constexpr bool
  operator== (const point& lhs, const point& rhs)
  {
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }

  // Found by argument-dependent lookup when the operands are reported.
  expression_formatter&
  operator<< (expression_formatter& formatter, const point& p)
  {
    return formatter << "{ " << p.x << ", " << p.y << " }";
  }

  // An abort handler which, when exceptions are available, returns
  // control to the test case, without terminating the process
  // (API-REVIEW.md #21).
#if defined(__EXCEPTIONS)
  struct abort_exception
  {
  };

  [[noreturn]] void
  test_abort_handler (const reflection::source_location&)
  {
    throw abort_exception{};
  }
#else
  void
  test_abort_handler (const reflection::source_location&)
  {
  }
#endif // defined(__EXCEPTIONS)

  // A reporter that ignores all events and exposes its output buffer, to
  // check the text written by the `reporter` stream operators, without
  // writing to the test output (API-REVIEW.md #7).
  class buffer_reporter final : public detail::reporter
  {
  public:
    buffer_reporter () : reporter{ runner_options{} }
    {
    }

    // The text accumulated by the stream operators.
    const std::string&
    text () const noexcept
    {
      return buffer_;
    }

    void
    clear () noexcept
    {
      clear_buffer_ ();
    }

    void
    begin_session (runner&) override
    {
    }

    void
    end_session (runner&) override
    {
    }

    void
    begin_suite (suite&) override
    {
    }

    void
    end_suite (suite&) override
    {
    }

    void
    skip_suite (suite&) override
    {
    }

    void
    begin_test_case (test_case&) override
    {
    }

    void
    end_test_case (test_case&) override
    {
    }

    void
    skip_test_case (test_case&) override
    {
    }

    const char*
    comment_prefix (void) const override
    {
      return "";
    }

  protected:
    void
    output_pass_prefix_ (std::string&, test_case&) override
    {
    }

    void
    output_pass_suffix_ (test_case&) override
    {
    }

    void
    output_fail_prefix_ (std::string&, const bool,
                         const reflection::source_location&,
                         test_case&) override
    {
    }

    void
    output_fail_suffix_ (const reflection::source_location&, bool,
                         test_case&) override
    {
    }
  };
} // namespace

// ----------------------------------------------------------------------------

static static_suite ts_miscellaneous{ "Miscellaneous suite", tr, [] (auto& ts)
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

    ts.test ("Arrays", [] (auto& t)
      {
        t.expect (eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
            << "array{ 42 } == array{ 42 }";
        local_counts.successful_checks++;

        t.expect (ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
            << "array{ 42 } != array{ 43 }";
        local_counts.successful_checks++;

        t.expect (eq (std::array{ 1, 2 }, std::array{ 1, 2 }))
            << "array{ 1, 2 } == array{ 1, 2 }";
        local_counts.successful_checks++;

        t.expect (ne (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
            << "array{ 1, 2, 3 } != array{ 1, 2, 4 }";
        local_counts.successful_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Arrays bad", [] (auto& t)
      {
        t.expect (ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
            << "array{ 42 } ne array{ 42 }";
        local_counts.failed_checks++;

        t.expect (eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
            << "array{ 42 } eq array{ 43 }";
        local_counts.failed_checks++;

        t.expect (ne (std::array{ 1, 2 }, std::array{ 1, 2 }))
            << "array{ 1, 2 } ne array{ 1, 2 }";
        local_counts.failed_checks++;

        t.expect (eq (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
            << "array{ 1, 2, 3 } eq array{ 1, 2, 4 }";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Vectors", [] (auto& t)
      {
        t.expect (eq (std::vector<int>{}, std::vector<int>{}))
            << "vector{ } == vector{ }";
        local_counts.successful_checks++;

        t.expect (eq (std::vector<int>{}, std::vector<int>{}));
        local_counts.successful_checks++;

        t.expect (eq (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
            << "vector{ 42 } == vector{ 42 }";
        local_counts.successful_checks++;

        t.expect (ne (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
            << "vector{ 42 } != vector{ 43 }";
        local_counts.successful_checks++;

        t.expect (eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
            << "vector{ 1, 2 } == vector{ 1, 2 }";
        local_counts.successful_checks++;

        t.expect (
            ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
            << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
        local_counts.successful_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Vectors bad", [] (auto& t)
      {
        t.expect (ne (std::vector<int>{}, std::vector<int>{}))
            << "vector{ } != vector{ }";
        local_counts.failed_checks++;

        t.expect (ne (std::vector<int>{}, std::vector<int>{}));
        local_counts.failed_checks++;

        t.expect (ne (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
            << "vector{ 42 } != vector{ 42 }";
        local_counts.failed_checks++;

        t.expect (eq (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
            << "vector{ 42 } == vector{ 43 }";
        local_counts.failed_checks++;

        t.expect (ne (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
            << "vector{ 1, 2 } != vector{ 1, 2 }";
        local_counts.failed_checks++;

        t.expect (
            eq (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
            << "vector{ 1, 2, 3 } == vector{ 1, 2, 4 }";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Custom types", [] (auto& t)
      {
        t.expect (eq (point{ 1, 2 }, point{ 1, 2 }))
            << "point{ 1, 2 } == point{ 1, 2 }";
        local_counts.successful_checks++;

        t.expect (ne (point{ 1, 2 }, point{ 1, 3 }))
            << "point{ 1, 2 } != point{ 1, 3 }";
        local_counts.successful_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Custom types bad", [] (auto& t)
      {
        t.expect (eq (point{ 1, 2 }, point{ 1, 3 }))
            << "point{ 1, 2 } == point{ 1, 3 }";
        local_counts.failed_checks++;

        // Without a message; the operands are reported in the condition.
        t.expect (eq (point{ 1, 2 }, point{ 1, 3 }));
        local_counts.failed_checks++;

        t.expect (ne (point{ 1, 2 }, point{ 1, 2 }))
            << "point{ 1, 2 } != point{ 1, 2 }";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The text written by the `reporter` stream operators, for every
    // supported type (API-REVIEW.md #7).
    ts.test ("Reporter stream operators", [] (auto& t)
      {
        buffer_reporter r;

        // Compares the accumulated text, then clears it.
        auto check = [&] (std::string_view expected, const char* message)
          {
            t.expect (eq (std::string_view{ r.text () }, expected)) << message;
            local_counts.successful_checks++;
            r.clear ();
          };

        r << "text";
        check ("text", "const char*");

        r << std::string_view{ "view" };
        check ("view", "std::string_view");

        r << 'c';
        check ("c", "char");

        r << true << ' ' << false;
        check ("true false", "bool");

        r << nullptr;
        check ("nullptr", "nullptr");

        r << 42 << ' ' << -7 << ' ' << 42u << ' ' << 42L;
        check ("42 -7 42 42", "integers");

        r << 1.25;
        check ("1.25", "double");

        r << static_cast<int*> (nullptr);
        check ("0x0", "null pointer");

        r << "line" << detail::endl;
        check ("line\n", "endl");

        // The `char` pointers and arrays are displayed as strings, as the
        // `const char` pointers are (API-REVIEW.md #13).
        char text[] = "mutable";
        r << text;
        check ("mutable", "char array");

        char* text_pointer = text;
        r << text_pointer;
        check ("mutable", "char*");

        r << static_cast<char*> (nullptr) << ' '
          << static_cast<const char*> (nullptr);
        check ("nullptr nullptr", "null char pointers");

        // A non-null pointer, also to a const object, is displayed as an
        // address, whose format depends on the platform.
        static const int constant = 42;
        r << &constant;
        t.expect (not r.text ().empty () && r.text () != "0x0")
            << "pointer to const";
        local_counts.successful_checks++;
        r.clear ();

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The text written by the `expression_formatter` stream operators for
    // the character pointers and arrays (API-REVIEW.md #13).
    ts.test ("Formatter character pointers", [] (auto& t)
      {
        detail::colours no_colours{};
        expression_formatter f{ no_colours };

        // Compares the accumulated text, then clears it.
        auto check = [&] (std::string_view expected, const char* message)
          {
            t.expect (eq (std::string_view{ f.str () }, expected)) << message;
            local_counts.successful_checks++;
            f.clear ();
          };

        char text[] = "mutable";
        f << text;
        check ("mutable", "char array");

        char* text_pointer = text;
        f << text_pointer;
        check ("mutable", "char*");

        const char* const_text_pointer = text;
        f << const_text_pointer;
        check ("mutable", "const char*");

        f << static_cast<char*> (nullptr) << ' '
          << static_cast<const char*> (nullptr);
        check ("nullptr nullptr", "null char pointers");

        // The `signed char` and `unsigned char` pointers, usually byte
        // buffers, are displayed as addresses, whose format depends on the
        // platform.
        unsigned char bytes[] = { 'a', 'b', 0 };
        f << bytes;
        t.expect (not f.str ().empty () && f.str () != "ab"
                  && f.str () != "0x0")
            << "unsigned char array";
        local_counts.successful_checks++;
        f.clear ();

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The type suffixes written by the `expression_formatter` for the
    // numbers, and the decimal point of the floating-point values
    // (API-REVIEW.md #44).
    ts.test ("Formatter number suffixes", [] (auto& t)
      {
        detail::colours no_colours{};
        expression_formatter f{ no_colours };

        // Compares the accumulated text, then clears it.
        auto check = [&] (std::string_view expected, const char* message)
          {
            t.expect (eq (std::string_view{ f.str () }, expected)) << message;
            local_counts.successful_checks++;
            f.clear ();
          };

        f << static_cast<signed char> (5);
        check ("5sc", "signed char");

        f << static_cast<unsigned char> (5);
        check ("5uc", "unsigned char");

        f << 42;
        check ("42", "int");

        f << 42L;
        check ("42l", "long");

        f << 42.0f;
        check ("42.0f", "integral float");

        f << 42.0;
        check ("42.0", "integral double");

        f << 42.0L;
        check ("42.0ld", "integral long double");

        f << 1.5f;
        check ("1.5f", "float");

        f << 1.5;
        check ("1.5", "double");

        f << 1.5L;
        check ("1.5ld", "long double");

        f << -2.0;
        check ("-2.0", "negative integral double");

        f << 1e20;
        check ("1e+20", "double with exponent");

        f << std::numeric_limits<double>::infinity ();
        check ("inf", "infinite double");

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The comparators accept pointers to const objects, whose addresses are
    // displayed on failure.
    ts.test ("Pointers to const", [] (auto& t)
      {
        static const int first = 1;
        static const int second = 2;

        t.expect (ne (&first, &second)) << "different const objects";
        local_counts.successful_checks++;

        t.expect (eq (&first, &first)) << "same const object";
        local_counts.successful_checks++;

        local_counts.executed_test_cases++;
      });

    // A runner can be initialised without a command line, with the options
    // set by the application (API-REVIEW.md #20). The local runners are
    // silent, so that they do not write to the test output.
    ts.test ("Runner options", [] (auto& t)
      {
        runner_options options{};
        options.selected_reporter = reporter_kind::human;
        options.verbosity_level = verbosity::silent;

        runner named_runner;
        auto& named_ts = named_runner.initialise (options, "Local");

        t.expect (eq (named_ts.name (), "Local")) << "given name";
        local_counts.successful_checks++;

        t.expect (named_runner.verbosity () == verbosity::silent)
            << "given verbosity";
        local_counts.successful_checks++;

        named_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (named_runner.run (), 0)) << "local session passed";
        local_counts.successful_checks++;

        runner unnamed_runner;
        auto& unnamed_ts = unnamed_runner.initialise (options);

        t.expect (eq (unnamed_ts.name (), "default suite"))
            << "default name without arguments";
        local_counts.successful_checks++;

        local_counts.executed_test_cases++;
      });

    // An option error does not terminate the process; it is reported on
    // stderr (the messages are expected in the test output), the tests are
    // still run, and `run()` returns 2 (API-REVIEW.md #21).
    ts.test ("Runner option errors", [] (auto& t)
      {
        char arg_name[] = "local";
        char arg_silent[] = "--silent";
        char arg_bad_reporter[] = "--reporter=unknown";
        char arg_reporter[] = "--reporter";

        char* bad_reporter_argv[]
            = { arg_name, arg_silent, arg_bad_reporter, nullptr };
        runner bad_reporter_runner;
        auto& bad_reporter_ts
            = bad_reporter_runner.initialise (3, bad_reporter_argv);
        bad_reporter_ts.test ("Local test",
                              [] (auto& lt) { lt.expect (true); });

        t.expect (bad_reporter_runner.verbosity () == verbosity::silent)
            << "valid options still applied";
        local_counts.successful_checks++;

        t.expect (eq (bad_reporter_runner.run (), 2)) << "unknown reporter";
        local_counts.successful_checks++;

        char* missing_argv[] = { arg_name, arg_silent, arg_reporter, nullptr };
        runner missing_runner;
        auto& missing_ts = missing_runner.initialise (3, missing_argv);
        missing_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (missing_runner.run (), 2)) << "missing argument";
        local_counts.successful_checks++;

        runner_options options{};
        options.verbosity_level = verbosity::silent;
        options.output_file_path = "/non-existent-folder/report.txt";

        runner file_runner;
        auto& file_ts = file_runner.initialise (options);
        file_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (file_runner.run (), 2)) << "output file not opened";
        local_counts.successful_checks++;

        local_counts.executed_test_cases++;
      });

    // The --filter option selects the suites and the test cases to run by
    // name, with one pattern per nesting level, as --grep in node-tap;
    // within a pattern, `|` separates alternatives (API-REVIEW.md #29).
    // The local runners are silent.
    ts.test ("Runner filter", [] (auto& t)
      {
        // The number of runs of each suite and test case body.
        struct runs_t
        {
          int alpha_one = 0;
          int alpha_two = 0;
          int beta = 0;
          int first = 0;
          int second = 0;
          int inner = 0;
          int other = 0;
        };
        runs_t runs{};

        // Each suite has two test cases; the second one has two nested
        // test cases.
        auto body = [&runs] (suite& s)
          {
            s.test ("first", [&runs] (test_case&) noexcept { ++runs.first; });
            s.test ("second", [&runs] (test_case& st)
              {
                ++runs.second;
                st.test ("inner",
                         [&runs] (test_case&) noexcept { ++runs.inner; });
                st.test ("other",
                         [&runs] (test_case&) noexcept { ++runs.other; });
              });
          };

        auto add_suites = [&runs, &body] (runner& r)
          {
            r.suite ("Alpha one", [&runs, &body] (suite& s)
              {
                ++runs.alpha_one;
                body (s);
              });
            r.suite ("Beta", [&runs, &body] (suite& s)
              {
                ++runs.beta;
                body (s);
              });
            r.suite ("Alpha two", [&runs, &body] (suite& s)
              {
                ++runs.alpha_two;
                body (s);
              });
          };

        // A single pattern, set by the application, selects the suites;
        // all their test cases run.
        runner_options options{};
        options.verbosity_level = verbosity::silent;
        options.filter_patterns = { "Alpha*" };

        runner suites_runner;
        suites_runner.initialise (options);
        add_suites (suites_runner);

        t.expect (eq (suites_runner.run (), 0)) << "suite filter passed";
        local_counts.successful_checks++;

        t.expect (eq (runs.alpha_one, 1) and eq (runs.alpha_two, 1)
                  and eq (runs.beta, 0))
            << "matching suites run";
        local_counts.successful_checks++;

        t.expect (eq (runs.first, 2) and eq (runs.second, 2)
                  and eq (runs.inner, 2) and eq (runs.other, 2))
            << "all their test cases run";
        local_counts.successful_checks++;

        t.expect (eq (suites_runner.skipped_suites_count (), 1u)
                  and eq (suites_runner.totals ().skipped_test_cases (), 0u))
            << "one suite skipped";
        local_counts.successful_checks++;

        // Patterns parsed from the command line, in both forms, one per
        // level: the suites, the test cases, and the nested test cases.
        char arg_name[] = "local";
        char arg_silent[] = "--silent";
        char arg_filter_suites[] = "--filter=Beta|Alpha t?o";
        char arg_filter[] = "--filter";
        char arg_second[] = "second";
        char arg_filter_inner[] = "--filter=inner";

        char* levels_argv[] = { arg_name,   arg_silent, arg_filter_suites,
                                arg_filter, arg_second, arg_filter_inner,
                                nullptr };

        runs = runs_t{};
        runner levels_runner;
        levels_runner.initialise (6, levels_argv);
        add_suites (levels_runner);

        t.expect (eq (levels_runner.run (), 0)) << "level filters passed";
        local_counts.successful_checks++;

        t.expect (eq (runs.alpha_one, 0) and eq (runs.alpha_two, 1)
                  and eq (runs.beta, 1))
            << "suites matching an alternative run";
        local_counts.successful_checks++;

        t.expect (eq (runs.first, 0) and eq (runs.second, 2))
            << "test cases matching the second pattern run";
        local_counts.successful_checks++;

        t.expect (eq (runs.inner, 2) and eq (runs.other, 0))
            << "nested test cases matching the third pattern run";
        local_counts.successful_checks++;

        t.expect (eq (levels_runner.skipped_suites_count (), 1u)
                  and eq (levels_runner.totals ().skipped_test_cases (), 4u))
            << "skipped suites and test cases counted";
        local_counts.successful_checks++;

        // The top suite is never skipped, but its test cases are filtered
        // too, including by its name; a pattern must match the whole name.
        runner_options top_options{};
        top_options.verbosity_level = verbosity::silent;
        top_options.filter_patterns = { "Local", "first" };

        runs = runs_t{};
        runner top_runner;
        body (top_runner.initialise (top_options, "Local"));

        t.expect (eq (top_runner.run (), 0)
                  and eq (top_runner.totals ().skipped_test_cases (), 1u))
            << "top suite filtered";
        local_counts.successful_checks++;

        t.expect (eq (runs.first, 1) and eq (runs.second, 0))
            << "top suite test case matching the second pattern runs";
        local_counts.successful_checks++;

        top_options.filter_patterns = { "Loc" };

        runs = runs_t{};
        runner partial_runner;
        body (partial_runner.initialise (top_options, "Local"));

        t.expect (eq (partial_runner.run (), 0)
                  and eq (partial_runner.totals ().skipped_test_cases (), 2u)
                  and eq (runs.first, 0) and eq (runs.second, 0))
            << "partial name does not match";
        local_counts.successful_checks++;

        // Without patterns, everything runs.
        runner_options all_options{};
        all_options.verbosity_level = verbosity::silent;

        runs = runs_t{};
        runner all_runner;
        all_runner.initialise (all_options);
        add_suites (all_runner);

        t.expect (eq (all_runner.run (), 0)
                  and eq (all_runner.skipped_suites_count (), 0u)
                  and eq (all_runner.totals ().skipped_test_cases (), 0u)
                  and eq (runs.first, 3) and eq (runs.other, 3))
            << "nothing skipped without patterns";
        local_counts.successful_checks++;

        // A missing pattern is an option error.
        char* missing_argv[] = { arg_name, arg_silent, arg_filter, nullptr };

        runner missing_runner;
        missing_runner.initialise (3, missing_argv);

        t.expect (eq (missing_runner.run (), 2)) << "missing pattern";
        local_counts.successful_checks++;

        local_counts.executed_test_cases++;
      });

    // The abort handler can be replaced, and, when exceptions are
    // available, it can return control to the application by throwing
    // (API-REVIEW.md #21).
    ts.test ("Abort handler", [] (auto& t)
      {
        runner local_runner;

        t.expect (local_runner.set_abort_handler (test_abort_handler)
                  == nullptr)
            << "no initial handler";
        local_counts.successful_checks++;

#if defined(__EXCEPTIONS)
        bool caught = false;
        try
          {
            local_runner.abort ();
          }
        catch (const abort_exception&)
          {
            caught = true;
          }

        t.expect (caught) << "handler called";
        local_counts.successful_checks++;
#endif // defined(__EXCEPTIONS)

        t.expect (local_runner.set_abort_handler (nullptr)
                  == &test_abort_handler)
            << "previous handler returned";
        local_counts.successful_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);
  } };

// ----------------------------------------------------------------------------
