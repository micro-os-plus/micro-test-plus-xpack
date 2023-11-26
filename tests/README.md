# Tests

There are several tests available, a unit test and two sample tests.

The CI workflow runs several tests, both as native processes and as
semihosted applications emulated by QEMU; for details see
[ci.yml](../.github/workflows/ci.yml).

Exactly the same source files are built on all platforms, without
changes.

## Unit test

The `unit-test.cpp` file checks if the framework file counts
the tests results (successes/failures) correctly.

## Sample

The `sample-test.cpp` file is a simple example exercising the
few primitives available in the testing framework.

If exceptions are enabled, this example also shows how to write a
test that checks if exceptions are caught properly.

## Minimal

The `minimal-test.cpp` is a really small test, intended for user
initial experimentation with the framework.

It is build only on native cmake configuration.

## Known issues

- older meson fails on Darwin new linker, since it no longer supports
`--version` -> 1.3.0 (<https://github.com/mesonbuild/meson/issues/12419>)
- meson 1.3.0 still fails with gcc 11
  (<https://github.com/mesonbuild/meson/issues/12552>)

- `test-native-cmake-sys` and `test-native-meson-sys` are strict only on
Darwin, which is known to have the toolchain; otherwise it is allowed to fail
- `test-native-cmake-gcc11` and `test-native-meson-gcc11` fail on Darwin

```
g++: warning: could not understand version 14.00.00
ld: warning: -multiply_defined is obsolete
ld: warning: REFERENCED_DYNAMICALLY flag on symbol '_NXArgc' is deprecated
ld: warning: REFERENCED_DYNAMICALLY flag on symbol '_NXArgv' is deprecated
ld: warning: REFERENCED_DYNAMICALLY flag on symbol '___progname' is deprecated
ld: warning: REFERENCED_DYNAMICALLY flag on symbol '_environ' is deprecated
0  0x10816ff43  __assert_rtn + 64
1  0x108071f43  ld::AtomPlacement::findAtom(unsigned char, unsigned long long, ld::AtomPlacement::AtomLoc const*&, long long&) const + 1411
2  0x10808e431  ld::InputFiles::SliceParser::parseObjectFile(mach_o::Header const*) const + 19745
3  0x10809eb71  ld::InputFiles::parseAllFiles(void (ld::AtomFile const*) block_pointer)::$_7::operator()(unsigned long, ld::FileInfo const&) const + 657
4  0x7ff80ae375cd  _dispatch_client_callout2 + 8
5  0x7ff80ae47e3e  _dispatch_apply_invoke + 214
6  0x7ff80ae3759a  _dispatch_client_callout + 8
7  0x7ff80ae4699d  _dispatch_root_queue_drain + 879
8  0x7ff80ae46f22  _dispatch_worker_thread2 + 152
9  0x7ff80afdbc06  _pthread_wqthread + 262
ld: Assertion failed: (resultIndex < sectData.atoms.size()), function findAtom, file Relocations.cpp, line 1336.
collect2: error: ld returned 1 exit status
[20/24] Building CXX object platform-bin/CMakeFiles/unit-test.dir/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/src/test-suite.cpp.o
g++: warning: could not understand version 14.00.00
[21/24] Building CXX object platform-bin/CMakeFiles/sample-test.dir/__/src/sample-test.cpp.o
g++: warning: could not understand version 14.00.00
[22/24] Building CXX object platform-bin/CMakeFiles/unit-test.dir/__/src/unit-test.cpp.o
g++: warning: could not understand version 14.00.00
ninja: build stopped: subcommand failed.
error: running 'cmake --build build/native-cmake-gcc11-release' failed
error: running 'xpm run build --config native-cmake-gcc11-release' failed
```

- on Linux the linker complains about libpthread:

```
/home/ilg/.local/xPacks/@xpack-dev-tools/gcc/13.2.0-1.1/.content/bin/../lib/gcc/aarch64-unknown-linux-gnu/13.2.0/../../../../aarch64-unknown-linux-gnu/bin/ld: warning: libpthread.so.0, needed by /home/ilg/.local/xPacks/@xpack-dev-tools/gcc/13.2.0-1.1/.content/bin/../lib/gcc/aarch64-unknown-linux-gnu/13.2.0/../../../../lib64/libstdc++.so, not found (try using -rpath or -rpath-link)
```
