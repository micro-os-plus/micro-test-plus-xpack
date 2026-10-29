# API compatibility with v5.0.1

Note: the private function `runner::run_suites()` (earlier `run_suites_()`)
was renamed `run_child_suites()`, to free the name for a public function;
this document uses the new name throughout.

Date: 2026-10-20, on branch `xpack-development`, commit `70660a6c`,
compared with the tag `v5.0.1`.

Purpose: to list the changes that break the applications written for
v5.0.1, so that it can be decided, item by item, which ones get an
alias with a `[[deprecated]]` attribute, and which ones are only
documented in the release notes.

Method:

- the public headers, the inline definitions, and the sources of both
  versions were compared with the comments stripped;
- the 18 test programs of v5.0.1 (`tests/sources/` at the tag) were
  compiled against the current headers; they compile without errors
  against the v5.0.1 headers, and produce 161 errors and 46
  deprecation warnings against the current ones;
- the suspected behaviour changes were confirmed with probe programs
  built and run against both versions (Apple clang 17, native);
- the v5.0.1 user documentation (`website/docs/`, without the
  generated API pages) was searched for the removed names.

Classification:

- **Part I, public API:** what an application uses without naming
  `detail` and without deriving from the library classes: the
  functions and types of the top namespace, the `literals`,
  `operators`, `utility`, and `reflection` namespaces, the public
  members of `runner`, `suite`, `static_suite`, and `subtest`, the
  members of the objects they return, and the run-time behaviour.
- **Part II, internal:** the `detail` namespace, the implementation
  helpers that were outside `detail` in v5.0.1 but not meant for
  applications (`type_traits`, `math`, the reporter classes), the
  class hierarchy (relevant only for derived classes), and the
  individual headers and sources (the applications include only
  `micro-os-plus/micro-test-plus.h`).

Of the v5.0.1 test programs, the application-style ones (`empty`,
`minimal`, `sample`, `suite`) break only on items 10 and 11; all the
other errors come from the `unit` programs, which also test the
framework internals.

## Summary

| #  | Change                                                 | Breaks the v5.0.1 tests       | Alias now |
| -- | ------------------------------------------------------ | ----------------------------- | --------- |
|    | **I.A. Public, already aliased**                       |                               |           |
| 1  | `runner (const char*)`                                 | warning, all                  | yes       |
| 2  | `static_runner` became an alias of `runner`            | warning, all                  | yes       |
| 3  | `runner::exit_code()` → `run()`                        | warning, all                  | yes       |
| 4  | `runner::suite()` → `add_suite()`                      | warning, `unit`               | yes       |
| 5  | `runner::suites_count()`                               | warning, `unit`               | yes       |
| 6  | `assume()` → `require()`                               | warning, `unit`               | yes       |
| 7  | `reflection::short_name()`                             | warning, `unit`               | yes       |
| 8  | `successful_checks()` → `passed_checks()`              | warning, `unit`               | yes       |
|    | **I.B. Public, breaks the build**                      |                               |           |
| 9  | `subtest` → `test_case`                                | `unit`                        | yes       |
| 10 | suite bodies receive `suite&`, not `static_suite&`     | `sample`, `suite`             | yes       |
| 11 | `_and()`, `_or()`, `_not()`                            | `sample`, `unit`              | yes       |
| 12 | `_i`, `_f`, ..., `_t<T>` wrapper types removed         | `unit`                        | yes       |
| 13 | counters members renamed                               | `unit`                        | yes       |
| 14 | `totals()` returns only a `const` reference            | `unit`                        | yes       |
| 15 | `runner::reporter()` removed                           | `unit`                        | yes       |
| 16 | `runner::timings()` and `suite::timings()` removed     | no                            | yes       |
| 17 | other members of the test objects no longer public     | no                            | no        |
| 18 | constructors of `suite` and `subtest` no longer public | no                            | no        |
| 19 | `mut()` removed                                        | no                            | no        |
|    | **I.C. Public, behaviour changes**                     |                               |           |
| 20 | `string_view` operators removed (containers unchanged) | `sample` (tests now removed)  | n/a       |
| 21 | `eq()` on `char` pointers compares contents            | no                            | n/a       |
| 22 | floating-point tolerance                               | no                            | n/a       |
| 23 | integer literals (checks, prefixes, negation)          | no                            | n/a       |
| 24 | order of the suites                                    | no                            | n/a       |
| 25 | errors in the command-line options                     | no                            | n/a       |
| 26 | `--filter` is consumed by the runner                   | no                            | n/a       |
| 27 | TAP diagnostics keys                                   | no                            | n/a       |
|    | **II. Internal**                                       |                               |           |
| 28 | `detail::runner_totals` → `counters`                   | warning, `unit`               | yes       |
| 29 | timestamp classes replaced by `detail::stopwatch`      | `unit` (`timings.cpp`)        | yes       |
| 30 | `type_traits` namespace and its concepts               | `unit` (`static-asserts.cpp`) | yes       |
| 31 | value wrapper templates moved to `detail`              | `unit` (`static-asserts.cpp`) | yes       |
| 32 | expression templates renamed                           | no                            | no        |
| 33 | `expression_formatter` members removed                 | no                            | no        |
| 34 | reporter classes moved to `detail`                     | no                            | no        |
| 35 | `math` → `detail::math`                                | no                            | no        |
| 36 | runner and test class hierarchy                        | no                            | no        |
| 37 | header and source files renamed or removed             | no                            | no        |

