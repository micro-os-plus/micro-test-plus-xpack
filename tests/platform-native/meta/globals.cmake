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

set(common_optimization_options

  -fmessage-length=0
  -fsigned-char
  -ffunction-sections
  -fdata-sections

  # -Wunused
  # -Wuninitialized
  # -Wall
  # -Wextra
  # -Wconversion
  # -Wpointer-arith
  # -Wshadow
  # -Wlogical-op
  # -Wfloat-equal

  # $<$<COMPILE_LANGUAGE:CXX>:-Wctor-dtor-privacy>
  # $<$<COMPILE_LANGUAGE:CXX>:-Wnoexcept>
  # $<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>
  # $<$<COMPILE_LANGUAGE:CXX>:-Wstrict-null-sentinel>
  # $<$<COMPILE_LANGUAGE:CXX>:-Wsign-promo>
)

add_compile_options(
  ${common_optimization_options}
)

add_link_options(
  ${common_optimization_options}
)

# -----------------------------------------------------------------------------
