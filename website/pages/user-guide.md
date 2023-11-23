
# User Guide

@tableofcontents

## Rationale

At the very limit, the simplest testing framework is the no-framework at all!
A test for a C/C++ project can be very well written without any framework,
possibly using the standard `assert()` macro, or even some similar user
defined mechanism.

However, failed asserts usually abort the test, and in case of multiple
test cases with multiple checks, it would be better to get a nice report.

Test frameworks do exactly this, they provide convenient mechanisms to write
various checks and to get a nice report.

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

### Minimal test

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

### Test a computed value

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

### More elaborate comparators

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

### More complex tests

For simple tests, invoking multiple test cases in `main()` might be enough.

For more complex applications, test cases can be grouped in test suites,
and invoked, possibly multiple times with different arguments.

Test cases are best instantiated as static objects; they self-register
automatically to the testing framework using the static constructors
mechanism, and are execute when the `exit_code()` function is invoked.

@par Examples

```cpp
// Define a function template to run the tests.
template <class T>
void
check_double_list_links (void)
{
  using namespace micro_os_plus::micro_test_plus;

  static T left_links;
  static T links;
  static T right_links;

  test_case ("Initial", [&] {
    if constexpr (T::is_statically_allocated::value)
      {
        // Check if the node is cleared.
        expect (eq (links.previous (), nullptr)) << "prev is null";
        expect (eq (links.next (), nullptr)) << "next is null";
        expect (links.uninitialized ()) << "uninitialized";

        left_links.initialize ();
        links.initialize ();
        right_links.initialize ();
      }

    expect (!left_links.linked ()) << "left unlinked";
    expect (!links.linked ()) << "unlinked";
    expect (!right_links.linked ()) << "right unlinked";
  });

  test_case ("Link", [&] {
    // Link left as previous.
    links.link_previous (&left_links);

    // Link right as next.
    links.link_next (&right_links);

    // The node must appear as linked now.
    expect (links.linked ()) << "linked";

    expect (eq (left_links.next (), &links)) << "left linked";
    expect (eq (right_links.previous (), &links)) << "right linked";
  });

  test_case ("Unlink", [&] {
    // Unlink the central node.
    links.unlink ();
    expect (!links.linked ()) << "unlinked";

    // Left and right must indeed point to each other.
    expect (eq (left_links.next (), &right_links)) << "left -> right";
    expect (eq (right_links.previous (), &left_links)) << "right <- right";
  });

  if constexpr (!T::is_statically_allocated::value)
    {
      test_case ("Allocated on stack", [] {
        T stack_links;
        expect (!stack_links.linked ()) << "unlinked";
      });
    }
}

// Instantiate the test for statically allocated lists.
static micro_os_plus::micro_test_plus::test_suite ts_static_double_list_links
    = {
        "Static double list links",
        check_double_list_links<micro_os_plus::utils::static_double_list_links>
      };

// Instantiate the same test for regular lists.
static micro_os_plus::micro_test_plus::test_suite ts_double_list_links
    = { "Double list links",
        check_double_list_links<micro_os_plus::utils::double_list_links> };
```

## C++ API

### Namespaces

The definitions are grouped in several namespaces below `micro_os_plus`:

- `micro_os_plus::micro_test_plus`
- `micro_os_plus::micro_test_plus::operators`
- `micro_os_plus::micro_test_plus::literals`
- `micro_os_plus::micro_test_plus::utility`

`micro_os_plus` is the top µOS++ namespace, and `micro_test_plus` is the
µTest++ namespace.

The `operators` namespace defines the custom operators, and the `literals`
namespace defines the literals (like `1_i`);

### Test runner initialisation & exit

There are two functions to initialise the test runner and to
return the test result as the process exit.

```cpp
void initialize (int argc, char* argv[], const char* name = "Main");

int exit_code (void);
```

See the reference [Initialisation & exit](group__micro-test-plus-inits.html) page.

### Test cases

Test cases are groups of several checks to be executed in the same environment.

```cpp
template <typename Callable_T, typename... Args_T>
void test_case (const char* name, Callable_T&& func, Args_T&&... arguments);
```

See the reference [Test cases](group__micro-test-plus-test-case.html) page.

### Expectations & assumptions

Expectations and assumptions are functions that check expressions
evaluating to boolean values.

```cpp
template <class Expr_T, type_traits::requires_t<....>>
bool expect(const Expr_T& expr);

template <class Expr_T, type_traits::requires_t<....>>
bool assume(const Expr_T& expr);
```

See the reference [Expectations](group__micro-test-plus-expectations.html)
and [Assumptions](group__micro-test-plus-assumptions.html) pages.

### Function comparators

In order to nicely report the difference between expected
and actual values in failed
conditions, several generic comparators are provided.

```cpp
template <class Lhs_T, class Rhs_T>
auto eq(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
auto ne(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
auto lt(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
auto le(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
auto gt(const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
auto ge(const Lhs_T& lhs, const Rhs_T& rhs);
```

See the reference [Function comparators](group__micro-test-plus-function-comparators.html) page.

### Logical functions

Complex expressions can be checked in a single line, using the logical
`_and()`, `_or()` and `_not()` functions.

