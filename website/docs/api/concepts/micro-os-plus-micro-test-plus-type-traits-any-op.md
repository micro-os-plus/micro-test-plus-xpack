---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/type-traits/any-op
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `any_op` Concept

<p>C++20 concept satisfied when at least one of two types derives from <span class="doxyComputerOutput">op</span>. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class Lhs_T, class Rhs_T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/any-op">micro_os_plus::micro_test_plus::type_traits::any_op</a> =  is_op&lt;Lhs_T&gt; or is_op&lt;Rhs_T&gt;
</div>

## Description {#details}

<p>C++20 concept satisfied when at least one of two types derives from <span class="doxyComputerOutput">op</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the left-hand operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the right-hand operand.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The <span class="doxyComputerOutput">any_op</span> concept is satisfied when <span class="doxyComputerOutput">Lhs_T</span> or <span class="doxyComputerOutput">Rhs_T</span> (or both) are derived from the <span class="doxyComputerOutput">type_traits::op</span> base struct. It is used to constrain binary operator overloads in the <span class="doxyComputerOutput">operators</span> namespace so that they are enabled only when at least one operand is a framework type, avoiding unintended conflicts with user-defined operators.</p>


<p>Definition at line 454 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">any_op = is_op&lt;Lhs_T&gt; or is_op&lt;Rhs_T&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
