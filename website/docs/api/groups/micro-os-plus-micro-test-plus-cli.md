---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cli
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Command Line Options

<p>Options for controlling the test output at run time.</p>

## Description {#details}


<p>The µTest++ framework offers flexible control over test-output verbosity, allowing users to tailor the level of detail to their specific requirements and workflow.</p>


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


<p>The human-readable format of the initial releases is also available. It is intended for the people who read the console output, while the TAP format is intended for the integration with other tools.</p>


<p>If needed, more reporting formats (like JUnit, JSON, etc.) can be added.</p>


<p>To explicitly ask for a specific format:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--reporter=tap</span> – the default TAP reporter</li>
<li><span class="doxyComputerOutput">--reporter=human</span> – the human-readable reporter</li>
</ul>

## Colours {#cli-colours}


<p>The human reporter highlights the results in colour. By default, the colours are used only when <span class="doxyComputerOutput">stdout</span> is a terminal, which can be detected only on POSIX platforms. To select them explicitly, as in the GNU tools:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--color=auto</span> – use colours only when the output is a terminal (the default)</li>
<li><span class="doxyComputerOutput">--color=always</span>, or <span class="doxyComputerOutput">--color</span> alone – always use colours, for example in the CI systems that render the ANSI escape sequences but do not provide a terminal</li>
<li><span class="doxyComputerOutput">--color=never</span> – never use colours</li>
</ul>

<p>As in the GNU tools, the value must be attached with <span class="doxyComputerOutput">=</span>, and the synonyms <span class="doxyComputerOutput">yes</span> and <span class="doxyComputerOutput">force</span> (for <span class="doxyComputerOutput">always</span>), <span class="doxyComputerOutput">no</span> and <span class="doxyComputerOutput">none</span> (for <span class="doxyComputerOutput">never</span>), and <span class="doxyComputerOutput">tty</span> and <span class="doxyComputerOutput">if-tty</span> (for <span class="doxyComputerOutput">auto</span>) are also accepted. For compatibility with Catch2 and Boost UT, <span class="doxyComputerOutput">--use-colour=&lt;mode&gt;</span> or <span class="doxyComputerOutput">--use-colour &lt;mode&gt;</span>, with <span class="doxyComputerOutput">yes</span>, <span class="doxyComputerOutput">no</span>, or <span class="doxyComputerOutput">auto</span> (or any other value of <span class="doxyComputerOutput">--color</span>), is also accepted. The TAP reporter never uses colours, and the output file never receives them.</p>


<p>On platforms without a command line, the mode can be set in <span class="doxyComputerOutput">runner_options::colour</span>.</p>


## Verbosity {#cli-verbosity}


<p>By default, µTest++ displays a summary line for each passing test case and full expectation details for each failing one.</p>


<p>To adjust the verbosity, the following command-line options are available:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--verbose</span> – display all expectations, regardless of outcome</li>
<li><span class="doxyComputerOutput">--quiet</span> – display only the session totals and, with the TAP reporter, one result line per test suite; the failed checks are not displayed</li>
<li><span class="doxyComputerOutput">--silent</span> – suppress all console output and return only the exit code</li>
</ul>

<p>On platforms without a command line, the level can be set in <span class="doxyComputerOutput">runner_options::verbosity_level</span>.</p>


<p>The source code for these examples is in <span class="doxyComputerOutput">tests/sources/minimal/src/main.cpp</span>.</p>


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


<p>In quiet mode, the µTest++ reporter displays only the overall session totals. The TAP reporter also displays one <span class="doxyComputerOutput">ok</span>/<span class="doxyComputerOutput">not ok</span> line per test suite, with the plan counting them, so that the output remains a valid TAP document, which the TAP consumers read as failed when a suite failed.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test one two --quiet --reporter=tap</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - Minimal # { passed, 2 checks in 1 test case, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


<p>Quiet mode tells whether the run failed, not what failed: the failed checks, their locations, and their test cases are not displayed. This is by design, since displaying in full only the failed test cases is what the default mode does. To learn what failed, run without <span class="doxyComputerOutput">--quiet</span>, or keep <span class="doxyComputerOutput">--quiet</span> and add <span class="doxyComputerOutput">--output-file</span> with the TAP reporter, whose file always receives the complete report, whatever the verbosity:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --quiet --output-file=sample-test.tap</span></span></div>

</div>


<p>With the human reporter, the output file is complete only in the default and verbose modes, so in quiet mode neither the console nor the file shows the failures.</p>


<p>When exceptions are not enabled and a failed requirement aborts the test execution, the results of the aborted test case are displayed in quiet mode as well, since the totals are never reached.</p>


### Silent mode {#cli-verbosity-silent}


