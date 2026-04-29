---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-test-plus-cli
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Command Line Options

<p>Options for controlling test output verbosity at run-time.</p>

## Description {#details}


<p>The µTest++ framework provides flexible command-line options to control the verbosity of test output, allowing users to tailor the level of detail to their specific requirements and workflow.</p>


<p>By default, the reporter presents detailed results only for failed test cases, while successful test cases are summarised in a single line, indicating the total number of passed and failed checks.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test one two --reporter=tap</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Minimal</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    # Subtest: Check various conditions</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        1..0</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check various conditions # { passed, 2 checks }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - Minimal # { passed, 2 checks in 1 test case, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


## Reporter {#cli-reporter}


<p>By default, the µTest++ output follows the <a href="https://en.wikipedia.org/wiki/Test_Anything_Protocol">TAP</a> rules.</p>


<p>For compatibility reasons, the proprietary format implemented by the initial releases will also be retained, but it is not recommended for new projects.</p>


<p>If needed, more reporting formats (like JUnit, JSON, etc.) can be added.</p>


<p>To explicitly ask for a specific format:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--reporter=tap</span> - the default TAP reporter</li>
<li><span class="doxyComputerOutput">--reporter=human</span> - the human-readable reporter</li>
</ul>

## Verbosity {#cli-verbosity}


<p>By default, µTest++ displays a summary line for each passing test case and full expectation details for each failing one.</p>


<p>To adjust the verbosity, the following command-line options are available:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--verbose</span> – display all expectations, regardless of outcome</li>
<li><span class="doxyComputerOutput">--quiet</span> – display only the test suite totals</li>
<li><span class="doxyComputerOutput">--silent</span> – suppress all output and return only the exit code</li>
</ul>

<p>These options enable developers to focus on the information most relevant to their needs, whether that is comprehensive diagnostics during development or succinct summaries for automated builds.</p>


<p>The examples provided illustrate the output produced in each mode, demonstrating how µTest++ adapts its reporting to support professional and efficient testing workflows across all files and folders.</p>


<p>The source code for this example is in <span class="doxyComputerOutput">tests/sources/minimal-test/src/main.cpp</span>.</p>


### Verbose mode {#cli-verbosity-verbose}


<p>In verbose mode, the µTest++ reporter provides detailed output for every expectation, irrespective of whether it passes or fails.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test one two --verbose --reporter=tap</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Minimal</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    # Subtest: Check various conditions</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        ok 1 - answer is 42</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        ok 2 - condition is true</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        1..2</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check various conditions # { passed, 2 checks }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - Minimal # { passed, 2 checks in 1 test case, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


### Quiet mode {#cli-verbosity-quiet}


<p>In quiet mode, the µTest++ reporter displays only the overall session totals.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test one two --quiet --reporter=tap</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..0</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


### Silent mode {#cli-verbosity-silent}


<p>In silent mode, the µTest++ reporter suppresses all output, and the framework returns only the exit code.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.15.0.</p>

</div>
