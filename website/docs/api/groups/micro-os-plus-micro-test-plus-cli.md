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

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test --reporter=tap one two</span></span></div>
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


<p>Options may also be set programmatically, on platforms without a command line, through <span class="doxyComputerOutput">runner_options</span>.</p>


<p>The µTest++ options come first. The parsing of the options ends at the first argument that does not start with a dash, or at the first <span class="doxyComputerOutput">--</span> alone; that argument, and all the following ones, are left to the application, uninterpreted, and are available from <span class="doxyComputerOutput">runner::application_arguments()</span>. The first <span class="doxyComputerOutput">--</span> alone is not passed on when it ends the options; it is needed in front of an application argument that starts with a dash, which would otherwise be taken for an unknown µTest++ option. After an application argument, a <span class="doxyComputerOutput">--</span> is not a terminator, and is passed on like any other argument. An option argument given separately (<span class="doxyComputerOutput">--reporter human</span>) belongs to its option. An unknown option before that point (an argument that starts with a dash, such as <span class="doxyComputerOutput">-x</span>, <span class="doxyComputerOutput">-</span> or <span class="doxyComputerOutput">-verbose</span>), an unknown reporter or colour mode, or an option with a missing argument, is an error: it is reported on <span class="doxyComputerOutput">stderr</span>, on the console, and in the output file, if any, no test is run, and the exit code is 2. For an unknown option, the console also suggests <span class="doxyComputerOutput">--help</span>.</p>


## Help {#cli-help}


<p>The <span class="doxyComputerOutput">--help</span> option, or its short form <span class="doxyComputerOutput">-h</span>, which is the only short option, writes the usage and the list of the options on the console, also with the <span class="doxyComputerOutput">silent</span> verbosity, runs no test, and the exit code is 0. The errors in the other options have priority: they are reported as usual, and the exit code is 2.</p>


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


<p>The human reporter highlights the results in colour. By default, the colours are used only when <span class="doxyComputerOutput">stdout</span> is a terminal, which can be detected only on POSIX platforms. To select them explicitly, with an option modelled on the <span class="doxyComputerOutput">--color</span> option of the GNU tools, whose American spelling <span class="doxyComputerOutput">--color</span> is also accepted:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--colour=auto</span> – use colours only when the output is a terminal (the default)</li>
<li><span class="doxyComputerOutput">--colour=always</span>, or <span class="doxyComputerOutput">--colour</span> alone – always use colours, for example in the CI systems that render the ANSI escape sequences but do not provide a terminal</li>
<li><span class="doxyComputerOutput">--colour=never</span> – never use colours</li>
</ul>

<p>As in the GNU tools, the value must be attached with <span class="doxyComputerOutput">=</span>, and the synonyms <span class="doxyComputerOutput">yes</span> and <span class="doxyComputerOutput">force</span> (for <span class="doxyComputerOutput">always</span>), <span class="doxyComputerOutput">no</span> and <span class="doxyComputerOutput">none</span> (for <span class="doxyComputerOutput">never</span>), and <span class="doxyComputerOutput">tty</span> and <span class="doxyComputerOutput">if-tty</span> (for <span class="doxyComputerOutput">auto</span>) are also accepted. For compatibility with Catch2 and Boost UT, <span class="doxyComputerOutput">--use-colour=&lt;mode&gt;</span> or <span class="doxyComputerOutput">--use-colour &lt;mode&gt;</span>, also spelled <span class="doxyComputerOutput">--use-color</span>, with <span class="doxyComputerOutput">yes</span>, <span class="doxyComputerOutput">no</span>, or <span class="doxyComputerOutput">auto</span> (or any other value of <span class="doxyComputerOutput">--colour</span>), is also accepted. The TAP reporter never uses colours, and the output file never receives them.</p>


<p>On platforms without a command line, the mode can be set in <span class="doxyComputerOutput">runner_options::colour</span>.</p>


## Verbosity {#cli-verbosity}


<p>By default, µTest++ displays a summary line for each passing test case and full expectation details for each failing one.</p>


<p>To adjust the verbosity, the following command-line options are available:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--verbose</span> – display all expectations, regardless of outcome</li>
<li><span class="doxyComputerOutput">--quiet</span> – display only the failed checks, with the names of their suites and test cases, and the session totals (and, with the TAP reporter, one result line per test suite)</li>
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

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test --verbose --reporter=tap one two</span></span></div>
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


<p>In quiet mode, the µTest++ reporter displays only the failed checks and the overall session totals; a run without failures displays only the totals. The TAP reporter also displays one <span class="doxyComputerOutput">ok</span>/<span class="doxyComputerOutput">not ok</span> line per test suite, with the plan counting them, so that the output remains a valid TAP document, which the TAP consumers read as failed when a suite failed.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test --quiet --reporter=tap one two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - Minimal # { passed, 2 checks in 1 test case, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


<p>When a check fails, it is displayed with its location, after the names of its suite and of its test cases. The human reporter writes them as the headings of the default mode, but only for the suites and the test cases with failures. The TAP reporter writes each failure as a TAP comment, after a <span class="doxyComputerOutput"># &lt;suite&gt; &gt; &lt;test case&gt;</span> line, so that the output remains a valid TAP document with only the suite result lines as test points:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Top suite &gt; Failed nested subtest &gt; middle subtest &gt; inner subtest</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">#                 not ok 1 - inner check fails</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">#                   ---</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">#                   condition: "1 == 2"</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">#                   at:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">#                     fileName: checks.cpp</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">#                     lineNumber: 399</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">#                   ...</span></span></div>

</div>


<p>The passed checks, and the test cases without failures, are not displayed. To keep the complete report while the console shows only the failures, add <span class="doxyComputerOutput">--output-file</span>, whose file always receives the complete report, whatever the verbosity:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --quiet --output-file=sample-test.tap</span></span></div>

</div>


<p>When exceptions are not enabled and a failed requirement aborts the test execution, the results of the aborted test case are displayed in quiet mode as well, since the totals are never reached.</p>


### Silent mode {#cli-verbosity-silent}


<p>In silent mode, the µTest++ reporter suppresses all console output, and the framework returns only the exit code; the output file, if any, is still written.</p>


## Output File {#cli-output-file}


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--output-file=&lt;path&gt;</span> or <span class="doxyComputerOutput">--output-file &lt;path&gt;</span> – write a copy of the report to a file</li>
</ul>

<p>The file never receives colours. With both reporters, it always receives the complete report, whatever the verbosity, so it can be passed to other tools. If the file cannot be opened, the error is reported on <span class="doxyComputerOutput">stderr</span> and on the console, no test is run, and the exit code is 2. The option errors are also written to the file, which is truncated, so that it never keeps the results of an earlier run. On platforms without a command line, the path can be set in <span class="doxyComputerOutput">runner_options::output_file_path</span>.</p>


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

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --filter='*namespace*' one two</span></span></div>
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

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --filter='*namespace*' --filter='Check one' one two</span></span></div>
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

<p>The suite bodies run, to create their test cases, but the test case bodies do not, so no check is evaluated. The selected test cases (see the filter above) are listed under the names of their suites; the nested test cases are not listed, since they are created by the bodies of their parents. The list is made of plain lines, the same with both reporters and with all the verbosity levels, and is written to the console and to the output file, if any, and the exit code is 0 (or 2 after an option error).</p>


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

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
