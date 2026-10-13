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

using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

namespace
{
  // A user-defined type, to check the comparators with custom types.
  struct point
  {
    int x;
    int y;
  };

  constexpr bool
  operator== (const point& lhs, const point& rhs)
  {
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }

  // Found by argument-dependent lookup when the operands are reported.
  expression_formatter&
  operator<< (expression_formatter& formatter, const point& p)
  {
    return formatter << "{ " << p.x << ", " << p.y << " }";
  }

  // A reporter that ignores all events and exposes its output buffer, to
  // check the text written by the `reporter` stream operators, without
  // writing to the test output (API-REVIEW.md #7).
  class buffer_reporter final : public reporter
  {
  public:
    buffer_reporter () : reporter{ nullptr }
    {
    }

    // The text accumulated by the stream operators.
    const std::string&
    text () const noexcept
    {
      return buffer_;
    }

    void
    clear () noexcept
    {
      clear_buffer_ ();
    }

    void
    begin_session (runner&) override
    {
    }

    void
    end_session (runner&) override
    {
    }

    void
    begin_suite (suite&) override
    {
    }

    void
    end_suite (suite&) override
    {
    }

    void
    begin_subtest (subtest&) override
    {
    }

    void
    end_subtest (subtest&) override
    {
    }

    const char*
    get_comment_prefix (void) override
    {
      return "";
    }

  protected:
    void
    output_pass_prefix_ (std::string&, subtest&) override
    {
    }

    void
    output_pass_suffix_ (subtest&) override
    {
    }

    void
    output_fail_prefix_ (std::string&, const bool,
                         const reflection::source_location&, subtest&) override
    {
    }

    void
    output_fail_suffix_ (const reflection::source_location&, bool,
                         subtest&) override
    {
    }
  };
} // namespace

// ----------------------------------------------------------------------------

