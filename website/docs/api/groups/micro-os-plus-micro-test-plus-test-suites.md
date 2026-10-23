---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus-test-suites
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# Test Suites

<p>Test suites are named groups of related test cases. <a href="#details">More...</a></p>

## Classes Index

<table class="doxyMembersIndex">

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

</table>

## Description {#details}

<p>Test suites are named groups of related test cases.</p>


<p>By default, all test cases defined in <span class="doxyComputerOutput">main()</span> are included in the top-level test suite, which is owned by the runner and returned by <span class="doxyComputerOutput">runner::initialise()</span>; its test cases run immediately. For more complex projects, additional test suites can be defined, typically in separate source files.</p>


<p>The additional test suites are either added in <span class="doxyComputerOutput">main()</span> with <span class="doxyComputerOutput">runner::add_suite()</span>, or defined as <span class="doxyComputerOutput">mt::static_suite</span> objects, at namespace scope, constructed with a name, a reference to the runner, and a callable (usually a function or a lambda with a <span class="doxyComputerOutput">mt::suite&amp;</span> first parameter, which creates the test cases), along with any optional arguments. The static suites register themselves in their constructors, so they are included in the test run without other calls.</p>



:::tip
<p>The runner referred to by the static suites in other source files must have external linkage (not <span class="doxyComputerOutput">static</span>), and be declared <span class="doxyComputerOutput">extern</span> in a header shared by these files.</p>
:::


<p>The static suites may be constructed before or after the runner, in any order. All suites, added or static, are run by <span class="doxyComputerOutput">runner::run()</span>, after the test cases of the top suite, in a single order, sorted by name (byte by byte, as by <span class="doxyComputerOutput">std::strcmp()</span>); suites with the same name run in the order in which they were created, so the static ones first. Zero-padded numeric prefixes (<span class="doxyComputerOutput">"01 - Init"</span>) give an explicit order. Test suites should nevertheless be designed to be independent of each other.</p>


<dl class="doxySectionUser">
<dt>Examples</dt>
<dd></dd>
</dl>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// In a header shared by the source files.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">extern</span><span class="doxyHighlight"> <a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner">micro_os_plus::micro_test_plus::runner</a> tr;</span></span></div>

</div>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// In main.cpp: the runner, with external linkage.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">mt::runner tr;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">main (</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[])</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; ts = tr.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#acfabd0e10d233ad305b6f4fc125a97f2">initialise</a> (argc, argv, </span><span class="doxyHighlightStringLiteral">"Sample"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ts.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/suite/#a402696dc4d4978ff3c050427890cfe01">test</a> (</span><span class="doxyHighlightStringLiteral">"Check one"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    t.expect (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"Passed"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> tr.<a href="/micro-test-plus-xpack/docs/api/classes/micro-os-plus/micro-test-plus/runner/#a97f725cb167a2b464fac0eb88a0c8a46">run</a> ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// In a separate source file: a self-registering suite.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> mt::static_suite ts_extra</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    = { </span><span class="doxyHighlightStringLiteral">"Extra suite"</span><span class="doxyHighlight">, tr, [] (mt::suite&amp; ts) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ts.test (</span><span class="doxyHighlightStringLiteral">"Check two"</span><span class="doxyHighlight">, [] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) { t.expect (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"Passed"</span><span class="doxyHighlight">; });</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">} };</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightComment">// Parametrised test suite accepting additional arguments.</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> </span><span class="doxyHighlightKeywordType">void</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">test_suite_with_args (mt::suite&amp; ts, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> ic, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> iv,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">                      </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">&amp; ir, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">* ip1, </span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight">* ip2)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ts.test (</span><span class="doxyHighlightStringLiteral">"args"</span><span class="doxyHighlight">, [&amp;] (</span><span class="doxyHighlightKeyword">auto</span><span class="doxyHighlight">&amp; t) {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    t.expect (mt::eq (ic, 42)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ic is 42"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    t.expect (mt::eq (iv, 43)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"iv is 43"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    t.expect (mt::eq (ir, 44)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"ir is 44"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    t.expect (mt::eq (*ip1, 45)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"*ip1 is 45"</span><span class="doxyHighlight">;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    t.expect (mt::eq (*ip2, 46)) &lt;&lt; </span><span class="doxyHighlightStringLiteral">"*ip2 is 46"</span><span class="doxyHighlight">;</span></span></div>
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
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeyword">static</span><span class="doxyHighlight"> mt::static_suite ts_args</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    = { </span><span class="doxyHighlightStringLiteral">"Args suite"</span><span class="doxyHighlight">, tr, test_suite_with_args,</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">        42, in, ir, &amp;in45, ip2 };</span></span></div>

</div>


<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.5 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
