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

# Command-line options

<p>Options for controlling the test output at run time.</p>

## Description {#details}


<p>The test programs accept options on the command line, which <span class="doxyComputerOutput">runner::initialise()</span> reads. On platforms without a command line, the same settings are made with <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a>, passed to <span class="doxyComputerOutput">runner::initialise()</span>.</p>


<table class="doxyTable">
<tr>
<th>Option</th>
<th>Effect</th>
</tr>
<tr>
<td><span class="doxyComputerOutput">--help</span>, <span class="doxyComputerOutput">-h</span></td>
<td>list the options; run no test</td>
</tr>
<tr>
<td><span class="doxyComputerOutput">--reporter=tap</span>, <span class="doxyComputerOutput">--reporter=human</span></td>
<td>the output format (TAP by default)</td>
</tr>
<tr>
<td><span class="doxyComputerOutput">--colour[=always</span>|<span class="doxyComputerOutput">never</span>|<span class="doxyComputerOutput">auto]</span></td>
<td>colour the human-readable output</td>
</tr>
<tr>
<td><span class="doxyComputerOutput">--verbose</span>, <span class="doxyComputerOutput">--quiet</span>, <span class="doxyComputerOutput">--silent</span></td>
<td>how much the console displays</td>
</tr>
<tr>
<td><span class="doxyComputerOutput">--output-file=&lt;path&gt;</span></td>
<td>write the complete report to a file</td>
</tr>
<tr>
<td><span class="doxyComputerOutput">--filter=&lt;pattern&gt;</span></td>
<td>run only the matching names</td>
</tr>
<tr>
<td><span class="doxyComputerOutput">--list-tests</span>, <span class="doxyComputerOutput">--list</span></td>
<td>list the test cases; run none</td>
</tr>
</table>

<dl class="doxySectionUser">
<dt>Options and application arguments</dt>
<dd>
<ul class="doxyList ">
<li>The µTest++ options come first. They end at the first argument that does not start with a dash, or at the first <span class="doxyComputerOutput">--</span> alone.</li>
<li>That argument, and all the following ones, are left to the application, uninterpreted; <span class="doxyComputerOutput">runner::application_arguments()</span> returns them.</li>
<li>The <span class="doxyComputerOutput">--</span> that ends the options is not passed on. It is needed before an application argument that starts with a dash, which would otherwise be taken for an unknown µTest++ option. After the first application argument, a <span class="doxyComputerOutput">--</span> is passed on like any other argument.</li>
<li>The value of an option may be attached (<span class="doxyComputerOutput">--reporter=human</span>) or given as the next argument (<span class="doxyComputerOutput">--reporter human</span>), except for <span class="doxyComputerOutput">--colour</span>, whose value must be attached.</li>
<li>An option may be repeated: the last one takes effect (<span class="doxyComputerOutput">--quiet --verbose</span> is <span class="doxyComputerOutput">--verbose</span>), except for <span class="doxyComputerOutput">--filter</span>, whose patterns are all kept, one for each nesting level.</li>
</ul>
</dd>
</dl>


<dl class="doxySectionUser">
<dt>Errors</dt>
<dd><p>An unknown option (an argument that starts with a dash before the end of the options, such as <span class="doxyComputerOutput">-x</span>, <span class="doxyComputerOutput">-</span>, or <span class="doxyComputerOutput">-verbose</span>), an unknown reporter or colour mode, or a missing option value is an error. It is reported on <span class="doxyComputerOutput">stderr</span>, on the console (unless <span class="doxyComputerOutput">--silent</span> is given), and in the output file, if any; no test runs, and the exit code is 2. For an unknown option, the console also suggests <span class="doxyComputerOutput">--help</span>.</p></dd>
</dl>


## Help {#cli-help}


<p><span class="doxyComputerOutput">--help</span>, or its short form <span class="doxyComputerOutput">-h</span> (the only short option), writes the usage and the list of the options on the console, even with <span class="doxyComputerOutput">--silent</span>, runs no test, and the exit code is 0. Errors in the other options take priority: they are reported as usual, and the exit code is 2.</p>


