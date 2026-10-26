---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/include/micro-os-plus/micro-test-plus/reporter-h
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `reporter.h` File

<p>C++ header file with declarations for the µTest++ test reporter. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>"
#include &lt;cstdint&gt;
#include &lt;cstdio&gt;
#include &lt;limits&gt;
#include &lt;string_view&gt;
#include &lt;string&gt;
#include &lt;memory&gt;
#include &lt;span&gt;
#include &lt;vector&gt;
#include &lt;charconv&gt;
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">inlines/reporter-inlines.h</a>"
</div>

## Namespaces Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus">micro_os_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The primary namespace for the µOS++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_test_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Primary namespace for the µTest++ testing framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Internal implementation details for the µTest++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Parameterised stream manipulator for outputting indentation. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case">open_test_case</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A test case that has begun and not yet ended. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route">output_route</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The destinations of a record. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Abstract base class for the reporters that display test results, including operand values for failures. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#details">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top">record_kind : uint8_t { <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5">...</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The kinds of records written by the reporters. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">reporter &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a> (reporter &amp;stream)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output stream manipulator for ending a line in test reports. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">indentation</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (size_t level)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Factory function that creates an <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span> manipulator. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ header file with declarations for the µTest++ test reporter.</p>


<p>This header provides the declarations for the test reporting facilities used within the µTest++ framework. It defines the <span class="doxyComputerOutput">endl</span> and <span class="doxyComputerOutput">indent()</span> stream manipulators, and the abstract <span class="doxyComputerOutput">reporter</span> base class, which accumulates output in a buffer, writes it to the console and to an optional output file, and dispatches the pass/fail results and the session, suite, and test case events to the concrete reporters (<span class="doxyComputerOutput">reporter_human</span> and <span class="doxyComputerOutput">reporter_tap</span>).</p>


<p>The formatting of the values and the comparison expressions is delegated to <span class="doxyComputerOutput">detail::expression_formatter</span>.</p>


<p>The <span class="doxyComputerOutput">verbosity</span> levels, and the other session options, are defined in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a></span>. The manipulators and the reporter are defined in the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">micro_os_plus::micro_test_plus::detail</a></span> namespace, since the reporters are internal to the framework.</p>


<p>The header files are organised within the <span class="doxyComputerOutput">include/micro-os-plus/micro-test-plus</span> folder to maintain a structured and modular codebase.</p>


<p>This file is intended solely for internal use within the framework and should not be included directly by user code.</p>


<div class="doxySectionDef">

## Enumerations

### record\_kind {#af25a23e4451135649a8207c3a0ea30b5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">enum class micro_os_plus::micro_test_plus::detail::record_kind : uint8_t</td>
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

<p>The kinds of records written by the reporters.</p>

<dl class="doxyEnumList">
<dt class="doxyEnumTableTitle">Enumeration values</dt>
<dd>
<table class="doxyEnumTable">

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">info<a id="af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c"></a></td>
<td class="doxyEnumItemDescription">The informational lines written at the beginning of the session</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">suite_heading<a id="af25a23e4451135649a8207c3a0ea30b5abd97c2ef5f66e470bc30d4fd1c3b1f08"></a></td>
<td class="doxyEnumItemDescription">The heading that marks the beginning of a suite</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">suite_result<a id="af25a23e4451135649a8207c3a0ea30b5a89dde41a0e1f6b1091218e741a26f257"></a></td>
<td class="doxyEnumItemDescription">The result line of a suite</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">test_case_heading<a id="af25a23e4451135649a8207c3a0ea30b5a50bcbe154487d5fbab186979293ec8f1"></a></td>
<td class="doxyEnumItemDescription">The heading that marks the beginning of a test case</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">test_case_result<a id="af25a23e4451135649a8207c3a0ea30b5a2e8ebf6e2498d36d386a89fe4f78c739"></a></td>
<td class="doxyEnumItemDescription">The result line of a test case</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">skipped<a id="af25a23e4451135649a8207c3a0ea30b5ae52e279299e912838f689d4380c81f4a"></a></td>
<td class="doxyEnumItemDescription">The line of a suite or of a test case skipped by the filter</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">passed_check<a id="af25a23e4451135649a8207c3a0ea30b5ad92bae248e3e6219914c8348b9b14a6e"></a></td>
<td class="doxyEnumItemDescription">The line of a passed check</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">failed_check<a id="af25a23e4451135649a8207c3a0ea30b5ae3a1f45168c36de6c9f4a81f84aaa640"></a></td>
<td class="doxyEnumItemDescription">The lines of a failed check, or the failure of a suite</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">total<a id="af25a23e4451135649a8207c3a0ea30b5afbb44b4487415b134bce9c790a27fe5e"></a></td>
<td class="doxyEnumItemDescription">The totals of the session</td>
</tr>

