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
# Must be included with include() in the `tests` scope.

file(RELATIVE_PATH folder_relative_path "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
message(VERBOSE "Including platform-native globals in '${folder_relative_path}' scope...")

# ---------------------------------------------------------------------------
# Global definitions. Before any libraries.

# A list of all imaginable warnings.
xpack_set_all_compiler_warnings(all_warnings)

# The global configuration file and possibly other platform defines.
include_directories(

  # Folders are relative to `tests`.
  "platform-native/include"
)

message(VERBOSE "+ platform-native/include")

# Global compiler definitions.
add_compile_definitions(

  # ...
)

set(common_options

  -fmessage-length=0
  -fsigned-char

  -ffunction-sections
  -fdata-sections

  ${all_warnings}
)

add_compile_options(
  ${common_options}
)

add_link_options(
  ${common_options}
)

# -----------------------------------------------------------------------------