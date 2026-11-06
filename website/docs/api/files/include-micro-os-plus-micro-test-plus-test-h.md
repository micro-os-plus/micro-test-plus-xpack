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

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>"
#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/counters-h">counters.h</a>"
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A name of a suite or of a test case, with the location where it was given. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#details">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/generic-callable">generic_callable</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Concept satisfied by a callable object whose call operator is not a single non-template member function. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/generic-callable/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/suite-body">suite_body</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Concept satisfied by a callable object that can be the body of a suite. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/suite-body/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">concept</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body">test_body</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Concept satisfied by a callable object that can be the body of a test case. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body/#details">More...</a></p>
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
<p>Concept satisfied when <span class="doxyComputerOutput">T</span> is a range of values for <span class="doxyComputerOutput">test_each()</span>. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range/#details">More...</a></p>
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
<p>Concept satisfied when <span class="doxyComputerOutput">T</span> is a tuple of values for <span class="doxyComputerOutput">test_each()</span>. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">concept</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/unsupported-condition">unsupported_condition</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Concept satisfied by a value that <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span> do not accept. <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/unsupported-condition/#details">More...</a></p>
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

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">escape_control_characters</a> (std::string &amp;name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Escapes the control characters of a name. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Callable_T, typename... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#abf92eca75cdfb0993bb529fdbb592be1">reject_suite_body</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stops the compilation with a message that tells what the body of a suite takes. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#abf92eca75cdfb0993bb529fdbb592be1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename Callable_T, typename... Args_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">reject_test_body</a> (void) noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stops the compilation with a message that tells what the body of a test case takes. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">test_each_value</a> (Self_T &amp;self, const located_name &amp;name, Values_T &amp;&amp;values, Callable_T &amp;callable)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Adds and runs a test case for each value. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Variables Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename... Ts&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">constexpr bool</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">dependent_false_v</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>A value that is always <span class="doxyComputerOutput">false</span>, but depends on the template arguments. <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>C++ header file with declarations for the µTest++ test hierarchy.</p>


<p>This header provides the declarations for the test hierarchy used within the µTest++ framework: the internal <span class="doxyComputerOutput">detail::runnable_base</span> base class, and the <span class="doxyComputerOutput">test_case</span>, <span class="doxyComputerOutput">suite</span>, <span class="doxyComputerOutput">top_suite</span>, and <span class="doxyComputerOutput">static_suite</span> classes. They offer mechanisms for running test cases, managing the counters of the passed and failed checks, and registering test suites with the runner.</p>


<p>The test suites are non-copyable and non-movable, so that each one has a single owner. Their bodies are any callable objects, such as functions and lambdas, with optional arguments.</p>


<p>All definitions reside within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace.</p>


<p>This file is included by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a></span>, which is the header that the applications include.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00344">344</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">344</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable</a> (Callable_T&amp;&amp; callable, Args_T&amp;&amp;... arguments)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(arguments) == 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> std::forward&lt;Callable_T&gt; (callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">351</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable">bound_callable&lt;Self_T, std::decay_t&lt;Callable_T&gt;</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">                                std::decay_t&lt;Args_T&gt;...&gt;{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">            std::forward&lt;Callable_T&gt; (callable),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span><span class="doxyLineContent"><span class="doxyHighlight">            std::forward&lt;Args_T&gt; (arguments)...</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span><span class="doxyLineContent"><span class="doxyHighlight">          };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">micro_os_plus::micro_test_plus::detail::bind_callable</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">micro_os_plus::micro_test_plus::detail::bind_callable</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6d375bb7425b231aa3605642289d2f44">micro_os_plus::micro_test_plus::detail::runnable_base::create_test_case</a>.</p>

</div>
</div>

### escape\_control\_characters() {#afe0adb93e576b2c11ba933ec65245d91}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::escape_control_characters (std::string &amp; name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Escapes the control characters of a name.</p>


