---

# DO NOT EDIT!
# Automatically generated via doxygen2docusaurus by Doxygen.

slug: /api/groups/micro-os-plus-micro-test-plus
custom_edit_url: null
toc_max_heading_level: 4
keywords:
  - doxygen
  - reference
  - group

---

<div class="doxyPage">

# µTest++

<p>The µTest++ Testing Framework. <a href="#details">More...</a></p>

## Topics Index

<table class="doxyMembersIndex">

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">&nbsp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api">C++ API</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>How to write the tests. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">&nbsp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-c-api">C API</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>There is no C API; C code is tested from C++. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-c-api/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">&nbsp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-config">Configuration</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>The macros that enable and configure the framework. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-config/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

<tr class="doxyMemberIndexItem">
<td class="doxyMemberIndexItemType" align="left" valign="top">&nbsp;</td>
<td class="doxyMemberIndexItemName" align="left" valign="top"><a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cli">Command-line options</a></td>
</tr>
<tr class="doxyMemberIndexDescription">
<td class="doxyMemberIndexDescriptionLeft"></td>
<td class="doxyMemberIndexDescriptionRight">
<p>Options for controlling the test output at run time. <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cli/#details">More...</a></p>
</td>
</tr>
<tr class="doxyMemberIndexSeparator">
<td class="doxyMemberIndexSeparator" colspan="2"></td>
</tr>

</table>

## Description {#details}

<p>The µTest++ Testing Framework.</p>


<p>µTest++ is a C++20 testing framework for embedded targets, which also runs on the native platforms. The tests are ordinary C++ code, functions and lambdas, with no preprocessor macros.</p>


<p>A test program uses three classes:</p>


<ul class="doxyList ">
<li>the <span class="doxyComputerOutput">runner</span>, which reads the command line, runs the suites, and returns the exit code;</li>
<li>the <span class="doxyComputerOutput">suite</span>, a named group of test cases;</li>
<li>the <span class="doxyComputerOutput">test_case</span>, a named sequence of checks, made with <span class="doxyComputerOutput">expect()</span> and <span class="doxyComputerOutput">require()</span>.</li>
</ul>

<p>The results are written in the TAP format, for the tools that read test results, or in a human-readable format.</p>


<p>The topics are grouped in four parts:</p>


<ul class="doxyList ">
<li>how to write the tests, in <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cpp-api">C++ API</a>;</li>
<li>how to test C code, in <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-c-api">C API</a>;</li>
<li>the macros that enable the framework, in <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-config">Configuration</a>;</li>
<li>the options of the test programs, in <a href="/micro-test-plus-xpack/docs/api/groups/micro-os-plus-micro-test-plus-cli">Command-line options</a>.</li>
</ul>

<hr/>

<p class="doxyGeneratedBy">Generated via <a href="https://xpack.github.io/doxygen2docusaurus">doxygen2docusaurus</a> 2.2.7 by <a href="https://www.doxygen.nl">Doxygen</a> 1.18.0.</p>

</div>
