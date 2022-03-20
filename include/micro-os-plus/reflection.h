/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from <https://opensource.org/licenses/MIT/>.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from <https://www.boost.org/LICENSE_1_0.txt>.
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
#pragma clang diagnostic ignored "-Wc++98-c++11-compat"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace reflection
  {
#if defined(__cpp_lib_source_location)
    using source_location = std::source_location;
#else
    /**
     * @brief Local implementation of the std::source_location.
     */
    class source_location
    {
    public:
      [[nodiscard]] static constexpr auto
      current (
#if (__has_builtin(__builtin_FILE) and __has_builtin(__builtin_LINE))
          const char* file = __builtin_FILE(), int line = __builtin_LINE()
#else
          const char* file = "unknown", int line = {}
#endif
              ) noexcept
      {
        source_location sl{};
        sl.file_ = file;
        sl.line_ = line;
        return sl;
      }

      [[nodiscard]] constexpr auto
      file_name () const noexcept
      {
        return file_;
      }

      [[nodiscard]] constexpr auto
      line () const noexcept
      {
        return line_;
      }

    private:
      const char* file_{ "unknown" };
      int line_{};
    };

#endif

    const char*
    short_name (const char* name);

    // TODO: update for the new namespaces.

    /**
     * @brief Parse the __PRETTY_FUNCTION__ macro to extract the type name.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    type_name () -> std::string_view
    {
#if defined(__clang__)
      // printf("|%s|%zu|\n", __PRETTY_FUNCTION__, sizeof (__PRETTY_FUNCTION__));
      // printf("|%s|\n", &__PRETTY_FUNCTION__[78]);
      return { &__PRETTY_FUNCTION__[78], sizeof (__PRETTY_FUNCTION__) - 80 };
#elif defined(__GNUC__)
      // printf("|%s|%zu|\n", __PRETTY_FUNCTION__, sizeof (__PRETTY_FUNCTION__));
      // printf("|%s|\n", &__PRETTY_FUNCTION__[93]);
      return { &__PRETTY_FUNCTION__[93], sizeof (__PRETTY_FUNCTION__) - 144 };
#else
#error "Unsupported compiler"
      return "Unsupported compiler";
#endif
    }
  } // namespace reflection

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_REFLECTION_H_

// ----------------------------------------------------------------------------
