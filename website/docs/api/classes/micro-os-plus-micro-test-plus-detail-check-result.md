---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/check-result
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `check_result` Class

<p>The result of one check, reported when destroyed. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::detail::check_result { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include "<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>"
</div>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ac5423d6f891819a4bf2f0bb0d4df8996">check_result</a> (check_result &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move constructor to prevent moving. <a href="#ac5423d6f891819a4bf2f0bb0d4df8996">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#adc3eb4dbb45d2dfa7b88aac996247f10">check_result</a> (const check_result &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy constructor to prevent copying. <a href="#adc3eb4dbb45d2dfa7b88aac996247f10">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemNoTypeNameTemplate" colspan="2" align="left" valign="top"><a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a> (const Expr_T &amp;expr, check_kind kind, const reflection::source_location &amp;location, test_case &amp;test_case, expression_formatter &amp;expression, bool writes_passed)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the result of a check of an expression. <a href="#a3c6ef4e73f3bf898f1682187dc86919d">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#aae72a4be3b00dd0af05eb50c65ae1815">check_result</a> (bool value, check_kind kind, bool has_expression, const reflection::source_location &amp;location, test_case &amp;test_case, bool writes_passed)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs the result of a check from its parts. <a href="#aae72a4be3b00dd0af05eb50c65ae1815">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#ae3b88e57597f9fcd04536b894bebef5e">~check_result</a> ()</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Destructor that reports the check. <a href="#ae3b88e57597f9fcd04536b894bebef5e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Operators Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemTypeTemplate" align="left" valign="top">auto &amp;</td>
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="#a44b0e35cd70af1cd0bfe333ffd6629e9">operator&lt;&lt;</a> (const T &amp;msg)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a message to the check. <a href="#a44b0e35cd70af1cd0bfe333ffd6629e9">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a26da353e3ea2577e00106c8f1f7b316b">operator=</a> (check_result &amp;&amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted move assignment operator to prevent moving. <a href="#a26da353e3ea2577e00106c8f1f7b316b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a231681600fe29544efcdba22c56d5740">operator=</a> (const check_result &amp;)=delete</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Deleted copy assignment operator to prevent copying. <a href="#a231681600fe29544efcdba22c56d5740">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Member Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a683d05f5acadf26be1ef2303c4670039">value</a> (void) const noexcept</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Retrieves the result value. <a href="#a683d05f5acadf26be1ef2303c4670039">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Private Member Attributes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info">failure_info</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af96f9a6d186ff05253e33d088cab8106">info_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The details displayed when the check fails. <a href="#af96f9a6d186ff05253e33d088cab8106">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Whether the outcome of the check is written. <a href="#af0281b8df34411a8e9e45fa7f7c83d4b">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reference to the test case invoking this check. <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a4a9f64710ef24d140b065ae5666badeb">uncaught_exceptions_</a> = 0</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The number of uncaught exceptions when the check was created. <a href="#a4a9f64710ef24d140b065ae5666badeb">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the result value of the check. <a href="#a5e3cca5a1c660bc576184ca200f73cc7">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The result of one check, reported when destroyed.</p>


<p>Returned by <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span>, it lives until the end of the expression statement. Its template constructor evaluates the expression and formats it, with the actual operand values, into the expression formatter of the reporter, which keeps the text for this check until it is reported, so that it can be displayed on failure. The messages passed via <span class="doxyComputerOutput">operator&lt;&lt;()</span> are collected into a string. The destructor reports the outcome, updates the counters of the test case, and, after a failed <span class="doxyComputerOutput">require()</span>, stops the test case.</p>


<p>A passed check whose line the reporter never writes (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/reporter/#a2c1e2c756b442d4832c161c8127faacf">reporter::writes_passed_checks()</a></span>) formats neither its expression nor its messages, and is only counted.</p>


<p>Only the template constructor depends on the type of the expression; it delegates to a private non-template constructor, and the destructor, which does the reporting, is not a template either, so this code is compiled once, in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/files/src/check-result-cpp">src/check-result.cpp</a></span>, not for each type of expression.</p>


<p>Definition at line 210 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### check\_result() {#ac5423d6f891819a4bf2f0bb0d4df8996}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::check_result::check_result (check_result &amp;&amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted move constructor to prevent moving.</p>


<p>The instance is a temporary that lives only until the end of the expression statement.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00254">254</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<p>Reference <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a>.</p>

</div>
</div>

### check\_result() {#adc3eb4dbb45d2dfa7b88aac996247f10}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::check_result::check_result (const check_result &amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted copy constructor to prevent copying.</p>


<p>Each instance reports exactly one check, from its destructor; a copy would report it twice.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00245">245</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<p>Reference <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a>.</p>

</div>
</div>

### check\_result() {#a3c6ef4e73f3bf898f1682187dc86919d}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::check_result::check_result (const Expr_T &amp; expr, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">check_kind</a> kind, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> &amp; test_case, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a> &amp; expression, bool writes_passed)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the result of a check of an expression.</p>


<p>The expression is evaluated, and, if the outcome is written, formatted into the expression formatter.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">Expr_T</td>
<td class="doxyParamItemDescription"><p>The type of the expression.</p></td>
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
<td class="doxyParamItemDescription"><p>The expression under evaluation.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">kind</td>
<td class="doxyParamItemDescription"><p>The kind of the check, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">check_kind::requirement</a></span> for <span class="doxyComputerOutput">require()</span>, whose failure stops the test case.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location of the check.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that owns this check.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">expression</td>
<td class="doxyParamItemDescription"><p>The expression formatter to format the expression text.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">writes_passed</td>
<td class="doxyParamItemDescription"><p>Whether the reporter writes the passed checks; if not, a passed check is not formatted.</p></td>
</tr>
</table>
</dd>
</dl>

<p>The expression is evaluated, and the result is passed, together with the kind of the check and whether the expression is a framework comparator, to the non-template constructor, which also stores the source location and the test case. The kind, <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">check_kind::requirement</a></span> for <span class="doxyComputerOutput">require()</span>, determines whether the test case is stopped if the check fails.</p>


<p>The expression formatter of the reporter, which is shared by all checks, is then assigned to this check by <span class="doxyComputerOutput">begin_check()</span>, which sets aside the text of a previous check not yet reported, if any. The expression is formatted into it only when the outcome is written: on failure, or, if <span class="doxyComputerOutput">writes_passed</span>, also on success. Otherwise the text of this check stays empty, and the operands, which may be application types with an expensive <span class="doxyComputerOutput">operator&lt;&lt;</span>, are not formatted.</p>


<p>An expression that is only explicitly convertible to <span class="doxyComputerOutput">bool</span>, such as a <span class="doxyComputerOutput">std::optional</span> or a <span class="doxyComputerOutput">std::unique_ptr</span>, is written as the result of the conversion, <span class="doxyComputerOutput">true</span> or <span class="doxyComputerOutput">false</span>, since that is what the check tested; its own value (the contents of a <span class="doxyComputerOutput">std::optional&lt;bool&gt;</span>, for example) could contradict the outcome, and many such types cannot be formatted at all.</p>


<p>The decision is taken here, while the operands are alive; a result kept in a variable outlives them.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00233">233</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/check-result-inlines-h/#l00106">106</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/check-result-inlines-h">check-result-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a3c6ef4e73f3bf898f1682187dc86919d">106</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result::check_result</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">check_kind</a> kind,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">107</span><span class="doxyLineContent"><span class="doxyHighlight">                                </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">                                <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">                                <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a>&amp; expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">                                </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> writes_passed)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a>{ static_cast&lt;bool&gt; (expr),</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">                        kind,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">                        <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/extension">extension</a>::is_op&lt;Expr_T&gt;,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">                        location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">                        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">                        writes_passed }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlight">      trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// The same address is used by the destructor, to retrieve the text,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// even if other checks used the formatter in the meantime.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">      expression.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a433e0e309292ccc3e42a35076e32d6c3">begin_check</a> (</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/extension/is-op">extension::is_op&lt;Expr_T&gt;</a></span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">                        or std::convertible_to&lt;Expr_T, bool&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">              expression &lt;&lt; expr;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">              expression &lt;&lt; static_cast&lt;bool&gt; (expr);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a433e0e309292ccc3e42a35076e32d6c3">micro_os_plus::micro_test_plus::detail::expression_formatter::begin_check</a> and <a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a>.</p>


<p>Referenced by <a href="#ac5423d6f891819a4bf2f0bb0d4df8996">check_result</a>, <a href="#adc3eb4dbb45d2dfa7b88aac996247f10">check_result</a>, <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a>, <a href="#a26da353e3ea2577e00106c8f1f7b316b">operator=</a> and <a href="#a231681600fe29544efcdba22c56d5740">operator=</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Constructors

### check\_result() {#aae72a4be3b00dd0af05eb50c65ae1815}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::check_result::check_result (bool value, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">check_kind</a> kind, bool has_expression, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> &amp; test_case, bool writes_passed)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs the result of a check from its parts.</p>


<p>The non-template part of the construction, shared by all the instantiations of the template constructor, which delegates to it.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">value</td>
<td class="doxyParamItemDescription"><p>The result of the evaluated expression.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">kind</td>
<td class="doxyParamItemDescription"><p>The kind of the check.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">has_expression</td>
<td class="doxyParamItemDescription"><p>Indicates whether the expression is a framework comparator, whose text is displayed on failure.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location of the check.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">test_case</td>
<td class="doxyParamItemDescription"><p>The test case that owns this check.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">writes_passed</td>
<td class="doxyParamItemDescription"><p>Whether the reporter writes the passed checks.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Stores the evaluated Boolean <span class="doxyComputerOutput">value</span>, and, in the failure details, the <span class="doxyComputerOutput">kind</span> of the check, the <span class="doxyComputerOutput">has_expression</span> flag, and the <span class="doxyComputerOutput">location</span> identifying the source line of the assertion, with an empty message; it also stores a reference to the owning <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a></span>. The outcome is written when the check failed, or when the reporter writes the passed checks (<span class="doxyComputerOutput">writes_passed</span>). The check number is assigned later, by the destructor, when the check is reported.</p>


<p>When exceptions are enabled, the number of uncaught exceptions is also stored, so that the destructor can tell whether it runs during stack unwinding.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00327">327</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/check-result-cpp/#l00081">81</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/check-result-cpp">check-result.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#aae72a4be3b00dd0af05eb50c65ae1815">81</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result::check_result</a> (</span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a683d05f5acadf26be1ef2303c4670039">value</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70c">check_kind</a> kind,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">82</span><span class="doxyLineContent"><span class="doxyHighlight">                                </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> has_expression,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">83</span><span class="doxyLineContent"><span class="doxyHighlight">                                </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">84</span><span class="doxyLineContent"><span class="doxyHighlight">                                <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> writes_passed)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">85</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>{ <a href="#a683d05f5acadf26be1ef2303c4670039">value</a> }, <a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a>{ !<a href="#a683d05f5acadf26be1ef2303c4670039">value</a> || writes_passed },</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">86</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>{ kind, {}, has_expression, location }, test_case_{ <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a> }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">87</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">      uncaught_exceptions_ = std::uncaught_exceptions ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">91</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>, <a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a>, <a href="#a683d05f5acadf26be1ef2303c4670039">value</a> and <a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~check\_result() {#ae3b88e57597f9fcd04536b894bebef5e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::check_result::~check_result ()</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel noexcept(false)">noexcept(false)</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Destructor that reports the check.</p>


<p>It may throw <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failed-requirement">failed_requirement</a></span>, after a failed <span class="doxyComputerOutput">require()</span>, to stop the test case, hence <span class="doxyComputerOutput">noexcept (false)</span>.</p>


<p>The destructor reports the result of the check, at the end of the expression statement, after all the user messages were appended.</p>


<p>The test point number of the test case is advanced first, so that the check numbers follow the order in which the checks are reported (the first check is reported as check #1), also when the result of a check is kept in a variable and reported after later checks.</p>


<p>If the evaluated expression is true, the reporter records a successful outcome along with any accumulated message, unless it does not write the passed checks, and the passed checks counter of the test case is incremented. If the expression is false, the reporter records a failure, with the failure details (the kind of the check, the message, and the source location) and the expression, and the failed checks counter is incremented.</p>


<p>The expression text is obtained from the expression formatter with <span class="doxyComputerOutput">check_text()</span>, which returns the text of this check even if later checks used the formatter, and is released with <span class="doxyComputerOutput">end_check()</span>.</p>


<p>If the check is a <span class="doxyComputerOutput">require()</span> and the test expression has failed, the test case is stopped: when exceptions are enabled, by throwing <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failed-requirement">failed_requirement</a></span>, caught by <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#adb4333ecb107fee477156b661f0b1512">test_case::run()</a></span>, as the fatal assertions of most C++ test frameworks do; the run then continues with the next test case. If the destructor runs during stack unwinding (for a result kept in a variable), it does not throw, since the test case is already being stopped.</p>


<p>Without exceptions, the test execution is aborted via the runner, whose reporter writes the buffered test output, in place of the <span class="doxyComputerOutput">end_test_case()</span> that is never reached (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a7bc806540e65c21095ef1ea1ef970db2">runner::abort()</a></span>).</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00283">283</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/check-result-cpp/#l00127">127</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/check-result-cpp">check-result.cpp</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ae3b88e57597f9fcd04536b894bebef5e">127</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#ae3b88e57597f9fcd04536b894bebef5e">check_result::~check_result</a> () noexcept (false)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">      trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// The index starts at 0; it must be incremented before the check is</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// reported, so that the first check is reported as check #1.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>.next_test_point_number ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// The text formatted by this check, even if the formatter was used by</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightComment">// other checks in the meantime (when this result was kept).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; expression = <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>.test_reporter ().expression_;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> std::string&amp; expression_str = expression.check_text (</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">142</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>) [[likely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">143</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">144</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">145</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">146</span><span class="doxyLineContent"><span class="doxyHighlight">              <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>.test_reporter ().pass (<a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>.message, expression_str,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">147</span><span class="doxyLineContent"><span class="doxyHighlight">                                                <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>.totals_.increment_passed_checks ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">151</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">152</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">153</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>.test_reporter ().fail (<a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>, expression_str, <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">154</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>.totals_.increment_failed_checks ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">155</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">156</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">157</span><span class="doxyLineContent"><span class="doxyHighlight">      expression.end_check (</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>.kind == <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">check_kind::requirement</a> &amp;&amp; !<a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>) [[unlikely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (std::uncaught_exceptions () &lt;= <a href="#a4a9f64710ef24d140b065ae5666badeb">uncaught_exceptions_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">throw</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failed-requirement">failed_requirement</a>{};</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>.abort (<a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>.location);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// defined(__cpp_exceptions)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="#ae3b88e57597f9fcd04536b894bebef5e">~check_result</a>, <a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>, <a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a>, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70caba12fb48e2d23bb2bd2819f64d02ec7e">micro_os_plus::micro_test_plus::detail::requirement</a>, <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>, <a href="#a4a9f64710ef24d140b065ae5666badeb">uncaught_exceptions_</a> and <a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>.</p>


<p>Referenced by <a href="#ae3b88e57597f9fcd04536b894bebef5e">~check_result</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator&lt;&lt;() {#a44b0e35cd70af1cd0bfe333ffd6629e9}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto &amp; micro_os_plus::micro_test_plus::detail::check_result::operator&lt;&lt; (const T &amp; msg)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a message to the check.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the message to append: a value that the formatter can write, or a callable object that returns one.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">msg</td>
<td class="doxyParamItemDescription"><p>The message to append, or the callable object that returns it, called only if the check fails.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the current check result.</p></dd>
</dl>


<p>This operator overload enables the check result to accumulate expectation messages by appending the provided value to the internal message string.</p>


<p>The value is written by the same <span class="doxyComputerOutput">operator&lt;&lt;</span> overloads as the operands of the expressions, so that both accept the same types, including the application types with an <span class="doxyComputerOutput">operator&lt;&lt;</span> for the formatter. The message is moved into a local formatter in the plain mode, which writes the numbers without the type suffixes and the <span class="doxyComputerOutput">char</span> values unchanged, and is moved back after the value is appended, so that no other buffer is allocated. The formatter of the reporter is not used, since it may hold the expression of this check, or of a pending one.</p>


<p>When the outcome of the check is not written, the message is not needed, and the value is not formatted.</p>


<p>A callable object (see <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/lazy-message">detail::lazy_message</a></span>) is called only if the check failed, and its result is appended as a value; after a success, even if the outcome is written, it appends nothing, since its purpose is to describe a failure with values that may not be valid otherwise, like the error of a <span class="doxyComputerOutput">std::expected</span> that holds a value. Being a class type, a lambda without captures is called too, although it is also printable, as a <span class="doxyComputerOutput">bool</span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00297">297</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/check-result-inlines-h/#l00184">184</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/check-result-inlines-h">check-result-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">184</span><span class="doxyLineContent"><span class="doxyHighlight">    check_result::operator&lt;&lt; (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; msg)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">185</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">186</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/lazy-message">detail::lazy_message&lt;T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">187</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">188</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">189</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">190</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">191</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">192</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">193</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">194</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">195</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (!<a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">196</span><span class="doxyLineContent"><span class="doxyHighlight">            {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">197</span><span class="doxyLineContent"><span class="doxyHighlight">              </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">198</span><span class="doxyLineContent"><span class="doxyHighlight">            }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">199</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">200</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">201</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a> formatter{ std::move (<a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>.message) };</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">202</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/detail/lazy-message">detail::lazy_message&lt;T&gt;</a>)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">203</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">204</span><span class="doxyLineContent"><span class="doxyHighlight">          formatter &lt;&lt; std::invoke (msg);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">205</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">206</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">207</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">208</span><span class="doxyLineContent"><span class="doxyHighlight">          formatter &lt;&lt; msg;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">209</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">210</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>.message = std::move (formatter.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1e8f6c298a6a12d07bdb9afd47c9c52c">buffer_</a>);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">211</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">212</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a1e8f6c298a6a12d07bdb9afd47c9c52c">micro_os_plus::micro_test_plus::detail::expression_formatter::buffer_</a>, <a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>, <a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a> and <a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>.</p>

</div>
</div>

### operator=() {#a26da353e3ea2577e00106c8f1f7b316b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">check_result &amp; micro_os_plus::micro_test_plus::detail::check_result::operator= (<a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a> &amp;&amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted move assignment operator to prevent moving.</p>


<p>Each instance reports exactly one check, from its destructor.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00273">273</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<p>References <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a> and <a href="#a683d05f5acadf26be1ef2303c4670039">value</a>.</p>

</div>
</div>

### operator=() {#a231681600fe29544efcdba22c56d5740}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">check_result &amp; micro_os_plus::micro_test_plus::detail::check_result::operator= (const <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a> &amp;)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel delete">delete</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Deleted copy assignment operator to prevent copying.</p>


<p>Each instance reports exactly one check, from its destructor.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00263">263</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<p>Reference <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### value() {#a683d05f5acadf26be1ef2303c4670039}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::check_result::value (void)</td>
</tr>
</table>
</td>
<td class="doxyMemberLabelsRight">
<span class="doxyMemberLabels">
<span class="doxyMemberLabel inline">inline</span>
<span class="doxyMemberLabel nodiscard">nodiscard</span>
<span class="doxyMemberLabel noexcept">noexcept</span>
</span>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Retrieves the result value.</p>


<dl class="doxySectionUser">
<dt>Parameters</dt>
<dd><p>None.</p></dd>
</dl>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Return Values</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">true</td>
<td class="doxyParamItemDescription"><p>The checked condition was met.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>The checked condition was not met.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns the result value stored in <span class="doxyComputerOutput"><a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00309">309</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/check-result-inlines-h/#l00147">147</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/check-result-inlines-h">check-result-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a683d05f5acadf26be1ef2303c4670039">147</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a683d05f5acadf26be1ef2303c4670039">check_result::value</a> (</span><span class="doxyHighlightKeywordType">void</span><span class="doxyHighlight">) </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">noexcept</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">148</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">149</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">150</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>.</p>


<p>Referenced by <a href="#aae72a4be3b00dd0af05eb50c65ae1815">check_result</a> and <a href="#a26da353e3ea2577e00106c8f1f7b316b">operator=</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Private Member Attributes

### info\_ {#af96f9a6d186ff05253e33d088cab8106}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">failure_info micro_os_plus::micro_test_plus::detail::check_result::info_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The details displayed when the check fails.</p>


<p>The kind, the expression flag, and the location are set by the constructor; the message is collected via <span class="doxyComputerOutput">operator&lt;&lt;()</span>. Passed to the reporter by the destructor; the message is also displayed when the check passes.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00360">360</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af96f9a6d186ff05253e33d088cab8106">360</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/structs/micro-os-plus/micro-test-plus/detail/failure-info">failure_info</a> <a href="#af96f9a6d186ff05253e33d088cab8106">info_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#aae72a4be3b00dd0af05eb50c65ae1815">check_result</a>, <a href="#ae3b88e57597f9fcd04536b894bebef5e">~check_result</a> and <a href="#a44b0e35cd70af1cd0bfe333ffd6629e9">operator&lt;&lt;</a>.</p>

</div>
</div>

### is\_written\_ {#af0281b8df34411a8e9e45fa7f7c83d4b}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const bool micro_os_plus::micro_test_plus::detail::check_result::is_written_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Whether the outcome of the check is written.</p>


<p>Set by the constructor for a failed check, and for a passed one when the reporter writes the passed checks. When not set, the expression and the messages are not formatted, and the destructor only updates the counters.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00349">349</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#af0281b8df34411a8e9e45fa7f7c83d4b">349</a></span><span class="doxyLineContent"><span class="doxyHighlight">      const </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#af0281b8df34411a8e9e45fa7f7c83d4b">is_written_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#aae72a4be3b00dd0af05eb50c65ae1815">check_result</a>, <a href="#a3c6ef4e73f3bf898f1682187dc86919d">check_result</a>, <a href="#ae3b88e57597f9fcd04536b894bebef5e">~check_result</a> and <a href="#a44b0e35cd70af1cd0bfe333ffd6629e9">operator&lt;&lt;</a>.</p>

</div>
</div>

### test\_case\_ {#acfffc3c834c3a59408fcfae3a20f2dc1}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">test_case&amp; micro_os_plus::micro_test_plus::detail::check_result::test_case_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Reference to the test case invoking this check.</p>


<p>Provides access to the reporter and to the totals to be updated.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00378">378</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#acfffc3c834c3a59408fcfae3a20f2dc1">378</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case">test_case</a>&amp; <a href="#acfffc3c834c3a59408fcfae3a20f2dc1">test_case_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#ae3b88e57597f9fcd04536b894bebef5e">~check_result</a>.</p>

</div>
</div>

### uncaught\_exceptions\_ {#a4a9f64710ef24d140b065ae5666badeb}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::detail::check_result::uncaught_exceptions_ = 0</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>The number of uncaught exceptions when the check was created.</p>


<p>If the destructor finds more, it runs during stack unwinding (for a result kept in a variable), and must not throw.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00370">370</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a4a9f64710ef24d140b065ae5666badeb">370</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> <a href="#a4a9f64710ef24d140b065ae5666badeb">uncaught_exceptions_</a> = 0;</span></span></div>

</div>


<p>Referenced by <a href="#ae3b88e57597f9fcd04536b894bebef5e">~check_result</a>.</p>

</div>
</div>

### value\_ {#a5e3cca5a1c660bc576184ca200f73cc7}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const bool micro_os_plus::micro_test_plus::detail::check_result::value_</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Stores the result value of the check.</p>


<p>The boolean value of the checked expression, computed by the template constructor.</p>


<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h/#l00338">338</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a5e3cca5a1c660bc576184ca200f73cc7">338</a></span><span class="doxyLineContent"><span class="doxyHighlight">      const </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="#a5e3cca5a1c660bc576184ca200f73cc7">value_</a>;</span></span></div>

</div>


<p>Referenced by <a href="#aae72a4be3b00dd0af05eb50c65ae1815">check_result</a>, <a href="#ae3b88e57597f9fcd04536b894bebef5e">~check_result</a>, <a href="#a44b0e35cd70af1cd0bfe333ffd6629e9">operator&lt;&lt;</a> and <a href="#a683d05f5acadf26be1ef2303c4670039">value</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/check-result-h">check-result.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/check-result-inlines-h">check-result-inlines.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/src/check-result-cpp">check-result.cpp</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.4 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
