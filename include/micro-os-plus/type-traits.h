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

#ifndef MICRO_TEST_PLUS_TYPE_TRAITS_H_
#define MICRO_TEST_PLUS_TYPE_TRAITS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include "math.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @brief Local type traits. Some may have standard equivalents, but
   * better keep them locally.
   */
  namespace type_traits
  {
    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class...>
    struct list
    {
    };

    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T, class...>
    struct identity
    {
      using type = T;
    };

#if defined(__DOXYGEN__)
    // error: Detected potential recursive class relation between class
    // micro_os_plus::micro_test_plus::type_traits::function_traits and base
    // class micro_os_plus::micro_test_plus::type_traits::function_traits<
    // decltype(&T::operator())>!
    // https://github.com/doxygen/doxygen/issues/9915
#else
    template <class T>
    struct function_traits : function_traits<decltype (&T::operator())>
    {
    };
#endif

    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class R, class... Args_T>
    struct function_traits<R (*) (Args_T...)>
    {
      using result_type = R;
      using args = list<Args_T...>;
    };

    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class R, class... Args_T>
    struct function_traits<R (Args_T...)>
    {
      using result_type = R;
      using args = list<Args_T...>;
    };

    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...)>
    {
      using result_type = R;
      using args = list<Args_T...>;
    };

    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...) const>
    {
      using result_type = R;
      using args = list<Args_T...>;
    };

    template <class T>
    T&&
    declval ();
    template <class... Ts, class Expr_T>
    constexpr auto
    is_valid (Expr_T expr) -> decltype (expr (declval<Ts...> ()), bool ())
    {
      return true;
    }

    template <class...>
    constexpr auto
    is_valid (...) -> bool
    {
      return false;
    }

    template <class T>
    static constexpr auto is_container_v = is_valid<T> (
        [] (auto t) -> decltype (t.begin (), t.end (), void ()) {});

    template <class T>
    static constexpr auto has_npos_v
        = is_valid<T> ([] (auto t) -> decltype (void (t.npos)) {});

    template <class T>
    static constexpr auto has_value_v
        = is_valid<T> ([] (auto t) -> decltype (void (t.value)) {});

    template <class T>
    static constexpr auto has_epsilon_v
        = is_valid<T> ([] (auto t) -> decltype (void (t.epsilon)) {});

    template <class T>
    inline constexpr auto is_floating_point_v = false;
    template <>
    inline constexpr auto is_floating_point_v<float> = true;
    template <>
    inline constexpr auto is_floating_point_v<double> = true;
    template <>
    inline constexpr auto is_floating_point_v<long double> = true;

#if defined(__clang__) or defined(_MSC_VER)
    template <class From, class To>
    static constexpr auto is_convertible_v = __is_convertible_to (From, To);
#else
    template <class From, class To>
    constexpr auto
    is_convertible (int) -> decltype (bool (To (declval<From> ())))
    {
      return true;
    }
    template <class...>
    constexpr auto
    is_convertible (...)
    {
      return false;
    }
    template <class From, class To>
    constexpr auto is_convertible_v = is_convertible<From, To> (0);
#endif

    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <bool>
    struct requires_
    {
    };

    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <>
    struct requires_<true>
    {
      using type = int;
    };

    template <bool Cond>
    using requires_t = typename requires_<Cond>::type;

    /**
     * @brief Empty base class of all operators.
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    struct op
    {
    };

    /**
     * @brief A generic integral constant.
     * It has a getter and a '-' operator to return the negative value.
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <auto N>
    struct integral_constant : op
    {
      using value_type = decltype (N);
      static constexpr auto value = N;

      [[nodiscard]] constexpr auto
      operator- () const
      {
        return integral_constant<-N>{};
      }

      [[nodiscard]] constexpr explicit
      operator value_type () const
      {
        return N;
      }

      [[nodiscard]] constexpr auto
      get () const
      {
        return N;
      }
    };

    /**
     * @brief A generic floating point constant, with custom size
     * and precision.
     * It has a getter and a '-' operator to return the negative value.
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T, auto N, auto D, auto Size, auto P = 1>
    struct floating_point_constant : op
    {
      using value_type = T;

      static constexpr auto epsilon = T (1) / math::pow (T (10), Size - 1);
      static constexpr auto value
          = T (P) * (T (N) + (T (D) / math::pow (T (10), Size)));

      [[nodiscard]] constexpr auto
      operator- () const
      {
        return floating_point_constant<T, N, D, Size, -1>{};
      }

      [[nodiscard]] constexpr explicit
      operator value_type () const
      {
        return value;
      }

      [[nodiscard]] constexpr auto
      get () const
      {
        return value;
      }
    };

    /**
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct genuine_integral_value : op
    {
      using value_type = T;

      constexpr genuine_integral_value (const T& _value) : value_{ _value }
      {
      }

      [[nodiscard]] constexpr explicit
      operator T () const
      {
        return value_;
      }

      [[nodiscard]] constexpr decltype (auto)
      get () const
      {
        return value_;
      }

      T value_{};
    };

    template <class T>
    inline constexpr auto is_op_v = __is_base_of (type_traits::op, T);

    /**
     * @brief Class defining a generic value, accessible via a getter.
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T, class = int>
    struct value : type_traits::op
    {
      using value_type = T;

      constexpr value (const T& _value) : value_{ _value }
      {
      }

      [[nodiscard]] constexpr explicit
      operator T () const
      {
        return value_;
      }

      [[nodiscard]] constexpr decltype (auto)
      get () const
      {
        return value_;
      }

      T value_{};
    };

    /**
     * @brief A generic value used to define floating points, which,
     * in addition to the actual value, has an epsilon, to use the
     * desired precision during comparisons.
     * If missing, the default is 1 / (10^decimals).
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class T>
    struct value<T,
                 type_traits::requires_t<type_traits::is_floating_point_v<T>>>
        : type_traits::op
    {
      using value_type = T;
      static inline auto epsilon = T{}; // Why static?

      constexpr value (const T& _value, const T precision) : value_{ _value }
      {
        epsilon = precision;
      }

      constexpr /*explicit(false)*/ value (const T& val)
          : value{ val,
                   T (1)
                       / math::pow (T (10),
                                    math::den_size<unsigned long long> (val)) }
      {
      }

      [[nodiscard]] constexpr explicit
      operator T () const
      {
        return value_;
      }

      [[nodiscard]] constexpr decltype (auto)
      get () const
      {
        return value_;
      }

      T value_{};
    };

  } // namespace type_traits

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TYPE_TRAITS_H_

// ----------------------------------------------------------------------------
