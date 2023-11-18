
# How to Use

@tableofcontents

The xPack Build Framework already includes ready to use
support for several testing frameworks:

- [Google Test](https://github.com/xpack-3rd-party/googletest-xpack)
- [Catch2](https://github.com/xpack-3rd-party/catch2-xpack)
- [Boost UT](https://github.com/xpack-3rd-party/boost-ut-xpack)

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

## C++ API

Aiming simplicity, µTest++ provides only a very limited number of primitives
used to check expectations and assumptions.

### Expectations

Expectations are checks whose results are counted and do not
break the test (as opposed to assumptions, which abort the test).

```cpp
template <class Expr_T, type_traits::requires_t<....>>
bool expect(const Expr_T& expr);
```

The template matches only expressions that evaluate to
a boolean or use custom comparators/operators derived from an
internal `detail::op` type.

For generic checks performed outside the testing framework, the results can
be reported with `expect(true)` or `expect(false)` (see the example testing
multiple exceptions below).

### Assumptions

Assumptions are checks that abort the test if the results are false.

```cpp
template <class Expr_T, type_traits::requires_t<....>>
bool assume(const Expr_T& expr);
```

Similarly, the template matches only expressions that evaluate to
a boolean and use custom comparators/operators derived from a
internal `detail::op` type.

### Function comparators

Expectations and assumptions can test any expression evaluating to a
boolean value, but in order to nicely report the difference between expected
and actual values in failed
conditions, the following generic comparators are available:

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

Similar templates are defined for pointer comparators.

Examples:

```cpp
expect (eq (compute_answer (), 42)) << "answer is 42";
expect (ne (compute_answer (), 43)) << "answer is not 43";
expect (lt (compute_answer (), 43)) << "answer is < 43";
expect (le (compute_answer (), 43)) << "answer is <= 42";
expect (gt (compute_answer (), 41)) << "answer is > 43";
expect (ge (compute_answer (), 42)) << "answer is >= 42";

expect (compute_condition ()) << "condition is true";
```

When such comparator functions are used, failed checks also display the
actual values compared during the test; for example:

```console
  Check failed comparisons
    ✗ actual != 42 FAILED (unit-test.cpp:286, 42 != 42)
    ✗ FAILED (unit-test.cpp:307, 42 != 42)
    ✗ 42 != 42_i FAILED (unit-test.cpp:310, 42 != 42)
    ✗ (actual == 42) and (actual != 42.0) FAILED (unit-test.cpp:781, (42 == 42 and 42.000000 != 42.000000))
```

### Logical function operators

Complex expressions can be checked in a single line, using the logical
`_and()`, `_or()` and `_not()` functions. The names are prefixed with
underscore since
`and`, `or` and `not` are reserved words in C/C++.

```cpp
template <class Lhs_T, class Rhs_T>
auto _and (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T>
auto _or (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Expr_T>
auto _not (const Expr_T& expr);
```

Examples:

```cpp
expect(_and (eq (compute_answer (), 42), eq (compute_float (), 42.0)));
```

A slightly more readable syntax is available with custom operators,
as shown below.

### Comparing strings

In C/C++, plain strings are actually pointers to characters, and simply
comparing them does not compare the content but the memory addresses.

For string comparisons to compare the content, use `string_view` objects:

```cpp
#include <string_view>
using namespace std::literals; // For the "sv" literal.
// ...

expect (eq (std::string_view{ compute_ultimate_answer () }, "forty-two"sv))
        << "ultimate_answer is 'forty-two'";
```

### Comparing containers

Containers can be compared for equality. The comparison
is done by iterating and comparing each member.

```cpp
expect (eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
        << "vector{ 1, 2 } eq vector{ 1, 2 }";

expect (ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 })
        << "vector{ 1, 2, 3 } ne vector{ 1, 2, 4 }";
```

### Operators

As in most other C++ test frameworks, it is
also possible to overload the `==`, `!=`, `<`, `>`, `<=`, `>=` operators.

To avoid possible interferences with other operators
defined by the application, these operators match only for operands of
specific types and are located in a separate namespace
(`micro_test_plus::operators`); when applied to regular values, the
standard operands are used; the comparisons are performed properly,
but in case of failures the actual values are not shown.

The following operators match only operands derived from the local
`detail::op` type, which can be enforced for constant values by using the
provided literals (like `1_i`) or, for dynamic values, by using the
provided casts (like `_i {expression}`, which are actually the
constructors of the internal classes):

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
```

Examples:

```cpp
test_case ("Operators", [] {
  using namespace micro_test_plus::operators;
  using namespace micro_test_plus::literals;

  expect (compute_answer () == 42_i) << "answer is 42 (with literal)";
  expect (_i {compute_answer ()} == 42) << "answer is 42 (with cast)";
  expect (compute_answer () != 43_i) << "answer is not 43";
  expect (compute_answer () < 43_i) << "answer is < 43";
  expect (compute_answer () <= 43_i) << "answer is <= 42";
  expect (compute_answer () > 41_i) << "answer is > 43";
  expect (compute_answer () >= 42_i) << "answer is >= 42";
});
```

In addition, equality operators are also provided for `string_view`
objects and for iterable containers:

```cpp
bool operator== (std::string_view lhs, std::string_view rhs);
bool operator!= (std::string_view lhs, std::string_view rhs);

template <class T, type_traits::requires_t<type_traits::is_container_v<T>>>
bool operator== (T&& lhs, T&& rhs);

template <class T, type_traits::requires_t<type_traits::is_container_v<T>>>
bool operator!= (T&& lhs, T&& rhs);
```

Examples:

```cpp
#include <string_view>
using namespace std::literals; // For the "sv" literal.
// ...

test_case ("Operators", [] {
  using namespace micro_test_plus::operators;

  expect (std::string_view{ compute_ultimate_answer () } == "forty-two"sv)
          << "ultimate answer == 'forty-two'";

  expect (std::vector<int>{ 1, 2 } == std::vector<int>{ 1, 2 })
          << "vector{ 1, 2 } == vector{ 1, 2 }";

  expect (std::vector<int>{ 1, 2, 3 } != std::vector<int>{ 1, 2, 4 })
          << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
});
```

### Logical operators

Similarly, logical operators are defined:

```cpp
template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator and (const Lhs_T& lhs, const Rhs_T& rhs);

template <class Lhs_T, class Rhs_T, type_traits::requires_t<....>>
bool operator or (const Lhs_T& lhs, const Rhs_T& rhs);

template <class T, type_traits::requires_t<....>>
bool operator not (const T& t);
```

They can be used in exactly the same way as standard operators, but the
additional functionality is enabled only when matching the typed operands.

Examples:

```cpp
expect (compute_answer () == 42_i && compute_float () == 42.0_f);
```

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

Examples:

```cpp
expect (_i {answer} == 42_i);
expect (_f {expression} == 42_f);
```

### Function comparators vs. operators & literals

Which to use, functions like `eq()` or the
overloaded operators? A very good question!

Functions guarantee that the nice feature of showing the actual values
when expectations fail is always available. Also the syntax is more on the
traditional side, and for some it may look simpler and easier to read.

Operators are generally easier to recognise than function calls,
but require the hack with the type wrappers and literals to enforce the
types, otherwise the actual values will not be displayed when the
expectations fail.

Both syntaxes are functional, and, once the differences understood,
the issue is a matter of personal preferences.

@note
The µOS++ projects favour explicit comparator functions.

### Explicit namespace

If for any reasons, the definitions in the `micro_test_plus` namespace
interfere with application definitions, it is recommended to
use the comparator functions, which can be more easily invoked
with explicit namespaces, possibly aliased to shorter names.

Example:

```cpp
{
  namespace mt = micro_os_plus::micro_test_plus;

  mt::test_case ("Check answer", [] {
    mt::expect (mt::eq (compute_answer (), 42)) << "answer is 42";
  });
}
```

### Exceptions

A C++ testing framework must be able to check if an expression
(usually a function call), throws or not an exception.

The following function templates allow to check various exceptions related
conditions:

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

Examples:

```cpp
expect (throws ([] { exercise_throw (true); })) << "exception thrown";

expect (throws<std::runtime_error> ([] { throw std::runtime_error{ "" }; }))
        << "std::runtime_error thrown";

expect (nothrow ([] { exercise_throw (false); })) << "exception not thrown";
```

If a more elaborate logic is required, for example for expecting multiple
exceptions, use an explicit `try` with multiple `catch` statements and
report the results with `expect(true)` or `expect(false)`.

```cpp
try
  {
    compute_answer ();
  }
catch (const std::overflow_error& e)
  {
    expect (true) << "std::overflow_error thrown";
  }
catch (const std::runtime_error& e)
  {
    expect (true) << "std::runtime_error thrown";
  }
catch (...)
  {
    expect (false) << "known exception thrown";
  }
```

### Test cases

Test cases group several checks done in the same environment.

There can be any number of test cases, and each test case is performed
by invoking
a function, parametrised with a name, a callable (usually a lambda),
and optional arguments:

```cpp
template <typename Callable_T, typename... Args_T>
void test_case (const char* name, Callable_T&& func, Args_T&&... arguments);
```

Examples:

```cpp
using namespace micro_os_plus::micro_test_plus;

test_case ("Check various conditions", [] {
  expect (eq (compute_answer (), 42)) << "answer eq 42";
  expect (ne (compute_answer (), 43)) << "answer ne 43";
});

test_case ("Check various conditions with operators", [] {
  using namespace micro_os_plus::micro_test_plus::operators;
  using namespace micro_os_plus::micro_test_plus::literals;

  expect (compute_answer () == 42_i) << "answer == 42";
  expect (compute_answer () != 43_i) << "answer != 43";
});
```

### Test runner initialization

The test runner is initialised with the process arguments and a
name, which is used for the default test suite:

```cpp
void initialize (int argc, char* argv[], const char* name = "Main");
```

The arguments can be used for controlling the verbosity level.

### Return the test result

The final test result that must be returned to the system
(0 for pass, 1 for fail), can be obtained with:

```cpp
int exit_code (void);
```

This call also triggers the execution of all global test suites.

For examples, see before.

### Test suites

Test suites are named sequences of test cases.

The test cases defined in `main()` are considered to be part of
the default (or main) test suite, and are executed immediately
when invoked.

For complex applications there can be multiple test
suites, usually in separate source files.

In order to make self-registration possible, test suites are classes,
constructed with a name, a callable (usually a lambda
which chains the execution of the test cases) and optional
arguments:

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
It is recommended to instantiate the test suites as static objects.

The self-registration is done in the constructor.
Test suites defined in different compilation units can be executed in any
order (since the order in which the
static constructors are invoked is not specified);
thus there should be no dependencies between test suites.

The registered test suites are executed when the function
`exit_code()` is invoked.

Examples:

```cpp
// Test suite with generic parameters.
static void
test_suite_args (int ic, int iv, int& ir, int* ip1, int* ip2)
{
  using namespace micro_os_plus::micro_test_plus;

  test_case ("args", [&] {
    expect (eq (ic, 42)) << "ic is 42";
    expect (eq (iv, 43)) << "iv is 43";
    expect (eq (ir, 44)) << "ir is 44";
    expect (eq (*ip1, 45)) << "*ip1 is 45";
    expect (eq (*ip2, 46)) << "*ip2 is 46";
  });
}

static int in = 43;
static int in44 = 44;
static int& ir = in44;
static int in45 = 45;
static int in46 = 46;
static int* ip2 = &in46;

static micro_os_plus::micro_test_plus::test_suite ts_args
    = { "Args", test_suite_args, 42, in, ir, &in45, ip2 };
```

### Utility functions

For tests comparing strings, in addition to exact matches, it is also possible
to check matches with patterns like `*` (for any characters) and `?` (for a
single character):

```cpp
namespace utility {
  bool is_match (std::string_view input, std::string_view pattern);
}
```

Examples:

```cpp
expect (utility::is_match ("abc", "a?c")) << "abc matches a?c";
expect (utility::is_match ("abc", "a*c")) << "abc matches a*c";
```

Also for tests handling strings, the following function template allows to
split a string into a vector of substrings, using a delimiter:

```cpp
namespace utility {
  template <class T, class Delim_T>
  auto split (T input, Delim_T delim) -> std::vector<T>;
}
```

Example:

```cpp
expect (std::vector<std::string_view>{ "a", "b" }
            == utility::split<std::string_view> ("a.b", "."))
        << "a.b splits into [a,b]";
```

### Custom types

It is possible to extend the comparators with templates matching custom
types, but this is a non-trivial task and requires a good knowledge of
C++.

TODO: add a test to show how to do this.

## C API

There are no C equivalents for the C++ definitions.

## Known problems

None.

## Command line options

### Verbosity

By default, the test reporter shows detailed results only for the failed
test cases; successful test cases are shown as a single line with
the total counts of passed/failed checks.

To control the verbosity, use one of the following command line options:

- `--verbose` - show all expectations, regardless of the result
- `--quiet` - show only the test suite totals
- `--silent` - suppress all output and only return the exit code

## Memory footprint

The memory footprint of unit tests based on µTest++ is definitely smaller than
that of traditional C++ testing framework, mainly because the `iostream`
library is not used.

However, the use of templates for implementing the comparators and
operators should be carefully observed for platforms with really
limited amounts of memory, since each pair of different operands
contributes to the program size.

At the limit, µTest++ can be used
without custom comparators and operators
(only with regular boolean expressions), and still be able to provide
the basic functionality of testing various conditions, but without
the optional features of displaying the actual values compared.

@note
The memory footprint on `debug` (built with `-O0`),
is significantly larger than on `release`. If necessary, the optimization
for the `debug` build can be increased to `-Og`, to save some memory.