/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 */

#ifndef MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_
#define MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#if defined(MICRO_OS_PLUS_DEBUG)
#define MICRO_TEST_PLUS_DEBUG
#endif

#include <type_traits>
#include <stdio.h>
#include <cstring>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

namespace micro_os_plus
{
  namespace micro_test_plus // `micro-test-plus` is shortened to `mtp`.
  {

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#endif

    class session
    {
    public:
      session ();

      /**
       * @brief Create a session with parameters.
       */
      session (int argc, char* argv[]);

      session (const session&) = delete;
      session (session&&) = delete;
      session&
      operator= (const session&)
          = delete;
      session&
      operator= (session&&)
          = delete;

      ~session () = default;

      /**
       * @brief Pass the
       */
      void
      init (int argc, char* argv[]);

      void
      start_suite (const char* name);

      void
      start_test_case (const char* name);

      [[deprecated ("Use `run_test_case(name, func);`")]] void
      run_test_case (void (*func) (session&), const char* name);

      void
      run_test_case (const char* name, void (*func) (session&));


      void
      pass (const char* message, const char* file = nullptr, int line = 0);

      void
      fail (const char* message, const char* file = nullptr, int line = 0);

      void
      expect_true (bool condition, const char* message,
                   const char* file = nullptr, int line = 0);

      template <typename T, typename U>
      void
      expect_equal (T actual, U expected, const char* message,
                    const char* file = nullptr, int line = 0);

      int
      result (void);

      inline int
      passed (void)
      {
        return passed_;
      }

      inline int
      failed (void)
      {
        return failed_;
      }

      inline int
      test_cases (void)
      {
        return test_cases_;
      }

    protected:
      template <typename T>
      void
      print_value_ (T value);

      void
      print_where_ (const char* format, const char* file, int line);

    protected:
      int argc_;
      char** argv_;

      const char* name_;

      int passed_;
      int failed_;
      int test_cases_;
    };

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  } // namespace micro_test_plus
} // namespace micro_os_plus

// ===== Inline & template implementations ====================================

namespace micro_os_plus
{
  namespace micro_test_plus // `micro-test-plus` is shortened to `mtp`.
  {

    template <typename T, typename U>
    void
    session::expect_equal ([[maybe_unused]] T actual,
                           [[maybe_unused]] U expected, const char* message,
                           const char* file, int line)
    {
#if defined(MICRO_TEST_PLUS_DEBUG)
      const char* type_part = std::strchr (__PRETTY_FUNCTION__, '[');
#endif
      if constexpr (!std::is_scalar_v<T>)
        {
#if defined(MICRO_TEST_PLUS_DEBUG)
          printf ("%s() %s\n", __func__, type_part);
#endif
          printf ("    ✗ %s (non scalar <actual>", message);
          print_where_ (" in '%s:%d'", file, line);
          printf (")\n");
          failed_++;
        }
      else if constexpr (!std::is_scalar_v<U>)
        {
#if defined(MICRO_TEST_PLUS_DEBUG)
          printf ("%s() %s\n", __func__, type_part);
#endif
          printf ("    ✗ %s (non scalar <expected>", message);
          print_where_ (" in '%s:%d'", file, line);
          printf (")\n");
          failed_++;
        }
      else
        {
          bool is_equal = false;
          if constexpr (std::is_pointer_v<T> && std::is_null_pointer_v<U>)
            {
#if defined(MICRO_TEST_PLUS_DEBUG)
              printf ("%s() %s compare pointers to null\n", __func__,
                      type_part);
#endif
              is_equal = (actual == nullptr);
            }
          else if constexpr (
              (std::is_same_v<T, char*> || std::is_same_v<T, const char*>)&&(
                  std::is_same_v<U, char*> || std::is_same_v<U, const char*>))
            {
#if defined(MICRO_TEST_PLUS_DEBUG)
              printf ("%s() %s compare strings\n", __func__, type_part);
#endif
              is_equal = (std::strcmp (actual, expected) == 0);
            }
          else if constexpr (std::is_pointer_v<T> && std::is_pointer_v<U>)
            {
#if defined(MICRO_TEST_PLUS_DEBUG)
              printf ("%s() %s compare pointers\n", __func__, type_part);
#endif

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
              is_equal = (reinterpret_cast<void*> (actual)
                          == reinterpret_cast<void*> (expected));
#pragma GCC diagnostic pop
            }
          else if constexpr (std::is_integral_v<T> && std::is_integral_v<U>)
            {
#if defined(MICRO_TEST_PLUS_DEBUG)
              printf ("%s() %s compare integrals\n", __func__, type_part);
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
              is_equal = (actual == expected);
#pragma GCC diagnostic pop
            }
          else if constexpr (std::is_floating_point_v<
                                 T> || std::is_floating_point_v<U>)
            {
#if defined(MICRO_TEST_PLUS_DEBUG)
              printf ("%s() %s\n", __func__, type_part);
#endif
              printf ("    ✗ %s (floating points not comparable", message);
              print_where_ (" in '%s:%d'", file, line);
              printf (")\n");
              failed_++;
            }
          else
            {
#if defined(MICRO_TEST_PLUS_DEBUG)
              printf ("%s() %s\n", __func__, type_part);
#endif
              printf ("    ✗ %s (non comparable types", message);
              print_where_ (" in '%s:%d'", file, line);
              printf (")\n");
              failed_++;
            }

          if (is_equal)
            {
              printf ("    ✓ %s\n", message);
              passed_++;
            }
          else
            {
              printf ("    ✗ %s (expected ", message);
              print_value_<U> (expected);
              printf (", got ");
              print_value_<T> (actual);
              print_where_ (", in '%s:%d'", file, line);
              printf (")\n");
              failed_++;
            }
        }
    }

    template <class T>
    void
    session::print_value_ ([[maybe_unused]] T value)
    {
      if constexpr (std::is_same_v<T, char*> || std::is_same_v<T, const char*>)
        {
          printf ("'%s'", value);
        }
      else if constexpr (std::is_null_pointer_v<T>)
        {
          printf ("nullptr");
        }
      else if constexpr (std::is_pointer_v<T>)
        {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
          printf ("%p", reinterpret_cast<void*> (value));
#pragma GCC diagnostic pop
        }
      else if constexpr (std::is_integral_v<T>)
        {
          printf ("%ld", static_cast<long> (value));
        }
      else
        {
          printf ("(unsupported type)");
        }
    }

  } // namespace micro_test_plus
} // namespace micro_os_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

// Macros are only a convenience to pass the file name and line number,
// otherwise the direct methods can be used as well, but please be aware that
// if the file name is not passed, it will not be displayed.
#define MTP_EXPECT_EQUAL(t, actual, expected, message) \
  t.expect_equal (actual, expected, message, __FILE__, __LINE__)
#define MTP_EXPECT_TRUE(t, condition, message) \
  t.expect_true (condition, message, __FILE__, __LINE__)

#define MTP_PASS(t, message) t.pass (message, __FILE__, __LINE__)
#define MTP_FAIL(t, message) t.fail (message, __FILE__, __LINE__)

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------
