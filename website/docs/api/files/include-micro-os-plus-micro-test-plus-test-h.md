---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/files/include/micro-os-plus/micro-test-plus/test-h
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - file

---

<div class="doxyPage">

# `test.h` File

<p>C++ header file with declarations for the µTest++ test hierarchy. <a href="#details">More...</a></p>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/counters-h">counters.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/stopwatch-h">stopwatch.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>"
#include &lt;cstddef&gt;
#include &lt;functional&gt;
#include &lt;initializer_list&gt;
#include &lt;memory&gt;
#include &lt;string&gt;
#include &lt;string_view&gt;
#include &lt;tuple&gt;
#include &lt;type_traits&gt;
#include &lt;utility&gt;
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">inlines/test-inlines.h</a>"
</div>

## Namespaces Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus">micro_os_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The primary namespace for the µOS++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_test_plus</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Primary namespace for the µTest++ testing framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">namespace</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Internal implementation details for the µTest++ framework. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable">bound_callable&lt;Self_T, Callable_T, Args_T&gt;</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Function object that holds a callable and the additional arguments it is invoked with. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">callable_ref&lt;Self_T&gt;</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-owning reference to a callable invoked with a <span class="doxyComputerOutput">Self_T&amp;</span> argument. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">runnable_base</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Non-template base for all runnable objects (suites and test cases). <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A test suite designed for static (namespace-scope) registration with a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A named, runnable test suite registered with the test runner. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A named, runnable test case that lives inside a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The name of a test case, with the location of its definition. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite">top_suite</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The optional top suite owned by every <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a></span> instance. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Concepts Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">concept</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">static_suite_body</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The body of a static suite written for v5.0.1, whose first parameter is a <span class="doxyComputerOutput">static_suite&amp;</span> reference. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">concept</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">test_values_range</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a range of values for <span class="doxyComputerOutput">test_each()</span>. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">concept</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">test_values_tuple</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>C++20 concept satisfied when <span class="doxyComputerOutput">T</span> is a tuple of values for <span class="doxyComputerOutput">test_each()</span>. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable</a> (Callable_T &amp;&amp;callable, Args_T &amp;&amp;... arguments)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Creates the function object that holds the body of a test case or suite. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Self_T, class Values_T, class Callable_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">test_each_value</a> (Self_T &amp;self, const test_case_name &amp;name, Values_T &amp;&amp;values, Callable_T &amp;callable)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Adds and runs a test case for each value. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ header file with declarations for the µTest++ test hierarchy.</p>


<p>This header provides the declarations for the test hierarchy used within the µTest++ framework: the internal <span class="doxyComputerOutput">detail::runnable_base</span> base class, and the <span class="doxyComputerOutput">test_case</span>, <span class="doxyComputerOutput">suite</span>, <span class="doxyComputerOutput">top_suite</span>, and <span class="doxyComputerOutput">static_suite</span> classes. They offer mechanisms for running test cases, managing the counters of the passed and failed checks, and registering test suites with the runner.</p>


<p>The design ensures that test suites are non-copyable and non-movable, maintaining unique ownership and consistent state. Flexible support for callable objects enables a wide range of test suite definitions, facilitating expressive and maintainable test organisation across embedded and general C++ projects.</p>


<p>All definitions reside within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>The header files are organised within the <span class="doxyComputerOutput">include/micro-os-plus/micro-test-plus</span> folder to maintain a structured and modular codebase.</p>


<p>This file is intended solely for internal use within the framework and should not be included directly by user code.</p>


<div class="doxySectionDef">

## Functions

### bind\_callable() {#a6abb44ef8226b1f80aad8010b5ef1a5c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Self_T, typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::detail::bind_callable (Callable_T &amp;&amp; callable, Args_T &amp;&amp;... arguments)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel nodiscard">nodiscard</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Creates the function object that holds the body of a test case or suite.</p>


<p>Without additional arguments, the callable already has the signature <span class="doxyComputerOutput">void (Self_T&amp;)</span>, and a copy of it is returned, without a wrapper.</p>


<p>Otherwise, a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable">bound_callable</a></span> stores copies of the callable and of the arguments (decayed, as by <span class="doxyComputerOutput">auto</span>), since a suite may run after the caller's temporaries are gone; the callable receives the copies as non-<span class="doxyComputerOutput">const</span> lvalues. A reference parameter thus refers to the copy; to refer to the caller's object, pass a pointer, or <span class="doxyComputerOutput">std::ref()</span>, which converts to a <span class="doxyComputerOutput">T&amp;</span> parameter (an <span class="doxyComputerOutput">auto&amp;</span> parameter receives the <span class="doxyComputerOutput">std::reference_wrapper</span> itself).</p>


<p>The returned object holds a copy of the callable (decayed, as by <span class="doxyComputerOutput">auto</span>) when there are no additional arguments; otherwise it is a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable">bound_callable</a></span> that holds copies of the callable and of the arguments, and passes the arguments after the leading reference, which is passed when the body is invoked. No memory is allocated, other than by the copies themselves.</p>


