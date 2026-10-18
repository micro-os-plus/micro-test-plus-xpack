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
 * @brief C++ source file with non-template implementations for the µTest++
 * expression formatter.
 *
 * @details
 * This source file contains the non-template `operator<<` overloads of
 * `expression_formatter` for all standard arithmetic, character, string,
 * boolean, and null-pointer types. Each overload appends the formatted
 * value — together with an appropriate type suffix where applicable — to
 * the internal string buffer.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/expression-formatter.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus::detail
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Appends the contents of the `std::string_view` directly to the
   * internal buffer using `buffer_.append(sv)`.
   */
  expression_formatter&
  expression_formatter::operator<< (std::string_view sv)
  {
    buffer_.append (sv);
    return *this;
  }

  /**
   * @details
   * The character is written as a C++ character literal, between single
   * quotes, so that the spaces and the control characters are visible,
   * and a zero does not end the text when it is printed as a C string.
   * The usual escape sequences are used for `'\\0'`, `'\\a'`, `'\\b'`,
   * `'\\t'`, `'\\n'`, `'\\v'`, `'\\f'`, `'\\r'`, `'\\''`, and `'\\\\'`;
   * the other control characters, `DEL`, and the values above `0x7F`
   * (for example the bytes of the UTF-8 sequences) are written as two
   * hexadecimal digits (`'\\x1b'`). The printable ASCII characters are
   * written unchanged.
   */
  expression_formatter&
  expression_formatter::operator<< (char c)
  {
    buffer_.push_back ('\'');
    switch (c)
      {
      case '\0':
        buffer_.append ("\\0");
        break;
      case '\a':
        buffer_.append ("\\a");
        break;
      case '\b':
        buffer_.append ("\\b");
        break;
      case '\t':
        buffer_.append ("\\t");
        break;
      case '\n':
        buffer_.append ("\\n");
        break;
      case '\v':
        buffer_.append ("\\v");
        break;
      case '\f':
        buffer_.append ("\\f");
        break;
      case '\r':
        buffer_.append ("\\r");
        break;
      case '\'':
        buffer_.append ("\\'");
        break;
      case '\\':
        buffer_.append ("\\\\");
        break;
      default:
        {
          const auto code = static_cast<unsigned char> (c);
          if (code < 0x20 || code >= 0x7F)
            {
              constexpr std::string_view digits{ "0123456789abcdef" };
              buffer_.append ("\\x");
              buffer_.push_back (digits[static_cast<std::size_t> (code >> 4)]);
              buffer_.push_back (
                  digits[static_cast<std::size_t> (code & 0x0F)]);
            }
          else
            {
              buffer_.push_back (c);
            }
        }
        break;
      }
    buffer_.push_back ('\'');
    return *this;
  }

  /**
   * @details
   * Appends the null-terminated C string @p s to the internal buffer
   * using `buffer_.append(s)`, or `"nullptr"` for a null pointer, as the
   * `c_string` overload does; the `char*` values also reach this
   * overload, and `std::string::append()` must not be called with a
   * null pointer.
   */
  expression_formatter&
  expression_formatter::operator<< (const char* s)
  {
    if (s == nullptr)
      {
        buffer_.append ("nullptr");
      }
    else
      {
        buffer_.append (s);
      }
    return *this;
  }

  /**
   * @details
   * Appends the characters of the string, or `"nullptr"` for a null
   * pointer, as the other operator overloads do for these values.
   */
  expression_formatter&
  expression_formatter::operator<< (const c_string& s)
  {
    if (s.is_null ())
      {
        buffer_.append ("nullptr");
      }
    else
      {
        buffer_.append (s.view ());
      }
    return *this;
  }

  /**
   * @details
   * Appends the name, as the `std::string_view` overload does, so that
   * the comparison is reported with the name instead of `true`.
   */
  expression_formatter&
  expression_formatter::operator<< (const named_bool& b)
  {
    buffer_.append (b.name ());
    return *this;
  }

  /**
   * @details
   * Appends the string `"true"` or `"false"` to the internal buffer
   * based on the value of @p v.
   */
  expression_formatter&
  expression_formatter::operator<< (bool v)
  {
    buffer_.append (v ? "true" : "false");
    return *this;
  }

  /**
   * @details
   * Appends the string `"nullptr"` to the internal buffer.
   */
  expression_formatter&
  expression_formatter::operator<< (std::nullptr_t)
  {
    buffer_.append ("nullptr");
    return *this;
  }

  /**
   * @details
   * Converts @p c to its decimal string representation via
   * `append_number()` and appends the type suffix `"sc"`, the name of
   * the `_sc` literal; the suffix `"c"` would suggest `char`, which is
   * written as a character.
   */
  expression_formatter&
  expression_formatter::operator<< (signed char c)
  {
    detail::append_number (buffer_, c);
    buffer_.append ("sc");
    return *this;
  }

  /**
   * @details
   * Converts @p c to its decimal string representation via
   * `append_number()` and appends the type suffix `"uc"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned char c)
  {
    detail::append_number (buffer_, c);
    buffer_.append ("uc");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number()` and appends the type suffix `"s"`.
   */
  expression_formatter&
  expression_formatter::operator<< (signed short v)
  {
    detail::append_number (buffer_, v);
    buffer_.append ("s");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number()` and appends the type suffix `"us"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned short v)
  {
    detail::append_number (buffer_, v);
    buffer_.append ("us");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number()` without a type suffix.
   */
  expression_formatter&
  expression_formatter::operator<< (signed int v)
  {
    detail::append_number (buffer_, v);
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number()` and appends the type suffix `"u"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned int v)
  {
    detail::append_number (buffer_, v);
    buffer_.append ("u");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number()` and appends the type suffix `"l"`.
   */
  expression_formatter&
  expression_formatter::operator<< (signed long v)
  {
    detail::append_number (buffer_, v);
    buffer_.append ("l");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number()` and appends the type suffix `"ul"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned long v)
  {
    detail::append_number (buffer_, v);
    buffer_.append ("ul");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number()` and appends the type suffix `"ll"`.
   */
  expression_formatter&
  expression_formatter::operator<< (signed long long v)
  {
    detail::append_number (buffer_, v);
    buffer_.append ("ll");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number()` and appends the type suffix `"ull"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned long long v)
  {
    detail::append_number (buffer_, v);
    buffer_.append ("ull");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number()`,
   * adds the decimal point if needed (via `append_decimal_point_()`),
   * and appends the type suffix `"f"`.
   */
  expression_formatter&
  expression_formatter::operator<< (float v)
  {
    const auto start = buffer_.size ();
    detail::append_number (buffer_, v);
    append_decimal_point_ (start);
    buffer_.append ("f");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number()`
   * and adds the decimal point if needed (via `append_decimal_point_()`),
   * without a type suffix.
   */
  expression_formatter&
  expression_formatter::operator<< (double v)
  {
    const auto start = buffer_.size ();
    detail::append_number (buffer_, v);
    append_decimal_point_ (start);
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number()`,
   * adds the decimal point if needed (via `append_decimal_point_()`),
   * and appends the type suffix `"ld"`, the name of the `_ld` literal;
   * the C++ suffix `"l"` would suggest `long`.
   */
  expression_formatter&
  expression_formatter::operator<< (long double v)
  {
    const auto start = buffer_.size ();
    detail::append_number (buffer_, v);
    append_decimal_point_ (start);
    buffer_.append ("ld");
    return *this;
  }

  /**
   * @details
   * The shortest representation of a floating-point value with an
   * integral value has no decimal point (`42.0` is formatted as `42`),
   * so it cannot be distinguished from an integer. If the text appended
   * since @p start contains only digits, after an optional sign, `".0"`
   * is appended. The text with a decimal point or an exponent, and the
   * infinities and NaNs, are left unchanged.
   */
  void
  expression_formatter::append_decimal_point_ (std::size_t start)
  {
    if (start < buffer_.size ()
        && (buffer_[start] == '-' || buffer_[start] == '+'))
      {
        ++start;
      }
    if (start == buffer_.size ())
      {
        return;
      }
    for (auto i = start; i < buffer_.size (); ++i)
      {
        if (buffer_[i] < '0' || buffer_[i] > '9')
          {
            return;
          }
      }
    buffer_.append (".0");
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * In the usual case, the previous check was already reported (its
   * `end_check()` reset `owner_`), and the buffer is only cleared,
   * keeping its capacity. Otherwise the text of the previous, still
   * pending, check is moved into `pending_`.
   */
  void
  expression_formatter::begin_check (const void* owner)
  {
    if (owner_ != nullptr)
      {
        pending_.emplace_back (owner_, std::move (buffer_));
      }

    buffer_.clear ();
    owner_ = owner;
  }

  /**
   * @details
   * Searches `pending_` only when the buffer belongs to another check.
   * If the check is not found (which does not happen when the calls are
   * paired), an empty string is returned.
   */
  const std::string&
  expression_formatter::check_text (const void* owner) const noexcept
  {
    if (owner == owner_)
      {
        return buffer_;
      }

    for (size_t i = 0; i < pending_.size (); ++i)
      {
        if (pending_[i].first == owner)
          {
            return pending_[i].second;
          }
      }

    static const std::string empty{};
    return empty;
  }

  /**
   * @details
   * If the buffer belongs to @p owner, it is released (and reused by the
   * next check); otherwise the text moved aside for @p owner is removed
   * from `pending_`, by moving the last entry into its place.
   */
  void
  expression_formatter::end_check (const void* owner) noexcept
  {
    if (owner == owner_)
      {
        owner_ = nullptr;
        return;
      }

    // Use indices and `swap()` + `pop_back()` (both returning void) rather
    // than iterators and `erase()`, which returns an iterator object and
    // triggers -Waggregate-return; the order of the entries is irrelevant.
    for (size_t i = 0; i < pending_.size (); ++i)
      {
        if (pending_[i].first == owner)
          {
            if (i + 1 != pending_.size ())
              {
                pending_[i].swap (pending_.back ());
              }
            pending_.pop_back ();
            return;
          }
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------
