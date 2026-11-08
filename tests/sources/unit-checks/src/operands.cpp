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

#include "unit-checks-test.h"

#include <array>
#include <chrono>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <numeric>
#include <optional>
#include <ratio>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>

namespace mt = micro_os_plus::micro_test_plus;

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
  mt::expression_formatter&
  operator<< (mt::expression_formatter& formatter, const point& p)
  {
    return formatter << "{ " << p.x << ", " << p.y << " }";
  }

  // A user-defined type with members whose types the formatter decorates
  // (the `long` suffix, the quotes of the strings), written by the
  // application as it wants, and reported so (#233).
  struct money
  {
    long cents;
    std::string currency;
  };

  bool
  operator== (const money& lhs, const money& rhs)
  {
    return lhs.cents == rhs.cents && lhs.currency == rhs.currency;
  }

  mt::expression_formatter&
  operator<< (mt::expression_formatter& formatter, const money& m)
  {
    return formatter << m.cents / 100 << "." << m.cents % 100 << " "
                     << m.currency;
  }

  // A scoped enumeration, and a type with `begin()` and `end()`, which the
  // formatter has templates for, with an `operator<<` of the application,
  // which must write them, in the plain mode.
  enum class lamp
  {
    stop,
    go
  };

  mt::expression_formatter&
  operator<< (mt::expression_formatter& formatter, const lamp& s)
  {
    return formatter << (s == lamp::stop ? "stop" : "go") << '/'
                     << static_cast<unsigned> (s);
  }

  struct basket
  {
    std::vector<int> items;

    [[nodiscard]] auto
    begin () const noexcept
    {
      return items.begin ();
    }

    [[nodiscard]] auto
    end () const noexcept
    {
      return items.end ();
    }

    bool
    operator== (const basket&) const
        = default;
  };

  mt::expression_formatter&
  operator<< (mt::expression_formatter& formatter, const basket& b)
  {
    return formatter << "basket of " << b.items.size ();
  }

  // A comparator, a predicate, and an operator of the application, built
  // only with public names, and reported as the built-in ones (#149).
  struct divides_tag
  {
    static constexpr const char* symbol = " divides ";

    template <class Lhs_T, class Rhs_T>
    static constexpr bool
    apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return rhs % lhs == 0;
    }
  };

  struct even_tag
  {
    static constexpr const char* symbol = "even ";

    template <class T>
    static constexpr bool
    apply (const T& t)
    {
      return t % 2 == 0;
    }
  };

  // A type of the application whose namespace has functions with the names
  // of the internal ones, better matches than the templates, which must
  // not be found by argument-dependent lookup (#251).
  struct hijacker
  {
    int value;
  };

  bool
  operator== (const hijacker& lhs, const hijacker& rhs)
  {
    return lhs.value == rhs.value;
  }

  mt::expression_formatter&
  operator<< (mt::expression_formatter& formatter, const hijacker& h)
  {
    return formatter << h.value;
  }

  [[maybe_unused]] int
  as_operand (hijacker&)
  {
    return 0;
  }

  [[maybe_unused]] int
  as_operand (hijacker&&)
  {
    return 0;
  }

  struct same_tag
  {
    static constexpr const char* symbol = " same ";

    template <class Lhs_T, class Rhs_T>
    static constexpr bool
    apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return lhs == rhs;
    }
  };

  template <class Lhs_T, class Rhs_T>
  constexpr auto
  divides (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return mt::extension::compare_op{ lhs, rhs, divides_tag{} };
  }

  template <class T>
  constexpr auto
  even (const T& t)
  {
    return mt::extension::predicate_op{ t, even_tag{} };
  }

  // A comparator of the application on C strings, reported with the
  // operands quoted, as the built-in comparators report them.
  struct prefix_tag
  {
    static constexpr const char* symbol = " has prefix ";

    template <class Lhs_T, class Rhs_T>
    static constexpr bool
    apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return std::string_view{ lhs }.starts_with (std::string_view{ rhs });
    }
  };

  template <class Lhs_T, class Rhs_T>
  constexpr auto
  has_prefix (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return mt::extension::compare_op{ lhs, rhs, prefix_tag{} };
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

  mt::expression_formatter&
  operator<< (mt::expression_formatter& formatter, state s)
  {
    return formatter << (s == state::on ? "on" : "off");
  }

  // A check built from the locals of a function, and returned from it
  // (#229).
  auto
  name_is_expected (const std::string& actual)
  {
    const std::string expected{ "an actual name, longer than the small "
                                "string buffer of the library" };
    return mt::eq (actual, expected);
  }

  // A user-defined type that counts its copies, to check that the
  // comparators do not copy the operands more than needed.
  int counted_copies = 0;

  struct counted
  {
    explicit counted (int v) : number{ v }
    {
    }

    counted (const counted& other) : number{ other.number }
    {
      ++counted_copies;
    }

    counted&
    operator= (const counted& other)
    {
      number = other.number;
      ++counted_copies;
      return *this;
    }

    int number;
  };

  constexpr bool
  operator== (const counted& lhs, const counted& rhs)
  {
    return lhs.number == rhs.number;
  }

  mt::expression_formatter&
  operator<< (mt::expression_formatter& formatter, const counted& c)
  {
    return formatter << c.number;
  }
} // namespace

