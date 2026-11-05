---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cpp-api-runners
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Test runners

<p>The runner initialises the framework and returns the exit code. <a href="#details">More...</a></p>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Aggregated check and test case counters for a node in the test tree. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The test runner for the µTest++ framework. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The configuration of a test session, and its command-line parser. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Enumerations Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">enum class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top">colour_mode { <a href="#ga603af2d1c9643caa351305180b2e905b">...</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The use of colours in the console output. <a href="#ga603af2d1c9643caa351305180b2e905b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">enum class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top">reporter_kind { <a href="#ga913c4161963e9439b20857358486e8b2">...</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The built-in reporters. <a href="#ga913c4161963e9439b20857358486e8b2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">enum class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top">verbosity { <a href="#ga809871d76f29309ed9c6fbd96d5a914b">...</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The verbosity levels for test reporting. <a href="#ga809871d76f29309ed9c6fbd96d5a914b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The runner initialises the framework and returns the exit code.</p>


<p>A test program usually has one <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a>, a global object, which <span class="doxyComputerOutput">main()</span> uses in three steps:</p>


<ol class="doxyList" type="1">
<li><span class="doxyComputerOutput">runner::initialise()</span> reads the command-line options, from <span class="doxyComputerOutput">argc</span> and <span class="doxyComputerOutput">argv</span> (see <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cli">Command-line options</a>); on platforms without a command line, the overload that takes the options, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options">runner_options</a>, sets them directly. The call is optional; without it, the default options are used;</li>
<li><span class="doxyComputerOutput">runner::add_top_suite()</span> returns the top suite, on which <span class="doxyComputerOutput">main()</span> creates its own test cases (see <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-test-suites">Test suites</a>). The call is optional, for programs whose test cases are all in other suites;</li>
<li><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a700e3ef1f955492cd84235bd388dcdf2">runner::run_suites()</a> runs the other suites, writes the totals, and returns the exit code, which <span class="doxyComputerOutput">main()</span> returns to the system.</li>
</ol>

<p>Several runners may coexist, global or local, each with its own suites: a runner runs only the suites that refer to it, so the runners do not interfere (see <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a>).</p>


<p>The exit code is:</p>


<ul class="doxyList ">
<li>0 when all the checks passed, when the test cases were only listed, or when the usage was displayed by <span class="doxyComputerOutput">--help</span>;</li>
<li>1 when a check failed, or when the program used the runner wrongly (for example, it added no suite at all);</li>
<li>2 when the command line had an error, or when the filters selected no test case.</li>
</ul>

<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::runner tr;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">main (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[])</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  tr.initialise (argc, argv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; ts = tr.add_top_suite (</span><span class="doxyHighlightStringLiteral">"Minimal"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ts.test (</span><span class="doxyHighlightStringLiteral">"Check truth"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    t.expect (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> tr.run_suites ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>The program writes (the passed checks are displayed only with the <span class="doxyComputerOutput">--verbose</span> option):</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Running: minimal</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Built with ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">TAP version 14</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># Subtest: Minimal</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ok 1 - Check truth # { passed, 1 check }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - Minimal # { passed, 1 check in 1 test case, time: X.XXX ms }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">1..1</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight"># { total: 1 check passed, 0 failed, in 1 test case, 1 test suite, time: X.XXX ms }</span></span></div>

</div>


<p>The name of the top suite is optional. Without it, the suite is named after the program, the file name of <span class="doxyComputerOutput">argv[0]</span> without its extension (<span class="doxyComputerOutput">minimal</span> above); without <span class="doxyComputerOutput">argv[0]</span>, it is named <span class="doxyComputerOutput">default suite</span>.</p>


<dl class="doxySectionUser">
<dt>Without a command line</dt>
<dd><p>On the platforms that have no command line, such as many embedded targets, <span class="doxyComputerOutput">main()</span> defines the options with <span class="doxyComputerOutput">runner_options</span>, starting from the defaults, and passes them to <span class="doxyComputerOutput">initialise()</span>:</p></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::runner tr;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">main (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::runner_options options{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  options.selected_reporter = mt::reporter_kind::human;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  options.verbosity_level = mt::verbosity::verbose;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  tr.initialise (options);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; ts = tr.add_top_suite (</span><span class="doxyHighlightStringLiteral">"Embedded"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ts.test (</span><span class="doxyHighlightStringLiteral">"Check truth"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    t.expect (mt::eq (6 * 7, 42));</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> tr.run_suites ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>The members of <span class="doxyComputerOutput">runner_options</span> are the options of the command line (see <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cli">Command-line options</a>): the reporter, the verbosity, the colours, the output file, the filter patterns, and the listing of the test cases.</p>


<div class="doxySectionDef">

## Enumerations

### colour\_mode {#ga603af2d1c9643caa351305180b2e905b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">enum class micro_os_plus::micro_test_plus::colour_mode </td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel strong">strong</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The use of colours in the console output.</p>

<dl class="doxyEnumList">
<dt class="doxyEnumTableTitle">Enumeration values</dt>
<dd>
<table class="doxyEnumTable">

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">automatic<a id="gga603af2d1c9643caa351305180b2e905ba2bd9c0ed00116be1258e0cc66617d7c8"></a></td>
<td class="doxyEnumItemDescription">
<p>Colours are used when <span class="doxyComputerOutput">stdout</span> is a terminal; on the platforms without <span class="doxyComputerOutput">isatty()</span>, such as the embedded ones, they are not used.</p>
</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">always<a id="gga603af2d1c9643caa351305180b2e905baf9f90eeaf400d228facde6bc48da5cfb"></a></td>
<td class="doxyEnumItemDescription">
<p>Colours are always used, for example in the CI systems that render the ANSI escape sequences but do not provide a terminal, or on embedded targets whose output is displayed by a terminal.</p>
</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">never<a id="gga603af2d1c9643caa351305180b2e905bac7561db7a418dd39b2201dfe110ab4a4"></a></td>
<td class="doxyEnumItemDescription">
<p>Colours are never used.</p>
</td>
</tr>

</table>
</dd>
</dl>


<p>Selected with the <span class="doxyComputerOutput">--colour</span> command-line option (or its American spelling <span class="doxyComputerOutput">--color</span>, or its alternative <span class="doxyComputerOutput">--use-colour</span>, also spelled <span class="doxyComputerOutput">--use-color</span>), or with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#a48ed4dd71eff02911c2d6943ba616850">runner_options::colour</a></span>; the default is <span class="doxyComputerOutput">automatic</span>. The names follow the values of <span class="doxyComputerOutput">--color</span> in the GNU tools.</p>


<p>Only the human-readable reporter uses colours; the TAP reporter never does, since the ANSI escape sequences are not part of the TAP syntax. The output file never receives colours, whatever the mode.</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>6.0.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00152">152</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga603af2d1c9643caa351305180b2e905ba2bd9c0ed00116be1258e0cc66617d7c8">154</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga603af2d1c9643caa351305180b2e905ba2bd9c0ed00116be1258e0cc66617d7c8">automatic</a>, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga603af2d1c9643caa351305180b2e905baf9f90eeaf400d228facde6bc48da5cfb">157</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga603af2d1c9643caa351305180b2e905baf9f90eeaf400d228facde6bc48da5cfb">always</a>, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga603af2d1c9643caa351305180b2e905bac7561db7a418dd39b2201dfe110ab4a4">161</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga603af2d1c9643caa351305180b2e905bac7561db7a418dd39b2201dfe110ab4a4">never</a> </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>

</div>

</div>
</div>

### reporter\_kind {#ga913c4161963e9439b20857358486e8b2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">enum class micro_os_plus::micro_test_plus::reporter_kind </td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel strong">strong</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The built-in reporters.</p>

<dl class="doxyEnumList">
<dt class="doxyEnumTableTitle">Enumeration values</dt>
<dd>
<table class="doxyEnumTable">

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">tap<a id="gga913c4161963e9439b20857358486e8b2a8f98645041aa7d5f53913329c6946a6b"></a></td>
<td class="doxyEnumItemDescription">
<p>The TAP reporter, compliant with TAP version 14.</p>
</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">human<a id="gga913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70"></a></td>
<td class="doxyEnumItemDescription">
<p>The human-readable reporter, with optional colours.</p>
</td>
</tr>

</table>
</dd>
</dl>


<p>Selected with the <span class="doxyComputerOutput">--reporter</span> command-line option, or with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#ad22d04df014c5b0658b6e7bd239f15b0">runner_options::selected_reporter</a></span>; the default is <span class="doxyComputerOutput">tap</span>.</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>6.0.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00127">127</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga913c4161963e9439b20857358486e8b2a8f98645041aa7d5f53913329c6946a6b">129</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga913c4161963e9439b20857358486e8b2a8f98645041aa7d5f53913329c6946a6b">tap</a>, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70">130</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga913c4161963e9439b20857358486e8b2a99e9bae675b12967251c175696f00a70">human</a> </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>

</div>

</div>
</div>

### verbosity {#ga809871d76f29309ed9c6fbd96d5a914b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">enum class micro_os_plus::micro_test_plus::verbosity </td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel strong">strong</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The verbosity levels for test reporting.</p>

<dl class="doxyEnumList">
<dt class="doxyEnumTableTitle">Enumeration values</dt>
<dd>
<table class="doxyEnumTable">

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">silent<a id="gga809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15"></a></td>
<td class="doxyEnumItemDescription">
<p>No console output; only the exit code is returned.</p>
<p>(= 0)</p>
</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">quiet<a id="gga809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d"></a></td>
<td class="doxyEnumItemDescription">
<p>Displays only the failed checks and the overall session summary; the TAP reporter also displays one result line per test suite, counted by the plan, and the failed checks as comments.</p>
<p>(= 1)</p>
</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">normal<a id="gga809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555"></a></td>
<td class="doxyEnumItemDescription">
<p>Displays test suite and test case results; the individual checks are shown only for failures, the passed checks being counted, and, in the TAP blocks, numbered by bare <span class="doxyComputerOutput">ok</span> lines.</p>
<p>(= 2)</p>
</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">verbose<a id="gga809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0"></a></td>
<td class="doxyEnumItemDescription">
<p>Displays all results, including passed checks, for maximum detail.</p>
<p>(= 3)</p>
</td>
</tr>

</table>
</dd>
</dl>


<p>The level is selected with the <span class="doxyComputerOutput">--silent</span>, <span class="doxyComputerOutput">--quiet</span>, and <span class="doxyComputerOutput">--verbose</span> command-line options, or with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner-options/#aff30f0303a958a549a2f4b6e67db00d5">runner_options::verbosity_level</a></span>; the default is <span class="doxyComputerOutput">normal</span>. The console output is intended for the people who watch the tests run, while the optional output file is intended for the integration with other tools. The level affects only the console output; the output file always receives the full report.</p>


<p>The <span class="doxyComputerOutput">quiet</span> level displays the failed checks, with the names of the suite and of the test cases that contain them, and the totals; the passed checks and the passed test cases are not displayed. To also see them, use the <span class="doxyComputerOutput">verbose</span> level, or keep <span class="doxyComputerOutput">quiet</span> and use an output file, which receives them.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00100">100</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">102</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">silent</a> = 0, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">103</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">quiet</a> = 1, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">107</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">normal</a> = 2, </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gga809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">111</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#gga809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbose</a> = 3 </span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
