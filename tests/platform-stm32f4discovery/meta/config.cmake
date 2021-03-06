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

if(platform-stm32f4discovery-included)
  return()
endif()

set(platform-stm32f4discovery-included TRUE)

message(STATUS "Including platform-stm32f4discovery...")

# -----------------------------------------------------------------------------
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# ---------------------------------------------------------------------------

include("${CMAKE_CURRENT_LIST_DIR}/globals.cmake")

# -----------------------------------------------------------------------------
# Dependencies.

# This will also define the device.
find_package(micro-os-plus-platform-stm32f4discovery REQUIRED)

# ---------------------------------------------------------------------------
# Recompute current path after find_package().

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# ---------------------------------------------------------------------------

if(NOT TARGET platform-stm32f4discovery-static)

  add_library(platform-stm32f4discovery-static INTERFACE EXCLUDE_FROM_ALL)

  # -------------------------------------------------------------------------

  set(source_files
    ${xpack_current_folder}/src/initialize-hardware.cpp
    ${xpack_current_folder}/src/interrupts-handlers.cpp
  )

  xpack_display_relative_paths("${source_files}" "${xpack_current_folder}")

  target_sources(
    platform-stm32f4discovery-static

    INTERFACE
      ${source_files}
  )

  target_include_directories(
    platform-stm32f4discovery-static

    INTERFACE
      # The include folder was passed globally, to catch the global config.h.
  )

  # The preprocessor definitions were passed globally.

  target_compile_options(
    platform-stm32f4discovery-static

    INTERFACE
      # ...

  )

  target_link_libraries(
    platform-stm32f4discovery-static
    
    INTERFACE
      micro-os-plus::platform-stm32f4discovery
  )

  # -------------------------------------------------------------------------
  # Aliases.

  add_library(micro-os-plus::platform ALIAS platform-stm32f4discovery-static)
  message(STATUS "=> micro-os-plus::platform")

endif()

# -----------------------------------------------------------------------------
