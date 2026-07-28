---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/type-traits/checkable
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `checkable` Concept

<p>C++20 concept satisfied when a type can be used as a test expression in <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">assume()</span>. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/checkable">micro_os_plus::micro_test_plus::type_traits::checkable</a> =  is_op&lt;T&gt; or std::convertible_to&lt;T, bool&gt;
</div>

## Description {#details}

<p>C++20 concept satisfied when a type can be used as a test expression in <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">assume()</span>.</p>


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

<p>The <span class="doxyComputerOutput">checkable</span> concept is satisfied when <span class="doxyComputerOutput">T</span> is either a framework operator type (derived from <span class="doxyComputerOutput">op</span>) or is implicitly convertible to <span class="doxyComputerOutput">bool</span>. It is used to constrain the <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">assume()</span> function templates, ensuring that only sensible expression types are accepted.</p>


<p>Definition at line 478 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/type-traits-h">type-traits.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">checkable = is_op&lt;T&gt; or std::convertible_to&lt;T, bool&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.1 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
