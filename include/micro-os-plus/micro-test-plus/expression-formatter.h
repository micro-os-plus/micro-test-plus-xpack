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
 * @brief C++ header file with declarations for the µTest++ expression
 * formatter.
 *
 * @details
 * This header provides the `expression_formatter` class, which encapsulates
 * all value-formatting logic used by the µTest++ framework. The class owns
 * a `std::string` buffer and exposes `operator<<` overloads for every
 * standard arithmetic type, character type, string, pointer, container,
 * and framework expression type derived from `detail::op`.
 *
 * By consolidating the formatting operators into a single class (using the
 * shared `detail::append_number_()` helper for numbers), the `reporter` is
 * relieved of those responsibilities, and `detail::deferred_reporter` can
 * pre-format expression text at construction time without requiring
 * `reporter` or `subtest` to be complete at that point.
 *
 * The formatter shares the colour configuration of the owning `reporter`:
 * comparator expressions are wrapped in pass/fail colour codes, which are
 * empty strings unless the reporter enables colours.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "type-traits.h"
#include "detail.h"

#include <charconv>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <string_view>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace detail
  {
    // ------------------------------------------------------------------------

    /**
     * @struct colours
     * @brief Colours used to highlight pass and fail results in test reports.
     *
     * @details
     * The `colours` structure defines ANSI escape sequences for terminal
     * output, enabling colour-coded highlighting of test outcomes. The `pass`
     * member specifies the colour for successful results (typically green),
     * while the `fail` member specifies the colour for failed results
     * (typically red). The `none` member resets the colour to the terminal
     * default.
     *
     * By default all members are empty strings, so no escape sequences are
     * emitted; reporters that support colours assign `colours_red_green`.
     *
     * @var colours::none
     * ANSI escape sequence to reset the terminal colour to default.
     * @var colours::pass
     * ANSI escape sequence to set the terminal colour for passing results
     * (green).
     * @var colours::fail
     * ANSI escape sequence to set the terminal colour for failing results
     * (red).
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    struct colours
    {
      const char* none = ""; /**< @brief Terminal colour reset sequence. */
      const char* pass
          = ""; /**< @brief Terminal colour sequence for passing tests. */
      const char* fail
          = ""; /**< @brief Terminal colour sequence for failing tests. */
    };

    /**
     * @brief Predefined colour set, with green for pass and red for fail.
     *
     * @details
     * Assigned by reporters that output to a colour-capable terminal; the
     * members are, in order, the reset, pass, and fail ANSI escape
     * sequences.
     */
    inline constexpr colours colours_red_green = {
      "\033[0m", /**< @brief Terminal colour reset sequence. */
      "\033[32m", /**< @brief Green colour sequence for passing tests. */
      "\033[31m" /**< @brief Red colour sequence for failing tests. */
    };

    // ========================================================================

    /**
     * @brief Formats values and expressions into an owned string buffer.
     *
     * @details
     * `expression_formatter` owns a `std::string` buffer and provides
     * `operator<<` overloads for all standard arithmetic types, character
     * types, strings, pointers, containers, and framework expression types
     * derived from `detail::op`.
     *
     * The numeric overloads append a type suffix (e.g., `42u`, `3l`, `1.5f`)
     * matching the conventions used in the existing reporter output, so that
     * the formatted text is identical whether produced by the reporter
     * directly or pre-formatted by a deferred reporter.
     *
     * The class is non-copyable and non-movable to avoid accidental copying
     * of the internal buffer.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class expression_formatter
    {
    public:
      /**
       * @brief Constructor with colour configuration.
       *
       * @param colours Reference to a `colours` instance for output
       * formatting; it must outlive the formatter.
       */
      expression_formatter (colours& colours) noexcept;

      /**
       * @brief Deleted copy constructor to prevent copying.
       *
       * @details
       * The formatter is owned by a reporter and refers to its colours.
       */
      expression_formatter (const expression_formatter&) = delete;

      /**
       * @brief Deleted move constructor to prevent moving.
       *
       * @details
       * The formatter is owned by a reporter and refers to its colours.
       */
      expression_formatter (expression_formatter&&) = delete;

      /**
       * @brief Deleted copy assignment operator to prevent copying.
       *
       * @details
       * The formatter is owned by a reporter and refers to its colours.
       */
      expression_formatter&
      operator= (const expression_formatter&)
          = delete;

      /**
       * @brief Deleted move assignment operator to prevent moving.
       *
       * @details
       * The formatter is owned by a reporter and refers to its colours.
       */
      expression_formatter&
      operator= (expression_formatter&&)
          = delete;

      /**
       * @brief Default destructor.
       *
       * @details
       * Releases the internal buffer; the referenced colours are not owned.
       */
      ~expression_formatter () = default;

      // ----------------------------------------------------------------------
      // Primitive operator<< overloads.

      /**
       * @brief Appends a string view to the buffer.
       *
       * @param sv The string view to append.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (std::string_view sv);

      /**
       * @brief Appends a single character to the buffer.
       *
       * @param c The character to append.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (char c);

      /**
       * @brief Appends a null-terminated C string to the buffer.
       *
       * @details
       * Also selected for the non-const `char` pointers and arrays, which
       * the pointer template does not accept. A null pointer is rendered
       * as `"nullptr"`.
       *
       * @param s The C string to append, or a null pointer.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (const char* s);

      /**
       * @brief Appends a C string operand of a comparator.
       *
       * @param s The operand.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (const c_string_& s);

      /**
       * @brief Appends the string representation of a boolean value.
       *
       * @param v The boolean value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (bool v);

      /**
       * @brief Appends the string `"nullptr"`.
       *
       * @return Reference to this instance.
       */
      expression_formatter& operator<< (std::nullptr_t);

      /**
       * @brief Appends a signed char value with type suffix `"c"`.
       *
       * @param c The signed char value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (signed char c);

      /**
       * @brief Appends an unsigned char value with type suffix `"uc"`.
       *
       * @param c The unsigned char value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (unsigned char c);

      /**
       * @brief Appends a signed short value with type suffix `"s"`.
       *
       * @param v The signed short value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (signed short v);

      /**
       * @brief Appends an unsigned short value with type suffix `"us"`.
       *
       * @param v The unsigned short value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (unsigned short v);

      /**
       * @brief Appends a signed int value (no suffix).
       *
       * @param v The signed int value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (signed int v);

      /**
       * @brief Appends an unsigned int value with type suffix `"u"`.
       *
       * @param v The unsigned int value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (unsigned int v);

      /**
       * @brief Appends a signed long value with type suffix `"l"`.
       *
       * @param v The signed long value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (signed long v);

      /**
       * @brief Appends an unsigned long value with type suffix `"ul"`.
       *
       * @param v The unsigned long value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (unsigned long v);

      /**
       * @brief Appends a signed long long value with type suffix `"ll"`.
       *
       * @param v The signed long long value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (signed long long v);

      /**
       * @brief Appends an unsigned long long value with type suffix `"ull"`.
       *
       * @param v The unsigned long long value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (unsigned long long v);

      /**
       * @brief Appends a float value with type suffix `"f"`.
       *
       * @param v The float value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (float v);

      /**
       * @brief Appends a double value (no suffix).
       *
       * @param v The double value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (double v);

      /**
       * @brief Appends a long double value with type suffix `"l"`.
       *
       * @param v The long double value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (long double v);

      // ----------------------------------------------------------------------
      // Template operator<< overloads.

      /**
       * @brief Appends the hexadecimal address of a pointer.
       *
       * @details
       * Null pointers are rendered as `"0x0"`. Non-null pointers are
       * formatted with `snprintf` using the `%p` specifier.
       *
       * The `char` pointers are excluded, so that they are written as
       * strings by the `const char*` overload, as the `const char`
       * pointers are; the `signed char` and `unsigned char` pointers,
       * usually byte buffers, are written as addresses.
       *
       * @tparam T The type pointed to, other than `char`.
       * @param v The pointer value.
       * @return Reference to this instance.
       */
      template <typename T>
        requires (not std::is_same_v<T, char>)
      expression_formatter&
      operator<< (T* v);

      /**
       * @brief Appends the value of an op expression via `detail::unwrap_()`.
       *
       * @tparam T An expression type satisfying `type_traits::is_op<T>`.
       * @param t The expression object.
       * @return Reference to this instance.
       */
      template <class T>
        requires type_traits::is_op<T>
      expression_formatter&
      operator<< (const T& t);

      /**
       * @brief Appends a genuine integral value without a type suffix.
       *
       * @tparam T The underlying integral type.
       * @param v The strongly-typed integral value.
       * @return Reference to this instance.
       */
      template <class T>
      expression_formatter&
      operator<< (const detail::genuine_integral_value<T>& v);

      /**
       * @brief Appends a container's elements enclosed in braces.
       *
       * @details
       * Elements are formatted as `{ e1, e2, … }` by iterating the
       * container and recursing through `operator<<` for each element.
       *
       * @tparam T A container type satisfying `type_traits::container_like`
       * that does not have `npos`.
       * @param t The container.
       * @return Reference to this instance.
       */
      template <class T>
        requires (type_traits::container_like<T>
                  and not type_traits::has_npos<T>)
      expression_formatter&
      operator<< (const T& t);

      // ----------------------------------------------------------------------
      // Compound expression operator<< overloads (with pass/fail colours).

      /**
       * @brief Formats an equality comparison as `lhs == rhs`.
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @param op The equality expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T>
      expression_formatter&
      operator<< (const detail::eq_<Lhs_T, Rhs_T>& op);

      /**
       * @brief Formats an inequality comparison as `lhs != rhs`.
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @param op The inequality expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T>
      expression_formatter&
      operator<< (const detail::ne_<Lhs_T, Rhs_T>& op);

      /**
       * @brief Formats a greater-than comparison as `lhs > rhs`.
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @param op The greater-than expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T>
      expression_formatter&
      operator<< (const detail::gt_<Lhs_T, Rhs_T>& op);

      /**
       * @brief Formats a greater-than-or-equal comparison as `lhs >= rhs`.
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @param op The greater-than-or-equal expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T>
      expression_formatter&
      operator<< (const detail::ge_<Lhs_T, Rhs_T>& op);

      /**
       * @brief Formats a less-than comparison as `lhs < rhs`.
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @param op The less-than expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T>
      expression_formatter&
      operator<< (const detail::lt_<Rhs_T, Lhs_T>& op);

      /**
       * @brief Formats a less-than-or-equal comparison as `lhs <= rhs`.
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @param op The less-than-or-equal expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T>
      expression_formatter&
      operator<< (const detail::le_<Rhs_T, Lhs_T>& op);

      /**
       * @brief Formats a logical AND as `(lhs and rhs)`.
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @param op The logical AND expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T>
      expression_formatter&
      operator<< (const detail::and_<Lhs_T, Rhs_T>& op);

      /**
       * @brief Formats a logical OR as `(lhs or rhs)`.
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @param op The logical OR expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T>
      expression_formatter&
      operator<< (const detail::or_<Lhs_T, Rhs_T>& op);

      /**
       * @brief Formats a logical NOT as `not operand`.
       *
       * @tparam T The operand type.
       * @param op The logical NOT expression.
       * @return Reference to this instance.
       */
      template <class T>
      expression_formatter&
      operator<< (const detail::not_<T>& op);

