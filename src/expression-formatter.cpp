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

  namespace
  {
    /**
     * @brief Appends an escape and a fixed number of hexadecimal digits.
     *
     * @details
     * Used by `expression_formatter::append_character()`; the digits are
     * lowercase, the most significant first, and the leading zeros are
     * kept, so that the number of digits shows the size of the type.
     *
     * @param buffer The text to which the escape is appended.
     * @param code The value to write.
     * @param escape The escape before the digits (`"\\x"`, `"\\u"`, or
     * `"\\U"`).
     * @param count The number of digits.
     * @par Returns
     *   Nothing.
     */
    void
    append_hex (std::string& buffer, char32_t code, std::string_view escape,
                std::size_t count)
    {
      constexpr std::string_view digits{ "0123456789abcdef" };
      buffer.append (escape);
      for (std::size_t i = count; i > 0; --i)
        {
          // The promoted type of `code` is `std::size_t` on some
          // platforms, so a cast would be reported as useless.
          const auto nibble = (code >> ((i - 1) * 4)) & 0x0Fu;
          buffer.push_back (digits[nibble]);
        }
    }
  } // namespace

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
   * quotes, by `append_character()`, so that the spaces and the control
   * characters are visible, and a zero does not end the text when it is
   * printed as a C string. The values above `0x7F` (for example the
   * bytes of the UTF-8 sequences) are written as two hexadecimal digits
   * (`'\\xc3'`).
   *
   * In the plain mode, used for the messages, the character is appended
   * unchanged, as text, without quotes and escapes.
   */
  expression_formatter&
  expression_formatter::operator<< (char c)
  {
    if (plain_)
      {
        buffer_.push_back (c);
        return *this;
      }

    append_character ("", static_cast<unsigned char> (c), sizeof (c));
    return *this;
  }

#if defined(__cpp_char8_t)
  /**
   * @details
   * Written by `append_character()` with the `u8` prefix, also in the
   * plain mode.
   */
  expression_formatter&
  expression_formatter::operator<< (char8_t c)
  {
    append_character ("u8", static_cast<char32_t> (c), sizeof (c));
    return *this;
  }
#endif // defined(__cpp_char8_t)

  /**
   * @details
   * Written by `append_character()` with the `u` prefix, also in the
   * plain mode.
   */
  expression_formatter&
  expression_formatter::operator<< (char16_t c)
  {
    append_character ("u", static_cast<char32_t> (c), sizeof (c));
    return *this;
  }

  /**
   * @details
   * Written by `append_character()` with the `U` prefix, also in the
   * plain mode.
   */
  expression_formatter&
  expression_formatter::operator<< (char32_t c)
  {
    append_character ("U", c, sizeof (c));
    return *this;
  }

  /**
   * @details
   * Written by `append_character()` with the `L` prefix, also in the
   * plain mode. The value is first converted to the unsigned type of
   * the same size, so that a negative value is not sign-extended to
   * 32 bits.
   */
  expression_formatter&
  expression_formatter::operator<< (wchar_t c)
  {
    append_character ("L", static_cast<std::make_unsigned_t<wchar_t>> (c),
                      sizeof (c));
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
   * Appends the string `"nullopt"` to the internal buffer; also used by
   * the `std::optional` template for the optionals without a value.
   */
  expression_formatter&
  expression_formatter::operator<< (std::nullopt_t)
  {
    buffer_.append ("nullopt");
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
    append_suffix ("sc");
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
    append_suffix ("uc");
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
    append_suffix ("s");
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
    append_suffix ("us");
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
    append_suffix ("u");
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
    append_suffix ("l");
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
    append_suffix ("ul");
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
    append_suffix ("ll");
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
    append_suffix ("ull");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number()`,
   * adds the decimal point if needed (via `append_decimal_point()`),
   * and appends the type suffix `"f"`.
   */
  expression_formatter&
  expression_formatter::operator<< (float v)
  {
    const auto start = buffer_.size ();
    detail::append_number (buffer_, v);
    append_decimal_point (start);
    append_suffix ("f");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number()`
   * and adds the decimal point if needed (via `append_decimal_point()`),
   * without a type suffix.
   */
  expression_formatter&
  expression_formatter::operator<< (double v)
  {
    const auto start = buffer_.size ();
    detail::append_number (buffer_, v);
    append_decimal_point (start);
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number()`,
   * adds the decimal point if needed (via `append_decimal_point()`),
   * and appends the type suffix `"ld"`, the name of the `_ld` literal;
   * the C++ suffix `"l"` would suggest `long`.
   */
  expression_formatter&
  expression_formatter::operator<< (long double v)
  {
    const auto start = buffer_.size ();
    detail::append_number (buffer_, v);
    append_decimal_point (start);
    append_suffix ("ld");
    return *this;
  }

  /**
   * @details
   * The shortest representation of a floating-point value with an
   * integral value has no decimal point (`42.0` is formatted as `42`),
   * so it cannot be distinguished from an integer. If the text appended
   * since @p start contains only digits, after an optional sign, `".0"`
   * is appended. The text with a decimal point or an exponent, and the
   * infinities and NaNs, are left unchanged, as is all text in the plain
   * mode, used for the messages.
   */
  void
  expression_formatter::append_decimal_point (std::size_t start)
  {
    if (plain_)
      {
        return;
      }
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

  /**
   * @details
   * Appends @p suffix, unless the formatter is in the plain mode, used
   * for the messages, which writes the numbers without suffixes.
   */
  void
  expression_formatter::append_suffix (const char* suffix)
  {
    if (not plain_)
      {
        buffer_.append (suffix);
      }
  }

  /**
   * @details
   * A value of an 8-bit type above `0x7F` is a part of a multi-byte
   * sequence; for the wider types, the surrogates (`0xD800` to `0xDFFF`)
   * and the values above `0x10FFFF` are not Unicode characters, and
   * cannot be written as universal character names. They are written
   * with `\\x` and twice as many hexadecimal digits as the bytes of the
   * type, so that the width of the type is visible. The control
   * characters keep the two digits of `char`, since they are the same in
   * all the encodings.
   */
  void
  expression_formatter::append_character (std::string_view prefix,
                                          char32_t code, std::size_t size)
  {
    buffer_.append (prefix);
    buffer_.push_back ('\'');
    switch (code)
      {
      case U'\0':
        buffer_.append ("\\0");
        break;
      case U'\a':
        buffer_.append ("\\a");
        break;
      case U'\b':
        buffer_.append ("\\b");
        break;
      case U'\t':
        buffer_.append ("\\t");
        break;
      case U'\n':
        buffer_.append ("\\n");
        break;
      case U'\v':
        buffer_.append ("\\v");
        break;
      case U'\f':
        buffer_.append ("\\f");
        break;
      case U'\r':
        buffer_.append ("\\r");
        break;
      case U'\'':
        buffer_.append ("\\'");
        break;
      case U'\\':
        buffer_.append ("\\\\");
        break;
      default:
        if (code < 0x20 || code == 0x7F)
          {
            append_hex (buffer_, code, "\\x", 2);
          }
        else if (code < 0x7F)
          {
            buffer_.push_back (static_cast<char> (code));
          }
        else if (size == 1 || (code >= 0xD800 && code <= 0xDFFF)
                 || code > 0x10FFFF)
          {
            append_hex (buffer_, code, "\\x", size * 2);
          }
        else if (code <= 0xFFFF)
          {
            append_hex (buffer_, code, "\\u", 4);
          }
        else
          {
            append_hex (buffer_, code, "\\U", 8);
          }
        break;
      }
    buffer_.push_back ('\'');
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
