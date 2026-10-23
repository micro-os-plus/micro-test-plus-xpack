---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/approx-operand
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `approx_operand` Concept

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a valid operand of the approximate comparator. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/approx-operand">micro_os_plus::micro_test_plus::detail::approx_operand</a> =  std::is_arithmetic_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a2c197674df5b07499a4ea40d124f1082">unwrapped_t</a>&lt;T&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and not std::is_same_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a2c197674df5b07499a4ea40d124f1082">unwrapped_t</a>&lt;T&gt;, bool&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and not std::is_same_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a2c197674df5b07499a4ea40d124f1082">unwrapped_t</a>&lt;T&gt;, char&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and not std::is_same_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a2c197674df5b07499a4ea40d124f1082">unwrapped_t</a>&lt;T&gt;, wchar_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and not std::is_same_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a2c197674df5b07499a4ea40d124f1082">unwrapped_t</a>&lt;T&gt;, char8_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and not std::is_same_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a2c197674df5b07499a4ea40d124f1082">unwrapped_t</a>&lt;T&gt;, char16_t&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and not std::is_same_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a2c197674df5b07499a4ea40d124f1082">unwrapped_t</a>&lt;T&gt;, char32_t&gt;
</div>

## Description {#details}

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a valid operand of the approximate comparator.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type to be checked, possibly a reference.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The <span class="doxyComputerOutput">approx_operand</span> concept is satisfied when <span class="doxyComputerOutput">T</span>, or the value it wraps (for the framework value wrappers and the numeric literals), is an arithmetic type other than <span class="doxyComputerOutput">bool</span> and the character types (<span class="doxyComputerOutput">char</span>, <span class="doxyComputerOutput">wchar_t</span>, <span class="doxyComputerOutput">char8_t</span>, <span class="doxyComputerOutput">char16_t</span>, and <span class="doxyComputerOutput">char32_t</span>), which are not numbers; <span class="doxyComputerOutput">signed char</span> and <span class="doxyComputerOutput">unsigned char</span> are accepted, as the integer types they are.</p>


<p>Definition at line 819 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/detail-h">detail.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">approx_operand = std::is_arithmetic_v&lt;unwrapped_t&lt;T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                             and not std::is_same_v&lt;unwrapped_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                             and not std::is_same_v&lt;unwrapped_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                             and not std::is_same_v&lt;unwrapped_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">wchar_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                             and not std::is_same_v&lt;unwrapped_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">char8_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                             and not std::is_same_v&lt;unwrapped_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">char16_t</span><span class="doxyHighlight">&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                             and not std::is_same_v&lt;unwrapped_t&lt;T&gt;, </span><span class="doxyHighlightKeywordType">char32_t</span><span class="doxyHighlight">&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
