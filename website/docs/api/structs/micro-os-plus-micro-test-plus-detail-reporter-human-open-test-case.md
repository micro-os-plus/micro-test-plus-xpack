---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/reporter-human/open-test-case
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `open_test_case` Struct

<p>A test case that has begun and not yet ended. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
struct micro_os_plus::micro_test_plus::detail::reporter_human::open_test_case { ... }
</div>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3f513af3911b9e52cb58e00045e2181a">name_displayed</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the name of the test case was displayed. <a href="#a3f513af3911b9e52cb58e00045e2181a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a> *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6c6a86e55cb509f7582d6287d6a7d7e8">test</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The test case. <a href="#a6c6a86e55cb509f7582d6287d6a7d7e8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>A test case that has begun and not yet ended.</p>


<p>Recorded by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a04cef97a62731931038355a1b5f23556">begin_test_case()</a></span> and removed by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">end_test_case()</a></span>.</p>


<p>Definition at line 405 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-human-h">reporter-human.h</a>.</p>


<div class="doxySectionDef">

## Public Member Attributes

### name\_displayed {#a3f513af3911b9e52cb58e00045e2181a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::reporter_human::open_test_case::name_displayed</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the name of the test case was displayed.</p>


<p>Always true with verbose verbosity; with normal verbosity, set when failed results are committed before a nested test case, so that <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human/#a7987c7a524058211a73d048d28943fb9">end_test_case()</a></span> does not display the name again.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-human-h/#l00423">423</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-human-h">reporter-human.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3f513af3911b9e52cb58e00045e2181a">423</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a3f513af3911b9e52cb58e00045e2181a">name_displayed</a>;</span></span></div>

</div>

</div>
</div>

### test {#a6c6a86e55cb509f7582d6287d6a7d7e8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const test_case* micro_os_plus::micro_test_plus::detail::reporter_human::open_test_case::test</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The test case.</p>


<p>Used to display its name when its results are committed.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-human-h/#l00413">413</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-human-h">reporter-human.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6c6a86e55cb509f7582d6287d6a7d7e8">413</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a904f410e240644fa77d65e686e6fc3eb">test_case</a>* <a href="#a6c6a86e55cb509f7582d6287d6a7d7e8">test</a>;</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-human-h">reporter-human.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
