@page change-log Change log

@tableofcontents

## Breaking changes

According to the [semver](https://semver.org) rules:

> Major version X (X.y.z | X > 0) MUST be incremented if any
> backwards incompatible changes are introduced to the public API.

The breaking changes introduced by each major release,
in reverse chronological order, are:

### v3.x (2022-04-03)

Major rework, with full set of comparators, exceptions,
function templates for test cases and class templates for test suites.

### v2.3.x (2022-02-19)

Deprecate `run_test_case(func, name)` in favour of
`run_test_case(name, func)`, to prepare for variadic templates.

### v2.x (2021-03-01)

The C++ namespace was renamed from `os` to `micro_os_plus`.

### v1.x (2021-02-04)

The initial code (inspired in its simplicity by node-tap)
was extracted from the mono-repo µOS++ project.
