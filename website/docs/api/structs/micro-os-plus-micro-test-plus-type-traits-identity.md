---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/type-traits/identity
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `identity` Struct Template

<p>Struct template for compile-time type identity. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class T, class...&gt;
struct micro_os_plus::micro_test_plus::type_traits::identity&lt;T, class...&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Public Member Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T, class...&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a8a488c6629ed310aa4fa5713e4e2e016">type</a> = T</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Alias for the preserved type. <a href="#a8a488c6629ed310aa4fa5713e4e2e016">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Struct template for compile-time type identity.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type to be preserved.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">...Unused</td>
<td class="doxyParamItemDescription"><p>Additional template parameters, ignored.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The <span class="doxyComputerOutput">identity</span> struct template provides a mechanism for preserving a type <span class="doxyComputerOutput">T</span> during template metaprogramming. It is commonly used to delay type evaluation or to forward types in complex template constructs within the µTest++ framework.</p>


<p>This utility is particularly useful in scenarios where type deduction or SFINAE is required, as it allows the type to be carried through template specialisations without modification.</p>


<p>Definition at line 141 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>.</p>


<div class="doxySectionDef">

## Public Member Typedefs

### type {#a8a488c6629ed310aa4fa5713e4e2e016}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, class...&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::type_traits::identity&lt; T,... &gt;::type =  T</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Alias for the preserved type.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h/#l00146">146</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a8a488c6629ed310aa4fa5713e4e2e016">146</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="#a8a488c6629ed310aa4fa5713e4e2e016">type</a> = T;</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 1.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
