/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ header file with inline implementations for the µTest++ function
 * comparators.
 *
 * @details
 * This header provides the inline implementations for the function comparator
 * templates used within the µTest++ framework. It defines the logic for
 * generic and pointer-based comparison operators, including equality,
 * non-equality, greater than, less than, and their respective logical
 * variants. Additionally, it implements logical combinators such as
 * conjunction (_and), disjunction (_or), and negation (_not), as well as a
 * utility for safely removing constness from objects.
 *
 * These comparators and logical operators enable expressive and type-safe test
 * expectations and assertions, supporting both value and pointer semantics.
 * The underscore-prefixed logical operators are intentionally named to avoid
 * conflicts with standard operators.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_INLINES_FUNCTION_COMPARATORS_INLINES_H_
#define MICRO_TEST_PLUS_INLINES_FUNCTION_COMPARATORS_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * The `eq` function template provides a generic equality comparator for any
   * non-pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that two values are equal. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  eq (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::eq_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `eq` function template provides a pointer equality comparator for any
   * pointer types. It constructs a comparator object that can be used within
   * the µTest++ framework to assert that two pointers are equal. This function
   * is typically used in test expectations and assertions to compare the
   * addresses of objects or resources.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  eq (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::eq_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `ne` function template provides a generic non-equality comparator for
   * any types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that two values are not equal. This function
   * is typically used in test expectations and assertions to compare the
   * actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  ne (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ne_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `ne` function template provides a pointer non-equality comparator for
   * any pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that two pointers are not equal.
   * This function is typically used in test expectations and assertions to
   * compare the addresses of objects or resources.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  ne (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ne_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `gt` function template provides a generic greater than comparator for
   * any types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that one value is greater than another. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  gt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::gt_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `gt` function template provides a pointer greater than comparator for
   * any pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that one pointer is greater than
   * another. This function is typically used in test expectations and
   * assertions to compare the addresses of objects or resources.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  gt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::gt_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `ge` function template provides a generic greater than or equal
   * comparator for any types. It constructs a comparator object that can be
   * used within the µTest++ framework to assert that one value is greater than
   * or equal to another. This function is typically used in test expectations
   * and assertions to compare the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  ge (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ge_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `ge` function template provides a pointer greater than or equal
   * comparator for any pointer types. It constructs a comparator object that
   * can be used within the µTest++ framework to assert that one pointer is
   * greater than or equal to another. This function is typically used in test
   * expectations and assertions to compare the addresses of objects or
   * resources.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  ge (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ge_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `lt` function template provides a generic less than comparator for any
   * types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that one value is less than another. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  lt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::lt_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `lt` function template provides a pointer less than comparator for any
   * pointer types. It constructs a comparator object that can be used within
   * the µTest++ framework to assert that one pointer is less than another.
   * This function is typically used in test expectations and assertions to
   * compare the addresses of objects or resources.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  lt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::lt_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  /**
   * @details
   * The `le` function template provides a generic less than or equal
   * comparator for any types. It constructs a comparator object that can be
   * used within the µTest++ framework to assert that one value is less than or
   * equal to another. This function is typically used in test expectations and
   * assertions to compare the actual and expected values.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  le (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::le_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `le` function template provides a pointer less than or equal
   * comparator for any pointer types. It constructs a comparator object that
   * can be used within the µTest++ framework to assert that one pointer is
   * less than or equal to another. This function is typically used in test
   * expectations and assertions to compare the addresses of objects or
   * resources.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  le (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::le_<Lhs_T*, Rhs_T*>{ lhs, rhs };
  }

  // --------------------------------------------------------------------------
  // Logical operators.

  /**
   * @details
   * The `_not` function template provides a generic logical negation for any
   * expression type. It constructs a logical negator object that can be used
   * within the µTest++ framework to assert that a given condition is false.
   * This function is typically used in test expectations and assertions to
   * invert logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical not operator.
   */
  template <class Expr_T>
  constexpr auto
  _not (const Expr_T& expr)
  {
    return detail::not_<Expr_T>{ expr };
  }

  /**
   * @details
   * The `_and` function template provides a generic logical conjunction for
   * any expression types. It constructs a logical conjunction object that can
   * be used within the µTest++ framework to assert that both given conditions
   * are true. This function is typically used in test expectations and
   * assertions to combine logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical and operator.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _and (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::and_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  /**
   * @details
   * The `_or` function template provides a generic logical disjunction for any
   * expression types. It constructs a logical disjunction object that can be
   * used within the µTest++ framework to assert that at least one of the given
   * conditions is true. This function is typically used in test expectations
   * and assertions to combine logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical or operator.
   */
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _or (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::or_<Lhs_T, Rhs_T>{ lhs, rhs };
  }

  // --------------------------------------------------------------------------
  // Utility functions.

  /**
   * @details
   * The `mut` function template provides a safe and generic mechanism to
   * remove the `const` qualifier from any type. It returns a non-const
   * reference to the input object, enabling modification of objects that were
   * originally declared as `const`. This utility is particularly useful in
   * testing scenarios where controlled mutation of test data is required.
   */
  template <class T>
  constexpr auto
  mut (const T& t) noexcept -> T&
  {
    return const_cast<T&> (t);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_INLINES_FUNCTION_COMPARATORS_INLINES_H_

// ----------------------------------------------------------------------------
