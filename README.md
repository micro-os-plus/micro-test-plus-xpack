[![license](https://img.shields.io/github/license/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/micro-test-plus-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/actions?query=workflow%3A%22CI+on+Push%22)

# A source library xPack with µTest++, a minimalistic testing framework

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

As a source library xPacks, the easiest way to add it to a project is via
**xpm**, but it can also be used as any Git project, for example as a submodule.

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

## Developer info

### Overview

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

### ISTQB Glossary

The **International Software Testing Qualification Board** defines some terms
used in testing frameworks:

- test condition: A testable aspect of a component or system identified as a basis for testing.
- test case: A set of preconditions, inputs, actions (where applicable), expected results and postconditions, developed based on test conditions.
- test suite: A set of test scripts or test procedures to be executed in a specific test run.

For more details see: <http://glossary.istqb.org/en/search/test%20case>.

### C++ API

TBD

### Build & integration info

The project is written in C++, and the tests are expected to be
written in C++ too (although there are no
major reasons to prevent adding C wrappers).

On embedded platforms, the test applications should be built with
**Arm semihosting** support.

To ease the integration of this package into user projects, there
are already made CMake and meson configuration files (see below).

For other build systems, consider the following details:

#### Include folders

The following folder should be used during the build:

- `include`

The header file to be included in user project is:

```c++
#include <micro-os-plus/micro-test-plus.h>
```

#### Source folders

- `src`

The source file to be added to user projects is:

- `micro-test-plus.cpp`.

#### Preprocessor definitions

- none required

#### Compiler options

- `-std=c++20` or higher for C++ sources
- `-std=c11` for C sources

#### C++ Namespaces

- `micro_os_plus::micro_test_plus`

`micro_os_plus` is the top µOS++ namespace, and `micro_test_plus` is the µTest++ namespace.

#### C++ Classes

- `micro_os_plus::micro_test_plus::test_session`

The project includes only one class, `test_session`. To automate
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
target_link_libraries(your-target PRIVATE

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
    micro_os_plus_micro_test_plus_dependency,
  ]
)
```

### Examples

A simple example showing how to use the µTest++ framework is
presented below and is also available in
[tests/src/sample-test.cpp](tests/src/sample-test.cpp).

Here are some excerpts:

```c++
#include <micro-os-plus/micro-test-plus.h>

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

// ...

// The test suite.
int
main (int argc, char* argv[])
{
  micro_test_plus::test_session t (argc, argv);

  t.start_suite ("Sample test");

  t.run_test_case ("Check various conditions", test_case_something);

  t.run_test_case ("Check parameterised", test_case_parameterised, 42);

  t.run_test_case ("Check args", test_case_main_args, argc, argv);

#if defined(__EXCEPTIONS)

  t.run_test_case ("Check if exceptions are thrown",
                   test_case_exception_thrown);

  t.run_test_case ("Check if exceptions are not thrown",
                   test_case_exception_not_thrown);

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
test_case_something (micro_test_plus::test_session& t)
{
  // Currently only int and long values can be compared.
  // For everything else use casts.
  MTP_EXPECT_EQUAL (t, compute_one (), 1, "compute_one() == 1");

  // Strings can also be compared (via `strcmp()`).
  MTP_EXPECT_EQUAL (t, compute_aaa (), "aaa", "compute_aaa() == 'aaa'");

  // More complex conditions are passed as booleans.
  MTP_EXPECT_TRUE (t, compute_condition (), "condition() is true");
}

void
test_case_parameterised (micro_test_plus::test_session& t, int n)
{
  MTP_EXPECT_EQUAL (t, n, 42, "parameter is 42");
}

void
test_case_main_args (micro_test_plus::test_session& t, int argc, char* argv[])
{
  MTP_EXPECT_EQUAL (t, argc, 3, "argc == 3");

  if (argc > 1)
    {
      MTP_EXPECT_EQUAL (t, argv[1], "one", "argv[1] == 'one'");
    }

  if (argc > 2)
    {
      MTP_EXPECT_EQUAL (t, argv[2], "two", "argv[2] == 'two'");
    }
}

// ----------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

// Test is something throws exceptions.
void
test_case_exception_thrown (micro_test_plus::test_session& t)
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
test_case_exception_not_thrown (micro_test_plus::test_session& t)
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

> cd build/native-cmake-release && ctest -V
UpdateCTestConfiguration  from :/Users/ilg/My Files/WKS Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-release/DartConfiguration.tcl
UpdateCTestConfiguration  from :/Users/ilg/My Files/WKS Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-release/DartConfiguration.tcl
Test project /Users/ilg/My Files/WKS Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-release
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: sample-test

1: Test command: /Users/ilg/My\ Files/WKS\ Projects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/build/native-cmake-release/platform-bin/sample-test "one" "two"
1: Test timeout computed to be: 10000000
1: Built with clang Apple LLVM 13.0.0 (clang-1300.0.29.30), no FP, with exceptions.
1:
1: Sample test started
1:
1:   Check various conditions
1:     ✓ compute_one() == 1
1:     ✓ compute_aaa() == 'aaa'
1:     ✓ condition() is true
1:
1:   Check parameterised
1:     ✓ parameter is 42
1:
1:   Check args
1:     ✓ argc == 3
1:     ✓ argv[1] == 'one'
1:     ✓ argv[2] == 'two'
1:
1:   Check if exceptions are thrown
1:     ✓ exception thrown
1:
1:   Check if exceptions are not thrown
1:     ✓ exception not thrown
1:
1: Sample test passed (9 tests in 3 test cases)
1/2 Test #1: sample-test ......................   Passed    0.00 sec
test 2
    Start 2: unit-test
...
```

### Known problems

- none

### Tests

The project is fully tested via GitHub
[Actions](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/)
on each push.

The test platforms are GNU/Linux, macOS and Windows, the tests are
compiled with GCC, clang and arm-none-eabi-gcc and run natively or
via QEMU.

There are two set of tests, one that runs on every push, with a
limited number of tests, and a set that is triggered manually,
usually before releases, and runs all tests on all supported
platforms.

The full set can be run manually with the following commands:

```sh
cd ~Work/micro-test-plus-xpack.git

xpm run install-all
xpm run test-all
```

## Change log - incompatible changes

According to [semver](https://semver.org) rules:

> Major version X (X.y.z | X > 0) MUST be incremented if any
backwards incompatible changes are introduced to the public API.

The incompatible changes, in reverse chronological order,
are:

- v2.3.x: deprecate `run_test_case(func, name)` in favour o
 `run_test_case(name, func)`, to prepare for variadic templates
- v2.x: the C++ namespace was renamed from `os` to `micro_os_plus`;
- v1.x: the code was extracted from the mono-repo µOS++ project.

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul/).
