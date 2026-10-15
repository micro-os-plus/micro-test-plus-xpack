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
 * @brief C++ header file with declarations for the µTest++ reflection
 * utilities.
 *
 * @details
 * This header provides the declarations for the reflection utilities used
 * within the µTest++ framework. It defines interfaces for obtaining source
 * location information and extracting type names at compile time, supporting
 * advanced diagnostics and reporting capabilities.
 *
 * The reflection utilities include a local implementation of `source_location`
 * for standard libraries that do not yet provide `std::source_location`, a
 * function to extract the file name from a path, and a function to extract
 * concise type names using the compiler-specific `__PRETTY_FUNCTION__`
 * macro. These facilities enable precise identification of code locations
 * and types in test reports.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::reflection` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_REFLECTION_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_REFLECTION_H_

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

#if defined(__cpp_lib_source_location)
#include <source_location>
#endif // defined(__cpp_lib_source_location)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::reflection
   * @brief Reflection utilities for the µTest++ testing framework.
   *
   * @details
   * The `reflection` namespace provides facilities for obtaining source
   * location information and type names at compile time, thereby supporting
   * advanced reporting and diagnostics within the µTest++ framework.
   *
   * It includes a local implementation of `source_location` for standard
   * libraries that do not yet provide `std::source_location`, as well as
   * utilities for extracting file names from paths and concise type names
   * from the compiler-specific `__PRETTY_FUNCTION__` macro.
   */
  namespace reflection
  {
    // ------------------------------------------------------------------------

#if defined(__cpp_lib_source_location)

    /**
     * @brief Alias for source location information.
     *
     * @details
     * The `source_location` type provides access to source code location
     * details, such as file name and line number, for enhanced diagnostics and
     * reporting within the µTest++ framework. When the standard library
     * provides it (`__cpp_lib_source_location` is defined), this alias refers
     * to `std::source_location`; otherwise, a local implementation with the
     * same interface subset is used.
     */
    using source_location = std::source_location;

#else

    /**
     * @brief Local implementation of source location information for
     * diagnostics.
     *
     * @details
     * This class provides a lightweight, constexpr-compatible alternative to
     * `std::source_location`, used when the standard library does not
     * provide it (`__cpp_lib_source_location` is not defined).
     *
     * It enables retrieval of the file name and line number at the point of
     * invocation, supporting enhanced diagnostics and reporting within the
     * µTest++ framework.
     *
     * The static `current()` method captures the current source location,
     * using compiler built-ins where available, or defaulting to `"unknown"`
     * and zero otherwise.
     *
     * @since 3.0.0
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class source_location
    {
    public:
      /**
       * @brief Obtain the current source location.
       *
       * @param file The file name (automatically provided by the compiler).
       * @param line The line number (automatically provided by the compiler).
       * @return A `source_location` instance with the captured information.
       */
      [[nodiscard]] static constexpr source_location
      current (
#if (__has_builtin(__builtin_FILE) and __has_builtin(__builtin_LINE))
          const char* file = __builtin_FILE (),
          unsigned int line = __builtin_LINE ()
#else
          const char* file = "unknown", unsigned int line = {}
#endif // (__has_builtin(__builtin_FILE) and __has_builtin(__builtin_LINE))
              ) noexcept;

      /**
       * @brief Retrieve the file name associated with this source location.
       *
       * @par Parameters
       *   None.
       * @return The file name as a constant character pointer.
       */
      [[nodiscard]] constexpr auto
      file_name (void) const noexcept;

      /**
       * @brief Retrieve the line number associated with this source location.
       *
       * @par Parameters
       *   None.
       * @return The line number as an unsigned integer.
       */
      [[nodiscard]] constexpr auto
      line (void) const noexcept;

    private:
      /**
       * @brief The file name where the source location was captured.
       *
       * @details
       * Defaults to `"unknown"` when no location was provided.
       */
      const char* file_{ "unknown" };

      /**
       * @brief The line number where the source location was captured.
       *
       * @details
       * Defaults to zero when no location was provided.
       */
      unsigned int line_{};
    };

#endif // defined(__cpp_lib_source_location)

    /**
     * @brief Extract the file name from a path.
     *
     * @details
     * Equivalent to `utility::extract_file_name()`, which the framework
     * uses internally.
     *
     * @param name The path, as a C-string.
     * @return A pointer to the file name within the input string, after
     * the last `/` or `\` separator, or the string itself if there is
     * no separator.
     */
    const char*
    short_name (const char* name) noexcept;

    /**
     * @brief Extract the type name from the `__PRETTY_FUNCTION__` macro.
     *
     * @details
     * The name is spelled as the compiler prints it, and is used to
     * identify the expected exception type in the `throws<E>` failure
     * messages. Only clang and GCC are supported; with other compilers
     * the function returns `"unknown"`.
     *
     * @tparam T The type whose name is to be extracted.
     *
     * @par Parameters
     *   None.
     * @return A `std::string_view` containing the extracted type name, or
     * `"unknown"` if it cannot be determined.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    type_name (void) -> std::string_view;

    // ------------------------------------------------------------------------
  } // namespace reflection

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/reflection-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_REFLECTION_H_

// ----------------------------------------------------------------------------
