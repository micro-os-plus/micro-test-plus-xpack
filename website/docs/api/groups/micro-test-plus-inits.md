---

# DO NOT EDIT!
# Automatically generated via docusaurus-plugin-doxygen by Doxygen.

slug: /api/groups/micro-test-plus-inits
custom_edit_url: null
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# The Initialisation & Exit Reference

<p>Functions for initialising the framework and returning an exit code. <a href="#details">More...</a></p>

## Functions Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">int</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gaa790667969dc1a261c324e89a6ea4591">exit_code</a> (void)</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Complete the test run and return the exit code. <a href="#gaa790667969dc1a261c324e89a6ea4591">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="right" valign="top">void</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="#gac2c60d60578f668878957ec68a37538f">initialize</a> (int argc, char *argv[], const char *name="Main")</td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Initialise the µTest++ framework. <a href="#gac2c60d60578f668878957ec68a37538f">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>Functions for initialising the framework and returning an exit code.</p>


<p>These functions are responsible for initialising the test runner and returning the test result as the process exit code. Proper initialisation ensures that the µTest++ framework is correctly configured to manage and execute test cases, while the exit code reflects the overall outcome of the tests, supporting integration with automated build and continuous integration systems.</p>

<p>The simplest test consists of a single test case containing a single expectation; for example:</p>

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightPreprocessor">#include &lt;<a href="/micro-test-plus-xpack/docs/api/files/include/micro-os-plus/micro-test-plus-h">micro-os-plus/micro-test-plus.h</a>&gt;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlightKeywordType">int</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">main(</span><span class="doxyHighlightKeywordType">int</span><span class="doxyHighlight"> argc, </span><span class="doxyHighlightKeywordType">char</span><span class="doxyHighlight">* argv[])</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">{</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeyword">namespace </span><span class="doxyHighlight">mt = <a href="/micro-test-plus-xpack/docs/api/namespaces/micro-os-plus/micro-test-plus">micro_os_plus::micro_test_plus</a>;</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::initialize(argc, argv, </span><span class="doxyHighlightStringLiteral">"Minimal"</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  mt::test_case (</span><span class="doxyHighlightStringLiteral">"Check truth"</span><span class="doxyHighlight">, [] {</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">    mt::expect (</span><span class="doxyHighlightKeyword">true</span><span class="doxyHighlight">);</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  })</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  </span><span class="doxyHighlightKeywordFlow">return</span><span class="doxyHighlight"> mt::exit_code ();</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">}</span></span></div>

</div>


<p>When this test is executed, the output is as follows:</p>

<div class="doxyProgramListing">

<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">• Minimal - test suite started</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">  ✓ Check truth - test case passed (1 check)</span></span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span></div>
<div class="doxyCodeLine"><span class="doxyNoLineNumber">&nbsp;</span><span class="doxyLineContent"><span class="doxyHighlight">✓ Minimal - test suite passed (1 check in 1 test case)</span></span></div>

</div>


<div class="doxySectionDef">

## Functions

### exit_code() {#gaa790667969dc1a261c324e89a6ea4591}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">int micro_os_plus::micro_test_plus::exit_code (void)</td>
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
<p>Complete the test run and return the exit code.</p>


<dl class="doxySectionUser">
<dt><b>Parameters</b></dt>
<dd>
<p>None.</p>
</dd>
</dl>


<dl class="doxySectionUser">
<dt><b>Returns</b></dt>
<dd>
<p>0 if all tests were successful, 1 if any test failed.</p>
</dd>
</dl>


<p>In addition to the test cases defined in <span class="doxyComputerOutput">main()</span>, additional test suites may be declared as static objects either within the same file or in other files, and are automatically registered via the static constructors mechanism.</p>

<p>The <span class="doxyComputerOutput">exit_code</span> function finalises the execution of all registered test suites and test cases within the µTest++ framework, and returns an appropriate exit code to the operating system. This function should be called at the end of the test program, typically from the <span class="doxyComputerOutput">main()</span> function, to ensure that all results are properly reported and the correct status is communicated.</p>

<p>The returned value indicates the overall success or failure of the test run, allowing integration with build systems and continuous integration environments.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp/#l00108">108</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp">micro-test-plus.cpp</a>.</p>
</div>
</div>

### initialize() {#gac2c60d60578f668878957ec68a37538f}

<div class="doxyMemberItem">
<div class="doxyMemberProto">
<table class="doxyMemberLabels">
<tr class="doxyMemberLabels">
<td class="doxyMemberLabelsLeft">
<table class="doxyMemberName">
<tr>
<td class="doxyMemberName">void micro_os_plus::micro_test_plus::initialize (int argc, char * argv=[], const char * name="Main")</td>
</tr>
</table>
</td>
</tr>
</table>
</div>
<div class="doxyMemberDoc">
<p>Initialise the µTest++ framework.</p>


<dl class="doxyParamsList">
<dt class="doxyParamsTableTitle">Parameters</dt>
<dd>
<table class="doxyParamsTable">
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] argc</td>
<td class="doxyParamItemDescription"><p>The number of command-line arguments.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] argv</td>
<td class="doxyParamItemDescription"><p>Array of pointers to null-terminated argument strings.</p></td>
</tr>
<tr class="doxyParamItem">
<td class="doxyParamItemName">[in] name</td>
<td class="doxyParamItemDescription"><p>The name of the default test suite. Defaults to <span class="doxyComputerOutput">"Main"</span> if not specified.</p></td>
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


<p>The <span class="doxyComputerOutput">initialize</span> function sets up the µTest++ testing framework, preparing it for test execution. It processes command-line arguments, configures the test environment, and establishes the default test suite name. This function should be called at the beginning of the test programme, typically from the <span class="doxyComputerOutput">main()</span> function, to ensure proper initialisation of all framework components.</p>

<p>The provided arguments may be used to configure verbosity or other run-time options for the test session.</p>

<p>Definition at line <a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp/#l00081">81</a> of file <a href="/micro-test-plus-xpack/docs/api/files/src/micro-test-plus-cpp">micro-test-plus.cpp</a>.</p>
</div>
</div>

</div>

<p class="doxyGeneratedBy">Generated via <a href="https://github.com/xpack/docusaurus-plugin-doxygen">docusaurus-plugin-doxygen</a> by <a href="https://www.doxygen.nl">Doxygen</a> 1.14.0.</p>

</div>
