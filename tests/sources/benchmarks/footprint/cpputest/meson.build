# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/benchmarks/footprint/cpputest/xcdl-test.jsonc
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
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
# `subdir('sources/benchmarks/footprint/cpputest')`
#
# This creates dependencies that can be linked to a target with:
#
# `dependencies: [benchmark_footprint_cpputest_dependency],`

# Note: the Meson configuration is provided only as a proof of concept;
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing \'tests/sources/benchmarks/footprint/cpputest/\'...')

# -----------------------------------------------------------------------------

# Meson's DSL does not provide introspection methods on dependency objects
# to retrieve their properties after creation. The `_local_*` variables
# therefore serve a dual purpose: populating the dependency object and
# iterating over its components for the `message()` calls at the end.

# -----------------------------------------------------------------------------

# The footprint benchmark program of CppUTest.

_local_compile_args = [] # Common C/C++ args.
_local_compile_c_args = [] # C only args.
_local_compile_cpp_args = [] # C++ only args.
_local_include_directories = []
_local_sources = []
_local_compile_definitions = []
_local_dependencies = []
_local_link_args = []
_local_link_with = []

_local_include_directories += [
  'include',
  '../../../../benchmarks-frameworks/cpputest/include',
]

_local_sources += [
  'src/main.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/CommandLineArguments.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/CommandLineTestRunner.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/JUnitTestOutput.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/MemoryLeakDetector.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/MemoryLeakWarningPlugin.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/SimpleMutex.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/SimpleString.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/SimpleStringInternalCache.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TeamCityTestOutput.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestFailure.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestFilter.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestHarness_c.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestMemoryAllocator.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestOutput.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestPlugin.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestRegistry.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestResult.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/TestTestingFixture.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/CppUTest/Utest.cpp',
  '../../../../benchmarks-frameworks/cpputest/src/Platforms/Gcc/UtestPlatform.cpp',
]

_local_compile_definitions += [
  '-DHAVE_CONFIG_H',
]

_local_compile_args += [
  '-w',
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
benchmark_footprint_cpputest_dependency = declare_dependency(
  include_directories: include_directories(_local_include_directories),
  compile_args: _local_compile_args + _local_compile_definitions,
  sources: files(_local_sources),
  dependencies: _local_dependencies,
  link_args: _local_link_args,
  link_with: _local_link_with,
)

# Meson dependencies cannot differentiate between C and C++ compile args;
# they are therefore exposed as separate variables alongside the dependency.
benchmark_footprint_cpputest_dependency_compile_c_args = _local_compile_c_args
benchmark_footprint_cpputest_dependency_compile_cpp_args = _local_compile_cpp_args

foreach name : _local_include_directories
  message('+ -I ' + name)
endforeach
foreach name : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args + _local_link_args
  message('+ ' + name)
endforeach
message('> benchmark_footprint_cpputest_dependency')

# -----------------------------------------------------------------------------
