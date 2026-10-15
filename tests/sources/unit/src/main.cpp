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

// Application types used to check that the comparators do not use
// functions of the application named `get` (API-REVIEW.md #5).
namespace user_types
{
  // A type with a free `get()` function in its namespace, which
  // argument-dependent lookup would find.
  struct wrapped
  {
    int v;

    bool
    operator== (const wrapped&) const
        = default;
  };

  constexpr int
  get (const wrapped&)
  {
    return 999;
  }

  // A type with a `get()` member function that does not return its value.
  struct handle
  {
    int id;

    int
    get () const
    {
      return 0;
    }

    bool
    operator== (const handle& other) const
    {
      return id == other.id;
    }
  };

  inline expression_formatter&
  operator<< (expression_formatter& formatter, const wrapped& w)
  {
    return formatter << "wrapped{ " << w.v << " }";
  }

  inline expression_formatter&
  operator<< (expression_formatter& formatter, const handle& h)
  {
    return formatter << "handle{ " << h.id << " }";
  }
} // namespace user_types

// ----------------------------------------------------------------------------

runner tr;

// A second runner, never initialised. Its static suite is constructed
// before it, and is neither counted nor run by `tr` (API-REVIEW.md #26).
extern runner other_runner;

static static_suite other_suite{ "Other runner suite", other_runner,
                                 [] (auto&) noexcept {} };

runner other_runner;

local_counts_t local_counts;

