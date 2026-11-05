---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/character
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `character` Concept

<p>Concept satisfied by the character types. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/character">micro_os_plus::micro_test_plus::detail::character</a> =  std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, char&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, wchar_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, char8_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, char16_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, char32_t&gt;
</div>

## Description {#details}

<p>Concept satisfied by the character types.</p>


<p>The <span class="doxyComputerOutput">character</span> concept is satisfied when the type, ignoring the cv-qualifiers, is one of <span class="doxyComputerOutput">char</span>, <span class="doxyComputerOutput">wchar_t</span>, <span class="doxyComputerOutput">char8_t</span>, <span class="doxyComputerOutput">char16_t</span>, or <span class="doxyComputerOutput">char32_t</span>. The comparators compare the arrays and the pointers of these types as strings (see <span class="doxyComputerOutput">basic_c_string</span>); <span class="doxyComputerOutput">signed char</span> and <span class="doxyComputerOutput">unsigned char</span> are not characters, but bytes.</p>


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

<p>Definition at line 1623 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">character = std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                        or std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">wchar_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                        or std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">char8_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                        or std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">char16_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                        or std::is_same_v&lt;std::remove_cv_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlight">&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
