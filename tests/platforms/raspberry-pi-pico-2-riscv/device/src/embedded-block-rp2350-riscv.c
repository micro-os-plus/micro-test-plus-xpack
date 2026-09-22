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

/*
 * The RP2350 boot ROM does not accept a plain entry address at the start of
 * flash; it requires a small PICOBIN "block" (a self-describing sequence of
 * items, bracketed by start/end markers) to be present within the first
 * 4 KiB of the image, identifying it as an executable (`IMAGE_DEF`).
 *
 * Unlike the sibling `raspberry-pi-pico-2-arm` platform's
 * `embedded-block-rp2350.c` (which only needs an `IMAGE_TYPE` item,
 * because the boot ROM's Arm fallback is to enter the vector table placed
 * at the image start), RISC-V has no such implicit entry convention: this
 * block also carries an explicit `ENTRY_POINT` item, giving the boot ROM
 * the address of `reset_entry` (device/src/reset-entry.S) and the
 * initial stack pointer (`__stack`, the top of RAM, defined by the
 * `startup` package's `sections.ld`). This mirrors the Pico SDK's own
 * `pico_crt0/embedded_start_block.inc.S`, which sets
 * `PICO_CRT0_INCLUDE_PICOBIN_ENTRY_POINT_ITEM` to 1 by default whenever
 * `__riscv` is defined, for exactly this reason.
 *
 * The item type/marker constants come from the Pico SDK's `boot/picobin.h`,
 * which is plain data format definitions, usable from C as-is (no Pico SDK
 * library is linked).
 *
 * The block is a single-entry "loop" (the offset to the next block is 0,
 * i.e. it points back to itself), so there is no separate end-of-flash
 * copy, matching the ARM platform's block.
 *
 * Unlike the ARM block, this one embeds relocatable symbol addresses (the
 * entry point and the stack pointer), not only compile-time constants, so
 * it is laid out as a struct rather than a flat `uint32_t[]`: this lets
 * the compiler/linker emit the address relocations for
 * `reset_entry`/`__stack` directly into the initialised data, instead
 * of requiring them to fold to constants.
 *
 * NOTE: this only supplies the metadata content; the linker script must
 * still place the `.embedded_block` section immediately after
 * `.reset_entry`, within the first 4 KiB of flash, or the boot ROM will
 * not find it (see linker-scripts/section-embedded-block.ld).
 * The section is included in the startup package, the 
 * `linker-scripts/section-interrupt-vectors.ld` file.
 */

#include "boot/picobin.h"

#include <stdint.h>

// ----------------------------------------------------------------------------

extern void
reset_entry (void);
extern uint8_t __stack;

// ----------------------------------------------------------------------------

// Declares this image as a RISC-V RP2350 executable; matches the Pico
// SDK's own default `PICO_CRT0_IMAGE_TYPE_ITEM_VALUE` for `__riscv`
// builds (no `EXE_SECURITY` bits: that field is Arm-only).
#define RP2350_RISCV_IMAGE_TYPE_ITEM_VALUE \
  (PICOBIN_IMAGE_TYPE_IMAGE_TYPE_AS_BITS (EXE) \
   | PICOBIN_IMAGE_TYPE_EXE_CPU_AS_BITS (RISCV) \
   | PICOBIN_IMAGE_TYPE_EXE_CHIP_AS_BITS (RP2350))

// Word count of the items preceding the `LAST` item: 1 word for
// `IMAGE_TYPE`, plus 3 words for `ENTRY_POINT` (1 header word + the
// entry address + the stack pointer).
#define RP2350_RISCV_EMBEDDED_BLOCK_ITEMS_WORD_COUNT (4)

// ----------------------------------------------------------------------------

// Every field below already falls on its natural alignment boundary (the
// four 1-byte fields are grouped into one 4-byte run), so no `packed`
// attribute is needed -- and, under `-mstrict-align`, adding one would
// only make the compiler warn that it is redundant.
typedef struct
{
  // Block start marker.
  uint32_t block_marker_start;

  // IMAGE_TYPE item: 1-byte item type, 1-byte item size (in words,
  // including this header word), 2-byte payload value.
  uint32_t image_type_item;

  // ENTRY_POINT item header: 1-byte item type, 1-byte item size (in
  // words, including this header word), 2 pad bytes; followed by the
  // entry address and the initial stack pointer.
  uint8_t entry_point_item_type;
  uint8_t entry_point_item_size_words;
  uint8_t entry_point_pad0;
  uint8_t entry_point_pad1;
  void (*entry_point_address) (void);
  const void* entry_point_stack_pointer;

  // LAST item header: 1-byte item type, 2-byte total size (in words) of
  // all items preceding this header word, 1 pad byte.
  uint32_t last_item_header;

  // Offset, in bytes, from this block to the next block in the loop; 0
  // means this is a single-block loop, pointing back to itself.
  uint32_t next_block_offset;

  // Block end marker.
  uint32_t block_marker_end;
} rp2350_riscv_embedded_block_t;

__attribute__ ((section (".embedded_block"), used,
                aligned (4))) static const rp2350_riscv_embedded_block_t
    embedded_block_rp2350_riscv
    = {
        .block_marker_start = PICOBIN_BLOCK_MARKER_START,

        .image_type_item
        = (uint32_t)PICOBIN_BLOCK_ITEM_1BS_IMAGE_TYPE | ((uint32_t)1 << 8)
          | ((uint32_t)RP2350_RISCV_IMAGE_TYPE_ITEM_VALUE << 16),

        .entry_point_item_type = (uint8_t)PICOBIN_BLOCK_ITEM_1BS_ENTRY_POINT,
        .entry_point_item_size_words = 3,
        .entry_point_pad0 = 0,
        .entry_point_pad1 = 0,
        .entry_point_address = &reset_entry,
        .entry_point_stack_pointer = &__stack,

        .last_item_header
        = (uint32_t)PICOBIN_BLOCK_ITEM_2BS_LAST
          | ((uint32_t)RP2350_RISCV_EMBEDDED_BLOCK_ITEMS_WORD_COUNT << 8),

        .next_block_offset = 0,

        .block_marker_end = PICOBIN_BLOCK_MARKER_END,
      };

// ----------------------------------------------------------------------------
