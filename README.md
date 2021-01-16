[![license](https://img.shields.io/github/license/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/LICENSE)

# A source xPack with µTest++, a minimalistic testing framework

The **µTest++** project provides a very simple testing framework,
intended for running unit tests on embedded platforms.

This README is addressed to developers who plan to include this package
into their own projects.

For maintainer infos, please see the
[README-MAINTAINER](README-MAINTAINER.md) file.

## Easy install

This package is available as
[`@micro-os-plus/micro-test-plus`](https://www.npmjs.com/package/@micro-os-plus/micro-test-plus)
from the `npmjs.com` registry; with [xpm](https://xpack.github.io/xpm/)
available, installing the latest version of the package is quite easy:

```console
$ cd <project>
$ xpm install @micro-os-plus/micro-test-plus@latest
```

Note: the package will be available from npmjs.com at a later date.

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

The **µTest++** framework is inspired by the [Node tap](https://node-tap.org),
but is way simpler and has only a limited number of primitives.

- each test suite must be compiled as a separate application
- a test suite may include any number of test cases
- each test case performs any number of tests checks
- each test check either succeeds or fails
- the main result of the test is passed as the process exit code
- the test progress is shown on STDOUT, with each test check on a separate line

The entire test suite is successful if there are no failed tests and there is
at least one successful test.

A simple example showing how to use the µTest++ framework is
available below and in [tests/sample.cpp](tests/sample.cpp); it is
built as part of the CI test.

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
  // Currently only int and long values can be compared.
  // For everything else use casts.
  MTP_EXPECT_EQ (t, compute_one (), 1, "compute_one() == 1");

  // Strings can also be compared (via `strcmp()`).
  MTP_EXPECT_EQ (t, compute_aaa (), "aaa", "compute_aaa() == 'aaa'");

  // More complex conditions are passed as booleans.
  MTP_EXPECT_TRUE (t, compute_condition (), "condition() is true");
}

// Test is something throws exceptions.
void
test_case_exception (mtp::test& t)
{
  try
    {
      // Do something that may throw
      MTP_PASS (t, "exception not thrown");
    }
  catch (...)
    {
      MTP_FAIL (t, "exception thrown");
    }
}

```

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT), with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul).
