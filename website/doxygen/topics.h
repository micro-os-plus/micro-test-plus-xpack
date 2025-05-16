/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/**
 * @file topics.h
 * @brief Doxygen group definitions and documentation topics for the µTest++
 * testing framework.
 * @details
 * This file defines the principal Doxygen groups and documentation topics for
 * the µTest++ testing framework, as part of the µOS++ project.
 *
 * Although named as a header, this file is not included in the build process;
 * it serves solely as a documentation resource for Doxygen. It cannot be
 * provided as a Markdown file or .doxyfile due to Doxygen processing
 * requirements.
 *
 * The file introduces the main documentation groups for the framework,
 * encompassing the C++ API, command-line options, expectations, assumptions,
 * comparators, operators, literals, utility functions, and test suite
 * management.
 *
 * The documentation is structured to deliver a comprehensive overview of the
 * framework's features, usage examples, and configuration options. It also
 * details the available verbosity modes and provides representative output for
 * various scenarios.
 *
 * All documentation topics and group definitions are maintained within this
 * file to ensure a consistent and modular structure. The file is located in
 * the `website/doxygen` folder to facilitate integration with the Doxygen
 * documentation system.
 */
/**
 * @dir src
 * @brief Source folder for the implementation of the µTest++ testing
 * framework.
 * @details
 * The `src` folder contains the core implementation files for the µTest++
 * testing framework, including the primary logic for test suite management,
 * test runner execution, result reporting, and supporting utilities.
 *
 * All source files within this folder are responsible for providing the
 * runtime behaviour and internal mechanisms of the framework. These
 * implementations are optimised for both embedded and general C++
 * environments, ensuring efficiency and reliability.
 *
 * The organisation of the `src` folder promotes maintainability and
 * modularity, enabling a clear separation between interface declarations
 * (located in the `include` folder) and implementation details.
 */
/**
 * @dir include
 * @brief Public header folder for the µTest++ testing framework.
 * @details
 * The `include` folder contains all public header files for the µTest++
 * testing framework, providing the primary interface for users and
 * integrators.
 *
 * This folder comprises declarations for test suite management, test runner
 * control, result reporting, mathematical utilities, type traits, literals,
 * operators, and supporting utilities. All public API definitions are
 * organised within this folder to ensure a clear separation from
 * implementation details, which reside in the `src` folder.
 *
 * The structure of the `include` folder promotes modularity, maintainability,
 * and ease of integration, enabling users to access the full capabilities of
 * the framework by including the appropriate headers in their projects.
 */
/**
 * @dir include/micro-os-plus
 * @brief Core public header folder for the µTest++ testing framework.
 * @details
 * The `include/micro-os-plus` folder contains the principal public header
 * files for the µTest++ testing framework, forming the main interface for
 * users and integrators.
 *
 * This folder includes declarations for all essential framework components,
 * such as test suite and test case management, test runner control, result
 * reporting, mathematical utilities, type traits, user-defined literals,
 * operators, reflection utilities, and supporting internal mechanisms.
 *
 * By organising all public API definitions within this folder, the project
 * ensures a clear separation from implementation details (which reside in the
 * `src` folder), thereby promoting modularity, maintainability, and ease of
 * integration.
 *
 * Users are encouraged to include the relevant headers from this folder to
 * access the full capabilities of the µTest++ framework in their projects.
 */
/**
 * @dir include/micro-os-plus/micro-test-plus
 * @brief Public header folder for the core components of the µTest++ testing
 * framework.
 * @details
 * The `include/micro-os-plus/micro-test-plus` folder contains the principal
 * public header files for the core functionality of the µTest++ testing
 * framework.
 *
 * This folder provides declarations for essential framework components,
 * including test suite and test case management, test runner and reporter
 * classes, mathematical utilities, type traits, user-defined literals,
 * operators, reflection utilities, and supporting internal mechanisms.
 *
 * By consolidating all public API definitions within this folder, the project
 * ensures a clear distinction from implementation details (which reside in the
 * `src` folder), thereby promoting modularity, maintainability, and ease of
 * integration.
 *
 * Users are advised to include the relevant headers from this folder to access
 * the full capabilities of the µTest++ framework in their projects.
 */
