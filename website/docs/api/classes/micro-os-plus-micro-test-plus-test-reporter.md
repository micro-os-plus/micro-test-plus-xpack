---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/test-reporter
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - class
toc_max_heading_level: 3

---

<div class="doxyPage">

# The `test_reporter` Class Reference

<p>Reporter to display test results, including operand values and types for failures. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::test_reporter
</div>

## Included Headers

<div class="doxyIncludesList">
#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
<br/>
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2e4113dbacfc7349545ddf6e5cca5268">test_reporter</a> ()=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Default constructor for the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> class. <a href="#a2e4113dbacfc7349545ddf6e5cca5268">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a092ef277e46b408cd539de029429a1aa">operator&lt;&lt;</a> (bool v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for boolean values. <a href="#a092ef277e46b408cd539de029429a1aa">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acfe54a05505f0081fcd13f31bd222fa5">operator&lt;&lt;</a> (char *s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a mutable character string. <a href="#acfe54a05505f0081fcd13f31bd222fa5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a318db1ab66a5f2f63c39d58a3c8b2656">operator&lt;&lt;</a> (char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a single character. <a href="#a318db1ab66a5f2f63c39d58a3c8b2656">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#affa86db322653867cc9a82f2720d0b49">operator&lt;&lt;</a> (const char *s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a constant character string. <a href="#affa86db322653867cc9a82f2720d0b49">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a8327d747306728c83e673a9993ab933a">operator&lt;&lt;</a> (const detail::and_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display and() expressions. <a href="#a8327d747306728c83e673a9993ab933a">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ae3c6e69e58215c20d2766ae6e454e2e0">operator&lt;&lt;</a> (const detail::eq_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gae9dfca849300a917cb1c231d275baaa3">eq()</a> expressions. <a href="#ae3c6e69e58215c20d2766ae6e454e2e0">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a248e333b17ace83dbfaf3db464520993">operator&lt;&lt;</a> (const detail::ge_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga34e03399670ec0b365b94b7bea788dd8">ge()</a> expressions. <a href="#a248e333b17ace83dbfaf3db464520993">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#abef6ddfab2ac750d9ec1a170873f6c3e">operator&lt;&lt;</a> (const detail::gt_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gae2fb681444d8256f6bf827eea6b7c29e">gt()</a> expressions. <a href="#abef6ddfab2ac750d9ec1a170873f6c3e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a7e08a3a2f3b5ae49ac3b138f93951746">operator&lt;&lt;</a> (const detail::le_&lt; Rhs_T, Lhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga2b5263a5b3965855aa04971bba735a56">le()</a> expressions. <a href="#a7e08a3a2f3b5ae49ac3b138f93951746">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a1f6ce3e6874d63ee7afe21f8301657c1">operator&lt;&lt;</a> (const detail::lt_&lt; Rhs_T, Lhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gac162522dcad1a6ff7c869d52d376b3ed">lt()</a> expressions. <a href="#a1f6ce3e6874d63ee7afe21f8301657c1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a292fdf290a81a3321edde14c31dff1ed">operator&lt;&lt;</a> (const detail::ne_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga59e4cf59954e81bc868e62b1c5c8db1f">ne()</a> expressions. <a href="#a292fdf290a81a3321edde14c31dff1ed">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a7f8caa4fbe97ef26ece7c5a37dc4ea9c">operator&lt;&lt;</a> (const detail::not_&lt; T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display not() expressions. <a href="#a7f8caa4fbe97ef26ece7c5a37dc4ea9c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a15d2d453175a3ab377eb12cae6e81d2e">operator&lt;&lt;</a> (const detail::nothrow_&lt; Expr_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display nothrow expressions. <a href="#a15d2d453175a3ab377eb12cae6e81d2e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Lhs_T, class Rhs_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a8167f599220c789c1044da084a119eb5">operator&lt;&lt;</a> (const detail::or_&lt; Lhs_T, Rhs_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display or() expressions. <a href="#a8167f599220c789c1044da084a119eb5">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T, class Exception_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ac43d666b5a7824b7e91a1306094fdb1e">operator&lt;&lt;</a> (const detail::throws_&lt; Expr_T, Exception_T &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display throws expressions for a specific exception type. <a href="#ac43d666b5a7824b7e91a1306094fdb1e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a46a7012a665e55c00e7a040588f0c83b">operator&lt;&lt;</a> (const detail::throws_&lt; Expr_T, void &gt; &amp;op)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display throws expressions for any exception. <a href="#a46a7012a665e55c00e7a040588f0c83b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#afdfeff359bdc48955dacb5448706b297">operator&lt;&lt;</a> (const T &amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for types with a getter. <a href="#afdfeff359bdc48955dacb5448706b297">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ab6cd245bcdf58b3004430a76bc78abc8">operator&lt;&lt;</a> (const type_traits::genuine_integral_value&lt; T &gt; &amp;v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display genuine integers, without the type suffix. <a href="#ab6cd245bcdf58b3004430a76bc78abc8">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a8d5212b37538ff11de36a1265b6f927b">operator&lt;&lt;</a> (double v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for double values. <a href="#a8d5212b37538ff11de36a1265b6f927b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0cbaa9549a0929515cd1684cda27e209">operator&lt;&lt;</a> (float v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for float values. <a href="#a0cbaa9549a0929515cd1684cda27e209">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a315aa52bed70671e66a7228d11452c93">operator&lt;&lt;</a> (long double v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for long double values. <a href="#a315aa52bed70671e66a7228d11452c93">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa347f64332ee58823aeb25ed204a8c93">operator&lt;&lt;</a> (signed char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for signed char values. <a href="#aa347f64332ee58823aeb25ed204a8c93">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6fbbfdde2f05c76aab0ea8ddc44495d7">operator&lt;&lt;</a> (signed int v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for signed int values. <a href="#a6fbbfdde2f05c76aab0ea8ddc44495d7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a8c29379f197e555fb8cc6e5d7ca66c09">operator&lt;&lt;</a> (signed long long v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for signed long long values. <a href="#a8c29379f197e555fb8cc6e5d7ca66c09">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a30306b9f0fb893ef89a0756a5025d0e2">operator&lt;&lt;</a> (signed long v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for signed long values. <a href="#a30306b9f0fb893ef89a0756a5025d0e2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af88660a913ae75160c1c88ffbb92830c">operator&lt;&lt;</a> (signed short v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for signed short values. <a href="#af88660a913ae75160c1c88ffbb92830c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a299c705a7e4ba728cdf236318222e234">operator&lt;&lt;</a> (std::nullptr_t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for nullptr. <a href="#a299c705a7e4ba728cdf236318222e234">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acade140484e4bdaab40a72bda0b42adb">operator&lt;&lt;</a> (std::string_view sv)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for std::string_view. <a href="#acade140484e4bdaab40a72bda0b42adb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt; ... &gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0db349234264801b1741a1502d83e286">operator&lt;&lt;</a> (T &amp;&amp;t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display containers. Iterates all members. <a href="#a0db349234264801b1741a1502d83e286">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0bdeb24c644813f434c7373b62280700">operator&lt;&lt;</a> (T *v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display any pointer. <a href="#a0bdeb24c644813f434c7373b62280700">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a91be9116b7ca4b8596cabb8690ea2c46">operator&lt;&lt;</a> (test_reporter &amp;(*func)(test_reporter &amp;))</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display the endl. <a href="#a91be9116b7ca4b8596cabb8690ea2c46">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acb9db4f1a9c23eae20e74b55b4244747">operator&lt;&lt;</a> (unsigned char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for unsigned char values. <a href="#acb9db4f1a9c23eae20e74b55b4244747">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a2df8fdfda10c3cdf9b5bdca00f377387">operator&lt;&lt;</a> (unsigned int v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for unsigned int values. <a href="#a2df8fdfda10c3cdf9b5bdca00f377387">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9712e8adb7ab22c433b0acac1e18fd78">operator&lt;&lt;</a> (unsigned long long v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for unsigned long long values. <a href="#a9712e8adb7ab22c433b0acac1e18fd78">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5a300e17b0498a54fa4724bee7a5bb58">operator&lt;&lt;</a> (unsigned long v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for unsigned long values. <a href="#a5a300e17b0498a54fa4724bee7a5bb58">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4ef05fd23acfc0b4bcd5d95bf25b518d">operator&lt;&lt;</a> (unsigned short v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for unsigned short values. <a href="#a4ef05fd23acfc0b4bcd5d95bf25b518d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac6d43b057a1be46a895e11c81a9c7cfb">begin_test_case</a> (const char *name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the beginning of a test case. <a href="#ac6d43b057a1be46a895e11c81a9c7cfb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad6375b4032aa02fd8258f77b7de5efdd">begin_test_suite</a> (const char *name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the beginning of a test suite. <a href="#ad6375b4032aa02fd8258f77b7de5efdd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aeab9d025989e57ed62ad0e701efc59ee">color</a> (const bool cond)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Selects the appropriate colour code based on a condition. <a href="#aeab9d025989e57ed62ad0e701efc59ee">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac0f25008c95f1ef27072df20d7668082">end_test_case</a> (const char *name)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the end of a test case. <a href="#ac0f25008c95f1ef27072df20d7668082">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad01d404c3fe5a44cf7f10bfcd599e0f3">end_test_suite</a> (test_suite_base &amp;suite)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the end of a test suite. <a href="#ad01d404c3fe5a44cf7f10bfcd599e0f3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a105cec33c0e4ed184d8db90df27a48d6">endline</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Inserts a line ending into the output buffer. <a href="#a105cec33c0e4ed184d8db90df27a48d6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#ab89536a4a5a82b658ca8282277c49f4b">fail</a> (Expr_T &amp;expr, bool abort, std::string &amp;message, const reflection::source_location &amp;location)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Report a failed condition. <a href="#ab89536a4a5a82b658ca8282277c49f4b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab48b00f46755dd9a70cb39a42bfad7f6">flush</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flush the current buffered content. <a href="#ab48b00f46755dd9a70cb39a42bfad7f6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa37bb1803ea48be27bd42ace2c61aa13">output</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output the current buffered content. <a href="#aa37bb1803ea48be27bd42ace2c61aa13">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#aa6ff8210496100842cf12b466195dcf7">pass</a> (Expr_T &amp;expr, std::string &amp;message)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Report a passed condition. <a href="#aa6ff8210496100842cf12b466195dcf7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae2b0f0247a64d1d22e9db9b5f47653db">output_fail_prefix_</a> (std::string &amp;message, const reflection::source_location &amp;location)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the prefix for a failing condition. <a href="#ae2b0f0247a64d1d22e9db9b5f47653db">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aaa1839530b6e8560711926613013312b">output_fail_suffix_</a> (bool abort)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the suffix for a failing condition. <a href="#aaa1839530b6e8560711926613013312b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af7b154289a09dddaa80e122100437876">output_pass_prefix_</a> (std::string &amp;message)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the prefix for a passing condition. <a href="#af7b154289a09dddaa80e122100437876">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a8df0d7843bb268c9e91fb90219aded65">output_pass_suffix_</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the suffix for a passing condition. <a href="#a8df0d7843bb268c9e91fb90219aded65">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af313ab4b60fd3a19e3b1a9c2fbccbdb6">add_empty_line</a> { true }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Controls whether to add an empty line between successful test cases. <a href="#af313ab4b60fd3a19e3b1a9c2fbccbdb6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">verbosity_t</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adc647f6da46704ba46dcb41a2ec95820">verbosity</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The verbosity level for test reporting. <a href="#adc647f6da46704ba46dcb41a2ec95820">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/colors">colors</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0b4aa7bfcd35287fd9bb9370aeea2154">colors_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>ANSI colour codes for output formatting. <a href="#a0b4aa7bfcd35287fd9bb9370aeea2154">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a212349d52907ad1f05a89b5b4d49c0c3">is_in_test_case_</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Indicates whether the reporter is currently within a test case. <a href="#a212349d52907ad1f05a89b5b4d49c0c3">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a22084218ef1a7005a96d9919587c09e2">out_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Internal output buffer for accumulating report content. <a href="#a22084218ef1a7005a96d9919587c09e2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Reporter to display test results, including operand values and types for failures.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> class is responsible for formatting and presenting test results within the µTest++ framework. It provides a comprehensive suite of output operators for a wide range of data types, containers, and comparator expressions, enabling detailed and informative reporting of test outcomes.</p>

