[![license](https://img.shields.io/github/license/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/micro-test-plus-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/actions?query=workflow%3A%22CI+on+Push%22)

# A source library xPack with µTest++, a testing framework for embedded platforms

The **µTest++** project (_micro test plus_) provides a relatively simple
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

The initial version of the **µTest++** framework was inspired by
[Node tap](https://node-tap.org) and has only a limited number of primitives.
The later v3.x was a full rework inspired by
[Boost UT](https://boost-ext.github.io/ut/) and was the reason to raise the
bar to C++ 20.

- for complex applications, test cases can be grouped in test suites
- test suites can be located in separate compilation units, and automatically
  register themselves to the runner;
- a test suite is a named sequence of test cases
- a test case is a sequence of conditions expected to be true
- test conditions are either common logical expressions, or they check
  if an exception was thrown (or no exception was thrown)
- each test condition either succeeds or fails
- the test progress is shown on STDOUT, with each test condition on a
  separate line, prefixed with either a check sign (✓) or a cross sign (✗)
- failed expectations display the location in the file and
  the actual values used in the expression evaluation
- the main result of the test is passed back as the process exit code

If there is at least one successful tested condition and there are no
failed tests, each test suite is considered successful;
if all tests suites are successful, the process returns 0 as exit value.

### ISTQB Glossary

The **International Software Testing Qualification Board** defines some terms
used in testing frameworks:

- test condition: A testable aspect of a component or system identified
  as a basis for testing.
- test case: A set of preconditions, inputs, actions (where applicable),
  expected results and postconditions, developed based on test conditions.
- test suite: A set of test scripts or test procedures to be executed in
  a specific test run.

For more details see: <http://glossary.istqb.org/en/search/test%20case>.

### C++ API

Aiming simplicity, µTest++ provides only a small number of primitives used
to check expectations/assumptions defined as logical conditions:

#### Expectations

Expectations are checks whose results are counted and do not
stop the fest (as opposed to assumptions, which abort the test).

```C++
template <class Expr_T, type_traits::requires_t<....>>
bool expect(const Expr_T& expr, const char *message = "");
```

The template matches only expressions that evaluate to
a boolean or use custom comparators/operators derived from a
local `op` type; these expressions are guaranteed when using
the provided comparators (see below).

#### Assumptions

Assumptions are checks that abort the test if the results are false.

```C++
template <class Expr_T, type_traits::requires_t<....>>
bool assume(const Expr_T& expr, const char *message = "");
```

Similarly, the template matches only expressions that evaluate to
a boolean or use custom comparators/operators derived from a
local `op` type; these expressions are guaranteed when using
the provided comparators (see below).

#### Comparators

Expectations and assumptions may use any expression evaluating to a
boolean value, but in order to nicely report the difference between expected
and actual values in failed
conditions, the following generic comparators are available:

```c++
template <class Lhs_T, class Rhs_T>
eq(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
ne(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
lt(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
le(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
gt(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
ge(const Lhs_T& lhs, const Rhs_T& rhs);
```

Similar templates are defined for pointer comparators.

Examples:

```c++
expect (eq (compute_answer (), 42), "answer is 42");
expect (ne (compute_answer (), 43), "answer is not 43");
expect (lt (compute_answer (), 43), "answer is < 43");
expect (le (compute_answer (), 43), "answer is <= 42");
expect (gt (compute_answer (), 41), "answer is > 43");
expect (ge (compute_answer (), 42), "answer is >= 42");

expect (compute_condition (), "condition is true");
```

When such comparators are used, failed checks also display the
actual values used during the test, for example:

```console
  Check failed comparisons
    ✗ actual != 42 FAILED (unit-test.cpp:286, 42 != 42)
    ✗ FAILED (unit-test.cpp:307, 42 != 42)
    ✗ 42 != 42_i FAILED (unit-test.cpp:310, 42 != 42)
    ✗ (actual == 42) and (actual != 42.0) FAILED (unit-test.cpp:781, (42 == 42 and 42.000000 != 42.000000))
```

#### Comparing strings

In C/C++, plain strings are actually pointers to characters, and comparing
them does not compare the content, but the memory addresses.

For string comparisons to compare the content, use `string_view`:

```c++
#include <string_view>
using namespace std::literals; // For the "sv" literal.
// ...

expect (eq (std::string_view{ compute_ultimate_answer () }, "fortytwo"sv),
        "ultimate_answer is 'fortytwo'");
```

#### Comparing containers

It is possible to directly compare containers for equality. The comparison
is done by iterating over the container and comparing each member.

```c++
expect (eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }),
        "vector{ 1, 2 } eq vector{ 1, 2 }");

expect (ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }),
        "vector{ 1, 2, 3 } ne vector{ 1, 2, 4 }");
```

#### Operators

As in most other C++ test frameworks,
is also possible to overload the `==`, `!=`, `<`, `>`, `<=`, `>=` operators.

To avoid interferences with possible other operators
defined by the application, these operators are enabled only for
specific types and are located in a separate namespace
(`micro_test_plus::operators`).

The following operators match only for operands derived from the local
`op` type, which can be enforced for constant values by using the
provided literals (like `1_i`) or, for dynamic values, by using the
provided casts (like `_i(expr)`):

```c++
template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator== (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator!= (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator< (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator<= (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator> (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator>= (const Lhs_T& lhs, const Rhs_T& rhs);
```

Examples:

```c++
using namespace micro_test_plus::operators;
using namespace micro_test_plus::literals;

expect (compute_answer () == 42_i, "answer is 42 (with literal)");
expect (_i (compute_answer ()) == 42, "answer is 42 (with cast)");
expect (compute_answer () != 43_i, "answer is not 43");
expect (compute_answer () < 43_i, "answer is < 43");
expect (compute_answer () <= 43_i, "answer is <= 42");
expect (compute_answer () > 41_i, "answer is > 43");
expect (compute_answer () >= 42_i, "answer is >= 42");
```

In addition, equality operators are also provided for `string_view`
objects and for iterable containers:

```c++
bool operator== (std::string_view lhs, std::string_view rhs);
bool operator!= (std::string_view lhs, std::string_view rhs);

template <class T, type_traits::requires_t<type_traits::is_container_v<T>>>
bool operator== (T&& lhs, T&& rhs);

template <class T, type_traits::requires_t<type_traits::is_container_v<T>>>
bool operator!= (T&& lhs, T&& rhs);
```

Examples:

```c++
#include <string_view>
using namespace std::literals; // For the "sv" literal.
// ...

using namespace micro_test_plus::operators;

expect (std::string_view{ compute_ultimate_answer () } == "fortytwo"sv,
        "ultimate answer == 'fortytwo'");

expect (std::vector<int>{ 1, 2 } == std::vector<int>{ 1, 2 },
        "vector{ 1, 2 } == vector{ 1, 2 }");

expect (std::vector<int>{ 1, 2, 3 } != std::vector<int>{ 1, 2, 4 },
        "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }");
```

#### Explicit namespace

If the operators interfere with application operators, or even if functions
interfere with application functions, it is recommended to
use the comparator functions, which can be more easily invoked
with explicit namespaces, possibly aliased to shorter names.

Example:

```c++
{
  namespace t = micro_test_plus;

  t::test_case ("Check answer", [] {
    t::expect (t:eq(compute_answer(), 42), "answer is 42");
  });
}
```

#### Exceptions

It is possible to check if any exception was thrown,
if a specific exception was thrown, or no exception at all was thrown:

```C++
// Check if any exception was thrown.
template <class Callable_T>
throws (const Callable_T& expr, const char *message = "");

// Check if a specific exception was thrown.
template <class Exception_T, class Callable_T>
throws (const Callable_T& expr, const char *message = "");

// Check if no exceptions are thrown.
template <class Callable_T>
nothrow (const Callable_T& expr, const char *message = "");
```

Examples:

```c++
expect (throws ([] { exercise_throw (true); }), "exception thrown");

expect (throws<std::runtime_error> ([] { throw std::runtime_error{ "" }; }),
        "std::runtime_error thrown");

expect (nothrow ([] { exercise_throw (false); }), "exception not thrown");
```

#### Pass/Fail reporters

For generic checks performed outside the testing framework, the results can
be reported with two functions:

```C++
// Passed check.
bool pass(const char *message = "passed");
// Failes check.
bool fail(const char *message = "...");
```

Examples:

```c++
pass ("xyz passed");
fail ("xyz...");
```

#### Test cases

Test cases group several checks done in the same environment.

There can be any number of test cases, and each test case is performed
by invoking
a function, parametrised with a name, a callable (usually a lambda),
and optional arguments:

```C++
template <typename Callable_T, typename... Args_T>
void
test_case (const char* name, Callable_T&& func, Args_T&&... arguments);
```

Examples:

```c++
test_case ("Check various conditions", [] {
  expect (eq (compute_answer (), 42), "answer eq 42");
  expect (ne (compute_answer (), 43), "answer ne 43");
});

test_case ("Check various conditions with operators", [] {
  using namespace micro_test_plus::operators;
  using namespace micro_test_plus::literals;

  expect (compute_answer () == 42_i, "answer == 42 (with literal)");
  expect (compute_answer () != 43_i, "answer != 43");
});
```

#### Initialise the test runner

The test runner is initialised with a name and the process arguments:

```C++
void
initialize (const char* name, int argc, char* argv[]);
```

#### Return the test result

The final test result to be returned to the system
(0 for pass, 1 for fail), is obtained with:

```C++
int
exit_code (void);
```

This call also triggers the execution of all global test suites.

Examples:

```c++
int
main (int argc, char* argv[])
{
  using namespace micro_test_plus;

  // There is a default test suite automatically defined in main().
  initialize ("Sample Test", argc, argv);

  test_case ("Check various conditions", [] {
    pass();
  });

  return exit_code ();
}
```

#### Test suites

Test suites are sequences of test cases.

The test cases defined in `main()` are considered the default test
suite, and are executed when invoked.

For complex applications it is also possible to define multiple test
suites, possibly in separate source files.

In order to make self-registration possible, test suites are classes,
which can be constructed with a name and a callable (usually a lambda),
which chaines the execution of the test cases:

```C++
class test_suite
{
public:
  template <class Callable_T>
  test_suite (const char* name, Callable_T callable);
}
```

It is recommended to instantiate the test suites as static objects.
The self-registration to the runner is done in the constructor.
For test suites defined in different compilation units, the order
in which they are executed replicates the order in which the
static constructors were invoked, and, since this order is not specified;
there should be no dependencies between test suites, as they
can be executed in any order.

The test cases in the separate test suites are executed when the
function `exit_code()` is invoked.

Examples:

```c++
static micro_test_plus::test_suite ts_1
    = { "A test suite", [] {
        using namespace micro_test_plus;

        test_case ("Check one", [] {
          pass ("Passed");
        });

        test_case ("Check two", [] {
          pass ("Passed");
        });
      }};
```

#### Custom types

It is possible to extend the comparators with templates matching custom
types, but this is not a trivial task and requires a good knowledge of
C++.

TODO: add a test to show this.

### Build & integration info

The project is written in C++, and the tests are expected to be
written in C++ too.

On embedded platforms, the test applications can be built with
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

The source file to be added to user projects are:

- `micro-test-plus.cpp`
- `test-reporter.cpp`
- `test-runner.cpp`
- `test-suite.cpp`

#### Preprocessor definitions

- `MICRO_OS_PLUS_TRACE` - to include the trace
- `MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS` to enable some tracing messages

#### Compiler options

- `-std=c++20` or higher for C++ sources

#### C++ Namespaces

- `micro_os_plus::micro_test_plus`
- `micro_os_plus::micro_test_plus::operators`
- `micro_os_plus::micro_test_plus::literals`

`micro_os_plus` is the top µOS++ namespace, and `micro_test_plus` is the
µTest++ namespace.

The `operators` namespace defines the custom operators, and the `literals`
namespace defines the literals (like `1_i`);

#### C++ Classes

- `micro_os_plus::micro_test_plus::test_suite`

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

An example showing how to use the µTest++ framework is
presented below and is also available in
[tests/src/sample-test.cpp](tests/src/sample-test.cpp).

Here are some excerpts:

```c++
#include <micro-os-plus/micro-test-plus.h>

using namespace micro_os_plus;
using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

// ...

// The test suite.
int
main (int argc, char* argv[])
{
  initialize ("Sample Test", argc, argv);

  test_case ("Check various conditions", [] {
    expect (eq (compute_answer (), 42), "answer is 42");
    expect (ne (compute_answer (), 43), "answer is not 43");
    expect (compute_condition (), "condition() is true");
  });

  test_case ("Check various conditions with operators", [] {
    using namespace micro_test_plus::operators;
    using namespace micro_test_plus::literals;

    expect (compute_answer () == 42_i, "answer == 42 (with literal)");
    expect (_i (compute_answer ()) == 42, "answer == 42 (with cast)");
    expect (compute_answer () != 43_i, "answer != 43");
  });

  test_case ("Check parameterised", [] {
    auto f = [] (int i) { return i + 42; };
    expect (eq (f (1), 43), "lambda == 43");
  });

#if defined(__EXCEPTIONS)

  test_case ("Check exceptions", [] {
    auto exercise_throw = [] { throw std::runtime_error{ "" }; }
    expect (throws<std::runtime_error> (
      exercise_throw), "std::runtime_error thrown");
  });

#endif // defined(__EXCEPTIONS)

  return t.result ();
}

// ----------------------------------------------------------------------------
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
1:     ✓ lambda == 43
1:
1:   Check exceptions
1:     ✓ std::runtime_error thrown
1:
1: Sample test passed (5 tests in 3 test cases)
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

- v3.x: major rework, with full set of comparators, exceptions,
  function templates for test cases and class templates for test suites;
- v2.3.x: deprecate `run_test_case(func, name)` in favour o
 `run_test_case(name, func)`, to prepare for variadic templates
- v2.x: the C++ namespace was renamed from `os` to `micro_os_plus`;
- v1.x: the code was extracted from the mono-repo µOS++ project.

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul/).

The code from Boost UT is released under the terms of the
[Boost Version 1.0 Software License](https://www.boost.org/LICENSE_1_0.txt).
