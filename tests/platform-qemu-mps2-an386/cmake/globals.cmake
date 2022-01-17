#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# This file defines the global settings that apply to all targets.

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# ---------------------------------------------------------------------------
# Global definitions. Before any libraries.

include_directories(

  ${xpack_current_folder}/include
)

add_compile_definitions(

  MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS
  # HAVE_MICRO_OS_PLUS_CONFIG_H

  $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:MICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_DEBUG>
)

# A list of all imaginable warnings.
xpack_set_all_compiler_warnings(all_warnings)

set(common_options

  -mcpu=cortex-m4
  -mthumb
  # -mfloat-abi=soft
  -mfloat-abi=hard

  -fmessage-length=0
  -fsigned-char
  -ffunction-sections
  -fdata-sections
  -fno-move-loop-invariants

  # $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>

  # ... libs-c/src/stdlib/exit.c:132:46
  # $<$<CXX_COMPILER_ID:GNU>:-Wno-missing-attributes>

  ${all_warnings}

  -Werror
)

add_compile_options(

    ${common_options}
)

add_link_options(

    ${common_options}
)

add_link_options(

    -nostartfiles
    # nano has no exceptions.
    # -specs=nano.specs
    -Wl,--gc-sections

    # Force the linker to keep the interrupt vectors which otherwise
    # are not refered from anywhere.
    -u_interrupt_vectors

    # Including files from other packages is not very nice, but functional.
    # Use absolute paths, otherwise set -L.
    -T${xpack_build_folder}/xpacks/micro-os-plus-platform-qemu-cortexm/linker-scripts/mem.ld
    -T${xpack_build_folder}/xpacks/micro-os-plus-architecture-cortexm/linker-scripts/sections.ld
)

# -----------------------------------------------------------------------------
