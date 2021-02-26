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

# https://cmake.org/cmake/help/v3.18/
# https://cmake.org/cmake/help/v3.18/manual/cmake-packages.7.html#package-configuration-file

if(micro-os-plus-micro-test-plus-included)
  return()
endif()

set(micro-os-plus-micro-test-plus-included TRUE)

message(STATUS "Including micro-os-plus-micro-test-plus...")

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# ---------------------------------------------------------------------------

add_library(micro-os-plus-micro-test-plus-static STATIC EXCLUDE_FROM_ALL)

# -------------------------------------------------------------------------

file(GLOB_RECURSE source_files CONFIGURE_DEPENDS "${xpack_current_folder}/src/*.c*")

target_sources(
  micro-os-plus-micro-test-plus-static

  PRIVATE
    ${source_files}
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

