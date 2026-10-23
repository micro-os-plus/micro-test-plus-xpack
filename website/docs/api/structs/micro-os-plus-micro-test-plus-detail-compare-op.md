---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/structs/micro-os-plus/micro-test-plus/detail/compare-op
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - struct

---

<div class="doxyPage">

# `compare_op` Struct Template

<p>Relational comparator struct template. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;<br/>
struct micro_os_plus::micro_test_plus::detail::compare_op&lt;Lhs_T, Rhs_T, Compare_T&gt; { ... }
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div></td>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a72f34185e1d681ad6874c8564c03a2a4">compare_op</a> (L &amp;&amp;lhs, R &amp;&amp;rhs, Compare_T)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a comparator for the given operands. <a href="#a72f34185e1d681ad6874c8564c03a2a4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div></td>
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div></td>
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div></td>
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div></td>
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div></td>
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div></td>
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

<p>Relational comparator struct template.</p>


<p>Derived from <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op">binary_op</a></span>, this struct compares the left-hand operand with the right-hand operand, using the operator defined by the tag <span class="doxyComputerOutput">Compare_T</span> (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/equal-to">equal_to</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-equal-to">not_equal_to</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/greater">greater</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/greater-equal">greater_equal</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/less">less</a></span>, or <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/less-equal">less_equal</a></span>). It is used within test expressions to provide human-readable relational assertions, with the actual and expected values, and the symbol of the tag, reported upon failure.</p>


<p>The tag is passed as an empty constructor argument, so that all three template arguments are deduced, for example <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/compare-op">compare_op</a>{ <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/equal-to">equal_to</a>{} }</span>. A factory function would do the same, but at <span class="doxyComputerOutput">-O0</span> it adds one function per instantiation.</p>


<p>It is also public, as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/extension/compare-op">extension::compare_op</a></span>, so that the applications can define their own comparisons with their own tags. A tag is an empty struct with:</p>


