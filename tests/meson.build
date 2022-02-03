
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
## Global definitions ##

# https://mesonbuild.com/Reference-manual.html#subdir
subdir('meson/globals')
if meson.is_cross_build()
  # Bare-metal builds are very strict. Native builds may use any toolchain.
  subdir('top/xpacks/micro-os-plus-build-helper/meson/enable-all-warnings')
endif
subdir('platform-'+ xpack_platform_name + '/meson/globals')

# -----------------------------------------------------------------------------
## Dependencies ##

# xpack_dependencies[] must be set in the platform native globals.
foreach dep: xpack_dependencies
  message('Adding ' + dep + '...')
  subdir('top/' + dep)
endforeach

# -----------------------------------------------------------------------------

# Include the project library, defined one level above.
subdir('top')

# Include the platform specific code.
subdir('platform-' + xpack_platform_name)

# -----------------------------------------------------------------------------
