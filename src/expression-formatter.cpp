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

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include "micro-os-plus/micro-test-plus/expression-formatter.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

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
   * Appends the single character @p c to the internal buffer using
   * `buffer_.append(1, c)`.
   */
  expression_formatter&
  expression_formatter::operator<< (char c)
  {
    buffer_.append (1, c);
    return *this;
  }

  /**
   * @details
   * Appends the null-terminated C string @p s to the internal buffer
   * using `buffer_.append(s)`.
   */
  expression_formatter&
  expression_formatter::operator<< (const char* s)
  {
    buffer_.append (s);
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
   * `append_number_()` and appends the type suffix `"c"`.
   */
  expression_formatter&
  expression_formatter::operator<< (signed char c)
  {
    detail::append_number_ (buffer_, c);
    buffer_.append ("c");
    return *this;
  }

  /**
   * @details
   * Converts @p c to its decimal string representation via
   * `append_number_()` and appends the type suffix `"uc"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned char c)
  {
    detail::append_number_ (buffer_, c);
    buffer_.append ("uc");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number_()` and appends the type suffix `"s"`.
   */
  expression_formatter&
  expression_formatter::operator<< (signed short v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("s");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number_()` and appends the type suffix `"us"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned short v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("us");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number_()` without a type suffix.
   */
  expression_formatter&
  expression_formatter::operator<< (signed int v)
  {
    detail::append_number_ (buffer_, v);
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number_()` and appends the type suffix `"u"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned int v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("u");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number_()` and appends the type suffix `"l"`.
   */
  expression_formatter&
  expression_formatter::operator<< (signed long v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("l");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number_()` and appends the type suffix `"ul"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned long v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("ul");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number_()` and appends the type suffix `"ll"`.
   */
  expression_formatter&
  expression_formatter::operator<< (signed long long v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("ll");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its decimal string representation via
   * `append_number_()` and appends the type suffix `"ull"`.
   */
  expression_formatter&
  expression_formatter::operator<< (unsigned long long v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("ull");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number_()`
   * and appends the type suffix `"f"`.
   */
  expression_formatter&
  expression_formatter::operator<< (float v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("f");
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number_()`
   * without a type suffix.
   */
  expression_formatter&
  expression_formatter::operator<< (double v)
  {
    detail::append_number_ (buffer_, v);
    return *this;
  }

  /**
   * @details
   * Converts @p v to its string representation via `append_number_()`
   * and appends the type suffix `"l"`.
   */
  expression_formatter&
  expression_formatter::operator<< (long double v)
  {
    detail::append_number_ (buffer_, v);
    buffer_.append ("l");
    return *this;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------
