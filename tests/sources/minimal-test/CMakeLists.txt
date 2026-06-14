# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from sources/minimal-test/xcdl-package.jsonc.
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
# `add_subdirectory("sources/minimal-test")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC tests-minimal)`

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'sources/minimal-test'...")

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (tests-minimal-interface INTERFACE EXCLUDE_FROM_ALL)

target_sources (
  tests-minimal-interface
  INTERFACE "src/main.cpp"
)

target_link_libraries (
  tests-minimal-interface 
  INTERFACE "micro-os-plus::micro-test-plus-static"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (tests-minimal-interface)
endif ()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (tests::minimal ALIAS tests-minimal-interface)
message (VERBOSE "> tests::minimal -> tests-minimal-interface")

# -----------------------------------------------------------------------------
