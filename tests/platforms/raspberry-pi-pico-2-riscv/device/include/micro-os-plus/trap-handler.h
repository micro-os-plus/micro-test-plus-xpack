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

#ifndef MICRO_OS_PLUS_TRAP_HANDLER_H_
#define MICRO_OS_PLUS_TRAP_HANDLER_H_

// ----------------------------------------------------------------------------

// This is a C++ only header; do not include it from C translation units.
#if defined(__cplusplus)

namespace device
{
  // Install a minimal Direct-mode `mtvec` trap handler.
  //
  // No test running on this platform arms a real interrupt source (the
  // LED is polled GPIO, the clocks are one-shot register pokes at
  // startup, and semihosting goes through the debug probe), so this
  // exists purely as a safety net that catches any unexpected
  // exception/interrupt and halts, rather than running off into
  // whatever `mtvec` happens to reset to. It deliberately does not
  // implement Hazard3's vectored `mtvec` mode or its
  // `meiea`/`meipa`/`meifa`/`meinext` external-interrupt-array
  // dispatch, since nothing here needs real interrupt handling.
  //
  // Must be called before any code that could trap runs; see
  // src/hooks.cpp's `micro_os_plus_startup_initialise_hardware_early_hook()`.
  void
  install_trap_handler (void);
} // namespace device

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_TRAP_HANDLER_H_

// ----------------------------------------------------------------------------
