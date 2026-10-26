---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/extension/has-epsilon
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `has_epsilon` Concept

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a framework floating-point wrapper with a tolerance. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/has-epsilon">micro_os_plus::micro_test_plus::extension::has_epsilon</a> =  is_op&lt;T&gt; and requires (const T&amp; t) { t.epsilon; }
</div>

## Description {#details}

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a framework floating-point wrapper with a tolerance.</p>


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

<p>The <span class="doxyComputerOutput">has_epsilon</span> concept is satisfied when <span class="doxyComputerOutput">T</span> is a framework expression type (see <span class="doxyComputerOutput">is_op</span>) with an <span class="doxyComputerOutput">epsilon</span> member, like <span class="doxyComputerOutput">floating_point_constant</span> and the floating-point specialisation of <span class="doxyComputerOutput">value&lt;T&gt;</span>. The comparators treat the operands within this tolerance as equal; a custom comparator uses it to do the same.</p>


<p>The types of the application are excluded, even if they have a member named <span class="doxyComputerOutput">epsilon</span>, so that they are compared with their own operators.</p>


<p>Definition at line 177 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">has_epsilon = is_op&lt;T&gt; and </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t) { t.epsilon; }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
