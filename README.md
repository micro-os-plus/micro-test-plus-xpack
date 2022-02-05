[![license](https://img.shields.io/github/license/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/micro-test-plus-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/actions?query=workflow%3A%22CI+on+Push%22)

# A source xPack with µTest++, a minimalistic testing framework

The **µTest++** project (_micro test plus_) provides a very simple
testing framework, intended for running unit tests on embedded
platforms.

The project is hosted on GitHub as
[micro-os-plus/micro-test-plus-xpack](https://github.com/micro-os-plus/micro-test-plus-xpack).

## Maintainer info

This page is addressed to developers who plan to include this package
into their own projects.

For maintainer infos, please see the
[README-MAINTAINER](README-MAINTAINER.md) file.

## Install

As a source xPacks, the easiest way to add it to a project is via **xpm**,
but it can also be used as any Git project, for example as a submodule.

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

For details please follow the instructions in the
[install](https://xpack.github.io/install/) page.

### xpm

This package is available as
[`@micro-os-plus/micro-test-plus`](https://www.npmjs.com/package/@micro-os-plus/micro-test-plus)
from the `npmjs.com` registry:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @micro-os-plus/micro-test-plus@latest
```

### Git submodule

If, for any reason, **xpm** is not available, the next recommended
solution is to link it as a Git submodule below an `xpacks` folder.

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/micro-os-plus/micro-test-plus-xpack.git \
  xpacks/micro-os-plus-micro-test-plus
```

## Branches

Apart from the unused `master` branch, there are two active branches:

- `xpack`, with the latest stable version (default)
- `xpack-develop`, with the current development version

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

## User info

The **µTest++** framework is inspired by [Node tap](https://node-tap.org),
but is way simpler and has only a limited number of primitives.

- test suites must be compiled as separate applications, one apllication
  can return only the result of one test suite
- a test suite may include any number of test cases
- each test case may perform any number of tests checks
- each test check either succeeds or fails
- the test progress is shown on STDOUT, with each test check on a separate
  line, prefixed with either a check sign (✓) or a cross sign (✗)
- the main result of the test is passed back as the process exit code

If there is at least one successful test and there are no failed tests,
the entire test suite is successful and the process returns
0 as exit value.

### Build & integration info

The project is written in C++, and the tests are expected to be
written in C++ too (although there are no
major reasons to prevent adding C wrappers).

On embedded platforms, the test applications should be built with
**Arm semihosting** support.

To ease the integration of this package into user projects, there
are already made CMake and meson configuration files (see below).

For other build systems, consider the following details:

#### Source folders

- `src`

The source file to be added to user projects is: `micro-test-plus.cpp`.

#### Include folders

- `include`

The header file to be included in user project is:

```c++
#include <micro-os-plus/micro-test-plus.h>
```

#### Preprocessor definitions

- none required

#### Compiler options

- `-std=c++17` or higher for C++ sources
- `-std=c11` for C sources

#### C++ Namespaces

- `micro_os_plus::micro_test_plus`

`micro_os_plus` is the top µOS++ namespace, and `micro_test_plus` is the µTest++ namespace.

#### C++ Classes

- `micro_os_plus::micro_test_plus::session`

The project includes only one class, `session`. To automate
passing the file name and the line number, several macros were added.

#### CMake

To integrate the µTest++ source library into a CMake application, add this
folder to the build:

```cmake
add_subdirectory("xpacks/micro-os-plus-micro-test-plus")`
```

The result is an interface library that can be added as an application
dependency with:

```cmake
target_link_libraries(
  your-target

  PUBLIC
    ...
    micro-os-plus::micro-test-plus
)
```

#### meson

To integrate the µTest++ source library into a meson application, add this
folder to the build:

```meson
subdir('xpacks/micro-os-plus-micro-test-plus')
```

The result is a dependency object that can be added as an application
dependency with:

```meson
exe = executable(
  your-target,

  dependencies: [
    ...
    micro_os_plus_micro_test_plus_dependency
  ]
)
```

### Examples

A simple example showing how to use the µTest++ framework is
presented below and is also available in
[tests/sample-test.cpp](tests/sample-test.cpp).

```c++
#include <micro-os-plus/micro-test-plus.h>

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

// Forward definitions of the test cases.
void
test_case_something (micro_test_plus::session& t);

void
test_case_args (micro_test_plus::session& t);

#if defined(__EXCEPTIONS)

void
test_case_exception_thrown (micro_test_plus::session& t);

void
test_case_exception_not_thrown (micro_test_plus::session& t);

#endif // defined(__EXCEPTIONS)

int
compute_one (void);

const char*
compute_aaa (void);

bool
compute_condition (void);

#if defined(__EXCEPTIONS)

void
exercise_throw (bool mustThrow);

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

static int g_argc;
static char** g_argv;

// The test suite.
int
main (int argc, char* argv[])
{
  micro_test_plus::session t (argc, argv);

  g_argc = argc;
  g_argv = argv;

  t.start_suite ("Sample test");

  t.run_test_case (test_case_something, "Check various conditions");

  t.run_test_case (test_case_args, "Check args");

#if defined(__EXCEPTIONS)

  t.run_test_case (test_case_exception_thrown,
                   "Check if exceptions are thrown");

  t.run_test_case (test_case_exception_not_thrown,
                   "Check if exceptions are not thrown");

#endif // defined(__EXCEPTIONS)

  return t.result ();
}

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
int
compute_one (void)
{
  return 1;
}

const char*
compute_aaa (void)
{
  return "aaa";
}

bool
compute_condition (void)
{
  return true;
}

#if defined(__EXCEPTIONS)

void
exercise_throw (bool mustThrow)
{
  if (mustThrow)
    {
      throw "kaboom";
    }
}

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

// Test equality or logical conditions.
void
test_case_something (micro_test_plus::session& t)
{
  // Currently only int and long values can be compared.
  // For everything else use casts.
  MTP_EXPECT_EQ (t, compute_one (), 1, "compute_one() == 1");

  // Strings can also be compared (via `strcmp()`).
  MTP_EXPECT_EQ (t, compute_aaa (), "aaa", "compute_aaa() == 'aaa'");

  // More complex conditions are passed as booleans.
  MTP_EXPECT_TRUE (t, compute_condition (), "condition() is true");
}

void
test_case_args (micro_test_plus::session& t)
{
  MTP_EXPECT_EQ (t, g_argc, 3, "argc == 3");

  if (g_argc > 1)
    {
      MTP_EXPECT_EQ (t, g_argv[1], "one", "argv[1] == 'one'");
    }

  if (g_argc > 2)
    {
      MTP_EXPECT_EQ (t, g_argv[2], "two", "argv[2] == 'two'");
    }
}

// ----------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

// Test is something throws exceptions.
void
test_case_exception_thrown (micro_test_plus::session& t)
{
  try
    {
      // Do something that throws.
      exercise_throw (true);

      // If we reached here, the exception was not thrown.
      MTP_FAIL (t, "exception not thrown");
    }
  catch (...)
    {
      // Got it.
      MTP_PASS (t, "exception thrown");
    }
}

void
test_case_exception_not_thrown (micro_test_plus::session& t)
{
  try
    {
      // Do something that may throw, but it doesn't.
      exercise_throw (false);

      // If we reached here, everything is fine.
      MTP_PASS (t, "exception not thrown");
    }
  catch (...)
    {
      MTP_FAIL (t, "exception thrown");
    }
}

#endif // defined(__EXCEPTIONS)

```

The output of running such a test looks like:

```console
$ cd micro-test-plus-xpack.git
$ xpm install-all
...
$ xpm run test-native
...
> Executing task: xpm run test --config native-cmake-debug <

> cd build/native-cmake-debug && ctest -V
UpdateCTestConfiguration  from :/Users/ilg/My Files/WKS Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-debug/DartConfiguration.tcl
UpdateCTestConfiguration  from :/Users/ilg/My Files/WKS Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-debug/DartConfiguration.tcl
Test project /Users/ilg/My Files/WKS Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-debug
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: unit-test

1: Test command: /Users/ilg/My\ Files/WKS\ Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-debug/platform/unit-test
...
1/2 Test #1: unit-test ........................   Passed    0.00 sec
test 2
    Start 2: sample-test

2: Test command: /Users/ilg/My\ Files/WKS\ Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-debug/platform/sample-test "one" "two"
2: Test timeout computed to be: 10000000
2: Built with clang Apple LLVM 13.0.0 (clang-1300.0.29.30), no FP, with exceptions, with DEBUG.
2: argv[] = '/Users/ilg/My Files/WKS Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-debug/platform/sample-test' 'one' 'two'
2:
2: Sample test started
2:
2:   Check various conditions
2:     ✓ compute_one() == 1
2:     ✓ compute_aaa() == 'aaa'
2:     ✓ condition() is true
2:
2:   Check args
2:     ✓ argc == 3
2:     ✓ argv[1] == 'one'
2:     ✓ argv[2] == 'two'
2:
2:   Check if exceptions are thrown
2:     ✓ exception thrown
2:
2:   Check if exceptions are not thrown
2:     ✓ exception not thrown
2:
2: Sample test passed (8 tests in 4 test cases)
2/2 Test #2: sample-test ......................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```

### Known problems

- none

### Tests

The project is fully tested via GitHub
[Actions](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/)
on each push.
The tests run on GNU/Linux, macOS and Windows, are compiled with GCC,
clang and arm-none-eabi-gcc and run natively or via QEMU.

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul/).
