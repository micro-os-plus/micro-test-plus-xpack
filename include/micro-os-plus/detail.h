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

#ifndef MICRO_TEST_PLUS_DETAIL_H_
#define MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
//#pragma clang diagnostic ignored "-Wc++98-c++11-compat"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @brief Implementation details, not part of the public API.
   */
  namespace detail
  {
    /**
     * @brief An object used to pass assertion parameters to the evaluator.
     */
    template <class Expr_T>
    struct assertion
    {
      Expr_T expr{};
      bool abort; // True if called from assume(), false from expect()
      const char* message;
      reflection::source_location location{};
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Generic getter implementation. If the type has
     * a get() method, call it. It is recommended for custom types
     * to define a get() method.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    get_impl (const T& t, int) -> decltype (t.get ())
    {
      return t.get ();
    }

    /**
     * @brief Variadic getter implementation that returns the
     * first argument and discards the rest.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    get_impl (const T& t, ...) -> decltype (auto)
    {
      return t;
    }

    /**
     * @brief Generic getter, calling the getter implementation.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    get (const T& t)
    {
      return get_impl (t, 0);
    }

    // ------------------------------------------------------------------------

    /**
     * @brief Equality comparator.
     */
    template <class Lhs_T, class Rhs_T>
    struct eq_ : type_traits::op
    {
      constexpr eq_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ [&] {
              using std::operator==;
              using std::operator<;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
              if constexpr (type_traits::has_value_v<
                                Lhs_T> and type_traits::has_value_v<Rhs_T>)
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "value == value");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // If both types have values (like numeric constants),
                  // compare them directly.
                  return Lhs_T::value == Rhs_T::value;
                }
              else if constexpr (
                  type_traits::has_epsilon_v<
                      Lhs_T> and type_traits::has_epsilon_v<Rhs_T>)
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "abs < min epsilon LR");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // If both values have precision, compare them using
                  // the smalles precision.
                  return math::abs (get (lhs) - get (rhs))
                         < math::min_value (Lhs_T::epsilon, Rhs_T::epsilon);
                }
              else if constexpr (type_traits::has_epsilon_v<Lhs_T>)
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "abs < epsilon L");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // If only the left operand has precision, use it.
                  return math::abs (get (lhs) - get (rhs)) < Lhs_T::epsilon;
                }
              else if constexpr (type_traits::has_epsilon_v<Rhs_T>)
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "abs < epsilon R");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // If only the right operand has precision, use it.
                  return math::abs (get (lhs) - get (rhs)) < Rhs_T::epsilon;
                }
              else
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "get() == get()");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // Call the generic getters, which might
                  // either call the type get() or return the value.
                  return get (lhs) == get (rhs);
                }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }

      [[nodiscard]] constexpr auto
      lhs () const
      {
        return get (lhs_);
      }

      [[nodiscard]] constexpr auto
      rhs () const
      {
        return get (rhs_);
      }

      const Lhs_T lhs_{};
      const Rhs_T rhs_{};
      const bool value_{};
    };

    /**
     * @brief Non-equality comparator.
     */
    template <class Lhs_T, class Rhs_T>
    struct ne_ : type_traits::op
    {
      constexpr ne_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ [&] {
              using std::operator==;
              using std::operator!=;
              using std::operator>;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
              if constexpr (type_traits::has_value_v<
                                Lhs_T> and type_traits::has_value_v<Rhs_T>)
                {
                  return Lhs_T::value != Rhs_T::value;
                }
              else if constexpr (
                  type_traits::has_epsilon_v<
                      Lhs_T> and type_traits::has_epsilon_v<Rhs_T>)
                {
                  return math::abs (get (lhs_) - get (rhs_))
                         > math::min_value (Lhs_T::epsilon, Rhs_T::epsilon);
                }
              else if constexpr (type_traits::has_epsilon_v<Lhs_T>)
                {
                  return math::abs (get (lhs_) - get (rhs_)) > Lhs_T::epsilon;
                }
              else if constexpr (type_traits::has_epsilon_v<Rhs_T>)
                {
                  return math::abs (get (lhs_) - get (rhs_)) > Rhs_T::epsilon;
                }
              else
                {
                  return get (lhs_) != get (rhs_);
                }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }
      [[nodiscard]] constexpr auto
      lhs () const
      {
        return get (lhs_);
      }
      [[nodiscard]] constexpr auto
      rhs () const
      {
        return get (rhs_);
      }

      const Lhs_T lhs_{};
      const Rhs_T rhs_{};
      const bool value_{};
    };

    /**
     * @brief Greater than comparator.
     */
    template <class Lhs_T, class Rhs_T>
    struct gt_ : type_traits::op
    {
      constexpr gt_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ [&] {
              using std::operator>;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
              if constexpr (type_traits::has_value_v<
                                Lhs_T> and type_traits::has_value_v<Rhs_T>)
                {
                  return Lhs_T::value > Rhs_T::value;
                }
              else
                {
                  return get (lhs_) > get (rhs_);
                }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }
      [[nodiscard]] constexpr auto
      lhs () const
      {
        return get (lhs_);
      }
      [[nodiscard]] constexpr auto
      rhs () const
      {
        return get (rhs_);
      }

      const Lhs_T lhs_{};
      const Rhs_T rhs_{};
      const bool value_{};
    };

    /**
     * @brief Greater than or equal comparator.
     */
    template <class Lhs_T, class Rhs_T>
    struct ge_ : type_traits::op
    {
      constexpr ge_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ [&] {
              using std::operator>=;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
              if constexpr (type_traits::has_value_v<
                                Lhs_T> and type_traits::has_value_v<Rhs_T>)
                {
                  return Lhs_T::value >= Rhs_T::value;
                }
              else
                {
                  return get (lhs_) >= get (rhs_);
                }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }
      [[nodiscard]] constexpr auto
      lhs () const
      {
        return get (lhs_);
      }
      [[nodiscard]] constexpr auto
      rhs () const
      {
        return get (rhs_);
      }

      const Lhs_T lhs_{};
      const Rhs_T rhs_{};
      const bool value_{};
    };

    /**
     * @brief Less than comparator.
     */
    template <class Lhs_T, class Rhs_T>
    struct lt_ : type_traits::op
    {
      constexpr lt_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ [&] {
              using std::operator<;

#if defined(__GNUC__)
#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
              if constexpr (type_traits::has_value_v<
                                Lhs_T> and type_traits::has_value_v<Rhs_T>)
                {
                  return Lhs_T::value < Rhs_T::value;
                }
              else
                {
                  return get (lhs_) < get (rhs_);
                }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }
      [[nodiscard]] constexpr auto
      lhs () const
      {
        return get (lhs_);
      }
      [[nodiscard]] constexpr auto
      rhs () const
      {
        return get (rhs_);
      }

    private:
      const Lhs_T lhs_{};
      const Rhs_T rhs_{};
      const bool value_{};
    };

    /**
     * @brief Less than or equal comparator.
     */
    template <class Lhs_T, class Rhs_T>
    struct le_ : type_traits::op
    {
      constexpr le_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ [&] {
              using std::operator<=;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#endif
              if constexpr (type_traits::has_value_v<
                                Lhs_T> and type_traits::has_value_v<Rhs_T>)
                {
                  return Lhs_T::value <= Rhs_T::value;
                }
              else
                {
                  return get (lhs_) <= get (rhs_);
                }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }

      [[nodiscard]] constexpr auto
      lhs () const
      {
        return get (lhs_);
      }

      [[nodiscard]] constexpr auto
      rhs () const
      {
        return get (rhs_);
      }

      const Lhs_T lhs_{};
      const Rhs_T rhs_{};
      const bool value_{};
    };

    /**
     * @brief Logical and operator.
     */
    template <class Lhs_T, class Rhs_T>
    struct and_ : type_traits::op
    {
      constexpr and_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ static_cast<bool> (lhs)
                                              and static_cast<bool> (rhs) }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }

      [[nodiscard]] constexpr auto
      lhs () const
      {
        return get (lhs_);
      }

      [[nodiscard]] constexpr auto
      rhs () const
      {
        return get (rhs_);
      }

      const Lhs_T lhs_{};
      const Rhs_T rhs_{};
      const bool value_{};
    };

    /**
     * @brief Logical or operator.
     */
    template <class Lhs_T, class Rhs_T>
    struct or_ : type_traits::op
    {
      constexpr or_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ static_cast<bool> (lhs)
                                              or static_cast<bool> (rhs) }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }
      [[nodiscard]] constexpr auto
      lhs () const
      {
        return get (lhs_);
      }
      [[nodiscard]] constexpr auto
      rhs () const
      {
        return get (rhs_);
      }

      const Lhs_T lhs_{};
      const Rhs_T rhs_{};
      const bool value_{};
    };

    /**
     * @brief Logical not operator.
     */
    template <class T>
    struct not_ : type_traits::op
    {
      explicit constexpr not_ (const T& t = {})
          : t_{ t }, value_{ not static_cast<bool> (t) }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }
      [[nodiscard]] constexpr auto
      value () const
      {
        return get (t_);
      }

      const T t_{};
      const bool value_{};
    };

