---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-test-plus-expectations
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Expectations

<p>Expectations are checks whose outcomes are accounted and reported. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga9baacbf1fea181ff175bcd14baa54ea1">expect</a> (const Expr_T &amp;expr, const reflection::source_location &amp;sl=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Evaluate a generic condition and report the results. <a href="#ga9baacbf1fea181ff175bcd14baa54ea1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Expectations are checks whose outcomes are accounted and reported.</p>


<p>Expectations are conditions that are verified during test execution, with their outcomes—whether passing or failing—being explicitly reported in the test results. Unlike assumptions, a failed expectation does not cause the test to terminate; instead, execution continues, allowing multiple conditions to be checked within a single test case.</p>


<p>This approach enables comprehensive validation of code behaviour, as all relevant expectations can be evaluated and reported in one run. By using expectations, developers gain detailed insight into which aspects of the code meet requirements and which do not, supporting thorough and efficient testing practices.</p>


<div class="doxySectionDef">

## Functions

### expect() {#ga9baacbf1fea181ff175bcd14baa54ea1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::subtest::expect (const Expr_T &amp; expr, const reflection::source_location &amp; sl=reflection::source_location::current())</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Evaluate a generic condition and report the results.</p>


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
<dt>Constraints</dt>
<dd><p>Enabled only if <span class="doxyComputerOutput">Expr_T</span> is derived from <span class="doxyComputerOutput">detail::op</span> or is convertible to <span class="doxyComputerOutput">bool</span> (enforced via a C++20 <span class="doxyComputerOutput">requires</span> clause).</p></dd>
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


<p>The <span class="doxyComputerOutput">expect</span> function template evaluates a logical condition or custom expression and reports the result within the µTest++ framework. It is designed to provide detailed diagnostics for test failures, including the actual and expected values, when using the provided comparators (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gae9dfca849300a917cb1c231d275baaa3">eq()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga59e4cf59954e81bc868e62b1c5c8db1f">ne()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gac162522dcad1a6ff7c869d52d376b3ed">lt()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga2b5263a5b3965855aa04971bba735a56">le()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gae2fb681444d8256f6bf827eea6b7c29e">gt()</a></span>, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga34e03399670ec0b365b94b7bea788dd8">ge()</a></span>) or custom operators.</p>


<p>The function template can be used with any expression that evaluates to a boolean or with custom comparators/operators derived from the local <span class="doxyComputerOutput">detail::op</span> type. For complex checks performed outside the <span class="doxyComputerOutput"><a href="#ga9baacbf1fea181ff175bcd14baa54ea1">expect()</a></span> logical expression (such as within <span class="doxyComputerOutput">if</span> or <span class="doxyComputerOutput">try</span>/<span class="doxyComputerOutput">catch</span> statements), the result can be reported by calling <span class="doxyComputerOutput">expect(true)</span> or <span class="doxyComputerOutput">expect(false)</span>.</p>


<p>The function returns an output stream, allowing optional messages to be appended to the test report.</p>


<p><b>Example</b></p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = micro_os_plus::micro_test_plus;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::expect(compute_answer() == 42) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer is 42"</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00640">640</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga9baacbf1fea181ff175bcd14baa54ea1">640</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ga9baacbf1fea181ff175bcd14baa54ea1">expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">641</span><span class="doxyLineContent"><span class="doxyHighlight">                                = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">642</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">643</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter">detail::deferred_reporter&lt;Expr_T&gt;</a>{ expr, </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">, sl, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">644</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">micro_os_plus::micro_test_plus::reflection::source_location::current</a> and <a href="#ga9baacbf1fea181ff175bcd14baa54ea1">micro_os_plus::micro_test_plus::subtest::expect</a>.</p>


<p>Referenced by <a href="#ga9baacbf1fea181ff175bcd14baa54ea1">micro_os_plus::micro_test_plus::subtest::expect</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.0.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