/**

@defgroup micro-test-plus µTest++
@ingroup micro-os-plus
@brief Topics relating to the µTest++ Testing Framework.
@details

µTest++ is a C++ source code library that delivers a lightweight testing
framework, specifically designed for embedded systems.

It provides a modern C++ API.

The verbosity of the test output can be adjusted using various command-line
options.


@defgroup micro-test-plus-cpp-api C++ API
@brief Topics relating to the µTest++ C++ API.
@ingroup micro-test-plus
@details

The implementation of µTest++ makes extensive use of modern C++ features. With
a focus on simplicity, µTest++ offers only a concise set of primitives for
verifying expectations and assumptions.

No preprocessor macros are employed; all primitives are implemented directly in
C++.


@defgroup micro-test-plus-c-api C API
@brief µTest++ C API Topics (note: not available).
@ingroup micro-test-plus
@details

Whilst µTest++ can be used to test C code without difficulty, its
implementation relies extensively on modern C++ features that cannot be
reproduced in C.

As a result, there are no C equivalents for the C++ definitions provided by
µTest++.


@defgroup micro-test-plus-cli Command Line Options
@brief Options for controlling verbosity at run-time.
@ingroup micro-test-plus
@details

## Description

By default, the µTest++ reporter presents detailed results solely for failed
test cases; successful test cases are summarised in a single line, indicating
the total number of passed and failed checks.

@par Example

```console
test 1
      Start  1: minimal-test

1: Test command:
/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/minimal-test
"one" "two" 1: Working Directory:
/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin
1: Test timeout computed to be: 10000000
1: Built with clang Apple LLVM 15.0.0 (clang-1500.0.40.1), with exceptions.
1:
1: • Minimal - test suite started
1:
1:   ✓ Check various conditions - test case passed (2 checks)
1:
1: ✓ Minimal - test suite passed (2 checks in 1 test case)
 1/12 Test  #1: minimal-test .....................   Passed    0.00 sec
```

## Verbosity

To modify the verbosity, one of the following command-line options may be
specified:

- `--verbose` – display all expectations, irrespective of the outcome
- `--quiet` – display only the test suite totals
- `--silent` – suppress all output and return only the exit code

@note
The source code for this test is located in the `tests/src/minimal-test.cpp`
file.

### Verbose mode

In verbose mode, the µTest++ reporter displays all expectations, regardless of
their result.

@par Example

```console
test 2
      Start  2: minimal-test --verbose

2: Test command:
/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/minimal-test
"one" "two" "--verbose" 2: Working Directory:
/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin
2: Test timeout computed to be: 10000000
2: Built with clang Apple LLVM 15.0.0 (clang-1500.0.40.1), with exceptions.
2:
2: • Minimal - test suite started
2:
2:   • Check various conditions - test case started
2:     ✓ answer is 42
2:     ✓ condition is true
2:   ✓ Check various conditions - test case passed (2 checks)
2:
2: ✓ Minimal - test suite passed (2 checks in 1 test case)
 2/12 Test  #2: minimal-test --verbose ...........   Passed    0.00 sec
```

### Quiet mode

In quiet mode, the µTest++ reporter outputs only the overall test suite totals.

@par Example

```console
test 3
      Start  3: minimal-test --quiet

3: Test command:
/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/minimal-test
"one" "two" "--quiet" 3: Working Directory:
/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin
3: Test timeout computed to be: 10000000
3:
3: ✓ Minimal - test suite passed (2 checks in 1 test case)
 3/12 Test  #3: minimal-test --quiet .............   Passed    0.00 sec
```

### Silent mode

In silent mode, the µTest++ reporter suppresses all output, and the framework
returns solely the exit code.

@par Example

```console
test 4
      Start  4: minimal-test --silent

4: Test command:
/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/minimal-test
"one" "two" "--silent" 4: Working Directory:
/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin
4: Test timeout computed to be: 10000000
4:
 4/12 Test  #4: minimal-test --silent ............   Passed    0.00 sec
```


@addtogroup micro-test-plus-cpp-api
@{


@defgroup micro-test-plus-inits Initialisation & Exit
@brief Functions for initialising the framework and returning an exit code.
@details

These functions are responsible for initialising the test runner and returning
the test result as the process exit code.

The simplest test consists of a single test case containing a single
expectation; for example:

```cpp
#include <micro-os-plus/micro-test-plus.h>

int
main(int argc, char* argv[])
{
  namespace mt = micro_os_plus::micro_test_plus;

  mt::initialize(argc, argv, "Minimal");

  mt::test_case ("Check truth", [] {
    mt::expect (true);
  })

  return mt::exit_code ();
}
```

When this test is executed, the output is as follows:

```console
• Minimal - test suite started

  ✓ Check truth - test case passed (1 check)

✓ Minimal - test suite passed (1 check in 1 test case)
```


@defgroup micro-test-plus-test-case Test Cases
@brief  Test cases are named sequences of checks.
@details

Test cases aggregate multiple checks to be performed within the same
environment.

Any number of test cases may be defined, each invoked by calling a function
parameterised with a name or description, a callable object (typically a
lambda), and optional arguments.

@par Examples

```cpp
namespace mt = micro_os_plus::micro_test_plus;

mt::test_case ("Check various conditions", [] {
  mt::expect (mt::eq (compute_answer (), 42)) << "answer eq 42";
  mt::expect (mt::ne (compute_answer (), 43)) << "answer ne 43";
});

mt::test_case ("Check various conditions with operators", [] {
  using namespace mt::operators;
  using namespace mt::literals;

  mt::expect (compute_answer () == 42_i) << "answer == 42";
  mt::expect (compute_answer () != 43_i) << "answer != 43";
});
```


@defgroup micro-test-plus-expectations Expectations
@brief  Expectations are checks whose outcomes are reported.
@details

Unlike assumptions, failed expectations are reported but do not cause the test
to terminate.


@defgroup micro-test-plus-assumptions Assumptions
@brief  Assumptions are conditions that must be satisfied for the test to
proceed.
@details

If an assumption fails, the test cannot continue and is terminated immediately.


@defgroup micro-test-plus-function-comparators Function Comparators
@brief  Functions for comparing actual and expected values.
@details

## Description

Expectations and assumptions may evaluate any expression yielding a boolean
value; however, to provide clear reporting of differences between actual and
expected values when checks fail, dedicated comparator functions should be
employed.

@par Examples

```cpp
mt::expect (mt::eq (compute_answer (), 42)) << "answer is 42";
mt::expect (mt::ne (compute_answer (), 43)) << "answer is not 43";
mt::expect (mt::lt (compute_answer (), 43)) << "answer is < 43";
mt::expect (mt::le (compute_answer (), 43)) << "answer is <= 42";
mt::expect (mt::gt (compute_answer (), 41)) << "answer is > 43";
mt::expect (mt::ge (compute_answer (), 42)) << "answer is >= 42";

mt::expect (compute_condition ()) << "condition is true";
```

When such comparator functions are employed, any failed checks will also
present the actual values compared during the test; for example:

```console
  Check failed comparisons
    ✗ actual != 42 FAILED (unit-test.cpp:286, 42 != 42)
    ✗ FAILED (unit-test.cpp:307, 42 != 42)
    ✗ 42 != 42_i FAILED (unit-test.cpp:310, 42 != 42)
    ✗ (actual == 42) and (actual != 42.0) FAILED (unit-test.cpp:781, (42 == 42
and 42.000000 != 42.000000))
```

### Comparing containers

Containers can be assessed for equality. The comparison is conducted by
iterating through each element and evaluating them individually.

@par Examples

```cpp
mt::expect (mt::eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
        << "vector{ 1, 2 } eq vector{ 1, 2 }";

mt::expect (mt::ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 })
        << "vector{ 1, 2, 3 } ne vector{ 1, 2, 4 }";
```

@defgroup micro-test-plus-logical-functions Logical Functions
@brief  Functions utilised in logical expressions.
@details

Complex expressions may be evaluated within a single statement by employing the
logical functions `mt::_and()`, `mt::_or()`, and `mt::_not()`.

@note
These names are prefixed with an underscore, as `and`, `or`, and `not` are
reserved keywords in both C and C++.

@par Example

```cpp
mt::expect(mt::_and (mt::eq (compute_answer (), 42), mt::eq (compute_float
(), 42.0)));
```

@note
When the operands are function comparators, it is recommended to utilise the
overloaded logical operators `&&`, `||`, and `!` provided within the
`micro_test_plus::operators` namespace.


@defgroup micro-test-plus-exceptions Checking Exceptions
@brief  Functions for verifying exceptions.
@details

A C++ testing framework should be capable of determining whether an expression
(typically a function call) throws an exception.

@par Examples

```cpp
mt::expect (mt::throws ([] { exercise_throw (true); })) << "exception thrown";

mt::expect (mt::throws<std::runtime_error> ([] { throw std::runtime_error{ ""
}; }))
        << "std::runtime_error thrown";

mt::expect (mt::nothrow ([] { exercise_throw (false); })) << "exception not
thrown";
```

If more advanced logic is required, such as handling multiple expected
exceptions, use an explicit `try` block with several `catch` statements, and
report the outcomes using `expect(true)` or `expect(false)`.

```cpp
try
  {
    compute_answer ();
  }
catch (const std::overflow_error& e)
  {
    mt::expect (true) << "std::overflow_error thrown";
  }
catch (const std::runtime_error& e)
  {
    mt::expect (true) << "std::runtime_error thrown";
  }
catch (...)
  {
    mt::expect (false) << "known exception thrown";
  }
```


@defgroup micro-test-plus-operators Operators
@brief Overloaded operators
@details

## Description

As with most other C++ testing frameworks, it is possible to overload the `==`,
`!=`, `<`, `>`, `<=`, and `>=` operators.

To avoid potential conflicts with operators defined by the application, these
operators are limited to operands of specific types and are placed within a
dedicated namespace (`micro_test_plus::operators`). When applied to standard
values, the default operators are utilised; comparisons are performed
correctly, but in the event of a failure, the actual values are not displayed.

These operators only match operands derived from the local `detail::op` type.
For constant values, this can be achieved using the provided literals (such as
`1_i`), or for dynamic values, by employing the provided casts (such as
`mt::to_i{expression}`), which are in fact constructors of the internal
classes.

@par Examples

```cpp
mt::test_case ("Operators", [] {
  using namespace micro_test_plus::operators;
  using namespace micro_test_plus::literals;

  mt::expect (compute_answer () == 42_i) << "answer is 42 (with literal)";
  mt::expect (mt::to_i {compute_answer ()} == 42) << "answer is 42 (with
cast)"; mt::expect (compute_answer () != 43_i) << "answer is not 43";
  mt::expect (compute_answer () < 43_i) << "answer is < 43";
  mt::expect (compute_answer () <= 43_i) << "answer is <= 42";
  mt::expect (compute_answer () > 41_i) << "answer is > 43";
  mt::expect (compute_answer () >= 42_i) << "answer is >= 42";
});
```

### Logical operators

Logical operators may be utilised in precisely the same manner as standard
operators; however, the enhanced functionality is available exclusively when
employed with typed operands.

@par Example

```cpp
mt::expect (compute_answer () == 42_i && compute_float () == 42.0_f);
```


@defgroup micro-test-plus-string-operators String Operators
@brief Overloaded operators for string comparison.
@details

In addition to the generic operators, specific equality operators are provided
for `string_view` objects.

@par Examples

```cpp
#include <string_view>
using namespace std::literals; // For the "sv" literal.
namespace mt = micro_os_plus::micro_test_plus;
// ...

mt::test_case ("Operators", [] {
  using namespace micro_test_plus::operators;

  mt::expect (std::string_view{ compute_ultimate_answer () } == "forty-two"sv)
          << "ultimate answer == 'forty-two'";
});
```


@defgroup micro-test-plus-container-operators Container Operators
@brief Overloaded operators for container comparison.
@details

In addition to the generic operators, specialised equality operators are also
provided for containers.

@par Examples

```cpp
#include <string_view>
using namespace std::literals; // For the "sv" literal.
namespace mt = micro_os_plus::micro_test_plus;
// ...

mt::test_case ("Operators", [] {
  using namespace micro_test_plus::operators;

  mt::expect (std::vector<int>{ 1, 2 } == std::vector<int>{ 1, 2 })
          << "vector{ 1, 2 } == vector{ 1, 2 }";

  mt::expect (std::vector<int>{ 1, 2, 3 } != std::vector<int>{ 1, 2, 4 })
          << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
});
```


@defgroup micro-test-plus-literals Literals and Wrappers
@brief Literal operators and wrappers.
@details

To convert constants into recognised typed operands, the framework provides
several literal operators within the dedicated `literals` namespace.

Similarly, for dynamic values, wrappers are available to convert them into
recognised types.

@par Examples

```cpp
mt::expect (mt::to_i {answer} == 42_i);
mt::expect (mt::to_f {expression} == 42_f);
```


@defgroup micro-test-plus-utility-functions Utility Functions
@brief Functions to assist with string operations.
@details

When performing string operations within tests, it is sometimes necessary to
match partial strings or to split lengthy strings.


@defgroup micro-test-plus-test-suites Test Suites
@brief Test suites are named sequences of test cases.
@details

The test cases defined in `main()` are regarded as part of the default (or
main) test suite and are executed immediately upon invocation.

For more complex applications, multiple test suites may be defined, typically
in separate source files.

To facilitate self-registration, test suites are implemented as classes,
constructed with a name, a callable (usually a lambda that chains the execution
of the test cases), and optional arguments:

```cpp
class test_suite : public test_suite_base
{
public:
  template <typename Callable_T, typename... Args_T>
  test_suite (const char* name, Callable_T&& callable,
              Args_T&&... arguments);
  // ...
}
```

@note
It is advisable to instantiate test suites as static objects.

Self-registration is performed within the constructor. Test suites defined in
separate compilation units may be executed in any order, as the sequence in
which static constructors are invoked is not specified; consequently, there
should be no dependencies between test suites.

All registered test suites are executed when the `exit_code()` function is
called.

@par Examples

```cpp
namespace mt = micro_os_plus::micro_test_plus;

// Test suite with generic parameters.
static void
test_suite_args (int ic, int iv, int& ir, int* ip1, int* ip2)
{
  mt::test_case ("args", [&] {
    mt::expect (mt::eq (ic, 42)) << "ic is 42";
    mt::expect (mt::eq (iv, 43)) << "iv is 43";
    mt::expect (mt::eq (ir, 44)) << "ir is 44";
    mt::expect (mt::eq (*ip1, 45)) << "*ip1 is 45";
    mt::expect (mt::eq (*ip2, 46)) << "*ip2 is 46";
  });
}

static int in = 43;
static int in44 = 44;
static int& ir = in44;
static int in45 = 45;
static int in46 = 46;
static int* ip2 = &in46;

static mt::test_suite ts_args
    = { "Args", test_suite_args, 42, in, ir, &in45, ip2 };
```

@}

*/