#if defined(__cpp_exceptions)

      /**
       * @brief Formats a typed throws expression as
       * `throws<TypeName>`.
       *
       * @tparam Callable_T The callable type.
       * @tparam Exception_T The expected exception type.
       * @param op The throws expression.
       * @return Reference to this instance.
       */
      template <class Callable_T, class Exception_T>
      expression_formatter&
      operator<< (const detail::throws_<Callable_T, Exception_T>& op);

      /**
       * @brief Formats an untyped throws expression as `throws`.
       *
       * @tparam Callable_T The callable type.
       * @param op The throws expression.
       * @return Reference to this instance.
       */
      template <class Callable_T>
      expression_formatter&
      operator<< (const detail::throws_<Callable_T, void>& op);

      /**
       * @brief Formats a nothrow expression as `nothrow`.
       *
       * @tparam Callable_T The callable type.
       * @param op The nothrow expression.
       * @return Reference to this instance.
       */
      template <class Callable_T>
      expression_formatter&
      operator<< (const detail::nothrow_<Callable_T>& op);

#endif // defined(__cpp_exceptions)

      // ----------------------------------------------------------------------
      // Buffer accessors.

      /**
       * @brief Returns a const reference to the internal buffer.
       *
       * @par Parameters
       *   None.
       * @return Const reference to the accumulated string.
       */
      [[nodiscard]] const std::string&
      str () const noexcept;

      /**
       * @brief Returns a pointer to the null-terminated buffer contents.
       *
       * @par Parameters
       *   None.
       * @return Pointer to the null-terminated character array.
       */
      [[nodiscard]] const char*
      c_str () const noexcept;

      /**
       * @brief Clears the internal buffer.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      void
      clear () noexcept;

      /**
       * @brief Returns whether the internal buffer is empty.
       *
       * @par Parameters
       *   None.
       * @retval true  The buffer contains no characters.
       * @retval false The buffer contains at least one character.
       */
      [[nodiscard]] bool
      empty () const noexcept;

      /**
       * @brief Appends a sequence of identical characters to the buffer.
       *
       * @param count The number of characters to append.
       * @param ch The character to repeat.
       * @par Returns
       *   Nothing.
       */
      void
      append (size_t count, char ch);

      /**
       * @brief Reserves storage in the internal buffer.
       *
       * @param capacity The minimum capacity to reserve.
       * @par Returns
       *   Nothing.
       */
      void
      reserve (size_t capacity);

      // ----------------------------------------------------------------------
      // Ownership by the checks.

      /**
       * @brief Prepares the buffer for the expression of a new check.
       *
       * @details
       * If the text in the buffer belongs to a check that was not reported
       * yet (its result was kept in a variable), the text is first moved
       * aside, so that this check can still report it. The buffer is then
       * cleared and assigned to @p owner.
       *
       * @param owner The check that will format its expression next.
       * @par Returns
       *   Nothing.
       */
      void
      begin_check (const void* owner);

      /**
       * @brief Returns the expression text of a check.
       *
       * @param owner The check that formatted the expression.
       * @return The text in the buffer, if it still belongs to @p owner,
       * otherwise the text moved aside for it; it remains valid until
       * `end_check()`.
       */
      [[nodiscard]] const std::string&
      check_text (const void* owner) const noexcept;

      /**
       * @brief Releases the expression text of a check, after it was
       * reported.
       *
       * @param owner The check that formatted the expression.
       * @par Returns
       *   Nothing.
       */
      void
      end_check (const void* owner) noexcept;

    protected:
      /**
       * @brief Selects the appropriate colour code based on a condition.
       *
       * @param cond Boolean value indicating pass (true) or fail (false).
       * @return The corresponding ANSI colour code as a string.
       */
      [[nodiscard]] inline auto
      colour_ (const bool cond) const;

      /**
       * @brief ANSI colour codes for output formatting.
       *
       * @details
       * A reference to the colours of the owning reporter, so that later
       * changes (e.g. enabling colours) are picked up automatically.
       */
      colours& colours_;

      /**
       * @brief The internal output buffer.
       *
       * @details
       * Accumulates the formatted text; cleared with `clear()`.
       */
      std::string buffer_{};

      /**
       * @brief The check whose expression is in the buffer.
       *
       * @details
       * Set by `begin_check()` and reset by `end_check()`; `nullptr` when
       * the text in the buffer does not belong to a pending check.
       */
      const void* owner_{ nullptr };

      /**
       * @brief The expression texts of the pending checks whose buffer was
       * reused.
       *
       * @details
       * Normally empty: a check is reported at the end of its statement,
       * before the next check begins. Only when the result of a check is
       * kept in a variable does a later check move its text here, keyed by
       * the check, so that the check objects themselves do not need to own
       * a copy, which would increase the stack usage of the test functions.
       */
      std::vector<std::pair<const void*, std::string>> pending_{};
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------

  /**
   * @ingroup micro-os-plus-micro-test-plus-function-comparators
   * @brief Public name of the formatter used to report operand values.
   *
   * @details
   * The function comparators and the custom operators report the values
   * of their operands when a check fails. Values of user-defined types
   * can be reported only if the application provides an `operator<<`
   * that writes them to this formatter, declared in the namespace of the
   * type, so that it is found by argument-dependent lookup:
   *
   * @code{.cpp}
   * namespace app
   * {
   *   struct point
   *   {
   *     int x;
   *     int y;
   *   };
   *
   *   constexpr bool
   *   operator== (const point& lhs, const point& rhs)
   *   {
   *     return lhs.x == rhs.x && lhs.y == rhs.y;
   *   }
   *
   *   inline mt::expression_formatter&
   *   operator<< (mt::expression_formatter& formatter, const point& p)
   *   {
   *     return formatter << "{ " << p.x << ", " << p.y << " }";
   *   }
   * } // namespace app
   * @endcode
   *
   * Without such an operator, comparators such as `eq()` do not compile
   * for user-defined types, since the operand values cannot be
   * formatted. Plain boolean checks, such as `expect (a == b)`, do not
   * need it, but they report only the source location on failure.
   *
   * Only the public `operator<<` overloads of the formatter are intended
   * for use by applications; the rest of the class is an implementation
   * detail.
   */
  using expression_formatter = detail::expression_formatter;

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/expression-formatter-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_

// ----------------------------------------------------------------------------
