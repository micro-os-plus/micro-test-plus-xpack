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
    abort (void)
    {
      ::abort ();
    }

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

  // --------------------------------------------------------------------------

  namespace reflection
  {
#if defined(__cpp_lib_source_location)
    using source_location = std::source_location;
#else
    /**
     * @brief Local implementation of the std::source_location.
     */
    class source_location
    {
    public:
      [[nodiscard]] static constexpr auto
      current (
#if (__has_builtin(__builtin_FILE) and __has_builtin(__builtin_LINE))
          const char* file = __builtin_FILE(), int line = __builtin_LINE()
#else
          const char* file = "unknown", int line = {}
#endif
              ) noexcept
      {
        source_location sl{};
        sl.file_ = file;
        sl.line_ = line;
        return sl;
      }

      [[nodiscard]] constexpr auto
      file_name () const noexcept
      {
        return file_;
      }

      [[nodiscard]] constexpr auto
      line () const noexcept
      {
        return line_;
      }

    private:
      const char* file_{ "unknown" };
      int line_{};
    };

#endif

    const char*
    short_name (const char* name);

    // TODO: update for the new namespaces.

    /**
     * @brief Parse the __PRETTY_FUNCTION__ macro to extract the type name.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    type_name () -> std::string_view
    {
#if defined(_MSC_VER) and not defined(__clang__)
      return { &__FUNCSIG__[120], sizeof (__FUNCSIG__) - 128 };
#elif defined(__clang_analyzer__)
      return { &__PRETTY_FUNCTION__[57], sizeof (__PRETTY_FUNCTION__) - 59 };
#elif defined(__clang__) and (__clang_major__ >= 13) and defined(__APPLE__)
      // TODO: find out why it fails to compute the length properly:
      // throws<std::runtime_error]>
      return { &__PRETTY_FUNCTION__[78],
               2 /* sizeof (__PRETTY_FUNCTION__) - 80 */ };
#elif defined(__clang__) and (__clang_major__ >= 12) and not defined(__APPLE__)
      return { &__PRETTY_FUNCTION__[97], sizeof (__PRETTY_FUNCTION__) - 99 };
#elif defined(__clang__)
      return { &__PRETTY_FUNCTION__[70], sizeof (__PRETTY_FUNCTION__) - 72 };
#elif defined(__GNUC__)
      return { &__PRETTY_FUNCTION__[85], sizeof (__PRETTY_FUNCTION__) - 136 };
