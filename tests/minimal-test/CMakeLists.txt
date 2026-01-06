# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2021-2025 Liviu Ionescu. All rights reserved.
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
# `add_subdirectory("tests/minimal-test")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC test::minimal)`

# -----------------------------------------------------------------------------

message(VERBOSE "Processing 'tests/minimal-test'...")

# -----------------------------------------------------------------------------
# The test library definitions.
add_library(test-minimal-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories(test-minimal-interface INTERFACE # None.
)

target_sources(test-minimal-interface INTERFACE src/main.cpp)

target_compile_definitions(test-minimal-interface INTERFACE # None.
)

target_compile_options(test-minimal-interface INTERFACE # None.
)

target_link_options(test-minimal-interface INTERFACE # None.
)

target_link_libraries(test-minimal-interface INTERFACE # None.
)

if(COMMAND xpack_display_target_lists)
  xpack_display_target_lists(test-minimal-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(test::minimal ALIAS test-minimal-interface)
message(VERBOSE "> test::minimal -> test-minimal-interface")

# -----------------------------------------------------------------------------
