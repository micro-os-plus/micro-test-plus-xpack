# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# https://mesonbuild.com/Reference-manual.html#project
project('micro-os-plus-micro-test-plus-tests',
  ['c', 'cpp'],
  default_options: [
    'c_std=c11',
    'cpp_std=c++20',
    'b_staticpic=false', # Mandatory, startup fails otherwise.
  ],
  meson_version: '>= 1.3'
)

# languages: {c, cpp}

# https://mesonbuild.com/Builtin-options.html#c_compiler-options
# c_std: none, c89, c99, c11, c17, c18, c2x, gnu89, gnu99, gnu11, gnu17, gnu18, gnu2x
#
# cpp_std: none, c++98, c++03, c++11, c++14, c++17, c++20
# c++2a, c++1z, gnu++03, gnu++11, gnu++14, gnu++17, gnu++1z,
# gnu++2a, gnu++20, vc++14, vc++17, vc++latest

# -----------------------------------------------------------------------------
# Global definitions #

enable_sample_test = true
enable_unit_test = true

# -----------------------------------------------------------------------------

fs = import('fs')
c_compiler = meson.get_compiler('c')
cpp_compiler = meson.get_compiler('cpp')
# message('Compiler ID: ' + c_compiler.get_id())

# -----------------------------------------------------------------------------

# https://mesonbuild.com/Reference-manual_builtin_meson.html#mesoncurrent_source_dir
xpack_tests_folder_path = meson.current_source_dir()
xpack_project_folder_path = fs.parent(xpack_tests_folder_path)
# https://mesonbuild.com/Reference-manual_builtin_meson.html#mesonproject_build_root
xpack_build_folder_path = meson.project_build_root()

xpack_platform_name = get_option('platform-name')

# Create a symbolic link to project root; don't bother with errors,
# without it the build will crash anyway.
if build_machine.system() == 'windows'
  # https://mesonbuild.com/Reference-manual_functions.html#run_command
  run_command('cmd', '/C', 'mklink /J top ..', check: false)
  xpack_path_separator = '\\'
else
  run_command('ln', '-s', '..', 'top', check: false)
  xpack_path_separator = '/'
endif

# Hack to compute the build folder relative path.
xpack_build_folder_relative_path = xpack_build_folder_path.replace(xpack_tests_folder_path + xpack_path_separator, '')
# message('Build relative folder: ' + xpack_build_folder_relative_path)

# -----------------------------------------------------------------------------

# buildtype: {plain, debug, debugoptimized, release, minsize, custom}
message('Build type: ' + get_option('buildtype'))
message('Platform name: ' + xpack_platform_name)

# -----------------------------------------------------------------------------

# https://mesonbuild.com/Reference-manual.html#subdir
subdir('meson/common-options')
subdir('xpacks/@micro-os-plus/build-helper/meson/enable-all-warnings')

# Since the order of processing is significative, include it in dependencies.
# subdir('platforms/'+ xpack_platform_name + '/meson/platform-options')

# -----------------------------------------------------------------------------
# Dependencies #

# Set `xpack_dependencies_folders` with the platform specific dependencies.
subdir('platforms/'+ xpack_platform_name + '/meson/dependencies-folders')

foreach dep: xpack_dependencies_folders
  message('Adding ' + dep + '...')
  subdir(dep)
endforeach

# -----------------------------------------------------------------------------

# Include the project library, defined one level above.
message('Adding top library...')
subdir('top')

# -----------------------------------------------------------------------------
# Platform specifics #

# Include the platform specific targets and tests.
subdir('platforms/' + xpack_platform_name)

# -----------------------------------------------------------------------------
