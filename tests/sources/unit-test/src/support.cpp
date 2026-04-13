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

#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
void __attribute__ ((noreturn))
local_test_assert (const char* failedexpr, const char* file, int line)
{
  fprintf (stdout, "\nassertion \"%s\" failed\n", failedexpr);
  fprintf (stdout, "file: \"%s\"\n", file);
  fprintf (stdout, "line: %d\n", line);

  fprintf (stdout, "\nµTest++ unit test failed!\n\n");

  abort ();
  /* NOTREACHED */
}
#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