int
main (int argc, char* argv[])
{
  auto& ts = tr.initialise (argc, argv, "Static top suite");

  if (tr.verbosity () > verbosity::quiet)
    {
      printf ("\nµTest++ unit tests; some checks are expected to fail.\n");
    }

  // --------------------------------------------------------------------------

  const counters& current_suite_totals = ts.totals ();

  ts.test ("require", [] (auto& t)
    {
      t.require (true) << "Requirement 1";
      local_counts.successful_checks++;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)
      // The deprecated alias.
      t.assume (true) << "Assumption 1";
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
      local_counts.successful_checks++;

      // The failed requirements are checked in exceptions.cpp; without
      // exceptions, they abort the test execution.
      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  ts.test ("Initial counters", [] ([[maybe_unused]] auto& t) noexcept
    { local_counts.executed_test_cases++; });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  ts.test ("expect(true)", [] (auto& t)
    {
      t.expect (true);
      local_counts.successful_checks++;

      t.require (true) << "Requirement 2";
      local_counts.successful_checks++;

      t.expect (true) << "TRUE";
      local_counts.successful_checks++;

      // char branch in check_result::operator<<.
      t.expect (true) << 'P';
      local_counts.successful_checks++;

      // Arithmetic (non-char) branch in check_result::operator<<.
      t.expect (true) << 42;
      local_counts.successful_checks++;

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  ts.test ("expect(false)", [] (auto& t)
    {
      t.expect (false);
      local_counts.failed_checks++;

      t.expect (false) << "false";
      local_counts.failed_checks++;

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  ts.test ("reflection::type_name()", [] (auto& t)
    {
      using namespace std::literals::string_view_literals;

#if 0
    std::string_view sv = reflection::type_name<void> ();
    printf ("|%*.s|\n", sv.length (), sv.data ());
#endif // 0-1

      t.expect (eq (reflection::type_name<void> (), "void"sv));
      local_counts.successful_checks++;

      t.expect (eq (reflection::type_name<int> (), "int"sv));
      local_counts.successful_checks++;

      t.expect (eq (reflection::type_name<unsigned int> (), "unsigned int"sv));
      local_counts.successful_checks++;

      t.expect (eq (reflection::type_name<float> (), "float"sv));
      local_counts.successful_checks++;

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

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

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

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

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

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

      // Windows-style path — returns filename component, as
      // utility::extract_file_name() does.
      t.expect (eq (std::string_view{ reflection::short_name (
                        "C:\\some\\path\\file.cpp") },
                    "file.cpp"sv));
      local_counts.successful_checks++;

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  ts.test ("Nested subtests", [] (auto& t)
    {
      t.test ("inner subtest", [] (auto& t2)
        {
          t2.expect (eq (1, 1));
          local_counts.successful_checks++;
          local_counts.executed_test_cases++; // inner
        });
      local_counts.executed_test_cases++; // outer
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  // A check in the outer test case before the nested one leaves the
  // outer result in the reporter buffer when the nested test case begins
  // (API-REVIEW.md #1).
  ts.test ("Nested subtest after a check", [] (auto& t)
    {
      t.expect (eq (1, 1)) << "outer check before the nested subtest";
      local_counts.successful_checks++;

      t.test ("inner subtest after a check", [] (auto& t2)
        {
          t2.expect (eq (2, 2)) << "inner check";
          local_counts.successful_checks++;
          local_counts.executed_test_cases++; // inner
        });
      local_counts.executed_test_cases++; // outer
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  // A failed check in a nested test case also fails all the outer test
  // cases, as in node-tap, although their own checks passed
  // (API-REVIEW.md #2).
  {
    const size_t failed_test_cases_before
        = current_suite_totals.failed_test_cases ();

    ts.test ("Failed nested subtest", [] (auto& t)
      {
        t.expect (eq (1, 1)) << "outer check passes";
        local_counts.successful_checks++;

        t.test ("middle subtest", [] (auto& t2)
          {
            t2.test ("inner subtest", [] (auto& t3)
              {
                t3.expect (eq (1, 2)) << "inner check fails";
                local_counts.failed_checks++;
                local_counts.executed_test_cases++; // inner
              });
            local_counts.executed_test_cases++; // middle
          });
        local_counts.executed_test_cases++; // outer
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);
    // The inner, the middle, and the outer test cases failed.
    test_assert (current_suite_totals.failed_test_cases ()
                 == failed_test_cases_before + 3);
  }

  // --------------------------------------------------------------------------

  // The result of a check kept in a variable is reported when the variable
  // goes out of scope, after the later checks, with its own expression
  // (here `1 == 2`), and numbered in the order of the output
  // (API-REVIEW.md #4).
  ts.test ("Stored check result", [] (auto& t)
    {
      {
        auto stored = t.expect (eq (1, 2));
        stored << "stored check fails";
        local_counts.failed_checks++;

        t.expect (eq (3, 3)) << "later check passes";
        local_counts.successful_checks++;
      } // The stored check is reported here.

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  // The comparators compare the application types with their own
  // operators, ignoring the application functions named `get`, both free
  // (found by argument-dependent lookup) and member (API-REVIEW.md #5).
  ts.test ("Application types with get()", [] (auto& t)
    {
      t.expect (ne (user_types::wrapped{ 1 }, user_types::wrapped{ 2 }))
          << "wrapped values differ";
      local_counts.successful_checks++;

      t.expect (eq (user_types::wrapped{ 3 }, user_types::wrapped{ 3 }))
          << "wrapped values are equal";
      local_counts.successful_checks++;

      t.expect (ne (user_types::handle{ 1 }, user_types::handle{ 2 }))
          << "handles differ";
      local_counts.successful_checks++;

      // The framework wrappers are still unwrapped.
      t.expect (eq (to_i{ 42 }, 42)) << "to_i{ 42 } == 42";
      local_counts.successful_checks++;

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  // Values of the fundamental types, including `bool`, can be streamed into
  // the check messages (API-REVIEW.md #6).
  ts.test ("Message values", [] (auto& t)
    {
      const bool flag = true;
      t.expect (flag) << "flag is " << flag << ", not " << !flag;
      local_counts.successful_checks++;

      t.expect (true) << "int " << 42 << ", char " << 'x' << ", double "
                      << 1.25;
      local_counts.successful_checks++;

      // Null C strings are written as `"nullptr"` (API-REVIEW.md #63).
      char* null_string = nullptr;
      const char* null_const_string = nullptr;
      t.expect (true) << "null strings " << null_string << ", "
                      << null_const_string << ", " << nullptr;
      local_counts.successful_checks++;

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  // All six comparisons apply the tolerance of the floating-point literals
  // and wrappers consistently: values within the tolerance are equal, and
  // neither less nor greater; `approx()` makes the tolerance explicit
  // (API-REVIEW.md #9).
  ts.test ("Floating-point tolerance", [] (auto& t)
    {
      using namespace literals;

      // `1.5_d` has a tolerance of 0.1, so 1.45 is equal to it.
      t.expect (eq (1.45, 1.5_d)) << "1.45 == 1.5_d";
      t.expect (negate (lt (1.45, 1.5_d))) << "not 1.45 < 1.5_d";
      t.expect (le (1.45, 1.5_d)) << "1.45 <= 1.5_d";
      t.expect (negate (gt (1.45, 1.5_d))) << "not 1.45 > 1.5_d";
      t.expect (ge (1.45, 1.5_d)) << "1.45 >= 1.5_d";
      t.expect (lt (1.3, 1.5_d)) << "1.3 < 1.5_d (outside the tolerance)";
      local_counts.successful_checks += 6;

      // An explicit tolerance of 0.01.
      t.expect (ne (1.45, approx (1.5, 0.01))) << "1.45 != approx (1.5, 0.01)";
      t.expect (lt (1.45, approx (1.5, 0.01))) << "1.45 < approx (1.5, 0.01)";
      t.expect (eq (1.495, approx (1.5, 0.01)))
          << "1.495 == approx (1.5, 0.01)";
      t.expect (negate (lt (1.495, approx (1.5, 0.01))))
          << "not 1.495 < approx (1.5, 0.01)";
      t.expect (eq (0.1f + 0.2f, approx (0.3f, 1e-6f)))
          << "0.1f + 0.2f == approx (0.3f, 1e-6f)";
      local_counts.successful_checks += 5;

      // A zero tolerance compares the values exactly (API-REVIEW.md #49).
      t.expect (eq (1.5, approx (1.5, 0.0))) << "1.5 == approx (1.5, 0.0)";
      t.expect (negate (ne (1.5, approx (1.5, 0.0))))
          << "not 1.5 != approx (1.5, 0.0)";
      t.expect (le (1.5, approx (1.5, 0.0))) << "1.5 <= approx (1.5, 0.0)";
      t.expect (ge (1.5, approx (1.5, 0.0))) << "1.5 >= approx (1.5, 0.0)";
      local_counts.successful_checks += 4;

      local_counts.executed_test_cases++;
    });

  test_assert (current_suite_totals.successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_suite_totals.failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_suite_totals.executed_test_cases ()
               == local_counts.executed_test_cases);

  // --------------------------------------------------------------------------

  {
    counters fresh{};
    test_assert (fresh.passed ());
    test_assert (fresh.executed_checks () == 0);
  }

  // After a test case runs:
  test_assert (current_suite_totals.executed_checks ()
               == local_counts.successful_checks + local_counts.failed_checks);

  // --------------------------------------------------------------------------

  // Exercise the dynamic runner::suite() path (registers a child suite
  // that is run lazily inside run()).
  test_assert (tr.suites_count () == 1);
  tr.suite ("Dynamic suite", [] (auto& s)
    {
      s.test ("check in dynamic suite", [] (auto& t)
        { t.expect (eq (1, 1)) << "1 == 1 in dynamic suite"; });
    });
  test_assert (tr.suites_count () == 2);

  // The name of a dynamic suite is copied, so it can be a temporary string,
  // destroyed before the suite runs; the name is longer than the short
  // string buffer, so that AddressSanitizer would report a use after free
  // (API-REVIEW.md #11).
  tr.suite (
      std::string ("Dynamic suite with a ").append ("temporary name").c_str (),
      [] (auto& s)
    {
      s.test ("check in dynamic suite with a temporary name", [] (auto& t) {
          t.expect (eq (2, 2)) << "2 == 2 in the suite with a temporary name";
        });
    });
  test_assert (tr.suites_count () == 3);

  // --------------------------------------------------------------------------

  // The static suites are kept in a list independent of the runner
  // objects; each runner counts and runs only its own, and a static suite
  // leaves the list when it is destroyed (API-REVIEW.md #26).
  {
    const size_t static_suites_count = tr.static_suites_count ();
    test_assert (static_suites_count > 0);
    test_assert (tr.total_suites_count ()
                 == tr.suites_count () + static_suites_count);

    test_assert (other_runner.static_suites_count () == 1);
    {
      static_suite local_suite{ "Local static suite", other_runner,
                                [] (auto&) noexcept {} };
      test_assert (other_runner.static_suites_count () == 2);
      test_assert (tr.static_suites_count () == static_suites_count);
    }
    test_assert (other_runner.static_suites_count () == 1);
  }

  // --------------------------------------------------------------------------

  // The inner test should return failure.
  // run() must be always called, otherwise the test suites
  // are not executed.
  int code = tr.run ();
  test_assert (code != 0);

  // The session runs only once; the later calls of run(), and of the
  // deprecated exit_code(), return the same code without running the
  // suites again, and a second initialise() changes nothing
  // (API-REVIEW.md #3).
  {
    const size_t executed_checks = tr.totals ().executed_checks ();
    const size_t executed_test_cases = tr.totals ().executed_test_cases ();

    test_assert (tr.run () == code);
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)
    test_assert (tr.exit_code () == code);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
    test_assert (&tr.initialise (argc, argv) == &ts);

    test_assert (tr.totals ().executed_checks () == executed_checks);
    test_assert (tr.totals ().executed_test_cases () == executed_test_cases);
  }

  if (tr.verbosity () > verbosity::quiet)
    {
      // On failure it aborts before reaching this point.
      printf ("Overall, the µTest++ unit tests were successful!\n\n");
    }

  return 0;
}

// ----------------------------------------------------------------------------
