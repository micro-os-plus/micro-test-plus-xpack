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
 * @brief C++ header file with inline implementations for the µTest++
 * internal detail namespace.
 *
 * @details
 * This header provides the out-of-line template and inline implementations
 * for all types declared in `detail.h`. It defines the bodies of the
 * `unwrap()` helper, the unary and binary operator base class templates,
 * the comparison tags, all relational, approximate, and logical comparator
 * constructors, the predicate constructor, the tolerance helpers
 * (`within_tolerance()`, `differ_by_at_most()`), the callable operator
 * types (`throws_op`, `nothrow_op`), the `append_number()` and
 * `append_pointer()` formatting helpers, the `basic_c_string` operand and
 * its operators, and `as_operand()`.
 *
 * Separating the implementations from the declarations keeps `detail.h`
 * concise and focused on the interface, whilst grouping the complex
 * lambda-based constructor bodies here for maintainability.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::detail`
 * namespace.
 *
 * This file is included by `detail.h`; the applications include
 * `micro-os-plus/micro-test-plus.h`, not this file.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DETAIL_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DETAIL_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include <algorithm>
#include <cerrno>
#include <cfloat>
#include <charconv>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <limits>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  namespace detail
  {
    // ========================================================================

    /**
     * @details
     * If the type `T` is a framework type (see `extension::is_op`)
     * that provides a `get()` member function, it is invoked and its result
     * returned. Otherwise a reference to the argument itself is returned,
     * so that the types of the application, even those with a `get()`
     * member function, are compared with their own operators, without a
     * copy. The selection is performed at compile time via
     * `if constexpr` with an inline `requires` expression; the return
     * type is deduced with `decltype (auto)` from the selected branch.
     */
    template <class T>
    constexpr decltype (auto)
    unwrap (const T& t)
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
      if constexpr (extension::is_op<T> && requires { t.get (); })
        return t.get ();
      else
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
        return t;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Stores the operand and the pre-computed boolean result of the
     * operation in the corresponding private members.
     */
    template <class T>
    template <class U>
    constexpr unary_op<T>::unary_op (U&& t, bool value)
        : t_{ std::forward<U> (t) }, value_{ value }
    {
    }

    /**
     * @details
     * Returns the pre-computed boolean result stored by the derived
     * comparator's constructor.
     */
    template <class T>
    constexpr unary_op<T>::
    operator bool () const
    {
      return value_;
    }

    /**
     * @details
     * Returns the operand, unwrapped by `detail::unwrap()` if it is a
     * framework wrapper type; the stored operand is not copied.
     */
    template <class T>
    constexpr decltype (auto)
    unary_op<T>::operand (void) const
    {
      return detail::unwrap (t_);
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Stores the two operands and the pre-computed boolean result of the
     * comparison in the corresponding private members.
     */
    template <class Lhs_T, class Rhs_T>
    template <class L, class R>
    constexpr binary_op<Lhs_T, Rhs_T>::binary_op (L&& lhs, R&& rhs, bool value)
        : lhs_{ std::forward<L> (lhs) }, rhs_{ std::forward<R> (rhs) },
          value_{ value }
    {
    }

    /**
     * @details
     * Returns the pre-computed boolean result stored by the derived
     * comparator's constructor.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr binary_op<Lhs_T, Rhs_T>::
    operator bool () const
    {
      return value_;
    }

    /**
     * @details
     * Returns the value of the left-hand operand, unwrapped by
     * `detail::unwrap()` if it is a framework wrapper type; the stored
     * operand is not copied.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr decltype (auto)
    binary_op<Lhs_T, Rhs_T>::lhs (void) const
    {
      return detail::unwrap (lhs_);
    }

    /**
     * @details
     * Returns the value of the right-hand operand, unwrapped by
     * `detail::unwrap()` if it is a framework wrapper type; the stored
     * operand is not copied.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr decltype (auto)
    binary_op<Lhs_T, Rhs_T>::rhs (void) const
    {
      return detail::unwrap (rhs_);
    }

    // ------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @details
     * The tolerance is the smaller `epsilon` of the two operands, if both
     * have one, otherwise the `epsilon` of the operand that has one. The
     * operands are equal when the absolute value of their difference is
     * less than the tolerance.
     */
    template <class Lhs_T, class Rhs_T>
      requires (extension::has_epsilon<Lhs_T> or extension::has_epsilon<Rhs_T>)
    constexpr bool
    within_tolerance (const Lhs_T& lhs, const Rhs_T& rhs)
    {
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)
      const auto difference
          = math::abs (detail::unwrap (lhs) - detail::unwrap (rhs));
      if constexpr (extension::has_epsilon<Lhs_T>
                    and extension::has_epsilon<Rhs_T>)
        {
          // If both values have precision, use the smallest one.
          return difference < math::min_value (lhs.epsilon, rhs.epsilon);
        }
      else if constexpr (extension::has_epsilon<Lhs_T>)
        {
          return difference < lhs.epsilon;
        }
      else
        {
          return difference < rhs.epsilon;
        }
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
    }
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    // ------------------------------------------------------------------------

    // The operands are compared as they are, including mixed integer and
    // floating-point types (integers of different signedness are compared
    // by value, see `sign_mixed_integers`); the warnings would be
    // reported in the test code of the application, not in the library.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma clang diagnostic ignored "-Wpedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

    /**
     * @brief The integer type used to compare a value of type @p T.
     *
     * @details
     * The primary template is the type itself. The character types
     * (`char`, `wchar_t`, `char8_t`, `char16_t`, and `char32_t`) are
     * compared as the numbers that they hold, so they are replaced by
     * the integer type of the same size and signedness, which
     * `std::cmp_*()` accepts; the signedness of `char` and `wchar_t`
     * depends on the platform, and is kept.
     *
     * @tparam T The type of the operand.
     */
    template <class T>
    struct comparison_integer
    {
      /**
       * @brief The type used for the comparison.
       */
      using type = T;
    };

    /**
     * @brief The integer type used to compare a character type.
     *
     * @tparam T The character type.
     */
    template <class T>
      requires character<T>
    struct comparison_integer<T>
    {
      /**
       * @brief The integer type of the same size and signedness.
       */
      using type
          = std::conditional_t<std::is_signed_v<T>, std::make_signed_t<T>,
                               std::make_unsigned_t<T>>;
    };

    /**
     * @brief Alias of the integer type used to compare the type @p T.
     *
     * @tparam T The type of the operand.
     */
    template <class T>
    using comparison_integer_t = typename comparison_integer<T>::type;

    /**
     * @brief Converts an integer or a character to the type used to
     * compare it.
     *
     * @tparam T The type of the operand.
     * @param value The operand.
     * @return The value, as `comparison_integer_t<T>`.
     */
    template <class T>
    [[nodiscard]] constexpr comparison_integer_t<T>
    as_comparison_integer (const T value) noexcept
    {
      return static_cast<comparison_integer_t<T>> (value);
    }

    /**
     * @brief Concept satisfied by two integer types of different
     * signedness.
     *
     * @details
     * The built-in comparison of a signed and an unsigned operand
     * converts the signed one to the unsigned type, so `-1 < 1u` is
     * false. For these pairs the comparisons use the `std::cmp_*()`
     * functions, which compare the mathematical values. The character
     * types take part as the integers of the same size and signedness
     * (see `comparison_integer`), since the built-in comparison of a
     * signed `char` with an `unsigned`, or of a `char32_t` with an
     * `int`, has the same problem. `bool` is excluded, since
     * `std::cmp_*()` do not accept it and its comparison with integers
     * is not a sign problem.
     */
    template <class Lhs_T, class Rhs_T>
    concept sign_mixed_integers
        = std::is_integral_v<Lhs_T> and std::is_integral_v<Rhs_T>
          and (not std::is_same_v<Lhs_T, bool>)
          and (not std::is_same_v<Rhs_T, bool>)
          and (std::is_signed_v<comparison_integer_t<Lhs_T>>
               != std::is_signed_v<comparison_integer_t<Rhs_T>>);

    /**
     * @brief The type with which an operand of a comparator is compared.
     *
     * @details
     * The type of the operand after `as_operand()` and `unwrap()`, without
     * references and qualifiers; for example `detail::basic_c_string<char>` for
     * a string literal.
     *
     * @tparam T The type deduced for the operand, possibly a reference.
     */
    template <class T>
    using comparison_operand_t
        = unwrapped_t<decltype (detail::as_operand (std::declval<T> ()))>;

    /**
     * @brief Concept satisfied by two pointers, one of which points to a
     * function.
     *
     * @details
     * The comparison of a function pointer with an object pointer, such as
     * a `void*`, is an extension of the compilers, accepted with a
     * warning, which the library silences, but not by the checks of the
     * concepts that follow; the comparators keep accepting it.
     *
     * @tparam Lhs_T The type of the left hand side operand.
     * @tparam Rhs_T The type of the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T>
    concept function_pointer_pair
        = std::is_pointer_v<Lhs_T> and std::is_pointer_v<Rhs_T>
          and (std::is_function_v<std::remove_pointer_t<Lhs_T>>
               or std::is_function_v<std::remove_pointer_t<Rhs_T>>);

    /**
     * @brief The comparison operators, as the template argument of the
     * `comparable` concept.
     *
     * @details
     * A single concept, parametrised by the operator, checks the operands
     * of all the comparators (`eq()`, `ne()`, `gt()`, `ge()`, `lt()`, and
     * `le()`).
     */
    enum class comparison : unsigned char
    {
      /** @brief The `==` operator, checked by `eq()`. */
      equal,
      /** @brief The `!=` operator, checked by `ne()`. */
      not_equal,
      /** @brief The `>` operator, checked by `gt()`. */
      greater,
      /** @brief The `>=` operator, checked by `ge()`. */
      greater_equal,
      /** @brief The `<` operator, checked by `lt()`. */
      less,
      /** @brief The `<=` operator, checked by `le()`. */
      less_equal
    };

    /**
     * @brief Names for the checks of the comparison operators, looked up
     * as the `apply()` functions look them up.
     *
     * @details
     * The using-declarations make the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, as in the bodies of the `apply()` functions; the concept
     * checks that the comparison is well-formed, without instantiating the
     * bodies.
     */
    namespace comparison_lookup
    {
      using std::operator==;
      using std::operator!=;
      using std::operator<;
      using std::operator>;
      using std::operator<=;
      using std::operator>=;

      /**
       * @brief Satisfied if the comparison selected by `Op` of two
       * `const` objects is well-formed.
       *
       * @details
       * Only the requirement of the selected operator is checked, so
       * that, for example, `eq()` accepts the types that have only an
       * `operator==`.
       *
       * @tparam Op The comparison.
       * @tparam Lhs_T The type of the left hand side operand.
       * @tparam Rhs_T The type of the right hand side operand.
       */
      template <comparison Op, class Lhs_T, class Rhs_T>
      concept can_compare
          = (Op == comparison::equal
             and requires (const Lhs_T& lhs, const Rhs_T& rhs) { lhs == rhs; })
            or (Op == comparison::not_equal
                and requires (const Lhs_T& lhs,
                              const Rhs_T& rhs) { lhs != rhs; })
            or (Op == comparison::greater
                and requires (const Lhs_T& lhs,
                              const Rhs_T& rhs) { lhs > rhs; })
            or (Op == comparison::greater_equal
                and requires (const Lhs_T& lhs,
                              const Rhs_T& rhs) { lhs >= rhs; })
            or (Op == comparison::less
                and requires (const Lhs_T& lhs,
                              const Rhs_T& rhs) { lhs < rhs; })
            or (Op == comparison::less_equal
                and requires (const Lhs_T& lhs, const Rhs_T& rhs) {
                      lhs <= rhs;
                    });
    } // namespace comparison_lookup

    /**
     * @brief Concept satisfied when two operands can be compared by the
     * comparator selected by `Op`.
     *
     * @details
     * The comparison is the one made by the `apply()` function of the
     * comparison tag: by value for the integers of different signedness
     * (see `sign_mixed_integers`), otherwise with the operator of the
     * language. A function pointer compared with an object pointer is
     * also accepted (see `function_pointer_pair`). Used to reject the
     * call of `eq()` and of the other comparators at the call site, with
     * a short diagnostic; the operator check is the first alternative, so
     * that the Clang diagnostic names the invalid operator and the two
     * types first (GCC reports only that no alternative is satisfied).
     *
     * @tparam Op The comparison.
     * @tparam Lhs_T The type deduced for the left hand side operand.
     * @tparam Rhs_T The type deduced for the right hand side operand.
     */
    template <comparison Op, class Lhs_T, class Rhs_T>
    concept comparable
        = comparison_lookup::can_compare<Op, comparison_operand_t<Lhs_T>,
                                         comparison_operand_t<Rhs_T>>
          or sign_mixed_integers<comparison_operand_t<Lhs_T>,
                                 comparison_operand_t<Rhs_T>>
          or function_pointer_pair<comparison_operand_t<Lhs_T>,
                                   comparison_operand_t<Rhs_T>>;

    /**
     * @details
     * The operands of the comparators must be written in the report of a
     * failed check, and compared with the operator. A single concept for
     * both conditions selects the comparator, and its negation selects the
     * overload that explains why a call is rejected.
     */
    template <comparison Op, class Lhs_T, class Rhs_T>
    concept comparable_operands
        = extension::printable<Lhs_T> and extension::printable<Rhs_T>
          and comparable<Op, Lhs_T, Rhs_T>;

    /**
     * @details
     * Always fails the static assertion that applies, since it is called
     * only when `comparable_operands` is not satisfied: an operand that
     * cannot be written is reported first, then the operator that the
     * operands do not support.
     */
    template <comparison Op, class Lhs_T, class Rhs_T>
    constexpr void
    reject_comparison (void) noexcept
    {
      if constexpr (not extension::printable<Lhs_T>
                    or not extension::printable<Rhs_T>)
        {
          static_assert (not std::is_same_v<Lhs_T, Lhs_T>,
                         "an operand of the comparator cannot be written in "
                         "the report; define an operator<< (mt::"
                         "expression_formatter&, const T&) in the namespace "
                         "of its type");
        }
      else if constexpr (Op == comparison::equal)
        {
          static_assert (not std::is_same_v<Lhs_T, Lhs_T>,
                         "the operands of eq () cannot be compared with ==");
        }
      else if constexpr (Op == comparison::not_equal)
        {
          static_assert (not std::is_same_v<Lhs_T, Lhs_T>,
                         "the operands of ne () cannot be compared with !=");
        }
      else if constexpr (Op == comparison::greater)
        {
          static_assert (not std::is_same_v<Lhs_T, Lhs_T>,
                         "the operands of gt () cannot be compared with >");
        }
      else if constexpr (Op == comparison::greater_equal)
        {
          static_assert (not std::is_same_v<Lhs_T, Lhs_T>,
                         "the operands of ge () cannot be compared with >=");
        }
      else if constexpr (Op == comparison::less)
        {
          static_assert (not std::is_same_v<Lhs_T, Lhs_T>,
                         "the operands of lt () cannot be compared with <");
        }
      else
        {
          static_assert (not std::is_same_v<Lhs_T, Lhs_T>,
                         "the operands of le () cannot be compared with <=");
        }
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator==` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    equal_to::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator==;
      if constexpr (sign_mixed_integers<Lhs_T, Rhs_T>)
        {
          return std::cmp_equal (as_comparison_integer (lhs),
                                 as_comparison_integer (rhs));
        }
      else
        {
          return lhs == rhs;
        }
    }

    /**
     * @details
     * The using-declarations make the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup; `operator==` is also needed for the C++20 rewritten
     * candidates of `!=`.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    not_equal_to::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator==;
      using std::operator!=;
      if constexpr (sign_mixed_integers<Lhs_T, Rhs_T>)
        {
          return std::cmp_not_equal (as_comparison_integer (lhs),
                                     as_comparison_integer (rhs));
        }
      else
        {
          return lhs != rhs;
        }
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator>` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    greater::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator>;
      if constexpr (sign_mixed_integers<Lhs_T, Rhs_T>)
        {
          return std::cmp_greater (as_comparison_integer (lhs),
                                   as_comparison_integer (rhs));
        }
      else
        {
          return lhs > rhs;
        }
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator>=` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    greater_equal::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator>=;
      if constexpr (sign_mixed_integers<Lhs_T, Rhs_T>)
        {
          return std::cmp_greater_equal (as_comparison_integer (lhs),
                                         as_comparison_integer (rhs));
        }
      else
        {
          return lhs >= rhs;
        }
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator<` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    less::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator<;
      if constexpr (sign_mixed_integers<Lhs_T, Rhs_T>)
        {
          return std::cmp_less (as_comparison_integer (lhs),
                                as_comparison_integer (rhs));
        }
      else
        {
          return lhs < rhs;
        }
    }

    /**
     * @details
     * The using-declaration makes the standard operators visible to
     * unqualified lookup, in addition to those found by argument-dependent
     * lookup, and hides any `operator<=` of the enclosing namespaces.
     */
    template <class Lhs_T, class Rhs_T>
    constexpr bool
    less_equal::apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      using std::operator<=;
      if constexpr (sign_mixed_integers<Lhs_T, Rhs_T>)
        {
          return std::cmp_less_equal (as_comparison_integer (lhs),
                                      as_comparison_integer (rhs));
        }
      else
        {
          return lhs <= rhs;
        }
    }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

    // ------------------------------------------------------------------------

    /**
     * @details
     * Satisfied when the tag has a static member `symbol` that the
     * formatter can write.
     */
    template <class Tag_T>
    concept tag_has_symbol = requires {
      requires extension::printable<
          std::remove_cvref_t<decltype (Tag_T::symbol)>>;
    };

    /**
     * @details
     * Always fails the static assertion that applies, since it is called
     * only when `extension::compare_tag` is not satisfied: the missing or
     * unprintable `symbol` is reported first, then the `apply()` that
     * cannot be called with the operands, or whose result is not
     * convertible to `bool`.
     */
    template <class Tag_T>
    constexpr void
    reject_compare_tag (void) noexcept
    {
      if constexpr (not tag_has_symbol<Tag_T>)
        {
          static_assert (not std::is_same_v<Tag_T, Tag_T>,
                         "the tag of a comparator needs a static member "
                         "symbol that can be written, such as a const "
                         "char*");
        }
      else
        {
          static_assert (not std::is_same_v<Tag_T, Tag_T>,
                         "the tag of a comparator needs a static member "
                         "function apply (lhs, rhs) that can be called with "
                         "the operands and returns a value convertible to "
                         "bool");
        }
    }

    /**
     * @details
     * As `reject_compare_tag()`, for the tag of a predicate, whose
     * `apply()` takes one operand.
     */
    template <class Tag_T>
    constexpr void
    reject_predicate_tag (void) noexcept
    {
      if constexpr (not tag_has_symbol<Tag_T>)
        {
          static_assert (not std::is_same_v<Tag_T, Tag_T>,
                         "the tag of a predicate needs a static member "
                         "symbol that can be written, such as a const "
                         "char*");
        }
      else
        {
          static_assert (not std::is_same_v<Tag_T, Tag_T>,
                         "the tag of a predicate needs a static member "
                         "function apply (operand) that can be called with "
                         "the operand and returns a value convertible to "
                         "bool");
        }
    }

    /**
     * @details
     * Evaluates the comparison inside an immediately invoked lambda, which
     * converts the result of `Compare_T::apply()` to `bool`, and passes it
     * to the `binary_op` base class constructor:
     * - for the framework constants with static `value` members (the
     *   numeric literals), the two values are compared directly;
     * - if at least one operand is a framework floating-point wrapper with
     *   an `epsilon` member, and the tag defines a
     *   `within_tolerance_result` (all the built-in tags do), operands
     *   within the tolerance give this result; otherwise the unwrapped
     *   values are compared; the tags of the application without it
     *   ignore the tolerance;
     * - for all other types, the framework wrappers are unwrapped, and the
     *   values, including the types of the application, are compared as
     *   they are.
     */
    template <class Lhs_T, class Rhs_T, class Compare_T>
    template <class L, class R>
      requires extension::compare_tag<Compare_T, unwrapped_t<L>,
                                      unwrapped_t<R>>
    constexpr compare_op<Lhs_T, Rhs_T, Compare_T>::compare_op (L&& lhs,
                                                               R&& rhs,
                                                               Compare_T)
        : binary_op<Lhs_T, Rhs_T>{ detail::as_operand (std::forward<L> (lhs)),
                                   detail::as_operand (std::forward<R> (rhs)),
                                   [&] () -> bool
      {
    // The result is computed before the arguments are moved, since
    // the base constructor is entered only after all its arguments
    // are evaluated.
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
        using lhs_type = std::remove_cvref_t<L>;
        using rhs_type = std::remove_cvref_t<R>;

        if constexpr (detail::has_value<lhs_type>
                      and detail::has_value<rhs_type>)
          {
            return Compare_T::apply (lhs_type::value, rhs_type::value);
          }
        else if constexpr ((extension::has_epsilon<lhs_type>
                            or extension::has_epsilon<rhs_type>)
                           and requires {
                                 Compare_T::within_tolerance_result;
                               })
          {
            return detail::within_tolerance (lhs, rhs)
                       ? Compare_T::within_tolerance_result
                       : Compare_T::apply (detail::unwrap (lhs),
                                           detail::unwrap (rhs));
          }
        else
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
          {
            return Compare_T::apply (detail::unwrap (lhs),
                                     detail::unwrap (rhs));
          }
      }() }
    {
    }

    /**
     * @details
     * Never called; the compilation stops in `reject_compare_tag()`, with a
     * message that states what the tag needs. The base is built with the
     * operands and a `false` result, so that the error is the only one.
     */
    template <class Lhs_T, class Rhs_T, class Compare_T>
    template <class L, class R>
      requires (not extension::compare_tag<Compare_T, unwrapped_t<L>,
                                           unwrapped_t<R>>)
    constexpr compare_op<Lhs_T, Rhs_T, Compare_T>::compare_op (L&& lhs,
                                                               R&& rhs,
                                                               Compare_T)
        : binary_op<Lhs_T, Rhs_T>{ detail::as_operand (std::forward<L> (lhs)),
                                   detail::as_operand (std::forward<R> (rhs)),
                                   false }
    {
      detail::reject_compare_tag<Compare_T> ();
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * For the integers, the larger value is selected with
     * `std::cmp_less()`, and the distance is computed in
     * `std::uintmax_t`: when both values have the same sign, as the
     * modular difference of their conversions, which is exact; otherwise,
     * as the sum of the larger value and of the magnitude of the negative
     * one. A sum that does not fit in `std::uintmax_t` is flagged as an
     * overflow, and gives `false`, since the true distance is larger than
     * any tolerance. The tolerance is compared with
     * `std::cmp_less_equal()`, so a negative one gives `false`.
     *
     * For the other types, the values are converted to their common type,
     * which is a floating-point one, so `std::int64_t` values compared
     * with a `float` tolerance lose precision; the comparison is inclusive,
     * so a distance equal to the tolerance succeeds. Two equal values,
     * including two infinities of the same sign, whose difference would be
     * NaN, are at the distance zero; a NaN operand always fails.
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    constexpr bool
    differ_by_at_most (Lhs_T lhs, Rhs_T rhs, Epsilon_T epsilon)
    {
      if constexpr (std::is_integral_v<Lhs_T> and std::is_integral_v<Rhs_T>
                    and std::is_integral_v<Epsilon_T>)
        {
          bool overflow = false;
          const auto distance
              = [&overflow] (auto larger,
                             auto smaller) constexpr -> std::uintmax_t
            {
              if constexpr (std::is_signed_v<decltype (smaller)>)
                {
                  if (smaller < 0 and std::cmp_greater_equal (larger, 0))
                    {
                      // The magnitude of the negative value, without
                      // negating the minimum of its type.
                      const auto magnitude
                          = static_cast<std::uintmax_t> (-(smaller + 1)) + 1u;
                      const auto upper = static_cast<std::uintmax_t> (larger);
                      if (upper > std::numeric_limits<std::uintmax_t>::max ()
                                      - magnitude)
                        {
                          overflow = true;
                          return std::numeric_limits<std::uintmax_t>::max ();
                        }
                      return upper + magnitude;
                    }
                }
              return static_cast<std::uintmax_t> (larger)
                     - static_cast<std::uintmax_t> (smaller);
            };

          const std::uintmax_t difference = std::cmp_less (lhs, rhs)
                                                ? distance (rhs, lhs)
                                                : distance (lhs, rhs);
          return !overflow && std::cmp_less_equal (difference, epsilon);
        }
      else
        {
          using float_type = std::common_type_t<Lhs_T, Rhs_T, Epsilon_T>;
          const auto left = static_cast<float_type> (lhs);
          const auto right = static_cast<float_type> (rhs);

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif // defined(__GNUC__)
          // The exact comparison is deliberate, for the infinities.
          const float_type distance
              = (left == right) ? float_type{} : math::abs (left - right);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

          return distance <= static_cast<float_type> (epsilon);
        }
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * The result is computed from the unwrapped arguments, with
     * `detail::differ_by_at_most()`, before the operands are forwarded
     * to the base and the tolerance to its member.
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    template <class L, class R, class E>
    constexpr approx_op<Lhs_T, Rhs_T, Epsilon_T>::approx_op (L&& lhs, R&& rhs,
                                                             E&& epsilon)
        : binary_op<Lhs_T, Rhs_T>{ std::forward<L> (lhs),
                                   std::forward<R> (rhs),
                                   detail::differ_by_at_most (
                                       detail::unwrap (lhs),
                                       detail::unwrap (rhs),
                                       detail::unwrap (epsilon)) },
          epsilon_{ std::forward<E> (epsilon) }
    {
    }

    /**
     * @details
     * Returns the stored tolerance, unwrapped with `detail::unwrap()`.
     */
    template <class Lhs_T, class Rhs_T, class Epsilon_T>
    constexpr decltype (auto)
    approx_op<Lhs_T, Rhs_T, Epsilon_T>::epsilon (void) const
    {
      return detail::unwrap (epsilon_);
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical conjunction `static_cast<bool>(lhs) and
     * static_cast<bool>(rhs)` and passes the result to the `binary_op`
     * base class constructor.
     */
    template <class Lhs_T, class Rhs_T>
    template <class L, class R>
    constexpr and_op<Lhs_T, Rhs_T>::and_op (L&& lhs, R&& rhs)
        : binary_op<Lhs_T, Rhs_T>{ std::forward<L> (lhs),
                                   std::forward<R> (rhs),
                                   static_cast<bool> (lhs)
                                       and static_cast<bool> (rhs) }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical disjunction `static_cast<bool>(lhs) or
     * static_cast<bool>(rhs)` and passes the result to the `binary_op`
     * base class constructor.
     */
    template <class Lhs_T, class Rhs_T>
    template <class L, class R>
    constexpr or_op<Lhs_T, Rhs_T>::or_op (L&& lhs, R&& rhs)
        : binary_op<Lhs_T, Rhs_T>{ std::forward<L> (lhs),
                                   std::forward<R> (rhs),
                                   static_cast<bool> (lhs)
                                       or static_cast<bool> (rhs) }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Evaluates the logical negation `not static_cast<bool>(t)` and
     * passes the result to the `unary_op` base class constructor.
     */
    template <class T>
    template <class U>
      requires (not std::is_same_v<std::remove_cvref_t<U>, not_op<T>>)
    constexpr not_op<T>::not_op (U&& t)
        : unary_op<T>{ std::forward<U> (t), not static_cast<bool> (t) }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Applies the predicate of the tag to the unwrapped operand, and passes
     * the boolean result, with the operand prepared by `as_operand()`, to
     * the `unary_op` base class constructor.
     */
    template <class T, class Predicate_T>
    template <class U>
      requires extension::predicate_tag<Predicate_T, unwrapped_t<U>>
    constexpr predicate_op<T, Predicate_T>::predicate_op (U&& t, Predicate_T)
        : unary_op<T>{ detail::as_operand (std::forward<U> (t)),
                       static_cast<bool> (
                           Predicate_T::apply (detail::unwrap (t))) }
    {
    }

    /**
     * @details
     * Never called; the compilation stops in `reject_predicate_tag()`, with
     * a message that states what the tag needs.
     */
    template <class T, class Predicate_T>
    template <class U>
      requires (not extension::predicate_tag<Predicate_T, unwrapped_t<U>>)
    constexpr predicate_op<T, Predicate_T>::predicate_op (U&& t, Predicate_T)
        : unary_op<T>{ detail::as_operand (std::forward<U> (t)), false }
    {
      detail::reject_predicate_tag<Predicate_T> ();
    }

    // ------------------------------------------------------------------------

#if defined(__cpp_exceptions)

    /**
     * @details
     * Stores the pre-computed boolean result, and, when the check failed,
     * what the invocation threw and the `what()` of the exception.
     */
    inline callable_op::callable_op (callable_result&& result)
        : value_{ result.value }, outcome_{ result.outcome },
          what_{ std::move (result.what) }
    {
    }

    /**
     * @details
     * Returns the result computed by the constructor of the derived
     * operator; the callable is not invoked again.
     */
    constexpr callable_op::
    operator bool () const
    {
      return value_;
    }

    /**
     * @details
     * Returns what was recorded when the check failed.
     */
    inline throw_outcome
    callable_op::outcome (void) const noexcept
    {
      return outcome_;
    }

    /**
     * @details
     * Returns the text recorded when a `std::exception` was thrown.
     */
    inline const std::string&
    callable_op::what (void) const noexcept
    {
      return what_;
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Invokes `func` inside a try/catch block. If `func` throws an
     * exception of type `Exception_T`, the result is `true`; if it throws
     * any other exception the result is `false`; if no exception is thrown
     * the result is `false`. The result is passed to the `callable_op`
     * base class constructor, with what was thrown, if the result is
     * `false`, to be written in the report: nothing, a `std::exception`,
     * with its `what()`, or another exception.
     *
     * The `failed_requirement` thrown to stop the test case after a failed
     * `require()` in `func` is not an exception of `func`, and is
     * rethrown.
     */
    // When `Exception_T` is `std::exception`, or one of its bases, the
    // handler of `std::exception` is unreachable, which is not an error.
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wexceptions"
#endif // defined(__GNUC__)

    template <class Exception_T>
    template <class Callable_T>
      requires std::invocable<Callable_T&>
    throws_op<Exception_T>::throws_op (Callable_T&& func)
        : callable_op{ [&func] () -> callable_result
      {
        try
          {
            func ();
          }
        catch (const failed_requirement&)
          {
            throw;
          }
        catch (const Exception_T&)
          {
            return { true, throw_outcome::none, {} };
          }
        catch (const std::exception& e)
          {
            return { false, throw_outcome::std_exception,
                     e.what () != nullptr ? e.what () : "" };
          }
        catch (...)
          {
            return { false, throw_outcome::unknown_exception, {} };
          }
        return { false, throw_outcome::none, {} };
      }() }
    {
    }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

    // ------------------------------------------------------------------------

    /**
     * @details
     * Invokes `func` inside a try/catch block. If `func` throws any
     * exception the result is `true`; if no exception is thrown the result
     * is `false`. The result is passed to the `callable_op` base class
     * constructor.
     *
     * The `failed_requirement` thrown to stop the test case after a failed
     * `require()` in `func` is not an exception of `func`, and is
     * rethrown.
     */
    template <class Callable_T>
      requires std::invocable<Callable_T&>
    throws_op<void>::throws_op (Callable_T&& func)
        : callable_op{ [&func] () -> callable_result
      {
        try
          {
            func ();
          }
        catch (const failed_requirement&)
          {
            throw;
          }
        catch (...)
          {
            return { true, throw_outcome::none, {} };
          }
        return { false, throw_outcome::none, {} };
      }() }
    {
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Invokes `func` inside a try/catch block. If `func` completes without
     * throwing, the result is `true`; if any exception is thrown the result
     * is `false`. The result is passed to the `callable_op` base class
     * constructor, with what was thrown, if the result is `false`, to be
     * written in the report: a `std::exception`, with its `what()`, or
     * another exception.
     *
     * The `failed_requirement` thrown to stop the test case after a failed
     * `require()` in `func` is not an exception of `func`, and is
     * rethrown.
     */
    template <class Callable_T>
      requires std::invocable<Callable_T&>
    nothrow_op::nothrow_op (Callable_T&& func)
        : callable_op{ [&func] () -> callable_result
      {
        try
          {
            func ();
          }
        catch (const failed_requirement&)
          {
            throw;
          }
        catch (const std::exception& e)
          {
            return { false, throw_outcome::std_exception,
                     e.what () != nullptr ? e.what () : "" };
          }
        catch (...)
          {
            return { false, throw_outcome::unknown_exception, {} };
          }
        return { true, throw_outcome::none, {} };
      }() }
    {
    }

#endif // defined(__cpp_exceptions)

    // ------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wfloat-equal"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

    /**
     * @details
     * The value is formatted into a local buffer, which is then appended
     * to `buffer`.
     *
     * For `long double`, a platform-specific path is chosen:
     * - On Windows and on platforms where `long double` has the same
     *   storage width as `double` (e.g. 32-bit Arm), the value is cast
     *   to `double` and formatted with `std::to_chars`.
     * - On all other platforms (e.g. x86-64 Linux/macOS with 80-bit
     *   extended precision, or AArch64 and RISC-V with 128-bit quad
     *   precision), `snprintf` with `%.*Lg` is used as a portable
     *   fallback, because `std::to_chars` for `long double` may be
     *   unavailable (e.g. when linking with `lld`). The precision starts
     *   at `LDBL_DIG` and is increased until the text reads back, with
     *   `strtold`, as the same value, up to `LDBL_DECIMAL_DIG`, which
     *   always reads back exactly. This gives the shortest exact form,
     *   as `std::to_chars` gives for the other types; a shorter form
     *   would need fewer than `LDBL_DIG` digits, and `%Lg` removes the
     *   trailing zeros, so starting at `LDBL_DIG` does not lose it. For
     *   zero and the subnormal values, which have fewer significant
     *   digits, the precision starts at 1. The value of `errno`, which
     *   `strtold` may set for subnormal values, is preserved. If no
     *   precision reads back exactly, the C library handles `long double`
     *   with the precision of `double` (e.g. newlib on AArch64 and
     *   RISC-V), and the value is cast to `double` and formatted with
     *   `std::to_chars`, as above.
     *
     * For all other numeric types, `std::to_chars` is called directly,
     * providing locale-independent formatting. The `snprintf()` path
     * uses the decimal point of the C locale, which is `.` unless the
     * application changes it with `setlocale()`.
     */
    template <class T>
      requires std::is_arithmetic_v<T>
    void
    append_number (std::string& buffer, const T v)
    {
      if constexpr (std::is_same_v<T, long double>)
        {
#if defined(_WIN32) \
    || (defined(__SIZEOF_LONG_DOUBLE__) \
        && __SIZEOF_LONG_DOUBLE__ == __SIZEOF_DOUBLE__)
          // On Windows (all toolchains: MinGW, Clang, MSVC), the C runtime
          // does not handle the %Lg printf specifier correctly for 80-bit
          // long double, producing garbage output. On platforms where long
          // double has the same width as double (e.g. 32-bit Arm), the cast
          // is lossless. In both cases, cast to double and use
          // std::to_chars.
          char buf[32];
          const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf),
                                                static_cast<double> (v));
          if (ec == std::errc{})
            buffer.append (buf, ptr);
#else
          // On other platforms (80-bit extended precision on x86-64,
          // 128-bit quad precision on AArch64 and RISC-V), std::to_chars
          // for long double may be unavailable (e.g., with lld).
          // Use snprintf as a portable fallback; %Lg is supported by the C
          // libraries used on these platforms (e.g. glibc, the macOS libc,
          // and newlib, the latter with the precision of double on AArch64
          // and RISC-V). Use the smallest precision that reads back as the
          // same value; the buffer fits the 36 digits of the 128-bit
          // format, with the sign, the point, and the exponent.
          char buf[48];
          const int saved_errno = errno;
          // The subnormal values have fewer significant digits.
          const int min_precision
              = (v > -LDBL_MIN && v < LDBL_MIN) ? 1 : LDBL_DIG;
          bool is_exact = false;
          for (int precision = min_precision; precision <= LDBL_DECIMAL_DIG;
               ++precision)
            {
              snprintf (buf, sizeof (buf), "%.*Lg", precision, v);
              // A NaN is never equal to itself, and has no digits.
              if (v != v || strtold (buf, nullptr) == v)
                {
                  is_exact = true;
                  break;
                }
            }
          errno = saved_errno;
          if (is_exact)
            {
              buffer.append (buf);
            }
          else
            {
              // The C library formats or reads long double with the
              // precision of double (e.g. newlib on AArch64 and RISC-V),
              // and its long text would only show the error of the
              // conversion; use the shortest form of the double value,
              // as on the platforms above.
              const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf),
                                                    static_cast<double> (v));
              if (ec == std::errc{})
                buffer.append (buf, ptr);
            }
#endif // long double formatting
        }
      else
        {
          char buf[32];
          const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf), v);
          if (ec == std::errc{})
            buffer.append (buf, ptr);
        }
    }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

    // ------------------------------------------------------------------------

    /**
     * @details
     * Null pointers are rendered as `"0x0"`, regardless of the platform,
     * avoiding platform-specific representations such as `"(nil)"` on
     * Linux/glibc. Non-null pointers are formatted with `snprintf()`,
     * using the `%p` specifier.
     *
     * The `%p` specifier expects a `void*`. Object pointers are converted
     * implicitly to `const volatile void*`, which accepts any
     * qualification, and the qualifiers are then removed with
     * `const_cast`; a `reinterpret_cast` to `void*` would not compile for
     * pointers to `const` objects. The object is not accessed. Function
     * pointers, which do not convert to `void*` implicitly, use
     * `reinterpret_cast`.
     */
    template <class T>
    void
    append_pointer (std::string& buffer, T* v)
    {
      if (v == nullptr)
        {
          buffer.append ("0x0");
          return;
        }

      void* p;
      if constexpr (std::is_function_v<T>)
        {
          p = reinterpret_cast<void*> (v);
        }
      else
        {
          const volatile void* cvp = v;
          p = const_cast<void*> (cvp);
        }

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

      char buf[20];
      snprintf (buf, sizeof (buf), "%p", p);
      buffer.append (buf);

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
    }

    // ========================================================================

    /**
     * @details
     * The length is computed with `std::char_traits<Char_T>::length()`,
     * which, unlike `strlen()`, can be evaluated at compile time.
     */
    template <character Char_T>
    constexpr basic_c_string<Char_T>::basic_c_string (
        const Char_T* str) noexcept
        : str_{ str },
          size_{ str == nullptr ? 0 : std::char_traits<Char_T>::length (str) }
    {
    }

    /**
     * @details
     * The characters are counted up to the first null character, or up to
     * `capacity`.
     */
    template <character Char_T>
    constexpr basic_c_string<Char_T>::basic_c_string (
        const Char_T* str, std::size_t capacity) noexcept
        : str_{ str }, size_{ capacity }
    {
      // Search within the array only; the view avoids indexing the raw
      // pointer.
      const std::size_t terminator
          = std::basic_string_view<Char_T>{ str, capacity }.find (Char_T{});
      if (terminator != std::basic_string_view<Char_T>::npos)
        {
          size_ = terminator;
        }
    }

    /**
     * @details
     * Returns an empty view for a null pointer.
     */
    template <character Char_T>
    constexpr std::basic_string_view<Char_T>
    basic_c_string<Char_T>::view (void) const noexcept
    {
      return str_ == nullptr ? std::basic_string_view<Char_T>{}
                             : std::basic_string_view<Char_T>{ str_, size_ };
    }

    /**
     * @details
     * Returns whether the stored pointer is null.
     */
    template <character Char_T>
    constexpr bool
    basic_c_string<Char_T>::is_null (void) const noexcept
    {
      return str_ == nullptr;
    }

    /**
     * @details
     * Two null pointers are equal; a null pointer is not equal to any
     * string, not even an empty one.
     */
    template <character Char_T>
    constexpr bool
    operator== (const basic_c_string<Char_T>& lhs,
                const basic_c_string<Char_T>& rhs) noexcept
    {
      if (lhs.is_null () || rhs.is_null ())
        {
          return lhs.is_null () && rhs.is_null ();
        }
      return lhs.view () == rhs.view ();
    }

    /**
     * @details
     * A null pointer is not equal to any string.
     */
    template <character Char_T>
    constexpr bool
    operator== (
        const basic_c_string<Char_T>& lhs,
        std::type_identity_t<std::basic_string_view<Char_T>> rhs) noexcept
    {
      return !lhs.is_null () && lhs.view () == rhs;
    }

    /**
     * @details
     * Returns whether the operand is a null pointer.
     */
    template <character Char_T>
    constexpr bool
    operator== (const basic_c_string<Char_T>& lhs, std::nullptr_t) noexcept
    {
      return lhs.is_null ();
    }

    /**
     * @details
     * A null pointer orders before any string.
     */
    template <character Char_T>
    constexpr std::strong_ordering
    operator<=> (const basic_c_string<Char_T>& lhs,
                 const basic_c_string<Char_T>& rhs) noexcept
    {
      if (lhs.is_null () || rhs.is_null ())
        {
          return !lhs.is_null () <=> !rhs.is_null ();
        }
      return lhs.view () <=> rhs.view ();
    }

    /**
     * @details
     * A null pointer orders before any string.
     */
    template <character Char_T>
    constexpr std::strong_ordering
    operator<=> (
        const basic_c_string<Char_T>& lhs,
        std::type_identity_t<std::basic_string_view<Char_T>> rhs) noexcept
    {
      if (lhs.is_null ())
        {
          return std::strong_ordering::less;
        }
      return lhs.view () <=> rhs;
    }

    /**
     * @details
     * Stores the pointer and the count; nothing is copied.
     */
    template <class T>
    constexpr array_operand<T>::array_operand (const T* first,
                                               std::size_t count) noexcept
        : first_{ first }, count_{ count }
    {
    }

    /**
     * @details
     * Returns the stored pointer.
     */
    template <class T>
    constexpr const T*
    array_operand<T>::begin (void) const noexcept
    {
      return first_;
    }

    // ------------------------------------------------------------------------
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

    /**
     * @details
     * Returns the pointer past the last element.
     */
    template <class T>
    constexpr const T*
    array_operand<T>::end (void) const noexcept
    {
      return first_ + count_;
    }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)
    // ------------------------------------------------------------------------

    /**
     * @details
     * Ranges of different sizes are not equal, without comparing any
     * element. The elements are compared as the scalar operands of
     * `eq ()` are, with `equal_to::apply ()`, so that integers of different
     * signedness are compared by value, not by converting the signed one to
     * the unsigned type.
     */
    template <class T, class R>
      requires (container_like<R>
                and std::equality_comparable_with<
                    T, typename range_element<R>::type>)
    constexpr bool
    operator== (const array_operand<T>& lhs, const R& rhs)
    {
      return std::equal (lhs.begin (), lhs.end (), rhs.begin (), rhs.end (),
                         [] (const auto& l, const auto& r)
        { return equal_to::apply (l, r); });
    }

    /**
     * @details
     * A range that is a prefix of the other is the lesser one.
     */
    template <class T, class R>
      requires (container_like<R>
                and std::three_way_comparable_with<
                    T, typename range_element<R>::type>)
    constexpr auto
    operator<=> (const array_operand<T>& lhs, const R& rhs)
    {
      return std::lexicographical_compare_three_way (lhs.begin (), lhs.end (),
                                                     rhs.begin (), rhs.end ());
    }

    // ------------------------------------------------------------------------

    /**
     * @details
     * Arrays of the character types are converted using their size as a
     * bound, pointers to them using the null terminator; the
     * cv-qualifiers of the characters are ignored. The other arrays are
     * converted to
     * `array_operand`. Every other operand is forwarded, unchanged, as an
     * lvalue or an rvalue reference.
     */
    template <class T>
    constexpr auto
    as_operand (T&& t) noexcept -> decltype (auto)
    {
      using type = std::remove_cvref_t<T>;

      if constexpr (std::is_array_v<type>
                    && character<std::remove_extent_t<type>>)
        {
          return basic_c_string<std::remove_cv_t<std::remove_extent_t<type>>>{
            t, std::extent_v<type>
          };
        }
      else if constexpr (std::is_pointer_v<type>
                         && character<std::remove_pointer_t<type>>)
        {
          return basic_c_string<std::remove_cv_t<std::remove_pointer_t<type>>>{
            t
          };
        }
      else if constexpr (std::is_array_v<type>)
        {
          // Other arrays (e.g. byte buffers) are compared by content.
          return array_operand<std::remove_extent_t<type>>{
            static_cast<const std::remove_extent_t<type>*> (t),
            std::extent_v<type>
          };
        }
      else if constexpr (std::is_function_v<type>)
        {
          // Functions are compared by address, as function pointers.
          return &t;
        }
      else
        {
          return std::forward<T> (t);
        }
    }

    // ------------------------------------------------------------------------

  } // namespace detail

  // --------------------------------------------------------------------------

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DETAIL_INLINES_H_

// ----------------------------------------------------------------------------