<ul class="doxyList ">
<li>a <span class="doxyComputerOutput">static constexpr const char* symbol</span>, written between the operands in the failure reports, with the surrounding spaces (for example <span class="doxyComputerOutput">" divides "</span>);</li>
<li>a static <span class="doxyComputerOutput">apply (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>)</span> member function template, which receives the unwrapped operands (the values of the <span class="doxyComputerOutput">to_*</span> wrappers and of the literals) and returns the result as <span class="doxyComputerOutput">bool</span>;</li>
<li>optionally, a <span class="doxyComputerOutput">static constexpr bool within_tolerance_result</span>; when present, and an operand is a floating-point wrapper (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/has-epsilon">extension::has_epsilon</a></span>), the operands within the tolerance give this result, as for the built-in comparators; when absent, the tolerance is ignored.</li>
</ul>

<p>The operands are not copied: the temporaries are moved into the comparator, and the named operands of class type are referred to (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a85cd019d0861a4b6d62c3424f4a8931d">stored_operand_t</a></span>). A comparator built in a function from its <span class="doxyComputerOutput">const&amp;</span> parameters refers to the arguments of that function, so it must be checked in the statement that calls the function.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the stored left-hand operand, either the operand type, or a <span class="doxyComputerOutput">const</span> reference to it.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the stored right-hand operand, either the operand type, or a <span class="doxyComputerOutput">const</span> reference to it.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Compare_T</td>
<td class="doxyParamItemDescription"><p>The tag that defines the comparison.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 753 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxySectionDef">

## Public Member Typedefs

### op\_type {#a384b1d115e493d6a554ebda4e3089b19}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div>
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

### compare\_op() {#a72f34185e1d681ad6874c8564c03a2a4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class L, class R&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::compare_op&lt; Lhs_T, Rhs_T, Compare_T &gt;::compare_op (L &amp;&amp; lhs, R &amp;&amp; rhs, Compare_T)</td>
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

<p>Constructs a comparator for the given operands.</p>


<p>The result is computed from the arguments, before they are forwarded to the base. The tag argument is used only to deduce <span class="doxyComputerOutput">Compare_T</span>.</p>


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

<p>Evaluates the comparison inside an immediately invoked lambda, which converts the result of <span class="doxyComputerOutput">Compare_T::apply()</span> to <span class="doxyComputerOutput">bool</span>, and passes it to the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op">binary_op</a></span> base class constructor:</p>


<ul class="doxyList ">
<li>for the framework constants with static <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a></span> members (the numeric literals), the two values are compared directly;</li>
<li>if at least one operand is a framework floating-point wrapper with an <span class="doxyComputerOutput">epsilon</span> member, and the tag defines a <span class="doxyComputerOutput">within_tolerance_result</span> (all the built-in tags do), operands within the tolerance give this result; otherwise the unwrapped values are compared; the tags of the application without it ignore the tolerance;</li>
<li>for all other types, the framework wrappers are unwrapped, and the values, including the types of the application, are compared as they are.</li>
</ul>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00770">770</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00370">370</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a72f34185e1d681ad6874c8564c03a2a4">370</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> <a href="#a72f34185e1d681ad6874c8564c03a2a4">compare_op&lt;Lhs_T, Rhs_T, Compare_T&gt;::compare_op</a> (L&amp;&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">371</span><span class="doxyLineContent"><span class="doxyHighlight">                                                               R&amp;&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">372</span><span class="doxyLineContent"><span class="doxyHighlight">                                                               Compare_T)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">373</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">binary_op</a>&lt;Lhs_T, Rhs_T&gt;{ std::forward&lt;L&gt; (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">                                   std::forward&lt;R&gt; (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>), [&amp;] () -&gt; </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">375</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">376</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The result is computed before the arguments are moved, since</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">377</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// the base constructor is entered only after all its arguments</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">378</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// are evaluated.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">379</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight">lhs_type = std::remove_cvref_t&lt;L&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">380</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">using </span><span class="doxyHighlight">rhs_type = std::remove_cvref_t&lt;R&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">381</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">382</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/has-value">detail::has_value&lt;lhs_type&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">383</span><span class="doxyLineContent"><span class="doxyHighlight">                      and <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/has-value">detail::has_value&lt;rhs_type&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">384</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">385</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> Compare_T::apply (lhs_type::value, rhs_type::value);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">386</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">387</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> ((<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/has-epsilon">extension::has_epsilon&lt;lhs_type&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">388</span><span class="doxyLineContent"><span class="doxyHighlight">                            or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/has-epsilon">extension::has_epsilon&lt;rhs_type&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">389</span><span class="doxyLineContent"><span class="doxyHighlight">                           and </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">390</span><span class="doxyLineContent"><span class="doxyHighlight">                                 Compare_T::within_tolerance_result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">391</span><span class="doxyLineContent"><span class="doxyHighlight">                               })</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">392</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">393</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6c5237ff6944278e8c5e3294cf99a3b9">detail::within_tolerance</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">394</span><span class="doxyLineContent"><span class="doxyHighlight">                       ? Compare_T::within_tolerance_result</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">395</span><span class="doxyLineContent"><span class="doxyHighlight">                       : Compare_T::apply (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlight">                                           <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">397</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">400</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> Compare_T::apply (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">lhs</a>),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">401</span><span class="doxyLineContent"><span class="doxyHighlight">                                     <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">rhs</a>));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">402</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">403</span><span class="doxyLineContent"><span class="doxyHighlight">      }() }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">404</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">405</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">micro_os_plus::micro_test_plus::detail::unwrap</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6c5237ff6944278e8c5e3294cf99a3b9">micro_os_plus::micro_test_plus::detail::within_tolerance</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator bool() {#ae9bf4f9ead2b8a63695988d37aa6f6f7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00350">350</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00165">165</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">    operator bool ()</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

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
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00364">364</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00178">178</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">178</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">binary_op&lt;Lhs_T, Rhs_T&gt;::lhs</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">lhs_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs_</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">micro_os_plus::micro_test_plus::detail::unwrap</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op/#a3a37dcd754e3d79a0db8479afe00a6c8">micro_os_plus::micro_test_plus::detail::and_op&lt; Lhs_T, Rhs_T &gt;::and_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op/#a5b53c23cc06ec1d830f7a99ddcb26259">micro_os_plus::micro_test_plus::detail::approx_op&lt; Lhs_T, Rhs_T, Epsilon_T &gt;::approx_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a>, <a href="#a72f34185e1d681ad6874c8564c03a2a4">micro_os_plus::micro_test_plus::detail::compare_op&lt; Lhs_T, Rhs_T, Compare_T &gt;::compare_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op/#af76c42f67671cf8657d3c104383c0818">micro_os_plus::micro_test_plus::detail::or_op&lt; Lhs_T, Rhs_T &gt;::or_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs</a>.</p>

</div>
</div>

### rhs() {#ae1436f1b38c1062f7c733d3e8cb39b87}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div>
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


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00378">378</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h/#l00191">191</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">191</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">binary_op&lt;Lhs_T, Rhs_T&gt;::rhs</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">detail::unwrap</a> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">rhs_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs_</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a59eb53c96f68d26635c13df53b358ac8">micro_os_plus::micro_test_plus::detail::unwrap</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-op/#a3a37dcd754e3d79a0db8479afe00a6c8">micro_os_plus::micro_test_plus::detail::and_op&lt; Lhs_T, Rhs_T &gt;::and_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/approx-op/#a5b53c23cc06ec1d830f7a99ddcb26259">micro_os_plus::micro_test_plus::detail::approx_op&lt; Lhs_T, Rhs_T, Epsilon_T &gt;::approx_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a>, <a href="#a72f34185e1d681ad6874c8564c03a2a4">micro_os_plus::micro_test_plus::detail::compare_op&lt; Lhs_T, Rhs_T, Compare_T &gt;::compare_op</a>, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-op/#af76c42f67671cf8657d3c104383c0818">micro_os_plus::micro_test_plus::detail::or_op&lt; Lhs_T, Rhs_T &gt;::or_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### lhs\_ {#ac21255b7b6b6d4b9c71522cc997a5fc2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div>
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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00390">390</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">390</a></span><span class="doxyLineContent"><span class="doxyHighlight">      Lhs_T <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ac21255b7b6b6d4b9c71522cc997a5fc2">lhs_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a27b015b0e2b40e0f0bbb1b08588e1c20">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::lhs</a>.</p>

</div>
</div>

### rhs\_ {#a3111bc24739599066db41c6a5023672b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div>
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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00398">398</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">398</a></span><span class="doxyLineContent"><span class="doxyHighlight">      Rhs_T <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a3111bc24739599066db41c6a5023672b">rhs_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#a33a6b26e134e3403ea52fcaf9ce92691">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::binary_op</a> and <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#ae1436f1b38c1062f7c733d3e8cb39b87">micro_os_plus::micro_test_plus::detail::binary_op&lt; Lhs_T, Rhs_T &gt;::rhs</a>.</p>

</div>
</div>

### value\_ {#abbe4c20d03a94cac1a942d8e3af65aea}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T, class Compare_T&gt;</div>
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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h/#l00406">406</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">406</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/binary-op/#abbe4c20d03a94cac1a942d8e3af65aea">value_</a>{};</span></span></div>

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
