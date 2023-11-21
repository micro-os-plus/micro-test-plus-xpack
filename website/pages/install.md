# Installation Guide

[![GitHub package.json version](https://img.shields.io/github/package-json/v/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/package.json)
[![GitHub tag (latest by date)](https://img.shields.io/github/v/tag/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/tags/)
[![npm (scoped)](https://img.shields.io/npm/v/@micro-os-plus/micro-test-plus.svg?color=blue)](https://www.npmjs.com/package/@micro-os-plus/micro-test-plus/)

@tableofcontents

As a source code library, this project can be integrated into another project
in the traditional way,
by either copying the relevant files into the target project, or by linking
the entire project as a Git submodule.

However, things can be further automated and the most convenient way is
to **add it as a dependency** to the project via **xpm**.

## Install with xpm/npm

Along with the source files, this project also includes a
`package.json` file with the metadata that allows it to be identified as an
**xpm/npm** package so that it can be directly installed from GitHub or
from the [npmjs.com](https://www.npmjs.com) registry as
[`@micro-os-plus/micro-test-plus`](https://www.npmjs.com/package/@micro-os-plus/micro-test-plus).

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application
that complements [npm](https://docs.npmjs.com)
with several extra features specific to
**C/C++ projects**.

It is recommended to install/update to the latest version with:

```sh
npm install --global xpm@latest
```

For details please follow the instructions in the
[xPack install](https://xpack.github.io/install/) page.

@warning
Be sure **xpm** is not installed with administrative rights.

### xpm

This project can be installed as a package from the
`npmjs.com` registry with:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @micro-os-plus/micro-test-plus@latest

ls -l xpacks/@micro-os-plus/micro-test-plus
```

### npm

The package can also be installed with [npm](https://docs.npmjs.com)
or related, but
the features specific to C/C++ projects will not be available;
therefore, at least for consistency reasons, it is recommended
to use **xpm**.

## Add as a Git submodule

Besides manually copying the relevant files to the target
project, which will later require extra maintenance efforts to keep the
project up to date, a more convenient
solution is to link the entire project as a **Git submodule**,
for example below an `xpacks` folder:

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/micro-os-plus/micro-test-plus-xpack.git \
  xpacks/@micro-os-plus/micro-test-plus
```

## Project repository

The project uses Git and is hosted on GitHub as
<https://github.com/micro-os-plus/micro-test-plus-xpack.git>.

## Branches

Apart from the unused `master` branch, there are two active branches:

- `xpack`, with the latest stable version (default)
- `xpack-develop`, with the current development version

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into the `xpack` branch.

## Build & integration info

The project is written in C++, and the tests are expected to be
written in C++ too, but the tested code can also be written in plain C.

The source code was compiled natively with **GCC** and **LLVM/clang** and cross
compiled on embedded **Arm** and **RISC-V** targets,
and is expected to be warnings free.

To run **on embedded platforms**, the test framework requires a minimum
of support from the system, like writing to the
output stream. Any such environments are acceptable, but for standalone
tests the most common solution is to use **Arm semihosting**.

To ease the integration of this library into user projects, there
are already made **CMake** and **meson** configuration files (see below).

For other build systems, consider the following details:

## Include folders

The following folders should be passed to the compiler during the build:

- `include`

The header files to be included in user projects are:

```cpp
#include <micro-os-plus/micro-test-plus.h>
```

## Source files

The source files to be added to user projects are:

- `src/micro-test-plus.cpp`
- `src/test-reporter.cpp`
- `src/test-runner.cpp`
- `src/test-suite.cpp`

## Preprocessor definitions

There are several preprocessor definitions used to configure the build:

- `MICRO_OS_PLUS_INCLUDE_CONFIG_H` - to include `<micro-os-plus/config.h>`
- `MICRO_OS_PLUS_TRACE` - to include the trace calls
- `MICRO_TEST_PLUS_TRACE` - to enable some tracing messages

## Compiler options

The following options must be passed to the compiler and linker:

- `-std=c++20` or higher for C++ sources

## C++ Namespaces

The code is grouped in the following namespaces:

- `micro_os_plus::micro_test_plus`
- `micro_os_plus::micro_test_plus::operators`
- `micro_os_plus::micro_test_plus::literals`
- `micro_os_plus::micro_test_plus::utility`

`micro_os_plus` is the top µOS++ namespace, and `micro_test_plus` is the
µTest++ namespace.

The `operators` namespace defines the custom operators, and the `literals`
namespace defines the literals (like `1_i`);

## C++ Classes

The following classes are defined:

- `micro_os_plus::micro_test_plus::test_suite`

## Dependencies

The library has the following dependencies:

- none

## CMake

To integrate the **micro-test-plus** library into a CMake application,
add the folder where this project is located to the build:

```cmake
add_subdirectory("xpacks/@micro-os-plus/micro-test-plus")
```

The result is **an interface library** that can be added as an application
dependency with:

```cmake
target_link_libraries(your-target PRIVATE

  micro-os-plus::micro-test-plus
)
```

## Meson Build

To integrate the **micro-test-plus** library into a
[meson](https://mesonbuild.com) application,
add the folder where this project is located to the build:

```meson
subdir('xpacks/@micro-os-plus/micro-test-plus')
```

The result is **a dependency object** that can be added
to an application with:

```meson
exe = executable(
  your-target,
  link_with: [
    # Nothing, not static.
  ],
  dependencies: [
    micro_os_plus_micro_test_lists_dependency,
  ]
)
```

## Status

@note
The **micro-test-plus** library is fully functional, and
it is used to test several projects in the µOS++ framework.
@n
@n
The project is CI tested on 32 and 64-bit bare-metal platforms (Arm Cortex-M0,
Cortex-M3, Cortex-M4F, Cortex-M7F, Cortex-A15, Cortex-A72, RISC-V RV32IMAC,
RV64IMAFDC), and natively, with GCC and LLVM/clang.
