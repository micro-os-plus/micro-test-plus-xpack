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

#ifndef MICRO_TEST_PLUS_TEST_REPORTER_INLINES_H_
#define MICRO_TEST_PLUS_TEST_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <cstring>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  template <typename T>
  test_reporter&
  test_reporter::operator<< (T* v)
  {
    char buff[20];
    snprintf (buff, sizeof (buff), "%p", reinterpret_cast<void*> (v));
    out_.append (buff);

    return *this;
  }

#if 0
  template <class T>
  test_reporter&
  test_reporter::operator<< (const T& t)
  {
    *this << detail::get (t);
    return *this;
  }
#endif

  template <class T>
  test_reporter&
  test_reporter::operator<< (const type_traits::genuine_integral_value<T>& v)
  {
    out_.append (std::to_string (static_cast<long long> (v.get ())));
    return *this;
  }

  template <class T,
            type_traits::requires_t<type_traits::is_container_v<T>
                                    and not type_traits::has_npos_v<T>>>
  test_reporter&
  test_reporter::operator<< (T&& t)
  {
    *this << '{';
    auto first = true;
    for (const auto& arg : t)
      {
        *this << (first ? "" : ", ") << arg;
        first = false;
      }
    *this << '}';
    return *this;
  }

  template <class Lhs_T, class Rhs_T>
  test_reporter&
  test_reporter::operator<< (const detail::eq_<Lhs_T, Rhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " == " << op.rhs ()
                  << colors_.none);
  }

  template <class Lhs_T, class Rhs_T>
  test_reporter&
  test_reporter::operator<< (const detail::ne_<Lhs_T, Rhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " != " << op.rhs ()
                  << colors_.none);
  }

  template <class Lhs_T, class Rhs_T>
  test_reporter&
  test_reporter::operator<< (const detail::gt_<Lhs_T, Rhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " > " << op.rhs ()
                  << colors_.none);
  }

  template <class Lhs_T, class Rhs_T>
  test_reporter&
  test_reporter::operator<< (const detail::ge_<Lhs_T, Rhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " >= " << op.rhs ()
                  << colors_.none);
  }

  template <class Lhs_T, class Rhs_T>
  test_reporter&
  test_reporter::operator<< (const detail::lt_<Rhs_T, Lhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " < " << op.rhs ()
                  << colors_.none);
  }

  template <class Lhs_T, class Rhs_T>
  test_reporter&
  test_reporter::operator<< (const detail::le_<Rhs_T, Lhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " <= " << op.rhs ()
                  << colors_.none);
  }

  template <class Lhs_T, class Rhs_T>
  test_reporter&
  test_reporter::operator<< (const detail::and_<Lhs_T, Rhs_T>& op)
  {
    return (*this << '(' << op.lhs () << color (op) << " and " << colors_.none
                  << op.rhs () << ')');
  }

  template <class Lhs_T, class Rhs_T>
  test_reporter&
  test_reporter::operator<< (const detail::or_<Lhs_T, Rhs_T>& op)
  {
    return (*this << '(' << op.lhs () << color (op) << " or " << colors_.none
                  << op.rhs () << ')');
  }

  template <class T>
  test_reporter&
  test_reporter::operator<< (const detail::not_<T>& op)
  {
    return (*this << color (op) << "not " << op.value () << colors_.none);
  }

#if defined(__cpp_exceptions)
  template <class Expr_T, class Exception_T>
  test_reporter&
  test_reporter::operator<< (const detail::throws_<Expr_T, Exception_T>& op)
  {
    return (*this << color (op) << "throws<"
                  << reflection::type_name<Exception_T> () << ">"
                  << colors_.none);
  }

  template <class Expr_T>
  test_reporter&
  test_reporter::operator<< (const detail::throws_<Expr_T, void>& op)
  {
    return (*this << color (op) << "throws" << colors_.none);
  }

  template <class Expr_T>
  test_reporter&
  test_reporter::operator<< (const detail::nothrow_<Expr_T>& op)
  {
    return (*this << color (op) << "nothrow" << colors_.none);
  }
#endif

  template <class Expr_T>
  void
  test_reporter::pass (Expr_T& expr, std::string& message)
  {
    output_pass_prefix_ (message);

    if (message.empty ())
      {
        // If there is no message, display the evaluated expression.
        *this << expr;
      }

    output_pass_suffix_ ();
  }

  template <class Expr_T>
  void
  test_reporter::fail (Expr_T& expr, bool abort, std::string& message,
                       const reflection::source_location& location)
  {
    output_fail_prefix_ (message, location);

    if constexpr (type_traits::is_op_v<Expr_T>)
      {
        *this << ", " << expr;
      }

    output_fail_suffix_ (abort);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------
