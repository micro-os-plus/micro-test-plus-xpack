#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# Create the test applications.

message('Processing platform-native...')

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
    link_with: [
      micro_os_plus_micro_test_plus_static
    ],
    link_args: linker_options
  )

  message('+ -I tests/include')
  message('+ tests/src/' + name + '.cpp')
  message('>> ' + name)

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
