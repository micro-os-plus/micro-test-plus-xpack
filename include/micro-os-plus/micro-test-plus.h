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

#include "reflection.h"
#include "math.h"
#include "type-traits.h"
#include "literals.h"
#include "test-suite.h"

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
     * @brief Operator to check if expression throws a specific exception.
     */
    template <class Expr_T, class Exception_T = void>
    struct throws_ : type_traits::op
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
    struct throws_<Expr_T, void> : type_traits::op
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
    struct nothrow_ : type_traits::op
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

    test_reporter&
    operator<< (std::string_view sv);

    test_reporter&
    operator<< (char c);

    test_reporter&
    operator<< (const char* s);

    test_reporter&
    operator<< (char* s);

    test_reporter&
    operator<< (bool v);

    test_reporter& operator<< (std::nullptr_t);

    test_reporter&
    operator<< (signed char c);

    test_reporter&
    operator<< (unsigned char c);

    test_reporter&
    operator<< (signed short c);

    test_reporter&
    operator<< (unsigned short c);

    test_reporter&
    operator<< (signed int v);

    test_reporter&
    operator<< (unsigned int v);

    test_reporter&
    operator<< (signed long v);

    test_reporter&
    operator<< (unsigned long v);

    test_reporter&
    operator<< (signed long long v);

    test_reporter&
    operator<< (unsigned long long v);

    test_reporter&
    operator<< (float v);

    test_reporter&
    operator<< (double v);

    test_reporter&
    operator<< (long double v);

    /**
     * @brief Output operator to display any pointer.
     */
    template <typename T>
    test_reporter&
    operator<< (T* v);

    /**
     * @brief Output operator to display the endl.
     */
    test_reporter&
    operator<< (test_reporter& (*func) (test_reporter&));

    // ------------------------------------------------------------------------
    // Specific operators.

    /**
     * @brief Output operator to types with a getter.
     */
    template <class T>
    test_reporter&
    operator<< (const T& t);

    /**
     * @brief Output operator to display genuine integers,
     * without the type suffix.
     */
    template <class T>
    test_reporter&
    operator<< (const type_traits::genuine_integral_value<T>& v);

    /**
     * @brief Output operator to display containers. Iterate all members.
     */
    template <class T, type_traits::requires_t<
                           type_traits::is_container_v<
                               T> and not type_traits::has_npos_v<T>> = 0>
    test_reporter&
    operator<< (T&& t);

    /**
     * @brief Output operator to display eq() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::eq_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display ne() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::ne_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display gt() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::gt_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display ge() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::ge_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display lt() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::lt_<Rhs_T, Lhs_T>& op);

    /**
     * @brief Output operator to display le() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::le_<Rhs_T, Lhs_T>& op);

    /**
     * @brief Output operator to display and() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::and_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display or() expressions.
     */
    template <class Lhs_T, class Rhs_T>
    test_reporter&
    operator<< (const detail::or_<Lhs_T, Rhs_T>& op);

    /**
     * @brief Output operator to display not() expressions.
     */
    template <class T>
    test_reporter&
    operator<< (const detail::not_<T>& op);

#if defined(__cpp_exceptions)
    template <class Expr_T, class Exception_T>
    test_reporter&
    operator<< (const detail::throws_<Expr_T, Exception_T>& op);

    template <class Expr_T>
    test_reporter&
    operator<< (const detail::throws_<Expr_T, void>& op);

    template <class Expr_T>
    test_reporter&
    operator<< (const detail::nothrow_<Expr_T>& op);
#endif

    // ------------------------------------------------------------------------

    /**
     * @brief Report a passed condition.
     */
    template <class Expr_T>
    void
    pass (detail::assertion<Expr_T> assertion);

    /**
     * @brief Report a failed condition.
     */
    template <class Expr_T>
    void
    fail (detail::assertion<Expr_T> assertion);

    void
    begin_test_case (const char* name);

    void
    end_test_case (const char* name);

    void
    begin_test_suite (const char* name);

    void
    end_test_suite (test_suite& suite);

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

  // --------------------------------------------------------------------------
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

  template <typename T>
  test_reporter&
  test_reporter::operator<< (T* v)
  {
    printf ("%p", reinterpret_cast<void*> (v));
    return *this;
  }

  template <class T>
  test_reporter&
  test_reporter::operator<< (const T& t)
  {
    *this << detail::get (t);
    return *this;
  }

  template <class T>
  test_reporter&
  test_reporter::operator<< (const type_traits::genuine_integral_value<T>& v)
  {
    printf ("%lld", static_cast<long long> (v.get ()));
    return *this;
  }

  template <class T,
            type_traits::requires_t<type_traits::is_container_v<
                                        T> and not type_traits::has_npos_v<T>>>
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
  test_reporter::pass (detail::assertion<Expr_T> assertion)

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

  template <class Expr_T>
  void
  test_reporter::fail (detail::assertion<Expr_T> assertion)

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
          << type_traits::genuine_integral_value{ assertion.location.line () };
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
