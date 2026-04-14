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

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ----------------------------------------------------------------------------

[[maybe_unused]] static void
static_asserts ()
{
  // --------------------------------------------------------------------------
  {
    {
      static_assert (static_cast<int> (verbosity::silent) == 0);
      static_assert (static_cast<int> (verbosity::quiet) == 1);
      static_assert (static_cast<int> (verbosity::normal) == 2);
      static_assert (static_cast<int> (verbosity::verbose) == 3);
    }

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

      static_assert (type_traits::has_value<foo>);
      static_assert (not type_traits::has_value<bar>);
      static_assert (not type_traits::has_value<int>);
      static_assert (not type_traits::has_value<void>);
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

    {
      using namespace literals;
      using namespace operators;

      // Modern to_* wrappers (preferred since 3.2.0).
      static_assert (to_i{ 42 } == 42_i);
      static_assert (to_b{ true });
      static_assert (not to_b{ false });
      static_assert (to_s{ 42 } == 42_s);
      static_assert (to_c{ 42 } == 42_c);
      static_assert (to_sc{ 42 } == 42_sc);
      static_assert (to_l{ 42 } == 42_l);
      static_assert (to_ll{ 42 } == 42_ll);
      static_assert (to_u{ 42u } == 42_u);
      static_assert (to_uc{ 42u } == 42_uc);
      static_assert (to_us{ 42u } == 42_us);
      static_assert (to_ul{ 42u } == 42_ul);
      static_assert (to_ull{ 42u } == 42_ull);
      static_assert (to_ull{ 18'446'744'073'709'551'615ull }
                     == 18'446'744'073'709'551'615_ull);

      // Generic to_t<T> wrapper (since 3.2.0).
      static_assert (to_t<int>{ 42 }.get () == 42);
      static_assert (to_t<bool>{ true }.get ());

      // Deprecated _t<T> generic wrapper.
      static_assert (_t<int>{ 42 }.get () == 42);
    }
  }
}

// ----------------------------------------------------------------------------
