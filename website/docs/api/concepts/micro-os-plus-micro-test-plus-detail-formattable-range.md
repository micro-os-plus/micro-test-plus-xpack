---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/formattable-range
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `formattable_range` Concept

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a range that the formatter writes element by element. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/formattable-range">micro_os_plus::micro_test_plus::detail::formattable_range</a> =  (container_like&lt;T&gt; or free_range&lt;T&gt;) and (not std::is_array_v&lt;T&gt;)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and (not has_npos&lt;T&gt;)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and (not std::is_same_v&lt;typename <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/range-element">range_element</a>&lt;T&gt;::type, T&gt;)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and extension::printable&lt;typename <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/range-element">range_element</a>&lt;T&gt;::type&gt;
</div>

## Description {#details}

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a range that the formatter writes element by element.</p>


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

<p>The <span class="doxyComputerOutput">formattable_range</span> concept is satisfied when <span class="doxyComputerOutput">T</span> can be iterated by a range-based <span class="doxyComputerOutput">for</span> statement, with <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> members (<span class="doxyComputerOutput">container_like</span>) or functions (<span class="doxyComputerOutput">free_range</span>), and:</p>


<ul class="doxyList ">
<li>is not an array, since the arrays are compared by address, and are written as addresses, as the pointers they decay to;</li>
<li>is not a string (see <span class="doxyComputerOutput">has_npos</span>), which is written as text;</li>
<li>does not have elements of its own type, like <span class="doxyComputerOutput">std::filesystem::path</span>, whose elements are paths, so that formatting it would recurse without end;</li>
<li>has elements that satisfy <span class="doxyComputerOutput">extension::printable</span>, so that a range of elements that cannot be reported is rejected where it is compared, not where its elements are formatted.</li>
</ul>

<p>The conditions are tested in this order, so the elements of a recursive range are not tested.</p>


<p>Definition at line 394 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">formattable_range = (container_like&lt;T&gt; or free_range&lt;T&gt;) and (not std::is_array_v&lt;T&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and (not has_npos&lt;T&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and (not std::is_same_v&lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> range_element&lt;T&gt;::type, T&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and extension::printable&lt;typename range_element&lt;T&gt;::type&gt;</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.4 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