<p>Replaces, in place, the control characters other than the tab, including the line feed and the NUL, with their escape sequences, so that the names reach the console and the output files as one line of visible text. Defined in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">src/test.cpp</a></span>.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name to escape.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The text is scanned first, so that a name without control characters is not touched. The tab is kept; all the other control characters, including the line feed and the NUL, and DEL, are replaced.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp/#l00080">80</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-cpp">test.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">80</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">escape_control_characters</a> (std::string&amp; name)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">81</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> is_control = [] (</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> unit = </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">unsigned</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> (unit &lt; 0x20 &amp;&amp; c != </span><span class="doxyHighlightCharLiteral">'\t'</span><span class="doxyHighlight">) || unit == 0x7F;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">        };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">87</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t first = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">while</span><span class="doxyHighlight"> (first &lt; name.size () &amp;&amp; !is_control (name[first]))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">          ++first;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (first == name.size ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string escaped (name, 0, first);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">      escaped.reserve (name.size () + 8);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (std::size_t i = first; i &lt; name.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (is_control (name[i]))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a1fd5e3a96e759c76038572203aa988c8">append_control_escape</a> (escaped, name[i]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">              escaped.push_back (name[i]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">      name = std::move (escaped);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a1fd5e3a96e759c76038572203aa988c8">micro_os_plus::micro_test_plus::detail::append_control_escape</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">micro_os_plus::micro_test_plus::detail::escape_control_characters</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#a6559d4b0648a5552702a2f5d40ba4db4">micro_os_plus::micro_test_plus::located_name::located_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#a49ca2791ea42fc17bd4f9de133c8adbb">micro_os_plus::micro_test_plus::located_name::located_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#a2be70223f532513d9f1ce311b436b72f">micro_os_plus::micro_test_plus::located_name::located_name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#a030144fd43957ba5e2c9a660d2dd33be">micro_os_plus::micro_test_plus::located_name::located_name</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">micro_os_plus::micro_test_plus::detail::escape_control_characters</a>.</p>

</div>
</div>

### reject\_suite\_body() {#abf92eca75cdfb0993bb529fdbb592be1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reject_suite_body (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stops the compilation with a message that tells what the body of a suite takes.</p>


<p>Always fails the static assertion that applies, since it is called only when <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/suite-body">suite_body</a></span> is not satisfied. A body that cannot be copied, or a body written for a test case, is recognised, to say so.</p>


<p>Called by the overloads of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#abdb31c03509a40a041b8f0ea8e12ebd1">runner::add_suite()</a></span> and of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a></span> constructor that are selected when the callable is not a valid body, as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">reject_test_body()</a></span> is for the test cases.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Args_T</td>
<td class="doxyParamItemDescription"><p>The types of the additional arguments.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00448">448</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#abf92eca75cdfb0993bb529fdbb592be1">448</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#abf92eca75cdfb0993bb529fdbb592be1">reject_suite_body</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">449</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">450</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (not std::is_copy_constructible_v&lt;std::decay_t&lt;Callable_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">451</span><span class="doxyLineContent"><span class="doxyHighlight">                    or not(std::is_copy_constructible_v&lt;std::decay_t&lt;Args_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">452</span><span class="doxyLineContent"><span class="doxyHighlight">                           and ...))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">dependent_false_v</a>&lt;Callable_T, Args_T...&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"the body of a suite and its additional arguments "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"must be copyable, since the suite runs later"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlight">                                             <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">                                             std::decay_t&lt;Args_T&gt;&amp;...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">dependent_false_v</a>&lt;Callable_T, Args_T...&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"the body of a suite takes a suite&amp; as its first "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">464</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"parameter, not a test_case&amp;"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">465</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">466</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">467</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">468</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">dependent_false_v</a>&lt;Callable_T, Args_T...&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">469</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"the body of a suite takes a suite&amp; as its first "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">470</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"parameter, followed by the additional arguments"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">471</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">472</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">micro_os_plus::micro_test_plus::detail::dependent_false_v</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#abf92eca75cdfb0993bb529fdbb592be1">micro_os_plus::micro_test_plus::detail::reject_suite_body</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#abdb31c03509a40a041b8f0ea8e12ebd1">micro_os_plus::micro_test_plus::runner::add_suite</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#abf92eca75cdfb0993bb529fdbb592be1">micro_os_plus::micro_test_plus::detail::reject_suite_body</a>.</p>

</div>
</div>

### reject\_test\_body() {#ab1f64ac2ae5a8acc8b198e7f44cf0747}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename Callable_T, typename... Args_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::reject_test_body (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel constexpr">constexpr</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stops the compilation with a message that tells what the body of a test case takes.</p>


<p>Always fails the static assertion that applies, since it is called only when <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body">test_body</a></span> is not satisfied. A body written for a suite is recognised, to say so.</p>


<p>Called by the overloads of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b497f0911a0abe12a341a560ba79e1d">test_case::test()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0cfa76ba0ba0c308d246b2b5d506ab19">suite::test()</a></span> that are selected when the callable is not a valid body, so that the diagnostic names the mistake in the terms of the application, instead of the concepts and the instantiation stack. Never called at run time.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Callable_T</td>
<td class="doxyParamItemDescription"><p>The type of the callable.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Args_T</td>
<td class="doxyParamItemDescription"><p>The types of the additional arguments.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00422">422</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">422</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">reject_test_body</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">423</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">                                        std::decay_t&lt;Args_T&gt;&amp;...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">dependent_false_v</a>&lt;Callable_T, Args_T...&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">428</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"the body of a test case takes a test_case&amp; as its "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">429</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"first parameter, not a suite&amp;"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">430</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">431</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">432</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">433</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">dependent_false_v</a>&lt;Callable_T, Args_T...&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">434</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"the body of a test case takes a test_case&amp; as its "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">435</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"first parameter, followed by the additional "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">436</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"arguments passed to test ()"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">437</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">438</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">micro_os_plus::micro_test_plus::detail::dependent_false_v</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">micro_os_plus::micro_test_plus::detail::reject_test_body</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">micro_os_plus::micro_test_plus::detail::reject_test_body</a>.</p>

</div>
</div>

### test\_each\_value() {#a3178150c77ae33d100e18e157436b04b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Self_T, class Values_T, class Callable_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::detail::test_each_value (Self_T &amp; self, const located_name &amp; name, Values_T &amp;&amp; values, Callable_T &amp; callable)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Adds and runs a test case for each value.</p>


<p>For each value, the name is built in a local string, which lives while the test case runs, since a test case runs within the call to <span class="doxyComputerOutput">test()</span>, and the test case is added with <span class="doxyComputerOutput">test()</span>, with the location of the call to <span class="doxyComputerOutput">test_each()</span>. The callable receives each value as a <span class="doxyComputerOutput">const</span> lvalue, referring to the element itself; neither the values nor the callable are copied. The values of a range are iterated by a range-based <span class="doxyComputerOutput">for</span> statement, and those of a tuple are expanded by <span class="doxyComputerOutput">std::apply()</span>, in order.</p>


<p>The common implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a419000e72526d0d251d7e28f48d656d2">test_case::test_each()</a></span> and <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a61a886b526fef82564a3e4ec1ea0dee4">suite::test_each()</a></span>.</p>


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


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l01029">1029</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">1029</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">test_each_value</a> (Self_T&amp; self, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; name, Values_T&amp;&amp; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1030</span><span class="doxyLineContent"><span class="doxyHighlight">                     Callable_T&amp; callable)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1031</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1032</span><span class="doxyLineContent"><span class="doxyHighlight">      std::size_t position = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1033</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1034</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> run_one</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1035</span><span class="doxyLineContent"><span class="doxyHighlight">          = [&amp;self, &amp;name, &amp;callable, &amp;position] (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1036</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1037</span><span class="doxyLineContent"><span class="doxyHighlight">          ++position;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1038</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1039</span><span class="doxyLineContent"><span class="doxyHighlight">          std::string text{ name.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#aa2ec3a20974c59b2f5a64a50b41db444">name</a> () };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1040</span><span class="doxyLineContent"><span class="doxyHighlight">          text += </span><span class="doxyHighlightStringLiteral">" ("</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1041</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/printable">extension::printable</a>&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1042</span><span class="doxyLineContent"><span class="doxyHighlight">                            std::remove_cvref_t&lt;</span><span class="doxyHighlightKeyword">decltype</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>)&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1043</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1044</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#a63b3cc3a8e725c2921787180f1244824">plain_text::append</a> (text, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1045</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1046</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1047</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1048</span><span class="doxyLineContent"><span class="doxyHighlight">              text += </span><span class="doxyHighlightCharLiteral">'#'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1049</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#a63b3cc3a8e725c2921787180f1244824">plain_text::append</a> (text, position);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1050</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1051</span><span class="doxyLineContent"><span class="doxyHighlight">          text += </span><span class="doxyHighlightCharLiteral">')'</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1052</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1053</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// The test case runs within this call, so the value and the</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1054</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// callable are captured by reference, not copied.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1055</span><span class="doxyLineContent"><span class="doxyHighlight">          self.test (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>{ std::move (text), name.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ade35aacdde746abad6be66a9fcab251b">location</a> () },</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1056</span><span class="doxyLineContent"><span class="doxyHighlight">                     [&amp;callable, &amp;<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; test_self)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1057</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1058</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_member_pointer_v&lt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1059</span><span class="doxyLineContent"><span class="doxyHighlight">                                std::remove_cvref_t&lt;Callable_T&gt;&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1060</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1061</span><span class="doxyLineContent"><span class="doxyHighlight">                  std::invoke (callable, test_self, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1062</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1063</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1064</span><span class="doxyLineContent"><span class="doxyHighlight">                {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1065</span><span class="doxyLineContent"><span class="doxyHighlight">                  callable (test_self, <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1066</span><span class="doxyLineContent"><span class="doxyHighlight">                }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1067</span><span class="doxyLineContent"><span class="doxyHighlight">            });</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a3e789d4fded524d5d5d088618d615026">1068</a></span><span class="doxyLineContent"><span class="doxyHighlight">        };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1069</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1070</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">test_values_range&lt;Values_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1071</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1072</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a> : values)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1073</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1074</span><span class="doxyLineContent"><span class="doxyHighlight">              run_one (<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">value</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1075</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1076</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1077</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1078</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1079</span><span class="doxyLineContent"><span class="doxyHighlight">          std::apply ([&amp;run_one] (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp;... elements)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1080</span><span class="doxyLineContent"><span class="doxyHighlight">            { (run_one (elements), ...); }, values);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1081</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">1082</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/plain-text/#a63b3cc3a8e725c2921787180f1244824">micro_os_plus::micro_test_plus::detail::plain_text::append</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ade35aacdde746abad6be66a9fcab251b">micro_os_plus::micro_test_plus::located_name::location</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#aa2ec3a20974c59b2f5a64a50b41db444">micro_os_plus::micro_test_plus::located_name::name</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">micro_os_plus::micro_test_plus::detail::test_each_value</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#adc0f91f958d943f505dac6f73c2c240d">micro_os_plus::micro_test_plus::suite::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a61a886b526fef82564a3e4ec1ea0dee4">micro_os_plus::micro_test_plus::suite::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a5fdc1f162d725c6e01b0858c5efecfa7">micro_os_plus::micro_test_plus::test_case::test_each</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a419000e72526d0d251d7e28f48d656d2">micro_os_plus::micro_test_plus::test_case::test_each</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">micro_os_plus::micro_test_plus::detail::test_each_value</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Variables

### dependent\_false\_v {#a360bed7e2af05a26d92e5ca4c414c06e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename... Ts&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::dependent_false_v = false</td>
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

<p>A value that is always <span class="doxyComputerOutput">false</span>, but depends on the template arguments.</p>


<p>Used as the condition of the <span class="doxyComputerOutput">static_assert</span> of the functions that reject an argument, so that they fail only when instantiated, and their diagnostic has the message, not the concepts that were not satisfied.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Ts</td>
<td class="doxyParamItemDescription"><p>The template arguments to depend on.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Definition at line <a href="#l01258">1258</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">1258</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">dependent_false_v</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#abf92eca75cdfb0993bb529fdbb592be1">micro_os_plus::micro_test_plus::detail::reject_suite_body</a> and <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">micro_os_plus::micro_test_plus::detail::reject_test_body</a>.</p>

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
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00012"></a>12</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * released under the terms of the Boost Version 1.0 Software License,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00013"></a>13</span><span class="doxyLineContent"><span class="doxyHighlightComment"> * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00014"></a>14</span><span class="doxyLineContent"><span class="doxyHighlightComment"> */</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00015"></a>15</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00016"></a>16</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00017"></a>17</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00039"></a>39</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00040"></a>40</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00041"></a>41</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00042"></a>42</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00043"></a>43</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00044"></a>44</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00045"></a>45</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00046"></a>46</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00047"></a>47</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00048"></a>48</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00049"></a>49</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00050"></a>50</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/project-config.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00051"></a>51</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/project-config.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00052"></a>52</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00053"></a>53</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00054"></a>54</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "micro-os-plus/micro-test-plus-defines.h"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00055"></a>55</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// __has_include("micro-os-plus/micro-test-plus-defines.h")</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00056"></a>56</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00057"></a>57</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00058"></a>58</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/counters-h">counters.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00059"></a>59</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/extension-h">extension.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00060"></a>60</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/stopwatch-h">stopwatch.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00061"></a>61</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reflection-h">reflection.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00062"></a>62</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00063"></a>63</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;cstddef&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00064"></a>64</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;functional&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00065"></a>65</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;initializer_list&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00066"></a>66</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;memory&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00067"></a>67</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00068"></a>68</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;string_view&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00069"></a>69</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;tuple&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00070"></a>70</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;type_traits&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00071"></a>71</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;utility&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00072"></a>72</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00073"></a>73</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00074"></a>74</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00075"></a>75</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00076"></a>76</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00077"></a>77</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00078"></a>78</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Waggregate-return"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00079"></a>79</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wpadded"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00080"></a>80</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00081"></a>81</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00082"></a>82</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wc++98-compat-bind-to-temporary-copy"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00083"></a>83</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wdocumentation"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00084"></a>84</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else </span><span class="doxyHighlightComment">// GCC only</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00085"></a>85</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wsuggest-final-types"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00086"></a>86</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wsuggest-final-methods"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00087"></a>87</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic ignored "-Wredundant-tags"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00088"></a>88</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00089"></a>89</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00090"></a>90</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00091"></a>91</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00092"></a>92</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00093"></a>93</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00094"></a>94</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00095"></a>95</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00096"></a>96</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00097"></a>97</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00098"></a>98</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00099"></a>99</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00100"></a>100</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00101"></a>101</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00102"></a>102</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00114"></a>114</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00115"></a>115</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#afe0adb93e576b2c11ba933ec65245d91">escape_control_characters</a> (std::string&amp; name);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00116"></a>116</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00117"></a>117</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00118"></a>118</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite">top_suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00119"></a>119</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00120"></a>120</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00121"></a>121</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00122"></a>122</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00176"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">176</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00177"></a>177</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00178"></a>178</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00195"></a>195</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Po</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">er_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00196"></a>196</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (std::is_same_v&lt;Pointer_T, const char*&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00197"></a>197</span><span class="doxyLineContent"><span class="doxyHighlight">                or std::is_same_v&lt;Pointer_T, char*&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00198"></a>198</span><span class="doxyLineContent"><span class="doxyHighlight">                or std::is_null_pointer_v&lt;Pointer_T&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00199"></a>199</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a> (Pointer_T <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#aa2ec3a20974c59b2f5a64a50b41db444">name</a>, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ade35aacdde746abad6be66a9fcab251b">location</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00200"></a>200</span><span class="doxyLineContent"><span class="doxyHighlight">                                  = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00201"></a>201</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00218"></a>218</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;std::</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> N&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00219"></a>219</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> (&amp;<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#aa2ec3a20974c59b2f5a64a50b41db444">name</a>)[N],</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00220"></a>220</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ade35aacdde746abad6be66a9fcab251b">location</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00221"></a>221</span><span class="doxyLineContent"><span class="doxyHighlight">                  = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00222"></a>222</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00231"></a>231</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#aa2ec3a20974c59b2f5a64a50b41db444">name</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00232"></a>232</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ade35aacdde746abad6be66a9fcab251b">location</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00233"></a>233</span><span class="doxyLineContent"><span class="doxyHighlight">                  = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00234"></a>234</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00243"></a>243</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a> (std::string&amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#aa2ec3a20974c59b2f5a64a50b41db444">name</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00244"></a>244</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ade35aacdde746abad6be66a9fcab251b">location</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00245"></a>245</span><span class="doxyLineContent"><span class="doxyHighlight">                  = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00246"></a>246</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00256"></a>256</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ab66a15ccc3f4b66fb2f8f897b2cb91ec">located_name</a> (std::string_view <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#aa2ec3a20974c59b2f5a64a50b41db444">name</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00257"></a>257</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ade35aacdde746abad6be66a9fcab251b">location</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00258"></a>258</span><span class="doxyLineContent"><span class="doxyHighlight">                  = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00259"></a>259</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00268"></a>268</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00269"></a>269</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#aa2ec3a20974c59b2f5a64a50b41db444">name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00270"></a>270</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00278"></a>278</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00279"></a>279</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#ade35aacdde746abad6be66a9fcab251b">location</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00280"></a>280</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00281"></a>281</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00289"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#a73d82df6b0bafcf4dfef0f15433185ca">289</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#a73d82df6b0bafcf4dfef0f15433185ca">name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00290"></a>290</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00298"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#a199094a3c03b40d8621279a30a152784">298</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name/#a199094a3c03b40d8621279a30a152784">location_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00299"></a>299</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00300"></a>300</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00301"></a>301</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00302"></a>302</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00303"></a>303</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00304"></a>304</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00305"></a>305</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">check_result;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00306"></a>306</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">reporter;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00307"></a>307</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">reporter_human;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00308"></a>308</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">reporter_tap;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00309"></a>309</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00310"></a>310</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00311"></a>311</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00348"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">348</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00349"></a>349</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00357"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">357</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00358"></a>358</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00366"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aec75a9652b7e98188d506c462aa73e19">366</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aec75a9652b7e98188d506c462aa73e19">check_result</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00367"></a>367</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00375"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ac1362875db31c5b5b875520025597a65">375</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ac1362875db31c5b5b875520025597a65">reporter_human</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00376"></a>376</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00385"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ac6f88fbc9f895d8d7495393d1a9a7d6a">385</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ac6f88fbc9f895d8d7495393d1a9a7d6a">reporter_tap</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00386"></a>386</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00387"></a>387</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00396"></a>396</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a8def9cddbb5bc877918104c785271753">own_index</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00397"></a>397</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00404"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0252f278ae59dddef03282d7aa84a51c">404</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0252f278ae59dddef03282d7aa84a51c">runnable_base</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00405"></a>405</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00413"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6086e33edab5d5b8b837cab432f087c9">413</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6086e33edab5d5b8b837cab432f087c9">runnable_base</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00414"></a>414</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00421"></a>421</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00422"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a41f7fada4e78a1869653f67f9acedb42">422</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a41f7fada4e78a1869653f67f9acedb42">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00423"></a>423</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00424"></a>424</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00432"></a>432</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00433"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a18b82d51daccd8a75f87e043d2660006">433</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a41f7fada4e78a1869653f67f9acedb42">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">runnable_base</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00434"></a>434</span><span class="doxyLineContent"><span class="doxyHighlight">          = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00435"></a>435</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00442"></a>442</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a90b850cc983e007829a3aaf929aa8b4d">~runnable_base</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00443"></a>443</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00444"></a>444</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// ----------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00445"></a>445</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00453"></a>453</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00454"></a>454</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00455"></a>455</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00470"></a>470</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00471"></a>471</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aa83553cf6bf351153328304ebc71e545">totals</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00472"></a>472</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00473"></a>473</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00478"></a>478</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00492"></a>492</span><span class="doxyLineContent"><span class="doxyHighlight">      [[deprecated (</span><span class="doxyHighlightStringLiteral">"internal to the framework (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00493"></a>493</span><span class="doxyLineContent"><span class="doxyHighlight">        nodiscard]] </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00494"></a>494</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a8def9cddbb5bc877918104c785271753">own_index</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00495"></a>495</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00508"></a>508</span><span class="doxyLineContent"><span class="doxyHighlight">      [[deprecated (</span><span class="doxyHighlightStringLiteral">"internal to the framework (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00509"></a>509</span><span class="doxyLineContent"><span class="doxyHighlight">        nodiscard]] </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00510"></a>510</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7ad637d38c035d54c872f72e1b9ac358">current_subtest_index</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00511"></a>511</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00523"></a>523</span><span class="doxyLineContent"><span class="doxyHighlight">      [[deprecated (</span><span class="doxyHighlightStringLiteral">"internal to the framework (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00524"></a>524</span><span class="doxyLineContent"><span class="doxyHighlight">        nodiscard]] </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00525"></a>525</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aaf838b03cddfb039d1295611be8a5e32">children_subtests_count</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00526"></a>526</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00530"></a>530</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00531"></a>531</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00532"></a>532</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00550"></a>550</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">virtual</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00551"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a1bffa5c8f05ffb464857521badd6ecef">551</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a1bffa5c8f05ffb464857521badd6ecef">run</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00552"></a>552</span><span class="doxyLineContent"><span class="doxyHighlight">          = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00553"></a>553</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00567"></a>567</span><span class="doxyLineContent"><span class="doxyHighlight">      [[noreturn]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00568"></a>568</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a5fec64d9b300277d56e02193bb7d0a46">abort</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00569"></a>569</span><span class="doxyLineContent"><span class="doxyHighlight">             = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> ()) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00570"></a>570</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00571"></a>571</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00588"></a>588</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">runner</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00589"></a>589</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00590"></a>590</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00606"></a>606</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter">reporter</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00607"></a>607</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00608"></a>608</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00623"></a>623</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00624"></a>624</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a3fd5730af8bd449cc56e29d5d14509e9">running_test_case</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00625"></a>625</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00642"></a>642</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00643"></a>643</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abd436b75b0dce84f8d4108e97f37a82e">has_running_test_case_of</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; target) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00644"></a>644</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00658"></a>658</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00659"></a>659</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aaec8b378e1d1639a5fa0e6dec20d6a46">is_aborted</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00660"></a>660</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00674"></a>674</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00675"></a>675</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a58c3051635ce2389a8afc2222cd6b30d">is_listing</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00676"></a>676</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00691"></a>691</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>*</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00692"></a>692</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6df38c720d659b6a53dfd2b65c5d25e4">exchange_running_suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>* running) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00693"></a>693</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00720"></a>720</span><span class="doxyLineContent"><span class="doxyHighlight">      [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00721"></a>721</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a5e5df8d6e176fd4aa0ba8ed2d5104780">accepts_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; target, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00722"></a>722</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00738"></a>738</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00739"></a>739</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a1a5da2b1dbdcda50a7e570c5cefbe52b">reject_body_exception</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00740"></a>740</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00753"></a>753</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00754"></a>754</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0d131770fe8aed387ca6da982f1ff60e">next_test_point_number</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00755"></a>755</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00770"></a>770</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00771"></a>771</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a38cf903fb0ba5b76b1eb2350b6385962">after_test_case_create</a> (</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00772"></a>772</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00808"></a>808</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00809"></a>809</span><span class="doxyLineContent"><span class="doxyHighlight">      [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00810"></a>810</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6d375bb7425b231aa3605642289d2f44">create_test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; parent_suite,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00811"></a>811</span><span class="doxyLineContent"><span class="doxyHighlight">                        </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> nesting_depth, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00812"></a>812</span><span class="doxyLineContent"><span class="doxyHighlight">                        Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00813"></a>813</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00814"></a>814</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">protected</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00823"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">823</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aad830bd92e4f6e4239d2bb5b75d5bf50">name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00824"></a>824</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00838"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a87091ad4653e9db854ba9d5a64b30738">838</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/counters">counters</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a87091ad4653e9db854ba9d5a64b30738">totals_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00839"></a>839</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00848"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ab7513249cc0aac30e3edd7008d08d355">848</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ab7513249cc0aac30e3edd7008d08d355">runner_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00849"></a>849</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00859"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">859</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a69687627342981d42471b17f1d83311f">own_index_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00860"></a>860</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00871"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">871</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#abc92cbb8ab8d04e7c75bf18aa7189d98">test_point_number_</a> = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00872"></a>872</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00883"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aff1a81aff41ab5dc80e2fac1c5a78a31">883</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#aff1a81aff41ab5dc80e2fac1c5a78a31">child_test_cases_count_</a> = 0;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00884"></a>884</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00885"></a>885</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00886"></a>886</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00887"></a>887</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00914"></a>914</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Self_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00915"></a>915</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeyword">auto</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00916"></a>916</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a6abb44ef8226b1f80aad8010b5ef1a5c">bind_callable</a> (Callable_T&amp;&amp; callable, Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00917"></a>917</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00918"></a>918</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00919"></a>919</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00942"></a>942</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Self_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00943"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable">943</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a15afa0762b074f3ef56335580bf7119d">bound_callable</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00944"></a>944</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00945"></a>945</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00968"></a>968</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> C, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... A&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00969"></a>969</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight">...(A) &gt; 0)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00970"></a>970</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a15afa0762b074f3ef56335580bf7119d">bound_callable</a> (C&amp;&amp; callable, A&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00971"></a>971</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00983"></a>983</span><span class="doxyLineContent"><span class="doxyHighlight">      [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00984"></a>984</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a65c86f89bf9e216b5e2e3dae5f599a49">operator()</a>(Self_T&amp; self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00985"></a>985</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l00986"></a>986</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01000"></a>1000</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;std::size_t... Is&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01001"></a>1001</span><span class="doxyLineContent"><span class="doxyHighlight">      [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01002"></a>1002</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#aa0583b5d4d54c56f1460c18e88e43aa2">invoke</a> (Self_T&amp; self, std::index_sequence&lt;Is...&gt;);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01003"></a>1003</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01011"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#ae9058f5a50afba3eafc6b86d68957fdb">1011</a></span><span class="doxyLineContent"><span class="doxyHighlight">      Callable_T <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#ae9058f5a50afba3eafc6b86d68957fdb">callable_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01012"></a>1012</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01020"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a674485f271757aa111f6cbf39bfa12f8">1020</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::tuple&lt;Args_T...&gt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/bound-callable/#a674485f271757aa111f6cbf39bfa12f8">arguments_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01021"></a>1021</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01022"></a>1022</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01023"></a>1023</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01024"></a>1024</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01045"></a>1045</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Self_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01046"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">1046</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a3e789d4fded524d5d5d088618d615026">callable_ref</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01047"></a>1047</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01048"></a>1048</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01065"></a>1065</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01066"></a>1066</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (!std::is_same_v&lt;std::remove_cv_t&lt;Callable_T&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01067"></a>1067</span><span class="doxyLineContent"><span class="doxyHighlight">                                  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a3e789d4fded524d5d5d088618d615026">callable_ref&lt;Self_T&gt;</a>&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01068"></a>1068</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">explicit</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a3e789d4fded524d5d5d088618d615026">callable_ref</a> (Callable_T&amp; callable) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01069"></a>1069</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01084"></a>1084</span><span class="doxyLineContent"><span class="doxyHighlight">      [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01085"></a>1085</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a10148eb90e3393d8166e8712468d32e2">operator()</a>(Self_T&amp; self) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01086"></a>1086</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01087"></a>1087</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01102"></a>1102</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01103"></a>1103</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01104"></a>1104</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#affde2e2f927df6b5ada7f5578f8d5c36">invoke_callable</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* callable, Self_T&amp; self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01105"></a>1105</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01112"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a7a5a1b1e001f34f819ac65e63c2d9567">1112</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a7a5a1b1e001f34f819ac65e63c2d9567">callable_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01113"></a>1113</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01121"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a7ca4453fe089a72345a476490212ae59">1121</a></span><span class="doxyLineContent"><span class="doxyHighlight">      void (*<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref/#a7ca4453fe089a72345a476490212ae59">invoke_</a>) (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">* callable, Self_T&amp; self);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01122"></a>1122</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01123"></a>1123</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01124"></a>1124</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01125"></a>1125</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01138"></a>1138</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01139"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">1139</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">test_values_range</a> = std::is_array_v&lt;std::remove_cvref_t&lt;T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01140"></a>1140</span><span class="doxyLineContent"><span class="doxyHighlight">                                or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/container-like">container_like&lt;std::remove_cvref_t&lt;T&gt;</a>&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01141"></a>1141</span><span class="doxyLineContent"><span class="doxyHighlight">                                or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/free-range">free_range&lt;std::remove_cvref_t&lt;T&gt;</a>&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01142"></a>1142</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01154"></a>1154</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01155"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">1155</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">test_values_tuple</a> = (not <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">test_values_range&lt;T&gt;</a>) and </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01156"></a>1156</span><span class="doxyLineContent"><span class="doxyHighlight">      std::tuple_size&lt;std::remove_cvref_t&lt;T&gt;&gt;<a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/value">::value</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01157"></a>1157</span><span class="doxyLineContent"><span class="doxyHighlight">    };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01158"></a>1158</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01175"></a>1175</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01176"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/generic-callable">1176</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/generic-callable">generic_callable</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01177"></a>1177</span><span class="doxyLineContent"><span class="doxyHighlight">        = std::is_class_v&lt;std::decay_t&lt;Callable_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01178"></a>1178</span><span class="doxyLineContent"><span class="doxyHighlight">          &amp;&amp; (!</span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> { &amp;std::decay_t&lt;Callable_T&gt;::operator(); });</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01179"></a>1179</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01196"></a>1196</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01197"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body">1197</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body">test_body</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01198"></a>1198</span><span class="doxyLineContent"><span class="doxyHighlight">        = <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/generic-callable">generic_callable&lt;Callable_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01199"></a>1199</span><span class="doxyLineContent"><span class="doxyHighlight">          || std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01200"></a>1200</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::decay_t&lt;Args_T&gt;&amp;...&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01201"></a>1201</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01215"></a>1215</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01216"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/suite-body">1216</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/suite-body">suite_body</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01217"></a>1217</span><span class="doxyLineContent"><span class="doxyHighlight">        = (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/generic-callable">generic_callable&lt;Callable_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01218"></a>1218</span><span class="doxyLineContent"><span class="doxyHighlight">           || std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01219"></a>1219</span><span class="doxyLineContent"><span class="doxyHighlight">                                  std::decay_t&lt;Args_T&gt;&amp;...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01220"></a>1220</span><span class="doxyLineContent"><span class="doxyHighlight">          &amp;&amp; std::is_copy_constructible_v&lt;std::decay_t&lt;Callable_T&gt;&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01221"></a>1221</span><span class="doxyLineContent"><span class="doxyHighlight">          &amp;&amp; (std::is_copy_constructible_v&lt;std::decay_t&lt;Args_T&gt;&gt; &amp;&amp; ...);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01222"></a>1222</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01237"></a>1237</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01238"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/unsupported-condition">1238</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/unsupported-condition">unsupported_condition</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01239"></a>1239</span><span class="doxyLineContent"><span class="doxyHighlight">#if defined(<a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-config/#ga67c701de5426ac340584ed038494a873">MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01240"></a>1240</span><span class="doxyLineContent"><span class="doxyHighlight">        = (not <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">extension::checkable&lt;T&gt;</a>) and (not <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/legacy-checkable">detail::legacy_checkable&lt;T&gt;</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01241"></a>1241</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01242"></a>1242</span><span class="doxyLineContent"><span class="doxyHighlight">        = not <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">extension::checkable&lt;T&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01243"></a>1243</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01244"></a>1244</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01257"></a>1257</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Ts&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01258"></a><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">1258</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">inline</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a360bed7e2af05a26d92e5ca4c414c06e">dependent_false_v</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01259"></a>1259</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01278"></a>1278</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01279"></a>1279</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01280"></a>1280</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#ab1f64ac2ae5a8acc8b198e7f44cf0747">reject_test_body</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01281"></a>1281</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01298"></a>1298</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01299"></a>1299</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01300"></a>1300</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#abf92eca75cdfb0993bb529fdbb592be1">reject_suite_body</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01301"></a>1301</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01322"></a>1322</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Self_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Values_T, </span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01323"></a>1323</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01324"></a>1324</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a3178150c77ae33d100e18e157436b04b">test_each_value</a> (Self_T&amp; self, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; name, Values_T&amp;&amp; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01325"></a>1325</span><span class="doxyLineContent"><span class="doxyHighlight">                     Callable_T&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01326"></a>1326</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01327"></a>1327</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01328"></a>1328</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01329"></a>1329</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01330"></a>1330</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01331"></a>1331</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01361"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">1361</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">test_case</a> final : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01362"></a>1362</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01373"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a68a030feff1f481126e9a6d170331420">1373</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01374"></a>1374</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01382"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a484008ed66130a2bf334948841099943">1382</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01383"></a>1383</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01384"></a>1384</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01405"></a>1405</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01406"></a>1406</span><span class="doxyLineContent"><span class="doxyHighlight">               <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; parent_suite, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a8def9cddbb5bc877918104c785271753">own_index</a>, </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01407"></a>1407</span><span class="doxyLineContent"><span class="doxyHighlight">               <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">detail::callable_ref&lt;test_case&gt;</a> body);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01408"></a>1408</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01409"></a>1409</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01416"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ab7f67423b68a596e6a31ffc7ba261345">1416</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ab7f67423b68a596e6a31ffc7ba261345">test_case</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">test_case</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01417"></a>1417</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01425"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a13ad0f433d3a8189cb806ddb38c2a56c">1425</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a13ad0f433d3a8189cb806ddb38c2a56c">test_case</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">test_case</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01426"></a>1426</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01433"></a>1433</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">test_case</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01434"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a556bbac39502797d52241f481e021847">1434</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a556bbac39502797d52241f481e021847">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">test_case</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01435"></a>1435</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01436"></a>1436</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01444"></a>1444</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">test_case</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01445"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac2e310ec902a0c3e786d4c415269c23e">1445</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a556bbac39502797d52241f481e021847">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">test_case</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01446"></a>1446</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01447"></a>1447</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01455"></a>1455</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a65cc2035c29d22461b92da2bdf0f3e66">~test_case</a> () </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01456"></a>1456</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01457"></a>1457</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01458"></a>1458</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01486"></a>1486</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01487"></a>1487</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body">detail::test_body</a>&lt;Callable_T, Args_T...&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01488"></a>1488</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01489"></a>1489</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b497f0911a0abe12a341a560ba79e1d">test</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01490"></a>1490</span><span class="doxyLineContent"><span class="doxyHighlight">          Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01491"></a>1491</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01492"></a>1492</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01511"></a>1511</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01512"></a>1512</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body">detail::test_body</a>&lt;Callable_T, Args_T...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01513"></a>1513</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01514"></a>1514</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b497f0911a0abe12a341a560ba79e1d">test</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01515"></a>1515</span><span class="doxyLineContent"><span class="doxyHighlight">          Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01516"></a>1516</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01517"></a>1517</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01559"></a>1559</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Values_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01560"></a>1560</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">detail::test_values_range&lt;Values_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01561"></a>1561</span><span class="doxyLineContent"><span class="doxyHighlight">                or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">detail::test_values_tuple&lt;Values_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01562"></a>1562</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01563"></a>1563</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a419000e72526d0d251d7e28f48d656d2">test_each</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Values_T&amp;&amp; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01564"></a>1564</span><span class="doxyLineContent"><span class="doxyHighlight">               Callable_T&amp;&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01565"></a>1565</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01587"></a>1587</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01588"></a>1588</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01589"></a>1589</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a419000e72526d0d251d7e28f48d656d2">test_each</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, std::initializer_list&lt;T&gt; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01590"></a>1590</span><span class="doxyLineContent"><span class="doxyHighlight">               Callable_T&amp;&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01591"></a>1591</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01592"></a>1592</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01593"></a>1593</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01623"></a>1623</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01624"></a>1624</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">extension::checkable&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01625"></a>1625</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01626"></a>1626</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-expectations/#ga6db7427ada09e476aec67306ca5c0b74">expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01627"></a>1627</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01628"></a>1628</span><span class="doxyLineContent"><span class="doxyHighlight">            = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01629"></a>1629</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp; result = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01630"></a>1630</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01631"></a>1631</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01651"></a>1651</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01652"></a>1652</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/unsupported-condition">detail::unsupported_condition&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01653"></a>1653</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01654"></a>1654</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-expectations/#ga6db7427ada09e476aec67306ca5c0b74">expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01655"></a>1655</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01656"></a>1656</span><span class="doxyLineContent"><span class="doxyHighlight">            = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01657"></a>1657</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp; result = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01658"></a>1658</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01659"></a>1659</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01702"></a>1702</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01703"></a>1703</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> extension::checkable&lt;Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01704"></a>1704</span><span class="doxyLineContent"><span class="doxyHighlight">    detail::check_result&amp;&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01705"></a>1705</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-requirements/#gaad1feafeef2f3cea336be3ebe0b27e14">require</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01706"></a>1706</span><span class="doxyLineContent"><span class="doxyHighlight">             </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> reflection::source_location&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01707"></a>1707</span><span class="doxyLineContent"><span class="doxyHighlight">             = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01708"></a>1708</span><span class="doxyLineContent"><span class="doxyHighlight">             detail::check_result&amp;&amp; result = detail::check_result{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01709"></a>1709</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01710"></a>1710</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01730"></a>1730</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01731"></a>1731</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> detail::unsupported_condition&lt;Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01732"></a>1732</span><span class="doxyLineContent"><span class="doxyHighlight">    detail::check_result&amp;&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01733"></a>1733</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api-requirements/#gaad1feafeef2f3cea336be3ebe0b27e14">require</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01734"></a>1734</span><span class="doxyLineContent"><span class="doxyHighlight">             </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> reflection::source_location&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01735"></a>1735</span><span class="doxyLineContent"><span class="doxyHighlight">             = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01736"></a>1736</span><span class="doxyLineContent"><span class="doxyHighlight">             detail::check_result&amp;&amp; result = detail::check_result{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01737"></a>1737</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01738"></a>1738</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01739"></a>1739</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01744"></a>1744</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01763"></a>1763</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01764"></a>1764</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> detail::legacy_checkable&lt;Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01765"></a>1765</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"the argument is always true; write the condition "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01766"></a>1766</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"(since 6.0.0)"</span><span class="doxyHighlight">)]] detail::check_result&amp;&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01767"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af5d04e3477e209f8989d13dfd36239b4">1767</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af5d04e3477e209f8989d13dfd36239b4">expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01768"></a>1768</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01769"></a>1769</span><span class="doxyLineContent"><span class="doxyHighlight">            = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01770"></a>1770</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp; result = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01771"></a>1771</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01787"></a>1787</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01788"></a>1788</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/legacy-checkable">detail::legacy_checkable&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01789"></a>1789</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"the argument is always true; write the condition "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01790"></a>1790</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightStringLiteral">"(since 6.0.0)"</span><span class="doxyHighlight">)]] <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01791"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a6fb4545d5dc1dbc82c837ce1565f7f26">1791</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a6fb4545d5dc1dbc82c837ce1565f7f26">require</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01792"></a>1792</span><span class="doxyLineContent"><span class="doxyHighlight">             </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01793"></a>1793</span><span class="doxyLineContent"><span class="doxyHighlight">             = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01794"></a>1794</span><span class="doxyLineContent"><span class="doxyHighlight">             <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp; result = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01795"></a>1795</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01823"></a>1823</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">class</span><span class="doxyHighlight"> Expr_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01824"></a>1824</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/checkable">extension::checkable&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01825"></a>1825</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"use require() (since 6.0.0)"</span><span class="doxyHighlight">)]] <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01826"></a>1826</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adeccc20d1919ae7f8fc697997dc9bb98">assume</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01827"></a>1827</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01828"></a>1828</span><span class="doxyLineContent"><span class="doxyHighlight">            = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location/#af2ee3ac5db96f13680291736d58fe327">reflection::source_location::current</a> (),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01829"></a>1829</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp; result = <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>{});</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01830"></a>1830</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01834"></a>1834</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01835"></a>1835</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01836"></a>1836</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01837"></a>1837</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01845"></a>1845</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeywordType">size_t</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01846"></a>1846</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#af2b6792d06fa335f2b617e4d39bbba3c">nesting_depth</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01847"></a>1847</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01848"></a>1848</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01863"></a>1863</span><span class="doxyLineContent"><span class="doxyHighlight">    [[nodiscard]] </span><span class="doxyHighlightKeywordType">bool</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01864"></a>1864</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a82e48e546c5a5034be69412c1641482d">is_misdirected</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01865"></a>1865</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01882"></a>1882</span><span class="doxyLineContent"><span class="doxyHighlight">    detail::check_result&amp;&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01883"></a>1883</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b25dc50ced0df2821d7a984eb142c1a">report_misdirected</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">detail::check_kind</a> kind,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01884"></a>1884</span><span class="doxyLineContent"><span class="doxyHighlight">                        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> reflection::source_location&amp; sl,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01885"></a>1885</span><span class="doxyLineContent"><span class="doxyHighlight">                        detail::check_result&amp;&amp; result);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01886"></a>1886</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01902"></a>1902</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01903"></a>1903</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac40bf24e28cce401256d3e90f0c9e8cd">report_misdirected_test</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> located_name&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01904"></a>1904</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01923"></a>1923</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01924"></a>1924</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a17e2b5c497cbbec3ad8e15b561d6b599">report_rejected_test</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; message,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01925"></a>1925</span><span class="doxyLineContent"><span class="doxyHighlight">                          </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> reflection::source_location&amp; location);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01926"></a>1926</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01945"></a>1945</span><span class="doxyLineContent"><span class="doxyHighlight">    [[gnu::always_inline]] </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01946"></a>1946</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">run</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01947"></a>1947</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01948"></a>1948</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01949"></a>1949</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01964"></a>1964</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01965"></a>1965</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a1980019eed5ac5b1eef65302eb9cc9cd">fail_unexpected_exception</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* what);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01966"></a>1966</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01967"></a>1967</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01968"></a>1968</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01977"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aad4b8f6b15291abb5dc6602784fa7bad">1977</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/callable-ref">detail::callable_ref&lt;test_case&gt;</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#aad4b8f6b15291abb5dc6602784fa7bad">callable_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01978"></a>1978</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01990"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9446f32cf9f22cb3deeaff451b1e7d95">1990</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9446f32cf9f22cb3deeaff451b1e7d95">located_name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01991"></a>1991</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l01999"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a3f1717ee8c04af1181f6dff2966b3d34">1999</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a3f1717ee8c04af1181f6dff2966b3d34">parent_suite_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02000"></a>2000</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02007"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a3da31fa70e1009cfde8a13a7ffaad036">2007</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a3da31fa70e1009cfde8a13a7ffaad036">nesting_depth_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02008"></a>2008</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02009"></a>2009</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02010"></a>2010</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02011"></a>2011</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02050"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">2050</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a> : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base">detail::runnable_base</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02051"></a>2051</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02059"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">2059</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02060"></a>2060</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02067"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a099a369b6d1f67c296baf9d22be40ba2">2067</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-human">detail::reporter_human</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02068"></a>2068</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02075"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a6cd3b3f893312fe43fa2d7b5018646e9">2075</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter-tap">detail::reporter_tap</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02076"></a>2076</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02083"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a79695ebe99eace27c6a3e1eb651a8522">2083</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a79695ebe99eace27c6a3e1eb651a8522">top_suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02084"></a>2084</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02091"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#af153e90c6ef7fad5fe7f059fced9f423">2091</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#af153e90c6ef7fad5fe7f059fced9f423">static_suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02092"></a>2092</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02093"></a>2093</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02114"></a>2114</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02115"></a>2115</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp;&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02116"></a>2116</span><span class="doxyLineContent"><span class="doxyHighlight">           Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02117"></a>2117</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02118"></a>2118</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02125"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a56a0f7e480793aa3a55f49544187d12a">2125</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a56a0f7e480793aa3a55f49544187d12a">suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02126"></a>2126</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02134"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aa8dac776abb9f904d1d148bf07fedbab">2134</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aa8dac776abb9f904d1d148bf07fedbab">suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02135"></a>2135</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02142"></a>2142</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02143"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a744cbf6c937041b6f8a5d6530479c3af">2143</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a744cbf6c937041b6f8a5d6530479c3af">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02144"></a>2144</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02145"></a>2145</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02153"></a>2153</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02154"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aaaa545978a454f1ae63fc06ac5169efe">2154</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a744cbf6c937041b6f8a5d6530479c3af">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02155"></a>2155</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02156"></a>2156</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02165"></a>2165</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">~suite</a> () </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02166"></a>2166</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02167"></a>2167</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// ------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02168"></a>2168</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02186"></a>2186</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02187"></a>2187</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body">detail::test_body</a>&lt;Callable_T, Args_T...&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02188"></a>2188</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02189"></a>2189</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0cfa76ba0ba0c308d246b2b5d506ab19">test</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02190"></a>2190</span><span class="doxyLineContent"><span class="doxyHighlight">          Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02191"></a>2191</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02192"></a>2192</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02211"></a>2211</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02212"></a>2212</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-body">detail::test_body</a>&lt;Callable_T, Args_T...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02213"></a>2213</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02214"></a>2214</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a0cfa76ba0ba0c308d246b2b5d506ab19">test</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02215"></a>2215</span><span class="doxyLineContent"><span class="doxyHighlight">          Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02216"></a>2216</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02217"></a>2217</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02259"></a>2259</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Values_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02260"></a>2260</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-range">detail::test_values_range&lt;Values_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02261"></a>2261</span><span class="doxyLineContent"><span class="doxyHighlight">                or <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/test-values-tuple">detail::test_values_tuple&lt;Values_T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02262"></a>2262</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02263"></a>2263</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a61a886b526fef82564a3e4ec1ea0dee4">test_each</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, Values_T&amp;&amp; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02264"></a>2264</span><span class="doxyLineContent"><span class="doxyHighlight">               Callable_T&amp;&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02265"></a>2265</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02287"></a>2287</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02288"></a>2288</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02289"></a>2289</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a61a886b526fef82564a3e4ec1ea0dee4">test_each</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, std::initializer_list&lt;T&gt; values,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02290"></a>2290</span><span class="doxyLineContent"><span class="doxyHighlight">               Callable_T&amp;&amp; callable);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02291"></a>2291</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02292"></a>2292</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02297"></a>2297</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02313"></a>2313</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"the timings are internal (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02314"></a>2314</span><span class="doxyLineContent"><span class="doxyHighlight">      nodiscard]] </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02315"></a>2315</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a06c121fc0e8e87451a718846a11fc853">timings</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02316"></a>2316</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02331"></a>2331</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"the timings are internal (since 6.0.0)"</span><span class="doxyHighlight">),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02332"></a>2332</span><span class="doxyLineContent"><span class="doxyHighlight">      nodiscard]] <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02333"></a>2333</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a06c121fc0e8e87451a718846a11fc853">timings</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02334"></a>2334</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02338"></a>2338</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02339"></a>2339</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02340"></a>2340</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02353"></a>2353</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02354"></a>2354</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a432deda5a8721472e8775cbc98451722">run</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02355"></a>2355</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02356"></a>2356</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02357"></a>2357</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02373"></a>2373</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02374"></a>2374</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a1d15dd97c94c3dabccb9e5a7444af0ec">fail_unexpected_exception</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* what);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02375"></a>2375</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02376"></a>2376</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02393"></a>2393</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02394"></a>2394</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a532459c0a6362991282548f4f845cb97">link</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02395"></a>2395</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02409"></a>2409</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02410"></a>2410</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a20ca7721bdf59488ed0713378235cfd2">unlink</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02411"></a>2411</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02412"></a>2412</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02421"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aec447d7b5763ffca58738813bad2e805">2421</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::function&lt;void (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>&amp;)&gt; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#aec447d7b5763ffca58738813bad2e805">callable_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02422"></a>2422</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02431"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">2431</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/stopwatch">detail::stopwatch</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a95145ab410f5c0b6e514ac366aff8d84">stopwatch_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02432"></a>2432</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02443"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a6ddd1c0721a1f0ce3c9e92870ef358ff">2443</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a6ddd1c0721a1f0ce3c9e92870ef358ff">located_name_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02444"></a>2444</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02453"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a65d1fed18566774295fcbc7df44c216e">2453</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a65d1fed18566774295fcbc7df44c216e">next_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02454"></a>2454</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02465"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">2465</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a>* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a612f5529e08321a2e44c714d60c2ba1e">first_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02466"></a>2466</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02467"></a>2467</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02468"></a>2468</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02469"></a>2469</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02487"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite">2487</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a> final : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02488"></a>2488</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02496"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a68a030feff1f481126e9a6d170331420">2496</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">friend</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_test_plus::runner</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02497"></a>2497</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02498"></a>2498</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02509"></a>2509</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a79695ebe99eace27c6a3e1eb651a8522">top_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02510"></a>2510</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02511"></a>2511</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02518"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ae653f09197ac9342cbb52efc386e96df">2518</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ae653f09197ac9342cbb52efc386e96df">top_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02519"></a>2519</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02527"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a04740b417d9571048cbee2125275acce">2527</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a04740b417d9571048cbee2125275acce">top_suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02528"></a>2528</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02535"></a>2535</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02536"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a7601ca8102a7b4b3d7e7f8b33a0728a3">2536</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a7601ca8102a7b4b3d7e7f8b33a0728a3">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02537"></a>2537</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02538"></a>2538</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02546"></a>2546</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02547"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a809ba320392c0ced46977d0b7d371543">2547</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#a7601ca8102a7b4b3d7e7f8b33a0728a3">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">top_suite</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02548"></a>2548</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02549"></a>2549</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02558"></a>2558</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/top-suite/#ac10e4f707de47389f43c38d420ce13e9">~top_suite</a> () </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02559"></a>2559</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02560"></a>2560</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02561"></a>2561</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02562"></a>2562</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02563"></a>2563</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02564"></a>2564</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02565"></a>2565</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02566"></a>2566</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02582"></a>2582</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02583"></a><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">2583</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">concept </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">static_suite_body</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02584"></a>2584</span><span class="doxyLineContent"><span class="doxyHighlight">        = (!std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a>&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02585"></a>2585</span><span class="doxyLineContent"><span class="doxyHighlight">                                std::decay_t&lt;Args_T&gt;&amp;...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02586"></a>2586</span><span class="doxyLineContent"><span class="doxyHighlight">          &amp;&amp; std::is_invocable_v&lt;std::decay_t&lt;Callable_T&gt;&amp;, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">static_suite</a>&amp;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02587"></a>2587</span><span class="doxyLineContent"><span class="doxyHighlight">                                 std::decay_t&lt;Args_T&gt;&amp;...&gt;;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02588"></a>2588</span><span class="doxyLineContent"><span class="doxyHighlight">  } </span><span class="doxyHighlightComment">// namespace detail</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02589"></a>2589</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02590"></a>2590</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ==========================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02591"></a>2591</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02634"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite">2634</a></span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a> final : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#ad7c1d86bb59a42c67848ec6d9482c42b">suite</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02635"></a>2635</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02636"></a>2636</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02665"></a>2665</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02666"></a>2666</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">detail::static_suite_body</a>&lt;Callable_T, Args_T...&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02667"></a>2667</span><span class="doxyLineContent"><span class="doxyHighlight">                &amp;&amp; <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/suite-body">detail::suite_body</a>&lt;Callable_T, Args_T...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02668"></a>2668</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02669"></a>2669</span><span class="doxyLineContent"><span class="doxyHighlight">                  Callable_T&amp;&amp; callable, Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02670"></a>2670</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02671"></a>2671</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02688"></a>2688</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02689"></a>2689</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (!<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">detail::static_suite_body</a>&lt;Callable_T, Args_T...&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02690"></a>2690</span><span class="doxyLineContent"><span class="doxyHighlight">                &amp;&amp; !<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/suite-body">detail::suite_body</a>&lt;Callable_T, Args_T...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02691"></a>2691</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02692"></a>2692</span><span class="doxyLineContent"><span class="doxyHighlight">                  Callable_T&amp;&amp; callable, Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02693"></a>2693</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(__DOXYGEN__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02694"></a>2694</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02695"></a>2695</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02700"></a>2700</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02735"></a>2735</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02736"></a>2736</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">requires</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/static-suite-body">detail::static_suite_body</a>&lt;Callable_T, Args_T...&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02737"></a>2737</span><span class="doxyLineContent"><span class="doxyHighlight">    [[deprecated (</span><span class="doxyHighlightStringLiteral">"use a suite&amp; first parameter (since 6.0.0)"</span><span class="doxyHighlight">)]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02738"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a7a9804ad5f348b9b63e0a5f72597f997">2738</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a7a9804ad5f348b9b63e0a5f72597f997">static_suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/located-name">located_name</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a6c652cd5dc8194269c1cc5f0dc1945e0">name</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a68a030feff1f481126e9a6d170331420">runner</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a0224080b4433f538798354eca0f4c8c5">test_runner</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02739"></a>2739</span><span class="doxyLineContent"><span class="doxyHighlight">                  Callable_T&amp;&amp; callable, Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02740"></a>2740</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02744"></a>2744</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02745"></a>2745</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02752"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae6e593e9cb04f52067b131da4a4c3db3">2752</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae6e593e9cb04f52067b131da4a4c3db3">static_suite</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a>&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02753"></a>2753</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02761"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a441e44ba0fdf43efc58992a9e3e8ce74">2761</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a441e44ba0fdf43efc58992a9e3e8ce74">static_suite</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a>&amp;&amp;) = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02762"></a>2762</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02769"></a>2769</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02770"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae050e143c88fb99eddf2060d37ad4340">2770</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae050e143c88fb99eddf2060d37ad4340">operator=</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a>&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02771"></a>2771</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02772"></a>2772</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02780"></a>2780</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a>&amp;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02781"></a><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a9715939a3717861be374ce1a884fd7fa">2781</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#ae050e143c88fb99eddf2060d37ad4340">operator=</a>(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">static_suite</a>&amp;&amp;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02782"></a>2782</span><span class="doxyLineContent"><span class="doxyHighlight">        = </span><span class="doxyHighlightKeyword">delete</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02783"></a>2783</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02792"></a>2792</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#abab764fadfeef6a609abaacadbce515e">~static_suite</a> () </span><span class="doxyHighlightKeyword">override</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02793"></a>2793</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02794"></a>2794</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">private</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02809"></a>2809</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02810"></a>2810</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a7ac8520c7d0761e54e7482ca5d7e26f2">link_or_reject</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">noexcept</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02811"></a>2811</span><span class="doxyLineContent"><span class="doxyHighlight">  };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02812"></a>2812</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02813"></a>2813</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// --------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02814"></a>2814</span><span class="doxyLineContent"><span class="doxyHighlight">} </span><span class="doxyHighlightComment">// namespace micro_os_plus::micro_test_plus</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02815"></a>2815</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02816"></a>2816</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02817"></a>2817</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02818"></a>2818</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02819"></a>2819</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02820"></a>2820</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02821"></a>2821</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02822"></a>2822</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cplusplus)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02823"></a>2823</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02824"></a>2824</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ============================================================================</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02825"></a>2825</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Templates, inlines &amp; constexpr implementations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02826"></a>2826</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02827"></a>2827</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">inlines/test-inlines.h</a>"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02828"></a>2828</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02829"></a>2829</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02830"></a>2830</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02831"></a>2831</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02832"></a>2832</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber"><a id="l02833"></a>2833</span><span class="doxyLineContent"><span class="doxyHighlightComment">// ----------------------------------------------------------------------------</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
