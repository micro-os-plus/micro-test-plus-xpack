---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/extension/suspicious-condition
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `suspicious_condition` Concept

<p>C++20 concept satisfied when a type is contextually convertible to <span class="doxyComputerOutput">bool</span>, but is most likely not a condition. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/suspicious-condition">micro_os_plus::micro_test_plus::extension::suspicious_condition</a> =  std::is_array_v&lt;T&gt; or std::is_function_v&lt;T&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_member_pointer_v&lt;T&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or (std::is_pointer_v&lt;T&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and (std::is_function_v&lt;std::remove_pointer_t&lt;T&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, char&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, wchar_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, char8_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, char16_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or std::is_same_v&lt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, char32_t&gt;))
</div>

## Description {#details}

<p>C++20 concept satisfied when a type is contextually convertible to <span class="doxyComputerOutput">bool</span>, but is most likely not a condition.</p>


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

<p>The <span class="doxyComputerOutput">suspicious_condition</span> concept is satisfied by the arrays (including the string literals), the functions, the pointers to functions and to members, and the pointers to the character types. All of them are contextually convertible to <span class="doxyComputerOutput">bool</span>, so, when passed to <span class="doxyComputerOutput">expect()</span> or <span class="doxyComputerOutput">require()</span>, the check silently passes, usually because the description was written instead of the condition, or because a function name was written without the call. The pointers to other object types are not included, since checking a pointer for null is a legitimate use.</p>


<p>Definition at line 217 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">suspicious_condition = std::is_array_v&lt;T&gt; or std::is_function_v&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          or std::is_member_pointer_v&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          or (std::is_pointer_v&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">              and (std::is_function_v&lt;std::remove_pointer_t&lt;T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                   or std::is_same_v&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                       std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                   or std::is_same_v&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                       std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, </span><span class="doxyHighlightKeywordType">wchar_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                   or std::is_same_v&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                       std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, </span><span class="doxyHighlightKeywordType">char8_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                   or std::is_same_v&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                       std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, </span><span class="doxyHighlightKeywordType">char16_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                   or std::is_same_v&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                       std::remove_cv_t&lt;std::remove_pointer_t&lt;T&gt;&gt;, </span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlight">&gt;))</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
