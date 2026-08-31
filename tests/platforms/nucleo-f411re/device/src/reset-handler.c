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

#include "micro-os-plus/device.h"

#include <stdint.h>

// ----------------------------------------------------------------------------

typedef void (*handler_ptr_t) (void);

extern handler_ptr_t _interrupt_vectors[];

extern void __attribute__ ((noreturn, weak))
_start (void);

// ----------------------------------------------------------------------------

// Begin address for the initialisation values of the .data section.
extern uintptr_t __data_load_addr__;
// Begin address for the .data section.
extern uintptr_t __data_begin__;
// End address for the .data section.
extern uintptr_t __data_end__;

extern uint32_t __stack;

// ----------------------------------------------------------------------------

void __attribute__ ((section (".after_vectors"), noreturn, naked))
Reset_Handler (void);

// QEMU sets SP to the first word in flash.
void
Reset_Handler (void)
{
  // For just in case, when started via a debugger.
  __asm__ (" MSR msp, %0 " : : "r"(&__stack) :);
  // cortexm_architecture_set_msp(&__stack);

  // SCB
  // https://developer.arm.com/documentation/dui0552/a/cortex-m3-peripherals/system-control-block

  // SCB->VTOR
  // https://developer.arm.com/documentation/dui0552/a/cortex-m3-peripherals/system-control-block/vector-table-offset-register
  // Mandatory when running from RAM. Not available on Cortex-M0.
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) \
    || defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__)
  // *((uint32_t*)0xE000ED08)
  SCB->VTOR = ((uint32_t)_interrupt_vectors & (uint32_t)(~0x3F));
#endif // defined(__ARM_ARCH_7M__) ...

  // Floating point instructions can be used early in the startup sequence
  // as a result of compiler optimisations, therefore enable the FPU before
  // calling any functions. (`SystemInit()` happens too late).
#if (defined(__FPU_USED) && (__FPU_USED == 1U)) \
    || (defined(__ARM_FEATURE_MVE) && (__ARM_FEATURE_MVE > 0U))
  // Enable CP10 and CP11 coprocessor.
  SCB->CPACR |= ((3U << 10U * 2U) | /* enable CP10 Full Access */
                 (3U << 11U * 2U)); /* enable CP11 Full Access */

  // Lazy save.
  FPU->FPCCR |= FPU_FPCCR_ASPEN_Msk | FPU_FPCCR_LSPEN_Msk;
#endif // defined (__FPU_USED) ...

  SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk | SCB_SHCSR_BUSFAULTENA_Msk
                | SCB_SHCSR_MEMFAULTENA_Msk;

  _start ();
}

// ----------------------------------------------------------------------------
