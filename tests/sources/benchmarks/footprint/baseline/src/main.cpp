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

// The reference of the footprint programs: an empty program, with no test
// framework. Its size is that of the platform code (the startup, the
// semihosting support) and of the parts of the C and C++ libraries that the
// platform code links. The footprint of each framework is the difference
// between the size of its program and the size of this one.

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  (void)argc;
  (void)argv;

  return 0;
}

// ----------------------------------------------------------------------------
