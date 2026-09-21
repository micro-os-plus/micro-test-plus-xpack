/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/*
 * The `_sbrk()` implementation below is copied, with only cosmetic
 * formatting changes, from the Raspberry Pi Pico SDK
 * (`src/rp2_common/pico_clib_interface/newlib_interface.c`), reused here
 * because this platform does not link the SDK's `pico_clib_interface`
 * (it provides its own µOS++ startup/runtime instead):
 *
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// ----------------------------------------------------------------------------

#define false 0

extern char __StackLimit; /* Set by linker.  */

__attribute__ ((weak)) void*
_sbrk (int incr)
{
  extern char end; /* Set by linker.  */
  static char* heap_end;
  char* prev_heap_end;

  if (heap_end == 0)
    heap_end = &end;

  prev_heap_end = heap_end;
  char* next_heap_end = heap_end + incr;

  if (__builtin_expect (next_heap_end > (&__StackLimit), false))
    {
#if PICO_USE_OPTIMISTIC_SBRK
      if (heap_end == &__StackLimit)
        {
          //        errno = ENOMEM;
          return (char*)-1;
        }
      next_heap_end = &__StackLimit;
#else
      return (char*)-1;
#endif
    }

  heap_end = next_heap_end;
  return (void*)prev_heap_end;
}

// ----------------------------------------------------------------------------
