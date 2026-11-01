---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cpp-api-expectations
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
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">detail::check_result &amp;&amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ga6db7427ada09e476aec67306ca5c0b74">expect</a> (const Expr_T &amp;expr, const reflection::source_location &amp;sl=reflection::source_location::current(), detail::check_result &amp;&amp;result=detail::check_result{})</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Evaluates a condition and reports the result. <a href="#ga6db7427ada09e476aec67306ca5c0b74">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Expectations are checks whose outcomes are counted and reported.</p>


<p>During test execution, each condition outcome, whether passing or failing, is explicitly reported in test results. Unlike requirements, a failed expectation does not stop the test; execution continues, allowing multiple conditions to be checked within a single test case.</p>


<p>This approach enables comprehensive validation of code behaviour, because all relevant expectations can be evaluated and reported in one run. Using expectations provides detailed insight into which aspects of the code meet requirements and which do not, supporting thorough and efficient testing.</p>


<div class="doxySectionDef">

## Functions

### expect() {#ga6db7427ada09e476aec67306ca5c0b74}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::check_result &amp;&amp; micro_os_plus::micro_test_plus::test_case::expect (const Expr_T &amp; expr, const reflection::source_location &amp; sl=reflection::source_location::current(), detail::check_result &amp;&amp; result=detail::check_result{})</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Evaluates a condition and reports the result.</p>


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
<dd><p>Enabled only if <span class="doxyComputerOutput">Expr_T</span> is a framework expression type or is contextually convertible to <span class="doxyComputerOutput">bool</span>, including by an <span class="doxyComputerOutput">explicit operator bool</span> (enforced via a C++20 <span class="doxyComputerOutput">requires</span> clause, with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">extension::checkable</a></span>).</p></dd>
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
<tr class="doxyParamItem">
<td class="doxyParamItemName">result</td>
<td class="doxyParamItemDescription"><p>The check result, a temporary created by the caller as the default argument, which the applications do not pass; it is destroyed at the end of the statement.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A reference to the check result, to which optional messages can be appended with <span class="doxyComputerOutput">operator&lt;&lt;</span>; the check is reported when it is destroyed, at the end of the statement, so the result cannot be kept in a variable.</p></dd>
</dl>


<p>Initialises the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a></span> received as the last argument, a temporary created by the caller, with the kind <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70cae15c5d274bf9fa6571890c731d88bc37">detail::check_kind::expectation</a></span>, and returns a reference to it. The check result evaluates the condition when initialised, and records a pass or fail when it is destroyed, at the end of the expression statement.</p>


<p>Stops the compilation with the message of the <span class="doxyComputerOutput">static_assert</span>, which states what <span class="doxyComputerOutput"><a href="#ga6db7427ada09e476aec67306ca5c0b74">expect()</a></span> takes. The condition of the <span class="doxyComputerOutput">static_assert</span> depends on the type, so it is evaluated only when the function is selected.</p>


<p>Deprecated; the check is the same as that of <span class="doxyComputerOutput"><a href="#ga6db7427ada09e476aec67306ca5c0b74">expect()</a></span>, for the arguments that are always true.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l01440">1440</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00499">499</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga6db7427ada09e476aec67306ca5c0b74">499</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga6db7427ada09e476aec67306ca5c0b74">test_case::expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">500</span><span class="doxyLineContent"><span class="doxyHighlight">                     <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp; result)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">501</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">502</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a82e48e546c5a5034be69412c1641482d">is_misdirected</a> ()) [[unlikely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">503</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">504</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b25dc50ced0df2821d7a984eb142c1a">report_misdirected</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70cae15c5d274bf9fa6571890c731d88bc37">detail::check_kind::expectation</a>, sl,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">505</span><span class="doxyLineContent"><span class="doxyHighlight">                                   std::move (result));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">506</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">507</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">508</span><span class="doxyLineContent"><span class="doxyHighlight">    result.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result/#ab81139f2b0c47e93b7d488976fcbbd66">init</a> (expr, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70cae15c5d274bf9fa6571890c731d88bc37">detail::check_kind::expectation</a>, sl, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">509</span><span class="doxyLineContent"><span class="doxyHighlight">                 <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().expression_,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">510</span><span class="doxyLineContent"><span class="doxyHighlight">                 <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().writes_passed_checks ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">511</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> std::move (result);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">512</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70cae15c5d274bf9fa6571890c731d88bc37">micro_os_plus::micro_test_plus::detail::expectation</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result/#ab81139f2b0c47e93b7d488976fcbbd66">micro_os_plus::micro_test_plus::detail::check_result::init</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a82e48e546c5a5034be69412c1641482d">micro_os_plus::micro_test_plus::test_case::is_misdirected</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b25dc50ced0df2821d7a984eb142c1a">micro_os_plus::micro_test_plus::test_case::report_misdirected</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">micro_os_plus::micro_test_plus::detail::runnable_base::test_reporter</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac2e310ec902a0c3e786d4c415269c23e">micro_os_plus::micro_test_plus::test_case::operator=</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