<tr class="doxyEnumItem">
<td class="doxyEnumItemName">abort<a id="af25a23e4451135649a8207c3a0ea30b5a5bb94a1c12413a2e5d14deabab29f2aa"></a></td>
<td class="doxyEnumItemDescription">The report of an aborted test execution</td>
</tr>

</table>
</dd>
</dl>


<p>The output policy, which decides where each kind of record is written at each verbosity level, is in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af33f2f6498a97383cdb75020e32ccf23">reporter::route()</a></span>. The concrete reporters only format the records and ask where they go.</p>


<p>Definition at line <a href="#l00165">165</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">171</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">info</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5abd97c2ef5f66e470bc30d4fd1c3b1f08">176</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5abd97c2ef5f66e470bc30d4fd1c3b1f08">suite_heading</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a89dde41a0e1f6b1091218e741a26f257">181</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a89dde41a0e1f6b1091218e741a26f257">suite_result</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a50bcbe154487d5fbab186979293ec8f1">186</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a50bcbe154487d5fbab186979293ec8f1">test_case_heading</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a2e8ebf6e2498d36d386a89fe4f78c739">191</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a2e8ebf6e2498d36d386a89fe4f78c739">test_case_result</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae52e279299e912838f689d4380c81f4a">197</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae52e279299e912838f689d4380c81f4a">skipped</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ad92bae248e3e6219914c8348b9b14a6e">202</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ad92bae248e3e6219914c8348b9b14a6e">passed_check</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae3a1f45168c36de6c9f4a81f84aaa640">207</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae3a1f45168c36de6c9f4a81f84aaa640">failed_check</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5afbb44b4487415b134bce9c790a27fe5e">212</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5afbb44b4487415b134bce9c790a27fe5e">total</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">213</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a5bb94a1c12413a2e5d14deabab29f2aa">217</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a5bb94a1c12413a2e5d14deabab29f2aa">abort</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">218</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Functions

### endl() {#a18e81b3839468cd82ad9c394d88a0e02}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::detail::endl (reporter &amp; stream)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output stream manipulator for ending a line in test reports.</p>


<p>Calls <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">reporter::end_line()</a></span>, which appends a line ending to the internal buffer. Unlike <span class="doxyComputerOutput">std::endl</span>, it does not flush; the buffer is written later, by the concrete reporters.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">stream</td>
<td class="doxyParamItemDescription"><p>Reference to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> instance.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the same <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span> instance, enabling chaining of output operations.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a></span> function calls <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">reporter::end_line()</a></span>, which appends a newline character to the buffer of the specified <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00224">224</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">224</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>&amp; stream)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">225</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">226</span><span class="doxyLineContent"><span class="doxyHighlight">    stream.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">end_line</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">227</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> stream;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">228</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">micro_os_plus::micro_test_plus::detail::reporter::end_line</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">micro_os_plus::micro_test_plus::detail::endl</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a314df80e98fe6fa5de008d6708a14925">micro_os_plus::micro_test_plus::detail::reporter_tap::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a3bd1c7d455abc782062d0e23a3ef1015">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#ab9fdb57e1a5497af22de7cf4a252ce4b">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aaea110287f115fbaf80b0248f724c5b6">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#aeb5fb6ae953d2250360968c5582f73ab">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_suffix</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a37c4235afdd9b704fd65d25d130bee86">micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_suffix</a>.</p>

</div>
</div>

### indent() {#ac6a624fe83a51361f31de016875fdb27}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">indentation micro_os_plus::micro_test_plus::detail::indent (size_t level)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Factory function that creates an <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span> manipulator.</p>


<p>Returns an <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span> aggregate initialised with <span class="doxyComputerOutput">level</span>.</p>


