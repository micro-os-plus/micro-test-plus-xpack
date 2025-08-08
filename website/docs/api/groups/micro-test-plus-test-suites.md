---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-test-plus-test-suites
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Test Suites

<p>Test suites are named collections of test cases. <a href="#details">More...</a></p>

## Classes Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">class</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite">test_suite</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Represents a named group of test cases that self-register to the runner. <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/test-suite/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Test suites are named collections of test cases.</p>


<p>Test suites in µTest++ are named groups of related test cases, allowing for structured organisation and execution of tests. By default, all test cases defined in <span class="doxyComputerOutput">main()</span> are included in the default (main) test suite and are executed immediately.</p>


<p>For more complex projects, multiple test suites can be defined, typically in separate source files. Test suites are implemented as classes, constructed with a name, a callable (usually a lambda that chains the execution of the test cases), and optional arguments. This design enables self-registration of test suites, ensuring they are automatically included in the test run.</p>


<p>It is advisable to instantiate test suites as static objects. Self-registration occurs within the constructor, and test suites defined in separate compilation units may be executed in any order, as the sequence of static constructor invocation is not specified. Therefore, test suites should not have dependencies on one another.</p>


<p>All registered test suites are executed when the <span class="doxyComputerOutput">exit_code()</span> function is called, ensuring comprehensive test coverage across the project.</p>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">class </span><span class="doxyHighlight">test_suite : </span><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight"> test_suite_base</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">public</span><span class="doxyHighlight">:</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">template</span><span class="doxyHighlight"> &lt;</span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight"> Callable_T, </span><span class="doxyHighlightKeyword">typename</span><span class="doxyHighlight">... Args_T&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  test_suite (</span><span class="doxyHighlightKeyword">const</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* name, Callable_T&amp;&amp; callable,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">              Args_T&amp;&amp;... arguments);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightComment">// ...</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>



:::tip
<p>It is strongly recommended to instantiate test suites as static objects.</p>
:::


<p>Self-registration is performed within the constructor, ensuring that each test suite is automatically included in the test run. When test suites are defined in separate compilation units, they may be executed in any order, as the sequence in which static constructors are invoked is not specified. Consequently, test suites should be designed to be independent and must not rely on the execution order of other suites.</p>


<p>All registered test suites are executed when the <span class="doxyComputerOutput">exit_code()</span> function is called, guaranteeing that the entire test suite collection is run and reported in a consistent and reliable manner.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Test suite with generic parameters.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">test_suite_args (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> ic, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> iv, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">&amp; ir, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">* ip1, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">* ip2)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::test_case (</span><span class="doxyHighlightStringLiteral">"args"</span><span class="doxyHighlight">, [&amp;] {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    mt::expect (mt::eq (ic, 42)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ic is 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    mt::expect (mt::eq (iv, 43)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"iv is 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    mt::expect (mt::eq (ir, 44)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ir is 44"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    mt::expect (mt::eq (*ip1, 45)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"*ip1 is 45"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    mt::expect (mt::eq (*ip2, 46)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"*ip2 is 46"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> in = 43;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> in44 = 44;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">&amp; ir = in44;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> in45 = 45;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> in46 = 46;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">* ip2 = &amp;in46;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> mt::test_suite ts_args</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    = { </span><span class="doxyHighlightStringLiteral">"Args"</span><span class="doxyHighlight">, test_suite_args, 42, in, ir, &amp;in45, ip2 };</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 1.1.0 by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
