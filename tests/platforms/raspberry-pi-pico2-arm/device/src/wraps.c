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
#include "micro-os-plus/device.h"
#include "micro-os-plus/startup.h"
#include "micro-os-plus/diag/trace.h"

// ----------------------------------------------------------------------------

void
__wrap_main (void)
{
  // `pico_clib_interface` is not linked, so the SDK's own `runtime_init()`
  // (which would otherwise call this) is never linked in either; only
  // `pico_crt0`'s empty weak stub runs. Without this call, the VFP
  // coprocessor is never enabled, and the first floating-point
  // instruction (e.g. in `printf`) faults with a UsageFault/NOCP.
  runtime_init_per_core_enable_coprocessors ();

  // The SDK's implementation only writes CPACR, without the barriers
  // ARM's enable-FPU sequence requires; without them, an FP instruction
  // fetched before the CPACR write takes effect (e.g. in the prologue of
  // the very next call, under the hard-float ABI) can still fault.
  __DSB ();
  __ISB ();

  // Call the µOS++ startup code to do some more initialisations,
  // prepare the semihosting environment, run static initializers,
  // then main() with argc/argv parameters and exit(code).
  // Note: requires MICRO_OS_PLUS_STARTUP_CALL_REAL_MAIN_ENABLED.
  micro_os_plus_startup_run_main ();

  while (1)
    {
      __WFI (); // Wait For Interrupt
    }
}

void
__wrap__libc_init_array (void)
{
  // Silence this call, the static initializers are later called in the
  // micro_os_plus_startup_run_main() right before calling main().
}

#if defined(NDEBUG)
void
hard_assertion_failure (void)
{
  micro_os_plus_trace_puts ("Hard assert");
  while (1)
    {
      __WFI (); // Wait For Interrupt
    }
}
#endif // defined(NDEBUG)

// ----------------------------------------------------------------------------
