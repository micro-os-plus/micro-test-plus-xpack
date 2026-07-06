---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/reporter
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `reporter` Class

<p>Reporter to display test results, including operand values and types for failures. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::reporter { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Derived Classes

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human">reporter_human</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Human (standard output) implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap">reporter_tap</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>TAP (Test Anything Protocol) implementation of <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> (std::unique_ptr&lt; std::vector&lt; std::string_view &gt; &gt; argvs)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructor for the reporter class. <a href="#a0643dcab9f46bc3090939c2a17f829e4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Destructor Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1ab2bf741196d093aada2d4f3876176b">~reporter</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Virtual destructor for the reporter class. <a href="#a1ab2bf741196d093aada2d4f3876176b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0a288fd4578c4879872ecdfc3349bf2d">operator&lt;&lt;</a> (bool v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for boolean values. <a href="#a0a288fd4578c4879872ecdfc3349bf2d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5bc1b012e5817563a4d699b2145ec077">operator&lt;&lt;</a> (char c)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a single character. <a href="#a5bc1b012e5817563a4d699b2145ec077">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#afb205af933ef6b71f23a6943ad6bd628">operator&lt;&lt;</a> (const char *s)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for a constant character string. <a href="#afb205af933ef6b71f23a6943ad6bd628">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a28826ad63a1c66a694c578049922d700">operator&lt;&lt;</a> (reporter &amp;(*func)(reporter &amp;))</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display the endl. <a href="#a28826ad63a1c66a694c578049922d700">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0699f03871f8c5f906a07bf32505cbd7">operator&lt;&lt;</a> (std::nullptr_t)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for nullptr. <a href="#a0699f03871f8c5f906a07bf32505cbd7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad7a2cc6446e65cf9034f85c93efb3945">operator&lt;&lt;</a> (std::string_view sv)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for std::string_view. <a href="#ad7a2cc6446e65cf9034f85c93efb3945">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;typename T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a0acf1be4a7b9738dd2d3b9748e32d872">operator&lt;&lt;</a> (T *v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator to display any pointer. <a href="#a0acf1be4a7b9738dd2d3b9748e32d872">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top"><a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a38ce845af263922f0e76a7e93fc0773d">operator&lt;&lt;</a> (T v)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output operator for arithmetic types, with type suffixes. <a href="#a38ce845af263922f0e76a7e93fc0773d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad4a31761666167469ad39585774b306e">begin_session</a> (runner &amp;runner)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the beginning of a test session. <a href="#ad4a31761666167469ad39585774b306e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a36390a428ba987aa91229d933a15ef27">begin_subtest</a> (subtest &amp;subtest)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the beginning of a subtest. <a href="#a36390a428ba987aa91229d933a15ef27">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a89624dfaadce9810f0f5ae1577ca1080">begin_suite</a> (suite &amp;suite)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the beginning of a test suite. <a href="#a89624dfaadce9810f0f5ae1577ca1080">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af93c2061b90f329e1d87219bdb7c0aa4">end_session</a> (runner &amp;runner)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the end of a test session. <a href="#af93c2061b90f329e1d87219bdb7c0aa4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aeaa7f67b201b405463456a6363191b50">end_subtest</a> (subtest &amp;subtest)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the end of a subtest. <a href="#aeaa7f67b201b405463456a6363191b50">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa70c60884405e172bce6c8b8bab0e636">end_suite</a> (suite &amp;suite)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Mark the end of a test suite. <a href="#aa70c60884405e172bce6c8b8bab0e636">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aee6d8d387798abd0d94052b1cf8987c4">endline</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Inserts a line ending into the output buffer. <a href="#aee6d8d387798abd0d94052b1cf8987c4">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">detail::expression_formatter</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ad2169093aee09bc28ae7f70467569a23">expression</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Provides access to the expression formatter for this reporter. <a href="#ad2169093aee09bc28ae7f70467569a23">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a0107c95e02de7196e660969b0e684173">fail</a> (bool abort, std::string &amp;message, const std::string &amp;expression, bool has_expression, const reflection::source_location &amp;location, subtest &amp;subtest)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Report a failed condition. <a href="#a0107c95e02de7196e660969b0e684173">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae7f404f29f265c5db6038f1e03f854b2">flush</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Flush the current buffered content. <a href="#ae7f404f29f265c5db6038f1e03f854b2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a> (void)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the comment-prefix string used by this reporter format. <a href="#a9cafc8992d508b5ffa0b6a64226202bd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1ac300083569b6304a7e120bb78ac337">pass</a> (std::string &amp;message, const std::string &amp;expression, subtest &amp;subtest)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Report a passed condition. <a href="#a1ac300083569b6304a7e120bb78ac337">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">micro_test_plus::verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a> () const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Returns the current verbosity level. <a href="#a24da76a8973a5aebca9ef7604740180c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a26d99bc552ad4ed31253028647e939b1">write_buffer_to_stdout</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output the current buffered content. <a href="#a26d99bc552ad4ed31253028647e939b1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">auto</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ab6b39c68c08e7ccfb29a693bc86d391c">colour_</a> (const bool cond) const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Selects the appropriate colour code based on a condition. <a href="#ab6b39c68c08e7ccfb29a693bc86d391c">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4192b8554e00783a61e5bebe6d9545cc">output_fail_prefix_</a> (std::string &amp;message, const bool has_expression, const reflection::source_location &amp;location, subtest &amp;subtest)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the prefix for a failing condition. <a href="#a4192b8554e00783a61e5bebe6d9545cc">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af103dba717208ba08d44285066a7b326">output_fail_suffix_</a> (const reflection::source_location &amp;location, bool abort, subtest &amp;subtest)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the suffix for a failing condition. <a href="#af103dba717208ba08d44285066a7b326">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aa78041c4993a5a84f0eba4c278071c9f">output_pass_prefix_</a> (std::string &amp;message, subtest &amp;subtest)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the prefix for a passing condition. <a href="#aa78041c4993a5a84f0eba4c278071c9f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a18e488b545a2dfa190f9f003b4f7ef57">output_pass_suffix_</a> (subtest &amp;subtest)=0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Outputs the suffix for a passing condition. <a href="#a18e488b545a2dfa190f9f003b4f7ef57">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae656aff0d07d7cc634f1a0b2046137e9">write_buffer_to_file_</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a7ee71ebee4a54fb4b05c1f476cc78263">write_info_</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends informational (non-result) text to the output buffer. <a href="#a7ee71ebee4a54fb4b05c1f476cc78263">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Protected Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a3961bc77e50ecbade82b29dd5983ddec">add_empty_line_</a> { true }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Controls whether to add an empty line between successful test cases. <a href="#a3961bc77e50ecbade82b29dd5983ddec">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::unique_ptr&lt; std::vector&lt; std::string_view &gt; &gt;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Owns the command-line arguments passed to the test runner. <a href="#a123948993e8c24962071a32d8274c4f6">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Output accumulation buffer. <a href="#a6eed4eaebea91b3377b89a118eb1c323">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/colours">detail::colours</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adb47f38a4be48757fb7f8658132998fe">colours_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>ANSI colour codes for output formatting. <a href="#adb47f38a4be48757fb7f8658132998fe">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">detail::expression_formatter</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5177970e7d8847d1c7f1ae79de88d1a1">expression_</a> { <a href="#adb47f38a4be48757fb7f8658132998fe">colours_</a> }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Expression formatter for pass and fail reporting. <a href="#a5177970e7d8847d1c7f1ae79de88d1a1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">FILE *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> { nullptr }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Optional output file for redirecting test report output. <a href="#a1d95688325caf323a4d77272dcf50b86">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const char *</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#abb92804e6eaee977fdc1e48f29c632f2">output_file_path_</a> { nullptr }</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Optional file path for redirecting test report output. <a href="#abb92804e6eaee977fdc1e48f29c632f2">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">enum <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914b">verbosity</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The verbosity level for test reporting. <a href="#aea922774c24ce8337d734fa457896595">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Reporter to display test results, including operand values and types for failures.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> class is responsible for formatting and presenting test results within the µTest++ framework. It provides a comprehensive suite of output operators for a wide range of data types, containers, and comparator expressions, enabling detailed and informative reporting of test outcomes.</p>


<p>For failed tests, the reporter prints the actual values of the operands along with their types, supporting precise diagnostics and efficient debugging. The class supports multiple verbosity levels and colour-coded output to distinguish between successful and failed tests, thereby enhancing the clarity and professionalism of test reports.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> also offers methods for reporting the commencement and completion of test cases and suites, as well as for handling pass and fail conditions. Additional features include output stream manipulators, support for exception-related expressions, and configurable formatting options.</p>


<p>All members and methods are defined within the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a></span> namespace, ensuring clear separation from user code and minimising the risk of naming conflicts.</p>


<p>Definition at line 185 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### reporter() {#a0643dcab9f46bc3090939c2a17f829e4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::reporter::reporter (std::unique_ptr&lt; std::vector&lt; std::string_view &gt; &gt; argvs)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructor for the reporter class.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">argvs</td>
<td class="doxyParamItemDescription"><p>Owning pointer to the command-line arguments vector; the reporter takes ownership via move.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Moves the supplied argument vector into <span class="doxyComputerOutput"><a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a></span> and scans it for the <span class="doxyComputerOutput">--verbose</span>, <span class="doxyComputerOutput">--quiet</span>, <span class="doxyComputerOutput">--silent</span>, and <span class="doxyComputerOutput">--output-file=</span> options, adjusting <span class="doxyComputerOutput"><a href="#aea922774c24ce8337d734fa457896595">verbosity_</a></span> and optionally opening the output file. If the output file path is specified but the file cannot be opened, the process exits with a diagnostic error message. The internal string buffer is pre-allocated to reduce dynamic allocation overhead.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00194">194</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00087">87</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0643dcab9f46bc3090939c2a17f829e4">87</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter::reporter</a> (std::unique_ptr&lt;std::vector&lt;std::string_view&gt;&gt; argvs)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">92</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">    std::string_view output_file_sv{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">96</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a> = std::move (argvs);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">97</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">98</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> std::string_view output_file_prefix{ </span><span class="doxyHighlightStringLiteral">"--output-file="</span><span class="doxyHighlight"> };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">99</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">100</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">101</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; args = *<a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">102</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 0; i &lt; args.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">103</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">104</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (args[i] == </span><span class="doxyHighlightStringLiteral">"--verbose"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">105</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">106</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (args[i] == </span><span class="doxyHighlightStringLiteral">"--quiet"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">verbosity::quiet</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (args[i] == </span><span class="doxyHighlightStringLiteral">"--silent"</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">                <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">verbosity::silent</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (args[i].starts_with (output_file_prefix))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlight">                output_file_sv = args[i].substr (output_file_prefix.size ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">            </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (args[i]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">                     == output_file_prefix.substr (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">                         0, output_file_prefix.size () - 1))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">              {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (i + 1 &lt; args.size ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlight">                  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">                    output_file_sv = args[++i];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">                  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">                </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">                  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">                    fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: --output-file option requires a "</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">                                     </span><span class="doxyHighlightStringLiteral">"file path argument\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">                    exit (1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">                  }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">              }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!output_file_sv.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// .data() is safe: all string_views are views into argv[]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// entries, which are null-terminated C strings.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> = fopen (output_file_sv.data (), </span><span class="doxyHighlightStringLiteral">"w"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">            fprintf (stderr, </span><span class="doxyHighlightStringLiteral">"error: Failed to open output file '%.*s'\n"</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">                     </span><span class="doxyHighlightKeyword">static_cast&lt;</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (output_file_sv.size ()),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">                     output_file_sv.data ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">            exit (1);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// The original string is zero terminated, so we can safely use .data()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#abb92804e6eaee977fdc1e48f29c632f2">output_file_path_</a> = output_file_sv.data ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pre-allocate buffer to reduce dynamic allocations.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.reserve (128);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a>, <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>, <a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>, <a href="#abb92804e6eaee977fdc1e48f29c632f2">output_file_path_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba556966c7830465dc4623d62e32cec31d">micro_os_plus::micro_test_plus::quiet</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba73be252ca82217b1458a25e6b4e99f15">micro_os_plus::micro_test_plus::silent</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a> and <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a391d670afb552fe8fc03011d37a517fd">micro_os_plus::micro_test_plus::reporter_human::reporter_human</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9e29142142a2a667e76e3670ba065b37">micro_os_plus::micro_test_plus::reporter_tap::reporter_tap</a>, <a href="#a0a288fd4578c4879872ecdfc3349bf2d">operator&lt;&lt;</a>, <a href="#a5bc1b012e5817563a4d699b2145ec077">operator&lt;&lt;</a>, <a href="#afb205af933ef6b71f23a6943ad6bd628">operator&lt;&lt;</a>, <a href="#a28826ad63a1c66a694c578049922d700">operator&lt;&lt;</a>, <a href="#a0699f03871f8c5f906a07bf32505cbd7">operator&lt;&lt;</a>, <a href="#ad7a2cc6446e65cf9034f85c93efb3945">operator&lt;&lt;</a>, <a href="#a0acf1be4a7b9738dd2d3b9748e32d872">operator&lt;&lt;</a>, <a href="#a38ce845af263922f0e76a7e93fc0773d">operator&lt;&lt;</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ad7a2cc6446e65cf9034f85c93efb3945">micro_os_plus::micro_test_plus::reporter_human::operator&lt;&lt;</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~reporter() {#a1ab2bf741196d093aada2d4f3876176b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::reporter::~reporter ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel virtual">virtual</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Virtual destructor for the reporter class.</p>


<p>If an output file was opened, it is flushed and closed, and a confirmation message naming the output file is written to <span class="doxyComputerOutput">stdout</span>. If tracing is enabled, the function signature is output for diagnostic purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00199">199</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00175">175</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1ab2bf741196d093aada2d4f3876176b">175</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1ab2bf741196d093aada2d4f3876176b">reporter::~reporter</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">176</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">177</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">178</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">179</span><span class="doxyLineContent"><span class="doxyHighlight">    trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">180</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">181</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">182</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">183</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">184</span><span class="doxyLineContent"><span class="doxyHighlight">        fflush (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlight">        fclose (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">        printf (</span><span class="doxyHighlightStringLiteral">"Test output written to '%s'.\n"</span><span class="doxyHighlight">, <a href="#abb92804e6eaee977fdc1e48f29c632f2">output_file_path_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#abb92804e6eaee977fdc1e48f29c632f2">output_file_path_</a> = </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> and <a href="#abb92804e6eaee977fdc1e48f29c632f2">output_file_path_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator&lt;&lt;() {#a0a288fd4578c4879872ecdfc3349bf2d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::reporter::operator&lt;&lt; (bool v)</td>
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
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00234">234</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a5bc1b012e5817563a4d699b2145ec077}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::reporter::operator&lt;&lt; (char c)</td>
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
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This operator overload appends the specified character to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span>. It enables efficient streaming of individual characters into the reporter, supporting precise and flexible formatting of test output across all test cases and folders.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00216">216</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00424">424</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">424</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad7a2cc6446e65cf9034f85c93efb3945">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> c)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">425</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">426</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.append (1, c);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">427</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">428</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> and <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#afb205af933ef6b71f23a6943ad6bd628}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::reporter::operator&lt;&lt; (const char * s)</td>
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
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This operator overload appends the contents of the provided C-style string to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span>. It enables efficient streaming of string literals and character arrays into the reporter, supporting clear and flexible formatting of test output across all test cases and folders.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00225">225</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00439">439</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">439</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad7a2cc6446e65cf9034f85c93efb3945">reporter::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* s)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">440</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">441</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.append (s);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">442</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">443</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> and <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a28826ad63a1c66a694c578049922d700}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::reporter::operator&lt;&lt; (<a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;(*)(<a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> &amp;) func)</td>
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
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This operator overload enables manipulators, such as <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#accd8ecc7473b09af578daa31bb8780eb">endl</a></span>, to be used with the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> stream in a manner similar to standard C++ streams. When a manipulator function is passed, it is invoked with the current <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> instance, allowing for seamless integration of stream operations and improved readability of test output across all test cases and folders.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00274">274</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00394">394</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">394</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad7a2cc6446e65cf9034f85c93efb3945">reporter::operator&lt;&lt;</a>(<a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a>&amp; (*func) (<a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a>&amp;))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">395</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">396</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Call the endl function.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">397</span><span class="doxyLineContent"><span class="doxyHighlight">    (*func) (*this);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">398</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">399</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a0699f03871f8c5f906a07bf32505cbd7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::reporter::operator&lt;&lt; (std::nullptr_t)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output operator for nullptr.</p>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00241">241</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>References <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> and <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#ad7a2cc6446e65cf9034f85c93efb3945}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::reporter::operator&lt;&lt; (std::string_view sv)</td>
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
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This operator overload appends the contents of the provided <span class="doxyComputerOutput">std::string_view</span> to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span>. It enables seamless streaming of string data into the reporter, supporting clear and efficient formatting of test output across all test cases and folders.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00207">207</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00410">410</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">410</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad7a2cc6446e65cf9034f85c93efb3945">reporter::operator&lt;&lt;</a>(std::string_view sv)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">411</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">412</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.append (sv);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">413</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">414</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> and <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a0acf1be4a7b9738dd2d3b9748e32d872}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;typename T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::reporter::operator&lt;&lt; (T * v)</td>
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
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This operator overload enables the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output pointer values in a consistent and readable format.</p>


<p>Null pointers are always rendered as the string <span class="doxyComputerOutput">"nullptr"</span>, regardless of the platform, avoiding platform-specific behaviour such as <span class="doxyComputerOutput">"(nil)"</span> on Linux/glibc or <span class="doxyComputerOutput">"0x0"</span> on macOS.</p>


<p>Non-null pointers are formatted as a hexadecimal address using <span class="doxyComputerOutput">snprintf</span> with the <span class="doxyComputerOutput">p</span> format specifier. The resulting string is appended to the internal output buffer, allowing pointer values to be included in test reports and diagnostics.</p>


<p>This approach provides clear and unambiguous representation of pointer addresses, which is particularly useful for debugging and verifying pointer-related test cases.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00265">265</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00145">145</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad7a2cc6446e65cf9034f85c93efb3945">reporter::operator&lt;&lt;</a>(T* v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (v == </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Explicitly render null pointers as "0x0" to avoid platform-specific</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// representations such as "(nil)" on Linux/glibc.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"0x0"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> buff[20];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">    snprintf (buff, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (buff), </span><span class="doxyHighlightStringLiteral">"%p"</span><span class="doxyHighlight">, </span><span class="doxyHighlightKeyword">reinterpret_cast&lt;</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">*</span><span class="doxyHighlightKeyword">&gt;</span><span class="doxyHighlight"> (v));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.append (buff);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> and <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.</p>

</div>
</div>

### operator&lt;&lt;() {#a38ce845af263922f0e76a7e93fc0773d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">reporter &amp; micro_os_plus::micro_test_plus::reporter::operator&lt;&lt; (T v)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output operator for arithmetic types, with type suffixes.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The arithmetic type.</p></td>
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
<td class="doxyParamItemDescription"><p>The value to output.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This template operator overload allows the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> to output values of any arithmetic type (integral or floating-point) in a consistent and readable format. The value is formatted using the <span class="doxyComputerOutput">append_number_</span> helper function, which handles the conversion to a string representation with appropriate type suffixes where applicable (e.g., "f" for float, "l" for long double). This enables numeric values to be included in test reports and diagnostics in a clear and unambiguous manner, supporting the verification of test cases that involve arithmetic expressions and comparisons.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00253">253</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00185">185</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad7a2cc6446e65cf9034f85c93efb3945">reporter::operator&lt;&lt;</a>(T v)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">detail::append_number_</a> (<a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>, v);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#aa3885b7b361bc6af9e7a52fa6dcc78a1">micro_os_plus::micro_test_plus::detail::append_number_</a> and <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### begin\_session() {#ad4a31761666167469ad39585774b306e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::begin_session (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a> &amp; runner)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Mark the beginning of a test session.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">runner</td>
<td class="doxyParamItemDescription"><p>Reference to the test runner.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00363">363</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>

</div>
</div>

### begin\_subtest() {#a36390a428ba987aa91229d933a15ef27}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::begin_subtest (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Mark the beginning of a subtest.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>Reference to the subtest.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00407">407</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest/#aa7bff3af9ebff14c45838991ed848c33">micro_os_plus::micro_test_plus::subtest::run</a>.</p>

</div>
</div>

### begin\_suite() {#a89624dfaadce9810f0f5ae1577ca1080}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::begin_suite (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
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
<td class="doxyParamItemName">suite</td>
<td class="doxyParamItemDescription"><p>Reference to the test suite.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00385">385</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#ad8302d2dc629b643d34b3cfeafe44b3b">micro_os_plus::micro_test_plus::detail::runnable&lt; subtest &gt;::abort</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a4ab3277887dfc4cd8ae84bb4101eae60">micro_os_plus::micro_test_plus::static_suite::run</a>.</p>

</div>
</div>

### end\_session() {#af93c2061b90f329e1d87219bdb7c0aa4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::end_session (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">runner</a> &amp; runner)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Mark the end of a test session.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">runner</td>
<td class="doxyParamItemDescription"><p>Reference to the test runner.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00374">374</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>

</div>
</div>

### end\_subtest() {#aeaa7f67b201b405463456a6363191b50}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::end_subtest (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Mark the end of a subtest.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>Reference to the subtest.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00418">418</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>

</div>
</div>

### end\_suite() {#aa70c60884405e172bce6c8b8bab0e636}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::end_suite (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite">suite</a> &amp; suite)</td>
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
<td class="doxyParamItemDescription"><p>Reference to the test suite.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00396">396</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/static-suite/#a4ab3277887dfc4cd8ae84bb4101eae60">micro_os_plus::micro_test_plus::static_suite::run</a>.</p>

</div>
</div>

### endline() {#aee6d8d387798abd0d94052b1cf8987c4}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::reporter::endline (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Inserts a line ending into the output buffer.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>This method appends a newline character to the internal output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> and immediately flushes the stream. This ensures that each line of test output is clearly separated and promptly displayed, enhancing the readability and organisation of test results across all test cases and folders.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00291">291</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00229">229</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aee6d8d387798abd0d94052b1cf8987c4">229</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#aee6d8d387798abd0d94052b1cf8987c4">reporter::endline</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">230</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">231</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.append (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">232</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ae7f404f29f265c5db6038f1e03f854b2">flush</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">233</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a> and <a href="#ae7f404f29f265c5db6038f1e03f854b2">flush</a>.</p>

</div>
</div>

### expression() {#ad2169093aee09bc28ae7f70467569a23}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::expression_formatter &amp; micro_os_plus::micro_test_plus::reporter::expression ()</td>
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

<p>Provides access to the expression formatter for this reporter.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the <span class="doxyComputerOutput">expression_formatter</span> instance used by this reporter.</p></dd>
</dl>


<p>Returns a reference to the <span class="doxyComputerOutput">expression_formatter</span> instance used by the reporter for formatting expressions in test reports. This allows the reporter to delegate the formatting of complex expressions to the <span class="doxyComputerOutput">expression_formatter</span>, which provides a consistent and extensible way to convert various types of values and expressions into their string representations for output in test reports.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00451">451</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00107">107</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ad2169093aee09bc28ae7f70467569a23">107</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ad2169093aee09bc28ae7f70467569a23">reporter::expression</a> ()</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a5177970e7d8847d1c7f1ae79de88d1a1">expression_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a5177970e7d8847d1c7f1ae79de88d1a1">expression_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/groups/micro-test-plus-expectations/#gaad2aa05f39d1877f2173f6d0f6718bd2">micro_os_plus::micro_test_plus::subtest::expect</a>, <a href="#a0107c95e02de7196e660969b0e684173">fail</a>, <a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a>, <a href="#a0699f03871f8c5f906a07bf32505cbd7">operator&lt;&lt;</a> and <a href="#a1ac300083569b6304a7e120bb78ac337">pass</a>.</p>

</div>
</div>

### fail() {#a0107c95e02de7196e660969b0e684173}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::reporter::fail (bool abort, std::string &amp; message, const std::string &amp; expression, bool has_expression, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Report a failed condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">abort</td>
<td class="doxyParamItemDescription"><p>Whether to abort execution after failure.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The message to display.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">expression</td>
<td class="doxyParamItemDescription"><p>The string representation of the expression.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">has_expression</td>
<td class="doxyParamItemDescription"><p>Whether the expression is a compound op to display.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location of the failure.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>The subtest that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Reports a test failure, formatting the output with source location and, when <span class="doxyComputerOutput">has_expression</span> is true, the pre-formatted expression string.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00349">349</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00471">471</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0107c95e02de7196e660969b0e684173">471</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a0107c95e02de7196e660969b0e684173">reporter::fail</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> abort, std::string&amp; message,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">472</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> has_expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">473</span><span class="doxyLineContent"><span class="doxyHighlight">                  </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">474</span><span class="doxyLineContent"><span class="doxyHighlight">                  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">475</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">476</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a4192b8554e00783a61e5bebe6d9545cc">output_fail_prefix_</a> (message, has_expression, location, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">477</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">478</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (has_expression)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">479</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">480</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">481</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">482</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">483</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#af103dba717208ba08d44285066a7b326">output_fail_suffix_</a> (location, abort, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">484</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>, <a href="#a4192b8554e00783a61e5bebe6d9545cc">output_fail_prefix_</a> and <a href="#af103dba717208ba08d44285066a7b326">output_fail_suffix_</a>.</p>

</div>
</div>

### flush() {#ae7f404f29f265c5db6038f1e03f854b2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::reporter::flush (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Flush the current buffered content.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>This method flushes the output buffer of the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter">reporter</a></span> by synchronising it with the standard output stream. This guarantees that all pending test output is immediately written and visible, ensuring prompt and reliable reporting of test results across all test cases and folders.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00318">318</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00373">373</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae7f404f29f265c5db6038f1e03f854b2">373</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ae7f404f29f265c5db6038f1e03f854b2">reporter::flush</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">374</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">375</span><span class="doxyLineContent"><span class="doxyHighlight">    fflush (stdout);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">376</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">377</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">378</span><span class="doxyLineContent"><span class="doxyHighlight">        fflush (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">379</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">380</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#aa61862bc406bf1251324b5ebdabcfca0">micro_os_plus::micro_test_plus::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a05627cdee9d67cbb0f30dc3cb9fe426f">micro_os_plus::micro_test_plus::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a59da3337bb7a2d1bc89406f548131d00">micro_os_plus::micro_test_plus::reporter_human::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a27a5c6eca6a4beb82466448bfe5c44e9">micro_os_plus::micro_test_plus::reporter_tap::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a172a7a10a5aa2bd47dc6e7dde903cbbd">micro_os_plus::micro_test_plus::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#ae118be849ab3ff75ab88ff4f54f54be0">micro_os_plus::micro_test_plus::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>, <a href="#aee6d8d387798abd0d94052b1cf8987c4">endline</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#aef7c1d0436d63165f94245bf16c69f6a">micro_os_plus::micro_test_plus::reporter_human::output_fail_suffix_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a951a2aa4cb5300a7706709a2336651a8">micro_os_plus::micro_test_plus::reporter_tap::output_fail_suffix_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac5713ce51eb50a6841879b1c7d00c234">micro_os_plus::micro_test_plus::reporter_human::output_pass_suffix_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#ac46a89737874c4f864a98b91d8c57ecd">micro_os_plus::micro_test_plus::reporter_tap::output_pass_suffix_</a>.</p>

</div>
</div>

### get\_comment\_prefix() {#a9cafc8992d508b5ffa0b6a64226202bd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual const char * micro_os_plus::micro_test_plus::reporter::get_comment_prefix (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Returns the comment-prefix string used by this reporter format.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>A null-terminated prefix string.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00429">429</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>References <a href="#ab6b39c68c08e7ccfb29a693bc86d391c">colour_</a>, <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>, <a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a>, <a href="#ae656aff0d07d7cc634f1a0b2046137e9">write_buffer_to_file_</a> and <a href="#a7ee71ebee4a54fb4b05c1f476cc78263">write_info_</a>.</p>


<p>Referenced by <a href="#a7ee71ebee4a54fb4b05c1f476cc78263">write_info_</a>.</p>

</div>
</div>

### pass() {#a1ac300083569b6304a7e120bb78ac337}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::reporter::pass (std::string &amp; message, const std::string &amp; expression, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Report a passed condition.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">message</td>
<td class="doxyParamItemDescription"><p>The message to display.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">expression</td>
<td class="doxyParamItemDescription"><p>The string representation of the expression.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>The subtest that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Outputs a pass prefix, followed by either the provided message or, if the message is empty, the evaluated expression string itself. A pass suffix is then appended to complete the output.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00332">332</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00452">452</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1ac300083569b6304a7e120bb78ac337">452</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a1ac300083569b6304a7e120bb78ac337">reporter::pass</a> (std::string&amp; message, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">453</span><span class="doxyLineContent"><span class="doxyHighlight">                  <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">454</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">455</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#aa78041c4993a5a84f0eba4c278071c9f">output_pass_prefix_</a> (message, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">456</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">457</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (message.empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">458</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">459</span><span class="doxyLineContent"><span class="doxyHighlight">        *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight"> &lt;&lt; <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">460</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">461</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">462</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a18e488b545a2dfa190f9f003b4f7ef57">output_pass_suffix_</a> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">463</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>, <a href="#aa78041c4993a5a84f0eba4c278071c9f">output_pass_prefix_</a> and <a href="#a18e488b545a2dfa190f9f003b4f7ef57">output_pass_suffix_</a>.</p>

</div>
</div>

### verbosity() {#a24da76a8973a5aebca9ef7604740180c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_test_plus::verbosity micro_os_plus::micro_test_plus::reporter::verbosity ()</td>
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

<p>Returns the current verbosity level.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>The active <span class="doxyComputerOutput"><a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a></span> value.</p></dd>
</dl>


<p>Returns the verbosity level stored in <span class="doxyComputerOutput"><a href="#aea922774c24ce8337d734fa457896595">verbosity_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00440">440</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00092">92</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a24da76a8973a5aebca9ef7604740180c">92</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a24da76a8973a5aebca9ef7604740180c">reporter::verbosity</a> () const -&gt; <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_test_plus</a>::<a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">93</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">94</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">95</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a> and <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a>.</p>


<p>Referenced by <a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a> and <a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a>.</p>

</div>
</div>

### write\_buffer\_to\_stdout() {#a26d99bc552ad4ed31253028647e939b1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::reporter::write_buffer_to_stdout (void)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Output the current buffered content.</p>



:::info
<p>Public because <span class="doxyComputerOutput">deferred_reporter_base</span> calls this from its destructor when aborting, after the subtest instance is no longer accessible via the normal reporting path.</p>
:::


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>This method writes the contents of the internal output buffer to the standard output stream without appending a newline character. After outputting the buffer, it is cleared to prepare for subsequent output. This approach ensures that test results are presented promptly and efficiently, supporting clear and organised reporting across all test cases and folders.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00307">307</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00245">245</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a26d99bc552ad4ed31253028647e939b1">245</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a26d99bc552ad4ed31253028647e939b1">reporter::write_buffer_to_stdout</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">246</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">247</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pass only the string, do not add an `\n` here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">248</span><span class="doxyLineContent"><span class="doxyHighlight">    printf (</span><span class="doxyHighlightStringLiteral">"%s"</span><span class="doxyHighlight">, <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">249</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a27a5c6eca6a4beb82466448bfe5c44e9">micro_os_plus::micro_test_plus::reporter_tap::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Functions

### colour\_() {#ab6b39c68c08e7ccfb29a693bc86d391c}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto micro_os_plus::micro_test_plus::reporter::colour_ (const bool cond)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel protected">protected</span>
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
<dt>Returns</dt>
<dd><p>The corresponding ANSI colour code as a string.</p></dd>
</dl>


<p>Returns the ANSI colour code for pass or fail, depending on the boolean condition provided.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00463">463</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h/#l00118">118</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ab6b39c68c08e7ccfb29a693bc86d391c">118</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ab6b39c68c08e7ccfb29a693bc86d391c">reporter::colour_</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> cond)</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">  </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> cond ? <a href="#adb47f38a4be48757fb7f8658132998fe">colours_</a>.pass : <a href="#adb47f38a4be48757fb7f8658132998fe">colours_</a>.fail;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>Reference <a href="#adb47f38a4be48757fb7f8658132998fe">colours_</a>.</p>


<p>Referenced by <a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a>.</p>

</div>
</div>

### output\_fail\_prefix\_() {#a4192b8554e00783a61e5bebe6d9545cc}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::output_fail_prefix_ (std::string &amp; message, const bool has_expression, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest)</td>
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
<td class="doxyParamItemName">has_expression</td>
<td class="doxyParamItemDescription"><p>Whether the failure is associated with an expression.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location of the failure.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>The subtest that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00514">514</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a4192b8554e00783a61e5bebe6d9545cc">output_fail_prefix_</a>.</p>


<p>Referenced by <a href="#a0107c95e02de7196e660969b0e684173">fail</a> and <a href="#a4192b8554e00783a61e5bebe6d9545cc">output_fail_prefix_</a>.</p>

</div>
</div>

### output\_fail\_suffix\_() {#af103dba717208ba08d44285066a7b326}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::output_fail_suffix_ (const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, bool abort, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest)</td>
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
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location of the failure.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">abort</td>
<td class="doxyParamItemDescription"><p>Whether to abort execution after failure.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>The subtest that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00529">529</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#af103dba717208ba08d44285066a7b326">output_fail_suffix_</a>.</p>


<p>Referenced by <a href="#a0107c95e02de7196e660969b0e684173">fail</a> and <a href="#af103dba717208ba08d44285066a7b326">output_fail_suffix_</a>.</p>

</div>
</div>

### output\_pass\_prefix\_() {#aa78041c4993a5a84f0eba4c278071c9f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::output_pass_prefix_ (std::string &amp; message, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest)</td>
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
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>The subtest that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00488">488</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#aa78041c4993a5a84f0eba4c278071c9f">output_pass_prefix_</a>.</p>


<p>Referenced by <a href="#aa78041c4993a5a84f0eba4c278071c9f">output_pass_prefix_</a> and <a href="#a1ac300083569b6304a7e120bb78ac337">pass</a>.</p>

</div>
</div>

### output\_pass\_suffix\_() {#a18e488b545a2dfa190f9f003b4f7ef57}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">virtual void micro_os_plus::micro_test_plus::reporter::output_pass_suffix_ (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest)</td>
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


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>The subtest that owns this check.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00499">499</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<p>Reference <a href="#a18e488b545a2dfa190f9f003b4f7ef57">output_pass_suffix_</a>.</p>


<p>Referenced by <a href="#a18e488b545a2dfa190f9f003b4f7ef57">output_pass_suffix_</a> and <a href="#a1ac300083569b6304a7e120bb78ac337">pass</a>.</p>

</div>
</div>

### write\_buffer\_to\_file\_() {#ae656aff0d07d7cc634f1a0b2046137e9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::reporter::write_buffer_to_file_ (void)</td>
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




<p>Writes the contents of <span class="doxyComputerOutput"><a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a></span> to <span class="doxyComputerOutput"><a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a></span> using <span class="doxyComputerOutput">fprintf</span> without appending a newline. If <span class="doxyComputerOutput"><a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a></span> is null, the call is a no-op.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00466">466</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00258">258</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae656aff0d07d7cc634f1a0b2046137e9">258</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ae656aff0d07d7cc634f1a0b2046137e9">reporter::write_buffer_to_file_</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">259</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">260</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightComment">// Pass only the string, do not add an `\n` here.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">261</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">262</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">263</span><span class="doxyLineContent"><span class="doxyHighlight">        fprintf (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>, </span><span class="doxyHighlightStringLiteral">"%s"</span><span class="doxyHighlight">, <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">264</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">265</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a> and <a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a> and <a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a>.</p>

</div>
</div>

### write\_info\_() {#a7ee71ebee4a54fb4b05c1f476cc78263}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::reporter::write_info_ (void)</td>
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

<p>Appends informational (non-result) text to the output buffer.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Nothing.</p></dd>
</dl>


<p>Constructs and emits two informational lines: the first lists the programme name and any command-line arguments; the second identifies the compiler (Clang, GCC, or MSVC) together with the version string, floating-point availability on bare-metal targets, exception support, and any active debug or trace macros. Both lines are written to the output file when one is open, and to <span class="doxyComputerOutput">stdout</span> unless verbosity is set to <span class="doxyComputerOutput">silent</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00477">477</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp/#l00278">278</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a7ee71ebee4a54fb4b05c1f476cc78263">278</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#a7ee71ebee4a54fb4b05c1f476cc78263">reporter::write_info_</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">279</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">280</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a> &amp;&amp; !<a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a>-&gt;empty ())</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">281</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">282</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; args = *<a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">283</span><span class="doxyLineContent"><span class="doxyHighlight">        std::string line;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">284</span><span class="doxyLineContent"><span class="doxyHighlight">        line.reserve (256);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">285</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (<a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">286</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (</span><span class="doxyHighlightStringLiteral">"Running: "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">287</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">288</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightComment">// Append only the file name part of argv[0].</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">289</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string_view arg0 = args[0];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">290</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> sep = arg0.rfind (</span><span class="doxyHighlightCharLiteral">'/'</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">291</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append ((sep != std::string_view::npos) ? arg0.substr (sep + 1)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">292</span><span class="doxyLineContent"><span class="doxyHighlight">                                                     : arg0);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">293</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">294</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">for</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeywordType">size_t</span><span class="doxyHighlight"> i = 1; i &lt; args.size (); ++i)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">295</span><span class="doxyLineContent"><span class="doxyHighlight">          {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">296</span><span class="doxyLineContent"><span class="doxyHighlight">            line.append (</span><span class="doxyHighlightStringLiteral">" "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">297</span><span class="doxyLineContent"><span class="doxyHighlight">            line.append (args[i]);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">298</span><span class="doxyLineContent"><span class="doxyHighlight">          }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">299</span><span class="doxyLineContent"><span class="doxyHighlight">        line.append (</span><span class="doxyHighlightStringLiteral">"\n"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">300</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">301</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">302</span><span class="doxyLineContent"><span class="doxyHighlight">          fprintf (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>, </span><span class="doxyHighlightStringLiteral">"%s"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">303</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">304</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) &amp;&amp; defined(MICRO_OS_PLUS_TRACE))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">305</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">306</span><span class="doxyLineContent"><span class="doxyHighlight">            || <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">307</span><span class="doxyLineContent"><span class="doxyHighlight">          printf (</span><span class="doxyHighlightStringLiteral">"%s"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">308</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(MICRO_OS_PLUS_INCLUDE_STARTUP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">309</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">310</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">311</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">312</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// Build the "Built with ..." line. For the output file the compiler</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">313</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// version is omitted; for stdout it is appended via __VERSION__.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">314</span><span class="doxyLineContent"><span class="doxyHighlight">      std::string line;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">315</span><span class="doxyLineContent"><span class="doxyHighlight">      line.reserve (256);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">316</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (<a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a> ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">317</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"Built with "</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">318</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">319</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"clang "</span><span class="doxyHighlight"> __VERSION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">320</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">321</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"GCC "</span><span class="doxyHighlight"> __VERSION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">322</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#elif defined(_MSC_VER)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">323</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"MSVC"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">324</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> msvc_ver[16];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">325</span><span class="doxyLineContent"><span class="doxyHighlight">      snprintf (msvc_ver, </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (msvc_ver), </span><span class="doxyHighlightStringLiteral">" - %d"</span><span class="doxyHighlight">, _MSC_VER);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">326</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (msvc_ver);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">327</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">328</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">"an unknown compiler"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">329</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">330</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">331</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">      || defined(WIN32))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">332</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// This is relevant only on bare-metal.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">333</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__ARM_PCS_VFP) || defined(__ARM_FP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">334</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with FP"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">335</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">336</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", no FP"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">337</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">338</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">339</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__EXCEPTIONS)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">340</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with exceptions"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">341</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">342</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", no exceptions"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">343</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">344</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_DEBUG)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">345</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with MICRO_OS_PLUS_DEBUG"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">346</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">347</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">348</span><span class="doxyLineContent"><span class="doxyHighlight">      line.append (</span><span class="doxyHighlightStringLiteral">", with MICRO_OS_PLUS_TRACE"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">349</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">350</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">351</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a> != </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight">)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">352</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">353</span><span class="doxyLineContent"><span class="doxyHighlight">          fprintf (<a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>, </span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">354</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">355</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">356</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) &amp;&amp; defined(MICRO_OS_PLUS_TRACE))</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">357</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a> || <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">verbosity::verbose</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">358</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">359</span><span class="doxyLineContent"><span class="doxyHighlight">          printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, line.c_str ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">360</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">361</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// !defined(MICRO_OS_PLUS_INCLUDE_STARTUP)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">362</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">363</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a>, <a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">micro_os_plus::micro_test_plus::normal</a>, <a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914ba2c7aea4237e25b4f8ee3b0bf77d6fed0">micro_os_plus::micro_test_plus::verbose</a> and <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#aa61862bc406bf1251324b5ebdabcfca0">micro_os_plus::micro_test_plus::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a05627cdee9d67cbb0f30dc3cb9fe426f">micro_os_plus::micro_test_plus::reporter_tap::begin_session</a> and <a href="#a9cafc8992d508b5ffa0b6a64226202bd">get_comment_prefix</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### add\_empty\_line\_ {#a3961bc77e50ecbade82b29dd5983ddec}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::reporter::add_empty_line_ { true }</td>
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

<p>Controls whether to add an empty line between successful test cases.</p>


<p>Used to nicely format the output.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00572">572</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3961bc77e50ecbade82b29dd5983ddec">572</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a3961bc77e50ecbade82b29dd5983ddec">add_empty_line_</a>{ </span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#aa61862bc406bf1251324b5ebdabcfca0">micro_os_plus::micro_test_plus::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a05627cdee9d67cbb0f30dc3cb9fe426f">micro_os_plus::micro_test_plus::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a59da3337bb7a2d1bc89406f548131d00">micro_os_plus::micro_test_plus::reporter_human::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a27a5c6eca6a4beb82466448bfe5c44e9">micro_os_plus::micro_test_plus::reporter_tap::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a172a7a10a5aa2bd47dc6e7dde903cbbd">micro_os_plus::micro_test_plus::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#ae118be849ab3ff75ab88ff4f54f54be0">micro_os_plus::micro_test_plus::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>.</p>

</div>
</div>

### argvs\_ {#a123948993e8c24962071a32d8274c4f6}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::unique_ptr&lt;std::vector&lt;std::string_view&gt; &gt; micro_os_plus::micro_test_plus::reporter::argvs_ {}</td>
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

<p>Owns the command-line arguments passed to the test runner.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00596">596</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a123948993e8c24962071a32d8274c4f6">596</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::unique_ptr&lt;std::vector&lt;std::string_view&gt;&gt; <a href="#a123948993e8c24962071a32d8274c4f6">argvs_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> and <a href="#a7ee71ebee4a54fb4b05c1f476cc78263">write_info_</a>.</p>

</div>
</div>

### buffer\_ {#a6eed4eaebea91b3377b89a118eb1c323}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::reporter::buffer_ {}</td>
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

<p>Output accumulation buffer.</p>


<p>Accumulates all reporter output until it is written to standard output or the output file via <span class="doxyComputerOutput"><a href="#a26d99bc552ad4ed31253028647e939b1">write_buffer_to_stdout()</a></span> or <span class="doxyComputerOutput"><a href="#ae656aff0d07d7cc634f1a0b2046137e9">write_buffer_to_file_()</a></span>.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00552">552</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a6eed4eaebea91b3377b89a118eb1c323">552</a></span><span class="doxyLineContent"><span class="doxyHighlight">    std::string <a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a59da3337bb7a2d1bc89406f548131d00">micro_os_plus::micro_test_plus::reporter_human::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a27a5c6eca6a4beb82466448bfe5c44e9">micro_os_plus::micro_test_plus::reporter_tap::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>, <a href="#aee6d8d387798abd0d94052b1cf8987c4">endline</a>, <a href="#a5bc1b012e5817563a4d699b2145ec077">operator&lt;&lt;</a>, <a href="#afb205af933ef6b71f23a6943ad6bd628">operator&lt;&lt;</a>, <a href="#ad7a2cc6446e65cf9034f85c93efb3945">operator&lt;&lt;</a>, <a href="#a0acf1be4a7b9738dd2d3b9748e32d872">operator&lt;&lt;</a>, <a href="#a38ce845af263922f0e76a7e93fc0773d">operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a95dcf787668c7897d5c92ecce99dc6d5">micro_os_plus::micro_test_plus::reporter_human::operator&lt;&lt;</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a4225a7fb05cb67bf2f881e97fc012ebb">micro_os_plus::micro_test_plus::reporter_tap::operator&lt;&lt;</a>, <a href="#ae656aff0d07d7cc634f1a0b2046137e9">write_buffer_to_file_</a> and <a href="#a26d99bc552ad4ed31253028647e939b1">write_buffer_to_stdout</a>.</p>

</div>
</div>

### colours\_ {#adb47f38a4be48757fb7f8658132998fe}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::colours micro_os_plus::micro_test_plus::reporter::colours_ {}</td>
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

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00542">542</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#adb47f38a4be48757fb7f8658132998fe">542</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail">detail</a>::colours <a href="#adb47f38a4be48757fb7f8658132998fe">colours_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a391d670afb552fe8fc03011d37a517fd">micro_os_plus::micro_test_plus::reporter_human::reporter_human</a>, <a href="#ab6b39c68c08e7ccfb29a693bc86d391c">colour_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a20077cabbb38559ff5b0f75140fc7eae">micro_os_plus::micro_test_plus::reporter_human::output_fail_prefix_</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ae831c47658d21e0e77bf7df79b8fc58f">micro_os_plus::micro_test_plus::reporter_human::output_pass_prefix_</a>.</p>

</div>
</div>

### expression\_ {#a5177970e7d8847d1c7f1ae79de88d1a1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">detail::expression_formatter micro_os_plus::micro_test_plus::reporter::expression_ { <a href="#adb47f38a4be48757fb7f8658132998fe">colours_</a> }</td>
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

<p>Expression formatter for pass and fail reporting.</p>


<p>Used in <span class="doxyComputerOutput"><a href="#a1ac300083569b6304a7e120bb78ac337">pass()</a></span> and <span class="doxyComputerOutput"><a href="#a0107c95e02de7196e660969b0e684173">fail()</a></span> to format expression values before appending the result to <span class="doxyComputerOutput"><a href="#a6eed4eaebea91b3377b89a118eb1c323">buffer_</a></span>. Will also be used by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter">detail::deferred_reporter</a></span> to pre-format expressions at construction time.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00563">563</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5177970e7d8847d1c7f1ae79de88d1a1">563</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">detail::expression_formatter</a> <a href="#a5177970e7d8847d1c7f1ae79de88d1a1">expression_</a>{ <a href="#adb47f38a4be48757fb7f8658132998fe">colours_</a> };</span></span></div>

</div>


<p>Referenced by <a href="#ad2169093aee09bc28ae7f70467569a23">expression</a>.</p>

</div>
</div>

### output\_file\_ {#a1d95688325caf323a4d77272dcf50b86}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">FILE* micro_os_plus::micro_test_plus::reporter::output_file_ { nullptr }</td>
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

<p>Optional output file for redirecting test report output.</p>


<p>When non-null, all output is written to this file instead of standard output. The reporter does not own the file; the caller is responsible for its lifetime.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00591">591</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a1d95688325caf323a4d77272dcf50b86">591</a></span><span class="doxyLineContent"><span class="doxyHighlight">    FILE* <a href="#a1d95688325caf323a4d77272dcf50b86">output_file_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a>, <a href="#a1ab2bf741196d093aada2d4f3876176b">~reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#aa61862bc406bf1251324b5ebdabcfca0">micro_os_plus::micro_test_plus::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a05627cdee9d67cbb0f30dc3cb9fe426f">micro_os_plus::micro_test_plus::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a59da3337bb7a2d1bc89406f548131d00">micro_os_plus::micro_test_plus::reporter_human::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a27a5c6eca6a4beb82466448bfe5c44e9">micro_os_plus::micro_test_plus::reporter_tap::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a172a7a10a5aa2bd47dc6e7dde903cbbd">micro_os_plus::micro_test_plus::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#ae118be849ab3ff75ab88ff4f54f54be0">micro_os_plus::micro_test_plus::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>, <a href="#ae7f404f29f265c5db6038f1e03f854b2">flush</a>, <a href="#ae656aff0d07d7cc634f1a0b2046137e9">write_buffer_to_file_</a> and <a href="#a7ee71ebee4a54fb4b05c1f476cc78263">write_info_</a>.</p>

</div>
</div>

### output\_file\_path\_ {#abb92804e6eaee977fdc1e48f29c632f2}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const char* micro_os_plus::micro_test_plus::reporter::output_file_path_ { nullptr }</td>
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

<p>Optional file path for redirecting test report output.</p>


<p>When non-null, <span class="doxyComputerOutput"><a href="#ae656aff0d07d7cc634f1a0b2046137e9">write_buffer_to_file_()</a></span> writes accumulated output to this path in addition to (or instead of) standard output.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00581">581</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#abb92804e6eaee977fdc1e48f29c632f2">581</a></span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* <a href="#abb92804e6eaee977fdc1e48f29c632f2">output_file_path_</a>{ </span><span class="doxyHighlightKeyword">nullptr</span><span class="doxyHighlight"> };</span></span></div>

</div>


<p>Referenced by <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a> and <a href="#a1ab2bf741196d093aada2d4f3876176b">~reporter</a>.</p>

</div>
</div>

### verbosity\_ {#aea922774c24ce8337d734fa457896595}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">enum verbosity micro_os_plus::micro_test_plus::reporter::verbosity_ = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">verbosity::normal</a></td>
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

<p>The verbosity level for test reporting.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h/#l00537">537</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aea922774c24ce8337d734fa457896595">537</a></span><span class="doxyLineContent"><span class="doxyHighlight">    enum <a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a> <a href="#aea922774c24ce8337d734fa457896595">verbosity_</a> = <a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a>::<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/#a809871d76f29309ed9c6fbd96d5a914bafea087517c26fadd409bd4b9dc642555">normal</a>;</span></span></div>

</div>


<p>Referenced by <a href="#a0643dcab9f46bc3090939c2a17f829e4">reporter</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#aa61862bc406bf1251324b5ebdabcfca0">micro_os_plus::micro_test_plus::reporter_human::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a05627cdee9d67cbb0f30dc3cb9fe426f">micro_os_plus::micro_test_plus::reporter_tap::begin_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a59da3337bb7a2d1bc89406f548131d00">micro_os_plus::micro_test_plus::reporter_human::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a27a5c6eca6a4beb82466448bfe5c44e9">micro_os_plus::micro_test_plus::reporter_tap::begin_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a172a7a10a5aa2bd47dc6e7dde903cbbd">micro_os_plus::micro_test_plus::reporter_human::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#ae118be849ab3ff75ab88ff4f54f54be0">micro_os_plus::micro_test_plus::reporter_tap::begin_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a3118ff89506858505f18e8fd368baffc">micro_os_plus::micro_test_plus::reporter_human::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a9a224d34b068e1698c00633ae2341e7f">micro_os_plus::micro_test_plus::reporter_tap::end_session</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#a052138e5f517b578df99204c8d88213e">micro_os_plus::micro_test_plus::reporter_human::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a79c7928d44d70b8fe5bf993775517e63">micro_os_plus::micro_test_plus::reporter_tap::end_subtest</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-human/#ac0a6d2bda91a9afa71346eef59c7f35e">micro_os_plus::micro_test_plus::reporter_human::end_suite</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reporter-tap/#a8649b62ba8f7ff88501450c5f939ab6d">micro_os_plus::micro_test_plus::reporter_tap::end_suite</a>, <a href="#a24da76a8973a5aebca9ef7604740180c">verbosity</a> and <a href="#a7ee71ebee4a54fb4b05c1f476cc78263">write_info_</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/reporter-inlines-h">reporter-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/reporter-h">reporter.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/reporter-cpp">reporter.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
