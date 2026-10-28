# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# build-helper/templates/common/_micro-os-plus/tests/meson/define-executables/meson-liquid.build
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

# Create the platform specific test executables.

# -----------------------------------------------------------------------------

message('Processing tests/meson/define-executables...')

# -----------------------------------------------------------------------------

tests = []

# Each test has its own library. Add only those enabled.
if xpack_enable_empty_test
  tests += {
    'name': 'empty-test',
    'dependency': test_empty_dependency,
    'compile_c_args': test_empty_dependency_compile_c_args,
    'compile_cpp_args': test_empty_dependency_compile_cpp_args,
  }
endif

if xpack_enable_minimal_test
  tests += {
    'name': 'minimal-test',
    'dependency': test_minimal_dependency,
    'compile_c_args': test_minimal_dependency_compile_c_args,
    'compile_cpp_args': test_minimal_dependency_compile_cpp_args,
  }
endif

if xpack_enable_suite_test
  tests += {
    'name': 'suite-test',
    'dependency': test_suite_dependency,
    'compile_c_args': test_suite_dependency_compile_c_args,
    'compile_cpp_args': test_suite_dependency_compile_cpp_args,
  }
endif

if xpack_enable_sample_test
  tests += {
    'name': 'sample-test',
    'dependency': test_sample_dependency,
    'compile_c_args': test_sample_dependency_compile_c_args,
    'compile_cpp_args': test_sample_dependency_compile_cpp_args,
  }
endif

if xpack_enable_unit_static_asserts_test
  tests += {
    'name': 'unit-static-asserts-test',
    'dependency': test_unit_static_asserts_dependency,
    'compile_c_args': test_unit_static_asserts_dependency_compile_c_args,
    'compile_cpp_args': test_unit_static_asserts_dependency_compile_cpp_args,
  }
endif

if xpack_enable_unit_checks_test
  tests += {
    'name': 'unit-checks-test',
    'dependency': test_unit_checks_dependency,
    'compile_c_args': test_unit_checks_dependency_compile_c_args,
    'compile_cpp_args': test_unit_checks_dependency_compile_cpp_args,
  }
endif

if xpack_enable_unit_combinations_test
  tests += {
    'name': 'unit-combinations-test',
    'dependency': test_unit_combinations_dependency,
    'compile_c_args': test_unit_combinations_dependency_compile_c_args,
    'compile_cpp_args': test_unit_combinations_dependency_compile_cpp_args,
  }
endif

if xpack_enable_unit_exceptions_test
  tests += {
    'name': 'unit-exceptions-test',
    'dependency': test_unit_exceptions_dependency,
    'compile_c_args': test_unit_exceptions_dependency_compile_c_args,
    'compile_cpp_args': test_unit_exceptions_dependency_compile_cpp_args,
  }
endif

if xpack_enable_unit_miscellaneous_test
  tests += {
    'name': 'unit-miscellaneous-test',
    'dependency': test_unit_miscellaneous_dependency,
    'compile_c_args': test_unit_miscellaneous_dependency_compile_c_args,
    'compile_cpp_args': test_unit_miscellaneous_dependency_compile_cpp_args,
  }
endif

if xpack_enable_unit_deprecated_test
  tests += {
    'name': 'unit-deprecated-test',
    'dependency': test_unit_deprecated_dependency,
    'compile_c_args': test_unit_deprecated_dependency_compile_c_args,
    'compile_cpp_args': test_unit_deprecated_dependency_compile_cpp_args,
  }
endif

# -----------------------------------------------------------------------------
# Define the tests executables.

