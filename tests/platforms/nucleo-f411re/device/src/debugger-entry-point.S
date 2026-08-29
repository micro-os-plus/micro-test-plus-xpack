/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2014-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

.type _debugger_entry_point,%function
.thumb_func
.global _debugger_entry_point

_debugger_entry_point:
    ldr r1, =0xE000ED08 // VTOR
    str r0, [r1]
    ldmia r0!, {r1, r2}
    msr msp, r1
    bx r2

// ----------------------------------------------------------------------------
