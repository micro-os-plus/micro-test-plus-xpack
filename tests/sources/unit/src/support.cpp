/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

#include "unit-test.h"

#include <cstddef>
#include <cstdlib>
#include <new>

#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

void __attribute__ ((noreturn))
local_test_assert (const char* failedexpr, const char* file, int line)
{
  fprintf (stderr, "\nassertion \"%s\" failed\n", failedexpr);
  fprintf (stderr, "file: \"%s\"\n", file);
  fprintf (stderr, "line: %d\n", line);

  fprintf (stderr, "\nµTest++ unit test failed!\n\n");

  abort ();
  /* NOTREACHED */
}

// ----------------------------------------------------------------------------

std::size_t allocations_count = 0;

// The replacements of the global allocation and deallocation functions,
// which count the allocations; the default array forms call them. They
// are defined here, and not in the file that uses the counter, since GCC
// inlines them there and then warns that `free()` is called for memory
// returned by `operator new` (`-Wmismatched-new-delete`).
void*
operator new (std::size_t size)
{
  ++allocations_count;
  void* pointer = std::malloc (size == 0 ? 1 : size);
  if (pointer == nullptr)
    {
#if defined(__cpp_exceptions)
      throw std::bad_alloc{};
#else
      std::abort ();
#endif // defined(__cpp_exceptions)
    }
  return pointer;
}

void
operator delete (void* pointer) noexcept
{
  std::free (pointer);
}

void
operator delete (void* pointer, std::size_t) noexcept
{
  std::free (pointer);
}

// ----------------------------------------------------------------------------