static static_suite ts_miscellaneous{ "Miscellaneous suite", tr, [] (auto& ts)
  {
    const detail::runner_totals& current_suite_totals = ts.totals ();

    local_counts = {};

    ts.test ("Arrays", [] (auto& t)
      {
        t.expect (eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
            << "array{ 42 } == array{ 42 }";
        local_counts.successful_checks++;

        t.expect (ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
            << "array{ 42 } != array{ 43 }";
        local_counts.successful_checks++;

        t.expect (eq (std::array{ 1, 2 }, std::array{ 1, 2 }))
            << "array{ 1, 2 } == array{ 1, 2 }";
        local_counts.successful_checks++;

        t.expect (ne (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
            << "array{ 1, 2, 3 } != array{ 1, 2, 4 }";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Arrays bad", [] (auto& t)
      {
        t.expect (ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
            << "array{ 42 } ne array{ 42 }";
        local_counts.failed_checks++;

        t.expect (eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
            << "array{ 42 } eq array{ 43 }";
        local_counts.failed_checks++;

        t.expect (ne (std::array{ 1, 2 }, std::array{ 1, 2 }))
            << "array{ 1, 2 } ne array{ 1, 2 }";
        local_counts.failed_checks++;

        t.expect (eq (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
            << "array{ 1, 2, 3 } eq array{ 1, 2, 4 }";
        local_counts.failed_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Vectors", [] (auto& t)
      {
        t.expect (eq (std::vector<int>{}, std::vector<int>{}))
            << "vector{ } == vector{ }";
        local_counts.successful_checks++;

        t.expect (eq (std::vector<int>{}, std::vector<int>{}));
        local_counts.successful_checks++;

        t.expect (eq (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
            << "vector{ 42 } == vector{ 42 }";
        local_counts.successful_checks++;

        t.expect (ne (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
            << "vector{ 42 } != vector{ 43 }";
        local_counts.successful_checks++;

        t.expect (eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
            << "vector{ 1, 2 } == vector{ 1, 2 }";
        local_counts.successful_checks++;

        t.expect (
            ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
            << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Vectors bad", [] (auto& t)
      {
        t.expect (ne (std::vector<int>{}, std::vector<int>{}))
            << "vector{ } != vector{ }";
        local_counts.failed_checks++;

        t.expect (ne (std::vector<int>{}, std::vector<int>{}));
        local_counts.failed_checks++;

        t.expect (ne (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
            << "vector{ 42 } != vector{ 42 }";
        local_counts.failed_checks++;

        t.expect (eq (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
            << "vector{ 42 } == vector{ 43 }";
        local_counts.failed_checks++;

        t.expect (ne (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
            << "vector{ 1, 2 } != vector{ 1, 2 }";
        local_counts.failed_checks++;

        t.expect (
            eq (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
            << "vector{ 1, 2, 3 } == vector{ 1, 2, 4 }";
        local_counts.failed_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Custom types", [] (auto& t)
      {
        t.expect (eq (point{ 1, 2 }, point{ 1, 2 }))
            << "point{ 1, 2 } == point{ 1, 2 }";
        local_counts.successful_checks++;

        t.expect (ne (point{ 1, 2 }, point{ 1, 3 }))
            << "point{ 1, 2 } != point{ 1, 3 }";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Custom types bad", [] (auto& t)
      {
        t.expect (eq (point{ 1, 2 }, point{ 1, 3 }))
            << "point{ 1, 2 } == point{ 1, 3 }";
        local_counts.failed_checks++;

        // Without a message; the operands are reported in the condition.
        t.expect (eq (point{ 1, 2 }, point{ 1, 3 }));
        local_counts.failed_checks++;

        t.expect (ne (point{ 1, 2 }, point{ 1, 2 }))
            << "point{ 1, 2 } != point{ 1, 2 }";
        local_counts.failed_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // The text written by the `reporter` stream operators, for every
    // supported type (API-REVIEW.md #7).
    ts.test ("Reporter stream operators", [] (auto& t)
      {
        buffer_reporter r;

        // Compares the accumulated text, then clears it.
        auto check = [&] (std::string_view expected, const char* message)
          {
            t.expect (eq (std::string_view{ r.text () }, expected)) << message;
            local_counts.successful_checks++;
            r.clear ();
          };

        r << "text";
        check ("text", "const char*");

        r << std::string_view{ "view" };
        check ("view", "std::string_view");

        r << 'c';
        check ("c", "char");

        r << true << ' ' << false;
        check ("true false", "bool");

        r << nullptr;
        check ("nullptr", "nullptr");

        r << 42 << ' ' << -7 << ' ' << 42u << ' ' << 42L;
        check ("42 -7 42 42", "integers");

        r << 1.25;
        check ("1.25", "double");

        r << static_cast<int*> (nullptr);
        check ("0x0", "null pointer");

        r << "line" << endl;
        check ("line\n", "endl");

        // The `char` pointers and arrays are displayed as strings, as the
        // `const char` pointers are (API-REVIEW.md #13).
        char text[] = "mutable";
        r << text;
        check ("mutable", "char array");

        char* text_pointer = text;
        r << text_pointer;
        check ("mutable", "char*");

        r << static_cast<char*> (nullptr) << ' '
          << static_cast<const char*> (nullptr);
        check ("nullptr nullptr", "null char pointers");

        // A non-null pointer, also to a const object, is displayed as an
        // address, whose format depends on the platform.
        static const int constant = 42;
        r << &constant;
        t.expect (not r.text ().empty () && r.text () != "0x0")
            << "pointer to const";
        local_counts.successful_checks++;
        r.clear ();

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // The text written by the `expression_formatter` stream operators for
    // the character pointers and arrays (API-REVIEW.md #13).
    ts.test ("Formatter character pointers", [] (auto& t)
      {
        detail::colours no_colours{};
        expression_formatter f{ no_colours };

        // Compares the accumulated text, then clears it.
        auto check = [&] (std::string_view expected, const char* message)
          {
            t.expect (eq (std::string_view{ f.str () }, expected)) << message;
            local_counts.successful_checks++;
            f.clear ();
          };

        char text[] = "mutable";
        f << text;
        check ("mutable", "char array");

        char* text_pointer = text;
        f << text_pointer;
        check ("mutable", "char*");

        const char* const_text_pointer = text;
        f << const_text_pointer;
        check ("mutable", "const char*");

        f << static_cast<char*> (nullptr) << ' '
          << static_cast<const char*> (nullptr);
        check ("nullptr nullptr", "null char pointers");

        // The `signed char` and `unsigned char` pointers, usually byte
        // buffers, are displayed as addresses, whose format depends on the
        // platform.
        unsigned char bytes[] = { 'a', 'b', 0 };
        f << bytes;
        t.expect (not f.str ().empty () && f.str () != "ab"
                  && f.str () != "0x0")
            << "unsigned char array";
        local_counts.successful_checks++;
        f.clear ();

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // The comparators accept pointers to const objects, whose addresses are
    // displayed on failure.
    ts.test ("Pointers to const", [] (auto& t)
      {
        static const int first = 1;
        static const int second = 2;

        t.expect (ne (&first, &second)) << "different const objects";
        local_counts.successful_checks++;

        t.expect (eq (&first, &first)) << "same const object";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);
  } };

// ----------------------------------------------------------------------------
