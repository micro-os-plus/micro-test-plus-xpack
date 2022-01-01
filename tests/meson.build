#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

linker_options = common_options

# https://mesonbuild.com/Reference-tables.html#operating-system-names
if build_machine.system() == 'darwin'
  # macOS always uses the Apple linker, regarless of the compiler.
  linker_options += [
    '-Wl,-dead_strip'
  ]
else # Linux or Windows
  if compiler.get_id() == 'gcc'
    # TODO: clang with gold might need it too.
    linker_options += [
      '-Wl,--gc-sections'
    ]
  elif compiler.get_id() == 'msvc'
    linker_options += [
      # TODO: Add MSVC options here.
    ]
  endif
endif

# Create the test applications.
# https://mesonbuild.com/Reference-manual.html#executable
application_unit_test = executable('unit-test',
  include_directories: include_directories(
    'include',
  ),
  sources: files(
    'src/unit-test.cpp'
  ),
  dependencies: [lib_micro_os_plus_micro_test_plus_dependency],
  link_with: [lib_micro_os_plus_micro_test_plus],
  c_args: c_compiler_options,
  cpp_args: cpp_compiler_options,
  link_args: linker_options
)

application_sample_test = executable('sample-test',
  include_directories: include_directories(
    'include',
  ),
  sources: files(
    'src/sample-test.cpp'
  ),
  dependencies: [lib_micro_os_plus_micro_test_plus_dependency],
  link_with: [lib_micro_os_plus_micro_test_plus],
  c_args: c_compiler_options,
  cpp_args: cpp_compiler_options,
  link_args: linker_options
)

nomalloc = environment({'MALLOC_PERTURB_': '0'})

test('unit-test', application_unit_test, env: nomalloc)
test('sample-test', application_sample_test, env: nomalloc)

# -----------------------------------------------------------------------------
