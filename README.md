[![license](https://img.shields.io/github/license/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/micro-test-plus-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/actions?query=workflow%3A%22CI+on+Push%22)

# A source xPack with µTest++, a minimalistic testing framework

The **µTest++** project (_micro test plus_) provides a very simple
testing framework, intended for running unit tests on embedded
platforms.

## Maintainer info

This page is addressed to developers who plan to include this package
into their own projects.

For maintainer infos, please see the
[README-MAINTAINER](README-MAINTAINER.md) file.

## Easy install

Note: the package will be available from npmjs.com at a later date.

When ready, this package will be available as
[`@micro-os-plus/micro-test-plus`](https://www.npmjs.com/package/@micro-os-plus/micro-test-plus)
from the `npmjs.com` registry; with [xpm](https://xpack.github.io/xpm/)
available, installing the latest version of the package is quite easy:

```console
$ cd <project>
$ xpm init # Unless a package.json is already present

$ xpm install @micro-os-plus/micro-test-plus@latest
```

This package is also available from
[GitHub](https://github.com/micro-os-plus/micro-test-plus-xpack):

```console
$ git clone https://github.com/micro-os-plus/micro-test-plus-xpack.git micro-test-plus-xpack.git
```

## Branches

Apart from the unused `master` branch, there are two active branches:

- `xpack`, with the latest stable version
- `xpack-develop`, with the current development version

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

## User info

The **µTest++** framework is inspired by [Node tap](https://node-tap.org),
but is way simpler and has only a limited number of primitives.

- test suites must be compiled as separate applications, one apllication
  can return only the result og one test suite
- a test suite may include any number of test cases
- each test case may perform any number of tests checks
- each test check either succeeds or fails
- the main result of the test is passed back as the process exit code
- the test progress is shown on STDOUT, with each test check on
  a separate line

If there is at least one successful test and there are no failed tests,
the entire test suite is successful and the process returns
the 0 exit value.

On embedded platforms, the test should be built with **Arm semihosting**
support.

## Build info

The project is written in C++, and the tests are expected to be
written in C++ too (although there are no
major reasons to prevent adding C wrappers).

To integrate this package into a build, consider the following details.

### Source folders

- `src`

The source file is: `micro-test-plus.cpp`.

### Include folders

- `include`

The file to be included is:

```c++
#include <micro-os-plus/micro-test-plus.h>
```

### Preprocessor definitions

- none required

### Compiler options

- `-std=c++11` or higher

### Namespace

- `os::mtp`

### Classes

- `os::mtp::test`

## Example

A simple example showing how to use the µTest++ framework is
available below and in [tests/sample.cpp](tests/sample.cpp); it is
also built as part of the CI test.

```c++
#include <micro-os-plus/micro-test-plus.h>

using namespace os;

// Forward definitions of the test cases.
void
test_case_something (mtp::test& t);

void
test_case_exception (mtp::test& t);

// The test suite.
int
main (int argc, char* argv[])
{
  mtp::test t (argc, argv);

  t.start_suite ("Sample test");

  t.run_test_case (test_case_something, "Check various conditions");

  t.run_test_case (test_case_exception, "Check if exceptions are thrown");

  return t.result ();
}

// Simple examples of functions to be tested.
int
compute_one ()
{
  return 1;
}

char*
compute_aaa ()
{
  return (char*)"aaa";
}

bool
compute_condition ()
{
  return true;
}

// Test equality or logical conditions.
void
test_case_something (mtp::test& t)
{
  // Currently only int and long values can be compared for equality.
  // For everything else use casts.
  MTP_EXPECT_EQ (t, compute_one (), 1, "compute_one() == 1");

  // Strings can also be compared (via `strcmp()`).
  MTP_EXPECT_EQ (t, compute_aaa (), "aaa", "compute_aaa() == 'aaa'");

  // More complex conditions are passed as booleans.
  MTP_EXPECT_TRUE (t, compute_condition (), "condition() is true");
}

// Test if something throws exceptions.
void
test_case_exception (mtp::test& t)
{
  try
    {
      // Do something that may throw
      // ...

      // If we reached here, everything is fine.
      MTP_PASS (t, "exception not thrown");
    }
  catch (...)
    {
      MTP_FAIL (t, "exception thrown");
    }
}

```

The output of running such a test looks like:

```console
$ xpm run test-sample
...

Built with clang Apple LLVM 12.0.0 (clang-1200.0.32.27), with exceptions.

Sample test started
  Check various conditions
    ✓ compute_one() == 1
    ✓ compute_aaa() == 'aaa'
    ✓ condition() is true

  Check if exceptions are thrown
    ✓ exception not thrown

Sample test passed (4 tests in 2 test cases)

...
```

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT), with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul).
