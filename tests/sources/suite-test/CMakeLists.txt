# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from
# sources/suite-test/xcdl-package.jsonc.
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
# `add_subdirectory("sources/suite-test")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC tests-suite)`

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'sources/suite-test'...")

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (tests-suite-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (tests-suite-interface INTERFACE "include")

target_sources (tests-suite-interface INTERFACE "src/main.cpp" "src/suite.cpp")

target_link_libraries (
  tests-suite-interface INTERFACE "micro-os-plus::micro-test-plus-static"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (tests-suite-interface)
endif ()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (tests::suite ALIAS tests-suite-interface)
message (VERBOSE "> tests::suite -> tests-suite-interface")

# -----------------------------------------------------------------------------
