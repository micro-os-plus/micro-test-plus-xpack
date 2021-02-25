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

message(STATUS "Including micro-os-plus-micro-test-plus...")

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# ---------------------------------------------------------------------------

add_library(micro-os-plus-micro-test-plus-static STATIC EXCLUDE_FROM_ALL)

# -------------------------------------------------------------------------

target_sources(
  micro-os-plus-micro-test-plus-static

  PRIVATE
    ${xpack_current_folder}/src/micro-test-plus.cpp
)

target_include_directories(
  micro-os-plus-micro-test-plus-static

  PUBLIC
    ${xpack_current_folder}/include
)

# -------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::micro-test-plus-static ALIAS micro-os-plus-micro-test-plus-static)
message(STATUS "micro-os-plus::micro-test-plus-static")

# -----------------------------------------------------------------------------