## Reporter {#cli-reporter}


<p>The output follows the <a href="https://en.wikipedia.org/wiki/Test_Anything_Protocol">TAP</a> rules by default, for the tools that read test results. A human-readable format, the format of the initial releases, is meant for people reading the console:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--reporter=tap</span> – the TAP reporter (the default);</li>
<li><span class="doxyComputerOutput">--reporter=human</span> – the human-readable reporter.</li>
</ul>

## Colours {#cli-colours}


<p>The human-readable reporter highlights the results in colour; the TAP reporter never does, and the output file never receives colours. The option is modelled on the <span class="doxyComputerOutput">--color</span> option of the GNU tools, whose spelling <span class="doxyComputerOutput">--color</span> is also accepted:</p>


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--colour=auto</span> – use colours only when <span class="doxyComputerOutput">stdout</span> is a terminal (the default); a terminal can be detected only on POSIX platforms;</li>
<li><span class="doxyComputerOutput">--colour=always</span>, or <span class="doxyComputerOutput">--colour</span> alone – always use colours, for example in the CI systems that display the ANSI escape sequences but do not provide a terminal;</li>
<li><span class="doxyComputerOutput">--colour=never</span> – never use colours.</li>
</ul>

<p>As in the GNU tools, the value must be attached with <span class="doxyComputerOutput">=</span>, and the synonyms <span class="doxyComputerOutput">yes</span> and <span class="doxyComputerOutput">force</span> (for <span class="doxyComputerOutput">always</span>), <span class="doxyComputerOutput">no</span> and <span class="doxyComputerOutput">none</span> (for <span class="doxyComputerOutput">never</span>), and <span class="doxyComputerOutput">tty</span> and <span class="doxyComputerOutput">if-tty</span> (for <span class="doxyComputerOutput">auto</span>) are also accepted.</p>


<p>For compatibility with Catch2 and Boost UT, <span class="doxyComputerOutput">--use-colour=&lt;mode&gt;</span> and <span class="doxyComputerOutput">--use-colour &lt;mode&gt;</span>, also spelled <span class="doxyComputerOutput">--use-color</span>, are accepted too, with <span class="doxyComputerOutput">yes</span>, <span class="doxyComputerOutput">no</span>, <span class="doxyComputerOutput">auto</span>, or any other value of <span class="doxyComputerOutput">--colour</span>.</p>


<p>On platforms without a command line, the mode is set in <span class="doxyComputerOutput">runner_options::colour</span>.</p>


## Verbosity {#cli-verbosity}


<p>Four levels select how much the console displays:</p>


<ul class="doxyList ">
<li>default – one line for each test case that passed, and the details of each failed check;</li>
<li><span class="doxyComputerOutput">--verbose</span> – every check, passed or failed;</li>
<li><span class="doxyComputerOutput">--quiet</span> – only the failed checks, with the names of their suites and test cases, and the session totals (and, with the TAP reporter, one result line for each suite);</li>
<li><span class="doxyComputerOutput">--silent</span> – nothing on the console; only the exit code reports the result, and the errors are still written on <span class="doxyComputerOutput">stderr</span>.</li>
</ul>

<p>On platforms without a command line, the level is set in <span class="doxyComputerOutput">runner_options::verbosity_level</span>. The examples below are the output of <span class="doxyComputerOutput">tests/sources/minimal/src/main.cpp</span>.</p>


### Default mode {#cli-verbosity-default}


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test --reporter=tap one two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Running: minimal-test --reporter=tap one two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Built with ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: minimal-test</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check various conditions # { passed, 2 checks }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - minimal-test # { passed, 2 checks in 1 test case, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


### Verbose mode {#cli-verbosity-verbose}


<p>Every check is displayed, passed or failed:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test --verbose --reporter=tap one two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Running: minimal-test --verbose --reporter=tap one two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Built with ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: minimal-test</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    # Subtest: Check various conditions</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        ok 1 - answer is 42</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        ok 2 - condition is true</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        1..2</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check various conditions # { passed, 2 checks }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - minimal-test # { passed, 2 checks in 1 test case, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


