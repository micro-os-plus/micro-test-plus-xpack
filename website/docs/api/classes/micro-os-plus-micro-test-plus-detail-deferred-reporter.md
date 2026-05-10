---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - class

---

<div class="doxyPage">

# `deferred_reporter` Class

<p>Deferred reporter class for a specific expression. <a href="#details">More...</a></p>

## Declaration

<div class="doxyDeclaration">
class micro_os_plus::micro_test_plus::detail::deferred_reporter { ... }
</div>

## Included Headers

<div class="doxyIncludesList">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;
</div>

## Base class

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base">deferred_reporter_base</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Base class for a deferred reporter that collects messages into a string. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Public Constructors Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexTemplate">
<td class="doxyMemberIndexTemplate" colspan="2"><div>template &lt;class Expr_T&gt;</div></td>
</tr>
<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemNoTypeNameTemplate" colspan="2" align="left" valign="top"><a href="#a0d6bc295723916664b22f60d783b85b0">deferred_reporter</a> (const Expr_T &amp;expr, bool abort, const reflection::source_location &amp;location, subtest &amp;subtest, expression_formatter &amp;expression)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Constructs a deferred reporter for a specific expression. <a href="#a0d6bc295723916664b22f60d783b85b0">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#a39821d33f3f3aa41b3df6f461258afb3">~deferred_reporter</a> ()=default</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Destructor for the deferred reporter. <a href="#a39821d33f3f3aa41b3df6f461258afb3">More...</a></p>
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
<td class="doxyMemberIndexItemNameTemplate" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a25895cdf53098c97033b5c476cdd7702">operator&lt;&lt;</a> (const T &amp;msg)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Appends a message to the reporter. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a25895cdf53098c97033b5c476cdd7702">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0c0b059add8cbddb96e8f2fef8cba431">value</a> () const</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Retrieves the result value. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0c0b059add8cbddb96e8f2fef8cba431">More...</a></p>
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
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa36fd4c36a94b04430599303e38a48bd">abort_</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Indicates whether the reporting should abort further processing. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa36fd4c36a94b04430599303e38a48bd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">std::string</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">deferred_output_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>String to collect the expectation message passed via <span class="doxyComputerOutput">operator&lt;&lt;()</span>. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa22fa7a9c9f3f456d971728083dbcc6e">has_expression_</a> = false</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Indicates whether the reporter has an associated expression. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa22fa7a9c9f3f456d971728083dbcc6e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a></td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a025498d9b9376056c56042cc98ed7afd">location_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the source location associated with the report. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a025498d9b9376056c56042cc98ed7afd">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aae23103bf1232549780c69911239b781">subtest_</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Reference to the test case invoking this report. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aae23103bf1232549780c69911239b781">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">bool</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">value_</a> {}</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Stores the result value of the report. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Deferred reporter class for a specific expression.</p>


<p>The <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter">deferred_reporter</a></span> class extends <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base">deferred_reporter_base</a></span> to provide deferred reporting functionality for a specific test expression within the framework.</p>


<p>This class is responsible for capturing the expression under evaluation, the abort status, and the source location. It is intended exclusively for internal use and is implemented in the <span class="doxyComputerOutput">include/micro-os-plus/micro-test-plus</span> folder to ensure a structured and modular codebase.</p>


<p>Definition at line 219 of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>.</p>


<div class="doxySectionDef">

## Public Constructors

### deferred\_reporter() {#a0d6bc295723916664b22f60d783b85b0}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class Expr_T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::deferred_reporter::deferred_reporter (const Expr_T &amp; expr, bool abort, const <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> &amp; location, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> &amp; subtest, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a> &amp; expression)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Constructs a deferred reporter for a specific expression.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">expr</td>
<td class="doxyParamItemDescription"><p>The expression under evaluation.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">abort</td>
<td class="doxyParamItemDescription"><p>Indicates whether reporting should abort further processing.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">location</td>
<td class="doxyParamItemDescription"><p>The source location relevant to the report.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">subtest</td>
<td class="doxyParamItemDescription"><p>The subtest that owns this deferred report.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">expression</td>
<td class="doxyParamItemDescription"><p>The expression formatter to format the expression text.</p></td>
</tr>
</table>
</dd>
</dl>

<p>This constructor initialises a deferred reporter for a specific expression, capturing the evaluation result, abort status, and source location.</p>


