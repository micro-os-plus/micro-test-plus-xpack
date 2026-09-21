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

#include "pico/runtime.h"
#include "pico/runtime_init.h"
#include "micro-os-plus/device.h"
#include "micro-os-plus/startup.h"
#include "micro-os-plus/diag/trace.h"

// ----------------------------------------------------------------------------

// Declared (.global, not .weak) in crt0_riscv.S, part of pico_crt0 (always
// linked here, unlike pico_runtime); calling it directly by name -- rather
// than overriding the .weak runtime_init() crt0_riscv.S also provides --
// avoids a multiple-definition conflict should some other configuration of
// this platform ever also link pico_runtime, which supplies its own
// runtime_init(). Clears the Hazard3 IRQ-force-array bits, enables only
// mie.MEIE (external IRQs; timer/software IRQ enables stay clear), sets
// mstatus.MIE, and clears mscratch. Normally called from the full
// pico_runtime dispatcher's runtime_init(), which this platform does not
// link (same minimal-SDK approach as the Arm-sdk sibling, which calls its
// own analogous gap, runtime_init_per_core_enable_coprocessors(), the same
// way, right here).
extern void
runtime_init_per_core_h3_irq_registers (void);

void
__wrap_main (void)
{
  runtime_init_per_core_h3_irq_registers ();

  // Call the µOS++ startup code to do some more initialisations,
  // prepare the semihosting environment, run static initializers,
  // then main() with argc/argv parameters and exit(code).
  // Note: requires MICRO_OS_PLUS_STARTUP_CALL_REAL_MAIN_ENABLED.
  micro_os_plus_startup_run_main ();

#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)
  micro_os_plus_architecture_brk ();
#endif
  while (1)
    {
      micro_os_plus_architecture_wfi ();
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

#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)
  micro_os_plus_architecture_brk ();
#endif
  while (1)
    {
      micro_os_plus_architecture_wfi ();
    }
}
#endif // defined(NDEBUG)

// ----------------------------------------------------------------------------
