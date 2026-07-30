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

#include <string_view>
#include <vector>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

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
   * These utilities include functions for pattern matching—such as verifying
   * whether a string matches a specified pattern—and for splitting strings
   * into sub-strings based on delimiters. The implementations are efficient
   * and suitable for both embedded and general C++ projects.
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
     * `path`, or `path` itself if no directory separator is found.
     */
    [[nodiscard]] const char*
    extract_file_name (const char* path) noexcept;

    /**
     * @ingroup micro-os-plus-micro-test-plus-utility-functions
     * @brief Check if a string matches a pattern.
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
     * @brief Split a string into a vector of sub-strings.
     *
     * @tparam T Type of the input string.
     * @tparam Delim_T Type of the delimiter.
     *
     * @param input Input string to split.
     * @param delim Delimiter string.
     * @return A vector containing the resulting sub-strings.
     */
    template <class T, class Delim_T>
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>;

    // ------------------------------------------------------------------------
  } // namespace utility

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/utility-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_UTILITY_H_

// ----------------------------------------------------------------------------
