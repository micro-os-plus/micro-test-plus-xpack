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
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#gace68a1bd4dd258082f4b1fc01fcd008a">require</a> (const Expr_T &amp;expr, const reflection::source_location &amp;sl=reflection::source_location::current())</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Checks a condition and, if false, stops the test case. <a href="#gace68a1bd4dd258082f4b1fc01fcd008a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Requirements are checks that stop the test case when they fail.</p>


<p>When a precondition of the following checks does not hold, the test case cannot continue meaningfully. A failed requirement is reported and counted like a failed expectation, and then the rest of the test case body is skipped; the run continues with the next test case.</p>


<p>This is the behaviour of the fatal assertions of most C++ test frameworks (<span class="doxyComputerOutput">ASSERT_*</span> in GoogleTest, <span class="doxyComputerOutput">REQUIRE()</span> in Catch2 and doctest, <span class="doxyComputerOutput">BOOST_REQUIRE()</span> in Boost.Test). The test case is stopped with an exception; without exceptions, it cannot be stopped alone, so the results of the test case are reported, ending with the failed requirement (followed, with the TAP reporter, by a <span class="doxyComputerOutput">Bail out!</span> line), and the whole test execution is aborted with <span class="doxyComputerOutput">runner::abort()</span>, as Catch2 does; the remaining test cases do not run, and no totals are written.</p>


<div class="doxySectionDef">

## Functions

### require() {#gace68a1bd4dd258082f4b1fc01fcd008a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::test_case::require (const Expr_T &amp; expr, const reflection::source_location &amp; sl=reflection::source_location::current())</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Checks a condition and, if false, stops the test case.</p>


<p>The failure is reported and counted as for <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-expectations/#gaf4f5f9632b5a290c1894984661a41a86">expect()</a></span>; then, when exceptions are enabled, the rest of the test case body is skipped, and the run continues with the next test case, as <span class="doxyComputerOutput">ASSERT_*</span> in GoogleTest, <span class="doxyComputerOutput">REQUIRE()</span> in Catch2 and doctest, and <span class="doxyComputerOutput">BOOST_REQUIRE()</span> in Boost.Test do. Without exceptions, the test execution is aborted with <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span>.</p>


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
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The check result, to which optional messages can be appended with <span class="doxyComputerOutput">operator&lt;&lt;</span>; the check is reported when it is destroyed, at the end of the statement.</p></dd>
</dl>


<p>Constructs and returns a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a></span> of the kind <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">detail::check_kind::requirement</a></span>. The check result evaluates the condition when constructed, records a pass or fail when it is destroyed, and, if the condition is false, stops the test case by throwing <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failed-requirement">detail::failed_requirement</a></span> (caught by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span>), or, without exceptions, aborts the test execution.</p>


<p>Deprecated; the check is the same as that of <span class="doxyComputerOutput"><a href="#gace68a1bd4dd258082f4b1fc01fcd008a">require()</a></span>, for the arguments that are always true.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l01291">1291</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00477">477</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#gace68a1bd4dd258082f4b1fc01fcd008a">477</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#gace68a1bd4dd258082f4b1fc01fcd008a">test_case::require</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">478</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">479</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">480</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>{ expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">481</span><span class="doxyLineContent"><span class="doxyHighlight">                                 <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">detail::check_kind::requirement</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">482</span><span class="doxyLineContent"><span class="doxyHighlight">                                 sl,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">483</span><span class="doxyLineContent"><span class="doxyHighlight">                                 *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">484</span><span class="doxyLineContent"><span class="doxyHighlight">                                 <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac928cbe8852ca0c0273482b905c6301b">expression_</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">485</span><span class="doxyLineContent"><span class="doxyHighlight">                                 <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0e6f0a129d495a7e9d57ef71412cd88f">writes_passed_checks</a> () };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">486</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#ac928cbe8852ca0c0273482b905c6301b">micro_os_plus::micro_test_plus::detail::reporter::expression_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">micro_os_plus::micro_test_plus::detail::requirement</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">micro_os_plus::micro_test_plus::detail::runnable_base::test_reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a0e6f0a129d495a7e9d57ef71412cd88f">micro_os_plus::micro_test_plus::detail::reporter::writes_passed_checks</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ad25dc8d5d657ace9d47d3a95b3341802">micro_os_plus::micro_test_plus::test_case::assume</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac2e310ec902a0c3e786d4c415269c23e">micro_os_plus::micro_test_plus::test_case::operator=</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