<p>A suite stores the object in a <span class="doxyComputerOutput">std::function</span>, since it runs later; a test case, which runs immediately, refers to it with a <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">callable_ref</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Self_T</td>
<td class="doxyParamItemDescription"><p>The type referred to by the first parameter of the callable (<span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span> or <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a></span>).</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Args_T</td>
<td class="doxyParamItemDescription"><p>The types of the additional callable arguments.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">callable</td>
<td class="doxyParamItemDescription"><p>A generic callable object, usually a lambda.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">arguments</td>
<td class="doxyParamItemDescription"><p>A possibly empty list of arguments forwarded to the callable after the leading <span class="doxyComputerOutput">Self_T&amp;</span> reference.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The function object, invocable with a <span class="doxyComputerOutput">Self_T&amp;</span> argument.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00278">278</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">278</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable</a> (Callable_T&amp;&amp; callable, Args_T&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(arguments) == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> std::forward&lt;Callable_T&gt; (callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">285</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">286</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable">bound_callable&lt;Self_T, std::decay_t&lt;Callable_T&gt;</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">287</span><span class="doxyLineContent"><span class="doxyHighlight">                                std::decay_t&lt;Args_T&gt;...&gt;{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">288</span><span class="doxyLineContent"><span class="doxyHighlight">            std::forward&lt;Callable_T&gt; (callable),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">289</span><span class="doxyLineContent"><span class="doxyHighlight">            std::forward&lt;Args_T&gt; (arguments)...</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span><span class="doxyLineContent"><span class="doxyHighlight">          };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">micro_os_plus::micro_test_plus::detail::bind_callable</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">micro_os_plus::micro_test_plus::detail::bind_callable</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ad4ac49522cfd6e1608d9ac64ab7a8b91">micro_os_plus::micro_test_plus::detail::runnable_base::create_test_case</a>.</p>

</div>
</div>

### test\_each\_value() {#acb0858a0ba8b635ff89c4cb00c532ce8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Self_T, class Values_T, class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::test_each_value (Self_T &amp; self, const test_case_name &amp; name, Values_T &amp;&amp; values, Callable_T &amp; callable)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Adds and runs a test case for each value.</p>


<p>For each value, the name is built in a local string, which lives while the test case runs, since a test case runs within the call to <span class="doxyComputerOutput">test()</span>, and the test case is added with <span class="doxyComputerOutput">test()</span>, with the location of the call to <span class="doxyComputerOutput">test_each()</span>. The callable receives each value as a <span class="doxyComputerOutput">const</span> lvalue, referring to the element itself; neither the values nor the callable are copied. The values of a range are iterated by a range-based <span class="doxyComputerOutput">for</span> statement, and those of a tuple are expanded by <span class="doxyComputerOutput">std::apply()</span>, in order.</p>


<p>The common implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#afe716dc1b9245d7761b1fd6e6e854c5c">test_case::test_each()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a08e3a26d6e032a580f095f8dcf8b2b41">suite::test_each()</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Self_T</td>
<td class="doxyParamItemDescription"><p>The type of the test case or suite.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Values_T</td>
<td class="doxyParamItemDescription"><p>The type of the range or tuple of values.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable object.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">self</td>
<td class="doxyParamItemDescription"><p>The test case or suite to which the test cases are added.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The common name of the test cases.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">values</td>
<td class="doxyParamItemDescription"><p>The range or tuple of values.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">callable</td>
<td class="doxyParamItemDescription"><p>The callable object, invoked with the test case and each value.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00746">746</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">746</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">test_each_value</a> (Self_T&amp; self, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; name,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">747</span><span class="doxyLineContent"><span class="doxyHighlight">                     Values_T&amp;&amp; values, Callable_T&amp; callable)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">748</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">749</span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t position = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">750</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">751</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> run_one</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">752</span><span class="doxyLineContent"><span class="doxyHighlight">          = [&amp;self, &amp;name, &amp;callable, &amp;position] (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">753</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">754</span><span class="doxyLineContent"><span class="doxyHighlight">          ++position;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">755</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">756</span><span class="doxyLineContent"><span class="doxyHighlight">          std::string text{ name.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a624bdd72fd18db434a64993818bb5466">name</a> () };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">757</span><span class="doxyLineContent"><span class="doxyHighlight">          text += </span><span class="doxyHighlightStringLiteral">" ("</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">758</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable</a>&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">759</span><span class="doxyLineContent"><span class="doxyHighlight">                            std::remove_cvref_t&lt;</span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>)&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">760</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">761</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#a63b3cc3a8e725c2921787180f1244824">plain_text::append</a> (text, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">762</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">763</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">764</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">765</span><span class="doxyLineContent"><span class="doxyHighlight">              text += </span><span class="doxyHighlightCharLiteral">'#'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">766</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#a63b3cc3a8e725c2921787180f1244824">plain_text::append</a> (text, position);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">767</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">768</span><span class="doxyLineContent"><span class="doxyHighlight">          text += </span><span class="doxyHighlightCharLiteral">')'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">769</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">770</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// The test case runs within this call, so the value and the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">771</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// callable are captured by reference, not copied.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">772</span><span class="doxyLineContent"><span class="doxyHighlight">          self.test (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>{ text, name.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#abfb91a55df657bbfbfb5fe774f46329b">location</a> () },</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">773</span><span class="doxyLineContent"><span class="doxyHighlight">                     [&amp;callable, &amp;<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; test_self)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">774</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">775</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_member_pointer_v&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">776</span><span class="doxyLineContent"><span class="doxyHighlight">                                std::remove_cvref_t&lt;Callable_T&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">777</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">778</span><span class="doxyLineContent"><span class="doxyHighlight">                  std::invoke (callable, test_self, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">779</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">780</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">781</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">782</span><span class="doxyLineContent"><span class="doxyHighlight">                  callable (test_self, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">783</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">784</span><span class="doxyLineContent"><span class="doxyHighlight">            });</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">785</span><span class="doxyLineContent"><span class="doxyHighlight">        };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">786</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">787</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">test_values_range&lt;Values_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">788</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">789</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a> : values)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">790</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">791</span><span class="doxyLineContent"><span class="doxyHighlight">              run_one (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">792</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">793</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">794</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">795</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">796</span><span class="doxyLineContent"><span class="doxyHighlight">          std::apply ([&amp;run_one] (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp;... elements)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">797</span><span class="doxyLineContent"><span class="doxyHighlight">            { (run_one (elements), ...); }, values);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">798</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">799</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#a63b3cc3a8e725c2921787180f1244824">micro_os_plus::micro_test_plus::detail::plain_text::append</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#abfb91a55df657bbfbfb5fe774f46329b">micro_os_plus::micro_test_plus::test_case_name::location</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a624bdd72fd18db434a64993818bb5466">micro_os_plus::micro_test_plus::test_case_name::name</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">micro_os_plus::micro_test_plus::detail::test_each_value</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a86d654e9059b1acecbf49f2725419320">micro_os_plus::micro_test_plus::suite::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a08e3a26d6e032a580f095f8dcf8b2b41">micro_os_plus::micro_test_plus::suite::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a018224e675db634b3b9898c72d1c8655">micro_os_plus::micro_test_plus::test_case::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#afe716dc1b9245d7761b1fd6e6e854c5c">micro_os_plus::micro_test_plus::test_case::test_each</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">micro_os_plus::micro_test_plus::detail::test_each_value</a>.</p>

</div>
</div>

</div>

## File Listing

The file content with the documentation metadata removed is:

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00001"></a>1</span><span class="doxyLineContent"><span class="doxyHighlightComment">/*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00002"></a>2</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * This file is part of the µOS++ project (https://micro-os-plus.github.io/).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00003"></a>3</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00004"></a>4</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00005"></a>5</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Permission to use, copy, modify, and/or distribute this software for any</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00006"></a>6</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * purpose is hereby granted, under the terms of the MIT license.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00007"></a>7</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00008"></a>8</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * If a copy of the license was not distributed with this file, it can be</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00009"></a>9</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * obtained from https://opensource.org/licenses/mit.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00010"></a>10</span><span class="doxyLineContent"><span class="doxyHighlightComment"> *</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00011"></a>11</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * Major parts of the code are inspired from v1.1.8 of the Boost UT project,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * released under the terms of the Boost Version 1 Software License,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00014"></a>14</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00015"></a>15</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00016"></a>16</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00017"></a>17</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00046"></a>46</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00047"></a>47</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/project-config.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/micro-test-plus-defines.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/counters-h">counters.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/stopwatch-h">stopwatch.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstddef&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;functional&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;initializer_list&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;memory&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string_view&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;tuple&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;type_traits&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;utility&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00083"></a>83</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00084"></a>84</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00085"></a>85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wpadded"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00086"></a>86</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00087"></a>87</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00088"></a>88</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wdocumentation"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00089"></a>89</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else </span><span class="doxyHighlightComment">// GCC only</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00090"></a>90</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wsuggest-final-types"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00091"></a>91</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wsuggest-final-methods"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00092"></a>92</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wredundant-tags"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00093"></a>93</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00094"></a>94</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00095"></a>95</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00096"></a>96</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00097"></a>97</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00098"></a>98</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00099"></a>99</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00100"></a>100</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00101"></a>101</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00102"></a>102</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00103"></a>103</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00104"></a>104</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00105"></a>105</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00106"></a>106</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00107"></a>107</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00108"></a>108</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00157"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">157</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00158"></a>158</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00159"></a>159</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00169"></a>169</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a624bdd72fd18db434a64993818bb5466">name</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00170"></a>170</span><span class="doxyLineContent"><span class="doxyHighlight">                    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#abfb91a55df657bbfbfb5fe774f46329b">location</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00171"></a>171</span><span class="doxyLineContent"><span class="doxyHighlight">                    = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ()) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00172"></a>172</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00182"></a>182</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a86534273fcfac3a3edd7fbae2f04e5ea">test_case_name</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a624bdd72fd18db434a64993818bb5466">name</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00183"></a>183</span><span class="doxyLineContent"><span class="doxyHighlight">                    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#abfb91a55df657bbfbfb5fe774f46329b">location</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00184"></a>184</span><span class="doxyLineContent"><span class="doxyHighlight">                    = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ()) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00185"></a>185</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00193"></a>193</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00194"></a>194</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a624bdd72fd18db434a64993818bb5466">name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00195"></a>195</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00203"></a>203</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00204"></a>204</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#abfb91a55df657bbfbfb5fe774f46329b">location</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00205"></a>205</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00206"></a>206</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00213"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a2941ef285834b5d22e0300238473e648">213</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#a2941ef285834b5d22e0300238473e648">name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00214"></a>214</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00222"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#ab9ecf89d495d71f224e182228eaec66e">222</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name/#ab9ecf89d495d71f224e182228eaec66e">location_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00223"></a>223</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00224"></a>224</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00225"></a>225</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00226"></a>226</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00227"></a>227</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00228"></a>228</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00229"></a>229</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">check_result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00230"></a>230</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">reporter;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00231"></a>231</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">reporter_human;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00232"></a>232</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">reporter_tap;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00233"></a>233</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00234"></a>234</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00235"></a>235</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00272"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">272</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00273"></a>273</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00281"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">281</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00282"></a>282</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00290"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aec75a9652b7e98188d506c462aa73e19">290</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aec75a9652b7e98188d506c462aa73e19">check_result</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00291"></a>291</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00299"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ac1362875db31c5b5b875520025597a65">299</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ac1362875db31c5b5b875520025597a65">reporter_human</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00300"></a>300</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00309"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ac6f88fbc9f895d8d7495393d1a9a7d6a">309</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00310"></a>310</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00311"></a>311</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00320"></a>320</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a8def9cddbb5bc877918104c785271753">own_index</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00321"></a>321</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00328"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0252f278ae59dddef03282d7aa84a51c">328</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0252f278ae59dddef03282d7aa84a51c">runnable_base</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00329"></a>329</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00337"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6086e33edab5d5b8b837cab432f087c9">337</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6086e33edab5d5b8b837cab432f087c9">runnable_base</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00338"></a>338</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00345"></a>345</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00346"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a41f7fada4e78a1869653f67f9acedb42">346</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a41f7fada4e78a1869653f67f9acedb42">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00347"></a>347</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00348"></a>348</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00356"></a>356</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00357"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a18b82d51daccd8a75f87e043d2660006">357</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a41f7fada4e78a1869653f67f9acedb42">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00358"></a>358</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00359"></a>359</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00366"></a>366</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">~runnable_base</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00367"></a>367</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00368"></a>368</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00369"></a>369</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00377"></a>377</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00378"></a>378</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00379"></a>379</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00394"></a>394</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00395"></a>395</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00396"></a>396</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00397"></a>397</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00402"></a>402</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00416"></a>416</span><span class="doxyLineContent"><span class="doxyHighlight">      [[deprecated (</span><span class="doxyHighlightStringLiteral">"internal to the framework (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00417"></a>417</span><span class="doxyLineContent"><span class="doxyHighlight">        nodiscard]] </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00418"></a>418</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a8def9cddbb5bc877918104c785271753">own_index</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00419"></a>419</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00432"></a>432</span><span class="doxyLineContent"><span class="doxyHighlight">      [[deprecated (</span><span class="doxyHighlightStringLiteral">"internal to the framework (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00433"></a>433</span><span class="doxyLineContent"><span class="doxyHighlight">        nodiscard]] </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00434"></a>434</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7ad637d38c035d54c872f72e1b9ac358">current_subtest_index</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00435"></a>435</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00447"></a>447</span><span class="doxyLineContent"><span class="doxyHighlight">      [[deprecated (</span><span class="doxyHighlightStringLiteral">"internal to the framework (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00448"></a>448</span><span class="doxyLineContent"><span class="doxyHighlight">        nodiscard]] </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00449"></a>449</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aaf838b03cddfb039d1295611be8a5e32">children_subtests_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00450"></a>450</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00454"></a>454</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00455"></a>455</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00456"></a>456</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00474"></a>474</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00475"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a1bffa5c8f05ffb464857521badd6ecef">475</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a1bffa5c8f05ffb464857521badd6ecef">run</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00476"></a>476</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00477"></a>477</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00491"></a>491</span><span class="doxyLineContent"><span class="doxyHighlight">      [[noreturn]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00492"></a>492</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a5fec64d9b300277d56e02193bb7d0a46">abort</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00493"></a>493</span><span class="doxyLineContent"><span class="doxyHighlight">             = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ()) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00494"></a>494</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00495"></a>495</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00512"></a>512</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">runner</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00513"></a>513</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00514"></a>514</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00530"></a>530</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00531"></a>531</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00532"></a>532</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00547"></a>547</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00548"></a>548</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a3fd5730af8bd449cc56e29d5d14509e9">running_test_case</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00549"></a>549</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00563"></a>563</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00564"></a>564</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aaec8b378e1d1639a5fa0e6dec20d6a46">is_aborted</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00565"></a>565</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00579"></a>579</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00580"></a>580</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a58c3051635ce2389a8afc2222cd6b30d">is_listing</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00581"></a>581</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00594"></a>594</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00595"></a>595</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0d131770fe8aed387ca6da982f1ff60e">next_test_point_number</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00596"></a>596</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00611"></a>611</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00612"></a>612</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a> (</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00613"></a>613</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00641"></a>641</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00642"></a>642</span><span class="doxyLineContent"><span class="doxyHighlight">      [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00643"></a>643</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ad4ac49522cfd6e1608d9ac64ab7a8b91">create_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; parent_suite,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00644"></a>644</span><span class="doxyLineContent"><span class="doxyHighlight">                        </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> nesting_depth, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00645"></a>645</span><span class="doxyLineContent"><span class="doxyHighlight">                        Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00646"></a>646</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00647"></a>647</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00656"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">656</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00657"></a>657</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00671"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a87091ad4653e9db854ba9d5a64b30738">671</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a87091ad4653e9db854ba9d5a64b30738">totals_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00672"></a>672</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00681"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ab7513249cc0aac30e3edd7008d08d355">681</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ab7513249cc0aac30e3edd7008d08d355">runner_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00682"></a>682</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00692"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">692</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">own_index_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00693"></a>693</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00704"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">704</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a> = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00705"></a>705</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00716"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aff1a81aff41ab5dc80e2fac1c5a78a31">716</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a> = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00717"></a>717</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00718"></a>718</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00719"></a>719</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00720"></a>720</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00747"></a>747</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Self_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00748"></a>748</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00749"></a>749</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable</a> (Callable_T&amp;&amp; callable, Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00750"></a>750</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00751"></a>751</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00752"></a>752</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00775"></a>775</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Self_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00776"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable">776</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a15afa0762b074f3ef56335580bf7119d">bound_callable</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00777"></a>777</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00778"></a>778</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00801"></a>801</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> C, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... A&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00802"></a>802</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(A) &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00803"></a>803</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a15afa0762b074f3ef56335580bf7119d">bound_callable</a> (C&amp;&amp; callable, A&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00804"></a>804</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00816"></a>816</span><span class="doxyLineContent"><span class="doxyHighlight">      [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00817"></a>817</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a65c86f89bf9e216b5e2e3dae5f599a49">operator()</a>(Self_T&amp; self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00818"></a>818</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00819"></a>819</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00833"></a>833</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;std::size_t... Is&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00834"></a>834</span><span class="doxyLineContent"><span class="doxyHighlight">      [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00835"></a>835</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#aa0583b5d4d54c56f1460c18e88e43aa2">invoke</a> (Self_T&amp; self, std::index_sequence&lt;Is...&gt;);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00836"></a>836</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00844"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#ae9058f5a50afba3eafc6b86d68957fdb">844</a></span><span class="doxyLineContent"><span class="doxyHighlight">      Callable_T <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#ae9058f5a50afba3eafc6b86d68957fdb">callable_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00845"></a>845</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00853"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a674485f271757aa111f6cbf39bfa12f8">853</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::tuple&lt;Args_T...&gt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a674485f271757aa111f6cbf39bfa12f8">arguments_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00854"></a>854</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00855"></a>855</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00856"></a>856</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00857"></a>857</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00878"></a>878</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Self_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00879"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">879</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a3e789d4fded524d5d5d088618d615026">callable_ref</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00880"></a>880</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00881"></a>881</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00897"></a>897</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00898"></a>898</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (!std::is_same_v&lt;std::remove_cv_t&lt;Callable_T&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00899"></a>899</span><span class="doxyLineContent"><span class="doxyHighlight">                                  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a3e789d4fded524d5d5d088618d615026">callable_ref&lt;Self_T&gt;</a>&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00900"></a>900</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a3e789d4fded524d5d5d088618d615026">callable_ref</a> (Callable_T&amp; callable) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00901"></a>901</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00916"></a>916</span><span class="doxyLineContent"><span class="doxyHighlight">      [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00917"></a>917</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a10148eb90e3393d8166e8712468d32e2">operator()</a>(Self_T&amp; self) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00918"></a>918</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00919"></a>919</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00934"></a>934</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00935"></a>935</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00936"></a>936</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#affde2e2f927df6b5ada7f5578f8d5c36">invoke_callable</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* callable, Self_T&amp; self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00937"></a>937</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00944"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a7a5a1b1e001f34f819ac65e63c2d9567">944</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a7a5a1b1e001f34f819ac65e63c2d9567">callable_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00945"></a>945</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00953"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a7ca4453fe089a72345a476490212ae59">953</a></span><span class="doxyLineContent"><span class="doxyHighlight">      void (*<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a7ca4453fe089a72345a476490212ae59">invoke_</a>) (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* callable, Self_T&amp; self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00954"></a>954</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00955"></a>955</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00956"></a>956</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00957"></a>957</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00970"></a>970</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00971"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">971</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">test_values_range</a> = std::is_array_v&lt;std::remove_cvref_t&lt;T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00972"></a>972</span><span class="doxyLineContent"><span class="doxyHighlight">                                or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/container-like">container_like&lt;std::remove_cvref_t&lt;T&gt;</a>&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00973"></a>973</span><span class="doxyLineContent"><span class="doxyHighlight">                                or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/free-range">free_range&lt;std::remove_cvref_t&lt;T&gt;</a>&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00974"></a>974</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00986"></a>986</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00987"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">987</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">test_values_tuple</a> = (not <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">test_values_range&lt;T&gt;</a>) and </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00988"></a>988</span><span class="doxyLineContent"><span class="doxyHighlight">      std::tuple_size&lt;std::remove_cvref_t&lt;T&gt;&gt;<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">::value</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00989"></a>989</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00990"></a>990</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01011"></a>1011</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Self_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Values_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01012"></a>1012</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01013"></a>1013</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#acb0858a0ba8b635ff89c4cb00c532ce8">test_each_value</a> (Self_T&amp; self, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; name,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01014"></a>1014</span><span class="doxyLineContent"><span class="doxyHighlight">                     Values_T&amp;&amp; values, Callable_T&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01015"></a>1015</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01016"></a>1016</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01017"></a>1017</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01018"></a>1018</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01019"></a>1019</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01020"></a>1020</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01050"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">1050</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">test_case</a> final : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01051"></a>1051</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01059"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a484008ed66130a2bf334948841099943">1059</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01060"></a>1060</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01061"></a>1061</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01082"></a>1082</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01083"></a>1083</span><span class="doxyLineContent"><span class="doxyHighlight">               <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; parent_suite, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a8def9cddbb5bc877918104c785271753">own_index</a>, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01084"></a>1084</span><span class="doxyLineContent"><span class="doxyHighlight">               <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">detail::callable_ref&lt;test_case&gt;</a> body);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01085"></a>1085</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01086"></a>1086</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01093"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ab7f67423b68a596e6a31ffc7ba261345">1093</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ab7f67423b68a596e6a31ffc7ba261345">test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">test_case</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01094"></a>1094</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01102"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a13ad0f433d3a8189cb806ddb38c2a56c">1102</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a13ad0f433d3a8189cb806ddb38c2a56c">test_case</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">test_case</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01103"></a>1103</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01110"></a>1110</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">test_case</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01111"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a556bbac39502797d52241f481e021847">1111</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a556bbac39502797d52241f481e021847">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">test_case</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01112"></a>1112</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01113"></a>1113</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01121"></a>1121</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">test_case</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01122"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac2e310ec902a0c3e786d4c415269c23e">1122</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a556bbac39502797d52241f481e021847">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">test_case</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01123"></a>1123</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01124"></a>1124</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01132"></a>1132</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0ffeed47bd9ecd07bda3a2f33f062b71">~test_case</a> () </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01133"></a>1133</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01134"></a>1134</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01135"></a>1135</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01153"></a>1153</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01154"></a>1154</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01155"></a>1155</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aac23ee148d8e5946cd87e0de036e9fb8">test</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01156"></a>1156</span><span class="doxyLineContent"><span class="doxyHighlight">          Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01157"></a>1157</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01198"></a>1198</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Values_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01199"></a>1199</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">detail::test_values_range&lt;Values_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01200"></a>1200</span><span class="doxyLineContent"><span class="doxyHighlight">                or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">detail::test_values_tuple&lt;Values_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01201"></a>1201</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01202"></a>1202</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#afe716dc1b9245d7761b1fd6e6e854c5c">test_each</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Values_T&amp;&amp; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01203"></a>1203</span><span class="doxyLineContent"><span class="doxyHighlight">               Callable_T&amp;&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01204"></a>1204</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01226"></a>1226</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01227"></a>1227</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01228"></a>1228</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#afe716dc1b9245d7761b1fd6e6e854c5c">test_each</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, std::initializer_list&lt;T&gt; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01229"></a>1229</span><span class="doxyLineContent"><span class="doxyHighlight">               Callable_T&amp;&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01230"></a>1230</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01231"></a>1231</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01232"></a>1232</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01251"></a>1251</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01252"></a>1252</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">extension::checkable&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01253"></a>1253</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01254"></a>1254</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-expectations/#gaf4f5f9632b5a290c1894984661a41a86">expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01255"></a>1255</span><span class="doxyLineContent"><span class="doxyHighlight">                                = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01256"></a>1256</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01288"></a>1288</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01289"></a>1289</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">extension::checkable&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01290"></a>1290</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01291"></a>1291</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-requirements/#gace68a1bd4dd258082f4b1fc01fcd008a">require</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01292"></a>1292</span><span class="doxyLineContent"><span class="doxyHighlight">                                 = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01293"></a>1293</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01294"></a>1294</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01299"></a>1299</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01316"></a>1316</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01317"></a>1317</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/legacy-checkable">extension::legacy_checkable&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01318"></a>1318</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"the argument is always true; write the condition "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01319"></a>1319</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"(since 6.0.0)"</span><span class="doxyHighlight">)]] </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01320"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0fbd378373bbda24c9d574904268bc94">1320</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a0fbd378373bbda24c9d574904268bc94">expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01321"></a>1321</span><span class="doxyLineContent"><span class="doxyHighlight">                                = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01322"></a>1322</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01336"></a>1336</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01337"></a>1337</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/legacy-checkable">extension::legacy_checkable&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01338"></a>1338</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"the argument is always true; write the condition "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01339"></a>1339</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"(since 6.0.0)"</span><span class="doxyHighlight">)]] </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01340"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a51f15ed441451eb5809559a54a1c7a73">1340</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a51f15ed441451eb5809559a54a1c7a73">require</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01341"></a>1341</span><span class="doxyLineContent"><span class="doxyHighlight">                                 = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01342"></a>1342</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01359"></a>1359</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01360"></a>1360</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">extension::checkable&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01361"></a>1361</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"use require() (since 6.0.0)"</span><span class="doxyHighlight">)]] </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01362"></a>1362</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ad25dc8d5d657ace9d47d3a95b3341802">assume</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01363"></a>1363</span><span class="doxyLineContent"><span class="doxyHighlight">                                = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01364"></a>1364</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01368"></a>1368</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01369"></a>1369</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01370"></a>1370</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01371"></a>1371</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01379"></a>1379</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01380"></a>1380</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01381"></a>1381</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01382"></a>1382</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01401"></a>1401</span><span class="doxyLineContent"><span class="doxyHighlight">    [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01402"></a>1402</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">run</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01403"></a>1403</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01404"></a>1404</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01405"></a>1405</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01420"></a>1420</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01421"></a>1421</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1980019eed5ac5b1eef65302eb9cc9cd">fail_unexpected_exception</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* what);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01422"></a>1422</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01423"></a>1423</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01424"></a>1424</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01433"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aad4b8f6b15291abb5dc6602784fa7bad">1433</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">detail::callable_ref&lt;test_case&gt;</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aad4b8f6b15291abb5dc6602784fa7bad">callable_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01434"></a>1434</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01442"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1c0173e5186060d94f09db00552f44b4">1442</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1c0173e5186060d94f09db00552f44b4">location_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01443"></a>1443</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01451"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a3f1717ee8c04af1181f6dff2966b3d34">1451</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a3f1717ee8c04af1181f6dff2966b3d34">parent_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01452"></a>1452</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01459"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a3da31fa70e1009cfde8a13a7ffaad036">1459</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a3da31fa70e1009cfde8a13a7ffaad036">nesting_depth_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01460"></a>1460</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01461"></a>1461</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01462"></a>1462</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01463"></a>1463</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01498"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">1498</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a> : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01499"></a>1499</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01507"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">1507</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01508"></a>1508</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01515"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a099a369b6d1f67c296baf9d22be40ba2">1515</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human">detail::reporter_human</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01516"></a>1516</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01523"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a6cd3b3f893312fe43fa2d7b5018646e9">1523</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">detail::reporter_tap</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01524"></a>1524</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01525"></a>1525</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01546"></a>1546</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01547"></a>1547</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a> (std::string_view <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01548"></a>1548</span><span class="doxyLineContent"><span class="doxyHighlight">           Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01549"></a>1549</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01550"></a>1550</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01557"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a56a0f7e480793aa3a55f49544187d12a">1557</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a56a0f7e480793aa3a55f49544187d12a">suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01558"></a>1558</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01566"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aa8dac776abb9f904d1d148bf07fedbab">1566</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aa8dac776abb9f904d1d148bf07fedbab">suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01567"></a>1567</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01574"></a>1574</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01575"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a744cbf6c937041b6f8a5d6530479c3af">1575</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a744cbf6c937041b6f8a5d6530479c3af">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01576"></a>1576</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01577"></a>1577</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01585"></a>1585</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01586"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aaaa545978a454f1ae63fc06ac5169efe">1586</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a744cbf6c937041b6f8a5d6530479c3af">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01587"></a>1587</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01588"></a>1588</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01597"></a>1597</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">~suite</a> () </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01598"></a>1598</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01599"></a>1599</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01600"></a>1600</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01618"></a>1618</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01619"></a>1619</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01620"></a>1620</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">test</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01621"></a>1621</span><span class="doxyLineContent"><span class="doxyHighlight">          Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01622"></a>1622</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01663"></a>1663</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Values_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01664"></a>1664</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">detail::test_values_range&lt;Values_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01665"></a>1665</span><span class="doxyLineContent"><span class="doxyHighlight">                or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">detail::test_values_tuple&lt;Values_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01666"></a>1666</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01667"></a>1667</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a08e3a26d6e032a580f095f8dcf8b2b41">test_each</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Values_T&amp;&amp; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01668"></a>1668</span><span class="doxyLineContent"><span class="doxyHighlight">               Callable_T&amp;&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01669"></a>1669</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01691"></a>1691</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01692"></a>1692</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01693"></a>1693</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a08e3a26d6e032a580f095f8dcf8b2b41">test_each</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case-name">test_case_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, std::initializer_list&lt;T&gt; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01694"></a>1694</span><span class="doxyLineContent"><span class="doxyHighlight">               Callable_T&amp;&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01695"></a>1695</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01696"></a>1696</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01701"></a>1701</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01717"></a>1717</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"the timings are internal (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01718"></a>1718</span><span class="doxyLineContent"><span class="doxyHighlight">      nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01719"></a>1719</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a06c121fc0e8e87451a718846a11fc853">timings</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01720"></a>1720</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01735"></a>1735</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"the timings are internal (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01736"></a>1736</span><span class="doxyLineContent"><span class="doxyHighlight">      nodiscard]] <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01737"></a>1737</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a06c121fc0e8e87451a718846a11fc853">timings</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01738"></a>1738</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01742"></a>1742</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01743"></a>1743</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01744"></a>1744</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01757"></a>1757</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01758"></a>1758</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">run</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01759"></a>1759</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01760"></a>1760</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01761"></a>1761</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01777"></a>1777</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01778"></a>1778</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a1d15dd97c94c3dabccb9e5a7444af0ec">fail_unexpected_exception</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* what);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01779"></a>1779</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01780"></a>1780</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01797"></a>1797</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01798"></a>1798</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a532459c0a6362991282548f4f845cb97">link</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01799"></a>1799</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01813"></a>1813</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01814"></a>1814</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a20ca7721bdf59488ed0713378235cfd2">unlink</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01815"></a>1815</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01816"></a>1816</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01825"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aec447d7b5763ffca58738813bad2e805">1825</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::function&lt;void (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>&amp;)&gt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aec447d7b5763ffca58738813bad2e805">callable_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01826"></a>1826</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01835"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">1835</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">stopwatch_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01836"></a>1836</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01847"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#abcc884f846957ce43a2e076ba6c7c129">1847</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#abcc884f846957ce43a2e076ba6c7c129">owned_name_</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01848"></a>1848</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01857"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a65d1fed18566774295fcbc7df44c216e">1857</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a65d1fed18566774295fcbc7df44c216e">next_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01858"></a>1858</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01869"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">1869</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a>* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">first_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01870"></a>1870</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01871"></a>1871</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01872"></a>1872</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01873"></a>1873</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01890"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite">1890</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a> final : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01891"></a>1891</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01899"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a68a030feff1f481126e9a6d170331420">1899</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01900"></a>1900</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01901"></a>1901</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01912"></a>1912</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01913"></a>1913</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01914"></a>1914</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01921"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ae653f09197ac9342cbb52efc386e96df">1921</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ae653f09197ac9342cbb52efc386e96df">top_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01922"></a>1922</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01930"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a04740b417d9571048cbee2125275acce">1930</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a04740b417d9571048cbee2125275acce">top_suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01931"></a>1931</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01938"></a>1938</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01939"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a7601ca8102a7b4b3d7e7f8b33a0728a3">1939</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a7601ca8102a7b4b3d7e7f8b33a0728a3">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01940"></a>1940</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01941"></a>1941</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01949"></a>1949</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01950"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a809ba320392c0ced46977d0b7d371543">1950</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a7601ca8102a7b4b3d7e7f8b33a0728a3">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01951"></a>1951</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01952"></a>1952</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01961"></a>1961</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">~top_suite</a> () </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01962"></a>1962</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01963"></a>1963</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01964"></a>1964</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01965"></a>1965</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01966"></a>1966</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01967"></a>1967</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01968"></a>1968</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01969"></a>1969</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01985"></a>1985</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01986"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">1986</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">static_suite_body</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01987"></a>1987</span><span class="doxyLineContent"><span class="doxyHighlight">        = (!std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01988"></a>1988</span><span class="doxyLineContent"><span class="doxyHighlight">                                std::decay_t&lt;Args_T&gt;&amp;...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01989"></a>1989</span><span class="doxyLineContent"><span class="doxyHighlight">          &amp;&amp; std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a>&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01990"></a>1990</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::decay_t&lt;Args_T&gt;&amp;...&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01991"></a>1991</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01992"></a>1992</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01993"></a>1993</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01994"></a>1994</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02037"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">2037</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">static_suite</a> final : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0232c48687da2eb3a2171d8647ffb0a6">suite</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02038"></a>2038</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02039"></a>2039</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02064"></a>2064</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02065"></a>2065</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">detail::static_suite_body</a>&lt;Callable_T, Args_T...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02066"></a>2066</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">static_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02067"></a>2067</span><span class="doxyLineContent"><span class="doxyHighlight">                  Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02068"></a>2068</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02069"></a>2069</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02074"></a>2074</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02106"></a>2106</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02107"></a>2107</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">detail::static_suite_body</a>&lt;Callable_T, Args_T...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02108"></a>2108</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"use a suite&amp; first parameter (since 6.0.0)"</span><span class="doxyHighlight">)]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02109"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a7890c9db0d4a64f53164857a4d034435">2109</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a7890c9db0d4a64f53164857a4d034435">static_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02110"></a>2110</span><span class="doxyLineContent"><span class="doxyHighlight">                  Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02111"></a>2111</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02115"></a>2115</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02116"></a>2116</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02123"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae6e593e9cb04f52067b131da4a4c3db3">2123</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae6e593e9cb04f52067b131da4a4c3db3">static_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">static_suite</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02124"></a>2124</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02132"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a441e44ba0fdf43efc58992a9e3e8ce74">2132</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a441e44ba0fdf43efc58992a9e3e8ce74">static_suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">static_suite</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02133"></a>2133</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02140"></a>2140</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">static_suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02141"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae050e143c88fb99eddf2060d37ad4340">2141</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae050e143c88fb99eddf2060d37ad4340">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">static_suite</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02142"></a>2142</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02143"></a>2143</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02151"></a>2151</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">static_suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02152"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a9715939a3717861be374ce1a884fd7fa">2152</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae050e143c88fb99eddf2060d37ad4340">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">static_suite</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02153"></a>2153</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02154"></a>2154</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02163"></a>2163</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#aee03f72ebd3b2ff8e670b00e07d7f729">~static_suite</a> () </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02164"></a>2164</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02165"></a>2165</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02180"></a>2180</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02181"></a>2181</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a7ac8520c7d0761e54e7482ca5d7e26f2">link_or_reject</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02182"></a>2182</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02183"></a>2183</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02184"></a>2184</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02185"></a>2185</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02186"></a>2186</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02187"></a>2187</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02188"></a>2188</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02189"></a>2189</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02190"></a>2190</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02191"></a>2191</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02192"></a>2192</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02193"></a>2193</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02194"></a>2194</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02195"></a>2195</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02196"></a>2196</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02197"></a>2197</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02198"></a>2198</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">inlines/test-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02199"></a>2199</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02200"></a>2200</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02201"></a>2201</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02202"></a>2202</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02203"></a>2203</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02204"></a>2204</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
