#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
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

include("${CMAKE_CURRENT_LIST_DIR}/globals.cmake")

# -----------------------------------------------------------------------------
