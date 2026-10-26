---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/extension/printable
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `printable` Concept

<p>C++20 concept satisfied when a type can be appended to the message of a check result via <span class="doxyComputerOutput">operator&lt;&lt;</span>. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">micro_os_plus::micro_test_plus::extension::printable</a> =  requires (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">detail::expression_formatter</a>&amp; formatter,<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;const T&amp; value) { formatter &lt;&lt; value; }
</div>

## Description {#details}

<p>C++20 concept satisfied when a type can be appended to the message of a check result via <span class="doxyComputerOutput">operator&lt;&lt;</span>.</p>


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

<p>The <span class="doxyComputerOutput">printable</span> concept is satisfied when a value of type <span class="doxyComputerOutput">T</span> can be written to an <span class="doxyComputerOutput">expression_formatter</span>, so the message of a check accepts the same values as the operands of the comparators: the strings, the characters, the arithmetic types, <span class="doxyComputerOutput">std::nullptr_t</span>, the pointers, the containers, the scoped enumerations, the pairs, the tuples, the optionals, the value wrappers, and the application types with an <span class="doxyComputerOutput">operator&lt;&lt;</span> for the formatter, found by argument-dependent lookup. It constrains the <span class="doxyComputerOutput">operator&lt;&lt;</span> overload of <span class="doxyComputerOutput">check_result</span>, which also accepts the callable objects that return a printable value, called only if the check fails; an application helper that forwards a value to the message uses it for the same constraint.</p>


<p>The formatter is only declared here; the concept is checked where it is used, after <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/expression-formatter-h">expression-formatter.h</a></span> was included.</p>


<p>Definition at line 305 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">printable = </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (detail::expression_formatter&amp; formatter,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; value) { formatter &lt;&lt; value; }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
