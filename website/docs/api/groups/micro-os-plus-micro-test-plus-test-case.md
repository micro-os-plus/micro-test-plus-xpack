---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-test-case
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Test Cases

<p>Test cases are named sequences of checks. <a href="#details">More...</a></p>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A named, runnable test case that lives inside a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ga1424c18b26d5fdaed11439c77e6bf561">subtest</a> = test_case</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span>. <a href="#ga1424c18b26d5fdaed11439c77e6bf561">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Test cases are named sequences of checks.</p>


<p>Each test case is defined by calling <span class="doxyComputerOutput">suite::test()</span> with a descriptive name and a callable object (typically a lambda accepting a <span class="doxyComputerOutput">test_case&amp;</span> reference), along with any optional arguments required for the test. The test case runs immediately, within the call. Nested test cases are defined with <span class="doxyComputerOutput">test_case::test()</span>, and a test case for each value of a range or a tuple with <span class="doxyComputerOutput">test_each()</span>.</p>


<p>Test cases allow related checks to be organised together within the same environment, improving clarity and maintainability. Any number of test cases may be defined, each focusing on a specific aspect of the code under test.</p>


<p>By grouping checks in this way, developers can identify which functionality is being verified and interpret results in the context of overall software quality.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// In main(), after tr.initialise():</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check various conditions"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::eq (compute_answer (), 42)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer eq 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::ne (compute_answer (), 43)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer ne 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<div class="doxySectionDef">

## Typedefs

### subtest {#ga1424c18b26d5fdaed11439c77e6bf561}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::subtest = test_case</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deprecated name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span>.</p>


<p>The v5.0.1 name of the class passed to the test case bodies, kept for the functions and the lambdas that name it as the type of their first parameter (<span class="doxyComputerOutput">void f (mt::subtest&amp; t)</span>); the lambdas with an <span class="doxyComputerOutput">auto&amp;</span> parameter are not affected.</p>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000058>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Definition at line 1517 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
