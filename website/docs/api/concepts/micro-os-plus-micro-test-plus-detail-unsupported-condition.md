---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/unsupported-condition
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `unsupported_condition` Concept

<p>Concept satisfied by a value that <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span> do not accept. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/unsupported-condition">micro_os_plus::micro_test_plus::detail::unsupported_condition</a> =  (not extension::checkable&lt;T&gt;) and (not detail::legacy_checkable&lt;T&gt;)
</div>

## Description {#details}

<p>Concept satisfied by a value that <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span> do not accept.</p>


<p>A value that is neither a framework expression type nor contextually convertible to <span class="doxyComputerOutput">bool</span>, for example a <span class="doxyComputerOutput">std::string</span>, and, if the deprecated functionality is not enabled, the string literals, the arrays, and the function names, which only the deprecated overloads accept. Selects the overloads that stop the compilation with a message that states what the functions take.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the value.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 1238 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">unsupported_condition = (not extension::checkable&lt;T&gt;) and (not detail::legacy_checkable&lt;T&gt;)</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