## Part I. Public API

### I.A. Changes already covered by deprecated aliases

All the deprecated features are tested in
`tests/sources/unit/src/deprecated.cpp`, in the "Deprecated suite";
the test cases named below are in that suite. The suite also tests
`runner::verbosity()`, deprecated in favour of `verbosity_level()`; it
is not listed here because it did not exist in v5.0.1.

#### 1. `runner (const char* top_suite_name)`

- **v5.0.1:** the name of the top suite could be passed to the
  constructor (used by all the v5.0.1 samples:
  `static mt::static_runner tr{ "Sample" };`).
- **Current:** deprecated; the name is passed to `initialise()`.
- **Tested:** yes, "runner (const char*)": the name given to the
  constructor is used when `initialise()` gets none, and is replaced
  when it gets one. The test uses the `runner_options` overload of
  `initialise()`; the `argc`/`argv` overload used in v5.0.1 forwards
  to it.

#### 2. `static_runner`

- **v5.0.1:** a separate class, derived from `runner` (`final`), the
  only runner type to which a `static_suite` could be attached.
- **Current:** `using static_runner [[deprecated ("use runner")]] =
  runner;`.
- **Remaining break:** since the two are now the same type, overloads
  that distinguish them (`f (runner&)` and `f (static_runner&)`)
  become redefinitions. Unlikely in practice.
- **Tested:** yes, "static_runner": a `static_assert` that it is the
  same type as `runner`, and a session run with a `static_runner`. The
  remaining break is a compile error and cannot be tested.

#### 3. `runner::exit_code()`

- **v5.0.1:** ran the suites and returned the exit code.
- **Current:** deprecated, forwards to `run()`.
- **Tested:** yes, "runner::exit_code()": `0` for a passed session,
  `1` for a failed one, and the later calls of `exit_code()` and
  `run()` return the same code without running the suites again.

#### 4. `runner::suite (name, callable, args...)`

- **Current:** deprecated, forwards to `add_suite()`. The name
  parameter changed from `const char*` to `std::string_view`, which is
  source compatible.
- **Tested:** partly, "runner::suite()": a suite added with a callable
  is run. The extra `args...` passed to the callable are not tested
  through `suite()`; they are tested through `add_suite()`, to which
  `suite()` forwards them.

#### 5. `runner::suites_count()`

- **Current:** deprecated, in favour of `added_suites_count()` and
  `total_suites_count()`; it returns the same value as in v5.0.1
  (the added suites plus the top suite).
- **Tested:** yes, "runner::suite()": `2` with one added suite, and
  equal to `added_suites_count() + 1`.

#### 6. `assume()`

- **Current:** deprecated, forwards to `require()`.
- **Tested:** yes, "assume()" (a passed check) and "Failed assume()"
  (the test case stops after the failed check). The failed case is
  compiled only with exceptions; without them, a failed requirement
  aborts the test execution.

#### 7. `reflection::short_name()`

- **Current:** deprecated, in favour of `utility::extract_file_name()`.
- **Tested:** yes, "reflection::short_name()": Unix and Windows paths,
  and a name without separators.

#### 8. `successful_checks()` and `increment_successful_checks()`

- **Current:** deprecated members of `counters`, in favour of
  `passed_checks()` and `increment_passed_checks()`. The `unit` tests
  call `successful_checks()` through a `detail::runner_totals&`
  reference, which compiles since items 14 and 28 were aliased.
- **Tested:** yes, "counters": both names, on a local `counters`
  object.

### I.B. Changes that break the build, without aliases

#### 9. `subtest` renamed `test_case`

- **v5.0.1:** `class subtest`, the type passed to the test case bodies;
  documented in the glossary.
- **Current:** `class test_case`; the name `subtest` does not exist.
- **Breaks:** `unit` (4 files declare functions with `subtest&`
  parameters, e.g.
  `test_case_expect_floats_passed_combinatorial (subtest& t)`).
- **Affects:** every function or lambda that names the type instead
  of using `auto&`.
- **Alias:** trivial. Done, in `test.h`:
  `using subtest [[deprecated ("use test_case")]] = test_case;`.
- **Tested:** yes, "subtest": a `static_assert` that it is the same
  type as `test_case`, and a function with a `subtest&` parameter
  passed directly to `suite::test()`, as the v5.0.1 `unit` tests did,
  and to `test_case::test()`, from a lambda with a `subtest&`
  parameter.

#### 10. Suite bodies receive `suite&`, not `static_suite&`

