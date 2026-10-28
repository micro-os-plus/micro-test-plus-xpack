---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cpp-api-deprecated-logical-functions
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Logical Functions

<p>Deprecated v5.0.1 names of the logical functions. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga9998cd63972fac8b24a2f0138322e7c1">_and</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated generic logical <b>and</b> operation, the v5.0.1 name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gab9b9c26860ceafc1288ecb415f52aaaf">all_of()</a></span>. <a href="#ga9998cd63972fac8b24a2f0138322e7c1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaa465723bc4fe309f15d30a4e7207d40f">_not</a> (Expr_T &amp;&amp;expr)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated generic logical <b>not</b> operation, the v5.0.1 name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate()</a></span>. <a href="#gaa465723bc4fe309f15d30a4e7207d40f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga1c7ddbf53764ab67240f1cf0e0fb4b8d">_or</a> (Lhs_T &amp;&amp;lhs, Rhs_T &amp;&amp;rhs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deprecated generic logical (inclusive) <b>or</b> operation, the v5.0.1 name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gae6395736f05626ba6dcf79ecc523486c">any_of()</a></span>. <a href="#ga1c7ddbf53764ab67240f1cf0e0fb4b8d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Deprecated v5.0.1 names of the logical functions.</p>


<p>The functions <span class="doxyComputerOutput">mt::_and()</span>, <span class="doxyComputerOutput">mt::_or()</span>, and <span class="doxyComputerOutput">mt::_not()</span> are the v5.0.1 names of <span class="doxyComputerOutput">mt::all_of()</span>, <span class="doxyComputerOutput">mt::any_of()</span>, and <span class="doxyComputerOutput">mt::negate()</span>. They are deprecated since 5.1.0, and are kept for compatibility with the existing applications; they behave as the functions that replace them.</p>


<p>The names were changed since a leading underscore is not used by the other public names. Unlike the replacements, <span class="doxyComputerOutput">mt::_and()</span> and <span class="doxyComputerOutput">mt::_or()</span> take exactly two operands, whereas <span class="doxyComputerOutput">mt::all_of()</span> and <span class="doxyComputerOutput">mt::any_of()</span> take two or more.</p>


<table class="doxyTable">
<tr>
<th>Deprecated</th>
<th>Replacement</th>
</tr>
<tr>
<td><span class="doxyComputerOutput">mt::_and()</span></td>
<td><span class="doxyComputerOutput">mt::all_of()</span></td>
</tr>
<tr>
<td><span class="doxyComputerOutput">mt::_or()</span></td>
<td><span class="doxyComputerOutput">mt::any_of()</span></td>
</tr>
<tr>
<td><span class="doxyComputerOutput">mt::_not()</span></td>
<td><span class="doxyComputerOutput">mt::negate()</span></td>
</tr>
</table>

<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Deprecated.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">t.expect (mt::_and (mt::eq (compute_answer (), 42),</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                    mt::lt (compute_answer (), 43)));</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Replacement.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">t.expect (mt::all_of (mt::eq (compute_answer (), 42),</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                      mt::lt (compute_answer (), 43)));</span></span></div>

</div>


<p>The overloaded logical operators of the <span class="doxyComputerOutput">micro_test_plus::operators</span> namespace are also deprecated since 5.1.0, in favour of the same replacement functions.</p>


<div class="doxySectionDef">

## Functions

### \_and() {#ga9998cd63972fac8b24a2f0138322e7c1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::_and (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deprecated generic logical <b>and</b> operation, the v5.0.1 name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gab9b9c26860ceafc1288ecb415f52aaaf">all_of()</a></span>.</p>


<p>The same as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gab9b9c26860ceafc1288ecb415f52aaaf">all_of()</a></span>. The name was changed since a leading underscore is not used by the other public names.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object that evaluates to true if both operand expressions are true.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000007>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gab9b9c26860ceafc1288ecb415f52aaaf">all_of()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Forwards to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gab9b9c26860ceafc1288ecb415f52aaaf">all_of()</a></span>, so the returned expression is the same, and is reported in the same way.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deprecated-inlines-h/#l00096">96</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deprecated-inlines-h">deprecated-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga9998cd63972fac8b24a2f0138322e7c1">96</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga9998cd63972fac8b24a2f0138322e7c1">_and</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gab9b9c26860ceafc1288ecb415f52aaaf">all_of</a> (std::forward&lt;Lhs_T&gt; (lhs), std::forward&lt;Rhs_T&gt; (rhs));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ga9998cd63972fac8b24a2f0138322e7c1">micro_os_plus::micro_test_plus::_and</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gab9b9c26860ceafc1288ecb415f52aaaf">micro_os_plus::micro_test_plus::all_of</a>.</p>


<p>Referenced by <a href="#ga9998cd63972fac8b24a2f0138322e7c1">micro_os_plus::micro_test_plus::_and</a>.</p>

</div>
</div>

### \_not() {#gaa465723bc4fe309f15d30a4e7207d40f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::_not (Expr_T &amp;&amp; expr)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deprecated generic logical <b>not</b> operation, the v5.0.1 name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate()</a></span>.</p>


<p>The same as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate()</a></span>. The name was changed since a leading underscore is not used by the other public names.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>Type of the operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">expr</td>
<td class="doxyParamItemDescription"><p>Logical expression to be negated.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object that evaluates to true if the operand is false.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000006>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Forwards to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate()</a></span>, so the returned expression is the same, and is reported in the same way.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deprecated-inlines-h/#l00083">83</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deprecated-inlines-h">deprecated-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaa465723bc4fe309f15d30a4e7207d40f">83</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gaa465723bc4fe309f15d30a4e7207d40f">_not</a> (Expr_T&amp;&amp; expr)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">negate</a> (std::forward&lt;Expr_T&gt; (expr));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#gaa465723bc4fe309f15d30a4e7207d40f">micro_os_plus::micro_test_plus::_not</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#ga6a0bb2654eb89c1b0a35134e8738eeb1">micro_os_plus::micro_test_plus::negate</a>.</p>


<p>Referenced by <a href="#gaa465723bc4fe309f15d30a4e7207d40f">micro_os_plus::micro_test_plus::_not</a>.</p>

</div>
</div>

### \_or() {#ga1c7ddbf53764ab67240f1cf0e0fb4b8d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::_or (Lhs_T &amp;&amp; lhs, Rhs_T &amp;&amp; rhs)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deprecated generic logical (inclusive) <b>or</b> operation, the v5.0.1 name of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gae6395736f05626ba6dcf79ecc523486c">any_of()</a></span>.</p>


<p>The same as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gae6395736f05626ba6dcf79ecc523486c">any_of()</a></span>. The name was changed since a leading underscore is not used by the other public names.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>Type of the right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">lhs</td>
<td class="doxyParamItemDescription"><p>Left hand side operand.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">rhs</td>
<td class="doxyParamItemDescription"><p>Right hand side operand.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An object that evaluates to true if at least one of the operand expressions is true, including when both are.</p></dd>
</dl>


<div class="doxyXrefSect">
<dl class="doxyXrefSectList">
<dt class="doxyXrefSectTitle"><a href=/micro-test-plus-xpack/docs/api/pages/deprecated/#_deprecated000008>Deprecated</a></dt>
<dd class="doxyXrefSectDescription">
<p>use <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gae6395736f05626ba6dcf79ecc523486c">any_of()</a> (since 5.1.0)</p>
</dd>
</dl>
</div>

<p>Forwards to <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gae6395736f05626ba6dcf79ecc523486c">any_of()</a></span>, so the returned expression is the same, and is reported in the same way.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deprecated-inlines-h/#l00109">109</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deprecated-inlines-h">deprecated-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga1c7ddbf53764ab67240f1cf0e0fb4b8d">109</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga1c7ddbf53764ab67240f1cf0e0fb4b8d">_or</a> (Lhs_T&amp;&amp; lhs, Rhs_T&amp;&amp; rhs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gae6395736f05626ba6dcf79ecc523486c">any_of</a> (std::forward&lt;Lhs_T&gt; (lhs), std::forward&lt;Rhs_T&gt; (rhs));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ga1c7ddbf53764ab67240f1cf0e0fb4b8d">micro_os_plus::micro_test_plus::_or</a> and <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-logical-functions/#gae6395736f05626ba6dcf79ecc523486c">micro_os_plus::micro_test_plus::any_of</a>.</p>


<p>Referenced by <a href="#ga1c7ddbf53764ab67240f1cf0e0fb4b8d">micro_os_plus::micro_test_plus::_or</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
