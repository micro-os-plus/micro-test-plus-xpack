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

/*
 * The RP2350 boot ROM does not accept a plain vector table at the start of
 * flash; it requires a small PICOBIN "block" (a self-describing sequence of
 * items, bracketed by start/end markers) to be present within the first
 * 4 KiB of the image, identifying it as an executable (`IMAGE_DEF`). With
 * no explicit `ENTRY_POINT`/`VECTOR_TABLE` items (as here), the boot ROM
 * falls back to using the vector table at the very start of the image,
 * which is exactly where the linker places `_interrupt_vectors`
 * (see vectors-rp2350.c).
 *
 * This mirrors, in C, the minimal block the Pico SDK's own
 * `pico_crt0/embedded_start_block.inc.S` assembles by default for a
 * standard (flash-resident, Arm, non-RISC-V) RP2350 build: a single
 * `IMAGE_TYPE` item declaring an Arm, secure, RP2350 executable, followed
 * by the mandatory `LAST` item and end marker. The item type/marker
 * constants come from the Pico SDK's `boot/picobin.h`, which is plain data
 * format definitions, usable from C as-is (no Pico SDK library is linked).
 *
 * The block is a single-entry "loop" (the offset to the next block is 0,
 * i.e. it points back to itself), so unlike the SDK's own layout there is
 * no separate end-of-flash copy, and no link-time symbol-distance
 * computation is needed: every field below is a compile-time constant.
 *
 * NOTE: this only supplies the metadata content; the linker script must
 * still place the `.embedded_block` section immediately after
 * `.interrupt_vectors`, within the first 4 KiB of flash, or the boot ROM
 * will not find it.
 */

#include "boot/picobin.h"

#include <stdint.h>

// ----------------------------------------------------------------------------

// Declares this image as an Arm, secure, RP2350 executable; matches the
// Pico SDK's own default `PICO_CRT0_IMAGE_TYPE_ITEM_VALUE` for a standard
// (non-RISC-V) RP2350 build.
#define RP2350_IMAGE_TYPE_ITEM_VALUE \
  (PICOBIN_IMAGE_TYPE_IMAGE_TYPE_AS_BITS (EXE) \
   | PICOBIN_IMAGE_TYPE_EXE_SECURITY_AS_BITS (S) \
   | PICOBIN_IMAGE_TYPE_EXE_CPU_AS_BITS (ARM) \
   | PICOBIN_IMAGE_TYPE_EXE_CHIP_AS_BITS (RP2350))

// Number of words occupied by the items preceding the `LAST` item (here,
// just the one-word `IMAGE_TYPE` item); this is what the `LAST` item's
// size field reports to the boot ROM parser.
#define RP2350_EMBEDDED_BLOCK_ITEMS_WORD_COUNT (1)

__attribute__ ((section (".embedded_block"), used,
                aligned (4))) static const uint32_t embedded_block_rp2350[]
    = {
        // Block start marker.
        PICOBIN_BLOCK_MARKER_START,

        // IMAGE_TYPE item: 1-byte item type, 1-byte item size (in words,
        // including this header word), 2-byte payload value.
        (uint32_t)PICOBIN_BLOCK_ITEM_1BS_IMAGE_TYPE | ((uint32_t)1 << 8)
            | ((uint32_t)RP2350_IMAGE_TYPE_ITEM_VALUE << 16),

        // LAST item header: 1-byte item type, 2-byte total size (in words) of
        // all items preceding this header word, 1 pad byte.
        (uint32_t)PICOBIN_BLOCK_ITEM_2BS_LAST
            | ((uint32_t)RP2350_EMBEDDED_BLOCK_ITEMS_WORD_COUNT << 8),

        // Offset, in bytes, from this block to the next block in the loop; 0
        // means this is a single-block loop, pointing back to itself.
        0,

        // Block end marker.
        PICOBIN_BLOCK_MARKER_END,
      };

// ----------------------------------------------------------------------------
