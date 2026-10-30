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

#include "unit-checks-test.h"

#include <cstdint>
#include <limits>

using namespace micro_os_plus::micro_test_plus;
using namespace std::literals;

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
#endif // defined(__clang__)
#endif // defined(__GNUC__)

  strcpy (str, "ab");
  strcat (str, "c");

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

  return str;
}

// ----------------------------------------------------------------------------

static static_suite ts_comparisons{ "Comparisons suite", tr, [] (auto& ts)
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

    ts.test ("Integer comparisons", [] (auto& t)
      {
        t.expect (eq (my_actual_integral (), 42)) << "actual == 42";
        local_counts.passed_checks++;

        t.expect (ne (my_actual_integral_more<int> (), 42))
            << "actual+1 != 42";
        local_counts.passed_checks++;

        t.expect (lt (my_actual_integral_less<int> (), 42)) << "actual-1 < 42";
        local_counts.passed_checks++;

        t.expect (le (my_actual_integral (), 42)) << "actual <= 42";
        local_counts.passed_checks++;

        t.expect (gt (my_actual_integral_more<int> (), 42)) << "actual+1 > 42";
        local_counts.passed_checks++;

        t.expect (ge (my_actual_integral (), 42)) << "actual >= 42";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    ts.test ("Failed integer comparisons", [] (auto& t)
      {
        local_counts.executed_test_cases++;

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
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    ts.test ("Float comparisons", [] (auto& t)
      {
        t.expect (eq (my_actual_float<float> (), 42.0f)) << "actual == 42.0f";
        local_counts.passed_checks++;

        t.expect (ne (my_actual_float<float> (), 43.0f)) << "actual != 43.0f";
        local_counts.passed_checks++;

        t.expect (eq (my_actual_float<double> (), 42.0)) << "actual == 42.0";
        local_counts.passed_checks++;

        t.expect (ne (my_actual_float<double> (), 43.0)) << "actual != 43.0";
        local_counts.passed_checks++;

        t.expect (eq (my_actual_float<float> (), 42.0)) << "actual == 42.0";
        local_counts.passed_checks++;

        t.expect (ne (my_actual_float<double> (), 43.0)) << "actual != 43.0";
        local_counts.passed_checks++;

        t.expect (eq (my_actual_float<double> (), 42.0f)) << "actual == 42.0f";
        local_counts.passed_checks++;

        t.expect (ne (my_actual_float<float> (), 43.0f)) << "actual != 43.0f";
        local_counts.passed_checks++;

        t.expect (eq (my_actual_float<float> (), 42)) << "actual == 42";
        local_counts.passed_checks++;

        t.expect (ne (my_actual_float<float> (), 43)) << "actual != 43";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

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

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    // The approximate comparator accepts the integers, the floating-point
    // values, and the wrappers, of mixed types and signedness.
    ts.test ("Approximate comparisons", [] (auto& t)
      {
        t.expect (approx (my_actual_integral<int> (), 43, 2))
            << "actual ~ 43 +/- 2";
        local_counts.passed_checks++;

        t.expect (approx (510u, 512u, 3u)) << "510u ~ 512u +/- 3u";
        local_counts.passed_checks++;

        t.expect (approx (0u, -1, 2)) << "0u ~ -1 +/- 2";
        local_counts.passed_checks++;

        t.expect (approx (std::numeric_limits<std::uint64_t>::max (),
                          std::numeric_limits<std::uint64_t>::max () - 1, 2))
            << "max ~ max - 1 +/- 2";
        local_counts.passed_checks++;

        t.expect (approx (my_actual_float<float> (), 42.001f, 0.01f))
            << "actual ~ 42.001f +/- 0.01f";
        local_counts.passed_checks++;

        t.expect (approx (1.5, 1.25f, 0.5)) << "1.5 ~ 1.25f +/- 0.5";
        local_counts.passed_checks++;

        t.expect (approx (10, 10.4, 0.5)) << "10 ~ 10.4 +/- 0.5";
        local_counts.passed_checks++;

        t.expect (negate (approx (10, 20, 5))) << "not 10 ~ 20 +/- 5";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    ts.test ("Failed approximate comparisons", [] (auto& t)
      {
        t.expect (approx (my_actual_integral<int> (), 45, 2))
            << "actual ~ 45 +/- 2";
        local_counts.failed_checks++;

        // The distance is larger than the tolerance.
        t.expect (approx (10, 13, 2)) << "10 ~ 13 +/- 2";
        local_counts.failed_checks++;

        // No wrap around of the unsigned difference.
        t.expect (approx (3u, 5u, 1u)) << "3u ~ 5u +/- 1u";
        local_counts.failed_checks++;

        // A negative tolerance fails.
        t.expect (approx (1, 1, -1)) << "1 ~ 1 +/- -1";
        local_counts.failed_checks++;

        t.expect (approx (my_actual_float<float> (), 42.1f, 0.01f))
            << "actual ~ 42.1f +/- 0.01f";
        local_counts.failed_checks++;

        t.expect (approx (1.0, 1.2, 0.1));
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    // As all pointers, 'char*' are compared by address.
    // To compare by content, use string_value{}.
    ts.test ("String comparisons", [] (auto& t)
      {
        t.expect (eq (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv == abc_sv";
        local_counts.passed_checks++;

        t.expect (ne (std::string_view{ compute_abc () }, "abx"sv))
            << "actual_sv != abx_sv";
        local_counts.passed_checks++;

        t.expect (lt (std::string_view{ compute_abc () }, "abd"sv))
            << "actual_sv < abd_sv";
        local_counts.passed_checks++;

        t.expect (le (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv <= abc_sv";
        local_counts.passed_checks++;

        t.expect (gt (std::string_view{ compute_abc () }, "abb"sv))
            << "actual_sv > abb_sv";
        local_counts.passed_checks++;

        t.expect (ge (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv >= abc_sv";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

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

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    // The C strings (`char` arrays, string literals, and `char` pointers)
    // are compared by content, also with `std::string`; a null pointer is
    // equal only to another null pointer.
    ts.test ("C string comparisons", [] (auto& t)
      {
        const char* actual = compute_abc ();
        char array[] = "abc";
        const char* null_string = nullptr;
        char unterminated[3] = { 'a', 'b', 'c' };

        t.expect (eq (actual, "abc")) << "actual == \"abc\"";
        t.expect (eq (array, actual)) << "array == actual";
        t.expect (eq ("abc", std::string{ "abc" })) << "\"abc\" == string";
        t.expect (eq (std::string{ "abc" }, actual)) << "string == actual";
        t.expect (eq ("abc"sv, actual)) << "string_view == actual";
        t.expect (ne (actual, "abx")) << "actual != \"abx\"";
        t.expect (lt (actual, "abd")) << "actual < \"abd\"";
        t.expect (le (actual, "abc")) << "actual <= \"abc\"";
        t.expect (gt (actual, "abb")) << "actual > \"abb\"";
        t.expect (ge (actual, "abc")) << "actual >= \"abc\"";
        local_counts.passed_checks += 10;

        t.expect (eq (null_string, nullptr)) << "null_string == nullptr";
        t.expect (ne (null_string, "")) << "null_string != \"\"";
        t.expect (lt (null_string, "")) << "null_string < \"\"";
        local_counts.passed_checks += 3;

        // An array without a terminator is not read beyond its end.
        t.expect (eq (unterminated, "abc")) << "unterminated == \"abc\"";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    // The failed C string comparisons display the strings.
    ts.test ("Failed C string comparisons", [] (auto& t)
      {
        const char* actual = compute_abc ();
        const char* null_string = nullptr;

        t.expect (eq (actual, "abx")) << "actual == \"abx\"";
        local_counts.failed_checks++;

        t.expect (eq (null_string, "abc")) << "null_string == \"abc\"";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    ts.test ("Pointer comparisons", [] (auto& t)
      {
        int one = 1;
        int* ptr1 = &one;
        int* ptr2 = &one;
        void* a_nullptr = nullptr;
        void* a_non_nullptr = &a_nullptr;
        void (*pfunc) (void) = a_func;

        t.expect (eq (ptr1, &one)) << "ptr1 == &one";
        local_counts.passed_checks++;

        t.expect (eq (ptr1, ptr2)) << "ptr1 == ptr2";
        local_counts.passed_checks++;

        t.expect (le (ptr1, ptr2)) << "ptr1 <= ptr2";
        local_counts.passed_checks++;

        t.expect (ge (ptr1, ptr2)) << "ptr1 >= ptr2";
        local_counts.passed_checks++;

        t.expect (ne (ptr1, a_non_nullptr)) << "ptr1 != a_non_nullptr";
        local_counts.passed_checks++;

        t.expect (eq (pfunc, a_func)) << "pfunc == afunc";
        local_counts.passed_checks++;

        t.expect (ne (pfunc, a_non_nullptr)) << "pfunc != a_non_nullptr";
        local_counts.passed_checks++;

        struct
        {
          int one;
          int two;
        } pair;

        int* pone = &pair.one;
        int* ptwo = &pair.two;

        t.expect (lt (pone, ptwo)) << "pone < ptwo";
        local_counts.passed_checks++;

        t.expect (gt (ptwo, pone)) << "ptwo > pone";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

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

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    ts.test ("Null pointer comparisons", [] (auto& t)
      {
        void* a_nullptr = nullptr;
        void* a_non_nullptr = &a_nullptr;
        void (*pfunc) (void) = nullptr;

        t.expect (eq (a_nullptr, nullptr)) << "a_nullptr == nullptr";
        local_counts.passed_checks++;

        t.expect (ne (a_non_nullptr, nullptr)) << "a_non_nullptr != nullptr";
        local_counts.passed_checks++;

        t.expect (eq (pfunc, nullptr)) << "pfunc == nullptr";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

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

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    ts.test ("Logical operations", [] (auto& t)
      {
        t.expect (negate (ne (my_actual_integral (), 42)))
            << "not (actual != 42)";
        local_counts.passed_checks++;

        t.expect (negate (eq (my_actual_integral (), 42)))
            << "not (actual == 42)";
        local_counts.failed_checks++;

        t.expect (all_of (eq (my_actual_integral (), 42),
                          eq (my_actual_float<float> (), 42.0)))
            << "(actual == 42) and (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (all_of (eq (my_actual_integral (), 42),
                          ne (my_actual_float<float> (), 42.0)))
            << "(actual == 42) and (actual != 42.0)";
        local_counts.failed_checks++;

        t.expect (all_of (ne (my_actual_integral (), 42),
                          eq (my_actual_float<float> (), 42.0)))
            << "(actual != 42) and (actual == 42.0)";
        local_counts.failed_checks++;

        t.expect (all_of (ne (my_actual_integral (), 42),
                          ne (my_actual_float<float> (), 42.0)))
            << "(actual != 42) and (actual != 42.0)";
        local_counts.failed_checks++;

        t.expect (all_of (eq (my_actual_integral (), 42),
                          eq (my_actual_float<float> (), 42.0)));
        local_counts.passed_checks++;

        t.expect (all_of (eq (my_actual_integral (), 42),
                          ne (my_actual_float<float> (), 42.0)));
        local_counts.failed_checks++;

        t.expect (any_of (eq (my_actual_integral (), 42),
                          eq (my_actual_float<float> (), 42.0)))
            << "(actual == 42) or (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (any_of (eq (my_actual_integral (), 42),
                          ne (my_actual_float<float> (), 42.0)))
            << "(actual == 42) or (actual != 42.0)";
        local_counts.passed_checks++;

        t.expect (any_of (ne (my_actual_integral (), 42),
                          eq (my_actual_float<float> (), 42.0)))
            << "(actual != 42) or (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (any_of (ne (my_actual_integral (), 42),
                          ne (my_actual_float<float> (), 42.0)))
            << "(actual != 42) or (actual != 42.0)";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    // The logical functions accept two or more operands; a chain of the
    // same operation is reported as a single group.
    ts.test ("Logical operations with more operands", [] (auto& t)
      {
        const int actual = my_actual_integral ();

        t.expect (all_of (eq (actual, 42), lt (actual, 43), gt (actual, 41)))
            << "all_of three true";
        local_counts.passed_checks++;

        t.expect (all_of (eq (actual, 42), ne (actual, 0), lt (actual, 43),
                          le (actual, 42), ge (actual, 42)))
            << "all_of five true";
        local_counts.passed_checks++;

        t.expect (any_of (eq (actual, 0), eq (actual, 1), eq (actual, 42)))
            << "any_of three, the last true";
        local_counts.passed_checks++;

        t.expect (any_of (eq (actual, 42), eq (actual, 0), eq (actual, 1)))
            << "any_of three, the first true";
        local_counts.passed_checks++;

        t.expect (
            all_of (eq (actual, 42), all_of (lt (actual, 43), ne (actual, 0))))
            << "all_of with a nested all_of";
        local_counts.passed_checks++;

        t.expect (
            negate (all_of (eq (actual, 42), eq (actual, 0), eq (actual, 1))))
            << "not all_of";
        local_counts.passed_checks++;

        t.expect (all_of (eq (actual, 42), lt (actual, 41), gt (actual, 41)))
            << "all_of three, the second false";
        local_counts.failed_checks++;

        t.expect (all_of (eq (actual, 42), eq (actual, 42), eq (actual, 42),
                          eq (actual, 0)))
            << "all_of four, the last false";
        local_counts.failed_checks++;

        t.expect (any_of (eq (actual, 0), eq (actual, 1), eq (actual, 2)))
            << "any_of three false";
        local_counts.failed_checks++;

        t.expect (
            any_of (all_of (eq (actual, 0), eq (actual, 42)),
                    all_of (eq (actual, 1), eq (actual, 42), eq (actual, 2))))
            << "any_of of two all_of";
        local_counts.failed_checks++;

        t.expect (
            all_of (eq (actual, 42), any_of (eq (actual, 0), eq (actual, 1))))
            << "all_of with a nested any_of";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);
  } };

// ----------------------------------------------------------------------------
