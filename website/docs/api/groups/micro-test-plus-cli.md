---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/groups/micro-test-plus-cli
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# The Command Line Options Reference

<p>Options for controlling test output verbosity at run-time.</p>

## Description {#details}

<p>Options for controlling test output verbosity at run-time.</p>


<p>The µTest++ framework provides flexible command-line options to control the verbosity of test output, allowing users to tailor the level of detail to their specific requirements and workflow.</p>

<p>By default, the reporter presents detailed results only for failed test cases, while successful test cases are summarised in a single line, indicating the total number of passed and failed checks.</p>

<dl class="doxySectionUser">
<dt><b>Example</b></dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">test 1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      Start  1: minimal-test</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1: Test command:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/minimal-test</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">"one" "two" 1: Working Directory:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1: Test timeout computed to be: 10000000</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1: Built with clang Apple LLVM 15.0.0 (clang-1500.0.40.1), with exceptions.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1: • Minimal - test suite started</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1:   ✓ Check various conditions - test case passed (2 checks)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1: ✓ Minimal - test suite passed (2 checks in 1 test case)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"> 1/12 Test  #1: minimal-test .....................   Passed    0 sec</span></span></div>

</div>


## Verbosity


<p>To adjust the verbosity, the following command-line options are available:</p>

<ul>
<li><span class="doxyComputerOutput">--verbose</span> – display all expectations, regardless of outcome</li>
<li><span class="doxyComputerOutput">--quiet</span> – display only the test suite totals</li>
<li><span class="doxyComputerOutput">--silent</span> – suppress all output and return only the exit code</li>
</ul>

<p>These options enable developers to focus on the information most relevant to their needs, whether that is comprehensive diagnostics during development or succinct summaries for automated builds.</p>

<p>The examples provided illustrate the output produced in each mode, demonstrating how µTest++ adapts its reporting to support professional and efficient testing workflows across all files and folders.</p>

<p>The source code for this test is located in the <span class="doxyComputerOutput">tests/src/minimal-test.cpp</span> file.</p>

### Verbose mode


<p>In verbose mode, the µTest++ reporter provides detailed output for every expectation, irrespective of whether it passes or fails.</p>

<dl class="doxySectionUser">
<dt><b>Example</b></dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">test 2</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      Start  2: minimal-test --verbose</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2: Test command:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/minimal-test</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">"one" "two" "--verbose" 2: Working Directory:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2: Test timeout computed to be: 10000000</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2: Built with clang Apple LLVM 15.0.0 (clang-1500.0.40.1), with exceptions.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2: • Minimal - test suite started</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2:   • Check various conditions - test case started</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2:     ✓ answer is 42</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2:     ✓ condition is true</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2:   ✓ Check various conditions - test case passed (2 checks)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">2: ✓ Minimal - test suite passed (2 checks in 1 test case)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"> 2/12 Test  #2: minimal-test --verbose ...........   Passed    0 sec</span></span></div>

</div>


### Quiet mode


<p>In quiet mode, the µTest++ reporter displays only the overall totals for the test suite.</p>

<dl class="doxySectionUser">
<dt><b>Example</b></dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">test 3</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      Start  3: minimal-test --quiet</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">3: Test command:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/minimal-test</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">"one" "two" "--quiet" 3: Working Directory:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">3: Test timeout computed to be: 10000000</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">3:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">3: ✓ Minimal - test suite passed (2 checks in 1 test case)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"> 3/12 Test  #3: minimal-test --quiet .............   Passed    0 sec</span></span></div>

</div>


### Silent mode


<p>In silent mode, the µTest++ reporter suppresses all output, and the framework returns only the exit code.</p>

<dl class="doxySectionUser">
<dt><b>Example</b></dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">test 4</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      Start  4: minimal-test --silent</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">4: Test command:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/minimal-test</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">"one" "two" "--silent" 4: Working Directory:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">/Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">4: Test timeout computed to be: 10000000</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">4:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"> 4/12 Test  #4: minimal-test --silent ............   Passed    0 sec</span></span></div>

</div>


<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
