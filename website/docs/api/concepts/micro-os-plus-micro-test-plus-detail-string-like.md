---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/string-like
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `string_like` Concept

<p>Concept satisfied when <span class="doxyComputerOutput">T</span> is a string, convertible to a <span class="doxyComputerOutput">std::basic_string_view</span> of a character type. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/string-like">micro_os_plus::micro_test_plus::detail::string_like</a> =  std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;char&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;wchar_t&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;char8_t&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;char16_t&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;char32_t&gt;&gt;
</div>

## Description {#details}

<p>Concept satisfied when <span class="doxyComputerOutput">T</span> is a string, convertible to a <span class="doxyComputerOutput">std::basic_string_view</span> of a character type.</p>


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

<p>The <span class="doxyComputerOutput">string_like</span> concept is satisfied when a <span class="doxyComputerOutput">const</span> object of type <span class="doxyComputerOutput">T</span> is implicitly convertible to a <span class="doxyComputerOutput">std::basic_string_view</span> of <span class="doxyComputerOutput">char</span>, <span class="doxyComputerOutput">wchar_t</span>, <span class="doxyComputerOutput">char8_t</span>, <span class="doxyComputerOutput">char16_t</span>, or <span class="doxyComputerOutput">char32_t</span>, as the standard strings and the string views are. It is used to detect the strings, which the formatter writes as text, not element by element (see <span class="doxyComputerOutput">formattable_range</span>). A container that has only a member named <span class="doxyComputerOutput">npos</span>, or that is not convertible, is not a string.</p>


<p>Definition at line 547 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">string_like = std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;char&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          or std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;wchar_t&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          or std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;char8_t&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          or std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;char16_t&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          or std::convertible_to&lt;const T&amp;, std::basic_string_view&lt;char32_t&gt;&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
