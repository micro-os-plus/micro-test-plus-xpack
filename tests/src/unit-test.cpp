/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

#include <micro-os-plus/micro-test-plus.h>

#include <cassert>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <string_view>

#if defined(__EXCEPTIONS)
#include <stdexcept>
#endif // defined(__EXCEPTIONS)

using namespace std::literals;

using namespace micro_os_plus;
using namespace micro_os_plus::micro_test_plus;

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wconversion"

// ----------------------------------------------------------------------------

// The simple way of testing a testing framework without having to resort to
// another testing framework (which might have clashing primitives),
// is to use traditional asserts. To have some minimal control and do not
// depend on NDEBUG, define a custom assert locally.

#define test_assert(EX) \
  (void)((EX) || (local_test_assert (#EX, __FILE__, __LINE__), 0))

static void __attribute__ ((noreturn))
local_test_assert (const char* failedexpr, const char* file, int line)
{
  fprintf (stdout, "\nassertion \"%s\" failed\n", failedexpr);
  fprintf (stdout, "file: \"%s\"\n", file);
  fprintf (stdout, "line: %d\n", line);

  fprintf (stdout, "\nµTest++ unit test failed!\n\n");

  abort ();
  /* NOTREACHED */
}

// ----------------------------------------------------------------------------

// Each test case exercises a method or a family of methods.
// After each test case, the caller checks if the counts of
// passed/failed test conditions matches the local counts.

static struct local_counts_s
{
  int test_cases;
  int successful_checks;
  int failed_checks;
} local_counts;

// ----------------------------------------------------------------------------

// Mock functions used to simulate code computing various
// integer/float/strings.

template <typename T = int>
T
my_actual_integral ()
{
  return 42;
}

template <typename T = int>
T
my_actual_integral_less (void)
{
  return 41;
}

template <typename T = int>
T
my_actual_integral_more (void)
{
  return 43;
}

template <typename T>
T
my_expected_integral (void)
{
  return 42;
}

template <typename T>
T
my_actual_float (void)
{
  return 42.0;
}

template <typename T>
T
my_expected_float (void)
{
  return 42.0;
}

static const char*
compute_abc (void)
{
  // Construct it from parts, to catch cases when the comparison is
  // not done via strcmp(), since the compiler will coalesce strings
  // and use the same address.
  static char str[10];
  strcpy (str, "ab");
  strcat (str, "c");
  return str;
}

static void
a_func (void)
{
}

#if defined(__EXCEPTIONS)

static void
exercise_throw (bool mustThrow)
{
  if (mustThrow)
    {
      throw "kaboom";
    }
}

#endif // __EXCEPTIONS)

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  initialize (argc, argv);

  if (reporter.verbosity > verbosity::quiet)
    {
      printf ("\nµTest++ unit tests; some checks are expected to fail.\n");
    }

  // --------------------------------------------------------------------------

  {
    static_assert (
        std::is_same_v<type_traits::list<>,
                       type_traits::function_traits<void ()>::args>);
    static_assert (
        std::is_same_v<void,
                       type_traits::function_traits<void ()>::result_type>);
    static_assert (
        std::is_same_v<type_traits::list<int>,
                       type_traits::function_traits<void (int)>::args>);
    static_assert (
        std::is_same_v<
            type_traits::list<int, const float&>,
            type_traits::function_traits<void (int, const float&)>::args>);
    static_assert (
        std::is_same_v<int,
                       type_traits::function_traits<int ()>::result_type>);
  }

  {
    struct foo
    {
      int value;
    };

    struct bar
    {
    };

    constexpr auto value = [] (auto t) -> decltype (t.value, void ()) {};
    static_assert (type_traits::is_valid<foo> (value));
    static_assert (not type_traits::is_valid<bar> (value));
    static_assert (not type_traits::is_valid<int> (value));
    static_assert (not type_traits::is_valid<void> (value));
  }

  {
    struct foo
    {
    };

    static_assert (type_traits::is_container_v<std::vector<int>>);
    static_assert (type_traits::is_container_v<std::array<bool, 0>>);
    static_assert (type_traits::is_container_v<std::string>);
    static_assert (type_traits::is_container_v<std::string_view>);
    // static_assert (type_traits::is_container_v<std::map<int, int>>);
    static_assert (not type_traits::is_container_v<int>);
    static_assert (not type_traits::is_container_v<foo>);
    static_assert (not type_traits::is_container_v<void>);
  }

  {
    using namespace literals;
    using namespace operators;

    static_assert ("true"_b);
    static_assert ((not "true"_b) != "true"_b);
    static_assert ("named"_b);
    static_assert (42 == 42_i);
    static_assert (0u == 0_u);
    static_assert (42u == 42_u);
    static_assert (42 == 42_s);
    static_assert (42 == 42_c);
    static_assert (42 == 42_l);
    static_assert (42 == 42_ll);
    static_assert (42u == 42_uc);
    static_assert (42u == 42_us);
    static_assert (42u == 42_us);
    static_assert (42u == 42_ul);
    static_assert (42 == 42_i8);
    static_assert (42 == 42_i16);
    static_assert (42 == 42_i32);
    static_assert (42 == 42_i64);
    static_assert (42u == 42_u8);
    static_assert (42u == 42_u16);
    static_assert (42u == 42_u32);
    static_assert (42u == 42_u64);
    static_assert (42.42f == 42.42_f);
    static_assert (42.42 == 42.42_d);
    static_assert (240.209996948 == 240.209996948_d);
    static_assert (static_cast<long double> (42.42) == 42.42_ld);
    static_assert (240.20999694824218 == 240.20999694824218_ld);
    static_assert (0 == 0_i);
    static_assert (10'000 == 10'000_i);
    static_assert (42'000'000 == 42'000'000_i);
    static_assert (9'999 == 9'999_i);
    static_assert (42 == 42_i);
    static_assert (-42 == -42_i);
    static_assert (-42 == -42_i);
    static_assert (0. == 0.0_d);
    static_assert (0.f == .0_f);
    static_assert (0.1 == .1_d);
    static_assert (0.1 == 0.1_d);
    static_assert (0.1177 == 0.1177_d);
    static_assert (-0.1177 == -0.1177_d);
    static_assert (0.01177 == 0.01177_d);
    static_assert (-0.01177 == -0.01177_d);
    static_assert (0.001177 == 0.001177_d);
    static_assert (-0.001177 == -0.001177_d);
    static_assert (001.001177 == 001.001177_d);
    static_assert (-001.001177 == -001.001177_d);
    static_assert (01.001177 == 01.001177_d);
    static_assert (-01.001177 == -01.001177_d);
    static_assert (0.42f == 0.42_f);
    static_assert (2.42f == 2.42_f);
    static_assert (-2.42 == -2.42_d);
    static_assert (123.456 == 123.456_d);
  }

  {
    using namespace literals;
    using namespace operators;

    static_assert (
        not std::is_same_v<decltype (_sc (42)), decltype (_c (42))>);
    static_assert (not std::is_same_v<decltype (42_sc), decltype (42_c)>);
    static_assert (
        not std::is_same_v<decltype (_sc (42)), decltype (_uc (42u))>);
    static_assert (not std::is_same_v<decltype (42_sc), decltype (42_uc)>);
  }

  {
    using namespace literals;
    using namespace operators;

    static_assert (_i (42) == 42_i);
    static_assert (_b (true));
    static_assert (not _b (false));
    static_assert (_s (42) == 42_s);
    static_assert (_c (42) == 42_c);
    static_assert (_sc (42) == 42_sc);
    static_assert (_l (42) == 42_l);
    static_assert (_ll (42) == 42_ll);
    static_assert (_uc (42u) == 42_uc);
    static_assert (_us (42u) == 42_us);
    static_assert (_us (42u) == 42_us);
    static_assert (_ul (42u) == 42_ul);
    static_assert (_ull (42u) == 42_ull);
    static_assert (_ull (18'446'744'073'709'551'615ull)
                   == 18'446'744'073'709'551'615_ull);
  }

  // --------------------------------------------------------------------------

  // assume(true) << "Assumption";
  // local_counts.successful_checks++;

  // Enable this to check if the asserts trigger.
#if 0
  assume(false) << "Check assume()";
#endif

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Initial counters",
             [] () noexcept { local_counts.test_cases++; });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  test_case ("expect(true)", [] {
    expect (true);
    local_counts.successful_checks++;

    expect (true) << "TRUE";
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  test_case ("expect(false)", [] {
    expect (false);
    local_counts.failed_checks++;

    expect (false) << "false";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  test_case ("Integer comparisons", [] {
    expect (eq (my_actual_integral (), 42)) << "actual == 42";
    local_counts.successful_checks++;

    expect (ne (my_actual_integral_more<int> (), 42)) << "actual+1 != 42";
    local_counts.successful_checks++;

    expect (lt (my_actual_integral_less<int> (), 42)) << "actual-1 < 42";
    local_counts.successful_checks++;

    expect (le (my_actual_integral (), 42)) << "actual <= 42";
    local_counts.successful_checks++;

    expect (gt (my_actual_integral_more<int> (), 42)) << "actual+1 > 42";
    local_counts.successful_checks++;

    expect (ge (my_actual_integral (), 42)) << "actual >= 42";
    local_counts.successful_checks++;

    {
      using namespace literals;

      expect (eq (42_i, 42_i));
      local_counts.successful_checks++;

      expect (eq (42, 42_i)) << "42 == 42_i";
      local_counts.successful_checks++;
    }

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  test_case ("Failed integer comparisons", [] {
    local_counts.test_cases++;

    expect (ne (my_actual_integral (), 42)) << "actual != 42";
    local_counts.failed_checks++;

    expect (eq (my_actual_integral_more<int> (), 42)) << "actual+1 == 42";
    local_counts.failed_checks++;

    expect (ge (my_actual_integral_less<int> (), 42)) << "actual-1 >= 42";
    local_counts.failed_checks++;

    expect (gt (my_actual_integral (), 42)) << "actual > 42";
    local_counts.failed_checks++;

    expect (le (my_actual_integral_more<int> (), 42)) << "actual+1 <= 42";
    local_counts.failed_checks++;

    expect (lt (my_actual_integral (), 42)) << "actual < 42";
    local_counts.failed_checks++;

    {
      using namespace literals;

      expect (ne (42_i, 42_i));
      local_counts.failed_checks++;

      expect (ne (42, 42_i)) << "42 != 42_i";
      local_counts.failed_checks++;
    }
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  test_case ("Float comparisons", [] {
    expect (eq (my_actual_float<float> (), 42.0f)) << "actual == 42.0f";
    local_counts.successful_checks++;

    expect (ne (my_actual_float<float> (), 43.0f)) << "actual != 43.0f";
    local_counts.successful_checks++;

    expect (eq (my_actual_float<double> (), 42.0)) << "actual == 42.0";
    local_counts.successful_checks++;

    expect (ne (my_actual_float<double> (), 43.0)) << "actual != 43.0";
    local_counts.successful_checks++;

    expect (eq (my_actual_float<float> (), 42.0)) << "actual == 42.0";
    local_counts.successful_checks++;

    expect (ne (my_actual_float<double> (), 43.0)) << "actual != 43.0";
    local_counts.successful_checks++;

    expect (eq (my_actual_float<double> (), 42.0f)) << "actual == 42.0f";
    local_counts.successful_checks++;

    expect (ne (my_actual_float<float> (), 43.0f)) << "actual != 43.0f";
    local_counts.successful_checks++;

    expect (eq (my_actual_float<float> (), 42)) << "actual == 42";
    local_counts.successful_checks++;

    expect (ne (my_actual_float<float> (), 43)) << "actual != 43";
    local_counts.successful_checks++;

    {
      using namespace literals;

      expect (eq (_f (42.101f), 42.101_f)) << "42.101f == 42.101_f";
      local_counts.successful_checks++;

      expect (eq (_f (42.101f, 0.01f), 42.10_f))
          << "42.101f epsilon 0.01f == 42.10_f";
      local_counts.successful_checks++;

      expect (ne (_f (42.101f, 0.1f), 42.1000_f))
          << "42.101f epsilon 0.1f != 42.10_f";
      local_counts.successful_checks++;

      expect (eq (_f (42.1010001f, 0.1f), 42.1_f))
          << "42.1010001f epsilon 0.1f == 42.1_f";
      local_counts.successful_checks++;

      expect (ne (_f (42.101f), 42.10_f)) << "42.101f != 42.10_f";
      local_counts.successful_checks++;

      expect (ne (_f (42.101f), 42.100_f)) << "42.101f != 42.100_f";
      local_counts.successful_checks++;

      expect (eq (_f (42.10f), 42.1_f)) << "42.10f == 42.1_f";
      local_counts.successful_checks++;

      expect (eq (_f (42.42f), 42.42_f)) << "42.42f == 42.42_f";
      local_counts.successful_checks++;

      expect (eq (_d (42.42), 42.420_d)) << "42.42 == 42.420_d";
      local_counts.successful_checks++;

      expect (eq (_d (42.0), 42.0_d)) << "42.0 == 42.0_d";
      local_counts.successful_checks++;

      expect (eq (_d (42.), 42._d)) << "42. == 42._d";
      local_counts.successful_checks++;

      expect (eq (_ld{ static_cast<long double> (42.42) }, 42.42_ld))
          << "42.42 == 42.42_ld";
      local_counts.successful_checks++;

      expect (eq (1234._f, 1234.f)) << "1234._f == 1234.f";
      local_counts.successful_checks++;

      expect (eq (1234.56_f, 1234.56f)) << "1234.56_f == 1234.56f";
      local_counts.successful_checks++;

      expect (eq (12345678.9f, 12345678.9_f)) << "12345678.9f == 12345678.9_f";
      local_counts.successful_checks++;

      expect (eq (111111.42f, 111111.42_f)) << "111111.42f == 111111.42_f";
      local_counts.successful_checks++;

      expect (eq (1111111111.42, 1111111111.42_d))
          << "1111111111.42 == 1111111111.42_d";
      local_counts.successful_checks++;
    }

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Failed float comparisons", [] {
    expect (ne (my_actual_float<float> (), 42.0f)) << "actual != 42.0";
    local_counts.failed_checks++;

    expect (eq (my_actual_float<float> (), 43.0f)) << "actual == 43.0";
    local_counts.failed_checks++;

    expect (ne (my_actual_float<float> (), 42)) << "actual != 42";
    local_counts.failed_checks++;

    expect (eq (my_actual_float<float> (), 43)) << "actual == 43";
    local_counts.failed_checks++;

    {
      using namespace literals;

      expect (ne (_f (42.101f), 42.101_f)) << "42.101f != 42.101_f";
      local_counts.failed_checks++;

      expect (ne (_f (42.101f, 0.01f), 42.10_f))
          << "42.101f epsilon 0.01f != 42.10_f";
      local_counts.failed_checks++;

      expect (eq (_f (42.101f, 0.1f), 42.1000_f))
          << "42.101f epsilon 0.1f == 42.10_f";
      local_counts.failed_checks++;

      expect (ne (_f (42.1010001f, 0.1f), 42.1_f))
          << "42.1010001f epsilon 0.1f != 42.1_f";
      local_counts.failed_checks++;

      expect (eq (_f (42.101f), 42.10_f)) << "42.101f == 42.10_f";
      local_counts.failed_checks++;

      expect (eq (_f (42.101f), 42.100_f)) << "42.101f == 42.100_f";
      local_counts.failed_checks++;

      expect (ne (_f (42.10f), 42.1_f)) << "42.10f == 42.1_f";
      local_counts.failed_checks++;

      expect (ne (_f (42.42f), 42.42_f)) << "42.42f == 42.42_f";
      local_counts.failed_checks++;

      expect (ne (_d (42.42), 42.420_d)) << "42.42 == 42.420_d";
      local_counts.failed_checks++;

      expect (ne (_d (42.0), 42.0_d)) << "42.0 == 42.0_d";
      local_counts.failed_checks++;

      expect (ne (_d (42.), 42._d)) << "42. == 42._d";
      local_counts.failed_checks++;

      expect (ne (_ld{ static_cast<long double> (42.42) }, 42.42_ld))
          << "42.42 == 42.42_ld";
      local_counts.failed_checks++;

      expect (ne (1234._f, 1234.f)) << "1234._f == 1234.f";
      local_counts.failed_checks++;

      expect (ne (1234.56_f, 1234.56f)) << "1234.56_f == 1234.56f";
      local_counts.failed_checks++;

      expect (ne (12345678.9f, 12345678.9_f)) << "12345678.9f == 12345678.9_f";
      local_counts.failed_checks++;

      expect (ne (111111.42f, 111111.42_f)) << "111111.42f == 111111.42_f";
      local_counts.failed_checks++;

      expect (ne (1111111111.42, 1111111111.42_d))
          << "1111111111.42 == 1111111111.42_d";
      local_counts.failed_checks++;
    }

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // As all pointers, 'char*' are compared by address.
  // To compare by content, use string_value{}.
  test_case ("String comparisons", [] {
    expect (eq (std::string_view{ compute_abc () }, "abc"sv))
        << "actual_sv == abc_sv";
    local_counts.successful_checks++;

    expect (ne (std::string_view{ compute_abc () }, "abx"sv))
        << "actual_sv != abx_sv";
    local_counts.successful_checks++;

    expect (lt (std::string_view{ compute_abc () }, "abd"sv))
        << "actual_sv < abd_sv";
    local_counts.successful_checks++;

    expect (le (std::string_view{ compute_abc () }, "abc"sv))
        << "actual_sv <= abc_sv";
    local_counts.successful_checks++;

    expect (gt (std::string_view{ compute_abc () }, "abb"sv))
        << "actual_sv > abb_sv";
    local_counts.successful_checks++;

    expect (ge (std::string_view{ compute_abc () }, "abc"sv))
        << "actual_sv >= abc_sv";
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Failed string comparisons", [] {
    expect (ne (std::string_view{ compute_abc () }, "abc"sv))
        << "actual_sv != abc_sv";
    local_counts.failed_checks++;

    expect (eq (std::string_view{ compute_abc () }, "abx"sv))
        << "actual_sv == abx_sv";
    local_counts.failed_checks++;

    expect (ge (std::string_view{ compute_abc () }, "abd"sv))
        << "actual_sv >= abd_sv";
    local_counts.failed_checks++;

    expect (gt (std::string_view{ compute_abc () }, "abc"sv))
        << "actual_sv > abc_sv";
    local_counts.failed_checks++;

    expect (le (std::string_view{ compute_abc () }, "abb"sv))
        << "actual_sv <= abb_sv";
    local_counts.failed_checks++;

    expect (lt (std::string_view{ compute_abc () }, "abc"sv))
        << "actual_sv < abc_sv";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Pointer comparisons", [] {
    int one = 1;
    int* ptr1 = &one;
    int* ptr2 = &one;
    void* a_nullptr = nullptr;
    void* a_non_nullptr = &a_nullptr;
    void (*pfunc) (void) = a_func;

    expect (eq (ptr1, &one)) << "ptr1 == &one";
    local_counts.successful_checks++;

    expect (eq (ptr1, ptr2)) << "ptr1 == ptr2";
    local_counts.successful_checks++;

    expect (le (ptr1, ptr2)) << "ptr1 <= ptr2";
    local_counts.successful_checks++;

    expect (ge (ptr1, ptr2)) << "ptr1 >= ptr2";
    local_counts.successful_checks++;

    expect (ne (ptr1, a_non_nullptr)) << "ptr1 != a_non_nullptr";
    local_counts.successful_checks++;

    expect (eq (pfunc, a_func)) << "pfunc == afunc";
    local_counts.successful_checks++;

    expect (ne (pfunc, a_non_nullptr)) << "pfunc != a_non_nullptr";
    local_counts.successful_checks++;

    struct
    {
      int one;
      int two;
    } pair;

    int* pone = &pair.one;
    int* ptwo = &pair.two;

    expect (lt (pone, ptwo)) << "pone < ptwo";
    local_counts.successful_checks++;

    expect (gt (ptwo, pone)) << "ptwo > pone";
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Failed pointer comparisons", [] {
    int one = 1;
    int* ptr1 = &one;
    int* ptr2 = &one;
    void* a_nullptr = nullptr;
    void* a_non_nullptr = &a_nullptr;
    void (*pfunc) (void) = a_func;

    expect (ne (ptr1, &one)) << "ptr1 != &one";
    local_counts.failed_checks++;

    expect (ne (ptr1, ptr2)) << "ptr1 != ptr2";
    local_counts.failed_checks++;

    expect (gt (ptr1, ptr2)) << "ptr1 > ptr2";
    local_counts.failed_checks++;

    expect (lt (ptr1, ptr2)) << "ptr1 < ptr2";
    local_counts.failed_checks++;

    expect (eq (ptr1, a_non_nullptr)) << "ptr1 == a_non_nullptr";
    local_counts.failed_checks++;

    expect (ne (pfunc, a_func)) << "pfunc != afunc";
    local_counts.failed_checks++;

    expect (eq (pfunc, a_non_nullptr)) << "pfunc == a_non_nullptr";
    local_counts.failed_checks++;

    struct
    {
      int one;
      int two;
    } pair;

    int* pone = &pair.one;
    int* ptwo = &pair.two;

    expect (ge (pone, ptwo)) << "pone >= ptwo";
    local_counts.failed_checks++;

    expect (le (ptwo, pone)) << "ptwo <= pone";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Null pointer comparisons", [] {
    void* a_nullptr = nullptr;
    void* a_non_nullptr = &a_nullptr;
    void (*pfunc) (void) = nullptr;

    expect (eq (a_nullptr, nullptr)) << "a_nullptr == nullptr";
    local_counts.successful_checks++;

    expect (ne (a_non_nullptr, nullptr)) << "a_non_nullptr != nullptr";
    local_counts.successful_checks++;

    expect (eq (pfunc, nullptr)) << "pfunc == nullptr";
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Failed null pointer comparisons", [] {
    void* a_nullptr = nullptr;
    void* a_non_nullptr = &a_nullptr;
    void (*pfunc) (void) = nullptr;

    expect (ne (a_nullptr, nullptr)) << "a_nullptr != nullptr";
    local_counts.failed_checks++;

    expect (eq (a_non_nullptr, nullptr)) << "a_non_nullptr == nullptr";
    local_counts.failed_checks++;

    expect (ne (pfunc, nullptr)) << "pfunc != nullptr";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  test_case ("reflection::type_name()", [] {
    using namespace std::literals::string_view_literals;

#if 0
    std::string_view sv = reflection::type_name<void> ();
    printf ("|%*.s|\n", sv.length (), sv.data ());
#endif

    expect (eq (reflection::type_name<void> (), "void"sv));
    local_counts.successful_checks++;

    expect (eq (reflection::type_name<int> (), "int"sv));
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

#if defined(__EXCEPTIONS)

  test_case ("thrown exceptions", [] {
    expect (throws ([] { exercise_throw (true); })) << "exception thrown";
    local_counts.successful_checks++;

    expect (throws<std::runtime_error> ([] {
      throw std::runtime_error{ "" };
    })) << "std::runtime_error thrown";
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Failed thrown exceptions", [] {
    expect (throws ([] { exercise_throw (false); })) << "exception thrown";
    local_counts.failed_checks++;

    expect (throws<std::runtime_error> ([] {
      throw std::invalid_argument{ "" };
    })) << "std::runtime_error thrown";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Not thrown exceptions", [] {
    expect (nothrow ([] { exercise_throw (false); }))
        << "exception not thrown";
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Failed not thrown exceptions", [] {
    expect (nothrow ([] { exercise_throw (true); })) << "exception not thrown";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

#endif // __EXCEPTIONS

  test_case ("Logical operations", [] {
    expect (_not (ne (my_actual_integral (), 42))) << "not (actual != 42)";
    local_counts.successful_checks++;

    expect (_not (eq (my_actual_integral (), 42))) << "not (actual == 42)";
    local_counts.failed_checks++;

    expect (_and (eq (my_actual_integral (), 42),
                  eq (my_actual_float<float> (), 42.0)))
        << "(actual == 42) and (actual == 42.0)";
    local_counts.successful_checks++;

    expect (_and (eq (my_actual_integral (), 42),
                  ne (my_actual_float<float> (), 42.0)))
        << "(actual == 42) and (actual != 42.0)";
    local_counts.failed_checks++;

    expect (_and (ne (my_actual_integral (), 42),
                  eq (my_actual_float<float> (), 42.0)))
        << "(actual != 42) and (actual == 42.0)";
    local_counts.failed_checks++;

    expect (_and (ne (my_actual_integral (), 42),
                  ne (my_actual_float<float> (), 42.0)))
        << "(actual != 42) and (actual != 42.0)";
    local_counts.failed_checks++;

    expect (_and (eq (my_actual_integral (), 42),
                  eq (my_actual_float<float> (), 42.0)));
    local_counts.successful_checks++;

    expect (_and (eq (my_actual_integral (), 42),
                  ne (my_actual_float<float> (), 42.0)));
    local_counts.failed_checks++;

    expect (_or (eq (my_actual_integral (), 42),
                 eq (my_actual_float<float> (), 42.0)))
        << "(actual == 42) or (actual == 42.0)";
    local_counts.successful_checks++;

    expect (_or (eq (my_actual_integral (), 42),
                 ne (my_actual_float<float> (), 42.0)))
        << "(actual == 42) or (actual != 42.0)";
    local_counts.successful_checks++;

    expect (_or (ne (my_actual_integral (), 42),
                 eq (my_actual_float<float> (), 42.0)))
        << "(actual != 42) or (actual == 42.0)";
    local_counts.successful_checks++;

    expect (_or (ne (my_actual_integral (), 42),
                 ne (my_actual_float<float> (), 42.0)))
        << "(actual != 42) or (actual != 42.0)";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Operators", [] {
    using namespace operators;
    using namespace literals;

    expect (my_actual_integral () == 42_i) << "actual == 42";
    local_counts.successful_checks++;

    expect (my_actual_integral_more<int> () == 42)
        << "actual+1 == 42 with scalar";
    local_counts.failed_checks++;

    expect (my_actual_integral_more<int> () == 42_i)
        << "actual+1 == 42 with _i literal";
    local_counts.failed_checks++;

    expect (_i (my_actual_integral_more<int> ()) == 42)
        << "actual+1 == 42 with _i()";
    local_counts.failed_checks++;

    expect (my_actual_integral_more<int> () != 42_i) << "actual+1 != 42";
    local_counts.successful_checks++;

    expect (my_actual_integral_less<int> () < 42_i) << "actual-1 < 42";
    local_counts.successful_checks++;

    expect (my_actual_integral () <= 42_i) << "actual <= 42";
    local_counts.successful_checks++;

    expect (my_actual_integral_more<int> () > 42_i) << "actual+1 > 42";
    local_counts.successful_checks++;

    expect (my_actual_integral () >= 42_i) << "actual >= 42";
    local_counts.successful_checks++;

    expect (!(my_actual_integral () != 42_i)) << "not (actual != 42)";
    local_counts.successful_checks++;

    expect (!(my_actual_integral () == 42_i)) << "not (actual == 42)";
    local_counts.failed_checks++;

    expect (((my_actual_integral () == 42_i)
             && (my_actual_float<float> () == 42.0_d)))
        << "(actual == 42) and (actual == 42.0)";
    local_counts.successful_checks++;

    expect (((my_actual_integral () == 42_i)
             && (my_actual_float<float> () != 42.0_d)))
        << "(actual == 42) and (actual != 42.0)";
    local_counts.failed_checks++;

    expect (((my_actual_integral () != 42_i)
             && (my_actual_float<float> () == 42.0_d)))
        << "(actual != 42) and (actual == 42.0)";
    local_counts.failed_checks++;

    expect (((my_actual_integral () != 42_i)
             && (my_actual_float<float> () != 42.0_d)))
        << "(actual != 42) and (actual != 42.0)";
    local_counts.failed_checks++;

    expect (((my_actual_integral () == 42_i)
             && (my_actual_float<float> () == 42.0_d)));
    local_counts.successful_checks++;

    expect (((my_actual_integral () == 42_i)
             && (my_actual_float<float> () != 42.0_d)));
    local_counts.failed_checks++;

    expect (
        ((my_actual_integral () == 42) || (my_actual_float<float> () == 42.0)))
        << "(actual == 42) or (actual == 42.0)";
    local_counts.successful_checks++;

    expect (
        ((my_actual_integral () == 42) || (my_actual_float<float> () != 42.0)))
        << "(actual == 42) or (actual != 42.0)";
    local_counts.successful_checks++;

    expect (
        ((my_actual_integral () != 42) || (my_actual_float<float> () == 42.0)))
        << "(actual != 42) or (actual == 42.0)";
    local_counts.successful_checks++;

    expect (
        (my_actual_integral () != 42_i || my_actual_float<float> () != 42.0_f))
        << "(actual != 42) or (actual != 42.0)";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  test_case ("Strings matches", [] {
    expect (utility::is_match ("", "")) << "empty strings";
    local_counts.successful_checks++;

    expect (utility::is_match ("", "*")) << "empty matches *";
    local_counts.successful_checks++;

    expect (utility::is_match ("abc", "abc")) << "abc matches abc";
    local_counts.successful_checks++;

    expect (utility::is_match ("abc", "a?c")) << "abc matches a?c";
    local_counts.successful_checks++;

    expect (utility::is_match ("abc", "a*")) << "abc matches a*";
    local_counts.successful_checks++;

    expect (utility::is_match ("abc", "a*c")) << "abc matches a*c";
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Failed strings matches", [] {
    expect (utility::is_match ("", "abc")) << "empty matches abc";
    local_counts.failed_checks++;

    expect (utility::is_match ("abc", "b??")) << "abc matches b??";
    local_counts.failed_checks++;

    expect (utility::is_match ("abc", "a*d")) << "abc matches a*d";
    local_counts.failed_checks++;

    expect (utility::is_match ("abc", "*C")) << "abc matches *C";
    local_counts.failed_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  test_case ("Splits", [] {
    expect (std::vector<std::string_view>{}
            == utility::split<std::string_view> ("", "."))
        << "empty splits into []";
    local_counts.successful_checks++;

    expect (std::vector<std::string_view>{ "a" }
            == utility::split<std::string_view> ("a.", "."))
        << "a. splits into [a]";
    local_counts.successful_checks++;

    expect (std::vector<std::string_view>{ "a", "b" }
            == utility::split<std::string_view> ("a.b", "."))
        << "a.b splits into [a,b]";
    local_counts.successful_checks++;

    expect (std::vector<std::string_view>{ "a", "b", "cde" }
            == utility::split<std::string_view> ("a.b.cde", "."))
        << "a.b.cde splits into [a, b, cde]";
    local_counts.successful_checks++;

    local_counts.test_cases++;
  });

  test_assert (current_test_suite->successful_checks ()
               == local_counts.successful_checks);
  test_assert (current_test_suite->failed_checks ()
               == local_counts.failed_checks);
  test_assert (current_test_suite->test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------
  // The inner test should return failure.
  // exit_code() must be always called, otherwise the test suites
  // are not executed.
  int code = exit_code ();
  test_assert (code != 0);

  if (reporter.verbosity > verbosity::quiet)
    {
      // On failure it aborts before reaching this point.
      printf ("\nOverall, the µTest++ unit tests were successful!\n\n");
    }

  return 0;
}

// ----------------------------------------------------------------------------
// Test suites.

template <typename T>
static void
test_case_expect_passed_integrals_combinatorial ()
{

  expect (
      eq (my_actual_integral<T> (), my_expected_integral<signed long long> ()))
      << "eq matches signed long long";
  local_counts.successful_checks++;

  expect (eq (my_actual_integral<T> (),
              my_expected_integral<unsigned long long> ()))
      << "eq matches unsigned long long";
  local_counts.successful_checks++;

  expect (eq (my_actual_integral<T> (), my_expected_integral<signed long> ()))
      << "eq matches signed long";
  local_counts.successful_checks++;

  expect (
      eq (my_actual_integral<T> (), my_expected_integral<unsigned long> ()))
      << "eq matches unsigned long";
  local_counts.successful_checks++;

  expect (eq (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "eq matches signed int";
  local_counts.successful_checks++;

  expect (eq (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "eq matches unsigned int";
  local_counts.successful_checks++;

  expect (eq (my_actual_integral<T> (), my_expected_integral<signed short> ()))
      << "eq matches signed short";
  local_counts.successful_checks++;

  expect (
      eq (my_actual_integral<T> (), my_expected_integral<unsigned short> ()))
      << "eq matches unsigned short";
  local_counts.successful_checks++;

  expect (eq (my_actual_integral<T> (), my_expected_integral<signed char> ()))
      << "eq matches signed char";
  local_counts.successful_checks++;

  expect (
      eq (my_actual_integral<T> (), my_expected_integral<unsigned char> ()))
      << "eq matches unsigned char";
  local_counts.successful_checks++;

  // --------------------------------------------------------------------------

  expect (le (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "le matches signed int";
  local_counts.successful_checks++;

  expect (ge (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "ge matches signed int";
  local_counts.successful_checks++;

  expect (
      ne (my_actual_integral_more<T> (), my_expected_integral<signed int> ()))
      << "ne matches signed int";
  local_counts.successful_checks++;

  expect (
      lt (my_actual_integral_less<T> (), my_expected_integral<signed int> ()))
      << "lt matches signed int";
  local_counts.successful_checks++;

  expect (
      gt (my_actual_integral_more<T> (), my_expected_integral<signed int> ()))
      << "gt matches signed int";
  local_counts.successful_checks++;

  expect (le (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "le matches unsigned int";
  local_counts.successful_checks++;

  expect (ge (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "ge matches unsigned int";
  local_counts.successful_checks++;

  expect (ne (my_actual_integral_more<T> (),
              my_expected_integral<unsigned int> ()))
      << "ne matches unsigned int";
  local_counts.successful_checks++;

  expect (lt (my_actual_integral_less<T> (),
              my_expected_integral<unsigned int> ()))
      << "lt matches unsigned int";
  local_counts.successful_checks++;

  expect (gt (my_actual_integral_more<T> (),
              my_expected_integral<unsigned int> ()))
      << "gt matches unsigned int";
  local_counts.successful_checks++;

  local_counts.test_cases++;
}

template <typename T>
static void
test_case_expect_failed_integrals_combinatorial ()
{

  expect (
      ne (my_actual_integral<T> (), my_expected_integral<signed long long> ()))
      << "ne matches signed long long";
  local_counts.failed_checks++;

  expect (ne (my_actual_integral<T> (),
              my_expected_integral<unsigned long long> ()))
      << "ne matches unsigned long long";
  local_counts.failed_checks++;

  expect (ne (my_actual_integral<T> (), my_expected_integral<signed long> ()))
      << "ne matches signed long";
  local_counts.failed_checks++;

  expect (
      ne (my_actual_integral<T> (), my_expected_integral<unsigned long> ()))
      << "ne matches unsigned long";
  local_counts.failed_checks++;

  expect (ne (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "ne matches signed int";
  local_counts.failed_checks++;

  expect (ne (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "ne matches unsigned int";
  local_counts.failed_checks++;

  expect (ne (my_actual_integral<T> (), my_expected_integral<signed short> ()))
      << "ne matches signed short";
  local_counts.failed_checks++;

  expect (
      ne (my_actual_integral<T> (), my_expected_integral<unsigned short> ()))
      << "ne matches unsigned short";
  local_counts.failed_checks++;

  expect (ne (my_actual_integral<T> (), my_expected_integral<signed char> ()))
      << "ne matches signed char";
  local_counts.failed_checks++;

  expect (
      ne (my_actual_integral<T> (), my_expected_integral<unsigned char> ()))
      << "ne matches unsigned char";
  local_counts.failed_checks++;

  // --------------------------------------------------------------------------

  expect (gt (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "gt matches signed int";
  local_counts.failed_checks++;

  expect (lt (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "lt matches signed int";
  local_counts.failed_checks++;

  expect (
      eq (my_actual_integral_more<T> (), my_expected_integral<signed int> ()))
      << "eq matches signed int";
  local_counts.failed_checks++;

  expect (
      ge (my_actual_integral_less<T> (), my_expected_integral<signed int> ()))
      << "ge matches signed int";
  local_counts.failed_checks++;

  expect (
      le (my_actual_integral_more<T> (), my_expected_integral<signed int> ()))
      << "le matches signed int";
  local_counts.failed_checks++;

  expect (gt (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "gt matches unsigned int";
  local_counts.failed_checks++;

  expect (lt (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "lt matches unsigned int";
  local_counts.failed_checks++;

  expect (eq (my_actual_integral_more<T> (),
              my_expected_integral<unsigned int> ()))
      << "eq matches unsigned int";
  local_counts.failed_checks++;

  expect (ge (my_actual_integral_less<T> (),
              my_expected_integral<unsigned int> ()))
      << "ge matches unsigned int";
  local_counts.failed_checks++;

  expect (le (my_actual_integral_more<T> (),
              my_expected_integral<unsigned int> ()))
      << "le matches unsigned int";
  local_counts.failed_checks++;

  local_counts.test_cases++;
}

template <typename T>
static void
test_case_expect_eq_floats_combinatorial (void)
{
  expect (
      eq (my_actual_float<T> (), my_expected_integral<signed long long> ()))
      << "42.0 == 42 signed long long";
  local_counts.successful_checks++;

  expect (
      eq (my_actual_float<T> (), my_expected_integral<unsigned long long> ()))
      << "42.0 == 42 unsigned long long";
  local_counts.successful_checks++;

  expect (eq (my_actual_float<T> (), my_expected_integral<signed long> ()))
      << "42.0 == 42 signed long";
  local_counts.successful_checks++;

  expect (eq (my_actual_float<T> (), my_expected_integral<unsigned long> ()))
      << "42.0 == 42 unsigned long";
  local_counts.successful_checks++;

  expect (eq (my_actual_float<T> (), my_expected_integral<signed int> ()))
      << "42.0 == 42 signed int";
  local_counts.successful_checks++;

  expect (eq (my_actual_float<T> (), my_expected_integral<unsigned int> ()))
      << "42.0 == 42 unsigned int";
  local_counts.successful_checks++;

  expect (eq (my_actual_float<T> (), my_expected_integral<signed short> ()))
      << "42.0 == 42 signed short";
  local_counts.successful_checks++;

  expect (eq (my_actual_float<T> (), my_expected_integral<unsigned short> ()))
      << "42.0 == 42 unsigned short";
  local_counts.successful_checks++;

  expect (eq (my_actual_float<T> (), my_expected_integral<signed char> ()))
      << "42.0 == 42 signed char";
  local_counts.successful_checks++;

  expect (eq (my_actual_float<T> (), my_expected_integral<unsigned char> ()))
      << "42.0 == 42 unsigned char";
  local_counts.successful_checks++;

  expect (eq (42, my_expected_float<T> ())) << "42 == 42.0";
  local_counts.successful_checks++;

  local_counts.test_cases++;
}

static test_suite ts_passed_integrals = {
  "Combinatorial integrals",
  [] {
    local_counts = {};

    test_case (
        "Combinatorial integrals with signed long long",
        test_case_expect_passed_integrals_combinatorial<signed long long>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case (
        "Combinatorial integrals unsigned long long",
        test_case_expect_passed_integrals_combinatorial<unsigned long long>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with signed int",
               test_case_expect_passed_integrals_combinatorial<signed int>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with unsigned int",
               test_case_expect_passed_integrals_combinatorial<unsigned int>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with signed short",
               test_case_expect_passed_integrals_combinatorial<signed int>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with unsigned short",
               test_case_expect_passed_integrals_combinatorial<unsigned int>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with signed short",
               test_case_expect_passed_integrals_combinatorial<signed short>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case (
        "Combinatorial integrals with unsigned short",
        test_case_expect_passed_integrals_combinatorial<unsigned short>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with signed char",
               test_case_expect_passed_integrals_combinatorial<signed char>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with unsigned char",
               test_case_expect_passed_integrals_combinatorial<unsigned char>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);
  }
};

static test_suite ts_failed_integrals = {
  "Failed combinatorial integrals",
  [] {
    local_counts = {};

    test_case (
        "Combinatorial integrals with signed long long",
        test_case_expect_failed_integrals_combinatorial<signed long long>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case (
        "Combinatorial integrals unsigned long long",
        test_case_expect_failed_integrals_combinatorial<unsigned long long>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with signed int",
               test_case_expect_failed_integrals_combinatorial<signed int>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with unsigned int",
               test_case_expect_failed_integrals_combinatorial<unsigned int>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with signed short",
               test_case_expect_failed_integrals_combinatorial<signed int>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with unsigned short",
               test_case_expect_failed_integrals_combinatorial<unsigned int>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with signed short",
               test_case_expect_failed_integrals_combinatorial<signed short>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case (
        "Combinatorial integrals with unsigned short",
        test_case_expect_failed_integrals_combinatorial<unsigned short>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with signed char",
               test_case_expect_failed_integrals_combinatorial<signed char>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Combinatorial integrals with unsigned char",
               test_case_expect_failed_integrals_combinatorial<unsigned char>);

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);
  }
};

static test_suite ts_passed_floats
    = { "Combinatorial floats", [] {
         local_counts = {};

         test_case ("Combinatorial floats",
                    test_case_expect_eq_floats_combinatorial<float>);

         test_assert (current_test_suite->successful_checks ()
                      == local_counts.successful_checks);
         test_assert (current_test_suite->failed_checks ()
                      == local_counts.failed_checks);
         test_assert (current_test_suite->test_cases ()
                      == local_counts.test_cases);

         test_case ("Combinatorial doubles",
                    test_case_expect_eq_floats_combinatorial<double>);

         test_assert (current_test_suite->successful_checks ()
                      == local_counts.successful_checks);
         test_assert (current_test_suite->failed_checks ()
                      == local_counts.failed_checks);
         test_assert (current_test_suite->test_cases ()
                      == local_counts.test_cases);
       } };

static test_suite ts_misc = {
  "Miscellaneous",
  [] {
    local_counts = {};

    test_case ("Arrays", [] {
      expect (eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
          << "array{ 42 } == array{ 42 }";
      local_counts.successful_checks++;

      expect (ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
          << "array{ 42 } != array{ 43 }";
      local_counts.successful_checks++;

      expect (eq (std::array{ 1, 2 }, std::array{ 1, 2 }))
          << "array{ 1, 2 } == array{ 1, 2 }";
      local_counts.successful_checks++;

      expect (ne (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
          << "array{ 1, 2, 3 } != array{ 1, 2, 4 }";
      local_counts.successful_checks++;

      local_counts.test_cases++;
    });

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Arrays failed", [] {
      expect (ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
          << "array{ 42 } ne array{ 42 }";
      local_counts.failed_checks++;

      expect (eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
          << "array{ 42 } eq array{ 43 }";
      local_counts.failed_checks++;

      expect (ne (std::array{ 1, 2 }, std::array{ 1, 2 }))
          << "array{ 1, 2 } ne array{ 1, 2 }";
      local_counts.failed_checks++;

      expect (eq (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
          << "array{ 1, 2, 3 } eq array{ 1, 2, 4 }";
      local_counts.failed_checks++;

      local_counts.test_cases++;
    });

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Vectors", [] {
      expect (eq (std::vector<int>{}, std::vector<int>{}))
          << "vector{ } == vector{ }";
      local_counts.successful_checks++;

      expect (eq (std::vector<int>{}, std::vector<int>{}));
      local_counts.successful_checks++;

      expect (eq (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
          << "vector{ 42 } == vector{ 42 }";
      local_counts.successful_checks++;

      expect (ne (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
          << "vector{ 42 } != vector{ 43 }";
      local_counts.successful_checks++;

      expect (eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
          << "vector{ 1, 2 } == vector{ 1, 2 }";
      local_counts.successful_checks++;

      expect (ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
          << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
      local_counts.successful_checks++;

      local_counts.test_cases++;
    });

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);

    test_case ("Vectors failed", [] {
      expect (ne (std::vector<int>{}, std::vector<int>{}))
          << "vector{ } != vector{ }";
      local_counts.failed_checks++;

      expect (ne (std::vector<int>{}, std::vector<int>{}));
      local_counts.failed_checks++;

      expect (ne (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
          << "vector{ 42 } != vector{ 42 }";
      local_counts.failed_checks++;

      expect (eq (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
          << "vector{ 42 } == vector{ 43 }";
      local_counts.failed_checks++;

      expect (ne (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
          << "vector{ 1, 2 } != vector{ 1, 2 }";
      local_counts.failed_checks++;

      expect (eq (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
          << "vector{ 1, 2, 3 } == vector{ 1, 2, 4 }";
      local_counts.failed_checks++;

      local_counts.test_cases++;
    });

    test_assert (current_test_suite->successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_test_suite->failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_test_suite->test_cases () == local_counts.test_cases);
  }
};

// ----------------------------------------------------------------------------
