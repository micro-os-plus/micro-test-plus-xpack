---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-assumptions
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
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga0346721eb94564ebce4a49ee81c020c8">assume</a> (const Expr_T &amp;expr, const reflection::source_location &amp;sl=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Check a condition and, if false, abort test execution. <a href="#ga0346721eb94564ebce4a49ee81c020c8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Assumptions are conditions that must be satisfied for a test to proceed.</p>


<p>When a required precondition does not hold, the test cannot execute meaningfully. If an assumption fails, the test is terminated immediately, as continuing would render the results invalid or misleading.</p>


<p>By explicitly defining assumptions, developers ensure that tests run only in appropriate contexts, improving the reliability and accuracy of outcomes. This mechanism is particularly valuable for guarding against invalid input, incomplete initialisation, and unsupported environments.</p>


<div class="doxySectionDef">

## Functions

### assume() {#ga0346721eb94564ebce4a49ee81c020c8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::subtest::assume (const Expr_T &amp; expr, const reflection::source_location &amp; sl=reflection::source_location::current())</td>
</tr>
</table>
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
<dt>Constraints</dt>
<dd><p>Enabled only if <span class="doxyComputerOutput">Expr_T</span> is derived from <span class="doxyComputerOutput">detail::op</span> or is convertible to <span class="doxyComputerOutput">bool</span> (enforced via a C++20 <span class="doxyComputerOutput">requires</span> clause).</p></dd>
</dl>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">expr</td>
<td class="doxyParamItemDescription"><p>Logical expression to evaluate.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">sl</td>
<td class="doxyParamItemDescription"><p>Optional source location, defaulting to the current line.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>An output stream to write optional messages.</p></dd>
</dl>


<p>Constructs and returns a <span class="doxyComputerOutput">deferred_reporter&lt;Expr_T&gt;</span> with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ad8302d2dc629b643d34b3cfeafe44b3b">abort</a> = true</span>. The reporter evaluates the condition, records a pass or fail when it is destroyed, and aborts execution if the condition is false.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00661">661</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00305">305</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga0346721eb94564ebce4a49ee81c020c8">305</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga0346721eb94564ebce4a49ee81c020c8">subtest::assume</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">306</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">307</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter">detail::deferred_reporter</a>{ expr, </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">, sl, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">308</span><span class="doxyLineContent"><span class="doxyHighlight">                                      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad120bac9a056a4684d866d974a09b6b">reporter</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter/#ad2169093aee09bc28ae7f70467569a23">expression</a> () };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">309</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter/#ad2169093aee09bc28ae7f70467569a23">micro_os_plus::micro_test_plus::reporter::expression</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad120bac9a056a4684d866d974a09b6b">micro_os_plus::micro_test_plus::detail::runnable&lt; subtest &gt;::reporter</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest/#ad3eb4bb11f1c6fc4631bae8a7215a95e">micro_os_plus::micro_test_plus::subtest::operator=</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