### Quiet mode {#cli-verbosity-quiet}


<p>Only the failed checks and the session totals are displayed; a run without failures displays only the totals. The TAP reporter also writes one <span class="doxyComputerOutput">ok</span> or <span class="doxyComputerOutput">not ok</span> line for each suite, so that the output remains a valid TAP document, which the TAP tools read as failed when a suite failed:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ minimal-test --quiet --reporter=tap one two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - minimal-test # { passed, 2 checks in 1 test case, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


<p>A failed check is displayed with its location, after the names of its suite and of its test cases:</p>


<ul class="doxyList ">
<li>the human-readable reporter writes the names as the headings of the default mode, only for the suites and the test cases with failures;</li>
<li>the TAP reporter writes a <span class="doxyComputerOutput"># &lt;suite&gt; &gt; &lt;test case&gt;</span> line, followed by the failure as TAP comments, so that only the suite result lines are test points:</li>
</ul>

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


<p>To keep the complete report while the console shows only the failures, add an output file, which always receives the complete report; the console then ends with a line that names the file:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --quiet --output-file=sample-test.tap</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Test output written to 'sample-test.tap'.</span></span></div>

</div>


<p>When exceptions are not enabled and a failed requirement aborts the run, the results of the aborted test case are displayed in quiet mode too, since the totals are never reached.</p>


### Silent mode {#cli-verbosity-silent}


<p>Nothing is displayed on the console, and only the exit code reports the result; the output file, if any, is still written, and the errors of the options and of the rejected calls are still written on <span class="doxyComputerOutput">stderr</span>. The output that was explicitly requested, with <span class="doxyComputerOutput">--help</span> or <span class="doxyComputerOutput">--list-tests</span>, is displayed.</p>


## Output file {#cli-output-file}


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--output-file=&lt;path&gt;</span> or <span class="doxyComputerOutput">--output-file &lt;path&gt;</span> – also write the report to a file.</li>
</ul>

<p>The file receives the complete report, whatever the verbosity, with both reporters, and never receives colours, so it can be passed to other tools. It is truncated first, so it never keeps the results of an earlier run, and it also receives the option errors. If the file cannot be opened, the error is reported on <span class="doxyComputerOutput">stderr</span> and on the console, no test runs, and the exit code is 2.</p>


