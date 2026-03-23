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
# `add_subdirectory("tests/sources/suite-test")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC test::suite)`

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/sources/suite-test'...")

# -----------------------------------------------------------------------------
# The test library definitions.
add_library (test-suite-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (test-suite-interface INTERFACE # None.
)

target_sources (test-suite-interface INTERFACE src/main.cpp src/suite.cpp)

target_compile_definitions (test-suite-interface INTERFACE # None.
)

target_compile_options (test-suite-interface INTERFACE # None.
)

target_link_options (test-suite-interface INTERFACE # None.
)

target_link_libraries (test-suite-interface INTERFACE # None.
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (test-suite-interface)
endif ()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (test::suite ALIAS test-suite-interface)
message (VERBOSE "> test::suite -> test-suite-interface")

# -----------------------------------------------------------------------------
