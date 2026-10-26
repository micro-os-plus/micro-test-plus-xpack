---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/or-op
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `or_op` Struct Template

<p>Logical OR comparator struct template. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class Lhs_T, class Rhs_T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::or_op&lt;Lhs_T, Rhs_T&gt; { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Base struct

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">struct</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op">binary_op&lt;Lhs_T, Rhs_T&gt;</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Common base struct template for binary comparators. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Typedefs Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">using</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op/#a384b1d115e493d6a554ebda4e3089b19">op_type</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Marker identifying the framework expression types. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op/#a384b1d115e493d6a554ebda4e3089b19">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class L, class R&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#af76c42f67671cf8657d3c104383c0818">or_op</a> (L &amp;&amp;lhs, R &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a logical OR comparator for the given operands. <a href="#af76c42f67671cf8657d3c104383c0818">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae9bf4f9ead2b8a63695988d37aa6f6f7">operator bool</a> () const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Conversion operator to boolean. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae9bf4f9ead2b8a63695988d37aa6f6f7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto </td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a> (void) const -&gt; decltype(auto)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Retrieves the left-hand operand. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto </td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a> (void) const -&gt; decltype(auto)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Retrieves the right-hand operand. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">Lhs_T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">lhs_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the left-hand operand. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">Rhs_T</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">rhs_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the right-hand operand. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">const bool</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">value_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the result of the comparison. <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Logical OR comparator struct template.</p>


<p>Derived from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op">binary_op</a></span>, this struct combines two sub-expressions with a logical OR operation. It enables composition of complex assertions by combining multiple conditions into a single logical whole, with reporting that shows the combined result and individual operand outcomes.</p>


<p>The sub-expressions are not copied: the temporaries are moved into the comparator, and the named ones are referred to (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a85cd019d0861a4b6d62c3424f4a8931d">stored_operand_t</a></span>).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the stored left-hand sub-expression, either its type, or a <span class="doxyComputerOutput">const</span> reference to it.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the stored right-hand sub-expression, either its type, or a <span class="doxyComputerOutput">const</span> reference to it.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 1018 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxySectionDef">

## Public Member Typedefs

### op\_type {#a384b1d115e493d6a554ebda4e3089b19}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">using micro_os_plus::micro_test_plus::detail::op::op_type = op</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Marker identifying the framework expression types.</p>


<p>Detected by the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op</a></span> concept, and inherited by all types derived from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/values-h/#l00121">121</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/values-h">values.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op/#a384b1d115e493d6a554ebda4e3089b19">121</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op/#a384b1d115e493d6a554ebda4e3089b19">op_type</a> = <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">op</a>;</span></span></div>

</div>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Constructors

### or\_op() {#af76c42f67671cf8657d3c104383c0818}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class L, class R&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::or_op&lt; Lhs_T, Rhs_T &gt;::or_op (L &amp;&amp; lhs, R &amp;&amp; rhs)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs a logical OR comparator for the given operands.</p>


<p>The result is computed from the arguments, before they are forwarded to the base.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">L</td>
<td class="doxyParamItemDescription"><p>The type of the left-hand operand argument.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">R</td>
<td class="doxyParamItemDescription"><p>The type of the right-hand operand argument.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">lhs</td>
<td class="doxyParamItemDescription"><p>The left-hand operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>The right-hand operand.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Evaluates the logical disjunction <span class="doxyComputerOutput">static_cast&lt;bool&gt;(<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>) or static_cast&lt;bool&gt;(<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>)</span> and passes the result to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op">binary_op</a></span> base class constructor.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l01034">1034</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00532">532</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af76c42f67671cf8657d3c104383c0818">532</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="#af76c42f67671cf8657d3c104383c0818">or_op&lt;Lhs_T, Rhs_T&gt;::or_op</a> (L&amp;&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>, R&amp;&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">533</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">binary_op</a>&lt;Lhs_T, Rhs_T&gt;{ std::forward&lt;L&gt; (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">534</span><span class="doxyLineContent"><span class="doxyHighlight">                                   std::forward&lt;R&gt; (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">535</span><span class="doxyLineContent"><span class="doxyHighlight">                                   </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">536</span><span class="doxyLineContent"><span class="doxyHighlight">                                       or </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>) }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">537</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">538</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator bool() {#ae9bf4f9ead2b8a63695988d37aa6f6f7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::operator bool ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Conversion operator to boolean.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The result of the comparison.</p></dd>
</dl>


<p>Returns the pre-computed boolean result stored by the derived comparator's constructor.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00352">352</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00166">166</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">    operator bool ()</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::value_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### lhs() {#a27b015b0e2b40e0f0bbb1b08588e1c20}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">decltype(auto) constexpr micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Retrieves the left-hand operand.</p>


<p>The operand is unwrapped with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap()</a></span> and returned by reference, so that formatting it does not copy it.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The extracted left-hand operand.</p></dd>
</dl>


<p>Returns the value of the left-hand operand, unwrapped by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap()</a></span> if it is a framework wrapper type; the stored operand is not copied.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00366">366</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00179">179</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">179</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">binary_op&lt;Lhs_T, Rhs_T&gt;::lhs</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">lhs_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs_</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">micro_os_plus::micro_test_plus::detail::unwrap</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op/#a3a37dcd754e3d79a0db8479afe00a6c8">micro_os_plus::micro_test_plus::detail::and_op&lt; Lhs_T, Rhs_T &gt;::and_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op/#a5b53c23cc06ec1d830f7a99ddcb26259">micro_os_plus::micro_test_plus::detail::approx_op&lt; Lhs_T, Rhs_T, Epsilon_T &gt;::approx_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op/#a72f34185e1d681ad6874c8564c03a2a4">micro_os_plus::micro_test_plus::detail::compare_op&lt; Lhs_T, Rhs_T, Compare_T &gt;::compare_op</a>, <a href="#af76c42f67671cf8657d3c104383c0818">micro_os_plus::micro_test_plus::detail::or_op&lt; Lhs_T, Rhs_T &gt;::or_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs</a>.</p>

</div>
</div>

### rhs() {#ae1436f1b38c1062f7c733d3e8cb39b87}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">decltype(auto) constexpr micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Retrieves the right-hand operand.</p>


<p>The operand is unwrapped with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap()</a></span> and returned by reference, so that formatting it does not copy it.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The extracted right-hand operand.</p></dd>
</dl>


<p>Returns the value of the right-hand operand, unwrapped by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap()</a></span> if it is a framework wrapper type; the stored operand is not copied.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00380">380</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00192">192</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">192</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">binary_op&lt;Lhs_T, Rhs_T&gt;::rhs</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">rhs_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs_</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">micro_os_plus::micro_test_plus::detail::unwrap</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op/#a3a37dcd754e3d79a0db8479afe00a6c8">micro_os_plus::micro_test_plus::detail::and_op&lt; Lhs_T, Rhs_T &gt;::and_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op/#a5b53c23cc06ec1d830f7a99ddcb26259">micro_os_plus::micro_test_plus::detail::approx_op&lt; Lhs_T, Rhs_T, Epsilon_T &gt;::approx_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op/#a72f34185e1d681ad6874c8564c03a2a4">micro_os_plus::micro_test_plus::detail::compare_op&lt; Lhs_T, Rhs_T, Compare_T &gt;::compare_op</a>, <a href="#af76c42f67671cf8657d3c104383c0818">micro_os_plus::micro_test_plus::detail::or_op&lt; Lhs_T, Rhs_T &gt;::or_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### lhs\_ {#ac21255b7b6b6d4b9c71522cc997a5fc2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">Lhs_T micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stores the left-hand operand.</p>


<p>Either a value, moved from a temporary, or a <span class="doxyComputerOutput">const</span> reference to a named operand (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a85cd019d0861a4b6d62c3424f4a8931d">stored_operand_t</a></span>), so that a named container is not copied. It is not <span class="doxyComputerOutput">const</span>, so that a temporary expression can be moved into an enclosing one.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00392">392</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">392</a></span><span class="doxyLineContent"><span class="doxyHighlight">      Lhs_T <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">lhs_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs</a>.</p>

</div>
</div>

### rhs\_ {#a3111bc24739599066db41c6a5023672b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">Rhs_T micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stores the right-hand operand.</p>


<p>Stored as the left-hand operand is.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00400">400</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">400</a></span><span class="doxyLineContent"><span class="doxyHighlight">      Rhs_T <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">rhs_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### value\_ {#abbe4c20d03a94cac1a942d8e3af65aea}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const bool micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::value_ {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stores the result of the comparison.</p>


<p>Computed once, by the derived comparator constructor.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00408">408</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">408</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">value_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae9bf4f9ead2b8a63695988d37aa6f6f7">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::operator bool</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this struct was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/values-h">values.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
