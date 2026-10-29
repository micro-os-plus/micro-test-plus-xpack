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

#include "unit-miscellaneous-test.h"

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>

using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

// Stack usage.
//
// The runner test cases below are much heavier on the stack than the
// applications, because of the way they are written, not because of the
// framework:
//
// - each test case creates several local runners (344 bytes each on
//   Cortex-M33), to check the sessions in isolation;
// - a local runner runs its suites inside the test case, so the call chain
//   of the framework (run_suites(), the suite, the test case, the reporter, and
//   the newlib printf() functions) is on the stack twice;
// - in the debug builds (-O0), the temporaries of all the checks of a test
//   case get separate slots in its frame, since the compiler does not
//   reuse them.
//
// An application with a single runner in main() needs about 2.5-3 KB on
// Cortex-M33 in the debug build; the largest part is newlib's printf().
// This file peaks at about 6 KB, in "Optional top suite", while one of its
// local runners reports a test case.
//
// The QEMU platforms have only 8 KB of stack, and an overflow ends in a
// lockup, without a diagnostic. Earlier, larger, versions of the runner
// test cases (frames of about 5 KB) did overflow it. Therefore keep the
// test cases with local runners small: split them when they grow, and
// move the common setup to functions, as the filter helpers below.

namespace
{
  // A user-defined type, to check the comparators with custom types.
  struct point
  {
    int x;
    int y;
  };

  // Found by argument-dependent lookup when the operands are reported.
  expression_formatter&
  operator<< (expression_formatter& formatter, const point& p)
  {
    return formatter << "{ " << p.x << ", " << p.y << " }";
  }

  // A callable that counts its copies, to check that test_each() does not
  // copy it.
  struct copy_counter
  {
    copy_counter () = default;
    copy_counter (const copy_counter&)
    {
      ++total_copies;
    }

    void
    operator() (test_case& t, int) const
    {
      t.expect (eq (total_copies, 0)) << "callable not copied";
    }

    static inline int total_copies = 0;
  };

  // A range with begin() and end() functions, not members, found by
  // argument-dependent lookup, as by a range-based for statement.
  struct number_pair
  {
    int numbers[2];
  };

  const int*
  begin (const number_pair& p)
  {
    return std::begin (p.numbers);
  }

  const int*
  end (const number_pair& p)
  {
    return std::end (p.numbers);
  }

  // Scoped enumerations, formatted by their underlying value.
  enum class colour
  {
    red,
    green
  };

  enum class level : std::uint8_t
  {
    low = 1,
    high = 2
  };

  // A scoped enumeration with its own formatter, which is preferred to
  // the one of the framework.
  enum class state
  {
    off,
    on
  };

  expression_formatter&
  operator<< (expression_formatter& formatter, state s)
  {
    return formatter << (s == state::on ? "on" : "off");
  }

  // A type that counts how many times it is formatted, to check that the
  // passed checks whose lines are not written are not formatted.
  int format_calls = 0;

  struct format_counter
  {
    int number;
  };

  constexpr bool
  operator== (const format_counter& lhs, const format_counter& rhs)
  {
    return lhs.number == rhs.number;
  }

  expression_formatter&
  operator<< (expression_formatter& formatter, const format_counter& c)
  {
    ++format_calls;
    return formatter << c.number;
  }

  // A type that counts its live instances, to check that a test case
  // and its body are destroyed when `test()` returns.
  int live_instances = 0;

  struct instance_counter
  {
    instance_counter ()
    {
      ++live_instances;
    }

    instance_counter (const instance_counter&)
    {
      ++live_instances;
    }

    instance_counter&
    operator= (const instance_counter&)
        = default;

    ~instance_counter ()
    {
      --live_instances;
    }
  };

  // An abort handler which, when exceptions are available, returns
  // control to the test case, without terminating the process.
#if defined(__cpp_exceptions)
  struct abort_exception
  {
  };

  [[noreturn]] void
  test_abort_handler (const reflection::source_location&)
  {
    throw abort_exception{};
  }
#else
  void
  test_abort_handler (const reflection::source_location&)
  {
  }
#endif // defined(__cpp_exceptions)

  // A reporter that ignores all events and exposes its output buffer, to
  // check the text written by the `reporter` stream operators, without
  // writing to the test output.
  class buffer_reporter final : public detail::reporter
  {
  public:
    buffer_reporter () : reporter{ runner_options{} }
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
      clear_buffer ();
    }

    void
    begin_session (const runner&) override
    {
    }

    void
    end_session (const runner&) override
    {
    }

    void
    begin_suite (const suite&) override
    {
    }

    void
    end_suite (const suite&) override
    {
    }

    void
    skip_suite (const suite&) override
    {
    }

    void
    fail_suite (const std::string&, const suite&) override
    {
    }

    void
    begin_test_case (const test_case&) override
    {
    }

    void
    end_test_case (const test_case&) override
    {
    }

    void
    skip_test_case (const test_case&) override
    {
    }

    void
    abort_session (const reflection::source_location&, bool) override
    {
    }

    const char*
    comment_prefix (void) const noexcept override
    {
      return "";
    }

  protected:
    void
    commit_buffer (void) override
    {
    }

    void
    output_pass_prefix (const std::string&, const test_case&) override
    {
    }

    void
    output_pass_suffix (const test_case&) override
    {
    }

    void
    output_fail_prefix (const std::string&, const bool,
                        const reflection::source_location&,
                        const test_case&) override
    {
    }

    void
    output_fail_suffix (const reflection::source_location&, detail::check_kind,
                        const test_case&) override
    {
    }
  };

  // Adds a test case on behalf of its caller; the location of the test
  // case is that of the call to the helper.
  void
  add_named_test_case (suite& s, const test_case_name& name, int* runs)
  {
    s.test (name, [runs] (auto& lt)
      {
        ++*runs;
        lt.expect (true);
      });
  }

  // Returns the line captured when the argument was converted.
  auto
  converted_line (const test_case_name& name)
  {
    return name.location ().line ();
  }

  // The number of runs of each suite and test case body, in the filter
  // tests. The filter helpers are functions, not lambdas in the test cases,
  // so that their temporaries are not added to the frames of the test
  // cases (see the note on the stack usage above).
  struct filter_runs
  {
    int alpha_one = 0;
    int alpha_two = 0;
    int beta = 0;
    int first = 0;
    int second = 0;
    int inner = 0;
    int other = 0;
  };

  // Adds two test cases; the second one has two nested test cases.
  void
  add_filter_test_cases (suite& s, filter_runs* runs)
  {
    s.test ("first", [runs] (test_case&) noexcept { ++runs->first; });
    s.test ("second", [runs] (test_case& st)
      {
        ++runs->second;
        st.test ("inner", [runs] (test_case&) noexcept { ++runs->inner; });
        st.test ("other", [runs] (test_case&) noexcept { ++runs->other; });
      });
  }

  // Adds three suites, each with the test cases above.
  void
  add_filter_suites (runner& r, filter_runs* runs)
  {
    r.add_suite ("Alpha one", [runs] (suite& s)
      {
        ++runs->alpha_one;
        add_filter_test_cases (s, runs);
      });
    r.add_suite ("Beta", [runs] (suite& s)
      {
        ++runs->beta;
        add_filter_test_cases (s, runs);
      });
    r.add_suite ("Alpha two", [runs] (suite& s)
      {
        ++runs->alpha_two;
        add_filter_test_cases (s, runs);
      });
  }
} // namespace