<p>For failed tests, the reporter prints the actual values of the operands along with their types, supporting precise diagnostics and efficient debugging. The class supports multiple verbosity levels and colour-coded output to distinguish between successful and failed tests, thereby enhancing the clarity and professionalism of test reports.</p>

<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> also offers methods for reporting the commencement and completion of test cases and suites, as well as for handling pass and fail conditions. Additional features include output stream manipulators, support for exception-related expressions, and configurable formatting options.</p>

<p>All members and methods are defined within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>

<p>Definition at line 194 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>

<div class="doxySectionDef">

## Public Constructors

### test_reporter() {#a2e4113dbacfc7349545ddf6e5cca5268}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::test_reporter::test_reporter ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel default">default</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Default constructor for the <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> class.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00200">200</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator<<() {#a092ef277e46b408cd539de029429a1aa}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (bool v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for boolean values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The boolean value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified boolean value to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables clear and direct streaming of boolean results into the reporter, supporting precise and readable formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00260">260</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00309">309</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#acfe54a05505f0081fcd13f31bd222fa5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (char * s)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for a mutable character string.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">s</td>
<td class="doxyParamItemDescription"><p>The string to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the contents of the provided modifiable C-style string to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables efficient streaming of mutable string data into the reporter, supporting clear and flexible formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00251">251</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00294">294</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a318db1ab66a5f2f63c39d58a3c8b2656}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (char c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for a single character.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">c</td>
<td class="doxyParamItemDescription"><p>The character to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the specified character to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables efficient streaming of individual characters into the reporter, supporting precise and flexible formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00233">233</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00264">264</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#affa86db322653867cc9a82f2720d0b49}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const char * s)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for a constant character string.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">s</td>
<td class="doxyParamItemDescription"><p>The string to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the contents of the provided C-style string to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables efficient streaming of string literals and character arrays into the reporter, supporting clear and flexible formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00242">242</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00279">279</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a8327d747306728c83e673a9993ab933a}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/and-">detail::and_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display and() expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The left-hand side type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The right-hand side type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The logical conjunction (AND) expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output logical conjunction (AND) expressions in a clear and structured format.</p>