<p>Allows writing <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a> &lt;&lt; indent(n)</span> instead of constructing the manipulator explicitly.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">level</td>
<td class="doxyParamItemDescription"><p>The number of four-space indentation levels.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span> value for use with <span class="doxyComputerOutput">operator&lt;&lt;</span>.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00068">68</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">68</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> level)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">69</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">70</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> { level };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">71</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">micro_os_plus::micro_test_plus::detail::reporter_human::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a0302f9f5b977b05139d73df3bbc18d69">micro_os_plus::micro_test_plus::detail::reporter_tap::begin_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aec7a63f892ff631e659c28607bf31242">micro_os_plus::micro_test_plus::detail::reporter_tap::display_open_headers</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#abcfa63d8c5ca8acd458383102b7e99e9">micro_os_plus::micro_test_plus::detail::reporter_human::display_open_names</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a2d5ddae3195ab52a957927a1b455f7b8">micro_os_plus::micro_test_plus::detail::reporter_tap::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">micro_os_plus::micro_test_plus::detail::reporter_human::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ad15f7dbbf6a683441df40c502125adc3">micro_os_plus::micro_test_plus::detail::reporter_tap::end_test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#afd98d9a322823d67448d4ba301846392">micro_os_plus::micro_test_plus::detail::reporter_human::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a314df80e98fe6fa5de008d6708a14925">micro_os_plus::micro_test_plus::detail::reporter_tap::fail_suite</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">micro_os_plus::micro_test_plus::detail::indent</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a032be7e38aad40c8bc44b2376ad90e29">micro_os_plus::micro_test_plus::detail::reporter_human::output_fail_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a3bd1c7d455abc782062d0e23a3ef1015">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#aaea110287f115fbaf80b0248f724c5b6">micro_os_plus::micro_test_plus::detail::reporter_tap::output_fail_suffix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a043919044274838f8030d53630e3b1f5">micro_os_plus::micro_test_plus::detail::reporter_human::output_pass_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#ac6c05f92e47ad71f72b44f9beb0b98f1">micro_os_plus::micro_test_plus::detail::reporter_tap::output_pass_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#af28ab5a9448645fb8976c0b139bf302b">micro_os_plus::micro_test_plus::detail::reporter_human::skip_test_case</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap/#a31ccd7af941d06241ce16df9274abc38">micro_os_plus::micro_test_plus::detail::reporter_tap::skip_test_case</a>.</p>

</div>
</div>

</div>

## File Listing

