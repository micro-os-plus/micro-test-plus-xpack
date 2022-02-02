#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# Create the test applications.

message('Processing tests/platform-qemu-mps2-an386...')

# -----------------------------------------------------------------------------

# Public definitions, also passed up to targets linking to them.
# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
platform_qemu_mps2_an386_dependency = declare_dependency(
  include_directories: include_directories(
    'include-platform',
  ),
  sources: files(
    'src/initialize-hardware.cpp',
    'src/interrupts-handlers.cpp',
  ),
  compile_args: [
  ],
  dependencies: [
    micro_os_plus_device_qemu_cortexm_dependency,
  ]
)

message('+ -I include')
message('+ src/initialize-hardware.cpp')
message('+ src/interrupts-handlers.cpp')
message('> platform_qemu_mps2_an386_dependency')

# -----------------------------------------------------------------------------

# Get the command names from the toolchain file.
size = find_program('size')
objdump = find_program('objdump')
objcopy = find_program('objcopy')

test_names = [ 'unit-test', 'sample-test' ]

foreach name : test_names
  # https://mesonbuild.com/Reference-manual.html#executable
  exe = executable(
    name,
    include_directories: include_directories(
      '../include',
      'include-platform',
    ),
    sources: files(
      '../src/' + name + '.cpp'
    ),
    dependencies: [
      # Tested library.
      micro_os_plus_micro_test_plus_dependency,

      # Platform; it brings device and architecture too.
      platform_qemu_mps2_an386_dependency,

      # Other dependencies.
      micro_os_plus_libs_c_dependency,
      micro_os_plus_libs_cpp_dependency,
      micro_os_plus_semihosting_dependency,
      micro_os_plus_startup_dependency,
    ],
    link_args: linker_options + [
      '-Wl,-Map,meson-out/'+ name + '-map.txt',
      '-nostartfiles',
      '-u_interrupt_vectors',
      # '-v',
      # Path are relative to the build folder.
      '-Txpacks/micro-os-plus-device-qemu-cortexm/linker-scripts/mem.ld',
      '-Txpacks/micro-os-plus-architecture-cortexm/linker-scripts/sections.ld',
    ],
    name_suffix: 'elf',
  )

  message('+ -I tests/include')
  message('+ -I tests/platform-qemu-mps2-an386/include-platform')
  message('+ tests/src/' + name + '.cpp')
  message('>> ' + name)

  # Leave the result in a variable with the test name.
  set_variable(name.underscorify(), exe)

  # https://mesonbuild.com/Reference-manual_functions.html#custom_target
  custom_target(
    name + '-size',

    input: exe,
    output: name + '.size',
    command: [
      size,
      '--format=berkeley',
      '@INPUT@'
    ],
    build_always_stale: true,
    build_by_default: true,
  )

  # --source --all-headers --demangle --line-numbers --wide "xxx.elf"
  custom_target(
    name + '-list',

    input: exe,
    output: name + '-list.txt',
    command: [
      objdump,
      '--source',
      '--all-headers',
      '--demangle',
      '--line-numbers',
      '--wide',
      '@INPUT@'
    ],
    build_always_stale: true,
    build_by_default: true, # Enable it only when needed.
    capture: true,
  )

  # -O ihex "xxx.elf"
  custom_target(
    name + '-hex',

    input: exe,
    output: name + '.hex',
    command: [
      objcopy,
      '-O',
      'ihex',
      '@INPUT@',
      '@OUTPUT@',
    ],
    build_always_stale: true,
    # build_by_default: true, # Enable it only when needed.
  )


endforeach

qemu = find_program('qemu-system-arm')

# https://mesonbuild.com/Unit-tests.html#malloc_perturb_
nomalloc = environment({'MALLOC_PERTURB_': '0'})

# https://mesonbuild.com/Reference-manual_functions.html#test
test(
  'unit-test',
  qemu,
  args: [
    '--machine', 'mps2-an386',
    '--cpu', 'cortex-m4',
    '--kernel', unit_test,
    '--nographic',
    '-d', 'unimp,guest_errors',
    '--semihosting-config', 'enable=on,target=native',
    '--semihosting-config', 'arg=unit-test',
  ],
  env: nomalloc
)

test(
  'sample-test',
  qemu,
  args: [
    '--machine', 'mps2-an386',
    '--cpu', 'cortex-m4',
    '--kernel', sample_test,
    '--nographic',
    '-d', 'unimp,guest_errors',
    '--semihosting-config', 'enable=on,target=native',
    '--semihosting-config', 'arg=unit-test,arg=one,arg=two',
  ],
  env: nomalloc
)

# -----------------------------------------------------------------------------
