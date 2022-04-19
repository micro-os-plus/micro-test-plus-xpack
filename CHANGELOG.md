# Change & release log

Releases in reverse chronological order.

Please check
[GitHub](https://github.com/micro-os-plus/micro-test-plus-xpack/issues/)
and close existing issues and pull requests.

## 2022-04-19

* 3.0.2
* cd697a4 README reworks

## 2022-04-10

* d53ee24 package.json: bump build-helper 2.7.1

## 2022-04-07

* b43ce71 test-all.yml: remove Raspberry Pi OS test

## 2022-04-05

* 3.0.1
* d8f24e6 #5 add parametrised test suites

## 2022-04-03

* c3053d5 3.0.0

## 2022-04-01

* a944962 test-reporter.cpp: use check marks for suites
* de8065f add support for unused main test suite

## 2022-03-31

* ab6a3d5 try parametrized test suites; not ready
* 3eb96f7 sample-test: explicit namespaces

## 2022-03-28

* 0b8ab47 launch.json: --verbose unit-test
* aa405f5 test-reporter minor rework
* c5a6e54 implement assume() with the same deferred_reporter
* 4906cd5 test-reporter: add output() method
* db00b7f add reported_ and run()

## 2022-03-27

* 11bcfd1 bump build-helper 2.6.3
* 5afa470 CI: bump clang13
* 3020ffe optimise deferred reporters

## 2022-03-26

* d8b9071 revert to build-helper 2.6.1
* 602d5d8 implement expect() << "message"
* 14ce153 package.json: meson platform toolchain files
* 367b706 unit-test.cpp: fix __xx warning
* 3ec0a21 add clang13
* 356f2f9 package.json: bump cmake & meson

## 2022-03-23

* 255d4e5 README updates
* c837032 package.json: bump buld-helper 2.6.2
* 49a3129 package.json: bump gcc 11.2.0-3.3
* 568d799 revert to interface library

## 2022-03-21

* c3729b8 process_deferred_begin
* 601c428 unit-tests fix messages
* 7340d7b printf string_view content
* 0a5bb6b test-reporter cosmetics (.)
* 4871095 colors as const char*
* f9c25c8 meson: update for static library

## 2022-03-20

* 79d72b2 README add Getting Started
* 8bb653f constexpr evaluate_and_report_
* c993275 reorder initialize()
* ebfb155 remove redundant pass()/fail()
* 03cc86d test-runner: argv[] cosmetics
* 3904bcb #pragma cleanups
* 7fe3bfd group several small *-inlines.h together
* 11fe6e8 add utility namespace
* 065824a unit-test: add static checks
* 48faa97 unit-test: add reflection::type_name() test
* 85aec05 unit-test: silence warning
* 7342f2c math.h: silence warning
* 4aeaa0d reflection: fix type_name()
* 7d6bd77 reflection.h: fix clang non apple
* 02eda65 reflection.h: warning/error in type_name()
* c5ab1d2 launch: add (gdb) native-cmake-clang12-debug

## 2022-03-17

* 01e6a21 unit-test.cpp: rename tests
* 327441d implement different verbosity
* 904e3ff remove trace in eq_

## 2022-03-16

* 116571d bump build-helper 2.6.1

## 2022-03-15

* d15b203 change to static library
* ad94a46 remove dependency from diag-trace, use printf()
* 9d387c8 reporter: disable unused generic <<
* eebde5f reporter: rework constant suffixes
* b43d2b0 reporter.fail print value only if is_op_v
* dca5409 literals.h: add comments
* d9021c4 sample-test update for new README examples
* df5d8b5 update README and docs
* cd3f97d split detail-inlines.h

## 2022-03-14

* f64083c revert from operators to functions
* 3ec0454 unit-test: add logical & operators
* d0d689a unit-test silence -Wdouble-promotion
* a635d1a docs & cosmetics
* f346a7a rename Callable_T
* ed9d0f2 .vscode/launch: add unit-test
* dc6ccca remove unused pointer _and(), _or(), _not()
* 67e2c43 fix meson -Wno-used-but-marked-unused
* 120c675 -Wno-used-but-marked-unused for clang on windows
* a6fee32 CI install --quiet
* 7e67230 add -Wno-missing-include-dirs to build
* b059c71 silence -Wmissing-include-dirs for GCC too
* 263b87e silence clang -Wmissing-include-dirs
* 1e8fc05 cosmetics
* 285a86a rework #includes
* 52fc562 split test-reporter & detail
* 17b0e3e split test-runner.h
* 62c7539 split inlines
* 2256fbf rename type-traits.h
* adc648e enable -Werror for native
* 037c767 split test-suite.cpp
* a80ea1a test-suite invokes reporter
* ce4c241 split test-suite.h
* a4a262a cleanup print_expr declaration
* 4b1984c split test-reporter.cpp
* e74786e split test-runner.cpp
* e4c7ed4 literals add docu
* 2f5efdd move casts to literals.h
* b1a0b55 move struct value to type_traits
* a9ec726 split literals.h
* bd64244 more type_triats moves
* 5a98f64 remove unused struct type_
* 8176edc move op & _constants to type_traits.h
* 658bf72 silence warnings
* 8407e38 fix type_traits guard

## 2022-03-13

* 1d5e4a9 docs
* 00e26c1 separate test_reporter implementation & inlines
* 7700eee rename Other_T
* 1c760ba split type_traits.h
* 2d7d4e8 split math.h
* c6b33c0 include source_location in reflection.h
* 149bbf5 rename Xxx_T
* ccd6482 split reflection.h
* 33390a4 remove deprecated expect_equal()
* cf4831a remove unused operators
* 33e84e9 add operators
* 63714b9 unit-test cleanup
* 51bb43c use evaluate_and_report_()
* 35a1ad1 unit-test: expect() without message
* 4cbe008 add explicit _not _and _or
* b36dfa6 move to detail::assertion
* 6dac36c README: mention string comparisons
* 8d04508 unit-test: cleanups & comments
* 5b2153d unit-test: check default messages
* eef5709 sample test pass() message
* cfd924d sample-test: include string_view
* 3968eef add @brief and comments
* 48ea51e reorder and cleanup operator <<
* 52e2fbc simplify trace eq_ messages
* 1d63119 provide a default for the message
* db9ae66 add type suffixes when displaying scalar values
* 406d48e add genuine_integral_value{}
* 8fb68ae cosmetics
* 18163a0 unit_test major rewrite
* e9e3fa2 sample-test: use string_view
* ddcd2a2 cmake cleanup
* 86996ed cmake xpack_create_hex
* ff53277 cmake add SIZE
* a34a283 cmake add report SIZE

## 2022-03-12

* f657ba0 add literals & more types
* f1676c1 more flush
* 357aefb rework operator<<
* 9250199 add more trace::printf
* fd7cf12 silence warnings
* ee30f22 more flush()
* d8e8900 add assume() with abort
* 646d374 add runner.name()

## 2022-03-03

* 3f84859 consistent copyright notices
* 278aff5 Add reference to boost license in copyright notice
* 28b5887 README: update for v3.x
* 2419718 add boost license
* 4e02d9d meson cosmetics
* 6ed18d2 package.json: native only on darwin
* d416cb3 quiet installs
* f93be58 package.json: remove gcc8
* 8d468c5 rework cmake & meson
* 687072c silence warnings
* b2bf818 sample-test: fix check args
* 2cf994c sample-test: silence warnings
* 6aed55a unit-test: temporarily disabled

## 2022-03-02

* 7117f36 launch.json: update
* b9bdb0f sample-test: rework with new comparators
* 8f0bc1f rework based on boost ut
* 58c0ba8 native/config.h comment _STDERR

## 2022-03-01

* db86cd1 add test_suite

## 2022-02-28

* 1120ed7 migrate to non-class functions

## 2022-02-27

* b3c12ab C++20
* c694f49 MICRO_OS_PLUS_TRACE
* f43a1ab platform-native/config.h: TRACE buffer 500

## 2022-02-19

* v2.3.0
* 94b340c use nested namespaces
* f921bf0 sample-test: cleanup globals
* 66df97e add support for test-all
* f6c19d2 cmake globals add -fdiagnostics-color=always
* 28efe4b add parameterised tests and combinatorials
* 560b678 add run_test_case variadic template
* 436a1ae deprecate run_test_case(func, name)
* 0a6a46b add start_test_case()

## 2022-02-18

* 5d0e9be package.json bump helper
* 69d6dec rework expect_equal with templates

## 2022-02-16

* 9d97cb1 meson: remove utf-8 chars

## 2022-02-10

* 776845a .c* include <micro-os-plus/config.h>
* 8f3e441 meson.build cosmetics

## 2022-02-09

* 4fcb75d MICRO_OS_PLUS_INCLUDE_CONFIG_H
* 81186d0 rename MICRO_OS_PLUS_DEBUG

## 2022-02-08

* 9c23c7d package.json: disable stm32f4 on Apple Silicon
* 3969095 package.json: bump clang
* 623e72d rename MICRO_OS_PLUS_TRACE

## 2022-02-06

* f1a8f80 MICRO_OS_PLUS_HAS_CONFIG_H
* 4d46a63 disable -flto on armv7l

## 2022-02-05

* v2.2.1
* 473d3f3 package.json: use npmjs.com deps
* b88b767 CI.yml try to enable qemu-cmake on Windows
* 518645c package.json: enable cortexm builds on windows
* e342558 meson create symbolic link at build time
* 00ff79d cmake revert to .. instead of top symlink
* 68053a5 package.json: bump build-helper
* 65918f6 cmake notice that -flto fails on embedded
* 868c55d meson native with_linux_clang_lto
* a223600 meson: notice that -flto fails on embedded
* bb3628a meson always include warnings
* 1d1e612 meson revert to warning_level = 0
* cc41eac meson native without -flto
* d562a5e cmake native add --gc-sections
* 4bee003 cmake globals -flto for release
* c2c7972 package.json: bump devices-stm32f4-extras
* 6139edb meson: disable -flto for clang on linux

## 2022-02-04

* v2.2.0
* 18219ef package.json: bump deps
* d30ea7d updates for device-*cortexm
* 33e2244 cmake: add xpack_display_target_lists
* 4f7324b package.json: add stm32f4discovery meson

## 2022-02-03

* d64bd80 cmake update qemu-mps2
* 18955fa cmake update stm32f4discovery
* e4541e9 cmake update for interface

## 2022-02-02

* e703fa9 .vscode/launch.json: add qemu launchers
* 3055967 cmake: rework test commands

## 2022-02-01

* 90e894f add meson qemu
* 6f55a37 package.json: rename dependencies to device-*
* fde47e6 package.json: move toolchain files to folder
* 041c252 cmake: rename platform-qemu-mps2-an386
* 1230c9b cmake: update for device-qemu-cortexm
* 10304ab rename platform-qemu-mps2-an386

## 2022-01-28

* 829ffbd separate top CMake config for tests
* 920a928 add top symbolic link
* 9a5987e sample-test.cpp: static variables
* 82c83d8 sample-test.cpp: test args

## 2022-01-26

* 15d6fe9 package.json: skip qemu tests on windows
* v2.1.0
* rework CMake

## 2022-01-03

* v2.0.5

## 2022-01-02

* CI.yml: remove native-cmake
* package.json: add meson gcc/clang
* PLATFORM_STM32F4DISCOVERY_WITHOUT_HAL

## 2022-01-01

* meson.build: add /utf-8 to msvc options
* [#4] add support for MSVC
* package.json: use posix paths on windows

## 2021-12-29

* stm32f4discovery test functional
* add native meson tests
* package.json: add clang12 test
* add explicit CMakeLists.txt

## 2021-12-26

* package.json: move devDeps to configs
* CI.yml: test-native
* package.json: migrate native to xpack actions

## 2021-03-13

* v2.0.4
* remove -pedantic-errors, use -Werror only on bare-metal

## 2021-03-10

* v2.0.3
* bump devDeps

## 2021-03-09

* v2.0.2
* fix/silence warnings
* remove warning flags from cmake

## 2021-03-02

* v2.0.1
* fix warnings, add -Wall..., -Werrror

## 2021-03-01

* v2.0.0

## 2021-02-28

* rename micro_os_plus

## 2021-02-12

* add support for CMake find_package()

## 2021-02-07

* prepare v2.0.0-pre
* [#1] - rename micro_test_plus::session
* [#2] - sample-test: conditional exceptions
* [#3] - add stm32f4discovery tests

## 2021-02-05

* prepare v1.1.1-pre

## 2021-02-04

* release preliminary v1.1.0
