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

      void
      init (int argc, char* argv[]);

      void
      start_suite (const char* name);

      void
      run_test_case (void (*f) (session&), const char* name);

      void
      pass (const char* message, const char* file = nullptr, int line = 0);

      void
      fail (const char* message, const char* file = nullptr, int line = 0);

      void
      expect_true (bool condition, const char* message,
                   const char* file = nullptr, int line = 0);

      void
      expect_eq (int actual, int expected, const char* message,
                 const char* file = nullptr, int line = 0);

      void
      expect_eq (long actual, long expected, const char* message,
                 const char* file = nullptr, int line = 0);

      void
      expect_eq (const char* actual, const char* expected, const char* message,
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

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

// Macros are only a convenience to pass the file name and line number,
// otherwise the direct methods can be used as well.
#define MTP_EXPECT_EQ(t, actual, expected, message) \
  t.expect_eq (actual, expected, message, __FILE__, __LINE__)
#define MTP_EXPECT_TRUE(t, condition, message) \
  t.expect_true (condition, message, __FILE__, __LINE__)

#define MTP_PASS(t, message) t.pass (message, __FILE__, __LINE__)
#define MTP_FAIL(t, message) t.fail (message, __FILE__, __LINE__)

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------
