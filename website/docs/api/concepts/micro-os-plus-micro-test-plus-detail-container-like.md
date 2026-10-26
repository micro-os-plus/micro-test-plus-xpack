---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/container-like
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `container_like` Concept

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides both <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> member functions returning an iterator and its sentinel. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/container-like">micro_os_plus::micro_test_plus::detail::container_like</a> =  requires (const T&amp; t) {<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;requires std::input_or_output_iterator&lt;decltype (t.begin ())&gt;;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;requires std::sentinel_for&lt;decltype (t.end ()), decltype (t.begin ())&gt;;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;}
</div>

## Description {#details}

<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides both <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> member functions returning an iterator and its sentinel.</p>


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

<p>The <span class="doxyComputerOutput">container_like</span> concept is satisfied when <span class="doxyComputerOutput">T</span> exposes both a <span class="doxyComputerOutput">begin()</span> and an <span class="doxyComputerOutput">end()</span> member function, as required by standard range-based iteration, and <span class="doxyComputerOutput">begin()</span> returns a <span class="doxyComputerOutput">std::input_or_output_iterator</span> for which <span class="doxyComputerOutput">end()</span> returns a <span class="doxyComputerOutput">std::sentinel_for</span>. The check is part of the concept, so a type whose <span class="doxyComputerOutput">begin()</span> and <span class="doxyComputerOutput">end()</span> return something else (<span class="doxyComputerOutput">void</span>, for example) is not a container, instead of being a hard error where the element type is formed. It is used to detect the ranges that the formatter writes element by element (see <span class="doxyComputerOutput">formattable_range</span>), and the ranges of values of <span class="doxyComputerOutput">test_each()</span>.</p>


<p>Definition at line 337 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">container_like = </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> std::input_or_output_iterator&lt;</span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (t.begin ())&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> std::sentinel_for&lt;</span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (t.end ()), </span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (t.begin ())&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
