#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.19/
# https://cmake.org/cmake/help/v3.19/manual/cmake-packages.7.html#package-configuration-file
cmake_minimum_required(VERSION 3.19)

# Use targets as include markers (variables are not scope independent).
if(TARGET platform-stm32f4discovery-included)
  return()
else()
  add_custom_target(platform-stm32f4discovery-included)
endif()

if(NOT TARGET micro-os-plus-build-helper-included)
  message(FATAL_ERROR "Include the mandatory build-helper (xpacks/micro-os-plus-build-helper/cmake/xpack-helper.cmake)")
endif()

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

if(NOT TARGET platform-stm32f4discovery-interface)

  add_library(platform-stm32f4discovery-interface INTERFACE EXCLUDE_FROM_ALL)

  # -------------------------------------------------------------------------

  if(NOT PLATFORM_STM32F4DISCOVERY_WITHOUT_HAL)
    set(source_files
      ${xpack_current_folder}/src/initialize-hardware.cpp
      ${xpack_current_folder}/src/interrupts-handlers.cpp
    )

    xpack_display_relative_paths("${source_files}" "${xpack_current_folder}")

    target_sources(
      platform-stm32f4discovery-interface

      INTERFACE
        ${source_files}
    )
  endif()

  target_include_directories(
    platform-stm32f4discovery-interface

    INTERFACE
      # The include folder was passed globally, to catch the global config.h.
  )

  # The preprocessor definitions were passed globally.

  target_compile_options(
    platform-stm32f4discovery-interface

    INTERFACE
      # ...
  )

    target_link_libraries(
      platform-stm32f4discovery-interface

      INTERFACE
        micro-os-plus::platform-stm32f4discovery
    )

  # -------------------------------------------------------------------------
  # Aliases.

  add_library(micro-os-plus::platform ALIAS platform-stm32f4discovery-interface)
  message(STATUS "=> micro-os-plus::platform (platform-stm32f4discovery-interface)")

endif()

# -----------------------------------------------------------------------------
