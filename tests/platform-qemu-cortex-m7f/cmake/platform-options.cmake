# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
# (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

message(VERBOSE "Including 'tests/platform-qemu-cortex-m7f/cmake/platform.cmake'...")

# -----------------------------------------------------------------------------

# Define the platform library.
add_library(platform-qemu-cortex-m7f-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories(platform-qemu-cortex-m7f-interface INTERFACE

  # This file is included from the tests folder.
  "platform-${PLATFORM_NAME}/include"
)

target_sources(platform-qemu-cortex-m7f-interface INTERFACE

  # None.
)

target_compile_definitions(platform-qemu-cortex-m7f-interface INTERFACE
  "${xpack_platform_compile_definition}"

  # Full POSIX conformance:
  # https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap02.html#tag_02_01_03
  # _POSIX_C_SOURCE=200809L

  # For S_IREAD
  _GNU_SOURCE
)

set(xpack_platform_common_args
  -mcpu=cortex-m7
  -mthumb

  # -mfloat-abi=soft
  -mfloat-abi=hard

  # -fno-move-loop-invariants

  # Embedded builds must be warning free.
  -Werror

  # -flto fails to run on QEMU.
  # $<$<CONFIG:Release>:-flto>
  # $<$<CONFIG:MinSizeRel>:-flto>
  $<$<CONFIG:Debug>:-fno-omit-frame-pointer>

  # ... libs-c/src/stdlib/exit.c:132:46
  # $<$<CXX_COMPILER_ID:GNU>:-Wno-missing-attributes>

  # $<$<COMPILE_LANGUAGE:C>:-fxxx>

  # https://cmake.org/cmake/help/v3.20/manual/cmake-generator-expressions.7.html?highlight=compile_language#genex:COMPILE_LANGUAGE
  # $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
  # $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
  # $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
)

target_compile_options(platform-qemu-cortex-m7f-interface INTERFACE
  ${xpack_platform_common_args}
)

# When `-flto` is used, the compile options must be passed to the linker too.
target_link_options(platform-qemu-cortex-m7f-interface INTERFACE

  # -v
  ${xpack_platform_common_args}

  -nostartfiles

  # --specs=rdimon.specs -Wl,--start-group -lgcc -lc -lc -lm -lrdimon -Wl,--end-group

  # Force the linker to keep the interrupt vectors which otherwise
  # are not referred from anywhere.
  # -u_interrupt_vectors

  # nano has no exceptions.
  # -specs=nano.specs
  -Wl,--gc-sections

  # .elf has a LOAD segment with RWX permissions (GCC 12)
  -Wl,--no-warn-rwx-segment

  # Including files from other packages is not very nice, but functional.
  # Use absolute paths, otherwise set -L.
  -T${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/devices-qemu-cortexm/linker-scripts/mem-mps2-an500.ld
  -T${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/architecture-cortexm/linker-scripts/sections-flash.ld

  # -T${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/architecture-cortexm/linker-scripts/sections-ram.ld
)

target_link_libraries(platform-qemu-cortex-m7f-interface INTERFACE
  micro-os-plus::common-options
  micro-os-plus::devices-qemu-cortexm
)

if(COMMAND xpack_display_target_lists)
  xpack_display_target_lists(platform-qemu-cortex-m7f-interface)
endif()

# -----------------------------------------------------------------------------

# Aliases.
add_library(micro-os-plus::platform ALIAS platform-qemu-cortex-m7f-interface)
message(VERBOSE "> micro-os-plus::platform -> platform-qemu-cortex-m7f-interface")

# -----------------------------------------------------------------------------
