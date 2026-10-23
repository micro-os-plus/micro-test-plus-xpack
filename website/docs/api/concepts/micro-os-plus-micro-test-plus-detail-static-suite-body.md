---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `static_suite_body` Concept

<p>The body of a static suite written for v5.0.1, whose first parameter is a <span class="doxyComputerOutput">static_suite&amp;</span> reference. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;typename Callable_T, typename... Args_T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">micro_os_plus::micro_test_plus::detail::static_suite_body</a> =  (!std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp;,<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::decay_t&lt;Args_T&gt;&amp;...&gt;)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&amp;&amp; std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a>&amp;,<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;std::decay_t&lt;Args_T&gt;&amp;...&gt;
</div>

## Description {#details}

<p>The body of a static suite written for v5.0.1, whose first parameter is a <span class="doxyComputerOutput">static_suite&amp;</span> reference.</p>


<p>Satisfied by a callable that cannot be invoked with a <span class="doxyComputerOutput">suite&amp;</span> reference, but can be invoked with a <span class="doxyComputerOutput">static_suite&amp;</span> one, followed by the arguments as stored (decayed, non-<span class="doxyComputerOutput">const</span> lvalues). It selects the deprecated constructor of <span class="doxyComputerOutput">static_suite</span>; the callables that accept a <span class="doxyComputerOutput">suite&amp;</span> reference, including the generic lambdas, do not satisfy it.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Args_T</td>
<td class="doxyParamItemDescription"><p>The types of the callable arguments.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 1879 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">static_suite_body = (!std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, suite&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                                std::decay_t&lt;Args_T&gt;&amp;...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          &amp;&amp; std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, static_suite&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::decay_t&lt;Args_T&gt;&amp;...&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
