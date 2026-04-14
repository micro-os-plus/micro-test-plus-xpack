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

using namespace micro_os_plus::micro_test_plus;
using namespace std::literals;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#endif

// ----------------------------------------------------------------------------

static void
a_func (void)
{
}

static const char*
compute_abc (void)
{
  // Construct it from parts, to catch cases when the comparison is
  // not done via strcmp(), since the compiler will coalesce strings
  // and use the same address.
  static char str[10];
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
  strcpy (str, "ab");
  strcat (str, "c");
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  return str;
}

// ----------------------------------------------------------------------------

static static_suite ts_exceptions{ "Comparisons suite", tr, [] (auto& ts)
  {
    runner_totals& current_suite_totals = ts.totals ();

    local_counts = {};

    ts.test ("Integer comparisons", [] (auto& t)
      {
        t.expect (eq (my_actual_integral (), 42)) << "actual == 42";
        local_counts.successful_checks++;

        t.expect (ne (my_actual_integral_more<int> (), 42))
            << "actual+1 != 42";
        local_counts.successful_checks++;

        t.expect (lt (my_actual_integral_less<int> (), 42)) << "actual-1 < 42";
        local_counts.successful_checks++;

        t.expect (le (my_actual_integral (), 42)) << "actual <= 42";
        local_counts.successful_checks++;

        t.expect (gt (my_actual_integral_more<int> (), 42)) << "actual+1 > 42";
        local_counts.successful_checks++;

        t.expect (ge (my_actual_integral (), 42)) << "actual >= 42";
        local_counts.successful_checks++;

        {
          using namespace literals;

          t.expect (eq (42_i, 42_i));
          local_counts.successful_checks++;

          t.expect (eq (42, 42_i)) << "42 == 42_i";
          local_counts.successful_checks++;
        }

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // --------------------------------------------------------------------------

    ts.test ("Failed integer comparisons", [] (auto& t)
      {
        local_counts.executed_subtest++;

        t.expect (ne (my_actual_integral (), 42)) << "actual != 42";
        local_counts.failed_checks++;

        t.expect (eq (my_actual_integral_more<int> (), 42))
            << "actual+1 == 42";
        local_counts.failed_checks++;

        t.expect (ge (my_actual_integral_less<int> (), 42))
            << "actual-1 >= 42";
        local_counts.failed_checks++;

        t.expect (gt (my_actual_integral (), 42)) << "actual > 42";
        local_counts.failed_checks++;

        t.expect (le (my_actual_integral_more<int> (), 42))
            << "actual+1 <= 42";
        local_counts.failed_checks++;

        t.expect (lt (my_actual_integral (), 42)) << "actual < 42";
        local_counts.failed_checks++;

        {
          using namespace literals;

          t.expect (ne (42_i, 42_i)) << "42_i != 42_i";
          local_counts.failed_checks++;

          t.expect (ne (42, 42_i)) << "42 != 42_i";
          local_counts.failed_checks++;
        }
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // --------------------------------------------------------------------------

    ts.test ("Float comparisons", [] (auto& t)
      {
        t.expect (eq (my_actual_float<float> (), 42.0f)) << "actual == 42.0f";
        local_counts.successful_checks++;

        t.expect (ne (my_actual_float<float> (), 43.0f)) << "actual != 43.0f";
        local_counts.successful_checks++;

        t.expect (eq (my_actual_float<double> (), 42.0)) << "actual == 42.0";
        local_counts.successful_checks++;

        t.expect (ne (my_actual_float<double> (), 43.0)) << "actual != 43.0";
        local_counts.successful_checks++;

        t.expect (eq (my_actual_float<float> (), 42.0)) << "actual == 42.0";
        local_counts.successful_checks++;

        t.expect (ne (my_actual_float<double> (), 43.0)) << "actual != 43.0";
        local_counts.successful_checks++;

        t.expect (eq (my_actual_float<double> (), 42.0f)) << "actual == 42.0f";
        local_counts.successful_checks++;

        t.expect (ne (my_actual_float<float> (), 43.0f)) << "actual != 43.0f";
        local_counts.successful_checks++;

        t.expect (eq (my_actual_float<float> (), 42)) << "actual == 42";
        local_counts.successful_checks++;

        t.expect (ne (my_actual_float<float> (), 43)) << "actual != 43";
        local_counts.successful_checks++;

        {
          using namespace literals;

          t.expect (eq (_f (42.101f), 42.101_f)) << "42.101f == 42.101_f";
          local_counts.successful_checks++;

          t.expect (eq (_f (42.101f, 0.01f), 42.10_f))
              << "42.101f epsilon 0.01f == 42.10_f";
          local_counts.successful_checks++;

          t.expect (ne (_f (42.101f, 0.1f), 42.1000_f))
              << "42.101f epsilon 0.1f != 42.10_f";
          local_counts.successful_checks++;

          t.expect (eq (_f (42.1010001f, 0.1f), 42.1_f))
              << "42.1010001f epsilon 0.1f == 42.1_f";
          local_counts.successful_checks++;

          t.expect (ne (_f (42.101f), 42.10_f)) << "42.101f != 42.10_f";
          local_counts.successful_checks++;

          t.expect (ne (_f (42.101f), 42.100_f)) << "42.101f != 42.100_f";
          local_counts.successful_checks++;

          t.expect (eq (_f (42.10f), 42.1_f)) << "42.10f == 42.1_f";
          local_counts.successful_checks++;

          t.expect (eq (_f (42.42f), 42.42_f)) << "42.42f == 42.42_f";
          local_counts.successful_checks++;

          t.expect (eq (_d (42.42), 42.420_d)) << "42.42 == 42.420_d";
          local_counts.successful_checks++;

          t.expect (eq (_d (42.0), 42.0_d)) << "42.0 == 42.0_d";
          local_counts.successful_checks++;

          t.expect (eq (_d (42.), 42._d)) << "42. == 42._d";
          local_counts.successful_checks++;

          t.expect (eq (_ld{ static_cast<long double> (42.42) }, 42.42_ld))
              << "42.42 == 42.42_ld";
          local_counts.successful_checks++;

          t.expect (eq (1234._f, 1234.f)) << "1234._f == 1234.f";
          local_counts.successful_checks++;

          t.expect (eq (1234.56_f, 1234.56f)) << "1234.56_f == 1234.56f";
          local_counts.successful_checks++;

          t.expect (eq (12345678.9f, 12345678.9_f))
              << "12345678.9f == 12345678.9_f";
          local_counts.successful_checks++;

          t.expect (eq (111111.42f, 111111.42_f))
              << "111111.42f == 111111.42_f";
          local_counts.successful_checks++;

          t.expect (eq (1111111111.42, 1111111111.42_d))
              << "1111111111.42 == 1111111111.42_d";
          local_counts.successful_checks++;
        }

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // --------------------------------------------------------------------------

    ts.test ("Failed float comparisons", [] (auto& t)
      {
        t.expect (ne (my_actual_float<float> (), 42.0f)) << "actual != 42.0";
        local_counts.failed_checks++;

        t.expect (eq (my_actual_float<float> (), 43.0f)) << "actual == 43.0";
        local_counts.failed_checks++;

        t.expect (ne (my_actual_float<float> (), 42)) << "actual != 42";
        local_counts.failed_checks++;

        t.expect (eq (my_actual_float<float> (), 43)) << "actual == 43";
        local_counts.failed_checks++;

        {
          using namespace literals;

          t.expect (ne (_f (42.101f), 42.101_f)) << "42.101f != 42.101_f";
          local_counts.failed_checks++;

          t.expect (ne (_f (42.101f, 0.01f), 42.10_f))
              << "42.101f epsilon 0.01f != 42.10_f";
          local_counts.failed_checks++;

          t.expect (eq (_f (42.101f, 0.1f), 42.1000_f))
              << "42.101f epsilon 0.1f == 42.10_f";
          local_counts.failed_checks++;

          t.expect (ne (_f (42.1010001f, 0.1f), 42.1_f))
              << "42.1010001f epsilon 0.1f != 42.1_f";
          local_counts.failed_checks++;

          t.expect (eq (_f (42.101f), 42.10_f)) << "42.101f == 42.10_f";
          local_counts.failed_checks++;

          t.expect (eq (_f (42.101f), 42.100_f)) << "42.101f == 42.100_f";
          local_counts.failed_checks++;

          t.expect (ne (_f (42.10f), 42.1_f)) << "42.10f == 42.1_f";
          local_counts.failed_checks++;

          t.expect (ne (_f (42.42f), 42.42_f)) << "42.42f == 42.42_f";
          local_counts.failed_checks++;

          t.expect (ne (_d (42.42), 42.420_d)) << "42.42 == 42.420_d";
          local_counts.failed_checks++;

          t.expect (ne (_d (42.0), 42.0_d)) << "42.0 == 42.0_d";
          local_counts.failed_checks++;

          t.expect (ne (_d (42.), 42._d)) << "42. == 42._d";
          local_counts.failed_checks++;

          t.expect (ne (_ld{ static_cast<long double> (42.42) }, 42.42_ld))
              << "42.42 == 42.42_ld";
          local_counts.failed_checks++;

          t.expect (ne (1234._f, 1234.f)) << "1234._f == 1234.f";
          local_counts.failed_checks++;

          t.expect (ne (1234.56_f, 1234.56f)) << "1234.56_f == 1234.56f";
          local_counts.failed_checks++;

          t.expect (ne (12345678.9f, 12345678.9_f))
              << "12345678.9f == 12345678.9_f";
          local_counts.failed_checks++;

          t.expect (ne (111111.42f, 111111.42_f))
              << "111111.42f == 111111.42_f";
          local_counts.failed_checks++;

          t.expect (ne (1111111111.42, 1111111111.42_d))
              << "1111111111.42 == 1111111111.42_d";
          local_counts.failed_checks++;
        }

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // --------------------------------------------------------------------------

    // As all pointers, 'char*' are compared by address.
    // To compare by content, use string_value{}.
    ts.test ("String comparisons", [] (auto& t)
      {
        t.expect (eq (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv == abc_sv";
        local_counts.successful_checks++;

        t.expect (ne (std::string_view{ compute_abc () }, "abx"sv))
            << "actual_sv != abx_sv";
        local_counts.successful_checks++;

        t.expect (lt (std::string_view{ compute_abc () }, "abd"sv))
            << "actual_sv < abd_sv";
        local_counts.successful_checks++;

        t.expect (le (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv <= abc_sv";
        local_counts.successful_checks++;

        t.expect (gt (std::string_view{ compute_abc () }, "abb"sv))
            << "actual_sv > abb_sv";
        local_counts.successful_checks++;

        t.expect (ge (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv >= abc_sv";
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

    ts.test ("Failed string comparisons", [] (auto& t)
      {
        t.expect (ne (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv != abc_sv";
        local_counts.failed_checks++;

        t.expect (eq (std::string_view{ compute_abc () }, "abx"sv))
            << "actual_sv == abx_sv";
        local_counts.failed_checks++;

        t.expect (ge (std::string_view{ compute_abc () }, "abd"sv))
            << "actual_sv >= abd_sv";
        local_counts.failed_checks++;

        t.expect (gt (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv > abc_sv";
        local_counts.failed_checks++;

        t.expect (le (std::string_view{ compute_abc () }, "abb"sv))
            << "actual_sv <= abb_sv";
        local_counts.failed_checks++;

        t.expect (lt (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv < abc_sv";
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

    ts.test ("Pointer comparisons", [] (auto& t)
      {
        int one = 1;
        int* ptr1 = &one;
        int* ptr2 = &one;
        void* a_nullptr = nullptr;
        void* a_non_nullptr = &a_nullptr;
        void (*pfunc) (void) = a_func;

        t.expect (eq (ptr1, &one)) << "ptr1 == &one";
        local_counts.successful_checks++;

        t.expect (eq (ptr1, ptr2)) << "ptr1 == ptr2";
        local_counts.successful_checks++;

        t.expect (le (ptr1, ptr2)) << "ptr1 <= ptr2";
        local_counts.successful_checks++;

        t.expect (ge (ptr1, ptr2)) << "ptr1 >= ptr2";
        local_counts.successful_checks++;

        t.expect (ne (ptr1, a_non_nullptr)) << "ptr1 != a_non_nullptr";
        local_counts.successful_checks++;

        t.expect (eq (pfunc, a_func)) << "pfunc == afunc";
        local_counts.successful_checks++;

        t.expect (ne (pfunc, a_non_nullptr)) << "pfunc != a_non_nullptr";
        local_counts.successful_checks++;

        struct
        {
          int one;
          int two;
        } pair;

        int* pone = &pair.one;
        int* ptwo = &pair.two;

        t.expect (lt (pone, ptwo)) << "pone < ptwo";
        local_counts.successful_checks++;

        t.expect (gt (ptwo, pone)) << "ptwo > pone";
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

    ts.test ("Failed pointer comparisons", [] (auto& t)
      {
        int one = 1;
        int* ptr1 = &one;
        int* ptr2 = &one;
        void* a_nullptr = nullptr;
        void* a_non_nullptr = &a_nullptr;
        void (*pfunc) (void) = a_func;

        t.expect (ne (ptr1, &one)) << "ptr1 != &one";
        local_counts.failed_checks++;

        t.expect (ne (ptr1, ptr2)) << "ptr1 != ptr2";
        local_counts.failed_checks++;

        t.expect (gt (ptr1, ptr2)) << "ptr1 > ptr2";
        local_counts.failed_checks++;

        t.expect (lt (ptr1, ptr2)) << "ptr1 < ptr2";
        local_counts.failed_checks++;

        t.expect (eq (ptr1, a_non_nullptr)) << "ptr1 == a_non_nullptr";
        local_counts.failed_checks++;

        t.expect (ne (pfunc, a_func)) << "pfunc != afunc";
        local_counts.failed_checks++;

        t.expect (eq (pfunc, a_non_nullptr)) << "pfunc == a_non_nullptr";
        local_counts.failed_checks++;

        struct
        {
          int one;
          int two;
        } pair;

        int* pone = &pair.one;
        int* ptwo = &pair.two;

        t.expect (ge (pone, ptwo)) << "pone >= ptwo";
        local_counts.failed_checks++;

        t.expect (le (ptwo, pone)) << "ptwo <= pone";
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

    ts.test ("Null pointer comparisons", [] (auto& t)
      {
        void* a_nullptr = nullptr;
        void* a_non_nullptr = &a_nullptr;
        void (*pfunc) (void) = nullptr;

        t.expect (eq (a_nullptr, nullptr)) << "a_nullptr == nullptr";
        local_counts.successful_checks++;

        t.expect (ne (a_non_nullptr, nullptr)) << "a_non_nullptr != nullptr";
        local_counts.successful_checks++;

        t.expect (eq (pfunc, nullptr)) << "pfunc == nullptr";
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

    ts.test ("Failed null pointer comparisons", [] (auto& t)
      {
        void* a_nullptr = nullptr;
        void* a_non_nullptr = &a_nullptr;
        void (*pfunc) (void) = nullptr;

        t.expect (ne (a_nullptr, nullptr)) << "a_nullptr != nullptr";
        local_counts.failed_checks++;

        t.expect (eq (a_non_nullptr, nullptr)) << "a_non_nullptr == nullptr";
        local_counts.failed_checks++;

        t.expect (ne (pfunc, nullptr)) << "pfunc != nullptr";
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

    ts.test ("Logical operations", [] (auto& t)
      {
        t.expect (_not (ne (my_actual_integral (), 42)))
            << "not (actual != 42)";
        local_counts.successful_checks++;

        t.expect (_not (eq (my_actual_integral (), 42)))
            << "not (actual == 42)";
        local_counts.failed_checks++;

        t.expect (_and (eq (my_actual_integral (), 42),
                        eq (my_actual_float<float> (), 42.0)))
            << "(actual == 42) and (actual == 42.0)";
        local_counts.successful_checks++;

        t.expect (_and (eq (my_actual_integral (), 42),
                        ne (my_actual_float<float> (), 42.0)))
            << "(actual == 42) and (actual != 42.0)";
        local_counts.failed_checks++;

        t.expect (_and (ne (my_actual_integral (), 42),
                        eq (my_actual_float<float> (), 42.0)))
            << "(actual != 42) and (actual == 42.0)";
        local_counts.failed_checks++;

        t.expect (_and (ne (my_actual_integral (), 42),
                        ne (my_actual_float<float> (), 42.0)))
            << "(actual != 42) and (actual != 42.0)";
        local_counts.failed_checks++;

        t.expect (_and (eq (my_actual_integral (), 42),
                        eq (my_actual_float<float> (), 42.0)));
        local_counts.successful_checks++;

        t.expect (_and (eq (my_actual_integral (), 42),
                        ne (my_actual_float<float> (), 42.0)));
        local_counts.failed_checks++;

        t.expect (_or (eq (my_actual_integral (), 42),
                       eq (my_actual_float<float> (), 42.0)))
            << "(actual == 42) or (actual == 42.0)";
        local_counts.successful_checks++;

        t.expect (_or (eq (my_actual_integral (), 42),
                       ne (my_actual_float<float> (), 42.0)))
            << "(actual == 42) or (actual != 42.0)";
        local_counts.successful_checks++;

        t.expect (_or (ne (my_actual_integral (), 42),
                       eq (my_actual_float<float> (), 42.0)))
            << "(actual != 42) or (actual == 42.0)";
        local_counts.successful_checks++;

        t.expect (_or (ne (my_actual_integral (), 42),
                       ne (my_actual_float<float> (), 42.0)))
            << "(actual != 42) or (actual != 42.0)";
        local_counts.failed_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);
  } };

// ----------------------------------------------------------------------------