- **v5.0.1:** the body of a `static_suite` was stored as
  `std::function<void (static_suite&)>`; the v5.0.1 user guide shows
  suite functions declared as `suite_function (mt::static_suite& ts)`
  and `check_double_list_links (mt::static_suite& ts)`.
- **Current:** the body is stored as `std::function<void (suite&)>`;
  a function taking `static_suite&` cannot be called with a `suite&`,
  and the construction fails with
  `no matching constructor for initialization of
  'std::function<void (suite &)>'`.
- **Breaks:** `sample` (`test_suite_with_args`), `suite`
  (`suite_function`).
- **Affects:** every application that follows the v5.0.1 guide for
  suites defined in separate files.
- **Alias:** not possible with a name; done in the `static_suite`
  constructor instead. A second constructor, marked `[[deprecated]]`,
  is selected by the concept `detail::static_suite_body` when the
  callable cannot be invoked with `suite&` but can with
  `static_suite&` (followed by the stored arguments); it wraps the
  callable in a lambda that casts the `suite&` back to
  `static_suite&`, which is always valid, since the object is a
  `static_suite`. The deprecation is reported at the declaration of
  the suite in the application; the bodies that accept `suite&`,
  including the generic lambdas, are not affected. The v5.0.1 `suite`
  program now compiles with deprecation warnings only.
- **Tested:** yes, "static_suite& suite functions": a function without
  arguments, and one with arguments, including an `int&` parameter,
  which refers to the copy, as in v5.0.1.

#### 11. `_and()`, `_or()`, and `_not()`

- **v5.0.1:** the logical function comparators, documented in the user
  guide.
- **Current:** renamed `both()`, `either()`, and `negate()`; the old
  names do not exist.
- **Breaks:** `sample` (`mt::_and (mt::eq (...), mt::eq (...))`),
  `unit` (`comparisons.cpp`, 12 uses).
- **Alias:** trivial, three forwarding function templates with
  `[[deprecated ("use both()")]]`, etc. Done: they forward to `both()`,
  `either()`, and `negate()`, so they return the same expressions, and
  the reports are the same.
- **Tested:** yes, "_and(), _or(), _not()": the returned types are the
  same as those of the current functions, and the checks with true and
  false results.

#### 12. The underscore value wrapper types

- **v5.0.1:** in the top namespace, `_b`, `_c`, `_sc`, `_s`, `_i`, `_l`,
  `_ll`, `_u`, `_uc`, `_us`, `_ul`, `_ull`, `_i8`, `_i16`, `_i32`, `_i64`,
  `_u8`, `_u16`, `_u32`, `_u64`, `_f`, `_d`, `_ld`, and the template
  `_t<T>` (the Boost UT style names), besides the `to_*` names. Not in
  the user guide.
- **Current:** the `to_*` names and `to_t<T>`; the underscore names
  were removed, then restored as deprecated aliases.
- **Breaks:** `unit` (`comparisons.cpp`: `_f` 16 times, `_d`, `_ld`;
  `operators.cpp`, `main.cpp`, `static-asserts.cpp`).
- **Alias:** trivial, 23 type aliases and one alias template, for
  example `using _i [[deprecated ("use to_i")]] = to_i;`. They do not
  conflict with the literal operators (`operator""_i` lives in
  `literals`), as in v5.0.1. Done, in `literals.h`: `_b` to `_ld` are
  the same types as in v5.0.1; `_t<T>` is now `to_t<T>`, not a
  separate class, also derived from `detail::value<T>`. Clang reports
  the deprecation at every use; GCC (15.2) only when the alias names
  the type of a declaration, not in an expression such as `_i (expr)`
  or `_t<int>{ x }`.
- **Tested:** yes, "_i, _f, ..., _t<T>": the 23 aliases and `_t<int>`
  are the same types as the `to_*` wrappers, and the checks in the
  functional cast notation, with true and false results.

#### 13. Counters members renamed

- **v5.0.1:** the object returned by `totals()` had
  `increment_successful_checks()`, `increment_failed_checks()`,
  `increment_executed_subtests()`, `successful_checks()`,
  `failed_checks()`, `executed_checks()`, `executed_subtests()`, and
  `was_successful()`.
- **Current:** renamed: `increment_executed_subtests()` →
  `increment_executed_test_cases()`, `executed_subtests()` →
  `executed_test_cases()`, `was_successful()` → `passed()`. The
  successful/passed pair has aliases (item 8). The rename of the class
  itself is item 28.
- **Breaks:** `unit` (`executed_subtests()` in 11 files,
  `was_successful()` in `main.cpp`); previously hidden behind the
  errors of items 14 and 28, now aliased.
- **Alias:** trivial, three deprecated forwarding members. Done, in
  `counters.h`: `increment_executed_subtests()`, `executed_subtests()`,
  and `was_successful()`, marked `[[deprecated]]`, forward to the
  current members.
- **Tested:** yes, "counters", together with item 8: each old name
  reads or increments the same counter as the new one, and
  `was_successful()` returns false after a failed check.