<p>The left-hand side and right-hand side expressions are enclosed in parentheses and separated by the word "and", with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This presentation assists in quickly identifying the components of logical assertions and facilitates efficient debugging of test failures involving compound conditions.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00538">538</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00306">306</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#ae3c6e69e58215c20d2766ae6e454e2e0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/eq-">detail::eq_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gae9dfca849300a917cb1c231d275baaa3">eq()</a> expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The left-hand side type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The right-hand side type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The equality comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output equality comparison expressions in a clear and expressive format.</p>

<p>The left-hand side and right-hand side values are formatted and separated by the equality operator (<span class="doxyComputerOutput">==</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in equality assertions and facilitates efficient debugging of test failures.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00460">460</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00185">185</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a248e333b17ace83dbfaf3db464520993}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ge-">detail::ge_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga34e03399670ec0b365b94b7bea788dd8">ge()</a> expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The left-hand side type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The right-hand side type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The greater-than-or-equal-to comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output greater-than-or-equal-to comparison expressions in a clear and expressive format.</p>

<p>The left-hand side and right-hand side values are formatted and separated by the greater-than-or-equal-to operator (<span class="doxyComputerOutput">&gt;=</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in greater-than-or-equal-to assertions and facilitates efficient debugging of test failures.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00499">499</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00246">246</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#abef6ddfab2ac750d9ec1a170873f6c3e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/gt-">detail::gt_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gae2fb681444d8256f6bf827eea6b7c29e">gt()</a> expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The left-hand side type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The right-hand side type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The greater-than comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output greater-than comparison expressions in a clear and expressive format.</p>

<p>The left-hand side and right-hand side values are formatted and separated by the greater-than operator (<span class="doxyComputerOutput">&gt;</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in greater-than assertions and facilitates efficient debugging of test failures.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00486">486</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00225">225</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a7e08a3a2f3b5ae49ac3b138f93951746}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/le-">detail::le_</a>&lt; Rhs_T, Lhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga2b5263a5b3965855aa04971bba735a56">le()</a> expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The left-hand side type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The right-hand side type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The less-than-or-equal-to comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output less-than-or-equal-to comparison expressions in a clear and expressive format.</p>

<p>The left-hand side and right-hand side values are formatted and separated by the less-than-or-equal-to operator (<span class="doxyComputerOutput">&lt;=</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in less-than-or-equal-to assertions and facilitates efficient debugging of test failures.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00525">525</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00286">286</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a1f6ce3e6874d63ee7afe21f8301657c1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/lt-">detail::lt_</a>&lt; Rhs_T, Lhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#gac162522dcad1a6ff7c869d52d376b3ed">lt()</a> expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The left-hand side type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The right-hand side type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The less-than comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output less-than comparison expressions in a clear and expressive format.</p>

<p>The left-hand side and right-hand side values are formatted and separated by the less-than operator (<span class="doxyComputerOutput">&lt;</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in less-than assertions and facilitates efficient debugging of test failures.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00512">512</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00265">265</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a292fdf290a81a3321edde14c31dff1ed}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/ne-">detail::ne_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-function-comparators/#ga59e4cf59954e81bc868e62b1c5c8db1f">ne()</a> expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The left-hand side type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The right-hand side type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The inequality comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output inequality comparison expressions in a clear and expressive format.</p>

<p>The left-hand side and right-hand side values are formatted and separated by the inequality operator (<span class="doxyComputerOutput">!=</span>), with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This structured output assists in quickly identifying the values involved in inequality assertions and facilitates efficient debugging of test failures.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00473">473</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00205">205</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a7f8caa4fbe97ef26ece7c5a37dc4ea9c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/not-">detail::not_</a>&lt; T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display not() expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The operand type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The logical negation expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enhances readability and clarity by formatting the output when handling negated expressions. It applies colour styling for improved distinction and appends the negated value accordingly, ensuring that logical negations are clearly represented in test reports and diagnostics.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00563">563</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00342">342</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a15d2d453175a3ab377eb12cae6e81d2e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/nothrow-">detail::nothrow_</a>&lt; Expr_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display nothrow expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>The expression type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The nothrow comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload formats output for expressions that do not throw exceptions. It applies colour styling for clarity and ensures a structured and concise representation of exception safety within test reports.</p>

<p>The output highlights the <span class="doxyComputerOutput">nothrow</span> qualifier, making it immediately apparent when an expression is guaranteed not to throw, thereby improving the readability and professionalism of the test output.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00602">602</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00398">398</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a8167f599220c789c1044da084a119eb5}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Lhs_T, class Rhs_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/or-">detail::or_</a>&lt; Lhs_T, Rhs_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display or() expressions.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Lhs_T</td>
<td class="doxyParamItemDescription"><p>The left-hand side type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Rhs_T</td>
<td class="doxyParamItemDescription"><p>The right-hand side type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The logical disjunction (OR) expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output logical disjunction (OR) expressions in a clear and structured format.</p>

<p>The left-hand side and right-hand side expressions are enclosed in parentheses and separated by the word "or", with appropriate colour highlighting applied for improved readability in test reports and diagnostics. This presentation assists in quickly identifying the components of logical assertions and facilitates efficient debugging of test failures involving compound conditions.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00551">551</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00326">326</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#ac43d666b5a7824b7e91a1306094fdb1e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T, class Exception_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-">detail::throws_</a>&lt; Expr_T, Exception_T &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display throws expressions for a specific exception type.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>The expression type.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">Exception_T</td>
<td class="doxyParamItemDescription"><p>The exception type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The throws comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload provides structured output for expressions that may throw exceptions. It applies colour styling for clarity and includes the exception type name for precise identification.</p>

<p>When invoked, the output highlights the <span class="doxyComputerOutput">throws</span> qualifier along with the specific exception type, making it immediately apparent which exception is expected. This enhances the readability and professionalism of test reports, and assists in the precise identification and debugging of exception-related test cases.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00578">578</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00362">362</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a46a7012a665e55c00e7a040588f0c83b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/throws-">detail::throws_</a>&lt; Expr_T, void &gt; &amp; op)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display throws expressions for any exception.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>The expression type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">op</td>
<td class="doxyParamItemDescription"><p>The throws comparator expression.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload formats output for expressions that may throw exceptions. It applies colour styling for clarity and ensures a structured representation of the exception handling mechanism.</p>

<p>When invoked, the output highlights the <span class="doxyComputerOutput">throws</span> qualifier, making it immediately apparent when an expression is expected to throw, thereby improving the readability and professionalism of the test output.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00590">590</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00381">381</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#afdfeff359bdc48955dacb5448706b297}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const T &amp; t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for types with a getter.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type with a getter method.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">t</td>
<td class="doxyParamItemDescription"><p>The object to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00419">419</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>
</div>
</div>

### operator<<() {#ab6cd245bcdf58b3004430a76bc78abc8}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (const <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/type-traits/genuine-integral-value">type_traits::genuine_integral_value</a>&lt; T &gt; &amp; v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display genuine integers, without the type suffix.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The underlying integral type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The strongly-typed integral value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output strongly-typed integral values in a clear and consistent decimal format.</p>

<p>The value is converted to a string using <span class="doxyComputerOutput">std::to_string</span> after being cast to <span class="doxyComputerOutput">long long</span>, ensuring accurate formatting and compatibility across platforms. The resulting string is appended to the internal output buffer, allowing integral values to be included in test reports and diagnostics.</p>

<p>This approach ensures precise and unambiguous representation of integral values, which is particularly advantageous for verifying test results and facilitating debugging.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00432">432</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00135">135</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a8d5212b37538ff11de36a1265b6f927b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (double v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for double values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The double value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified double-precision floating-point value to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of double values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00374">374</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00513">513</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a0cbaa9549a0929515cd1684cda27e209}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (float v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for float values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The float value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified floating-point value to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>, followed by the character 'f' to indicate a float type. It enables precise and readable streaming of float values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00365">365</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00497">497</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a315aa52bed70671e66a7228d11452c93}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (long double v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for long double values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The long double value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified long double-precision floating-point value to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>, followed by the character 'l' to indicate a long double type. It enables precise and readable streaming of long double values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00383">383</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00529">529</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#aa347f64332ee58823aeb25ed204a8c93}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (signed char c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for signed char values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">c</td>
<td class="doxyParamItemDescription"><p>The signed char value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified signed character to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of character values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00275">275</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00338">338</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a6fbbfdde2f05c76aab0ea8ddc44495d7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (signed int v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for signed int values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The signed int value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified signed integer to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of signed integer values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00311">311</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00402">402</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a8c29379f197e555fb8cc6e5d7ca66c09}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (signed long long v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for signed long long values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The signed long long value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified signed long long integer to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of signed long long values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00347">347</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00465">465</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a30306b9f0fb893ef89a0756a5025d0e2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (signed long v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for signed long values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The signed long value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified signed long integer to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of signed long values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00329">329</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00433">433</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#af88660a913ae75160c1c88ffbb92830c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (signed short v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for signed short values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The signed short value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified signed short integer to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of signed short values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00293">293</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00370">370</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a299c705a7e4ba728cdf236318222e234}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (std::nullptr_t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for nullptr.</p>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string "nullptr" to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables clear and explicit streaming of null pointer values into the reporter, supporting precise and readable formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00267">267</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00323">323</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#acade140484e4bdaab40a72bda0b42adb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (std::string_view sv)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for std::string_view.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">sv</td>
<td class="doxyParamItemDescription"><p>The string view to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the contents of the provided <span class="doxyComputerOutput">std::string_view</span> to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables seamless streaming of string data into the reporter, supporting clear and efficient formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00224">224</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00250">250</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a0db349234264801b1741a1502d83e286}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T, type_traits::requires_t&lt; type_traits::is_container_v&lt; T &gt; and not type_traits::has_npos_v&lt; T &gt; &gt; = 0&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (T &amp;&amp; t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display containers. Iterates all members.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The container type.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">t</td>
<td class="doxyParamItemDescription"><p>The container to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output container types in a structured and readable format.</p>

<p>The contents of the container are enclosed in curly braces and each element is separated by a comma and a space. The operator iterates over the container, formatting each element in sequence, which ensures clarity and consistency in test reports and diagnostics.</p>

<p>This approach provides a clear visual representation of container contents, making it easier to interpret test results and debug issues involving collections of values.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00447">447</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00159">159</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a0bdeb24c644813f434c7373b62280700}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (T * v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display any pointer.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the pointer.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The pointer value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> to output pointer values in a consistent and readable hexadecimal format.</p>

<p>The pointer is formatted as a string using <span class="doxyComputerOutput">snprintf</span> with the <span class="doxyComputerOutput">p</span> format specifier, ensuring portability across platforms. The resulting string is appended to the internal output buffer, allowing pointer values to be included in test reports and diagnostics.</p>

<p>This approach provides clear and unambiguous representation of pointer addresses, which is particularly useful for debugging and verifying pointer-related test cases.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00395">395</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00092">92</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### operator<<() {#a91be9116b7ca4b8596cabb8690ea2c46}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;(*)(<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> &amp;) func)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator to display the endl.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">func</td>
<td class="doxyParamItemDescription"><p>Function pointer to the stream manipulator.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload enables manipulators, such as <span class="doxyComputerOutput">endl</span>, to be used with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> stream in a manner similar to standard C++ streams. When a manipulator function is passed, it is invoked with the current <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> instance, allowing for seamless integration of stream operations and improved readability of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00404">404</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00206">206</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#acb9db4f1a9c23eae20e74b55b4244747}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (unsigned char c)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for unsigned char values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">c</td>
<td class="doxyParamItemDescription"><p>The unsigned char value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified unsigned character to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of unsigned character values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00284">284</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00354">354</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a2df8fdfda10c3cdf9b5bdca00f377387}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (unsigned int v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for unsigned int values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The unsigned int value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified unsigned integer to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of unsigned integer values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00320">320</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00417">417</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a9712e8adb7ab22c433b0acac1e18fd78}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (unsigned long long v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for unsigned long long values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The unsigned long long value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified unsigned long long integer to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of unsigned long long values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00356">356</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00481">481</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a5a300e17b0498a54fa4724bee7a5bb58}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (unsigned long v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for unsigned long values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The unsigned long value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified unsigned long integer to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of unsigned long values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00338">338</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00449">449</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### operator<<() {#a4ef05fd23acfc0b4bcd5d95bf25b518d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_reporter &amp; micro_os_plus::micro_test_plus::test_reporter::operator&lt;&lt; (unsigned short v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output operator for unsigned short values.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">v</td>
<td class="doxyParamItemDescription"><p>The unsigned short value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Reference to the current <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a> instance.</p>
</dd>
</dl>


<p>This operator overload appends the string representation of the specified unsigned short integer to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>. It enables precise and readable streaming of unsigned short values into the reporter, supporting clear formatting of test output across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00302">302</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00386">386</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### begin_test_case() {#ac6d43b057a1be46a895e11c81a9c7cfb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::begin_test_case (const char * name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Mark the beginning of a test case.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name of the test case.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method marks the beginning of a test case, setting the internal state to indicate that test output is now within a test case context. If there is pending output and the verbosity level is set to verbose, it ensures that output is properly separated and displayed, adding an empty line if necessary. The output buffer is cleared and the stream is flushed to guarantee that all previous output is visible before the new test case begins. This approach enhances the clarity and organisation of test results across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00658">658</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00548">548</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### begin_test_suite() {#ad6375b4032aa02fd8258f77b7de5efdd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::begin_test_suite (const char * name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Mark the beginning of a test suite.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name of the test suite.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method marks the beginning of a test suite, ensuring that output is properly separated and clearly presented. If there is pending output, the stream is flushed and an empty line is added for clarity. For silent or quiet verbosity levels, output is suppressed. Otherwise, a message indicating the start of the test suite is displayed. This approach enhances the organisation and readability of test results across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00678">678</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00657">657</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### color() {#aeab9d025989e57ed62ad0e701efc59ee}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::test_reporter::color (const bool cond)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Selects the appropriate colour code based on a condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">cond</td>
<td class="doxyParamItemDescription"><p>Boolean value indicating pass (true) or fail (false).</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>The corresponding ANSI colour code as a string.</p>
</dd>
</dl>


<p>Returns the ANSI colour code for pass or fail, depending on the boolean condition provided.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00213">213</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>
</div>
</div>

### end_test_case() {#ac0f25008c95f1ef27072df20d7668082}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::end_test_case (const char * name)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Mark the end of a test case.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">name</td>
<td class="doxyParamItemDescription"><p>The name of the test case.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method marks the end of a test case, summarising its outcome and outputting the results with appropriate formatting and colour coding. If any checks have failed, a failure message is displayed, including the number of successful and failed checks. For passing test cases, a success message is shown with the total number of checks. The output is adjusted according to the verbosity level, and additional spacing is managed for clarity. The output buffer is cleared and the stream is flushed to ensure all results are immediately visible, supporting clear and organised reporting across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00668">668</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00580">580</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### end_test_suite() {#ad01d404c3fe5a44cf7f10bfcd599e0f3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::end_test_suite (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite-base">test_suite_base</a> &amp; suite)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Mark the end of a test suite.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">suite</td>
<td class="doxyParamItemDescription"><p>Reference to the test suite base.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method marks the end of a test suite, summarising the overall results and presenting them with appropriate formatting and colour coding. If the suite contains test cases and the verbosity is not set to quiet, an empty line is added for clarity. For suites with no failed checks and at least one successful check, a success message is displayed, including the number of checks and test cases. Otherwise, a failure message is shown, detailing the number of successful and failed checks, as well as the total number of test cases. The output is immediately flushed to ensure prompt and organised reporting across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00688">688</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00689">689</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### endline() {#a105cec33c0e4ed184d8db90df27a48d6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::endline (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Inserts a line ending into the output buffer.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method appends a newline character to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> and immediately flushes the stream. This ensures that each line of test output is clearly separated and promptly displayed, enhancing the readability and organisation of test results across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00615">615</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00222">222</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### fail() {#ab89536a4a5a82b658ca8282277c49f4b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::fail (Expr_T &amp; expr, bool abort, std::string &amp; message, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Report a failed condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>The expression type.</p></td>
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
<td class="doxyParamItemDescription"><p>The evaluated expression.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">abort</td>
<td class="doxyParamItemDescription"><p>Whether to abort execution after failure.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The message to display.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location of the failure.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This function reports a test failure and formats the output in a clear and consistent manner. It provides contextual information, including the precise source location, and appends the evaluated expression when applicable. The failure handling process ensures uniformity in the presentation of unsuccessful test cases, aiding in the rapid identification and diagnosis of issues within test reports.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00647">647</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00443">443</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

### flush() {#ab48b00f46755dd9a70cb39a42bfad7f6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::flush (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Flush the current buffered content.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method flushes the output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> by synchronising it with the standard output stream. This guarantees that all pending test output is immediately written and visible, ensuring prompt and reliable reporting of test results across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00699">699</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00236">236</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### output() {#aa37bb1803ea48be27bd42ace2c61aa13}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::output (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Output the current buffered content.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method writes the contents of the internal output buffer to the standard output stream without appending a newline character. After outputting the buffer, it is cleared to prepare for subsequent output. This approach ensures that test results are presented promptly and efficiently, supporting clear and organised reporting across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00710">710</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00735">735</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### pass() {#aa6ff8210496100842cf12b466195dcf7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::pass (Expr_T &amp; expr, std::string &amp; message)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Report a passed condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>The expression type.</p></td>
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
<td class="doxyParamItemDescription"><p>The evaluated expression.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The message to display.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This operator overload formats output for expressions that do not throw exceptions. It applies colour styling for clarity and ensures a structured representation of exception safety.</p>

<p>When invoked, the function outputs a pass prefix, followed by either the provided message or, if the message is empty, the evaluated expression itself. It then appends a pass suffix to complete the output. This approach guarantees that successful test outcomes are presented in a clear and consistent manner, enhancing the readability and professionalism of test reports.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00631">631</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h/#l00419">419</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Functions

### output_fail_prefix_() {#ae2b0f0247a64d1d22e9db9b5f47653db}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::output_fail_prefix_ (std::string &amp; message, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Outputs the prefix for a failing condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The message to display.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location of the failure.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method outputs the prefix for a failing test result, applying the appropriate colour formatting and symbols to clearly indicate failure. If the output occurs within a test case, additional indentation is applied for readability. The prefix includes a cross symbol (<span class="doxyComputerOutput">✗</span>), an optional message, and the label "FAILED". The source location is appended in parentheses, showing the file or folder name and line number where the failure occurred. Colour formatting is reset after the prefix to maintain consistent output style across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00757">757</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00144">144</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### output_fail_suffix_() {#aaa1839530b6e8560711926613013312b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::output_fail_suffix_ (bool abort)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Outputs the suffix for a failing condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">abort</td>
<td class="doxyParamItemDescription"><p>Whether to abort execution after failure.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method outputs the suffix for a failing test result by closing the location information, appending an "aborted..." message if the test was aborted, and then adding a newline to the test output. The output stream is flushed to ensure immediate visibility. This approach guarantees that failure results are clearly separated, promptly reported, and easily distinguishable across all test cases and folders.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00768">768</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00184">184</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### output_pass_prefix_() {#af7b154289a09dddaa80e122100437876}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::output_pass_prefix_ (std::string &amp; message)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Outputs the prefix for a passing condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The message to display.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>This method outputs the prefix for a passing test result, applying the appropriate colour formatting and symbols to clearly indicate success. If the output occurs within a test case, additional indentation is applied for readability. The prefix includes a tick symbol (<span class="doxyComputerOutput">✓</span>) and, if provided, an associated message. Colour formatting is reset after the prefix to maintain consistent output style across all test cases and folders.</p>

<p>The prefix/suffix methods help shorten the code generated by the template methods.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00735">735</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00094">94</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

### output_pass_suffix_() {#a8df0d7843bb268c9e91fb90219aded65}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::test_reporter::output_pass_suffix_ (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Outputs the suffix for a passing condition.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>Nothing.</p>
</dd>
</dl>


<p>The <span class="doxyComputerOutput">endl</span> function acts as a stream manipulator for the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span>, inserting a line ending into the output buffer and flushing the current content if necessary. This ensures that test report output is clearly separated and formatted, improving readability and professionalism in the presentation of test results.</p>

<p>Using <span class="doxyComputerOutput">endl</span> in conjunction with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-reporter">test_reporter</a></span> output operators provides a familiar and convenient mechanism for managing line breaks, similar to standard C++ stream manipulators.</p>

<p>The prefix/suffix methods help shorten the code generated by the template methods.</p>

<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00746">746</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp/#l00125">125</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Attributes

### add_empty_line {#af313ab4b60fd3a19e3b1a9c2fbccbdb6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::test_reporter::add_empty_line { true }</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Controls whether to add an empty line between successful test cases.</p>


<p>Used to nicely format the output.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00719">719</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>
</div>
</div>

### verbosity {#adc647f6da46704ba46dcb41a2ec95820}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">verbosity_t micro_os_plus::micro_test_plus::test_reporter::verbosity {}</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>The verbosity level for test reporting.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00724">724</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>
</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### colors_ {#a0b4aa7bfcd35287fd9bb9370aeea2154}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">colors micro_os_plus::micro_test_plus::test_reporter::colors_ {}</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>ANSI colour codes for output formatting.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00773">773</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>
</div>
</div>

### is_in_test_case_ {#a212349d52907ad1f05a89b5b4d49c0c3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::test_reporter::is_in_test_case_ = false</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Indicates whether the reporter is currently within a test case.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00783">783</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>
</div>
</div>

### out_ {#a22084218ef1a7005a96d9919587c09e2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::test_reporter::out_ {}</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel protected">protected</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Internal output buffer for accumulating report content.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h/#l00778">778</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a>.</p>
</div>
</div>

</div>

<hr/>

<p>The documentation for this class was generated from the following files:</p>

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-reporter-inlines-h">test-reporter-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-reporter-h">test-reporter.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/test-reporter-cpp">test-reporter.cpp</a></li>
</ul>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