<p>When the run ends, the console shows a line with the path of the file (<span class="doxyComputerOutput"># Test output written to '&lt;path&gt;'.</span> with the TAP reporter, without the <span class="doxyComputerOutput"># </span> with the human-readable one); <span class="doxyComputerOutput">--silent</span> omits it. An empty path (<span class="doxyComputerOutput">--output-file=</span> or <span class="doxyComputerOutput">--output-file ""</span>) writes no file, which also cancels an earlier <span class="doxyComputerOutput">--output-file</span>.</p>


<p>On platforms without a command line, the path is set in <span class="doxyComputerOutput">runner_options::output_file_path</span>.</p>


## Filter {#cli-filter}


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--filter=&lt;pattern&gt;</span> or <span class="doxyComputerOutput">--filter &lt;pattern&gt;</span> – run only the suites and the test cases whose names match the patterns, as <span class="doxyComputerOutput">--grep</span> does in node-tap.</li>
</ul>

<p>The option is repeated for each nesting level:</p>


<ul class="doxyList ">
<li>the first pattern applies to the names of the suites;</li>
<li>the second pattern applies to the names of their test cases;</li>
<li>each further pattern applies to the names of the test cases nested one level deeper.</li>
</ul>

<p>The levels without a pattern are not filtered; to filter only the test cases, use <span class="doxyComputerOutput">*</span> for the suites.</p>


<p>In a pattern, <span class="doxyComputerOutput">*</span> matches any sequence of characters, including an empty one, <span class="doxyComputerOutput">?</span> matches any single character, and <span class="doxyComputerOutput">|</span> separates alternatives. The match is case-sensitive, and the pattern must match the whole name; for example, <span class="doxyComputerOutput">Static</span> does not select a suite named <span class="doxyComputerOutput">Static suite</span>, but <span class="doxyComputerOutput">Static*</span> and <span class="doxyComputerOutput">Args*|Static*</span> do. Quote the patterns, so that the shell does not expand the wildcards.</p>


<p>The suites and the test cases that are not selected are reported as skipped, keep their numbers in the TAP plans, and their code does not run. The top suite is never skipped as a whole, since its body is <span class="doxyComputerOutput">main()</span>, but its test cases are filtered like those of the other suites. When the filters select no test case at all, the error is reported, and the exit code is 2.</p>


<p>On platforms without a command line, the patterns are set in <span class="doxyComputerOutput">runner_options::filter_patterns</span>.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd><p>The <span class="doxyComputerOutput">sample</span> test program has a top suite named <span class="doxyComputerOutput">Sample</span>, and two other suites, <span class="doxyComputerOutput">Args suite</span> and <span class="doxyComputerOutput">Static suite</span>. To run only the suites whose names start with <span class="doxyComputerOutput">Static</span>:</p></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --filter='Static*' one two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Sample</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check various conditions # SKIP filtered</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 9 - Check containers # SKIP filtered</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..9</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - Sample # { passed, 0 checks in 0 test cases, 9 skipped, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 2 - Args suite # SKIP filtered</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Static suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check one # { passed, 1 check }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 2 - Check two # { passed, 1 check }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..2</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 3 - Static suite # { passed, 2 checks in 2 test cases, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..3</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 2 checks passed, 0 failed, in 2 test cases, 9 skipped, 3 test suites, 1 skipped, time: X.XXX ms }</span></span></div>

</div>


<p>The test cases of the top suite are skipped, since the name <span class="doxyComputerOutput">Sample</span> does not match the first pattern. To run only the test case <span class="doxyComputerOutput">Check one</span> of the same suite:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --filter='Static*' --filter='Check one' one two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Static suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check one # { passed, 1 check }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 2 - Check two # SKIP filtered</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..2</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 3 - Static suite # { passed, 1 check in 1 test case, 1 skipped, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..3</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 1 check passed, 0 failed, in 1 test case, 10 skipped, 3 test suites, 1 skipped, time: X.XXX ms }</span></span></div>

</div>


## Listing the test cases {#cli-list-tests}


<ul class="doxyList ">
<li><span class="doxyComputerOutput">--list-tests</span>, or <span class="doxyComputerOutput">--list</span> – list the test cases instead of running them, as in Catch2 and Boost UT.</li>
</ul>

<p>The bodies of the suites run, to create their test cases, but the bodies of the test cases do not, so no check is evaluated. The selected test cases are listed under the names of their suites, followed by their count; the nested test cases are not listed, since only the bodies of their parents create them.</p>


<p>The list is made of plain lines, the same with both reporters and with all the verbosity levels, and is written to the console and to the output file, if any. The exit code is 0, 1 if a call was rejected or an exception escaped the body of a suite, which makes the list incomplete (the error is written in the list, as an <span class="doxyComputerOutput">error:</span> line, or a <span class="doxyComputerOutput"># error:</span> comment with the TAP reporter, and on <span class="doxyComputerOutput">stderr</span>), or 2 after an option error, or if the filters selected no test case.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">$ sample-test --list-tests</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">All available test cases:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  Sample</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    Check various conditions</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  Args suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    args</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  Static suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    Check one</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    Check two</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">12 test cases in 3 test suites</span></span></div>

</div>


<p>With filter patterns, the header is <span class="doxyComputerOutput">Matching test cases:</span>. On platforms without a command line, the listing is requested with <span class="doxyComputerOutput">runner_options::list_tests</span>, and <span class="doxyComputerOutput">runner::is_listing()</span> tells whether the test cases are being listed.</p>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