#### 14. `totals()` returns only a `const` reference

- **v5.0.1:** `totals()` had a non-`const` overload, returning
  `runner_totals&`, on the suites and the subtests (`test_node`); the
  runner had no `totals()`.
- **Current:** `const counters& totals (void) const noexcept` on the
  runner and the nodes; on the nodes, also the compatibility overload
  described below.
- **Breaks:** `unit` (12 files bind
  `detail::runner_totals& current_suite_totals = ts.totals ();`, a
  non-`const` reference, which fails even with an alias for the class
  name).
- **Affects:** code that binds a non-`const` reference, or that
  modifies the counters.
- **Alias:** a `[[deprecated]]` non-`const` overload is not usable:
  it is selected for every call on a non-`const` node, so all the
  current reads (`ts.totals ().passed_checks ()`,
  `const counters& c = ts.totals ();`) would warn. Done instead with a
  plain non-`const` overload, `counters& totals (void) noexcept`, in
  `runnable_base`, without the attribute; the v5.0.1 binding is
  reported by the deprecated alias of item 28. The internal counters
  and the framework code are unchanged. A modification of the totals
  through `ts.totals ()` is not reported; a derived type with
  deprecated modifying members was considered, but it would have
  required the framework to update the counters through a separate
  accessor.
- **Tested:** yes, "non-const totals(), detail::runner_totals", together
  with item 28: the types returned by both overloads, the v5.0.1
  binding, which refers to the live totals, the modifications through
  it, and a failed check added to the totals of the top suite, which
  fails the session, as in v5.0.1.

#### 15. `runner::reporter()` removed

- **v5.0.1:** `class reporter& reporter (void) const noexcept`, public;
  it gave access to the verbosity, and to the reporter stream
  (`tr.reporter () << "..." << mt::endl`).
- **Current:** removed; the reporter is internal (item 34). The
  verbosity is available as `runner::verbosity_level()`; writing into
  the report is no longer possible.
- **Breaks:** `unit` (`main.cpp`, twice
  `tr.reporter ().verbosity () > verbosity::quiet`).
- **Alias:** done: a deprecated `runner::reporter()`, `const` as in
  v5.0.1, returning `detail::reporter&`, plus a deprecated
  `detail::reporter::verbosity()`, which restore the common use; this
  re-exposes an internal class, but only through deprecated members.
  The stream use is not restored: the v5.0.1 `mt::endl` and
  `mt::indent()` remain in `detail` (item 34), without aliases, and
  no v5.0.1 test or page used them. As in v5.0.1,
  the call is valid only after `initialise()`, which creates the
  reporter.
- **Tested:** yes, "runner::reporter()": the type returned, the v5.0.1
  expression on two local runners, with the human and the TAP
  reporters and the verbosity of their session options, and on the
  runner of the unit tests, with the verbosity of the command line.

#### 16. `runner::timings()` and `suite::timings()` removed

- **v5.0.1:** public members (`const` and non-`const`) returning the
  `detail::timestamps` of the session and of the suite.
- **Current:** removed; the times are kept in an internal
  `detail::stopwatch` (item 29), not reachable from the runner or the
  suites.
- **Breaks:** no test.
- **Alias:** done, despite the changed type (item 29): deprecated
  `runner::timings()` and `suite::timings()`, `const` and non-`const`
  as in v5.0.1, returning the internal `detail::stopwatch`; a
  deprecated `detail::timestamps` alias of `stopwatch` (in
  `stopwatch.h`), so that the v5.0.1 binding
  `detail::timestamps& t = tr.timings ();` compiles; and the read-only
  members of the v5.0.1 class, deprecated, on `stopwatch`:
  `has_begin()`, `has_end()`, `has_timestamps()` (forwarding to
  `has_elapsed()`), and `compute_elapsed_time (ms, us)` (splitting
  `elapsed()`). Two differences remain: without a clock,
  `has_begin()` and `has_end()` return `false` (v5.0.1 returned `true`
  after the calls), and `compute_elapsed_time()` returns zero without
  both readings (v5.0.1 asserted). The writers and the
  `detail::timestamp` class were initially not kept, since the readings
  belong to the runner; they were added later, with item 29.
- **Tested:** yes, "timings(), detail::timestamps": the types returned
  by the four overloads, the v5.0.1 bindings, which refer to the
  stopwatches of the session, of the top suite, and of an added suite,
  started by `initialise()` (or before the suite body) and stopped by
  `run()`; and "timestamps::compute_elapsed_time()": the deprecated
  members with known readings, including the split of an interval
  with a borrow from the seconds.

#### 17. Other members of the test objects no longer public

- **v5.0.1:** public on the suites and the subtests: `own_index()`
  (getter and setter), `current_subtest_index()`,
  `increment_subtest_index()`, `children_subtests_count()`,
  `reporter()`, `runner()`, `abort()`, and `run()`; on `top_suite`,
  the setter `name (const char*)`; on `runner`, `name()`.