<p>The expression is evaluated and its boolean result is passed to the base class. The abort flag determines whether further test execution should be halted if the expectation fails. The source location provides contextual information for reporting purposes.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00234">234</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h/#l00157">157</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h">deferred-reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#a0d6bc295723916664b22f60d783b85b0">157</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="#a0d6bc295723916664b22f60d783b85b0">deferred_reporter::deferred_reporter</a> (</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">158</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> abort,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">159</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; location, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">160</span><span class="doxyLineContent"><span class="doxyHighlight">        <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter">expression_formatter</a>&amp; expression)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">161</span><span class="doxyLineContent"><span class="doxyHighlight">        : <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">deferred_reporter_base</a>{ static_cast&lt;bool&gt; (expr), location, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a> }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">162</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">163</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">164</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(MICRO_OS_PLUS_TRACE) \</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">165</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">    &amp;&amp; defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">166</span><span class="doxyLineContent"><span class="doxyHighlight">      trace::printf (</span><span class="doxyHighlightStringLiteral">"%s\n"</span><span class="doxyHighlight">, __PRETTY_FUNCTION__);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">167</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif </span><span class="doxyHighlightComment">// MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">168</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa36fd4c36a94b04430599303e38a48bd">abort_</a> = abort;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">169</span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa22fa7a9c9f3f456d971728083dbcc6e">has_expression_</a> = <a href="/micro-test-plus-xpack/docs/api/concepts/micro-os-plus/micro-test-plus/type-traits/is-op">type_traits::is_op&lt;Expr_T&gt;</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">170</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">171</span><span class="doxyLineContent"><span class="doxyHighlight">      expression.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a53d35068a650f572f80e098221ad9aa1">clear</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">172</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">173</span><span class="doxyLineContent"><span class="doxyHighlight">      expression &lt;&lt; expr;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">174</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::deferred_reporter_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa36fd4c36a94b04430599303e38a48bd">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::abort_</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/expression-formatter/#a53d35068a650f572f80e098221ad9aa1">micro_os_plus::micro_test_plus::detail::expression_formatter::clear</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa22fa7a9c9f3f456d971728083dbcc6e">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::has_expression_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Destructor

### \~deferred\_reporter() {#a39821d33f3f3aa41b3df6f461258afb3}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">micro_os_plus::micro_test_plus::detail::deferred_reporter::~deferred_reporter ()</td>
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

<p>Destructor for the deferred reporter.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00241">241</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Operators

### operator&lt;&lt;() {#a25895cdf53098c97033b5c476cdd7702}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<div class="doxyMemberTemplate">template &lt;class T&gt;</div>
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">auto &amp; micro_os_plus::micro_test_plus::detail::deferred_reporter_base::operator&lt;&lt; (const T &amp; msg)</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">

<p>Appends a message to the reporter.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Template Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">T</td>
<td class="doxyParamItemDescription"><p>The type of the message to append.</p></td>
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
<td class="doxyParamItemDescription"><p>The message to append.</p></td>
</tr>
</table>
</dd>
</dl>

<dl class="doxySectionUser">
<dt>Returns</dt>
<dd><p>Reference to the current reporter instance.</p></dd>
</dl>


<p>This operator overload enables the deferred reporter to accumulate expectation messages by appending the provided value to the internal message string.</p>


