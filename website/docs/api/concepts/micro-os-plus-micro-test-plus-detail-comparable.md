---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/comparable
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `comparable` Concept

<p>Concept satisfied when two operands can be compared by the comparator selected by <span class="doxyComputerOutput">Op</span>. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ada744f2df815ad518c8b897608907c0b">comparison</a> Op, class Lhs_T, class Rhs_T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/comparable">micro_os_plus::micro_test_plus::detail::comparable</a> =  comparison_lookup::can_compare&lt;Op, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6bdf1e117e085a41c16e2dae63e72e52">comparison_operand_t</a>&lt;Lhs_T&gt;,<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6bdf1e117e085a41c16e2dae63e72e52">comparison_operand_t</a>&lt;Rhs_T&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or sign_mixed_integers&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6bdf1e117e085a41c16e2dae63e72e52">comparison_operand_t</a>&lt;Lhs_T&gt;,<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6bdf1e117e085a41c16e2dae63e72e52">comparison_operand_t</a>&lt;Rhs_T&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or function_pointer_pair&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6bdf1e117e085a41c16e2dae63e72e52">comparison_operand_t</a>&lt;Lhs_T&gt;,<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6bdf1e117e085a41c16e2dae63e72e52">comparison_operand_t</a>&lt;Rhs_T&gt;&gt;
</div>

## Description {#details}

<p>Concept satisfied when two operands can be compared by the comparator selected by <span class="doxyComputerOutput">Op</span>.</p>


<p>The comparison is the one made by the <span class="doxyComputerOutput">apply()</span> function of the comparison tag: by value for the integers of different signedness (see <span class="doxyComputerOutput">sign_mixed_integers</span>), otherwise with the operator of the language. A function pointer compared with an object pointer is also accepted (see <span class="doxyComputerOutput">function_pointer_pair</span>). Used to reject the call of <span class="doxyComputerOutput">eq()</span> and of the other comparators at the call site, with a short diagnostic; the operator check is the first alternative, so that the Clang diagnostic names the invalid operator and the two types first (GCC reports only that no alternative is satisfied).</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Op</td>
<td class="doxyParamItemDescription"><p>The comparison.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The type deduced for the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The type deduced for the right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 507 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;comparison Op, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">comparable = comparison_lookup::can_compare&lt;Op, comparison_operand_t&lt;Lhs_T&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                                         comparison_operand_t&lt;Rhs_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          or sign_mixed_integers&lt;comparison_operand_t&lt;Lhs_T&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                                 comparison_operand_t&lt;Rhs_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          or function_pointer_pair&lt;comparison_operand_t&lt;Lhs_T&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                                   comparison_operand_t&lt;Rhs_T&gt;&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
