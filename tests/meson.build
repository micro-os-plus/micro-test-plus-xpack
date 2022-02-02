
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# https://mesonbuild.com/Reference-manual.html#project
project('µTest++',
  ['c', 'cpp'],
  default_options: [
    'c_std=c11',
    'cpp_std=c++17',
    'b_staticpic=false', # Mandatory, startup fails otherwise.
  ],
  meson_version: '>= 0.59'
)

# languages: {c, cpp}

# https://mesonbuild.com/Builtin-options.html#c_compiler-options
# c_std: none, c89, c99, c11, c17, c18, c2x, gnu89, gnu99, gnu11, gnu17, gnu18, gnu2x
#
# cpp_std: none, c++98, c++03, c++11, c++14, c++17, c++20
# c++2a, c++1z, gnu++03, gnu++11, gnu++14, gnu++17, gnu++1z,
# gnu++2a, gnu++20, vc++14, vc++17, vc++latest

# -----------------------------------------------------------------------------

fs = import('fs')
c_compiler = meson.get_compiler('c')
# message('Compiler ID: ' + c_compiler.get_id())

# -----------------------------------------------------------------------------

# https://mesonbuild.com/Reference-manual_builtin_meson.html#mesoncurrent_source_dir
xpack_project_folder_path = fs.parent(meson.current_source_dir())
# https://mesonbuild.com/Reference-manual_builtin_meson.html#mesonproject_build_root
xpack_build_folder_path = meson.project_build_root()

xpack_platform_name = get_option('platform-name')

xpack_build_folder_relative_path = xpack_build_folder_path.replace(xpack_project_folder_path + '/', '')
# message('Build relative folder: ' + xpack_build_folder_relative_path)

# -----------------------------------------------------------------------------

# buildtype: {plain, debug, debugoptimized, release, minsize, custom}
message('Build type: ' + get_option('buildtype'))
message('Platform name: ' + xpack_platform_name)

# -----------------------------------------------------------------------------


# Compiler preprocessor definitions.
compiler_definitions = []
if get_option('buildtype').contains('debug')
  compiler_definitions += ['-DDEBUG']
  compiler_definitions += ['-DTRACE']
endif
if get_option('buildtype') == 'release'
  compiler_definitions += ['-DNDEBUG']
endif

# Options for both compilers and linkers. When using -flto all options
# must also be passed to the linker.
# https://mesonbuild.com/Reference-tables.html#c_compiler-ids

common_options = []
if get_option('buildtype') == 'debug'
  common_options += ['-O0']
elif get_option('buildtype') == 'debugoptimized'
  common_options += ['-Og'] # Override -O2
elif get_option('buildtype') == 'minsize'
  # common_options += ['-Os']
elif get_option('buildtype') == 'release'
  # common_options += ['-O3']
else
  common_options += ['-O']
endif

if c_compiler.get_id() == 'gcc' or c_compiler.get_id().contains('clang')
  common_options += [
    '-fmessage-length=0',
    '-fsigned-char'
  ]
  # This is used in conjunction with linker `--gc-sections`.
  common_options += [
    '-ffunction-sections',
    '-fdata-sections'
  ]

  if get_option('buildtype') == 'release' or get_option('buildtype') == 'debugoptimized'
  # Optional, comment it out to disable link time optimizations.
    common_options += [
      '-flto'
    ]
  endif
  if get_option('buildtype').contains('debug')
    common_options += [
      '-fno-omit-frame-pointer'
    ]
  endif
elif c_compiler.get_id() == 'msvc'
  common_options += [
    # Add MSVC options here.
  ]
endif

includes = [ '-I../../tests/platform-' + xpack_platform_name + '/include-config' ]
message('+ -I tests/platform-' + xpack_platform_name + '/include-config')

c_compiler_options = includes + compiler_definitions + common_options

cpp_compiler_options = includes + compiler_definitions + common_options

if c_compiler.get_id() == 'msvc'
  c_compiler_options += '/utf-8'
  cpp_compiler_options += '/utf-8'
endif

add_global_arguments(
  c_compiler_options,

  language: 'c'
)

add_global_arguments(
  cpp_compiler_options,

  language: 'cpp'
)


linker_options = common_options

# https://mesonbuild.com/Reference-tables.html#operating-system-names
if build_machine.system() == 'darwin'
  if not meson.is_cross_build()
    # macOS always uses the Apple linker, regarless of the c_compiler.
    linker_options += [
      '-Wl,-dead_strip'
    ]
  else
    linker_options += [
      '-Wl,--gc-sections'
    ]
  endif
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
## Dependencies ##

# Cannot be moved to platform folders, since `subdir()` accepts only
# children folders.
# https://mesonbuild.com/Reference-manual.html#subdir

# The order is relevant, each package must be included only after
# all its dependencies were included.
config_dependencies = []
if xpack_platform_name == 'qemu-mps2-an386'

  common_flags = [
    '-mcpu=cortex-m4',
    '-mthumb',
    '-mfloat-abi=hard',
    '-fno-move-loop-invariants',
  ]

  common_cpp_extra_flags = [
    '-fno-rtti',
    '-fno-use-cxa-atexit',
    '-fno-threadsafe-statics'
  ]

  add_global_arguments(
    common_flags,

    language: [ 'c', 'cpp' ]
  )

  add_global_arguments(
    common_cpp_extra_flags,

    language: [ 'cpp' ]
  )

  add_global_link_arguments(
    common_flags,

    language: [ 'c', 'cpp' ]
  )

  add_global_link_arguments(
    common_cpp_extra_flags,

    language: [ 'cpp' ]
  )

  add_global_arguments(
    '-DMICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS',

    language: [ 'c', 'cpp' ]
  )

  message('+ -D MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS')
  if get_option('buildtype').contains('debug')
    add_global_arguments(
      '-DMICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_STDOUT',

      language: [ 'c', 'cpp' ]
    )
    message('+ -D MICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_STDOUT')
  endif

  subdir('top/xpacks/micro-os-plus-build-helper/meson/enable-all-warnings')

  # The current folder is tests, we must include folders from the build folder.
  config_dependencies = [
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-version', # -
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-diag-trace', # -
    xpack_build_folder_relative_path + '/xpacks/xpack-3rd-party-arm-cmsis-core-m', # -
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-architecture-cortexm', # (architecture) -
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-semihosting', # diag-trace, architecture
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-device-cortexm', # semihosting
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-startup', # version, diag-trace, architecture
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-libs-c', # diag-trace, startup, architecture
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-libs-cpp', # diag-trace
    xpack_build_folder_relative_path + '/xpacks/micro-os-plus-device-qemu-cortexm', # device, diag-trace | (device) arm-cmsis-core-m, architecture-cortexm-device
  ]

  xpack_device_compile_definition='DEVICE_QEMU_CORTEX_M4'

endif

foreach dep: config_dependencies
  message('Adding ' + dep + '...')
  subdir('top/' + dep)
endforeach

# -----------------------------------------------------------------------------

# Include the project library, defined one level above.
subdir('top')

# Include the platform specific code.
subdir('platform-' + xpack_platform_name)

# -----------------------------------------------------------------------------
