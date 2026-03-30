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
# `add_subdirectory("tests/sources/empty-test")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC test::empty)`

# -----------------------------------------------------------------------------

message(VERBOSE "Processing 'tests/sources/empty-test'...")

# -----------------------------------------------------------------------------
# The test library definitions.
add_library(test-empty-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories(test-empty-interface INTERFACE # None.
)

target_sources(test-empty-interface INTERFACE src/main.cpp)

target_compile_definitions(test-empty-interface INTERFACE # None.
)

target_compile_options(test-empty-interface INTERFACE # None.
)

target_link_options(test-empty-interface INTERFACE # None.
)

target_link_libraries(test-empty-interface INTERFACE # None.
)

if(COMMAND xpack_display_target_lists)
  xpack_display_target_lists(test-empty-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(test::empty ALIAS test-empty-interface)
message(VERBOSE "> test::empty -> test-empty-interface")

# -----------------------------------------------------------------------------
