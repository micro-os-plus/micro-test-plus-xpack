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

# This file defines the global settings that apply to all targets.

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# -----------------------------------------------------------------------------
# Global definitions. Before any libraries.

set(common_options

  -fmessage-length=0
  -fsigned-char
  -ffunction-sections
  -fdata-sections
)

add_compile_options(
  ${common_options}
)

add_link_options(
  ${common_options}
)

# -----------------------------------------------------------------------------
