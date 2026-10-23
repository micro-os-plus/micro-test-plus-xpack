---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/type-traits/function-traits-aa0970b0a1efa305c0cfd55ce14bb11b
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `function_traits` Struct Template

<p>Deprecated traits of the pointers to member functions. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class R, class T, class... Args_T&gt;<br/>
struct micro_os_plus::micro_test_plus::type_traits::function_traits&lt;R(T::*)(Args_T...)&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a>&gt;
</div>

## Public Member Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class R, class T, class... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#abe3052f92aa798f6a80a6e9250fc76b4">args</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/list">list</a>&lt; Args_T... &gt;</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The parameter types, as a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/list">list</a></span>. <a href="#abe3052f92aa798f6a80a6e9250fc76b4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class R, class T, class... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a1f21557f758a46166726e0c6e01ee8bc">result_type</a> = R</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The return type. <a href="#a1f21557f758a46166726e0c6e01ee8bc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Deprecated traits of the pointers to member functions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">R</td>
<td class="doxyParamItemDescription"><p>The return type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The class type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Args_T</td>
<td class="doxyParamItemDescription"><p>The parameter types.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Exposes the return type and the parameter types of a pointer to a non-<span class="doxyComputerOutput">const</span> member function.</p>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000047>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>Not replaced (since 5.1.0).</p>
</dd>
</dl>
</div>

<p>Definition at line 896 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a>.</p>


<div class="doxySectionDef">

## Public Member Typedefs

### args {#abe3052f92aa798f6a80a6e9250fc76b4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class R, class T, class... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::type_traits::function_traits&lt; R(T::*)(Args_T...)&gt;::args = list&lt;Args_T...&gt;</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The parameter types, as a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/list">list</a></span>.</p>


<p>The types <span class="doxyComputerOutput">Args_T</span> of the specialisation, without the object parameter of the member functions.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h/#l00913">913</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abe3052f92aa798f6a80a6e9250fc76b4">913</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="#abe3052f92aa798f6a80a6e9250fc76b4">args</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/list">list</a>&lt;Args_T...&gt;;</span></span></div>

</div>

</div>
</div>

### result\_type {#a1f21557f758a46166726e0c6e01ee8bc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class R, class T, class... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::type_traits::function_traits&lt; R(T::*)(Args_T...)&gt;::result_type = R</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The return type.</p>


<p>The type <span class="doxyComputerOutput">R</span> of the specialisation.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h/#l00904">904</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1f21557f758a46166726e0c6e01ee8bc">904</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="#a1f21557f758a46166726e0c6e01ee8bc">result_type</a> = R;</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following file:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
