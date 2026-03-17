---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-test-plus-assumptions
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Assumptions

<p>Assumptions are conditions that must be satisfied for a test to proceed. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga0f5febbef70eb641691b98583410a1ca">assume</a> (const Expr_T &amp;expr, const reflection::source_location &amp;sl=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Check a condition and, if false, abort test execution. <a href="#ga0f5febbef70eb641691b98583410a1ca">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Assumptions are conditions that must be satisfied for a test to proceed.</p>


<p>Assumptions represent essential preconditions that must hold true for a test case to execute meaningfully. If an assumption fails, the test is immediately terminated, as continuing would render the results invalid or misleading.</p>


<p>By clearly specifying assumptions, developers can ensure that tests are only run in appropriate contexts, improving the reliability and accuracy of test outcomes. This mechanism is particularly valuable for guarding against invalid input, incomplete initialisation, or unsupported environments.</p>


<div class="doxySectionDef">

## Functions

### assume() {#ga0f5febbef70eb641691b98583410a1ca}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T, type_traits::requires_t&lt; type_traits::is_op_v&lt; Expr_T &gt; or type_traits::is_convertible_v&lt; Expr_T, bool &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::assume (const Expr_T &amp; expr, const reflection::source_location &amp; sl=reflection::source_location::current())</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Check a condition and, if false, abort test execution.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>The type of the custom expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>SFINAE</dt>
<dd><p>Enabled only if <span class="doxyComputerOutput">Expr_T</span> is derived from <span class="doxyComputerOutput">detail::op</span> or is convertible to <span class="doxyComputerOutput">bool</span>.</p></dd>
</dl>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] expr</td>
<td class="doxyParamItemDescription"><p>Logical expression to evaluate.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] sl</td>
<td class="doxyParamItemDescription"><p>Optional source location, defaulting to the current line.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An output stream to write optional messages.</p></dd>
</dl>


<p>The <span class="doxyComputerOutput">assume</span> function template evaluates a logical condition or custom expression and reports the result within the µTest++ framework. It is designed to provide detailed diagnostics for test failures, including the actual and expected values, when using the provided comparators (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gae9dfca849300a917cb1c231d275baaa3">eq()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga59e4cf59954e81bc868e62b1c5c8db1f">ne()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gac162522dcad1a6ff7c869d52d376b3ed">lt()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga2b5263a5b3965855aa04971bba735a56">le()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gae2fb681444d8256f6bf827eea6b7c29e">gt()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga34e03399670ec0b365b94b7bea788dd8">ge()</a></span>) or custom operators.</p>


<p>The function template can be used with any expression that evaluates to a boolean or with custom comparators/operators derived from the local <span class="doxyComputerOutput">detail::op</span> type. For complex checks performed outside the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-expectations/#ga75c3f43663a5440d78231fe572fe4a22">expect()</a></span> logical expression (such as within <span class="doxyComputerOutput">if</span> or <span class="doxyComputerOutput">try</span>/<span class="doxyComputerOutput">catch</span> statements), the result can be reported by calling <span class="doxyComputerOutput">expect(true)</span> or <span class="doxyComputerOutput">expect(false)</span>.</p>


<p>The function returns an output stream, allowing optional messages to be appended to the test report.</p>


<p><b>Example</b></p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::assume(compute_answer() == 42) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is 42"</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/micro-test-plus-inlines-h/#l00188">188</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/micro-test-plus-inlines-h">micro-test-plus-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga0f5febbef70eb641691b98583410a1ca">188</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga0f5febbef70eb641691b98583410a1ca">assume</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter">detail::deferred_reporter&lt;Expr_T&gt;</a>{ expr, </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">, sl };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.0.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
