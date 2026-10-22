---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/runner-options
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `runner_options` Struct

<p>The configuration of a test session. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
struct micro_os_plus::micro_test_plus::runner_options { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::span&lt; char *const  &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7c2cca740efdbdc4927cac43aa456611">arguments</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The complete command line, including <span class="doxyComputerOutput">argv[0]</span>, if any. <a href="#a7c2cca740efdbdc4927cac43aa456611">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905b">colour_mode</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a48ed4dd71eff02911c2d6943ba616850">colour</a> { <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905ba2bd9c0ed00116be1258e0cc66617d7c8">colour_mode::automatic</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the console output uses colours. <a href="#a48ed4dd71eff02911c2d6943ba616850">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::vector&lt; std::string_view &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a8dc9c5a5b6c89c12acd27d67d57618dd">filter_patterns</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The patterns that select the suites and the test cases to run, one per nesting level. <a href="#a8dc9c5a5b6c89c12acd27d67d57618dd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a> { false }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the test cases are listed instead of run. <a href="#ac4f95336439b329d0f3731a5dcafb6f9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aacf79acd1554b6e8899524bc02ee6257">output_file_path</a> { nullptr }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Path of the optional output file, or <span class="doxyComputerOutput">nullptr</span>. <a href="#aacf79acd1554b6e8899524bc02ee6257">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2">reporter_kind</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad22d04df014c5b0658b6e7bd239f15b0">selected_reporter</a> { <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a8f98645041aa7d5f53913329c6946a6b">reporter_kind::tap</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The reporter that displays the results. <a href="#ad22d04df014c5b0658b6e7bd239f15b0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a> = ...</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The level of detail of the console output. <a href="#aff30f0303a958a549a2f4b6e67db00d5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The configuration of a test session.</p>


<p><span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise</a> (argc, argv)</span> parses the command-line options into this structure and passes it to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">runner::initialise</a> (options)</span>, which creates the selected reporter and starts the session.</p>


<p>The applications that do not have a command line, such as the embedded ones without semihosting arguments, can define the options directly, starting from the defaults, and call the second overload:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::runner_options options{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">options.selected_reporter = mt::reporter_kind::human;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">options.verbosity_level = mt::verbosity::verbose;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; ts = tr.initialise (options, </span><span class="doxyHighlightStringLiteral">"Main"</span><span class="doxyHighlight">);</span></span></div>

</div>


<p>The structure only refers to the strings it uses; they must remain valid until <span class="doxyComputerOutput">initialise()</span> returns, which copies what it keeps.</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line 195 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxySectionDef">

## Public Member Attributes

### arguments {#a7c2cca740efdbdc4927cac43aa456611}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::span&lt;char* const&gt; micro_os_plus::micro_test_plus::runner_options::arguments {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The complete command line, including <span class="doxyComputerOutput">argv[0]</span>, if any.</p>


<p>A view of the <span class="doxyComputerOutput">argv[]</span> array of <span class="doxyComputerOutput">main()</span>, set when the options are parsed from the command line. When not empty, the reporters list it at the beginning of the report, and <span class="doxyComputerOutput">initialise()</span> derives the default name of the top suite from <span class="doxyComputerOutput"><a href="#a7c2cca740efdbdc4927cac43aa456611">arguments</a>[0]</span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00255">255</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7c2cca740efdbdc4927cac43aa456611">255</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::span&lt;char* const&gt; <a href="#a7c2cca740efdbdc4927cac43aa456611">arguments</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac40f554936c71d7c748c1241ffd3f2ac">micro_os_plus::micro_test_plus::runner::initialise</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2319eb34fc8b601ca5e6a8ec538ba138">micro_os_plus::micro_test_plus::runner::parse_options</a>.</p>

</div>
</div>

### colour {#a48ed4dd71eff02911c2d6943ba616850}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">colour_mode micro_os_plus::micro_test_plus::runner_options::colour { <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905ba2bd9c0ed00116be1258e0cc66617d7c8">colour_mode::automatic</a> }</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the console output uses colours.</p>


<p>Set by <span class="doxyComputerOutput">--color[=&lt;when&gt;]</span>, as in the GNU tools, where <span class="doxyComputerOutput">&lt;when&gt;</span> is <span class="doxyComputerOutput">always</span>, <span class="doxyComputerOutput">never</span>, or <span class="doxyComputerOutput">auto</span>, or one of their GNU synonyms (<span class="doxyComputerOutput">yes</span> and <span class="doxyComputerOutput">force</span>, <span class="doxyComputerOutput">no</span> and <span class="doxyComputerOutput">none</span>, <span class="doxyComputerOutput">tty</span> and <span class="doxyComputerOutput">if-tty</span>), and <span class="doxyComputerOutput">--color</span> alone means <span class="doxyComputerOutput">always</span>; the value is accepted only after <span class="doxyComputerOutput">=</span>. The alternative <span class="doxyComputerOutput">--use-colour=&lt;mode&gt;</span> or <span class="doxyComputerOutput">--use-colour &lt;mode&gt;</span>, as in Catch2 and Boost UT, takes <span class="doxyComputerOutput">yes</span>, <span class="doxyComputerOutput">no</span>, or <span class="doxyComputerOutput">auto</span>, and also accepts the other values of <span class="doxyComputerOutput">--color</span>. Used only by the human reporter.</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00244">244</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a48ed4dd71eff02911c2d6943ba616850">244</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905b">colour_mode</a> <a href="#a48ed4dd71eff02911c2d6943ba616850">colour</a>{ <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a603af2d1c9643caa351305180b2e905ba2bd9c0ed00116be1258e0cc66617d7c8">colour_mode::automatic</a> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a82221fa355584dbaa75c7e66fbefa6b8">micro_os_plus::micro_test_plus::detail::reporter_human::reporter_human</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2319eb34fc8b601ca5e6a8ec538ba138">micro_os_plus::micro_test_plus::runner::parse_options</a>.</p>

</div>
</div>

### filter\_patterns {#a8dc9c5a5b6c89c12acd27d67d57618dd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::vector&lt;std::string_view&gt; micro_os_plus::micro_test_plus::runner_options::filter_patterns {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The patterns that select the suites and the test cases to run, one per nesting level.</p>


<p>Each <span class="doxyComputerOutput">--filter=&lt;pattern&gt;</span> or <span class="doxyComputerOutput">--filter &lt;pattern&gt;</span> option adds one pattern; unlike the other options, <span class="doxyComputerOutput">--filter</span> may be repeated. As with <span class="doxyComputerOutput">--grep</span> in node-tap, the first pattern applies to the suite names, the second to the names of the test cases, and each further pattern to the names of the test cases nested one level deeper; the levels without a pattern are not filtered.</p>


<p>Within a pattern, <span class="doxyComputerOutput">|</span> separates alternatives; a name matches when it matches any of them, as defined by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-utility-functions/#gaa2f0f4cff320a783ad2347c9ff3fc731">utility::is_match()</a></span>: <span class="doxyComputerOutput">*</span> matches any sequence of characters, <span class="doxyComputerOutput">?</span> matches any single character, the match is case-sensitive, and the alternative must cover the whole name.</p>


<p>The suites and the test cases that do not match are reported as skipped, and their bodies are not called. The top suite is never skipped as a whole, since its body is <span class="doxyComputerOutput">main()</span>, but when its name does not match the first pattern, all its test cases are skipped.</p>


<p>When the list is empty (the default), everything runs.</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00284">284</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a8dc9c5a5b6c89c12acd27d67d57618dd">284</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::vector&lt;std::string_view&gt; <a href="#a8dc9c5a5b6c89c12acd27d67d57618dd">filter_patterns</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac40f554936c71d7c748c1241ffd3f2ac">micro_os_plus::micro_test_plus::runner::initialise</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2319eb34fc8b601ca5e6a8ec538ba138">micro_os_plus::micro_test_plus::runner::parse_options</a>.</p>

</div>
</div>

### list\_tests {#ac4f95336439b329d0f3731a5dcafb6f9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::runner_options::list_tests { false }</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the test cases are listed instead of run.</p>


<p>Set by the <span class="doxyComputerOutput">--list-tests</span> option, or by its short form <span class="doxyComputerOutput">--list</span>. When set, the suite bodies run, as usual, to create their test cases, but the bodies of the test cases do not, so no check is evaluated. The selected test cases (see <span class="doxyComputerOutput"><a href="#a8dc9c5a5b6c89c12acd27d67d57618dd">filter_patterns</a></span>) are listed under the names of their suites, as Catch2 lists them:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">All available test cases:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  Sample</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    Check various conditions</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    Check strings</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  Explicit </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">suite</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    Check one</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">3 test cases in 2 test suites</span></span></div>

</div>


<p>The header is <span class="doxyComputerOutput">Matching test cases:</span> when there are filter patterns, and the suites without selected test cases are not listed. The nested test cases are not listed, since they are created by the bodies of their parents, which do not run. The list is written to the console, unless the verbosity is <span class="doxyComputerOutput">silent</span>, and to the output file, if any; no report is written, and <span class="doxyComputerOutput">run()</span> returns 0, or 2 after an option error.</p>


<dl class="doxySectionUser">
<dt>Since</dt>
<dd><p>5.1.0</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00316">316</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ac4f95336439b329d0f3731a5dcafb6f9">316</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#ac4f95336439b329d0f3731a5dcafb6f9">list_tests</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac40f554936c71d7c748c1241ffd3f2ac">micro_os_plus::micro_test_plus::runner::initialise</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2319eb34fc8b601ca5e6a8ec538ba138">micro_os_plus::micro_test_plus::runner::parse_options</a>.</p>

</div>
</div>

### output\_file\_path {#aacf79acd1554b6e8899524bc02ee6257}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::runner_options::output_file_path { nullptr }</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Path of the optional output file, or <span class="doxyComputerOutput">nullptr</span>.</p>


<p>Set by <span class="doxyComputerOutput">--output-file=&lt;path&gt;</span> or <span class="doxyComputerOutput">--output-file &lt;path&gt;</span>. When it is <span class="doxyComputerOutput">nullptr</span> or empty, no file is written. The reporter opens the file, and keeps a copy of the path, when it is created by <span class="doxyComputerOutput">initialise()</span>; if the file cannot be opened, the error is reported on <span class="doxyComputerOutput">stderr</span>, the report is written only to the console, and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a97f725cb167a2b464fac0eb88a0c8a46">runner::run()</a></span> returns 2.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00228">228</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aacf79acd1554b6e8899524bc02ee6257">228</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#aacf79acd1554b6e8899524bc02ee6257">output_file_path</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">micro_os_plus::micro_test_plus::detail::reporter::reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2319eb34fc8b601ca5e6a8ec538ba138">micro_os_plus::micro_test_plus::runner::parse_options</a>.</p>

</div>
</div>

### selected\_reporter {#ad22d04df014c5b0658b6e7bd239f15b0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter_kind micro_os_plus::micro_test_plus::runner_options::selected_reporter { <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a8f98645041aa7d5f53913329c6946a6b">reporter_kind::tap</a> }</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The reporter that displays the results.</p>


<p>Set by <span class="doxyComputerOutput">--reporter=&lt;name&gt;</span> or <span class="doxyComputerOutput">--reporter &lt;name&gt;</span>, where the name is <span class="doxyComputerOutput">tap</span> or <span class="doxyComputerOutput">human</span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00204">204</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad22d04df014c5b0658b6e7bd239f15b0">204</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2">reporter_kind</a> <a href="#ad22d04df014c5b0658b6e7bd239f15b0">selected_reporter</a>{ <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a913c4161963e9439b20857358486e8b2a8f98645041aa7d5f53913329c6946a6b">reporter_kind::tap</a> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac40f554936c71d7c748c1241ffd3f2ac">micro_os_plus::micro_test_plus::runner::initialise</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2319eb34fc8b601ca5e6a8ec538ba138">micro_os_plus::micro_test_plus::runner::parse_options</a>.</p>

</div>
</div>

### verbosity\_level {#aff30f0303a958a549a2f4b6e67db00d5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_test_plus::verbosity micro_os_plus::micro_test_plus::runner_options::verbosity_level</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The level of detail of the console output.</p>

<dl class="doxySectionUser">
<dt>Initialiser</dt>
<dd>
<div class="doxyVerbatim">{
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_test_plus::verbosity::normal</a>
&nbsp;&nbsp;&nbsp;&nbsp;}
</div>
</dd>
</dl>


<p>Set by <span class="doxyComputerOutput">--silent</span>, <span class="doxyComputerOutput">--quiet</span>, or <span class="doxyComputerOutput">--verbose</span>; when several are given, the last one takes effect.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h/#l00213">213</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aff30f0303a958a549a2f4b6e67db00d5">213</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a> <a href="#aff30f0303a958a549a2f4b6e67db00d5">verbosity_level</a>{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">214</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_test_plus::verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">215</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#ac40f554936c71d7c748c1241ffd3f2ac">micro_os_plus::micro_test_plus::runner::initialise</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a2319eb34fc8b601ca5e6a8ec538ba138">micro_os_plus::micro_test_plus::runner::parse_options</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.4 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
