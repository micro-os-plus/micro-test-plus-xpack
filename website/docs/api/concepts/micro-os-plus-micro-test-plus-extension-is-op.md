---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/extension/is-op
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `is_op` Concept

<p>C++20 concept satisfied when a type is a framework expression type. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">micro_os_plus::micro_test_plus::extension::is_op</a> =  requires { requires std::same_as&lt;typename T::op_type, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/op">detail::op</a>&gt;; }
</div>

## Description {#details}

<p>C++20 concept satisfied when a type is a framework expression type.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type to be checked.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The <span class="doxyComputerOutput">is_op</span> concept is satisfied when <span class="doxyComputerOutput">T</span> has the <span class="doxyComputerOutput">op_type</span> member type alias of <span class="doxyComputerOutput">detail::op</span>, either inherited from the <span class="doxyComputerOutput">detail::op</span> base struct, or declared directly, like in <span class="doxyComputerOutput">detail::value_base</span>, which avoids the empty base. It is used throughout the framework, both as a constraint and as a boolean expression in <span class="doxyComputerOutput">if constexpr</span> contexts.</p>


<p>A custom comparator or operator uses it to tell the framework operands, like <span class="doxyComputerOutput">to_i</span> or the <span class="doxyComputerOutput">_i</span> literals, from the types of the application. The applications build their own expressions with <span class="doxyComputerOutput">extension::compare_op</span> and <span class="doxyComputerOutput">extension::predicate_op</span>, not by declaring the <span class="doxyComputerOutput">op_type</span> marker, which the formatter could not report.</p>


<p>Definition at line 156 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">is_op = </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> { </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> std::same_as&lt;typename T::op_type, detail::op&gt;; }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
