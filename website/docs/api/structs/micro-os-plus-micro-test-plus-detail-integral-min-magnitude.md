---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/integral-min-magnitude
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `integral_min_magnitude` Struct Template

<p>Struct template representing the absolute value of the minimum of a signed integral type, as written in a literal. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::integral_min_magnitude&lt;T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a30671e3b97a6c4c108d47358e9e40b35">operator-</a> () const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Unary minus operator. <a href="#a30671e3b97a6c4c108d47358e9e40b35">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Struct template representing the absolute value of the minimum of a signed integral type, as written in a literal.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The signed integral type of the literal.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The absolute value of the minimum of a signed type (e.g. 128 for <span class="doxyComputerOutput">int8_t</span>) does not fit in the type, but the literal must be accepted to write the minimum with the unary minus (e.g. <span class="doxyComputerOutput">-128<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-literals/#ga265f8609ef3d6ead78c7a66825553e24">_i8</a></span>). The literal operators return this type for such a literal; its only operation is the unary minus, so any other use of the literal fails to compile.</p>


<p>Definition at line 281 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/values-h">values.h</a>.</p>


<div class="doxySectionDef">

## Public Operators

### operator-() {#a30671e3b97a6c4c108d47358e9e40b35}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::detail::integral_min_magnitude&lt; T &gt;::operator- ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Unary minus operator.</p>


<p>The only operation of the type, the one that makes the literal valid.</p>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/integral-constant">integral_constant</a></span> with the minimum value of <span class="doxyComputerOutput">T</span>.</p></dd>
</dl>


<p>Returns the minimum of <span class="doxyComputerOutput">T</span>, which is the negation of the absolute value represented by this type.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/values-h/#l00293">293</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/values-h">values.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/values-inlines-h/#l00159">159</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/values-inlines-h">values-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a30671e3b97a6c4c108d47358e9e40b35">159</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a30671e3b97a6c4c108d47358e9e40b35">integral_min_magnitude&lt;T&gt;::operator-</a>() const noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/integral-constant">integral_constant&lt;std::numeric_limits&lt;T&gt;::min</a> ()&gt;{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/values-inlines-h">values-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/values-h">values.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
