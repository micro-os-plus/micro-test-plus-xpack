---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/extension/has-epsilon
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `has_epsilon` Concept

<p>Deprecated concept satisfied when <span class="doxyComputerOutput">T</span> is a framework floating-point wrapper with a tolerance. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/has-epsilon">micro_os_plus::micro_test_plus::extension::has_epsilon</a> =  is_op&lt;T&gt; and requires (const T&amp; t) { t.epsilon; }
</div>

## Description {#details}

<p>Deprecated concept satisfied when <span class="doxyComputerOutput">T</span> is a framework floating-point wrapper with a tolerance.</p>


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

<p>The <span class="doxyComputerOutput">has_epsilon</span> concept is satisfied when <span class="doxyComputerOutput">T</span> is a framework expression type (see <span class="doxyComputerOutput">is_op</span>) with an <span class="doxyComputerOutput">epsilon</span> member, like <span class="doxyComputerOutput">floating_point_constant</span> and the floating-point specialisation of <span class="doxyComputerOutput">value&lt;T&gt;</span>. The comparators treat the operands within this tolerance as equal; a custom comparator uses it to do the same.</p>


<p>The types of the application are excluded, even if they have a member named <span class="doxyComputerOutput">epsilon</span>, so that they are compared with their own operators.</p>


<p>Only the deprecated floating-point wrappers have a tolerance, so the concept is deprecated with them, and is available only when <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-config/#ga67c701de5426ac340584ed038494a873">MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED</a></span> is defined.</p>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000117>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>To be removed with the deprecated floating-point wrappers (since 6.0.0).</p>
</dd>
</dl>
</div>

<p>Definition at line 348 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">has_epsilon = is_op&lt;T&gt; and </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; t) { t.epsilon; }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
