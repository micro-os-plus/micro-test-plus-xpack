---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/extension/legacy-checkable
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `legacy_checkable` Concept

<p>C++20 concept satisfied when a type was accepted by <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span> before the exclusion of the suspicious conditions. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/legacy-checkable">micro_os_plus::micro_test_plus::extension::legacy_checkable</a> =  (not checkable&lt;T&gt;) and suspicious_condition&lt;T&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and requires (const T&amp; t) { t ? true : false; }
</div>

## Description {#details}

<p>C++20 concept satisfied when a type was accepted by <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span> before the exclusion of the suspicious conditions.</p>


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

<p>Satisfied by the types that are contextually convertible to <span class="doxyComputerOutput">bool</span> but are not <span class="doxyComputerOutput">checkable</span>, i.e. the <span class="doxyComputerOutput">suspicious_condition</span> types. It constrains the deprecated overloads of <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span>, which keep such code compiling for one release, with a warning.</p>


<p>Definition at line 278 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">legacy_checkable = (not checkable&lt;T&gt;) and suspicious_condition&lt;T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                               and </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t) { t ? true : </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">; }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
