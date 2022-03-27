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

#ifndef MICRO_TEST_PLUS_TEST_REPORTER_H_
#define MICRO_TEST_PLUS_TEST_REPORTER_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

//#include <functional>
#include <string_view>
#include <string>

#include "type-traits.h"
#include "test-suite.h"
#include "detail.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  struct colors
  {
    const char* none = "\033[0m";
    const char* pass = "\033[32m";
    const char* fail = "\033[31m";
  };

  enum class verbosity
  {
    silent = 0, // Nothing, only return the exit code
    quiet = 1, // Test suites results
    normal = 2, // Test suites results and failed test cases
    verbose = 3 // All, including passed checks
  };

  typedef verbosity verbosity_t;

  class test_reporter;

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

    void
    endline (void);

    // ------------------------------------------------------------------------

    /**
     * @brief Report a passed condition.
     */
    template <class Expr_T>
    void
    pass (Expr_T& expr, std::string& message);

    /**
     * @brief Report a failed condition.
     */
    template <class Expr_T>
    void
    fail (Expr_T& expr, std::string& message,
          const reflection::source_location& location);

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

    // Used to nicely format the output, without empty lines
    // between successful test cases.
    bool add_empty_line{ true };

    verbosity_t verbosity{};

  protected:
    // The prefix/suffix methods help shorten the code
    // generated by the template methods.

    void
    output_pass_prefix_ (std::string& message);

    void
    output_pass_suffix_ (void);

    void
    output_fail_prefix_ (std::string& message,
                         const reflection::source_location& location);

    void
    output_fail_suffix_ (void);

    colors colors_{};
    std::string out_{};
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_REPORTER_H_

// ----------------------------------------------------------------------------
