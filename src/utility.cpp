/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ source file with implementations for the µTest++ utility
 * functions.
 *
 * @details
 * This source file contains the implementations of the utility functions
 * for the µTest++ framework. It provides `extract_file_name()`, which
 * strips the folder path from a file path returning only the base name,
 * and `is_match()`, which performs wildcard pattern matching with `*`
 * (any sequence of characters) and `?` (any single character) support, and the `split()` overload
 * for string views.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::utility` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/utility.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace utility
  {
#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdocumentation"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

    /**
     * @details
     * The `extract_file_name` function extracts the file name from a given
     * file path, handling both Unix-style (`/`) and Windows-style (`\`) path
     * separators. It returns a pointer to the start of the file name within
     * the input string, or the original string if no separators are found.
     *
     * This utility is particularly useful for test reporting, allowing for
     * concise display of file names without full paths.
     *
     * @par Example
     *
     * @code{.cpp}
     * const char* path = "/home/user/project/test.cpp";
     * const char* filename = utility::extract_file_name (path);
     * // filename now points to "test.cpp"
     * @endcode
     */
    [[nodiscard]] const char*
    extract_file_name (const char* path) noexcept
    {
      const std::string_view sv{ path };
      const auto pos = sv.find_last_of ("/\\");
      if (pos == std::string_view::npos)
        {
          return path; // No separators found, return original string.
        }
      return sv.substr (pos + 1).data ();
    }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

    /**
     * @details
     * This function enables pattern-based string comparison for tests,
     * supporting both exact matches and wildcard patterns. The pattern may
     * include `*` to match any sequence of characters (including an empty
     * one) and `?` to match any single character. This allows for flexible
     * validation of string content in test assertions, accommodating
     * variable or partially known values.
     *
     * The match is iterative, with no recursion, so the stack usage is
     * constant, which matters on embedded targets. When a mismatch occurs
     * after a `*`, only the most recent `*` is retried, one character
     * further in the input; the earlier ones never need to be, since any
     * match they could produce is also found by the most recent one. The
     * worst-case complexity is `O(n * m)`, for an input of length `n` and
     * a pattern of length `m`.
     *
     * The function is also used by the runner to select the suites and
     * the test cases matching the `--filter` patterns, for each of the
     * alternatives separated by `|`.
     *
     * @par Examples
     *
     * @code{.cpp}
     * namespace mt = micro_os_plus::micro_test_plus;
     *
     * t.expect (mt::utility::is_match ("abc", "a?c")) << "abc matches a?c";
     * t.expect (mt::utility::is_match ("abc", "a*c")) << "abc matches a*c";
     * @endcode
     */
    [[nodiscard]] bool
    is_match (std::string_view input, std::string_view pattern)
    {
      constexpr auto npos = std::string_view::npos;

      std::size_t i = 0; // Index in the input.
      std::size_t p = 0; // Index in the pattern.

      // The position of the most recent `*` in the pattern, and the input
      // index where its match ends.
      std::size_t star_p = npos;
      std::size_t star_i = 0;

      while (i < input.size ())
        {
          if (p < pattern.size ()
              && (pattern[p] == '?' || pattern[p] == input[i]))
            {
              ++i;
              ++p;
            }
          else if (p < pattern.size () && pattern[p] == '*')
            {
              // Start by matching an empty sequence.
              star_p = p++;
              star_i = i;
            }
          else if (star_p != npos)
            {
              // Extend the match of the most recent `*` by one character.
              p = star_p + 1;
              i = ++star_i;
            }
          else
            {
              return false;
            }
        }

      // The input is exhausted; the rest of the pattern must be only `*`.
      while (p < pattern.size () && pattern[p] == '*')
        {
          ++p;
        }

      return p == pattern.size ();
    }

    /**
     * @details
     * The function iterates through the input, identifying the positions
     * of any of the delimiter characters (via `find_first_of()`) and
     * extracting the views between them. Empty views, such as those
     * between consecutive delimiters, are omitted. It is the overload
     * selected for string literals and `const char*` arguments, which the
     * template cannot handle.
     *
     * @par Example
     *
     * @code{.cpp}
     * namespace mt = micro_os_plus::micro_test_plus;
     *
     * t.expect (std::vector<std::string_view>{ "a", "b" }
     *           == mt::utility::split ("a.b", "."))
     *     << "a.b splits into [a,b]";
     * @endcode
     */
    [[nodiscard]] std::vector<std::string_view>
    split (std::string_view input, std::string_view delimiters)
    {
      std::vector<std::string_view> output{};
      std::size_t first{};
      while (first < input.size ())
        {
          const auto second = input.find_first_of (delimiters, first);
          if (first != second)
            {
              output.emplace_back (input.substr (first, second - first));
            }
          if (second == std::string_view::npos)
            {
              break;
            }
          first = second + 1;
        }
      return output;
    }

  } // namespace utility
  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
