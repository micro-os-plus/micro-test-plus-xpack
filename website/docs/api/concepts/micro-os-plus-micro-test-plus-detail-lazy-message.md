---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/lazy-message
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `lazy_message` Concept

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a callable object that returns a printable message. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/lazy-message">micro_os_plus::micro_test_plus::detail::lazy_message</a> =  std::is_class_v&lt;T&gt; and std::invocable&lt;const T&amp;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and (not std::is_void_v&lt;std::invoke_result_t&lt;const T&amp;&gt;&gt;)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and extension::printable&lt;std::invoke_result_t&lt;const T&amp;&gt;&gt;
</div>

## Description {#details}

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a callable object that returns a printable message.</p>


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

<p>The <span class="doxyComputerOutput">lazy_message</span> concept is satisfied when <span class="doxyComputerOutput">T</span> is a class type, such as a lambda or a <span class="doxyComputerOutput">std::function</span>, callable without arguments as a <span class="doxyComputerOutput">const</span> object, whose result is not <span class="doxyComputerOutput">void</span> and satisfies <span class="doxyComputerOutput">extension::printable</span>. The message operator of the checks calls such an object only when the check fails, and appends its result, so that a message that is valid only after a failure (the error of a <span class="doxyComputerOutput">std::expected</span>, for example) is not evaluated after a success.</p>


<p>The function pointers are excluded, since they are printable (as addresses), and calling them by mistake could have side effects; a lambda without captures, which converts to a function pointer and then to <span class="doxyComputerOutput">bool</span>, is printable too, and is called, since it is a class type.</p>


<p>Definition at line 486 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">lazy_message = std::is_class_v&lt;T&gt; and std::invocable&lt;const T&amp;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and (not std::is_void_v&lt;std::invoke_result_t&lt;const T&amp;&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and extension::printable&lt;std::invoke_result_t&lt;const T&amp;&gt;&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