```cpp
template <class Lhs_T, class Rhs_T>
auto _and (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
auto _or (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Expr_T>
auto _not (const Expr_T& expr);
```

See the reference [Logical functions](group__micro-test-plus-logical-functions.html) page.

### Checking exceptions

It is also possible to check various
exceptions related conditions.

```cpp
// Check for any exception.
template <class Callable_T>
auto throws (const Callable_T& expr);

// Check for a specific exception.
template <class Exception_T, class Callable_T>
auto throws (const Callable_T& expr);

// Check for no exception at all.
template <class Callable_T>
auto nothrow (const Callable_T& expr);
```

See the reference [Checking exceptions](group__micro-test-plus-exceptions.html) page.

### Operators

For convenience, it is
also possible to overload the `==`, `!=`, `<`, `>`, `<=`, `>=` operators:

```cpp
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

template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator and (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator or (const Lhs_T& lhs, const Rhs_T& rhs);

template <class T, type_traits::requires_t<....>>
bool operator not (const T& t);
```

See the reference [Operators](group__micro-test-plus-operators.html) page.

### String operators

Equality operators are provided for `string_view`
objects:

```cpp
bool operator== (std::string_view lhs, std::string_view rhs);
bool operator!= (std::string_view lhs, std::string_view rhs);
```

See the reference [String operators](group__micro-test-plus-string-operators.html) page.

### Container operators

Equality operators are provided for iterable containers:

```cpp
template <class T, type_traits::requires_t<type_traits::is_container_v<T>>>
bool operator== (T&& lhs, T&& rhs);

template <class T, type_traits::requires_t<type_traits::is_container_v<T>>>
bool operator!= (T&& lhs, T&& rhs);
```

See the reference [Container operators](group__micro-test-plus-container-operators.html) page.

### Literals and wrappers

For converting constants to recognised typed operands, the following
literal operators are available in the separate namespace `literals`:

```cpp
namespace literals {
  auto operator""_i (); // int
  auto operator""_s (); // short
  auto operator""_c (); // char
  auto operator""_sc () // signed char
  auto operator""_l (); // long
  auto operator""_ll (); // long long
  auto operator""_u (); // unsigned
  auto operator""_uc (); // unsigned char
  auto operator""_us (); // unsigned short
  auto operator""_ul (); // unsigned long
  auto operator""_ull (); // unsigned long long
  auto operator""_i8 (); // int8_t
  auto operator""_i16 (); // int16_t
  auto operator""_i32 (); // int32_t
  auto operator""_i64 (); // int64_t
  auto operator""_u8 (); // uint8_t
  auto operator""_u16 (); // uint16_t
  auto operator""_u32 (); // uint32_t
  auto operator""_u64 (); // uint64_t
  auto operator""_f (); // float
  auto operator""_d (); // double
  auto operator""_ld (); // long double
  auto operator""_b (); // bool
}
```

Similarly, for dynamic values, there are wrappers that convert them to
recognised types:

```cpp
  using _b = type_traits::value<bool>;
  using _c = type_traits::value<char>;
  using _sc = type_traits::value<signed char>;
  using _s = type_traits::value<short>;
  using _i = type_traits::value<int>;
  using _l = type_traits::value<long>;
  using _ll = type_traits::value<long long>;
  using _u = type_traits::value<unsigned>;
  using _uc = type_traits::value<unsigned char>;
  using _us = type_traits::value<unsigned short>;
  using _ul = type_traits::value<unsigned long>;
  using _ull = type_traits::value<unsigned long long>;
  using _i8 = type_traits::value<std::int8_t>;
  using _i16 = type_traits::value<std::int16_t>;
  using _i32 = type_traits::value<std::int32_t>;
  using _i64 = type_traits::value<std::int64_t>;
  using _u8 = type_traits::value<std::uint8_t>;
  using _u16 = type_traits::value<std::uint16_t>;
  using _u32 = type_traits::value<std::uint32_t>;
  using _u64 = type_traits::value<std::uint64_t>;
  using _f = type_traits::value<float>;
  using _d = type_traits::value<double>;
  using _ld = type_traits::value<long double>;

  // Template for wrapping any other type.
  template <class T>
  struct _t : type_traits::value<T>
  {
    constexpr explicit _t (const T& t) : type_traits::value<T>{ t }
    {
    }
  };
```

See the reference [Literals and wrappers](group__micro-test-plus-literals.html) page.

### Utility functions

```cpp
namespace utility {
  bool is_match (std::string_view input, std::string_view pattern);
}

namespace utility {
  template <class T, class Delim_T>
  auto split (T input, Delim_T delim) -> std::vector<T>;
}
```

See the reference [Utility functions](group__micro-test-plus-utility-functions.html) page.

### Test suites

Test suites are named sequences of test cases.

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

See the reference [Test suites](group__micro-test-plus-test-suites.html) page.

## C API

There are no C equivalents for the C++ definitions.

## Command line options

To control the verbosity, use one of the following command line options:

- `--verbose` - show all expectations, regardless of the result
- `--quiet` - show only the test suite totals
- `--silent` - suppress all output and only return the exit code

See the reference [Command line options](group__micro-test-plus-cli.html) page.

## Known problems

- none
