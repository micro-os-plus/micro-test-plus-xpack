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

#include <vector>
#include <string_view>

using namespace std::literals;

// For this test only, make the namespaces globally visible.
using namespace micro_os_plus;
using namespace micro_os_plus::micro_test_plus;

#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif

// ----------------------------------------------------------------------------

static_runner tr{ "Static top suite" };

local_counts_t local_counts;

int
main (int argc, char* argv[])
{
  auto& ts = tr.initialise (argc, argv);

  if (tr.reporter ().verbosity () > verbosity::quiet)
    {
      printf ("\nµTest++ unit tests; some checks are expected to fail.\n");
    }

  // --------------------------------------------------------------------------

  runner_totals& current_suite_totals = ts.totals ();

  ts.test ("assume", [] (auto& t)
    {
      t.assume (true) << "Assumption 1";
      local_counts.successful_checks++;

    // Enable this to check if the test is aborted.
#if 0
      t.assume(false) << "Check assume()";
      local_counts.failed_checks++;
#endif
      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  ts.test ("Initial counters", [] ([[maybe_unused]] auto& t) noexcept
    { local_counts.executed_subtest++; });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  ts.test ("expect(true)", [] (auto& t)
    {
      t.expect (true);
      local_counts.successful_checks++;

      t.assume (true) << "Assumption 2";
      local_counts.successful_checks++;

      t.expect (true) << "TRUE";
      local_counts.successful_checks++;

      // char branch in deferred_reporter_base::operator<<.
      t.expect (true) << 'P';
      local_counts.successful_checks++;

      // Arithmetic (non-char) branch in deferred_reporter_base::operator<<.
      t.expect (true) << 42;
      local_counts.successful_checks++;

      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // t.assume (true) << "Assumption 3";
  // local_counts.successful_checks++;
  // t.assume (true) << "Assumption 4";
  // local_counts.successful_checks++;

  // --------------------------------------------------------------------------

  ts.test ("expect(false)", [] (auto& t)
    {
      t.expect (false);
      local_counts.failed_checks++;

      t.expect (false) << "false";
      local_counts.failed_checks++;

      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  ts.test ("reflection::type_name()", [] (auto& t)
    {
      using namespace std::literals::string_view_literals;

#if 0
    std::string_view sv = reflection::type_name<void> ();
    printf ("|%*.s|\n", sv.length (), sv.data ());
#endif

      t.expect (eq (reflection::type_name<void> (), "void"sv));
      local_counts.successful_checks++;

      t.expect (eq (reflection::type_name<int> (), "int"sv));
      local_counts.successful_checks++;

      t.expect (eq (reflection::type_name<unsigned int> (), "unsigned int"sv));
      local_counts.successful_checks++;

      t.expect (eq (reflection::type_name<float> (), "float"sv));
      local_counts.successful_checks++;

      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  ts.test ("Strings matches", [] (auto& t)
    {
      t.expect (utility::is_match ("", "")) << "empty strings";
      local_counts.successful_checks++;

      t.expect (utility::is_match ("", "*")) << "empty matches *";
      local_counts.successful_checks++;

      t.expect (utility::is_match ("abc", "abc")) << "abc matches abc";
      local_counts.successful_checks++;

      t.expect (utility::is_match ("abc", "a?c")) << "abc matches a?c";
      local_counts.successful_checks++;

      t.expect (utility::is_match ("abc", "a*")) << "abc matches a*";
      local_counts.successful_checks++;

      t.expect (utility::is_match ("abc", "a*c")) << "abc matches a*c";
      local_counts.successful_checks++;

      t.expect (utility::is_match ("abc", "*")) << "abc matches *";
      local_counts.successful_checks++;

      t.expect (utility::is_match ("abc", "*bc")) << "abc matches *bc";
      local_counts.successful_checks++;

      t.expect (utility::is_match ("abc", "*b*")) << "abc matches *b*";
      local_counts.successful_checks++;

      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  ts.test ("Failed strings matches", [] (auto& t)
    {
      t.expect (utility::is_match ("", "abc")) << "empty matches abc";
      local_counts.failed_checks++;

      t.expect (utility::is_match ("abc", "b??")) << "abc matches b??";
      local_counts.failed_checks++;

      t.expect (utility::is_match ("abc", "a*d")) << "abc matches a*d";
      local_counts.failed_checks++;

      t.expect (utility::is_match ("abc", "*C")) << "abc matches *C";
      local_counts.failed_checks++;

      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  ts.test ("Splits", [] (auto& t)
    {
      t.expect (std::vector<std::string_view>{}
                == utility::split<std::string_view> ("", "."))
          << "empty splits into []";
      local_counts.successful_checks++;

      t.expect (std::vector<std::string_view>{ "a" }
                == utility::split<std::string_view> ("a.", "."))
          << "a. splits into [a]";
      local_counts.successful_checks++;

      t.expect (std::vector<std::string_view>{ "a", "b" }
                == utility::split<std::string_view> ("a.b", "."))
          << "a.b splits into [a,b]";
      local_counts.successful_checks++;

      t.expect (std::vector<std::string_view>{ "a", "b", "cde" }
                == utility::split<std::string_view> ("a.b.cde", "."))
          << "a.b.cde splits into [a, b, cde]";
      local_counts.successful_checks++;

      t.expect (std::vector<std::string_view>{ "abc" }
                == utility::split<std::string_view> ("abc", "."))
          << "abc (no delimiter) splits into [abc]";
      local_counts.successful_checks++;

      t.expect (std::vector<std::string_view>{}
                == utility::split<std::string_view> (".", "."))
          << ". (only delimiter) splits into []";
      local_counts.successful_checks++;

      t.expect (std::vector<std::string_view>{ "a" }
                == utility::split<std::string_view> (".a", "."))
          << ".a (leading delimiter) splits into [a]";
      local_counts.successful_checks++;

      t.expect (std::vector<std::string_view>{ "a", "b" }
                == utility::split<std::string_view> ("a..b", "."))
          << "a..b (consecutive delimiters) splits into [a, b]";
      local_counts.successful_checks++;

      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  ts.test ("to_* modern wrappers", [] (auto& t)
    {
      // Verify runtime wrapping of floating-point values.
      float f = 42.0f;
      t.expect (eq (to_f{ f }, 42.0f)) << "to_f wraps float for eq";
      local_counts.successful_checks++;

      double d = 42.0;
      t.expect (eq (to_d{ d }, 42.0)) << "to_d wraps double for eq";
      local_counts.successful_checks++;

      // Generic to_t<T> wrapper in a runtime expectation.
      int x = 42;
      t.expect (eq (to_t<int>{ x }, 42)) << "to_t<int> generic wrapper";
      local_counts.successful_checks++;

      t.expect (eq (_t<int>{ x }, 42)) << "_t<int> deprecated generic wrapper";
      local_counts.successful_checks++;

      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  ts.test ("reflection::short_name()", [] (auto& t)
    {
      // Path with slash — returns filename component.
      t.expect (eq (
          std::string_view{ reflection::short_name ("/some/path/file.cpp") },
          "file.cpp"sv));
      local_counts.successful_checks++;

      // Path without slash — returns original.
      t.expect (eq (std::string_view{ reflection::short_name ("file.cpp") },
                    "file.cpp"sv));
      local_counts.successful_checks++;

      local_counts.executed_subtest++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  ts.test ("Nested subtests", [] (auto& t)
    {
      t.test ("inner subtest", [] (auto& t2)
        {
          t2.expect (eq (1, 1));
          local_counts.successful_checks++;
          local_counts.executed_subtest++; // inner
        });
      local_counts.executed_subtest++; // outer
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_subtests ()
               == local_counts.executed_subtest);

  // --------------------------------------------------------------------------

  {
    runner_totals fresh{};
    test_assert (fresh.was_successful ());
    test_assert (fresh.executed_checks () == 0);
  }

  // After a test case runs:
  test_assert (current_suite_totals.executed_checks ()
               == local_counts.successful_checks + local_counts.failed_checks);

  // --------------------------------------------------------------------------

  // Exercise the dynamic runner::suite() path (registers a child suite
  // that is run lazily inside exit_code()).
  test_assert (tr.suites_count () == 1);
  tr.suite ("Dynamic suite", [] (auto& s)
    {
      s.test ("check in dynamic suite", [] (auto& t)
        { t.expect (eq (1, 1)) << "1 == 1 in dynamic suite"; });
    });
  test_assert (tr.suites_count () == 2);

  // --------------------------------------------------------------------------

  // The inner test should return failure.
  // exit_code() must be always called, otherwise the test suites
  // are not executed.
  int code = tr.exit_code ();
  test_assert (code != 0);

  if (tr.reporter ().verbosity () > verbosity::quiet)
    {
      // On failure it aborts before reaching this point.
      printf ("Overall, the µTest++ unit tests were successful!\n\n");
    }

  return 0;
}

// ----------------------------------------------------------------------------
