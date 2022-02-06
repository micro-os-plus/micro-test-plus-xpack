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

# This file defines the global compiler settings that apply to all targets.
# Must be added with `include()` in the `tests` scope.

message(VERBOSE "Including platform-native globals...")

# -----------------------------------------------------------------------------
# Global definitions. Before any libraries.

# A list of all imaginable warnings.
xpack_set_all_compiler_warnings(all_warnings)

# The global configuration file and possibly other platform defines.
include_directories(

  # Folders are relative to `tests`.
  "platform-native/include-config"
)

message(VERBOSE "G+ -I tests/platform-native/include-config")

# Global compiler definitions.
add_compile_definitions(

  # ...
)

set(common_options

  -fmessage-length=0
  -fsigned-char

  -ffunction-sections
  -fdata-sections
)

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux" AND "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "armv7l")
  # clang-12: error: unable to execute command: Segmentation fault
  # clang-12: error: linker command failed due to signal (use -v to see invocation)
  # Alternate linker was not effective.
else()
  list(APPEND common_options
    $<$<CONFIG:Release>:-flto>
    $<$<CONFIG:MinSizeRel>:-flto>
  )
endif()

list(APPEND common_options
  ${all_warnings}
)

add_compile_options(
  ${common_options}
)

# When using -flto, the compiler options must be passed to the linker too.
add_link_options(
  ${common_options}
)

# -----------------------------------------------------------------------------
