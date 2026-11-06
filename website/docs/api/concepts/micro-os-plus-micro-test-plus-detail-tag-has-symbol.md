---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/tag-has-symbol
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `tag_has_symbol` Concept

<p>Concept satisfied when the tag of a comparator or of a predicate has a symbol that can be written. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class Tag_T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/tag-has-symbol">micro_os_plus::micro_test_plus::detail::tag_has_symbol</a> =  requires {<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;requires extension::printable&lt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::remove_cvref_t&lt;decltype (Tag_T::symbol)&gt;&gt;;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;}
</div>

## Description {#details}

<p>Concept satisfied when the tag of a comparator or of a predicate has a symbol that can be written.</p>


<p>Satisfied when the tag has a static member <span class="doxyComputerOutput">symbol</span> that the formatter can write. Used by <span class="doxyComputerOutput">reject_compare_tag()</span> and by <span class="doxyComputerOutput">reject_predicate_tag()</span>, to tell a missing or unprintable symbol from a wrong <span class="doxyComputerOutput">apply()</span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Tag_T</td>
<td class="doxyParamItemDescription"><p>The tag of the comparator or of the predicate.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 753 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Tag_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">tag_has_symbol = </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> extension::printable&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          std::remove_cvref_t&lt;</span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (Tag_T::symbol)&gt;&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
