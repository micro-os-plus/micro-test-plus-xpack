#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# Create the test applications.

message('Processing platform-native...')

# -----------------------------------------------------------------------------

linker_options = common_options

# https://mesonbuild.com/Reference-tables.html#operating-system-names
if build_machine.system() == 'darwin'
  # macOS always uses the Apple linker, regarless of the c_compiler.
  linker_options += [
    '-Wl,-dead_strip'
  ]
else # Linux or Windows
  if c_compiler.get_id() == 'gcc'
    # TODO: clang with gold might need it too.
    linker_options += [
      '-Wl,--gc-sections'
    ]
  elif c_compiler.get_id() == 'msvc'
    linker_options += [
      # TODO: Add MSVC options here.
    ]
  endif
endif

# -----------------------------------------------------------------------------

test_names = [ 'unit-test', 'sample-test' ]

foreach name : test_names

  # https://mesonbuild.com/Reference-manual.html#executable
  exe = executable(
    name,
    include_directories: include_directories(
      '../include',
    ),
    sources: files(
      '../src/' + name + '.cpp'
    ),
    dependencies: [
      micro_os_plus_micro_test_plus_dependency
    ],
    link_args: linker_options
  )

  message('A+ -I tests/include')
  message('A+ tests/src/' + name + '.cpp')
  message('A> ' + name)

  # Leave the result in a variable with the test name.
  set_variable(name.underscorify(), exe)

endforeach

# https://mesonbuild.com/Unit-tests.html#malloc_perturb_
nomalloc = environment({'MALLOC_PERTURB_': '0'})

# https://mesonbuild.com/Reference-manual_functions.html#test
test(
  'unit-test',
  unit_test,
  args: [],
  env: nomalloc
)

test(
  'sample-test',
  sample_test,
  args: [
    'one',
    'two'
  ],
  env: nomalloc
)

# -----------------------------------------------------------------------------