- **Current:** `name()`, `totals()`, `test()`, `expect()`, `require()`,
  and `nesting_depth()` remain public; `test_runner()` (the old
  `runner()`) and `test_reporter()` are protected; `abort()` and
  `run()` are private; the others are removed. `runner::abort()`
  remains public.
- **Breaks:** no test.
- **Alias:** `t.abort()` is the only member likely to be used in tests;
  it could be re-exposed as a deprecated forwarder to the runner. The
  others are not worth an alias.

#### 18. Constructors of `suite` and `subtest` no longer public

- **v5.0.1:** public templates; a `suite` could be constructed
  directly (although it was then never run, since it was not
  registered); `top_suite` too.
- **Current:** `suite` is protected, `top_suite` and `test_case` are
  private. `static_suite` remains public, and now accepts any
  `runner&`, not only a `static_runner&`.
- **Breaks:** no test.
- **Alias:** none recommended.

#### 19. `mut()` removed

- **v5.0.1:** `mut (const T&) -> T&`, a `const_cast` helper inherited
  from Boost UT; undocumented.
- **Current:** removed, without replacement.
- **Breaks:** no test.
- **Alias:** trivial to re-add as deprecated; arguably better left out.

### I.C. Behaviour changes (the code compiles, the results differ)

All the items of this section are documented in the v5.1 compatibility
notices (`website/docs/getting-started/_project/_compatibility-notices.mdx`);
the paragraphs are named below by their first words.

#### 20. `string_view` and container operators removed

- **v5.0.1:** `operators` defined `operator==` and `operator!=` for
  two `std::string_view`, and for two container-like operands,
  returning expression templates; the v5.0.1 sample has the test cases
  "Check strings with operators" and "Check containers with
  operators", both removed from the current sample.
- **Current:** removed. With `using namespace mt::operators`,
  `std::string_view{ s } == "abc"sv` still compiles, but now calls the
  standard operator and checks a plain `bool`: a failed check no longer
  shows the operands (probe: v5.0.1 prints `abc == abd`, the current
  version prints nothing).
- **Containers:** no observable change. For two containers of the same
  type, the standard `operator==` was already selected in v5.0.1, as
  the more specialised template, so the failed check printed no
  operands in either version (probe: `v == w` with two
  `std::vector<int>` prints only the location in both); for two
  containers of different types (`std::vector<int>` and
  `std::list<int>`), the check did not compile in v5.0.1 either, since
  the expression template itself compared them with `==`.
- **Reason for the removal:** stated in the description of the
  `operators` namespace (`operators.h`): the standard operators are
  selected for `std::string` objects and for containers of the same
  type anyway, and the `std::string_view` overloads also replaced the
  standard ones in the application code that follows the using
  directive, so that some string comparisons returned a comparator and
  others a `bool`.
- **Decision:** not restored; document that `mt::eq()` and `mt::ne()`
  must be used for strings and containers.
- **Documented:** "The `==` and `!=` operators for `std::string_view`
  were removed ...". The containers need no notice.

#### 21. Comparisons of `char` pointers compare the contents

- **v5.0.1:** `eq (Lhs_T*, Rhs_T*)` and the other pointer overloads
  compared `const char*` (and `char` arrays) by address.
- **Current:** `char` pointers and arrays are wrapped as C strings and
  compared by contents (probe: two distinct buffers holding `"abc"`
  fail `mt::eq (p1, p2)` in v5.0.1 and pass now). Other pointer types
  are still compared by address.
- **Decision:** document; the new behaviour is the expected one for
  strings, but a test that checked pointer identity for `char*`
  silently changes meaning (it should now use `mt::eq
  (static_cast<const void*> (p1), static_cast<const void*> (p2))`).
- **Documented:** "The comparators now compare the C strings ...",
  including the cast to `const void*`.

#### 22. Floating-point tolerance

- **v5.0.1:** the tolerance of `to_f()`, `to_d()`, and `to_ld()` was
  derived from the number of decimals (`0.1` for `1.5` and for `2.0`,
  `0.01` for `1.25`), but values smaller than about `1e-7` also got
  `0.1`, so `to_d (1e-9) == 0.0` passed. The relational comparisons
  ignored the tolerance.
- **Current:**
  - those small values get a tolerance derived from their magnitude
    (`to_d (1e-9).epsilon` is `1e-9`), so that check now fails, and a
    wrapped zero compares exactly;
  - the values whose decimal rounding produced 17 or 18 decimals
    (e.g. `to_d{ 0.011 }`) now get one unit of their last written
    decimal, as documented;
  - `<`, `<=`, `>`, `>=`, `lt()`, `le()`, `gt()`, and `ge()` apply the
    tolerance, as `==` and `!=` already did (probe: `1.45 < 1.5_d` and
    `mt::lt (0.0105, mt::to_d{ 0.011 })` pass in v5.0.1 and fail now).

  The tolerances of the literals (`1.5_d`, `1.25_d`) are unchanged.
  Explicit tolerances are available with `approx()`.
- **Decision:** document (this is the fix of the review item about
  tolerances).