<p>If the argument is a <span class="doxyComputerOutput">char</span>, it is appended directly as a character. If the argument is of another arithmetic type, it is converted to a string using a fixed-size buffer and <span class="doxyComputerOutput">std::to_chars</span> to avoid dynamic memory allocation. For all other types, the value is appended directly.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00153">153</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h/#l00108">108</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h">deferred-reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber">108</span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a25895cdf53098c97033b5c476cdd7702">deferred_reporter_base::operator&lt;&lt;</a>(</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> T&amp; msg)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">109</span><span class="doxyLineContent"><span class="doxyHighlight">    {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">110</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_same_v&lt;T, char&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">111</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">112</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">deferred_output_</a>.push_back (msg);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">113</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">114</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">constexpr</span><span class="doxyHighlight"> (std::is_arithmetic_v&lt;T&gt;)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">115</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">116</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// Optimise to avoid dynamic memory allocation in std::to_string by</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">117</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// using a fixed-size buffer and std::to_chars.</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">118</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">119</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic push</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">120</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__clang__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">121</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">122</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">123</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">124</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight"> buf[64];</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">125</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// 64 bytes is sufficient for the longest decimal representation</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">126</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightComment">// of any standard arithmetic type (long double ~45 chars).</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">127</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">static_assert</span><span class="doxyHighlight"> (</span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (buf) &gt;= 50,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">128</span><span class="doxyLineContent"><span class="doxyHighlight">                         </span><span class="doxyHighlightStringLiteral">"buf must be large enough for any arithmetic type"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">129</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight"> [ptr, ec] = std::to_chars (buf, buf + </span><span class="doxyHighlightKeyword">sizeof</span><span class="doxyHighlight"> (buf), msg);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">130</span><span class="doxyLineContent"><span class="doxyHighlight">          </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (ec == std::errc{})</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">131</span><span class="doxyLineContent"><span class="doxyHighlight">            <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">deferred_output_</a>.append (buf, ptr);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">132</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#if defined(__GNUC__)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">133</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#pragma GCC diagnostic pop</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">134</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#endif</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">135</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">136</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">else</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">137</span><span class="doxyLineContent"><span class="doxyHighlight">        {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">138</span><span class="doxyLineContent"><span class="doxyHighlight">          <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">deferred_output_</a>.append (msg);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">139</span><span class="doxyLineContent"><span class="doxyHighlight">        }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">140</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">141</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::deferred_output_</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Public Member Functions

### value() {#a0c0b059add8cbddb96e8f2fef8cba431}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::deferred_reporter_base::value ()</td>
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
<td class="doxyParamItemDescription"><p>The reported condition was met.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">false</td>
<td class="doxyParamItemDescription"><p>The reported condition was not met.</p></td>
</tr>
</table>
</dd>
</dl>

<p>Returns the result value stored in <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">value_</a></span>.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00165">165</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h/#l00087">87</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h">deferred-reporter-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0c0b059add8cbddb96e8f2fef8cba431">87</a></span><span class="doxyLineContent"><span class="doxyHighlight">    <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0c0b059add8cbddb96e8f2fef8cba431">deferred_reporter_base::value</a> ()</span><span class="doxyHighlightKeyword"> const</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">88</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">    </span><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">89</span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">value_</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">90</span><span class="doxyLineContent"><span class="doxyHighlight">    }</span></span></div>

</div>


<p>Reference <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::value_</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::deferred_reporter_base</a>.</p>

</div>
</div>

</div>

<div class="doxySectionDef">

## Protected Member Attributes

### abort\_ {#aa36fd4c36a94b04430599303e38a48bd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::deferred_reporter_base::abort_ = false</td>
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

<p>Indicates whether the reporting should abort further processing.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00177">177</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa36fd4c36a94b04430599303e38a48bd">177</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa36fd4c36a94b04430599303e38a48bd">abort_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#a0d6bc295723916664b22f60d783b85b0">deferred_reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a3a8503e793c807cbb882033cc5ff2831">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::~deferred_reporter_base</a>.</p>

</div>
</div>

### deferred\_output\_ {#a0d4853e08c3106a270e951e56d876840}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">std::string micro_os_plus::micro_test_plus::detail::deferred_reporter_base::deferred_output_ {}</td>
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

<p>String to collect the expectation message passed via <span class="doxyComputerOutput">operator&lt;&lt;()</span>.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00193">193</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">193</a></span><span class="doxyLineContent"><span class="doxyHighlight">      std::string <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0d4853e08c3106a270e951e56d876840">deferred_output_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a3a8503e793c807cbb882033cc5ff2831">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::~deferred_reporter_base</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a25895cdf53098c97033b5c476cdd7702">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::operator&lt;&lt;</a>.</p>

</div>
</div>

### has\_expression\_ {#aa22fa7a9c9f3f456d971728083dbcc6e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::deferred_reporter_base::has_expression_ = false</td>
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

<p>Indicates whether the reporter has an associated expression.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00182">182</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa22fa7a9c9f3f456d971728083dbcc6e">182</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aa22fa7a9c9f3f456d971728083dbcc6e">has_expression_</a> = </span><span class="doxyHighlightKeyword">false</span><span class="doxyHighlight">;</span></span></div>

</div>


<p>Referenced by <a href="#a0d6bc295723916664b22f60d783b85b0">deferred_reporter</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a3a8503e793c807cbb882033cc5ff2831">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::~deferred_reporter_base</a>.</p>

</div>
</div>

### location\_ {#a025498d9b9376056c56042cc98ed7afd}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">const reflection::source_location micro_os_plus::micro_test_plus::detail::deferred_reporter_base::location_ {}</td>
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

<p>Stores the source location associated with the report.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00187">187</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a025498d9b9376056c56042cc98ed7afd">187</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a025498d9b9376056c56042cc98ed7afd">location_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::deferred_reporter_base</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a3a8503e793c807cbb882033cc5ff2831">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::~deferred_reporter_base</a>.</p>

</div>
</div>

### subtest\_ {#aae23103bf1232549780c69911239b781}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">subtest&amp; micro_os_plus::micro_test_plus::detail::deferred_reporter_base::subtest_</td>
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

<p>Reference to the test case invoking this report.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00198">198</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aae23103bf1232549780c69911239b781">198</a></span><span class="doxyLineContent"><span class="doxyHighlight">      <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/subtest">subtest</a>&amp; <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#aae23103bf1232549780c69911239b781">subtest_</a>;</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::deferred_reporter_base</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a3a8503e793c807cbb882033cc5ff2831">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::~deferred_reporter_base</a>.</p>

</div>
</div>

### value\_ {#af633053afa944173b47482786f9d9a7e}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">bool micro_os_plus::micro_test_plus::detail::deferred_reporter_base::value_ {}</td>
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

<p>Stores the result value of the report.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h/#l00171">171</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">171</a></span><span class="doxyLineContent"><span class="doxyHighlight">      </span><span class="doxyHighlightKeywordType">bool</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#af633053afa944173b47482786f9d9a7e">value_</a>{};</span></span></div>

</div>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#abd34896d8d956db7223829bcbf9efb04">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::deferred_reporter_base</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a3a8503e793c807cbb882033cc5ff2831">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::~deferred_reporter_base</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/deferred-reporter-base/#a0c0b059add8cbddb96e8f2fef8cba431">micro_os_plus::micro_test_plus::detail::deferred_reporter_base::value</a>.</p>

</div>
</div>

</div>

<hr/>

The documentation for this class was generated from the following files:

<ul>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/deferred-reporter-h">deferred-reporter.h</a></li>
<li><a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/deferred-reporter-inlines-h">deferred-reporter-inlines.h</a></li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.17.0.</p>

</div>
