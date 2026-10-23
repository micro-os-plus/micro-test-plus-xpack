---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/range-element-f7399366cd6336ecbea702c3289d9432
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `range_element` Struct Template

<p>The type of the elements of a range with <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> members. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::range_element&lt;T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>&gt;
</div>

## Public Member Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#aa2f9968426ee992c2e99aedc6226c145">type</a> = std::remove_cvref_t&lt; decltype(*begin(std::declval&lt; const T &amp; &gt;()))&gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The element type, without references and qualifiers. <a href="#aa2f9968426ee992c2e99aedc6226c145">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ae9d6272e688f4f08412df6d6ee978bc2">type</a> = std::remove_cvref_t&lt; decltype(*std::declval&lt; const T &amp; &gt;().begin())&gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The element type, without references and qualifiers. <a href="#ae9d6272e688f4f08412df6d6ee978bc2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The type of the elements of a range with <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> members.</p>


<p>The type of the elements of a range with <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> functions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The range type.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 334 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxySectionDef">

## Public Member Typedefs

### type {#aa2f9968426ee992c2e99aedc6226c145}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::detail::range_element&lt; T &gt;::type = std::remove_cvref_t&lt;decltype (*begin (std::declval&lt;const T&amp;&gt; ()))&gt;</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The element type, without references and qualifiers.</p>


<p>The type of the dereferenced <span class="doxyComputerOutput">begin()</span> function, found by argument-dependent lookup, as in a range-based <span class="doxyComputerOutput">for</span> statement over a <span class="doxyComputerOutput">const</span> range.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h/#l00365">365</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aa2f9968426ee992c2e99aedc6226c145">365</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="#ae9d6272e688f4f08412df6d6ee978bc2">type</a></span></span></div>

</div>

</div>
</div>

### type {#ae9d6272e688f4f08412df6d6ee978bc2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::detail::range_element&lt; T &gt;::type = std::remove_cvref_t&lt;
         decltype (*std::declval&lt;const T&amp;&gt; ().begin ())&gt;</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The element type, without references and qualifiers.</p>


<p>The type of the dereferenced <span class="doxyComputerOutput">begin()</span> member, as iterated by a range-based <span class="doxyComputerOutput">for</span> statement over a <span class="doxyComputerOutput">const</span> range.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h/#l00343">343</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae9d6272e688f4f08412df6d6ee978bc2">343</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="#ae9d6272e688f4f08412df6d6ee978bc2">type</a> = std::remove_cvref_t&lt;</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
