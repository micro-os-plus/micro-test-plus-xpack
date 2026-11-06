---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/ambiguous-condition
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `ambiguous_condition` Concept

<p>Concept satisfied by the wrappers of a <span class="doxyComputerOutput">bool</span>, whose condition is ambiguous. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/ambiguous-condition">micro_os_plus::micro_test_plus::detail::ambiguous_condition</a> =  <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/is-bool-wrapper">is_bool_wrapper</a>&lt;std::remove_cv_t&lt;T&gt;&gt;<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">::value</a>
</div>

## Description {#details}

<p>Concept satisfied by the wrappers of a <span class="doxyComputerOutput">bool</span>, whose condition is ambiguous.</p>


<p>The condition of a <span class="doxyComputerOutput">std::optional&lt;bool&gt;</span>, or of a smart pointer to a <span class="doxyComputerOutput">bool</span>, tests the wrapper (a value is present, or the pointer is not null), not the <span class="doxyComputerOutput">bool</span> that it holds, which is what a reader of <span class="doxyComputerOutput">t.expect (flag)</span> assumes; a check with <span class="doxyComputerOutput">false</span> inside would pass, and be reported as <span class="doxyComputerOutput">true</span>, for another reason than the one the author had in mind, as the checks of the arguments that are always true (see <span class="doxyComputerOutput">suspicious_condition</span>). A check that passes silently by mistake is worse than one that does not compile, so <span class="doxyComputerOutput">extension::checkable</span> rejects these types, and the application writes <span class="doxyComputerOutput">has_value()</span>, <span class="doxyComputerOutput">!= nullptr</span>, or compares the value with <span class="doxyComputerOutput">eq()</span>. The wrappers of the other types are accepted, since the presence of a value is then the only meaning of the condition.</p>


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

<p>Definition at line 216 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">ambiguous_condition = is_bool_wrapper&lt;std::remove_cv_t&lt;T&gt;&gt;::value</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
