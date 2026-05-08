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

#include <string_view>

using namespace std::literals;
using namespace micro_os_plus::micro_test_plus;

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

static static_suite ts_utility{ "Utility suite", tr, [] (auto& ts)
  {
    detail::runner_totals& current_suite_totals = ts.totals ();

    local_counts = {};

    // ------------------------------------------------------------------------

    ts.test ("utility::extract_file_name()", [] (auto& t)
      {
        // Unix-style path — returns filename component.
        t.expect (eq (std::string_view{ utility::extract_file_name (
                          "/home/user/project/test.cpp") },
                      "test.cpp"sv))
            << "Unix path returns filename";
        local_counts.successful_checks++;

        // Windows-style path — returns filename component.
        t.expect (eq (std::string_view{ utility::extract_file_name (
                          "C:\\Users\\user\\project\\test.cpp") },
                      "test.cpp"sv))
            << "Windows path returns filename";
        local_counts.successful_checks++;

        // No separators — returns original string.
        t.expect (
            eq (std::string_view{ utility::extract_file_name ("test.cpp") },
                "test.cpp"sv))
            << "No separator returns original";
        local_counts.successful_checks++;

        // Empty string — returns empty string.
        t.expect (
            eq (std::string_view{ utility::extract_file_name ("") }, ""sv))
            << "Empty string returns empty";
        local_counts.successful_checks++;

        // Mixed separators — last separator wins.
        t.expect (eq (std::string_view{ utility::extract_file_name (
                          "/some/path\\file.cpp") },
                      "file.cpp"sv))
            << "Mixed separators, last wins";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    ts.test ("utility::is_match() — passing", [] (auto& t)
      {
        // Both empty — trivial match.
        t.expect (utility::is_match ("", "")) << "\"\" matches \"\"";
        local_counts.successful_checks++;

        // Empty string against * wildcard.
        t.expect (utility::is_match ("", "*")) << "\"\" matches \"*\"";
        local_counts.successful_checks++;

        // Exact match.
        t.expect (utility::is_match ("abc", "abc")) << "abc matches abc";
        local_counts.successful_checks++;

        // Single-character wildcard.
        t.expect (utility::is_match ("abc", "a?c")) << "abc matches a?c";
        local_counts.successful_checks++;

        // ? matches any single character.
        t.expect (utility::is_match ("abc", "???")) << "abc matches ???";
        local_counts.successful_checks++;

        // * at the end — matches any suffix.
        t.expect (utility::is_match ("abc", "a*")) << "abc matches a*";
        local_counts.successful_checks++;

        // * in the middle — matches interior substring.
        t.expect (utility::is_match ("abc", "a*c")) << "abc matches a*c";
        local_counts.successful_checks++;

        // * alone — matches any string.
        t.expect (utility::is_match ("abc", "*")) << "abc matches *";
        local_counts.successful_checks++;

        // * at the start — matches any prefix.
        t.expect (utility::is_match ("abc", "*bc")) << "abc matches *bc";
        local_counts.successful_checks++;

        // * on both sides — matches any string containing substring.
        t.expect (utility::is_match ("abc", "*b*")) << "abc matches *b*";
        local_counts.successful_checks++;

        // Multiple consecutive * wildcards.
        t.expect (utility::is_match ("abc", "**")) << "abc matches **";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    ts.test ("utility::is_match() — failing", [] (auto& t)
      {
        // Non-empty string against a non-wildcard pattern that does not match.
        t.expect (utility::is_match ("", "abc")) << "\"\" matches abc";
        local_counts.failed_checks++;

        // Wrong leading character — ? does not match first char.
        t.expect (utility::is_match ("abc", "b??")) << "abc matches b??";
        local_counts.failed_checks++;

        // * matches prefix but trailing char prevents match.
        t.expect (utility::is_match ("abc", "a*d")) << "abc matches a*d";
        local_counts.failed_checks++;

        // Case-sensitive mismatch.
        t.expect (utility::is_match ("abc", "*C")) << "abc matches *C";
        local_counts.failed_checks++;

        // Too many ? wildcards.
        t.expect (utility::is_match ("ab", "???")) << "ab matches ???";
        local_counts.failed_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------
  } };

// ----------------------------------------------------------------------------
