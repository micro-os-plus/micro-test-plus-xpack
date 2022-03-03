#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file defines the global settings that apply to all targets.
# Must be included with include() in the `tests` scope.

message(VERBOSE "Including platform-stm32f4discovery globals...")

# -----------------------------------------------------------------------------

# Global definitions.
# add_compile_definitions()
# include_directories()

set(xpack_platform_common_options

  -mcpu=cortex-m4
  -mthumb
  -mfloat-abi=soft
  # -mfloat-abi=hard

  -fno-move-loop-invariants

  # Embedded builds must be warning free.
  -Werror

  # -flto fails with undefined reference to `__assert_func'...
  # $<$<CONFIG:Release>:-flto>
  # $<$<CONFIG:MinSizeRel>:-flto>

  $<$<CONFIG:Debug>:-fno-omit-frame-pointer>

  # ... libs-c/src/stdlib/exit.c:132:46
  # $<$<CXX_COMPILER_ID:GNU>:-Wno-missing-attributes>

  # $<$<COMPILE_LANGUAGE:C>:-fxxx>

  # $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
  # $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
)

add_compile_definitions(
  # ...
  _POSIX_C_SOURCE=200809L
)

add_compile_options(
  ${xpack_platform_common_options}
)

add_link_options(
  ${xpack_platform_common_options}
)

# -----------------------------------------------------------------------------
