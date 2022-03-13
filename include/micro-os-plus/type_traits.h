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

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-unnamed-type-template-args"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{

  /**
   * @brief Local type traits. Some may have standard equivalents, but
   * better keep them locally.
   */
  namespace type_traits
  {
    template <class...>
    struct list
    {
    };

    template <class T, class...>
    struct identity
    {
      using type = T;
    };

    template <class T>
    struct function_traits : function_traits<decltype (&T::operator())>
    {
    };

    template <class R, class... Args_T>
    struct function_traits<R (*) (Args_T...)>
    {
      using result_type = R;
      using args = list<Args_T...>;
    };

    template <class R, class... Args_T>
    struct function_traits<R (Args_T...)>
    {
      using result_type = R;
      using args = list<Args_T...>;
    };

    template <class R, class T, class... Args_T>
    struct function_traits<R (T::*) (Args_T...)>
    {
      using result_type = R;
      using args = list<Args_T...>;
    };

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
    static constexpr auto is_container_v
        = is_valid<T> ([] (auto t) -> decltype (t.begin (), t.end (),
                                                void ()) {});

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
    static constexpr auto is_convertible_v = __is_convertible_to(From, To);
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

    template <bool>
    struct requires_
    {
    };
    template <>

    struct requires_<true>
    {
      using type = int;
    };

    template <bool Cond>
    using requires_t = typename requires_<Cond>::type;
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
