# Change & release log

Releases in reverse chronological order.

Please check
[GitHub](https://github.com/micro-os-plus/micro-test-plus-xpack/issues/)
and close existing issues and pull requests.

## 2026-11-09

* v6.0.0 prepared
* b5983b7a compatibility-notices update
* d7cc6138 build-boards.yml: disable windows
* 2b78274c separate build-board workflow
* ffaf1d26 tests/package.json: shortConfigurationName
* de794b1c Merge branch 'xpack-development' of https://github.com/micro-os-plus/micro-test-plus-xpack into xpack-development
* bb37ec79 website: add comparison
* b8529f33 tests/package*.json update
* d8331639 workflows: fix windows clean cache
* 70699392 package*.json bump deps
* df03d27c website: bump deps and update
* 73d99ac1 workflows updates
* cd708964 workflows updates
* 6eb2787f re-generate commons for latest gh hosts
* 7acbab33 test-ci.yml: try ubuntu 26 and macos 26
* bca94d8e add trigger-workflow-test-all.mjs using curl
* 214322de #287: Use gcc-ar for the LTO archives on Windows
* 1afb57ce #286: Silence the GCC 11 format truncations
* f25162cd skills updates
* 3a54cb51 add trigger-workflow-test-all.mjs using gh
* fe8dd77b #285: Rename the alias that shadows value_type
* 0c37b0eb #284: Guard the sized operator delete
* f0ae2c37 #284: Silence -Wpadded in the operands test
* 653a017f #283: Pass the wstring lengths explicitly
* 07b1d09c #284: Use llu for size_t with MinGW GCC
* d2d769a1 The Windows CI build with MinGW-w64 GCC failed, because the size_t conversion macro expanded to "zu", which the ms_printf format checker of GCC rejects, and because the listed test case and suite counts were narrowed from size_t to unsigned long, which is 32-bit there.
* ba9bf347 #283: Pass the u16string lengths explicitly
* e63e9858 #283: Avoid a GCC 14 LTO false positive
* 04d27645 tests/package.json bump deps
* 35a742e9 tests/package.json: raspberry-pi-dependencies
* 1935c42a tests/pacakge.json update
* 961098f2 re-generate tests commons
* 946c4889 #282: re-format
* 3b1a2468 website update
* 7f38f714 website update blog post
* 3aa2f527 website: add comparison
* 6507c054 tests/package*.json update
* 395e3502 workflows: fix windows clean cache
* 44c9c6a7 package*.json bump deps
* 292ef8e2 website: bump deps and update
* 2a580137 workflows updates
* 8c7f3091 workflows updates
* 83b54650 re-generate commons for latest gh hosts
* 870916fd test-ci.yml: try ubuntu 26 and macos 26

## 2026-11-08

* cc97d50e add trigger-workflow-test-all.mjs using curl
* bfd9d5b7 #287: Use gcc-ar for the LTO archives on Windows
* 905b81c9 #286: Silence the GCC 11 format truncations
* 6055123e skills updates
* 028d5db2 add trigger-workflow-test-all.mjs using gh
* 4845186d #285: Rename the alias that shadows value_type
* 6c764cbb #284: Guard the sized operator delete
* 04090403 #284: Silence -Wpadded in the operands test
* 9d91b102 #283: Pass the wstring lengths explicitly
* c8bb215c #284: Use llu for size_t with MinGW GCC
* 49f9be46 The Windows CI build with MinGW-w64 GCC failed, because the size_t conversion macro expanded to "zu", which the ms_printf format checker of GCC rejects, and because the listed test case and suite counts were narrowed from size_t to unsigned long, which is 32-bit there.
* 6e6f6cb4 #283: Pass the u16string lengths explicitly
* 60585a5d #283: Avoid a GCC 14 LTO false positive
* 324fb638 tests/package.json bump deps
* 4b2c31ea tests/package.json: raspberry-pi-dependencies
* 52a408f8 tests/pacakge.json update
* 4a3e9f99 re-generate tests commons
* 415e5c62 #282: re-format

## 2026-11-07

* a495ade7 website re-generate
* c5ef2c19 website updates
* d8ab16c5 #282: Write the duration ratio without suffixes
* 0c1919b0 Fix the findings of the website review 4

## 2026-11-06

* 99339c89 WEBSITE-API-REVIEW-4.md and updates
* 4659806f re-generate website

## 2026-11-05

* 01834cff WEBSITE-API-REVIEW-3.md and fixes
* f7003aaf Review the published pages in website-api-review
* 55868b39 Hide the rejecting overloads from Doxygen
* 101bb480 website update
* af053101 Fix the website-api-review skill
* d51bb01c package-lock.json
* 8904784b website update
* d561cdcd Fix the warnings of doxygen2docusaurus
* 1b0ad1c7 API-REVIEW-10.md and DOXYGEN-REVIEW.md
* 67aa7242 #280: Report the misplaced test cases when listing
* ff363279 #279: Accept the volatile arrays as operands
* 4c3468e9 DOXYGEN-REVIEW.md
* ba2ba243 Update the comments that were stale after #278
* 18ae7408 re-format cmake
* f7ad1e8c API-REVIEW-10.md
* 4d4ed367 #278: Write the wide strings as text
* 576641d7 #277: Report the errors while listing the tests
* 308bd4ac Document that the arrays are referred to
* 1be46e35 #276: Compare the array elements by their value
* bfb5c5e3 API-REVIEW-9.md
* 11f1366e #275: Test the framework without exceptions
* 007a0d3d #274: Report the rejected calls
* d577784b #273: Write the application types in plain mode
* 8637f7e9 #272: Compare the characters by their value
* abb8a98d #271: Bound the character arrays by their size
* aaadbe4b skill update
* 1be9456a API-REVIEW-8.md

## 2026-11-04

* f6714bc5 Update the comments and the pages that were stale
* d74a9b38 #270: Move two internal concepts out of extension
* 06c94f00 Correct the quoting of the members of the types
* c130b482 #269: Quote the file name of the TAP location
* 5ebf9cca Document more design decisions of the API review
* 05736e96 Wrap a comment line of the human-readable reporter
* 268ca111 Document the design decisions of the API review
* e5c75804 #268: State what the tag of an expression needs
* e733b9ff #267: State why a comparison is rejected
* 5c9fa10a Update the developer pages for the recent fixes
* 728d5090 #266: State what a message argument is
* aad44356 #265: State what the body of a test takes
* 0a4b61d7 #229: Document the copies of the operands
* 14f5144f skill update
* 10479a1d #264: Reject the wrappers of a bool as conditions
* 44a355d2 #263: Do not copy the body of a test case
* cb8f6a7a #262: Accept the mutable callables in throws()
* 888eeb30 #230: Document that a check result is not named
* 5a14844e #261: Reject the misdirected test cases
* e5d7f766 skill update
* d85947d0 #260: Compare the wide strings by content
* 5ec9632e #259: Reject early test cases of static suites
* 38d88189 skills updates
* 35a688d0 website update credits
* 7b5e3582 website update claude link
* 26c8b8eb doxygen updates
* 77738c6f re-generate doxygen
* 43ba4fe2 website updates
* 298299a3 website: add the additional developer pages

## 2026-11-03

* 5faa077c copilot & claude update
* 0bacbd67 #258: Number the unwritten passed TAP checks
* da6ebfb8 website updates
* 00ffcc30 .npmignore no LICENSE-Boost
* f3b568f3 WEBSITE-REVIEW-2.md and changes
* 025dae98 website move compatibility notices to releases
* 4d4c8a84 website review updates

## 2026-11-02

* ccab3ace website review updates
* 06e3e166 re-format cmake
* cef82bb4 xcdl-package.jsonc: make diag-trace optional
* 19390757 website review updates
* b58cc6ee website/package.json bump deps
* cfcdfcc3 WEBSITE-REVIEW-1.md added
* 4f44037f update skill file
* 485efc2b re-generate website
* 3f6fd3df add missing doxygen definitions
* 18aaa6e0 skills updates
* 22ea84bb WEBSITE-API-REVIEW-?.md added
* 2657381c website consistency updates
* 3de4ebe1 website/doxygen/topics updates
* a4890979 rephrase human-readable
* 817de3d5 Doxygen and website updates
* 90eed7fe website re-generate
* 56ac326d Colour the closing parenthesis of a negation
* f3429c4e List all the option spellings in the help
* 885ad544 #237: Write the colour sequences without escaping
* 411bcff2 CLAUDE.md update
* ec9557f8 Update the Doxygen comments to match the code

## 2026-11-01

* 26cbe023 skill update
* 72ec2a6e API-REVIEW-7.md added
* 3e7f46ac Silence the warning of throws<std::exception>
* e5e5fbd4 Fix the documentation items of API-REVIEW-7.md
* 45139a09 #256: Report the missing comparison first
* eb68e27d #255: Merge the comparison concepts
* bddd782e #254: Write the long double suffix as L
* 60af1266 #253: Detect the strings by their conversion
* a099a4ff copilot & skill updated
* 868f7efa #252: Move the misplaced test case checks
* e8246e85 #252: Reject test cases on a suite not running
* 691bfaf7 API-REVIEW-6.md added
* c2a19d23 Fix the documentation items of API-REVIEW-6.md
* 05ba6d48 #251: Qualify the calls of the internal functions
* e570bdf7 #250: Move approx_operand to the extension namespace
* d651fa6e #249: Avoid copying the names in the TAP reporter
* 30d379dc #248: Match the options with a value in one table
* 7b084117 #247: Guard the deprecated value wrappers
* 5e6cc586 #246: Do not instantiate the generic bodies when checking
* 9b405683 #245: Fail the listing when the filters select nothing
* 3040e93a #244: Describe the filter levels in the help
* bf1aa796 #243: State what expect() and require() take
* 1011aad1 #242: Write the negated comparisons in parentheses
* f4873dc0 #241: Report why the exception checks failed
* 398787cf #240: Check the tags of the extension expressions
* bd1d33c4 #239: Check the bodies of the tests and the suites
* 2bddb862 #238: Reject the operands that cannot be compared
* 099d0d5c #237: Escape the control characters of the text
* 36a441c8 #236: Check and report the wide strings
* 78700952 #235: Accept equal infinities in approx()
* d0e3af3d #234: Do not swallow a failed requirement
* 8ad82b6b #233: Report the values of application types as written
* f51ded85 #232: Write the option errors to the output file
* a9e314a6 #231: Report a misdirected check as a failure
* e9ad5539 #230: Prevent using a bound check result
* 6fc1a779 #229: Store the operands of the comparisons
* 52881542 update compare-size.py

## 2026-10-31

* 444d9a3e copilot-instructions updates
* 87e3c16b api-review skill update
* df38a724 API-REVIEW-5.md updated
* 48776691 #228: Name the suites and the test cases alike
* 6104e382 API-REVIEW-5.md added
* bcb876fe #227: Give the real reason for the string_view names
* 557d765b #226: Make the counters mutators private
* a5458f6c #225: Add a default constructor to the formatter
* 6ecbc779 #224: Document the stateless extension tags
* a5904145 #223: Keep the options constructor free of output
* e54ddb7d detail.h re-format
* e0fcb270 #222: Prevent keeping a check result in a variable
* 079b4aa9 CLAUDE.md update
* ab67099c #221: Write the types without a suffix as casts
* c824ff2d #220: Reject a mode after a bare --colour
* 1123a982 #219: Quote the C strings in the reports
* a3d6d3d6 #218: Make the options command line read-only
* e6e58964 #217: Constrain the logical function operands
* fec5ed7d .github copilot 7 skills updates
* 44491d81 add .claude/skills symlink
* c826cd6a #216: Discard suites added to a declined session
* bc0c39ce tests-template.jsonc hasUnitCommon
* 72d815e3 #215: Rename the tests assets folder to expected
* ccae0625 #214: Use the mt alias and share session check
* 61fe800f re-generate tests commons
* d83fe8f3 #213: Build the unit tests as a single program

## 2026-10-30

* 6333715d #212: Write the list of test cases as plain lines
* b88ae289 #211: Report the unknown single-dash arguments
* 1c6720a3 #210: Add the --help option
* db0045ec api-review-4.md updated
* 727842cb #209: Guard the tolerance definitions as deprecated
* e550feed Fix the empty @par paragraphs in utility.cpp
* 231e021c #208: Limit the elements of a range in the reports
* 7a3e2867 #207: Make run_suites() nodiscard
* 7fc46067 #206: Share the loop that displays the open headings
* 5d621c32 #205: Accept a null path in extract_file_name()
* ad6582aa #204: Accept both spellings of the colour options
* 5239bd53 #203: Accept the same names for suites and tests
* d853c6ca #202: Make the suite constructor private
* 90ca4c69 #201: Explain the options terminator
* 3d004354 #201: End the options at the application arguments
* 1e4db6b9 The test programs were run with the arguments one and two ...
* d2275b4c #200: Write the test case list as TAP comments
* 7ab637d5 #199: Fail the session on a repeated setup call
* 71aa55ce #198: Constrain the formatters of std types
* a7ebaaa6 #197: Write the output file note as a comment
* 832768b7 #175: Stop the run on command-line errors
* 6484dfa7 #196: Make approx() inclusive of the tolerance
* c1f961a0 #195: Compare mixed-sign integers by value
* 4bb459bc API-REVIEW-4.md
* e9e79e78 6.0.0
* 3e4a23e5 website: update configuration and deprecations

## 2026-10-29

* fd2fcce1 #194: Keep a few removed definitions deprecated
* 6da63ce0 #193: Rename runner::run to run_suites
* b9bb6ac0 #193: Rename runner::run_suites to run_child_suites
* 1c163cdf website updates
* 6fadb04b doxygen deprecated grouping
* 123bf7a7 prefer --xxx=yyy
* 7d66091a prefer --xxx=yyy
* f5779028 website update
* 947f9692 re-generate top commons
* 98bf6cdb website update

## 2026-10-28

* f14cba6e website update
* 711b329f re-generate website
* 0de8b140 #191: Use singular for the test library names
* 7fde75c3 #190: Make the deprecated definitions optional
* d9d64701 #60: Document the use of several runners
* dd28f5d6 #189: Regenerate the board human references
* 974cbd5a #189: Decouple initialise() from the top suite
* a2f0ad33 #188: Make runner_options a parsing class

## 2026-10-26

* 8be06822 package.json update
* 18d013bf re-generate top commons
* 392cc770 re-generate tests commons
* 6cf382be re-generate top commons templates
* 27f1174f tests re-format cmake
* e5d65e5d #187: Make split() accept string literals
* f90df1ff re-format code
* e5ee994e #186: Make the classes not meant for derivation final
* 091a288f silence warning

## 2026-10-25

* 9b4f1d71 document that the alphabetical suite order is kept
* fb91a5b3 #185: Make the totals of the nodes read-only
* 6032fdda #184: Reject the always-true check arguments
* dc2e824e #183: Compare the raw arrays by content
* 731850e7 #182: Do not suffix inf and nan
* 53ac5328 #181: Ignore -Wdocumentation in the concept headers
* 9adfef35 #endif cosmetics
* ef3ff658 #179: Guard uncaught_exceptions_ by exceptions
* bb32344a #178: Do not format passed checks when normal
* 551dd181 #177: Do not copy the values of test_each()
* 34bc8ccb #176: Format std::chrono durations in checks
* 0770184e #175: Stop on command-line errors
* 8ca45534 #174: Route the reporter output through one policy
* a4cb125b #173: Quote string operands in failure messages
* c82e9493 #172: Accept null test and suite names
* 3fc247f5 #171: Require iterators in container_like
* 664850de #170: Reject the late static suites
* 42ab3ca3 API-REVIEW-3 update suggeted order
* fec2bc0b api-review update
* 1b55e954 #169: Move the operators and literals
* e7f7d5f7 #168: Add the variadic all_of and any_of
* 1efc4e8f #167: Use the noexcept references on RISC-V
* 1bb68ad0 #166: Add the third API review
* 0b707ed6 #166: Deprecate the operators and literals

## 2026-10-23

* 1e491028 website update
* 4344d9fc tests semihosting-defines.h cosmetics
* 7efba8da .cmake-format.py update
* b303beb9 update skills & copilot
* ef9de694 tests split unit-combinations & miscellaneous
* ac80b965 split unit-checks, unit-exceptions and unit-deprecated
* b727a45f rename unit-static-asserts
* d6781883 add static asserts test

## 2026-10-22

* 8d51ce2e tests/pacakge.json: add synthetic-posix-sys to all
* 7d56bd9a tests/pacakge.json: remove clang16
* 49bd1c5b #165: Build the library with clang 17 and 18
* e7547ccb #164: Group the deprecated definitions separately
* e79e8440 remove duplicate @deprecated
* 335bab7f update doxygen
* c2b83fc1 DOXYGE-REVIEW.md added
* 3a58bccd doxygen-review skill updated

## 2026-10-21

* de08c022 re-indent code
* e89ab070 Remove the unneeded pragmas from the tests
* 243c7bdd package.json 5.1.0-pre
* f77342cf maintenance docs updates
* cb741fbf skills updates
* c148dddf #163: Add the --list-tests option
* 87e470fc #162: Add the --color and --use-colour options
* 1e21b785 #160: Add test_each() to the suites and test cases
* 9f98e14f #159: Detect the formatted ranges as range-for
* d3c3cdb8 #158: Require printable operands in comparators
* 23f1a2ce #157: Add the three-argument approx() comparator
* ffa6845c add more copilot instructions & claude skills
* 03af21b0 #156: Call the callable messages only on failure
* 2933857e #155: Accept explicit bool conversions in checks
* b0afe2fd cleanups in copyright messages
* dbe0c110 #153: Restore the v5.0.1 type_traits::has_value
* 2569b329 #153: Restore the deprecated type_traits, timestamp
* 2a61dc46 #153: Restore the deprecated subtest
* af9720f5 #153: Document the suite order and --filter
* 72a7b401 #153: Restore the deprecated runner::reporter()
* 87a5272e #153: Restore the deprecated timings()
* c0c7238a #153: Restore the non-const totals()
* 2605063f #153: Restore the deprecated counters members
* bf5a50e1 #153: Restore the deprecated wrapper types

## 2026-10-20

* feeaf486 #153: Restore the deprecated logical functions
* d35ad6e1 #153: Accept the static_suite& suite functions
* 1b39ac05 tests/package.json update configs-selected
* 5b151f54 revert -Og to -O0 in aarch64, f411re, h533re
* 123f0c76 #154: Reduce the stack used by nested test cases
* 4fc532df #153: Move the deprecated feature tests to one file
* 70660a6c #151: Report the wide characters as literals
* 025a723d #148: Validate the TAP outputs against TAP 14
* 2ae68d6b #143: Explain the second initialise() branch
* 0f623d56 #142: Use the size format macro everywhere
* 3de2002b #141: Use the standard exception and Windows macros
* 3d7ec5fa #140: Refer to the test case bodies
* 8d3b836a #139: Forward the operands of the comparators
* fdcab206 #138: Format the passed checks only when written
* a451f903 #152: Write the report lines to both streams once
* 0bf23316 #137: Remove the callable type from throws_op
* dd9c8cbf #136: Simplify the floating-point literal encoding
* efbebd50 #135: Deprecate reflection::short_name()
* 48a2b3b8 #134: Move the common reporter logic to reporter
* 71f381a6 #133: Move the test case creation to runnable_base
* fdaa1f64 #132: Keep all the suites in one sorted list
* 6d33fa75 #131: Write the messages with the formatter
* 8fa29e9b tests/scripts/README update
* 74e84dcd tests/package*.json update
* 3b6272d8 skill update
* 5d000eaf #150: Say member functions and data members
* eca85089 #130: Align noexcept and restart the stopwatch
* 01efcbac #129: Remove the underscore from member functions

## 2026-10-19

* a46e6f17 #127: Add added_suites_count() and passed_checks()
* d3132ec3 re-format clang
* aa662c25 #126: Deprecate suite() and verbosity()
* cee35ed9 #125: Make the non-public members private
* 6dec41fb #124: Make the counters copyable

## 2026-10-18

* d029d08b #123: Document the output redirection
* c8295c08 #122: Report aborts through the reporter
* f497d3ec #121: Document that quiet does not show failures
* 81bce73b #120: Document the byte order of the suite names
* 47d987d4 #149: Make custom comparators report operands
* 0ee0278b #118: Rename type_traits to extension
* b43b0fcd #117: Make the formatter protocol private
* c51d8477 #116: Make the test case name a public type
* b200ea72 #115: Make the test node protocol private
* 620cfbcd #146: Rename the TAP location fields
* a3445ab3 #147: Quote the TAP condition values
* e7421411 #144: Remove the aborted marker from TAP
* a309b387 #114: Respect the silent verbosity for the output file
* 287a15d9 #113: Format the common standard types
* 75e921f8 #112: Remove the string_view operators
* 850957df #111: Escape the names in the TAP output
* b5c7a6a6 #110: Document the purpose of the output file
* 2b83ff31 #109: Count the suites in the quiet TAP plan
* 5167fe2e #108: Keep the type of negated integer literals
* 257d4962 #107: Print long double in the shortest exact form
* 977e9755 #106: Quote the characters in the reports
* 0ba39b82 #105: Restrict value concepts to framework types
* 1be5557f copilot-instructions update
* 3739ef5b Count the leading zeros of small wrapped values
* cac5faac copilot-instructions update
* f6fa0d4f Report the named boolean literals by name
* 604b608e Remove the empty base of the value wrappers
* 2d89d03e Report the aborted test case before aborting
* 6f7509a3 Nest the test cases started on a running suite
* a176c555 Correct the begin_suite() and end_suite() callers
* d7cf21a1 Catch the exceptions thrown in the suite bodies
* 2ddf8780 Reject the suites added after run() started
* 72a5bc37 Correct the filter_patterns_ description
* e81de8ab tests/package.json update ci & selected
* a2bd9576 claude & copilot updates
* 552ae9eb Copy the filter patterns in the runner
* 9de58bfd Keep the verbosity in the runner
* a8733dc2 Make source_location independent of include order
* 56c4d722 configurable st-openocd

## 2026-10-16

* 97989e68 package description update

## 2026-10-15

* 821ca8ab api-review update
* f279ee54 add new skills
* 970c4231 re-format
* f58dff49 #95: Remove the unused helpers
* 6265f4cb #94: Parse the type name by its full marker
* 0c84df54 #93: Add the wrapper tolerance compatibility notice
* aab11b2e #93: Count the decimals of a value safely
* ee9e4810 #92: Print the TAP test point as size_t
* 97c81428 #91: Undefine the size format macro
* 9316deee #90: Pass the names to the reporter writes
* 20b23129 #88: Destroy the test cases after they run
* 488fc7b3 #87: Add the get() compatibility notice
* 660b5121 #87: Return the operands by reference
* 7d846b8a #86: Capture the callable arguments in a lambda
* 9ab5f925 #85: Remove the container operators
* ac6a2bb5 #84: Merge the six comparison structures
* 9c61e33a #83: Remove the duplicated code
* a84c9e75 #82: Use const references in the reporter hooks
* e37df158 #81: Name the check kind in the failure reports
* 96d63e7f #80: Unify the declaration style
* 55ba0be4 #79: Fix the number suffixes in failure messages
* 420694bf #78: Rename endline() and flush()
* 66fd6880 #77: Rename get_comment_prefix()
* b0c6561a #76: Add the deprecated attributes
* 71f0d26f #75: Remove the deprecated type wrappers
* a04d37f8 #74: Rename the logical functions
* fee79766 #73: Apply the name suffix rules
* dc890c5b #72: Merge deferred reporters into check_result
* eada5504 #69: Replace the remaining subtest references
* 0fbebfa8 #71: Replace the timing classes with a stopwatch
* 0fbf32a3 #70: Rename runner_totals to counters
* f28083ac #69: Rename subtest to test_case

## 2026-10-14

* c53c45c8 #68: Merge test_node into runnable_base
* d9767eff #66: Move the math namespace to detail
* 59698efd #65: Rename runnable_base::runner() to test_runner
* a4bca562 #64: Move the value wrappers to detail
* 5a6009ca website/package*.json bump deps
* f663eee6 #63: Add the --filter option to select tests
* 395c980d #62: Include detail.h in two public headers
* 02fb0de0 #61: Run all suites in a single name order
* 866693e0 #60: Merge static_runner into runner
* 0e2dd5cc #59: Pass suite& to the static suite callables
* b55760e6 #58: Remove the runnable template layer
* 06a6783e #57: Stop deriving the runner from test_node
* 3ee4a3f6 #56: Stop only the test case on failed require
* ad4a1a9c #55: Stop terminating the process on errors
* 438ebb5a #44: Fix the doxygen match of as_operand_
* badcf376 #54: Configure the runner without a command line
* f9a962b5 #53: Parse the command-line options once
* aedc6117 #52: Move the reporters to the detail namespace
* 4d893432 #51: Remove the detail types from public signatures
* 9253f119 #50: Make the test node constructors non-public

## 2026-10-13

* 3bd15439 #49: Make the test counters and indices read-only
* 35ece3b5 #48: Write null C strings in messages as nullptr
* 56b99ca9 #46: Report exceptions escaping a test case
* 4fd2c4ae #47: Raise the stack size of the test platforms
* fd6220ab #45: Print char pointers as strings
* 96da278a #44: Compare C strings by content
* 38c89353 #43: Copy the names of the suites
* 7032feb4 #42: Fix floating-point literals on 32-bit targets
* 4dc047e4 #41: Apply the float tolerance in all comparisons
* 0d280c51 #40: Define reporter bool and nullptr operators
* 19b02b56 #39: Parse integer literals with C++ syntax
* 40d58127 #38: Allow bool values in check messages
* 2f29e6c8 #37: Ignore application get() in comparators
* c4c3597c #36: Report stored checks with their own text
* b5139d83 #35: Rename exit_code() to run(), run once
* c0af8a17 #34: Fail test cases with failed nested ones
* d9b694e0 #33: Allow nested test cases after checks
* f1827b97 website: update CustomFeatureList

## 2026-10-12

* 38bb4962 website: HomepageExmple update
* 00a0f8c4 #32: Document how to use custom types
* ffcb8e36 website description cosmetics
* 3f95b554 website: add userGuideDescription
* 945fbfc6 website: add faq content
* 0fd71bc0 website: fix about typo
* 635fb82a website: add _more-intro.mdx content
* e203fa11 website cleanup
* 5d601583 website: make test pages draft
* e9ffb1d0 website cleanup developer/install/prerequisites
* fd7a5b05 website: make Glossry not collapsed
* 44c6cf33 website: add home page example
* 3a436c78 launch.com add nodegenerate-website-commons.mjs
* f3cae730 website: update home page features
* 87931611 update device-raspberry-pi references
* 7f54df68 tests/README update
* 9d9dcd3a package.json consistency updates
* 058ef42d okatforms README updates for wrap.c
* 21c8d507 skills updates
* 95915aeb tests consistencies fixes
* 31004e10 tests cleanups
* be23271e add consistency-check skill
* 6af9731d website doxygen update
* 639d3053 add doxygen-review skill
* 625c6cf1 update doxygen comments
* 3b339d40 website update folder hierarchy
* 970ee671 fix include guards
* 4857922a fix exception-inlines.h (plural) name
* f683d416 update READMEs
* 8b446e8e launch.json fix synthetic-posix
* 654074dd tests/package.json add missing link-dependencies-raspberry-pi*
* 0c190807 tests/package.json fix zero-2-w configuration
* 78076ae8 rename platforms qemu-aarch32/64
* 90500ede update for specific device names

## 2026-10-11

* adf6efb1 update for device (singular)
* 28077455 re-generate tests commons
* 86b21a73 re-generate top commons
* ba1aba2f update for architecture (singlular)

## 2026-10-08

* ec773ea7 platforms *-cubemx vectors cosmetics
* 785349fb scripts/convert-startup-to-vectors.mjs update rmSync
* 224373c0 tests/package.json configs-platforms-vectors
* a156a0c4 tests/meson define-executables fix synthetic-posix
* 6fecffef tests/pacakge.json fix synthetic-posix
* 992c6041 rename synthetic-posix

## 2026-10-07

* a702d272 re-generate tests commons
* 0ada31c7 tests-template.json add all platforms
* 75d93864 tests reformat
* 434a1bb5 common-functions.cmake update
* 60eade7c platforms README updates

## 2026-10-06

* 879de4d2 remove DO NOT EDIT from artefacts
* a7614ad5 re-generate tests commons
* 73b831ac re-generate top commons

## 2026-10-05

* 427f0f51 RPi openocd cosmetics
* 0298b33c ST openocd cosmetics
* 97e80f39 move code to maintenance
* 57f1ad3a copilot-instructions: add xcdl section
* 5bef38f4 qemu-riscv-*: smp 2 to test cpu parking
* 52acc325 project-config.h __ASSEMBLER__ notice

## 2026-09-30

* ce612370 raspberry-pi-zero-2-w-jtag.md update
* cbdba1f0 copilot-instructions.md update
* 76b38a09 raspberry-pi-zero-2-w-jtag.md update
* 6ab0de56 workflows update
* 057adc13 workflow updates
* 0d81c355 reporter: strip colour sequences from the output file
* f282049b website: document the console output path
* 945474bd reporter: route console and file output through helpers
* 60e8b753 reporter-human: do not write colour codes to the output file
* 475ef647 tests nucleo-h533 st-openocd temporary fix

## 2026-09-29

* 65883d5b pico-2-ricv no exceptions
* a89c3ffa tests openocd reset halt + resume
* 9b3188f3 pico-2-riscv-sdk: run each SDK initialiser once, in SDK order
* 2b0f634c pico-sdk: run each SDK initialiser once, in SDK order
* 3d9473ec pico-2-arm-sdk: run each SDK initialiser once, in SDK order

## 2026-09-27

* 4a8bae42 add raspberry pi jtag docs

## 2026-09-26

* 67401eb4 pico-2-*-sdk updated for device-raspberry-pi
* 48a5a91e pico-sdk updated for device-raspberry-pi
* 91288db9 update device-defines.h to use _CORE_XXX
* cf2a5f18 update architecture-defines.h
* fe9cd380 include device-defines.h in all device.h

## 2026-09-25

* 9417772c rename pico vectors to support
* 5df6ef12 bring back pico-2-riscv mem.ld
* e71dfb73 pico & pico 2 non-sdk updated for devices-raspberry-pi
* b7397666 pico-sdk cleanup experimental

## 2026-09-23

* 1d882ca3 fix architecture macro names
* 74635c1d pico clen warnings
* ff7da80e pico add -Werror

## 2026-09-22

* ecad2fa1 launch.json add svdPath to cppdbg
* 9d0446b6 pico hooks %lu Hz
* 2de30718 launch & tasks update
* c3ff0a0a add pico-2-riscv
* c95df21c pico 2 arm rename embedded-block-rp2350-arm.c
* a27d998b pico cmake cleanups
* 5fd5104d tests: add placeholders for pi zero
* 1117c7d0 tests/package.json add pico-2-riscv (no sdk)
* d1d2cc4c copilot-instructions.md update
* 4b01c92c tests/package.json add pico-2-riscv-sdk
* 7e34766d launch.json more pico 2 riscv targets
* 23ccadf7 explicit PICO_PLATFORM rp2350-arm-s
* 64408952 add platform pico-2-riscv-sdk, one run only

## 2026-09-21

* b1411373 re-format cmake
* b3275c8a nucleo boards max clocks
* 8639197e align standalone f411 clock to 96MHz
* fd3c5d37 rework cubemx_main & hooks
* b15e1771 tests/package.json add more boards
* c59f8b5a vectors use MICRO_OS_PLUS_DEBUG_ENABLED
* 543c3bd5 hooks fix format
* 9845c179 wraps pico use architecture instead of cmsis
* 0ef1226e display clock in pico-*-sdk platforms
* 6cded85b display clock in nucleo-*-cubemx platforms
* 642db6bd display SystemCoreClock

## 2026-09-20

* feed3ad8 add new nucleo-standalon-platform skill
* a36e3812 re-format cmake
* a35a892d change f767zi clock to hse
* 68d7dac0 add platform nucleo-h533re with rc clock
* b7e950b2 add platform nucleo-f767zi
* 9415a929 platforms pico* shorten platform namespace
* 68a08751 change the clock to c++ in pico and pico-2-arm
* 1c984102 rename to system-clock for pico*
* b0891b87 aggregate headers

## 2026-09-19

* e0adac3c nucleo-* rework headers, simplify namespace
* dbaa7c0b add platform nucleo-f411re
* b80c27bf rename micro_os_plus_*_clock_initialise
* 21edb0ef hooks.cpp document hooks
* a20e94eb use micro_os_plus_startup_post_init_array_hook for pico too
* cbfe3b30 nucleo-h533re-cubemx-startup add green led
* 90255632 nucleo-f767zi-cubemx-startup add green led
* b0026b88 nucleo-f411re-cubemx-startup add green led
* 6614f798 copilot-instructions.md update
* 8eb0cb65 clock.c reformat
* 2fea7b0b update namespace and led names
* 4c328762 more #if defined(__GNUC__) guards on pragmas
* 3b0b60d6 nucleo-f411re-cubemx add green led
* b5f6cd74 tests/package.json add link-dependencies for pico
* d788d9f7 rename cubemx platforms
* e66df188 raspberry-pi-pico-arm-sdk add green led
* ca653d6b tests/package.json bump deps
* fcf654db raspberry-pi-pico-2-arm-sdk add green led
* 9f6048d5 CLAUDE.md update
* bd520d8b .npmignore CLAUDE.md
* 30ba8cde tests/package.json bump deps
* fcb7f8b6 clear-build-folder.mjs: check folder presence

## 2026-09-18

* d5d8fbd9 cosmetics
* 39c2c4ed pico-2 add led
* 2b1dff07 tests/package.json bump deps
* 9a28ff64 update skills
* b002f3be raspberry-pi-pico add led
* 82fac327 tests/package.json bump deps
* 44f2e6b2 raspberry-pi-pico add MICRO_OS_PLUS_ARCHITECTURES_CORTEXM_VTOR_PRESENT
* ebbd5938 pico-sdk show libs content
* 0206d2c8 add clock to rp2040
* 6b09ce6c meson: swap library and artefacts

## 2026-09-17

* babc53bc tests/package.json bump deps

## 2026-09-16

* 7f03227b package.json fix aarch64 actions
* 9999f1b1 setting.json python.analysis.exclude **
* b6a762d7 rename micro_os_plus_platform_dependency
* 8acb0a00 fix riscv section-reset-entry.ld
* b5769465 rename all cmake device libraries
* 98380b61 rename all cmake platform libraries
* afb6f8a7 launch.json update
* 4ad33eee cmake cosmetics
* 117a0f7e rename pico2 platform-interface
* d327c44c add pico-2-arm clock
* a578bfad project-config.h cosmetics
* e007ba96 add raspberry-pi-pico-2-arm
* 5d188f9a raspberry-pi-pico __vectors_align=256
* bec331cd fix cortex-m3 meson

## 2026-09-15

* d5fb986e tests/package.json add build actions
* 639ad809 reference section-interrupt-vectors.ld & architecture
* d358ba5a more comments in dependencies-folders.cmake
* 3a9ef4cc more comments in dependencies-libraries.cmake
* 95f018c9 raspberry-pi-pico updates
* 74458566 launch.json updates
* 15024fc2 defines.h cosmetics
* 42d163b1 comments
* dec9ba36 tests/package.json update pico link-dependencies
* 95025c36 add platform raspberry-pi-pico

## 2026-09-14

* c06688f7 add -sdk suffix to pico & pico 2
* c20326c7 tests/package.json add clear actions
* 47090b09 f411re cosmetics
* ca3c06d0 pico & pico2 use wrap main & __libc_init_array
* 38d335d2 pico cleanups
* 4149d7eb copilot-instructions.md update
* f297e5c8 add sleep to openocd for nucleo boards
* 5d137132 add pico2-arm

## 2026-09-13

* 8603084b add pico experimental files

## 2026-09-12

* 5fd81fee add raspberry-pi-pico
* 54998276 update copyright year 2026
* f0a8c5e7 launch.json update
* 866b3822 nucleo device README updates
* bd6d6d04 update STM32F411.svd in second project
* 6d019ce4 STM32F411.svd add system peripherals
* db18ce21 add STM32F411.svd from CMSIS Pack
* 9084314c STM32F767.svd add system peripherals
* 1fe5a93e add STM32F767.svd from CMSIS Pack
* dd177eb1 STM32H533.svd add system peripherals
* c8aaadd9 add STM32H533.svd from CMSIS Pack
* f029da0d update copyright dates
* 32db2998 update nucleo platforms cmake to import cubemx cmake

## 2026-09-11

* 48ad0b61 nucleo-f411re README updates & cleanups
* faecbbb4 nucleo-f411re-cubemx-startup README update
* a9e41336 cmake-format.mjs ignore stm32cubemx
* 97a4c9ac nucleo-f411re-cubemx-startup cleanups
* 91e44c37 tests/package.json bump deps
* 4baa3155 add nucleo-f411re-cubemx-startup

## 2026-09-10

* c7fd0596 cleanups
* 001cba5d test/package.json nucleo dependencies
* 1ba2a5c6 tests/package.json bump deps
* 66aa6d12 qemu-risc updates sections.ld
* 08cb9505 qemu-cortex README updates
* b18e0153 nucleo README updates
* 66defb97 stm32cubemx main.c use hook

## 2026-09-08

* 3ef02ef8 cmake add ADDITIONAL_CLEAN_FILES

## 2026-09-07

* 7b76350c vectors-liquid.c: check MICRO_OS_PLUS_DEBUG_ENABLED
* a16879c8 convert-startup: accept IRQ_Vectors
* aa02fd1f tests: add dependencies-libraries
* 08e71d58 add CLAUDE.md
* adb913b4 tests: use cortex-m architecture handlers

## 2026-09-04

* a96b3327 add CLAUDE.md
* 0fd4d96f fix double dot in script copyright
* 8e1d2bc1 tests/package.json add m33 to qemu cortexm variants
* dbcaf6eb tests/xcdl-project.json add m33
* 5797c29a meson_options.txt updates
* 8790389a nucleo-f411 cleanup *.jdebug
* 35bba598 nucleo-h533 exception handlers with SecureFault
* 239b712e platform update memory maps
* c82d90b8 use startup sections.ld

## 2026-09-03

* e22632cb re-generate vectors for SecureFault_Handler
* f61ce79c convert-startup...: add isArmArch8m
* 9801b7d0 package*.json add prettier
* 854b2e92 add cpu_reset to qemu debug options
* 5944c221 re-generate vectors-*.c
* 0dacd738 add convert-startup-to-vectors
* c387e5a5 cmake/common-functions: add qemu log

## 2026-09-02

* 30d909e3 tests/package.json ignore errors for celan
* 7326d5bb tests/package.json add clean-nucleo-*
* 0926e5fc platforms cmake-format
* 0d778470 add platforms/nucleo-h533re

## 2026-09-01

* 0d327355 prepend_compile_common_private_option & stm32cubemx-drivers-objects-library

## 2026-08-31

* a6091cf0 platforms/nucleo-f411re update
* 89b61681 add platforms/nucleo-f767zi
* 63ea4b2f platforms/nucleo-f411re update
* b10664a3 .vscode/settingd.json: variableUseNaturalFormat
* ee767b4e cmake cosmetics
* 55b73931 tests/cmake: shorten map path
* 88aa7752 clanf-format.mjs update to avoid stm32cubemx
* 0620328a tests/package.json: add nucleo-f411re
* 1b95d1d3 tests/sources: [[noreturn]]
* 7ff39576 platforms/nucleo-f411re: update reset-handler.c
* fc8cf11b platforms/nucleo-f411re: update stm32cubemx

## 2026-08-29

* e0558def platforms/nucleo-f411re update

## 2026-08-13

* 54cd55ec test-inlines.h: silence warnings on windows

## 2026-08-12

* 2c59d16f test/package.json deps
* e5891c91 native meson check get-libraries-paths.mjs exit code
* f72c7bfb common-functions ccleanups
* 2effc685 workflows updates
* d5856218 cmake template file paths updates

## 2026-08-08

* 60153ce6 swap cmake platform-library with artefacts

## 2026-08-06

* 54d26027 blog post update
* ca96b3d7 publish with retries
* c5331d60 blog post update
* c8abd8a4 worklfows update concurency
* 10d1dc54 blog post update
* 011ee646 website update group references
* 83d8b8dc website: blog post release 5.0.1 published
* 397ebebd Revert "website: blog post release 5.0.0 updated"
* 491f7297 5.0.1
* 886b068e re-generate website
* 441199cf prepare 5.0.1
* eba9729a website: blog post release 5.0.0 updated
* 68cd2a59 5.0.0
* c29e9801 CHANGELOG: publish npm v5.0.0
* a65d59b7 prepare 5.0.0
* 265b70bf cosmetics
* c7dab306 #if __has_include("micro-os-plus/diag/trace.h")
* 389ab6ce re-generate top commons for test-all
* 48088dc9 re-generate tests commons with get-libraries-paths.mjs
* 4997cc10 restore test-ci.yml
* c649f29f re-generate tests commons
* 0db77691 re-generate tests commons native cmake
* 6a805a73 re-generate tests commons native cmake

## 2026-08-05

* 59b4456c try without mac arm
* 911b582f restore test-ci.yml
* fafd8f3c native do not sanitize on windows
* e7878131 re-generate tests commons for meson libc++
* 036de50b try without mac arm
* a609fab9 run bash get-libraries-paths in meson
* c60d0291 restore test-ci.yml
* 6b6f6225 re-generate tests commons for bash get-libraries-paths.sh
* bad6d4a8 try without mac arm
* 49175180 try without mac arm
* 00732870 re-generate tests commons
* 8b517bd5 #pragma ... push cosmetics
* 1ff90957 tests/package-local.json update

## 2026-08-04

* 5811f73a CHANGELOG update
* cd9c11a8 tests/package*.json update
* 3e136f14 use tests/scripts/xcdl-export.mjs
* 92e44f39 website/package*.json

## 2026-08-03

* 253f655d re-generate website commons for .mjs
* 227ceb54 re-generate tests commons
* 62cd0b22 use generate-t.*-commons.mjs
* 49f06f1f re-generate top commons for skills
* ec1985ca re-generate top commons for .mjs
* 9e57ff3f update skills
* d091aca9 migrate to clang-format.mjs

## 2026-07-30

* 4e60eea9 website update
* b3836dba re-generate website doxygen
* a0fa7c1f move @namespace to runner.h
* 4ce58c3d simplify -Wunsafe-buffer-usage-in-libc-call usage
* 538071fb test sources project-config.h cleanups
* 6ae96bcc cosmetise #endif // ...
* bfb25358 #if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)
* 381b3682 website doxygen groups updates
* fde02bba re-generate website doxygen
* 56b249df re-generate website commons
* 11f487d7 re-generate top commons
* 97d53f09 website doxygen updates

## 2026-07-28

* 8d8275ef re-generate doxygen
* bdadb1b9 re-generate website commons for fromFilePath & #include "..."
* c44f2480 cosmetise #if defined(__cplusplus)
* 89821a4d re-generate tests commons for {{fromFilePath}}
* 6e9190b1 re-generate top commons for {{fromFilePath}}

## 2026-07-27

* 2edeafb8 include & src: update guard macros & includes
* cd186c61 tests cleanup includes
* 12727f54 re-generate tests commons
* b0254256 re-generate tests commons to fix templates/*

## 2026-07-25

* 6205f226 cosmetise automatically generated notices
* 37373fc7 re-generate tests commons
* 6043e23b re-generate tests commons: tie trace to debug
* 87462472 re-generate tests platform meson
* ff9ae10e re-generate top commons
* a01c5686 re-generate startup-defines.h
* ba51196d tests make CMakeLists.txt RO

## 2026-07-24

* 5946feb1 cmake reformat
* eafb56e3 tests-templates.json add useStaticLibrary
* eafb98a5 update tests assets
* 4ab884a5 re-generate platforms CMakeLists.txt
* c9bdc08a tests startup-defines.h reformat
* 140a30d3 tests trace-defines.h cleanups

## 2026-07-23

* af4dbba5 re-generate tests commons
* 0513568d re-generate tests commons
* e43a7f37 tests remove config.h
* bd807e06 tests updates
* 9edfe4ae update copyright notices
* caf69f57 website update
* 80ea0cbe MICRO_OS_PLUS_DEBUG_ENABLED

## 2026-07-22

* e5602fb0 cosmetics
* 584cfab3 xcdl export
* 9490608d re-generate top commons
* 22ca77d1 inlines fix guard macros

## 2026-07-21

* 1a7f4e55 remove xcdl-export.sh
* 5acfb1de semihosting-defines.h update

## 2026-07-19

* bbe9ca70 tests update for startup-defines.h
* 211c1321 src update for new xcdl macros
* 4759ca12 tests update for semihosting-defines.h
* e248afe1 re-generate top commons
* 26c5478c xcdl-package.jsonc cosmetics
* af04e798 package.json update for buildVerbose

## 2026-07-17

* 8f567477 platform/native architectures-synthetic-posix
* 71d5b88f platform/native MICRO_OS_PLUS_DIAG_TRACE_POSIX_ENABLED
* cee24246 re-generate top commons

## 2026-07-15

* bb22c34c re-generate tests commons
* 2c9cd672 website update
* 7a64fb21 webpreview update

## 2026-07-14

* 896b41f9 website update
* 26626496 @param cleanups
* 4e95c869 website: blog post release 5.0.0 published
* f2d12396 5.0.0
* e9b258af CHANGELOG: publish npm v5.0.0
* daba4c03 prepare v5.0.0
* f0d07d10 re-generate website commons
* f1ed6b33 re-generate tests commons
* 6a312ca8 re-generate top commons
* f8e5f223 re-format
* e5c352c7 no longer use MICRO_OS_PLUS_TRACE
* 0cb68011 website update
* ad59833b @param cleanups
* 80ab24b6 website: blog post release 5.0.0 published
* 824bf1fb 5.0.0
* 15bbb2ea CHANGELOG: publish npm v5.0.0
* 2603a443 prepare v5.0.0
- b22e2984 re-generate website commons
- fa8ef5d5 re-generate tests commons
- 48e26241 re-generate top commons
- aff164ca re-format
- 8e7fa600 no longer use MICRO_OS_PLUS_TRACE

## 2026-07-07

- a5ed67ad re-generate website

## 2026-07-06

- v5.0.0 prepared
- 7bff519f re-generate website
- 00f2d3a7 xcdl-package.jsonc update descriptions
- 05d6e10d re-generate website
- 5478853b doxygen updates (addtogroup)
- a1d7be60 move @details to declaration
- 5a9f6e9a clang-format.sh update
- d282fcd5 tests sources updates
- 6902b821 tests cmake updates
- 22cea2d8 tests headers updates (trace-defines.h)
- c840212b .h files cosmetics

## 2026-07-02

- 36eb7e71 re-generate tests commons
- c0f86f8e tests: add clear-build-folder
- d44fd188 ignore -Wunknown-warning-option

## 2026-07-01

- 1d81e483 re-generate tests commons
- 2abf2b3f re-generate top commons
- c8a0c64a tests/package.json: update ci & selected
- 497f8339 tests: add preliminary xcdl-project.jsonc
- 7aae1f48 tests: shorten source folders
- ab3aeaf4 tests/package.json split long properties

## 2026-06-20

- 78e76f28 CMakeLists.txt cosmetics
- 1acf4540 tests/sources fix .static-library
- d05fc4a9 templates cosmetics
- 640d2dff micro-test-plus.h fix c+=20 test

## 2026-06-17

- cae250fe re-generate cmake & meson

## 2026-06-15

- f9bc2c56 re-generate tests
- 2e0745d4 CMakeLists.txt update
- 40c140d3 re-generate top commons
- 1325d4ad re-format jsonc
- ef0401bd re-format cmake
- 747c1bb2 re-generate tests cmake

## 2026-06-14

- 632f5a12 tr-generate tests commons
- 5507d67d tests update for xcdl-export
- b05a20ba tests/platforms updates
- b66909b4 re-gnerate top commons

## 2026-06-12

- 08449aca update \*-defines.h
- 68ab8944 cmake re-format
- 2bcd7b08 scripts update
- bccc2038 xcdl-package.jsonc update descrptions
- 155eb62e package.json cleanup redundant script
- 6fc6eb34 rename MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE\*\_ENABLED
- f5e3a08e rename project-config.h, leave config.h around
- b1496374 clang-format tests/sources
- b11df203 #include reorder

## 2026-06-11

- 34740b27 prefer project-config.h
- 6b893b5b re-generate top cmake
- 2c0699b4 rename xcdl-package.jsonc
- 86a377a7 re-generate top commons

## 2026-06-06

- 891e9c4d use \_\_has_include(<micro-os-plus/config.h>)

## 2026-05-27

- 68c54ac5 re-generate make & meson via xcdl export
- 5b640305 package.json: add xcdl-export
- e746532c move xcdl-library.json to the top
- d6617496 re-generate top commons for xcdl-export.sh

## 2026-05-25

- 49581cbc re-generate tests commons
- 0f489502 use xcdl-export
- 182ab3a8 rename config/xcdl-library.json
- bf8fb63f add scripts/xcdl-export.sh

## 2026-05-22

- 016e2cca re-generate top commons
- f8746ee2 make static library standalone
- 6e6be9b3 add_qemu_test(0 and add_compare_files_test()
- 05751bc4 add static library to cmake
- 64f961b0 re-generate top commons

## 2026-05-17

- 0336eebe re-format tests cmake
- 149faa68 re-generate top commons
- 3a94ba3d config/\*.json updates

## 2026-05-12

- fc954949 re-generate tests commons (short-win-paths-properties)
- b77ea4d3 website update
- d6965e62 4.1.1
- f82c7015 CHANGELOG: publish npm v4.1.1
- f45e0684 prepare v4.1.1
- 2442265 Revert "fix clang16 linux build"
- dac3a9e fix clang16 linux build

## 2026-05-11

- d070711 fix clang16 linux build
- 1817181 website update
- 3c10916 website posts fixes
- bb42b96 website: blog post release 4.1.0 published
- a836b29 4.1.0
- 45b61e6 CHANGELOG: publish npm v4.1.0
- v4.1.0 published on npmjs.com
- 353d2a1 CmakeLists.txt add CXX
- 68c840b CMake cosmetics in comments
- 6ba1ac4 CMakeLists.txt duplicate fix
- 4ea4a84 website doxygen update
- 5810287 prepare v4.1.0
- 496bf98 re-generate website commons
- 4f3a2b9 use local cmake-format & reformat

## 2026-05-10

- fe8d5ac use local clang-format & reformat
- 9239eca #31: move the top default suite name to initialise()
- 478a667 website/package\*.json update
- d69a6be re-generate website commons
- 7e0d3f9 config.doxyfile: add EXCLUDE_PATTERNS
- 86596a2 update .dox files to remove repetitions
- dded41a copilot-instructions.md update
- fbe0cd9 detail.h: add @details

## 2026-05-09

- 597515f website update
- 88dd73c detail::indent_t
- a835441 doxygen update
- a903306 cleanups for includes
- 8a6ab9f cmake: disable coverage
- d4216c5 #28: fix circular dependency
- 8004f37 #28: more includes reworks

## 2026-05-08

- 5b55e3f #28: more inlines fixed, only test-inlines.h remaining
- 9dd8012 fix illegal character
- 26675c5 #30: Move internal classes to details namespace
- cbf8e4c extract exceptions-inline.h
- fbca56c remove nodiscard from definitions
- 4ed019a #29: Extract expression formatting code from reporter
- 9b1369d Merge branch 'xpack-development' of https://github.com/micro-os-plus/micro-test-plus-xpack into xpack-development
- 4ef8a04 #29: Extract expression formatting code from reporter
- c9bf9b1 #29: Extract expression formatting code from reporter

## 2026-05-07

- d25e887 #28: Re-organise inlines

## 2026-05-06

- 5c2c832 tests: use add_compile_common_private_options
- 404fdd2 test-inlines.h: silence warning
- ee30572 re-generate commons
- ab9c415 re-generate top commons
- e8f23ee #27: Split definitions from declarations
- f6aaa8a tests: use add_compile_common_private_options

## 2026-05-04

- 536e327 website update

## 2026-04-30

- aca5767 platforms/native: remove -stdlib=libc++ from non clang
- 0cef14e more guards & guard cosmetics
- e15b6d7 guard include diag/trace.h
- 0ad8f72 tests: include platform.h
- 8775c7f website user update
- 953cc21 includes: add guard to prevent direct includes

## 2026-04-29

- 8f330f5 re-generate tests commons
- 7c3b63d fix again blog autoformat
- e2ddd82 website updates
- f9a1b1a website: update last blog posts
- 730a42c website: add link to TAP
- 08aeb97 website: fix blog posts code block
- 88273bf .vscode/settings.json: do not reformat mdx
- 88107e3 re-generate website commons
- 14309a9 website: blog post release 4.0.0 published
- 07f01d3 blog posts cosmetics
- 6e72885 4.0.0
- cfd4b34 CHANGELOG: publish npm v4.0.0
- v4.0.0 published on npmjs.com
- 1105af3 re-format
- ac64933 CHANGELOG update for v4.0.0
- bdb8f37 workflow update
- v4.0.0 prepared
- 1bec407 website update
- 4015c5b remove website/static/.gitignore
- 4219430 #26: remove variables templates, use concepts

## 2026-04-27

- febd39a more doxygen comments

## 2026-04-25

- 5b35a79 website update

## 2026-04-24

- 0772248 remove code-review.md
- a983f70 fix doxygen. remove @defgroup micro-os-plus-micro-test-plus-config

## 2026-04-21

- 5456f4d reporter.h: fix verbosity() return type
- c848bad add comments with explanations
- 5280cf8 doxygen updates
- 5981d7c detail.h: auto get()
- e7016eb math.h: add more noexcept
- d7ac669 math-inlines.h: add static_asserts
- a1584b5 operators.h: heterogenous container operators
- b7498d4 reporter.h: remove verbosity_t
- 47e497b deferred-reporter-inlines.h: static_assert buffer size
- cc5e566 deferred-reporter: reference to location
- 4d0d7f4 micro-test-plus.h: add Doxygen config section
- 5db7865 runner.cpp: copy argvs
- ddfe9f1 type-traits.h: more cosmetics
- 29c2c82 type-traits.h: value*base* used consistently
- d34ce29 type-traits.h reorder concepts
- 52b9c16 add type_traits::printable
- 5189513 add is_op and checkable concepts
- aaadf34 add type_traits::any_op
- 1d0a231 detail.h: extract common binary*op* & co

## 2026-04-20

- 3ba1539 README update
- f1cd9c7 runner.cpp: validate reporter initialised
- 5fafa76 website update - no concepts ref yet

## 2026-04-17

- 98e0f4d website/doxygen updates
- 2edb5bb doxygen examples update
- 7434174 split exceptions.h and utility.h
- d3646d6 sample-test update ts
- 9897a58 doxygen comments updated
- f641190 copilot-instructions.md update

## 2026-04-16

- d1c27e2 tests: update platforms without exceptions
- fc71cf6 cortex-a72: noexcept
- 505edd2 compare-files.sh: reverse diff order
- aacfa73 reporter: confirm written output file.
- acc8fb1 platforms: add compare to qemu tests
- 17e52a5 compare-files.sh exit if missing files
- b41c0c1 cortex-m0: add compare test
- 9fb3604 reporter.cpp: fix double link on mingw
- 7e5f9b4 compare-files.sh update sed
- 6ce71a8 reporter-inlines.h print long double on mingw
- 95474b7 reporter-inlines.h print long double on mingw
- 0a9376e reporter-inlines.h print long double on mingw
- 57194e3 reporter-inlines.h print long double via snprintf
- 0405cb6 platforms cmake objects explanations
- 027fe7c top CMakeLists.txt re-work OBJECTS
- 83a0dc9 cmake rename xpack_global_common_options
- ca04d0f platforms compile options for micro-test-plus-objects
- f79e4eb adjust timings for testing

## 2026-04-15

- b87ae24 add clang coverage to native
- b646da4 unit-tests: add more tests
- 7eaa090 CMakeLists.txt: add micro-test-plus-objects
- 111067e project-functions.cmake: use micro-test-plus-objects
- e40981e common-functions.cmake: add coverage functions
- 840eba3 timings.h: add has_begin and has_end

## 2026-04-14

- 5c59ecb reporter-tap.cpp: fix suite summary
- 2a705db compare-files.sh update
- 7bbcf79 more #if defined(**GNUC**)
- d69cffc rename compare-files.sh
- 8f3ea5e compare-tap-files.sh updates
- 6a01d04 #25: implement --output-file for the human reporter
- 75074d8 reporter-tap.cpp cosmetise messages \n
- b28b3eb #25: implement --output-file for the human reporter
- 71215d3 fix own_index after sort
- e768f02 utility.cpp: avoid unsafe buffer
- 3c0efcd utility: add extract_file_name()
- 6ffb82b runner.cpp: rework sort without aggregate return
- 9a6e461 more #if defined(**GNUC**)
- 205a0e4 silence warnings
- ff4d28c reorder pragmas
- 4858d46 sort suites
- caef2b0 sort suites
- 43898b5 sort suites

## 2026-04-13

- 3536099 split unit-test

## 2026-04-12

- 88c6837 fix cmake a72 syntax
- 82a5dc9 tests-ci add a72
- 3a4abb7 tests TRACE buffer 512

## 2026-04-11

- 120d6c6 use -Og for aarch64 debug
- c1c8563 unit-test fix float tests
- 1dbc1fb tests/pacakge.json: bump deps
- e79e520 remove commented out pragmas
- 1f15f59 compare-tap-files.sh: support mingw pointers without 0x
- b615252 reporter-human.cpp: fix missing subtest begin
- 97a9cfd utility-inlines.h silence warning
- 6f8c883 rename utility-inlines.h
- 58d8b60 move doxygen to test-inlines.h
- aba22eb move exception functions to function-comparators-inlines.h

## 2026-04-10

- e654cd7 add more unit tests
- 05591ee add more unit tests
- 7485915 code-review.md update
- d1a6efd reporter-tap.cpp: use trace::printf
- 2b6c39a reporter-human.cpp: cleanup
- f5822a6 reporter-tap.cpp: use trace::printf
- 0f895d8 runner.h: do not include ctime
- 4ac2eed test.cpp: explain that subtests do not record the time.
- 2f206b5 test-inlines.h: explain why nullptr passed
- 25847e9 deferred-reporter-inlines.h: clear includes
- 97e63b2 reporter-inlines.h: fix explnation (nil) on linux
- 52233c8 test.cpp: clarify emplanation
- ea345bb runner.cpp: cosmetics (british english)
- b0cca8a reporter: simplify constructor verbosity\_
- f839318 fix trace::puts
- c724549 timings.cpp: add precondition assert
- aff7d92 tests/assets/tap update
- ffe7cbd compare-tap-files.sh update sed time
- ebce825 use stderr for warnings and errors
- fd109c2 use trace::printf
- 50f4d20 #if defined(MICRO_OS_PLUS_TRACE)
- 4f70a41 test-inlines.h: rename child_subtest
- de6a36e runner-inlines.h: rename child_suite
- a132531 remove commented out includes
- e531413 rename protected append*number*
- 5f72b25 runner.h: remove useless suite*index*
- 3112ede runner.cpp: avoid shadow exit_code
- a603afb rename parameters suffixed with underscore
- d8b721f remove tests code-review.md
- 2cb079b end protected with underscore
- ea4b203 test-inlines.h initialise unsed callable to nullptr
- c384d80 reporters flush before abort
- 49f5e2f utility.cpp: explain complexity
- cc4e200 runner.cpp: name ot "runner"
- d805891 reporter.h: remove unused verbosity_t
- dab4c34 include c++ headers
- 2661a41 reporter: explain why write_buffer_to_stdout is public
- 3300421 runner-totals += noexcept
- d0f8e85 reporter-human.cpp: write warning on stderr
- a924f5d argvs vector constructor with cast
- 142ef0d deferred-reporter.h apply the rule of five
- dd97f1d flush() also the output file
- 5942653 test abort() calls runner abort
- dee289c reporter.h: make flush() public
- 49c3c25 detail.h: ne* fix >= lhs*.epsilon
- 36ad478 comment out includes
- 39b739b test.cpp re-enable pragmas
- 0e86cdb split reflection.cpp and utility.cpp
- 859f4e2 comment out more pragmas
- a8c8629 cmake: show size for native

## 2026-04-09

- d23c1af enable tracing in native minimal test
- c1d824f add noexcept where needed
- 59a3c26 add time back to file tap reports
- 8642897 reporter: bring version back to info
- 670cda9 timings: rework with optional and uint32_t
- 5a51a06 move timings to suite & runner
- 16a35e2 compare-tap-files.sh: sed hex pointers
- 0360ddc unit-test: add missing description
- 0387ab1 move static*children_suites* to static_runner
- 0b12359 commented out cmake unit-test verbose
- da23740 fix printing long double
- 91d49a9 #24: reporter-human.cpp: use colour only if a tty
- 94fa902 Null pointers should be rendered as 0x0

## 2026-04-08

- c43dbff #23: add test code to compare tap files
- 971b706 tests cosmetics
- 3ca668a more consistent totals
- d61fdc1 #22: argvs as vector of string_view
- fa54491 platform README update
- 3f22c35 cosmetics "error:"
- 3e4c10e use --reporter human for unit-tests

## 2026-04-07

- b973f93 make totals & timings protected
- c7bf95c rename runner\_ to avoid -Wshadow
- 6084289 reporter operator<< forwarding reference
- b23e68b replace strncmp with string_view.starts_with
- a5db50b reporter-inlines.h cleanups
- 754bc05 type-traits.h more const
- 195f102 container_like requires const
- a04cfa9 remove redundant reporter::operator<<(char\* s)
- 1d1196e fix reporter::operator<<(const T& t) recursion
- a19af57 deferred-reporter-inlines.h silence warning
- 799dc0d improve deferred_reporter_base::operator<<
- 56a4831 detail.h replace get_impl. with concept
- a6369fb implement iterative math::pow
- d43e039 type-traits.himprove has_npos
- 8c2669d re-enable operator<< (const T& t)
- 3894fda type-traits.h cleanup value<T, Opt>
- 0c2a67c fix deferred_reporter_b char
- 8ec9b23 `requires_` / `requires_t` replaced with c++20 requires
- a913784 use std::is_base_of_v
- e6182a6 use std::is_convertible_v
- 9516a88 use concept container_like & other
- 7785b9a detail.h private members
- 6a28693 rename not\_.operand()
- 7bfee0e reporter operators consistently use append_number
- 6226989 silence warning in reporter
- 82fbfc0 detail.h cosmetics
- 8207330 remove more constexpr
- 241275c replace strrchr with string_view
- 1d510cb avoid problematic strncat in reporter
- 5c0e7c2 fix reflection::type_name()
- 4f720d2 use consteval in math
- 4e618fb use std::declval
- 321dc0d use c++ loops in runner
- ceeb3c6 fix redundant has*static_suites* guard
- 5892cba inline was_successful ()
- 722c9d4 use std::to_chars in reporter operators
- a967e64 non static epsilon
- 759017e add [[likely]]
- d58e613 switch sfinae to concepts
- 17448ba using verbosity_t
- a6711bd buffer\_.reserve(128)
- 04f20e5 optimise to std::to_chars
- f3c772c disable timestamps for subtests
- 5f7f8a1 remove duplicate name\_ = name;
- 5ece91a inline constexpr colors
- 469f7e3 #21: fix abort location
- d8a1599 #21: add location to runner.abort()
- af580c1 remove some unused methods
- 9503e4d change some methods to protected
- 137a487 add more const to methods
- 7b48b60 micro-test-plus.h remove top expect & assume
- 2453113 remove useless constexpr specifiers from methods
- e41e2c8 remove redundant name() from runner
- cf57e92 #17 fix more warnings
- e67e3e2 #17 fix more warnings
- 98e5c2b #17 fix more warnings
- 609bf05 #17 fix more warnings
- a9d34d4 #17: add --output-file

## 2026-04-06

- bcb18cf move verbosity processing to reporter
- e38f299 rename add*empty_line*
- edf3097 config.h cosmetics
- 53f1a7e Merge branch 'xpack-development' of https://github.com/micro-os-plus/micro-test-plus-xpack into xpack-development
- 15cc731 cosmetics
- 33e4753 MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
- 554c5bb update trace messages

## 2026-04-05

- 0df2ed3 update trace messages
- 143e563 use smart pointers in timings
- b6df491 store smart pointers inside children*subtests*
- 6629734 use smart pointers inside children*suites*
- 1d87188 runner.h: fix constexpr
- f2db8e2 make children*suites* an object, no pointer
- 06909b0 make reporter\_ a smart pointer
- 3c47909 make top_suite an object, no pointer
- 7d27fe5 make top*suite* a unique pointer
- 78338ca #19: re-work test objects hierarchy

## 2026-04-04

- 2ac0dce unit-test updated to new objects
- e5c13ec suite-test cosmetics
- 44425f7 cosmetics
- c867188 #20: rename human reporter

## 2026-04-03

- 0c8d363 suite-test silence warning
- 13e75fc reporter-basic.cpp cosmetics
- 6e921f8 #19 unify suites with tests

## 2026-03-31

- 3fb45b3 reporter: rename begin/end_session
- 03bfb73 rename runner & static_runner
- 0008c25 test: silence diagnostics
- c2d8356 disable trace in native
- 86ed61b warnings silenced
- cee7519 rename \*2 namespace back to micro_test_plus
- e35b654 remove the initial micro_test_plus namespace
- 1b0e26b major re-work, separate mt2 namespace

## 2026-03-24

- 26317ce website re-generate commons
- 75e93ab website: blog post release 3.3.1 published

## 2026-03-23

- e08c550 3.3.1
- 3e6dadf CHANGELOG: publish npm v3.3.1
- 5573d85 prepare v3.3.1
- f1be263 tests: add suite-test
- df22b28 #16: fix static inits
- 511f8cf re-generate website commons
- c700756 tests meson update usage
- 759051f move tests to sources

## 2026-03-22

- fd91598 website: blog post release 3.3.0 published
- a116185 3.3.0
- c412e55 CHANGELOG: publish npm v3.3.0
- 394c679 prepare v3.3.0
- 8d33c3e website update for tap
- 181b428 website/doxygen rewrites
- 14bea0a cli.dox update to tap
- 4a4f840 #9: fix empty line
- ae54b12 cmake cosmetics
- 3cb5a08 #10: fix not ok messages
- 2fda6fc #10: fix rounding

## 2026-03-21

- 1e2c980 empty .npmignore in tests
- 2242fd0 test-reporter-tap.cpp cosmetics
- a3ecec4 try timespec_get only on win32
- 7ba0701 try timespec_get
- 9ead310 #if defined(CLOCK_MONOTONIC)
- 4e9478c Revert "try -lwinpthread on windows"
- 951742a try -lwinpthread on windows
- 5bce849 #10: fix long long warning

## 2026-03-20

- f9c0293 Revert "#10: use defined(**linux**)"
- 574ff65 #10: fix duplicate struct timespec
- cbdc8ed #10: use defined(**linux**)
- 15a191d #10: show total time
- 3bae621 make runner default_test_suite public
- e25dbf3 #10: add elapsed time to suites
- 0139c5e test-reporter-\*.cpp plurals

## 2026-03-19

- 9258c55 cli.dox update
- 022cbed test-reporter: fix syntax
- cc95083 website update
- e4c6be1 #9: default tap
- 84b34d3 native cmake with explicit --reporter
- e35ad6a #9: functional test-reporter-tap
- 7aa70ac test-runner: add totals
- f6a2bc1 add begin/end_test
- 7d6f684 test-suite.h: size_t analytics
- 1e7a54c detail.h: reformat

## 2026-03-18

- 7bae711 add suite index
- 6619d3b default basic
- 5465c38 rename test*suites*
- c60d2b5 rename test_cases_count
- 459d10c #9: process --reporter=tap or basic
- 2c8cc51 #9: add a test-reporter-tap as a duplicate of base
- 122c76a #11: make the test_reporter_basic class final to avoid warnings
- d84d2b8 #11: extract test_runner_basic in separate files
- 75b8fb1 #11: move operator implementations back to the base class
- 096d136 #11: make the test_reporter an abstract class
- 8f20d22 #13: access the reporter via a pointer

## 2026-03-17

- 42e0810 website: blog post release 3.2.3 published
- b84b446 3.2.3
- aeda731 CHANGELOG: publish npm v3.2.3
- 7d877be prepare v3.2.3
- 7943290 package.json update
- d40573b settings.json update
- 6eaed82 re-generate website
- 6c53c08 re-generate tests commons

## 2026-03-15

- f785a0d re-generate tests commons with define-executables
- 28700b7 re-generate tests commons; xpacks*enable*\*
- 87c04ad settings.json update cmake defaultFormatter
- fa4719e tests: update to simplified platform aliases

## 2026-03-13

- 1df6029 package-lovk.json update
- c94b7cf re-generate tests commons
- b3ec2a9 tests meson cosmetics
- 4045da4 tests cmake reformat
- 42e6f65 tests add DO NOT EDIT
- 0c2c517 ad and use project-functions.cmake

## 2026-03-12

- 9f3eba2 tests infrastructure update
- 9270993 dependencies-folders use project folders
- a3d23f4 tests: project-definitions
- b080e20 \*-test: fix message > dependency
- acf22f4 cmake: move CMAKE_EXPORT_COMPILE_COMMANDS up

## 2026-03-11

- 861b4ca move xcdl-build.json
- 8e0540a re-generate top commons

## 2026-03-10

- f16de5e README update
- f68a8d9 package\*.json updates
- 3a0bd1a workflows update to 0.23.2

## 2026-03-09

- 85aca94 tests/package\*.json bump deps
- 9a7ccbf tests/package.json: explicit dependencies specifier & platforms
- fd40e7b try xpm install -dd
- e29a752 try xpm install -dd
- 3641e20 re-generate top commons
- a42b3d8 package\*.json update
- fc922bf test-ci.yml: bump deps
- 250ddb4 test-ci.yml: bump deps

## 2026-03-08

- 9356141 package.json cosmetics
- 4ffc072 website copyright 2026 update
- 6060eb9 tests/package.json: bump deps
- 42a0eaf silence warnings

## 2026-01-19

- 27d753f package.json update ctest --test-dir

## 2026-01-18

- 7f5dd8c package.json: group deps releases
- 8ac2c5b package.json compute latest release

## 2026-01-17

- 2ac5ca4 package.json update with templates

## 2026-01-16

- efd0b74 package.json: update inherits
- a5ad31e package.json: update toochain names
- a6e7fb6 package.json template actions

## 2026-01-15

- 92a7d78 settings.json: configure meson false

## 2026-01-06

- 489d204 workflows update
- c149bda package.json 3.2.3-pre
- 5f2f0cc CHANGELOG update
- dafef2a copyright reformat following cmake
- c1bb7e4 Copyright 2026
- 9543dc5 package\*.json bump deps
- cdb7c12 CMakeLists.txt reformat
- 55d1500 add .cmake-format.yaml
- b127ac5 settings.json update
- 578d545 include: fix doxygen
- 710c8ff tests rework & reformat cmake

## 2025-11-20

- c1459d7 npm --prefix
- 414f4da npm --prefix
- 5460362 silence warnings
- d2032d5 replace auto -> source_location

## 2025-10-07

- f099ea9 update copyright notices

## 2025-08-23

- 6e09fe5 tests/package.json disable clang 15
- caba436 tests native rework
- 1ba174e tests top meson.build
- e6ce35c tests global-definitions add minimal test
- db8a14b no need for top config.h
- 1c926ff move tests to folders
- 858b92d move code from test-main.cmake to top

## 2025-08-22

- 8dbfa79 fix typo

## 2025-08-08

- ab3b7ab website update Generated via
- 7d69688 website update Generated via links

## 2025-07-30

- 31ed4de add doxygen back to git

## 2025-07-29

- 621040d website update sidebar
- 53124cc website update without The ... Reference

## 2025-07-14

- b878ad9 website update for tree tables

## 2025-07-10

- 38442a1 website/package.json update d2d config
- fb828ce website package.json update link-helpers
- e9132f8 website update for doxygen2docusaurus

## 2025-07-06

- 897d07e website reorder index without ~
- f571fce website rework index files
- 9da3278 website update with treeEntryName
- ea87f50 fix broken links in test/md
- be89733 publish-github-pages.yml update
- 48f427d website update
- b016885 website/doxygen update
- 25fddfa reflection-inlines.h update doxy metadata

## 2025-06-19

- afa713d publish-github-pages without doxygen
- a65e1f8 website package.json cleanup
- d0fbaf3 website re-generate as html

## 2025-06-16

- 4593547 website docs api update
- 99e639a website doxygen xml update
- b8132ed website doxygen update

## 2025-06-11

- c2f2863 website update

## 2025-06-06

- c9ae57b website docusaurus.config.ts comment out faster
- 3e913cb website docusaurus.config.ts enable faster
- e8e05e4 website package\*.json add faster
- b518e57 website docusaurus.config.ts revert to using preset
- c43d1a9 website package\*.json 3.8.1
- 2a5c0f3 website regenerate
- e66973e move @mainpage to doxygen folder

## 2025-06-05

- 4154858 update package\*.json
- 3c7a543 website package\*.json update
- 16888c7 website add doxygen/xml
- e37c3fb website update config and docs/api

## 2025-05-26

- 1ede877 website re-generate commons 1.14.0
- a6be438 package\*.json update
- 35df5ab re-generate commons doxygen 1.14.0

## 2025-05-24

- d29b5dc website doxygen cosmetics
- 8f90d06 website re-generate docs api
- efe9e95 website re-generate commons
- a1f8d68 website re-generate docs api
- 1b170fd package\*.json bump deps
- c8c0efd add Docs wrapper

## 2025-05-23

- bebad3d website re-generate commons runOnStart
- 9861c51 re-generate top commons (no generate-doxygen)
- 3bfb114 fix topics.h H1

## 2025-05-22

- f0fa84f website re-generate docs api
- 22af156 type-traits.h fix warning
- 6ca4410 website re-generate docs api
- 054114e code fix doxygen errors
- ee4beec website re-generate docs
- dd2d262 code update doxygen for files & folders
- 8f4a2ad cosmetics
- 2db30dc move \*-inlines.h to separate folder
- 08065b2 code split inlines into separate files

## 2025-05-21

- 6ace7d6 move throws & nothrow to inlines
- 00a29fb move function comparators to inlines
- 8b05ae6 test-suite-inlines.h fixes
- 38399a7 move expect & assume to inlines.h
- cf74ace move include inlines to test-reporter.h
- 62f00e7 move test_suite::test_suite to separate inline
- af7231f doxygen cosmetics
- a0aba61 website re-generate commons
- 8278aec re-generate commons
- 746e991 website cosmetics licenses/mit

## 2025-05-20

- 2209a6d website package-lock.json update
- 13daa54 website re-generate commons, bump deps
- 9b80736 website re-generate doxygen docs
- 44ee8dc doxygen updates

## 2025-05-18

- b4716ec re-generate top commons
- e897e3c tests re-generate commons
- 2a2d633 detail.h: fix doxygen
- 52c5636 website package.json bump deps
- 925e2c7 publish-github-pages.yml update
- 867fb72 website package.json bump deps
- dbed476 website package-lock.json update
- 7425379 website package.json use github deps
- 64825e3 website package.json bump deps
- 387961f publish-github-pages.yml update GITHUB_PATH
- 0fc37eb publish-github-pages.yml update build
- 590a68b website update
- 664e2a6 doxygen topics add ##Description
- 526405d literals.h replace @deprecated with @par
- 06b1ac9 website reorder @details
- fd2f81c sources move @details at the end

## 2025-05-17

- 987479c website updates
- 329fcc9 explicit void and cosmetics
- e1d4b86 website namespaces with full name
- 500f2e0 website docs api update with full doxygen metadata
- 64d1b71 website doxygen configuration split into separate files
- 44b464a source code full doxygen

## 2025-05-16

- 4199543 use @code/@endcode
- 42e258b website update with fully documented detail.h
- 2822be3 detail.h fully documented
- c75d146 website update doxygen
- 499b31f doxygen rephrase in british english
- 1639668 website faq update
- b70fef2 website update for moved headers; add documentation for folders
- 88a3163 move headers to include/micro-os-plus/micro-test-plus
- 6f6144a website rename doxygen topics files as .h

## 2025-05-15

- d2b8232 website @file @namespace updates
- 8706045 doxygen @file @namespace updates
- 142c64e website update
- 68c26b1 website rephrase all project files
- 20d2371 website api update topics
- 16fdd97 website update docusaurus config, sidebar and menu
- 8503518 website update topics and user's guide

## 2025-05-14

- ef6cb40 website re-generate commons
- ea4ed37 doxygen REPEAT_BRIEF = NO
- 3d93c1d website re-generate commons
- e884791 website move docusaurus jsons to top

## 2025-05-12

- 835d5e5 website fix index template parameters
- c6f4b98 website sort members
- 03ba6ee website update () for functions & Constructors sections
- f5050c0 website rename top topics
- 3ffd64a website update indices

## 2025-05-11

- bf33de1 website: add docusaurus-config-api-menu-dropdown.json
- 02f9451 website move folders index to files
- c903886 doxygen fix @par empty line

## 2025-05-10

- 80283a5 website update for default constructors & destructor
- c4c31b3 website: add redirectsOutputFolderPath to plugin
- 4350132 website update for @par Example
- b394f2b add an empty line after @par Example
- 99967a3 website update pages h1
- b7470b3 website namespaces add fqn

## 2025-05-09

- f42a5bf website update EnumerationListItem & Reference

## 2025-05-08

- a692dc5 website update enumeration
- 654a4ae website update docs/api

## 2025-04-30

- e54b9b8 add website api pages
- f302a91 update doxygen metadata

## 2025-04-25

- 75cfaa6 website re-generate commons

## 2025-03-16

- e9f4d19 website: re-generate commons
- b80ae62 website: blog post update

## 2025-03-15

- ed2ee93 website: blog post release 3.2.2 published
- 32950dc 3.2.2
- 10cf3b9 CHANGELOG: publish npm v3.2.2
- 234724a prepare v3.2.2
- 771e589 re-generate commons

## 2025-03-14

- 1475002 re-generate top commons
- 464a485 re-generate top commons
- 632bcc8 publish-github-pages update
- d89c851 website: blog post release 3.2.1 published
- c70d3e0 3.2.1
- 60103cd prepare v3.2.1
- 8daa820 website: update post
- 703dcf9 website: re-generate commons & blog posts
- 564f37f tests: re-generate commons

## 2025-03-12

- a7dc192 re-generate commons with long description
- ae24148 website: re-generate commons
- 0c97d4e website: re-generate commons
- 7c01414 website: re-generate commons
- 31d25ac website: re-generate commons

## 2025-03-11

- e0db831 website: re-generate commons
- e31417b website: re-generate commons
- 0350fa2 website: re-generate with longer descriptiveName

## 2025-03-10

- f514bf6 website: re-generate commons
- 3ba95c6 website: re-generate commons major

## 2025-03-05

- 30197db website: green

## 2025-03-04

- 57afe72 website: fix pathname:// links
- 24e28c1 website: getting-started rework
- 73abd63 config.doxyfile: disable XML for now
- af1383f docusaurus\*: use pathname:///
- d963f3d docusaurus\*: accept broken links
- ba6a4e9 \*redirect.ts remove '/reference'
- d71fa22 re-generate commons
- 2cc8dd6 website docusaurus test

## 2025-03-03

- 17fc2c5 doxygen/.gitignore

## 2025-03-02

- e233776 website: move doxygen files to separate folder
- 32ff366 tests/package-lock.json update

## 2025-02-28

- 435d61f copyright notices cosmetics
- c228aef tests: re-generate commons
- d178ebe re-generate workflows
- 5f78801 test-all: fix clear cache syntax

## 2025-02-27

- 9a6ecf5 test-all: fix clear cache syntax
- 5a78a81 test-all: fix clear cache syntax
- df341b9 test-all: fix clear cache syntax
- 4c56913 test-all: clean xPack cache
- 76606cb re-generate workflows
- 6472bc0 tests/native/meson -rtlib=compiler-rt
- e5bed09 tests/native/cmake remove duplicate -stdlib=libc++
- 5425929 tests/package.json: add native-meson-clang to test-ci
- 9babed3 tests/native meson -stdlib=libc++
- 1fe540d reflection.h: unsigned int line

## 2025-02-26

- 4d46b66 package.json fix action test
- c76db36 package.json add git-pull-helper
- cac8c46 tests/package.json: bump helper
- 8274320 tests/package-lock.json update
- db0f79a re-generate commons
- 052057d workflows: update

## 2025-02-25

- 808db36 workflows cosmetics
- 6531845 meson/common-options: fix link_args
- 241c368 workflows: npm -C
- b867523 workflows: &&
- 2636562 workflows: remove windows 2019
- 8aca778 tests/package-local.json
- 9650766 re-generate commons
- 34695b1 xcdl.json update

## 2025-02-24

- cca99a3 package.json: update topConfig
- 6b926ad package.json update
- 66412e3 package.json: add topConfig
- eab469f re-generate workflows
- 5fc7f95 test-ci.yml: fix install-ci
- de675ce test-ci.yml: fix install-ci
- cf02869 rename test-ci.yml
- 8a8431d ci.yml update
- 94d8603 tests/package\*.json: bump deps
- 05e42b2 platforms/native: update RPATH
- 00c2a30 publish-github-pages.yml: update from npm helper
- 5a1770c website: update for node_modules
- 328857c re-generate commons
- a8a661e package\*.json: use npm & extract xcdl.json
- d3c7750 silence documentation warnings

## 2024-11-21

- c3847f1 rename xpack-development
- e7b1d9b rename MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
- 459143c package.json: add cdlComponents
- ffaf7b1 tests/package.json CMAKE_MAKE_PROGRAM only on windows
- 5cf103a update copyright notice

## 2024-02-14

- a1b201a tests/package.json: add short win path to meson
- 3269a0e tests/package.json: explicit CMAKE_MAKE_PROGRAM

## 2023-12-26

- 7c113ee README update
- b534088 credits.md: remove macstadium.com opensource
- 11ffc8b website/pages/home.md: cleanup dummy links
- acefd31 publish-github-pages.yml: bump doxygen 1.10.0
- b24ad6b cmake cosmetics

## 2023-12-06

- 7a2ee88 3.2.0
- 2a6abf2 prepare v3.2.0
- 90963ce micro-test-plus.h cosmetics
- c57c46e literals.h: silence clang deprecation warning
- f776b18 doxygen metadata: add @headerfile
- 94ff7d7 website: use to\_\*
- 9d4f8bb tests/sample-test.cpp: use to\_\*
- 24606d7 literals.h: add to*\*, deprecate *\*

## 2023-12-05

- 76ddc99 user-guide.md: use mt::
- 86adedf doxygen metadata: use mt:: in examples
- 71db099 tests: use explicit mt::
- c508d4f testing.md: remove reference to test-all.yml
- 11a1f31 testing.md: update
- 1ee57a8 testing.md: fix typo
- 749e2d6 testing.md: add clang 17
- 221a630 rename xpack-development
- 06419e5 tests/package.json: enable gcc11
- 03cb2ed tests/package.json: bump deps

## 2023-12-04

- ebe7e55 package-lock.json updates
- 17e8859 tests/package.json: add clang 17
- 75e585a micro-test-plus.cpp: silence warning for clang 17

## 2023-11-30

- b4ff766 website/package.json: #v2.3.1
- 19a43d6 testing.md update
- 822e464 rework tests with platforms sub-folder
- 2aef49a website/package.json: explicit #v2.3.0
- 313fd41 website/package.json: explicit #2.3.0
- 80d0fe8 testing.md: updates

## 2023-11-29

- 2227c94 3.1.2
- 552865e prepare v3.1.2
- 993d0f7 testing.md: updates

## 2023-11-28

- 21393a5 ci.yml cosmetics
- f1488f8 package.json: bump deps
- ffd542a cosmetics
- 8d6ca4f meson cross.ini fix cpu
- 57bd3f0 explicit --cpu for risc-v qemu
- b3dc45b meson: remove redundancy
- d9ea278 Revert "home.md temporarily disable anchors hack"
- 8483aff home.md temporarily disable anchors hack
- 78b2426 config.doxyfile: enable sitemap.xml
- eb53997 maintainer.md updates
- a4d0807 README update
- 43fadfa package.json: use latest commit theme
- c5d87d6 home.md: remove ci & web badges
- 93bb6e6 native/cmake: add listing
- 45557b3 meson.build >=1.3
- e16d922 meson_options.txt update
- 261d337 move platform-native/include/.../platform.h
- feedf64 move enable_testing() to top

## 2023-11-27

- f0713ca home.md: re-enable explicit links
- ab49151 home.md: temporarily disable explicit links
- f45769a home.md: update dummy links
- 6f14fe4 testing.md update
- 4679b05 testing.md update
- 9cb0e18 testing.md update
- d1a4af5 testing.md update
- 12ee949 testing.md update
- 7e2d82f testing.md update
- a354eec testing.md update
- faa17f6 testing.md update
- 616bb45 testing.md update

## 2023-11-26

- 206e8a1 website/README update
- c8e45ef website/package.json update actions
- e2c9b2d maintainer.md: fix twitter
- d53b93c maintainer.md: fix twitter
- 94dd8a6 maintainer.md: shorten twitter url
- cc8d0cb testing.md: fix links
- 5b55edc home.md: fix url
- c2c7bac home.md: add dummy links to static pages
- d52ff26 markdown use @page
- 6eaa27b user-guide.md update ISTQB
- 2f357ce package.json: update homepage
- 32ad598 package.json: update
- 6e41039 package.json: add check urls
- fd31269 maintainer.md: update twitter url
- 7954a43 install.md: update
- a49c1c6 install.md: show tree
- ab75189 .npmignore website
- c230d2d maintainer.md update
- db8a023 tests/package.json update
- 0156bf3 README update
- f03584e package.json: bump meson-build

## 2023-11-25

- 509ff38 home.md: add Manual Pages
- eed0475 tests/package.json: add install/tes-latest
- d2a23dd tests/README update
- a755996 maintainer.md: update
- 17866f0 tests/package.json: add more selected
- 593b361 tests/package.json: fix syntax
- bbe15ab tests/package.json: fix syntax
- 1456260 tests/package.json: re-enable some tests
- c8f7c5a tests/package.json: reorder actions
- 68626be tests/package.json: fix install-selected
- 079df5c tests/package.json: cleanup actions

## 2023-11-24

- 3aba98d website/maintainer.md update
- 42f60eb pacakge.json: disable some meson
- fed45b3 package.json: add test selected
- 265495e topics.doxyfile: examples to command line options
- 4c5311e topics.doxyfile: rename group micro-os-plus-micro-test-plus
- 7a71772 add minimal-test.cpp for native builds

## 2023-11-23

- 7d12935 user-guide.md: update
- 5699ed8 user-guide.md: update
- 31de282 user-guide.md: update

## 2023-11-22

- e3f4a8c user-guide.md update Rationale
- 79a3a04 home.md: fix link
- d4dbd85 rename some groups
- fb83f9b user-guide.md update title
- e20730a user-guide.md: add c++ api
- 3d05656 rename some groups
- 599121b install.md cleanups
- f05590a rename user-guide.md
- 8b3ce4c rename doxy groups micro-test-plus-\*
- 03225e6 topics.doxyfile update mtp-top
- 2b83889 home.md update
- cb4b8b8 rename 'integrate'

## 2023-11-21

- d87b685 home.md update
- e15fa64 rename Integration Guide
- 6e2c567 home.md update
- 0419764 package-lock.json
- c83e2c2 rename pages
- 3b44a8c doxygen metadata
- b7f2791 re-format

## 2023-11-19

- 4315e9c website README
- e457fd2 config.doxyfile: include src && include
- 123bb53 type-traits.h: avoid potential recursive error
- 0fe11ff developer.md: update
- 557bbdd home.md update
- c676d6f change-log.md update
- 198fadd home.md update
- 496c308 developer.md: update
- 9fe24b4 workflow update
- c955d3d home.md: update
- 3ff6614 home.md: update
- d871a67 home.md: update
- 6151bf8 add DoxygenLayout.xml for the GitHub link
- 38f101a package.json: add link-deps

## 2023-11-18

- 3d67a79 developer.md update
- a0bdd9a home.md update
- 6df7e90 maintainer.md update
- b096248 workflow update
- 5f700a5 home.md update links
- 9186c97 workflow update
- 5e5cf7a workflow update
- 3e784b0 workflow update
- 844cee5 workflow update
- 01ce2a2 workflows update
- 36d36d4 add website
- 440701a README update
- 311c7ec package.json: remove some redundancy

## 2023-11-17

- 933ea5c ci.yml: bump xpm to 0.18.0
- 04ad5c4 package.json: update npm actions
- 6c0f0e5 tests/package.json: use xpm run --all-configs

## 2023-11-16

- ed8b3fd ci.yml: fix actions
- 1fc00fc ci.yml: update; add meson
- 63489b6 .vscode/settings.json: ignoreWords
- e4bfe8e package.json: gccXX for cortex & riscv
- 6003397 platform-\*/meson.build: --no-warn-rwx-segment >=12

## 2023-11-15

- 801a305 platform-options.cmake: --no-warn-rwx-segment >=12

## 2023-10-29

- f0f6af7 package.json: disable clang 13/14 on linux
- 8bc2250 disable meson on macos (due to ldd --version)
- 8d6ea94 enable -no-pie for macos gcc

## 2023-10-26

- c124b2d native/cmake cosmetics
- bfd6ef6 native/meson: informative MICRO_OS_PLUS_DEVICE_NATIVE
- c076a8f cmake: enable \_POSIX_C_SOURCE
- 1d1054b meson: add asserts
- 111a1c0 native/cmake: rename _local_\*
- 704cf89 verbose messages cosmetics

## 2023-10-23

- f175fe8 cosmetics
- cc55c0a add platforms m3 m4f
- 8949702 tests/package.json: bump deps
- bd28efb cmake: validate xpack_platform_compile_definition
- 4de3322 meson rework
- 95ec308 move cmake \_compile_definitions to dependencies

## 2023-10-20

- ce36d69 cmake renames & common-main.cmake
- d9553a2 cmake cleanups
- 54accd7 cmake add explanations
- b59fbac rename micro-os-plus::common-options

## 2023-10-19

- 0638af7 tests/package.json: remove clang12
- be8ea3f README update
- 5f53e2c native/cmake: no need for statics
- 71368ca native/cmake: add libc++ to link
- ecb5705 native/cmake: compute -rpath
- 3a4535b tests/package.json: bump deps
- e0f050c ci.yml: test m0, m7f, rv32imac
- b32f4bd tests/package.json: bump deps
- 21f948b .vscode/settings.json: ignoreWords
- 71bc722 cleanups
- 94d507f rework meson

## 2023-10-18

- 785704e rework/simplify cmake
- fc475bb add more cortex & riscv platforms
- 4bf3531 package.json multiple toolchains
- a804a2e .vscode/settings.json: ignoreWords
- cedaed9 meson: add xpack_tests_folder_path
- 0227c10 cosmetics
- fdca222 -Wl,--no-warn-rwx-segments

## 2023-10-17

- 9ddcdd6 fix typos
- c1e7f17 silence warnings
- b8e417f literals.h: include cstdint

## 2023-10-13

- b9e132b package.json: bump deps
- 60d5ab3 meson.build: add check: false

## 2023-10-12

- a38e3d2 README update
- 852bfac package-lock.json update
- de6024c tests: fix paths
- 07a8b87 split tests/package.json
- 7c6a7eb ci.yml: non-sudo npm install
- 750e4ff ci.yml: try non-sudo
- 26f4594 ci.yml: bump deps
- 37a16d6 README update
- 707fbc5 package.json: update description
- 39d328e package.json: update scripts
- 90b83f3 package.json: add del-cli to devDeps

## 2023-07-14

- cc2f4b7 ci.yml: xpm 0.16.2
- 0c93537 README updates
- 725da90 tests/CMakeLists.txt cosmetics
- 03de509 package.json: cosmetise urls
- 36b27c9 package.json: minXpm 0.16.2

## 2023-06-04

- 0ac4fd5 ci.yml: bump node 18
- 650e786 ci.yml: bump matrix.os
- 8f058ed package.json: build-helper-xpack#xpack-develop
- 28f809c update for xpacks/@scope/name
- 6d27fb8 ci.yml: bump xpm 0.16.1
- 30e6aa3 remove --quiet

## 2023-06-03

- 4d446bb lower case ci.yml
- 0be4b56 package.json min 0.16.0
- 064eb46 lower case ci.yml

## 2023-05-08

- 8719abe .npmignore update
- 843c811 READMEs updates
- c1fb3e9 README updates
- 46bb468 meson.build cosmetics

## 2023-02-18

- 5eb637f README update
- 6894005 README update
- f5db7d7 README update

## 2022-08-16

- cc2699b package.json min 0.14.0 & defaults
- 9439094 CI.yml: explicit xpm version

## 2022-08-04

- a0739bb tests/cross.ini: add link to cpu-families

## 2022-08-03

- b1b8b28 README updates
- 965008d .vscode/settings.json: cmake.ignoreCMakeListsMissing
- ffb029c .vscode/settings.json: makefile.configureOnOpen

## 2022-08-02

- fa3cd23 READMEs updates

## 2022-07-30

- ceb6702 test-runner.cpp: conditional verbosity
- 80a0d20 3.1.1
- 8f35eb1 prepare v3.1.1
- 41d0acf update mps2 config
- 7c4cf61 #7: package.json: use inheritance
- 736a885 bump deps
- 6221d1f #6: remove STM32F4DISCOVERY test
- b080101 test-runner.cpp: conditional verbosity

## 2022-07-28

- ec67074 CI.yml do not trigger on tags

## 2022-07-25

- af5ae81 package.json minimumXpmRequired

## 2022-07-12

- 2b15c56 CMake: xpack_display_greetings() with arg
- 4459cc9 package.json: bump deps

## 2022-06-04

- v3.1.0
- b8994fb revert sections.ld

## 2022-06-03

- 1e30b5f tests: update for sections-flash.ld
- 0e434ea test-runner.cpp: show FP only for non-native

## 2022-04-19

- 3.0.2
- cd697a4 README reworks

## 2022-04-10

- d53ee24 package.json: bump build-helper 2.7.1

## 2022-04-07

- b43ce71 test-all.yml: remove Raspberry Pi OS test

## 2022-04-05

- 3.0.1
- d8f24e6 #5 add parametrised test suites

## 2022-04-03

- c3053d5 3.0.0

## 2022-04-01

- a944962 test-reporter.cpp: use check marks for suites
- de8065f add support for unused main test suite

## 2022-03-31

- ab6a3d5 try parametrized test suites; not ready
- 3eb96f7 sample-test: explicit namespaces

## 2022-03-28

- 0b8ab47 launch.json: --verbose unit-test
- aa405f5 test-reporter minor rework
- c5a6e54 implement assume() with the same deferred_reporter
- 4906cd5 test-reporter: add output() method
- db00b7f add reported\_ and run()

## 2022-03-27

- 11bcfd1 bump build-helper 2.6.3
- 5afa470 CI: bump clang13
- 3020ffe optimise deferred reporters

## 2022-03-26

- d8b9071 revert to build-helper 2.6.1
- 602d5d8 implement expect() << "message"
- 14ce153 package.json: meson platform toolchain files
- 367b706 unit-test.cpp: fix \_\_xx warning
- 3ec0a21 add clang13
- 356f2f9 package.json: bump cmake & meson

## 2022-03-23

- 255d4e5 README updates
- c837032 package.json: bump build-helper 2.6.2
- 49a3129 package.json: bump gcc 11.2.0-3.3
- 568d799 revert to interface library

## 2022-03-21

- c3729b8 process_deferred_begin
- 601c428 unit-tests fix messages
- 7340d7b printf string_view content
- 0a5bb6b test-reporter cosmetics (.)
- 4871095 colors as const char\*
- f9c25c8 meson: update for static library

## 2022-03-20

- 79d72b2 README add Getting Started
- 8bb653f constexpr evaluate*and_report*
- c993275 reorder initialize()
- ebfb155 remove redundant pass()/fail()
- 03cc86d test-runner: argv[] cosmetics
- 3904bcb #pragma cleanups
- 7fe3bfd group several small \*-inlines.h together
- 11fe6e8 add utility namespace
- 065824a unit-test: add static checks
- 48faa97 unit-test: add reflection::type_name() test
- 85aec05 unit-test: silence warning
- 7342f2c math.h: silence warning
- 4aeaa0d reflection: fix type_name()
- 7d6bd77 reflection.h: fix clang non apple
- 02eda65 reflection.h: warning/error in type_name()
- c5ab1d2 launch: add (gdb) native-cmake-clang12-debug

## 2022-03-17

- 01e6a21 unit-test.cpp: rename tests
- 327441d implement different verbosity
- 904e3ff remove trace in eq\_

## 2022-03-16

- 116571d bump build-helper 2.6.1

## 2022-03-15

- d15b203 change to static library
- ad94a46 remove dependency from diag-trace, use printf()
- 9d387c8 reporter: disable unused generic <<
- eebde5f reporter: rework constant suffixes
- b43d2b0 reporter.fail print value only if is_op_v
- dca5409 literals.h: add comments
- d9021c4 sample-test update for new README examples
- df5d8b5 update README and docs
- cd3f97d split detail-inlines.h

## 2022-03-14

- f64083c revert from operators to functions
- 3ec0454 unit-test: add logical & operators
- d0d689a unit-test silence -Wdouble-promotion
- a635d1a docs & cosmetics
- f346a7a rename Callable_T
- ed9d0f2 .vscode/launch: add unit-test
- dc6ccca remove unused pointer \_and(), \_or(), \_not()
- 67e2c43 fix meson -Wno-used-but-marked-unused
- 120c675 -Wno-used-but-marked-unused for clang on windows
- a6fee32 CI install --quiet
- 7e67230 add -Wno-missing-include-dirs to build
- b059c71 silence -Wmissing-include-dirs for GCC too
- 263b87e silence clang -Wmissing-include-dirs
- 1e8fc05 cosmetics
- 285a86a rework #includes
- 52fc562 split test-reporter & detail
- 17b0e3e split test-runner.h
- 62c7539 split inlines
- 2256fbf rename type-traits.h
- adc648e enable -Werror for native
- 037c767 split test-suite.cpp
- a80ea1a test-suite invokes reporter
- ce4c241 split test-suite.h
- a4a262a cleanup print_expr declaration
- 4b1984c split test-reporter.cpp
- e74786e split test-runner.cpp
- e4c7ed4 literals add docu
- 2f5efdd move casts to literals.h
- b1a0b55 move struct value to type_traits
- a9ec726 split literals.h
- bd64244 more type_traits moves
- 5a98f64 remove unused struct type\_
- 8176edc move op & \_constants to type_traits.h
- 658bf72 silence warnings
- 8407e38 fix type_traits guard

## 2022-03-13

- 1d5e4a9 docs
- 00e26c1 separate test_reporter implementation & inlines
- 7700eee rename Other_T
- 1c760ba split type_traits.h
- 2d7d4e8 split math.h
- c6b33c0 include source_location in reflection.h
- 149bbf5 rename Xxx_T
- ccd6482 split reflection.h
- 33390a4 remove deprecated expect_equal()
- cf4831a remove unused operators
- 33e84e9 add operators
- 63714b9 unit-test cleanup
- 51bb43c use evaluate*and_report*()
- 35a1ad1 unit-test: expect() without message
- 4cbe008 add explicit \_not \_and \_or
- b36dfa6 move to detail::assertion
- 6dac36c README: mention string comparisons
- 8d04508 unit-test: cleanups & comments
- 5b2153d unit-test: check default messages
- eef5709 sample test pass() message
- cfd924d sample-test: include string_view
- 3968eef add @brief and comments
- 48ea51e reorder and cleanup operator <<
- 52e2fbc simplify trace eq\_ messages
- 1d63119 provide a default for the message
- db9ae66 add type suffixes when displaying scalar values
- 406d48e add genuine_integral_value{}
- 8fb68ae cosmetics
- 18163a0 unit_test major rewrite
- e9e3fa2 sample-test: use string_view
- ddcd2a2 cmake cleanup
- 86996ed cmake xpack_create_hex
- ff53277 cmake add SIZE
- a34a283 cmake add report SIZE

## 2022-03-12

- f657ba0 add literals & more types
- f1676c1 more flush
- 357aefb rework operator<<
- 9250199 add more trace::printf
- fd7cf12 silence warnings
- ee30f22 more flush()
- d8e8900 add assume() with abort
- 646d374 add runner.name()

## 2022-03-03

- 3f84859 consistent copyright notices
- 278aff5 Add reference to boost license in copyright notice
- 28b5887 README: update for v3.x
- 2419718 add boost license
- 4e02d9d meson cosmetics
- 6ed18d2 package.json: native only on darwin
- d416cb3 quiet installs
- f93be58 package.json: remove gcc8
- 8d468c5 rework cmake & meson
- 687072c silence warnings
- b2bf818 sample-test: fix check args
- 2cf994c sample-test: silence warnings
- 6aed55a unit-test: temporarily disabled

## 2022-03-02

- 7117f36 launch.json: update
- b9bdb0f sample-test: rework with new comparators
- 8f0bc1f rework based on boost ut
- 58c0ba8 native/config.h comment \_STDERR

## 2022-03-01

- db86cd1 add test_suite

## 2022-02-28

- 1120ed7 migrate to non-class functions

## 2022-02-27

- b3c12ab C++20
- c694f49 MICRO_OS_PLUS_TRACE
- f43a1ab platform-native/config.h: TRACE buffer 500

## 2022-02-19

- v2.3.0
- 94b340c use nested namespaces
- f921bf0 sample-test: cleanup globals
- 66df97e add support for test-all
- f6c19d2 cmake globals add -fdiagnostics-color=always
- 28efe4b add parametrised tests and combinatorics
- 560b678 add run_test_case variadic template
- 436a1ae deprecate run_test_case(func, name)
- 0a6a46b add start_test_case()

## 2022-02-18

- 5d0e9be package.json bump helper
- 69d6dec rework expect_equal with templates

## 2022-02-16

- 9d97cb1 meson: remove utf-8 chars

## 2022-02-10

- 776845a .c\* include <micro-os-plus/config.h>
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
- 4bee003 cmake globals -flto for release
- c2c7972 package.json: bump devices-stm32f4-extras
- 6139edb meson: disable -flto for clang on linux

## 2022-02-04

- v2.2.0
- 18219ef package.json: bump deps
- d30ea7d updates for device-\*cortexm
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
- 6f55a37 package.json: rename dependencies to device-\*
- fde47e6 package.json: move toolchain files to folder
- 041c252 cmake: rename platform-qemu-mps2-an386
- 1230c9b cmake: update for devices-qemu-cortexm
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