- **Documented:** "The relational comparisons ...", "The tolerance of
  the floating-point wrappers ...", and "The leading zeros of a small
  wrapped value ...".

#### 23. Integer literals

- **v5.0.1:** out-of-range literals (`300_uc`, `70000_s`) and literals
  with a fraction (`1.5_i`) were accepted silently; the prefixes were
  not parsed, so `010_i` was 10; the negation of a literal returned an
  `int`, so `-1_u8` was the `int` value -1.
- **Current:**
  - the out-of-range literals and those with a fraction are rejected
    with `static_assert` messages;
  - the `0x`, `0b`, and leading-`0` (octal) prefixes are parsed, so
    `010_i` is 8 (probe: `010_i == 8_i` fails in v5.0.1, as `10 == 8`,
    and passes now);
  - the negation keeps the type of the literal, and wraps around for
    the unsigned types, so `-1_u8` is the `std::uint8_t` value 255
    (probe: `mt::eq (-1_u8, -1)` passes in v5.0.1 and fails now, as
    `255uc == -1`).
- **Decision:** document.
- **Documented:** "The integer literals now follow the C++ syntax ..."
  and "The negation of an integer literal ...".

#### 24. Order of the suites

- **v5.0.1:** the suites added with `runner::suite()` ran first, sorted
  by name, then the static suites, sorted by name.
- **Current:** all the suites are kept in a single list, sorted by name,
  so the added and the static suites are interleaved; for equal names,
  the static suites constructed before `main()` run first. The suite
  numbers in the TAP output change accordingly.
- **Decision:** document.
- **Documented:** "All the suites, those added with
  `runner::add_suite()` and the `static_suite` objects, ..." (added for
  this item); the current order is also described in the User's Guide.

#### 25. Errors in the command-line options

- **v5.0.1:** an unknown `--reporter` value, `--reporter` or
  `--output-file` without a value, or an output file that could not be
  opened, terminated the program inside `initialise()` with `exit (1)`.
- **Current:** the error is printed on `stderr`, the option is ignored,
  `initialise()` returns, the tests are run, and `run()` returns `2`
  (probe: an output file that cannot be opened ends v5.0.1 before any
  test, and the current version runs the tests and returns `2`).
- **Decision:** document.
- **Documented:** "The option errors (an unknown `--reporter` name,
  ...".

#### 26. `--filter` is consumed by the runner

- **v5.0.1:** unknown options were ignored, so an application could
  use `--filter` for its own purpose.
- **Current:** `--filter` selects the suites and the test cases; as
  `--filter <pattern>`, it also consumes the next argument. The
  other options recognised by the runner (`--reporter`,
  `--output-file`, `--verbose`, `--quiet`, and `--silent`) were
  already recognised in v5.0.1.
- **Decision:** document.
- **Documented:** "The runner now also recognises the `--filter`
  option ..." (added for this item); the option is described in the
  User's Guide.

#### 27. TAP diagnostics keys

- **v5.0.1:** the YAML block of a failed check used the keys
  `filename` and `line`, and an unquoted `condition`.
- **Current:** `fileName` and `lineNumber` (TAP 14), and a quoted
  `condition`.
- **Affects:** tools that parse the TAP diagnostics of µTest++.
- **Decision:** document.
- **Documented:** "In the `at:` field of the YAML diagnostics blocks
  ..." and "In the YAML diagnostics blocks of the TAP output, the
  `condition:` values ...".

## Part II. Internal changes

### 28. `detail::runner_totals` renamed `counters`

- **v5.0.1:** `detail::runner_totals`, the type returned by `totals()`
  (non-copyable).
- **Current:** `micro_test_plus::counters`, in the top namespace,
  copyable. The member renames are item 13.
- **Breaks:** `unit` (12 files name the type).
- **Alias:** done, in `counters.h`: `namespace detail { using
  runner_totals [[deprecated ("use counters")]] = counters; }`;
  together with item 14, the v5.0.1 binding
  `detail::runner_totals& t = ts.totals ();` compiles, with a
  deprecation warning.
- **Tested:** yes, with item 14.

### 29. Timestamp classes replaced by `detail::stopwatch`

- **v5.0.1:** `detail::timestamp` (`has_clock()`, `value()`) and
  `detail::timestamps` (`timestamp_begin()`, `timestamp_end()`,
  `has_begin()`, `has_end()`, `has_timestamps()`,
  `compute_elapsed_time (ms, us)`), header `timings.h`.
- **Current:** `detail::stopwatch` (`start()`, `stop()`,
  `has_elapsed()`, `elapsed()` returning `std::chrono::microseconds`),
  header `stopwatch.h`.
- **Breaks:** `unit` (`timings.cpp` derives test classes from both and
  accesses their protected members).
