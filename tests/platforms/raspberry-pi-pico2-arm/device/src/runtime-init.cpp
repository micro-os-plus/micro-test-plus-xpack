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

#include "pico/runtime.h"
#include "pico/runtime_init.h"
#include "micro-os-plus/startup.h"
#include "micro-os-plus/diag/trace.h"

// ----------------------------------------------------------------------------

extern "C"

{
  void
  runtime_init (void)
  {
    // This custom runtime_init() replaces the SDK's own staged
    // dispatcher (the PICO_RUNTIME_INIT_FUNC_* chain in
    // pico_runtime_init/runtime_init.c), so none of those steps run
    // unless called explicitly here. In particular, the FPU coprocessor
    // (CP10) is never enabled otherwise, which faults with a UsageFault
    // (CFSR NOCP) the moment code executes a floating-point instruction,
    // e.g. formatting a float/double in printf.
    runtime_init_per_core_enable_coprocessors ();

    micro_os_plus_startup_run_main ();
  }

#if defined(NDEBUG)
  void
  hard_assertion_failure (void)
  {
    micro_os_plus_trace_puts ("Hard assert");
    while (1)
      {
      }
  }
#endif // defined(NDEBUG)
}

// ----------------------------------------------------------------------------
