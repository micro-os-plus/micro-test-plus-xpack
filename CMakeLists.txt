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

# https://cmake.org/cmake/help/v3.19/
cmake_minimum_required(VERSION 3.19)

# This file is intended to be consumed by applications with:
#
# add_subdirectory("xpacks/micro-os-plus-micro-test-plus")
#
# For testing, CMake should set the separate `tests` folder as root.

include("${CMAKE_CURRENT_LIST_DIR}/meta/micro-os-plus-micro-test-plus-config.cmake")

# -----------------------------------------------------------------------------
