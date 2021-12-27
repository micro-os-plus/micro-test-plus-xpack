#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# This Source Code Form is subject to the terms of the MIT License.
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# Use targets as include markers (variables are not scope independent).
if(TARGET platform-native-included)
  return()
else()
  add_custom_target(platform-native-included)
endif()

message(STATUS "Including platform-native...")

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# -----------------------------------------------------------------------------
# Global definitions. Before any libraries.

# A list of all imaginable warnings.
xpack_set_all_compiler_warnings(all_warnings)

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
