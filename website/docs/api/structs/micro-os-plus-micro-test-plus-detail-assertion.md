---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/assertion
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - struct
toc_max_heading_level: 3

---

<div class="doxyPage">

# The `assertion` Struct Template Reference

<p>Assertion struct template for parameter passing to the evaluator. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class Expr_T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::assertion&lt;Expr_T&gt;
</div>

## Included Headers

<div class="doxyIncludesList">
#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
<br/>
</div>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">Expr_T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a3bda35bdd21c44124c7828c65ac3395f">expr</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The expression under evaluation. <a href="#a3bda35bdd21c44124c7828c65ac3395f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a></td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#acd2e0e20795f5a31ed3031ab51579dc0">location</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The source location associated with the assertion. <a href="#acd2e0e20795f5a31ed3031ab51579dc0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Assertion struct template for parameter passing to the evaluator.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>The type of the expression being asserted.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The <span class="doxyComputerOutput">assertion</span> struct template is used to encapsulate assertion parameters, including the expression under evaluation and its associated source location. This design enables precise reporting and diagnostics within the framework.</p>

<p>The structure is intended exclusively for internal use and is implemented in the <span class="doxyComputerOutput">include/micro-os-plus/micro-test-plus</span> folder to maintain a structured and modular codebase.</p>

<p>Definition at line 112 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>

<div class="doxySectionDef">

## Public Member Attributes

### expr {#a3bda35bdd21c44124c7828c65ac3395f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">Expr_T micro_os_plus::micro_test_plus::detail::assertion&lt; Expr_T &gt;::expr {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>The expression under evaluation.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00117">117</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>
</div>
</div>

### location {#acd2e0e20795f5a31ed3031ab51579dc0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reflection::source_location micro_os_plus::micro_test_plus::detail::assertion&lt; Expr_T &gt;::location {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>The source location associated with the assertion.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00122">122</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>
</div>
</div>

</div>

<hr/>

<p>The documentation for this struct was generated from the following file:</p>

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a></li>
</ul>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