// ----------------------------------------------------------------------------

static static_suite ts_miscellaneous{ "Miscellaneous suite", tr, [] (auto& ts)
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

    // The text written by the `reporter` stream operators, for every
    // supported type.
    ts.test ("Reporter stream operators", [] (auto& t)
      {
        buffer_reporter r;

        // Compares the accumulated text, then clears it.
        auto check = [&] (std::string_view expected, const char* message)
          {
            t.expect (eq (std::string_view{ r.text () }, expected)) << message;
            local_counts.passed_checks++;
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

        r << "line" << detail::endl;
        check ("line\n", "endl");

        // The `char` pointers and arrays are displayed as strings, as the
        // `const char` pointers are.
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
        local_counts.passed_checks++;
        r.clear ();

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The text written by the `expression_formatter` stream operators for
    // the character pointers and arrays.
    ts.test ("Formatter character pointers", [] (auto& t)
      {
        detail::colours no_colours{};
        expression_formatter f{ no_colours };

        // Compares the text written since the previous check (the
        // formatter only appends).
        std::size_t start = 0;
        auto check = [&] (std::string_view expected, const char* message)
          {
            std::string_view written{ f.str () };
            t.expect (eq (written.substr (start), expected)) << message;
            local_counts.passed_checks++;
            start = written.size ();
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

        f << static_cast<char*> (nullptr) << " "
          << static_cast<const char*> (nullptr);
        check ("nullptr nullptr", "null char pointers");

        // The `signed char` and `unsigned char` pointers, usually byte
        // buffers, are displayed as addresses, whose format depends on the
        // platform.
        unsigned char bytes[] = { 'a', 'b', 0 };
        f << bytes;
        std::string_view written = std::string_view{ f.str () }.substr (start);
        t.expect (not written.empty () && written != "ab" && written != "0x0")
            << "unsigned char array";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The type suffixes written by the `expression_formatter` for the
    // numbers, and the decimal point of the floating-point values.
    ts.test ("Formatter number suffixes", [] (auto& t)
      {
        detail::colours no_colours{};
        expression_formatter f{ no_colours };

        // Compares the text written since the previous check (the
        // formatter only appends).
        std::size_t start = 0;
        auto check = [&] (std::string_view expected, const char* message)
          {
            std::string_view written{ f.str () };
            t.expect (eq (written.substr (start), expected)) << message;
            local_counts.passed_checks++;
            start = written.size ();
          };

        f << static_cast<signed char> (5);
        check ("5sc", "signed char");

        f << static_cast<unsigned char> (5);
        check ("5uc", "unsigned char");

        f << 42;
        check ("42", "int");

        f << 42L;
        check ("42l", "long");

        f << 42.0f;
        check ("42.0f", "integral float");

        f << 42.0;
        check ("42.0", "integral double");

        f << 42.0L;
        check ("42.0ld", "integral long double");

        f << 1.5f;
        check ("1.5f", "float");

        f << 1.5;
        check ("1.5", "double");

        f << 1.5L;
        check ("1.5ld", "long double");

        // The `long double` values are written in the shortest exact form,
        // as the other floating-point values, not with six digits. With at
        // most 15 digits, the text is the same where `long double` is as
        // wide as `double`.
        f << 0.1000001L;
        check ("0.1000001ld", "long double with seven digits");

        f << 3.14159265358979L;
        check ("3.14159265358979ld", "long double with 15 digits");

        f << -2.0;
        check ("-2.0", "negative integral double");

        f << 1e20;
        check ("1e+20", "double with exponent");

        f << std::numeric_limits<double>::infinity ();
        check ("inf", "infinite double");

        // The type suffix is not appended to the infinities and NaNs.
        f << std::numeric_limits<float>::infinity ();
        check ("inf", "infinite float");

        f << -std::numeric_limits<float>::infinity ();
        check ("-inf", "negative infinite float");

        f << std::numeric_limits<float>::quiet_NaN ();
        check ("nan", "float NaN");

        f << std::numeric_limits<double>::quiet_NaN ();
        check ("nan", "double NaN");

        f << std::numeric_limits<long double>::infinity ();
        check ("inf", "infinite long double");

        f << std::numeric_limits<long double>::quiet_NaN ();
        check ("nan", "long double NaN");

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The characters are written by the `expression_formatter` as quoted
    // literals, with the non-printable ones escaped, so that a zero does
    // not end the output.
    ts.test ("Formatter characters", [] (auto& t)
      {
        detail::colours no_colours{};
        expression_formatter f{ no_colours };

        // Compares the text written since the previous check (the
        // formatter only appends).
        std::size_t start = 0;
        auto check = [&] (std::string_view expected, const char* message)
          {
            std::string_view written{ f.str () };
            t.expect (eq (written.substr (start), expected)) << message;
            local_counts.passed_checks++;
            start = written.size ();
          };

        f << 'a';
        check ("'a'", "letter");

        f << ' ';
        check ("' '", "space");

        f << '"';
        check ("'\"'", "double quote");

        f << '\0';
        check ("'\\0'", "zero");

        f << '\a' << '\b' << '\t' << '\n' << '\v' << '\f' << '\r';
        check ("'\\a''\\b''\\t''\\n''\\v''\\f''\\r'", "control escapes");

        f << '\'' << '\\';
        check ("'\\'''\\\\'", "quote and backslash");

        f << '\x1b' << '\x7f';
        check ("'\\x1b''\\x7f'", "other control characters");

        f << static_cast<char> (0xC3);
        check ("'\\xc3'", "non-ASCII byte");

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The wide characters are written as quoted literals with their
    // prefix, not as numbers; the values outside ASCII are written as
    // universal character names, and the values that are not characters
    // by themselves with `\x` and all the digits of their type.
    ts.test ("Formatter wide characters", [] (auto& t)
      {
        detail::colours no_colours{};
        expression_formatter f{ no_colours };

        // Compares the text written since the previous check (the
        // formatter only appends).
        std::size_t start = 0;
        auto check = [&] (std::string_view expected, const char* message)
          {
            std::string_view written{ f.str () };
            t.expect (eq (written.substr (start), expected)) << message;
            local_counts.passed_checks++;
            start = written.size ();
          };

#if defined(__cpp_char8_t)
        f << u8'a' << u8'\n' << u8'\x1b';
        check ("u8'a'u8'\\n'u8'\\x1b'", "char8_t ASCII");

        f << static_cast<char8_t> (0xC3);
        check ("u8'\\xc3'", "char8_t code unit");
#endif // defined(__cpp_char8_t)

        f << u'x' << u'\0' << u'\'' << u'\x7f';
        check ("u'x'u'\\0'u'\\''u'\\x7f'", "char16_t ASCII");

        f << u'\u00e9' << static_cast<char16_t> (0xFFFF);
        check ("u'\\u00e9'u'\\uffff'", "char16_t non-ASCII");

        f << static_cast<char16_t> (0xD83D);
        check ("u'\\xd83d'", "char16_t surrogate");

        f << U'x' << U'\t';
        check ("U'x'U'\\t'", "char32_t ASCII");

        f << static_cast<char32_t> (0x80) << U'\U0001f600';
        check ("U'\\u0080'U'\\U0001f600'", "char32_t non-ASCII");

        f << static_cast<char32_t> (0xDC00)
          << static_cast<char32_t> (0x110000);
        check ("U'\\x0000dc00'U'\\x00110000'", "char32_t not characters");

        f << L'x' << L'\u00e9';
        check ("L'x'L'\\u00e9'", "wchar_t");

        if constexpr (sizeof (wchar_t) == 4)
          {
            f << static_cast<wchar_t> (-1);
            check ("L'\\xffffffff'", "wchar_t negative");
          }
        else if constexpr (sizeof (wchar_t) == 2)
          {
            f << static_cast<wchar_t> (-1);
            check ("L'\\uffff'", "wchar_t negative");
          }

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The scoped enumerations and `std::byte` are written by the
    // `expression_formatter` by their underlying value, the pairs and the
    // tuples as `(a, b)`, and the optionals by their value, or as
    // `nullopt`.
    ts.test ("Formatter standard types", [] (auto& t)
      {
        detail::colours no_colours{};
        expression_formatter f{ no_colours };

        // Compares the text written since the previous check (the
        // formatter only appends).
        std::size_t start = 0;
        auto check = [&] (std::string_view expected, const char* message)
          {
            std::string_view written{ f.str () };
            t.expect (eq (written.substr (start), expected)) << message;
            local_counts.passed_checks++;
            start = written.size ();
          };

        f << colour::green;
        check ("1", "scoped enumeration");

        f << level::high;
        check ("2uc", "scoped enumeration with underlying type");

        f << state::on;
        check ("on", "scoped enumeration with formatter");

        f << std::byte{ 0x2a };
        check ("42uc", "std::byte");

        f << std::pair{ 1, 'a' };
        check ("(1, 'a')", "pair");

        f << std::tuple{ 1, 2u, "three" };
        check ("(1, 2u, three)", "tuple");

        f << std::tuple<>{};
        check ("()", "empty tuple");

        f << std::vector<std::pair<int, int>>{ { 1, 2 }, { 3, 4 } };
        check ("{(1, 2), (3, 4)}", "container of pairs");

        f << std::vector<std::vector<int>>{ { 1 }, { 2, 3 } };
        check ("{{1}, {2, 3}}", "container of containers");

        f << number_pair{ { 7, 8 } };
        check ("{7, 8}", "range with begin() and end() functions");

        f << std::optional<int>{ 42 };
        check ("42", "optional with value");

        f << std::optional<int>{};
        check ("nullopt", "optional without value");

        f << std::nullopt;
        check ("nullopt", "nullopt");

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The messages accept the values of the expressions, written by the
    // formatter without the type suffixes, and with the characters
    // unquoted.
    ts.test ("Message types", [] (auto& t)
      {
        t.expect (true) << "numbers " << 1 << ' ' << 2u << ' ' << 3l << ' '
                        << 1.5f << ' ' << 2.0 << ' ' << true;
        local_counts.passed_checks++;

        static const int constant = 42;
        t.expect (true) << "pointer " << &constant;
        local_counts.passed_checks++;

        t.expect (true) << "container " << std::vector<int>{ 1, 2 };
        local_counts.passed_checks++;

        t.expect (true) << "standard types " << std::pair{ 1, 'a' } << ' '
                        << std::optional<int>{} << ' ' << colour::green;
        local_counts.passed_checks++;

        t.expect (true) << "custom type " << point{ 1, 2 } << ' ' << state::on;
        local_counts.passed_checks++;

        t.expect (true) << "wide characters " << u'x' << ' ' << U'x' << ' '
                        << L'x';
        local_counts.passed_checks++;

        t.expect (false) << "failed " << std::vector<int>{ 3 };
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    // A callable object appended to a check is called only if the check
    // fails, and its result is appended to the message.
    ts.test ("Lazy messages", [] (auto& t)
      {
        int calls = 0;

        t.expect (true) << "passed" << [&calls] () noexcept
          {
            ++calls;
            return " and not appended";
          };
        local_counts.passed_checks++;

        // Not called after a success, when it would not be valid.
        std::optional<int> empty{};
        t.expect (not empty.has_value ())
            << [&empty] { return empty.value (); };
        local_counts.passed_checks++;

        t.expect (eq (calls, 0)) << "not called after a success";
        local_counts.passed_checks++;

        t.expect (false) << "failed" << [&calls] () noexcept
          {
            ++calls;
            return " and appended";
          };
        local_counts.failed_checks++;

        t.expect (eq (calls, 1)) << "called after a failure";
        local_counts.passed_checks++;

        // Without captures, it converts to `bool`, but it is called.
        t.expect (false) << [] () noexcept { return 42; };
        local_counts.failed_checks++;

        std::function<std::string (void)> message
            = [] { return std::string{ "from a function" }; };
        t.expect (false) << message;
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    // In the TAP output, the `\` and `#` characters of the names, the
    // messages, and the expressions are escaped, and the line breaks are
    // replaced by spaces, so that the failed test case below is not read as
    // a TODO.
    ts.test ("TAP escapes # TODO in names \\ messages", [] (auto& t)
      {
        t.expect (true) << "message with # hash and \\ backslash";
        local_counts.passed_checks++;

        t.expect (
            eq (std::string_view{ "a # b" }, std::string_view{ "a # b" }));
        local_counts.passed_checks++;

        t.expect (true) << "first line\nsecond line";
        local_counts.passed_checks++;

        t.expect (false) << "failed # TODO not a directive\nnext line";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    // The `condition:` values are YAML double-quoted scalars, so the
    // operands that contain `: `, ` #`, `"`, or `\` keep the YAML
    // diagnostics block valid, and are not truncated.
    ts.test ("TAP condition values are quoted", [] (auto& t)
      {
        t.expect (eq (std::string_view{ "key: \"value\" # not a comment" },
                      std::string_view{ "a\\b" }));
        local_counts.failed_checks++;

        t.expect (eq (std::string_view{ "line\nbreak\ttab" },
                      std::string_view{ "x" }));
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // A runner can be initialised without a command line, with the options
    // set by the application. The local runners are silent, so that they
    // do not write to the test output.
    ts.test ("Runner options", [] (auto& t)
      {
        runner_options options{};
        options.selected_reporter = reporter_kind::human;
        options.verbosity_level = verbosity::silent;

        runner named_runner;

        // The verbosity is kept by the runner, not by the reporter, which
        // does not exist yet.
        t.expect (named_runner.verbosity_level () == verbosity::normal)
            << "default verbosity before initialise()";
        local_counts.passed_checks++;

        named_runner.initialise (options);
        auto& named_ts = named_runner.add_top_suite ("Local");

        t.expect (eq (named_ts.name (), "Local")) << "given name";
        local_counts.passed_checks++;

        t.expect (named_runner.verbosity_level () == verbosity::silent)
            << "given verbosity";
        local_counts.passed_checks++;

        bool added_suite_ran = false;
        named_runner.add_suite ("Added", [&added_suite_ran] (suite& s)
          {
            added_suite_ran = true;
            s.test ("Added test", [] (auto& lt) { lt.expect (true); });
          });

        named_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (named_runner.run_suites (), 0))
            << "local session passed";
        local_counts.passed_checks++;

        t.expect (added_suite_ran) << "added suite ran";
        local_counts.passed_checks++;

        // The total also counts the top suite.
        t.expect (eq (named_runner.added_suites_count (), 1u)
                  and eq (named_runner.total_suites_count (),
                          1 + named_runner.added_suites_count ()
                              + named_runner.static_suites_count ()))
            << "total_suites_count() counts the top suite";
        local_counts.passed_checks++;

        runner unnamed_runner;
        unnamed_runner.initialise (options);
        auto& unnamed_ts = unnamed_runner.add_top_suite ();

        t.expect (eq (unnamed_ts.name (), "default suite"))
            << "default name without arguments";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // Both `initialise()` and `add_top_suite()` are optional; a session
    // without any suite is an error (the messages are expected in the test
    // output).
    ts.test ("Optional top suite", [] (auto& t)
      {
        runner_options options{};
        options.verbosity_level = verbosity::silent;

        bool added_suite_ran = false;
        runner suites_runner;
        suites_runner.initialise (options);
        suites_runner.add_suite ("Added", [&added_suite_ran] (suite& s)
          {
            added_suite_ran = true;
            s.test ("Added test", [] (auto& lt) { lt.expect (true); });
          });

        t.expect (eq (suites_runner.run_suites (), 0) and added_suite_ran
                  and eq (suites_runner.total_suites_count (), 1u)
                  and eq (suites_runner.totals ().executed_test_cases (), 1u))
            << "without a top suite, only the added suites run";
        local_counts.passed_checks++;

        runner empty_runner;
        empty_runner.initialise (options);

        t.expect (eq (empty_runner.run_suites (), 1)
                  and eq (empty_runner.total_suites_count (), 0u))
            << "a session without suites fails";
        local_counts.passed_checks++;

        runner top_runner;
        top_runner.initialise (options);
        top_runner.add_top_suite ("Top");

        t.expect (eq (top_runner.run_suites (), 0)
                  and eq (top_runner.total_suites_count (), 1u))
            << "a top suite without test cases passes";
        local_counts.passed_checks++;

        runner twice_runner;
        twice_runner.initialise (options);
        auto& first_ts = twice_runner.add_top_suite ("First");

        t.expect (&twice_runner.add_top_suite ("Second") == &first_ts
                  and eq (first_ts.name (), "First"))
            << "a second add_top_suite() returns the same suite";
        local_counts.passed_checks++;

        runner late_runner;
        late_runner.initialise (options);
        late_runner.add_suite ("Added", [] (suite& s)
          { s.test ("Added test", [] (auto& lt) { lt.expect (true); }); });

        t.expect (eq (late_runner.run_suites (), 0)) << "the session passes";
        local_counts.passed_checks++;

        late_runner.add_top_suite ("Late");

        t.expect (eq (late_runner.run_suites (), 1))
            << "a top suite added after run_suites() is rejected";
        local_counts.passed_checks++;

        // Without `initialise()`, the default options are used; the
        // session header is written to the console.
        runner default_runner;
        auto& default_ts = default_runner.add_top_suite ();

        t.expect (eq (default_ts.name (), "default suite")
                  and default_runner.verbosity_level () == verbosity::normal)
            << "without initialise(), the default options are used";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // An option error does not terminate the process; it is reported on
    // stderr (the messages are expected in the test output), the tests are
    // still run, and `run_suites()` returns 2; an unknown reporter stops the
    // session, without running any test.
    ts.test ("Runner option errors", [] (auto& t)
      {
        char arg_name[] = "local";
        char arg_silent[] = "--silent";
        char arg_bad_reporter[] = "--reporter=unknown";
        char arg_reporter[] = "--reporter";

        char* bad_reporter_argv[]
            = { arg_name, arg_silent, arg_bad_reporter, nullptr };
        runner bad_reporter_runner;
        bad_reporter_runner.initialise (3, bad_reporter_argv);
        auto& bad_reporter_ts = bad_reporter_runner.add_top_suite ();
        bad_reporter_ts.test ("Local test",
                              [] (auto& lt) { lt.expect (true); });

        t.expect (bad_reporter_runner.verbosity_level () == verbosity::silent)
            << "valid options still applied";
        local_counts.passed_checks++;

        t.expect (eq (bad_reporter_runner.run_suites (), 2))
            << "unknown reporter";
        local_counts.passed_checks++;

        char arg_unknown[] = "--verbos";
        char* unknown_argv[] = { arg_name, arg_silent, arg_unknown, nullptr };
        runner unknown_runner;
        unknown_runner.initialise (3, unknown_argv);
        auto& unknown_ts = unknown_runner.add_top_suite ();
        unknown_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (unknown_runner.run_suites (), 2)) << "unknown option";
        local_counts.passed_checks++;

        char* missing_argv[] = { arg_name, arg_silent, arg_reporter, nullptr };
        runner missing_runner;
        missing_runner.initialise (3, missing_argv);
        auto& missing_ts = missing_runner.add_top_suite ();
        missing_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (missing_runner.run_suites (), 2)) << "missing argument";
        local_counts.passed_checks++;

        runner_options options{};
        options.verbosity_level = verbosity::silent;
        options.output_file_path = "/non-existent-folder/report.txt";

        runner file_runner;
        file_runner.initialise (options);
        auto& file_ts = file_runner.add_top_suite ();
        file_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (file_runner.run_suites (), 2))
            << "output file not opened";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The colour modes of `--color` and `--use-colour`; an unknown mode is
    // an option error.
    ts.test ("Runner colour options", [] (auto& t)
      {
        char arg_name[] = "local";
        char arg_silent[] = "--silent";
        char arg_color[] = "--color";
        char arg_color_always[] = "--color=always";
        char arg_color_never[] = "--color=never";
        char arg_color_auto[] = "--color=auto";
        char arg_colour_yes[] = "--use-colour=yes";
        char arg_colour[] = "--use-colour";
        char arg_colour_no[] = "no";
        char arg_colour_auto[] = "--use-colour=auto";
        // The GNU synonyms, accepted by both options.
        char arg_color_force[] = "--color=force";
        char arg_color_none[] = "--color=none";
        char arg_color_if_tty[] = "--color=if-tty";
        char arg_colour_tty[] = "--use-colour=tty";

        char* colour_argv[]
            = { arg_name,        arg_silent,     arg_color_always,
                arg_color_never, arg_color_auto, arg_colour_yes,
                arg_colour,      arg_colour_no,  arg_colour_auto,
                arg_color_force, arg_color_none, arg_color_if_tty,
                arg_colour_tty,  nullptr };
        runner colour_runner;
        colour_runner.initialise (13, colour_argv);
        auto& colour_ts = colour_runner.add_top_suite ();
        colour_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (colour_runner.run_suites (), 0)) << "valid colour modes";
        local_counts.passed_checks++;

        // As in the GNU tools, `--color` alone does not take the next
        // argument as its value.
        char* color_argv[] = { arg_name, arg_color, arg_silent, nullptr };
        runner color_runner;
        color_runner.initialise (3, color_argv);
        auto& color_ts = color_runner.add_top_suite ();
        color_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (color_runner.verbosity_level () == verbosity::silent
                  and eq (color_runner.run_suites (), 0))
            << "--color alone keeps the next argument";
        local_counts.passed_checks++;

        char arg_bad_color[] = "--color=maybe";
        char arg_bad_colour[] = "--use-colour=maybe";

        char* bad_colour_argv[]
            = { arg_name, arg_silent, arg_bad_colour, nullptr };
        runner bad_colour_runner;
        bad_colour_runner.initialise (3, bad_colour_argv);
        auto& bad_colour_ts = bad_colour_runner.add_top_suite ();
        bad_colour_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        char* bad_color_argv[]
            = { arg_name, arg_silent, arg_bad_color, nullptr };
        runner bad_color_runner;
        bad_color_runner.initialise (3, bad_color_argv);
        auto& bad_color_ts = bad_color_runner.add_top_suite ();
        bad_color_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (bad_colour_runner.run_suites (), 2)
                  and eq (bad_color_runner.run_suites (), 2))
            << "unknown colour mode";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The --filter option selects the suites and the test cases to run by
    // name, with one pattern per nesting level, as --grep in node-tap;
    // within a pattern, `|` separates alternatives.
    // The local runners are silent.
    ts.test ("Runner filter of the suites", [] (auto& t)
      {
        filter_runs runs{};

        // A single pattern, set by the application, selects the suites;
        // all their test cases run.
        runner_options options{};
        options.verbosity_level = verbosity::silent;
        options.filter_patterns = { "Alpha*" };

        runner suites_runner;
        suites_runner.initialise (options);
        suites_runner.add_top_suite ();
        add_filter_suites (suites_runner, &runs);

        t.expect (eq (suites_runner.run_suites (), 0))
            << "suite filter passed";
        local_counts.passed_checks++;

        t.expect (eq (runs.alpha_one, 1) and eq (runs.alpha_two, 1)
                  and eq (runs.beta, 0))
            << "matching suites run";
        local_counts.passed_checks++;

        t.expect (eq (runs.first, 2) and eq (runs.second, 2)
                  and eq (runs.inner, 2) and eq (runs.other, 2))
            << "all their test cases run";
        local_counts.passed_checks++;

        t.expect (eq (suites_runner.skipped_suites_count (), 1u)
                  and eq (suites_runner.totals ().skipped_test_cases (), 0u))
            << "one suite skipped";
        local_counts.passed_checks++;

        // Patterns parsed from the command line, in both forms, one per
        // level: the suites, the test cases, and the nested test cases.
        char arg_name[] = "local";
        char arg_silent[] = "--silent";
        char arg_filter_suites[] = "--filter=Beta|Alpha t?o";
        char arg_filter[] = "--filter";
        char arg_second[] = "second";
        char arg_filter_inner[] = "--filter=inner";

        char* levels_argv[] = { arg_name,   arg_silent, arg_filter_suites,
                                arg_filter, arg_second, arg_filter_inner,
                                nullptr };

        runs = filter_runs{};
        runner levels_runner;
        levels_runner.initialise (6, levels_argv);
        levels_runner.add_top_suite ();
        add_filter_suites (levels_runner, &runs);

        t.expect (eq (levels_runner.run_suites (), 0))
            << "level filters passed";
        local_counts.passed_checks++;

        t.expect (eq (runs.alpha_one, 0) and eq (runs.alpha_two, 1)
                  and eq (runs.beta, 1))
            << "suites matching an alternative run";
        local_counts.passed_checks++;

        t.expect (eq (runs.first, 0) and eq (runs.second, 2))
            << "test cases matching the second pattern run";
        local_counts.passed_checks++;

        t.expect (eq (runs.inner, 2) and eq (runs.other, 0))
            << "nested test cases matching the third pattern run";
        local_counts.passed_checks++;

        t.expect (eq (levels_runner.skipped_suites_count (), 1u)
                  and eq (levels_runner.totals ().skipped_test_cases (), 4u))
            << "skipped suites and test cases counted";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The top suite is never skipped, but its test cases are filtered
    // too, including by its name; a pattern must match the whole name.
    ts.test ("Runner filter of the top suite", [] (auto& t)
      {
        filter_runs runs{};

        runner_options top_options{};
        top_options.verbosity_level = verbosity::silent;
        top_options.filter_patterns = { "Local", "first" };

        runner top_runner;
        top_runner.initialise (top_options);
        add_filter_test_cases (top_runner.add_top_suite ("Local"), &runs);

        t.expect (eq (top_runner.run_suites (), 0)
                  and eq (top_runner.totals ().skipped_test_cases (), 1u))
            << "top suite filtered";
        local_counts.passed_checks++;

        t.expect (eq (runs.first, 1) and eq (runs.second, 0))
            << "top suite test case matching the second pattern runs";
        local_counts.passed_checks++;

        top_options.filter_patterns = { "Loc" };

        runs = filter_runs{};
        runner partial_runner;
        partial_runner.initialise (top_options);
        add_filter_test_cases (partial_runner.add_top_suite ("Local"), &runs);

        // A filter that selects no test case is an error.
        t.expect (eq (partial_runner.run_suites (), 2)
                  and eq (partial_runner.totals ().skipped_test_cases (), 2u)
                  and eq (runs.first, 0) and eq (runs.second, 0))
            << "partial name does not match";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The filter patterns are owned by the options.
    ts.test ("Runner filter patterns", [] (auto& t)
      {
        filter_runs runs{};
        char arg_name[] = "local";
        char arg_silent[] = "--silent";
        char arg_filter[] = "--filter";

        // The patterns are copied by initialise(); changing the caller's
        // string afterwards does not change the selection.
        std::string copied_pattern{ "Beta" };
        runner_options copied_options{};
        copied_options.verbosity_level = verbosity::silent;
        copied_options.filter_patterns = { copied_pattern };

        runner copied_runner;
        copied_runner.initialise (copied_options);
        copied_runner.add_top_suite ();
        copied_pattern = "Zeta";
        add_filter_suites (copied_runner, &runs);

        t.expect (eq (copied_runner.run_suites (), 0) and eq (runs.beta, 1)
                  and eq (runs.alpha_one, 0) and eq (runs.alpha_two, 0))
            << "patterns copied by initialise()";
        local_counts.passed_checks++;

        // Without patterns, everything runs.
        runner_options all_options{};
        all_options.verbosity_level = verbosity::silent;

        runs = filter_runs{};
        runner all_runner;
        all_runner.initialise (all_options);
        all_runner.add_top_suite ();
        add_filter_suites (all_runner, &runs);

        t.expect (eq (all_runner.run_suites (), 0)
                  and eq (all_runner.skipped_suites_count (), 0u)
                  and eq (all_runner.totals ().skipped_test_cases (), 0u)
                  and eq (runs.first, 3) and eq (runs.other, 3))
            << "nothing skipped without patterns";
        local_counts.passed_checks++;

        // A missing pattern is an option error.
        char* missing_argv[] = { arg_name, arg_silent, arg_filter, nullptr };

        runner missing_runner;
        missing_runner.initialise (3, missing_argv);
        missing_runner.add_top_suite ();

        t.expect (eq (missing_runner.run_suites (), 2)) << "missing pattern";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // With --list-tests, the suite bodies run, to create the test cases,
    // which are listed, but not run; the nested test cases are not listed.
    // The list is written to the output file, and, unless silent, to the
    // console.
    ts.test ("List test cases", [] (auto& t)
      {
        // Not `unit-checks-test-list.txt`, the disassembly of the build.
        static constexpr const char* list_path = "listed-test-cases.txt";

        // Reads the list into a string passed by reference, since a
        // returned local string is not always elided (clang `-Wnrvo`).
        const auto read_list = [] (std::string& text)
          {
            text.clear ();
            if (std::FILE* file = std::fopen (list_path, "r"); file != nullptr)
              {
                char buffer[128];
                std::size_t count;
                while ((count = std::fread (buffer, 1, sizeof (buffer), file))
                       > 0)
                  {
                    text.append (buffer, count);
                  }
                std::fclose (file);
              }
            std::remove (list_path);
          };

        int bodies_run = 0;
        bool suite_body_run = false;

        // Adds the same suites and test cases to a runner.
        const auto add_tests
            = [&bodies_run, &suite_body_run] (runner& r, suite& top)
          {
            r.add_suite ("Added", [&bodies_run, &suite_body_run] (suite& s)
              {
                suite_body_run = true;
                s.test ("Added test",
                        [&bodies_run] (test_case&) noexcept { ++bodies_run; });
                s.test_each ("Each", { 1, 2 },
                             [&bodies_run] (test_case&, int) noexcept
                  { ++bodies_run; });
              });
            r.add_suite ("Empty", [] (suite&) noexcept {});
            top.test ("Local test", [&bodies_run] (test_case& lt)
              {
                ++bodies_run;
                lt.test ("Nested test", [&bodies_run] (test_case&) noexcept
                  { ++bodies_run; });
              });
          };

        {
          char arg_name[] = "local";
          char arg_list[] = "--list-tests";
          char arg_silent[] = "--silent";
          char arg_output[] = "--output-file=listed-test-cases.txt";
          char* list_argv[]
              = { arg_name, arg_list, arg_silent, arg_output, nullptr };

          runner list_runner;
          list_runner.initialise (4, list_argv);
          auto& list_ts = list_runner.add_top_suite ("Local");
          add_tests (list_runner, list_ts);

          t.expect (eq (list_runner.run_suites (), 0))
              << "listed, exit code 0";
          local_counts.passed_checks++;
        }

        t.expect (eq (bodies_run, 0)) << "no test case body run";
        local_counts.passed_checks++;

        t.expect (suite_body_run) << "suite body run";
        local_counts.passed_checks++;

        std::string list;
        read_list (list);
        t.expect (eq (list, "All available test cases:\n"
                            "  Local\n"
                            "    Local test\n"
                            "  Added\n"
                            "    Added test\n"
                            "    Each (1)\n"
                            "    Each (2)\n"
                            "4 test cases in 2 test suites\n"))
            << "all test cases listed";
        local_counts.passed_checks++;

        {
          runner_options options{};
          options.verbosity_level = verbosity::silent;
          options.output_file_path = list_path;
          options.list_tests = true;
          options.filter_patterns = { "Added", "Each*" };

          runner filtered_runner;
          filtered_runner.initialise (options);
          auto& filtered_ts = filtered_runner.add_top_suite ("Local");
          add_tests (filtered_runner, filtered_ts);

          t.expect (eq (filtered_runner.run_suites (), 0))
              << "filtered, exit code 0";
          local_counts.passed_checks++;
        }

        read_list (list);
        t.expect (eq (list, "Matching test cases:\n"
                            "  Added\n"
                            "    Each (1)\n"
                            "    Each (2)\n"
                            "2 test cases in 1 test suite\n"))
            << "matching test cases listed";
        local_counts.passed_checks++;

        t.expect (eq (bodies_run, 0)) << "still no test case body run";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The suites added once run_suites() has started would never run; they are
    // rejected, and the exit code is not 0. A call of run_suites() from a suite
    // body is rejected too.
    ts.test ("Late suites", [] (auto& t)
      {
        runner_options options{};
        options.selected_reporter = reporter_kind::human;
        options.verbosity_level = verbosity::silent;

        int late_runs = 0;
        int nested_run_code = 0;

        runner during_runner;
        during_runner.initialise (options);
        during_runner.add_top_suite ("Local");
        during_runner.add_suite ("Outer", [&] (suite& s)
          {
            during_runner.add_suite ("Inner", [&late_runs] (suite& is)
              {
                ++late_runs;
                is.test ("Local test", [] (auto& lt) { lt.expect (false); });
              });
            nested_run_code = during_runner.run_suites ();
            s.test ("Local test", [] (auto& lt) { lt.expect (true); });
          });

        t.expect (eq (during_runner.run_suites (), 1))
            << "suite added during run_suites() rejected";
        local_counts.passed_checks++;

        t.expect (eq (late_runs, 0)
                  and eq (during_runner.added_suites_count (), 1u)
                  and eq (during_runner.totals ().failed_checks (), 0u))
            << "rejected suite neither run nor counted";
        local_counts.passed_checks++;

        t.expect (eq (nested_run_code, 1)) << "nested run_suites() rejected";
        local_counts.passed_checks++;

        runner after_runner;
        after_runner.initialise (options);
        after_runner.add_top_suite ("Local");
        after_runner.add_suite ("Early", [] (suite& s)
          { s.test ("Local test", [] (auto& lt) { lt.expect (true); }); });

        t.expect (eq (after_runner.run_suites (), 0)) << "session passed";
        local_counts.passed_checks++;

        after_runner.add_suite ("After", [&late_runs] (suite&) noexcept
          { ++late_runs; });

        t.expect (eq (after_runner.run_suites (), 1) and eq (late_runs, 0)
                  and eq (after_runner.added_suites_count (), 1u))
            << "suite added after run_suites() rejected";
        local_counts.passed_checks++;

        // The static suites are rejected the same way, whether they sort
        // before or after the running suite, or are constructed after
        // the session ended.
        runner static_runner;
        static_runner.initialise (options);
        static_runner.add_top_suite ("Local");
        std::optional<static_suite> before_suite;
        std::optional<static_suite> after_suite;
        static_runner.add_suite ("Middle", [&] (suite& s)
          {
            before_suite.emplace ("Before", static_runner,
                                  [&late_runs] (suite&) noexcept
              { ++late_runs; });
            after_suite.emplace ("Zafter", static_runner,
                                 [&late_runs] (suite&) noexcept
              { ++late_runs; });
            s.test ("Local test", [] (auto& lt) { lt.expect (true); });
          });

        t.expect (eq (static_runner.run_suites (), 1) and eq (late_runs, 0)
                  and eq (static_runner.static_suites_count (), 0u))
            << "static suites constructed during run_suites() rejected";
        local_counts.passed_checks++;

        std::optional<static_suite> ended_suite;
        ended_suite.emplace ("Ended", static_runner,
                             [&late_runs] (suite&) noexcept { ++late_runs; });

        t.expect (eq (static_runner.run_suites (), 1) and eq (late_runs, 0)
                  and eq (static_runner.static_suites_count (), 0u))
            << "static suite constructed after run_suites() rejected";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // A test case started on the suite from inside a running test case,
    // after a check, runs nested in the running test case, instead of
    // aborting the program.
    ts.test ("Test case started on the suite", [&ts] (auto& t)
      {
        t.expect (true) << "check before the test case";
        local_counts.passed_checks++;

        ts.test ("test case started on the suite", [] (auto& it)
          {
            it.expect (true) << "check in the test case";
            local_counts.passed_checks++;
          });
        local_counts.executed_test_cases++; // nested

        t.expect (eq (t.totals ().executed_test_cases (), 1u)) << "run nested";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++; // outer
      });

    // The additional arguments of `test()` and `add_suite()` are copied, so a
    // reference parameter refers to the copy, unless `std::ref()` is
    // passed, and a deferred suite receives the values of the call.
    // test_each() adds a test case for each value of a range or a tuple,
    // named after the value, or after its position if it cannot be
    // written.
    ts.test_each ("Each vector value", std::vector<int>{ 1, 2, 3 },
                  [] (auto& t, int value)
      {
        t.expect (gt (value, 0)) << "value " << value << " > 0";
        local_counts.passed_checks++;
        local_counts.executed_test_cases++;
      });

    ts.test_each ("Each list value", { "alpha", "beta" },
                  [] (auto& t, const char* value)
      {
        t.expect (ne (value, nullptr)) << "string not null";
        local_counts.passed_checks++;
        local_counts.executed_test_cases++;
      });

    static constexpr int primes[]{ 2, 3 };
    ts.test_each ("Each array value", primes, [] (auto& t, int value)
      {
        t.expect (gt (value, 1)) << "prime > 1";
        local_counts.passed_checks++;
        local_counts.executed_test_cases++;
      });

    ts.test_each ("Each tuple value", std::tuple{ 42, 1.5, true, 'x' },
                  [] (auto& t, const auto& value)
      {
        t.expect (eq (value, value)) << "equal to itself";
        local_counts.passed_checks++;
        local_counts.executed_test_cases++;
      });

    struct opaque
    {
    };
    ts.test_each ("Each unnamed value", std::vector<opaque>{ {}, {} },
                  [] (auto& t, const opaque&)
      {
        t.expect (true) << "named by position";
        local_counts.passed_checks++;
        local_counts.executed_test_cases++;
      });

    // The values and the callable are not copied, so move-only elements
    // are accepted, and a callable that counts its copies sees none.
    std::vector<std::unique_ptr<int>> owned;
    owned.push_back (std::make_unique<int> (7));
    owned.push_back (std::make_unique<int> (9));
    ts.test_each ("Each move-only value", owned,
                  [] (auto& t, const std::unique_ptr<int>& value)
      {
        t.expect (ne (value.get (), nullptr)) << "owned pointer";
        local_counts.passed_checks++;
        local_counts.executed_test_cases++;
      });

    copy_counter copy_counting_callable;
    ts.test_each ("Each uncopied callable", { 1, 2, 3 },
                  copy_counting_callable);
    local_counts.passed_checks += 3;
    local_counts.executed_test_cases += 3;

    ts.test ("Nested test_each", [] (auto& t)
      {
        t.test_each ("Each nested value", { 10, 20 }, [] (auto& nt, int value)
          {
            nt.expect (eq (value % 10, 0)) << "multiple of 10";
            local_counts.passed_checks++;
            local_counts.executed_test_cases++;
          });

        local_counts.executed_test_cases++;
      });

    ts.test_each ("Failed each value", { 1, 2 }, [] (auto& t, int value)
      {
        t.expect (eq (value, 1)) << "value " << value << " == 1";
        if (value == 1)
          {
            local_counts.passed_checks++;
          }
        else
          {
            local_counts.failed_checks++;
          }
        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Callable arguments", [] (auto& t)
      {
        runner_options options{};
        options.selected_reporter = reporter_kind::human;
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Local");

        int copied = 1;
        int referred = 1;
        int pointed = 1;

        local_ts.test ("Arguments",
                       [] (test_case& lt, int value, int& copy, int& reference,
                           int* pointer)
          {
            copy = value;
            reference = value;
            *pointer = value;
            lt.expect (true);
          },
                       2, copied, std::ref (referred), &pointed);

        t.expect (eq (copied, 1)) << "reference parameter refers to a copy";
        local_counts.passed_checks++;

        t.expect (eq (referred, 2)) << "std::ref() refers to the object";
        local_counts.passed_checks++;

        t.expect (eq (pointed, 2)) << "pointer refers to the object";
        local_counts.passed_checks++;

        int value = 3;
        int received = 0;

        local_runner.add_suite ("Deferred", [] (suite& s, int v, int* out)
          {
            *out = v;
            s.test ("Local test", [] (auto& lt) { lt.expect (true); });
          }, value, &received);
        value = 4;

        t.expect (eq (local_runner.run_suites (), 0))
            << "local session passed";
        local_counts.passed_checks++;

        t.expect (eq (received, 3)) << "deferred suite received the copy";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // A test case is destroyed when the `test()` call that created it
    // returns, together with its body and bound arguments; only their
    // number is kept.
    ts.test ("Test case lifetime", [] (auto& t)
      {
        runner_options options{};
        options.selected_reporter = reporter_kind::human;
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Local");

        live_instances = 0;

        local_ts.test ("Captured", [counter = instance_counter{}] (auto& lt)
          {
            static_cast<void> (counter);
            lt.expect (true);
          });

        local_ts.test ("Bound", [] (auto& lt, const instance_counter&)
          { lt.expect (true); }, instance_counter{});

        t.expect (eq (live_instances, 0)) << "test cases destroyed";
        local_counts.passed_checks++;

        t.expect (eq (local_ts.totals ().executed_test_cases (), 2U))
            << "test cases counted";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.run_suites (), 0))
            << "local session passed";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // A test case refers to its body, which is a local object of `test()`,
    // so the body is not allocated, whatever the size of the lambda
    // captures and of the bound arguments; a test case with a large body
    // allocates as much as one without captures.
    ts.test ("Test case bodies", [] (auto& t)
      {
        runner_options options{};
        options.selected_reporter = reporter_kind::human;
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Local");

        // Run a first test case, so that the allocations done only once,
        // if any, are not counted.
        local_ts.test ("First", [] (auto& lt) { lt.expect (true); });

        std::size_t start_count = allocations_count;
        local_ts.test ("Small", [] (auto& lt) { lt.expect (true); });
        const std::size_t small_allocations = allocations_count - start_count;

        std::int64_t a = 1;
        std::int64_t b = 2;
        std::int64_t c = 3;
        std::int64_t d = 4;
        std::int64_t sum = 0;

        start_count = allocations_count;
        local_ts.test ("Large",
                       [&a, &b, &c, &d, &sum] (auto& lt, std::int64_t x,
                                               std::int64_t y, std::int64_t z)
          {
            sum = a + b + c + d + x + y + z;
            lt.expect (true);
          },
                       5, 6, 7);
        const std::size_t large_allocations = allocations_count - start_count;

        t.expect (eq (sum, 28)) << "large body invoked";
        local_counts.passed_checks++;

        t.expect (eq (large_allocations, small_allocations))
            << "large body not allocated";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.run_suites (), 0))
            << "local session passed";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // A passed check formats neither its operands nor its messages when
    // the reporter does not write its line; a failed check is always
    // formatted.
    ts.test ("Formatting of passed checks", [] (auto& t)
      {
        const format_counter a{ 1 };
        const format_counter b{ 2 };

        for (const reporter_kind kind :
             { reporter_kind::human, reporter_kind::tap })
          {
            runner_options options{};
            options.selected_reporter = kind;
            options.verbosity_level = verbosity::silent;

            runner local_runner;
            local_runner.initialise (options);
            auto& local_ts = local_runner.add_top_suite ("Local");

            int passed_calls = -1;
            int failed_calls = -1;

            local_ts.test ("Checks", [&] (auto& lt)
              {
                format_calls = 0;
                lt.expect (eq (a, a)) << "passed " << a;
                passed_calls = format_calls;

                format_calls = 0;
                lt.expect (eq (a, b)) << "failed " << a;
                failed_calls = format_calls;
              });

            const char* name
                = (kind == reporter_kind::human) ? "human" : "tap";

            t.expect (eq (passed_calls, 0))
                << "passed check not formatted (" << name << ")";
            local_counts.passed_checks++;

            t.expect (eq (failed_calls, 3))
                << "failed check formatted (" << name << ")";
            local_counts.passed_checks++;

            t.expect (eq (local_ts.totals ().passed_checks (), 1U)
                      and eq (local_ts.totals ().failed_checks (), 1U))
                << "both checks counted (" << name << ")";
            local_counts.passed_checks++;
          }

        local_counts.executed_test_cases++;
      });

    // The abort handler can be replaced, and, when exceptions are
    // available, it can return control to the application by throwing.
    ts.test ("Abort handler", [] (auto& t)
      {
        runner local_runner;

        t.expect (local_runner.set_abort_handler (test_abort_handler)
                  == nullptr)
            << "no initial handler";
        local_counts.passed_checks++;

#if defined(__cpp_exceptions)
        bool caught = false;
        try
          {
            local_runner.abort ();
          }
        catch (const abort_exception&)
          {
            caught = true;
          }

        t.expect (caught) << "handler called";
        local_counts.passed_checks++;
#endif // defined(__cpp_exceptions)

        t.expect (local_runner.set_abort_handler (nullptr)
                  == &test_abort_handler)
            << "previous handler returned";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // While the report is open, from `initialise()` to the end of
    // `run_suites()`, the abort is reported by the reporter, which completes
    // the report, before the handler is called; an exception thrown by the
    // handler is not caught by the test cases, and reaches the
    // application, and the runner cannot be used afterwards.
    ts.test ("Abort during the session", [] (auto& t)
      {
#if defined(__cpp_exceptions)
        for (const reporter_kind kind :
             { reporter_kind::human, reporter_kind::tap })
          {
            const char* prefix
                = (kind == reporter_kind::human) ? "human " : "tap ";

            runner_options options{};
            options.selected_reporter = kind;
            options.verbosity_level = verbosity::silent;

            runner local_runner;
            local_runner.initialise (options);
            auto& local_ts = local_runner.add_top_suite ("Local");
            local_runner.set_abort_handler (test_abort_handler);

            bool caught = false;
            try
              {
                local_ts.test ("Aborting", [&local_runner] (auto& lt)
                  {
                    lt.expect (true);
                    local_runner.abort ();
                  });
              }
            catch (const abort_exception&)
              {
                caught = true;
              }

            t.expect (caught) << prefix << "handler exception passed on";
            local_counts.passed_checks++;

            bool is_run = false;
            local_ts.test ("After the abort", [&is_run] (auto& lt)
              {
                is_run = true;
                lt.expect (true);
              });

            t.expect (!is_run) << prefix << "no test case after the abort";
            local_counts.passed_checks++;

            t.expect (eq (local_runner.run_suites (), 1))
                << prefix << "run_suites() refused after the abort";
            local_counts.passed_checks++;
          }
#else
        t.expect (true) << "skipped without exceptions";
        local_counts.passed_checks++;
#endif // defined(__cpp_exceptions)

        local_counts.executed_test_cases++;
      });

    // The test case names can be standard strings, also temporary ones,
    // and the suite names can also be string views; a helper can forward
    // a test case name with the location of its caller.
    ts.test ("Test case and suite names", [] (auto& t)
      {
        runner_options options{};
        options.selected_reporter = reporter_kind::human;
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Local");

        std::string reported;

        const std::string prefix = "Name";
        local_ts.test (prefix + " from temporary", [&reported] (auto& lt)
          {
            reported = lt.name ();
            lt.expect (true);
          });

        t.expect (eq (reported, std::string{ "Name from temporary" }))
            << "temporary string name";
        local_counts.passed_checks++;

        const std::string named = "Name from string";
        local_ts.test (named, [&reported] (auto& lt)
          {
            reported = lt.name ();
            lt.expect (true);
          });

        t.expect (eq (reported, named)) << "string name";
        local_counts.passed_checks++;

        int runs = 0;
        add_named_test_case (local_ts, "Name via helper", &runs);
        add_named_test_case (local_ts, prefix + " via helper", &runs);

        t.expect (eq (runs, 2)) << "helper test cases run";
        local_counts.passed_checks++;

        const auto line = converted_line ("Converted name");
        const decltype (line) expected_line = __LINE__ - 1;

        t.expect (eq (line, expected_line)) << "location of the caller";
        local_counts.passed_checks++;

        std::string from_string;
        std::string from_view;

        {
          // Destroyed before the suite runs.
          std::string suite_name = "Suite from string";
          local_runner.add_suite (suite_name, [&from_string] (suite& s)
            {
              from_string = s.name ();
              s.test ("Local test", [] (auto& lt) { lt.expect (true); });
            });
          suite_name = "Changed";
        }

        // Not null-terminated after the first 15 characters.
        const std::string_view view = "Suite from view, truncated";
        local_runner.add_suite (view.substr (0, 15), [&from_view] (suite& s)
          {
            from_view = s.name ();
            s.test ("Local test", [] (auto& lt) { lt.expect (true); });
          });

        t.expect (eq (local_runner.run_suites (), 0))
            << "local session passed";
        local_counts.passed_checks++;

        t.expect (eq (from_string, std::string{ "Suite from string" }))
            << "string suite name copied";
        local_counts.passed_checks++;

        t.expect (eq (from_view, std::string{ "Suite from view" }))
            << "string view suite name copied";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);
  } };

// ----------------------------------------------------------------------------
