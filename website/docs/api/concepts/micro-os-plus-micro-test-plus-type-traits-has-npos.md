---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/type-traits/has-npos
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `has_npos` Concept

<p>Deprecated C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides a <span class="doxyComputerOutput">npos</span> member. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/has-npos">micro_os_plus::micro_test_plus::type_traits::has_npos</a> =  requires { T::npos; }
</div>

## Description {#details}

<p>Deprecated C++20 concept satisfied when <span class="doxyComputerOutput">T</span> provides a <span class="doxyComputerOutput">npos</span> member.</p>


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

<p>Restored with its v5.0.1 definition, satisfied by any type with a member named <span class="doxyComputerOutput">npos</span>. It is not used by the framework any more, which detects the strings with <span class="doxyComputerOutput">detail::string_like</span>, so that the containers with a member named <span class="doxyComputerOutput">npos</span> are compared element by element.</p>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000096>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>There is no replacement; the concept used by the framework is internal (since 6.0.0).</p>
</dd>
</dl>
</div>

<p>Definition at line 2541 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deprecated-h">deprecated.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">has_npos = </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> { T::npos; }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
