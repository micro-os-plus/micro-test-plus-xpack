---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/function-pointer-pair
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `function_pointer_pair` Concept

<p>Concept satisfied by two pointers, one of which points to a function. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class Lhs_T, class Rhs_T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/function-pointer-pair">micro_os_plus::micro_test_plus::detail::function_pointer_pair</a> =  std::is_pointer_v&lt;Lhs_T&gt; and std::is_pointer_v&lt;Rhs_T&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and (std::is_function_v&lt;std::remove_pointer_t&lt;Lhs_T&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_function_v&lt;std::remove_pointer_t&lt;Rhs_T&gt;&gt;)
</div>

## Description {#details}

<p>Concept satisfied by two pointers, one of which points to a function.</p>


<p>The comparison of a function pointer with an object pointer, such as a <span class="doxyComputerOutput">void*</span>, is an extension of the compilers, accepted with a warning, which the library silences, but not by the checks of the concepts that follow; the comparators keep accepting it.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 322 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">function_pointer_pair = std::is_pointer_v&lt;Lhs_T&gt; and std::is_pointer_v&lt;Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and (std::is_function_v&lt;std::remove_pointer_t&lt;Lhs_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">               or std::is_function_v&lt;std::remove_pointer_t&lt;Rhs_T&gt;&gt;)</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
