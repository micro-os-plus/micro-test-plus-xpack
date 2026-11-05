---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cpp-api-requirements
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Requirements

<p>Requirements are checks that stop the test case when they fail. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">detail::check_result &amp;&amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gaad1feafeef2f3cea336be3ebe0b27e14">require</a> (const Expr_T &amp;expr, const reflection::source_location &amp;sl=reflection::source_location::current(), detail::check_result &amp;&amp;result=detail::check_result{})</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks a condition and, if false, stops the test case. <a href="#gaad1feafeef2f3cea336be3ebe0b27e14">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Requirements are checks that stop the test case when they fail.</p>


<p><span class="doxyComputerOutput">t.require (condition)</span> checks a condition as <span class="doxyComputerOutput">expect()</span> does, and also stops the test case when it fails. Use it when the rest of the test case depends on the condition, for example to check that a pointer is not null before using it.</p>


<p>A failed requirement is reported and counted like a failed expectation. What follows depends on the build:</p>


<ul class="doxyList ">
<li>with exceptions, the rest of the test case is skipped, and the run continues with the next test case; this is the behaviour of the fatal assertions of most C++ test frameworks (<span class="doxyComputerOutput">ASSERT_*</span> in GoogleTest, <span class="doxyComputerOutput">REQUIRE()</span> in Catch2 and doctest, <span class="doxyComputerOutput">BOOST_REQUIRE()</span> in Boost.Test);</li>
<li>without exceptions, a test case cannot be stopped alone, so the whole test run is aborted with <span class="doxyComputerOutput">runner::abort()</span>, as Catch2 does: the results of the test case are written, ending with the failed requirement (followed, with the TAP reporter, by a <span class="doxyComputerOutput">Bail out!</span> line), the remaining test cases do not run, and no totals are written. The process is then terminated with <span class="doxyComputerOutput">::abort()</span>, unless the application set another handler with <span class="doxyComputerOutput">runner::set_abort_handler()</span>.</li>
</ul>

<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check the buffer"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* buffer = get_buffer ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.require (mt::ne (buffer, </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"buffer allocated"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::eq (buffer[0], </span><span class="doxyHighlightCharLiteral">'a'</span><span class="doxyHighlight">));</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<div class="doxySectionDef">

## Functions

### require() {#gaad1feafeef2f3cea336be3ebe0b27e14}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::check_result &amp;&amp; micro_os_plus::micro_test_plus::test_case::require (const Expr_T &amp; expr, const reflection::source_location &amp; sl=reflection::source_location::current(), detail::check_result &amp;&amp; result=detail::check_result{})</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Checks a condition and, if false, stops the test case.</p>


<p>The failure is reported and counted as for <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-expectations/#ga6db7427ada09e476aec67306ca5c0b74">expect()</a></span>; then, when exceptions are enabled, the rest of the test case body is skipped, and the run continues with the next test case, as <span class="doxyComputerOutput">ASSERT_*</span> in GoogleTest, <span class="doxyComputerOutput">REQUIRE()</span> in Catch2 and doctest, and <span class="doxyComputerOutput">BOOST_REQUIRE()</span> in Boost.Test do. Without exceptions, the test execution is aborted with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span>.</p>


<p>The test case is stopped by throwing a private exception, at the end of the statement, after the optional message was appended. It is not derived from <span class="doxyComputerOutput">std::exception</span>; a <span class="doxyComputerOutput">catch (...)</span> in the test case body must rethrow it, and the body must not be <span class="doxyComputerOutput">noexcept</span>.</p>


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
<dd><p>A reference to the check result, to which optional messages can be appended with <span class="doxyComputerOutput">operator&lt;&lt;</span>; the check is reported when it is destroyed, at the end of the statement.</p></dd>
</dl>



:::warning
<p>The result must not be named, stored, or kept in any variable. A reference such as <span class="doxyComputerOutput">auto&amp;&amp; r = t.expect (...)</span> compiles, but dangles after the statement; the message operator and <span class="doxyComputerOutput">value()</span> can be called only on a temporary, so the named result cannot be used, and forcing it with <span class="doxyComputerOutput">std::move()</span> is undefined. The check must be reported at the end of the statement, and not later. Write the message in the same statement, with <span class="doxyComputerOutput">operator&lt;&lt;</span>.</p>
:::


<p>Initialises the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a></span> received as the last argument, a temporary created by the caller, with the kind <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">detail::check_kind::requirement</a></span>, and returns a reference to it. The check result evaluates the condition when initialised, records a pass or fail when it is destroyed, and, if the condition is false, stops the test case by throwing <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failed-requirement">detail::failed_requirement</a></span> (caught by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span>), or, without exceptions, aborts the test execution.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l01705">1705</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00683">683</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gaad1feafeef2f3cea336be3ebe0b27e14">683</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gaad1feafeef2f3cea336be3ebe0b27e14">test_case::require</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">684</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">685</span><span class="doxyLineContent"><span class="doxyHighlight">                      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp; result)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">686</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">687</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a82e48e546c5a5034be69412c1641482d">is_misdirected</a> ()) [[unlikely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">688</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">689</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b25dc50ced0df2821d7a984eb142c1a">report_misdirected</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">detail::check_kind::requirement</a>, sl,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">690</span><span class="doxyLineContent"><span class="doxyHighlight">                                   std::move (result));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">691</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">692</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">693</span><span class="doxyLineContent"><span class="doxyHighlight">    result.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result/#ab81139f2b0c47e93b7d488976fcbbd66">init</a> (expr, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">detail::check_kind::requirement</a>, sl, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">694</span><span class="doxyLineContent"><span class="doxyHighlight">                 <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().expression_,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">695</span><span class="doxyLineContent"><span class="doxyHighlight">                 <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().writes_passed_checks ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">696</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> std::move (result);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">697</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result/#ab81139f2b0c47e93b7d488976fcbbd66">micro_os_plus::micro_test_plus::detail::check_result::init</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a82e48e546c5a5034be69412c1641482d">micro_os_plus::micro_test_plus::test_case::is_misdirected</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b25dc50ced0df2821d7a984eb142c1a">micro_os_plus::micro_test_plus::test_case::report_misdirected</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">micro_os_plus::micro_test_plus::detail::requirement</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">micro_os_plus::micro_test_plus::detail::runnable_base::test_reporter</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adeccc20d1919ae7f8fc697997dc9bb98">micro_os_plus::micro_test_plus::test_case::assume</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
