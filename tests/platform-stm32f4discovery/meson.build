#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# Create the test applications.

message('Processing tests/platform-stm32f4discovery...')

# -----------------------------------------------------------------------------

# Enable them only when needed.
xpack_create_listing = false
xpack_create_hex = false

# -----------------------------------------------------------------------------

# The final platform library can now be defined, with the
# customised initialisation on top of the CubeMX library.

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
platform_stm32f4discovery_dependency = declare_dependency(
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
    micro_os_plus_platform_stm32f4discovery_dependency,
  ]
)

message('+ -I tests/platform-stm32f4discovery/include-platform')
message('+ tests/platform-stm32f4discovery/src/initialize-hardware.cpp')
message('+ tests/platform-stm32f4discovery/src/interrupts-handlers.cpp')
message('> platform_stm32f4discovery_dependency')

# =============================================================================

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
      # 'include-config' # was added globally
    ),
    sources: files(
      '../src/' + name + '.cpp'
    ),
    dependencies: [
      # Tested library.
      micro_os_plus_micro_test_plus_dependency,

      # Platform; it brings device and architecture too.
      platform_stm32f4discovery_dependency,

      # Other dependencies.
      micro_os_plus_libs_c_dependency,
      micro_os_plus_libs_cpp_dependency,
      micro_os_plus_semihosting_dependency,
      micro_os_plus_startup_dependency,
    ],
    link_args: [
      '-Wl,-Map,meson-out/'+ name + '-map.txt',
      '-nostartfiles',
      # Ensure the linker will keep the interrupt vectors which otherwise
      # are not refered from anywhere.
      '-u_interrupt_vectors',
      '-Wl,--gc-sections',
      # '-v',
      # Path are relative to the build folder.
      '-Txpacks/micro-os-plus-platform-stm32f4discovery/linker-scripts/mem.ld',
      '-Txpacks/micro-os-plus-architecture-cortexm/linker-scripts/sections.ld',
    ],
    name_suffix: 'elf',
  )

  message('+ -I tests/include')
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
    build_by_default: xpack_create_listing,
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
    build_by_default: xpack_create_hex,
  )

endforeach

qemu = find_program('qemu-system-gnuarmeclipse')

# https://mesonbuild.com/Unit-tests.html#malloc_perturb_
nomalloc = environment({'MALLOC_PERTURB_': '0'})

# https://mesonbuild.com/Reference-manual_functions.html#test
test(
  'unit-test',
  qemu,
  args: [
    '--board', 'STM32F4-Discovery',
    '--image', unit_test,
    '--nographic',
    '--verbose',
    '-d', 'unimp,guest_errors',
    '--semihosting-config', 'enable=on,target=native',
    '--semihosting-cmdline', 'unit-test',
  ],
  env: nomalloc
)

test(
  'sample-test',
  qemu,
  args: [
    '--board', 'STM32F4-Discovery',
    '--image', sample_test,
    '--nographic',
    '--verbose',
    '-d', 'unimp,guest_errors',
    '--semihosting-config', 'enable=on,target=native',
    '--semihosting-cmdline', 'sample-test', 'one', 'two',
  ],
  env: nomalloc
)

# -----------------------------------------------------------------------------
