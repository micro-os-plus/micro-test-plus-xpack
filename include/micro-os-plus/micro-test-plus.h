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

#ifndef MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_
#define MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#if defined(MICRO_OS_PLUS_TRACE)
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_TRACE

#if defined(MICRO_OS_PLUS_DEBUG)
#define MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
#endif

#include <array>
#include <type_traits>
#include <functional>
// #include <utility>
#include <vector>
#include <cstdlib>
#include <string_view>
// #include <iostream>

#include <stdio.h>
#include <cstring>
//#include <string.h>

#if defined(__cpp_lib_source_location)
#include <source_location>
#endif

#include "reflection.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
// warning: deleted function definitions are incompatible with C++98
// [-Wc++98-compat]
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  class test_runner;
  class test_reporter;
  class test_suite;

  extern test_runner runner;
  extern test_reporter reporter;
  extern test_suite* current_test_suite;

  // --------------------------------------------------------------------------
  // Public API.

  /**
   * @brief Initialize the test framework.
   */
  void
  initialize (const char* name, int argc, char* argv[]);

  /**
   * @brief Define a test case.
   */
  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& func, Args_T&&... arguments);

  [[nodiscard]] int
  exit_code (void);

  // --------------------------------------------------------------------------

  /**
   * @brief A named group of test cases which self registers to the runner.
   */
  class test_suite
  {
  public:
    /**
     * @brief Construct the default suite used in main().
     */
    test_suite (const char* name);

    /**
     * @brief Construct a suite in a separate compile unit, usually with
     * a lambda.
     */
    template <class Callable_T>
    test_suite (const char* name, Callable_T callable);

    /**
     * @brief Run the sequence of test cases in the suite.
     */
    void
    run ();

    /**
     * @brief Mark the begining of a named test case.
     */
    void
    begin_test_case (const char* name);

    /**
     * @brief Mark the end of a test case.
     */
    void
    end_test_case ();

    /**
     * @brief Get the suite name.
     */
    [[nodiscard]] constexpr const char*
    name ()
    {
      return name_;
    }

    /**
     * @brief Count one more passed test condition.
     */
    constexpr void
    increment_passed (void)
    {
      ++passed_;
    }

    /**
     * @brief Count one more failed test condition.
     */
    constexpr void
    increment_failed (void)
    {
      ++failed_;
    }

    /**
     * @brief Get the number of passed conditions.
     */
    constexpr int
    passed (void)
    {
      return passed_;
    }

    /**
     * @brief Get the number of failed conditions.
     */
    constexpr int
    failed (void)
    {
      return failed_;
    }

    /**
     * @brief Get the number of test cases.
     */
    constexpr int
    test_cases (void)
    {
      return test_cases_;
    }

    /**
     * @brief Begin the execution of the test suite.
     */
    void
    begin (void);

    /**
     * @brief Mark the end of the test suite.
     */
    void
    end (void);

    /**
     * @brief Get the test suite result.
     */
    [[nodiscard]] constexpr bool
    success (void)
    {
      // Also fail if none passed.
      return (failed_ == 0 && passed_ != 0);
    }

  private:
    /**
     * @brief The test suite name.
     */
    const char* name_;

    /**
     * @brief The current test case name.
     */
    const char* test_case_name_;

    /**
     * @brief The functions/lambda to perform the tests.
     */
    std::function<void ()> callable_ = nullptr;

    /**
     * @brief Count of passed test conditions.
     */
    int passed_ = 0;

    /**
     * @brief Count of failed test conditions.
     */
    int failed_ = 0;

    /**
     * @brief Count of test cases in the test suite.
     */
    int test_cases_ = 0;
  };

  // --------------------------------------------------------------------------

  /**
   * @brief The test runner. It maintaines a list of test suites which
   * automatically register themselves in their constructors.
   */
  class test_runner
  {
  public:
    test_runner ();

    // The rule of five.
    test_runner (const test_runner&) = delete;
    test_runner (test_runner&&) = delete;
    test_runner&
    operator= (const test_runner&)
        = delete;
    test_runner&
    operator= (test_runner&&)
        = delete;

    ~test_runner () = default;

    /**
     * @brief Pass the main arguments explicitly, if the default
     * contructor was used.
     */
    void
    initialize (const char* name, int argc, char* argv[]);

    /**
     * @brief Return 0 if the all tests were successful, 1 otherwise.
     */
    int
    exit_code (void);

    /**
     * @brief Called by test suite constructors to register them
     * to the runner.
     */
    void
    register_test_suite (test_suite* suite);

    constexpr const char*
    name (void)
    {
      return default_suite_name_;
    }

    [[noreturn]] void
    abort (void);

  protected:
    int argc_ = 0;
    char** argv_ = nullptr;

    const char* default_suite_name_ = "Test";

    /**
     * @brief Pointer to the default test suite which groups
     * the main tests.
     */
    test_suite* default_test_suite_;

    /**
     * @brief Pointer to array of registered test suites.
     * Statically initialised to zero as BSS, such that
     * test suites defined as static objects in different
     * compilation units can  be automatically executed.
     */
    std::vector<test_suite*>* suites_;
  };

  // ==========================================================================

  /**
   * @brief Local mathematical functions.
   *
   * Some may have equivalents in the standard library, but may be
   * more complicated to use, or have only floating point variants, or
   * not be constexpr.
   */
  namespace math
  {
    /**
     * @brief Generic absolute of any value.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    abs (const T t) -> T
    {
      return t < T{} ? -t : t;
    }

    /**
     * @brief Generic minimum of two values.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    min_value (const T& lhs, const T& rhs) -> const T&
    {
      return (rhs < lhs) ? rhs : lhs;
    }

    /**
     * @brief Generic 'power of', to raise base to exponent (base ^ exp).
     */
    template <class T, class Exp_T>
    [[nodiscard]] constexpr auto
    pow (const T base, const Exp_T exp) -> T
    {
      // If the exponent is 0, return 1, otherwise recurse.
      return exp ? T (base * pow (base, exp - Exp_T (1))) : T (1);
    }

    /**
     * @brief Compute the integral value of a number represented as
     * an array of characters.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    num () -> T
    {
      // Assume all are digits or dot or apostrophe.
      static_assert (
          ((Cs == '.' or Cs == '\'' or (Cs >= '0' and Cs <= '9')) and ...));
      T result{};
      for (const char c : { Cs... })
        {
          if (c == '.')
            {
              break;
            }
          if (c >= '0' and c <= '9')
            {
              result = result * T (10) + T (c - '0');
            }
        }
      return result;
    }

    /**
     * @brief Compute the decimals of a number represented as
     * an array of characters.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    den () -> T
    {
      constexpr const std::array cs{ Cs... };
      T result{};
      auto i = 0u;
      while (cs[i++] != '.')
        {
        }

      for (auto j = i; j < sizeof...(Cs); ++j)
        {
          result += pow (T (10), sizeof...(Cs) - j) * T (cs[j] - '0');
        }
      return result;
    }

    /**
     * @brief Compute the number of decimal places of a number represented as
     * an array of characters.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    den_size () -> T
    {
      constexpr const std::array cs{ Cs... };
      T i{};
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
      while (cs[i++] != '.')
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
        {
        }

      return T (sizeof...(Cs)) - i + T (1);
    }

    /**
     * @brief Compute the number of decimal places of a value,
     * up to 7 digits.
     */
    template <class T, class Value_T>
    [[nodiscard]] constexpr auto
    den_size (Value_T value) -> T
    {
      constexpr auto precision = Value_T (1e-7);
      T result{};
      Value_T tmp{};
      do
        {
          value *= 10;
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Warith-conversion"
#else
#pragma GCC diagnostic ignored "-Wimplicit-int-float-conversion"
#endif
#endif
          tmp = value - T (value);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
          ++result;
        }
      while (tmp > precision);

      return result;
    }

  } // namespace math

  // --------------------------------------------------------------------------

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

  struct none
  {
  };

  /**
   * @brief Implementation details, not part of the public API.
   */
  namespace detail
  {
    template <class Expr_T>
    struct assertion
    {
      Expr_T expr{};
      bool abort; // True if called from assume(), false from expect()
      const char* message;
      reflection::source_location location{};
    };

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

    /**
     * @brief Empty base class of all operators.
     */
    struct op
    {
    };

    /**
     * @brief Class defining an internal type.
     * It has == and != operators to check if the type is the same
     * with other types.
     */
    template <class T>
    struct type_ : op
    {
      template <class TOther>
      [[nodiscard]] constexpr auto
      operator() (const TOther&) const -> const type_<TOther>
      {
        return {};
      }

      [[nodiscard]] constexpr auto
      operator== (type_<T>) -> bool
      {
        return true;
      }

      template <class TOther>
      [[nodiscard]] constexpr auto
      operator== (type_<TOther>) -> bool
      {
        return false;
      }

      template <class TOther>
      [[nodiscard]] constexpr auto
      operator== (const TOther&) -> bool
      {
        return std::is_same_v<TOther, T>;
      }

      [[nodiscard]] constexpr auto
      operator!= (type_<T>) -> bool
      {
        return true;
      }

      template <class TOther>
      [[nodiscard]] constexpr auto
      operator!= (type_<TOther>) -> bool
      {
        return true;
      }

      template <class TOther>
      [[nodiscard]] constexpr auto
      operator!= (const TOther&) -> bool
      {
        return not std::is_same_v<TOther, T>;
      }
    };

    /**
     * @brief Class defining a generic value, accessible via a getter.
     */
    template <class T, class = int>
    struct value : op
    {
      using value_type = T;

      constexpr value (const T& _value) : value_{ _value }
      {
      }

      [[nodiscard]] constexpr explicit operator T () const
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
     */
    template <class T>
    struct value<T,
                 type_traits::requires_t<type_traits::is_floating_point_v<T>>>
        : op
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

      [[nodiscard]] constexpr explicit operator T () const
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
     * @brief A generic integral constant.
     * It has a getter and a '-' operator to return the negative value.
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

      [[nodiscard]] constexpr explicit operator value_type () const
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

      [[nodiscard]] constexpr explicit operator value_type () const
      {
        return value;
      }

      [[nodiscard]] constexpr auto
      get () const
      {
        return value;
      }
    };

    template <class T>
    struct genuine_integral_value : op
    {
      using value_type = T;

      constexpr genuine_integral_value (const T& _value) : value_{ _value }
      {
      }

      [[nodiscard]] constexpr explicit operator T () const
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

    // ------------------------------------------------------------------------

    /**
     * @brief Equality comparator.
     */
    template <class Lhs_T, class Rhs_T>
    struct eq_ : op
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
    struct ne_ : op
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
    struct gt_ : op
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
    struct ge_ : op
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
    struct lt_ : op
    {
      constexpr lt_ (const Lhs_T& lhs = {}, const Rhs_T& rhs = {})
          : lhs_{ lhs }, rhs_{ rhs }, value_{ [&] {
              using std::operator<;

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
    struct le_ : op
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
    struct and_ : op
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
    struct or_ : op
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
    struct not_ : op
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
     * @brief Operator to check if expression throws a specific exception.
     */
    template <class Expr_T, class Exception_T = void>
    struct throws_ : op
    {
      constexpr explicit throws_ (const Expr_T& expr)
          : value_{ [&expr] {
              try
                {
                  expr ();
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
     * @brief Operator to check if expression throws any exception.
     */
    template <class Expr_T>
    struct throws_<Expr_T, void> : op
    {
      constexpr explicit throws_ (const Expr_T& expr)
          : value_{ [&expr] {
              try
                {
                  expr ();
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
     * @brief Operator to check if expression does not throw any exception.
     */
    template <class Expr_T>
    struct nothrow_ : op
    {
      constexpr explicit nothrow_ (const Expr_T& expr)
          : value_{ [&expr] {
              try
                {
                  expr ();
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

  } // namespace detail

  // --------------------------------------------------------------------------

  struct colors
  {
    std::string_view none = "\033[0m";
    std::string_view pass = "\033[32m";
    std::string_view fail = "\033[31m";
  };

  test_reporter&
  endl (test_reporter& stream);

  // Requires events::assertion_* for  and detailed operators.

  /**
   * @brief Reporter to display the test results. For failed
   * tests it prints the actual values of the operands, with their types.
   */
  class test_reporter
  {
  public:
    test_reporter () = default;

    [[nodiscard]] inline auto
    color (const bool cond)
    {
      return cond ? colors_.pass : colors_.fail;
    }

    template <typename T>
    void
    print_expr (T expr);

    auto&
    operator<< (std::string_view sv)
    {
      printf ("%s", sv.data ());
      return *this;
    }

    auto&
    operator<< (char c)
    {
      printf ("%c", c);
      return *this;
    }

    auto&
    operator<< (const char* s)
    {
      printf ("%s", s);
      return *this;
    }

    auto&
    operator<< (char* s)
    {
      printf ("%s", s);
      return *this;
    }

    auto&
    operator<< (bool v)
    {
      printf ("%s", v ? "true_b" : "false_b");
      return *this;
    }

    auto&
    operator<< (std::nullptr_t)
    {
      printf ("nullptr");
      return *this;
    }

#if 1
    auto&
    operator<< (signed char c)
    {
      printf ("%d_sc", c);
      return *this;
    }

    auto&
    operator<< (unsigned char c)
    {
      printf ("%d_uc", c);
      return *this;
    }
#endif

    auto&
    operator<< (signed short c)
    {
      printf ("%d_s", c);
      return *this;
    }

    auto&
    operator<< (unsigned short c)
    {
      printf ("%u_us", c);
      return *this;
    }

    auto&
    operator<< (signed int v)
    {
      printf ("%d_i", v);
      return *this;
    }

    auto&
    operator<< (unsigned int v)
    {
      printf ("%u_u", v);
      return *this;
    }

    auto&
    operator<< (signed long v)
    {
      printf ("%ld_l", v);
      return *this;
    }

    auto&
    operator<< (unsigned long v)
    {
      printf ("%lu_ul", v);
      return *this;
    }

    auto&
    operator<< (signed long long v)
    {
      printf ("%lld_ll", v);
      return *this;
    }

    auto&
    operator<< (unsigned long long v)
    {
      printf ("%llu_ull", v);
      return *this;
    }

    auto&
    operator<< (float v)
    {
      printf ("%f_f", static_cast<double> (v));
      return *this;
    }

    auto&
    operator<< (double v)
    {
      printf ("%f_d", v);
      return *this;
    }

    auto&
    operator<< (long double v)
    {
      printf ("%Lf_ld", v);
      return *this;
    }

    /**
     * @brief Output operator to display any pointer.
     */
    template <typename T>
    auto&
    operator<< (T* v)
    {
      printf ("%p", reinterpret_cast<void*> (v));
      return *this;
    }

    /**
     * @brief Output operator to display the endl.
     */
    auto&
    operator<< (test_reporter& (*func) (test_reporter&))
    {
      // Call the endl function.
      (*func) (*this);
      return *this;
    }

    // ------------------------------------------------------------------------
    // Specific operators.

    /**
     * @brief Output operator to types with a getter.
     */
    template <class T>
    auto&
    operator<< (const T& t)
    {
      *this << detail::get (t);
      return *this;
    }

    /**
     * @brief Output operator to display genuine integers,
     * without the type suffix.
     */
    template <class T>
    auto&
    operator<< (const detail::genuine_integral_value<T>& v)
    {
      printf ("%lld", static_cast<long long> (v.get ()));
      return *this;
    }

    /**
     * @brief Output operator to display containers. Iterate all members.
     */
    template <class T, type_traits::requires_t<
                           type_traits::is_container_v<
                               T> and not type_traits::has_npos_v<T>> = 0>
    auto&
    operator<< (T&& t)
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

    /**
     * @brief Output operator to display eq() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    auto&
    operator<< (const detail::eq_<Lhs_T, Rhs_T>& op)
    {
      return (*this << color (op) << op.lhs () << " == " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display ne() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    auto&
    operator<< (const detail::ne_<Lhs_T, Rhs_T>& op)
    {
      return (*this << color (op) << op.lhs () << " != " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display gt() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    auto&
    operator<< (const detail::gt_<Lhs_T, Rhs_T>& op)
    {
      return (*this << color (op) << op.lhs () << " > " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display ge() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    auto&
    operator<< (const detail::ge_<Lhs_T, Rhs_T>& op)
    {
      return (*this << color (op) << op.lhs () << " >= " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display lt() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    auto&
    operator<< (const detail::lt_<Rhs_T, Lhs_T>& op)
    {
      return (*this << color (op) << op.lhs () << " < " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display le() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    auto&
    operator<< (const detail::le_<Rhs_T, Lhs_T>& op)
    {
      return (*this << color (op) << op.lhs () << " <= " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display and() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    auto&
    operator<< (const detail::and_<Lhs_T, Rhs_T>& op)
    {
      return (*this << '(' << op.lhs () << color (op) << " and "
                    << colors_.none << op.rhs () << ')');
    }

    /**
     * @brief Output operator to display or() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    auto&
    operator<< (const detail::or_<Lhs_T, Rhs_T>& op)
    {
      return (*this << '(' << op.lhs () << color (op) << " or " << colors_.none
                    << op.rhs () << ')');
    }

    /**
     * @brief Output operator to display not() expressions.
     */
    template <class T>
    auto&
    operator<< (const detail::not_<T>& op)
    {
      return (*this << color (op) << "not " << op.value () << colors_.none);
    }

#if defined(__cpp_exceptions)
    template <class Expr_T, class Exception_T>
    auto&
    operator<< (const detail::throws_<Expr_T, Exception_T>& op)
    {
      return (*this << color (op) << "throws<"
                    << reflection::type_name<Exception_T> () << ">"
                    << colors_.none);
    }

    template <class Expr_T>
    auto&
    operator<< (const detail::throws_<Expr_T, void>& op)
    {
      return (*this << color (op) << "throws" << colors_.none);
    }

    template <class Expr_T>
    auto&
    operator<< (const detail::nothrow_<Expr_T>& op)
    {
      return (*this << color (op) << "nothrow" << colors_.none);
    }
#endif

    // ------------------------------------------------------------------------

    /**
     * @brief Report a passed condition.
     */
    template <class Expr_T>
    auto
    pass (detail::assertion<Expr_T> assertion) -> void
    {
      *this << colors_.pass << "    ✓ ";
      if (strlen (assertion.message))
        {
          // If a non-empty message is provided, display it.
          *this << assertion.message;
        }
      else
        {
          // Otherwise display the evaluated expression.
          *this << assertion.expr;
        }
      *this << colors_.none;
      *this << endl;

      flush ();
      current_test_suite->increment_passed ();
    }

    /**
     * @brief Report a failed condition.
     */
    template <class Expr_T>
    auto
    fail (detail::assertion<Expr_T> assertion) -> void
    {
      *this << colors_.fail << "    ✗ ";
      if (strlen (assertion.message))
        {
          *this << assertion.message << " ";
        }
      *this << "FAILED";
      *this << colors_.none;
      *this << " (" << reflection::short_name (assertion.location.file_name ())
            << ":"
            << detail::genuine_integral_value{ assertion.location.line () };
      *this << ", " << assertion.expr;
      if (assertion.abort)
        {
          *this << ", aborted";
        }
      *this << ")";
      *this << endl;

      flush ();
      current_test_suite->increment_failed ();
    }

    /**
     * @brief Flush the current buffered content.
     */
    void
    flush (void);

  private:
    colors colors_{};
  };

  // --------------------------------------------------------------------------

  namespace detail
  {
    template <class Expr_T>
    [[nodiscard]] auto
    evaluate_and_report_ (detail::assertion<Expr_T> assertion) -> bool
    {
      // This cast calls the bool operator, which evaluates the expression.
      if (static_cast<bool> (assertion.expr))
        {
          reporter.pass (
              detail::assertion<Expr_T>{ .expr = assertion.expr,
                                         .abort = assertion.abort,
                                         .message = assertion.message,
                                         .location = assertion.location });
          return true;
        }

      reporter.fail (
          detail::assertion<Expr_T>{ .expr = assertion.expr,
                                     .abort = assertion.abort,
                                     .message = assertion.message,
                                     .location = assertion.location });
      if (assertion.abort)
        {
          current_test_suite->end ();
          runner.abort ();
        }
      return false;
    }

  } // namespace detail

  namespace type_traits
  {
    template <class T>
    inline constexpr auto is_op_v = __is_base_of(detail::op, T);
  } // namespace type_traits

  // --------------------------------------------------------------------------

  namespace literals
  {
    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i ()
    {
      return detail::integral_constant<math::num<int, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_s ()
    {
      return detail::integral_constant<math::num<short, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_c ()
    {
      return detail::integral_constant<math::num<char, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_sc ()
    {
      return detail::integral_constant<math::num<signed char, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_l ()
    {
      return detail::integral_constant<math::num<long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_ll ()
    {
      return detail::integral_constant<math::num<long long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u ()
    {
      return detail::integral_constant<math::num<unsigned, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_uc ()
    {
      return detail::integral_constant<math::num<unsigned char, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_us ()
    {
      return detail::integral_constant<math::num<unsigned short, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_ul ()
    {
      return detail::integral_constant<math::num<unsigned long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_ull ()
    {
      return detail::integral_constant<
          math::num<unsigned long long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i8 ()
    {
      return detail::integral_constant<math::num<std::int8_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i16 ()
    {
      return detail::integral_constant<math::num<std::int16_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i32 ()
    {
      return detail::integral_constant<math::num<std::int32_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_i64 ()
    {
      return detail::integral_constant<math::num<std::int64_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u8 ()
    {
      return detail::integral_constant<math::num<std::uint8_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u16 ()
    {
      return detail::integral_constant<math::num<std::uint16_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u32 ()
    {
      return detail::integral_constant<math::num<std::uint32_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_u64 ()
    {
      return detail::integral_constant<math::num<std::uint64_t, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_f ()
    {
      return detail::floating_point_constant<
          float, math::num<unsigned long, Cs...> (),
          math::den<unsigned long, Cs...> (),
          math::den_size<unsigned long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_d ()
    {
      return detail::floating_point_constant<
          double, math::num<unsigned long, Cs...> (),
          math::den<unsigned long, Cs...> (),
          math::den_size<unsigned long, Cs...> ()>{};
    }

    template <char... Cs>
    [[nodiscard]] constexpr auto operator""_ld ()
    {
      return detail::floating_point_constant<
          long double, math::num<unsigned long long, Cs...> (),
          math::den<unsigned long long, Cs...> (),
          math::den_size<unsigned long long, Cs...> ()>{};
    }

    constexpr auto operator""_b (const char* name, decltype (sizeof ("")) size)
    {
      struct named : std::string_view, detail::op
      {
        using value_type = bool;
        [[nodiscard]] constexpr operator value_type () const
        {
          return true;
        }

        [[nodiscard]] constexpr auto
        operator== (const named&) const
        {
          return true;
        }

        [[nodiscard]] constexpr auto
        operator== (const bool other) const
        {
          return other;
        }
      };

      return named{ { name, size }, {} };
    }
  } // namespace literals

  // --------------------------------------------------------------------------
  // Public API.

  template <class Expr_T = bool>
  constexpr auto
  pass (const char* message = "passed",
        const reflection::source_location& sl
        = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = true, .abort = false, .message = message, .location = sl });
  }

  template <class Expr_T = bool>
  constexpr auto
  fail (const char* message = "...", const reflection::source_location& sl
                                     = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = false, .abort = false, .message = message, .location = sl });
  }

  /**
   * @brief The generic evaluation function.
   */
  template <
      class Expr_T,
      type_traits::requires_t<
          type_traits::is_op_v<
              Expr_T> or type_traits::is_convertible_v<Expr_T, bool>> = 0>
  constexpr auto
  expect (const Expr_T& expr, const char* message = "",
          const reflection::source_location& sl
          = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = expr, .abort = false, .message = message, .location = sl });
  }

  /**
   * @brief The generic evaluation function.
   */
  template <
      class Expr_T,
      type_traits::requires_t<
          type_traits::is_op_v<
              Expr_T> or type_traits::is_convertible_v<Expr_T, bool>> = 0>
  constexpr auto
  assume (const Expr_T& expr, const char* message = "",
          const reflection::source_location& sl
          = reflection::source_location::current ())
  {
    return detail::evaluate_and_report_<Expr_T> (detail::assertion<Expr_T>{
        .expr = expr, .abort = true, .message = message, .location = sl });
  }

#if defined(__cpp_exceptions)
  template <class Exception_T, class Expr_T>
  [[nodiscard]] constexpr auto
  throws (const Expr_T& expr)
  {
    return detail::throws_<Expr_T, Exception_T>{ expr };
  }

  template <class Expr_T>
  [[nodiscard]] constexpr auto
  throws (const Expr_T& expr)
  {
    return detail::throws_<Expr_T>{ expr };
  }

  template <class Expr_T>
  [[nodiscard]] constexpr auto
  nothrow (const Expr_T& expr)
  {
    return detail::nothrow_{ expr };
  }
#endif

  /**
   * @brief Generic equality comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @brief Pointer equality comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @brief Generic non-equality comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @brief Pointer non-equality comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @brief Generic greater than comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @brief Pointer greater than comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @brief Generic greater than or equal comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @brief Pointer greater than or equal comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @brief Generic less than comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @brief Generic less than comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @brief Generic less than or equal comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  /**
   * @brief Generic less than or equal comparator.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T* expr)
  {
    return detail::not_{ expr };
  }

  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T& expr)
  {
    return detail::not_{ expr };
  }

  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::and_{ lhs, rhs };
  }

  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T* lhs, const Rhs_T* rhs)
  {
    return detail::and_{ lhs, rhs };
  }

  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _or (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::or_{ lhs, rhs };
  }

  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _or (const Lhs_T* lhs, const Rhs_T* rhs)
  {
    return detail::or_{ lhs, rhs };
  }

  /**
   * @brief Generic mutator, to remove const from any type.
   */
  template <class T>
  [[nodiscard]] constexpr auto
  mut (const T& t) noexcept -> T&
  {
    return const_cast<T&> (t);
  }

  // --------------------------------------------------------------------------

  using _b = detail::value<bool>;
  using _c = detail::value<char>;
  using _sc = detail::value<signed char>;
  using _s = detail::value<short>;
  using _i = detail::value<int>;
  using _l = detail::value<long>;
  using _ll = detail::value<long long>;
  using _u = detail::value<unsigned>;
  using _uc = detail::value<unsigned char>;
  using _us = detail::value<unsigned short>;
  using _ul = detail::value<unsigned long>;
  using _ull = detail::value<unsigned long long>;
  using _i8 = detail::value<std::int8_t>;
  using _i16 = detail::value<std::int16_t>;
  using _i32 = detail::value<std::int32_t>;
  using _i64 = detail::value<std::int64_t>;
  using _u8 = detail::value<std::uint8_t>;
  using _u16 = detail::value<std::uint16_t>;
  using _u32 = detail::value<std::uint32_t>;
  using _u64 = detail::value<std::uint64_t>;
  using _f = detail::value<float>;
  using _d = detail::value<double>;
  using _ld = detail::value<long double>;

  template <class T>
  struct _t : detail::value<T>
  {
    constexpr explicit _t (const T& t) : detail::value<T>{ t }
    {
    }
  };

  namespace operators
  {
    [[nodiscard]] constexpr auto
    operator== (std::string_view lhs, std::string_view rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    [[nodiscard]] constexpr auto
    operator!= (std::string_view lhs, std::string_view rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator== (T&& lhs, T&& rhs)
    {
      return detail::eq_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator!= (T&& lhs, T&& rhs)
    {
      return detail::ne_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator== (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator!= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator> (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::gt_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator>= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ge_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator< (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::lt_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator<= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::le_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator and (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::and_{ lhs, rhs };
    }

    template <
        class Lhs_T, class Rhs_T,
        type_traits::requires_t<
            type_traits::is_op_v<Lhs_T> or type_traits::is_op_v<Rhs_T>> = 0>
    [[nodiscard]] constexpr auto
    operator or (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::or_{ lhs, rhs };
    }

    template <class T, type_traits::requires_t<type_traits::is_op_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator not (const T& t)
    {
      return detail::not_{ t };
    }
  } // namespace operators

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ===== Inline & template implementations ====================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  template <class Callable_T>
  test_suite::test_suite (const char* name, Callable_T callable)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    name_ = name;
    callable_ = callable;

    runner.register_test_suite (this);
  }

  // --------------------------------------------------------------------------

  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& func, Args_T&&... arguments)
  {
#if 0 // defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    current_test_suite->begin_test_case (name);
    std::invoke (std::forward<Callable_T> (func),
                 std::forward<Args_T> (arguments)...);
    current_test_suite->end_test_case ();
  }
  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------
