# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed with:
#
# `add_subdirectory("tests/sources/unit-test")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC test::unit)`

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/sources/unit-test'...")

# -----------------------------------------------------------------------------
# The test library definitions.
add_library (test-unit-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (test-unit-interface INTERFACE include)

target_sources (
  test-unit-interface
  INTERFACE src/main.cpp
            src/static-asserts.cpp
            src/integral-passed-combinations.cpp
            src/integral-failed-combinations.cpp
            src/float-passed-combinations.cpp
            src/float-failed-combinations.cpp
            src/comparisons.cpp
            src/operators.cpp
            src/exceptions.cpp
            src/miscellaneous.cpp
            src/utility.cpp
            src/timings.cpp
            src/support.cpp
)

target_compile_definitions (test-unit-interface INTERFACE)

target_compile_options (test-unit-interface INTERFACE)

target_link_options (test-unit-interface INTERFACE)

target_link_libraries (test-unit-interface INTERFACE)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (test-unit-interface)
endif ()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (test::unit ALIAS test-unit-interface)
message (VERBOSE "> test::unit -> test-unit-interface")

# -----------------------------------------------------------------------------