The file content with the documentation metadata removed is:

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00001"></a>1</span><span class="doxyLineContent"><span class="doxyHighlightComment">/*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00002"></a>2</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * This file is part of the µOS++ project (https://micro-os-plus.github.io/).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00003"></a>3</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00004"></a>4</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00005"></a>5</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Permission to use, copy, modify, and/or distribute this software for any</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00006"></a>6</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * purpose is hereby granted, under the terms of the MIT license.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00007"></a>7</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00008"></a>8</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * If a copy of the license was not distributed with this file, it can be</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00009"></a>9</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * obtained from https://opensource.org/licenses/mit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00010"></a>10</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00011"></a>11</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00042"></a>42</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00043"></a>43</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00044"></a>44</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00045"></a>45</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00046"></a>46</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00047"></a>47</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/project-config.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/micro-test-plus-defines.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/runner-options-h">runner-options.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdint&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstdio&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;limits&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string_view&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;memory&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;span&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;vector&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;charconv&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wpadded"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00083"></a>83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00084"></a>84</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00085"></a>85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00086"></a>86</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00087"></a>87</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00088"></a>88</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00089"></a>89</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00090"></a>90</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00091"></a>91</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00092"></a>92</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00093"></a>93</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00094"></a>94</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00095"></a>95</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00096"></a>96</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// Forward definitions.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00097"></a>97</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00098"></a>98</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00099"></a>99</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00100"></a>100</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00101"></a>101</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00102"></a>102</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00103"></a>103</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">check_result</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00104"></a>104</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00105"></a>105</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00106"></a>106</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00119"></a>119</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00120"></a>120</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a18e81b3839468cd82ad9c394d88a0e02">endl</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>&amp; stream);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00121"></a>121</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00122"></a>122</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00123"></a>123</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00131"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">131</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00132"></a>132</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00139"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation/#a6b8b1c2610c1f1591bc87068deeefd5a">139</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation/#a6b8b1c2610c1f1591bc87068deeefd5a">level</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00140"></a>140</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00141"></a>141</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00152"></a>152</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00153"></a>153</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ac6a624fe83a51361f31de016875fdb27">indent</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> level);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00154"></a>154</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00155"></a>155</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00156"></a>156</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00165"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5">165</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">enum class</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5">record_kind</a> : uint8_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00166"></a>166</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00171"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">171</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5acaf9b6b99962bf5c2264824231d7a40c">info</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00172"></a>172</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00176"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5abd97c2ef5f66e470bc30d4fd1c3b1f08">176</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5abd97c2ef5f66e470bc30d4fd1c3b1f08">suite_heading</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00177"></a>177</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00181"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a89dde41a0e1f6b1091218e741a26f257">181</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a89dde41a0e1f6b1091218e741a26f257">suite_result</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00182"></a>182</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00186"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a50bcbe154487d5fbab186979293ec8f1">186</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a50bcbe154487d5fbab186979293ec8f1">test_case_heading</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00187"></a>187</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00191"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a2e8ebf6e2498d36d386a89fe4f78c739">191</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a2e8ebf6e2498d36d386a89fe4f78c739">test_case_result</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00192"></a>192</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00197"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae52e279299e912838f689d4380c81f4a">197</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae52e279299e912838f689d4380c81f4a">skipped</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00198"></a>198</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00202"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ad92bae248e3e6219914c8348b9b14a6e">202</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ad92bae248e3e6219914c8348b9b14a6e">passed_check</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00203"></a>203</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00207"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae3a1f45168c36de6c9f4a81f84aaa640">207</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5ae3a1f45168c36de6c9f4a81f84aaa640">failed_check</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00208"></a>208</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00212"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5afbb44b4487415b134bce9c790a27fe5e">212</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5afbb44b4487415b134bce9c790a27fe5e">total</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00213"></a>213</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00217"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a5bb94a1c12413a2e5d14deabab29f2aa">217</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5a5bb94a1c12413a2e5d14deabab29f2aa">abort</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00218"></a>218</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00219"></a>219</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00226"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route">226</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route">output_route</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00227"></a>227</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00231"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route/#a5ffc75b90c3290f21a2126bba91a759a">231</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route/#a5ffc75b90c3290f21a2126bba91a759a">console</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00232"></a>232</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00240"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route/#a9e8864f658fa4382fe94008f0a5efd6e">240</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route/#a9e8864f658fa4382fe94008f0a5efd6e">file</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00241"></a>241</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00242"></a>242</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a>244</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00277"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">277</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00278"></a>278</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00286"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">286</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">micro_test_plus::test_case</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00287"></a>287</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00295"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aec75a9652b7e98188d506c462aa73e19">295</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aec75a9652b7e98188d506c462aa73e19">check_result</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00296"></a>296</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00303"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">303</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00304"></a>304</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00305"></a>305</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00312"></a>312</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/runner-options">runner_options</a>&amp; opts);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00313"></a>313</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00321"></a>321</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">~reporter</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00322"></a>322</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00329"></a>329</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00330"></a>330</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>(std::string_view sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00331"></a>331</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00338"></a>338</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00339"></a>339</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00340"></a>340</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00352"></a>352</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00353"></a>353</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00354"></a>354</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00361"></a>361</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00362"></a>362</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00363"></a>363</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00369"></a>369</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>(std::nullptr_t);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00370"></a>370</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00379"></a>379</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00380"></a>380</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> std::is_arithmetic_v&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00381"></a>381</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00382"></a>382</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>(T v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00383"></a>383</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00397"></a>397</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00398"></a>398</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (not std::is_same_v&lt;T, char&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00399"></a>399</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00400"></a>400</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">operator</span><span class="doxyHighlight">&lt;&lt; (T* v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00401"></a>401</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00408"></a>408</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00409"></a>409</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp; (*func) (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00410"></a>410</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00420"></a>420</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7e04bcbd0745543c604fdd975829175a">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00421"></a>421</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a54158cb2ca77354223506355247cab9a">operator&lt;&lt;</a>(<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/indentation">indentation</a> m);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00422"></a>422</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00423"></a>423</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00424"></a>424</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00438"></a>438</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00439"></a>439</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a287bad0e5eccee7df4a2c8517959bd0e">end_line</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00440"></a>440</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00453"></a>453</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00454"></a>454</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a804b593aefa158d92a72da43de57d242">flush_streams</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00455"></a>455</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00469"></a>469</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00470"></a>470</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a083ecdfa952d7f8c372a61fbea309357">has_output_file_error</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00471"></a>471</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00485"></a>485</span><span class="doxyLineContent"><span class="doxyHighlight">      [[deprecated (</span><span class="doxyHighlightStringLiteral">"use runner::verbosity_level() (since 5.1.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00486"></a>486</span><span class="doxyLineContent"><span class="doxyHighlight">        nodiscard]] </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00487"></a>487</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a467d1332df523b9acaa3ff82b0ebb714">verbosity</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight"> -&gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00488"></a>488</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00489"></a>489</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00490"></a>490</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00500"></a>500</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00501"></a>501</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad9e6ccebc1904f723409ddb0caaddb3e">pass</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00502"></a>502</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00503"></a>503</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00515"></a>515</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00516"></a>516</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a406cf77b7adcd5fe9417ce7bce4f3afb">fail</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info">failure_info</a>&amp; failure, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00517"></a>517</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00518"></a>518</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00519"></a>519</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00520"></a>520</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00532"></a>532</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00533"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a00e5e3b4f1ddfeeff6deb614d120caef">533</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a00e5e3b4f1ddfeeff6deb614d120caef">begin_session</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00534"></a>534</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00535"></a>535</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00547"></a>547</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00548"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1f1495d610d01955c8f8634810b54bb4">548</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1f1495d610d01955c8f8634810b54bb4">end_session</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00549"></a>549</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00550"></a>550</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00563"></a>563</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00564"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aceec705f3b14971e03701afb35a8feef">564</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aceec705f3b14971e03701afb35a8feef">begin_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00565"></a>565</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00566"></a>566</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00581"></a>581</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00582"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a89358dc17ea470ab4e829136284cd896">582</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a89358dc17ea470ab4e829136284cd896">end_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00583"></a>583</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00584"></a>584</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00600"></a>600</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00601"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a01df0bb54bda2662826e84e685374ce0">601</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a01df0bb54bda2662826e84e685374ce0">skip_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00602"></a>602</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00603"></a>603</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00621"></a>621</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00622"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1bf7be6972ddc4f81cecb1552452db10">622</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1bf7be6972ddc4f81cecb1552452db10">fail_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00623"></a>623</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00624"></a>624</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00638"></a>638</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00639"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa5f6b45879c1e0986ce4ebf9f374a182">639</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa5f6b45879c1e0986ce4ebf9f374a182">begin_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00640"></a>640</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00641"></a>641</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00653"></a>653</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00654"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a145971ca001d89162c435f87b4cfeece">654</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a145971ca001d89162c435f87b4cfeece">end_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00655"></a>655</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00656"></a>656</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00673"></a>673</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00674"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1986653001ad23e18de13822bbcd022f">674</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a1986653001ad23e18de13822bbcd022f">skip_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00675"></a>675</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00676"></a>676</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00707"></a>707</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00708"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a246e22554555caffce30c61ffe80e5f2">708</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a246e22554555caffce30c61ffe80e5f2">abort_session</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00709"></a>709</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> is_requirement)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00710"></a>710</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00711"></a>711</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00723"></a>723</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00724"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">724</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a324aa273975068c140ab6eecc7e722c9">comment_prefix</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00725"></a>725</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00726"></a>726</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00743"></a>743</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00744"></a>744</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0e6f0a129d495a7e9d57ef71412cd88f">writes_passed_checks</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00745"></a>745</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00746"></a>746</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00747"></a>747</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00748"></a>748</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00763"></a>763</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00764"></a>764</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a37cba38a47d66a928a936ee081c6d88c">write_buffer_to_file</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00765"></a>765</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00792"></a>792</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/output-route">output_route</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00793"></a>793</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#af33f2f6498a97383cdb75020e32ccf23">route</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#af25a23e4451135649a8207c3a0ea30b5">record_kind</a> kind) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00794"></a>794</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00811"></a>811</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] std::string_view</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00812"></a>812</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#adb473d2a466c856bfe8151c7558383c1">console_lines</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> failed) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00813"></a>813</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00826"></a>826</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00827"></a>827</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a887f23131eb91fecf060982dcbd3b1ca">write_console_text</a> (std::string_view text);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00828"></a>828</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00842"></a>842</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00843"></a>843</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2d5e5125b8c71fe0dedbe92d730647ec">mark_failure</a> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> begin);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00844"></a>844</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00858"></a>858</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00859"></a>859</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5ddd6ca6ce847ca89d7a3fcf9751f97d">enter_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> displayed);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00860"></a>860</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00876"></a>876</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00877"></a>877</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#abaee31ffca8e65c9af34f7f67227c5b3">write_console</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00878"></a>878</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00879"></a>879</span><span class="doxyLineContent"><span class="doxyHighlight">          __attribute__ ((format (printf, 2, 3)))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00880"></a>880</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00881"></a>881</span><span class="doxyLineContent"><span class="doxyHighlight">          ;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00882"></a>882</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00895"></a>895</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00896"></a>896</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a90a541c6a9b1ddd3da9440358bfc704e">write_file</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00897"></a>897</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00898"></a>898</span><span class="doxyLineContent"><span class="doxyHighlight">          __attribute__ ((format (printf, 2, 3)))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00899"></a>899</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00900"></a>900</span><span class="doxyLineContent"><span class="doxyHighlight">          ;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00901"></a>901</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00922"></a>922</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00923"></a>923</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aa97f2ba65009154090dc68e42c94db71">write_line</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> to_console, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* format, ...)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00924"></a>924</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00925"></a>925</span><span class="doxyLineContent"><span class="doxyHighlight">          __attribute__ ((format (printf, 3, 4)))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00926"></a>926</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00927"></a>927</span><span class="doxyLineContent"><span class="doxyHighlight">          ;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00928"></a>928</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00938"></a>938</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00939"></a>939</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aeafdc8e05a6d80d9445f17ff354ee215">write_info</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00940"></a>940</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00953"></a>953</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00954"></a>954</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5859ce31641330b243cfb5d1c6080859">clear_buffer</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00955"></a>955</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00963"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">963</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a> = 32;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00964"></a>964</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00983"></a>983</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00984"></a>984</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac6dca3d3fa34870f3960fe5e226e45d8">format_elapsed_time</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">stopwatch</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00985"></a>985</span><span class="doxyLineContent"><span class="doxyHighlight">                           </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2bf85bc5dd65df1816b52b7fd7c6c627">elapsed_time_size_</a>]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00986"></a>986</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01005"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">1005</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01006"></a>1006</span><span class="doxyLineContent"><span class="doxyHighlight">          = 94 + 6 * (std::numeric_limits&lt;size_t&gt;::digits10 + 1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01007"></a>1007</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01026"></a>1026</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01027"></a>1027</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6bf3aac88a5e66e2f93eb32c54dbdd14">format_session_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a68a030feff1f481126e9a6d170331420">runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01028"></a>1028</span><span class="doxyLineContent"><span class="doxyHighlight">                             </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01029"></a>1029</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01047"></a>1047</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01048"></a>1048</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a570030599ccc9f4133ed6a9eda2c2a1c">format_suite_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01049"></a>1049</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01068"></a>1068</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01069"></a>1069</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a60b8564f54a6a1230e6d4ce110de93f5">format_test_case_totals</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01070"></a>1070</span><span class="doxyLineContent"><span class="doxyHighlight">                               </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;message)[<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aaa55b147a670878984952ca1112cecd8">totals_size_</a>]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01071"></a>1071</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01085"></a>1085</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01086"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a844e80839c81133b52ee3beabf64d942">1086</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a844e80839c81133b52ee3beabf64d942">commit_buffer</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01087"></a>1087</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01088"></a>1088</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01103"></a>1103</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01104"></a>1104</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a5cf73aaf67484b50c25ef42363d49337">commit_outer_results</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01105"></a>1105</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01118"></a>1118</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01119"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aede54e424adbe77bdb6b87d40f2d3517">1119</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#aede54e424adbe77bdb6b87d40f2d3517">output_pass_prefix</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01120"></a>1120</span><span class="doxyLineContent"><span class="doxyHighlight">                          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01121"></a>1121</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01122"></a>1122</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01133"></a>1133</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01134"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a82f4940bc3915b3fdcb58823f9bdb535">1134</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a82f4940bc3915b3fdcb58823f9bdb535">output_pass_suffix</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01135"></a>1135</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01136"></a>1136</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01152"></a>1152</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01153"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a24888ee49f3e3abb1a849e309a099189">1153</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a24888ee49f3e3abb1a849e309a099189">output_fail_prefix</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01154"></a>1154</span><span class="doxyLineContent"><span class="doxyHighlight">                          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> has_expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01155"></a>1155</span><span class="doxyLineContent"><span class="doxyHighlight">                          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01156"></a>1156</span><span class="doxyLineContent"><span class="doxyHighlight">                          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01157"></a>1157</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01158"></a>1158</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01173"></a>1173</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01174"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#adce64d6a989f193c1d0c306039a3639c">1174</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#adce64d6a989f193c1d0c306039a3639c">output_fail_suffix</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01175"></a>1175</span><span class="doxyLineContent"><span class="doxyHighlight">                          <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">check_kind</a> kind, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01176"></a>1176</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01177"></a>1177</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01178"></a>1178</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01186"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">1186</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a7ee7d450c03e89bb0beb6cd97056aa4e">indent_size_</a> = 4;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01187"></a>1187</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01196"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">1196</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2560a0f1cf935e420a2e584ccddf1a1e">verbosity_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01197"></a>1197</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01207"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">1207</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">colours</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">colours_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01208"></a>1208</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01217"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">1217</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0972f104175c075295a8aa385e90aad4">buffer_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01218"></a>1218</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01228"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">1228</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a970a08a00e70f1574033085350656230">buffer_has_failures_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01229"></a>1229</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01239"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ab8acd7e0c7bc5240a0912affd115305b">1239</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ab8acd7e0c7bc5240a0912affd115305b">failures_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01240"></a>1240</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01247"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case">1247</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">struct </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case">open_test_case</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01248"></a>1248</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01255"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case/#abb9fb536c656c747e0e2f9062193f7e2">1255</a></span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>* <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case/#abb9fb536c656c747e0e2f9062193f7e2">test</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01256"></a>1256</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01265"></a><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case/#a545589f22f45b2450bf06447aaee7ee5">1265</a></span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/reporter/open-test-case/#a545589f22f45b2450bf06447aaee7ee5">name_displayed</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01266"></a>1266</span><span class="doxyLineContent"><span class="doxyHighlight">      };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01267"></a>1267</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01275"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad7db34b25d785eacf98d4a50f1951d5b">1275</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::vector&lt;open_test_case&gt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad7db34b25d785eacf98d4a50f1951d5b">open_test_cases_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01276"></a>1276</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01283"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad0a2ebe9aedaecf71fc76993122e661f">1283</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ad0a2ebe9aedaecf71fc76993122e661f">current_suite_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01284"></a>1284</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01294"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6b07e60aa8baeb90821690d1ff9c65e6">1294</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a6b07e60aa8baeb90821690d1ff9c65e6">suite_displayed_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01295"></a>1295</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01307"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac928cbe8852ca0c0273482b905c6301b">1307</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac928cbe8852ca0c0273482b905c6301b">expression_</a>{ <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a69616e251ebb3d22e481ada0831bec3c">colours_</a> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01308"></a>1308</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01318"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">1318</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a38252f2ef24feabcb7f55e7bdac30bd2">add_empty_line_</a>{ </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01319"></a>1319</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01329"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">1329</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac3878d2e85ed2cae4c71c793d7a8f52e">output_file_path_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01330"></a>1330</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01340"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">1340</a></span><span class="doxyLineContent"><span class="doxyHighlight">      FILE* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a270178ed5fbe0d3f4d72766c2984582a">output_file_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01341"></a>1341</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01348"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">1348</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0d73674812cca717a754137b4b26ed89">has_output_file_error_</a>{ </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01349"></a>1349</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01359"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">1359</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::span&lt;char* const&gt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a3e47f2c530c5019bde9fe56867bc581f">arguments_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01360"></a>1360</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01361"></a>1361</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01362"></a>1362</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01363"></a>1363</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01364"></a>1364</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01365"></a>1365</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01366"></a>1366</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01367"></a>1367</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01368"></a>1368</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01369"></a>1369</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01370"></a>1370</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01371"></a>1371</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01372"></a>1372</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01373"></a>1373</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01374"></a>1374</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01375"></a>1375</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01376"></a>1376</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01377"></a>1377</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">inlines/reporter-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01378"></a>1378</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01379"></a>1379</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01380"></a>1380</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01381"></a>1381</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01382"></a>1382</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01383"></a>1383</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