#endif
    }

  } // namespace reflection

  /**
   * @brief Types used as arguments to on() functions.
   */
  namespace events
  {
    template <class TExpr>
    struct assertion
    {
      TExpr expr{};
      bool abort; // True if called from assume(), false from expect()
      const char* message;
      reflection::source_location location{};
    };

    template <class TExpr>
    assertion (TExpr, reflection::source_location) -> assertion<TExpr>;

    template <class TExpr>
    struct assertion_pass
    {
      TExpr expr{};
      bool abort; // True if called from assume(), false from expect()
      const char* message;
      reflection::source_location location{};
    };

    template <class TExpr>
    assertion_pass (TExpr) -> assertion_pass<TExpr>;

    template <class TExpr>
    struct assertion_fail
    {
      TExpr expr{};
      bool abort; // True if called from assume(), false from expect()
      const char* message;
      reflection::source_location location{};
    };

    template <class TExpr>
    assertion_fail (TExpr) -> assertion_fail<TExpr>;

  } // namespace events

  // --------------------------------------------------------------------------

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
    template <class T, class TExp>
    [[nodiscard]] constexpr auto
    pow (const T base, const TExp exp) -> T
    {
      // If the exponent is 0, return 1, otherwise recurse.
      return exp ? T (base * pow (base, exp - TExp (1))) : T (1);
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
    template <class T, class TValue>
    [[nodiscard]] constexpr auto
    den_size (TValue value) -> T
    {
      constexpr auto precision = TValue (1e-7);
      T result{};
      TValue tmp{};
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

    template <class R, class... TArgs>
    struct function_traits<R (*) (TArgs...)>
    {
      using result_type = R;
      using args = list<TArgs...>;
    };

    template <class R, class... TArgs>
    struct function_traits<R (TArgs...)>
    {
      using result_type = R;
      using args = list<TArgs...>;
    };

    template <class R, class T, class... TArgs>
    struct function_traits<R (T::*) (TArgs...)>
    {
      using result_type = R;
      using args = list<TArgs...>;
    };

    template <class R, class T, class... TArgs>
    struct function_traits<R (T::*) (TArgs...) const>
    {
      using result_type = R;
      using args = list<TArgs...>;
    };

    template <class T>
    T&&
    declval ();
    template <class... Ts, class TExpr>
    constexpr auto
    is_valid (TExpr expr) -> decltype (expr (declval<Ts...> ()), bool ())
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
    template <class TLhs, class TRhs>
    struct eq_ : op
    {
      constexpr eq_ (const TLhs& lhs = {}, const TRhs& rhs = {})
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
                                TLhs> and type_traits::has_value_v<TRhs>)
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "value == value");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // If both types have values (like numeric constants),
                  // compare them directly.
                  return TLhs::value == TRhs::value;
                }
              else if constexpr (
                  type_traits::has_epsilon_v<
                      TLhs> and type_traits::has_epsilon_v<TRhs>)
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "abs < min epsilon LR");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // If both values have precision, compare them using
                  // the smalles precision.
                  return math::abs (get (lhs) - get (rhs))
                         < math::min_value (TLhs::epsilon, TRhs::epsilon);
                }
              else if constexpr (type_traits::has_epsilon_v<TLhs>)
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "abs < epsilon L");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // If only the left operand has precision, use it.
                  return math::abs (get (lhs) - get (rhs)) < TLhs::epsilon;
                }
              else if constexpr (type_traits::has_epsilon_v<TRhs>)
                {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
                  micro_os_plus::trace::printf ("    eq_ %s\n",
                                                "abs < epsilon R");
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

                  // If only the right operand has precision, use it.
                  return math::abs (get (lhs) - get (rhs)) < TRhs::epsilon;
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

      const TLhs lhs_{};
      const TRhs rhs_{};
      const bool value_{};
    };

    /**
     * @brief Non-equality comparator.
     */
    template <class TLhs, class TRhs>
    struct ne_ : op
    {
      constexpr ne_ (const TLhs& lhs = {}, const TRhs& rhs = {})
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
                                TLhs> and type_traits::has_value_v<TRhs>)
                {
                  return TLhs::value != TRhs::value;
                }
              else if constexpr (
                  type_traits::has_epsilon_v<
                      TLhs> and type_traits::has_epsilon_v<TRhs>)
                {
                  return math::abs (get (lhs_) - get (rhs_))
                         > math::min_value (TLhs::epsilon, TRhs::epsilon);
                }
              else if constexpr (type_traits::has_epsilon_v<TLhs>)
                {
                  return math::abs (get (lhs_) - get (rhs_)) > TLhs::epsilon;
                }
              else if constexpr (type_traits::has_epsilon_v<TRhs>)
                {
                  return math::abs (get (lhs_) - get (rhs_)) > TRhs::epsilon;
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

      const TLhs lhs_{};
      const TRhs rhs_{};
      const bool value_{};
    };

    /**
     * @brief Greater than comparator.
     */
    template <class TLhs, class TRhs>
    struct gt_ : op
    {
      constexpr gt_ (const TLhs& lhs = {}, const TRhs& rhs = {})
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
                                TLhs> and type_traits::has_value_v<TRhs>)
                {
                  return TLhs::value > TRhs::value;
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

      const TLhs lhs_{};
      const TRhs rhs_{};
      const bool value_{};
    };

    /**
     * @brief Greater than or equal comparator.
     */
    template <class TLhs, class TRhs>
    struct ge_ : op
    {
      constexpr ge_ (const TLhs& lhs = {}, const TRhs& rhs = {})
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
                                TLhs> and type_traits::has_value_v<TRhs>)
                {
                  return TLhs::value >= TRhs::value;
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

      const TLhs lhs_{};
      const TRhs rhs_{};
      const bool value_{};
    };

    /**
     * @brief Less than comparator.
     */
    template <class TLhs, class TRhs>
    struct lt_ : op
    {
      constexpr lt_ (const TLhs& lhs = {}, const TRhs& rhs = {})
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
                                TLhs> and type_traits::has_value_v<TRhs>)
                {
                  return TLhs::value < TRhs::value;
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
      const TLhs lhs_{};
      const TRhs rhs_{};
      const bool value_{};
    };

    /**
     * @brief Less than or equal comparator.
     */
    template <class TLhs, class TRhs>
    struct le_ : op
    {
      constexpr le_ (const TLhs& lhs = {}, const TRhs& rhs = {})
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
                                TLhs> and type_traits::has_value_v<TRhs>)
                {
                  return TLhs::value <= TRhs::value;
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

      const TLhs lhs_{};
      const TRhs rhs_{};
      const bool value_{};
    };

    /**
     * @brief Logical and operator.
     */
    template <class TLhs, class TRhs>
    struct and_ : op
    {
      constexpr and_ (const TLhs& lhs = {}, const TRhs& rhs = {})
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

      const TLhs lhs_{};
      const TRhs rhs_{};
      const bool value_{};
    };

    /**
     * @brief Logical or operator.
     */
    template <class TLhs, class TRhs>
    struct or_ : op
    {
      constexpr or_ (const TLhs& lhs = {}, const TRhs& rhs = {})
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

      const TLhs lhs_{};
      const TRhs rhs_{};
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
    template <class TExpr, class TException = void>
    struct throws_ : op
    {
      constexpr explicit throws_ (const TExpr& expr)
          : value_{ [&expr] {
              try
                {
                  expr ();
                }
              catch (const TException&)
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
    template <class TExpr>
    struct throws_<TExpr, void> : op
    {
      constexpr explicit throws_ (const TExpr& expr)
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
    template <class TExpr>
    struct nothrow_ : op
    {
      constexpr explicit nothrow_ (const TExpr& expr)
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
    template <class TLhs, class TRhs>
    auto&
    operator<< (const detail::eq_<TLhs, TRhs>& op)
    {
      return (*this << color (op) << op.lhs () << " == " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display ne() expressions.
     */
    template <class TLhs, class TRhs>
    auto&
    operator<< (const detail::ne_<TLhs, TRhs>& op)
    {
      return (*this << color (op) << op.lhs () << " != " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display gt() expressions.
     */
    template <class TLhs, class TRhs>
    auto&
    operator<< (const detail::gt_<TLhs, TRhs>& op)
    {
      return (*this << color (op) << op.lhs () << " > " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display ge() expressions.
     */
    template <class TLhs, class TRhs>
    auto&
    operator<< (const detail::ge_<TLhs, TRhs>& op)
    {
      return (*this << color (op) << op.lhs () << " >= " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display lt() expressions.
     */
    template <class TLhs, class TRhs>
    auto&
    operator<< (const detail::lt_<TRhs, TLhs>& op)
    {
      return (*this << color (op) << op.lhs () << " < " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display le() expressions.
     */
    template <class TLhs, class TRhs>
    auto&
    operator<< (const detail::le_<TRhs, TLhs>& op)
    {
      return (*this << color (op) << op.lhs () << " <= " << op.rhs ()
                    << colors_.none);
    }

    /**
     * @brief Output operator to display and() expressions.
     */
    template <class TLhs, class TRhs>
    auto&
    operator<< (const detail::and_<TLhs, TRhs>& op)
    {
      return (*this << '(' << op.lhs () << color (op) << " and "
                    << colors_.none << op.rhs () << ')');
    }

    /**
     * @brief Output operator to display or() expressions.
     */
    template <class TLhs, class TRhs>
    auto&
    operator<< (const detail::or_<TLhs, TRhs>& op)
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
    template <class TExpr, class TException>
    auto&
    operator<< (const detail::throws_<TExpr, TException>& op)
    {
      return (*this << color (op) << "throws<"
                    << reflection::type_name<TException> () << ">"
                    << colors_.none);
    }

    template <class TExpr>
    auto&
    operator<< (const detail::throws_<TExpr, void>& op)
    {
      return (*this << color (op) << "throws" << colors_.none);
    }

    template <class TExpr>
    auto&
    operator<< (const detail::nothrow_<TExpr>& op)
    {
      return (*this << color (op) << "nothrow" << colors_.none);
    }
#endif

    // ------------------------------------------------------------------------

    /**
     * @brief Report a passed condition.
     */
    template <class TExpr>
    auto
    pass (events::assertion_pass<TExpr> assertion) -> void
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
    template <class TExpr>
    auto
    fail (events::assertion_fail<TExpr> assertion) -> void
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
    /**
     * @brief Helper class to give each expectation a type and a boolean value.
     */
    template <class T>
    struct expect_
    {
      constexpr explicit expect_ (bool value) : value_{ value }
      {
      }

      [[nodiscard]] constexpr operator bool () const
      {
        return value_;
      }

      bool value_{};
    };

    template <class TExpr>
    [[nodiscard]] auto
    on (events::assertion<TExpr> assertion) -> bool
    {
      // if (dry_run_)
      //   {
      //     return true;
      //   }

      if (static_cast<bool> (assertion.expr))
        {
          reporter.pass (
              events::assertion_pass<TExpr>{ .expr = assertion.expr,
                                             .abort = assertion.abort,
                                             .message = assertion.message,
                                             .location = assertion.location });
          return true;
        }

      reporter.fail (
          events::assertion_fail<TExpr>{ .expr = assertion.expr,
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

  template <class TExpr = bool>
  constexpr auto
  pass (const char* message = "passed",
        const reflection::source_location& sl
        = reflection::source_location::current ())
  {
    return detail::expect_<TExpr>{ detail::on<TExpr> (events::assertion<TExpr>{
        .expr = true, .abort = false, .message = message, .location = sl }) };
  }

  template <class TExpr = bool>
  constexpr auto
  fail (const char* message = "...", const reflection::source_location& sl
                                     = reflection::source_location::current ())
  {
    return detail::expect_<TExpr>{ detail::on<TExpr> (events::assertion<TExpr>{
        .expr = false, .abort = false, .message = message, .location = sl }) };
  }

  /**
   * @brief The generic evaluation function.
   */
  template <class TExpr,
            type_traits::requires_t<
                type_traits::is_op_v<
                    TExpr> or type_traits::is_convertible_v<TExpr, bool>> = 0>
  constexpr auto
  expect (const TExpr& expr, const char* message = "",
          const reflection::source_location& sl
          = reflection::source_location::current ())
  {
    return detail::expect_<TExpr>{ detail::on<TExpr> (events::assertion<TExpr>{
        .expr = expr, .abort = false, .message = message, .location = sl }) };
  }

  /**
   * @brief The generic evaluation function.
   */
  template <class TExpr,
            type_traits::requires_t<
                type_traits::is_op_v<
                    TExpr> or type_traits::is_convertible_v<TExpr, bool>> = 0>
  constexpr auto
  assume (const TExpr& expr, const char* message = "",
          const reflection::source_location& sl
          = reflection::source_location::current ())
  {
    return detail::expect_<TExpr>{ detail::on<TExpr> (events::assertion<TExpr>{
        .expr = expr, .abort = true, .message = message, .location = sl }) };
  }

#if defined(__cpp_exceptions)
  template <class TException, class TExpr>
  [[nodiscard]] constexpr auto
  throws (const TExpr& expr)
  {
    return detail::throws_<TExpr, TException>{ expr };
  }

  template <class TExpr>
  [[nodiscard]] constexpr auto
  throws (const TExpr& expr)
  {
    return detail::throws_<TExpr>{ expr };
  }

  template <class TExpr>
  [[nodiscard]] constexpr auto
  nothrow (const TExpr& expr)
  {
    return detail::nothrow_{ expr };
  }
#endif

  /**
   * @brief Generic equality comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  eq (const TLhs& lhs, const TRhs& rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @brief Pointer equality comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  eq (TLhs* lhs, TRhs* rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @brief Generic non-equality comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  ne (const TLhs& lhs, const TRhs& rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @brief Pointer non-equality comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  ne (TLhs* lhs, TRhs* rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @brief Generic greater than comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  gt (const TLhs& lhs, const TRhs& rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @brief Pointer greater than comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  gt (TLhs* lhs, TRhs* rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @brief Generic greater than or equal comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  ge (const TLhs& lhs, const TRhs& rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @brief Pointer greater than or equal comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  ge (TLhs* lhs, TRhs* rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @brief Generic less than comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  lt (const TLhs& lhs, const TRhs& rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @brief Generic less than comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  lt (TLhs* lhs, TRhs* rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @brief Generic less than or equal comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  le (const TLhs& lhs, const TRhs& rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  /**
   * @brief Generic less than or equal comparator.
   */
  template <class TLhs, class TRhs>
  [[nodiscard]] constexpr auto
  le (TLhs* lhs, TRhs* rhs)
  {
    return detail::le_{ lhs, rhs };
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

#if 0
  template <typename T, typename U>
  void
  expect_equal ([[maybe_unused]] T actual, [[maybe_unused]] U expected,
                const char* message, const char* file, int line)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    const char* type_part = std::strchr (__PRETTY_FUNCTION__, '[');
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
    if constexpr (!std::is_scalar_v<T>)
      {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
        micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
        printf ("    ✗ %s (non scalar <actual>", message);
        reporter.print_where (" in '%s:%d'", file, line);
        printf (")\n");
        current_test_suite->increment_failed ();
        return;
      }
    else if constexpr (!std::is_scalar_v<U>)
      {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
        micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
        printf ("    ✗ %s (non scalar <expected>", message);
        reporter.print_where (" in '%s:%d'", file, line);
        printf (")\n");
        current_test_suite->increment_failed ();
        return;
      }
    else
      {
        bool is_equal = false;
        if constexpr (std::is_pointer_v<T> && std::is_null_pointer_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            printf ("%s() %s compare pointers to null\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
            is_equal = (actual == nullptr);
          }
        else if constexpr (
            (std::is_same_v<T, char*> || std::is_same_v<T, const char*>)&&(
                std::is_same_v<U, char*> || std::is_same_v<U, const char*>))
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s compare strings\n",
                                          __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
            is_equal = (std::strcmp (actual, expected) == 0);
          }
        else if constexpr (std::is_pointer_v<T> && std::is_pointer_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            printf ("%s() %s compare pointers\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

            is_equal = (reinterpret_cast<void*> (actual)
                        == reinterpret_cast<void*> (expected));
          }
        else if constexpr (std::is_integral_v<T> && std::is_integral_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s compare integrals\n",
                                          __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif
            is_equal = (actual == expected);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
          }
        else if constexpr (std::is_floating_point_v<
                               T> && std::is_floating_point_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
            printf ("    ✗ %s (floating points not comparable", message);
            reporter.print_where (" in '%s:%d'", file, line);
            printf (")\n");
            current_test_suite->increment_failed ();
            return;
          }
        else if constexpr (std::is_floating_point_v<
                               T> || std::is_floating_point_v<U>)
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#if defined(__clang__)
#pragma GCC diagnostic ignored "-Wimplicit-int-float-conversion"
#endif
#endif
            is_equal = (actual == expected);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
          }
        else
          {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
            micro_os_plus::trace::printf ("%s() %s\n", __func__, type_part);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
            printf ("    ✗ %s (non comparable types", message);
            reporter.print_where (" in '%s:%d'", file, line);
            printf (")\n");
            current_test_suite->increment_failed ();
            return;
          }
        // Else fail.

        if (is_equal)
          {
            reporter.pass (message, file, line);
            current_test_suite->increment_passed ();
          }
        else
          {
            printf ("    ✗ %s (expected ", message);
            reporter.print_value<U> (expected);
            printf (", got ");
            reporter.print_value<T> (actual);
            reporter.print_where (", in '%s:%d'", file, line);
            printf (")\n");
            current_test_suite->increment_failed ();
          }
      }
  }
#endif

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