#if defined(__cpp_exceptions)
    /**
     * @brief Operator to check if the expression throws a specific exception.
     */
    template <class Callable_T, class Exception_T = void>
    struct throws_ : type_traits::op
    {
      constexpr explicit throws_ (const Callable_T& func)
          : value_{ [&func] {
              try
                {
                  func ();
                }
              catch (const Exception_T&)
                {
                  return true;
                }
              catch (...)
                {
                  return false;
                }
              return false;
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }

      const bool value_{};
    };

    /**
     * @brief Operator to check if the expression throws any exception.
     */
    template <class Callable_T>
    struct throws_<Callable_T, void> : type_traits::op
    {
      constexpr explicit throws_ (const Callable_T& func)
          : value_{ [&func] {
              try
                {
                  func ();
                }
              catch (...)
                {
                  return true;
                }
              return false;
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }

      const bool value_{};
    };

    /**
     * @brief Operator to check if the expression does not throw any exception.
     */
    template <class Callable_T>
    struct nothrow_ : type_traits::op
    {
      constexpr explicit nothrow_ (const Callable_T& func)
          : value_{ [&func] {
              try
                {
                  func ();
                }
              catch (...)
                {
                  return false;
                }
              return true;
            }() }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }

      const bool value_{};
    };
#endif

    template <class Expr_T>
    [[nodiscard]] bool
    evaluate_and_report_ (detail::assertion<Expr_T> assertion);

    // ----------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_DETAIL_H_

// ----------------------------------------------------------------------------
