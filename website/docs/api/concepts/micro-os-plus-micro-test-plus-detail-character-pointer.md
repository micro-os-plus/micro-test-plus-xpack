---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/character-pointer
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `character_pointer` Concept

<p>Concept satisfied by the pointers to the character types. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/character-pointer">micro_os_plus::micro_test_plus::detail::character_pointer</a> =  std::is_pointer_v&lt;T&gt; and character&lt;std::remove_pointer_t&lt;T&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and not std::is_volatile_v&lt;std::remove_pointer_t&lt;T&gt;&gt;
</div>

## Description {#details}

<p>Concept satisfied by the pointers to the character types.</p>


<p>The <span class="doxyComputerOutput">character_pointer</span> concept is satisfied when the type is a pointer to a <span class="doxyComputerOutput">character</span>, possibly <span class="doxyComputerOutput">const</span>, but not <span class="doxyComputerOutput">volatile</span>. The formatter writes these pointers as C strings, and <span class="doxyComputerOutput">located_name</span> takes them as names.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type to check.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 1642 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">character_pointer = std::is_pointer_v&lt;T&gt; and character&lt;std::remove_pointer_t&lt;T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and not std::is_volatile_v&lt;std::remove_pointer_t&lt;T&gt;&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
