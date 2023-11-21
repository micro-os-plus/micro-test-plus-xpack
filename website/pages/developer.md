
# How to Use

@tableofcontents

## Motivation

The xPack Build Framework already includes ready to use
support for several testing frameworks
([Google Test](https://github.com/xpack-3rd-party/googletest-xpack),
[Catch2](https://github.com/xpack-3rd-party/catch2-xpack),
[Boost UT](https://github.com/xpack-3rd-party/boost-ut-xpack)).

However, they all are quite heavy in terms of memory resources; also the
learning curve for mastering them is quite steep.

Thus, for embedded projects, a simpler solution, with a smaller
memory footprint, was considered a useful addition.

## Overview

The initial version of the **µTest++** framework was inspired mainly by
[Node tap](https://node-tap.org) and aimed for simplicity.
The later v3.x was a full rework inspired by
[Boost UT](https://boost-ext.github.io/ut/).

The main characteristics of µTest++, basically inherited from Boost UT, are:

- intended to test **both C and C++** projects
- modern C++ 20 code (this was also the reason
  to raise the bar to C++ 20 for the entire µOS++ project)
- **macro free** (while preserving the nice feature of being able to report
  the file name and line number for failed tests)
- **expectations**, **assumptions**, **exceptions**
- **test cases**, **test suites**
- automatic test suites registration

As major differentiator from Boost UT:

- **reduced memory footprint**, since there are no dependencies on
  the standard C++ stream library
- a slightly **simplified API**

## Concepts and features

- for complex applications, test cases can be grouped in test suites
- test suites can be located in separate compilation units; they automatically
  register themselves to the runner;
- a **test suite** is a named sequence of test cases;
- a **test case** is a sequence of **test conditions**
  (or simply **tests**, or **checks**),
  which are expectations/assumptions,
  i.e. conditions expected to be true;
- tests are based on logical expressions, which usually
  compute a result and compare it to an expected value
- for C++ projects: it is also possible to check if, while evaluating
  an expression, **exceptions** are thrown or not;
- each test either succeeds or fails;
- for **expectations**, the runner keeps counts of them;
- **assumptions** are hard conditions expected to be true in order for the test
  to be able to run;
- failed assumptions abort the test;
- the test progress is shown on STDOUT, with each tests on a
  separate line, prefixed with either a check sign (✓) or a cross sign (✗);
- failed tests display the location in the file and, if possible,
  the actual values used in the expression evaluation;
- the main result of the test is passed back to the system as the process
  exit code.

A test suite is considered successful
if there is at least one successful expectation
and there are no failed tests.

If all tests suites are successful, the process returns 0 as exit value.

## ISTQB Glossary

The **International Software Testing Qualification Board** defines some terms
used in testing frameworks:

- **test condition**: a testable aspect of a component or system identified
  as a basis for testing (implemented in µTest++ as calls to `expect()` or
  `assume()` functions);
- **test case**: a set of preconditions, inputs, actions (where applicable),
  expected results and postconditions, developed based on test conditions
  (implemented in µTest++ as calls to the `test_case()` function)
- **test suite**: a set of test scripts or test procedures to be executed in
  a specific test run (implemented in µTest++ as instances of the
  `test_suite` class).

For more details see: [ISTBQ](http://glossary.istqb.org/en/search/test%20case).

## Getting started

The absolute minimal test has a single test case, with a single expectation;
for example:

```cpp
#include <micro-os-plus/micro-test-plus.h>

int
main(int argc, char* argv[])
{
  using namespace micro_os_plus::micro_test_plus;

  initialize(argc, argv, "Minimal");

  test_case ("Check truth", [] {
    expect (true);
  })

  return exit_code ();
}
```

When running this test, the output looks like:

```console
• Minimal - test suite started

  ✓ Check truth - test case passed (1 check)

✓ Minimal - test suite passed (1 check in 1 test case)
```

A slightly more useful example would check the result of a computed value;
for example:

```cpp
#include <micro-os-plus/micro-test-plus.h>

static int
compute_answer()
{
  return 42;
}

int
main(int argc, char* argv[])
{
  using namespace micro_os_plus::micro_test_plus;

  initialize(argc, argv, "The Answer");

  test_case ("Check answer", [] {
    expect (compute_answer() == 42) << "answer is 42";
  });

  return exit_code ();
}
```

```console
• The Answer - test suite started

  ✓ Check answer - test case passed (1 check)

✓ The Answer - test suite passed (1 check passed, 0 checks failed, in 1 test case)
```

In case the function returns the wrong answer, the test will fail;
for example:

```cpp
static int
compute_answer()
{
  return 42 + 1;
}
```

In this case the test will fail with:

```console
• The Answer - test suite started

  • Check answer - test case started
    ✗ answer is 42 FAILED (answer.cpp:17)
  ✗ Check answer - test case FAILED (0 checks passed, 1 check failed)

✗ The Answer - test suite FAILED (0 checks passed, 1 check failed, in 1 test case)
```

The output identifies the failed test as located at line 17, but does not
provide more details, for example it does not tell what was the actual
wrong answer.

To get such a useful information, the test should be slightly more elaborate,
and must use some custom comparators or operators; for example:

```cpp
// ...

int
main(int argc, char* argv[])
{
  using namespace micro_os_plus::micro_test_plus;

  initialize(argc, argv, "The Answer");

  test_case ("Check answer with comparator", [] {
    expect (eq (compute_answer (), 42)) << "answer is 42";
  });

  test_case ("Check answer with operator", [] {
    using namespace micro_os_plus::micro_test_plus::operators;
    using namespace micro_os_plus::micro_test_plus::literals;

    expect (compute_answer () == 42_i) << "answer is 42";
    expect (_i {compute_answer ()} == 42) << "answer is 42";
  });

  return exit_code ();
}
```

The result would look like:

```console
• The Answer - test suite started

  • Check answer with comparator - test case started
    ✗ answer is 42 FAILED (answer.cpp:17, 43 == 42)
  ✗ Check answer with comparator - test case FAILED (0 checks passed, 1 check failed)

  • Check answer with operator - test case started
    ✗ answer is 42 FAILED (answer.cpp:24, 43 == 42)
    ✗ answer is 42 FAILED (answer.cpp:25, 43 == 42)
  ✗ Check answer with operator - test case FAILED (0 checks passed, 1 check failed)

✗ The Answer - test suite FAILED (0 checks passed, 3 checks failed, in 2 test cases)
```

In the first case, `eq()` is a function that basically compares almost
everything and is able to keep track of the values of its operands.
There are similar functions for all comparisons.

In the second case, a custom operator is used. To avoid interferences
with other operators, this custom operator is defined in a separate namespace
(which must
be explicitly referred to as shown) and matches only operands of
some specific types.

To cast the integer constant `42` to such a specific type, a custom literal
is available (`_i`), which is also defined in a separate namespace.

In addition to literals used to define constants, there are also definitions
which can be used to cast expressions.

For the custom operators to match, it is necessary for at least one of
the operands
to be of the specific type, usually the constant using a literal, but if both
are expression, at least one of them must be casted.

