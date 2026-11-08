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

namespace mt = micro_os_plus::micro_test_plus;
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

static mt::static_suite ts_comparisons{ "Comparisons suite", tr, [] (auto& ts)
  {
    const mt::counters& current_suite_totals = ts.totals ();

    local_counts = {};

    ts.test ("Integer comparisons", [] (auto& t)
      {
        t.expect (mt::eq (my_actual_integral (), 42)) << "actual == 42";
        local_counts.passed_checks++;

        t.expect (mt::ne (my_actual_integral_more<int> (), 42))
            << "actual+1 != 42";
        local_counts.passed_checks++;

        t.expect (mt::lt (my_actual_integral_less<int> (), 42))
            << "actual-1 < 42";
        local_counts.passed_checks++;

        t.expect (mt::le (my_actual_integral (), 42)) << "actual <= 42";
        local_counts.passed_checks++;

        t.expect (mt::gt (my_actual_integral_more<int> (), 42))
            << "actual+1 > 42";
        local_counts.passed_checks++;

        t.expect (mt::ge (my_actual_integral (), 42)) << "actual >= 42";
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

        t.expect (mt::ne (my_actual_integral (), 42)) << "actual != 42";
        local_counts.failed_checks++;

        t.expect (mt::eq (my_actual_integral_more<int> (), 42))
            << "actual+1 == 42";
        local_counts.failed_checks++;

        t.expect (mt::ge (my_actual_integral_less<int> (), 42))
            << "actual-1 >= 42";
        local_counts.failed_checks++;

        t.expect (mt::gt (my_actual_integral (), 42)) << "actual > 42";
        local_counts.failed_checks++;

        t.expect (mt::le (my_actual_integral_more<int> (), 42))
            << "actual+1 <= 42";
        local_counts.failed_checks++;

        t.expect (mt::lt (my_actual_integral (), 42)) << "actual < 42";
        local_counts.failed_checks++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // -------------------------------------------------------------------------

    // The character types are compared as the numbers that they hold, so
    // the comparison with an integer of the other signedness does not
    // convert the signed operand to the unsigned type.
    ts.test ("Character and integer comparisons", [] (auto& t)
      {
        t.expect (mt::gt (U'a', -1)) << "U'a' > -1";
        local_counts.passed_checks++;

        t.expect (mt::lt (-1, U'a')) << "-1 < U'a'";
        local_counts.passed_checks++;

        t.expect (mt::ne (U'\xFFFFFFFF', -1)) << "U'\\xFFFFFFFF' != -1";
        local_counts.passed_checks++;

        t.expect (mt::eq (U'a', 97)) << "U'a' == 97";
        local_counts.passed_checks++;

        t.expect (mt::eq ('a', 97u)) << "'a' == 97u";
        local_counts.passed_checks++;

        t.expect (mt::lt ('a', U'b')) << "'a' < U'b'";
        local_counts.passed_checks++;

        // The signedness of `char` depends on the platform; the result must
        // be that of the numbers, whichever it is.
        const char negative = static_cast<char> (-1);
        t.expect (mt::eq (static_cast<bool> (mt::lt (negative, 1u)),
                          static_cast<int> (negative) < 1))
            << "char lt unsigned";
        local_counts.passed_checks++;

        t.expect (mt::eq (static_cast<bool> (mt::gt (negative, 0u)),
                          static_cast<int> (negative) > 0))
            << "char gt unsigned";
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

    ts.test ("Float comparisons", [] (auto& t)
      {
        t.expect (mt::eq (my_actual_float<float> (), 42.0f))
            << "actual == 42.0f";
        local_counts.passed_checks++;

        t.expect (mt::ne (my_actual_float<float> (), 43.0f))
            << "actual != 43.0f";
        local_counts.passed_checks++;

        t.expect (mt::eq (my_actual_float<double> (), 42.0))
            << "actual == 42.0";
        local_counts.passed_checks++;

        t.expect (mt::ne (my_actual_float<double> (), 43.0))
            << "actual != 43.0";
        local_counts.passed_checks++;

        t.expect (mt::eq (my_actual_float<float> (), 42.0))
            << "actual == 42.0";
        local_counts.passed_checks++;

        t.expect (mt::ne (my_actual_float<double> (), 43.0))
            << "actual != 43.0";
        local_counts.passed_checks++;

        t.expect (mt::eq (my_actual_float<double> (), 42.0f))
            << "actual == 42.0f";
        local_counts.passed_checks++;

        t.expect (mt::ne (my_actual_float<float> (), 43.0f))
            << "actual != 43.0f";
        local_counts.passed_checks++;

        t.expect (mt::eq (my_actual_float<float> (), 42)) << "actual == 42";
        local_counts.passed_checks++;

        t.expect (mt::ne (my_actual_float<float> (), 43)) << "actual != 43";
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
        t.expect (mt::ne (my_actual_float<float> (), 42.0f))
            << "actual != 42.0";
        local_counts.failed_checks++;

        t.expect (mt::eq (my_actual_float<float> (), 43.0f))
            << "actual == 43.0";
        local_counts.failed_checks++;

        t.expect (mt::ne (my_actual_float<float> (), 42)) << "actual != 42";
        local_counts.failed_checks++;

        t.expect (mt::eq (my_actual_float<float> (), 43)) << "actual == 43";
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
        t.expect (mt::approx (my_actual_integral<int> (), 43, 2))
            << "actual ~ 43 +/- 2";
        local_counts.passed_checks++;

        t.expect (mt::approx (510u, 512u, 3u)) << "510u ~ 512u +/- 3u";
        local_counts.passed_checks++;

        t.expect (mt::approx (0u, -1, 2)) << "0u ~ -1 +/- 2";
        local_counts.passed_checks++;

        t.expect (mt::approx (std::numeric_limits<std::uint64_t>::max (),
                              std::numeric_limits<std::uint64_t>::max () - 1,
                              2))
            << "max ~ max - 1 +/- 2";
        local_counts.passed_checks++;

        t.expect (mt::approx (my_actual_float<float> (), 42.001f, 0.01f))
            << "actual ~ 42.001f +/- 0.01f";
        local_counts.passed_checks++;

        t.expect (mt::approx (1.5, 1.25f, 0.5)) << "1.5 ~ 1.25f +/- 0.5";
        local_counts.passed_checks++;

        t.expect (mt::approx (10, 10.4, 0.5)) << "10 ~ 10.4 +/- 0.5";
        local_counts.passed_checks++;

        // Two equal infinities are at the distance zero (#235).
        constexpr double infinity = std::numeric_limits<double>::infinity ();
        t.expect (mt::approx (infinity, infinity, 0.1)) << "inf ~ inf";
        local_counts.passed_checks++;

        t.expect (mt::approx (-infinity, -infinity, 0.1)) << "-inf ~ -inf";
        local_counts.passed_checks++;

        t.expect (mt::negate (mt::approx (10, 20, 5))) << "not 10 ~ 20 +/- 5";
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
        t.expect (mt::approx (my_actual_integral<int> (), 45, 2))
            << "actual ~ 45 +/- 2";
        local_counts.failed_checks++;

        // The distance is larger than the tolerance.
        t.expect (mt::approx (10, 13, 2)) << "10 ~ 13 +/- 2";
        local_counts.failed_checks++;

        // No wrap around of the unsigned difference.
        t.expect (mt::approx (3u, 5u, 1u)) << "3u ~ 5u +/- 1u";
        local_counts.failed_checks++;

        // A negative tolerance fails.
        t.expect (mt::approx (1, 1, -1)) << "1 ~ 1 +/- -1";
        local_counts.failed_checks++;

        t.expect (mt::approx (my_actual_float<float> (), 42.1f, 0.01f))
            << "actual ~ 42.1f +/- 0.01f";
        local_counts.failed_checks++;

        t.expect (mt::approx (1.0, 1.2, 0.1));
        local_counts.failed_checks++;

        // The infinity of the other sign, a finite value, a NaN, and a
        // negative tolerance fail (#235).
        constexpr double infinity = std::numeric_limits<double>::infinity ();
        t.expect (mt::approx (infinity, -infinity, 0.1)) << "inf ~ -inf";
        local_counts.failed_checks++;

        t.expect (mt::approx (infinity, 1.0, 0.1)) << "inf ~ 1.0";
        local_counts.failed_checks++;

        t.expect (mt::approx (std::numeric_limits<double>::quiet_NaN (),
                              std::numeric_limits<double>::quiet_NaN (), 0.1))
            << "NaN ~ NaN";
        local_counts.failed_checks++;

        t.expect (mt::approx (1.0, 1.0, -0.1)) << "1.0 ~ 1.0 +/- -0.1";
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
        t.expect (mt::eq (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv == abc_sv";
        local_counts.passed_checks++;

        t.expect (mt::ne (std::string_view{ compute_abc () }, "abx"sv))
            << "actual_sv != abx_sv";
        local_counts.passed_checks++;

        t.expect (mt::lt (std::string_view{ compute_abc () }, "abd"sv))
            << "actual_sv < abd_sv";
        local_counts.passed_checks++;

        t.expect (mt::le (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv <= abc_sv";
        local_counts.passed_checks++;

        t.expect (mt::gt (std::string_view{ compute_abc () }, "abb"sv))
            << "actual_sv > abb_sv";
        local_counts.passed_checks++;

        t.expect (mt::ge (std::string_view{ compute_abc () }, "abc"sv))
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
        t.expect (mt::ne (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv != abc_sv";
        local_counts.failed_checks++;

        t.expect (mt::eq (std::string_view{ compute_abc () }, "abx"sv))
            << "actual_sv == abx_sv";
        local_counts.failed_checks++;

        t.expect (mt::ge (std::string_view{ compute_abc () }, "abd"sv))
            << "actual_sv >= abd_sv";
        local_counts.failed_checks++;

        t.expect (mt::gt (std::string_view{ compute_abc () }, "abc"sv))
            << "actual_sv > abc_sv";
        local_counts.failed_checks++;

        t.expect (mt::le (std::string_view{ compute_abc () }, "abb"sv))
            << "actual_sv <= abb_sv";
        local_counts.failed_checks++;

        t.expect (mt::lt (std::string_view{ compute_abc () }, "abc"sv))
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

        t.expect (mt::eq (actual, "abc")) << "actual == \"abc\"";
        t.expect (mt::eq (array, actual)) << "array == actual";
        t.expect (mt::eq ("abc", std::string{ "abc" })) << "\"abc\" == string";
        t.expect (mt::eq (std::string{ "abc" }, actual)) << "string == actual";
        t.expect (mt::eq ("abc"sv, actual)) << "string_view == actual";
        t.expect (mt::ne (actual, "abx")) << "actual != \"abx\"";
        t.expect (mt::lt (actual, "abd")) << "actual < \"abd\"";
        t.expect (mt::le (actual, "abc")) << "actual <= \"abc\"";
        t.expect (mt::gt (actual, "abb")) << "actual > \"abb\"";
        t.expect (mt::ge (actual, "abc")) << "actual >= \"abc\"";
        local_counts.passed_checks += 10;

        t.expect (mt::eq (null_string, nullptr)) << "null_string == nullptr";
        t.expect (mt::ne (null_string, "")) << "null_string != \"\"";
        t.expect (mt::lt (null_string, "")) << "null_string < \"\"";
        local_counts.passed_checks += 3;

        // An array without a terminator is not read beyond its end.
        t.expect (mt::eq (unterminated, "abc")) << "unterminated == \"abc\"";
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

    // The wide and Unicode C strings (arrays, string literals, and
    // pointers of `wchar_t`, `char8_t`, `char16_t`, and `char32_t`) are
    // compared by content, like the `char` ones.
    ts.test ("Wide C string comparisons", [] (auto& t)
      {
        const wchar_t* wide = L"abc";
        const char16_t* utf16 = u"abc";
        const char32_t* utf32 = U"abc";
        const wchar_t* null_wide = nullptr;
        wchar_t unterminated[3] = { L'a', L'b', L'c' };

        t.expect (mt::eq (L"abc", std::wstring{ L"abc", 3 }))
            << "wide literal";
        t.expect (mt::eq (std::wstring{ L"abc", 3 }, wide))
            << "wstring == wide";
        t.expect (mt::eq (wide, L"abc")) << "wide == wide literal";
        t.expect (mt::eq (u8"abc", std::u8string{ u8"abc" })) << "u8 literal";
        // The explicit length avoids a GCC 14 and 15 `-Wstringop-overread`
        // false positive with `-O3 -flto`, which source pragmas cannot
        // silence.
        t.expect (mt::eq (u"abc", std::u16string{ u"abc", 3 }))
            << "u16 literal";
        t.expect (mt::eq (utf16, u"abc")) << "utf16 == u16 literal";
        t.expect (mt::eq (U"abc", std::u32string{ U"abc" })) << "u32 literal";
        t.expect (mt::eq (utf32, U"abc")) << "utf32 == u32 literal";
        t.expect (mt::ne (wide, L"abx")) << "wide != \"abx\"";
        t.expect (mt::lt (wide, L"abd")) << "wide < \"abd\"";
        t.expect (mt::ge (wide, L"abc")) << "wide >= \"abc\"";
        local_counts.passed_checks += 11;

        t.expect (mt::eq (null_wide, nullptr)) << "null_wide == nullptr";
        t.expect (mt::ne (null_wide, L"")) << "null_wide != \"\"";
        local_counts.passed_checks += 2;

        // An array without a terminator is not read beyond its end, and
        // the terminator is not part of the string.
        t.expect (mt::eq (unterminated, L"abc")) << "unterminated == \"abc\"";
        t.expect (mt::eq (L"abc", std::wstring_view{ L"abc" }))
            << "terminator not compared";
        local_counts.passed_checks += 2;

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

        t.expect (mt::eq (actual, "abx")) << "actual == \"abx\"";
        local_counts.failed_checks++;

        t.expect (mt::eq (null_string, "abc")) << "null_string == \"abc\"";
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

    // The failed wide C string comparisons display the strings.
    ts.test ("Failed wide C string comparisons", [] (auto& t)
      {
        const wchar_t* wide = L"abc";
        const wchar_t* null_wide = nullptr;

        t.expect (mt::eq (wide, L"abx")) << "wide == \"abx\"";
        local_counts.failed_checks++;

        t.expect (mt::eq (null_wide, L"abc")) << "null_wide == \"abc\"";
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

        t.expect (mt::eq (ptr1, &one)) << "ptr1 == &one";
        local_counts.passed_checks++;

        t.expect (mt::eq (ptr1, ptr2)) << "ptr1 == ptr2";
        local_counts.passed_checks++;

        t.expect (mt::le (ptr1, ptr2)) << "ptr1 <= ptr2";
        local_counts.passed_checks++;

        t.expect (mt::ge (ptr1, ptr2)) << "ptr1 >= ptr2";
        local_counts.passed_checks++;

        t.expect (mt::ne (ptr1, a_non_nullptr)) << "ptr1 != a_non_nullptr";
        local_counts.passed_checks++;

        t.expect (mt::eq (pfunc, a_func)) << "pfunc == afunc";
        local_counts.passed_checks++;

        t.expect (mt::ne (pfunc, a_non_nullptr)) << "pfunc != a_non_nullptr";
        local_counts.passed_checks++;

        struct
        {
          int one;
          int two;
        } pair;

        int* pone = &pair.one;
        int* ptwo = &pair.two;

        t.expect (mt::lt (pone, ptwo)) << "pone < ptwo";
        local_counts.passed_checks++;

        t.expect (mt::gt (ptwo, pone)) << "ptwo > pone";
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

        t.expect (mt::ne (ptr1, &one)) << "ptr1 != &one";
        local_counts.failed_checks++;

        t.expect (mt::ne (ptr1, ptr2)) << "ptr1 != ptr2";
        local_counts.failed_checks++;

        t.expect (mt::gt (ptr1, ptr2)) << "ptr1 > ptr2";
        local_counts.failed_checks++;

        t.expect (mt::lt (ptr1, ptr2)) << "ptr1 < ptr2";
        local_counts.failed_checks++;

        t.expect (mt::eq (ptr1, a_non_nullptr)) << "ptr1 == a_non_nullptr";
        local_counts.failed_checks++;

        t.expect (mt::ne (pfunc, a_func)) << "pfunc != afunc";
        local_counts.failed_checks++;

        t.expect (mt::eq (pfunc, a_non_nullptr)) << "pfunc == a_non_nullptr";
        local_counts.failed_checks++;

        struct
        {
          int one;
          int two;
        } pair;

        int* pone = &pair.one;
        int* ptwo = &pair.two;

        t.expect (mt::ge (pone, ptwo)) << "pone >= ptwo";
        local_counts.failed_checks++;

        t.expect (mt::le (ptwo, pone)) << "ptwo <= pone";
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

        t.expect (mt::eq (a_nullptr, nullptr)) << "a_nullptr == nullptr";
        local_counts.passed_checks++;

        t.expect (mt::ne (a_non_nullptr, nullptr))
            << "a_non_nullptr != nullptr";
        local_counts.passed_checks++;

        t.expect (mt::eq (pfunc, nullptr)) << "pfunc == nullptr";
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

        t.expect (mt::ne (a_nullptr, nullptr)) << "a_nullptr != nullptr";
        local_counts.failed_checks++;

        t.expect (mt::eq (a_non_nullptr, nullptr))
            << "a_non_nullptr == nullptr";
        local_counts.failed_checks++;

        t.expect (mt::ne (pfunc, nullptr)) << "pfunc != nullptr";
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
        t.expect (mt::negate (mt::ne (my_actual_integral (), 42)))
            << "not (actual != 42)";
        local_counts.passed_checks++;

        t.expect (mt::negate (mt::eq (my_actual_integral (), 42)))
            << "not (actual == 42)";
        local_counts.failed_checks++;

        // The comparisons are written between parentheses, so that the
        // negation is not read as applying to the first operand only
        // (#242); the other operands are not changed.
        t.expect (mt::negate (mt::approx (42, 42, 1)));
        local_counts.failed_checks++;

        t.expect (mt::negate (mt::eq ("abc", "abc")));
        local_counts.failed_checks++;

        t.expect (mt::negate (mt::negate (mt::eq (42, 42))));
        local_counts.passed_checks++;

        t.expect (mt::negate (mt::negate (mt::ne (42, 42))));
        local_counts.failed_checks++;

        t.expect (mt::negate (mt::any_of (mt::eq (42, 42), mt::ne (1, 1))));
        local_counts.failed_checks++;

        t.expect (mt::negate (true));
        local_counts.failed_checks++;

        t.expect (mt::all_of (mt::eq (my_actual_integral (), 42),
                              mt::eq (my_actual_float<float> (), 42.0)))
            << "(actual == 42) and (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (mt::all_of (mt::eq (my_actual_integral (), 42),
                              mt::ne (my_actual_float<float> (), 42.0)))
            << "(actual == 42) and (actual != 42.0)";
        local_counts.failed_checks++;

        t.expect (mt::all_of (mt::ne (my_actual_integral (), 42),
                              mt::eq (my_actual_float<float> (), 42.0)))
            << "(actual != 42) and (actual == 42.0)";
        local_counts.failed_checks++;

        t.expect (mt::all_of (mt::ne (my_actual_integral (), 42),
                              mt::ne (my_actual_float<float> (), 42.0)))
            << "(actual != 42) and (actual != 42.0)";
        local_counts.failed_checks++;

        t.expect (mt::all_of (mt::eq (my_actual_integral (), 42),
                              mt::eq (my_actual_float<float> (), 42.0)));
        local_counts.passed_checks++;

        t.expect (mt::all_of (mt::eq (my_actual_integral (), 42),
                              mt::ne (my_actual_float<float> (), 42.0)));
        local_counts.failed_checks++;

        t.expect (mt::any_of (mt::eq (my_actual_integral (), 42),
                              mt::eq (my_actual_float<float> (), 42.0)))
            << "(actual == 42) or (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (mt::any_of (mt::eq (my_actual_integral (), 42),
                              mt::ne (my_actual_float<float> (), 42.0)))
            << "(actual == 42) or (actual != 42.0)";
        local_counts.passed_checks++;

        t.expect (mt::any_of (mt::ne (my_actual_integral (), 42),
                              mt::eq (my_actual_float<float> (), 42.0)))
            << "(actual != 42) or (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (mt::any_of (mt::ne (my_actual_integral (), 42),
                              mt::ne (my_actual_float<float> (), 42.0)))
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

        t.expect (mt::all_of (mt::eq (actual, 42), mt::lt (actual, 43),
                              mt::gt (actual, 41)))
            << "all_of three true";
        local_counts.passed_checks++;

        t.expect (mt::all_of (mt::eq (actual, 42), mt::ne (actual, 0),
                              mt::lt (actual, 43), mt::le (actual, 42),
                              mt::ge (actual, 42)))
            << "all_of five true";
        local_counts.passed_checks++;

        t.expect (mt::any_of (mt::eq (actual, 0), mt::eq (actual, 1),
                              mt::eq (actual, 42)))
            << "any_of three, the last true";
        local_counts.passed_checks++;

        t.expect (mt::any_of (mt::eq (actual, 42), mt::eq (actual, 0),
                              mt::eq (actual, 1)))
            << "any_of three, the first true";
        local_counts.passed_checks++;

        t.expect (
            mt::all_of (mt::eq (actual, 42),
                        mt::all_of (mt::lt (actual, 43), mt::ne (actual, 0))))
            << "all_of with a nested all_of";
        local_counts.passed_checks++;

        t.expect (mt::negate (mt::all_of (
            mt::eq (actual, 42), mt::eq (actual, 0), mt::eq (actual, 1))))
            << "not all_of";
        local_counts.passed_checks++;

        t.expect (mt::all_of (mt::eq (actual, 42), mt::lt (actual, 41),
                              mt::gt (actual, 41)))
            << "all_of three, the second false";
        local_counts.failed_checks++;

        t.expect (mt::all_of (mt::eq (actual, 42), mt::eq (actual, 42),
                              mt::eq (actual, 42), mt::eq (actual, 0)))
            << "all_of four, the last false";
        local_counts.failed_checks++;

        t.expect (mt::any_of (mt::eq (actual, 0), mt::eq (actual, 1),
                              mt::eq (actual, 2)))
            << "any_of three false";
        local_counts.failed_checks++;

        t.expect (
            mt::any_of (mt::all_of (mt::eq (actual, 0), mt::eq (actual, 42)),
                        mt::all_of (mt::eq (actual, 1), mt::eq (actual, 42),
                                    mt::eq (actual, 2))))
            << "any_of of two all_of";
        local_counts.failed_checks++;

        t.expect (
            mt::all_of (mt::eq (actual, 42),
                        mt::any_of (mt::eq (actual, 0), mt::eq (actual, 1))))
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

    // -------------------------------------------------------------------------

    // The elements of the arrays are compared as the single integers are,
    // by value, not by converting the signed one to the unsigned type.
    ts.test ("Arrays of integers of different signedness", [] (auto& t)
      {
        constexpr unsigned maximum = std::numeric_limits<unsigned>::max ();
        const int signed_values[] = { -1, 2 };
        const unsigned unsigned_values[] = { maximum, 2u };
        const std::array<unsigned, 2> unsigned_array{ maximum, 2u };

        t.expect (mt::ne (signed_values, unsigned_values))
            << "int[] != unsigned[]";
        local_counts.passed_checks++;

        t.expect (mt::ne (signed_values, unsigned_array))
            << "int[] != std::array<unsigned>";
        local_counts.passed_checks++;

        const int equal_values[] = { 1, 2 };
        t.expect (mt::eq (equal_values, std::array<unsigned, 2>{ 1u, 2u }))
            << "int[] == std::array<unsigned> with equal values";
        local_counts.passed_checks++;

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
