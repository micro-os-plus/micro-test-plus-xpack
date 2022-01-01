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
