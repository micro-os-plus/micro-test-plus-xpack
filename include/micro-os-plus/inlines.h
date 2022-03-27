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

#ifndef MICRO_TEST_PLUS_INLINES_H_
#define MICRO_TEST_PLUS_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-c++17-compat-pedantic"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{

  template <class Callable_T>
  test_suite::test_suite (const char* name, Callable_T callable)
  {
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE

    name_ = name;
    callable_ = callable;

    runner.register_test_suite (this);
  }

  // --------------------------------------------------------------------------

  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& func, Args_T&&... arguments)
  {
#if 0 // defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE

    current_test_suite->begin_test_case (name);
    std::invoke (std::forward<Callable_T> (func),
                 std::forward<Args_T> (arguments)...);
    current_test_suite->end_test_case ();
  }

  // --------------------------------------------------------------------------
  namespace detail
  {
    // ------------------------------------------------------------------------

    template <class T>
    auto&
    deferred_reporter_base::operator<< (const T& msg)
    {
      if constexpr (std::is_arithmetic_v<T>)
        {
          message_.append (std::to_string (msg));
        }
      else
        {
          message_.append (msg);
        }
      return *this;
    }

    // ------------------------------------------------------------------------

    template <class Expr_T>
    constexpr deferred_reporter<Expr_T>::deferred_reporter (
        const Expr_T& expr, const reflection::source_location& location)
        : deferred_reporter_base{ static_cast<bool> (expr), location }, expr_{
            expr
          }
    {
    }

    template <class Expr_T>
    deferred_reporter<Expr_T>::~deferred_reporter ()
    {
      if (value_)
        {
          reporter.pass (expr_, message_);
        }
      else
        {
          reporter.fail (expr_, message_, location_);
        }
    }

    // ------------------------------------------------------------------------

    template <class Expr_T>
    constexpr deferred_reporter_abort<Expr_T>::deferred_reporter_abort (
        const Expr_T& expr, const reflection::source_location& location)
        : deferred_reporter<Expr_T>{ expr, location }
    {
      if (!deferred_reporter_base::value_)
        {
          reporter.fail (deferred_reporter<Expr_T>::expr_,
                         deferred_reporter_base::message_,
                         deferred_reporter_base::location_);
          abort ();
        }
    }

    template <class Expr_T>
    deferred_reporter_abort<Expr_T>::~deferred_reporter_abort ()
    {
      reporter.pass (deferred_reporter<Expr_T>::expr_,
                     deferred_reporter_base::message_);
    }

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
  namespace utility
  {
    template <class T = std::string_view, class Delim_T>
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>
    {
      std::vector<T> output{};
      std::size_t first{};
      while (first < std::size (input))
        {
          const auto second = input.find_first_of (delim, first);
          if (first != second)
            {
              output.emplace_back (input.substr (first, second - first));
            }
          if (second == T::npos)
            {
              break;
            }
          first = second + 1;
        }
      return output;
    }
  } // namespace utility

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_INLINES_H_

// ----------------------------------------------------------------------------
