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
 * By consolidating the formatting operators and their shared `append_number_`
 * helper into a single class, the `reporter` is relieved of those
 * responsibilities, and `detail::deferred_reporter` can pre-format expression
 * text at construction time without requiring `reporter` or `subtest` to be
 * complete at that point.
 *
 * Colour-code processing is intentionally excluded from this class; it
 * remains the responsibility of the owning `reporter`.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_
#define MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <charconv>
#include <cstdio>
#include <string>
#include <string_view>

#include "type-traits.h"
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
     * These colour codes enhance the clarity and professionalism of test
     * reports by making it immediately apparent which tests have passed or
     * failed, thereby improving the overall user experience when reviewing
     * test results.
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
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    struct colours
    {
      const char* none = ""; /**< @brief Terminal colour reset sequence. */
      const char* pass
          = ""; /**< @brief Terminal colour sequence for passing tests. */
      const char* fail
          = ""; /**< @brief Terminal colour sequence for failing tests. */
    };

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
     * The numeric overloads append a type suffix (e.g., `42u`, `3l`, `1.0f`)
     * matching the conventions used in the existing reporter output, so that
     * the formatted text is identical whether produced by the reporter
     * directly or pre-formatted by a deferred reporter.
     *
     * The class is non-copyable and non-movable to avoid accidental copying
     * of the internal buffer.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    class expression_formatter
    {
    public:
      /**
       * @brief Constructor with colour configuration.
       *
       * @param colours Reference to a `colours` instance for output
       * formatting.
       */
      expression_formatter (colours& colours) noexcept;

      /**
       * @brief Deleted copy constructor to prevent copying.
       */
      expression_formatter (const expression_formatter&) = delete;

      /**
       * @brief Deleted move constructor to prevent moving.
       */
      expression_formatter (expression_formatter&&) = delete;

      /**
       * @brief Deleted copy assignment operator to prevent copying.
       */
      expression_formatter&
      operator= (const expression_formatter&)
          = delete;

      /**
       * @brief Deleted move assignment operator to prevent moving.
       */
      expression_formatter&
      operator= (expression_formatter&&)
          = delete;

      /**
       * @brief Default destructor.
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
       * @param s The C string to append.
       * @return Reference to this instance.
       */
      expression_formatter&
      operator<< (const char* s);

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
       * @tparam T The type pointed to.
       * @param v The pointer value.
       * @return Reference to this instance.
       */
      template <typename T>
      expression_formatter&
      operator<< (T* v);

      /**
       * @brief Appends the value of an op expression via `detail::get`.
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
      operator<< (const type_traits::genuine_integral_value<T>& v);

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
      // Compound expression operator<< overloads (without colour).

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
#endif

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
       */
      colours& colours_;

      /**
       * @brief The internal output buffer.
       */
      std::string buffer_{};
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ============================================================================
// Templates & constexpr implementations.

#include "inlines/expression-formatter-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_EXPRESSION_FORMATTER_H_

// ----------------------------------------------------------------------------
