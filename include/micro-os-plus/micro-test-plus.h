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

#if defined(MICRO_OS_PLUS_TRACE)
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_TRACE

#if defined(MICRO_OS_PLUS_DEBUG)
#define MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
#endif

#include <type_traits>
#include <functional>
#include <vector>
#include <stdio.h>
#include <cstring>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
// warning: deleted function definitions are incompatible with C++98
// [-Wc++98-compat]
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#endif

  class test_runner;
  class test_suite;

  extern test_runner runner;
  extern test_suite* current_test_suite;

  class test_runner
  {
  public:
    test_runner ();

    // The rule of five.
    test_runner (const test_runner&) = delete;
    test_runner (test_runner&&) = delete;
    test_runner&
    operator= (const test_runner&)
        = delete;
    test_runner&
    operator= (test_runner&&)
        = delete;

    ~test_runner () = default;

    /**
     * @brief Pass the main arguments explicitly, if the default
     * contructor was used.
     */
    void
    init (const char* name, int argc, char* argv[]);

    int
    result (void);

    void
    register_test_suite (test_suite* suite)
    {
      trace::printf ("%s\n", __PRETTY_FUNCTION__);

      if (suites_ == nullptr)
        {
          suites_ = new std::vector<test_suite*> ();
        }
      suites_->push_back (suite);
    }

  public:
    template <typename T>
    void
    print_value_ (T value);

    void
    print_where_ (const char* format, const char* file, int line);

  protected:
    int argc_ = 0;
    char** argv_ = nullptr;

    const char* default_suite_name_ = "Test";

    test_suite* default_test_suite_;

    // Statically initialised to zero.
    std::vector<test_suite*>* suites_;
  };

  class test_suite
  {
  public:
    test_suite (const char* name)
    {
      trace::printf ("%s\n", __PRETTY_FUNCTION__);

      name_ = name;
      callable_ = [] {};

      // The default test suite needs no registration.
    }

    template <class Callable_T>
    test_suite (const char* name, Callable_T callable)
    {
      trace::printf ("%s\n", __PRETTY_FUNCTION__);

      name_ = name;
      callable_ = callable;

      runner.register_test_suite (this);
    }

    constexpr auto
    operator() ()
    {
      return callable_ ();
    }

    constexpr auto
    operator() () const
    {
      return callable_ ();
    }

    inline void
    run ()
    {
      begin ();
      callable_ ();
      end ();
    }

    void
    begin_test_case (const char* name);

    void
    end_test_case ([[maybe_unused]] const char* name);

    const char*
    name ()
    {
      return name_;
    }

    inline void
    pass (void)
    {
      ++passed_;
    }

    inline void
    fail (void)
    {
      ++failed_;
    }

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

    void
    begin (void);

    void
    end (void);

    int
    result (void);

  private:
    const char* name_;
    std::function<void ()> callable_;

    int passed_ = 0;
    int failed_ = 0;
    int test_cases_ = 0;
  };

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  // --------------------------------------------------------------------------

  void
  init (const char* name, int argc, char* argv[]);

  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& func, Args_T&&... arguments);

  int
  result (void);

  void
  pass (const char* message, const char* file = __builtin_FILE(),
        int line = __builtin_LINE());

  void
  fail (const char* message, const char* file = __builtin_FILE(),
        int line = __builtin_LINE());

  void
  expect_true (bool condition, const char* message,
               const char* file = __builtin_FILE(),
               int line = __builtin_LINE());

  template <typename T, typename U>
  void
  expect_equal (T actual, U expected, const char* message,
                const char* file = __builtin_FILE(),
                int line = __builtin_LINE());

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ===== Inline & template implementations ====================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  template <class T>
  void
  test_runner::print_value_ ([[maybe_unused]] T value)
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
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif
        printf ("%p", reinterpret_cast<void*> (value));
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
      }
    else if constexpr (std::is_integral_v<T>)
      {
        printf ("%ld", static_cast<long> (value));
      }
    else if constexpr (std::is_floating_point_v<T>)
      {
        printf ("%f", static_cast<double> (value));
      }
    else
      {
        printf ("(unsupported type)");
      }
  }

  // --------------------------------------------------------------------------

  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& func, Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    current_test_suite->begin_test_case (name);
    std::invoke (std::forward<Callable_T> (func),
                 std::forward<Args_T> (arguments)...);
    current_test_suite->end_test_case (name);
  }

  template <typename T, typename U>
  void
  expect_equal ([[maybe_unused]] T actual, [[maybe_unused]] U expected,
                const char* message, const char* file, int line)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    const char* type_part = std::strchr (__PRETTY_FUNCTION__, '[');
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
    if constexpr (!std::is_scalar_v<T>)
      {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
        micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
        printf ("    ✗ %s (non scalar <actual>", message);
        runner.print_where_ (" in '%s:%d'", file, line);
        printf (")\n");
        current_test_suite->fail ();
        return;
      }
    else if constexpr (!std::is_scalar_v<U>)
      {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
        micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
        printf ("    ✗ %s (non scalar <expected>", message);
        runner.print_where_ (" in '%s:%d'", file, line);
        printf (")\n");
        current_test_suite->fail ();
        return;
      }
    else
      {
        bool is_equal = false;
        if constexpr (std::is_pointer_v<T> && std::is_null_pointer_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            printf ("%s() %s compare pointers to null\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
            is_equal = (actual == nullptr);
          }
        else if constexpr (
            (std::is_same_v<T, char*> || std::is_same_v<T, const char*>)&&(
                std::is_same_v<U, char*> || std::is_same_v<U, const char*>))
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s compare strings\n",
                                          __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
            is_equal = (std::strcmp (actual, expected) == 0);
          }
        else if constexpr (std::is_pointer_v<T> && std::is_pointer_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            printf ("%s() %s compare pointers\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif
            is_equal = (reinterpret_cast<void*> (actual)
                        == reinterpret_cast<void*> (expected));
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
          }
        else if constexpr (std::is_integral_v<T> && std::is_integral_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s compare integrals\n",
                                          __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif
            is_equal = (actual == expected);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
          }
        else if constexpr (std::is_floating_point_v<
                               T> && std::is_floating_point_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
            printf ("    ✗ %s (floating points not comparable", message);
            runner.print_where_ (" in '%s:%d'", file, line);
            printf (")\n");
            current_test_suite->fail ();
            return;
          }
        else if constexpr (std::is_floating_point_v<
                               T> || std::is_floating_point_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#if defined(__clang__)
#pragma GCC diagnostic ignored "-Wimplicit-int-float-conversion"
#endif
#endif
            is_equal = (actual == expected);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
          }
        else
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
            printf ("    ✗ %s (non comparable types", message);
            runner.print_where_ (" in '%s:%d'", file, line);
            printf (")\n");
            current_test_suite->fail ();
            return;
          }
        // Else fail.

        if (is_equal)
          {
            printf ("    ✓ %s\n", message);
            current_test_suite->pass ();
          }
        else
          {
            printf ("    ✗ %s (expected ", message);
            runner.print_value_<U> (expected);
            printf (", got ");
            runner.print_value_<T> (actual);
            runner.print_where_ (", in '%s:%d'", file, line);
            printf (")\n");
            current_test_suite->fail ();
          }
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------
