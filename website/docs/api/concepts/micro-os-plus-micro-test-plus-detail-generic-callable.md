---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/generic-callable
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `generic_callable` Concept

<p>Concept satisfied by a callable object whose call operator is not a single non-template member function. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;typename Callable_T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/generic-callable">micro_os_plus::micro_test_plus::detail::generic_callable</a> =  std::is_class_v&lt;std::decay_t&lt;Callable_T&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&amp;&amp; (!requires { &amp;std::decay_t&lt;Callable_T&gt;::operator(); })
</div>

## Description {#details}

<p>Concept satisfied by a callable object whose call operator is not a single non-template member function.</p>


<p>The generic lambdas (<span class="doxyComputerOutput">[] (auto&amp; t) { ... }</span>), the function objects with a template or an overloaded call operator, and the classes without a call operator. To find out whether such an object can be invoked, the compiler must instantiate its body to deduce the return type, and an error in the body becomes an error of the check, with its own long trace; so the bodies of the tests and of the suites that satisfy this concept are not checked for invocability, and an error is reported where the body is invoked.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 1179 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">generic_callable = std::is_class_v&lt;std::decay_t&lt;Callable_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          &amp;&amp; (!</span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> { &amp;std::decay_t&lt;Callable_T&gt;::operator(); })</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.6 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
