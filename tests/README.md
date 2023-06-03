# Tests

There are two tests available, a unit test and a sample test.

The CI workflow runs several tests, both as native processes and as
semihosted applications emulated by QEMU; for details see
[ci.yml](../.github/workflows/ci.yml).

Exactly the same source files are built on both platforms, without
changes.

## Unit test

The `unit-test.cpp` file checks if the framework file counts
the tests results (successes/failures) correctly.

## Sample

The `sample-test.cpp` file is a simple example exercising the
few primitives available in the testing framework.

If exceptions are enabled, this example also shows how to write a
test that checks if exceptions are caught properly.
