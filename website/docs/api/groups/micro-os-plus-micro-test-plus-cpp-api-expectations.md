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


<p><span class="doxyComputerOutput">t.expect (condition)</span> checks a condition, counts the result, and reports it; when the check fails, the test case continues, so that all its checks are evaluated and reported in one run.</p>


<p>The condition is one of:</p>


<ul class="doxyList ">
<li>a function comparator, such as <span class="doxyComputerOutput">mt::eq (actual, 42)</span>, or a combination of them, which reports the values of its operands;</li>
<li>an exception check, such as <span class="doxyComputerOutput">mt::throws (...)</span>;</li>
<li>any other value that converts to <span class="doxyComputerOutput">bool</span> in a condition, such as <span class="doxyComputerOutput">x == 1</span>, a pointer, or a <span class="doxyComputerOutput">std::optional&lt;int&gt;</span>, which reports only the location of the failed check.</li>
</ul>

<p>The values that would make the check pass by mistake do not compile: the string literals and the other character arrays and pointers, the function names, the pointers to functions and to members, and the wrappers of a <span class="doxyComputerOutput">bool</span> (<span class="doxyComputerOutput">std::optional&lt;bool&gt;</span> and the smart pointers to <span class="doxyComputerOutput">bool</span>), whose condition tells whether a value is present, not what it is. The scoped enumerations do not compile either, since only a cast converts them. Write the comparison instead, such as <span class="doxyComputerOutput">mt::eq (flag.value (), true)</span>. With the deprecated definitions enabled, all of these are accepted, with a deprecation warning, except the wrappers of a <span class="doxyComputerOutput">bool</span> and the scoped enumerations.</p>


<p>A message can be appended with <span class="doxyComputerOutput">&lt;&lt;</span>, with any values that can be written, for example <span class="doxyComputerOutput">t.expect (x == 2) &lt;&lt; "x is " &lt;&lt; x;</span>. The check is reported at the end of the statement, with the message, or, without one, with the condition.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check the values"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> x = 1;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::eq (x, 2));</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (x == 2) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"x is "</span><span class="doxyHighlight"> &lt;&lt; x;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<p>Both checks fail; the human-readable reporter displays:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">• Check the values</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ✗ FAILED (main.cpp:13, 1 == 2)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    ✗ x is 1 FAILED (main.cpp:14)</span></span></div>

</div>


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
<dd><p>A reference to the check result, to which optional messages can be appended with <span class="doxyComputerOutput">operator&lt;&lt;</span>; the check is reported when it is destroyed, at the end of the statement.</p></dd>
</dl>



:::warning
<p>The result must not be named, stored, or kept in any variable. A reference such as <span class="doxyComputerOutput">auto&amp;&amp; r = t.expect (...)</span> compiles, but dangles after the statement; the message operator and <span class="doxyComputerOutput">value()</span> can be called only on a temporary, so the named result cannot be used, and forcing it with <span class="doxyComputerOutput">std::move()</span> is undefined. The check must be reported at the end of the statement, and not later. Write the message in the same statement, with <span class="doxyComputerOutput">operator&lt;&lt;</span>.</p>
:::


<p>Initialises the <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a></span> received as the last argument, a temporary created by the caller, with the kind <span class="doxyComputerOutput"><a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70cae15c5d274bf9fa6571890c731d88bc37">detail::check_kind::expectation</a></span>, and returns a reference to it. The check result evaluates the condition when initialised, and records a pass or fail when it is destroyed, at the end of the expression statement.</p>


<p>Declaration at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h/#l01628">1628</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/test-h">test.h</a>, definition at line <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h/#l00623">623</a> of file <a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus/inlines/test-inlines-h">test-inlines.h</a>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyLineNumber"><a href="#ga6db7427ada09e476aec67306ca5c0b74">623</a></span><span class="doxyLineContent"><span class="doxyHighlight">  <a href="#ga6db7427ada09e476aec67306ca5c0b74">test_case::expect</a> (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> Expr_T&amp; expr, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/reflection/source-location">reflection::source_location</a>&amp; sl,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">624</span><span class="doxyLineContent"><span class="doxyHighlight">                     <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result">detail::check_result</a>&amp;&amp; result)</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">625</span><span class="doxyLineContent"><span class="doxyHighlight">  {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">626</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">if</span><span class="doxyHighlight"> (<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a82e48e546c5a5034be69412c1641482d">is_misdirected</a> ()) [[unlikely]]</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">627</span><span class="doxyLineContent"><span class="doxyHighlight">      {</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">628</span><span class="doxyLineContent"><span class="doxyHighlight">        </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b25dc50ced0df2821d7a984eb142c1a">report_misdirected</a> (<a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70cae15c5d274bf9fa6571890c731d88bc37">detail::check_kind::expectation</a>, sl,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">629</span><span class="doxyLineContent"><span class="doxyHighlight">                                   std::move (result));</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">630</span><span class="doxyLineContent"><span class="doxyHighlight">      }</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">631</span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">632</span><span class="doxyLineContent"><span class="doxyHighlight">    result.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result/#ab81139f2b0c47e93b7d488976fcbbd66">init</a> (expr, <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70cae15c5d274bf9fa6571890c731d88bc37">detail::check_kind::expectation</a>, sl, *</span><span class="doxyHighlightKeyword">this</span><span class="doxyHighlight">,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">633</span><span class="doxyLineContent"><span class="doxyHighlight">                 <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().expression_,</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">634</span><span class="doxyLineContent"><span class="doxyHighlight">                 <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">test_reporter</a> ().writes_passed_checks ());</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">635</span><span class="doxyLineContent"><span class="doxyHighlight">    </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> std::move (result);</span></span></div>
<div class="doxyCodeLine"><span class="doxyLineNumber">636</span><span class="doxyLineContent"><span class="doxyHighlight">  }</span></span></div>

</div>


<p>References <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus/detail/#a0726a1bc3b6f16245cb8a4b42fe0e70cae15c5d274bf9fa6571890c731d88bc37">micro_os_plus::micro_test_plus::detail::expectation</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/check-result/#ab81139f2b0c47e93b7d488976fcbbd66">micro_os_plus::micro_test_plus::detail::check_result::init</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a82e48e546c5a5034be69412c1641482d">micro_os_plus::micro_test_plus::test_case::is_misdirected</a>, <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#a9b25dc50ced0df2821d7a984eb142c1a">micro_os_plus::micro_test_plus::test_case::report_misdirected</a> and <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/detail/runnable-base/#a7e4a578732a0464480e211f6591fa69f">micro_os_plus::micro_test_plus::detail::runnable_base::test_reporter</a>.</p>


<p>Referenced by <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-case/#ac2e310ec902a0c3e786d4c415269c23e">micro_os_plus::micro_test_plus::test_case::operator=</a>.</p>

</div>
</div>

</div>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
