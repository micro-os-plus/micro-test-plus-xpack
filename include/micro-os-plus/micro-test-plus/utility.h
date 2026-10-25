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
 * @brief C++ header file with declarations for the µTest++ utility helpers.
 *
 * @details
 * This header provides declarations for the utility helper functions used
 * within the µTest++ framework. It defines interfaces for string operations
 * including file-name extraction, pattern matching, and string splitting.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_UTILITY_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_UTILITY_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include <cstddef>
#include <string_view>
#include <vector>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::utility
   * @brief Utility functions for the µTest++ testing framework.
   *
   * @details
   * The `micro_os_plus::micro_test_plus::utility` namespace provides a suite
   * of helper functions designed to support advanced string operations and
   * other common tasks within the µTest++ framework.
   *
   * These utilities include functions for extracting the file name from a
   * path, for pattern matching (verifying whether a string matches a
   * pattern with `*` and `?` wildcards), and for splitting strings into
   * sub-strings based on delimiters. The implementations are efficient and
   * suitable for both embedded and general C++ projects.
   *
   * By encapsulating these helper functions within a dedicated namespace, the
   * framework maintains clear code organisation and minimises naming
   * conflicts.
   */
  namespace utility
  {
    /**
     * @ingroup micro-os-plus-micro-test-plus-utility-functions
     * @brief Extracts the file name component from a full path.
     *
     * @param path A null-terminated file path string.
     * @return A pointer to the first character of the file name within
     * `path`, or `path` itself if no path separator (`/` or `\`) is found.
     */
    [[nodiscard]] const char*
    extract_file_name (const char* path) noexcept;

    /**
     * @ingroup micro-os-plus-micro-test-plus-utility-functions
     * @brief Checks whether a string matches a pattern with `*` and `?`
     * wildcards.
     *
     * @param input The string view to be checked.
     * @param pattern The string view containing the pattern to match.
     * @return `true` if the input string matches the pattern; otherwise,
     * `false`.
     */
    [[nodiscard]] bool
    is_match (std::string_view input, std::string_view pattern);

    /**
     * @ingroup micro-os-plus-micro-test-plus-utility-functions
     * @brief Splits a string into a vector of sub-strings.
     *
     * @details
     * This template preserves the type of the argument: for a
     * `std::string_view` it returns views into the input, for a
     * `std::string` it returns copies. It takes part in overload
     * resolution only for the string-like types, i.e. those having
     * `npos`, `find_first_of()`, and `substr()`; for string literals and
     * `const char*` arguments the non-template overload is selected.
     *
     * @tparam T Type of the input string.
     * @tparam Delim_T Type of the delimiter.
     *
     * @param input Input string to split.
     * @param delim Delimiter characters; any of them separates sub-strings.
     * @return A vector containing the resulting sub-strings; empty
     * sub-strings (e.g. between consecutive delimiters) are omitted.
     */
    template <class T, class Delim_T>
      requires requires (T s, Delim_T d) {
        T::npos;
        s.find_first_of (d, std::size_t{});
        s.substr (std::size_t{}, std::size_t{});
      }
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>;

    /**
     * @ingroup micro-os-plus-micro-test-plus-utility-functions
     * @brief Splits a string view into a vector of string views.
     *
     * @details
     * This overload accepts string literals and `const char*` arguments,
     * which the template cannot handle, and also any other type
     * convertible to `std::string_view`. The returned views refer to the
     * characters of the input, which must outlive them.
     *
     * @param input Input string to split.
     * @param delimiters Delimiter characters; any of them separates
     * sub-strings.
     * @return A vector containing the resulting sub-strings; empty
     * sub-strings (e.g. between consecutive delimiters) are omitted.
     */
    [[nodiscard]] std::vector<std::string_view>
    split (std::string_view input, std::string_view delimiters);

    // ------------------------------------------------------------------------
  } // namespace utility

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/utility-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_UTILITY_H_

// ----------------------------------------------------------------------------
