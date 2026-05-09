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
 * for environments lacking C++20 standard support, as well as functions for
 * extracting concise type names using compiler-specific macros such as
 * `__PRETTY_FUNCTION__`. These facilities enable precise identification of
 * code locations and types in test reports, enhancing the clarity and
 * professionalism of diagnostic output.
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

#ifndef MICRO_TEST_PLUS_REFLECTION_H_
#define MICRO_TEST_PLUS_REFLECTION_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <string_view>

#if defined(__cpp_lib_source_location)
#include <source_location>
#endif

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// =============================================================================

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
   * It includes a local implementation of `source_location` for environments
   * lacking C++20 standard support, as well as utilities for extracting
   * concise type names from compiler-specific macros such as
   * `__PRETTY_FUNCTION__`.
   *
   * All definitions within this namespace are intended to facilitate advanced
   * reflection and reporting capabilities.
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
     * reporting within the µTest++ framework. When C++20 standard support is
     * available, this alias refers to `std::source_location`; otherwise, a
     * local implementation is used to ensure consistent functionality across
     * all supported environments. This abstraction enables precise
     * identification of code locations in test reports, supporting clear and
     * professional diagnostics across all files and folders.
     */
    using source_location = std::source_location;
#else
    /**
     * @brief Local implementation of source location information for
     * diagnostics.
     *
     * @details
     * This class provides a lightweight, constexpr-compatible alternative to
     * `std::source_location` for environments lacking C++20 standard support.
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
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
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
#endif
              ) noexcept;

      /**
       * @brief Retrieve the file name associated with this source location.
       *
       * @par Parameters
       *	 None.
       * @return The file name as a constant character pointer.
       */
      [[nodiscard]] constexpr auto
      file_name (void) const noexcept;

      /**
       * @brief Retrieve the line number associated with this source location.
       *
       * @par Parameters
       *	 None.
       * @return The line number as an unsigned integer.
       */
      [[nodiscard]] constexpr auto
      line (void) const noexcept;

    private:
      /**
       * @brief The file name where the source location was captured.
       */
      const char* file_{ "unknown" };

      /**
       * @brief The line number where the source location was captured.
       */
      unsigned int line_{};
    };

#endif

    /**
     * @brief Extract a short type or function name from a fully qualified
     * name.
     *
     * @param name The fully qualified name as a C-string.
     * @return A pointer to the short name within the input string.
     */
    const char*
    short_name (const char* name) noexcept;

    /**
     * @brief Extract the type name from the `__PRETTY_FUNCTION__` macro.
     *
     * @tparam T The type whose name is to be extracted.
     *
     * @par Parameters
     *	 None.
     * @return A `std::string_view` containing the extracted type name.
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
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ============================================================================
// Templates & constexpr implementations.

#include "inlines/reflection-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_REFLECTION_H_

// ----------------------------------------------------------------------------
