---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/extension/compare-tag
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `compare_tag` Concept

<p>Concept satisfied by a tag that defines a custom comparator. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class Tag_T, class Lhs_T, class Rhs_T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/compare-tag">micro_os_plus::micro_test_plus::extension::compare_tag</a> =  requires (const Lhs_T&amp; lhs, const Rhs_T&amp; rhs) {<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;requires printable&lt;std::remove_cvref_t&lt;decltype (Tag_T::symbol)&gt;&gt;;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{ Tag_T::apply (lhs, rhs) } -&gt; std::convertible_to&lt;bool&gt;;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;}
</div>

## Description {#details}

<p>Concept satisfied by a tag that defines a custom comparator.</p>


<p>The tag of <span class="doxyComputerOutput">extension::compare_op</span> is a structure with a static <span class="doxyComputerOutput">symbol</span>, which the failure reports write between the two operands, and a static <span class="doxyComputerOutput">apply()</span> member function template, which receives the operands, unwrapped, and returns the result of the comparison. The <span class="doxyComputerOutput">symbol</span> must be printable, usually a <span class="doxyComputerOutput">const char*</span> that includes the surrounding spaces; the result of <span class="doxyComputerOutput">apply()</span> must be convertible to <span class="doxyComputerOutput">bool</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Tag_T</td>
<td class="doxyParamItemDescription"><p>The type of the tag.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the left hand side operand, as <span class="doxyComputerOutput">apply()</span> receives it.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the right hand side operand, as <span class="doxyComputerOutput">apply()</span> receives it.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 456 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Tag_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">compare_tag = </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Lhs_T&amp; lhs, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Rhs_T&amp; rhs) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> printable&lt;std::remove_cvref_t&lt;</span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (Tag_T::symbol)&gt;&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      { Tag_T::apply (lhs, rhs) } -&gt; std::convertible_to&lt;bool&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
