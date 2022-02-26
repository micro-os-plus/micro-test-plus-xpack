# Change & release log

Releases in reverse chronological order.

Please check
[GitHub](https://github.com/micro-os-plus/micro-test-plus-xpack/issues/)
and close existing issues and pull requests.

## 2022-02-19

- v2.3.0
- 94b340c use nested namespaces
- f921bf0 sample-test: cleanup globals
- 66df97e add support for test-all
- f6c19d2 cmake globals add -fdiagnostics-color=always
- 28efe4b add parameterised tests and combinatorials
- 560b678 add run_test_case variadic template
- 436a1ae deprecate run_test_case(func, name)
- 0a6a46b add start_test_case()

## 2022-02-18

- 5d0e9be package.json bump helper
- 69d6dec rework expect_equal with templates

## 2022-02-16

- 9d97cb1 meson: remove utf-8 chars

## 2022-02-10

- 776845a .c* include <micro-os-plus/config.h>
- 8f3e441 meson.build cosmetics

## 2022-02-09

- 4fcb75d MICRO_OS_PLUS_INCLUDE_CONFIG_H
- 81186d0 rename MICRO_OS_PLUS_DEBUG

## 2022-02-08

- 9c23c7d package.json: disable stm32f4 on Apple Silicon
- 3969095 package.json: bump clang
- 623e72d rename MICRO_OS_PLUS_TRACE

## 2022-02-06

- f1a8f80 MICRO_OS_PLUS_HAS_CONFIG_H
- 4d46a63 disable -flto on armv7l

## 2022-02-05

- v2.2.1
- 473d3f3 package.json: use npmjs.com deps
- b88b767 CI.yml try to enable qemu-cmake on Windows
- 518645c package.json: enable cortexm builds on windows
- e342558 meson create symbolic link at build time
- 00ff79d cmake revert to .. instead of top symlink
- 68053a5 package.json: bump build-helper
- 65918f6 cmake notice that -flto fails on embedded
- 868c55d meson native with_linux_clang_lto
- a223600 meson: notice that -flto fails on embedded
- bb3628a meson always include warnings
- 1d1e612 meson revert to warning_level = 0
- cc41eac meson native without -flto
- d562a5e cmake native add --gc-sections
 4bee003 cmake globals -flto for release
- c2c7972 package.json: bump devices-stm32f4-extras
- 6139edb meson: disable -flto for clang on linux

## 2022-02-04

- v2.2.0
- 18219ef package.json: bump deps
- d30ea7d updates for device-*cortexm
- 33e2244 cmake: add xpack_display_target_lists
- 4f7324b package.json: add stm32f4discovery meson

## 2022-02-03

- d64bd80 cmake update qemu-mps2
- 18955fa cmake update stm32f4discovery
- e4541e9 cmake update for interface

## 2022-02-02

- e703fa9 .vscode/launch.json: add qemu launchers
- 3055967 cmake: rework test commands

## 2022-02-01

- 90e894f add meson qemu
- 6f55a37 package.json: rename dependencies to device-*
- fde47e6 package.json: move toolchain files to folder
- 041c252 cmake: rename platform-qemu-mps2-an386
- 1230c9b cmake: update for device-qemu-cortexm
- 10304ab rename platform-qemu-mps2-an386

## 2022-01-28

- 829ffbd separate top CMake config for tests
- 920a928 add top symbolic link
- 9a5987e sample-test.cpp: static variables
- 82c83d8 sample-test.cpp: test args

## 2022-01-26

- 15d6fe9 package.json: skip qemu tests on windows
- v2.1.0
- rework CMake

## 2022-01-03

- v2.0.5

## 2022-01-02

- CI.yml: remove native-cmake
- package.json: add meson gcc/clang
- PLATFORM_STM32F4DISCOVERY_WITHOUT_HAL

## 2022-01-01

- meson.build: add /utf-8 to msvc options
- [#4] add support for MSVC
- package.json: use posix paths on windows

## 2021-12-29

- stm32f4discovery test functional
- add native meson tests
- package.json: add clang12 test
- add explicit CMakeLists.txt

## 2021-12-26

- package.json: move devDeps to configs
- CI.yml: test-native
- package.json: migrate native to xpack actions

## 2021-03-13

- v2.0.4
- remove -pedantic-errors, use -Werror only on bare-metal

## 2021-03-10

- v2.0.3
- bump devDeps

## 2021-03-09

- v2.0.2
- fix/silence warnings
- remove warning flags from cmake

## 2021-03-02

- v2.0.1
- fix warnings, add -Wall..., -Werrror

## 2021-03-01

- v2.0.0

## 2021-02-28

- rename micro_os_plus

## 2021-02-12

- add support for CMake find_package()

## 2021-02-07

- prepare v2.0.0-pre
- [#1] - rename micro_test_plus::session
- [#2] - sample-test: conditional exceptions
- [#3] - add stm32f4discovery tests

## 2021-02-05

- prepare v1.1.1-pre

## 2021-02-04

- release preliminary v1.1.0
