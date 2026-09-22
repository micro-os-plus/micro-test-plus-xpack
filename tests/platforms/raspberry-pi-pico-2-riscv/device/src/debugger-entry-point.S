/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2017-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

#define __ASSEMBLY__ 1
#include "micro-os-plus/architecture.h"

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wundef"
#endif // defined(__GNUC__)
#include "pico/bootrom_constants.h"
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

// Required to satisfy the linker script definitions:
// ENTRY(_debugger_entry_point)

// On RISC-V there are no custom initialisations to be done when the
// application is started by a debugger, so generally this can go directly 
// to the reset.

// For platforms that use a bootstrap, like the pico 2, that need to jump 
// to the bootstrap, reimplement this function in the project.

    .section  .debugger_entry_point, "ax", @progbits
    .align    2 // number of low order zeros, i.e. align to a multiple of 4

    .globl    _debugger_entry_point
    .type     _debugger_entry_point, @function

_debugger_entry_point:

    li        a0, BOOTROM_ENTRY_OFFSET
    jr        a0

// ----------------------------------------------------------------------------