<p>In silent mode, the µTest++ reporter suppresses all console output, and the framework returns only the exit code; the output file, if any, is still written.</p>


## Output File {#cli-output-file}


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--output-file=&lt;path&gt;</span> or <span class="doxyComputerOutput">--output-file &lt;path&gt;</span> – write a copy of the report to a file</li>
</ul>

<p>The file never receives colours. With the TAP reporter, it always receives the complete report, whatever the verbosity, so it can be passed to other tools; with the human reporter, it is complete only in the default and verbose modes. If the file cannot be opened, the error is reported on <span class="doxyComputerOutput">stderr</span>, the report is written only to the console, and the exit code is 2. On platforms without a command line, the path can be set in <span class="doxyComputerOutput">runner_options::output_file_path</span>.</p>


## Filter {#cli-filter}


<p>By default, all test suites and test cases are run. To run only some of them, the <span class="doxyComputerOutput">--filter</span> option selects them by name, as <span class="doxyComputerOutput">--grep</span> does in node-tap:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--filter=&lt;pattern&gt;</span> or <span class="doxyComputerOutput">--filter &lt;pattern&gt;</span> – run only the suites and the test cases whose names match the patterns</li>
</ul>

<p>The option may be repeated, one pattern per nesting level: the first pattern applies to the suite names, the second to the names of the test cases, and each further pattern to the names of the test cases nested one level deeper. The levels without a pattern are not filtered; to filter only the test cases, use <span class="doxyComputerOutput">*</span> for the suites.</p>


<p>In a pattern, <span class="doxyComputerOutput">*</span> matches any sequence of characters, including an empty one, <span class="doxyComputerOutput">?</span> matches any single character, and <span class="doxyComputerOutput">|</span> separates alternatives. The match is case-sensitive, and the pattern must cover the whole name; for example, <span class="doxyComputerOutput">Args</span> does not select a suite named <span class="doxyComputerOutput">Args suite</span>, but <span class="doxyComputerOutput">Args*</span> and <span class="doxyComputerOutput">Args*|*namespace*</span> do. Since the patterns usually contain wildcards, they must be quoted, to prevent the shell from expanding them.</p>


<p>The suites and the test cases that are not selected are reported as skipped, keep their numbers in the TAP plans, and their code is not run. The top suite is never skipped as a whole, since its body is <span class="doxyComputerOutput">main()</span>, but its test cases are filtered like those of any other suite.</p>


<p>On platforms without a command line, the patterns can be set in <span class="doxyComputerOutput">runner_options::filter_patterns</span>.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test one two --filter='*namespace*'</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Sample</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - Sample # { passed, 31 checks in 13 test cases, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 2 - Args suite # SKIP filtered</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Explicit namespace suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 3 - Explicit namespace suite # { passed, 2 checks in 2 test cases, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Implicit namespace suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 4 - Implicit namespace suite # { passed, 2 checks in 2 test cases, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..4</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 35 checks passed, 0 failed, in 17 test cases, 4 test suites, 1 skipped, time: X.XXX ms }</span></span></div>

</div>


<p>To run only the test cases named <span class="doxyComputerOutput">Check one</span> of the same suites:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test one two --filter='*namespace*' --filter='Check one'</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Explicit namespace suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    # Subtest: Check one</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        1..0</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check one # { passed, 1 check }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 2 - Check two # SKIP filtered</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..2</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 3 - Explicit namespace suite # { passed, 1 check in 1 test case, 1 skipped, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..4</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 2 test cases, 15 skipped, 4 test suites, 1 skipped, time: X.XXX ms }</span></span></div>

</div>


<p>The test cases of the top suite <span class="doxyComputerOutput">Sample</span> are skipped too, since its name does not match the first pattern.</p>


## Listing the Test Cases {#cli-list-tests}


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--list-tests</span>, or <span class="doxyComputerOutput">--list</span> – list the test cases instead of running them, as in Catch2 and Boost UT</li>
</ul>

<p>The suite bodies run, to create their test cases, but the test case bodies do not, so no check is evaluated. The selected test cases (see the filter above) are listed under the names of their suites; the nested test cases are not listed, since they are created by the bodies of their parents. The list is written to the console, unless the verbosity is <span class="doxyComputerOutput">silent</span>, and to the output file, if any, and the exit code is 0 (or 2 after an option error).</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --list-tests</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">All available test cases:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  Sample</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    Check various conditions</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>

</div>


<p>The header is <span class="doxyComputerOutput">Matching test cases:</span> when there are filter patterns. On platforms without a command line, the listing can be requested with <span class="doxyComputerOutput">runner_options::list_tests</span>, and checked with <span class="doxyComputerOutput">runner::is_listing()</span>.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.4 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
