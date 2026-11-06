---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-cpp-api-test-case
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Test cases

<p>Test cases are named sequences of checks. <a href="#details">More...</a></p>

## Classes Index

<table class="doxyMembersIndex">

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

</table>

## Description {#details}

<p>Test cases are named sequences of checks.</p>


<p>A test case is created with <span class="doxyComputerOutput">test()</span>, called on a suite, with a name and a callable, usually a lambda that receives the test case (<span class="doxyComputerOutput">[] (auto&amp; t) { ... }</span>), followed by any arguments for the callable. The test case runs immediately, within the call, and its checks are made on the test case received by the lambda (<span class="doxyComputerOutput">t.expect (...)</span>).</p>


<p>Write one test case for each behaviour of the code under test; the report shows the result of each test case, so a failure points to the behaviour that broke.</p>


<p>A test case that makes no check passes, and is reported as <span class="doxyComputerOutput">passed (0 checks)</span>; a body that forgets its checks is not detected, so make at least one in each test case.</p>


<p>An exception that escapes the body of a test case is caught, and reported as a failed check of that test case, with the text of its <span class="doxyComputerOutput">what()</span> (<span class="doxyComputerOutput">unexpected exception: ...</span>, or <span class="doxyComputerOutput">unexpected exception of unknown type</span>); the test case ends, and the run continues with the next one. Nested test cases catch their own exceptions, so the exception is reported by the innermost test case whose body it escapes. An exception that escapes the body of a suite fails that suite in the same way. Without exceptions, nothing can be thrown, and this does not apply.</p>


<p>A test case can contain other test cases, created with <span class="doxyComputerOutput">test()</span> on the test case itself (<span class="doxyComputerOutput">t.test (...)</span>); they are reported nested.</p>


<dl class="doxySectionUser">
<dt>Example</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// In main(), after tr.add_top_suite():</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test (</span><span class="doxyHighlightStringLiteral">"Check various conditions"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::eq (compute_answer (), 42)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer eq 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  t.expect (mt::ne (compute_answer (), 43)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"answer ne 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">});</span></span></div>

</div>


<dl class="doxySectionUser">
<dt>Test cases for several values</dt>
<dd></dd>
</dl>


<p><span class="doxyComputerOutput">test_each()</span>, called on a suite or on a test case, creates and runs a test case for each value of a range (a container, an array, a span, or a view), of a list written in place, or of a tuple, whose values may have different types. The callable receives the test case and the value, and a generic lambda is needed for a tuple. Each test case is named after the common name, followed by the value in parentheses, such as <span class="doxyComputerOutput">Sizes (16)</span>; a value that cannot be written, such as an application type without an <span class="doxyComputerOutput">operator&lt;&lt;</span>, is replaced by its position, starting at 1, such as <span class="doxyComputerOutput">Records (#2)</span>.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test_each (</span><span class="doxyHighlightStringLiteral">"Sizes"</span><span class="doxyHighlight">, std::vector&lt;int&gt;{ 1, 16, 512 },</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">              [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> size) { t.expect (mt::gt (size, 0)); });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test_each (</span><span class="doxyHighlightStringLiteral">"Limits"</span><span class="doxyHighlight">, { 3, 4 },</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">              [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> limit) { t.expect (mt::gt (limit, 2)); });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ts.test_each (</span><span class="doxyHighlightStringLiteral">"Types"</span><span class="doxyHighlight">, std::tuple{ 42, 1.5, </span><span class="doxyHighlightStringLiteral">"text"</span><span class="doxyHighlight"> },</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">              [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t, </span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; value) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                t.expect (mt::eq (value, value));</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">              });</span></span></div>

</div>


<p>With the TAP reporter, the first call is reported as:</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 1 - Sizes (1) # { passed, 1 check }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 2 - Sizes (16) # { passed, 1 check }</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">ok 3 - Sizes (512) # { passed, 1 check }</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.8 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
