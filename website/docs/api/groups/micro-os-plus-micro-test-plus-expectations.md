---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-expectations
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Expectations

<p>Expectations are checks whose outcomes are counted and reported. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaad2aa05f39d1877f2173f6d0f6718bd2">expect</a> (const Expr_T &amp;expr, const reflection::source_location &amp;sl=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Evaluate a generic condition and report the results. <a href="#gaad2aa05f39d1877f2173f6d0f6718bd2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Expectations are checks whose outcomes are counted and reported.</p>


<p>During test execution, each condition outcome, whether passing or failing, is explicitly reported in test results. Unlike assumptions, a failed expectation does not terminate the test; execution continues, allowing multiple conditions to be checked within a single test case.</p>


<p>This approach enables comprehensive validation of code behaviour, because all relevant expectations can be evaluated and reported in one run. Using expectations provides detailed insight into which aspects of the code meet requirements and which do not, supporting thorough and efficient testing.</p>


<div class="doxySectionDef">

## Functions

### expect() {#gaad2aa05f39d1877f2173f6d0f6718bd2}

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


<p>Constructs and returns a <span class="doxyComputerOutput">deferred_reporter&lt;Expr_T&gt;</span> with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ad8302d2dc629b643d34b3cfeafe44b3b">abort</a> = false</span>. The reporter evaluates the condition and records a pass or fail when it is destroyed at the end of the expression statement.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l00641">641</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00290">290</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaad2aa05f39d1877f2173f6d0f6718bd2">290</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gaad2aa05f39d1877f2173f6d0f6718bd2">subtest::expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter">detail::deferred_reporter</a>{ expr, </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">, sl, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span><span class="doxyLineContent"><span class="doxyHighlight">                                      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad120bac9a056a4684d866d974a09b6b">reporter</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter/#ad2169093aee09bc28ae7f70467569a23">expression</a> () };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">294</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter/#ad2169093aee09bc28ae7f70467569a23">micro_os_plus::micro_test_plus::reporter::expression</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad120bac9a056a4684d866d974a09b6b">micro_os_plus::micro_test_plus::detail::runnable&lt; subtest &gt;::reporter</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest/#ad3eb4bb11f1c6fc4631bae8a7215a95e">micro_os_plus::micro_test_plus::subtest::operator=</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.2 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