- **Alias:** the read-only part used through `timings()` is restored
  with item 16. Done for the rest, in `stopwatch.h`: the writers, on
  `stopwatch`, deprecated (`timestamp_begin()` and `timestamp_end()`,
  with and without a `timespec`; as in v5.0.1, they record only an
  absent reading, and `timestamp_begin()` does not clear the stop
  reading, unlike `start()`); and the `detail::timestamp` class,
  restored as in v5.0.1 and marked `[[deprecated]]`, with the
  default constructor reading the clock of `stopwatch` (in
  `src/stopwatch.cpp`) and the `protected` member `value_`. Two
  differences remain: a reading is absent when it is zero, not when
  its `std::optional` is empty, so a zero `timespec` given to the
  writers is not recorded, and a reading without a clock is retried;
  and the protected `std::optional<timestamp>` members of
  `timestamps` are not restored, so the v5.0.1 `test_timestamps`
  class of `timings.cpp` still fails (`test_timestamp` compiles).
- **Tested:** yes, "timestamps::timestamp_begin(), timestamp_end()":
  the first readings are kept, the clock does not replace present
  readings, the start writer keeps the stop reading, zero times are
  not readings, and the clock readings; and "detail::timestamp": the
  copy semantics, the conversion from `timespec`, the types returned by
  `value()`, the default constructor with and without a clock, the
  time given to the constructor, the modification through `value()`,
  and `has_clock()` through a class derived as in v5.0.1.

### 30. `type_traits` namespace and its concepts

- **v5.0.1:** `type_traits::is_op`, `any_op`, `checkable`, `printable`,
  `has_epsilon`, `has_value`, `container_like`, `has_npos`,
  `is_floating_point`, and the helpers `list`, `identity`,
  `function_traits`. Outside `detail`, and visible in the declarations
  shown in the v5.0.1 user guide, but not meant to be used by the
  applications.
- **Current:** `extension::is_op`, `any_op`, `checkable`, `printable`,
  `has_epsilon`; `detail::container_like`, `has_npos`, `has_value`;
  `is_floating_point`, `list`, `identity`, and `function_traits` are
  removed (`std::floating_point` replaces the first). Semantic
  changes: `is_op` now detects the `op_type` member instead of the
  inheritance from `type_traits::op`; `has_epsilon` and `has_value`
  now also require `is_op` (and `has_value` a static `value`);
  `printable` now accepts everything the formatter can print.
- **Breaks:** `unit` (`static-asserts.cpp`, 16 uses).
- **Alias:** done, at the end of `extension.h`, as
  `namespace [[deprecated ("use the extension namespace")]]
  type_traits`, since the concepts themselves cannot carry the
  attribute: using-declarations of the eight current concepts, which
  therefore keep their current semantics (the v5.0.1 static assertion
  `has_value<foo>`, for a `foo` with a non-static `value` member, now
  fails); `is_floating_point`, a concept equivalent to
  `std::floating_point`; and `list`, `identity`, and `function_traits`,
  restored as in v5.0.1. The using-declarations of concepts are
  accepted by GCC 11 and 15, and by clang 16 to 21. Clang reports the
  namespace at every qualified use; GCC only for the names declared in
  the namespace itself (the restored templates, and the alias templates
  of item 31 when they name the type of a declaration), not for the
  concepts nor for the names of the using-declarations. GCC also
  reports the partial specialisations of `function_traits`, inside the
  namespace, so `-Wdeprecated-declarations` is ignored in the rest of
  the header.
- **Tested:** yes, "type_traits", together with item 31: static
  assertions on each concept, including the changed `has_value`, and on
  the restored helpers, with a function type, a function pointer, and a
  lambda.

### 31. Value wrapper templates moved to `detail`

- **v5.0.1:** `type_traits::op` (the base of all expressions),
  `type_traits::value<T>`, `value_base_<T>` (with the public data
  member `value_`, and `get()` returning `T`),
  `integral_constant<N>`, `floating_point_constant<...>`, and
  `genuine_integral_value<T>`.
- **Current:** `detail::op`, `detail::value<T>`, `detail::value_base<T>`
  (`value_` private, `get()` returning `const T&`),
  `detail::integral_constant<N>`, `detail::floating_point_constant<...>`;
  `genuine_integral_value` is removed.
- **Breaks:** `unit` (`static-asserts.cpp`).
- **Affects:** applications that wrote their own expression types
  deriving from `type_traits::op`; the supported route is now
  `extension::compare_op` and `extension::predicate_op`.
- **Alias:** done, in the deprecated namespace of item 30:
  using-declarations of `detail::op`, `value`, `integral_constant`, and
  `floating_point_constant`; the alias templates `value_base_<T>` (of
  `detail::value_base<T>`) and `genuine_integral_value<T>` (of
  `detail::value<T>`, which has the same members for the integral
  types). Direct accesses to `value_` cannot be restored, and
  `get()` returns a `const` reference.
- **Tested:** yes, "type_traits", together with item 30: each name is
  the same type as the current one, and the checks of the wrapped
  values, with true and false results.

### 32. Expression templates renamed

