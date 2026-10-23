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
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
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

  template <class Lhs_T, class Rhs_T>
  constexpr auto
  divides (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return extension::compare_op{ lhs, rhs, divides_tag{} };
  }

  template <class T>
  constexpr auto
  even (const T& t)
  {
    return extension::predicate_op{ t, even_tag{} };
  }

  namespace custom_operators
  {
    // `a | b` reads "a divides b"; enabled only when an operand is a
    // framework type, as the operators of the framework are.
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator| (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return extension::compare_op{ lhs, rhs, divides_tag{} };
    }
  } // namespace custom_operators

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

  expression_formatter&
  operator<< (expression_formatter& formatter, const counted& c)
  {
    return formatter << c.number;
  }
} // namespace

// ----------------------------------------------------------------------------

static static_suite ts_operands{ "Operands suite", tr, [] (auto& ts)
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

    // A copy of the counters is a snapshot, which is not updated by the
    // later checks.
    const counters before = ts.totals ();

    ts.test ("Arrays", [] (auto& t)
      {
        t.expect (eq (std::array<int, 1>{ 42 }, std::array<int, 1>{ 42 }))
            << "array{ 42 } == array{ 42 }";
        local_counts.passed_checks++;

        t.expect (ne (std::array<int, 1>{ 42 }, std::array<int, 1>{ 43 }))
            << "array{ 42 } != array{ 43 }";
        local_counts.passed_checks++;

        t.expect (eq (std::array{ 1, 2 }, std::array{ 1, 2 }))
            << "array{ 1, 2 } == array{ 1, 2 }";
        local_counts.passed_checks++;

        t.expect (ne (std::array{ 1, 2, 3 }, std::array{ 1, 2, 4 }))
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

    counters after{};
    after = current_suite_totals;
    test_assert (after.passed_checks ()
                 == current_suite_totals.passed_checks ());
    test_assert (after.executed_test_cases ()
                 == current_suite_totals.executed_test_cases ());

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
        t.expect (eq (std::vector<int>{}, std::vector<int>{}))
            << "vector{ } == vector{ }";
        local_counts.passed_checks++;

        t.expect (eq (std::vector<int>{}, std::vector<int>{}));
        local_counts.passed_checks++;

        t.expect (eq (std::vector<int>{ 42 }, std::vector<int>{ 42 }))
            << "vector{ 42 } == vector{ 42 }";
        local_counts.passed_checks++;

        t.expect (ne (std::vector<int>{ 42 }, std::vector<int>{ 43 }))
            << "vector{ 42 } != vector{ 43 }";
        local_counts.passed_checks++;

        t.expect (eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
            << "vector{ 1, 2 } == vector{ 1, 2 }";
        local_counts.passed_checks++;

        t.expect (
            ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
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
        t.expect (eq (point{ 1, 2 }, point{ 1, 2 }))
            << "point{ 1, 2 } == point{ 1, 2 }";
        local_counts.passed_checks++;

        t.expect (ne (point{ 1, 2 }, point{ 1, 3 }))
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
        t.expect (eq (point{ 1, 2 }, point{ 1, 3 }))
            << "point{ 1, 2 } == point{ 1, 3 }";
        local_counts.failed_checks++;

        // Without a message; the operands are reported in the condition.
        t.expect (eq (point{ 1, 2 }, point{ 1, 3 }));
        local_counts.failed_checks++;

        t.expect (ne (point{ 1, 2 }, point{ 1, 2 }))
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

    ts.test ("Custom comparators", [] (auto& t)
      {
        using namespace literals;
        using namespace custom_operators;

        t.expect (divides (3, 12)) << "3 divides 12";
        local_counts.passed_checks++;

        t.expect (divides (3_i, to_i{ 12 })) << "3_i divides to_i{ 12 }";
        local_counts.passed_checks++;

        t.expect (even (to_i{ 4 })) << "even to_i{ 4 }";
        local_counts.passed_checks++;

        t.expect (3_i | 12) << "3_i | 12";
        local_counts.passed_checks++;

        t.expect (both (divides (3, 12), even (4))) << "combined";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Custom comparators bad", [] (auto& t)
      {
        using namespace literals;
        using namespace custom_operators;

        // The operands are reported, with the symbols of the tags.
        t.expect (divides (5, 12)) << "5 divides 12";
        local_counts.failed_checks++;

        t.expect (divides (5, 12));
        local_counts.failed_checks++;

        t.expect (even (to_i{ 7 }));
        local_counts.failed_checks++;

        t.expect (5_i | 12);
        local_counts.failed_checks++;

        t.expect (both (divides (3, 12), even (7)));
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
        t.expect (eq (colour::red, colour::red))
            << "colour::red == colour::red";
        local_counts.passed_checks++;

        t.expect (ne (colour::red, colour::green))
            << "colour::red != colour::green";
        local_counts.passed_checks++;

        t.expect (lt (level::low, level::high)) << "level::low < level::high";
        local_counts.passed_checks++;

        t.expect (ne (state::off, state::on)) << "state::off != state::on";
        local_counts.passed_checks++;

        t.expect (ne (std::byte{ 1 }, std::byte{ 2 }))
            << "std::byte{ 1 } != std::byte{ 2 }";
        local_counts.passed_checks++;

        t.expect (eq (std::pair{ 1, 2 }, std::pair{ 1, 2 }))
            << "pair{ 1, 2 } == pair{ 1, 2 }";
        local_counts.passed_checks++;

        t.expect (ne (std::tuple{ 1, 'a' }, std::tuple{ 1, 'b' }))
            << "tuple{ 1, 'a' } != tuple{ 1, 'b' }";
        local_counts.passed_checks++;

        std::vector<std::pair<int, int>> pairs1{ { 1, 2 } };
        std::vector<std::pair<int, int>> pairs2{ { 1, 3 } };
        t.expect (ne (pairs1, pairs2)) << "pairs1 != pairs2";
        local_counts.passed_checks++;

        std::optional<int> optional{ 42 };
        t.expect (eq (optional, 42)) << "optional == 42";
        local_counts.passed_checks++;

        t.expect (ne (optional, std::nullopt)) << "optional != nullopt";
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
        t.expect (eq (colour::red, colour::green))
            << "colour::red == colour::green";
        local_counts.failed_checks++;

        t.expect (eq (std::byte{ 1 }, std::byte{ 2 }))
            << "std::byte{ 1 } == std::byte{ 2 }";
        local_counts.failed_checks++;

        std::vector<std::pair<int, int>> pairs1{ { 1, 2 } };
        std::vector<std::pair<int, int>> pairs2{ { 1, 3 } };
        t.expect (eq (pairs1, pairs2)) << "pairs1 == pairs2";
        local_counts.failed_checks++;

        t.expect (eq (std::optional<int>{ 42 }, std::nullopt))
            << "optional == nullopt";
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

        // Written as `true`, not as the contained `false`.
        t.expect (std::optional<bool>{ false });
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

        t.expect (ne (&first, &second)) << "different const objects";
        local_counts.passed_checks++;

        t.expect (eq (&first, &first)) << "same const object";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The named operands are referred to, and the temporaries are moved,
    // so the comparators do not copy the operands.
    ts.test ("Operand copies", [] (auto& t)
      {
        const counted a{ 1 };
        const counted b{ 1 };

        counted_copies = 0;
        t.expect (eq (a, b)) << "plain operands";
        local_counts.passed_checks++;
        int copies = counted_copies;

        t.expect (eq (copies, 0)) << "plain operands not copied";
        local_counts.passed_checks++;

        const to_t<counted> wrapped{ a };

        counted_copies = 0;
        t.expect (eq (wrapped, b)) << "wrapped operand";
        local_counts.passed_checks++;
        copies = counted_copies;

        t.expect (eq (copies, 0)) << "wrapped operand not copied";
        local_counts.passed_checks++;

        counted_copies = 0;
        t.expect (both (eq (a, b), negate (ne (a, b))))
            << "nested comparators";
        local_counts.passed_checks++;
        copies = counted_copies;

        t.expect (eq (copies, 0)) << "nested comparators not copied";
        local_counts.passed_checks++;

        // A comparator that outlives the statement owns its temporary
        // operands; `counted` has no move constructor, so the temporary
        // is copied, once.
        counted_copies = 0;
        const auto stored = eq (counted{ 1 }, b);
        copies = counted_copies;

        t.expect (stored) << "stored comparator";
        local_counts.passed_checks++;

        t.expect (eq (copies, 1)) << "temporary operand stored once";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });
  } };

// ----------------------------------------------------------------------------
