# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/benchmarks/footprint/cpputest/xcdl-test.jsonc
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

# This file is intended to be used by applications via:
#
# `add_subdirectory("sources/benchmarks/footprint/cpputest")`
#
# This creates interface libraries that can be linked to a target with:
#
# ~~~
# target_link_libraries(your-target PUBLIC benchmark::footprint-cpputest)
# ~~~

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/sources/benchmarks/footprint/cpputest/'...")

# -----------------------------------------------------------------------------

# The footprint benchmark program of CppUTest.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (benchmark-footprint-cpputest-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (
  benchmark-footprint-cpputest-interface
  INTERFACE "include" "../../../../benchmarks-frameworks/cpputest/include"
)

target_sources (
  benchmark-footprint-cpputest-interface
  INTERFACE
    "src/main.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/CommandLineArguments.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/CommandLineTestRunner.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/JUnitTestOutput.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/MemoryLeakDetector.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/MemoryLeakWarningPlugin.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/SimpleMutex.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/SimpleString.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/SimpleStringInternalCache.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TeamCityTestOutput.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestFailure.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestFilter.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestHarness_c.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestMemoryAllocator.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestOutput.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestPlugin.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestRegistry.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestResult.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestTestingFixture.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/CppUTest/Utest.cpp"
    "../../../../benchmarks-frameworks/cpputest/src/Platforms/Gcc/UtestPlatform.cpp"
)

target_compile_definitions (
  benchmark-footprint-cpputest-interface INTERFACE "HAVE_CONFIG_H"
)

target_compile_options (benchmark-footprint-cpputest-interface INTERFACE "-w")

xpack_display_target_lists (benchmark-footprint-cpputest-interface)

# -----------------------------------------------------------------------------
# Alias.

# Export an alias target using namespaced syntax (Project::Target). This is the
# canonical pattern for consumption via target_link_libraries(), whether the
# dependency is added via add_subdirectory(), FetchContent, or an installed
# package via find_package(). Using "::" lets CMake detect an invalid or
# misspelled target name at configure time, rather than silently passing it
# through to the linker as a plain string or flag. Note: alias targets are
# read-only; properties must be set on the underlying target, not on the alias
# itself.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  benchmark::footprint-cpputest ALIAS benchmark-footprint-cpputest-interface
)
message (
  VERBOSE
  "> benchmark::footprint-cpputest -> benchmark-footprint-cpputest-interface"
)

# -----------------------------------------------------------------------------
