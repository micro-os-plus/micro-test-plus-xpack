/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

// The POSIX functions required by some of the frameworks measured by the
// footprint programs (Catch2, GoogleTest, and Boost.Test), and not provided
// by the bare-metal platforms. They do the minimum required for the tests
// to run: there is no random source, no file system, and no clock.
//
// They are defined only with newlib, the C library of the bare-metal
// toolchains; on the native platforms, the C library provides the real
// functions, which must not be replaced.
//
// To build Boost.Test, also define `_POSIX_MONOTONIC_CLOCK=200112L` and
// `_POSIX_TIMERS=1`, so that newlib declares `CLOCK_MONOTONIC` and
// `clock_gettime()`.

// ----------------------------------------------------------------------------

#include <errno.h>
#include <stddef.h>
#include <sys/types.h>
#include <time.h>

// ----------------------------------------------------------------------------

#if defined(_NEWLIB_VERSION)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wreserved-identifier"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

// Used by Catch2, to seed its random generator; there is no entropy source.
int
_getentropy (void* buffer, size_t length)
{
  (void)buffer;
  (void)length;

  errno = ENOSYS;
  return -1;
}

// Used by GoogleTest, which aborts if it cannot get the current folder;
// return the root folder.
char*
getcwd (char* buffer, size_t size)
{
  if (buffer == NULL || size < 2)
    {
      errno = ERANGE;
      return NULL;
    }

  buffer[0] = '/';
  buffer[1] = '\0';
  return buffer;
}

// Used by GoogleTest, to create the folders of the output files; there is no
// file system.
int
mkdir (const char* path, mode_t mode)
{
  (void)path;
  (void)mode;

  errno = ENOSYS;
  return -1;
}

// Used by Boost.Test, to time the tests; there is no clock, the time is
// always zero.
int
clock_gettime (clockid_t clock_id, struct timespec* tp)
{
  (void)clock_id;

  tp->tv_sec = 0;
  tp->tv_nsec = 0;
  return 0;
}

// ----------------------------------------------------------------------------

#endif // defined(_NEWLIB_VERSION)

// ----------------------------------------------------------------------------
