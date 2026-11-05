---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/concepts/micro-os-plus/micro-test-plus/detail/sign-mixed-integers
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - concept

---

<div class="doxyPage">

# `sign_mixed_integers` Concept

<p>Concept satisfied by two integer types of different signedness. <a href="#details">More...</a></p>

## Definition

<div class="doxyDefinition">
template &lt;class Lhs_T, class Rhs_T&gt;<br/>
concept <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/sign-mixed-integers">micro_os_plus::micro_test_plus::detail::sign_mixed_integers</a> =  std::is_integral_v&lt;Lhs_T&gt; and std::is_integral_v&lt;Rhs_T&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and (not std::is_same_v&lt;Lhs_T, bool&gt;)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and (not std::is_same_v&lt;Rhs_T, bool&gt;)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;and (std::is_signed_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51cdb19f7f3312bb3946451261c83ece">comparison_integer_t</a>&lt;Lhs_T&gt;&gt;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;!= std::is_signed_v&lt;<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a51cdb19f7f3312bb3946451261c83ece">comparison_integer_t</a>&lt;Rhs_T&gt;&gt;)
</div>

## Description {#details}

<p>Concept satisfied by two integer types of different signedness.</p>


<p>The built-in comparison of a signed and an unsigned operand converts the signed one to the unsigned type, so <span class="doxyComputerOutput">-1 &lt; 1u</span> is false. For these pairs the comparisons use the <span class="doxyComputerOutput">std::cmp_*()</span> functions, which compare the mathematical values. The character types take part as the integers of the same size and signedness (see <span class="doxyComputerOutput">comparison_integer</span>), since the built-in comparison of a signed <span class="doxyComputerOutput">char</span> with an <span class="doxyComputerOutput">unsigned</span>, or of a <span class="doxyComputerOutput">char32_t</span> with an <span class="doxyComputerOutput">int</span>, has the same problem. <span class="doxyComputerOutput">bool</span> is excluded, since <span class="doxyComputerOutput">std::cmp_*()</span> do not accept it and its comparison with integers is not a sign problem.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the left operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The type of the right operand.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line 368 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/detail-inlines-h">detail-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight">&lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Lhs_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight">sign_mixed_integers = std::is_integral_v&lt;Lhs_T&gt; and std::is_integral_v&lt;Rhs_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and (not std::is_same_v&lt;Lhs_T, bool&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and (not std::is_same_v&lt;Rhs_T, bool&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">          and (std::is_signed_v&lt;comparison_integer_t&lt;Lhs_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">               != std::is_signed_v&lt;comparison_integer_t&lt;Rhs_T&gt;&gt;)</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