// ----------------------------------------------------------------------------

static mt::static_suite ts_operands{ "Operands suite", tr, [] (auto& ts)
  {
    const mt::counters& current_suite_totals = ts.totals ();

    local_counts = {};

    // A copy of the counters is a snapshot, which is not updated by the
    // later checks.
    const mt::counters before = ts.totals ();

    ts.test ("Arrays", [] (auto& t)
      {
        t.expect (mt::eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
            << "array{ 42 } == array{ 42 }";
        local_counts.passed_checks++;

        t.expect (mt::ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
            << "array{ 42 } != array{ 43 }";
        local_counts.passed_checks++;

        t.expect (mt::eq (std::array{ 1, 2 }, std::array{ 1, 2 }))
            << "array{ 1, 2 } == array{ 1, 2 }";
        local_counts.passed_checks++;

        t.expect (mt::ne (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
            << "array{ 1, 2, 3 } != array{ 1, 2, 4 }";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    test_assert (before.passed_checks () == 0);
    test_assert (before.executed_test_cases () == 0);
    test_assert (current_suite_totals.passed_checks ()
                 > before.passed_checks ());

    mt::counters after{};
    after = current_suite_totals;
    test_assert (after.passed_checks ()
                 == current_suite_totals.passed_checks ());
    test_assert (after.executed_test_cases ()
                 == current_suite_totals.executed_test_cases ());

    ts.test ("Arrays bad", [] (auto& t)
      {
        t.expect (mt::ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
            << "array{ 42 } ne array{ 42 }";
        local_counts.failed_checks++;

        t.expect (mt::eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
            << "array{ 42 } eq array{ 43 }";
        local_counts.failed_checks++;

        t.expect (mt::ne (std::array{ 1, 2 }, std::array{ 1, 2 }))
            << "array{ 1, 2 } ne array{ 1, 2 }";
        local_counts.failed_checks++;

        t.expect (mt::eq (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
            << "array{ 1, 2, 3 } eq array{ 1, 2, 4 }";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Vectors", [] (auto& t)
      {
        t.expect (mt::eq (std::vector<int>{}, std::vector<int>{}))
            << "vector{ } == vector{ }";
        local_counts.passed_checks++;

        t.expect (mt::eq (std::vector<int>{}, std::vector<int>{}));
        local_counts.passed_checks++;

        t.expect (mt::eq (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
            << "vector{ 42 } == vector{ 42 }";
        local_counts.passed_checks++;

        t.expect (mt::ne (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
            << "vector{ 42 } != vector{ 43 }";
        local_counts.passed_checks++;

        t.expect (mt::eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
            << "vector{ 1, 2 } == vector{ 1, 2 }";
        local_counts.passed_checks++;

        t.expect (
            mt::ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
            << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Vectors bad", [] (auto& t)
      {
        t.expect (mt::ne (std::vector<int>{}, std::vector<int>{}))
            << "vector{ } != vector{ }";
        local_counts.failed_checks++;

        t.expect (mt::ne (std::vector<int>{}, std::vector<int>{}));
        local_counts.failed_checks++;

        t.expect (mt::ne (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
            << "vector{ 42 } != vector{ 42 }";
        local_counts.failed_checks++;

        t.expect (mt::eq (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
            << "vector{ 42 } == vector{ 43 }";
        local_counts.failed_checks++;

        t.expect (mt::ne (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
            << "vector{ 1, 2 } != vector{ 1, 2 }";
        local_counts.failed_checks++;

        t.expect (
            mt::eq (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
            << "vector{ 1, 2, 3 } == vector{ 1, 2, 4 }";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Custom types", [] (auto& t)
      {
        t.expect (mt::eq (point{ 1, 2 }, point{ 1, 2 }))
            << "point{ 1, 2 } == point{ 1, 2 }";
        local_counts.passed_checks++;

        t.expect (mt::ne (point{ 1, 2 }, point{ 1, 3 }))
            << "point{ 1, 2 } != point{ 1, 3 }";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Custom types bad", [] (auto& t)
      {
        t.expect (mt::eq (point{ 1, 2 }, point{ 1, 3 }))
            << "point{ 1, 2 } == point{ 1, 3 }";
        local_counts.failed_checks++;

        // Without a message; the operands are reported in the condition.
        t.expect (mt::eq (point{ 1, 2 }, point{ 1, 3 }));
        local_counts.failed_checks++;

        t.expect (mt::ne (point{ 1, 2 }, point{ 1, 2 }))
            << "point{ 1, 2 } != point{ 1, 2 }";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The strings of the wide character types are compared by content, and
    // reported as UTF-8 text; their pointers and arrays are not strings
    // (#236). The `std::wstring` and `std::u16string` objects are
    // constructed with an explicit length, to avoid a GCC 14 and 15
    // `-Wstringop-overread` false positive with `-O3 -flto`, which source
    // pragmas cannot silence (#283).
    ts.test ("Wide strings", [] (auto& t)
      {
        t.expect (mt::eq (std::wstring{ L"caf\u00e9", 4 },
                          std::wstring{ L"caf\u00e9", 4 }))
            << L"wide " << L"string";
        local_counts.passed_checks++;

        t.expect (mt::eq (std::u16string_view{ u"caf\u00e9" },
                          std::u16string{ u"caf\u00e9", 4 }));
        local_counts.passed_checks++;

        t.expect (mt::eq (std::u32string{ U"\U0001F600" },
                          std::u32string_view{ U"\U0001F600" }));
        local_counts.passed_checks++;

        t.expect (mt::eq (std::u8string{ u8"caf\u00e9" },
                          std::u8string_view{ u8"caf\u00e9" }));
        local_counts.passed_checks++;

        t.expect (mt::ne (std::u16string{ u"abc", 3 },
                          std::u16string{ u"abd", 3 }));
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Wide strings bad", [] (auto& t)
      {
        t.expect (mt::eq (std::u16string{ u"caf\u00e9", 4 },
                          std::u16string{ u"cafe", 4 }));
        local_counts.failed_checks++;

        t.expect (mt::eq (std::wstring_view{ L"a\tb" },
                          std::wstring_view{ L"a b" }));
        local_counts.failed_checks++;

        t.expect (
            mt::eq (std::u32string{ U"\U0001F600" }, std::u32string{ U"x" }));
        local_counts.failed_checks++;

        t.expect (mt::eq (std::u8string_view{ u8"na\u00efve" },
                          std::u8string_view{ u8"naive" }));
        local_counts.failed_checks++;

        // The messages write the text of the pointers and of the arrays.
        t.expect (false) << u"utf-16 " << U"utf-32 " << u8"utf-8 " << L"wide";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The values written by the `operator<<` of the application are
    // reported as it writes them, in the operands and in the elements of
    // the standard types (#233).
    ts.test ("Custom types with members bad", [] (auto& t)
      {
        t.expect (mt::eq (money{ 11910, "EUR" }, money{ 11900, "EUR" }));
        local_counts.failed_checks++;

        t.expect (mt::eq (std::pair{ 1, money{ 10, "RON" } },
                          std::pair{ 1, money{ 20, "RON" } }));
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The application `operator<<` takes precedence over the templates of
    // the formatter, and writes in the plain mode, in the operands and in
    // the elements of the standard types.
    ts.test ("Custom enumerations and ranges bad", [] (auto& t)
      {
        t.expect (mt::eq (lamp::stop, lamp::go));
        local_counts.failed_checks++;

        t.expect (mt::eq (basket{ { 1 } }, basket{ { 2 } }));
        local_counts.failed_checks++;

        t.expect (mt::eq (std::vector<lamp>{ lamp::stop },
                          std::vector<lamp>{ lamp::go }));
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Custom comparators", [] (auto& t)
      {
        t.expect (divides (3, 12)) << "3 divides 12";
        local_counts.passed_checks++;

        t.expect (even (4)) << "even 4";
        local_counts.passed_checks++;

        t.expect (mt::all_of (divides (3, 12), even (4))) << "combined";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Operand deduction", [] (auto& t)
      {
        hijacker a{ 1 };
        hijacker b{ 1 };
        t.expect (mt::extension::compare_op{ a, b, same_tag{} }) << "lvalues";
        local_counts.passed_checks++;

        t.expect (mt::extension::compare_op{ hijacker{ 2 }, hijacker{ 2 },
                                             same_tag{} })
            << "temporaries";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Custom comparators bad", [] (auto& t)
      {
        // The operands are reported, with the symbols of the tags.
        t.expect (divides (5, 12)) << "5 divides 12";
        local_counts.failed_checks++;

        t.expect (divides (5, 12));
        local_counts.failed_checks++;

        t.expect (even (7));
        local_counts.failed_checks++;

        t.expect (mt::all_of (divides (3, 12), even (7)));
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Custom comparators with strings bad", [] (auto& t)
      {
        // The C string operands are quoted, as for the built-in
        // comparators, so that an empty one is visible.
        const char* text = "hello";
        t.expect (has_prefix (text, "help"));
        local_counts.failed_checks++;

        char buffer[8] = "";
        t.expect (has_prefix (buffer, "help"));
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The comparators accept the standard types that the formatter writes.
    ts.test ("Standard types", [] (auto& t)
      {
        t.expect (mt::eq (colour::red, colour::red))
            << "colour::red == colour::red";
        local_counts.passed_checks++;

        t.expect (mt::ne (colour::red, colour::green))
            << "colour::red != colour::green";
        local_counts.passed_checks++;

        t.expect (mt::lt (level::low, level::high))
            << "level::low < level::high";
        local_counts.passed_checks++;

        t.expect (mt::ne (state::off, state::on)) << "state::off != state::on";
        local_counts.passed_checks++;

        t.expect (mt::ne (std::byte{ 1 }, std::byte{ 2 }))
            << "std::byte{ 1 } != std::byte{ 2 }";
        local_counts.passed_checks++;

        t.expect (mt::eq (std::pair{ 1, 2 }, std::pair{ 1, 2 }))
            << "pair{ 1, 2 } == pair{ 1, 2 }";
        local_counts.passed_checks++;

        t.expect (mt::ne (std::tuple{ 1, 'a' }, std::tuple{ 1, 'b' }))
            << "tuple{ 1, 'a' } != tuple{ 1, 'b' }";
        local_counts.passed_checks++;

        std::vector<std::pair<int, int>> pairs1{ { 1, 2 } };
        std::vector<std::pair<int, int>> pairs2{ { 1, 3 } };
        t.expect (mt::ne (pairs1, pairs2)) << "pairs1 != pairs2";
        local_counts.passed_checks++;

        std::optional<int> optional{ 42 };
        t.expect (mt::eq (optional, 42)) << "optional == 42";
        local_counts.passed_checks++;

        t.expect (mt::ne (optional, std::nullopt)) << "optional != nullopt";
        local_counts.passed_checks++;

        using namespace std::chrono_literals;
        t.expect (mt::eq (5ms, 5ms)) << "5ms == 5ms";
        local_counts.passed_checks++;

        t.expect (mt::lt (250us, 1ms)) << "250us < 1ms";
        local_counts.passed_checks++;

        t.expect (mt::eq (1000ms, 1s)) << "1000ms == 1s";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Standard types bad", [] (auto& t)
      {
        t.expect (mt::eq (colour::red, colour::green))
            << "colour::red == colour::green";
        local_counts.failed_checks++;

        t.expect (mt::eq (std::byte{ 1 }, std::byte{ 2 }))
            << "std::byte{ 1 } == std::byte{ 2 }";
        local_counts.failed_checks++;

        std::vector<std::pair<int, int>> pairs1{ { 1, 2 } };
        std::vector<std::pair<int, int>> pairs2{ { 1, 3 } };
        t.expect (mt::eq (pairs1, pairs2)) << "pairs1 == pairs2";
        local_counts.failed_checks++;

        t.expect (mt::eq (std::optional<int>{ 42 }, std::nullopt))
            << "optional == nullopt";
        local_counts.failed_checks++;

        t.expect (mt::eq (std::chrono::milliseconds{ 5 },
                          std::chrono::milliseconds{ 6 }))
            << "5ms == 6ms";
        local_counts.failed_checks++;

        // A period without a standard unit is written as the ratio, `[N/D]s`,
        // without the type suffixes of the numbers.
        t.expect (mt::eq (std::chrono::duration<int, std::ratio<1, 30>>{ 3 },
                          std::chrono::duration<int, std::ratio<1, 30>>{ 4 }))
            << "3[1/30]s == 4[1/30]s";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The checks accept the types with an `explicit operator bool`. Without
    // a message, a passed check is written as the result of the conversion,
    // not as the value of the operand.
    ts.test ("Explicit conversions to bool", [] (auto& t)
      {
        std::optional<int> engaged{ 0 };
        t.expect (engaged) << "optional with a value";
        local_counts.passed_checks++;

        // Written as `true`, not as the contained `0`.
        t.expect (std::optional<int>{ 0 });
        local_counts.passed_checks++;

        auto owner = std::make_unique<int> (42);
        t.expect (owner) << "unique_ptr not null";
        local_counts.passed_checks++;

        std::function<int (int)> callable = [] (int i) noexcept { return i; };
        t.expect (callable) << "function not empty";
        local_counts.passed_checks++;

        t.require (owner) << "required unique_ptr";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Explicit conversions to bool bad", [] (auto& t)
      {
        t.expect (std::optional<int>{}) << "empty optional";
        local_counts.failed_checks++;

        t.expect (std::unique_ptr<int>{}) << "null unique_ptr";
        local_counts.failed_checks++;

        t.expect (std::function<void (void)>{}) << "empty function";
        local_counts.failed_checks++;

        t.expect (std::shared_ptr<int>{});
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The comparators accept pointers to const objects, whose addresses are
    // displayed on failure.
    ts.test ("Pointers to const", [] (auto& t)
      {
        static const int first = 1;
        static const int second = 2;

        t.expect (mt::ne (&first, &second)) << "different const objects";
        local_counts.passed_checks++;

        t.expect (mt::eq (&first, &first)) << "same const object";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The named operands are copied into the comparators, so that a
    // comparator can be returned from the function that builds it (#229).
    ts.test ("Operand copies", [] (auto& t)
      {
        const counted a{ 1 };
        const counted b{ 1 };

        counted_copies = 0;
        t.expect (mt::eq (a, b)) << "plain operands";
        local_counts.passed_checks++;
        int copies = counted_copies;

        t.expect (mt::eq (copies, 2)) << "plain operands copied once each";
        local_counts.passed_checks++;

        // A comparator that outlives the statement owns its temporary
        // operands; `counted` has no move constructor, so the temporary
        // is copied, once.
        counted_copies = 0;
        const auto stored = mt::eq (counted{ 1 }, b);
        copies = counted_copies;

        t.expect (stored) << "stored comparator";
        local_counts.passed_checks++;

        t.expect (mt::eq (copies, 2)) << "operands stored once each";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // A comparator built from the locals of a function, and returned from
    // it, must not refer to the destroyed locals (#229).
    ts.test ("Returned comparators", [] (auto& t)
      {
        const std::string actual{ "an actual name, longer than the small "
                                  "string buffer of the library" };
        t.expect (name_is_expected (actual)) << "returned comparator";
        local_counts.passed_checks++;

        const auto stored = name_is_expected (actual);
        t.expect (mt::eq (stored.rhs (), actual))
            << "operand of the returned comparator";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The arrays that are not `char` arrays are compared by content, not by
    // address, and are displayed as ranges.
    ts.test ("Raw arrays", [] (auto& t)
      {
        const std::uint8_t first[]{ 1, 2, 3 };
        const std::uint8_t same[]{ 1, 2, 3 };
        const std::uint8_t other[]{ 1, 2, 4 };
        const std::uint8_t shorter[]{ 1, 2 };
        const int numbers[]{ 1, 2 };
        const std::vector<int> vector{ 1, 2 };

        t.expect (mt::eq (first, same)) << "bytes equal";
        local_counts.passed_checks++;

        t.expect (mt::ne (first, other)) << "bytes not equal";
        local_counts.passed_checks++;

        t.expect (mt::ne (first, shorter)) << "different sizes";
        local_counts.passed_checks++;

        t.expect (mt::lt (first, other)) << "bytes less";
        local_counts.passed_checks++;

        t.expect (mt::gt (first, shorter)) << "prefix is less";
        local_counts.passed_checks++;

        t.expect (mt::eq (numbers, vector)) << "array == vector";
        local_counts.passed_checks++;

        t.expect (mt::eq (vector, numbers)) << "vector == array";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Raw arrays bad", [] (auto& t)
      {
        const std::uint8_t first[]{ 1, 2, 3 };
        const std::uint8_t other[]{ 1, 2, 4 };

        t.expect (mt::eq (first, other)) << "bytes eq";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    // The volatile arrays, such as the buffers filled by a DMA controller,
    // are compared element by element, also the ones of characters; the
    // volatile pointers are compared by address (#279).
    ts.test ("Volatile operands", [] (auto& t)
      {
        static volatile std::uint8_t buffer[]{ 1, 2, 3 };
        static volatile int numbers[]{ -1, 2 };
        static volatile char text[]{ 'a', 'b', 0 };
        volatile char* const pointer = text;

        t.expect (mt::eq (buffer, std::array<std::uint8_t, 3>{ 1, 2, 3 }))
            << "volatile bytes";
        local_counts.passed_checks++;

        t.expect (mt::eq (numbers, std::vector<int>{ -1, 2 }))
            << "volatile integers";
        local_counts.passed_checks++;

        t.expect (mt::ne (numbers, std::vector<unsigned>{ UINT_MAX, 2u }))
            << "volatile integers by value";
        local_counts.passed_checks++;

        t.expect (mt::eq (text, std::array<char, 3>{ 'a', 'b', 0 }))
            << "volatile characters";
        local_counts.passed_checks++;

        t.expect (mt::eq (pointer, pointer)) << "volatile pointer";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Volatile operands bad", [] (auto& t)
      {
        static volatile std::uint8_t buffer[]{ 1, 2, 3 };

        t.expect (mt::eq (buffer, std::array<std::uint8_t, 3>{ 1, 2, 4 }))
            << "volatile bytes eq";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    ts.test ("Long ranges bad", [] (auto& t)
      {
        std::vector<int> numbers (20);
        std::iota (numbers.begin (), numbers.end (), 1);
        std::vector<int> other{ numbers };
        other.back () = 0;

        t.expect (mt::eq (numbers, other)) << "long vector eq";
        local_counts.failed_checks++;

        const std::vector<std::uint8_t> exact (16, 7);
        std::vector<std::uint8_t> exact_other{ exact };
        exact_other.back () = 8;

        t.expect (mt::eq (exact, exact_other)) << "16 bytes eq";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });
  } };

// ----------------------------------------------------------------------------
