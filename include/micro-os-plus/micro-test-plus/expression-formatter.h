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
 * scoped enumeration, pair, tuple, optional, and framework expression
 * type (see `extension::is_op`).
 *
 * By consolidating the formatting operators into a single class (using the
 * shared `detail::append_number()` helper for numbers), the `reporter` is
 * relieved of those responsibilities, and `detail::check_result` can
 * pre-format expression text at construction time without requiring
 * `reporter` or `test_case` to be complete at that point.
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

#include "detail.h"
#include "extension.h"

#include <charconv>
#include <cstdio>
#include <optional>
#include <string>
#include <tuple>
#include <type_traits>
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
    // Forward definitions.
    class check_result;

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
     * types, strings, pointers, containers, scoped enumerations (including
     * `std::byte`), pairs, tuples, optionals, and framework expression
     * types (see `extension::is_op`).
     *
     * The numeric overloads append a type suffix named after the µTest++
     * literals (e.g., `42u`, `3l`, `5sc`, `1.5f`, `1.5ld`); `int` and
     * `double` have no suffix, and the floating-point values always have
     * a decimal point or an exponent (`42.0`), so that they can be
     * distinguished from the integers.
     *
     * The class is non-copyable and non-movable to avoid accidental copying
     * of the internal buffer.
     *
     * Apart from the constructor, the public members are the
     * `operator<<` overloads and the read-only `str()`, so that the
     * application `operator<<` functions for user-defined types can only
     * append text. The functions that assign the buffer to a check, and
     * return and release its text, are private, and called only by
     * `check_result`, a friend; an application function calling them
     * would corrupt the texts of the pending checks.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class expression_formatter
    {
      // Assign the buffer to the checks, and report their texts.
      friend class check_result;

    public:
      /**
       * @brief Constructor with colour configuration.
       *
       * @param colours Reference to a `colours` instance for output
       * formatting; it must outlive the formatter.
       */
      expression_formatter (const colours& colours) noexcept;

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
       * @brief Appends a character, as a quoted literal, to the buffer.
       *
       * @details
       * The character is written between single quotes, with the
       * non-printable characters escaped (`'a'`, `' '`, `'\\0'`,
       * `'\\x1b'`), so that it can be identified in the reports. To
       * write a separator without quotes, use a string (`" "`).
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
      operator<< (const c_string& s);

      /**
       * @brief Appends the name of a named boolean constant.
       *
       * @details
       * The constant, created by the `_b` literal, is reported by its
       * name, not by its value, which is always `true`.
       *
       * @param b The named boolean constant.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (const named_bool& b);

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
       * @brief Appends the string `"nullopt"`.
       *
       * @details
       * Selected for `std::nullopt`, so that an optional value can be
       * compared with it (`eq (opt, std::nullopt)`).
       *
       * @return Reference to this instance.
       */
      expression_formatter& operator<< (std::nullopt_t);

      /**
       * @brief Appends a signed char value with type suffix `"sc"`.
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
       * @details
       * An integral value is written with a decimal point (`42.0f`).
       *
       * @param v The float value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (float v);

      /**
       * @brief Appends a double value (no suffix).
       *
       * @details
       * An integral value is written with a decimal point (`42.0`), to
       * distinguish it from an `int`.
       *
       * @param v The double value.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (double v);

      /**
       * @brief Appends a long double value with type suffix `"ld"`.
       *
       * @details
       * An integral value is written with a decimal point (`42.0ld`).
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
       * @brief Appends the value of a framework value wrapper via
       * `detail::unwrap()`.
       *
       * @details
       * Only the wrappers with a `get()` accessor (the `to_*` wrappers and
       * the literals) are accepted. Any other type satisfying
       * `extension::is_op` must have its own overload, as the built-in
       * expressions and `extension::compare_op` and
       * `extension::predicate_op` have; without it, `detail::unwrap()`
       * would return the expression itself, and this overload would call
       * itself without end, so such a type is rejected at compile time.
       *
       * @tparam T A value wrapper type satisfying `extension::is_op<T>`,
       * with a `get()` accessor.
       * @param t The value wrapper.
       * @return Reference to this instance.
       */
      template <class T>
        requires (extension::is_op<T> and requires (const T& v) { v.get (); })
      expression_formatter&
      operator<< (const T& t);

      /**
       * @brief Appends a container's elements enclosed in braces.
       *
       * @details
       * Elements are formatted as `{ e1, e2, … }` by iterating the
       * container and recursing through `operator<<` for each element.
       *
       * @tparam T A container type satisfying `detail::container_like`
       * that does not have `npos`.
       * @param t The container.
       * @return Reference to this instance.
       */
      template <class T>
        requires (detail::container_like<T> and not detail::has_npos<T>)
      expression_formatter&
      operator<< (const T& t);

      /**
       * @brief Appends the underlying value of a scoped enumeration.
       *
       * @details
       * The value is converted to the underlying type and formatted as
       * that type, with its suffix (for example `1` for an `int` and
       * `1uc` for `std::byte`, whose underlying type is `unsigned char`).
       *
       * The unscoped enumerations are not selected, since they convert
       * implicitly to an integer, and are formatted as one.
       *
       * An `operator<<` defined by the application for an enumeration,
       * for example to write the names of the enumerators, is preferred
       * to this template.
       *
       * @tparam T A scoped enumeration type.
       * @param v The enumeration value.
       * @return Reference to this instance.
       */
      template <class T>
        requires (std::is_enum_v<T>
                  and not std::is_convertible_v<T, std::underlying_type_t<T>>)
      expression_formatter&
      operator<< (T v);

      /**
       * @brief Appends the members of a pair, as `(first, second)`.
       *
       * @details
       * Each member is formatted through `operator<<`, so the pairs
       * stored in the maps are also formatted, as `{(1, 2), (3, 4)}`.
       *
       * @tparam T1 The type of the first member.
       * @tparam T2 The type of the second member.
       * @param p The pair.
       * @return Reference to this instance.
       */
      template <class T1, class T2>
      expression_formatter&
      operator<< (const std::pair<T1, T2>& p);

      /**
       * @brief Appends the elements of a tuple, as `(e1, e2, …)`.
       *
       * @details
       * Each element is formatted through `operator<<`; an empty tuple is
       * written as `()`.
       *
       * @tparam Ts The types of the elements.
       * @param t The tuple.
       * @return Reference to this instance.
       */
      template <class... Ts>
      expression_formatter&
      operator<< (const std::tuple<Ts...>& t);

      /**
       * @brief Appends the value of an optional, or `nullopt`.
       *
       * @details
       * A value is formatted through `operator<<`, as the contained type,
       * so an optional with a value is written as the value alone; an
       * optional without a value is written as `nullopt`.
       *
       * @tparam T The type of the contained value.
       * @param o The optional.
       * @return Reference to this instance.
       */
      template <class T>
      expression_formatter&
      operator<< (const std::optional<T>& o);

      // ----------------------------------------------------------------------
      // Compound expression operator<< overloads (with pass/fail colours).

      /**
       * @brief Formats a relational comparison as `lhs op rhs`.
       *
       * @details
       * The operator symbol is taken from the tag (for example `==` for
       * `detail::equal_to`).
       *
       * @tparam Lhs_T Left-hand operand type.
       * @tparam Rhs_T Right-hand operand type.
       * @tparam Compare_T The tag that defines the comparison.
       * @param op The comparison expression.
       * @return Reference to this instance.
       */
      template <class Lhs_T, class Rhs_T, class Compare_T>
      expression_formatter&
      operator<< (const detail::compare_op<Lhs_T, Rhs_T, Compare_T>& op);

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
      operator<< (const detail::and_op<Lhs_T, Rhs_T>& op);

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
      operator<< (const detail::or_op<Lhs_T, Rhs_T>& op);

      /**
       * @brief Formats a logical NOT as `not operand`.
       *
       * @tparam T The operand type.
       * @param op The logical NOT expression.
       * @return Reference to this instance.
       */
      template <class T>
      expression_formatter&
      operator<< (const detail::not_op<T>& op);

      /**
       * @brief Formats a unary predicate as `symbol operand`.
       *
       * @details
       * The symbol is the one of the tag, written as defined by the
       * application, so it includes the separating space.
       *
       * @tparam T The operand type.
       * @tparam Predicate_T The tag that defines the predicate.
       * @param op The predicate expression.
       * @return Reference to this instance.
       */
      template <class T, class Predicate_T>
      expression_formatter&
      operator<< (const detail::predicate_op<T, Predicate_T>& op);

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
      operator<< (const detail::throws_op<Callable_T, Exception_T>& op);

      /**
       * @brief Formats an untyped throws expression as `throws`.
       *
       * @tparam Callable_T The callable type.
       * @param op The throws expression.
       * @return Reference to this instance.
       */
      template <class Callable_T>
      expression_formatter&
      operator<< (const detail::throws_op<Callable_T, void>& op);

      /**
       * @brief Formats a nothrow expression as `nothrow`.
       *
       * @tparam Callable_T The callable type.
       * @param op The nothrow expression.
       * @return Reference to this instance.
       */
      template <class Callable_T>
      expression_formatter&
      operator<< (const detail::nothrow_op<Callable_T>& op);

#endif // defined(__cpp_exceptions)

      // ----------------------------------------------------------------------

      /**
       * @brief Returns the text written to the formatter.
       *
       * @details
       * Intended for testing the application `operator<<` functions with
       * a formatter constructed for this purpose; since the formatter only
       * appends, the text of each value starts where the previous one
       * ended. The text cannot be modified through this reference.
       *
       * @par Parameters
       *   None.
       * @return Const reference to the accumulated string.
       */
      [[nodiscard]] const std::string&
      str (void) const noexcept;

    private:
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

      // ----------------------------------------------------------------------

      /**
       * @brief Selects the appropriate colour code based on a condition.
       *
       * @param cond Boolean value indicating pass (true) or fail (false).
       * @return The corresponding ANSI colour code as a string.
       */
      [[nodiscard]] inline auto
      colour_ (const bool cond) const;

      /**
       * @brief Adds a decimal point to a floating-point value formatted
       * as an integer.
       *
       * @details
       * Called after a floating-point value was appended to the buffer;
       * `".0"` is appended only if the value was written with digits
       * only.
       *
       * @param start The position in the buffer where the value begins.
       * @par Returns
       *   Nothing.
       */
      void
      append_decimal_point_ (std::size_t start);

      /**
       * @brief Appends the elements of a tuple-like object, separated by
       * commas.
       *
       * @details
       * Shared by the pair and tuple overloads; the elements are obtained
       * with `std::get<Is>()` and formatted through `operator<<`, without
       * the enclosing parentheses.
       *
       * @tparam Tuple_T A type accepted by `std::get` (a pair or a tuple).
       * @tparam Is The indices of the elements.
       * @param t The tuple-like object.
       * @par Returns
       *   Nothing.
       */
      template <class Tuple_T, std::size_t... Is>
      void
      append_elements_ (const Tuple_T& t, std::index_sequence<Is...>);

      /**
       * @brief ANSI colour codes for output formatting.
       *
       * @details
       * A reference to the colours of the owning reporter, so that later
       * changes (e.g. enabling colours) are picked up automatically.
       */
      const colours& colours_;

      /**
       * @brief The internal output buffer.
       *
       * @details
       * Accumulates the formatted text; cleared by `begin_check()`.
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
   * formatted; only the scoped enumerations are formatted without it,
   * by their underlying value. Plain boolean checks, such as `expect (a == b)`, do not
   * need it, but they report only the source location on failure.
   *
   * Applications use the `operator<<` overloads, and `str()` to test
   * their own operators; the functions that manage the buffer are
   * private to the framework.
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