foreach test : tests

  test_name = test['name']
  message('> ' + test_name)

  test_dependency = test['dependency']
  test_dependency_compile_c_args = test['compile_c_args']
  test_dependency_compile_cpp_args = test['compile_cpp_args']

  # ---------------------------------------------------------------------------
  _local_compile_args = [] # Common C/C++ args.
  _local_compile_c_args = []
  _local_compile_cpp_args = []
  _local_include_directories = []
  _local_sources = []
  _local_compile_definitions = []
  _local_dependencies = []
  _local_link_args = []
  _local_link_with = []

  _local_compile_c_args += common_options_dependency_compile_c_args
  _local_compile_cpp_args += common_options_dependency_compile_cpp_args

  _local_compile_c_args += test_dependency_compile_c_args
  _local_compile_cpp_args += test_dependency_compile_cpp_args

  _local_compile_c_args += xpack_tested_library_dependency_compile_c_args
  _local_compile_cpp_args += xpack_tested_library_dependency_compile_cpp_args

  # _local_compile_c_args += micro_os_plus_diag_trace_dependency_compile_c_args
  # _local_compile_cpp_args += micro_os_plus_diag_trace_dependency_compile_cpp_args

  _local_compile_c_args += micro_os_plus_platform_dependency_compile_c_args
  _local_compile_cpp_args += micro_os_plus_platform_dependency_compile_cpp_args

  if xpack_platform_name != 'synthetic-posix'
    # _local_compile_c_args += micro_os_plus_semihosting_dependency_compile_c_args
    # _local_compile_cpp_args += micro_os_plus_semihosting_dependency_compile_cpp_args
  endif

  if xpack_platform_name != 'synthetic-posix'
    _local_link_args += [
      '-Wl,-Map,'+ test_name + '-map.txt',
      # '-v',
    ]
  endif

  _local_dependencies += [ common_options_dependency ] 

  # The current test.
  _local_dependencies += [ test_dependency ] # <--- 

  # TODO: remove it after updating architecture dependencies.
  _local_dependencies += [ micro_os_plus_diag_trace_dependency ]

  # Platform specific dependencies. Bring device & architecture too
  _local_dependencies += [ micro_os_plus_platform_dependency ]

  if xpack_platform_name != 'synthetic-posix'
    _local_dependencies += [ micro_os_plus_semihosting_dependency ]
  endif

  _local_dependencies += xpack_dependencies_libraries

  # ---------------------------------------------------------------------------

  # https://mesonbuild.com/Reference-manual.html#executable
  test_executable = executable(
    test_name,
    include_directories: include_directories(_local_include_directories),
    sources: files(_local_sources),
    c_args: _local_compile_args + _local_compile_c_args + _local_compile_definitions,
    cpp_args: _local_compile_args + _local_compile_cpp_args + _local_compile_definitions,
    dependencies: _local_dependencies,
    link_args: _local_link_args,
    link_with: _local_link_with,
    name_suffix: xpack_platform_name != 'synthetic-posix' ? 'elf' : [],
  )

  # ---------------------------------------------------------------------------

  foreach xn : _local_include_directories
    message('A+ -I ' + xn)
  endforeach
  # Note: dependencies compile_args not shown.
  foreach xn : _local_sources + _local_compile_definitions + _local_compile_args + _local_compile_c_args + _local_compile_cpp_args + _local_link_args
    message('A+ ' + xn)
  endforeach
  message('A> ' + test_name)

  # ---------------------------------------------------------------------------

  if xpack_platform_name != 'synthetic-posix'

    # https://mesonbuild.com/Reference-manual_functions.html#custom_target
    if xpack_enable_report_size
      size = find_program('size')

      custom_target(
        test_name + '-size',

        input: test_executable,
        output: test_name + '.size',
        command: [
          size,
          '--format=berkeley',
          '@INPUT@'
        ],
        build_always_stale: true,
        build_by_default: true,
      )
    endif

    # -------------------------------------------------------------------------

    if xpack_enable_create_listing
      objdump = find_program('objdump')
      
      # --source --all-headers --demangle --line-numbers --wide "xxx.elf"
      custom_target(
        test_name + '-list',

        input: test_executable,
        output: test_name + '-list.txt',
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
        build_by_default: xpack_enable_create_listing,
        capture: true,
      )
    endif

    # -------------------------------------------------------------------------

    if xpack_enable_create_hex
      objcopy = find_program('objcopy')

      # -O ihex "xxx.elf"
      custom_target(
        test_name + '-hex',

        input: test_executable,
        output: test_name + '.hex',
        command: [
          objcopy,
          '-O',
          'ihex',
          '@INPUT@',
          '@OUTPUT@',
        ],
        build_always_stale: true,
        build_by_default: xpack_enable_create_hex,
      )
    endif

  endif

  # ---------------------------------------------------------------------------

  # Create a variable with the test test_name and assign it the executable object.
  set_variable(test_name.underscorify(), test_executable)

  # ---------------------------------------------------------------------------

  message('')  # Separator for readability

endforeach

# -----------------------------------------------------------------------------
