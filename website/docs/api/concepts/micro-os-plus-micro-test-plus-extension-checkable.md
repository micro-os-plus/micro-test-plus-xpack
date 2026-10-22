---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/extension/checkable
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `checkable` Concept

<p>C++20 concept satisfied when a type can be used as a test expression in <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">micro_os_plus::micro_test_plus::extension::checkable</a> =  is_op&lt;T&gt; or requires (const T&amp; t) { t ? true : false; }
</div>

## Description {#details}

<p>C++20 concept satisfied when a type can be used as a test expression in <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>.</p>


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

<p>The <span class="doxyComputerOutput">checkable</span> concept is satisfied when <span class="doxyComputerOutput">T</span> is either a framework expression type (see <span class="doxyComputerOutput">is_op</span>) or a type contextually convertible to <span class="doxyComputerOutput">bool</span>, as the condition of an <span class="doxyComputerOutput">if</span> statement is. This includes the types with an <span class="doxyComputerOutput">explicit operator bool</span>, such as <span class="doxyComputerOutput">std::optional</span>, <span class="doxyComputerOutput">std::unique_ptr</span>, <span class="doxyComputerOutput">std::shared_ptr</span>, and <span class="doxyComputerOutput">std::function</span>, but not the scoped enumerations, which only a cast converts. It is used to constrain the <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span> function templates, ensuring that only sensible expression types are accepted; an application helper that forwards its argument to them uses it for the same constraint.</p>


<p>The condition of the conditional operator, which cannot be overloaded, is used to test the contextual conversion, applied to a <span class="doxyComputerOutput">const</span> value, as <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span> receive it.</p>


<p>Definition at line 220 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">checkable = is_op&lt;T&gt; or </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t) { t ? true : </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">; }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.4 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
