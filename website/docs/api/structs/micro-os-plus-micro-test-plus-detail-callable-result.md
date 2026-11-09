---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/callable-result
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `callable_result` Struct

<p>The result of the invocation of the callable of a check. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
struct micro_os_plus::micro_test_plus::detail::callable_result { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>&gt;
</div>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a879f218299b32f5eb9fe68e15dfe0edf">throw_outcome</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#abd77c787fde5f5d9b90a883849d9a76b">outcome</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>What was thrown, when the check failed. <a href="#abd77c787fde5f5d9b90a883849d9a76b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af4bafb957cc53a478f741f3e0048b293">value</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The result of the check. <a href="#af4bafb957cc53a478f741f3e0048b293">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5118df01280af3f6094bb718716b422c">what</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The <span class="doxyComputerOutput"><a href="#a5118df01280af3f6094bb718716b422c">what()</a></span> of the <span class="doxyComputerOutput">std::exception</span> thrown, if any. <a href="#a5118df01280af3f6094bb718716b422c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The result of the invocation of the callable of a check.</p>


<p>Returned by the lambda that the constructors of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-op">throws_op</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-op">nothrow_op</a></span> pass to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/callable-op">callable_op</a></span>.</p>


<p>Definition at line 1361 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxySectionDef">

## Public Member Attributes

### outcome {#abd77c787fde5f5d9b90a883849d9a76b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">throw_outcome micro_os_plus::micro_test_plus::detail::callable_result::outcome</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>What was thrown, when the check failed.</p>


<p><span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a879f218299b32f5eb9fe68e15dfe0edfa334c4a4c42fdb79d7ebc3e73b517e6f8">throw_outcome::none</a></span> when the check passed, or when nothing was thrown but an exception was expected.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01379">1379</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abd77c787fde5f5d9b90a883849d9a76b">1379</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a879f218299b32f5eb9fe68e15dfe0edf">throw_outcome</a> <a href="#abd77c787fde5f5d9b90a883849d9a76b">outcome</a>;</span></span></div>

</div>

</div>
</div>

### value {#af4bafb957cc53a478f741f3e0048b293}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::callable_result::value</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The result of the check.</p>


<p>True if the expected exception was thrown (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-op">throws_op</a></span>), or if nothing was thrown (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-op">nothrow_op</a></span>).</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01370">1370</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af4bafb957cc53a478f741f3e0048b293">1370</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#af4bafb957cc53a478f741f3e0048b293">value</a>;</span></span></div>

</div>

</div>
</div>

### what {#a5118df01280af3f6094bb718716b422c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::callable_result::what</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The <span class="doxyComputerOutput"><a href="#a5118df01280af3f6094bb718716b422c">what()</a></span> of the <span class="doxyComputerOutput">std::exception</span> thrown, if any.</p>


<p>Empty unless <span class="doxyComputerOutput"><a href="#abd77c787fde5f5d9b90a883849d9a76b">outcome</a></span> is <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a879f218299b32f5eb9fe68e15dfe0edfa1702c8950d15f035273a3f192a9da2dc">throw_outcome::std_exception</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01387">1387</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5118df01280af3f6094bb718716b422c">1387</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="#a5118df01280af3f6094bb718716b422c">what</a>;</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