- **v5.0.1 (all in `detail`):** `eq_`, `ne_`, `gt_`, `ge_`, `lt_`, `le_`,
  `and_`, `or_`, `not_`, `unary_op_`, `binary_op_`, `callable_op_`,
  `throws_<Callable_T, Exception_T>`, `nothrow_<Callable_T>`, the
  function `get()`, the struct `assertion`, the classes
  `deferred_reporter_base` and `deferred_reporter` (the type returned
  by `expect()`).
- **Current:** `compare_op<Lhs_T, Rhs_T, Tag_T>` with the tags
  `equal_to`, `not_equal_to`, `greater`, `greater_equal`, `less`,
  `less_equal`; `and_op`, `or_op`, `not_op`, `unary_op`, `binary_op`,
  `callable_op`, `throws_op<Exception_T>` (the callable is no longer a
  template parameter), `nothrow_op`, `unwrap()`, and `check_result`;
  `assertion` is removed. `expect()` returns `auto`, so only the code
  that names these types is affected.
- **Alias:** alias templates such as `eq_<L, R> = compare_op<L, R,
  equal_to>` are possible, but construction with deduction would still
  differ (the tag argument). Not recommended.

### 33. `expression_formatter` members removed

- **v5.0.1:** `detail::expression_formatter` with `str()`, `c_str()`,
  `clear()`, `empty()`, `append (count, ch)`, `reserve()`, constructed
  from a non-`const` `colours&`.
- **Current:** also published as `mt::expression_formatter`; only
  `str()` remains; the constructor takes `const colours&`.
- **Affects:** application `operator<<` overloads for their own types
  that used the removed members.
- **Alias:** `c_str()`, `empty()`, `append()`, and `reserve()` could be
  re-added as deprecated; `clear()` would interfere with the nested
  check buffers and should not return.

### 34. Reporter classes moved to `detail`

- **v5.0.1:** in the top namespace: `reporter`, `reporter_human`,
  `reporter_tap`, `endl()`, `indent()` (returning `detail::indent_t`).
  Custom reporters were never possible (the runner creates the
  reporter itself), so these were reachable only through
  `runner::reporter()` (item 15).
- **Current:** `detail::reporter`, `detail::reporter_human`,
  `detail::reporter_tap`, `detail::endl()`, `detail::indent()`
  (returning `detail::indentation`). Renamed members: `endline()` →
  `end_line()`, `write_buffer_to_stdout()` →
  `write_buffer_to_console()`, `flush()` → `flush_streams()`,
  `get_comment_prefix()` → `comment_prefix()`, `begin_subtest()` and
  `end_subtest()` → `begin_test_case()` and `end_test_case()`;
  removed: `verbosity()`, `expression()`; the constructor takes a
  `runner_options` instead of the vector of arguments.
- **Alias:** not recommended beyond what item 15 decides.

### 35. `math` moved to `detail::math`

- **v5.0.1:** `micro_test_plus::math` (`abs()`, `min_value()`, `pow()`,
  `num()`, `den()`, `den_size()`, with a run-time overload of
  `den_size (value)`).
- **Current:** `detail::math`; the run-time `den_size (value)` became
  `count_decimals (value)`.
- **Alias:** possible as `namespace [[deprecated]] math { using
  namespace detail::math; }`; low value.

### 36. Runner and test class hierarchy

- **v5.0.1:** `runner` derived from `detail::test_node`, had a virtual
  destructor and a virtual `total_suites_count()`, and protected
  members (`run_child_suites()`, `register_suite_()`, the data members);
  `static_runner` derived from it and added the static member
  `register_static_suite()`; `detail::runnable<Self_T>` was the common
  template base of `suite` and `subtest`; the free functions
  `detail::to_runner()` and `detail::register_static_suite()` existed.
- **Current:** `runner` is a plain, non-polymorphic class with private
  members; `detail::test_node`, `detail::runnable<Self_T>`, and the
  functions above are removed.
- **Affects:** only classes derived from the runner or the test
  classes.
- **Alias:** none recommended.

### 37. Header and source files renamed or removed

- **v5.0.1 headers:** `deferred-reporter.h`, `runner-totals.h`,
  `timings.h`, `type-traits.h`, with their `inlines/*-inlines.h`, and
  `inlines/exceptions-inline.h` (singular).
- **Current headers:** `check-result.h`, `counters.h`, `extension.h`,
  `runner-options.h`, `stopwatch.h`, `values.h`, and
  `inlines/exceptions-inlines.h`. The include guards of most headers
  were renamed as well.
- **v5.0.1 sources:** `src/deferred-reporter.cpp`, `src/runner-totals.cpp`,
  `src/timings.cpp` (listed in the v5.0.1 install documentation).
- **Current sources:** `src/check-result.cpp`, `src/counters.cpp`,
  `src/stopwatch.cpp`.
- **Affects:** applications that include individual headers instead of
  `micro-os-plus/micro-test-plus.h`, and builds that list the sources
  by hand. The CMake targets and the meson dependency keep their
  names.
- **Alias:** forwarding headers with a `#warning` are possible for the
  removed headers; nothing can be done for hand-written source lists.
